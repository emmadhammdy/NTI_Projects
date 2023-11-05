/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 5 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/


#ifndef WD_INTERFACE_H_
#define WD_INTERFACE_H_




typedef enum
{
	Disable,
	Enable
}Bit_Mode_t;

typedef enum
{
	Cycles_16K,
	Cycles_32K,
	Cycles_64K,
	Cycles_128K,
	Cycles_256K,
	Cycles_512K,
	Cycles_1024K,
	Cycles_2048K,

}CyclesNUM_t;



/****************************************************************************/
/**********************      Prototypes        *****************************/
/****************************************************************************/
void WD_enable();
void WD_disable();
void WD_sleep(CyclesNUM_t sleepTime);
void WD_refresh();


#endif /* WD_INTERFACE_H_ */
