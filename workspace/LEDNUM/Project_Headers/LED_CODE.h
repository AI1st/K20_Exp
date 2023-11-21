/*
 * LED_CODE.h
 *
 *  Created on: Dec 23, 2015
 *      Author: dell
 */

#ifndef LED_CODE_H_
#define LED_CODE_H_

                          // GCPDEAFB
#define LED_0	0xA0    // (0b10100000)
#define LED_1	0xBE    // (0b10111110)
#define LED_2	0x62    // (0b01100010)
#define LED_3	0x2A    // (0b10100000)
#define LED_4	0x3C    // (0b10111110)
#define LED_5	0x29    // (0b01100010)
#define LED_6	0x21    // (0b10100000)
#define LED_7	0xBA    // (0b10111110)
#define LED_8	0x20    // (0b01100010)
#define LED_9	0x28    // (0b10111110)
#define LED_-	0x7F    // (0b01100010)
#define LED_off	0xFF    // (0b01100010)

#define Select_LED0 	0xFFFFEFFF
#define Select_LED1	    0xFFFFDFFF
#define Select_LED2	    0xFFFFBFFF
#define Select_LED3 	0xFFFF7FFF
#define Select_LED4	    0xFFFEFFFF
#define Select_LED5	    0xFFFDFFFF

#endif /* LED_CODE_H_ */
