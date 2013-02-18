/**
 * @file UARTpin.h
 *
 * Prototype of UARTPin class, for creating UART connections
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