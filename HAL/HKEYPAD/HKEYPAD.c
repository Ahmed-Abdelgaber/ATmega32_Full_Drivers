/*
 * HKEYPAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Gaber
 */

#include "LSTD_TYPES.h"
#include "MDIO.h"
#include "HKEYPAD.h"
#include "HKEYPAD_Config.h"
#include "HKEYPAD_Private.h"
#include <util/delay.h>

u8 HKEYPAD_U8_switchValue[ROWS_NUMBER][COLUMNS_NUMBER]={{SEVEN,FOUR,ONE,SET},{EIGHT,FIVE,TWO,ZERO},{NINE,SIX,THREE,EQUAL},{DIVIDE,MULTIPLICATION,SUBTRACTION,ADDITION}};

void HKEYPAD_Void_init(){
	MDIO_Void_setPinDirection(COLUMN_PORT,COLUMN_PIN0,OUTPUT);
	MDIO_Void_setPinDirection(COLUMN_PORT,COLUMN_PIN1,OUTPUT);
	MDIO_Void_setPinDirection(COLUMN_PORT,COLUMN_PIN2,OUTPUT);
	MDIO_Void_setPinDirection(COLUMN_PORT,COLUMN_PIN3,OUTPUT);
	MDIO_Void_setPinDirection(ROW_PORT,ROW_PIN0,INPUT);
	MDIO_Void_setPinDirection(ROW_PORT,ROW_PIN1,INPUT);
	MDIO_Void_setPinDirection(ROW_PORT,ROW_PIN2,INPUT);
	MDIO_Void_setPinDirection(ROW_PORT,ROW_PIN3,INPUT);


	MDIO_Void_setPinValue(COLUMN_PORT,COLUMN_PIN0,HIGH);
	MDIO_Void_setPinValue(COLUMN_PORT,COLUMN_PIN1,HIGH);
	MDIO_Void_setPinValue(COLUMN_PORT,COLUMN_PIN2,HIGH);
	MDIO_Void_setPinValue(COLUMN_PORT,COLUMN_PIN3,HIGH);
	MDIO_Void_setPinValue(ROW_PORT,ROW_PIN0,HIGH);
	MDIO_Void_setPinValue(ROW_PORT,ROW_PIN1,HIGH);
	MDIO_Void_setPinValue(ROW_PORT,ROW_PIN2,HIGH);
	MDIO_Void_setPinValue(ROW_PORT,ROW_PIN3,HIGH);
}

u8 HKEYPAD_U8_getPressedKey()
{
	u8 pressedKey = NOTPRESSED;
	u8 column_index ;
	u8 row_index ;
	for(column_index = COLUMN_INIT;column_index < COLUMN_END;column_index++)
	{
		/*Select Column*/
		MDIO_Void_setPinValue(COLUMN_PORT,column_index,LOW);
		for(row_index = ROW_INIT;row_index < ROW_END;row_index ++)
		{
			/*Check The Status Of The Switch*/
			if(MDIO_Value_getPinValue(ROW_PORT,row_index) == 0)
			{
			pressedKey = HKEYPAD_U8_switchValue[column_index-COLUMN_INIT][row_index-ROW_INIT];
			/*Wait Until the switch released(Single Press)*/
			while(MDIO_Value_getPinValue(ROW_PORT,row_index) == 0);
			/*Delay to avoid bouncing*/
			_delay_ms(10);
			}
		}
		MDIO_Void_setPinValue(COLUMN_PORT,column_index,HIGH);
	}
	return pressedKey;
}

