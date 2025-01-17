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

#pragma once

#include "Dptf.h"
#include "DomainCoreControlBase.h"
#include "CachedValue.h"

//
// Core Controls (Processor)
//

class DomainCoreControl_001 : public DomainCoreControlBase
{
public:
	DomainCoreControl_001(
		UIntN participantIndex,
		UIntN domainIndex,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface);
	virtual ~DomainCoreControl_001(void);

	// DomainCoreControlInterface
	virtual CoreControlStaticCaps getCoreControlStaticCaps(UIntN participantIndex, UIntN domainIndex) override;
	virtual CoreControlDynamicCaps getCoreControlDynamicCaps(UIntN participantIndex, UIntN domainIndex) override;
	virtual CoreControlLpoPreference getCoreControlLpoPreference(UIntN participantIndex, UIntN domainIndex) override;
	virtual CoreControlStatus getCoreControlStatus(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setActiveCoreControl(
		UIntN participantIndex,
		UIntN domainIndex,
		const CoreControlStatus& coreControlStatus) override;

	// ParticipantActivityLoggingInterface
	virtual void sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex) override;

	// ComponentExtendedInterface
	virtual void onClearCachedData(void) override;
	virtual std::string getName(void) override;
	virtual std::shared_ptr<XmlNode> getXml(UIntN domainIndex) override;

protected:
	virtual void restore(void) override;

private:
	// hide the copy constructor and = operator
	DomainCoreControl_001(const DomainCoreControl_001& rhs);
	DomainCoreControl_001& operator=(const DomainCoreControl_001& rhs);

	// Functions
	CoreControlStaticCaps createCoreControlStaticCaps(UIntN domainIndex);
	CoreControlDynamicCaps createCoreControlDynamicCaps(UIntN domainIndex);
	void verifyCoreControlStatus(UIntN domainIndex, const CoreControlStatus& coreControlStatus);

	// Vars (external)
	CachedValue<CoreControlStaticCaps> m_coreControlStaticCaps;
	CachedValue<CoreControlDynamicCaps> m_coreControlDynamicCaps;
	CachedValue<CoreControlStatus> m_coreControlStatus;
};
