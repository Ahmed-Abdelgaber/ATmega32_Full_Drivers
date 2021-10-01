/*
 * APPCALCULATOR.h
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢١
 *      Author: Ahmed Gaber
 */

#ifndef APPCALCULATOR_APPCALCULATOR_H_
#define APPCALCULATOR_APPCALCULATOR_H_


void APP_Void_printPressedButton(u8 pressedButton);
void APP_Void_storeEnteredValue (u32 *ptrToEnteredValue, u8 pressedButton);
void APP_Void_additionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber);
void APP_Void_subtractionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber);
void APP_Void_multiblicationOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber);
void APP_Void_divisionOperation (u32 *ptrToFirstNumber, u32 *ptrToSecondNumber);

#endif /* APPCALCULATOR_APPCALCULATOR_H_ */
