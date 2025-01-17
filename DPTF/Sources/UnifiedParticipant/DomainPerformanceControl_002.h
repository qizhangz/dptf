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
#include "DomainPerformanceControlBase.h"
#include "CachedValue.h"

// Processor Participant Performance Controls

class DomainPerformanceControl_002 : public DomainPerformanceControlBase
{
public:
	DomainPerformanceControl_002(
		UIntN participantIndex,
		UIntN domainIndex,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface);
	virtual ~DomainPerformanceControl_002(void);

	// DomainPerformanceControlInterface
	virtual PerformanceControlStaticCaps getPerformanceControlStaticCaps(UIntN participantIndex, UIntN domainIndex)
		override;
	virtual PerformanceControlDynamicCaps getPerformanceControlDynamicCaps(UIntN participantIndex, UIntN domainIndex)
		override;
	virtual PerformanceControlStatus getPerformanceControlStatus(UIntN participantIndex, UIntN domainIndex) override;
	virtual PerformanceControlSet getPerformanceControlSet(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setPerformanceControl(UIntN participantIndex, UIntN domainIndex, UIntN performanceControlIndex)
		override;
	virtual void setPerformanceControlDynamicCaps(
		UIntN participantIndex,
		UIntN domainIndex,
		PerformanceControlDynamicCaps newCapabilities) override;
	virtual void setPerformanceCapsLock(UIntN participantIndex, UIntN domainIndex, Bool lock) override;

	// ComponentExtendedInterface
	virtual void onClearCachedData(void) override;
	virtual std::string getName(void) override;
	virtual std::shared_ptr<XmlNode> getXml(UIntN domainIndex) override;

protected:
	virtual void capture(void) override;
	virtual void restore(void) override;
	virtual UIntN getCurrentPerformanceControlIndex(UIntN participantIndex, UIntN domainIndex) override;

private:
	// hide the copy constructor and = operator
	DomainPerformanceControl_002(const DomainPerformanceControl_002& rhs);
	DomainPerformanceControl_002& operator=(const DomainPerformanceControl_002& rhs);

	PerformanceControlSet createCombinedPerformanceControlSet(UIntN domainIndex);
	PerformanceControlDynamicCaps createPerformanceControlDynamicCaps(UIntN domainIndex);
	void createPerformanceControlStatus(void);
	void arbitratePerformanceStateLimits(
		UIntN domainIndex,
		UIntN pStateUpperLimitIndex,
		UIntN pStateLowerLimitIndex,
		UIntN tStateUpperLimitIndex,
		UIntN tStateLowerLimitIndex,
		UIntN& performanceUpperLimitIndex,
		UIntN& performanceLowerLimitIndex);
	void calculateThrottlingStateLimits(UIntN& tStateUpperLimitIndex, UIntN& tStateLowerLimitIndex, UIntN domainIndex);
	void calculatePerformanceStateLimits(UIntN& pStateUpperLimitIndex, UIntN& pStateLowerLimitIndex, UIntN domainIndex);
	UIntN snapIfPerformanceControlIndexIsOutOfBounds(UIntN domainIndex, UIntN performanceControlIndex);
	PerformanceControlStaticCaps createPerformanceControlStaticCaps(void);
	PerformanceControlSet createPerformanceStateSet(UIntN domainIndex);
	PerformanceControlSet getPerformanceStateSet(UIntN domainIndex);
	PerformanceControlSet getThrottlingStateSet(UIntN domainIndex);
	PerformanceControlSet createThrottlingStateSet(UIntN domainIndex);
	Bool isFirstTstateDeleted(UIntN domainIndex);

	CachedValue<PerformanceControlStaticCaps> m_performanceControlStaticCaps;
	CachedValue<PerformanceControlDynamicCaps> m_performanceControlDynamicCaps; // TODO : Ling - do we need this?
	CachedValue<PerformanceControlSet> m_performanceControlSet;
	CachedValue<PerformanceControlStatus> m_performanceControlStatus;
	CachedValue<PerformanceControlSet> m_performanceStateSet; // P-states
	CachedValue<PerformanceControlSet> m_throttlingStateSet; // T-states
	UIntN m_tdpFrequencyLimitControlIndex; // TODO: Ling - highly unlikely we'd still need this
	CachedValue<Bool> m_isFirstTstateDeleted;
	CachedValue<PerformanceControlDynamicCaps> m_initialStatus;
	Bool m_capabilitiesLocked;
};
