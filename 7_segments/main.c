/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Emad Hamdy
 */
#include <stdio.h>
#define F_CPU 16000000
#include <avr/delay.h>
#include "segment_7.h"


int main() {

	sevSeg_init();

	while (1) {
		sevSeg_num(0);
		_delay_ms(500);
		sevSeg_num(1);
		_delay_ms(500);
		sevSeg_num(2);
		_delay_ms(500);
		sevSeg_num(3);
		_delay_ms(500);
		sevSeg_num(4);
		_delay_ms(500);
		sevSeg_num(5);
		_delay_ms(500);
		sevSeg_num(6);
		_delay_ms(500);
		sevSeg_num(7);
		_delay_ms(500);
		sevSeg_num(8);
		_delay_ms(500);
		sevSeg_num(9);
		_delay_ms(500);

	}
	return 0;
}

