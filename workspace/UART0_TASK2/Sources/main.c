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
unsigned char UART0_GetChar()
{
	while(!(UART0_S1&0x20));
	return UART0_D;  
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

unsigned char dtoa(unsigned char num)  //将4位二进制数转换为字符
{
	if (num>=10)
		num= 'A'+( num-10); //结果为A~F
	else
		num='0'+num;    //结果为0~9
		return num;
}

void UART0_SendHex(unsigned char num) 
 {
	unsigned  char  nTmp;
	nTmp = dtoa((num&0xF0)>>4);  //获得num的高四位
	UART0_SendChar(nTmp);		//串口发送
	nTmp = dtoa((num &0x0F));//获得num的低四位
	UART0_SendChar(nTmp);		
}

int main(void)
{
	unsigned char temp;
	  System_Init();
	  UART0_Init();
	  for(;;) {
	    temp = UART0_GetChar();
	    UART0_SendChar(temp);				//回显
	    UART0_SendChar('-');
	    UART0_SendChar('0');
	    UART0_SendChar('x');
	    UART0_SendHex(temp);
	    UART0_SendChar('\r');
	    UART0_SendChar('\n');
	  } 

}
