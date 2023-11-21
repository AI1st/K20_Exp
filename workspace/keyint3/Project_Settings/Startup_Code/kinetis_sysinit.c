/*
 *    kinetis_sysinit.c - Default init routines for P2
 *                     		Kinetis ARM systems
 *    Copyright �2012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"

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

/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void Default_Handler()
{
	__asm("bkpt");
}

uint32_t ledset;
int color=0; 

void PORTE_Handler()
{   uint32_t ledout;
    uint32_t ledout3;
	int n=0;
	
	if(PORTE_ISFR&0X04)  //按键按下之后该位中断标志为1  
			     {  n=color;
			        color=0;}
	if(PORTE_ISFR&0X08)  //按键按下之后该位中断标志为1  
				 {  n=color-1;
				    color=1;}		   
	if(PORTE_ISFR&0X10)  //按键按下之后该位中断标志为1  
				 {  n=color-2;
				   color=2;}
	
	if(n>0&&n<3)
		{   GPIOC_PDOR|=0x0FFF;
		    ledset=ledset>>n;
			GPIOC_PDOR=~ledset;}
	if(n<0)
			{ GPIOC_PDOR|=0x0FFF;
			  ledset=ledset<<(-n);
			  GPIOC_PDOR=~ledset;}
		
	if(PORTE_ISFR&0X20)  //按键按下之后该位中断标志为1  
				 {  n=color;
				    GPIOC_PDOR|=0x0FFFF;
				    if(n!=0)
				    {ledout3=ledset>>n;}
				    ledout=ledout3|(ledout3<<1)|(ledout3<<2);
				    GPIOC_PDOR=~ledout;
				    //color=3;
				    }

			PORTE_ISFR |= 0x000000FF;  //Clear Port E  flags

}

void PORTB_Handler()
{   
	uint32_t ledout;
//	ledout=ledset;
	if(PORTB_ISFR&0X20000)  //按键按下之后该位中断标志为1  
			     {  GPIOC_PDOR|=0x0FFFF;
			        ledset=0x01;
					ledout=~ledset;			     
					GPIOC_PDOR&=ledout;	}
			   
	if(PORTB_ISFR&0X10000)  //按键按下之后该位中断标志为1  
				     {  GPIOC_PDOR|=0x0FFFF;
				        ledset=0x09;
						ledout=~ledset;			     
						GPIOC_PDOR&=ledout;  }
	if(PORTB_ISFR&0X0800)  //按键按下之后该位中断标志为1  
				     {  GPIOC_PDOR|=0x0FFFF;
				        ledset=0x49;
						ledout=~ledset;			     
						GPIOC_PDOR&=ledout; }
	if(PORTB_ISFR&0X0400)  //按键按下之后该位中断标志为1  
				     {  GPIOC_PDOR|=0x0FFFF;
				        ledset=0x249;
						ledout=~ledset;			     
						GPIOC_PDOR&=ledout;  }
			color=0;
			PORTB_ISFR |= 0x3C000;  //Clear Port E  flags

}
/**
 **===========================================================================
 **  Reset handler
 **===========================================================================
 */
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
        //Default_Handler,
        PORTB_Handler,	
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
