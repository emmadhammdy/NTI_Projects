/*
 * GPIO_Driver.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Emad Hamdy
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "STD_TYPES.h"

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



void DIO_voidSetPinDirection(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);
void DIO_voidSetPinValue(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);
u8 DIO_voidGetPinValue(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId);
void DIO_voidSetPortDirection(prephieral_t *Copy_u8PortId, u8 Copy_ugDirection);
void DIO_voidSetPortValue(prephieral_t *Copy_u8PortId, u8 Copy_u8Value);
u8 DIO_voidGetportValue(prephieral_t *Copy_u8PortId);

#endif /* GPIO_DRIVER_H_ */
