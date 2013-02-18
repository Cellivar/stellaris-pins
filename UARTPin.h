/**
 * @file UARTpin.h
 *
 * Prototype of UARTPin class, for creating UART connections.
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

#ifndef STELLARIS_PINS_UARTPIN_CHAPMAN_H
#define STELLARIS_PINS_UARTPIN_CHAPMAN_H

#include "utils/uartstdio.h"
#include "driverlib\uart.h"
#include "Pin.h"

namespace StellarisPins
{
	// Device enum
	enum UART { UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7 };

	class UARTPin
	{
	public:
		UARTPin(UART connection);
		UARTPin(UART connection, bool uartCTS, bool uartRTS);

		void EnableSTDIO();
		void EnableSTDIO(int speed);

	private:
		UART connection;

		void Init(UART connection, bool uartCTS, bool uartRTS);

	}


}

#endif // STELLARIS_PINS_UARTPIN_CHAPMAN_H