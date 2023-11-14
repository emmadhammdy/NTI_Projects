/*******************************************************************************/
/*   Author    : EMAD HAMDY                                                    */
/*   Version   : V01                                                           */
/*   Date      : 11 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "../MCAL/GPIO_Driver.h"
#include "../MCAL/TIMER0_interfacec.h"


typedef enum
{
	StopMotor,
	StartMotor,
}Motor_Modes_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void DcMotor_init();
void DcMotor_ON( u8 DutyCycle);
void DcMotor_OFF();




#endif /* DC_MOTOR_INTERFACE_H_ */
