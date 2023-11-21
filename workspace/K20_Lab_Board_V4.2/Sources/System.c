/*
 * System.c
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */
#include <derivative.h>

unsigned char  Num[11]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28,0xFF};
unsigned long int led[6]={BIT12,BIT13,BIT14,BIT15,BIT16,BIT17};


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
	enable_irq(45);  //UART0 interrupt
	enable_irq(68);  //PIT interrupt
	enable_irq(88);  //PORTB interrupt
	enable_irq(91);  //PORTE interrupt
}






/*KEY initial*/
void KEY_Init()
{
	/*enable PORTA,PORTC,PORTE  clock*/
	SIM_SCGC5|=SIM_SCGC5_PORTB_MASK+SIM_SCGC5_PORTE_MASK;

	/*portB  set to GPIO,raising edge interrupt,no pull enable,passive filter enable*/	
	PORTB_PCR10=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	PORTB_PCR11=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;			
	PORTB_PCR16=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	PORTB_PCR17=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	
	/*portE  set to GPIO,raising edge interrupt,no pull enable,passive filter enable*/
	PORTE_PCR2=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	PORTE_PCR3=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	PORTE_PCR4=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	PORTE_PCR5=PORT_PCR_MUX(0X1)+PORT_PCR_IRQC(0X0A)+PORT_PCR_PE_MASK+PORT_PCR_PS_MASK;	
	
}

//SMG init
void SMG_Init()
{
	    /* PORTA and PORTD clock have already enabled*/
		SIM_SCGC5|=SIM_SCGC5_PORTA_MASK+SIM_SCGC5_PORTD_MASK;		   
	    
		/*portA  set to GPIO*/	    
	    PORTA_PCR12=PORT_PCR_MUX(0X1);
	    PORTA_PCR13=PORT_PCR_MUX(0X1);
	    PORTA_PCR14=PORT_PCR_MUX(0X1);
	    PORTA_PCR15=PORT_PCR_MUX(0X1);
	    PORTA_PCR16=PORT_PCR_MUX(0X1);
	    PORTA_PCR17=PORT_PCR_MUX(0X1);
	    
		/*portD  set to GPIO*/	    
	    PORTD_PCR0=PORT_PCR_MUX(0X1);
	    PORTD_PCR1=PORT_PCR_MUX(0X1);
	    PORTD_PCR2=PORT_PCR_MUX(0X1);
	    PORTD_PCR3=PORT_PCR_MUX(0X1);
	    PORTD_PCR4=PORT_PCR_MUX(0X1);
	    PORTD_PCR5=PORT_PCR_MUX(0X1);
	    PORTD_PCR6=PORT_PCR_MUX(0X1);
	    PORTD_PCR7=PORT_PCR_MUX(0X1); 
	    
	    /*LED control pin set to out*/	    
	    GPIOA_PDDR|=GPIO_PDDR_PDD(GPIO_PIN(12)|GPIO_PIN(13)|GPIO_PIN(14)|GPIO_PIN(15)|GPIO_PIN(16)|GPIO_PIN(17));
	    
	    /*LED bit pin set to out*/	  
	    GPIOD_PDDR|=0x000000FF;	    
	    
	    /*LED control pin set to high ,LEDs are closed*/
	    GPIOA_PDOR|=GPIO_PDDR_PDD(GPIO_PIN(12)|GPIO_PIN(13)|GPIO_PIN(14)|GPIO_PIN(15)|GPIO_PIN(16)|GPIO_PIN(17));	    
	    
	    /*LED bit pin set to low ,LED bit are all lighted,change GPIOC_PDOR register can change the number it shows*/
		GPIOD_PDOR=0x00;		
		
		/*LED control pin set to low ,LEDs are all open*/
		GPIOA_PDOR&=~GPIO_PDDR_PDD(GPIO_PIN(12)|GPIO_PIN(13)|GPIO_PIN(14)|GPIO_PIN(15)|GPIO_PIN(16)|GPIO_PIN(17));
}

//SMG show data in show_data[]:0---5
void SMG_show_data(unsigned char show_data[],unsigned char number)
{
	/*
	unsigned char i;
	for(i=0;i<6;i++)
	{
		 GPIOA_PDOR|=0xFF000; 
		 GPIOD_PDOR=Num[show_data[i]];
		 GPIOA_PDOR&=~(led[i%6]);		
		 //GPIOA_PDOR=0x00;
	}*/
	
	 GPIOA_PDOR|=0xFF000; 
	 GPIOD_PDOR=Num[show_data[number]];
	 GPIOA_PDOR&=~(led[number%6]);	
}
