#ifndef HLED_H_
#define HLED_H_
#include "MDIO.h"

#define LED0 0
#define LED0_PORT PORT_C
#define LED0_PIN PIN0
#define LED1 1
#define LED1_PORT PORT_C
#define LED1_PIN PIN1
#define LED2 2
#define LED2_PORT PORT_C
#define LED2_PIN PIN2
#define LED3 3
#define LED3_PORT PORT_A
#define LED3_PIN PIN3
#define LED4 4
#define LED4_PORT PORT_A
#define LED4_PIN PIN4
#define LED5 5
#define LED5_PORT PORT_A
#define LED5_PIN PIN5
#define LED6 6
#define LED6_PORT PORT_A
#define LED6_PIN PIN6
#define LED7 7
#define LED7_PORT PORT_A
#define LED7_PIN PIN7

void HLED_Void_ledIntialize(); //Set Direction
void HLED_Void_setON(u8 ledNumber);
void HLED_Void_setOff(u8 ledNumber);

#endif
