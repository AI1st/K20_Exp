/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

unsigned int ADC_Result;

void ADC_Init (void)  {
	/*enable ADC0  clock*/
	SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
     /* Set pin0 of PORTE as analog function */
	PORTE_PCR0 = 0x0000;
	//PORTE_PCR0=PORT_PCR_MUX(0X0);
	//long sample time single-end 12bit conversion
	ADC1_CFG1 = 0X00000014;
	//	ADC1_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
	//ADxxxa channel select
	ADC1_CFG2 = 0X00000000;
	//default voltage reference Vrefh  and Vrefl,software trigger
	ADC1_SC2 = 0X00000000;
	//continuous conversions
	ADC1_SC3 = 0X00000008; 
	//ADC1_SC3=ADC_SC3_ADCO_MASK; 
	//interrupt disable and select ADC0_SE4a channel as input
	ADC1_SC1A = 0X0000004;
	//ADC1_SC1A=ADC_SC1_ADCH(4);		
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
	ADC_Init();
	for(;;){
	while((ADC1_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
		  	
		ADC_Result=ADC1_RA;
		
		//clear flag	   	
	   	ADC1_SC1A&=~ADC_SC1_COCO_MASK;
	   	delay( );
	}
}
