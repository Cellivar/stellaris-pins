/**
 * @file UARTPin.cpp
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

#include "UARTPin.h"

namespace StellarisPins
{

	UARTPin::UARTPin(UART connection)
	{
		this->Init(connection, false, false);
	}
	
	UARTPin::UARTPin(UART connection, bool uartCTS, bool uartRTS)
	{
		this->Init(connection, uartCTS, uartRTS);
	}


	// Create the UART connections and activate the relevant GPIO connection
	void UARTPin::Init(UART connection, bool uartCTS, bool uartRTS)
	{
		this->connection = connection;

		// TODO: Figure out how to do a proper lookup, a switch/case seems like
		// it is inefficient here. Something akin to a reverse ENUM...
		switch (connection)
		{
		case 0:
			// RX:PA0 TX:PA1
			SysCtlPeripheralEnable(PERIPH_A);
			GPIOPinConfigure(0x00000001);
			GPIOPinConfigure(0x00000401);
			GPIOPinTypeUART(PORTA, 0x00000003);
			UARTFlowControlSet(0x4000C000, 0);
			break;

		case 1:
			// RX:PB0 TX:PB1 
			SysCtlPeripheralEnable(PERIPH_B);
			GPIOPinConfigure(0x00010001);
			GPIOPinConfigure(0x00010401);
			GPIOPinTypeUART(PORTB, 0x00000003);

			// RTS/CTS Settings
			// RTS:PF0 CTS:PF1
			unsigned char uartMode = 0;
			if (uartCTS) 
			{
				uartMode |= 0x00008000;
				GPIOPinConfigure(0x00050401);	// UART CTS
			}

			if (uartRTS)
			{
				uartMode |= 0x00004000;
				GPIOPinConfigure(0x00050001);	// UART RTS
			}

			if (uartCTS || uartRTS)
			{
				SysCtlPeripheralEnable(PERIPH_F);
				UARTFlowControlSet(0x4000D000, uartMode);
			}
			break;

		case 2:
			// RX:PD6 TX:PD7
			SysCtlPeripheralEnable(PERIPH_D);
			GPIOPinConfigure(0x00031801);
			GPIOPinConfigure(0x00031C01);
			GPIOPinTypeUART(PORTD, 0x00000060);
			UARTFlowControlSet(0x4000E000, 0);
			break;
			
		case 3:
			// RX:PC6 TX:PC7
			SysCtlPeripheralEnable(PERIPH_C);
			GPIOPinConfigure(0x00021801);
			GPIOPinConfigure(0x00021C01);
			GPIOPinTypeUART(PORTC, 0x00000060);
			UARTFlowControlSet(0x4000F000, 0);
			break;
			
		case 4:
			// RX:PC4 TX:PC5
			SysCtlPeripheralEnable(PERIPH_D);
			GPIOPinConfigure(0x00021001);
			GPIOPinConfigure(0x00021401);
			GPIOPinTypeUART(PORTC, 0x00000030);
			UARTFlowControlSet(0x40010000, 0);
			break;
			
		case 5:
			// RX:PE4 TX:PE5
			SysCtlPeripheralEnable(PERIPH_E);
			GPIOPinConfigure(0x00041001);
			GPIOPinConfigure(0x00041401);
			GPIOPinTypeUART(PORTE, 0x00000030);
			UARTFlowControlSet(0x40011000, 0);
			break;
			
		case 6:
			// RX:PD4 TX:PD5
			SysCtlPeripheralEnable(PERIPH_D);
			GPIOPinConfigure(0x00031001);
			GPIOPinConfigure(0x00031401);
			GPIOPinTypeUART(PORTD, 0x00000030);
			UARTFlowControlSet(0x40012000, 0);
			break;
			
		case 7:
			// RX:PE0 TX:PE1
			SysCtlPeripheralEnable(PERIPH_E);
			GPIOPinConfigure(0x00040001);
			GPIOPinConfigure(0x00040401);
			GPIOPinTypeUART(PORTE, 0x00000003);
			UARTFlowControlSet(0x40013000, 0);
			break;
		}
	}

	void UARTPin::EnableSTDIO()
	{
		this->EnableSTDIO(115200);
	}

	void UARTPin::EnableSTDIO(int speed)
	{
		UARTStdioInitExpClk(this->connection, speed);
	}

}








