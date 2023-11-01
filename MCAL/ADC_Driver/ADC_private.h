/*
 * ADC_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Emad Hamdy
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#include "platformtypes.h"
// ADC REGISTER BASE ADDRESS
#define ADC_BASE (volatile ADC_config_t*)(0x24)
/**************************************************/
typedef struct
{
	usint8_t ADCL;
	usint8_t ADCH;
	usint8_t ADCSRA;
	usint8_t ADMUX;
	usint8_t reserved[41];
	usint8_t SFIOR;

}ADC_config_t;


#endif /* ADC_PRIVATE_H_ */
