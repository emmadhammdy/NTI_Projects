/*
 * EXTI_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Emad Hamdy
 */

#include <stdio.h>
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "platformtypes.h"
/********************** GOLBAL VARIABLES ********************/

Register_t *EXTI = EXTI_BASE;

void (*voidptrfn[3])(void);
/********************** FUNCTION IMPLEMENTATION ********************/

void EXTI_ENABLE(usint8_t INT_ID, usint8_t TRIG) {

	switch (INT_ID) {
	case INT0_ID:
		SET_BIT(EXTI->GICR, INT0_ID);
		if (TRIG == ANY_CHANGE) {
			SET_BIT(EXTI->MCUCR, 0);
			CLEAR_BIT(EXTI->MCUCR, 1);
		} else if (TRIG == FALLING_EDGE) {
			SET_BIT(EXTI->MCUCR, 1);
			CLEAR_BIT(EXTI->MCUCR, 0);
		} else {
			SET_BIT(EXTI->MCUCR, 1);
			SET_BIT(EXTI->MCUCR, 0);
		}

		break;
	case INT1_ID:
		SET_BIT(EXTI->GICR, INT1_ID);
		if (TRIG == ANY_CHANGE) {
			SET_BIT(EXTI->MCUCR, 2);
			CLEAR_BIT(EXTI->MCUCR, 3);
		} else if (TRIG == FALLING_EDGE) {
			SET_BIT(EXTI->MCUCR, 3);
			CLEAR_BIT(EXTI->MCUCR, 2);
		} else {
			SET_BIT(EXTI->MCUCR, 2);
			SET_BIT(EXTI->MCUCR, 3);
		}
		break;

	case INT2_ID:
		SET_BIT(EXTI->GICR, INT2_ID);
		if (TRIG == FALLING_EDGE) {
			CLEAR_BIT(EXTI->MCUCSR, 6);
		} else if (TRIG == RISING_EDGE) {
			SET_BIT(EXTI->MCUCSR, 6);
		}
		break;
	default:
		break;
	}

}

void EXTI_DISABLE(usint8_t EXTI_ID) {
	switch (EXTI_ID) {
	case INT0_ID:
		CLEAR_BIT(EXTI->GICR, INT0_ID);
		break;
	case INT1_ID:
		CLEAR_BIT(EXTI->GICR, INT1_ID);
		break;
	case INT2_ID:
		CLEAR_BIT(EXTI->GICR, INT2_ID);
		break;
	default:
		break;
	}

}


void EXTI_setCallBack(usint8_t EXTI_ID , void (*ptr)(void) )
{
	switch (EXTI_ID) {
	case INT0_ID:
		voidptrfn[0]=ptr;
		break;
	case INT1_ID:
		voidptrfn[1]=ptr;
		break;
	case INT2_ID:
		voidptrfn[2]=ptr;
		break;
	default:
		break;
	}

}

/*********  INT 0 *********/
EXTI0_IRQHandler
{
	voidptrfn[0]();

}

/*********  INT 1 *********/
EXTI1_IRQHandler
{
	voidptrfn[1]();
}
/*********  INT 2 *********/
EXTI2_IRQHandler
{
	voidptrfn[2]();

}
