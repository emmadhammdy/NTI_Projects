/*
 * EXTI_interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Emad Hamdy
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "platformtypes.h"

/********************** INTERRUPT IDS *******************/

#define INT0_ID		6 			//
#define INT1_ID		7 		    //
#define INT2_ID 	5 		    //
/********************* TRIGGERING CFG INT0,INT1 *********/

#define RISING_EDGE			3	//
#define FALLING_EDGE		2   //
#define ANY_CHANGE			1   //
#define LOW_LEVEL			0   //



/********************** prototypes **********************/

void EXTI_ENABLE(usint8_t EXTI_ID , usint8_t TRIG ); // external interrupt enable
void EXTI_DISABLE(usint8_t EXTI_ID );	// external interrupt disable
void EXTI_setCallBack(usint8_t EXTI_ID , void (*ptr)(void)  );// call back function

/********************** MACROS **********************/
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT) REG&= ~(1<<BIT)


#endif /* EXTI_INTERFACE_H_ */
