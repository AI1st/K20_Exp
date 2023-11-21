/*
 * LED.c
 *
 *  Created on: Mar 21, 2014
 *      Author: renpf
 */

#include <derivative.h>
#include <LED.h>

/*LED inital*/
void LED_Init()
{
	/*enable PORTB and PORTD  clock*/
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

//input parameter number:0x01--LED1;0x02----LED2;0x03----LED3;0x04---LED4
void LED_light(unsigned char number)
{
	switch(number)
	{
	     case 1:
	    		/*port out set to high*/
	    		GPIOC_PDOR=0XFFF;      //all dim
	    	    GPIOC_PDOR&=~(BIT0|BIT���j��dk��Ƶ�џ�SC�x��x���A$4&�:� >tOu�3Մ^�UehؓEҜS�n	k�����ݺ��ý���w�~��������p�yK�����sT$�V��6��旇(�6��[^�0\$�1��:b��c�I$,ꟺ��rPؠ����X������a�=~ux�������{F��:��;��oy�ܯ
�����㠎iEB�_�%x�P�t��[M1�ɉ_�������6e7��'�`4�sak��6�]G�JI���f�եQsG-W�C0n�5�^�����T�����i�MB����ݟ�P�6�SEwa�;AZ�+x��~Z+�� +��nt?��ZqQ�L�(g��>uz�C��c�hF���w�/d�A��Q<��=p����������`�>��y����$W�a��E�*�&�o��;*��~3��3���=x��Ȓo��c��U3u�;A�\�;����p"s5/�"J�!��zk�l�6��O0U���y�a7��w5��^X���N�a<�-�B$^x0�M�{�}F�]1�-Y0��Q�6k|h>ڻ�H<;�;T�q
�i�=aq���=�����Nn�!���Kt�GR�����8n�^tH��z�j]�E�\ eA\�RS+��a�HQ�~���},���|9���7�R>��V;S��0Q�JQO�?��uAe�i���qz�'��
��/YQ��.��9Wz AP��z�tC��,��a.�ǟ��[��@Y�&L0:Fؐ�I�×a��`�Ԟ�ƜT�2T�e>�&#���+�o�yE� 0{񽑸�a�>�ٙ�%Ps]�>�}&��b�a�굻Z.���VfNCl���kd���`��}����;��V�`O�;w��vdN�u�\�0�/���h�ӹw_���������6�b~��v��dNk<�*-�Sг��I������q
�a�Qh��&V�h:���z�?��S��ܶ�xj	B=��[)D��N�G�     case 0x02:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT6);  //GPIOC0--9--11  light	    	
    	         break;
        case 0x03:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT3);  //GPIOC0--9--11  light	    	
    	         break;
        case 0x04:
	             GPIOC_PDOR=0XFFF;      //all dim
                 GPIOC_PDOR&=~(BIT0);  //GPIOC0--9--11  light	    	
    	         break;
	    case 0x05:
    		     GPIOC_PDOR=0XFFF;      //all dim
    	         GPIOC_PDOR&=~(BIT10);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x06:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT7);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x07:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT4);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x08:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT1);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x09:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT11);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x0a:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT8);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x0b:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT5);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x0c:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT2);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x0d:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT3|BIT6|BIT9|BIT1|BIT4|BIT7|BIT10|BIT2|BIT5|BIT8|BIT11);  //GPIOC0--9--11  light	    	
	    	     break;
	/*    case 0x32:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT5);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x33:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT8);  //GPIOC0--9--11  light	    	
	    	     break;
	    case 0x34:
		         GPIOC_PDOR=0XFFF;      //all dim
	             GPIOC_PDOR&=~(BIT0|BIT3|BIT6|BIT9);  //GPIOC0--9--11  light	    	
	    	     break;  */
	    default: 
	    	     break;
	}
}
