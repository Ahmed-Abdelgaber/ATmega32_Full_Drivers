/*
 * HEEPROM.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef HEEPROM_HEEPROM_H_
#define HEEPROM_HEEPROM_H_

#include "LSTD_TYPES.h"
#define READ 1
#define WRITE 0
void HEEPROM_void_init();
u8 HEEPROM_u8_read(u16 add,u8 *ptr_to_data);
u8 HEEPROM_u8_write(u16 add,u8 data);

#endif /* HEEPROM_HEEPROM_H_ */
