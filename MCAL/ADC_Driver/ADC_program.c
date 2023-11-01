/*
 * ADC_program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Emad Hamdy
 */

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"

/*************** GLOBAL VARIABLE ****************/
ADC_config_t *pADC = ADC_BASE;
static usint8_t flag;
void (*ptrcallback)(void);

/*************** FUNCTIONS IMPLEMENTATION ****************/


void start_conversion(CHANNEL_t CH )
{
	if (flag == 0)
	{
	// channel selection //
		pADC->ADMUX &= 0b11100000;
		pADC->ADMUX |= CH;

		// starting conversion //
		SET_BIT(pADC->ADCSRA,6);
		flag =1;
	}


}

void ADC_Init(prescaler_t prescaler, ADC_tiggerSrc_t trigger , Vref_t volt_ref , AdjustmentDir_t adjust ) {

	// reset the ADMUX value
	pADC->ADMUX=0x00;

	// prescaler selection //
	pADC->ADCSRA&= 0b11111000;
	pADC->ADCSRA|= prescaler;
	// auto trigger configuration //

	if (trigger == Disable) {
		CLEAR_BIT(pADC->ADCSRA, 5);

	} else {
		// set the value of pin ADATE
		SET_BIT(pADC->ADCSRA, 5);

		// mode of triggering configuration //
		pADC->SFIOR &=0b00011111;
		pADC->SFIOR|= trigger<<5;
	}
		// voltage Ref selection //
		switch(volt_ref)
		{
		case AREF:
			CLEAR_BIT(pADC->ADMUX,6);
			CLEAR_BIT(pADC->ADMUX,7);
			break;
		case AVCC:
			SET_BIT(pADC->ADMUX,6);
			CLEAR_BIT(pADC->ADMUX,7);
			break;
		case INTERNAL_256V:
			CLEAR_BIT(pADC->ADMUX,6);
			SET_BIT(pADC->ADMUX,7);
			break;
		default:
			break;
		}

		// ADC Conversion presentation in the ADC data register //
		if (adjust==LEFT_ADJUST)
		{
			SET_BIT(pADC->ADMUX,5);
			// writing bit to one enable left adjustment

		}
		else
		{
			CLEAR_BIT(pADC->ADMUX,5);
			// writing bit to any value except one enable right adjustment
		}



	// to enable ADC //
	SET_BIT(pADC->ADCSRA, 7);

	if(INTERRUPT)
	{
	SET_BIT(pADC->ADCSRA,3); // ADIE bit in ADCSRA register //
	}
	else
	{
		// polling //
	}


}

usint16_t ADC_getDigitalValueSynchNonBlocking (CHANNEL_t CH,usint16_t* pData)
{
	usint16_t data;
	start_conversion(CH);
	if (GET_BIT(pADC->ADCSRA,6)==0)
	{
		data= pADC->ADCL;
		*pData = data|((usint16_t)pADC->ADCH<<8);
		flag=0;
		return 1;

	}

		return 0 ;
}

void ADC_getDigitalValueAsynchCallBack(CHANNEL_t CH , void(*ptr)(void))
{
	// channel selection //
	pADC->ADMUX &= 0b11100000;
	pADC->ADMUX |= CH;
	// start conversion //
	SET_BIT(pADC->ADCSRA,6);
	// interrupt enable //
	SET_BIT(pADC->ADCSRA,3);
	ptrcallback = ptr;

}




ADC_ISR
{
	ptrcallback();

}
