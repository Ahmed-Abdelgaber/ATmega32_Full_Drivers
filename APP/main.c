/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Ahmed Gaber
 */

#include "LSTD_TYPES.h"
#include "MDIO.h"
#include "HLCD.h"
#include <util/delay.h>

int main(void)
{
	HLCD_Void_config();
	HLCD_Void_init();
	while(1)
	{
		HLCD_Void_sendData('H');
		_delay_ms(1000);
		HLCD_Void_sendCommand(CLEAR_LCD);
		HLCD_Void_sendString("Ahmed");
		_delay_ms(1000);
		HLCD_Void_sendCommand(CLEAR_LCD);
		HLCD_Void_setPosition(2, 5);
		HLCD_Void_sendNumber(5);
	}
	return 0;
}
