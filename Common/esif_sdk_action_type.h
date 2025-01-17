/*******************************************************************************
** This file is provided under a dual BSD/GPLv2 license.  When using or
** redistributing this file, you may do so under either license.
**
** GPL LICENSE SUMMARY
**
** Copyright (c) 2013-2022 Intel Corporation All Rights Reserved
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of version 2 of the GNU General Public License as published by the
** Free Software Foundation.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
** details.
**
** You should have received a copy of the GNU General Public License along with
** this program; if not, write to the Free Software  Foundation, Inc.,
** 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
** The full GNU General Public License is included in this distribution in the
** file called LICENSE.GPL.
**
** BSD LICENSE
**
** Copyright (c) 2013-2022 Intel Corporation All Rights Reserved
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice, this
**   list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer in the documentation
**   and/or other materials provided with the distribution.
** * Neither the name of Intel Corporation nor the names of its contributors may
**   be used to endorse or promote products derived from this software without
**   specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

#pragma once

#include "esif_sdk.h"

/*
 * Action Type Declarations
 */

typedef enum esif_action_type {
	ESIF_ACTION_ACPI = 4,
	ESIF_ACTION_ACPIDECIC = 55,
	ESIF_ACTION_ACPILPAT = 40,
	ESIF_ACTION_BATTERY = 75,
	ESIF_ACTION_CAPI = 83,
	ESIF_ACTION_CODE = 38,
	ESIF_ACTION_CONFIG = 20,
	ESIF_ACTION_CONST = 33,
	ESIF_ACTION_DDIGFXDISP = 35,
	ESIF_ACTION_DDIGFXPERF = 36,
	ESIF_ACTION_DELEGATE = 60,
	ESIF_ACTION_DGFX = 70,
	ESIF_ACTION_DPPEBRT = 32,
	ESIF_ACTION_DPTFWWAN = 50,
	ESIF_ACTION_HWPF = 80,
	ESIF_ACTION_IDGFX = 78,
	ESIF_ACTION_IOC = 74,
	ESIF_ACTION_IOSF = 34,
	ESIF_ACTION_JAVA = 62,
	ESIF_ACTION_KACACHE = 85,
	ESIF_ACTION_KDELEGATE = 52,
	ESIF_ACTION_KHID = 73,
	ESIF_ACTION_KIOCTL = 64,
	ESIF_ACTION_KODE = 29,
	ESIF_ACTION_KONST = 1,
	ESIF_ACTION_MMIO = 2,
	ESIF_ACTION_MMIODIV2 = 56,
	ESIF_ACTION_MMIOTJMAX = 48,
	ESIF_ACTION_MMIOTJMAXROUNDDOWN = 66,
	ESIF_ACTION_MMIOTJMAXROUNDUP = 67,
	ESIF_ACTION_MSR = 22,
	ESIF_ACTION_MSRTEMPC = 72,
	ESIF_ACTION_NVAPI = 82,
	ESIF_ACTION_NVME = 63,
	ESIF_ACTION_OSTF = 68,
	ESIF_ACTION_PERC = 61,
	ESIF_ACTION_PHIDGET = 69,
	ESIF_ACTION_PLATPOWER = 71,
	ESIF_ACTION_PSM = 44,
	ESIF_ACTION_RFPWIFI = 43,
	ESIF_ACTION_SIM = 65,
	ESIF_ACTION_SOCWC = 77,
	ESIF_ACTION_SYSFS = 59,
	ESIF_ACTION_SYSTEM = 31,
	ESIF_ACTION_USBCM = 76,
	ESIF_ACTION_USBFAN = 49,
	ESIF_ACTION_VIRTUAL = 39,
	ESIF_ACTION_VPU = 84,
} esif_action_type_t;

/* Max Enum Value for Iteration purposes */
#define MAX_ESIF_ACTION_ENUM_VALUE  ESIF_ACTION_KACACHE

static ESIF_INLINE esif_string esif_action_type_str(esif_action_type_t type)
{
	switch (type) {
	ESIF_CASE_ENUM(ESIF_ACTION_ACPI);
	ESIF_CASE_ENUM(ESIF_ACTION_ACPIDECIC);
	ESIF_CASE_ENUM(ESIF_ACTION_ACPILPAT);
	ESIF_CASE_ENUM(ESIF_ACTION_BATTERY);
	ESIF_CASE_ENUM(ESIF_ACTION_CAPI);
	ESIF_CASE_ENUM(ESIF_ACTION_CODE);
	ESIF_CASE_ENUM(ESIF_ACTION_CONFIG);
	ESIF_CASE_ENUM(ESIF_ACTION_CONST);
	ESIF_CASE_ENUM(ESIF_ACTION_DDIGFXDISP);
	ESIF_CASE_ENUM(ESIF_ACTION_DDIGFXPERF);
	ESIF_CASE_ENUM(ESIF_ACTION_DELEGATE);
	ESIF_CASE_ENUM(ESIF_ACTION_DGFX);
	ESIF_CASE_ENUM(ESIF_ACTION_DPPEBRT);
	ESIF_CASE_ENUM(ESIF_ACTION_DPTFWWAN);
	ESIF_CASE_ENUM(ESIF_ACTION_HWPF);
	ESIF_CASE_ENUM(ESIF_ACTION_IDGFX);
	ESIF_CASE_ENUM(ESIF_ACTION_IOC);
	ESIF_CASE_ENUM(ESIF_ACTION_IOSF);
	ESIF_CASE_ENUM(ESIF_ACTION_JAVA);
	ESIF_CASE_ENUM(ESIF_ACTION_KACACHE);
	ESIF_CASE_ENUM(ESIF_ACTION_KDELEGATE);
	ESIF_CASE_ENUM(ESIF_ACTION_KHID);
	ESIF_CASE_ENUM(ESIF_ACTION_KIOCTL);
	ESIF_CASE_ENUM(ESIF_ACTION_KODE);
	ESIF_CASE_ENUM(ESIF_ACTION_KONST);
	ESIF_CASE_ENUM(ESIF_ACTION_MMIO);
	ESIF_CASE_ENUM(ESIF_ACTION_MMIODIV2);
	ESIF_CASE_ENUM(ESIF_ACTION_MMIOTJMAX);
	ESIF_CASE_ENUM(ESIF_ACTION_MMIOTJMAXROUNDDOWN);
	ESIF_CASE_ENUM(ESIF_ACTION_MMIOTJMAXROUNDUP);
	ESIF_CASE_ENUM(ESIF_ACTION_MSR);
	ESIF_CASE_ENUM(ESIF_ACTION_MSRTEMPC);
	ESIF_CASE_ENUM(ESIF_ACTION_NVAPI);
	ESIF_CASE_ENUM(ESIF_ACTION_NVME);
	ESIF_CASE_ENUM(ESIF_ACTION_OSTF);
	ESIF_CASE_ENUM(ESIF_ACTION_PERC);
	ESIF_CASE_ENUM(ESIF_ACTION_PHIDGET);
	ESIF_CASE_ENUM(ESIF_ACTION_PLATPOWER);
	ESIF_CASE_ENUM(ESIF_ACTION_PSM);
	ESIF_CASE_ENUM(ESIF_ACTION_RFPWIFI);
	ESIF_CASE_ENUM(ESIF_ACTION_SIM);
	ESIF_CASE_ENUM(ESIF_ACTION_SOCWC);
	ESIF_CASE_ENUM(ESIF_ACTION_SYSFS);
	ESIF_CASE_ENUM(ESIF_ACTION_SYSTEM);
	ESIF_CASE_ENUM(ESIF_ACTION_USBCM);
	ESIF_CASE_ENUM(ESIF_ACTION_USBFAN);
	ESIF_CASE_ENUM(ESIF_ACTION_VIRTUAL);
	ESIF_CASE_ENUM(ESIF_ACTION_VPU);
	}
	return ESIF_NOT_AVAILABLE;
}


#ifdef esif_ccb_stricmp
static ESIF_INLINE esif_action_type_t esif_action_type_str2enum(esif_string name)
{
	static struct esif_action_type_map_t {
		esif_action_type_t type;
		esif_string name;
	}
	esif_action_type_map[] = {
		ESIF_MAP_ENUM(ESIF_ACTION_ACPI),
		ESIF_MAP_ENUM(ESIF_ACTION_ACPIDECIC),
		ESIF_MAP_ENUM(ESIF_ACTION_ACPILPAT),
		ESIF_MAP_ENUM(ESIF_ACTION_BATTERY),
		ESIF_MAP_ENUM(ESIF_ACTION_CAPI),
		ESIF_MAP_ENUM(ESIF_ACTION_CODE),
		ESIF_MAP_ENUM(ESIF_ACTION_CONFIG),
		ESIF_MAP_ENUM(ESIF_ACTION_CONST),
		ESIF_MAP_ENUM(ESIF_ACTION_DDIGFXDISP),
		ESIF_MAP_ENUM(ESIF_ACTION_DDIGFXPERF),
		ESIF_MAP_ENUM(ESIF_ACTION_DELEGATE),
		ESIF_MAP_ENUM(ESIF_ACTION_DGFX),
		ESIF_MAP_ENUM(ESIF_ACTION_DPPEBRT),
		ESIF_MAP_ENUM(ESIF_ACTION_DPTFWWAN),
		ESIF_MAP_ENUM(ESIF_ACTION_HWPF),
		ESIF_MAP_ENUM(ESIF_ACTION_IDGFX),
		ESIF_MAP_ENUM(ESIF_ACTION_IOC),
		ESIF_MAP_ENUM(ESIF_ACTION_IOSF),
		ESIF_MAP_ENUM(ESIF_ACTION_JAVA),
		ESIF_MAP_ENUM(ESIF_ACTION_KACACHE),
		ESIF_MAP_ENUM(ESIF_ACTION_KDELEGATE),
		ESIF_MAP_ENUM(ESIF_ACTION_KHID),
		ESIF_MAP_ENUM(ESIF_ACTION_KIOCTL),
		ESIF_MAP_ENUM(ESIF_ACTION_KODE),
		ESIF_MAP_ENUM(ESIF_ACTION_KONST),
		ESIF_MAP_ENUM(ESIF_ACTION_MMIO),
		ESIF_MAP_ENUM(ESIF_ACTION_MMIODIV2),
		ESIF_MAP_ENUM(ESIF_ACTION_MMIOTJMAX),
		ESIF_MAP_ENUM(ESIF_ACTION_MMIOTJMAXROUNDDOWN),
		ESIF_MAP_ENUM(ESIF_ACTION_MMIOTJMAXROUNDUP),
		ESIF_MAP_ENUM(ESIF_ACTION_MSR),
		ESIF_MAP_ENUM(ESIF_ACTION_MSRTEMPC),
		ESIF_MAP_ENUM(ESIF_ACTION_NVAPI),
		ESIF_MAP_ENUM(ESIF_ACTION_NVME),
		ESIF_MAP_ENUM(ESIF_ACTION_OSTF),
		ESIF_MAP_ENUM(ESIF_ACTION_PERC),
		ESIF_MAP_ENUM(ESIF_ACTION_PHIDGET),
		ESIF_MAP_ENUM(ESIF_ACTION_PLATPOWER),
		ESIF_MAP_ENUM(ESIF_ACTION_PSM),
		ESIF_MAP_ENUM(ESIF_ACTION_RFPWIFI),
		ESIF_MAP_ENUM(ESIF_ACTION_SIM),
		ESIF_MAP_ENUM(ESIF_ACTION_SOCWC),
		ESIF_MAP_ENUM(ESIF_ACTION_SYSFS),
		ESIF_MAP_ENUM(ESIF_ACTION_SYSTEM),
		ESIF_MAP_ENUM(ESIF_ACTION_USBCM),
		ESIF_MAP_ENUM(ESIF_ACTION_USBFAN),
		ESIF_MAP_ENUM(ESIF_ACTION_VIRTUAL),
		ESIF_MAP_ENUM(ESIF_ACTION_VPU),
	};

	/* Match ESIF_ACTION_TYPENAME or TYPENAME using a Binary Search */
	int start = 0, end = ESIF_ARRAY_LEN(esif_action_type_map) - 1, node = ESIF_ARRAY_LEN(esif_action_type_map) / 2;
	size_t prefix = (esif_ccb_strnicmp(name, "ESIF_ACTION_", 12) == 0 ? 0 : 12);
	while (start <= end) {
		int comp = esif_ccb_stricmp(name, esif_action_type_map[node].name + prefix);
		if (comp == 0) {
			return esif_action_type_map[node].type;
		}
		else if (comp > 0) {
			start = node + 1;
		}
		else {
			end = node - 1;
		}
		node = (end - start) / 2 + start;
	}
	return (esif_action_type_t)0;
}
#endif


/*
 * Action MSR Hint Declarations
 */

enum esif_action_msr_hint {
	ESIF_ACTION_MSR_HINT_UNI = 1,
	ESIF_ACTION_MSR_HINT_MAX = 2,
	ESIF_ACTION_MSR_HINT_MIN = 3,
	ESIF_ACTION_MSR_HINT_MUL = 4,
	ESIF_ACTION_MSR_HINT_SPECIFIC = 5,
};

static ESIF_INLINE esif_string esif_action_msr_hint_str(
	enum esif_action_msr_hint hint
	)
{
	switch (hint) {
	ESIF_CASE_ENUM(ESIF_ACTION_MSR_HINT_UNI);
	ESIF_CASE_ENUM(ESIF_ACTION_MSR_HINT_MAX);
	ESIF_CASE_ENUM(ESIF_ACTION_MSR_HINT_MIN);
	ESIF_CASE_ENUM(ESIF_ACTION_MSR_HINT_MUL);
	ESIF_CASE_ENUM(ESIF_ACTION_MSR_HINT_SPECIFIC);
	}
	return ESIF_NOT_AVAILABLE;
}
