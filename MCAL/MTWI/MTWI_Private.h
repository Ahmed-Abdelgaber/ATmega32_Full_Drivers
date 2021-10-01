/*
 * MTWI_private.h
 *
 *  Created on: Sep 28, 2021
 *      Author: hesham elsedfy
 */

#ifndef MCAL_MTWI_MTWI_PRIVATE_H_
#define MCAL_MTWI_MTWI_PRIVATE_H_

#include "LSTD_TYPES.h"

#define MTWI_TWDR (*((volatile u8*)0x23))
#define MTWI_TWAR (*((volatile u8*)0x22))
#define MTWI_TWCR (*((volatile u8*)0x56))
#define MTWI_TWSR (*((volatile u8*)0x21))
#define MTWI_TWBR (*((volatile u8*)0x20))

/*MTWI_TWCR*/
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7
/*TWSR BITS*/
#define TWPS0 0
#define TWPS1 1

#define TWS3 0
#define TWS4 1
#define TWS5 2
#define TWS6 3
#define TWS7 4

/*MTWI_TWAR*/
#define TWGCE 0
/*prescaler bits*/
#define MTWI_PRESCALER_1 0
#define MTWI_PRESCALER_4 1
#define MTWI_PRESCALER_16 2
#define MTWI_PRESCALER_64 3
#endif /* MCAL_MTWI_MTWI_PRIVATE_H_ */
