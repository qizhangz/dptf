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
#include "CachedProperty.h"
#include "PolicyServicesInterfaceContainer.h"
#include "SpecificInfo.h"
#include "ParticipantProperty.h"

class dptf_export CriticalTripPointsCachedProperty : public CachedProperty, ParticipantProperty
{
public:
	CriticalTripPointsCachedProperty(const PolicyServicesInterfaceContainer& policyServices, UIntN participantIndex);
	~CriticalTripPointsCachedProperty();

	const SpecificInfo& getTripPoints();
	virtual Bool supportsProperty() override;

	std::shared_ptr<XmlNode> getXml();

protected:
	virtual void refreshData() override;

private:
	SpecificInfo m_criticalTripPoints;
};
