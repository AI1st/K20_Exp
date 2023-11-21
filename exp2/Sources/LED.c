/*
 * LED.c
 *
 *  Created on: Mar 21, 2014
 *      Author: renpf
 */

#include <derivative.h>

/*LED initial*/
void LED_Init()
{
	/*enable PORTB and PORTD  clock*/
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

//input parameter number:0x01--LED1;0x02----LED2;0x04----LED3;0x08---LED4
void LED_light(unsigned char number)
{
	switch(number)
	{
	     case 0x01:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT0);   //GPIOC0  light
	    	    break;
	     case 0x02:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    		GPIOC_PDOR&=~(BIT0|BIT3);   //
	    	    break;
	     case 0x03:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    		GPIOC_PDOR&=~(BIT0|BIT3|BIT6);   //
	    	    break;
	     case 0x04:
	    		/*port out set to high*/ 
	    		GPIOC_PDOR=0XFFF;      //all dim
	    		GPIOC_PDOR&=~(BIT0|BIT3|BIT6|BIT9);   //
	    	    break;
	     default: 
	    	    GPIOC_PDOR&=~0xFFF;              //GPIOC0--11  light
	    	    break;
	}
}

//0x01--LED1_flag;0x02---LED2_flag;0x04---LED3_flag;0x08---LED4_flag;white---0x00;blue---0x30;green---0x20;red---0x10
void LED_color(unsigned char LED1_flag,unsigned char LED2_flag,unsigned char LED3_flag,unsigned char LED4_flag,unsigned char color)
{
	unsigned char led_light_flag;
	led_light_flag=LED1_flag|LED2_flag|LED3_flag|LED4_flag|color;
	switch(led_light_flag)
	{
        case 0x01:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT1);  //GPIOC0--1--2  light	    	
    	         break;
        case 0x03:
	             GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT1|BIT2|BIT3|BIT4|BIT5);   	
    	         break;
        case 0x07:
	             GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT1|BIT2);
	             GPIOC_PDOR&=~(BIT3|BIT4|BIT5); 
                 GPIOC_PDOR&=~(BIT6|BIT7|BIT8);    	
    	         break;
        case 0x0F:
	             GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT1|BIT2);
	             GPIOC_PDOR&=~(BIT3|BIT4|BIT5); 
	             GPIOC_PDOR&=~(BIT6|BIT7|BIT8); 
                 GPIOC_PDOR&=~(BIT9|BIT10|BIT11);  	    	
    	         break;
	    case 0x11:
    		     GPIOC_PDOR=0XFFF;      //all dim
    	         GPIOC_PDOR&=~(BIT0);  	    	
	    	     break;
	    case 0x13:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT0|BIT3);    	
	    	     break;
	    case 0x17:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT0|BIT3|BIT6);  	
	    	     break;
	    case 0x1F:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT0|BIT3|BIT6|BIT9);	
	    	     break;
	    case 0x21:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT1);    	
	    	     break;
	    case 0x23:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT1|BIT4); 	
	    	     break;
	    case 0x27:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT1|BIT4|BIT7);   	
	    	     break;
	    case 0x2F:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT1|BIT4|BIT7|BIT10);     	
	    	     break;
	    case 0x31:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT2);    	
	    	     break;
	    case 0x33:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT2|BIT5);    	
	    	     break;
	    case 0x37:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT2|BIT5|BIT8);    	
	    	     break;
	    case 0x3F:
		         GPIOC_PDOR=0XFFF;      //all dim
		         GPIOC_PDOR&=~(BIT2|BIT5|BIT8|BIT11);	
	    	     break;
	    default: 
	    	     break;
	}
}
