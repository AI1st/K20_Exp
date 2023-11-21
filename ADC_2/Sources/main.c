/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "LED_CODE.h"  

unsigned int ADC_Result;
unsigned int temperature_value, photo_value;
int counter=0;

unsigned char num[11]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28,0x7F};

void partial_delay(int delay_t)
	{  
	   unsigned short i,j;
	   for(i=0;i<30*delay_t;i++) 
	      for(j=0;j<20; j++)
	         asm("nop");
	}

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

void LED_Iniled()
{
	SIM_SCGC5|=0x3E00;
	PORTC_PCR0 = On;
	PORTC_PCR1 = On;
	PORTC_PCR2 = On;
	PORTC_PCR3 = On;
	PORTC_PCR4 = On;
	PORTC_PCR5 = On;
	PORTC_PCR6 = On;
	PORTC_PCR7 = On;
	PORTC_PCR8 = On;
	PORTC_PCR9 = On;
	PORTC_PCR10 = On;
	PORTC_PCR11 = On;
	GPIOC_PDOR|= 0x0FFF;
	GPIOC_PDDR =0x0FFF;
}

void l1()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b111111111000;
}
void l2()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b111111000111;
}
void l3()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b111000111111;
}
void l4()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b000111111111;
}

void l_off(){
	GPIOC_PDOR|= 0xFFF;
}

unsigned int ADC0_TR_DATA()
{
	//check convert complete flag 
	while((ADC0_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
	  	
	ADC_Result=ADC0_RA;
	
	//clear flag	   	
   	ADC0_SC1A&=~ADC_SC1_COCO_MASK;
   	
   	return ADC_Result;
}

void ADC_channel_temperature()
{
	ADC1_SC1A=ADC_SC1_ADCH(5);		    //PTE1----temperature sensor
	
}

unsigned int ADC1_TR_DATA()
{
	//check convert complete flag 
	while((ADC1_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
	  	
	ADC_Result=ADC1_RA;
	
	//clear flag	   	
   	ADC1_SC1A&=~ADC_SC1_COCO_MASK;
   	
   	return ADC_Result;

}

void show_number_right(int number)
	{  
	   unsigned int display_number[3] = {0};
	   int pointer = 1;
	   int i;
	   for(i=1;i<=3;i++){
		   display_number[i-1] = (number % (pointer*10)) / pointer;
		   pointer *= 10;
	   }
	   uint32_t Select_LED = Select_LED0;
	   for(i=1;i<=3;i++){
		   GPIOA_PDOR |= 0x03F000;	
		   GPIOD_PDOR &= ~0xFF;
		   GPIOA_PDOR &= Select_LED; 
		   int m;
		   m= display_number[i-1];
		   GPIOD_PDOR |= num[m];
		   Select_LED = Select_LED<<1;
		   Select_LED += 1;
		   partial_delay(1);
	  
	   }
		//led闪烁部分
	   int f = 1000/number;
	   int flash = counter%(f*5);
	   if(flash==0){
		   l1();
		   l2();
		   l3();
		   l4();
			}
	   if(flash==25){
		   l_off();
	   }
	}


void show_number_left(int number)
	{
	
	//数字管显示部分
	int temperature = number/10;
	unsigned int display_number[3] = {0};
	int pointer = 1;
	int i;
	for(i=1;i<=3;i++){
		display_number[i-1] = (temperature % (pointer*10)) / pointer;
		pointer *= 10;
	}
	uint32_t Select_LED = Select_LED0;
	for(i=1;i<=3;i++){
		Select_LED = Select_LED<<1;
		Select_LED += 1;
	}
	for(i=1;i<=3;i++){
		GPIOA_PDOR |= 0x03F000;	//ѡ��λ��
		GPIOD_PDOR &= ~0xFF;//ѡ������
//		GPIOD_PDOR |= LED_off;
		GPIOA_PDOR &= Select_LED; 
		int m;
		m= display_number[i-1];
		GPIOD_PDOR |= num[m];
		Select_LED = Select_LED<<1;
		Select_LED += 1;
		partial_delay(1);
		   //delay();   
	}
	  
	}


int main(void)
{
	LED_Iniled();
	ADC0_initial();
	ADC1_initial();
	LED_Disp_Init();
	
	
	for(;;) {	   
		
		photo_value=ADC0_TR_DATA();
		temperature_value=ADC1_TR_DATA();
		photo_value/=40;
		temperature_value/=2;
		
		show_number_right(photo_value);
		
		ADC_channel_temperature();
		show_number_left(temperature_value);
		
		partial_delay(1);
		counter+=1;
		
	}
	
	return 0;
}
