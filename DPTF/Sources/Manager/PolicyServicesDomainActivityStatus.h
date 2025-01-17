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
#include "PolicyServices.h"
#include "DomainActivityStatusInterface.h"
#include "CoreActivityInfo.h"

class PolicyServicesDomainActivityStatus final : public PolicyServices, public DomainActivityStatusInterface
{
public:
	PolicyServicesDomainActivityStatus(DptfManagerInterface* dptfManager, UIntN policyIndex);

	virtual Percentage getUtilizationThreshold(UIntN participantIndex, UIntN domainIndex) override final;
	virtual Percentage getResidencyUtilization(UIntN participantIndex, UIntN domainIndex) override final;
	virtual UInt64 getCoreActivityCounter(UIntN participantIndex, UIntN domainIndex) override final;
	virtual UInt32 getCoreActivityCounterWidth(UIntN participantIndex, UIntN domainIndex) override final;
	virtual UInt64 getTimestampCounter(UIntN participantIndex, UIntN domainIndex) override final;
	virtual UInt32 getTimestampCounterWidth(UIntN participantIndex, UIntN domainIndex) override final;
	virtual CoreActivityInfo getCoreActivityInfo(UIntN participantIndex, UIntN domainIndex) override final;
	virtual void setPowerShareEffectiveBias(UIntN participantIndex, UIntN domainIndex, 
		UInt32 powerShareEffectiveBias) override final;
	virtual UInt32 getSocDgpuPerformanceHintPoints(UIntN participantIndex, UIntN domainIndex) override final; 
};
