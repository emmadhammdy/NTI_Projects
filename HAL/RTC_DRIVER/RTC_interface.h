/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 3 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#ifndef RTC_INTERFACE_H_
#define RTC_INTERFACE_H_

#include "STD_TYPES.h"
#include "I2C_interface.h"

typedef enum {

	Hour_AM, Hour_PM, none
} Hour_Mode_t;

typedef enum {
	Time_24, Time_12
} Time_Mode_t;

typedef struct {

	u8 seconds;  // 00 - 59 //
	u8 minutes;	 // 00 - 59 //
	u8 hours;    // 1 - 12, 0 - 23 //
	Hour_Mode_t AM_PM;
	Time_Mode_t timeformat;
} Time_t;

typedef struct {
	u8 Day;
	u8 date;
	u8 month;
	u8 year;

} Date_t;



/****************************************************************************/
/**********************      Prototypes        *****************************/
/****************************************************************************/
void RTC_Init();
u8 RTC_setTime(const Time_t* time);
void RTC_getTime();
u8 RTC_setDate(const Date_t* date);
void RTC_getDate();

#endif /* RTC_INTERFACE_H_ */
