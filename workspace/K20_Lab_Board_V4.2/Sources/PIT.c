/*
 * PIT.c
 *
 *  Created on: Mar 26, 2014
 *      Author: leo
 */

#include <derivative.h>

void PIT_init(unsigned int number_ms)
{
	/*Trun on PIT clocks*/
	SIM_SCGC6|=SIM_SCGC6_PIT_MASK;
	
    /*Enable PIT Module*/
	PIT_MCR&=~(PIT_MCR_MDIS_MASK);
	
	/*Setup the channel0 of PIT*/
	PIT_LDVAL0=20000*number_ms;
	
	/*Enable the IRQ of channel0,PIT*/
	PIT_TCTRL0|=PIT_TCTRL_TIE_MASK;
	
	/*Running channel0,PIT*/
	PIT_TCTRL0|=PIT_TCTRL_TEN_MASK;
	
}
