/*
 *    kinetis_sysinit.c - Default init routines for P2
 *                     		Kinetis ARM systems
 *    Copyright �2012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"
#include "LED.h"

unsigned char LED_flag=0x01;
extern unsigned int brightness_state;
extern unsigned int total_state;

int state = 0;
int threshold=0;
int direction=1;
int count = 0;

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


void pit_channel0_ISR(void){
	//*********单位PWN**********
	state +=1;
	if(state<threshold){
		green();
	}
	else{
		led_off();
	}
	if(state==9){
		state = 0;
		count+=1;
	}
	//*********单位PWN**********
	if(count==21){ //数21个PWM波
		threshold += direction;
		count = 0; //重新清零count
	}
	if((threshold==0 || threshold==9)){
		direction = -direction;
	}
	// 清除PIT中断标志位
	PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
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
    		Default_Handler,  //0
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
            Default_Handler,  //30
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,  //40
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,  //50
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
            pit_channel0_ISR,   //Default_Handler,
            Default_Handler,
            Default_Handler,  //70
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,  //80
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,  //90
            Default_Handler,	
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,
            Default_Handler,	//100
            Default_Handler,
            Default_Handler,
            Default_Handler,			
};
