/*
 * GIE_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Emad Hamdy
 */


#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"

void GIE_ENABLE()
{
	asm("SEI");

}


void GIE_DISABLE()
{
	asm("CLI");

}

