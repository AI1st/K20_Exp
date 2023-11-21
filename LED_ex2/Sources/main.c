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
void iniled()
{
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
	
}
//void red()
//{
//	//通过逻辑”或”置1，不影响其他位，使能PORTC时钟 
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR0=On;	//设置PTC2为GPIO
//		   PORTC_PCR1=Off;	//设置PTC2为GPIO
//		   PORTC_PCR2=Off;	//设置PTC2为GPIO
//		   PORTC_PCR3=On;	//设置PTC2为GPIO
//		   PORTC_PCR4=Off;	//设置PTC2为GPIO
//		   PORTC_PCR5=Off;	//设置PTC2为GPIO
//		   PORTC_PCR6=On;	//设置PTC2为GPIO
//		   PORTC_PCR7=Off;	//设置PTC2为GPIO
//		   PORTC_PCR8=Off;	//设置PTC2为GPIO
//		   PORTC_PCR9=On;	//设置PTC2为GPIO
//		   PORTC_PCR10=Off;	//设置PTC2为GPIO
//		   PORTC_PCR11=Off;	//设置PTC2为GPIO
//}
//void green()
//{
//	//通过逻辑”或”置1，不影响其他位，使能PORTC时钟 
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR1=On;	//设置PTC2为GPIO
//		   PORTC_PCR0=Off;	//设置PTC2为GPIO
//		   PORTC_PCR2=Off;	//设置PTC2为GPIO
//		   PORTC_PCR4=On;	//设置PTC2为GPIO
//		   PORTC_PCR5=Off;	//设置PTC2为GPIO
//		   PORTC_PCR3=Off;	//设置PTC2为GPIO
//		   PORTC_PCR7=On;	//设置PTC2为GPIO
//		   PORTC_PCR8=Off;	//设置PTC2为GPIO
//		   PORTC_PCR6=Off;	//设置PTC2为GPIO
//		   PORTC_PCR10=On;	//设置PTC2为GPIO
//		   PORTC_PCR11=Off;	//设置PTC2为GPIO
//		   PORTC_PCR9=Off;	//设置PTC2为GPIO
//}
//void blue()
//{
//	//通过逻辑”或”置1，不影响其他位，使能PORTC时钟
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR2=On;	//设置PTC2为GPIO
//		   PORTC_PCR1=Off;	//设置PTC2为GPIO
//		   PORTC_PCR0=Off;	//设置PTC2为GPIO
//		   PORTC_PCR5=On;	//设置PTC2为GPIO
//		   PORTC_PCR4=Off;	//设置PTC2为GPIO
//		   PORTC_PCR3=Off;	//设置PTC2为GPIO
//		   PORTC_PCR8=On;	//设置PTC2为GPIO
//		   PORTC_PCR7=Off;	//设置PTC2为GPIO
//		   PORTC_PCR6=Off;	//设置PTC2为GPIO
//		   PORTC_PCR11=On;	//设置PTC2为GPIO
//		   PORTC_PCR10=Off;	//设置PTC2为GPIO
//		   PORTC_PCR9=Off;	//设置PTC2为GPIO
//}
void red()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b110110110110;
}
void green()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b101101101101;
}
void blue()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b011011011011;
}
int main(void)
{
	//通过逻辑”或”置1，不影响其他位，使能PORTC时钟
	   SIM_SCGC5|=0x3E00;   
       // GPIOC_PDOR&=~0xFFFF; //配置PTC2为0，小灯点亮 (不加~也效果相同的2原因：上电的寄存器初始状态为全零)
	   iniled();
	   GPIOC_PDOR|= 0x0FFF;
	   //GPIOC_PDOR&=~GPIO_PIN(2);
	   //PORTC_PCR2=PORT_PCR_MUX(1);
	   GPIOC_PDDR =0x0FFF;   //配置PTC2为输出 
	   //GPIOC_PDDR=GPIO_PIN(2); 
	   
	   for(;;){
		    //GPIOC_PDOR = ~ GPIOC_PDOR;
		    red();
		    delay();
		    delay();
		    green();
		    delay();
		    delay();
		    blue();
		    delay();
		    delay();
	        
	// ~为逻辑取反，也可用GPIOD_PTOR寄存器反转端口
	        //GPIOC_PDOR = ~ GPIOC_PDOR;	
	          }

}
