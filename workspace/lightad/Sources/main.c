/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

unsigned int ADC_Result;
unsigned char show[3];
unsigned char AD_flag;
//extern unsigned long int led[3]={BIT12,BIT13,BIT14};  //,BIT15,BIT16,BIT17
//unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};

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
void ADC0_Init (void)  {
	/*enable ADC0  clock*/
	SIM_SCGC6|=SIM_SCGC6_ADC0_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
     /* Set pin0 of PORTE as analog function */
	PORTB_PCR3=0x0000;
	//long sample time single-end 12bit conversion
	ADC0_CFG1=0X00000014;
	//ADxxxa channel select
	ADC0_CFG2=0X00000000;
	//default voltage reference Vrefh  and Vrefl,software trigger
	ADC0_SC2=0X00000000;
	//continuous conversions
	ADC0_SC3=0X00000008;  
	//interrupt disable and select ADC0_SE13a channel as input
	ADC0_SC1A=0X000000d;
 //   	SIM_SCGC5|=SIM_SCGC5_PORTE_MASK;
//	    SIM_SCGC3|=SIM_SCGC3_ADC1_MASK;
				
		//PTE0 and PTE1 configured as pin of ADC module
//		PORTE_PCR0=PORT_PCR_MUX(0X0);
	//	PORTE_PCR1=PORT_PCR_MUX(0X0);

	  		
		//long sample time and single-end  8bit conversion
//		ADC1_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
		
		//continuous conversions
//		ADC1_SC3=ADC_SC3_ADCO_MASK; 
		
		//interrupt disable and select AD1_se4a channel as input		
//		ADC1_SC1A=ADC_SC1_ADCH(4);		 //potentiometers sensor path acquire	
}
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
	   for(i=0;i<300;i++) 
	      for(j=0;j<20; j++)
	         asm("nop");
	}

int main(void)
{
	    LED_Disp_Init( );
	    PIT_init(0x01);	     //1ms interval interrupt	
		NVICICPR2=1<<(68%32);
	    NVICISER2=1<<(68%32);
	    ADC0_Init();
	    AD_flag=0;
	    
		for(;;)
		{
		if (AD_flag==1){
			while((ADC0_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
		  	
			ADC_Result=ADC0_RA;
			ADC_Result>>=4;
				unsigned char i;
		//		GPIOA_PDOR|=0xFF000; 
				AD_flag=0;
				for(i=0;i<3;i++)
				{		
					show[i]=ADC_Result%10;
					ADC_Result/=10;
					}					
			//clear flag	   	
		   	ADC0_SC1A&=~ADC_SC1_COCO_MASK;
		   } 
		}
		
}
