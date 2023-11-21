/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

void delay(void)
{  
   unsigned short i,j;
   for(i=0;i<3000;i++) 
      for(j=0;j<200; j++)
         asm("nop");
}

int main(void)
{
	unsigned char bLed;
		SIM_SCGC5|=0x800;  
		PORTC_PCR0=0x100;
		PORTC_PCR3=0x100;
		GPIOC_PDDR=	0x0009;  
		GPIOC_PDOR &= ~0x0009;
		bLed = 0;
		for(;;){
		        delay();
		        bLed = ~bLed;
		        
		       if(bLed) 
		        {
		GPIOC_PDOR=0x0001;         }
		        else 
		        {
		GPIOC_PDOR=0x0008;        }

		     }
}





