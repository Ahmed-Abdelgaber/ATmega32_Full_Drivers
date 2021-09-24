/*
 * MEXTINT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Gaber
 */

#include "MEXTINT.h"
#include "MEXTINT_Private.h"
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include <avr/interrupt.h>

void (*ptrToISRINT0)(void);
void (*ptrToISRINT1)(void);
void (*ptrToISRINT2)(void);

void MEXTINT_Void_enableGlobalInt()
{
	SET_BIT(SREG,I_BIT);
}
void MEXTINT_Void_disableGlobalInt()
{
	CLEAR_BIT(SREG,I_BIT);
}

void MEXTINT_Void_enableIntNumber(u8 intNumber,u8 intMode)
{
	//Step 1: Enable General Interrupt
	SET_BIT(SREG,I_BIT);
	//Step 2: Enable The Interrupt
	SET_BIT(GICR,intNumber);
	//Step 3: Determine Mode
	if(intNumber == INT0)
	{
		switch(intMode)
		{
		case RISE_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case FALL_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case ANY_CHANG:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		}
	}
	else if(intNumber == INT1)
	{
		switch(intMode)
		{
		case RISE_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case FALL_EDGE:
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
		case ANY_CHANG:
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
		}
	}
	else if(intNumber == INT2)
	{

		switch(intMode)
		{
		case RISE_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
		case FALL_EDGE:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
		}
	}
}

void MEXTINT_Void_disableIntNumber(u8 intNumber)
{
	//Step 1:disable general interrupt
	//CLEAR_BIT(SREG,I_BIT);
	//Step 2:disable interrupt
	CLEAR_BIT(GICR,intNumber);
}

void MEXINIT_Void_setCallBack_INT0(void (*ptrToISR)(void))
{
	ptrToISRINT0 = ptrToISR;
}
void MEXINIT_Void_setCallBack_INT1(void (*ptrToISR)(void))
{
	ptrToISRINT1 = ptrToISR;
}
void MEXINIT_Void_setCallBack_INT2(void (*ptrToISR)(void))
{
	ptrToISRINT2 = ptrToISR;
}

ISR(INT0_vect)
{
	ptrToISRINT0();
}

ISR(INT1_vect)
{
	ptrToISRINT1();
}

ISR(INT2_vect)
{
	ptrToISRINT2();
}
