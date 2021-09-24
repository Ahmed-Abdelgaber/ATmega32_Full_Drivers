/*
 * MDIO.c
 *
 * Created: 07/09/2021 09:28:22 Õ
 *  Author: Ahmed Gaber
 */
#include "MDIO.h"
#include "MDIO_private.h"
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


void MDIO_Void_setPinValue(portName port, pinNumber pin, value val) {
	if (val == HIGH) {
		switch (port) {
		case PORT_A:
			SET_BIT(PORTA, pin);
			break;
		case PORT_B:
			SET_BIT(PORTB, pin);
			break;
		case PORT_C:
			SET_BIT(PORTC, pin);
			break;
		case PORT_D:
			SET_BIT(PORTD, pin);
			break;
		}
	} else if (val == LOW) {
		switch (port) {
		case PORT_A:
			CLEAR_BIT(PORTA, pin);
			break;
		case PORT_B:
			CLEAR_BIT(PORTB, pin);
			break;
		case PORT_C:
			CLEAR_BIT(PORTC, pin);
			break;
		case PORT_D:
			CLEAR_BIT(PORTD, pin);
			break;
		}
	}
}
void MDIO_Void_setPinDirection(portName port, pinNumber pin,pinDirection direction) {
	if (direction == INPUT) {
		switch (port) {
		case PORT_A:
			CLEAR_BIT(DDRA, pin);
			break;
		case PORT_B:
			CLEAR_BIT(DDRB, pin);
			break;
		case PORT_C:
			CLEAR_BIT(DDRC, pin);
			break;
		case PORT_D:
			CLEAR_BIT(DDRD, pin);
			break;
		}
	} else if (direction == OUTPUT) {
		switch (port) {
		case PORT_A:
			SET_BIT(DDRA, pin);
			break;
		case PORT_B:
			SET_BIT(DDRB, pin);
			break;
		case PORT_C:
			SET_BIT(DDRC, pin);
			break;
		case PORT_D:
			SET_BIT(DDRD, pin);
			break;
		}
	}
}
value MDIO_Value_getPinValue(portName port, pinNumber pin) {
	value val = 2;
	switch (port) {
	case PORT_A:
		val = GET_BIT(PINA, pin);
		break;
	case PORT_B:
		val = GET_BIT(PINB, pin);
		break;
	case PORT_C:
		val = GET_BIT(PINC, pin);
		break;
	case PORT_D:
		val = GET_BIT(PIND, pin);
		break;
	}
	return val;
}
void MDIO_Void_setPortValue(portName port, u8 val) {
	switch (port) {
	case PORT_A:
		PORTA = val;
		break;
	case PORT_B:
		PORTB = val;
		break;
	case PORT_C:
		PORTC = val;
		break;
	case PORT_D:
		PORTD = val;
		break;
	}
}
void MDIO_Void_setPortDirection(portName port, pinDirection direction) {
	if (direction == OUTPUT) {
		switch (port) {
		case PORT_A:
			DDRA = 0xFF;
			break;
		case PORT_B:
			DDRB = 0xFF;
			break;
		case PORT_C:
			DDRC = 0xFF;
			break;
		case PORT_D:
			DDRD = 0xFF;
			break;
		}
	} else if (direction == INPUT) {
		switch (port) {
		case PORT_A:
			DDRA = 0x00;
			break;
		case PORT_B:
			DDRB = 0x00;
			break;
		case PORT_C:
			DDRC = 0x00;
			break;
		case PORT_D:
			DDRD = 0x00;
			break;
		}
	}

}

void MDIO_Void_setSpecifcBitsValue(portName port,currentPort* currentPort)
{
	switch (port) {
		case PORT_A:
		if(currentPort->Pin.Pin0==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN0,HIGH);
		}
		else if (currentPort->Pin.Pin0==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN0,LOW);
		}
		if(currentPort->Pin.Pin1==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN1,HIGH);
		}
		else if (currentPort->Pin.Pin1==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN1,LOW);
		}
		if(currentPort->Pin.Pin2==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN2,HIGH);
		}
		else if (currentPort->Pin.Pin2==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN2,LOW);
		}
		if(currentPort->Pin.Pin3==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN3,HIGH);
		}
		else if (currentPort->Pin.Pin3==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN3,LOW);
		}
		if(currentPort->Pin.Pin4==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN4,HIGH);
		}
		else if (currentPort->Pin.Pin4==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN4,LOW);
		}
		if(currentPort->Pin.Pin5==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN5,HIGH);
		}
		else if (currentPort->Pin.Pin5==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN5,LOW);
		}
		if(currentPort->Pin.Pin6==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN6,HIGH);
		}
		else if (currentPort->Pin.Pin6==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN6,LOW);
		}
		if(currentPort->Pin.Pin7==HIGH)
		{
			MDIO_Void_setPinValue(PORT_A,PIN7,HIGH);
		}
		else if (currentPort->Pin.Pin7==LOW)
		{
			MDIO_Void_setPinValue(PORT_A,PIN7,LOW);
		}
		break;
		case PORT_B:
		
		if(currentPort->Pin.Pin0==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN0,HIGH);
		}
		else if (currentPort->Pin.Pin0==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN0,LOW);
		}
		if(currentPort->Pin.Pin1==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN1,HIGH);
		}
		else if (currentPort->Pin.Pin1==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN1,LOW);
		}
		if(currentPort->Pin.Pin2==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN2,HIGH);
		}
		else if (currentPort->Pin.Pin2==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN2,LOW);
		}
		if(currentPort->Pin.Pin3==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN3,HIGH);
		}
		else if (currentPort->Pin.Pin3==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN3,LOW);
		}
		if(currentPort->Pin.Pin4==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN4,HIGH);
		}
		else if (currentPort->Pin.Pin4==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN4,LOW);
		}
		if(currentPort->Pin.Pin5==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN5,HIGH);
		}
		else if (currentPort->Pin.Pin5==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN5,LOW);
		}
		if(currentPort->Pin.Pin6==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN6,HIGH);
		}
		else if (currentPort->Pin.Pin6==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN6,LOW);
		}
		if(currentPort->Pin.Pin7==HIGH)
		{
			MDIO_Void_setPinValue(PORT_B,PIN7,HIGH);
		}
		else if (currentPort->Pin.Pin7==LOW)
		{
			MDIO_Void_setPinValue(PORT_B,PIN7,LOW);
		}
		
		break;
		case PORT_C:
		
		if(currentPort->Pin.Pin0==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN0,HIGH);
		}
		else if (currentPort->Pin.Pin0==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN0,LOW);
		}
		if(currentPort->Pin.Pin1==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN1,HIGH);
		}
		else if (currentPort->Pin.Pin1==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN1,LOW);
		}
		if(currentPort->Pin.Pin2==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN2,HIGH);
		}
		else if (currentPort->Pin.Pin2==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN2,LOW);
		}
		if(currentPort->Pin.Pin3==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN3,HIGH);
		}
		else if (currentPort->Pin.Pin3==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN3,LOW);
		}
		if(currentPort->Pin.Pin4==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN4,HIGH);
		}
		else if (currentPort->Pin.Pin4==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN4,LOW);
		}
		if(currentPort->Pin.Pin5==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN5,HIGH);
		}
		else if (currentPort->Pin.Pin5==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN5,LOW);
		}
		if(currentPort->Pin.Pin6==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN6,HIGH);
		}
		else if (currentPort->Pin.Pin6==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN6,LOW);
		}
		if(currentPort->Pin.Pin7==HIGH)
		{
			MDIO_Void_setPinValue(PORT_C,PIN7,HIGH);
		}
		else if (currentPort->Pin.Pin7==LOW)
		{
			MDIO_Void_setPinValue(PORT_C,PIN7,LOW);
		};
		break;
		case PORT_D:
		
		if(currentPort->Pin.Pin0==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN0,HIGH);
		}
		else if (currentPort->Pin.Pin0==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN0,LOW);
		}
		if(currentPort->Pin.Pin1==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN1,HIGH);
		}
		else if (currentPort->Pin.Pin1==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN1,LOW);
		}
		if(currentPort->Pin.Pin2==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN2,HIGH);
		}
		else if (currentPort->Pin.Pin2==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN2,LOW);
		}
		if(currentPort->Pin.Pin3==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN3,HIGH);
		}
		else if (currentPort->Pin.Pin3==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN3,LOW);
		}
		if(currentPort->Pin.Pin4==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN4,HIGH);
		}
		else if (currentPort->Pin.Pin4==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN4,LOW);
		}
		if(currentPort->Pin.Pin5==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN5,HIGH);
		}
		else if (currentPort->Pin.Pin5==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN5,LOW);
		}
		if(currentPort->Pin.Pin6==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN6,HIGH);
		}
		else if (currentPort->Pin.Pin6==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN6,LOW);
		}
		if(currentPort->Pin.Pin7==HIGH)
		{
			MDIO_Void_setPinValue(PORT_D,PIN7,HIGH);
		}
		else if (currentPort->Pin.Pin7==LOW)
		{
			MDIO_Void_setPinValue(PORT_D,PIN7,LOW);
		}
		break;
	}
	
}