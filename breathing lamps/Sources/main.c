/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "INT_PIT.h"
#include "LED.h"
//思路：设置五档亮度的高电平占空比，在每个计时器中断中修改高电平占空比

unsigned int brightness_state=0;
unsigned int total_state=100;

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


int main(void)
{
	int counter = 0;

	
	PIT_init(2);
	LED_Init();
	EN_Init();
	
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
