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
#include "DomainType.h"
#include "DomainFunctionalityVersions.h"
#include "XmlNode.h"

class DomainProperties final
{
public:
	DomainProperties(
		Guid guid,
		UIntN domainIndex,
		Bool domainEnabled,
		DomainType::Type domainType,
		std::string domainName,
		std::string domainDescription,
		DomainFunctionalityVersions domainFunctionalityVersions);

	Guid getGuid(void) const;
	UIntN getDomainIndex(void) const;
	Bool isEnabled(void) const;
	DomainType::Type getDomainType(void) const;
	std::string getName(void) const;
	std::string getDescription(void) const;

	Bool implementsActiveControlInterface(void) const;
	Bool implementsActivityStatusInterface(void) const;
	Bool implementsCoreControlInterface(void) const;
	Bool implementsDisplayControlInterface(void) const;
	Bool implementsEnergyControlInterface(void) const;
	Bool implementsPeakPowerControlInterface(void) const;
	Bool implementsPerformanceControlInterface(void) const;
	Bool implementsPowerControlInterface(void) const;
	Bool implementsSystemPowerControlInterface(void) const;
	Bool implementsBatteryStatusInterface(void) const;
	Bool implementsPlatformPowerStatusInterface(void) const;
	Bool implementsPowerStatusInterface(void) const;
	Bool implementsDomainPriorityInterface(void) const;
	Bool implementsRfProfileControlInterface(void) const;
	Bool implementsRfProfileStatusInterface(void) const;
	Bool implementsTemperatureInterface(void) const;
	Bool implementsTemperatureThresholdInterface(void) const;
	Bool implementsProcessorControlInterface(void) const;
	Bool implementsUtilizationInterface(void) const;
	Bool implementsSocWorkloadClassificationInterface(void) const;
	Bool implementsDynamicEppInterface() const;

	Bool operator==(const DomainProperties& domain);
	Bool operator!=(const DomainProperties& domain);

	std::shared_ptr<XmlNode> getXml() const;

private:
	Guid m_guid;
	UIntN m_domainIndex;
	Bool m_enabled;
	DomainType::Type m_domainType;
	std::string m_name;
	std::string m_description;
	DomainFunctionalityVersions m_domainFunctionalityVersions;

	Bool isInterfaceImplemented(UInt8 version) const;
};
