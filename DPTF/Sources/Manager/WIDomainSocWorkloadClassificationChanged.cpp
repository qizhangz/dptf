/******************************************************************************
** Copyright (c) 2013-2022 Intel Corporation All Rights Reserved
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

#include "WIDomainSocWorkloadClassificationChanged.h"
#include "PolicyManagerInterface.h"
#include "Participant.h"
#include "EsifServicesInterface.h"

WIDomainSocWorkloadClassificationChanged::WIDomainSocWorkloadClassificationChanged(
	DptfManagerInterface* dptfManager,
	UIntN participantIndex,
	UIntN domainIndex,
	SocWorkloadClassification::Type socWorkloadClassification)
	: DomainWorkItem(dptfManager, FrameworkEvent::DomainSocWorkloadClassificationChanged, participantIndex, domainIndex)
	, m_socWorkloadClassification(socWorkloadClassification)
{
}

WIDomainSocWorkloadClassificationChanged::~WIDomainSocWorkloadClassificationChanged(void)
{
}

void WIDomainSocWorkloadClassificationChanged::onExecute(void)
{
	writeDomainWorkItemStartingInfoMessage();

	try
	{
		getParticipantPtr()->domainSocWorkloadClassificationChanged(m_socWorkloadClassification);
	}
	catch (participant_index_invalid& ex)
	{
		writeDomainWorkItemWarningMessage(ex, "ParticipantManager::getParticipantPtr");
	}
	catch (std::exception& ex)
	{
		writeDomainWorkItemErrorMessage(ex, "Participant::domainSocWorkloadClassificationChanged");
	}

	auto policyManager = getPolicyManager();
	auto policyIndexes = policyManager->getPolicyIndexes();

	for (auto i = policyIndexes.begin(); i != policyIndexes.end(); ++i)
	{
		try
		{
			auto policy = policyManager->getPolicyPtr(*i);
			policy->executeDomainSocWorkloadClassificationChanged(getParticipantIndex(), getDomainIndex(), m_socWorkloadClassification);
		}
		catch (policy_index_invalid&)
		{
			// do nothing.  No item in the policy list at this index.
		}
		catch (std::exception& ex)
		{
			writeDomainWorkItemErrorMessagePolicy(ex, "Policy::executeDomainSocWorkloadClassificationChanged", *i);
		}
	}
}
