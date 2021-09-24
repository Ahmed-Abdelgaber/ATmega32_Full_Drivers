/*
 * MDIO.h
 *
 * Created: 07/09/2021 09:28:44 Õ
 *  Author: Ahmed Gaber
 */

#ifndef MDIO_H_
#define MDIO_H_
#include "LSTD_TYPES.h"
typedef enum {
	PORT_A = 0, PORT_B, PORT_C, PORT_D
} portName;

typedef enum {
	PIN0 = 0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} pinNumber;

typedef enum {
	LOW = 0, HIGH = 1,NOTUSED=2
} value;

typedef enum {
	INPUT = 0, OUTPUT
} pinDirection;

typedef union
{
	struct
	{
		u8 Pin0:1;
		u8 Pin1:1;
		u8 Pin2:1;
		u8 Pin3:1;
		u8 Pin4:1;
		u8 Pin5:1;
		u8 Pin6:1;
		u8 Pin7:1;
	}Pin;
}currentPort;
void MDIO_Void_setPinValue(portName port, pinNumber pin, value val);
void MDIO_Void_setPinDirection(portName port, pinNumber pin,pinDirection direction);
value MDIO_Value_getPinValue(portName port, pinNumber pin);
void MDIO_Void_setPortValue(portName port, u8 val);
void MDIO_Void_setPortDirection(portName port, pinDirection direction);
void MDIO_Void_setSpecifcBitsValue(portName port,currentPort* currentPort);
#endif /* MDIO_H_ */
