/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include <stdlib.h>

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

void UART0_SendString(char * pt)  
{
  while((*pt)!=0) 
  {
    UART0_SendChar(*pt);
    pt++;
  }
}

int main(void)
{
	unsigned char magic;
	unsigned char i,Input, nGuess,again;

	i=0;
	again=0;
	System_Init();
	UART0_Init();
	for(;;)
	{
	  if(again==0)
	  {
	  UART0_SendString("\r\nGuess my number(0~9)\r\n");
	  while(!(UART0_S1&0x20)) i++;
	  magic = i%10;  //猜的数0~9
//	  i=rand();
//	  magic= i%10 ;

      again=1;
	  nGuess =0;
	  }
	  if(again==1)
	  {
	    Input = UART0_GetChar();
	    nGuess ++;
	    UART0_SendChar(Input); // 回显 
	    if ((Input - '0') > magic) 
	       UART0_SendString(" Large\r\n");
	    else if((Input - '0') < magic)  
	       UART0_SendString(" Small\r\n");
	    else{
	        UART0_SendChar(0x07);
	        UART0_SendString(" Bingo!\n\rYou take ");
	        UART0_SendHex(nGuess);
	        UART0_SendString(" times to get it.\n\r");
	        again=0;
	        }

         }
	}
}
