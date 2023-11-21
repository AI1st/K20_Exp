/*
 * Beep.h
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */

#ifndef BEEP_H_
#define BEEP_H_

void Beep_Init(void);
void FTM2_Init(void);
//setup the frequency of the beep
void Beep_setup(unsigned int count);

#endif /* BEEP_H_ */
