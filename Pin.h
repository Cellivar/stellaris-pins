/**
 * @file Pin.h
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
 * OneWireCRC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OneWireCRC.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STELLARIS_PINS_PIN_CHAPMAN_H
#define STELLARIS_PINS_PIN_CHAPMAN_H

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

class Pin
{
public:
	Pin
	( unsigned long periphAddress
	, unsigned long portAddress
	, unsigned char pinMask
	);
	~Pin();

protected:
	unsigned long peripherial;
	unsigned long port;
	unsigned char pin;
};


#endif // STELLARIS_PINS_PIN_CHAPMAN_H
