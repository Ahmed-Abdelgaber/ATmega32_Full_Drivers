/*
 * MTWI_interface.h
 *
 *  Created on: Sep 28, 2021
 *      Author: hesham elsedfy
 */

#ifndef MCAL_MTWI_MTWI_INTERFACE_H_
#define MCAL_MTWI_MTWI_INTERFACE_H_

#include  "LSTD_TYPES.h"

#define MTWI_M_START_SUCCESS 0x08
#define MTWI_M_REPEATED_START_SUCCESS 0x10
#define MTWI_M_T_SLAVE_ADDRESS_ACK 0x18 //master has sent the SLAVE ADRESS and received an acknowledgement
#define MTWI_M_T_SLAVE_ADDRESS_NACK 0x20

#define MTWI_M_R_SLAVE_ADDRESS_ACK 0x40
#define MTWI_M_R_SLAVE_ADDRESS_NACK 0x48

#define MTWI_M_T_DATA_ACK 0x28
#define MTWI_M_T_DATA_NACK 0x30

#define MTWI_M_R_DATA_ACK 0x50
#define MTWI_M_R_DATA_NACK 0x58

#define MTWI_ARBITRATION_LOST 0x38
#define MTWI_M_R_SLAVE_ADDRESS_ACK 0x40 //master has sent the SLAVE ADRESS and received an acknowledgement
/*MASTER INTERFACE*/
void MTWI_Init(void);
void MTWI_u8_SEND_START_BIT();
void MTWI_u8_SEND_STOP_BIT();
void MTWI_SEND_DATA(u8 data);
u8 MTWI_READ_DATA_ACK();
u8 MTWI_READ_DATA_NACK();
u8 MTWI_u8_GETSTATUS();

#endif /* MCAL_MTWI_MTWI_INTERFACE_H_ */
