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

#include "DomainRfProfileControl_000.h"

DomainRfProfileControl_000::DomainRfProfileControl_000(
	UIntN participantIndex,
	UIntN domainIndex,
	std::shared_ptr<ParticipantServicesInterface> participantServicesInterface)
	: DomainRfProfileControlBase(participantIndex, domainIndex, participantServicesInterface)
{
	// Do nothing.  Not an error.
}

RfProfileCapabilities DomainRfProfileControl_000::getRfProfileCapabilities(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

void DomainRfProfileControl_000::setRfProfileCenterFrequency(
	UIntN participantIndex,
	UIntN domainIndex,
	const Frequency& centerFrequency)
{
	throw not_implemented();
}

Percentage DomainRfProfileControl_000::getSscBaselineSpreadValue(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

Percentage DomainRfProfileControl_000::getSscBaselineThreshold(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

Percentage DomainRfProfileControl_000::getSscBaselineGuardBand(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

void DomainRfProfileControl_000::sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

void DomainRfProfileControl_000::onClearCachedData(void)
{
	// Do nothing.  Not an error.
}

std::shared_ptr<XmlNode> DomainRfProfileControl_000::getXml(UIntN domainIndex)
{
	throw not_implemented();
}

std::string DomainRfProfileControl_000::getName(void)
{
	return "RF Profile Control (Version 0)";
}