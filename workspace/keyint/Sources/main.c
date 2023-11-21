/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

int main(void)
{
	    SIM_SCGC5|=0x800;   //使能PORTC时钟
		PORTC_PCR0=0x100;	//LED1红灯对应引脚设置为GPIO
		PORTC_PCR1=0x100;	//LED1绿灯对应引脚设置为GPIO
		GPIOC_PDDR|= 0x03;   //LED1红绿灯对应端口都设置为输出
		GPIOC_PDOR|=0x03;    // PTC0和PTC1赋1，两个小灯全灭  
		KEY_Init();
		EN_Init();

		for(;;)
		{
		
			int i;
			i=1;
			i=i++;
					}
		
}
