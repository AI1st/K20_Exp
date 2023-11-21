
 /*
 * main implementation: use this 'C' sample to create your own application
 *
 */

//#include "LED.h"  /*LED configure*/
#include "derivative.h" /* include peripheral declarations */
#include "System.h" /* include peripheral declarations */

int main(void)
{
	LED_Init();	
	KEY_Init();
	EN_Init();

	for(;;)
			{
			
				int i;
				i=1;
				i=i++;
						}
			
}
