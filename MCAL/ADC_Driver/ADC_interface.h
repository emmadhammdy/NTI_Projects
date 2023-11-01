/*
 * ADC_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Emad Hamdy
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "platformtypes.h"


typedef enum
{
		CHANNEL0,
		CHANNEL1,
		CHANNEL2,
		CHANNEL3,
		CHANNEL4,
		CHANNEL5,
		CHANNEL6,
		CHANNEL7

}CHANNEL_t;



typedef enum
{
	FREE_RUNNING,
	ANALOG_COMP,
	EXTI_REQ_0,
	TIMER0_CTC,
	TIMER0_OVF,
	TIMER1_CTC,
	TIMER1_OVF,
	TIMER1_CAPE

}ADC_tiggerSrc_t;

typedef enum
{
	div_factor_2=0x01,
	div_factor_4,
	div_factor_8,
	div_factor_16,
	div_factor_32,
	div_factor_64,
	div_factor_128,
}prescaler_t;


typedef enum  {
    AREF,        // External Analog Reference (connected to AREF pin)
    AVCC,        // AVCC with external capacitor at AREF pin
	reserved,
    INTERNAL_256V,  // Internal 2.56V Voltage Reference

}Vref_t;

typedef enum {
	Disable=0xF0,		// to not conflict with auto trigger configuration //
	Enable = 0x01
}status_t;

typedef enum {
	RIGHT_ADJUST,
	LEFT_ADJUST
}AdjustmentDir_t;



/****************** BIT CONFIG ****************/
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT) REG&= ~(1<<BIT)
#define GET_BIT(REG,BIT)	((REG>>BIT) & 1)


#define INTERRUPT 1
#define TRIGGER	  1



/************************ INTERRUPT ***********************/
#define ADC_ISR           \
	void __vector_16(void) __attribute__ ((signal)); \
	void __vector_16(void)

/****************** prototypes ****************/
void ADC_Init(prescaler_t prescaler, ADC_tiggerSrc_t trigger,Vref_t volt_ref , AdjustmentDir_t adjust);
usint16_t ADC_getDigitalValueSynchNonBlocking(CHANNEL_t CH,usint16_t* pData);
void ADC_getDigitalValueAsynchCallBack(usint8_t CH,void(*ptr)(void));

#endif /* ADC_INTERFACE_H_ */
