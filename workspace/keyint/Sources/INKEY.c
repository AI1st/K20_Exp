/*
 * INKEY.c
 *
 *  Created on: Dec 18, 2015
 *      Author: dell
 */

#include <derivative.h>

/*delay function*/
void delayms(unsigned int number)
{
  unsigned short i,j;
  for(i=0;i<number;i++)
  {
	  for(j=0;j<100;j++)
		  asm("nop");
  }
}

/*enable interrupt*/
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
	enable_irq(91);  //PORTE interrupt
}






/*KEY initial*/
void KEY_Init()
{
	/*enable PORTE  clock*/
	SIM_SCGC5|=SIM_SCGC5_PORTE_MASK;

	/*portE2、3  set to GPIO,raising edge interrupt,no pull enable,passive filter enable*/
	PORTE_PCR2=0x0A0103;
	//PORTE_PCR2=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;
	PORTE_PCR3=0x0A0103;
	//PORTE_PCR3=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	GPIOE_PDDR&= ~0x0C;  //两个按键端口PTE2和PTE3设置为输入	
}

