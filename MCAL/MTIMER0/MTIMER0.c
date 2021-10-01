/*
 * TIMER0.c
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MTIMER0_Private.h"
#include "MTIMER0.h"
#include "MTIMER0_Config.h"
void MTIMER0_Void_init()
{
	#if TIMER0_MODE == TIMER0_OVF_MODE
	/*Normal Mode*/
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/*Interrupt Enable*/
	SET_BIT(TIMSK,TOIE0);
	#elif TIMER0_MODE == TIMER0_CTC_MODE
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*Interrupt Enable*/
	SET_BIT(TIMSK,TCIE0);
	#elif TIMER0_MODE == TIMER0_FAST_PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#if TIMER0_PWM_MODE == FAST_PWM_NON_INVERTING
	CLEAR_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
	#elif TIMER0_PWM_MODE==FAST_PWM_INVERTING
	SET_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
	#else
	#error "your Timer0 PWM mode invalid "
	#endif
	#elif TIMER0_MODE==TIMER0_PHASE_CORRECT_PWM

	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	#if TIMER0_PWM_MODE==PHASE_CORRECT_PWM_NON_INVERTING
	CLEAR_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
	#elif TIMER0_PWM_MODE==PHASE_CORRECT_PWM_INVERTING
	SET_BIT(TCCR0,COM20);
	SET_BIT(TCCR0,COM21);
	#else
	#error "your Timer0 PWM mode invalid "
	#endif
	#else
	#error "UNVALID TIMER0 MODE"
	#endif
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIMER_PRESCALER;
}

void MTIMER0_Void_setPreloadValue(u8 Copy_U8_preloadValue)
{
	TCNT0 = Copy_U8_preloadValue;
}

void MTIMER0_Void_setCTCValue(u8 Copy_U8_CTCValue)
{
	OCR0 = Copy_U8_CTCValue;
}
