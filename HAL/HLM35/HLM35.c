/*
 * HLM35.c
 *
 * Created: 21/09/2021 01:12:06 م
 *  Author: Ahmed Gaber
 */ 
#include "HLM35.h"
#include "MADC.h"
#include "LSTD_TYPES.h"

u8 HLM35_U8_readTemperature()
{
	u16 ADC_digitalValue = MADC_U16_readDigitalValue(TEMPERATURE_CHANNEL);
	u32 melliVolt = ((u32)ADC_digitalValue * V_REFERENCE)/RESOLUTION;
	u8 temperature = melliVolt/10;
	return temperature;	
}