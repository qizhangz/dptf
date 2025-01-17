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

#include "TimeOps.h"
#include "EsifTime.h"
#include <string>
#include <sstream>

using namespace std;

std::string TimeOps::generateTimestampNowAsString()
{
	EsifTime timeGenerator;
	auto localTime = timeGenerator.getLocalTime();
	stringstream timestamp;
	timestamp << setfill('0') << setw(4) << (1900 + localTime.tm_year);
	timestamp << setfill('0') << setw(2) << (1 + localTime.tm_mon);
	timestamp << setfill('0') << setw(2) << (0 + localTime.tm_mday);
	timestamp << setfill('0') << setw(2) << (0 + localTime.tm_hour);
	timestamp << setfill('0') << setw(2) << (0 + localTime.tm_min);
	timestamp << setfill('0') << setw(2) << (0 + localTime.tm_sec);
	return timestamp.str();
}
