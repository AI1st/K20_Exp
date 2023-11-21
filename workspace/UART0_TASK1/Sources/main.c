/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

void UART0_Init() 
{	
	UART0_BDH = 0x00;
	UART0_BDL = 0x88; 
    UART0_C4=0x10;    //������9600
    UART0_C2 = 0x0C;   //�򿪷��ͺͽ�����
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
	   for(j=0;j<100;j++)		//Ƕ�׵�ѭ���壬��ʱ
		   asm("nop");		       //����ת
   }
}
void System_Init()
{
	SIM_SCGC4|=0x400;// ʹ��UART0��ʱ��
	SIM_SCGC5|=0x200; // ʹ��PORTA��ʱ��
	PORTA_PCR1=0x200; //���ö˿�PTA1ΪUART0���ö˿�
	PORTA_PCR2=0x200; //���ö˿�PTA1ΪUART0���ö˿�
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
			UART0_SendChar('\n');		//��\n����\r����windows�µĻ��з�
			UART0_SendChar('\r'); 
		   }
	UART0_SendChar(ascii_char++);
	 }
	for(;;)
	{	
		delay();
	}
}



