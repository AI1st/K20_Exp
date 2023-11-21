/*
 *    kinetis_sysinit.c - Default init routines for P2
 *                     		Kinetis ARM systems
 *    Copyright �2012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"
#include "LED_CODE.h"

/**
 **===========================================================================
 **  External declarations
 **===========================================================================
 */
#if __cplusplus
extern "C" {
#endif
extern uint32_t __vector_table[];
extern unsigned long _estack;
extern void __thumb_startup(void);
#if __cplusplus
}
#endif

extern unsigned short encoding_flag;
extern unsigned short input_flag;
extern unsigned short add_flag;
extern unsigned short temp;
extern unsigned short input_num;

void partial_delay(int deley_t);
void delay(void);

/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void Default_Handler()
{
	__asm("bkpt");
}

/**
 **===========================================================================
 **  Reset handler
 **===========================================================================
 */

void PORTB_Handler()
{
	//PORTB_ISFR |= 0x00000FFF;
	partial_delay(500); //按键去抖
	if(PORTB_ISFR&0b100000000000000000)  //sw1  -  0
	    {
//		GPIOC_PDOR|=0xFFF;
//		GPIOC_PDOR=~0x01;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 0;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 0;
				temp = 0;  
			}
	    }
	if(PORTB_ISFR& 0b10000000000000000)  //sw2  -  1
		{
//		GPIOC_PDOR|=0xFFF;
//		GPIOC_PDOR=~0b000000001001;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 1;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 1;
				temp = 0;  //temp清零
			}
		}
	if(PORTB_ISFR&      0b100000000000)  //sw3  -  2
		{
//		GPIOC_PDOR|=0xFFF;
//		GPIOC_PDOR=~0b000001001001;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 2;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 2;
				temp = 0;  //temp清零
			}
		}
	if(PORTB_ISFR&       0b10000000000)  //sw4  -  3
		{
//		GPIOC_PDOR|=0xFFF;
//		GPIOC_PDOR=~0b001001001001;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 3;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 3;
				temp = 0;  //temp清零
			}
		}
	while((GPIOB_PDIR&0x030C00)!= 0x030C00){}
	PORTB_ISFR |= 0x0FFFFF;  //Clear ort B  flags
	
}

void PORTE_Handler()
{
	//PORTE_ISFR |= 0x000000FF;
	partial_delay(500); //按键去抖
	if(PORTE_ISFR&0b100)     //sw5  -  4        //按键按下该位后中断标志为1 
		{
//		GPIOC_PDOR&=~0x01;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 4;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 4;
				temp = 0;  //temp清零
			}
		}
	if(PORTE_ISFR&0b1000)    //sw6  -  5       
		{
//		GPIOC_PDOR&=~0x02;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 5;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 5;
				temp = 0;  //temp清零
			}
		}
	if(PORTE_ISFR&0b10000)   //sw7  -  6        
		{
//		GPIOC_PDOR&=~0x01;
			if(encoding_flag==0){
				encoding_flag = 1;
				
				temp = 6;
			}
			else{
				encoding_flag = 0;
				input_flag = 1; //在main中需要清零
				
				input_num = temp*10 + 6;
				temp = 0;  //temp清零
			}
		}
	if(PORTE_ISFR&0b100000)  //sw8  -  +        
		{
//		GPIOC_PDOR|=0x01;
			if(encoding_flag==0){
				add_flag = 1;  //在main中需要清零
			}
			else{
			}
		}
	while((GPIOE_PDIR&0x003C)!= 0x003C){}
	PORTE_ISFR |= 0x0000FF;  //Clear Port E  flags
//		PORTE_PCR2 |= 0x01000000;  //Another way to Clear Port E  flags
//		PORTE_PCR3 |= 0x01000000;
}



void __init_hardware()
{
	SCB_VTOR = (uint32_t)__vector_table; /* Set the interrupt vector table position */
	/*
		Disable the Watchdog because it may reset the core before entering main().
		There are 2 unlock words which shall be provided in sequence before
		accessing the control register.
	*/
	WDOG_UNLOCK = KINETIS_WDOG_UNLOCK_SEQ_1;
	WDOG_UNLOCK = KINETIS_WDOG_UNLOCK_SEQ_2;
	WDOG_STCTRLH = KINETIS_WDOG_DISABLED_CTRL;
}

/* Weak definitions of handlers point to Default_Handler if not implemented */
void NMI_Handler() __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler() __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler() __attribute__ ((weak, alias("Default_Handler")));
void DebugMonitor_Handler() __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler() __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler() __attribute__ ((weak, alias("Default_Handler")));


/* The Interrupt Vector Table */
void (* const InterruptVector[])() __attribute__ ((section(".vectortable"))) = {
    /* Processor exceptions */
    (void(*)(void)) &_estack,
    __thumb_startup,
    NMI_Handler, 
    HardFault_Handler, 
    MemManage_Handler, 
    BusFault_Handler,
    UsageFault_Handler, 
    0, 
    0, 
    0, 
    0, 
    SVC_Handler, 
    DebugMonitor_Handler, 
    0,
    PendSV_Handler, 
    SysTick_Handler,
    /* Interrupts */
    Default_Handler,   //0
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,  //10
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,  //20
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,   
    Default_Handler,   //30
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,    
    Default_Handler,    //40
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,   //50
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,  //60
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,   //70
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  
    Default_Handler,   //80
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    PORTB_Handler,     //88
    Default_Handler,  
    Default_Handler,   //90
    PORTE_Handler,	  //91  PORTE Interrupt
   // Default_Handler,  	
    Default_Handler,  
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,	
    Default_Handler,
    Default_Handler,
    Default_Handler,		
};
