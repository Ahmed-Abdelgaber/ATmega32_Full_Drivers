/*
 * MEXTINT_Private.h
 *
 *  Created on: ٢٩‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef MEXTINT_MEXTINT_PRIVATE_H_
#define MEXTINT_MEXTINT_PRIVATE_H_

#define SREG   (*((volatile u8*)0x5F))
#define I_BIT 7

#define MCUCR  (*((volatile u8*)0x55))
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR (*((volatile u8*)0x54))
#define ISC2 6

#define GICR   (*((volatile u8*)0x5B))
#define INT2 5
#define INT0 6
#define INT1 7

#define GIFR   (*((volatile u8*)0x5A))
#define INTF2 5
#define INTF0 6
#define INTF1 7

#endif /* MEXTINT_MEXTINT_PRIVATE_H_ */
