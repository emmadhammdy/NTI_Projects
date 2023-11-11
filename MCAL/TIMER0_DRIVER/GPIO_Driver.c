/*
 * GPIO_Driver.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Emad Hamdy
 */
#include "GPIO_Driver.h"

prephieral_t* pD= (volatile prephieral_t*)0x30;
prephieral_t* pC= (volatile prephieral_t*)0x33;
prephieral_t* pB= (volatile prephieral_t*)0x36;
prephieral_t* pA= (volatile prephieral_t*)0x39;


void DIO_voidSetPinDirection(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{


	switch(Copy_u8PinId)
	{
	case 0:
		Copy_u8PortId->Direction.bit_access.bit_0= Copy_u8Direction;
		break;
	case 1:
		Copy_u8PortId->Direction.bit_access.bit_1=Copy_u8Direction;
		break;
	case 2:
			Copy_u8PortId->Direction.bit_access.bit_2=Copy_u8Direction;
			break;
	case 3:
			Copy_u8PortId->Direction.bit_access.bit_3=Copy_u8Direction;
			break;
	case 4:
			Copy_u8PortId->Direction.bit_access.bit_4=Copy_u8Direction;
			break;
	case 5:
			Copy_u8PortId->Direction.bit_access.bit_5=Copy_u8Direction;
			break;
	case 6:
			Copy_u8PortId->Direction.bit_access.bit_6=Copy_u8Direction;
			break;
	case 7:
			Copy_u8PortId->Direction.bit_access.bit_7=Copy_u8Direction;
			break;
	default:
		break;

	}


}
void DIO_voidSetPinValue(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	switch(Copy_u8PinId)
	{
	case 0:
			Copy_u8PortId->output.bit_access.bit_0= Copy_u8Value;
			break;
		case 1:
			Copy_u8PortId->output.bit_access.bit_1=Copy_u8Value;
			break;
		case 2:
				Copy_u8PortId->output.bit_access.bit_2=Copy_u8Value;
				break;
		case 3:
				Copy_u8PortId->output.bit_access.bit_3=Copy_u8Value;
				break;
		case 4:
				Copy_u8PortId->output.bit_access.bit_4=Copy_u8Value;
				break;
		case 5:
				Copy_u8PortId->output.bit_access.bit_5=Copy_u8Value;
				break;
		case 6:
				Copy_u8PortId->output.bit_access.bit_6=Copy_u8Value;
				break;
		case 7:
				Copy_u8PortId->output.bit_access.bit_7=Copy_u8Value;
				break;
		default:
			break;
	}

}
u8 DIO_voidGetPinValue(prephieral_t *Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 value=0;
	switch(Copy_u8PinId)
	{
	case 0:
		value=Copy_u8PortId->Input.bit_access.bit_0;
		break;
	case 1:
		value=Copy_u8PortId->Input.bit_access.bit_1;
		break;
	case 2:
		value=Copy_u8PortId->Input.bit_access.bit_2;
		break;
	case 3:
		value=Copy_u8PortId->Input.bit_access.bit_3;
		break;
	case 4:
		value=Copy_u8PortId->Input.bit_access.bit_4;
		break;
	case 5:
		value=Copy_u8PortId->Input.bit_access.bit_5;
		break;
	case 6:
		value=Copy_u8PortId->Input.bit_access.bit_6;
		break;
	case 7:
		value=Copy_u8PortId->Input.bit_access.bit_7;
		break;
	}

	return value;
}
void DIO_voidSetPortDirection(prephieral_t *Copy_u8PortId, u8 Copy_ugDirection)
{
	Copy_u8PortId->Direction.All_bits=Copy_ugDirection;

}
void DIO_voidSetPortValue(prephieral_t *Copy_u8PortId, u8 Copy_u8Value)
{
	Copy_u8PortId->output.All_bits=Copy_u8Value;

}
u8 DIO_voidGetportValue(prephieral_t *Copy_u8PortId)
{
	u8 value = Copy_u8PortId->Input.All_bits;


	return value;
}

