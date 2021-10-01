/*
 * HLCD.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef HLCD_HLCD_H_
#define HLCD_HLCD_H_

#include "LSTD_TYPES.h"

typedef struct arabicChar
{
	u8 customizedChar[7];
	u8 number;
}arabicChar;

#define CLEAR_LCD 0b00000001

void HLCD_Void_init();
void HLCD_Void_sendCommand(u8 Copy_u8_command);
void HLCD_Void_sendData(u8 Copy_u8_data);
void HLCD_Void_sendNumber(u32 Copy_u32_number);
void HLCD_Void_sendString(u8 *ptrToString);
void HLCD_Void_setPosition(u8 row,u8 column);
void HLCD_Void_sendCustomizedChar(u8* ptrToCustomizedChar,u8 charNumber);
void HLCD_Void_printCustomizedChar(u8 charNumber);
void HLCD_Void_config();

#endif /* HLCD_HLCD_H_ */
