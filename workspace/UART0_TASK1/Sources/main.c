/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

void UART0_Init() 
{	
	UART0_BDH = 0x00;
	UART0_BDL = 0x88; 
    UART0_C4=0x10;    //波特率9600
    UART0_C2 = 0x0C;   //打开发送和接收器
}
void UART0_SendChar(unsigned char data)
{
	 while(!(UART0_S1&0x80)); 
	 UART0_D=data;
}
void delay()
{  
	unsigned int i,j;
   for(i=0;i<5000;i++)  
   {
	   for(j=0;j<100;j++)		//嵌套的循环体，延时
		   asm("nop");		       //空跳转
   }
}
void System_Init()
{
	SIM_SCGC4|=0x400;// 使能UART0的时钟
	SIM_SCGC5|=0x200; // 使能PORTA的时钟
	PORTA_PCR1=0x200; //配置端口PTA1为UART0复用端口
	PORTA_PCR2=0x200; //配置端口PTA1为UART0复用端口
}
int main()
{ 
	unsigned char ascii_char;
	System_Init();
 	UART0_Init();
 	ascii_char=0;
 	while(ascii_char<128)
 	{
		if(ascii_char % 16 ==0)
		{
			UART0_SendChar('\n');		//’\n’’\r’是windows下的换行符
			UART0_SendChar('\r'); 
		   }
	UART0_SendChar(ascii_char++);
	 }
	for(;;)
	{	
		delay();
	}
}



