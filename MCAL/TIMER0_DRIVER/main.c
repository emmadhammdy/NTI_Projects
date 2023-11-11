/*
 * main.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Emad Hamdy
 */



#include "TIMER0_interfacec.h"
#include "GPIO_Driver.h"
#include <util/delay.h>

int main()
{

	TIMER0_init();
	TIEMR0_START();

	DIO_voidSetPinDirection(pB, 3, 1);

	while(1)
	{
		TIMER0_voidSetPhaseCorrectPWM(70);
	}

	return 0;
}
