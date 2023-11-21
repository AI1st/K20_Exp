/*
 * common.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lenovo
 */


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
