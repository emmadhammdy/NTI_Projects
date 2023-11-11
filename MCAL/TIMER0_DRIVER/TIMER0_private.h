/*
 * TIMER0_private.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Emad Hamdy
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "STD_TYPES.h"

typedef struct
{
	volatile u8 SFIOR;
	volatile u8 RESERVED0;
	volatile u8 TCNT0;
	volatile u8 TCCR0;
    volatile u8 reserved[4];
	volatile u8 TIFR;
	volatile u8 TIMSK;
	volatile u8 reserve[2];
	volatile u8 OCR0;

}TIMER0_Registers_t;


typedef enum
{
	timer_OFF = 0, // timer is off //
	no_prescaler = 1,
	FCPU_8 = 2,
	FCPU_64 = 3,
	FCPU_256 = 4,
	FCPU_1024 = 5,
	EXT_FALLING = 6,
	EXT_RISING = 7

}prescaler_t;


typedef enum
{
	normal_mode=0,
	phase_correct=8,
	CTC=1,
	fast_pwm=9
}operation_modes_t;


typedef enum
{
	OC0_disconnected,
	Toggle_OC0_on_compare_match,
	Clear_OC0_on_compare_match,
	Set_OC0_on_compare_match,
}OC0_modes_t;


 typedef enum
{
	TIMER0_OVIE,
	TIMER0_OCIE
}IntID_t;

/**************** some other configurations ******************/
#define interrupt		1
#define Busy_wait		2
#define NO_operation 	3

 /************************ INTERRUPT ***********************/
 /* Timer/Counter0 Compare Match ISR */

 #define TIMER0_CompareMatch_IRQHandler            \
 	void __vector_10(void) __attribute__ ((signal)); \
 	void __vector_10(void)
 /*********************/
 /* Timer/Counter0 Overflow ISR */

 #define TIMER0_Overflow_IRQHandler            \
 	void __vector_11(void) __attribute__ ((signal)); \
 	void __vector_11(void)
/***************** BIT CONFIG **************/

#define SET_BIT(REG,BIT)   REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT) REG&= ~(1<<BIT)
#define READ_BIT(REG, BIT) (((REG) >> (BIT)) & 1)


#define TIMER0_PRESCALER_MASK   0b11111000
#define TIMER0_OC0_MODE_MASK    0b11001111
#define TIMER0_INTERRUPT_MASK	0b11111100
#define TIMER0_MODE_MASKING     0b10110111

#endif /* TIMER0_PRIVATE_H_ */
