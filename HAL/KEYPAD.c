/*
 * KEYPAD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Emad Hamdy
 */

#include "KEYPAD.h"
#include "GPIO_Driver.h"

void keypad_cfg() {
	// set ROWS as input
	DIO_voidSetPinDirection(pC, 2, INPUT);
	DIO_voidSetPinDirection(pC, 3, INPUT);
	DIO_voidSetPinDirection(pC, 4, INPUT);
	DIO_voidSetPinDirection(pC, 5, INPUT);
	// set COL as output //
	DIO_voidSetPinDirection(pD, 3, OUTPUT);
	DIO_voidSetPinDirection(pD, 5, OUTPUT);
	DIO_voidSetPinDirection(pD, 6, OUTPUT);
	DIO_voidSetPinDirection(pD, 7, OUTPUT);

	// set COL by default as HIGH //
	DIO_voidSetPinValue(pD, 3, HIGH);
	DIO_voidSetPinValue(pD, 5, HIGH);
	DIO_voidSetPinValue(pD, 6, HIGH);
	DIO_voidSetPinValue(pD, 7, HIGH);



	// set ROWS by default as Pull Up  //
	DIO_voidSetPinValue(pC, 2, HIGH);
	DIO_voidSetPinValue(pC, 3, HIGH);
	DIO_voidSetPinValue(pC, 4, HIGH);
	DIO_voidSetPinValue(pC, 5, HIGH);


}

usint8_t keypad_read(void) {

	usint8_t r, c, keyvalue = -1;
	usint8_t row[4] = { 2, 3, 4, 5 }, col[4] = { 3, 5, 6, 7 };

	for (c = 0; c < 4; c++) {
		DIO_voidSetPinValue(pD, col[c], LOW);

		for (r = 0; r < 4; r++) {
			if (DIO_voidGetPinValue(pC, row[r]) == 0) {
				// Key is pressed
				keyvalue = r * 4 + c;
				// Debouncing delay
				while (DIO_voidGetPinValue(pC, row[r]) == 0);
			}
		}

		// Set the column back to HIGH for the next iteration
		DIO_voidSetPinValue(pD, col[c], HIGH);
	}

	return keyvalue;

}
