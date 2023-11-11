/*******************************************************************************/
/*   Author    : Emad Hamdy                                                    */
/*   Version   : V01                                                           */
/*   Date      : 25 October 2023                                               */
/*******************************************************************************/
#include "TIMER0_interfacec.h"
#include "TIMER0_private.h"
#define F_CPU 16000000
#include "TIMER0_config.h"
/******************* GLOBAL VARIABLE *******************/
TIMER0_Registers_t *pTIMER = TIMER0_BASE;
void (*GlobalptrFUN[2])(void);
u32 GNumofOVF = 0;
u8 gRemaning = 0;
u8 TIMER_Int_or_Stuck = NO_operation;
Timer0_CLK = F_CPU/1024;
/*******************************************************/

void TIMER0_init(void) {

	/******* Waveform Generation Mode ********/
	pTIMER->TCCR0 &= TIMER0_MODE_MASKING;
	pTIMER->TCCR0 |= (TIMER0_MODE << 3);
/*--------------------------------------------------*/
		// configure the OC0 pin //
	pTIMER->TCCR0 &= TIMER0_OC0_MODE_MASK;
	pTIMER->TCCR0 |= (TIMER0_COMPARE_MATCH_MODE << 4);
/*---------------------------------------------------*/


}

/*******************************************************/
void TIEMR0_START(void) {

	// to start timer , we must configure the prescaler //
	pTIMER->TCCR0 &= TIMER0_PRESCALER_MASK;
	pTIMER->TCCR0 |= TIMER0_PRESCALER;

}
/*******************************************************/
void TIEMR0_STOP(void) {
	// clear prescaler bits "timer stop" //
	pTIMER->TCCR0 = 0;

}
/*******************************************************/
void TIMER0_IntEn(IntID_t IntID) {


	pTIMER->TIMSK &= TIMER0_INTERRUPT_MASK;

	if (IntID == TIMER0_OVIE)
	{
		SET_BIT(pTIMER->TIMSK, 0);
	}
	else if (IntID == TIMER0_OCIE)
	{

		SET_BIT(pTIMER->TIMSK, 1);
	}
}

/*******************************************************/

void TIMER0_IntDis(IntID_t IntID) {

		pTIMER->TIMSK &= TIMER0_INTERRUPT_MASK;

		if (IntID == TIMER0_OVIE)
		{
			CLEAR_BIT(pTIMER->TIMSK, 0);

		}
		else if (IntID == TIMER0_OCIE)
		{

			CLEAR_BIT(pTIMER->TIMSK, 1);
		}


}
/*******************************************************/
void TIMER0_SetDelayTimerMilliSec(u32 Copy_u32Time) {

	TIMER_Int_or_Stuck = Busy_wait;
	TIMER0_IntDis(TIMER0_OVIE);
	u32 Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000);
	GNumofOVF = Local_u32Load / 0xFF;
	gRemaning = Local_u32Load % 0xFF;
	gRemaning = (0xFF - gRemaning);
	pTIMER->TCNT0 = gRemaning;

	// start timer //
	TIEMR0_START();
	// enable perphieral interrupt //
	TIMER0_IntEn(TIMER0_OVIE);

	while (TIMER_Int_or_Stuck == Busy_wait);

}
/*******************************************************/
void TIMER0_voidSetPeriodic(u16 Copy_u32Time, void (*func)(void)) {
	TIMER_Int_or_Stuck = interrupt;

	TIMER0_IntDis(TIMER0_OVIE);

	u32 Timer0_CLK = F_CPU / 1024;
	u32 Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000);
	GNumofOVF = Local_u32Load / 0xFF;
	gRemaning = Local_u32Load % 0xFF;
	gRemaning = (0xFF - gRemaning);
	pTIMER->TCNT0 = gRemaning;

	GlobalptrFUN[1] = func;
	// start timer //
	TIEMR0_START();
	// enable perphieral interrupt //
	TIMER0_IntEn(TIMER0_OVIE);

}
/*******************************************************/
void TIMER0_void_setCallBack(void (*ptrfn)(void), IntID_t copy_u8IntID) {

	if (copy_u8IntID == TIMER0_OCIE) {
		GlobalptrFUN[0] = ptrfn;
	} else if (copy_u8IntID == TIMER0_OVIE) {
		GlobalptrFUN[1] = ptrfn;
	} else {
		// do nothing //
	}

}
/*******************************************************/
void TIMER0_voidSetFastPWM(u8 DutyCyclePercentage) {
	if (TIMER0_MODE == fast_pwm) {



		//  disable interrupt //
		TIMER0_IntDis(TIMER0_OCIE);
/*-------------------------------------------------*/
		// duty cycle real value //
		u8 dutyCycleReal = (DutyCyclePercentage * 255) / 100;
		pTIMER->OCR0 = dutyCycleReal;
/*---------------------------------------------------*/
		// start timer 0 //
		TIEMR0_START();
		// enable interrupt //
		TIMER0_IntEn(TIMER0_OCIE);
	}
}
/*******************************************************/
void TIMER0_voidSetPhaseCorrectPWM(u8 DutyCyclePercentage) {
	if (TIMER0_MODE == phase_correct) {

		//  disable interrupt //
		TIMER0_IntDis(TIMER0_OCIE);
		/*---------------------------------------------------*/
		// calculate the real value of duty cycle //
		u8 DutyCycleReal = (DutyCyclePercentage * 255) / 100;
		// store value in OCR0 //
		pTIMER->OCR0 = DutyCycleReal;
		/*---------------------------------------------------*/
		// start timer 0 //
		TIEMR0_START();
		// enable interrupt //
		TIMER0_IntEn(TIMER0_OCIE);
	}

}
TIMER0_CompareMatch_IRQHandler
{
	GlobalptrFUN[0]();
}

TIMER0_Overflow_IRQHandler
{
	if (TIMER_Int_or_Stuck == interrupt) {
		static u32 TempOVF = 0;
		TempOVF++;
		if (TempOVF == GNumofOVF + 1) {
			GlobalptrFUN[1]();
			TempOVF = 0;
			pTIMER->TCNT0 = gRemaning;
		}
	} else if (TIMER_Int_or_Stuck == Busy_wait) {
		static u32 TempOVF = 0;
		TempOVF++;
		if (TempOVF == GNumofOVF + 1) {
			TempOVF = 0;
			TIMER_Int_or_Stuck = NO_operation;
		} else if (GNumofOVF == 0) {
			TIMER_Int_or_Stuck = NO_operation;
		}
	}
}

