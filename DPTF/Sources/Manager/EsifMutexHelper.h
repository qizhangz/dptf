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
#include "EsifMutex.h"

//
// This class was created to make sure the mutex is unlocked even if an exception is thrown while a mutex
// has been locked within a function.  The MutexHelper must be created on the stack and then lock() should be
// called on the MutexHelper.  Then you have the option of calling unlock() whenever needed.  If an
// exception is thrown while the mutex is still locked, the destructor will call unlock() when the stack
// unwinds.
//

class EsifMutexHelper final
{
public:
	EsifMutexHelper(EsifMutex* esifMutex);
	~EsifMutexHelper(void);

	void lock(void);
	void unlock(void);

private:
	// hide the copy constructor and assignment operator.
	EsifMutexHelper(const EsifMutexHelper& rhs);
	EsifMutexHelper& operator=(const EsifMutexHelper& rhs);

	EsifMutex* m_esifMutex;
	Bool m_mutexLocked;
};
