/*
 * HLCD_Config.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef HLCD_HLCD_CONFIG_H_
#define HLCD_HLCD_CONFIG_H_

#include "HLCD_Private.h"

#define PORT_DATA    PORT_D
#define PORT_CONTROL PORT_A

#define RS PIN5
#define RW PIN6
#define E  PIN7

#define FUNCTION_SET FUNCTION_SET_8BITS_2LINES
#define DISPLAY_ON_OFF DISPLAY_ON_CURSOR_BLINKING
#define ENTRY_MODE_SET ENTRY_MODE_SET_INCREMENT_SHIFT

#endif /* HLCD_HLCD_CONFIG_H_ */
