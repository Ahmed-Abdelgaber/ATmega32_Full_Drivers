/*
 * APPCALCULATOR.c
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


#include"LSTD_TYPES.h"
#include "MDIO.h"
#include "HLCD.h"
#include "HKEYPAD.h"
#include "APPCALCULATOR.h"
#include <util/delay.h>



void APP_Void_printPressedButton(u8 pressedButton){

	switch(pressedButton)
	{
	case ONE:
		HLCD_Void_sendNumber(1);
		break;
	case TWO:
		HLCD_Void_sendNumber(2);
		break;
	case THREE:
		HLCD_Void_sendNumber(3);
		break;
	case FOUR:
		HLCD_Void_sendNumber(4);
		break;
	case FIVE:
		HLCD_Void_sendNumber(5);
		break;
	case SIX:
		HLCD_Void_sendNumber(6);
		break;
	case SEVEN:
		HLCD_Void_sendNumber(7);
		break;
	case EIGHT:
		HLCD_Void_sendNumber(8);
		break;
	case NINE:
		HLCD_Void_sendNumber(9);
		break;
	case ZERO:
		HLCD_Void_sendNumber(0);
		break;
	case SUBTRACTION:
		HLCD_Void_sendData('-');
		break;
	case ADDITION:
		HLCD_Void_sendData('+');
		break;
	case MULTIPLICATION:
		HLCD_Void_sendData('x');
		break;
	case DIVIDE:
		HLCD_Void_sendData('/');
		break;
	}

}

void APP_Void_storeEnteredValue (u32 *ptrToEnteredValue, u8 pressedButton)
{
	switch(pressedButton)
	{
	case ONE:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+1;
		break;
	case TWO:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+2;
		break;
	case THREE:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+3;
		break;
	case FOUR:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+4;
		break;
	case FIVE:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+5;
		break;
	case SIX:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+6;
		break;
	case SEVEN:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+7;
		break;
	case EIGHT:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+8;
		break;
	case NINE:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+9;
		break;
	case ZERO:
		*ptrToEnteredValue = ((*ptrToEnteredValue)*10)+0;
		break;
	}

}

void APP_Void_additionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber)
{
	u32 Copy_U32_result = (*ptrToFirstNumber)+(*ptrToSecondNumber);
	HLCD_Void_setPosition(2,1);
	HLCD_Void_sendData('=');
	HLCD_Void_sendNumber(Copy_U32_result);
}
void APP_Void_subtractionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber)
{
	u32 Copy_U32_result = (*ptrToFirstNumber)-(*ptrToSecondNumber);
	HLCD_Void_setPosition(2,1);
	HLCD_Void_sendData('=');
	HLCD_Void_sendNumber(Copy_U32_result);
}
void APP_Void_multiblicationOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber)
{
	u32 Copy_U32_result = (*ptrToFirstNumber)*(*ptrToSecondNumber);
	HLCD_Void_setPosition(2,1);
	HLCD_Void_sendData('=');
	HLCD_Void_sendNumber(Copy_U32_result);
}
void APP_Void_divisionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber)
{
	u32 Copy_U32_result = (*ptrToFirstNumber)/(*ptrToSecondNumber);
	HLCD_Void_setPosition(2,1);
	HLCD_Void_sendData('=');
	HLCD_Void_sendNumber(Copy_U32_result);
}
