/*
 * TIMER0_interfacec.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Emad Hamdy
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "STD_TYPES.h"
//========================================//


/**************** PROTOTYPES **************/
void TIMER0_init();
void TIEMR0_START();
void TIEMR0_STOP();
void TIMER0_SetDelayTimerMilliSec(u32 copy_u32TimesMs);
void TIMER0_voidSetPeriodic(u16 Copy_u32Time, void (*func)(void));
void TIMER0_IntEn(IntID_t IntID);
void TIMER0_IntDis(IntID_t IntID);
void TIMER0_void_setCallBack(void (*ptrfn)(void), IntID_t copy_u8IntID);
void TIMER0_voidSetFastPWM(u8 DutyCycle);
/**************** TIMER0  BASE_ADDRESS **************/

#define TIMER0_BASE ((volatile TIMER0_Registers_t* )0x50)



#endif /* TIMER0_INTERFACE_H_ */
