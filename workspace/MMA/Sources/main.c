/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "MMA8451Q.h"
#include "UART0.h"

unsigned char MMA8451_XYZ_CFG;

unsigned char MMA8451_X_MSB,MMA8451_X_LSB;
unsigned char MMA8451_Y_MSB,MMA8451_Y_LSB;
unsigned char MMA8451_Z_MSB,MMA8451_Z_LSB;

void enable_irq(int irq)
{
	int div;
	/*Determinate which of the NVICISERs corresponds to the irq */
	div=irq/32;
	switch(div)
	{
	   case  0x0:
		   NVICICPR0=1<<(irq%32);
		   NVICISER0=1<<(irq%32);
		   break;
	   case  0x1:
		   NVICICPR1=1<<(irq%32);
		   NVICISER1=1<<(irq%32);
		   break;
	   case  0x2:
		   NVICICPR2=1<<(irq%32);
		   NVICISER2=1<<(irq%32);
		   break;		   
	}
}

/*enable initial*/
void EN_Init()
{
	enable_irq(45);  //UART0 interrupt
//	enable_irq(68);  //PIT interrupt
//	enable_irq(88);  //PORTB interrupt
//	enable_irq(91);  //PORTE interrupt
}

void System_Init()
{
	SIM_SCGC4|=0x400;// ʹ��UART0��ʱ��
	SIM_SCGC5|=0x200; // ʹ��PORTA��ʱ��
	PORTA_PCR1=0x200; //���ö˿�PTA1ΪUART0���ö˿�
	PORTA_PCR2=0x200; //���ö˿�PTA1ΪUART0���ö˿�
}

int main(void)
{
	System_Init();
	UART0_Init();
	MMA8451_Init();  //initial MMA8451 g sensor		
	EN_Init();
	unsigned int counter=0;
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
