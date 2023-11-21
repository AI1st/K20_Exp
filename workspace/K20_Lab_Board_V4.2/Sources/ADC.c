/*
 * ADC_Init.c
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */


#include <derivative.h>
extern unsigned int ADC_Result;

void ADC0_initial()
{
	//ADC0 initial
	    SIM_SCGC5|=SIM_SCGC5_PORTB_MASK;
	    SIM_SCGC6|=SIM_SCGC6_ADC0_MASK;
	    
	    PORTB_PCR3=PORT_PCR_MUX(0X0);
	    
		ADC0_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
		ADC0_SC3=ADC_SC3_ADCO_MASK; 
		ADC0_SC1A=ADC_SC1_ADCH(13);		 //potentiometers sensor path acquire	
}

void ADC1_initial()
{
    /*enable PORTD and ADC1  clock*/
    SIM_SCGC5|=SIM_SCGC5_PORTE_MASK;
    SIM_SCGC3|=SIM_SCGC3_ADC1_MASK;
			
	//PTE0 and PTE1 configured as pin of ADC module
	PORTE_PCR0=PORT_PCR_MUX(0X0);
	PORTE_PCR1=PORT_PCR_MUX(0X0);

  		
	//long sample time and single-end  8bit conversion
	ADC1_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
	
	//continuous conversions
	ADC1_SC3=ADC_SC3_ADCO_MASK; 
	
	//interrupt disable and select AD1_se4a channel as input		
	ADC1_SC1A=ADC_SC1_ADCH(4);		 //potentiometers sensor path acquire	
}


void ADC_Init()
{
	ADC0_initial();
	ADC1_initial();
}


//anolog convert to digital
unsigned int ADC1_TR_DATA()
{
	//check convert complete flag 
	while((ADC1_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
	  	
	ADC_Result=ADC1_RA;
	
	//clear flag	   	
   	ADC1_SC1A&=~ADC_SC1_COCO_MASK;
   	
   	return ADC_Result;

}

//anolog convert to digital
unsigned int ADC0_TR_DATA()
{
	//check convert complete flag 
	while((ADC0_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
	  	
	ADC_Result=ADC0_RA;
	
	//clear flag	   	
   	ADC0_SC1A&=~ADC_SC1_COCO_MASK;
   	
   	return ADC_Result;
}

//change ADC channel
void ADC_channel_temperature()
{
	ADC1_SC1A=ADC_SC1_ADCH(5);		    //PTE1----temperature sensor
	
}


//change ADC channel
void ADC_channel_potentiometer()
{
	ADC1_SC1A=ADC_SC1_ADCH(4);		    //potentiometers sensor path acquire
}


//data1 forward,data2 backward
void data_to_array(unsigned int data1,unsigned int data2,unsigned char array[])
{
	data1=data1&0xFF;
	data2>>=4;
	unsigned char i;
	for(i=0;i<3;i++)
	{		
		array[i]=data1%10;
		data1/=10;
	}
	for(i=3;i<6;i++)
	{		
		array[i]=data2%10;
		data2/=10;
	}
}
