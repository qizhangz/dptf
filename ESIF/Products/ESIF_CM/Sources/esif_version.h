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

#ifndef _ESIF_VERSION_H_
#define _ESIF_VERSION_H_

#include "Ver.h"

#define STR(arg) #arg
#define STR2(arg) STR(##arg)
#define EXPAND_TOSTR(arg) STR(arg)

#define ESIF_VERSION_MAJOR	VER_MAJOR
#define ESIF_VERSION_MINOR	VER_MINOR
#define ESIF_VERSION_HOTFIX	VER_HOTFIX
#define ESIF_VERSION_BUILD	VER_BUILD

#define ESIF_VERSION EXPAND_TOSTR(ESIF_VERSION_MAJOR.ESIF_VERSION_MINOR.ESIF_VERSION_HOTFIX.ESIF_VERSION_BUILD)

/* IPF Product and Copyright Definitions */
#define ESIF_PRODUCT   "Intel(R) Innovation Platform Framework"
#define ESIF_COPYRIGHT "Copyright (c) 2013-2022 Intel Corporation All Rights Reserved"
#define ESIF_COMPANY   "Intel Corporation"
#define ESIF_LOWER_FRAMEWORK "IPF Lower Framework"
#define ESIF_UPPER_FRAMEWORK "IPF Upper Framework"

#endif /* _ESIF_VERSION_H_ */

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



