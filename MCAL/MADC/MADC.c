/*
* MADC.c
*
* Created: 19/09/2021 10:58:08 ص
*  Author: Ahmed Gaber
*/
#include "MADC.h"
#include "MADC_Private.h"
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

void MADC_Void_ADCinit(ADC_preScaler preScaler, ADC_refrenceType source)
{
	//Step 1: Choose Prescaler
	ADCSRA = preScaler;
	//Step 2: Enable ADC
	SET_BIT(ADCSRA,ADEN);
	//Step 3: Disable Interrupt
	CLEAR_BIT(ADCSRA,ADIE);
	//Step 4: Disable auto trigger
	CLEAR_BIT(ADCSRA,ADATE);
	//Step 5: Choose Reference & Adjust Right
	ADMUX = source;
}
u16 MADC_U16_readDigitalValue(ADC_channel channel)
{
	//Step 1: Choose Channel
	ADMUX &= CHANNEL_MASK;
	ADMUX |= channel;
	
	//Step 2: Start Conversion
	SET_BIT(ADCSRA,ADSC);
	
	//Step 3: Check & Wait Till conversion ends
	while(GET_BIT(ADCSRA,ADSC));
	
	//Step 4: Return Value
	u16 ADC_digitalValue = ADCL + (ADCH << 8);
	return ADC_digitalValue;
}
