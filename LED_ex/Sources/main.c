#include "derivative.h" /* include peripheral declarations */


void delay()
{  
	unsigned int i,j;
   for(i=0;i<5000;i++)  
{
  for(j=0;j<100;j++)		//嵌套的循环体，延时
   asm("nop");	
}
}

int main(void)
{
	//通过逻辑”或”置1，不影响其他位，使能PORTC时钟
	   SIM_SCGC5|=0x800;   
	   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
	   PORTC_PCR2=0x100;	//设置PTC2为GPIO
	   //PORTC_PCR2=PORT_PCR_MUX(1);
	   GPIOC_PDDR =0x04;   //配置PTC2为输出 
	   //GPIOC_PDDR=GPIO_PIN(2); 
	   GPIOC_PDOR&=~0x04; //配置PTC2为0，小灯点亮 
	   //GPIOC_PDOR&=~GPIO_PIN(2);
	   for(;;){
	        delay();
	// ~为逻辑取反，也可用GPIOD_PTOR寄存器反转端口
	        GPIOC_PDOR = ~ GPIOC_PDOR;	
	          }

}
