/*
 * UART0.c
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */


#include <derivative.h>


unsigned short uartclk_khz=20970;
unsigned short baud=9600;
unsigned short sbr,brfa;
unsigned char tom;


unsigned char uart0_getchar(void)
{
	
	/*wait until character has been received*/
	while(!(UART0_S1&UART_S1_RDRF_MASK));
	
	return UART0_D;

}

/*
void uart0_putchar(unsigned char data)
{
	while(!(UART0_S1&UART_S1_TDRE_MASK));
    UART0_D=data;
}*/
void UART0_send_data(unsigned char data[],unsigned char number)
{
	unsigned short i;
	for(i=0;i<number;i++)
	{
	   while(!(UART0_S1&0x80)); 
	      UART0_D=*(data+i);
	}
}

void UART0_SendChar(unsigned char data)
{
	 while(!(UART0_S1&0x80)); 
	 UART0_D=data;
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
	nTmp = dtoa((num&0x0F));//获得num的低四位
    UART0_SendChar(nTmp);		
    UART0_SendChar('\r');
    UART0_SendChar('\n');//
}



void UART0_Init()
{
	
	    UART0_BDH = 0x00;
		UART0_BDL = 0x88; 
	    UART0_C4=0x10;    //波特率9600
	    UART0_C2 = 0x2C;   //打开发送和接收器
}



