/**
 * @file SSIPin.h
 *
 * Description of UARTPin class
 *
 * 
 *
 * Copyright (C) <2012> Cliff Chapman <chapman.cliff@gmail.com>
 *
 * This file is part of the Stellaris Pin Library.
 * 
 * The Stellaris Pin Library is free software: you can redistribute it 
 * and/or modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 * 
 * The Stellaris Pin Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with The Stellaris Pin Library.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STELLARIS_PINS_SSIPIN_CHAPMAN_H
#define STELLARIS_PINS_SSIPIN_CHAPMAN_H

#include "Pin.h"
#include "driverlib\ssi.h"

namespace StellarisPins
{
	// Device selection enum
	enum SSI { SSI0, SSI1, SSI2, SSI3 };
	enum FRF_MODE 
		{ MOTO0 = 0x00000000
		, MOTO1 = 0x00000002
		, MOTO2 = 0x00000001
		, MOTO3 = 0x00000003
		, TI	= 0x00000010
		, NMW	= 0x00000020
		};

	class SSIPin
	{
	public:
		SSIPin(SSI connection, bool isMaster, FRF_MODE mode, int bitRate, 
			int dataWidth);

	private:
		SSI connection;
		unsigned char base;

		void Init(SSI connection, bool isMaster, FRF_MODE mode, int bitRate, 
			int dataWidth);

	};

}

#endif // STELLARIS_PINS_SSIPIN_CHAPMAN_H