/*
 * ADC.h
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */

#ifndef ADC_H_
#define ADC_H_


void ADC_Init();
void ADC0_initial();
void ADC1_initial();
//anolog convert to digital
unsigned int ADC0_TR_DATA();
unsigned int ADC1_TR_DATA();
void ADC_channel_temperature();

//change ADC channel
void ADC_channel_potentiometer();
//data1 forward,data2 backward
void data_to_array(unsigned int data1,unsigned int data2,unsigned char array[]);
#endif /* ADC_H_ */
