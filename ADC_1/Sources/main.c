/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "LED_CODE.h"  

unsigned int ADC_Result;
float voltage;

unsigned char num[11]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28,0x7F};

void partial_delay(int delay_t)
	{  
	   unsigned short i,j;
	   for(i=0;i<30*delay_t;i++) 
	      for(j=0;j<20; j++)
	         asm("nop");
	}


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

void iniled()
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
	GPIOC_PDOR&= 0b111111000000;
}
void l3()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b111000000000;
}
void l4()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b000000000000;
}

void show_number(float number)
	{  

	   int digit_num = number;
	   int float_num = (number-digit_num)*10+0.5;
	   
	   //数字管部分
	   uint32_t Select_LED = Select_LED0;  //初始化
	   GPIOA_PDOR |= 0x03F000;	
	   GPIOD_PDOR &= ~0xFF;     
	   //显示小数部分
	   GPIOA_PDOR &= Select_LED; //片选初始化
	   GPIOD_PDOR |= num[float_num];
	   partial_delay(1);
	   //复位并片选下一个数字管
	   GPIOA_PDOR |= 0x03F000;	
	   GPIOD_PDOR &= ~0xFF;
	   Select_LED = Select_LED<<1;
	   Select_LED += 1;
	   GPIOA_PDOR &= Select_LED; //重新片选
	   GPIOD_PDOR |= (num[digit_num]&0b11011111);
	   partial_delay(1);
	   //partial_delay(1);
	  //delay();
	  
	}

void show_range(float number){
	
	   //LED灯部分
	   if(number>0.5&&number<1){
		   l4();
	   }
	   else if(number>1&&number<1.5){
		   l3();
	   }
	   else if(number>1.5&&number<2){
		   l2(); 
	   }
	   else if(number>2&&number<3){
		   l1();   
	   }
}
int main(void)
{
	
	float range = 3276;
	float start = 127;
	//uint32_t Select_LED;
	//Select_LED = Select_LED0;
	
	ADC_Init();
	LED_Disp_Init( );
	iniled();
	
	for(;;){
	while((ADC1_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
		  	
		ADC_Result=ADC1_RA;
		voltage = (ADC_Result-start)/range *3.3;
		
		show_number(voltage);
		show_range(voltage);
		
		//clear flag	   	
	   	ADC1_SC1A&=~ADC_SC1_COCO_MASK;
	   	//delay();
	}
}
