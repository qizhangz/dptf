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
#include <string>

namespace DptfRequestType
{
	enum Enum
	{
		// All Controls
		ClearPolicyRequestsForAllControls,
		ClearCachedData,

		// Active Control
		ActiveControlGetStaticCaps,
		ActiveControlGetDynamicCaps,
		ActiveControlGetStatus,
		ActiveControlGetControlSet,
		ActiveControlSetFanSpeed,
		ActiveControlSetDynamicCaps,
		ActiveControlSetFanCapsLock,
		ActiveControlSetFanDirection,

		// Battery Status
		BatteryStatusGetMaxBatteryPower,
		BatteryStatusGetBatteryStatus,
		BatteryStatusGetBatteryInformation,
		BatteryStatusGetChargerType,
		BatteryStatusGetBatterySteadyState,
		BatteryStatusGetBatteryHighFrequencyImpedance,
		BatteryStatusGetBatteryNoLoadVoltage,
		BatteryStatusGetBatteryMaxPeakCurrent,
		BatteryStatusGetBatteryPercentage,
		BatteryStatusSetBatteryPercentage,

		// Processor Control
		ProcessorControlSetUnderVoltageThreshold,
		ProcessorControlSetTccOffsetTemperature,
		ProcessorControlGetMaxTccOffsetTemperature,
		ProcessorControlGetMinTccOffsetTemperature,

		// TemperatureControl
		TemperatureControlGetTemperatureStatus,
		TemperatureControlGetTemperatureThresholds,
		TemperatureControlSetTemperatureThresholds,
		TemperatureControlGetPowerShareTemperatureThreshold,
		TemperatureControlGetCalibrationTable,
		TemperatureControlGetPollingTable,
		TemperatureControlIsVirtualTemperatureControl,
		TemperatureControlSetVirtualTemperature,

		// Soc Workload Classification
		SocWorkloadClassificationGetSocWorkload,

		// Dynamic EPP
		DynamicEppGetEppSensitivityHint,
		DynamicEppGetDynamicEppSupport,
		DynamicEppSetDynamicEppSupport,

		// Platform Notification
		PlatformNotificationSetOsc,
		PlatformNotificationSetApplicationAliveResponse,
		PlatformNotificationSetPolicySystemMode,
		PlatformNotificationAppBroadcastSend,

		// END
		END
	};

	std::string ToString(DptfRequestType::Enum requestType);
};
