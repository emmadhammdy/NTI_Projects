/*
 * GPIO_Driver.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Emad Hamdy
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "platformtypes.h"

typedef union
{
	unsigned char All_bits;
	struct
	{
		unsigned char bit_0:1;
		unsigned char bit_1:1;
		unsigned char bit_2:1;
		unsigned char bit_3:1;
		unsigned char bit_4:1;
		unsigned char bit_5:1;
		unsigned char bit_6:1;
		unsigned char bit_7:1;
	}bit_access;
}access_register_t;

typedef struct
{
	access_register_t Input;
	access_register_t Direction;
	access_register_t output;

}_prephieral_t;
typedef volatile _prephieral_t prephieral_t;
prephieral_t* pD;
prephieral_t* pC;
prephieral_t* pB;
prephieral_t* pA;



void DIO_voidSetPinDirection(prephieral_t *Copy_usint8_tPortId, usint8_t Copy_usint8_tPinId, usint8_t Copy_usint8_tDirection);
void DIO_voidSetPinValue(prephieral_t *Copy_usint8_tPortId, usint8_t Copy_usint8_tPinId, usint8_t Copy_usint8_tValue);
usint8_t DIO_voidGetPinValue(prephieral_t *Copy_usint8_tPortId, usint8_t Copy_usint8_tPinId);
void DIO_voidSetPortDirection(prephieral_t *Copy_usint8_tPortId, usint8_t Copy_ugDirection);
void DIO_voidSetPortValue(prephieral_t *Copy_usint8_tPortId, usint8_t Copy_usint8_tValue);
usint8_t DIO_voidGetportValue(prephieral_t *Copy_usint8_tPortId);

#endif /* GPIO_DRIVER_H_ */
