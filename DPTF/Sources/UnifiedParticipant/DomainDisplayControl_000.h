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
#include "DomainDisplayControlBase.h"

//
// Implements the Null Object pattern.  In the case that the functionality isn't implemented, we use
// this in place so we don't have to check for NULL pointers all throughout the participant implementation.
//

class DomainDisplayControl_000 : public DomainDisplayControlBase
{
public:
	DomainDisplayControl_000(
		UIntN participantIndex,
		UIntN domainIndex,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface);

	virtual DisplayControlDynamicCaps getDisplayControlDynamicCaps(UIntN participantIndex, UIntN domainIndex) override;
	virtual DisplayControlStatus getDisplayControlStatus(UIntN participantIndex, UIntN domainIndex) override;
	virtual UIntN getUserPreferredDisplayIndex(UIntN participantIndex, UIntN domainIndex) override;
	virtual UIntN getUserPreferredSoftBrightnessIndex(UIntN participantIndex, UIntN domainIndex) override;
	virtual Bool isUserPreferredIndexModified(UIntN participantIndex, UIntN domainIndex) override;
	virtual UIntN getSoftBrightnessIndex(UIntN participantIndex, UIntN domainIndex) override;
	virtual void updateUserPreferredSoftBrightnessIndex(UIntN participantIndex, UIntN domainIndex) override;
	virtual DisplayControlSet getDisplayControlSet(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setDisplayControl(UIntN participantIndex, UIntN domainIndex, UIntN displayControlIndex) override;
	virtual void setSoftBrightness(UIntN participantIndex, UIntN domainIndex, UIntN displayControlIndex) override;
	virtual void restoreUserPreferredSoftBrightness(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setDisplayControlDynamicCaps(
		UIntN participantIndex,
		UIntN domainIndex,
		DisplayControlDynamicCaps newCapabilities) override;
	virtual void setDisplayCapsLock(UIntN participantIndex, UIntN domainIndex, Bool lock) override;

	// ParticipantActivityLoggingInterface
	virtual void sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex) override;

	// ComponentExtendedInterface
	virtual void onClearCachedData(void) override;
	virtual std::string getName(void) override;
	virtual std::shared_ptr<XmlNode> getXml(UIntN domainIndex) override;
};
