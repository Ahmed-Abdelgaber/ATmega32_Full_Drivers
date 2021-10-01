/*
 * MUART.h
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef MUART_MUART_H_
#define MUART_MUART_H_

#include "LSTD_TYPES.h"

typedef enum
{
	_2400 = 416,
	_4800 = 207,
	_9600 = 103,
	_14K  = 68,
	_19K  = 51,
	_115K  = 8

}UART_boudRate;
typedef enum
{
	 polling= 0,
	 interrupt = 1
}UART_interruputMode;

typedef enum
{
	asynchronousMode = 0,
	synchronousMode  = 1
}UART_trancReceivMode;

typedef enum
{
	noParityBit = 0,
	evenParity = 2,
	oddParity = 3
}UART_parityMode;

typedef enum
{
	oneBit = 0,
	twoBits = 1
}UART_stopBitsNumber;

typedef enum
{
	fiveBits = 0,
	sixBits,
	sevenBits,
	eightBits,
	nineBits
}UART_messageSize;

typedef enum
{
	fallingEdge = 0,
	risingEdge = 1,
	noClock = 2
}UART_clockPolarity;//With Reference to TX

void MUART_Void_UARTinit(UART_interruputMode interruptMode,UART_trancReceivMode trancReceivMode,UART_parityMode parityMode,UART_messageSize messageSize,UART_clockPolarity clockPolarity,UART_stopBitsNumber stopBitsNumber,UART_boudRate boudRate);
void MUART_Void_sendByte(u8 Copy_U8_data);
void MUART_Void_sendString(u8* Copy_U8_string);
u8 MUART_U8_recieveByte();
void MUART_Void_recieveString(u8* ptrToResceivedString);
bool MUART_Value_isRecieved();


#endif /* MUART_MUART_H_ */
