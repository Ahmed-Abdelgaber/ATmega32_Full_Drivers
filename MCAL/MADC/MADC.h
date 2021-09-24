/*
* MADC.h
*
* Created: 19/09/2021 10:57:51 ص
*  Author: Ahmed Gaber
*/


#ifndef MADC_H_
#define MADC_H_

#include "LSTD_TYPES.h"

typedef enum
{
	preScaler_2 = 1,
	preScaler_4,
	preScaler_8,
	preScaler_16,
	preScaler_32,
	preScaler_64,
	preScaler_128
	
}ADC_preScaler;

typedef enum
{
	AREF = 0b00000000 ,
	AVCC = 0b01000000,
	INTERNAL = 0b11000000
}ADC_refrenceType;

typedef enum
{
	ADC0 = 0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_channel;

void MADC_Void_ADCinit(ADC_preScaler preScaler, ADC_refrenceType source);
u16 MADC_U16_readDigitalValue(ADC_channel channel);



#endif /* MADC_H_ */