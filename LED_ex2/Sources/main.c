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
void iniled()
{
	PORTC_PCR0 = On;
	PORTC_PCR1 = On;
	PORTC_PCR2 = On;
	PORTC_PCR3 = On;
	PORTC_PCR4 = On;
	PORTC_PCR5 = On;
	PORTC_PCR6 = On;
	PORTC_PCR7 = On;
	PORTC_PCR8 = On;
	PORTC_PCR9 = On;
	PORTC_PCR10 = On;
	PORTC_PCR11 = On;
	
}
//void red()
//{
//	//ͨ���߼�������1����Ӱ������λ��ʹ��PORTCʱ�� 
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR0=On;	//����PTC2ΪGPIO
//		   PORTC_PCR1=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR2=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR3=On;	//����PTC2ΪGPIO
//		   PORTC_PCR4=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR5=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR6=On;	//����PTC2ΪGPIO
//		   PORTC_PCR7=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR8=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR9=On;	//����PTC2ΪGPIO
//		   PORTC_PCR10=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR11=Off;	//����PTC2ΪGPIO
//}
//void green()
//{
//	//ͨ���߼�������1����Ӱ������λ��ʹ��PORTCʱ�� 
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR1=On;	//����PTC2ΪGPIO
//		   PORTC_PCR0=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR2=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR4=On;	//����PTC2ΪGPIO
//		   PORTC_PCR5=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR3=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR7=On;	//����PTC2ΪGPIO
//		   PORTC_PCR8=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR6=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR10=On;	//����PTC2ΪGPIO
//		   PORTC_PCR11=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR9=Off;	//����PTC2ΪGPIO
//}
//void blue()
//{
//	//ͨ���߼�������1����Ӱ������λ��ʹ��PORTCʱ��
//		   //SIM_SCGC5|=SIM_SCGC5_PORTC_MASK;
//		   PORTC_PCR2=On;	//����PTC2ΪGPIO
//		   PORTC_PCR1=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR0=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR5=On;	//����PTC2ΪGPIO
//		   PORTC_PCR4=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR3=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR8=On;	//����PTC2ΪGPIO
//		   PORTC_PCR7=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR6=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR11=On;	//����PTC2ΪGPIO
//		   PORTC_PCR10=Off;	//����PTC2ΪGPIO
//		   PORTC_PCR9=Off;	//����PTC2ΪGPIO
//}
void red()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b110110110110;
}
void green()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b101101101101;
}
void blue()
{
	GPIOC_PDOR|= 0xFFF;
	GPIOC_PDOR&= 0b011011011011;
}
int main(void)
{
	//ͨ���߼�������1����Ӱ������λ��ʹ��PORTCʱ��
	   SIM_SCGC5|=0x3E00;   
       // GPIOC_PDOR&=~0xFFFF; //����PTC2Ϊ0��С�Ƶ��� (����~ҲЧ����ͬ��2ԭ���ϵ�ļĴ�����ʼ״̬Ϊȫ��)
	   iniled();
	   GPIOC_PDOR|= 0x0FFF;
	   //GPIOC_PDOR&=~GPIO_PIN(2);
	   //PORTC_PCR2=PORT_PCR_MUX(1);
	   GPIOC_PDDR =0x0FFF;   //����PTC2Ϊ��� 
	   //GPIOC_PDDR=GPIO_PIN(2); 
	   
	   for(;;){
		    //GPIOC_PDOR = ~ GPIOC_PDOR;
		    red();
		    delay();
		    delay();
		    green();
		    delay();
		    delay();
		    blue();
		    delay();
		    delay();
	        
	// ~Ϊ�߼�ȡ����Ҳ����GPIOD_PTOR�Ĵ�����ת�˿�
	        //GPIOC_PDOR = ~ GPIOC_PDOR;	
	          }

}
