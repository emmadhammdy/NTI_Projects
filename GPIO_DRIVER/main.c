/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Emad Hamdy
 */

#include <stdio.h>
#include "GPIO_Driver.h"
#define F_CPU 16000000
#include <avr/delay.h>

int main() {

	DIO_voidSetPinDirection(pA, 6, 1);
	DIO_voidSetPinDirection(pA, 5, 1);

	while (1) {

		DIO_voidSetPinValue(pA, 6, 1);
		_delay_ms(500);
		DIO_voidSetPinValue(pA, 6, 0);
		_delay_ms(500);
		DIO_voidSetPinValue(pA, 5, 1);
		_delay_ms(500);
		DIO_voidSetPinValue(pA, 5, 0);
		_delay_ms(500);

	}

	return 0;
}
