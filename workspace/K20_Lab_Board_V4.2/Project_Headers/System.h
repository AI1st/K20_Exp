/*
 * System.h
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_



void delayms(unsigned int number);
void enable_irq(int irq);
void EN_Init();
void KEY_Init();
void SMG_Init();
//SMG show data in show_data[]:0---5
void SMG_show_data(unsigned char show_data[],unsigned char number);


#endif /* SYSTEM_H_ */
