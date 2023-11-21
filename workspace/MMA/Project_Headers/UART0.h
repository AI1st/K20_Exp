/*
 * UART0.h
 *
 *  Created on: Aug 16, 2013
 *      Author: renpf
 */

#ifndef UART0_H_
#define UART0_H_

unsigned char uart0_getchar(void);
void UART0_SendChar(unsigned char data);
void UART0_send_data(unsigned char data[],unsigned char number);
unsigned char dtoa(unsigned char num);
void UART0_SendHex(unsigned char num); 
void UART0_Init();
#endif /* UART0_H_ */
