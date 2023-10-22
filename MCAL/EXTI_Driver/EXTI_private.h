/*
 * EXTI_private.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Emad Hamdy
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "platformtypes.h"


typedef struct
{
	usint8_t MCUCSR;
	usint8_t MCUCR;
	usint8_t reserved[4];
	usint8_t GIFR;
	usint8_t GICR;

}Register_t;

/********************** BASE ADDRESS ********************/
#define EXTI_BASE (volatile Register_t *)(0x54)


/*********************/
#define EXTI0_IRQHandler            \
	void __vector_1(void) __attribute__ ((signal)); \
	void __vector_1(void)
/*********************/
#define EXTI1_IRQHandler            \
	void __vector_2(void) __attribute__ ((signal)); \
	void __vector_2(void)
/*********************/
#define EXTI2_IRQHandler            \
	void __vector_3(void) __attribute__ ((signal)); \
	void __vector_3(void)
/*********************/

#endif /* EXTI_PRIVATE_H_ */
