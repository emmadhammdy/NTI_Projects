/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 5 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/


#include "WD_interface.h"
#include "WD_config.h"
#include "WD_private.h"
/*******************************************************************************/
WD_REG_t* pWD = WD_BASE_ADDRESS;
/*******************************************************************************/



void WD_enable()
{
	// to enable the watch dog , set the WDE BIT //
	SET_BIT(pWD->WDTCR,WDE);
}
/*******************************************************************************/
void WD_disable()
{
	// disable Watch dog //
	pWD->WDTCR |= (1<<WDTOE)|(1<<WDE);
	pWD->WDTCR &= ~(1<<WDE);
}

/*******************************************************************************/

void WD_sleep(CyclesNUM_t sleepTime)
{
	// set reset time //
	pWD->WDTCR &= WD_PRESCALER_MASK;
	pWD->WDTCR |= sleepTime;

}
/*******************************************************************************/
void WD_refresh()
{
	// set the WD value again //
	asm("WDR");
}
