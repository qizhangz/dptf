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
#include "DomainActivityStatusBase.h"
#include "CachedValue.h"
#include "CoreActivityInfo.h"

class DomainActivityStatus_001 : public DomainActivityStatusBase
{
public:
	DomainActivityStatus_001(
		UIntN participantIndex,
		UIntN domainIndex,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface);
	virtual ~DomainActivityStatus_001();

	virtual Percentage getUtilizationThreshold(UIntN participantIndex, UIntN domainIndex) override;
	virtual Percentage getResidencyUtilization(UIntN participantIndex, UIntN domainIndex) override;
	virtual UInt64 getCoreActivityCounter(UIntN participantIndex, UIntN domainIndex) override;
	virtual UInt32 getCoreActivityCounterWidth(UIntN participantIndex, UIntN domainIndex) override;
	virtual UInt64 getTimestampCounter(UIntN participantIndex, UIntN domainIndex) override;
	virtual UInt32 getTimestampCounterWidth(UIntN participantIndex, UIntN domainIndex) override;
	virtual CoreActivityInfo getCoreActivityInfo(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setPowerShareEffectiveBias(UIntN participantIndex, UIntN domainIndex, UInt32 powerShareEffectiveBias)
		override;

	// ParticipantActivityLoggingInterface
	virtual void sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex) override;

	// ComponentExtendedInterface
	virtual void onClearCachedData(void) override;
	virtual std::string getName(void) override;
	virtual std::shared_ptr<XmlNode> getXml(UIntN domainIndex) override;

private:
	// hide the copy constructor and = operator
	DomainActivityStatus_001(const DomainActivityStatus_001& rhs);
	DomainActivityStatus_001& operator=(const DomainActivityStatus_001& rhs);
};
