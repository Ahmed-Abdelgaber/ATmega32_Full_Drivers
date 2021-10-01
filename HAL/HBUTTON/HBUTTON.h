/*
 * HBUTTON.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef HBUTTON_HBUTTON_H_
#define HBUTTON_HBUTTON_H_

#define BUTTON0
#define BUTTON0_PORT PORT_D
#define BUTTON0_PIN PIN2
#define BUTTON1
#define BUTTON1_PORT PORT_D
#define BUTTON1_PIN PIN3
#define BUTTON2
#define BUTTON2_PORT PORT_B
#define BUTTON2_PIN PIN2

void HBUTTON_Void_puttonInit();
bool HBUTTON_Value_getButtonValue(u8 buttonPort, u8 buttonPin);

#endif /* HBUTTON_HBUTTON_H_ */
