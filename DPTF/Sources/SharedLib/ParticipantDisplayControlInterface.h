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
#include "DisplayControlDynamicCaps.h"
#include "DisplayControlStatus.h"
#include "DisplayControlSet.h"

// (PD) Putting this on hold for now.  See e-mail chain from 5/21 when there is time to
//      revisit and correct.

class dptf_export ParticipantDisplayControlInterface
{
public:
	//    virtual DisplayControlDynamicCaps getDisplayControlDynamicCaps(UIntN participantIndex, UIntN domainIndex) = 0;
	//    virtual DisplayControlStatus getDisplayControlStatus(UIntN participantIndex, UIntN domainIndex) = 0;
	//    virtual DisplayControlSet getDisplayControlSet(UIntN participantIndex, UIntN domainIndex) = 0;
	//    virtual void setDisplayControl(UIntN participantIndex, UIntN domainIndex, UIntN displayControlIndex) = 0;
};