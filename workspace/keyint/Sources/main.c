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
		GPIOC_PDDR|= 0x03;   //LED1���̵ƶ�Ӧ�˿ڶ�����Ϊ���
		GPIOC_PDOR|=0x03;    // PTC0��PTC1��1������С��ȫ��  
		KEY_Init();
		EN_Init();

		for(;;)
		{
		
			int i;
			i=1;
			i=i++;
					}
		
}
