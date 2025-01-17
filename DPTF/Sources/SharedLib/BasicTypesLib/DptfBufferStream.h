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
#include "DptfBuffer.h"

class DptfBufferStream
{
public:
	DptfBufferStream(DptfBuffer& buffer);
	virtual ~DptfBufferStream();

	UInt8 readNextUint8();
	UInt16 readNextUint16();
	UInt32 readNextUint32();
	UInt64 readNextUint64();
	double readNextDouble();
	float readNextFloat();
	Bool readNextBool();
	Power readNextPower();
	Temperature readNextTemperature();
	void resetReadPosition();
	Bool canReadNext(size_t bytes) const;

	void appendUint8(UInt8 value);
	void appendUint16(UInt16 value);
	void appendUint32(UInt32 value);
	void appendUint64(UInt64 value);
	void appendDouble(double value);
	void appendFloat(float value);
	void appendBool(bool value);

	const DptfBuffer& getBuffer() const;

private:
	DptfBuffer& m_buffer;
	UInt32 m_currentLocation;
	void throwIfReadIsPastEndOfBuffer(size_t nextSize);
};
