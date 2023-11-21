/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
/*
 * 电子琴核心逻辑：
 * 1.读入键盘输入的变量(当没有读入时应该清零)
 * 2.将读入的变量放入(Beep_setup中)
 */
#include "derivative.h" /* include peripheral declarations */
#include "beep.h"
#include "common.h"
#include "key.h"
#include "digitron.h"

int press_key = 0;

int main(void)
{
	int freq, counter=0;	
	Beep_Init();
	FTM2_Init();	
	
	for(;;) {	   
//		freq = note[counter];
//		if(freq==0xff)
//		{FTM2_SC = 0x00;
//		 //counter=0;
//		}
//		else
//		{
//			Beep_setup(freq);
//	   	    delay(duration[counter]);
//	   	    counter++;
//		}
		if(!press_key){
			freq = freq_list[21];
			Beep_setup(freq);
		}
	}
}
