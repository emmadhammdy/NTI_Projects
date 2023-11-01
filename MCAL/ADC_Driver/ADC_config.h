/*
 * ADC_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Emad Hamdy
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
 * Task : ADC driver
 Requirements:
 1. Your driver should support postBuild Configuration, the
 ADC may change prescaler , Vref ....etc during RunTime .
 2. Your Driver should support polling and also interrupt
 3. Polling function will be nonBlocking , this function will be
 synchronous.
 4. Interrupt will be Asynchronous.
 5. Functions that need to be supported :
 a. ADC_Init() ;
 this function should select ( Vref , Right or Left adjust
 , pre-scaler , autotrigger or Not , and ADC enable).
 b. ADC_getDigitalValueSynchNonBlocking ();
 needs to know the channel , this fn works in a polling
 fashion but with time out .
 c. ADC_getDigitalValueAsynchCallBack();
 needs to know channel and the call back pointer ,
 this fn enables Interrupt and selects the channel and
 starts conversion.
 */

#endif /* ADC_CONFIG_H_ */
