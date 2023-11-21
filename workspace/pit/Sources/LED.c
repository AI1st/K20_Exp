/*
 * LED.c
 *
 *  Created on: Mar 21, 2014
 *      Author: renpf
 */

#include <derivative.h>
#include <LED.h>

/*LED inital*/
void LED_Init()
{
	/*enable PORTC clock*/
	SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
	
	/*portC0---11 was set to GPIO*/	
	PORTC_PCR0=PORT_PCR_MUX(0X1);	
	PORTC_PCR1=PORT_PCR_MUX(0X1);
	PORTC_PCR2=PORT_PCR_MUX(0X1);	
	PORTC_PCR3=PORT_PCR_MUX(0X1);
	PORTC_PCR4=PORT_PCR_MUX(0X1);	
	PORTC_PCR5=PORT_PCR_MUX(0X1);
	PORTC_PCR6=PORT_PCR_MUX(0X1);	
	PORTC_PCR7=PORT_PCR_MUX(0X1);	
	PORTC_PCR8=PORT_PCR_MUX(0X1);	
	PORTC_PCR9=PORT_PCR_MUX(0X1);
	PORTC_PCR10=PORT_PCR_MUX(0X1);	
	PORTC_PCR11=PORT_PCR_MUX(0X1);
	    
	/*port set to out*/
	GPIOC_PDDR|=0XFFF;
	/*port out set to high*/
	GPIOC_PDOR=0XFFF;
	
}


//0x01--LED1_flag red;0x02---LED2_flag red;0x03---LED3_flag red;0x04---LED4_flag red;
void LED_color(unsigned char LED_flag)
{
	switch(LED_flag)
	{
        case 0x01:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT9);  //GPIOC9  light	    	
    	         break;
        case 0x02:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT6);  //GPIOC6  light	    	
    	         break;
        case 0x03:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT3);  //GPIOC3  light	    	
    	         break;
        case 0x04:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT0);  //GPIOC0  light	    	
    	         break;

	    default: 
	    	     break;
	}
}
