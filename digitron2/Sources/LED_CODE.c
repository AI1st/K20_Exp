# include"LED_CODE.h"
# include"derivative.h"


void LED_Disp_Init(void) 
{
	SIM_SCGC5 |=(0x1000 | 0x0200);
	/*portA  set to GPIO*/	    
	PORTA_PCR12=0x100;
	PORTA_PCR13=0x100;
	PORTA_PCR14=0x100;
	PORTA_PCR15=0x100;
	PORTA_PCR16=0x100;
	PORTA_PCR17=0x100;

	/*portD  set to GPIO*/
	PORTD_PCR0 = 0x0100;
	PORTD_PCR1 = 0x0100;
	PORTD_PCR2 = 0x0100;
	PORTD_PCR3 = 0x0100;
	PORTD_PCR4 = 0x0100;
	PORTD_PCR5 = 0x0100;
	PORTD_PCR6 = 0x0100;		
	PORTD_PCR7 = 0x0100;
		
	/*LED bit pin set to out*/
	GPIOD_PDDR |=0x00FF;
	GPIOA_PDDR |=0x03F000;
	/*LED control pin set to high ,LEDs are closed*/
	GPIOA_PDOR |=0x03F000;
	/*LED bit pin set to high ,LED bit are all off, change GPIOD_PDOR register can change the number it shows*/
	GPIOD_PDOR = 0xFF;
}
