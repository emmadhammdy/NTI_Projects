/*
 * TIMER0_config.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Emad Hamdy
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*
    timer_OFF, // timer is off //
	no_prescaler,
	FCPU_8,
	FCPU_64,
	FCPU_256,
	FCPU_1024,
	EXT_FALLING,
	EXT_RISING

*/

// Choose from the above //
#define TIMER0_PRESCALER		 FCPU_1024

/*
	normal_mode,
	phase_correct,
	CTC,
	fast_pwm
*/

// choose one of the above //
#define TIMER0_MODE				 phase_correct

/*
	OC0_disconnected
	Toggle_OC0_on_compare_match
	Clear_OC0_on_compare_match
	Set_OC0_on_compare_match
*/
// choose one of the above //


/* Options : [PWM]
 *
	OC0_disconnected,
	Toggle_OC0_on_compare_match,
	Clear_OC0_on_compare_match,
	Set_OC0_on_compare_match,


*/
#define TIMER0_COMPARE_MATCH_MODE            Clear_OC0_on_compare_match

#endif /* TIMER0_CONFIG_H_ */
