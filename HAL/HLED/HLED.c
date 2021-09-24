#include "LSTD_TYPES.h"
#include "HLED.h"

void HLED_Void_ledIntialize() {
	MDIO_Void_setPinDirection(LED0_PORT, LED0_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED1_PORT, LED1_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED2_PORT, LED2_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED3_PORT, LED3_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED4_PORT, LED4_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED5_PORT, LED5_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED6_PORT, LED6_PIN, OUTPUT);
	MDIO_Void_setPinDirection(LED7_PORT, LED7_PIN, OUTPUT);
}
void HLED_Void_setON(u8 ledNumber) {
	switch (ledNumber) {
	case LED0:
		MDIO_Void_setPinValue(LED0_PORT, LED0_PIN, HIGH);
		break;
	case LED1:
		MDIO_Void_setPinValue(LED1_PORT, LED1_PIN, HIGH);
		break;
	case LED2:
		MDIO_Void_setPinValue(LED2_PORT, LED2_PIN, HIGH);
		break;
	case LED3:
		MDIO_Void_setPinValue(LED3_PORT, LED3_PIN, HIGH);
		break;
	case LED4:
		MDIO_Void_setPinValue(LED4_PORT, LED4_PIN, HIGH);
		break;
	case LED5:
		MDIO_Void_setPinValue(LED5_PORT, LED5_PIN, HIGH);
		break;
	case LED6:
		MDIO_Void_setPinValue(LED6_PORT, LED6_PIN, HIGH);
		break;
	case LED7:
		MDIO_Void_setPinValue(LED7_PORT, LED7_PIN, HIGH);
		break;
	}

}
void HLED_Void_setOff(u8 ledNumber) {
	switch (ledNumber) {
	case LED0:
		MDIO_Void_setPinValue(LED0_PORT, LED0_PIN, LOW);
		break;
	case LED1:
		MDIO_Void_setPinValue(LED1_PORT, LED1_PIN, LOW);
		break;
	case LED2:
		MDIO_Void_setPinValue(LED2_PORT, LED2_PIN, LOW);
		break;
	case LED3:
		MDIO_Void_setPinValue(LED3_PORT, LED3_PIN, LOW);
		break;
	case LED4:
		MDIO_Void_setPinValue(LED4_PORT, LED4_PIN, LOW);
		break;
	case LED5:
		MDIO_Void_setPinValue(LED5_PORT, LED5_PIN, LOW);
		break;
	case LED6:
		MDIO_Void_setPinValue(LED6_PORT, LED6_PIN, LOW);
		break;
	case LED7:
		MDIO_Void_setPinValue(LED7_PORT, LED7_PIN, LOW);
		break;
	}
}
