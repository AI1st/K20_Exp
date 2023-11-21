/*
 *    kinetis_sysinit.c - Default init routines for P2
 *                     		Kinetis ARM systems
 *    Copyright 锟�012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"
#include "System.h" /* include peripheral declarations */
#include "ADC.h" /* include peripheral declarations */
#include "UART0.h" /* include peripheral declarations */
//#include "LED.h"
#include "MMA8451Q.h"/*MMA8451Q */


extern unsigned int ADC_Result;
unsigned int c;
unsigned int number=0;

unsigned char lED1_light_flag;
unsigned char lED2_light_flag;
unsigned char lED3_light_flag;
unsigned char lED4_light_flag;

unsigned char MMA8451_data[6];
extern unsigned char show[6];

unsigned int flag_100ms=0;
unsigned char flag_measure;

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

/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void PORTB_Handler()
{
	//A KEY handler  all show 0
	if(PORTB_ISFR&BIT10)
	{
		//0x01--LED1_flag;0x02---LED2_flag;0x03---LED3_flag;0x04---LED4_flag;blue---0x10;green---0x20;red---0x30
		LED_color(lED1_light_flag,lED2_light_flag,lED3_light_flag,lED4_light_flag,0x10);
	}
	//B KEY handler  all show 1
	else if(PORTB_ISFR&BIT11)
	{
		LED_color(lED1_light_flag,lED2_light_flag,lED3_light_flag,lED4_light_flag,0x20);
	}
	//C KEY handler  all show 2
	else if(PORTB_ISFR&BIT16)
	{
		LED_color(lED1_light_flag,lED2_light_flag,lED3_light_flag,lED4_light_flag,0x30);	
	}
	//D KEY handler  all close
	else if(PORTB_ISFR&BIT17)
	{
		LED_color(lED1_light_flag,lED2_light_flag,lED3_light_flag,lED4_light_flag,0x00);
	}	
	//clear interrupt flag
	PORTB_ISFR |= 0xFFFFFFFF;  //Clear Port B  ISR flags
}



/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void PORTE_Handler()
{
	//L KEY handler
	if(PORTE_ISFR&BIT2)   
	{
		LED_light(0x01);   //LED1
		lED1_light_flag=1; //LED1 flag
		lED2_light_flag=0;
		lED3_light_flag=0;
		lED4_light_flag=0;
	}
	//DOWN KEY handler
	else if(PORTE_ISFR&BIT3)
	{
		LED_light(0x02);   //LED2
		lED1_light_flag=0; //LED1 flag
		lED2_light_flag=2;
		lED3_light_flag=0;
		lED4_light_flag=0;
	}
	else if(PORTE_ISFR&BIT4)
	{
		LED_light(0x03);   //LED3
		lED1_light_flag=0; //LED1 flag
		lED2_light_flag=0;
		lED3_light_flag=3;
		lED4_light_flag=0;
	}
	else if(PORTE_ISFR&BIT5)
	{
		LED_light(0x04);   //LED4
		lED1_light_flag=0; //LED1 flag
		lED2_light_flag=0;
		lED3_light_flag=0;
		lED4_light_flag=4;
	}
	//clear interrupt flag
	PORTE_ISFR |= 0x000000FF;  //Clear Port E  flags
}



/***************************************************************************//*!
 * @brief   UART0 read data register full interrupt service routine.
 ******************************************************************************/
void uart0_isr(void)
{
  
	//ADC_TR_DATA();	

  if (UART0_S1&UART_S1_RDRF_MASK)  
  {
	  c = UART0_D;	               
	  
    if (UART0_S1&UART_S1_TDRE_MASK)
    {           
    	MMA8451_data[0]=MMA8451_ReadRegister(0x01);
    	MMA8451_data[1]=MMA8451_ReadRegister(0x02);
		
    	MMA8451_data[2]=MMA8451_ReadRegister(0x03);
    	MMA8451_data[3]=MMA8451_ReadRegister(0x04);
		
    	MMA8451_data[4]=MMA8451_ReadRegister(0x05);
    	MMA8451_data[5]=MMA8451_ReadRegister(0x06);

    	UART0_send_data(MMA8451_data,6);     
    }
  }    
}

//PIT interrupt handle
void pit_channel0_ISR(void)
{
	number++;	
	flag_100ms++;
	//SMG show number	
	SMG_show_data(show,number-1);	
	if(number==6)
		number=0;
	if(flag_100ms==1000)
	{
		flag_100ms=0;
		flag_measure=1;
	}
	/*Clear the flag of channel0,PIT*/
	PIT_TFLG0|=PIT_TFLG_TIF_MASK;
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
    uart0_isr,        //45
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
    pit_channel0_ISR,
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
    Default_Handler,  //87  PORTA Interrupt
    PORTB_Handler,    //88  PORTB Interrupt
    Default_Handler,  //89  PORTC Interrupt
    Default_Handler,  //90  PORTD Interrupt
    PORTE_Handler,	  //91  PORTE Interrupt
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,  //100
    Default_Handler,
    Default_Handler,
    Default_Handler,		
};
