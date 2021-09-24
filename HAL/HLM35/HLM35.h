/*
 * HLM35.h
 *
 * Created: 21/09/2021 01:11:48 م
 *  Author: Ahmed Gaber
 */ 


#ifndef HLM35_H_
#define HLM35_H_
#include "LSTD_TYPES.h"
#define TEMPERATURE_CHANNEL ADC0
#define V_REFERENCE 5000
#define RESOLUTION 1024
u8 HLM35_U8_readTemperature();




#endif /* HLM35_H_ */