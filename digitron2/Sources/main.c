#include "derivative.h" /* include peripheral declarations */
#include "LED_CODE.h"   
#include "INKEY.h" 

unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};

// ��ʼ������flag��״̬
unsigned short encoding_flag = 0;
unsigned short input_flag = 0;
unsigned short input_flag2 = 0;
unsigned short add_flag = 0;

unsigned short temp = 0;
unsigned short input_num = 0;

unsigned short get_number(unsigned short encoding){
	unsigned short number;
	switch(encoding){
	case 0:
		number = 0;
	case 1:
		number = 1;
	case 2:
		number = 2;
	case 3:
		number = 3;
	case 4:
		number = 4;
	case 5:
		number = 5;
	case 6:
		number = 6;
	case 10:
		number = 7;
	case 11:
		number = 8;
	case 12:
		number = 9;
	default :
		number = 0;
	}
	return number;
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
		   display_number[i] = (number % (pointer*10)) / pointer;
		   pointer *= 10;
	   }
	   uint32_t Select_LED = Select_LED0;
	   for(i=1;i<=6;i++){
		   GPIOA_PDOR &= Select_LED; 
		   GPIOD_PDOR |= num[display_number[i]];
		   Select_LED += 1;
	   }
	}

void delay(void)
	{  
	   unsigned short i,j;
	   for(i=0;i<3000;i++) 
	      for(j=0;j<200; j++)
	         asm("nop");
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
	//Select_LED = Select_LED0;
	i=0;
	
//	//ע��:PORTA����ѡ��λ�ܣ�PORTD��������λ�ܴ���ֵ
//	//added
	GPIOA_PDOR |= 0x03F000;
	GPIOD_PDOR &= ~0xFF;  //init
	
	for(;;)
	{
		//1.�����߼�����
		if(input_flag & !input_flag2){
			//������1�����־λ1ʱ���û��������ֲ���ʾ����Ļ��
			input_flag = 0; //�����־λ
			current_number = current_number*10 + get_number(input_num);
			if(current_number>=1000000){
				current_number = current_number%1000000;
			}
		}
		else if(input_flag & input_flag2){
			//������2�����־λ1ʱ���û��������ֲ���ʾ����Ļ��
			input_flag = 0; //�����־λ
			number_to_be_added = number_to_be_added*10 + get_number(input_num);
			if(number_to_be_added>=1000000){
				number_to_be_added = number_to_be_added % 1000000;
			}
		}
		else if(add_flag & !number_to_be_added){
			//���ӷ���־Ϊ1ʱ����number_to_be_addedΪ��ʱ�������Ļ����input2_flag��1
			input_flag2 = 1;
		}
		else if(add_flag & number_to_be_added){
			//���ӷ���־Ϊ1ʱ����number_to_be_added��Ϊ��ʱ������current_number + number_to_be_added
			//����add_flag��־���㣬input_flag2����, number_to_be_added���㣬����ӷ���õ�������
			add_flag = 0;
			input_flag2 = 0;
			number_to_be_added = 0;
			current_number = current_number + number_to_be_added;
		}
		else{
			
		}
		
		//2.�������ʾ����
		if(!number_to_be_added){
			//������ļ���Ϊ0ʱ���������ʾ������current_number
			show_number(current_number);
		}
		else if(number_to_be_added){
			//������ļ�����Ϊ0ʱ���������ʾ����number_to_be_added
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
