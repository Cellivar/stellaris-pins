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

#include "Pin.h"

namespace StellarisPins
{

	/**
	 * Create a pin object based on a peripherial address, the port address and
	 * the pin mask. Does not verify inputs (because I'm lazy).
	 *
	 */
	Pin::Pin
		( unsigned long periphAddress
		, unsigned long portAddress
		, unsigned char pinMask
		)
	{
		// Set the internal properties
		peripherial = periphAddress;
		port = portAddress;
		pin = pinMask;

		// Enable the peripherial
		SysCtlPeripheralEnable(peripherial);

		// Being a base class we don't know what to do with the actual pins,
		// so instead we will twiddle our thumbs.

		// thumb->twiddle(THUMB_LEFT, THUMB_RIGHT);
	}

}