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

unsigned char dtoa(unsigned char num)  //��4λ��������ת��Ϊ�ַ�
{
	if (num>=10)
		num= 'A'+( num-10); //���ΪA~F
	else
		num='0'+num;    //���Ϊ0~9
		return num;
}

void UART0_SendHex(unsigned char num) 
 {
	unsigned  char  nTmp;
	nTmp = dtoa((num&0xF0)>>4);  //���num�ĸ���λ
	UART0_SendChar(nTmp);		//���ڷ���
	nTmp = dtoa((num &0x0F));//���num�ĵ���λ
	UART0_SendChar(nTmp);		
}

int main(void)
{
	unsigned char temp;
	  System_Init();
	  UART0_Init();
	  for(;;) {
	    temp = UART0_GetChar();
	    UART0_SendChar(temp);				//����
	    UART0_SendChar('-');
	    UART0_SendChar('0');
	    UART0_SendChar('x');
	    UART0_SendHex(temp);
	    UART0_SendChar('\r');
	    UART0_SendChar('\n');
	  } 

}
