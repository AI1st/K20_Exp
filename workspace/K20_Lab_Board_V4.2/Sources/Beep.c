/*
 * Beep.c
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */


#include <derivative.h>


//Beep initial
void Beep_Init(void)
{
  //enable FTM2 clock
  SIM_SCGC3|=SIM_SCGC3_FTM2_MASK;
  SIM_SCGC5|=SIM_SCGC5_PORTB_MASK;
  
  //PTA13 is set to FTM2 pin
  PORTB_PCR18 = PORT_PCR_MUX(0x3);
  
}


//TPM1 module initialization
void FTM2_Init(void)
{  
	FTM2_CNT = 0;
	FTM2_MOD = 0x2BC0;                                  //T
	FTM2_CNTIN=0x00;
	FTM2_SC = FTM_SC_CLKS(1);
	FTM2_C0SC = FTM_CnSC_ELSB_MASK+FTM_CnSC_MSB_MASK;   //
	//determine the Beep start or not
	FTM2_C0V = 0x00;     //initial	
}

//setup the frequency of the beep
void Beep_setup(unsigned int count)
{
	FTM2_MOD = count*2;                                      //T
	FTM2_C0V = count;                                    //initial	
}
