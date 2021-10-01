/*
 * LBIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Gaber
 */

#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

#define  SET_BIT(Reg,Bit) Reg |= (1<<(Bit))
#define  CLEAR_BIT(Reg,Bit) Reg &= ~(1<<(Bit))
#define  TOGGEL_BIT(Reg,Bit) Reg ^= (1<<(Bit))
#define  GET_BIT(Reg,Bit) (Reg>>(Bit)) & 0x01

#endif /* LBIT_MATH_H_ */
