/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 3 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#include "RTC_interface.h"
#include "RTC_private.h"
#include "RTC_config.h"
#include "I2C_interface.h"
/*******************************************************************************/

/*******************************************************************************/

static u8 decimalToBCD(u8 decimal) {
	u8 bcd = 0;
	u8 shift = 0;

	while (decimal > 0) {
		u8 digit = decimal % 10;
		bcd |= (digit << shift);
		decimal /= 10;
		shift += 4;
	}

	return bcd;
}

/*******************************************************************************/
void RTC_Init() {

	Init(normal_speed);  // initialize the I2C with 100K frequency //
}
/*******************************************************************************/
u8 RTC_setTime(const Time_t *time) {

	sendStart();
	if (getStatus() != TWI_START) {
		return ERROR;
	}
	/*****************************************************/

	// send address //
	sendByte(RTC_Slave_address_W);
	if (getStatus() != TWI_MT_SLA_W_ACK) {
		return ERROR;
	}
	/*****************************************************/
	// send address to be accessed //
	sendByte(seconds_address);
	u8 converted_sec = decimalToBCD(time->seconds);
	// write seconds to RTC //
	sendByte(converted_sec);
	// check status //
	if (getStatus() != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/

	u8 converted_min = decimalToBCD(time->minutes);
	sendByte(converted_min);
	if (getStatus() != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/
	u8 converted_hours ;
	if (time->timeformat == Time_12)
	{
		if (time->AM_PM == Hour_AM)
		{
			converted_hours = converted_hours | HOURS_AM_MASK;
		}
		else if (time->AM_PM == Hour_PM)
		{
			converted_hours = converted_hours | HOURS_PM_MASK;

		}

	}
	else if (time->timeformat == Time_24)
	{
		converted_hours = decimalToBCD(time->hours);
	}
	sendByte(converted_hours);

	if (getStatus() != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/

	// send stop //
	sendStop();

	return SUCCESS;
}
/*******************************************************************************/
void RTC_getTime(Time_t* getTime) {

	// send start bit //
	sendStart();

	// send RTC address //
	sendByte(RTC_Slave_address_W);
	/*****************************************************/
	// send accessed address //
	sendByte(seconds_address);
	/*****************************************************/
	// send repeated start //
	sendStart();
	/*****************************************************/
	// send address with Read bit //
	sendByte(RTC_Slave_address_R);
	/*****************************************************/
	// read seconds with acknowledge //
	getTime->seconds = receiveByte_ACK();
	// read minutes with acknowledge //
	getTime->minutes = receiveByte_ACK();
	// read hours with not acknowledge //
	getTime->hours = receiveByte_NACK();
	/*****************************************************/
	// send stop //
	sendStop();




}
/*******************************************************************************/
u8 RTC_setDate(const Date_t *date) {

	sendStart();
	if (getStatus != TWI_START) {
		return ERROR;
	}
	/*****************************************************/
	// send address //
	sendByte(RTC_Slave_address_W);
	if (getStatus != TWI_MT_SLA_W_ACK) {
		return ERROR;
	}
	/*****************************************************/
	// send adderss to be accessed //
	sendByte(Day_address);
	u8 converted_Day = decimalToBCD(date->Day);
	// write data to RTC //
	sendByte(converted_Day);
	// check status //
	if (getStatus != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/
	u8 converted_date = decimalToBCD(date->date);
	// write data to RTC //
	sendByte(converted_date);
	// check status //
	if (getStatus != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/
	u8 converted_month = decimalToBCD(date->month);
	// write data to RTC //
	sendByte(converted_month);
	// check status //
	if (getStatus != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/
	u8 converted_year = decimalToBCD(date->year);
	// write data to RTC //
	sendByte(converted_year);
	// check status //
	if (getStatus != TWI_MT_DATA_ACK) {
		return ERROR;
	}
	/*****************************************************/
		// send stop //
		sendStop();



	return SUCCESS;
}
/*******************************************************************************/
void RTC_getDate(Date_t* getDate) {
	sendStart();

	// send RTC address //
	sendByte(RTC_Slave_address_W);
	/*****************************************************/
	// send accessed address //
	sendByte(Day_address);
	/*****************************************************/
	// send repeated start //
	sendStart();
	/*****************************************************/
	// send address with Read bit //
	sendByte(RTC_Slave_address_R);
	/*****************************************************/
	// read Day with acknowledge //
	getDate->Day = receiveByte_ACK();
	// read date with acknowledge //
	getDate->date = receiveByte_ACK();
	// read month with acknowledge //
	getDate->month = receiveByte_ACK();
	// read year with not acknowledge //
	getDate->year = receiveByte_NACK();
	/*****************************************************/
	// send stop //
	sendStop();



}
