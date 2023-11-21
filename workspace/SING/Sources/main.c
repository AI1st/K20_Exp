/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

#define PWM_CLK_FREQ 20970000
#define L1 M1*2 //low
#define L2 M2*2
#define L3 M3*2
#define L4 M4*2
#define L5 M5*2
#define L6 M6*2
#define L7 M7*2
#define M1 (unsigned short)(PWM_CLK_FREQ/523)/2 //middle
#define M2 (unsigned short)(PWM_CLK_FREQ/587)/2
#define M3 (unsigned short)(PWM_CLK_FREQ/659)/2
#define M4 (unsigned short)(PWM_CLK_FREQ/698)/2
#define M5 (unsigned short)(PWM_CLK_FREQ/784)/2
#define M6 (unsigned short)(PWM_CLK_FREQ/880)/2
#define M7 (unsigned short)(PWM_CLK_FREQ/988)/2
#define H1 M1/2 //high
#define H2 M2/2
#define H3 M3/2
#define H4 M4/2
#define H5 M5/2
#define H6 M6/2
#define H7 M7/2
#define NN 0 //stop

const unsigned short note[70]
//frequency
= {M3, M3, M4, M5,
M5, M4, M3, M2,
M1, M1, M2, M3,
M3, M2, M2,
M3, M3, M4, M5,
M5, M4, M3, M2,
M1, M1, M2, M3,
M2, M1, M1,
M2, M2, M3, M1,
M2, M3, M4, M3, M1,
M2, M3, M4, M3, M2,
M1, M2, L5, M3,
M3, M3, M4, M5,
M5, M4, M3, M4, M2,
M1, M1, M2, M3,
M2, M1, M1,
NN, 0xff};
const unsigned short duration[70]
//long
= {0x02,0x02,0x02,0x02,
0x02,0x02,0x02,0X02,
0x02,0x02,0x02,0X02,
0x03,0x01,0x04,
0x02,0x02,0x02,0x02,
0x02,0x02,0x02,0X02,
0x02,0x02,0x02,0X02,
0x03,0x01,0x04,
0x02,0x02,0x02,0x02,
0x02,0x01,0x01,0X02,0X02,
0x02,0x01,0x01,0X02,0X02,
0x02,0x02,0x02,0X02,
0x02,0x02,0x02,0x02,
0x02,0x02,0x02,0X01,0X01,
0x02,0x02,0x02,0X02,
0x03,0x01,0x04,
0x50, 0};

void delay(unsigned int number)
{
  unsigned short i,j,k;
  for(k=0;k<number;k++)
  {
    for(i=0;i<5000;i++)
    {
	  for(j=0;j<100;j++)
		  asm("nop");
   }
 }
}
void Beep_Init(void)
{
  //enable FTM2 clock
  SIM_SCGC3|=SIM_SCGC3_FTM2_MASK;
  SIM_SCGC5|=SIM_SCGC5_PORTB_MASK;
  
  //PTA13 is set to FTM2 pin
  PORTB_PCR18 = PORT_PCR_MUX(0x3);
  
}


//TPM1 module initialisation
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


int main(void)
{
	int freq, counter=0;	
	Beep_Init();
	FTM2_Init();	
	
	for(;;) {	   
		freq = note[counter];
		if(freq==0xff)
		{FTM2_SC = 0x00;
		 //counter=0;
		}
		else
		{
			Beep_setup(freq);
	   	    delay(duration[counter]);
	   	    counter++;
		}
	}
	
//	return 0;
}
