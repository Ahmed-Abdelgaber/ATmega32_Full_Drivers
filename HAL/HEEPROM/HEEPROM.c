/*
 * HEEPROM.c
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */


#include "HEEPROM.h"
#include "LSTD_TYPES.h"
#include "MDIO.h"
#include "MTWI.h"

void HEEPROM_void_init()
{
	MTWI_Init();
}
u8 HEEPROM_u8_read(u16 add,u8 *ptr_to_data)
{
	u8 _3MSB; //contains the 3 msb of 11 it address + w\r bit
	u8 state;
	/*sent start bit*/
	MTWI_u8_SEND_START_BIT();
	/*check status code*/
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_START_SUCCESS)
	{
		return 0;
	}
	/*send address + write*/
	_3MSB=(add>>8)<<1;
	MTWI_SEND_DATA(0xA0|_3MSB|WRITE);
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_T_SLAVE_ADDRESS_ACK){
		return 2;
	}
	MTWI_SEND_DATA(add);
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_T_DATA_ACK){
		return 3;
	}
	/*send repeated start bit again*/
	MTWI_u8_SEND_START_BIT();
	/*check status code*/
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_REPEATED_START_SUCCESS){
		return 4;
	}
	/*edit read bit*/
	MTWI_SEND_DATA(0xA0|READ);
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_R_SLAVE_ADDRESS_ACK){
		return 5;
	}
	/*read data*/
	*ptr_to_data=MTWI_READ_DATA_ACK();
	state = MTWI_u8_GETSTATUS();
	/*check state*/
	if (state!=MTWI_M_R_DATA_ACK){
		return 6;
	}
	/*send stop*/
	MTWI_u8_SEND_STOP_BIT();
	return 1;
}
u8 HEEPROM_u8_write(u16 add,u8 data){
	u8 _3MSB; //contains the 3 msb of 11 it address + w\r bit
	u8 _8LSB;
	u8 state;
	/*sent start bit*/
	MTWI_u8_SEND_START_BIT();
	/*check status code*/
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_START_SUCCESS){
		return 0;
	}
	/*send address + write*/
	_3MSB=(add>>8)<<1;
	MTWI_SEND_DATA(0xA0|_3MSB|WRITE);
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_T_SLAVE_ADDRESS_ACK){
		return 0;
	}
	/*send the rest of the address*/
	MTWI_SEND_DATA(add);
	state = MTWI_u8_GETSTATUS();
	if (state!=MTWI_M_T_DATA_ACK){
		return 0;
	}
	/*send the data*/
	MTWI_SEND_DATA(data);
	if (state!=MTWI_M_T_DATA_ACK){
		return 0;
	}
	/*send stop bit*/
	MTWI_u8_SEND_STOP_BIT();
	return 1;
}
