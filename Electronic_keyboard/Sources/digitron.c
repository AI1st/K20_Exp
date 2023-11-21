/*
 * digitron.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lenovo
 */

#include "derivative.h"
#include "digitron.h"

const unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};

void LED_Disp_Init(void) 
{
	SIM_SCGC5 |=(0x1000 | 0x0200);
	/*portA  set to GPIO*/	    
	PORTA_PCR12=0x100;
	PORTA_PCR13=0x100;
	PORTA_PCR14=0x100;
	PORTA_PCR15=0x100;
	PORTA_PCR16=0x100;
	PORTA_PCR17=0x100;

	/*portD  set to GPIO*/
	PORTD_PCR0 = 0x0100;
	PORTD_PCR1 = 0x0100;
	PORTD_PCR2 = 0x0100;
	PORTD_PCR3 = 0x0100;
	PORTD_PCR4 = 0x0100;
	PORTD_PCR5 = 0x0100;
	PORTD_PCR6 = 0x0100;		
	PORTD_PCR7 = 0x0100;
		
	/*LED bit pin set to out*/
	GPIOD_PDDR |=0x00FF;
	GPIOA_PDDR |=0x03F000;
	/*LED control pin set to high ,LEDs are closed*/
	GPIOA_PDOR |=0x03F000;
	/*LED bit pin set to high ,LED bit are all off, change GPIOD_PDOR register can change the number it shows*/
	GPIOD_PDOR = 0xFF;
}

void show_number(int number)
	{  
//	   unsigned int tube0 = number % 10 / 1;
//	   unsigned int tube1 = number % 100 / 10;
//	   unsigned int tube2 = number % 1000 / 100;
//	   unsigned int tube2 = number % 10000 / 1000;
//	   unsigned int tube3 = number % 100000 / 10000;
//	   unsigned int tube4 = number % 100000 / 100000;
	   unsigned int display_number[6] = {0};
	   int pointer = 1;
	   int i;
	   for(i=1;i<=6;i++){
		   display_number[i-1] = (number % (pointer*10)) / pointer;
		   pointer *= 10;
	   }
	   uint32_t Select_LED = Select_LED0;
	   for(i=1;i<=6;i++){
		   GPIOA_PDOR |= 0x03F000;	//ѡ��λ��
		   GPIOD_PDOR &= ~0xFF;//ѡ������
//		   GPIOD_PDOR |= LED_off;
		   GPIOA_PDOR &= Select_LED; 
		   int m;
		   m= display_number[i-1];
		   GPIOD_PDOR |= num[m];
		   Select_LED = Select_LED<<1;
		   Select_LED += 1;
		   partial_delay(1);
		   //delay();
	   }
	}
