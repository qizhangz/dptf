/******************************************************************************
** Copyright (c) 2013-2023 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "PolicyManager.h"
#include "DptfManager.h"
#include "WorkItemQueueManagerInterface.h"
#include "WIPolicyCreateAll.h"
#include "WIPolicyDestroy.h"
#include "EsifFileEnumerator.h"
#include "EsifServicesInterface.h"
#include "StatusFormat.h"
#include "MapOps.h"
#include "Utility.h"
#include "ManagerLogger.h"

using namespace StatusFormat;
using namespace std;

PolicyManager::PolicyManager(DptfManagerInterface* dptfManager, const set<Guid>& defaultPolicies)
	: m_dptfManager(dptfManager)
	, m_policies()
	, m_supportedPolicyList(make_shared<SupportedPolicyList>(dptfManager, defaultPolicies))
	, m_supportedDynamicPolicyList(make_shared<SupportedDynamicPolicyList>(dptfManager))
	, m_registeredEvents()
{
}

PolicyManager::~PolicyManager(void)
{
	try
	{
		PolicyManager::destroyAllPolicies();
	}
	catch (...)
	{
		
	}
}

void PolicyManager::createAllPolicies(const string& dptfPolicyDirectoryPath)
{
	try
	{
		// Queue up a work item and wait for the return.
		const auto workItem = make_shared<WIPolicyCreateAll>(m_dptfManager, dptfPolicyDirectoryPath);
		m_dptfManager->getWorkItemQueueManager()->enqueueImmediateWorkItemAndWait(workItem);
	}
	catch (...)
	{
		MANAGER_LOG_MESSAGE_ERROR({
			ManagerMessage message = ManagerMessage(
				m_dptfManager,
				_file,
				_line,
				_function,
				"Failed while trying to enqueue and wait for WIPolicyCreateAll."s);
			return message;
		});
	}
}

UIntN PolicyManager::createPolicy(const string& policyFileName)
{
	UIntN firstAvailableIndex = Constants::Invalid;
	bool shouldDestroyPolicyAfterExceptionCatch = false;
	string exceptionDuringCreationMessage;
	try
	{
		// First check if we have an instance of the policy already
		throwIfPolicyAlreadyExists(policyFileName);

		auto indexesInUse = MapOps<UIntN, shared_ptr<IPolicy>>::getKeys(m_policies);
		firstAvailableIndex = getFirstAvailableIndex(indexesInUse);
		m_policies[firstAvailableIndex] = make_shared<Policy>(m_dptfManager);

		// Create the policy.  This will end up calling the functions in the .dll/.so and will throw an
		// exception if it doesn't find a valid policy to load.
		m_policies[firstAvailableIndex]->createPolicy(
			policyFileName,
			firstAvailableIndex,
			m_supportedPolicyList,
			Guid::createInvalid(),
			Guid::createInvalid(),
			Constants::EmptyString,
			Constants::EmptyString);

		MANAGER_LOG_MESSAGE_INFO({
			ManagerMessage message = ManagerMessage(m_dptfManager, _file, _line, _function, "Policy has been created."s);
			message.setPolicyIndex(firstAvailableIndex);
			message.addMessage("Policy Index"s, firstAvailableIndex);
			message.addMessage("Policy File Name"s, policyFileName);
			return message;
		});
	}
	catch (policy_not_in_idsp_list&)
	{
		// can destroy the policy right away since this type of exception is not generated by the policy
		destroyPolicy(firstAvailableIndex);
		firstAvailableIndex = Constants::Invalid;
	}
	catch (const exception& ex)
	{
		// can't destroy policy here because exception object originated from it's memory space and DLL
		shouldDestroyPolicyAfterExceptionCatch = true;
		exceptionDuringCreationMessage = ex.what();
	}
	catch (...)
	{
		// can't destroy policy here because exception object originated from it's memory space and DLL
		shouldDestroyPolicyAfterExceptionCatch = true;
		exceptionDuringCreationMessage = "Unknown error during policy creation"s;
	}

	if (shouldDestroyPolicyAfterExceptionCatch)
	{
		destroyPolicy(firstAvailableIndex);
		firstAvailableIndex = Constants::Invalid;
		throw dptf_exception(exceptionDuringCreationMessage);
	}

	return firstAvailableIndex;
}

UIntN PolicyManager::createDynamicPolicy(
	const string& policyFileName,
	Guid dynamicPolicyUuid,
	Guid dynamicPolicyTemplateGuid,
	const string& dynamicPolicyName,
	const string& dynamicPolicyUuidString)
{
	UIntN firstAvailableIndex = Constants::Invalid;

	try
	{
		// First check if we have an instance of the dynamic policy already
		throwIfDynamicPolicyAlreadyExists(policyFileName, dynamicPolicyName);

		auto indexesInUse = MapOps<UIntN, shared_ptr<IPolicy>>::getKeys(m_policies);
		firstAvailableIndex = getFirstAvailableIndex(indexesInUse);
		m_policies[firstAvailableIndex] = make_shared<Policy>(m_dptfManager);

		// Create the dynamic policy.  This will end up calling the functions in the .dll/.so and will throw an
		// exception if it doesn't find a valid policy to load.
		m_policies[firstAvailableIndex]->createPolicy(
			policyFileName,
			firstAvailableIndex,
			m_supportedPolicyList,
			dynamicPolicyUuid,
			dynamicPolicyTemplateGuid,
			dynamicPolicyName,
			dynamicPolicyUuidString);

		MANAGER_LOG_MESSAGE_INFO({
			ManagerMessage message =
				ManagerMessage(m_dptfManager, _file, _line, _function, "Dynamic Policy has been created."s);
			message.setPolicyIndex(firstAvailableIndex);
			message.addMessage("Policy Index"s, firstAvailableIndex);
			message.addMessage("Policy File Name"s, policyFileName);
			message.addMessage("Policy Name"s, dynamicPolicyName);
			return message;
		});
	}
	catch (policy_already_exists&)
	{
		// Ignore duplicate dynamic policy instance
	}
	catch (policy_not_in_idsp_list&)
	{
		destroyPolicy(firstAvailableIndex);
		firstAvailableIndex = Constants::Invalid;
	}
	catch (dynamic_policy_template_guid_invalid&)
	{
		destroyPolicy(firstAvailableIndex);
		firstAvailableIndex = Constants::Invalid;
	}
	catch (...)
	{
		destroyPolicy(firstAvailableIndex);
		throw;
	}

	return firstAvailableIndex;
}

void PolicyManager::destroyAllPolicies()
{
	const auto policyIndexes = MapOps<UIntN, shared_ptr<IPolicy>>::getKeys(m_policies);
	for (const auto& policyIndex : policyIndexes)
	{
		if (m_policies[policyIndex] != nullptr)
		{
			try
			{
				// Queue up a work item and wait for the return.
				auto workItem = make_shared<WIPolicyDestroy>(m_dptfManager, policyIndex);
				m_dptfManager->getWorkItemQueueManager()->enqueueImmediateWorkItemAndWait(workItem);
			}
			catch (...)
			{
				MANAGER_LOG_MESSAGE_ERROR({
					ManagerMessage message = ManagerMessage(
						m_dptfManager,
						_file,
						_line,
						_function,
						"Failed while trying to enqueue and wait for WIPolicyDestroy.");
					message.addMessage("Policy Index", policyIndex);
					return message;
				});
			}
		}
	}
}

void PolicyManager::destroyPolicy(UIntN policyIndex)
{
	const auto matchedPolicy = m_policies.find(policyIndex);
	if ((matchedPolicy != m_policies.end()) && (matchedPolicy->second != nullptr))
	{
		try
		{
			matchedPolicy->second->destroyPolicy();
		}
		catch (...)
		{
			MANAGER_LOG_MESSAGE_ERROR({
				ManagerMessage message =
					ManagerMessage(m_dptfManager, _file, _line, _function, "Failed while trying to destroy policy."s);
				message.addMessage("Policy Index"s, policyIndex);
				return message;
			});
		}

		m_policies.erase(matchedPolicy);
	}
}

void PolicyManager::reloadPolicy(const string& policyName)
{
	if (policyExists(policyName))
	{
		const auto policy = getPolicy(policyName);
		const auto index = policy->getPolicyIndex();
		const auto fileName = policy->getPolicyFileName();
		destroyPolicy(index);
		createPolicy(fileName);
	}
}

set<UIntN> PolicyManager::getPolicyIndexes() const
{
	return MapOps<UIntN, shared_ptr<IPolicy>>::getKeys(m_policies);
}

shared_ptr<ISupportedPolicyList> PolicyManager::getSupportedPolicyList() const
{
	return m_supportedPolicyList;
}

shared_ptr<ISupportedDynamicPolicyList> PolicyManager::getSupportedDynamicPolicyList() const
{
	return m_supportedDynamicPolicyList;
}

IPolicy* PolicyManager::getPolicyPtr(UIntN policyIndex)
{
	const auto matchedPolicy = m_policies.find(policyIndex);
	if ((matchedPolicy == m_policies.end()) || (matchedPolicy->second == nullptr))
	{
		throw policy_index_invalid();
	}

	return matchedPolicy->second.get();
}

void PolicyManager::registerEvent(UIntN policyIndex, PolicyEvent::Type policyEvent)
{
	if ((m_registeredEvents.test(policyEvent) == false) && (PolicyEvent::RequiresEsifEventRegistration(policyEvent)))
	{
		// Let ESIF know since the first policy is registering
		const FrameworkEvent::Type frameworkEvent = PolicyEvent::ToFrameworkEvent(policyEvent);
		m_dptfManager->getEsifServices()->registerEvent(frameworkEvent);
	}

	m_registeredEvents.set(policyEvent);
	dynamic_cast<Policy*>(getPolicyPtr(policyIndex))->registerEvent(policyEvent);
}

void PolicyManager::unregisterEvent(UIntN policyIndex, PolicyEvent::Type policyEvent)
{
	if (isAnyPolicyRegisteredForEvent(policyEvent) == true)
	{
		dynamic_cast<Policy*>(getPolicyPtr(policyIndex))->unregisterEvent(policyEvent);
		m_registeredEvents.set(policyEvent, isAnyPolicyRegisteredForEvent(policyEvent));

		if ((m_registeredEvents.test(policyEvent) == false)
			&& (PolicyEvent::RequiresEsifEventRegistration(policyEvent)))
		{
			const FrameworkEvent::Type frameworkEvent = PolicyEvent::ToFrameworkEvent(policyEvent);
			m_dptfManager->getEsifServices()->unregisterEvent(frameworkEvent);
		}
	}
}

shared_ptr<XmlNode> PolicyManager::getStatusAsXml()
{
	auto root = XmlNode::createRoot();
	root->addChild(XmlNode::createComment("format_id=10-E0-F6-61-4B-7D-F7-40-AE-90-CF-DA-99-0F-F9-1A"s));

	const auto eventStatus = XmlNode::createWrapperElement("policy_manager_event_status"s);
	eventStatus->addChild(getEventsInXml());

	for (auto& policy : m_policies)
	{
		try
		{
			if (policy.second != nullptr)
			{
				string name = policy.second->getName();
				const auto policyStatus = XmlNode::createWrapperElement("policy_event_status"s);
				const auto policyName = XmlNode::createDataElement("policy_name"s, name);
				policyStatus->addChild(policyName);
				policyStatus->addChild(getEventsXmlForPolicy(policy.first));
				eventStatus->addChild(policyStatus);
			}
		}
		catch (...)
		{
			// Policy not available, do not add.
		}
	}
	root->addChild(eventStatus);
	return root;
}

string PolicyManager::getDiagnosticsAsXml()
{
	const auto root = XmlNode::createRoot();
	return root->toString();
}

shared_ptr<IPolicy> PolicyManager::getPolicy(const string& policyName) const
{
	for (const auto& policy : m_policies)
	{
		if (policyName == policy.second->getName())
		{
			return policy.second;
		}
	}
	throw dptf_exception("Policy \""s + policyName + "\" not found."s);
}

Bool PolicyManager::policyExists(const string& policyName) const
{
	for (const auto& policy : m_policies)
	{
		if (policyName == policy.second->getName())
		{
			return true;
		}
	}
	return false;
}

Bool PolicyManager::IsDynamicPolicyTemplateFileName(const string& policyName) const
{
	// TODO : Make this as list if there are more policy templates
	const string policyTemplateFileName = "DptfPolicyAdaptivePerformance"s ESIF_LIB_EXT;

	if (policyName == policyTemplateFileName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PolicyManager::throwIfPolicyAlreadyExists(const string& policyFileName)
{
	for (auto policy = m_policies.begin(); policy != m_policies.end(); ++policy)
	{
		if (policy->second->getPolicyFileName() == policyFileName && policy->second->isDynamicPolicy() == false)
		{
			MANAGER_LOG_MESSAGE_DEBUG({
				ManagerMessage debugMessage =
					ManagerMessage(m_dptfManager, _file, _line, _function, "Policy instance already exists."s);
				debugMessage.setPolicyIndex(policy->first);
				debugMessage.addMessage("Policy Index"s, policy->first);
				debugMessage.addMessage("Policy File Name"s, policyFileName);
				return debugMessage;
			});
			throw policy_already_exists();
		}
	}
}

void PolicyManager::throwIfDynamicPolicyAlreadyExists(const string& policyFileName, const string& policyName)
{
	for (auto policy = m_policies.begin(); policy != m_policies.end(); ++policy)
	{
		if (policy->second->getPolicyFileName() == policyFileName && policy->second->getName() == policyName
			&& policy->second->isDynamicPolicy() == true)
		{
			MANAGER_LOG_MESSAGE_DEBUG({
				ManagerMessage debugMessage =
					ManagerMessage(m_dptfManager, _file, _line, _function, "Dynamic Policy instance already exists."s);
				debugMessage.setPolicyIndex(policy->first);
				debugMessage.addMessage("Policy Index"s, policy->first);
				debugMessage.addMessage("Policy File Name"s, policyFileName);
				debugMessage.addMessage("Policy Name"s, policyName);
				return debugMessage;
			});
			throw policy_already_exists();
		}
	}
}

Bool PolicyManager::isAnyPolicyRegisteredForEvent(PolicyEvent::Type policyEvent) const
{
	for (const auto& policy : m_policies)
	{
		const auto policyLink = dynamic_cast<Policy*>(policy.second.get());
		if (policyLink && 
		   (policyLink->isEventRegistered(policyEvent) == true))
		{
			return true;
		}
	}
	return false;
}

UIntN PolicyManager::getPolicyCount() const
{
	UIntN policyCount = 0;

	for (const auto& policy : m_policies)
	{
		if (policy.second != nullptr)
		{
			policyCount++;
		}
	}

	return policyCount;
}

shared_ptr<XmlNode> PolicyManager::getEventsXmlForPolicy(UIntN policyIndex)
{
	auto status = XmlNode::createWrapperElement("event_values"s);
	constexpr auto eventCount = PolicyEvent::Max;
	const auto policy = dynamic_cast<Policy*>(getPolicyPtr(policyIndex));
	if (policy)
	{
		for (auto eventIndex = 1; eventIndex < eventCount; eventIndex++) // Skip the "Invalid" event
		{
			const auto event = XmlNode::createWrapperElement("event"s);
			const auto eventName = XmlNode::createDataElement(
				"event_name"s, PolicyEvent::toString(static_cast<PolicyEvent::Type>(eventIndex)));
			event->addChild(eventName);
			const auto eventStatus = XmlNode::createDataElement(
				"event_status"s, friendlyValue(policy->isEventRegistered(static_cast<PolicyEvent::Type>(eventIndex))));
			event->addChild(eventStatus);
			status->addChild(event);
		}
	}
	return status;
}

shared_ptr<XmlNode> PolicyManager::getEventsInXml()
{
	auto status = XmlNode::createWrapperElement("events"s);
	constexpr auto eventCount = PolicyEvent::Max;
	for (auto eventIndex = 1; eventIndex < eventCount; eventIndex++) // Skip the "Invalid" event
	{
		const auto event = XmlNode::createWrapperElement("event"s);
		const auto eventName = XmlNode::createDataElement("event_name"s, PolicyEvent::toString(static_cast<PolicyEvent::Type>(eventIndex)));
		event->addChild(eventName);
		status->addChild(event);
	}
	return status;
}

EsifServicesInterface* PolicyManager::getEsifServices() const
{
	return m_dptfManager->getEsifServices();
}
