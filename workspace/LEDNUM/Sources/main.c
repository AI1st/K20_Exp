/*
S * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "LED_CODE.h"   

unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};

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

void delay(void)
	{  
	   unsigned short i,j;
	   for(i=0;i<3000;i++) 
	      for(j=0;j<200; j++)
	         asm("nop");
	}

int main(void)
{
	uint32_t Select_LED;
	unsigned short i;
	
	LED_Disp_Init( );
	Select_LED=Select_LED0;
	i=0;
	
	for(;;){
	GPIOA_PDOR |= 0x03F000;	
	
	GPIOD_PDOR &= ~0xFF;
//	GPIOD_PDOR |= LED_0;
	GPIOD_PDOR |= num[i];	
	GPIOA_PDOR &= Select_LED; 
	delay();
	Select_LED=Select_LED<<1;
	Select_LED++;
	if (Select_LED==0xFFFBFFFF)
	{
		Select_LED=Select_LED0;
		i++;
			if (i==10)
				{
					i=0;
				}
	}
	
	}
}
