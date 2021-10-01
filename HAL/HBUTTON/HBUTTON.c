/*
 * HBUTTON.c
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


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

bool HBUTTON_Value_getButtonValue(u8 buttonPort, u8 buttonPin)
{
	bool buttonValue ;
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
