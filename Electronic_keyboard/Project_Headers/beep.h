/*
 * beep.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Lenovo
 */

#ifndef BEEP_H_
#define BEEP_H_

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

const unsigned short freq_list[22]={
		L1,L2,L3,L4,L5,L6,L7,
		M1,M2,M3,M4,M5,M6,M7,
		H1,H2,H3,H4,H5,H6,H7,
		NN
};

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

void Beep_Init(void);
void FTM2_Init(void);
void Beep_setup(unsigned int count);

#endif /* BEEP_H_ */
