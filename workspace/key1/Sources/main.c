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
	SIM_SCGC5|=0x2800;   //ʹ��PORTC��PORTEʱ��
	PORTC_PCR0=0x100;	//LED1��ƶ�Ӧ��������ΪGPIO
	PORTC_PCR1=0x100;	//LED1�̵ƶ�Ӧ��������ΪGPIO
	PORTE_PCR2=0x103;	//����A��Ӧ����PTE2����ΪGPIO
	PORTE_PCR3=0x103;	//����B��Ӧ����PTE3����ΪGPIO
	GPIOC_PDDR|= 0x03;   //LED1���̵ƶ�Ӧ�˿ڶ�����Ϊ���
	GPIOE_PDDR&= ~0x0C;  //���������˿�PTE2��PTE3����Ϊ����
	GPIOC_PDOR|=0x03;    // PTC0��PTC1��1������С��ȫ��  
	for(;;)
	{
	//A��������֮��Ϊ0���͵�ƽ����д��if(!(GPIOE_PDIR&0x20))
	   if((GPIOE_PDIR&0x04)==0)     
	     { GPIOC_PDOR&=~0x01;} //�����
	   else
	GPIOC_PDOR|=0x01; 
	   
	if((GPIOE_PDIR&0x08)==0)    //B��������֮��Ϊ0���͵�ƽ��
	     { GPIOC_PDOR&=~0x02;}   //�̵���
	   else
	GPIOC_PDOR|=0x02;	
				}
	
}
