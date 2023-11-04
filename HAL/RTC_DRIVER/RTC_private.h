/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 3 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#ifndef RTC_PRIVATE_H_
#define RTC_PRIVATE_H_



/****************************************************************************/
#define ERROR	0
#define SUCCESS 1
/****************************************************************************/




/****************************************************************************/
#define RTC_Slave_address_W	11010000
#define RTC_Slave_address_R	11010001
#define seconds_address		0x00
#define	Day_address			0x03
#define HOURS_AM_MASK		0b01000000
#define HOURS_PM_MASK		0b01100000

/****************************************************************************/

/*
#define Seconds		(volatile u8*)0x00)
#define Hours		(volatile u8*)0x01)
#define Day			(volatile u8*)0x03)
#define Date		(volatile u8*)0x04)
#define Month		(volatile u8*)0x05)
#define Year		(volatile u8*)0x06)
#define	Control		(volatile u8*)0x07)
*/
#endif /* RTC_PRIVATE_H_ */
