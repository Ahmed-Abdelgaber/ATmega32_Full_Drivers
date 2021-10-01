/*
 * TIMER0_Private.h
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef MTIMER0_MTIMER0_PRIVATE_H_
#define MTIMER0_MTIMER0_PRIVATE_H_

#define TCCR0   *((volatile u8*)0x53)
#define TIMSK   *((volatile u8*)0x59)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)

#define WGM00 6
#define WGM01 3
#define TOIE0 0
#define TCIE0 1
#define COM20 4
#define COM21 5

#define NO_PRESCALER 1
#define PRESCALER_8 2
#define PRESCALER_64 3
#define PRESCALER_256 4
#define PRESCALLER_1024 5
#define EXTERNAL_EVENT_FALLING_EDGE 6
#define EXTERNAL_EVENT_RISING_EDGE 7

#define TIMER0_OVF_MODE 1
#define TIMER0_CTC_MODE 2
#define TIMER0_FAST_PWM            2
#define TIMER0_PHASE_CORRECT_PWM   3

#define FAST_PWM_NON_INVERTING     1
#define FAST_PWM_INVERTING         2

#define PHASE_CORRECT_PWM_NON_INVERTING  1
#define PHASE_CORRECT_PWM_INVERTING      2

#define PRESCALER_MASK 0xF8



#endif /* MTIMER0_MTIMER0_PRIVATE_H_ */
