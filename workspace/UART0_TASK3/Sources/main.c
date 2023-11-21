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
	  magic = i%10;  //�µ���0~9
//	  i=rand();
//	  magic= i%10 ;

      again=1;
	  nGuess =0;
	  }
	  if(again==1)
	  {
	    Input = UART0_GetChar();
	    nGuess ++;
	    UART0_SendChar(Input); // ���� 
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
