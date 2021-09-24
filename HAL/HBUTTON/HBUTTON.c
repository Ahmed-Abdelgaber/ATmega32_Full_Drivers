/*
 * HBUTTON.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Gaber
 */

#ifndef HBUTTON_HBUTTON_C_
#define HBUTTON_HBUTTON_C_
#include "MDIO.h"
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBUTTON.h"

void HBUTTON_Void_puttonInit()
{
	MDIO_Void_setPinDirection(BUTTON0_PORT,BUTTON0_PIN,INPUT);
	MDIO_Void_setPinDirection(BUTTON1_PORT,BUTTON1_PIN,INPUT);
	MDIO_Void_setPinDirection(BUTTON2_PORT,BUTTON2_PIN,INPUT);
	MDIO_Void_setPinValue(BUTTON0_PORT,BUTTON0_PIN,HIGH);
	MDIO_Void_setPinValue(BUTTON1_PORT,BUTTON1_PIN,HIGH);
	MDIO_Void_setPinValue(BUTTON2_PORT,BUTTON2_PIN,HIGH);
}

value HBUTTON_Value_getButtonValue(u8 buttonPort, u8 buttonPin)
{
	value buttonValue ;
	if((GET_BIT(buttonPort,buttonPin)) == HIGH)
	{
		buttonValue = HIGH;
	}
	else if ((GET_BIT(buttonPort,buttonPin)) == LOW)
	{
		buttonValue = LOW;
	}
	return buttonValue;
}

#endif /* HBUTTON_HBUTTON_C_ */
