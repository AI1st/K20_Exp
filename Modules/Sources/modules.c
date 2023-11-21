/*
 * modules.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Lenovo
 */
//1.初始化程序：

//1.1LED初始化程序
	void LED_Init()
	{
		/*enable PORTC clock*/
		SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
		
		/*portC0---11 was set to GPIO*/	
		PORTC_PCR0=PORT_PCR_MUX(0X1);	
		PORTC_PCR1=PORT_PCR_MUX(0X1);
		PORTC_PCR2=PORT_PCR_MUX(0X1);	
		PORTC_PCR3=PORT_PCR_MUX(0X1);
		PORTC_PCR4=PORT_PCR_MUX(0X1);	
		PORTC_PCR5=PORT_PCR_MUX(0X1);
		PORTC_PCR6=PORT_PCR_MUX(0X1);	
		PORTC_PCR7=PORT_PCR_MUX(0X1);	
		PORTC_PCR8=PORT_PCR_MUX(0X1);	
		PORTC_PCR9=PORT_PCR_MUX(0X1);
		PORTC_PCR10=PORT_PCR_MUX(0X1);	
		PORTC_PCR11=PORT_PCR_MUX(0X1);
			
		/*port set to out*/
		GPIOC_PDDR|=0XFFF;
		/*port out set to high*/
		GPIOC_PDOR=0XFFF;
	}


//1.2数码管初始化程序
	void LED_Disp_Init(void) 
	{
		SIM_SCGC5 |=(0x1000 | 0x0200);
		/*portA  set to GPIO*/	    
		PORTA_PCR12=0x100;
		PORTA_PCR13=0x100;
		PORTA_PCR14=0x100;
		PORTA_PCR15=0x100;
		PORTA_PCR16=0x100;
		PORTA_PCR17=0x100;
	
		/*portD  set to GPIO*/
		PORTD_PCR0 = 0x0100;
		PORTD_PCR1 = 0x0100;
		PORTD_PCR2 = 0x0100;
		PORTD_PCR3 = 0x0100;
		PORTD_PCR4 = 0x0100;
		PORTD_PCR5 = 0x0100;
		PORTD_PCR6 = 0x0100;		
		PORTD_PCR7 = 0x0100;
			
		/*LED bit pin set to out*/
		GPIOD_PDDR |=0x00FF;
		GPIOA_PDDR |=0x03F000;
		/*LED control pin set to high ,LEDs are closed*/
		GPIOA_PDOR |=0x03F000;
		/*LED bit pin set to high ,LED bit are all off, change GPIOD_PDOR register can change the number it shows*/
		GPIOD_PDOR = 0xFF;
	}


//1.3ADC初始化程序
	extern unsigned int ADC_Result;
	
	void ADC0_initial()
	{
		//ADC0 initial
			SIM_SCGC5|=SIM_SCGC5_PORTB_MASK;
			SIM_SCGC6|=SIM_SCGC6_ADC0_MASK;
			
			PORTB_PCR3=PORT_PCR_MUX(0X0);
			
			ADC0_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
			ADC0_SC3=ADC_SC3_ADCO_MASK; 
			ADC0_SC1A=ADC_SC1_ADCH(13);		 //potentiometers sensor path acquire	
	}
	
	void ADC1_initial()
	{
		/*enable PORTD and ADC1  clock*/
		SIM_SCGC5|=SIM_SCGC5_PORTE_MASK;
		SIM_SCGC3|=SIM_SCGC3_ADC1_MASK;
				
		//PTE0 and PTE1 configured as pin of ADC module
		PORTE_PCR0=PORT_PCR_MUX(0X0);
		PORTE_PCR1=PORT_PCR_MUX(0X0);
	
			
		//long sample time and single-end  8bit conversion
		ADC1_CFG1=ADC_CFG1_ADLSMP_MASK+ADC_CFG1_MODE(1);	
		
		//continuous conversions
		ADC1_SC3=ADC_SC3_ADCO_MASK; 
		
		//interrupt disable and select AD1_se4a channel as input		
		ADC1_SC1A=ADC_SC1_ADCH(4);		 //potentiometers sensor path acquire	
	}
	
	
	void ADC_Init()
	{
		ADC0_initial();
		ADC1_initial();
	}
	
	
	//change ADC channel
	void ADC_channel_temperature()
	{
		ADC1_SC1A=ADC_SC1_ADCH(5);		    //PTE1----temperature sensor
		
	}
	
	
	//change ADC channel
	void ADC_channel_potentiometer()
	{
		ADC1_SC1A=ADC_SC1_ADCH(4);		    //potentiometers sensor path acquire
	}
	
	

//2.中断初始化程序：
	
//2.0通用中断启用程序
	void enable_irq(int irq)
	{
		int div;
		/*Determinate which of the NVICISERs corresponds to the irq */
		div=irq/32;
		switch(div)
		{
		   case  0x0:
			   NVICICPR0=1<<(irq%32);
			   NVICISER0=1<<(irq%32);
			   break;
		   case  0x1:
			   NVICICPR1=1<<(irq%32);
			   NVICISER1=1<<(irq%32);
			   break;
		   case  0x2:
			   NVICICPR2=1<<(irq%32);
			   NVICISER2=1<<(irq%32);
			   break;		   
		}
	}
	
//2.1计时器中断初始化程序
	void PIT_init(unsigned int number_ms)
	{
		/*Trun on PIT clocks*/
		SIM_SCGC6|=SIM_SCGC6_PIT_MASK;
		
	    /*Enable PIT Module*/
		PIT_MCR&=~(PIT_MCR_MDIS_MASK);
		
		/*Setup the channel0 of PIT*/
		PIT_LDVAL0=20000*number_ms;
		
		/*Enable the IRQ of channel0,PIT*/
		PIT_TCTRL0|=PIT_TCTRL_TIE_MASK;
		
		/*Running channel0,PIT*/
		PIT_TCTRL0|=PIT_TCTRL_TEN_MASK;
		
	}
	
//3.单位功能模块
//3.1led亮灯程序
	void red_all()
	{
		GPIOC_PDOR|= 0xFFF;
		GPIOC_PDOR&= 0b110110110110;
	}
	void green_all()
	{
		GPIOC_PDOR|= 0xFFF;
		GPIOC_PDOR&= 0b101101101101;
	}
	void blue_all()
	{
		GPIOC_PDOR|= 0xFFF;
		GPIOC_PDOR&= 0b011011011011;
	}

//3.2数码管显示程序
	unsigned char num[10]={0xA0,0xBE,0x62,0x2A,0x3C,0x29,0x21,0xBA,0x20,0x28};
	void show_number(int *numbers)
		{  
		   uint32_t Select_LED = Select_LED0;
		   for(i=1;i<=6;i++){
			   GPIOA_PDOR |= 0x03F000;	
			   GPIOD_PDOR &= ~0xFF;
			   GPIOA_PDOR &= Select_LED; 
			   int m;
			   m= numbers[i-1];
			   GPIOD_PDOR |= num[m];
			   Select_LED = Select_LED<<1;
			   Select_LED += 1;
			   partial_delay(1);
		   }
		}
	
//3.3 ADC读取函数
	//anolog convert to digital
	unsigned int ADC1_TR_DATA()
	{
		//check convert complete flag 
		while((ADC1_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
			
		ADC_Result=ADC1_RA;
		
		//clear flag	   	
		ADC1_SC1A&=~ADC_SC1_COCO_MASK;
		
		return ADC_Result;
	
	}
	
	//anolog convert to digital
	unsigned int ADC0_TR_DATA()
	{
		//check convert complete flag 
		while((ADC0_SC1A&ADC_SC1_COCO_MASK)!=ADC_SC1_COCO_MASK);
			
		ADC_Result=ADC0_RA;
		
		//clear flag	   	
		ADC0_SC1A&=~ADC_SC1_COCO_MASK;
		
		return ADC_Result;
	}
	
	//data1 forward,data2 backward
	void data_to_array(unsigned int data1,unsigned int data2,unsigned char array[])
	{
		data1=data1&0xFF;
		data2>>=4;
		unsigned char i;
		for(i=0;i<3;i++)
		{		
			array[i]=data1%10;
			data1/=10;
		}
		for(i=3;i<6;i++)
		{		
			array[i]=data2%10;
			data2/=10;
		}
	}
	
//4.中断服务子程序模板
	
//4.1定时器中断服务子程序模板
	void pit_channel0_ISR(void)
	{
		//**************INSERT YOUR CODE******************
		
		//**************INSERT YOUR CODE******************
		/*Clear the flag of channel0,PIT*/
		PIT_TFLG0|=PIT_TFLG_TIF_MASK;
	}

//4.2按键中断服务子程序模板
	void PORTB_Handler()
	{
		partial_delay(500); //按键去抖
		if(PORTB_ISFR&0b100000000000000000)  //sw1  -  0
		    {
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 0;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 0;
					temp = 0;  
				}
		    }
		if(PORTB_ISFR& 0b10000000000000000)  //sw2  -  1
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 1;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 1;
					temp = 0;  //temp清零
				}
			}
		if(PORTB_ISFR&      0b100000000000)  //sw3  -  2
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 2;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 2;
					temp = 0;  //temp清零
				}
			}
		if(PORTB_ISFR&       0b10000000000)  //sw4  -  3
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 3;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 3;
					temp = 0;  //temp清零
				}
			}
		while((GPIOB_PDIR&0x030C00)!= 0x030C00){}
		PORTB_ISFR |= 0x0FFFFF;  //Clear ort B  flags
		
	}

	void PORTE_Handler()
	{
		partial_delay(500); //按键去抖
		if(PORTE_ISFR&0b100)     //sw5  -  4        //按键按下该位后中断标志为1 
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 4;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 4;
					temp = 0;  //temp清零
				}
			}
		if(PORTE_ISFR&0b1000)    //sw6  -  5       
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 5;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 5;
					temp = 0;  //temp清零
				}
			}
		if(PORTE_ISFR&0b10000)   //sw7  -  6        
			{
				if(encoding_flag==0){
					encoding_flag = 1;
					
					temp = 6;
				}
				else{
					encoding_flag = 0;
					input_flag = 1; //在main中需要清零
					
					input_num = temp*10 + 6;
					temp = 0;  //temp清零
				}
			}
		if(PORTE_ISFR&0b100000)  //sw8  -  +        
			{
				if(encoding_flag==0){
					add_flag = 1;  //在main中需要清零
				}
				else{
				}
			}
		while((GPIOE_PDIR&0x003C)!= 0x003C){}
		PORTE_ISFR |= 0x0000FF;  //Clear Port E  flags
	}
	

//5.其它模块
	
//5.1延时模块
	void delayms(unsigned int number)
	{
	  unsigned short i,j;
	  for(i=0;i<number;i++)
	  {
		  for(j=0;j<100;j++)
			  asm("nop");
	  }
	}
