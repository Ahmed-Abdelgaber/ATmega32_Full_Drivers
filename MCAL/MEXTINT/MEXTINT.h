/*
 * MEXTINT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Gaber
 */

#ifndef MEXTINT_MEXTINT_H_
#define MEXTINT_MEXTINT_H_
#include "LSTD_TYPES.h"
#include "MEXTINT_Private.h"

#define INT0 6
#define INT1 7
#define INT2 5

#define RISE_EDGE 1
#define FALL_EDGE 2
#define ANY_CHANG 3
#define LOW_LEVEL 4

void MEXTINT_Void_enableGlobalInt();
void MEXTINT_Void_disableGlobalInt();
void MEXTINT_Void_enableIntNumber(u8 intNumber,u8 intMode);
void MEXTINT_Void_disableIntNumber(u8 intNumber);
void MEXINIT_Void_setCallBack_INT0(void (*ptrToISR)(void));
void MEXINIT_Void_setCallBack_INT1(void (*ptrToISR)(void));
void MEXINIT_Void_setCallBack_INT2(void (*ptrToISR)(void));
#endif /* MEXTINT_MEXTINT_H_ */
