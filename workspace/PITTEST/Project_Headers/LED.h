/*
 * LED.h
 *
 *  Created on: Jan 12, 2016
 *      Author: dell
 */

#ifndef LED_H_
#define LED_H_

#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10
#define BIT5  0x20
#define BIT6  0x40
#define BIT7  0x80
#define BIT8  0x100
#define BIT9  0x200
#define BIT10  0x400
#define BIT11  0x800
#define BIT12  0x1000
#define BIT13  0x2000
#define BIT14  0x4000
#define BIT15  0x8000
#define BIT16  0x10000
#define BIT17  0x20000
#define BIT18  0x40000
#define BIT19  0x80000

void LED_Init();
void LED_color(unsigned char LED_flag);

#endif /* LED_H_ */
