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
	enable_irq(68);  //PORTE interrupt
}
