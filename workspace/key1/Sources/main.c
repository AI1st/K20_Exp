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
	SIM_SCGC5|=0x2800;   //使能PORTC和PORTE时钟
	PORTC_PCR0=0x100;	//LED1红灯对应引脚设置为GPIO
	PORTC_PCR1=0x100;	//LED1绿灯对应引脚设置为GPIO
	PORTE_PCR2=0x103;	//按键A对应引脚PTE2设置为GPIO
	PORTE_PCR3=0x103;	//按键B对应引脚PTE3设置为GPIO
	GPIOC_PDDR|= 0x03;   //LED1红绿灯对应端口都设置为输出
	GPIOE_PDDR&= ~0x0C;  //两个按键端口PTE2和PTE3设置为输入
	GPIOC_PDOR|=0x03;    // PTC0和PTC1赋1，两个小灯全灭  
	for(;;)
	{
	//A按键按下之后为0（低电平）可写成if(!(GPIOE_PDIR&0x20))
	   if((GPIOE_PDIR&0x04)==0)     
	     { GPIOC_PDOR&=~0x01;} //红灯亮
	   else
	GPIOC_PDOR|=0x01; 
	   
	if((GPIOE_PDIR&0x08)==0)    //B按键按下之后为0（低电平）
	     { GPIOC_PDOR&=~0x02;}   //绿灯亮
	   else
	GPIOC_PDOR|=0x02;	
				}
	
}
