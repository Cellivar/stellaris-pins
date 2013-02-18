/**
 * @file DigitalIOPin.h
 *
 * Pin class, for simple definitions relating to pins on the Stellaris
 *
 * Because I don't like typing C-style definitions over and over.
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

#include "DigitalIOPin.h"


/**
 * Constructor based off of the base class Pin. Selected pin is initalized
 * as default input.
 *
 * @param[in] periphAddress Peripheral address from sysctl.h
 * @param[in] portAddress GPIO port address from hw_memmap.h
 * @param[in] pinMask GPIO pin from gpio.h
 */
DigitalIOPin::DigitalIOPin
	( unsigned long periphAddress
	, unsigned long portAddress
	, unsigned char pinMask
	)
	: Pin(periphAddress, portAddress, pinMask)
{
	// After base initialization (including enabling the peripheral device)
	// default to GPIO digital input
	GPIOPinTypeGPIOOutput(this->port, this->pin);
}


/**
 * Write a value to this pin. Writing to a pin configured as an input pin has no
 * effect.
 *
 * @param[in] val Write value to this pin
 */
void DigitalIOPin::Write(unsigned char val)
{
	if (val != 0)
	{
		val = this->pin;
	}

	GPIOPinWrite(this->port, this->pin, val);
}

/**
 * Read a value from this pin. Both input and output pins are read.
 *
 * @param[out] int Value of the pin
 */
int DigitalIOPin::Read(void)
{
	int val = GPIOPinRead(this->port, this->pin);
	val = val / this->pin;
	return val;// (this->pin -1));// & 1;
	//return (GPIOPinRead(this->port, this->pin) / this->pin);
}

/**
 * Set pin mode to input
 */
void DigitalIOPin::Input(void)
{
	GPIODirModeSet(this->port, this->pin, GPIO_DIR_MODE_IN);
}

/**
 * Set pin mode to output
 */
void DigitalIOPin::Output(void)
{
	GPIODirModeSet(this->port, this->pin, GPIO_DIR_MODE_OUT);
}

/**
 * Set pull mode and strength of the pin.
 *
 * Parameters are located in the GPIOPadConfigSet documentation
 *
 * @param mode ulPinType setting
 * @param strength ulStrength setting
 */
void DigitalIOPin::PullMode(unsigned long strength, unsigned long mode)
{
	GPIOPadConfigSet(this->port, this->pin, strength, mode);
}
