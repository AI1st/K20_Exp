#include "derivative.h" /* include peripheral declarations */
#include "LED_CODE.h"   
#include "INKEY.h" 

#define LED_off	0xFF 

unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};

// 初始化所有flag和状态
unsigned short encoding_flag = 0;
unsigned short input_flag = 0;
unsigned short input_flag2 = 0;
unsigned short add_flag = 0;

unsigned short temp = 0;
unsigned short input_num = 0;

unsigned short get_number(unsigned short encoding){
	unsigned short number;
	number = (encoding/10)*7 + encoding%10;
	return number;
}

void delay(void)
	{  
	   unsigned short i,j;
	   for(i=0;i<3000;i++) 
	      for(j=0;j<200; j++)
	         asm("nop");
	}

void partial_delay(int delay_t)
	{  
	   unsigned short i,j;
	   for(i=0;i<30*delay_t;i++) 
	      for(j=0;j<20; j++)
	         asm("nop");
	}

void show_number(int number)
	{  
//	   unsigned int tube0 = number % 10 / 1;
//	   unsigned int tube1 = number % 100 / 10;
//	   unsigned int tube2 = number % 1000 / 100;
//	   unsigned int tube2 = number % 10000 / 1000;
//	   unsigned int tube3 = number % 100000 / 10000;
//	   unsigned int tube4 = number % 100000 / 100000;
	   unsigned int display_number[6] = {0};
	   int pointer = 1;
	   int i;
	   for(i=1;i<=6;i++){
		   display_number[i-1] = (number % (pointer*10)) / pointer;
		   pointer *= 10;
	   }
	   uint32_t Select_LED = Select_LED0;
	   for(i=1;i<=6;i++){
		   GPIOA_PDOR |= 0x03F000;	//ѡ��λ��
		   GPIOD_PDOR &= ~0xFF;//ѡ������
//		   GPIOD_PDOR |= LED_off;
		   GPIOA_PDOR &= Select_LED; 
		   int m;
		   m= display_number[i-1];
		   GPIOD_PDOR |= num[m];
		   Select_LED = Select_LED<<1;
		   Select_LED += 1;
		   partial_delay(1);
		   //delay();
	   }
	}

int main(void)
{
	uint32_t Select_LED;
	
	unsigned int current_number = 0;
	unsigned int number_to_be_added = 0;
	unsigned short i;
	
	KEY_Init();
	EN_Init();
	LED_Disp_Init( );
	Select_LED = Select_LED0;
	i=0;
	
//	//注意:PORTA用于选数位管，PORTD用于向数位管传递值
//	//added
	GPIOA_PDOR |= 0x03F000;
	GPIOD_PDOR &= ~0xFF;  //init
	
	for(;;)
	{
		//1.变量逻辑部分
		
		if(add_flag && !number_to_be_added){
			//当加法标志为1时，且number_to_be_added为空时，清空屏幕，将input2_flag置1
			input_flag2 = 1;
			add_flag = 0;
		}
		else if(add_flag && number_to_be_added){
			//当加法标志为1时，且number_to_be_added不为空时，计算current_number + number_to_be_added
			//并将add_flag标志清零，input_flag2清零, number_to_be_added清零，输出加法后得到的数字
			add_flag = 0;
			input_flag2 = 0;
			current_number = current_number + number_to_be_added;
			number_to_be_added = 0;
		}
		else{
			
		}

		if(input_flag && !input_flag2){
			//当变量1输入标志位1时，用户输入数字并显示在屏幕上
			input_flag = 0; //清零标志位
			current_number = current_number*10 + get_number(input_num);
			if(current_number>=1000000){
				current_number = current_number%1000000;
			}
		}
		else if(input_flag && input_flag2){
			//当变量2输入标志位1时，用户输入数字并显示在屏幕上
			input_flag = 0; //清零标志位
			number_to_be_added = number_to_be_added*10 + get_number(input_num);
			if(number_to_be_added>=1000000){
				number_to_be_added = number_to_be_added % 1000000;
			}
		}
		
		//2.数码管显示部分
		if(!number_to_be_added){
			//当输入的加数为0时，数码管显示被加数current_number
			show_number(current_number);
		}
		else if(number_to_be_added){
			//当输入的加数不为0时，数码管显示加数number_to_be_added
			show_number(number_to_be_added);
		}
		

		
//		GPIOA_PDOR |= 0x03F000;	
//		GPIOD_PDOR &= ~0xFF;
		
//	//	GPIOD_PDOR |= LED_0;
//		GPIOD_PDOR |= num[i];	
//		GPIOA_PDOR &= Select_LED; 
//		delay();
//		Select_LED=Select_LED<<1;
//		Select_LED++;
//		if (Select_LED==0xFFFBFFFF)
//		{
//			Select_LED=Select_LED0;
//			i++;
//				if (i==10)
//					{
//						i=0;
//					}
//		}
	}
}
