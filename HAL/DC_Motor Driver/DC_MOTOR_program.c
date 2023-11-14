/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 11 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_private.h"

/*************************************************/
void DcMotor_init()
{
	DIO_void1SetPinDirection(pB, 3, 1);

}

/*************************************************/
void DcMotor_ON(u8 DutyCycle)
{


		TIMER0_voidSetFastPWM(DutyCycle);

}
/*************************************************/
void DcMotor_OFF()
{
	TIMER0_voidSetFastPWM(StopMotor);
}

