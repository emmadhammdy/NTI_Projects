/*
 * segement_7.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Emad Hamdy
 */

#include <stdio.h>

#include "segment_7.h"
#include "GPIO_Driver.h"

void sevSeg_init() {
	// setting PINS directions //
	DIO_voidSetPinDirection(pB, 0, OUTPUT); // setting PB0 direction as output //
	DIO_voidSetPinDirection(pB, 1, OUTPUT); // setting PB1 direction as output //
	DIO_voidSetPinDirection(pB, 2, OUTPUT); // setting PB2 direction as output //
	DIO_voidSetPinDirection(pB, 4, OUTPUT); // setting PB4 direction as output //

	// setting the pin PA3 as output //
	DIO_voidSetPinDirection(pA, 3, HIGH); // setting PA3 direction as output //

	// as common anode LOW voltage will be provided to the pin //
	DIO_voidSetPinValue(pA, 3, LOW); // setting PA3 direction as output //

}

void sevSeg_num(usint8_t number) {
	if (number > 9) {
		// do nothing
	} else {
		switch (number) {
		case 0:
			DIO_voidSetPinValue(pB, 0, LOW);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 1:

			DIO_voidSetPinValue(pB, 0, HIGH);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 2:
			DIO_voidSetPinValue(pB, 0, LOW);
			DIO_voidSetPinValue(pB, 1, HIGH);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 3:
			DIO_voidSetPinValue(pB, 0, HIGH);
			DIO_voidSetPinValue(pB, 1, HIGH);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 4:
			DIO_voidSetPinValue(pB, 0, LOW);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, HIGH);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 5:

			DIO_voidSetPinValue(pB, 0, HIGH);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, HIGH);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 6:
			DIO_voidSetPinValue(pB, 0, LOW);
			DIO_voidSetPinValue(pB, 1, HIGH);
			DIO_voidSetPinValue(pB, 2, HIGH);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 7:
			DIO_voidSetPinValue(pB, 0, HIGH);
			DIO_voidSetPinValue(pB, 1, HIGH);
			DIO_voidSetPinValue(pB, 2, HIGH);
			DIO_voidSetPinValue(pB, 4, LOW);
			break;
		case 8:
			DIO_voidSetPinValue(pB, 0, LOW);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, HIGH);
			break;
		case 9:
			DIO_voidSetPinValue(pB, 0, HIGH);
			DIO_voidSetPinValue(pB, 1, LOW);
			DIO_voidSetPinValue(pB, 2, LOW);
			DIO_voidSetPinValue(pB, 4, HIGH);
			break;
		default:
			break;
		}
	}
}
