/*
 * HLM35.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef HLM35_HLM35_H_
#define HLM35_HLM35_H_

#include "LSTD_TYPES.h"
#define TEMPERATURE_CHANNEL ADC0
#define V_REFERENCE 5000
#define RESOLUTION 1024
u8 HLM35_U8_readTemperature();


#endif /* HLM35_HLM35_H_ */
