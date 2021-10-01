/*
 * HLCD.c
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


#include "HLCD_config.h"
#include "HLCD_Private.h"
#include "HLCD.h"
#include "MDIO.h"
#include "LSTD_TYPES.h"
#include <util/delay.h>

void HLCD_Void_config()
{
	MDIO_Void_setPortDirection(PORT_DATA, OUTPUT);
	MDIO_Void_setPinDirection(PORT_CONTROL, RS, OUTPUT);
	MDIO_Void_setPinDirection(PORT_CONTROL, RW, OUTPUT);
	MDIO_Void_setPinDirection(PORT_CONTROL, E, OUTPUT);
}

void HLCD_Void_sendCommand(u8 Copy_u8_command)
{
#if FUNCTION_SET == FUNCTION_SET_8BITS_1LINE || FUNCTION_SET == FUNCTION_SET_8BITS_2LINES
	//Select Command Register
	MDIO_Void_setPinValue(PORT_CONTROL, RS, LOW);
	//Select Write Mode
	MDIO_Void_setPinValue(PORT_CONTROL, RW, LOW);
	//Send Command
	MDIO_Void_setPortValue(PORT_DATA, Copy_u8_command);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(5);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
#elif FUNCTION_SET == FUNCTION_SET_4BITS_1LINE || FUNCTION_SET == FUNCTION_SET_4BITS_2LINES
	//Select Data Register
	MDIO_Void_setPinValue(PORT_CONTROL, RS, LOW);
	//Select Write Mode
	MDIO_Void_setPinValue(PORT_CONTROL, RW, LOW);
	//Send Command
	MDIO_Void_setPortValue(PORT_DATA, Copy_u8_command);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(2);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
	//Shift by 4bits
	Copy_u8_command <<= 4;
	//Send Command
	MDIO_Void_setPortValue(PORT_DATA,Copy_u8_command);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(2);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
#endif
}

void HLCD_Void_sendData(u8 Copy_u8_data)
{
#if FUNCTION_SET == FUNCTION_SET_8BITS_1LINE || FUNCTION_SET ==FUNCTION_SET_8BITS_2LINES
	//Select Data Register
	MDIO_Void_setPinValue(PORT_CONTROL, RS, HIGH);
	//Select Write Mode
	MDIO_Void_setPinValue(PORT_CONTROL, RW, LOW);
	//Send Data
	MDIO_Void_setPortValue(PORT_DATA, Copy_u8_data);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(2);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
#elif FUNCTION_SET == FUNCTION_SET_4BITS_1LINE || FUNCTION_SET == FUNCTION_SET_4BITS_2LINES
	//Select Data Register
	MDIO_Void_setPinValue(PORT_CONTROL, RS, HIGH);
	//Select Write Mode
	MDIO_Void_setPinValue(PORT_CONTROL, RW, LOW);
	//Send Command
	MDIO_Void_setPortValue(PORT_DATA, Copy_u8_data);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(2);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
	//Shift by 4bits
	Copy_u8_data <<= 4;
	//Send Command
	MDIO_Void_setPortValue(PORT_DATA,Copy_u8_data);
	//LCD enable
	MDIO_Void_setPinValue(PORT_CONTROL, E, HIGH);
	_delay_ms(2);
	MDIO_Void_setPinValue(PORT_CONTROL, E, LOW);
#endif

}

void HLCD_Void_init()
{
#if FUNCTION_SET == FUNCTION_SET_4BITS_1LINE || FUNCTION_SET == FUNCTION_SET_4BITS_2LINES
	_delay_ms(30);
	HLCD_Void_sendCommand(FUNCTION_SET);
	HLCD_Void_sendCommand(FUNCTION_SET);
	HLCD_Void_sendCommand(FUNCTION_SET<<4);
	_delay_ms(2);
	HLCD_Void_sendCommand(DISPLAY_ON_OFF);
	HLCD_Void_sendCommand(DISPLAY_ON_OFF<<4);
	_delay_ms(2);
	HLCD_Void_sendCommand(CLEAR_DISPLAY);
	HLCD_Void_sendCommand(CLEAR_DISPLAY<<4);
	_delay_ms(2);
	HLCD_Void_sendCommand(ENTRY_MODE_SET);
	HLCD_Void_sendCommand(ENTRY_MODE_SET<<4);
#elif FUNCTION_SET == FUNCTION_SET_8BITS_1LINE || FUNCTION_SET ==FUNCTION_SET_8BITS_2LINES
	_delay_ms(30);
	HLCD_Void_sendCommand(FUNCTION_SET);
	_delay_ms(2);
	HLCD_Void_sendCommand(DISPLAY_ON_OFF);
	_delay_ms(2);
	HLCD_Void_sendCommand(CLEAR_DISPLAY);
	_delay_ms(2);
	HLCD_Void_sendCommand(ENTRY_MODE_SET);
	_delay_ms(2);
#endif
}

void HLCD_Void_sendString(u8 *ptrToString)
{
	u8 index = 0;
	while (ptrToString[index] != '\0') {
		HLCD_Void_sendData(ptrToString[index]);
		index++;
	}

}

void HLCD_Void_setPosition(u8 row, u8 column)
{
	if (row < LINE_ONE || row > LINE_TWO||column >16||column<1)
	{
		/*NOTHING*/
	}
	else{
		switch (row) {
		case LINE_ONE:
			HLCD_Void_sendCommand(LINE_ONE_ADDRESS + (column-1));
			break;
		case LINE_TWO:
			HLCD_Void_sendCommand(LINE_TWO_ADDRESS + (column-1));
			break;
		}
	}
}

void HLCD_Void_sendNumber(u32 Copy_u32_number)
{
	u8 arrayOfNumbers[MAX_DIGITS_IN_32BIT];
	u8 while_index = 0;
	if (Copy_u32_number == 0)
	{
		HLCD_Void_sendData( 0 + ASCII_INDEX);
	}
	else
	{
		while (Copy_u32_number != 0) {
			arrayOfNumbers[while_index] = Copy_u32_number % 10;
			Copy_u32_number /= 10;
			while_index++;
		}
		while (while_index != 0) {
			HLCD_Void_sendData(arrayOfNumbers[while_index - 1] + ASCII_INDEX);
			while_index--;
		}
	}
}

void HLCD_Void_sendCustomizedChar(u8* ptrToCustomizedChar,u8 charNumber)
{
	//Send CGram Address
	HLCD_Void_sendCommand(SET_CGRAM_ADDRESS + (charNumber-1)*8);
	//Write the Customized Character Row by Row
	u8 index;
	for (index = 0;index<8;index++)
	{
		HLCD_Void_sendData(ptrToCustomizedChar[index]);
	}

}

void HLCD_Void_printCustomizedChar(u8 charNumber)
{
	HLCD_Void_sendData(charNumber-1);
}
