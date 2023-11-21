/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "derivative.h" /* include peripheral declarations */
#include "System.h" /* include peripheral declarations */
#include "ADC.h" /* include peripheral declarations */
#include "UART0.h" /* include peripheral declarations */
#include "Beep.h" /* include peripheral declarations */
//#include "LED.h"  /*LED configure*/
#include "MMA8451Q.h"/*MMA8451Q */
#include "PIT.h"

unsigned int ADC_Result;
unsigned char MMA8451_XYZ_CFG;

unsigned char MMA8451_X_MSB,MMA8451_X_LSB;
unsigned char MMA8451_Y_MSB,MMA8451_Y_LSB;
unsigned char MMA8451_Z_MSB,MMA8451_Z_LSB;

unsigned int temperature_value,photo_value,ADC_value;

unsigned char show[6];
extern unsigned char flag_measure;

int main(void)
{
	LED_Init();	
	KEY_Init();
	SMG_Init();
	Beep_Init();
	ADC_Init();
	UART0_Init();
	FTM2_Init();
	PIT_init(0x01);  //1ms interval interrupt
	MMA8451_Init();  //initial MMA8451 g sensor
	EN_Init();
	
	for(;;)
	{	  
		//potentiometer control  beep
		ADC_channel_potentiometer();
		ADC_value=ADC1_TR_DATA();
		Beep_setup(ADC_value);
		if(flag_measure==1)
		{
			flag_measure=0;
		    //temperature sensor
		    ADC_channel_temperature();
		    delayms(0x01);
		    temperature_value=ADC1_TR_DATA();
	    	
		    photo_value=ADC0_TR_DATA();
		
		    //SMG show data store
		    data_to_array(temperature_value,photo_value,show);
		}		
	}
	
	return 0;
}
