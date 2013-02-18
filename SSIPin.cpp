/**
 * @file SSIPin.cpp
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

#include "SSIPin.h"

namespace StellarisPins
{
	SSIPin::SSIPin
		( SSI connection
		, bool isMaster
		, FRF_MODE mode
		, int bitRate
		, int dataWidth
		)
	{
		this->Init(connection, isMaster, mode, bitRate, dataWidth);
	}

	void SSIPin::Init
		( SSI connection
		, bool isMaster
		, FRF_MODE mode
		, int bitRate
		, int dataWidth
		)
	{
		this->connection = connection;

		int masterMode = 0;
		if (isMaster)
		{
			masterMode = SSI_MODE_MASTER;
		}
		else
		{
			masterMode = SSI_MODE_SLAVE;
		}

		switch(connection)
		{
		case 0:
			// PA2: SSI0CLK
			// PA3: SSI0FSS
			// PA4: SSI0RX
			// PA5: SSI0TX
			SysCtlPeripheralEnable(PERIPH_A);
			SysCtlPeripheralEnable(0x10000010);
			GPIOPinConfigure(0x00000802);
			GPIOPinConfigure(0x00000C02);
			GPIOPinConfigure(0x00001002);
			GPIOPinConfigure(0x00001402);
			GPIOPinTypeSSI(PORTA, PIN2 | PIN3 | PIN4 | PIN5);
			this->base = SSI0_BASE;
			SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), mode, 
				masterMode, bitRate, dataWidth);
			SSIEnable(SSI0_BASE);

		break;

		case 1:
			// PF0: SSI0CLK
			// PF1: SSI0FSS
			// PF2: SSI0RX
			// PF3: SSI0TX
			SysCtlPeripheralEnable(PERIPH_F);
			SysCtlPeripheralEnable(0x10000020);
			GPIOPinConfigure(0x00050002);
			GPIOPinConfigure(0x00050402);
			GPIOPinConfigure(0x00050802);
			GPIOPinConfigure(0x00050C02);
			GPIOPinTypeSSI(PORTF, PIN0 | PIN1 | PIN2 | PIN3);
			this->base = SSI1_BASE;
			SSIConfigSetExpClk(SSI1_BASE, SysCtlClockGet(), mode, 
				masterMode, bitRate, dataWidth);
			SSIEnable(SSI1_BASE);

		break;

		case 2:
			// PB4: SSI0CLK
			// PB5: SSI0FSS
			// PB6: SSI0RX
			// PB7: SSI0TX
			SysCtlPeripheralEnable(PERIPH_B);
			SysCtlPeripheralEnable(0xf0001c02);
			GPIOPinConfigure(0x00011002);
			GPIOPinConfigure(0x00011402);
			GPIOPinConfigure(0x00011802);
			GPIOPinConfigure(0x00011C02);
			GPIOPinTypeSSI(PORTB, PIN4 | PIN5 | PIN6 | PIN7);
			this->base = SSI2_BASE;
			SSIConfigSetExpClk(SSI2_BASE, SysCtlClockGet(), mode, 
				masterMode, bitRate, dataWidth);
			SSIEnable(SSI2_BASE);

		break;

		case 3:
			// PD0: SSI0CLK
			// PD1: SSI0FSS
			// PD2: SSI0RX
			// PD3: SSI0TX
			SysCtlPeripheralEnable(PERIPH_D);
			SysCtlPeripheralEnable(0xf0001c03);
			GPIOPinConfigure(0x00030002);
			GPIOPinConfigure(0x00030402);
			GPIOPinConfigure(0x00030802);
			GPIOPinConfigure(0x00030C02);
			GPIOPinTypeSSI(PORTD, PIN2 | PIN3 | PIN4 | PIN5);
			this->base = SSI3_BASE;
			SSIConfigSetExpClk(SSI3_BASE, SysCtlClockGet(), mode, 
				masterMode, bitRate, dataWidth);
			SSIEnable(SSI3_BASE);

		break;
		}
	}

	unsigned char SSIPin::Send(char data)
	{
		unsigned long retVal;
		SSIDataPut(this->base, data);
		SSIDataGet(this->base, &retVal);
		return (char)retVal;
	}


}