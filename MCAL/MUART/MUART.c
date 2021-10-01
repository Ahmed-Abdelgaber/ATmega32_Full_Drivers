/*
 * MUART.c
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


#include "LBIT_MATH.h"
#include "MUART.h"
#include "MUART_Private.h"

void MUART_Void_UARTinit(UART_interruputMode interruptMode,UART_trancReceivMode trancReceivMode,UART_parityMode parityMode,UART_messageSize messageSize,UART_clockPolarity clockPolarity,UART_stopBitsNumber stopBitsNumber,UART_boudRate boudRate)
{
	/*Enable RX TX Pins*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	/*Enable UCSRC*/
	SET_BIT(UCSRC,URSEL);
	/*Choose Asynchronous or Synchronous*/
	switch(trancReceivMode)
	{
	case asynchronousMode:
		CLEAR_BIT(UCSRC,UMSEL);
		break;
	case synchronousMode:
		SET_BIT(UCSRC,UMSEL);
		break;
	}

	/*Enable or Disable UART Interrupt*/
	switch(interruptMode)
	{
	case polling:
		CLEAR_BIT(UCSRB,RXCIE);
		CLEAR_BIT(UCSRB,TXCIE);
		CLEAR_BIT(UCSRB,UDRIE);
		break;
	case interrupt:
		SET_BIT(UCSRB,RXCIE);
		SET_BIT(UCSRB,TXCIE);
		SET_BIT(UCSRB,UDRIE);
		break;
	}

	/*Choose Parity Mode*/
	switch(parityMode)
	{
	case noParityBit:
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
		break;
	case evenParity:
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
	case oddParity:
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
	}

	/*Choose Message Size*/
	switch(messageSize)
	{
	case fiveBits:
		CLEAR_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
	case sixBits:
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
	case sevenBits:
		CLEAR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
	case eightBits:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
	case nineBits:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
		break;
	}

	/*Choose Clock Polarity*/
	switch(clockPolarity)
	{
	case fallingEdge:
		SET_BIT(UCSRC,UCPOL);
		break;
	case risingEdge:
		CLEAR_BIT(UCSRC,UCPOL);
		break;
	case noClock:
		/*Asynchronous Mode Do Nothing*/
		break;
	}

	/*Choose Number of Stop Bits*/
	switch(stopBitsNumber)
	{
	case oneBit:
		CLEAR_BIT(UCSRC,USBS);
		break;
	case twoBits:
		SET_BIT(UCSRC,USBS);
		break;
	}

	/*Choose Baud Rate*/
	/*Enable UBRRH*/
	CLEAR_BIT(UCSRC,URSEL);
	switch(boudRate)
	{
	case _2400:
		UBRRL |= _2400;
		UBRRH |= _2400 >> 8;
		break;
	case _4800:
		UBRRL |= _4800;
		UBRRH |= _4800 >> 8;
		break;
	case _9600:
		UBRRL |= _9600;
		UBRRH |= _9600 >> 8;
		break;
	case _14K:
		UBRRL |= _14K;
		UBRRH |= _14K >> 8;
		break;
	case _19K:
		UBRRL |= _19K;
		UBRRH |= _19K >> 8;
		break;
	case _115K:
		UBRRL |= _115K;
		UBRRH |= _115K >> 8;
	}
}

bool MUART_Value_isRecieved()
{
	return !GET_BIT(UCSRA,RXC);
}

void MUART_Void_sendByte(u8 Copy_U8_data)
{
	/*Checking 9-bit Mode*/
	if ((GET_BIT(UCSRB,UCSZ2)) == 0)
	{
		while ((GET_BIT(UCSRA,UDRE)) == 0);
		UDR = Copy_U8_data;
	}
	else
	{
		//while ((GET_BIT(UCSRA,UDRE)) == 0);
		//if ((GET_BIT(Copy_U16_data,9)) == 0)
		//{
		//CLEAR_BIT(UCSRB,TXB8);
		//}
		//else
		//{
		//SET_BIT(UCSRB,TXB8);
		//}
		//UDR = Copy_U16_data;
	}
}

void MUART_Void_sendString(u8* Copy_U8_string)
{
	u8 index = 0;
	/*Checking 9-bit Mode*/
	if ((GET_BIT(UCSRB,UCSZ2)) == 0)
	{
		while((GET_BIT(UCSRA,UDRE)) == 0);
		while(Copy_U8_string[index] != '\0')
		{
			UDR = Copy_U8_string[index];
			index++;
		}
	}
	else
	{
		//while((GET_BIT(UCSRA,UDRE)) == 0);
		//while(Copy_U16_string[index] != '\0')
		//{
		//if ((GET_BIT(Copy_U16_string[index],9)) == 0)
		//{
		//CLEAR_BIT(UCSRB,TXB8);
		//}
		//else
		//{
		//SET_BIT(UCSRB,TXB8);
		//}
		//UDR = Copy_U16_string[index];
		//index++;
		//}
	}
}

u8 MUART_U8_recieveByte()
{
	u8 dataReceived = 0;
	/*Checking 9-Bit Mode*/
	if ((GET_BIT(UCSRB,UCSZ2)) == 0)
	{
		while ((GET_BIT(UCSRA,RXC)) == 0);
		dataReceived = UDR;
	}
	else
	{
		//while ((GET_BIT(UCSRA,RXC)) == 0);
		//dataReceived = GET_BIT(UCSRB,RXB8);
		//dataReceived &= RXC_MASK; //0x01
		//dataReceived = (dataReceived << 8)|UDR;
	}
	return dataReceived;
}

void MUART_Void_recieveString(u8* ptrToResceivedString)
{
	u8 index = 0;
	while((GET_BIT(UCSRA,UDRE)) == 0);
	while( UDR != '\0')
	{
		*ptrToResceivedString[index] = UDR;
		index++;
	}

}

