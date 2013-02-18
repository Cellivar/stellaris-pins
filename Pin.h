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
 * The Stellaris Pin Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with The Stellaris Pin Library.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STELLARIS_PINS_PIN_CHAPMAN_H
#define STELLARIS_PINS_PIN_CHAPMAN_H

// GPIO peripherial addresses
#define PERIPH_A	0x20000001
#define PERIPH_B	0x20000002
#define PERIPH_C	0x20000004
#define PERIPH_D	0x20000008
#define PERIPH_E	0x20000010
#define PERIPH_F	0x20000020

// GPIO Port addresses
#define PORTA		0x40004000
#define PORTB		0x40005000
#define PORTC		0x40006000
#define PORTD		0x40007000
#define PORTE		0x40024000
#define PORTF		0x40025000

// GPIO Pin masks
#define PIN0		0x00000001
#define PIN1		0x00000002
#define PIN2		0x00000004
#define PIN3		0x00000008
#define PIN4		0x00000010
#define PIN5		0x00000020
#define PIN6		0x00000040
#define PIN7		0x00000080



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

protected:
	unsigned long peripherial;
	unsigned long port;
	unsigned char pin;
};


#endif // STELLARIS_PINS_PIN_CHAPMAN_H
