#include "derivative.h" /* include peripheral declarations */


void delay()
{  
	unsigned int i,j;
   for(i=0;i<5000;i++)  
{
  for(j=0;j<100;j++)		//Ƕ�׵�ѭ���壬��ʱ
   asm("nop");	
}
}

int main(void)
{
	//ͨ���߼�������1����Ӱ������λ��ʹ��PORTCʱ��
	   SIM_SCGC5|=0x800;   
	   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
	   PORTC_PCR2=0x100;	//����PTC2ΪGPIO
	   //PORTC_PCR2=PORT_PCR_MUX(1);
	   GPIOC_PDDR =0x04;   //����PTC2Ϊ��� 
	   //GPIOC_PDDR=GPIO_PIN(2); 
	   GPIOC_PDOR&=~0x04; //����PTC2Ϊ0��С�Ƶ��� 
	   //GPIOC_PDOR&=~GPIO_PIN(2);
	   for(;;){
	        delay();
	// ~Ϊ�߼�ȡ����Ҳ����GPIOD_PTOR�Ĵ�����ת�˿�
	        GPIOC_PDOR = ~ GPIOC_PDOR;	
	          }

}
