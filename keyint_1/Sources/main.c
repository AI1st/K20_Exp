/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

int main(void)
{
	    SIM_SCGC5|=0x800;   //使能PORTC时钟
	    SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;   //使能PORTC时钟
		PORTC_PCR0=0x100;	//LED1红灯对应引脚设置为GPIO
		PORTC_PCR1=0x100;	//LED1绿灯对应引脚设置为GPIO
		PORTC_PCR2=0x100;	//LED1蓝灯对应引脚设置为GPIO
		PORTC_PCR3=0x100;	//LED2红灯对应引脚设置为GPIO
		PORTC_PCR4=0x100;	//LED2绿灯对应引脚设置为GPIO
		PORTC_PCR5=0x100;	//LED2蓝灯对应引脚设置为GPIO
		PORTC_PCR6=0x100;	//LED3红灯对应引脚设置为GPIO
		PORTC_PCR7=0x100;	//LED3绿灯对应引脚设置为GPIO
		PORTC_PCR8=0x100;	//LED3蓝灯对应引脚设置为GPIO
		PORTC_PCR9=0x100;	//LED4红灯对应引脚设置为GPIO
		PORTC_PCR10=0x100;	//LED4绿灯对应引脚设置为GPIO
		PORTC_PCR11=0x100;	//LED4蓝灯对应引脚设置为GPIO
		GPIOC_PDOR|=0xFFFF;    // 初始设置所有小灯全灭  
		GPIOC_PDDR|= 0xFFFF;   //LED1-LED4红绿灯对应端口都设置为输出
		
		KEY_Init();
		EN_Init();

		for(;;)
		{
		
			int i;
			i=1;
			i=i++;
					}
		
}
