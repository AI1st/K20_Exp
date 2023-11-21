/*
 * LED.c
 *
 *  Created on: Mar 21, 2014
 *      Author: renpf
 */

#include <derivative.h>

/*LED inital*/
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

//input parameter number:0x01--LED1;0x02----LED2;0x03----LED3;0x04---LED4
void LED_light(unsigned char number)
{
	switch(number)
	{
	     case 1:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT0|BIT1|BIT2);   //GPIOC0--1--2  light
	    	    break;
	     case 2:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT3|BIT4|BIT5);   //GPIOC0--3--5  light
	    	    break;
	     case 3:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT6|BIT7|BIT8);   //GPIOC0--6--8  light
	    	    break;
	     case 4:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT9|BIT10|BIT11);  //GPIOC0--9--11  light
	    	    break;
	     default: 
	    	    GPIOC_PDOR&=~0xFFF;              //GPIOC0--1--2  light
	    	    break;
	}
}

//0x01--LED1_flag;0x02---LED2_flag;0x03---LED3_flag;0x04---LED4_flag;white---0x00;blue---0x10;green---0x20;red---0x30
void LED_color(unsigned char LED1_flag,unsigned char LED2_flag,unsigned char LED3_flag,unsigned char LED4_flag,unsigned char color)
{
	unsigned char led_light_flag;
	led_light_flag=LED1_flag|LED2_flag|LED3_flag|LED4_flag|color;
	switch(led_light_flag)
	{
        case 0x01:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT1|BIT2);  //GPIOC0--9--11  light	    	
    	         break;
        case 0x02:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT3|BIT4|BIT5);  //GPIOC0--9--11  light	    	
    	         break;
        case 0x03:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT6|BIT7|BIT8);  //GPIOC0--9--11  light	    	
    	         break;
        case 0x04:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT9|BIT10|BIT11);  //GPIOC0--9--11  light	    	
    	         break;
	    case 0x11:
    		     GPIOC_PDOR=0XFFF;      //all dim
    	         GPIOC_PDOR&=~(BIT0);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x12:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT3);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x13:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT6);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x14:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT9);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x21:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT1);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x22:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT4);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x23:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT7);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x24:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT10);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x31:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT2);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x32:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT5);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x33:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT8);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x34:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT11);  //GPIOC0--9--11  light	    	
	    	     break;
	    default: 
	    	     break;
	}
}
