/*
 * MDIO.h
 *
 *  Created on: ??�/??�/????
 *      Author: Ahmed Gaber
 */

#ifndef MDIO_MDIO_H_
#define MDIO_MDIO_H_
#include "LSTD_TYPES.h"
typedef enum {
	PORT_A = 0, PORT_B, PORT_C, PORT_D
} portName;

typedef enum {
	PIN0 = 0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} pinNumber;


typedef enum {
	INPUT = 0, OUTPUT
} pinDirection;


typedef union
{
	struct
	{
		u16 Pin0:2;
		u16 Pin1:2;
		u16 Pin2:2;
		u16 Pin3:2;
		u16 Pin4:2;
		u16 Pin5:2;
		u16 Pin6:2;
		u16 Pin7:2;
	}Pin;
}currentPort;

typedef enum {
	LOW = 0, HIGH = 1,NOTUSED= 2
} value;

void MDIO_Void_setPinValue(portName port, pinNumber pin, value val);
void MDIO_Void_setPinDirection(portName port, pinNumber pin,pinDirection direction);
value MDIO_Value_getPinValue(portName port, pinNumber pin);
void MDIO_Void_setPortValue(portName port,u8 val);
void MDIO_Void_setPortDirection(portName port, pinDirection direction);
void MDIO_Void_setSpecifcBitsValue(portName port,currentPort* currentPortVlue);

#endif /* MDIO_MDIO_H_ */
