/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

int main(void)
{
	        SIM_SCGC5|=0x800;   //ʹ��PORTCʱ��
			PORTC_PCR0=0x100;	//LED1��ƶ�Ӧ��������ΪGPIO
			PORTC_PCR1=0x100;	//LED1�̵ƶ�Ӧ��������ΪGPIO
			PORTC_PCR2=0x100;	//LED1���ƶ�Ӧ��������ΪGPIO
			PORTC_PCR3=0x100;	//LED2��ƶ�Ӧ��������ΪGPIO
			PORTC_PCR4=0x100;	//LED2�̵ƶ�Ӧ��������ΪGPIO
			PORTC_PCR5=0x100;	//LED2���ƶ�Ӧ��������ΪGPIO
			PORTC_PCR6=0x100;	//LED3��ƶ�Ӧ��������ΪGPIO
			PORTC_PCR7=0x100;	//LED3�̵ƶ�Ӧ��������ΪGPIO
			PORTC_PCR8=0x100;	//LED3���ƶ�Ӧ��������ΪGPIO
			PORTC_PCR9=0x100;	//LED4��ƶ�Ӧ��������ΪGPIO
			PORTC_PCR10=0x100;	//LED4�̵ƶ�Ӧ��������ΪGPIO
			PORTC_PCR11=0x100;	//LED4���ƶ�Ӧ��������ΪGPIO
			GPIOC_PDDR|= 0x0FFF;   //LED�������ƶ�Ӧ�˿ڶ�����Ϊ���
			GPIOC_PDOR|=0x0FFF;    // PTC0-PTC11��1�����и�С��ȫ��  
			KEY_Init();
			EN_Init();
			
			for(;;)
					{
					
						int i;
						i=1;
						i=i++;
								}
}
