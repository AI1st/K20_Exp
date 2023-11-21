/*
** ###################################################################
**     Processors:          MK20DN512VLK10
**                          MK20DX256VLK10
**                          MK20DN512VLL10
**                          MK20DX256VLL10
**                          MK20DN512VLQ10
**                          MK20DX128VLQ10
**                          MK20DX256VLQ10
**                          MK20DN512VMB10
**                          MK20DX256VMB10
**                          MK20DN512VMC10
**                          MK20DX256VMC10
**                          MK20DN512VMD10
**                          MK20DX256VMD10
**                          MK20DX128VMD10
**
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K20P144M100SF2V2RM Rev. 2, Jun 2012
**     Version:             rev. 1.6, 2012-10-29
**
**     Abstract:
**         This header file implements peripheral memory map for MK20D10
**         processor.
**
**     Copyright: 1997 - 2012 Freescale, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2011-09-15)
**         Initial version
**     - rev. 1.1 (2012-01-10)
**         Registers updated according to the new reference manual revision - Rev. 1, Jan 2012
**     - rev. 1.2 (2012-03-26)
**         SDHC - removed bit group WRBRSTLEN from the SDHC_WML register.
**     - rev. 1.3 (2012-04-13)
**         Added new #define symbol MCU_MEM_MAP_VERSION_MINOR.
**         Added new #define symbols <peripheralType>_BASE_PTRS.
**     - rev. 1.4 (2012-07-09)
**         UART0 - Fixed register definition - CEA709.1-B (LON) registers added.
**     - rev. 1.5 (2012-10-23)
**         SIM - LLWU bit in SCGC4 register added.
**     - rev. 1.6 (2012-10-29)
**         Registers updated according to the new reference manual revision - Rev. 2, Jun 2012
**
** ###################################################################
*/

/**
 * @file MK20D10.h
 * @version 1.6
 * @date 2012-10-29
 * @brief Peripheral memory map for MK20D10
 *
 * This header file implements peripheral memory map for MK20D10 processor.
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MCU_MK20D10)  /* Check if memory map has not been already included */
#define MCU_MK20D10

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error MK20D10 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major versi�:J��K���b�qs�E��Y�oZV����F�rq�x�|���4�sZ�O0��_���*|T�h]����+��M����ո]�_8�Ù��jS�o
'bM.~�W�%�hW�����-��!�B�=ʮ.�C֓�*&� ��?X�B��5S	G���ޭ4R��b�}O���j�rM2�ޚ�4_wqNH�#��� ��d���M�y�Tѓ��3�O��(Pb\0�̲�mT�]���r%C�a� +�)͈+/B9v���sd���h(�o��O��-ʟhD�R�D{J^z~�f7}�!)s���	z]'�~�Y8.3[s���d|�a�7ƒ��^i�:�_��BG�Гa$��B�ukP�lI:-��\t���f/�7"9N꼏�TJ ��_��r��Z�J�U����B�	����O|�U���o���[��yLͨR��Q���Ҿ��հdڏLt��s*x�|��G��޲�����TI�j��G�@���T]�,���y$�fD�-��m���y��!�������4C�po<50�a�>XNu�3hV~j�[��K+�ڨX��z�=^T#�32KoO�Q��JhZMK���Z�l=�.f�6�f��#F_�Zk:N��Q��*]��ǸZS(��21}����G���?��C�E�$����W�_��#&C�;.P	x����3nJ�;ո6�'���1ְ�⸙k*���V"Z�T&�����aBJ�8�=����CYQ]�3�i8-�m�f:�S�I��ʦ8���12�2!P3��n3U9
��ۀ�YJn��3��q����z�����E9��Ȇ�<��n��[YEw������y�òċ�����e��@�ZSň#��<'���e���IH}"ΰ�akwh�����N+�^��8��8	}@�T���<M���;F��,$�w�e�"���n-[,��I����>�ۃ,E�F%���V��N�>�|��`�L�8WyK,�n�ҟ�N4�B!ה{�4wy��:�)Ԗ=�Kբ[��^��I����E���T6��4x,�^<Y �ؽ)��{����Խ�'�����C�bD0g*��v�؊�����ك�~����ўu3|�=V-$Y	X.9���A��?29��}�)Y�z
���%�[m��$�������n�"Z�ii���H���l�c��;}�k���v����,�i��<��/�\8� ��nF�K�,�*A	̒�G8(�7ײ]���OȤ�&��	qB��w��+R��}�G�G������Ց�Ttř�/o��p���!�;�\����5l*$�C�4Ђ9��]��Q�w�n�h�߳
k�U�Y���K�.)��v���YG�R"��S�m7�@9��ʒ��ل#��ov��ّ��Q�������Y�F�e]�kEU������sI`��N���W$-v�ߕ�B��T�U-�/VP"}-Qo���ޢ��**A�iP��y�	] ?����JN�}��Ճ2D�9?߶�űMN�9v��HbU��q��d�oޛƏ�����!��X#9p;v(%�����Wԫ�呮����s���7�G8��7�ʏ�C���G
SPf�k�u�r8���X� �&:#��s�����G�Ia�h�ɱb��S~����h�����xg����aP�H��4���5ϲ��)�2�t<}�9�"�&}��0ވ�؈mzY�����":I"$5nq���]��7DF!�Xc�A!I�f�ʮ#|���ٚ벂� ���˳�
��[����JYj�sX5�Ƴ�BY_��=;��1����}:Eq$��[��N�<��@���O�~>���@9�\[�N�!���e #O3���k����/B�5?F�}����>��?��H��(������+%ƦM�ו]p�
��f����/�WrN!�+`��&��T����վj<��/��֬B�����$\��uS�[� �NDā5����<�,�V�ѝR|����ǧ��I�J��kC'��D��✎j�&h�7Ǡ-��a�9����mOjZ�/q�"FS|��c@��u�-V�=_����^�]�+qK!������ؓU��o�3R�9�52�Q���Ѥ!,��� �5�LD�Sˎ	]	D�o��:� t��B��T8��%MZЏÖ�A���4� �U^]�Pƌˌ���M
i�y�nZ��p*U=ڨ|��Nᥪ�5�|+\���p)³��O6$�� �uFMNb*I`�[��˟�e4��O.�0��ٸk�Hμ����ݝ,�|*&���'�y#V�"���]�\�33���u�ǭ:�����W}�?�W���W��xT�"I�)�Ȳ<�i@���P���y�%���	�o%�+R"���tL�W �w+bV�s�mC7��_�Y�f��c�?V�ۄ���QV�ߑ��)h�fM�BT���l �7��Z�C'�3�eR,y�d�,U��h���q8���O���/�O��+�8X��z%������}�ڰ��k48��H��� Iܙ�ˎ0��ٰ����)�s���F���L��ZS���3fЬ�ih��u���SS� O3�'~�sm���U�Z��$_�ȶ�tm	�œ�UL�s_��^%��G���p����k�2�>�ĶGk���2o�MvY"��\JH���SE����l�5����c��5��7t��b:��˕��S�́�4�cO�����@2�Iu�a�E��O�����CQ���
��Ҳ���|���Z.�x�޻�*1�w���������W���M���H��ch��_u��B��n�"(7�����Q�kN�e�e<�Di0zQ�ɭa�! �B-\'��$����N� +KB5�VC����;z��?�>B6O"z���<����Y���O/�i�t|�]�8��]F�M�})��v�<"��G+J�p�q����_����Pq�1��}�a�7�����R���2��:��{F!(���T�6֭�Ne�`dt�@k����贍av�p���).W�����ߍ&��y�XτY9f�86���5hannel 8 Transfer Complete */
  INT_DMA9                     = 25,               /**< DMA Channel 9 Transfer Complete */
  INT_DMA10                    = 26,               /**< DMA Channel 10 Transfer Complete */
  INT_DMA11                    = 27,               /**< DMA Channel 11 Transfer Complete */
  INT_DMA12                    = 28,               /**< DMA Channel 12 Transfer Complete */
  INT_DMA13                    = 29,               /**< DMA Channel 13 Transfer Complete */
  INT_DMA14                    = 30,               /**< DMA Channel 14 Transfer Complete */
  INT_DMA15                    = 31,               /**< DMA Channel 15 Transfer Complete */
  INT_DMA_Error                = 32,               /**< DMA Error Interrupt */
  INT_MCM                      = 33,               /**< Normal Interrupt */
  INT_FTFL                     = 34,               /**< FTFL Interrupt */
  INT_Read_Collision           = 35,               /**< Read Collision Interrupt */
  INT_LVD_LVW             ��3�d}gӥ���gn.^h������yƈ,xf �
x:�D|2{��{���}p~�M�jbu��J���j���U�y/Y��.7i`�^���h���z)p��F�M�u�(|\ʈ �Tٕ�w��$��/%�����]ލ�鰏BlH(�6�a��ۊ9����r�����闉�Mӈ������0�{|o	h�����@@3Ӏ@����n�S<jCR���|˥�#���� ����X}U^�/+n�e4���:�2���v�OS����#�K�)᳝�3Jdϓ�n1�I���B� �o윜g
Weڂ����Tj��R�{�#0��n�\y��?F2,�cҷ]e�����_T宍�*ߌ����m2��G
�NK��Q3��,*A�����m�ύ�?28���ڈѸ���L�l�B��L�,Yt��%TuA� �F')��n}#�{���FO�T�i9�eĤd��^�9�^��o;Y%�f&��{_��ɔNa� �|��aZ��!���pNӦ�K|���'қb����J�4Lt!���a�m�]����^'�#�.H�S�t�SW���������.���[]hK�:��ǐ��@(�r��u�L�me��r�װ닙]���=isq�=�����@��������K^�唉\��X��C�ʊ|f"ˁ�Q�ʕLd�-�[M�~��L��@���	���:%��+������ʒ)�J��Zr��ᅸ���3��a���<ة����������7/IG����J� &_u�|ǐR7�~�|F�kS2z�z[ڏ�rL���EJ?�YFԍq�(�ꂤ:�!rԩ�lL�\MR)e��������^�t����s�����)�C)5���^ý��"=*s��e�Ϻ�%��_�����M�i���c�wʿ�Y���;o���4E�ǖ�����WT����Nf�k'��ϛ[ع��S��vAw�E�f�`�����Bʱ���՜��`�!�L0C���0�plΧSqߑspt *o
  IJT_CAN0_Rx_Warning    `  $� = 49,               /:*< CAN  �x warning interrupt */
  INT_CAN0_Wake_Ut          $  = 50,     �         /**< CAN0 wake"up interrupt!*/
  INT_I2S0_Tx                  = 51,( `(        "! /**< I2S0 |ranRmit iNderrurt */
  INT_I2S0_Rx                0 = 52,              �/**< I2S0 receive )lterrupt */*  INT_CAN1_ORed_Message_buffEr = u3,               /.*< CAN1 OR'f mm3sqge juffers interru�t *.
  INT_CAN1Bu{_Off      �      = 74,               /**< CAN1 Bus off mnterv}pt */
  INT_CAN1_Error           ! 0 = 55,               /**, CAN1 e�ror interrupt *
  INT[CAN1_Tx_Warning        ! ="56,               /**< CAN1 Tx warning interrupt */
  INT_CAN1_Rx_Warning          = 57,               /*+<�CAN1 Px warninf interrupt */  INT_CAN1_W�ke_Up             = 58,               /**< CAN1!w`ke up interrupt */
  INT_Reserved59               = 59,               /**< Reserve� interrupt 59 */
  INT_UART0_LON            "   = 60,               /**< ART0 L�N interrupt */
  INT_UART0_RXTX        $     = 61,               /**< UART0 Receive/Transmit interrupt */
  INT_UART0_ERR �      !       = 62,       $       /**< UART0 Error interrqpt */
  INT[UART1_RX]TX       (      = 63,               /**< UART1 Receive?�ransmit inteprupt */  INT_UABD1_ERR $          $   = 64,               /**< URT1 Mrror interrupt */
  INT_UART2_RX_TX              = 65,               /**< UART2 Receive/Transmit ioterrupd */
  INT_UART2_ERR       $    (   = 66,               /**< UAPT2 Ersor interpupt */
  HNT_UART3_RX_TX              = �7,               /**< UART3 Receive/Tranceit�interqept */
  IN�_UART3_ERR                = 68,               /**< UART3 Error interrupt J/
  INT_UART4_RX_TX              = 69,               '**< UART4 Receive/Transmit interrupt */
  INT_EART4_ERR    !           = 72.               /**< UART4 Error inter2upt(*/
  INT_U@RT5_RX_TX        ! 0   = 71,               /:*< U@RT5 Recuife/Tzansmit iNterrupt */
  INT_UERT5_ERR"               = 72,            0  /**<"UART7 Error inTerrupt */
  KNT_ADC8                     = 73,   !           /**< ADC0 interrupt */  INT_AT�1             ! 0   � = 74,"   �          /**4 ADC1 interrupt */
  IN\_CMP0        !             75,               /.*< CMp0 intersupt */
  INT_CMP1                    0= 76,               /j*< CMP1 inTerrupt */
  I^T_CMP2     "  (      "     = 77,               /**< CMP2 inderrupt */
  INP_FTM0 (              0    = 78,          (    /**< FTM0 fault, overflow and channels interrupt */
  INT_FTM1                     = 79,               /**< FTM1 fault, overflow and channels interrupt */
  INT_FTM2                     = 80,             ! /**< FTM2 fault,�overflow!`nd channeLs interrupt */
  INT_CIP                      = 81,$          (   /**< CMT interrupT */
( INT_RTC          `           = 82,          0    /**< RTC interrupt */
  INT_RTC_Seconds 0            = 83,               /**< RTC seconds interr5tt */
  INT_�IT0   $  $          (   = 84,           !   /:*< IT timer channel 0 interrupt */
  INT_PITq "         � (     � = 85,               /**< PIT timer`chafnel 1 in|erpupt */
  INT_PIT2 �  �   (            = 86,  !            /**< PIT timer cha�nel 2 interrqpt */
  INP_PIT3        $"       "�  = 87,               /**< PIT$timer channel 3 interrupt */  INT_PDB0            (       0= 88,(              /**< PDB0 Interr�pt */
 `INT_USB0  !                  = <9,     (         /**< USB0 interrupt */M
 �IOT_USBDCT                   = 90,      "        /.*< US@DCD Interrupt *-
  INT_Reserwed91"              = 99,               /**< Re{erved intgrrupt(91 */
  INT_Reserved92              != 92,   (           /**< ResErved interrupv 92 */
  INT_reserved93               = 93,               /**< Reserved interrupt 93 */
  INT_Reserved94     0         = 94,           0   /**< Reserved interrupt 94 */
  INT_Rererved95               = 95,   "   $       /*�< Reserved interrupt 95 */
  INT_SDHC                     = 96,               /**< SDHC Interpupt */
  INT_DAS0   (            (   �= 97,               /**< DAC0 interrupt */
  INT_DAC1                     = 98,               /**< DAC1 interrupt */
  INT_TSI0                     = 99,               /**< TSI0 Interrupt */
  INT_MCG                      = 100,              /**< MCG Interrupt */
  INT_LPTimer                  = 101,              /**< LPTimer interrupt */
  INT_Reserved102              = 102,              /**< Reserved interrupt 102 */
  INT_PORTA                    = 103,              /**< Port A interrupt */
  INT_PORTB                    = 104,              /**< Port B interrupt */
  INT_PORTC                    = 105,              /**< Port C interrupt */
  INT_PORTD                    = 106,              /**< Port D interrupt */
  INT_PORTE                    = 107,              /**< Port E interrupt */
  INT_Reserved108              = 108,              /**< Reserved interrupt 108 */
  INT_Reserved109              = 109,              /**< Reserved interrupt 109 */
  INT_SWI                      = 110,              /**< Software interrupt */
  INT_Reserrud111       0      =011�,(             /**< Reserve� interrup4 111 +/	
  INT_Reserved112            � = 112,              /**< Reserved ynterrupt 112 */
 $INT_Reserv%d113        0 0   = 113,             !/**< Reserved intdrrupt 113 */
  INT_Reserved114              = 11�,              /**< Recerted interrupt 914 */
  INT_Rmserved115              = 115,              /**< Reserved`interrupt 115 */
  INT_REserved116              = �16,              /**< Reserved interrurt 116 */
  INT_Reserved117      0       = 117, �         $  /**< Reserved hnterrupt 117 */
  INT�Reqerved118              = 118,              ** Reserved inteprupt 118 *o
  INT_Reserved119   $$       ( = 119               /**< Reserved inte�ru`t 119 */
} IPQInterruptIndex;

/**
 * @}
(*/ /* end of group Interrupt_vector_numbers (/�

/* ----,--------------------------------,-------------------�--/-----------m--
   -- Peripheral type dafines
   %---------�-----------------------------/---------------------------------- */

/**
 * @addtogroup Peripheral_defines Peripheral type defines
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Peripheral ADC
 * @{
 */

/** ADC - Peripheral register structure */
typedef struct ADC_MemMap {
  uint32_t SC1[2];                                 /**< ADC Status and Control Registers 1, array offset: 0x0, array step: 0x4 */
  uint32_t CFG1;                                   /**< ADC Configuration Register 1, offset: 0x8 */
  uint32_t CFG2;                                   /**< ADC Configuration Register 2, offset: 0xC */
  uint32_t R[2];                                   /**< ADC Data Result Register, array offset: 0x10, array step: 0x4 */
  uint32_t CV1;                                    /**< Compare Value Registers, offset: 0x18 */
  uint32_t CV2;                                    /**< Compare Value Registers, offset: 0x1C */
  uint32_t SC2;                                    /**< Status and Control Register 2, offset: 0x20 */
  uint32_t SC3;                                    /**< Status and Control Register 3, offset: 0x24 */
  uint32_t OFS;                                    /**< ADC Offset Correction Register, offset: 0x28 */
  uint32_t PG;                                     /**< ADC Plus-Side Gain Register, offset: 0x2C */
  uint32_t MG;                                     /**< ADC Minus-Side Gain Register, offset: 0x30 */
  uint32_t CLPD;                                   /**< ADC Plus-SY��fK�L'z����Ƶ��[� aJH-wnjբ��x�y��3=���mW;���A�"��K�}��9�P�Nm	-vW?Ò���X������uJ3&�a ��kTkR��{�۱2���pI��0o�5q��oHJ�~��=�'�7�X�tc������g�ș=
8�䌀�k�ǰxB^�J���y�{a���t��3��(��7
�a�*�6%`y�3Y�^z���.�|&4m�qIc2��J�k�gЎk�UK��d+@�*q�Awu��P���i����l!�" =<y�o�O�p��0b>��4QӰr�u�rfM���:�a_IV#���&��e.K%gK(Pa�X�����B�(L�Ei�D�G�Z^�"m�Y�ⷮ/�+L��ƒ���~�Տ�� x��j�EC����d�C��q
�ۗ��!G����"��6�C�~�R>��|�fb� ZS�����+���J2Vz�����ғ�i)݁�
0gW��V��>�q%p�%�)��/�(C�C�ڸԭƢ�F��{�20N��
C�g���������E��W�������n��-~	J-��e�����+)��4������0h�M��������ϩ��xJB��
i}1N��H���G�}ѱ1<{B�ã�����$�m|EߢH�Va�]W-bh%����LDo��c�1�@���V$A���,8٤�l�c!����[��ċ{��X��W����o���V�-g�4M@X+ ����7�x�g�Ӹz��Ę�����1�e]n��.�gY��MG k:E���:3��#�.AS4v=�NQ��l��::v�K����L�~}�)����\����V�<$s�t�ͻ�{�]�zg��O�>m_�BA}h�o��Z�*��9"��WnO�tA���F�lC�C� *�Xī+MW�p�����xp�c��p��ȉ��%`��5H��]��X�p����܌�y~�o�D7��C�=P1?�����b�Udm��=S�������p��y�eT�c��Ȋv6����=ֲ},��*��ʌ���`���<��HWj����P��S!#4�\��գ	�:���;����t��_|6R�]oL��Ͽ��	�|��ũ�K����;�_�Ƚ}���큪2�wp���
45�1��P�ʾ�}R�<�O��4�y?J�J��A�O�@z�C1q1S�����u>�y���u�.�u�r�3%�Tc�Q���i��ӕ��_�,���u�)4�\J��/4t�o`5fn"��e��[bu���.�:�1����/��-v\������G���I&�*��O�L���Gdr-�0�6Q�����w�
B�vPmQz2�迭�K��(l:��Ylh(���;�O�gX?Z���/���uE�O��{��q�pP�]�We�
rؗ�د��z#u���h����<�x����?Fwi�N9R|�W�&t�fx�VK�^)��/X L_���
-�g��ح��h�n�t6�2Q�B�U�ַ]���I�7�T�%�˙:�����I!(�2�K����W�ኍO��
�l�*�l��
������/
~c<Y���X�p���c��"7��ȱySk���U~]��E-�t�i�5�n�Q�b�W��M�M��鳾[%O.5bi!11�X#�)���}��W�o��OҺ���B���1��;Ε%�Ӛ���M�P�XP>?X����i;D�baZ��0+#ցX��p��߱�����#wAH�kJx�����-�yl7>�{��w�؇���ևq/,{#�"ܵhJڎ�zf�%b�!��+�K����:�ti��H��zjj8b�ʚ7���jҫ}{�<s�����P��������@�/z?��V>g��t8�&���	��x~"�<��w���H�H+7��_9�߅��^@z�e�Ͼ�<0�5f�pX�}�Zhb&�ظ����	�$����
��G�l��w��^_�ӲM��͂	���۝CE�)�'�d�W�%,?�w�+z��X�\�&N=ster accessor macros
 * @{
 */


/* ADC - Register accessors */
#define ADC_SC1_REG(base,index)                  ((base)->SC1[index])
#define ADC_CFG1_REG(base)                       ((base)->CFG1)
#define ADC_CFG2_REG(base)                       ((base)->CFG2)
#define ADC_R_REG(base,index)                    ((base)->R[index])
#define ADC_CV1_REG(base)                        ((base)->CV1)
#define ADC_CV2_REG(base)                        ((base)->CV2)
#define ADC_SC2_REG(base)                        ((base)->SC2)
#define ADC_SC3_REG(base)                        ((base)->SC3)
#define ADC_OFS_REG(base)                        ((base)->OFS)
#define ADC_PG_REG(base)                         ((base)->PG)
#define ADC_MG_REG(base)                         ((base)->MG)
#define ADC_CLPD_REG(base)                       ((base)->CLPD)
#define ADC_CLPS_REG(base)                       ((base)->CLPS)
#define ADC_CLP4_REG(base)                       ((base)->CLP4)
#define ADC_CLP3_REG(base)                       ((base)->CLP3)
#define ADC_CLP2_REG(base)                       ((base)->CLP2)
#define ADC_CLP1_REG(base)                       ((base)->CLP1)
#define ADC_CLP0_REG(base)                       ((base)->CLP0)
#define ADC_PGA_REG(base)                        ((base)->PGA)
#define ADC_CLMD_REG(base)                       ((base)->CLMD)
#define ADC_CLMS_REG(base)                       ((base)->CLMS)
#define ADC_CLM4_REG(base)                       ((base)->CLM4)
#define ADC_CLM3_REG(base)                       ((base)->CLM3)
#define ADC_CLM2_REG(base)                       ((base)->CLM2)
#define ADC_CLM1_REG(base)                       ((base)->CLM1)
#define ADC_CLM0_REG(base)                       ((base)->CLM0)

/**
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_$�댡[X�+��~Z�c��[ms�J��7|�M	*d"V�?B��M���aB��4�#�\��9�܁��G.<�0/��e�	���,�=�Z<��܋Rl����g8/"@lLK(����ۣA�3�ӂ���� m�xO�|ġ#�Ҟ���e��4rrw=�x2�( 'N���:̹��0�n���Ac��,L�6���`�����w�I2�5nՂr�I�%�����n����r�N�49�;L�.��y�ң����_I�����]�S��/[�j�� )qc�Y����$�7Ӄ�d�V�Qn�D3h!��H}FM!��*�k�\�6����a���h�� ���Cf��(��j� �b?=P�{i	ha�2/�U-7��~��&ND�:��fq��){va�<L�£��0~"�K�ņ�7�a�!	謖�D*��8�dZN���[��xZ~Gc�|�bQ�8�f�7vl{Z�c�~t�ԵH�L�[.>�V��/�V�7��8��Kux�3-Rz1��k0�ɂ ?j�аx�z�^���rM>cJ9�rF�g���_�Ȑ�v�zPVY.I]T�#�}����$U c�׊���I��3t�
r!|�*7�N�-�,o$� ����,��/�`@�3�cu������F��q�k}fZ�*q�v꿗���*(3��̤� 'Q&�3*M]���EPHE�?W��kN2��O�|FԬ�|<�}��jm��<pJ��0�(�/�T{O-l�`��=�۫}�L�k��Vd��������������c@U�Ag�t'g
o�o>��u��+.��D�K�Eg��D��b��z,����I�,�e%�nR4C��K�#�wO~d�*#*�D0C�r�4r���^����|C�B9�IXy�Tn��I[��_$ՅML���7:?D�
I>řr���15?����<��+NF=x�6��9^���'���䘉/�RF�vQ����!�4��X��T0YF�ϖxW��7)���3�Vqŷq��� t9 p=(�y����٦�(N���T2jԡ�����I�M��X����e�\XI�׉��E��=�WsU�%FUclض4_�9��^��@�Kӊ;�rJA�^�#��1���j@����\���i�N7<�yq^��H+7�#'�L(��T�1x��X��YK�k=I�_q>�3pq���=B������"SB�	%n��a�뺟���00-A�xʨ���'���
Ň_a5�0V7�v�D��E]�J
�#�W���^'"R,ɿ����"��|��g��(�<D�P�v��r��ߑk�Z댇�� o�43�K�J?������c>��D$5��oMYeɷ�lxqA��z��12'��>磙���wz3-����P���B!�����3���� !���(��?�>i7^�@��`�|�0J�����m>���-�˾��ŢL9��''��T���|���h��Ժ	�Bx�Cwc����6T*�%F�5r�ԀB���D��ݪ����Y�!E�P�5�iC��+q���Y$�NZ:a�k�@�	@��/_�p$	�,w�%���H	u�%�`u���-��,�A�'W����N�D��'`�����f�������0�U~-����﵎
O)Y'I �����ݪW�U��=�̺!1�����SE�5fT��pa�*�Noo�pƟi;C����`����	�����d�(��i�?2$x�
��D��7/�/�N~�p-/�Ɋ� ;-&ϟ�F��N���M����ۙ�N�v� ��9������{���m�C�f�l��g��4橁	� uO&t�d���_ݔ�<�l�v��(o��"������!S)�����S�>�9�t�^@��e���w8�E�(y���@L|6�[�a��lR@@P�9�S]C���I� 7��+������w�"=���g��"ϟ�Kǻ���}tM�@���t���������+�9�-5�t�m���ɣ��x-�Ǟ�f��ZY_ȎMASK                     0x10u
#define ADC_CFG2_MUXSEL_SHIFT                    4
/* R Bit Fields */
#define ADC_R_D_MASK                             0xFFFFu
#define ADC_R_D_SHIFT                            0
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK)
/* CV1 Bit Fields */
#define ADC_CV1_CV_MASK                          0xFFFFu
#define ADC_CV1_CV_SHIFT                         0
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV1_CV_SHIFT))&ADC_CV1_CV_MASK)
/* CV2 Bit Fields */
#define ADC_CV2_CV_MASK                          0xFFFFu
#define ADC_CV2_CV_SHIFT                         0
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CV2_CV_SHIFT))&ADC_CV2_CV_MASK)
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(xY �1p�5<�@7sI2PC�f �e��� �f���6��胄���Qn��j��y�S���ˡ�}UB����%����&Xt�N_��������%��T���Tu
0��P;��l�Aau[l�;���""9�>�g}T�B)S����GϾR@b�64 ��h=�#p
�#�����`�k� ��!�_{��?�����T6�;�j��I2X��d��� ;�zd�_�T�ڱ�����,=���0H+0�T��+jtV?�+��.�=�6o�ht"�7��޼��?��N���;0���Ĺ-ּՒ��bӭw��"O�R��%O��x���{E��	q��o{�O�b�xF� ���86��J����n%<�2[��>���:�Cw�)�qڛn��z��*X��Մ��9 t���FܔVӘ��Tdx��2����lJ���P���_����{f�����M(!�"�/(ɄMnu��EK�҄�z���'�p��E����㴼�0�Md3U{��܀��Y��gg�p��R�&?ԣ����.���1D�+!V��]L��I���2��qMs2��'���=DX�:�o|r$�l�|�!�@��<\���;h�]6)�oW]��d�?vC��s��i�1��5��0��,<,cB<֕�b�����s��k�y��hv0K�X`�U���%o�V�EZVC������8��л	�i��~k�*5j�K����h(�����1�<o��\�?]2ۄ�B ���n%�Q~�an�pX�:�� ��W@^��	u6iI���0��g���5�Q^\���C�z{�Lbd�_/�=��S����	�FŶNO��{������C���i�vꦱ�2�^0��;�rS���4\����r�Љ���Hl�p\E}���7F��J��4|�σC�"ڧ.nL�&'�s<u].����o#�S��%�ӌ=��l�	�п�����w9@f���X�� ��m$���� ����E�l炬p"�xTVHT                       2
#define ADC_SC3_ATCO_MASK                        0x8u
#degine ADC_SC3_ADCO_SH�FT                !      3
#defane ADC_SC3_CALF_MASK   $                    0x40u
#defije IDC_SC3_CALF_SHIFT   (    $    0   `     6
#defife AD_�C3_BAL_MaSK             (           0x80u
#define ADC_SC3_CAL_SHIFT                 �   `  7
/* OFS Cit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFF5
"d%fine �DC_OFS_OFS_SHIDT    �                   0
#define ADC_OfS_OFS(x)                           (((uhnd32_t)(((uint3�_t)(x))<<ADC_OFS_OFS_SHIfT))&ADCOFS_OFS_OESK)
/* PG Bit Fields */M
#define ADC_PG_PG_MASK             "             0xFFFFu�
#define(ADC_PG_PG_SHIFT      $                `  0
#define ADC_PG_PG(xi �    0                      (((uints2_t)(((uint32_t)(x)(<<ADCPG_PG_SHIFT))&ADC_PG_P�_EASK)J/" MG Bit Fiel`s */
#define ADB_MG_MG_MASK                           0xFFFFu
#define ATC_]G_MG_SHIFT              ( ( "       0
#devine ADC_MG_MG(p�                       "  �  (((uint32_t)(((uint3r_t)(x))<8ADC_MG_MG_sHIFT))&ADC_MG_MG_MAsK)
/* CLPD Bit Fields "/
#define ADC_CLPD_CLPD_MASK    $   `    (         0x3Fu
#dEfine C_CLPF_CLPDOSHIFT     0     $    `   ` 0
#define ADC_CLRD_CLPD(x)            ! !          (((ui~t33_t)(((uint32_t)(x))<<ADC_ALPD_CLPD_SIFT)	&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#dg�ine ADC_CLPS_CLPS_MASK              " $      0x3Fu
#define ADC_CMPS_CPS_SHINT                      0�#define IDC_CLPS_CLTS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPSALPs_MASK)
/* CLP4 Bit(Fields */
#define ADC_CLX4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC^CLP4_CLP4(x)                (    $   (((uint32_t)((�uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT)�&ALC_CLP4_CLP4_MASK)
/* CLP3 Bit fields */
#define ADC_CLP3_CLP3^MASJ        !   �         0x1FFu
#define ADC_CLP3_CLP3_SHIFT           0          0
#define ALCWCLP#�CLP3(x)           !             (((uint32_t)(((uint3_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Nields */
#ddfine ADC_CLP2_CLP2_MASK                       xFFu
#define ADC_CLP2CLP2_SHIFT        ! "           0
#define ADC_KLP2_CLP2(x)    !            $       (((uint32Ot)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADK_CLP2_CLP2_MASK)
/* CLP1 Bit Fi%lds */
#define A�C_CLP1_CLP1_MASK                "      0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#de�ine QD�_CLP1_CLP1(x)                         (((uint32Wt)(((uint32_t�(x))<<ADC_CLP1_CLP1_SHIFT))&AEC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
"defi~e ADC_CLQ0_CLP8_MASK0  !               !   0x3Fu
#ddfine ADC_CLP0_CP0_SHIGT$                     0
#Define ADC_SLQ_CLP0(x)  0           0          (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0CLP0_MASK)
/* PGA Bit Fieltq */
#define ADC_PWA_PAG_MASK                  !  (  0xF0040u
#define ADC_PGA_PGAG_S@IFT                       1
#define ADC_PA_PGAG(x)     0                    ((*uint32_t)(((uint33_t)(t))<<ADC_PGA_PGAG_SHIFT))&ADC_PGA_PGAG_MASK)
#define ADC_PGA_PGALPb_MASK                      0x100000u
#define ADC_PGA_PGALPb_SHIFT                     20
#define ADC_PGA_PGAEN_MASK                       0x800000u
#define ADC_PGA_PGAEN_SHIFT                      23
/* CLMD Bit Fields */
#define ADC_CLMD_CLMD_MASK                       0x3Fu
#define ADC_CLMD_CLMD_SHIFT                      0
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK)
/* CLMS Bit Fields */
#define ADC_CLMS_CLMS_MASK                       0x3Fu
#define ADC_CLMS_CLMS_SHIFT                      0
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK)
/* CLM4 Bit Fields */
#define ADC_CLM4_CLM4_MASK                       0x3FFu
#define ADC_CLM4_CLM4_SHIFT                      0
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK)
/* CLM3 Bit Fields */
#define ADC_CLM3_CLM3_MASK                       0x!FFu
#defInd ADC_CLM3_CLM3_SHIFT      `         �     0
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uift32_t)(x)�<<ADG_CLM3_CLM3_SHIFT)-&ADC_CLM3_CLM3_MASK)
/* CLM2 BIt F�elds */
#dufine ADCWCLM2_CDM2_MASK                      "0xFFu
#def�ne ADC_CLM2_CDM2_SHIFT     �   (           !0
#define ADC_CLM2_CLM2(x)                         (((uint32_t)((�uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MQSK)
/* CLM1 Bit Fields */�
#define�ADCCL1_CLM1_MASK  "                    0y7Fu
#define ADC_CLM1_C�1_SHIFT              !       0
#define ADC_CLM1_CLM1(h)                         (h(uint32_t)(((uint32_t)(x))<<DC_CLM1_CLM1_SHIFT))&ADC_CLM1_KlM1_MASK)
/* CLM0 Bit Fields */
#define ADC__LM4_CLM0_MASK                     ` 0x3Fu
#defibe ADC_CL�0_CLM0_SHIFT  `                   0
#define ADC_CLM0_CLM0(x)                         (((uint�2_t9(((uint32_t)(x/)<<ADC_C\M0_CLM0_SHIFT))&ADC_CLM0[CLM0_MASK)

/**
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC -0PeripheraL instance bq�e addresses *'
/** Peripheral ADC0 base pointer */
#define ADC0_BACE_PTR                       �    ((ADC_MemM�pPtr)0x4003B000u)
/** Peripheral ADC1 base pointer */
#define ADC1_BASE_PTR                            ((ADCWMemMapPtr)0x400BB000u)
/** Array initializer of ADC pe�ipheral ba3e pointers */
#deFine ADC_BACE_PTRS                       �    { ADC0_BASE_PTZ, ADC1�BASE_PTR }

+* �---------------------)----------------------------------------------------
   -- AFC - Reghst�r accesso2 macros
   -----------------�----------------m-----------------�---------------------- *o

/**
 *�@addtogroup ADC_ReeisTer_Acce{sor_Macros"ADC - ReGister accessor macros
 * @{
 *-*

/. ADC - RegiSper instance definitions */
/* ADC0 */
#define ADC0_SC1A          ( $        "!   !     ADC_SC1_REG(ADC0_BASE_PTR,0)
#define"EDC0_SC1B                            0   ADC_SC1_REG(@DC0_BASD_PTR,1)
#defioe ADC0_CFG1!                     (       ` ADB_CFE1[REG(ADC0_BASE_PTR)
#define DC0_BFG2                                ADC_CFG2_REC(ADC0_BASE_PTR)*#define ADC0_RA           `                      ADC_R_REG(ADC0_BASE_PTR-0)
#define ADC0_RC                                 `ADC_R_R��(ADC0_BASD_pTR,19
#define ADC0_CV1   "        !                    ADc_CV1_REG( DC0_BASE_PVR)
#define ADC0_CV2                                 ADC_CV2OREg(ADC0_BASE_PTR)
#define QDC0_SC2            $                 �  ADC_SC2_REG(ADC0_BASE_PTR)
#define ADC0_SC3                                 	DC_SB3_REG(ADC4_BASE_PTR)
#define ADC0_OFS                               "�IDC_OFS_REG(ADC0OBASE_XTR)
#dedine ADC0_PG                                  ADC_PG_REG(ADK0_BASE_PTR)
#ddfmne!ADC0_MG                            $     ADC_MG_REG(ADC0_BaSE_PTR)
#$efine ADC0_CLPD(                               ADC_CLPL_REG(ADC0_BA�E_PTR)
#define ADC0_CLPS                �            (  ADC_CLPS_RG(ALC0_BASE_PTR)
#lefine ATC0_C\P4                                AFC_CLX4_REG(ADC0_BA�E_PTR)
#define ADC2_CLP3                 0              ADC_C�P3_REG(ADC0_BASE_PTR-
#define ADC0_CL@2                         �      ADC_CLP2_REG(ADC0_BASE_PTR)
#define ADC0_CLP1                (      �     (  ADC_CLP1_REG(ATC0_BASE_PTR)
#define ADC0_CLP0                "           �   aDC_CLP0_REG(ADC0_BASE_PTR)
#define ADC0_PGA                                 ADC_PGA_REG(ADC0_BASE_PTR)
#define ADC0_CLMD          "             0�      A�C_CLMD_REG(ADC0_BASE_PTR)
#defife ADC0^CLMS                                ALC_CLMS_REG(ADC0_BASE_PTR)
c�efine ATC0_CLM4"                      0$       A@C_ClM4_REG(AFC0_BASE_PTR)
#define ADC0_CLM3                        `  0    ADC_CLM3^REG(AC0_BASE_PTR)
#defkne ADC0_CLM2                $0            ( ADC_CLM2_REG(@tC0_BASE_RtR)#define ADC0_CLM1"    !                 "0       ADC^CLM1_REG(ADC0_BASE_PTR)*#devine ADC0_CLM0                      �         ADC_CLM0_REG(ADC1_BASE_PTR)
/* ADC� */
#define ADC1]SC1A         !                 �    ADC_SC1_REG(ADC1_BASE_PTR,0)
#define ADC1_SC1B                                ADC_SC1_REG(ADC1_BASE_PTR,1)
#define ADC1_CFG1                                ADC_CFG1_REG(ADC1_BASE_PTR)
#define ADC1_CFG2                                ADC_CFG2_REG(ADC1_BASE_PTR)
#define ADC1_RA                                  ADC_R_REG(ADC1_BASE_PTR,0)
#define ADC1_RB                                  ADC_R_REG(ADC1_BASE_PTR,1)
#define ADC1_CV1                                 ADC_CV1_REG(ADC1_BASE_PTR)
#define ADC1_CV2                                 ADC_CV2_REG(ADC1_BASE_PTR)
#define ADC1_SC2                                 ADC_SC2_REG(ADC1_BASE_PTR)
#define ADC1_SC3                                 ADC_SC3_REG(ADC1_BASE_PTR)
#define ADC1_OFS                                 ADC_OFS_REG(ADC1_BASE_PTR)
#define ADC1_PG                                  ADC_PG_REG(ADC1_BASE_PTR)
#define ADC1_MG                                  ADC_MG_REG(ADC1_BASE_PTR)
#define ADC1_CLPD                                ADC_CLPD_REG(ADC1_BASE_PTR)
#define ADC1_CLPS                                ADC_CLPS_REG(ADC1_BASE_PTR)
#define ADC1_CLP4                                ADC_CLP4_REG(ADC1_BASE_PTR)
#define ADC1_CLP3                                ADC_CLP3_REG(ADC1_BASE_PTR)
#define ADC1_CLP2                                ADC_CLP2_REG(ADC1_BASE_PTR)
#define ADC1_CLP1                                ADC_CLP1_REG(ADC1_BASE_PTR)
#define ADC1_CLP0                                ADC_CLP0_REG(ADC1_BASE_PTR)
#define ADC1_PGA                                 ADC_PGA_REG(ADC1_BASE_PTR)
#define ADC1_CLMD                                ADC_CLMD_REG(ADC1_BASE_PTR)
#define ADC1_CLMS                                ADC_CLMS_REG(ADC1_BASE_PTR)
#define ADC1_CLM4                                ADC_CLM4_REG(ADC1_BASE_PTR)
#define ADC1_CLM3                                ADC_CLM3_REG(ADC1_BASE_PTR)
#define ADC1_CLM2                                ADC_CLM2_REG(ADC1_BASE_PTR)
#define ADC1_CLM1                                ADC_CLM1_REG(ADC1_BASE_PTR)
#define ADC1_CLM0                                ADC_CLM0_REG(ADC1_BASE_PTR)

/* ADC - Register array accessors */
#define ADC0_SC1(index)                          ADC_SC1_REG(ADC0_BASE_PTR,index)
#define ADC1_SC1(index)                          ADC_SC1_REG(ADC1_BASE_PTR,index)
#define ADC0_R(index)                            ADC_R_REG(ADC0_BASE_PTR,index)
#define ADC1_R(index)                            ADC_R_REG(ADC1_BASE_PTR,index)

/**
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ADC_Peripheral */


/* ----------------------------------------------------------------------------
   -- AIPS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Peripheral AIPS
 * @{
 */

/** AIPS - Peripheral register structure */
typedef struct AIPS_MemMap {
  uint32_t MPRA;                                   /**< Master Privilege Register A, offset: 0x0 */
  uint8_t RESERVED_0[28];
  uint32_t PACRA;                                  /**< Peripheral Access Control Register, offset: 0x20 */
  uint32_t PACRB;                                  /**< Peripheral Access Control Register, offset: 0x24 */
  uint32_t PACRC;                                  /**< Peripheral Access Control Register, offset: 0x28 */
  uint32_t PACRD;                                  /**< Peripheral Access Control Register, offset: 0x2C */
  uint8_t RESERVED_1[16];
  uint32_t PACRE;                                  /**< Peripheral Access Control Register, offset: 0x40 */
  uint32_t PACRF;                                  /**< Peripheral Access Control Register, offset: 0x44 */
  uint32_t PACRG;                                  /**< Peripheral Access Control Register, offset: 0x48 */
  uint32_t PACRH;                                  /**< Peripheral Access Control Register, offset: 0x4C */
  uint32_t PACRI;                                  /**< Peripheral Access Control Register, offset: 0x50 */
  uint32_t PACRJ;                                  /**< Peripheral Access Control Register, offset: 0x54 */
  uint32_t PACRK;                                  /**< Peripheral Access Control Register, offset: 0x58 */
  uint32_t PACRL;                                  /**< Peripheral Access Control Register, offset: 0x5C */
  uint32_t PACRM;                                  /**< Peripheral Access Control Register, offset: 0x60 */
  uint32_t PACRN;                                  /**< Peripheral Access Control Register, offset: 0x64 */
  uint32_t PACRO;                                  /**< Peripheral Access Control Register, offset: 0x68 */
  uint32_t PACRP;                                  /**< Peripheral Access Control Register, offset: 0x6C */
} volatile *AIPS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros
 * @{
 */


/* AIPS - Register accessors */
#define AIPS_MPRA_REG(base)                      ((base)->MPRA)
#define AIPS_PACRA_REG(base)                     ((base)->PACRA)
#define AIPS_PACRB_REG(base)                     ((base)->PACRB)
#define AIPS_PACRC_REG(base)                     ((base)->PACRC)
#define AIPS_PACRD_REG(base)                     ((base)->PACRD)
#define AIPS_PACRE_REG(base)                     ((base)->PACRE)
#define AIPS_PACRF_REG(base)                     ((base)->PACRF)
#define AIPS_PACRG_REG(base)                     ((base)->PACRG)
#define AIPS_PACRH_REG(base)                     ((base)->PACRH)
#define AIPS_PACRI_REG(base)                     ((base)->PACRI)
#define AIPS_PACRJ_REG(base)                     ((base)->PACRJ)
#define AIPS_PACRK_REG(base)                     ((base)->PACRK)
#define AIPS_PACRL_REG(base)                     ((base)->PACRL)
#define AIPS_PACRM_REG(base)                     ((base)->PACRM)
#define AIPS_PACRN_REG(base)                     ((base)->PACRN)
#define AIPS_PACRO_REG(base)                     ((base)->PACRO)
#define AIPS_PACRP_REG(base)                     ((base)->PACRP)

/**
 * @}
 */ /* end of group AIPS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Masks AIPS Register Masks
 * @{
 */

/* MPRA Bit Fields */
#define AIPS_MPRA_MPL5_MASK                      0x100u
#define AIPS_MPRA_MPL5_SHIFT                     8
#define AIPS_MPRA_MTW5_MASK                      0x200u
#define AIPS_MPRA_MTW5_SHIFT                     9
#define AIPS_MPRA_MTR5_MASK                      0x400u
#define AIPS_MPRA_MTR5_SHIFT                     10
#define AIPS_MPRA_MPL4_MASK                      0x1000u
#define AIPS_MPRA_MPL4_SHIFT                     12
#define AIPS_MPRA_MTW4_MASK                      0x2000u
#define AIPS_MPRA_MTW4_SHIFT                     13
#define AIPS_MPRA_MTR4_MASK                      0x4000u
#define AIPS_MPRA_MTR4_SHIFT                     14
#define AIPS_MPRA_MPL3_MASK                      0x10000u
#define AIPS_MPRA_MPL3_SHIFT                     16
#define AIPS_MPRA_MTW3_MASK                      0x20000u
#define AIPS_MPRA_MTW3_SHIFT                     17
#define AIPS_MPRA_MTR3_MASK                      0x40000u
#define AIPS_MPRA_MTR3_SHIFT                     18
#define AIPS_MPRA_MPL2_MASK                      0x100000u
#define AIPS_MPRA_MPL2_SHIFT                     20
#define AIPS_MPRA_MTW2_MASK                      0x200000u
#define AIPS_MPRA_MTW2_SHIFT                     21
#define AIPS_MPRA_MTR2_MASK                      0x400000u
#define AIPS_MPRA_MTR2_SHIFT                     22
#define AIPS_MPRA_MPL1_MASK                      0x1000000u
#define AIPS_MPRA_MPL1_SHIFT                     24
#define AIPS_MPRA_MTW1_MASK                      0x2000000u
#define AIPS_MPRA_MTW1_SHIFT                     25
#define AIPS_MPRA_MTR1_MASK                      0x4000000u
#define AIPS_MPRA_MTR1_SHIFT                     26
#define AIPS_MPRA_MPL0_MASK                      0x10000000u
#define AIPS_MPRA_MPL0_SHIFT                     28
#define AIPS_MPRA_MTW0_MASK                      0x20000000u
#define AIPS_MPRA_MTW0_SHIFT                     29
#define AIPS_MPRA_MTR0_MASK                      0x40000000u
#define AIPS_MPRA_MTR0_SHIFT                     30
/* PACRA Bit Fields */
#define AIPS_PACRA_TP7_MASK                      0x1u
#define AIPS_PACRA_TP7_SHIFT                     0
#define AIPS_PACRA_WP7_MASK                      0x2u
#define AIPS_PACRA_WP7_SHIFT                     1
#define AIPS_PACRA_SP7_MASK                      0x4u
#define AIPS_PACRA_SP7_SHIFT                     2
#define AIPS_PACRA_TP6_MASK                      0x10u
#define AIPS_PACRA_TP6_SHIFT                     4
#define AIPS_PACRA_WP6_MASK                      0x20u
#define AIPS_PACRA_WP6_SHIFT                     5
#define AIPS_PACRA_SP6_MASK                      0x40u
#define AIPS_PACRA_SP6_SHIFT                     6
#define AIPS_PACRA_TP5_MASK                      0x100u
#define AIPS_PACRA_TP5_SHIFT                     8
#define AIPS_PACRA_WP5_MASK                      0x200u
#define AIPS_PACRA_WP5_SHIFT                     9
#define AIPS_PACRA_SP5_MASK                      0x400u
#define AIPS_PACRA_SP5_SHIFT                     10
#define AIPS_PACRA_TP4_MASK                      0x1000u
#define AIPS_PACRA_TP4_SHIFT                     12
#define AIPS_PACRA_WP4_MASK                      0x2000u
#define AIPS_PACRA_WP4_SHIFT                     13
#define AIPS_PACRA_SP4_MASK                      0x4000u
#define AIPS_PACRA_SP4_SHIFT                     14
#define AIPS_PACRA_TP3_MASK                      0x10000u
#define AIPS_PACRA_TP3_SHIFT                     16
#define AIPS_PACRA_WP3_MASK                      0x20000u
#define AIPS_PACRA_WP3_SHIFT                     17
#define AIPS_PACRA_SP3_MASK                      0x40000u
#define AIPS_PACRA_SP3_SHIFT                     18
#define AIPS_PACRA_TP2_MASK                      0x100000u
#define AIPS_PACRA_TP2_SHIFT                     20
#define AIPS_PACRA_WP2_MASK                      0x200000u
#define AIPS_PACRA_WP2_SHIFT                     21
#define AIPS_PACRA_SP2_MASK                      0x400000u
#define AIPS_PACRA_SP2_SHIFT                     22
#define AIPS_PACRA_TP1_MASK                      0x1000000u
#define AIPS_PACRA_TP1_SHIFT                     24
#define AIPS_PACRA_WP1_MASK                      0x2000000u
#define AIPS_PACRA_WP1_SHIFT                     25
#define AIPS_PACRA_SP1_MASK                      0x4000000u
#define AIPS_PACRA_SP1_SHIFT                     26
#define AIPS_PACRA_TP0_MASK                      0x10000000u
#define AIPS_PACRA_TP0_SHIFT                     28
#define AIPS_PACRA_WP0_MASK                      0x20000000u
#define AIPS_PACRA_WP0_SHIFT                     29
#define AIPS_PACRA_SP0_MASK                      0x40000000u
#define AIPS_PACRA_SP0_SHIFT                     30
/* PACRB Bit Fields */
#define AIPS_PACRB_TP7_MASK                      0x1u
#define AIPS_PACRB_TP7_SHIFT                     0
#define AIPS_PACRB_WP7_MASK                      0x2u
#define AIPS_PACRB_WP7_SHIFT                     1
#define AIPS_PACRB_SP7_MASK                      0x4u
#define AIPS_PACRB_SP7_SHIFT                     2
#define AIPS_PACRB_TP6_MASK                      0x10u
#define AIPS_PACRB_TP6_SHIFT                     4
#define AIPS_PACRB_WP6_MASK                      0x20u
#define AIPS_PACRB_WP6_SHIFT                     5
#define AIPS_PACRB_SP6_MASK                      0x40u
#define AIPS_PACRB_SP6_SHIFT                     6
#define AIPS_PACRB_TP5_MASK                      0x100u
#define AIPS_PACRB_TP5_SHIFT                     8
#define AIPS_PACRB_WP5_MASK                      0x200u
#define AIPS_PACRB_WP5_SHIFT                     9
#define AIPS_PACRB_SP5_MASK                      0x400u
#define AIPS_PACRB_SP5_SHIFT                     10
#define AIPS_PACRB_TP4_MASK                      0x1000u
#define AIPS_PACRB_TP4_SHIFT                     12
#define AIPS_PACRB_WP4_MASK                      0x2000u
#define AIPS_PACRB_WP4_SHIFT                     13
#define AIPS_PACRB_SP4_MASK                      0x4000u
#define AIPS_PACRB_SP4_SHIFT                     14
#define AIPS_PACRB_TP3_MASK                      0x10000u
#define AIPS_PACRB_TP3_SHIFT                     16
#define AIPS_PACRB_WP3_MASK                      0x20000u
#define AIPS_PACRB_WP3_SHIFT                     17
#define AIPS_PACRB_SP3_MASK                      0x40000u
#define AIPS_PACRB_SP3_SHIFT                     18
#define AIPS_PACRB_TP2_MASK                      0x100000u
#define AIPS_PACRB_TP2_SHIFT                     20
#define AIPS_PACRB_WP2_MASK                      0x200000u
#define AIPS_PACRB_WP2_SHIFT                     21
#define AIPS_PACRB_SP2_MASK                      0x400000u
#define AIPS_PACRB_SP2_SHIFT                     22
#define AIPS_PACRB_TP1_MASK                      0x1000000u
#define AIPS_PACRB_TP1_SHIFT                     24
#define AIPS_PACRB_WP1_MASK                      0x2000000u
#define AIPS_PACRB_WP1_SHIFT                     25
#define AIPS_PACRB_SP1_MASK                      0x4000000u
#define AIPS_PACRB_SP1_SHIFT                     26
#define AIPS_PACRB_TP0_MASK                      0x10000000u
#define AIPS_PACRB_TP0_SHIFT                     28
#define AIPS_PACRB_WP0_MASK                      0x20000000u
#define AIPS_PACRB_WP0_SHIFT                     29
#define AIPS_PACRB_SP0_MASK                      0x40000000u
#define AIPS_PACRB_SP0_SHIFT                     30
/* PACRC Bit Fields */
#define AIPS_PACRC_TP7_MASK                      0x1u
#define AIPS_PACRC_TP7_SHIFT                     0
#define AIPS_PACRC_WP7_MASK                      0x2u
#define AIPS_PACRC_WP7_SHIFT                     1
#define AIPS_PACRC_SP7_MASK                      0x4u
#define AIPS_PACRC_SP7_SHIFT                     2
#define AIPS_PACRC_TP6_MASK                      0x10u
#define AIPS_PACRC_TP6_SHIFT                     4
#define AIPS_PACRC_WP6_MASK                      0x20u
#define AIPS_PACRC_WP6_SHIFT                     5
#define AIPS_PACRC_SP6_MASK                      0x40u
#define AIPS_PACRC_SP6_SHIFT                     6
#define AIPS_PACRC_TP5_MASK                      0x100u
#define AIPS_PACRC_TP5_SHIFT                     8
#define AIPS_PACRC_WP5_MASK                      0x200u
#define AIPS_PACRC_WP5_SHIFT                     9
#define AIPS_PACRC_SP5_MASK                      0x400u
#define AIPS_PACRC_SP5_SHIFT                     10
#define AIPS_PACRC_TP4_MASK                      0x1000u
#define AIPS_PACRC_TP4_SHIFT                     12
#define AIPS_PACRC_WP4_MASK                      0x2000u
#define AIPS_PACRC_WP4_SHIFT                     13
#define AIPS_PACRC_SP4_MASK                      0x4000u
#define AIPS_PACRC_SP4_SHIFT                     14
#define AIPS_PACRC_TP3_MASK                      0x10000u
#define AIPS_PACRC_TP3_SHIFT                     16
#define AIPS_PACRC_WP3_MASK                      0x20000u
#define AIPS_PACRC_WP3_SHIFT                     17
#define AIPS_PACRC_SP3_MASK                      0x40000u
#define AIPS_PACRC_SP3_SHIFT                     18
#define AIPS_PACRC_TP2_MASK                      0x100000u
#define AIPS_PACRC_TP2_SHIFT                     20
#define AIPS_PACRC_WP2_MASK                      0x200000u
#define AIPS_PACRC_WP2_SHIFT                     21
#define AIPS_PACRC_SP2_MASK                      0x400000u
#define AIPS_PACRC_SP2_SHIFT                     22
#define AIPS_PACRC_TP1_MASK                      0x1000000u
#define AIPS_PACRC_TP1_SHIFT                     24
#define AIPS_PACRC_WP1_MASK                      0x2000000u
#define AIPS_PACRC_WP1_SHIFT                     25
#define AIPS_PACRC_SP1_MASK                      0x4000000u
#define AIPS_PACRC_SP1_SHIFT                     26
#define AIPS_PACRC_TP0_MASK                      0x10000000u
#define AIPS_PACRC_TP0_SHIFT                     28
#define AIPS_PACRC_WP0_MASK                      0x20000000u
#define AIPS_PACRC_WP0_SHIFT                     29
#define AIPS_PACRC_SP0_MASK                      0x40000000u
#define AIPS_PACRC_SP0_SHIFT                     30
/* PACRD Bit Fields */
#define AIPS_PACRD_TP7_MASK                      0x1u
#define AIPS_PACRD_TP7_SHIFT                     0
#define AIPS_PACRD_WP7_MASK                      0x2u
#define AIPS_PACRD_WP7_SHIFT                     1
#define AIPS_PACRD_SP7_MASK                      0x4u
#define AIPS_PACRD_SP7_SHIFT                     2
#define AIPS_PACRD_TP6_MASK                      0x10u
#define AIPS_PACRD_TP6_SHIFT                     4
#define AIPS_PACRD_WP6_MASK                      0x20u
#define AIPS_PACRD_WP6_SHIFT                     5
#define AIPS_PACRD_SP6_MASK                      0x40u
#define AIPS_PACRD_SP6_SHIFT                     6
#define AIPS_PACRD_TP5_MASK                      0x100u
#define AIPS_PACRD_TP5_SHIFT                     8
#define AIPS_PACRD_WP5_MASK                      0x200u
#define AIPS_PACRD_WP5_SHIFT                     9
#define AIPS_PACRD_SP5_MASK                      0x400u
#define AIPS_PACRD_SP5_SHIFT                     10
#define AIPS_PACRD_TP4_MASK                      0x1000u
#define AIPS_PACRD_TP4_SHIFT                     12
#define AIPS_PACRD_WP4_MASK                      0x2000u
#define AIPS_PACRD_WP4_SHIFT                     13
#define AIPS_PACRD_SP4_MASK                      0x4000u
#define AIPS_PACRD_SP4_SHIFT                     14
#define AIPS_PACRD_TP3_MASK                      0x10000u
#define AIPS_PACRD_TP3_SHIFT                     16
#define AIPS_PACRD_WP3_MASK                      0x20000u
#define AIPS_PACRD_WP3_SHIFT                     17
#define AIPS_PACRD_SP3_MASK                      0x40000u
#define AIPS_PACRD_SP3_SHIFT                     18
#define AIPS_PACRD_TP2_MASK                      0x100000u
#define AIPS_PACRD_TP2_SHIFT                     20
#define AIPS_PACRD_WP2_MASK                      0x200000u
#define AIPS_PACRD_WP2_SHIFT                     21
#define AIPS_PACRD_SP2_MASK                      0x400000u
#define AIPS_PACRD_SP2_SHIFT                     22
#define AIPS_PACRD_TP1_MASK                      0x1000000u
#define AIPS_PACRD_TP1_SHIFT                     24
#define AIPS_PACRD_WP1_MASK                      0x2000000u
#define AIPS_PACRD_WP1_SHIFT                     25
#define AIPS_PACRD_SP1_MASK                      0x4000000u
#define AIPS_PACRD_SP1_SHIFT                     26
#define AIPS_PACRD_TP0_MASK                      0x10000000u
#define AIPS_PACRD_TP0_SHIFT                     28
#define AIPS_PACRD_WP0_MASK                      0x20000000u
#define AIPS_PACRD_WP0_SHIFT                     29
#define AIPS_PACRD_SP0_MASK                      0x40000000u
#define AIPS_PACRD_SP0_SHIFT                     30
/* PACRE Bit Fields */
#define AIPS_PACRE_TP7_MASK                      0x1u
#define AIPS_PACRE_TP7_SHIFT                     0
#define AIPS_PACRE_WP7_MASK                      0x2u
#define AIPS_PACRE_WP7_SHIFT                     1
#define AIPS_PACRE_SP7_MASK                      0x4u
#define AIPS_PACRE_SP7_SHIFT                     2
#define AIPS_PACRE_TP6_MASK                      0x10u
#define AIPS_PACRE_TP6_SHIFT                     4
#define AIPS_PACRE_WP6_MASK                      0x20u
#define AIPS_PACRE_WP6_SHIFT                     5
#define AIPS_PACRE_SP6_MASK                      0x40u
#define AIPS_PACRE_SP6_SHIFT                     6
#define AIPS_PACRE_TP5_MASK                      0x100u
#define AIPS_PACRE_TP5_SHIFT                     8
#define AIPS_PACRE_WP5_MASK                      0x200u
#define AIPS_PACRE_WP5_SHIFT                     9
#define AIPS_PACRE_SP5_MASK                      0x400u
#define AIPS_PACRE_SP5_SHIFT                     10
#define AIPS_PACRE_TP4_MASK                      0x1000u
#define AIPS_PACRE_TP4_SHIFT                     12
#define AIPS_PACRE_WP4_MASK                      0x2000u
#define AIPS_PACRE_WP4_SHIFT                     13
#define AIPS_PACRE_SP4_MASK                      0x4000u
#define AIPS_PACRE_SP4_SHIFT                     14
#define AIPS_PACRE_TP3_MASK                      0x10000u
#define AIPS_PACRE_TP3_SHIFT                     16
#define AIPS_PACRE_WP3_MASK                      0x20000u
#define AIPS_PACRE_WP3_SHIFT                     17
#define AIPS_PACRE_SP3_MASK                      0x40000u
#define AIPS_PACRE_SP3_SHIFT                     18
#define AIPS_PACRE_TP2_MASK                      0x100000u
#define AIPS_PACRE_TP2_SHIFT                     20
#define AIPS_PACRE_WP2_MASK                      0x200000u
#define AIPS_PACRE_WP2_SHIFT                     21
#define AIPS_PACRE_SP2_MASK                      0x400000u
#define AIPS_PACRE_SP2_SHIFT                     22
#define AIPS_PACRE_TP1_MASK                      0x1000000u
#define AIPS_PACRE_TP1_SHIFT                     24
#define AIPS_PACRE_WP1_MASK                      0x2000000u
#define AIPS_PACRE_WP1_SHIFT                     25
#define AIPS_PACRE_SP1_MASK                      0x4000000u
#define AIPS_PACRE_SP1_SHIFT                     26
#define AIPS_PACRE_TP0_MASK                      0x10000000u
#define AIPS_PACRE_TP0_SHIFT                     28
#define AIPS_PACRE_WP0_MASK                      0x20000000u
#define AIPS_PACRE_WP0_SHIFT                     29
#define AIPS_PACRE_SP0_MASK                      0x40000000u
#define AIPS_PACRE_SP0_SHIFT                     30
/* PACRF Bit Fields */
#define AIPS_PACRF_TP7_MASK                      0x1u
#define AIPS_PACRF_TP7_SHIFT                     0
#define AIPS_PACRF_WP7_MASK                      0x2u
#define AIPS_PACRF_WP7_SHIFT                     1
#define AIPS_PACRF_SP7_MASK                      0x4u
#define AIPS_PACRF_SP7_SHIFT                     2
#define AIPS_PACRF<r^��v���(��d8d�k�G't��οFjB2���#1%��f��2҄�َ���sܫ^e��J�/���E�ٓ7���Ȍ��$�#)�-� �
��8{��i(L�`%fx�I�|�g�։.M�@�幂�PI��q��k��^B �y�����:>m�YZex��������]������J���5Ō��G9�i�!U3�T���2,�]7�i_��=�#x	���?�N����L��2ޤ���b�&��T���T�J�&]M��R�����)��Z�d-�έ�p���4�Qpc;�W7<Oמ��)$��{�1m�(~�mW��w���p��?�`>dy�w�IR3�A\�(z�[�] ��+O��碦+mP^YӵK9�B�S3���G�}Y�4q�*:�e�[��z�#1ھ�N�5�#ά�9��{���ڼ�w�4RA�W�����:RB��;�(�|�����ݦ0��[�9��תUU�UG��^:��J\^���nG�G���Z)�ެ$��2��-�H�il;t}�Q�è�+�%��6���2��*�q$o�As�;:#���i�:.����#��T
&Yp�=�bw�x������Ȟ�+���@"�O����q�g%r��Ң]Y�!�7�<�F�f3��UŇ�N�5fʈ�X���A�a��,Ы����x��H>%�1�a����D�>���OY����0b7��E�eh�G=ތ�І��/�ߺ�D��:F(�)ujϟNNe	\,�gdz#�~^�;��C9�oӍX��������oq���z�YK`7t4�<эRՔ����J�i�I�)�'Pr�(jGj��W�<%��03��ف����
�&�OD0o�eݸ�u���L�B=R�F�|3j#�Dh���Ùn��-�L&��Ͱv�z�tp&����>3��)������?1͍��EΝ�4�m�}���V�z�?f� ��(��[����@�eKQYBԅr��I\��`+� ���И��Hy>f%���7�� ���#b1p�g����|��ND�����Z��,����������c_�o�"�Gd��f"B`Q����XF�31��?���ނ��j�!h�}R��A�Y�@d�ؚ�KN�TҰ�m���=�#���K�j��	�/[T�X7��9�:��C_�M�D4�o7�;������_���^<�$��Dϊi:������Θ�H��.L�O؟';��n�񹣝9Å����$�r���+��u�rbo���&�����,ϗƛi4�J�L�0��N�VT���MjSY��0(P9����A�/ ����D�\�%���a�.��������v-Z��fz��Y'��SOmM+s:o'gh�g7�9H!����C�/Io;����j��iU3%�*c��N�޺$?\������k��>g]�J΍�*��U�*��޾�)�Mж��������5%W��մ-ڷy��G�L�U�dG�"<�3}��.�z�����Ӛ9S?���&�ORzn��JX���3bp�UL�e<��J�xu1 <��7Om�)�3�#w�k-���A�hY�͂�ٍ�sݜ[OD�~<�W�PQŎ�
��#*g�$����L�n}�9c��+���v�7�fg��B��Mvs�δ����=�pȄ�]�� ����r�i���H���&k�a�\���KN��=x��Y�2Y��ɴ����'O
�k��,���o���Ğ�F��]���:��9n`�+�2\���c�a��Í�@�,Qk��.���nd�5�G�y�^�G
7N�(}փw��k�6���}jPp��J���nM��>��<�ijB�G)���V�<@�HЎ���M�GXi����p�ɪ`�@��%
�K�+��ޒ�#te�@{\B�@N�|
� ���O���wOEe+-�s&كO<�L�F'�U��'(�X�4 !i����lM(�}q��{G�;:}���uω䟙�����~�`)	��Ԙ�l�8(�1ꊵ)�!��Q��C�g��U{ݖ�q������x����2efine AIPS_PACRF_TP0_SHIFT                     28
#define AIPS_PACRF_WP0_MASK                      0x20000000u
#define AIPS_PACRF_WP0_SHIFT                     29
#define AIPS_PACRF_SP0_MASK                      0x40000000u
#define AIPS_PACRF_SP0_SHIFT                     30
/* PACRG Bit Fields */
#define AIPS_PACRG_TP7_MASK                      0x1u
#define AIPS_PACRG_TP7_SHIFT                     0
#define AIPS_PACRG_WP7_MASK                      0x2u
#define AIPS_PACRG_WP7_SHIFT                     1
#define AIPS_PACRG_SP7_MASK                      0x4u
#define AIPS_PACRG_SP7_SHIFT                     2
#define AIPS_PACRG_TP6_MASK                      0x10u
#define AIPS_PACRG_TP6_SHIFT                     4
#define AIPS_PACRG_WP6_MASK                      0x20u
#define AIPS_PACRG_WP6_SHIFT                     5
#define AIPS_PACRG_SP6_MASK                      0x40u
#define AIPS_PACRG_SP6_SHIFT                     6
#define AIPS_PACRG_TP5_MASK                      0x100u
#define AIPS_PACRG_TP5_SHIFT                     8
#define AIPS_PACRG_WP5_MASK                      0x200u
#define AIPS_PACRG_WP5_SHIFT                     9
#define AIPS_PACRG_SP5_MASK                      0x400u
#define AIPS_PACRG_SP5_SHIFT                     10
#define AIPS_PACRG_TP4_MASK                      0x1000u
#define AIPS_PACRG_TP4_SHIFT                     12
#define AIPS_PACRG_WP4_MASK                      0x2000u
#define AIPS_PACRG_WP4_SHIFT                     13
#define AIPS_PACRG_SP4_MASK                      0x4000u
#define AIPS_PACRG_SP4_SHIFT                     14
#define AIPS_PACRG_TP3_MASK                      0x10000u
#define AIPS_PACRG_TP3_SHIFT                     16
#define AIPS_PACRG_WP3_MASK                      0x20000u
#define AIPS_PACRG_WP3_SHIFT                     17
#define AIPS_PACRG_SP3_MASK                      0x40000u
#define AIPS_PACRG_SP3_SHIFT                     18
#define AIPS_PACRG_TP2_MASK                      0x100000u
#define AIPS_PACRG_TP2_SHIFT                     2 
#define AIPW_PACRG_WP2_MASK     0          $     0x200000eM
#define AIPS_PACRG_WP2_SHIFT    `                21
#defi.e AIPS_PACRG_SP2_MASK    !               " 0x400000u
#devine AIPS_PCrG_SP2_SHIFT                     22
#deFine AIPS_PACRE_TP1_MASK   `$                 0x1000000u
#define AIPS_PACRG_TP1_SHIFT            (        24
#dfi~e AIPS_PACRG^WP1_MASK        (     (    !  0x2000000u
#define(AIPS_PACRG_WQ1_SHIFT                     25#defkne AIPS_PACRG_SP1_]ASK       0              0x4000000u
#define QIPS_PICRG_SP1_SHIFT                     26
#define AIPS_PACRG_TP0_MASK        `           ! 0x10000000u
#define AIPR_PACRG_TP0_WHQFT                   � 28�#debinm AIPS_PACRG_WP0_MASO                 !    0x20000020u	
cdefine AIPS_PACRG_WP0_S@IFT                $    29
#define AIPC_PACRG_SP0_MASK           $   "      0840000000u
#define AIPS_PACRG_CP _SHIFT    `               `30
/* PACRH Bit Fields */
#define AIPS_PACRH_TP7_MASK                      0x1u
#define A�PS_PACRH_TP7_SHIFT                     0
#define AIPS_PACRH_WP7_MASK                      0x2u
#define AIPS_PACRH_WP7_SHIFT                     1
#define AIPS_PACRH_SP7_MASK                      0x4u
#define AIPS_PACRH_SP7_SHIFT                     2
#define AIPS_PACRH_TP6_MASK                      0x10u
#define AIPS_PACRH_TP6_SHIFT                     4
#define AIPS_PACRH_WP6_MASK                      0x20u
#define AIPS_PACRH_WP6_SHIFT                     5
#define AIPS_PACRH_SP6_MASK                      0x40u
#define AIPS_PACRH_SP6_SHIFT                     6
#define AIPS_PACRH_TP5_MASK                      0x100u
#define AIPS_PACRH_TP5_SHIFT                     8
#define AIPS_PACRH_WP5_MASK                      0x200u
#define AIPS_PACRH_WP5_SHIFT                     9
#define AIPS_PACRH_SP5_MASK                      0x400u
#define AIPS_PACRH_SP5_SHIFT                     10
#define AIPS_PACRH_TP4_MASK                      0x1000u
#define AIPS_PACRH_TP4_SHIFT                     12
#define AIPS_PACRH_WP4_MASK                      0x2000u
#define AIPS_PACRH_WP4_SHIFT                     13
#define AIPS_PACRH_SP4_MASK                      0x4000u
#define AIPS_PACRH_SP4_SHIFT                     14
#define AIPS_PACRH_TP3_MASK                      0x10000u
#define AIPS_PACRH_TP3_SHIFT                     16
#define AIPS_PACRH_WP3_MASK                      0x20000u
#define AIPS_PACRH_WP3_SHIFT                     17
#define AIPS_PACRH_SP3_MASK                      0x40000u
#define AIPS_PACRH_SP3_SHIFT                     18
#define AIPS_PACRH_TP2_MASK                      0x100000u
#define AIPS_PACRH_TP2_SHIFT                     20
#define AIPS_PACRH_WP2_MASK                      0x200000u
#define AIPS_PACRH_WP2_SHIFT                     21
#define AIPS_PACRH_SP2_MASK                      0x400000u
#define AIPS_PACRH_SP2_SHIFT                     22
#define AIPS_PACRH_TP1_MASK                      0x1000000u
#define AIPS_PACRH_TP1_SHIFT                     24
#define AIPS_PACRH_WP1_MASK                      0x2000000u
#define AIPS_PACRH_WP1_SHIFT                     25
#define AIPS_PACRH_SP1_MASK                      0x4000000u
#define AIPS_PACRH_SP1_SHIFT                     26
#define AIPS_PACRH_TP0_MASK                      0x10000000u
#define AIPS_PACRH_TP0_SHIFT                     28
#define AIPS_PACRH_WP0_MASK                      0x20000000u
#define AIPS_PACRH_WP0_SHIFT                     29
#define AIPS_PACRH_SP0_MASK                      0x40000000u
#define AIPS_PACRH_SP0_SHIFT                     30
/* PACRI Bit Fields */
#define AIPS_PACRI_TP7_MASK                      0x1u
#define AIPS_PACRI_TP7_SHIFT                     0
#define AIPS_PACRI_WP7_MASK                      0x2u
#define AIPS_PACRI_WP7_SHIFT                     1
#define AIPS_PACRI_SP7_MASK                      0x4u
#define AIPS_PACRI_SP7_SHIFT                     2
#define AIPS_PACRI_TP6_MASK                      0x10u
#define AIPS_PACRI_TP6_SHIFT                     4
#define AIPS_PACRI_WP6_MASK                      0xr0u
#define AIPS_PACRI_WP6_SHIFT                     5
#define AIPS_PACRI_SP6_M�SK         ! "          0x40u
#define AIPS_PACRI_SP6_SHIFT                     6
#define AIPS_P@CRI_TP5_MASK          $           0x10u
#defi�e(AIPS_PACRI_TP5_SHIFT   !           �     8
#dafine AIPS_PACRI_WP5_MASK    �                 0xr00u
#define AIPS_PACPI_WP5_HIFT     �               9
#define AIPS_PACRI_SP5_MASK                �     0x400u
#defiNe AIPS_PACSI_SP5_SHIFT                     10
#define AIPS_PACRI_TP4_MASK                      0x1000u
#definu AIPS_PACRI_TPt_SHIFT                     12
#de&inm AKP[OPACPIWWP4_MASK    "      "          0x2000u
#define AIPS_PACRI^WP4_SHIFT      ` �            13
#ddfine AIPS_PACSI_SP<_MASK  !�( $           0  (0x4000u
#deb�ne AIPS_PABRI_SP4_S�IFT                     14
#defhne AIPS_PACRI_TP3_MASK    �     "    !      0x10000u
#defife AIPS_PACRI_TP3_SHIFT       (  `   "      16
#define AIPS_PACRY_WP3_MASK                 !    0x20000u
#define AIPS_PACRI_WP3_SHIFT                     17
#defmne �IPS_PACRI_SP3_MASK            )         0x40000u
#d�fine AIPS_PABRI_SP3_SHIFT                   0 18
#define AIPS_PACRI_TP2_MASK                      0x1100005
#define AIPS_PACRI_TP2_SHIFT     0               2p
#define"AIPS_PACRI_Wp2_MASK        !             0x200040u
#define AIPS_PACVI_WP2_SHIFT                     21
#define aIPS_PACRI_SQ2_MASK                     0z400000u
#define AIPS_PACRI_SP2_SHIFT  �        0     (   22
#define AHPS_PACRI_TP0_MASˠ  `        0         0p1000000u
#define AIPS_PAcRI_TP1_[HI�T      (             !24
#define AIPS_PACRI_WP1_MASK         �            0x200000u
"define AIPS_PACRI_WP1_SHIFT "            0      25
#define AIPS_pACRI_SP1_MASK                  !   0x4000200u
#defi~e AITS_PACRI_SP1_SHIFT�                    26
#define AAPS_PACZI_TP0_MASK                      0x10000000u
#def)ne AIPS_PACRI_TP0_SHIFT    !!               28
#define AIPS_PACZI_WP0_MASK                      0x20000000u
#de %e�����1�`��!"� �zYv>��}w�a
$��Z>���E�:��J��U�Q#�h~�c�=e;ӽ��0�7��G������"�%�O�^���6Xʞ�?��TG�z��_��ݗ�w�[4!`�5<�)�k`�$8X6$�oJ|4���u2����R�*�	f5hG!B�~�����bt����S~Y�s�;%88n<����p������̂^d��	RY�>j�h�%�M)�@������`����Z>��!�ሤ��9^����_m��ɑ�>ݪ<v����:mώ����O%����D/`7$��×�*�wA��&�q/�?y�w4��j��_z�	z5&�$,R,Ru�ai)a\���ZK�C��z/����E�Z$�y���_�\j2S�QǢ���sCB��Z/lD&� ��F�U�#��4�E��i���爡0)]��N�c�����
[��E����a	�,l�Xj`
�^X<�;��u�����ث.n{����}�%/�U�J����.���� �[h6�>����:dr,����F0����g��V���b<�Yn�_CXt��b_:^N����8�F�b/U�fGu?�q%o�B���5q�b+9@,���+	����+5�'g�,u���u�[(rg�[���\f5Y���yI��b�8�c�1.R��}X�hi7	�I���k���ׇj4��1в���r��i�3�įXk�Q��� @F�9���&Bd��)X�#���_���o��w�,��; z\S��2Ƽ�V��w�hB\{S�K�c��Ȩ�e86a�&8���Xqq��4AX�F'�S�1�i=�����$����山M#9Cn����x�h�&��ʇhSjB�[��e�,F���m�+|����!�?���R0%���lp�Wr|��g�E��x�-����-�/�mf6	�p{��Iڲ���y�՟zd�8m�����/^����x��T2�
� �#��l=:�W_:L��|c���dA�>��� �L�=I��"�E�h��͌���&/`	�u�9a��0y���LBmt!��Dӱ$�n/2�pO��t$Ly?X���� %F,��+s^��m�	uk�J���HSOw;��t���lݙu�}�,��/�1yq_΅k�}j]�H$�o�Y:����� {���^Vn���<�R�2�m�V�Q嵊|���d^�0��ح\u���ق��%O�5�(Z*��P��"����Є�;!iJ�`���$�Ij:u0�c	�Z �|��N��۷x��8�4A�ǟ��[�PNm�/�E�>�]w�0��d�+��	�?������R[�:nP�}D�jTI�J�j.+Ѯ���4t�� #G�?vBs���4}b��f�rpQ4�
p�:��1%z��|�̍�^b���}���BoǖF�L�3A�T��c��R�7�q��RG<�����_�K*�5��,�������w�?;n��o1[S��<p�m�,�ƬPN�3��f�x��	��mV�{vE�]��#Y�������@S}��"�����H�j����ѹ���T�*���g�Yz�
�М�r{�
C����O��T�f	���Ϩ�վT��x�*o;�����8U9��or���8�6�|l,�/+Ϋ���d[AR�]�LhQ^��`w�8 z�������ŗ�yV��&�I:�׷V�[�]C����P����,X�I�y*��#������ЍC���WY���L�M:�e�n�Mn��^�E�2>����Z��z
������o��TK�=���������;ɽ CQ4H���]�����J�o�k������h���Uaz�Ä?Gܜ�R[�����wPWUc�|%d�t��h�܉ �)�(��RJ�*�oU�����>A�6���8��~��NH�<7	��v�\� :�h�q�����k:U��ݞN�6\�Z�T�H.��͟� ���Ք�i:#��I _1��GP�p]��~o��y�N��`�Wt:���N�Ĳ�|z�̙ܢ6��i_Y��'�Ư�?��P ?U[w�L/=A+��Z��5is�2�ڰ��/O�ႻE\��]�����[|=�\J��J�#1��ɀ��n��S���?�-������D��s���;��툇z۠�T/x���:��N6�06��k.u
�%ո.���S��`YeK�ta��]�N7����r�_V�Lėzͩ8�~���`�˃/����r/�&�i�dPk�^�K��Dl�(_0�c;��U�>oM�^<�T�ёz��@�m�l���/iw]����4x_uM�H<��0XO$�c��"�E`+��������2�U�9���X\K�?%�;_��7w�7��*�@�sW8u�U��X>/� �Y9?�:�'���)ݢ|*b'��&0�UK�z�y�{I8h�y��0�2�����!I�֛��MQg��~IlŦ�]GR��gߩ���XZ�l�����sP������ax�f����X���^!9�
����ggӌ��,�";q�F�B��O�q�l�hr��7� H�
A!Jn��HyИ� ���H�~4SW����I�B�Q�A�DЖ��;?U(r��s��=��n/�(m��3dT�~=`QF@@8�<��KT�N�Ry���5;�y�0���q��"�2M�K��6�,H��1���|~��ݹ�b%O'��׉�O�^&蔀)K&�ܮ*c�J�o�V����;�2�j��7X��P���<sF�'d�!��Ɵx���)�㗞�Vo~gc��%��xx�W[��\'i��8�mZ5p��\��S"{mp�$����� ՍZ�)�������7.�$m]�O�����$播t�*���-U��A�:��4p�c6p�����
�O�nG��h����[Gߎi��am&y7�QbS�xTP���焅��	��<0�^��3�,M��t�s�M���R��-���#�*lcD���T�m�G@�������w�n��~�	�מN�z�717�(���V���d*^A�80)g4@����֒���Rg�:DGBzL.Ղp��K�Ҥ�B�]���z�,6��2נ*V�v�َ����q4�O���ԡ,B�4v&��q|���'#�s$�@f(�v��o�f��4o|Ͼ�;�����/D4r#Q`�L��j_�J��(�6��)%�E���Y?dx6R���>Y�����&ueds�k)�k)�@��5~\c"
PX��2���D(XW�S�d��:���X�C|L}|q&���u�"�f,6y��;��%����qz�G^����)�ws�6_�]B�`�90j��qi�>��Au[]�g�y���py��ń�?e������2)��o��:�&�Ԉ�'+p|���q�Z��tSM��3fFR�q�d��鷀x�k��h��|�S�;P�=�bk���=:Q�鏓I3���@���ݢ�+1��q�݂Q&��E�T�})�����%^/��r���I:V�.���*�{�&��q�JC���H䐙~7�~����a�jg����{*��Y�D;B_R��Xp�3���3V����0U?�^����p[zݺ�ܢŬ���[|�B#3�o�0dI(��!���B^K��>� 7t��]㢞lN���)�E�`a��?e%�:��3�#��KA
��� �b$� n�ٳ=ð����I��cD����ޏפ��Pf�2#�­u�~�C�'�� }��s��L�F��Ǯ(�}�d&���5U<2]BͣѼ��&T?��B��[���5H�r�pΣe���H�\�=�ئu����Q�uejE?V;un��u̬����QT��
QK��9j
�T|��\;�>N�s'%e�"��%@�2������>�Q��^&��9�r�``P E���q3��cբiOl�|���>2���rh�/FT��z�)�=�nW������F8/���+�8��1 
���KqW�f���V�������^�w���Z	s|��B�"7�E�<�� sE1#�3����d�Ϡ��^��V��7� %e�����1�`��!"� �zYv>��}w�a
$��Z>���E�:��J��U�Q#�h~�c�=e;ӽ��0�7��G������"�%�O�^���6Xʞ�?��TG�z��_��ݗ�w�[4!`�5<�)�k`�$8X6$�oJ|4���u2����R�*�	f5hG!B�~�����bt����S~Y�s�;%88n<����p������̂^d��	RY�>j�h�%�M)�@������`����Z>��!�ሤ��9^����_m��ɑ�>ݪ<v����:mώ����O%����D/`7$��×�*�wA��&�q/�?y�w4��j��_z�	z5&�$,R,Ru�ai)a\���ZK�C��z/����E�Z$�y���_�\j2S�QǢ���sCB��Z/lD&� ��F�U�#��4�E��i���爡0)]��N�c�����
[��E����a	�,l�Xj`
�^X<�;��u�����ث.n{����}�%/�U�J����.���� �[h6�>����:dr,����F0����g��V���b<�Yn�_CXt��b_:^N����8�F�b/U�fGu?�q%o�B���5q�b+9@,���+	����+5�'g�,u���u�[(rg�[���\f5Y���yI��b�8�c�1.R��}X�hi7	�I���k���ׇj4��1в���r��i�3�įXk�Q��� @F�9���&Bd��)X�#���_���o��w�,��; z\S��2Ƽ�V��w�hB\{S�K�c��Ȩ�e86a�&8���Xqq��4AX�F'�S�1�i=�����$����山M#9Cn����x�h�&��ʇhSjB�[��e�,F���m�+|����!�?���R0%���lp�Wr|��g�E��x�-����-�/�mf6	�p{��Iڲ���y�՟zd�8m�����/^����x��T2�
� �#��l=:�W_H�7}y<u [>v�&�$UU�Z
��� ���K�U����V���3ӶPG����^|l]x�������S��s�?��j��X�R�X�Z5T�y�=3����Z��t��x�i���ID(`p��G�V��S~�섈�ݔr���[PD�Zݮa�G��l����P��ߪ���f}nG��R9U�I��^�:v��~�1
6���<�-H����O���h0Kj�n1��Ir4���gb-ֶ���ݒ��Il��ӗo�ڷڣ\i����!w�8��SĹ�k.��<�C�OQ08e�ו�1���y��xP��`3�F�Q�V��/�~�a<@#Ԟ~N��6��H�t��n������7I�`�F�
�ޒ���6Àf�N�Ќ)	e{Fi6���r��'�[w7��l%���}w(P{��i��kq*Sd�$٣�A2]����}`���Ֆg��M�0K����F�@����h�o���s�\�oL�����]>Kf�x�Z�3V����S�fڐ��R�?n�JC4�>	��!�>Lx�*א�lC��5�m ��Q�C�xΞHڨ�T:<E!s?�@����ۍ�����Y�Hl�Ү@aF��=�oK�u������l�188����6��=,�g��.%lX�/�! u��I�?�x��	��4j8�'��+$�"���o�u��v�1����n	��4�Դkf9��-������:�j8�Ae%�3��a�����ˢj��KE�ykg����}P!\�)1Xm��������nR��S�b~]�Z!��Xz$��}5�'G�ےO�78�0=~�ˏx�2�?����!��
A]�4gP��\j]w<0"9�c�Ɠd:	P�I��;�X�#�P��Af���?s� Fn1Ò�7j/����<���9ʘ#����D�Y��9q�dhݕ,�7��4X���nxt&�y��-�;H���+��ϝ�v�oxÅ"�`�Y������:�_Y���؄|�Tu< 0|5J_����<5�y��y\1c��D��c?�(������f����Y�Ϫ;�>kU��k�N^o(7��g����sk}�r���E��|�=��̄��ay�(�Mnq������D��9��<�|zS��:cOvx�)ƅ���<���*�Җi�X���?;�S<$��G���y�J^����%�4{�������n�����@�K<uh/�w�~��r�ߞ��q�U��c�> ^�uڼ�w����Cc����V�;-���,K��Z���qmx�{�I�	@��$\l�DT�ֺ1��D1v�'�"���G�x�9�@�CT���@VO�n��;��S:��&�c��2�{���́RW�*l[b��"t$�r��E9^��R�)�E�ъ�J��J�Q�~	�״l�Z��KRl�'����� OP~�L�>���� �{��Q%C^�Z�K���bw�ƙ@Ս�{\��(�U�:����/���:@�ꎬ�J;�m@�٦�3�Ysä4�E�pH�8����xO���Ts��X�+u��=�s�Z|�r'��W �X��{~u�U"�g�P��ht�������"�8=U��X�K����z#*]����gw�#k�J��) @�0A��ߘ��0��K~�������D�^=2���^t>� �}�X�S�vDQ|�m=���K�,���@�L�
0[��H�W�^���8Sq����'6�"E��^�h��8a^�n<TۇԵ�����Kr �Z�>sޱ�
5|"�\�bfD�.����w���1V�O��%N´w2�c�W�D� yק��4��'@g�矛�U���W�>L0�c-�m��@Y�n��H�|v+�/$iR��.�vIc1~��	�g��e��IY�e�X���I��J�cے{=�> ��~@��s�F�Q��>e�_��N2��Mo�@�k4�Ww�O:F�\}jΣwK�oy���6Ê����]����E�e��E��8q�W�cJ���rC"�vQ�fY��^+䚱�e AIPS_PACRL_SP3_SHIFT                     18
#define AIPS_PACRL_TP2_MASK                      0x100000u
#define AIPS_PACRL_TP2_SHIFT                     20
#define AIPS_PACRL_WP2_MASK                      0x200000u
#define AIPS_PACRL_WP2_SHIFT                     21
#define AIPS_PACRL_SP2_MASK                      0x400000u
#define AIPS_PACRL_SP2_SHIFT                     22
#define AIPS_PACRL_TP1_MASK                      0x1000000u
#define AIPS_PACRL_TP1_SHIFT                     24
#define AIPS_PACRL_WP1_MASK                      0x2000000u
#define AIPS_PACRL_WP1_SHIFT                     25
#define AIPS_PACRL_SP1_MASK                      0x4000000u
#define AIPS_PACRL_SP1_SHIFT                     26
#define AIPS_PACRL_TP0_MASK                      0x10000000u
#define AIPS_PACRL_TP0_SHIFT                     28
#define AIPS_PACRL_WP0_MASK                      0x20000000u
#define AIPS_PACRL_WP0_SHIFT                     29
#define AIPS_PACRL_SP0_MASK                      0x40000000u
#define AIPS_PACRL_SP0_SHIFT                     30
/* PACRM Bit Fields */
#define AIPS_PACRM_TP7_MASK                      0x1u
#define AIPS_PACRM_TP7_SHIFT                     0
#define AIPS_PACRM_WP7_MASK                      0x2u
#define AIPS_PACRM_WP7_SHIFT                     1
#define AIPS_PACRM_SP7_MASK                      0x4u
#define AIPS_PACRM_SP7_SHIFT                     2
#define AIPS_PACRM_TP6_MASK                      0x10u
#define AIPS_PACRM_TP6_SHIFT                     4
#define AIPS_PACRM_WP6_MASK                      0x20u
#define AIPS_PACRM_WP6_SHIFT                     5
#define AIPS_PACRM_SP6_MASK                      0x40u
#define AIPS_PACRM_SP6_SHIFT                     6
#define AIPS_PACRM_TP5_MASK                      0x100u
#define AIPS_PACRM_TP5_SHIFT                     8
#define AIPS_PACRM_WP5_MASK                      0x200u
#define AIPS_PACRM_WP5_SHIFT                     9
#define AIPS_PACRM_SP5_MASK                      0x400u
#define AIPS_PACRM_SP5_SHIFT                     10
#define AIPS_pACRM_TP4_MASK                   !  0x1000u#defile AIPS_PACRM_TP4_SHIFT                     12
#define AIPS_PACRMWP4WMASK      (   0    $   ! !0|6000u
#defAna AIPS_PAKRM_WP4[SHIFT         $  "    !(  13
#define AIP[_PACRM_SP4_MASK       (   ` "        0x4000u
#degine AIPS_PACRM_SP4_SHIFT    "               (14
#define AIPS[PACPM_TP3_MASK                      0x1000u-
#define AIPS_PACRM_TP3_[HIFT "              �    16#define AMPS_PACRL_WP3MAK `         $          0x20000u
#define EIPS_PACRM_WP3_SHIFT             !       17
#dedinm AIPS_PACRM_SP3_MASC !0                   0x40000u
#define AIPS_PACRM_SP3_SXIFT (                   18J#define AIPS_PaCRM_TP2_M@SK                      0x100000u
#define AIPS_PACRMTP2_SHIFT               "     20
#defile0AIPS]PACRE_WP2_MASK               !      0x200000u
#define AIPS_PACR�^WP2_SHIFT                     21
#define AIPS_PACRM_Sp2_MASK                      0x4  000u
#l�fine AAPS_RACRM_SP2_SHIFT                     22
#define AIPS[PACRM_TP1_MASK    0                 0x1000000u
#d%fine AIPS_PACRM_TP1_SHAFT                     24#define AIPS_PACRM_WQ1_MESK                      0x2000000u
#define AIPS_PACRM_WP1_SHIFT     " "   �    $    25
#define AIPS_PACRM_SP1_MASK                      0x4000000u
"define AIPS_PACRM[Sp1_SHIFT                     26
#define AIPS_PACRM_TP0_MASK  �       (           x100000 0u
#define AIPS_PACRM_TP0_SHIFT �             `     08
#define AIPS_PACRM_WP0_MASK            !         0x20000000u
#define AIPS_PA�RM_WP0_SHIFT       $            �29
#define IIPS_PQCRM_SP0_MASK    $         0 $     0x40000000u
#define AIPS_PACRM_SP0_SHIFT                     30
/* PAKRN Bit Vieldr */
#def)ne AIPS_PACRL]TP6_MASK                      0x1u
#tefine AIPS_PABRNOTPw_SHIFT �            �      �
#d%fine �IPS_PACRN_WP7_MAS{       �              0x2u
#definm AIPSPACRN_WP7_SIIFT                 (   1
#define AIPS_PACRN_SP7_MASK                      0x4u
#�efine AIPS^P�BRN_SP7_SJIFT                     2
#lefine AIPS_PACR�_TP6_IASk     (  (             0x10u
#define AIPS_PACRN_TP6_SHIFT                     4
#define AIPS_PACRN_WP6_MASK ( `              �   0x20u
#define AIPS[PACQN_WP&_CHIFT      `              5
#�efane AIPS_PACRN_SP6_MASK                      0x40u
#define AIPS_PACRN_SP6_SHIFT        "            6
#define$AIPS_PACRN_TP5_MASK                      0x100u
#define AIPS_PACRN_TP5_SHIFT                 (  "8
#debije AIPS_PIKRN_WP5_MASK         !0           �x200u
#define AIPS_PACRN_WP5_SHIFT        `       $    9
#define AI@S_�ACRNSP4_MASK                      0x400t
#define AIPS_PACRN_SP5_SHIFT    `       1     $  10
#defYne AIPs_PACRN_TP4_MASK                (     0x1000u
#defioe AIPS_PACRNTP4_SHIFT�       "            12
#defi�e AIPS_P@CRN_WP4_MASK #    $       �       0x2000u
+defiNe AIPS_PACRN_WP$_[HIFT     �    0   (      13
#definm AI@S_PQCRN_SP4_MASK                      0x4000u
#define AIPS_PACRNWSP4_SHIFT    "  0       0     14
#define AIPS_PACRN_TP3_EASK($ (         $        0x10000u
#define AIPS_PACRN_TP3_SHHFT          !     "    16
#$efine AIPS_PACRNWP3_M@SK                     ` x20000u
#define AIPS_PACRN_WP3_RHIFT  `                  17�
�define AIPS_PACRN_SP3_MASK        !             0x40000u
#defile AIPS_PACRN_SP3_SHIFT     `               1(J#define AIPS_PACRN_TP2_MCSK              "       08100000u-
#define AIPS_PACRN_TP2_SHIFT                     20
#define �IPC_PACRN_WP2_MASK     "    0           0x200004u#define AIPS_PCCRN_WP2_SHIFT         "�          21
#define AIPS_PCRN[SP2_MASK                0     0y404000u
�defi�e AIPS_PACRN_SP2_SHIFT             (       22
#define AIPS_PACRN_TP�_MASK            0(        0x1000000u
#define AIPS_PACRN_TP1_SHIFT (                   24
#define AIPS_PACPN_WP1�MASK                      0x2000000u
#define AIPS_PACRN_WP1_SXIFT    `                25
#dufije AIPS_PACRN_WP1_MAS[                   !  0x4000000u
#define AITS_RACRN_SP1_SHINT`            "     ( 26
#define AIPS_PAcRN_TP0_MASK                      0x10000000u
#define AIPS_PACRN_TP0_SHIFT                     28
#define AIPS_PACRN_WP0_MASK                      0x20000000u
#define AIPS_PACRN_WP0_SHIFT                     29
#define AIPS_PACRN_SP0_MASK                      0x40000000u
#define AIPS_PACRN_SP0_SHIFT                     30
/* PACRO Bit Fields */
#define AIPS_PACRO_TP7_MASK                      0x1u
#define AIPS_PACRO_TP7_SHIFT                     0
#define AIPS_PACRO_WP7_MASK                      0x2u
#define AIPS_PACRO_WP7_SHIFT                     1
#define AIPS_PACRO_SP7_MASK                      0x4u
#define AIPS_PACRO_SP7_SHIFT                     2
#define AIPS_PACRO_TP6_MASK                      0x10u
#define AIPS_PACRO_TP6_SHIFT                     4
#define AIPS_PACRO_WP6_MASK                      0x20u
#define AIPS_PACRO_WP6_SHIFT                     5
#define AIPS_PACRO_SP6_MASK                      0x40u
#define AIPS_PACRO_SP6_SHIFT                     6
#define AIPS_PACRO_TP5_MASK                      0x100u
#defIne AIPS_PACSO_TP5_SHIFT    �               08
#definf`AIPS_PACRO_OP5_MASK            "         0x20pu
#define AIPS�PACZO_WP5_SHIFT                    `9M
#dgfine AIPS_PACRO_SP5_LA�K                      0x400u
#define$AIPS_PACRO_SP5_SHIFT (   `               10
#denine AIPS_PACRO_TP4_MASK                      0x1000u
#defing AIPS_pACRO_TP4[SHIFT         �        0  12
#define AIPS_PACRO_WP4_MASK                      0x2000u
#d�fine �IPS_PACRO_WR4_SHIFT    (                13
#define AIPS_PACRO_SP4_MASK       (      0       8x4000u
#define AAPS_PACRO_SP$_SHIFT    (       !        14
#define AIPV�PACRO_TP3_MASK  !                   0x10000u
#define aIPS_PACRO_TP3_SHIFT              (      16
#define AIPS_PACRO_WP3_MASK                      0x20000u
#tefine AIPS_PACR__WP3_SHIT                (    97
#define AIPS_PACRO_Sp3_MASK                   $  0x40000u
#define AIPS_PACRO_SP3_ShIFT       (     �       18
#def)ne AIPS_PACRO_TP2_MASK                      0x10�000u
#define AIPS_PACRO_TP2_SHIFT!                    20
#d�fine AIPQ_PACRO_WP2_MARK                      0z200000u
+define AIPS_PACRO_WP2_SHIFt                   " 21
#d%fine AIP[_PACRO_SP2_MASK        !             0x400000u
#defin%(AIPS_RACRG_SP2_SHIFT                (    22
#define AIPS_PACRK_TP1_MASK                     `0x100000u
#defife AIPS_PACRO_TP1_SHYFT   0          ! !    24
#define AIPS_PACRM_WP1_MASK        $          $  0x2000100u
#define AIPS_PACRO�WP1_[HIFT   (                 25
#define AIPS_PACRO_SP1_MASK            (         0p4000000u
#define AIPS_PACRO_SP1_RHHFT            (        26
3define AIPSPACRO_TP0_MASK                �  "  0x10000001u
#define AIPS_PACRO_TP0_SHIFT                     28
#define A�PS_PACRO_WP0_MASK               �      0x20000000u
#defyne AIPS_PACRO_wP0_SHIFT"              $     29
#define AIPS^PACRO_SP0_MASK                (�    0x40000000u
#define AIPS�PACRO_SP0_[HIFD       !            30/* PACRP Bit Fields */
#define AIPS_PACRP_TP7_MASK   !    �             0x1u
#define AIPS_PACRP_TP7_SHIFT                     0
#define AIPS_PACRP_WP7_MASK                      0x2u
#define AIPS_PACRP_WP7_SHIFT                     1
#define AIPS_PACRP_SP7_MASK                      0x4u
#define AIPS_PACRP_SP7_SHIFT                     2
#define AIPS_PACRP_TP6_MASK                      0x10u
#define AIPS_PACRP_TP6_SHIFT                     4
#define AIPS_PACRP_WP6_MASK                      0x20u
#define AIPS_PACRP_WP6_SHIFT                     5
#define AIPS_PACRP_SP6_MASK                      0x40u
#define AIPS_PACRP_SP6_SHIFT                     6
#define AIPS_PACRP_TP5_MASK                      0x100u
#define AIPS_PACRP_TP5_SHIFT                     8
#define AIPS_PACRP_WP5_MASK                      0x200u
#define AIPS_PACRP_WP5_SHIFT                     9
#define AIPS_PACRP_SP5_MASK                      0x400u
#define AIPS_PACRP_SP5_SHIFT                     10
#define AIPS_PACRP_TP4_MASK                      0x1000u
#define AIPS_PACRP_TP4_SHIFT                     12
#define AIPS_PACRP_WP4_MASK                      0x2000u
#define AIPS_PACRP_WP4_SHIFT                     13
#define AIPS_PACRP_SP4_MASK                      0x4000u
#define AIPS_PACRP_SP4_SHIFT                     14
#define AIPS_PACRP_TP3_MASK                      0x10000u
#define AIPS_PACRP_TP3_SHIFT                     16
#define AIPS_PACRP_WP3_MASK                      0x20000u
#define AIPS_PACRP_WP3_SHIFT                     17
#define AIPS_PACRP_SP3_MASK                      0x40000u
#define AIPS_PACRP_SP3_SHIFT                     18
#define AIPS_PACRP_TP2_MASK                      0x100000u
#define AIPS_PACRP_TP2_SHIFT                     20
#define AIPS_PACRP_WP2_MASK                      0x200000u
#define AIPS_PACRP_WP2_SHIFT                     21
#define AIPS_PACRP_SP2_MASK                      0x400000u
#define AIPS_PACRP_SP2_SHIFT                     22
#define AIPS_PACRP_TP1_MASK                      0x1000000u
#define AIPS_PACRP_TP1_SHIFT                     24
#define AIPS_PACRP_WP1_MASK                      0x2000000u
#define AIPS_PACRP_WP1_SHIFT                     25
#define AIPS_PACRP_SP1_MASK                      0x4000000u
#define AIPS_PACRP_SP1_SHIFT                     26
#define AIPS_PACRP_TP0_MASK                      0x10000000u
#define AIPS_PACRP_TP0_SHIFT                     28
#define AIPS_PACRP_WP0_MASK                      0x20000000u
#define AIPS_PACRP_WP0_SHIFT                     29
#define AIPS_PACRP_SP0_MASK                      0x40000000u
#define AIPS_PACRP_SP0_SHIFT                     30

/**
 * @}
 */ /* end of group AIPS_Register_Masks */


/* AIPS - Peripheral instance base addresses */
/** Peripheral AIPS0 base pointer */
#define AIPS0_BASE_PTR                           ((AIPS_MemMapPtr)0x40000000u)
/** Peripheral AIPS1 base pointer */
#define AIPS1_BASE_PTR                           ((AIPS_MemMapPtr)0x40080000u)
/** Array initializer of AIPS peripheral base pointers */
#define AIPS_BASE_PTRS                           { AIPS0_BASE_PTR, AIPS1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros
 * @{
 */


/* AIPS - Register instance definitions */
/* AIPS0 */
#define AIPS0_MPRA                               AIPS_MPRA_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRA                              AIPS_PACRA_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRB                              AIPS_PACRB_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRC                              AIPS_PACRC_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRD                              AIPS_PACRD_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRE                              AIPS_PACRE_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRF                              AIPS_PACRF_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRG                              AIPS_PACRG_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRH                              AIPS_PACRH_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRI                              AIPS_PACRI_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRJ                              AIPS_PACRJ_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRK                              AIPS_PACRK_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRL                              AIPS_PACRL_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRM                              AIPS_PACRM_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRN                              AIPS_PACRN_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRO                              AIPS_PACRO_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRP                              AIPS_PACRP_REG(AIPS0_BASE_PTR)
/* AIPS1 */
#define AIPS1_MPRA                               AIPS_MPRA_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRA                              AIPS_PACRA_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRB                              AIPS_PACRB_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRC                              AIPS_PACRC_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRD                              AIPS_PACRD_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRE                              AIPS_PACRE_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRF                              AIPS_PACRF_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRG                              AIPS_PACRG_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRH                              AIPS_PACRH_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRI                              AIPS_PACRI_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRJ                              AIPS_PACRJ_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRK                              AIPS_PACRK_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRL                              AIPS_PACRL_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRM                              AIPS_PACRM_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRN                              AIPS_PACRN_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRO                              AIPS_PACRO_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRP                              AIPS_PACRP_REG(AIPS1_BASE_PTR)

/**
 * @}
 */ /* end of group AIPS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group AIPS_Peripheral */


/* ----------------------------------------------------------------------------
   -- AXBS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Peripheral AXBS
 * @{
 */

/** AXBS - Peripheral register structure */
typedef struct AXBS_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    uint32_t PRS;                                    /**< Priority Registers Slave, array offset: 0x0, array step: 0x100 */
    uint8_t RESERVED_0[12];
    uint32_t CRS;                                    /**< Control Register, array offset: 0x10, array step: 0x100 */
    uint8_t RESERVED_1[236];
  } SLAVE[5];
  uint8_t RESERVED_0[768];
  uint32_t MGPCR0;                                 /**< Master General Purpose Control Register, offset: 0x800 */
  uint8_t RESERVED_1[252];
  uint32_t MGPCR1;                                 /**< Master General Purpose Control Register, offset: 0x900 */
  uint8_t RESERVED_2[252];
  uint32_t MGPCR2;                                 /**< Master General Purpose Control Register, offset: 0xA00 */
  uint8_t RESERVED_3[508];
  uint32_t MGPCR4;                                 /**< Master General Purpose Control Register, offset: 0xC00 */
  uint8_t RESERVED_4[252];
  uint32_t MGPCR5;                                 /**< Master General Purpose Control Register, offset: 0xD00 */
} volatile *AXBS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros
 * @{
 */


/* AXBS - Register accessors */
#define AXBS_PRS_REG(base,index)                 ((base)->SLAVE[index].PRS)
#define AXBS_CRS_REG(base,index)                 ((base)->SLAVE[index].CRS)
#define AXBS_MGPCR0_REG(base)                    ((base)->MGPCR0)
#define AXBS_MGPCR1_REG(base)                    ((base)->MGPCR1)
#define AXBS_MGPCR2_REG(base)                    ((base)->MGPCR2)
#define AXBS_MGPCR4_REG(base)                    ((base)->MGPCR4)
#define AXBS_MGPCR5_REG(base)                    ((base)->MGPCR5)

/**
 * @}
 */ /* end of group AXBS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/* PRS Bit Fields */
#define AXBS_PRS_M0_MASK                         0x7u
#define AXBS_PRS_M0_SHIFT                        0
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M0_SHIFT))&AXBS_PRS_M0_MASK)
#define AXBS_PRS_M1_MASK                         0x70u
#define AXBS_PRS_M1_SHIFT                        4
#define AXBS_PRS_M1(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M1_SHIFT))&AXBS_PRS_M1_MASK)
#define AXBS_PRS_M2_MASK                         0x700u
#define AXBS_PRS_M2_SHIFT                        8
#define AXBS_PRS_M2(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M2_SHIFT))&AXBS_PRS_M2_MASK)
#define AXBS_PRS_M3_MASK                         0x7000u
#define AXBS_PRS_M3_SHIFT                        12
#define AXBS_PRS_M3(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M3_SHIFT))&AXBS_PRS_M3_MASK)
#define AXBS_PRS_M4_MASK                         0x70000u
#define AXBS_PRS_M4_SHIFT                        16
#define AXBS_PRS_M4(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M4_SHIFT))&AXBS_PRS_M4_MASK)
#define AXBS_PRS_M5_MASK                         0x700000u
#define AXBS_PRS_M5_SHIFT                        20
#define AXBS_PRS_M5(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M5_SHIFT))&AXBS_PRS_M5_MASK)
/* CRS Bit Fields */
#define AXBS_CRS_PARK_MASK                       0x7u
#define AXBS_CRS_PARK_SHIFT                      0
#define AXBS_CRS_PARK(x)                         (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_PARK_SHIFT))&AXBS_CRS_PARK_MASK)
#define AXBS_CRS_PCTL_MASK                       0x30u
#define AXBS_CRS_PCTL_SHIFT                      4
#define AXBS_CRS_PCTL(x)                         (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_PCTL_SHIFT))&AXBS_CRS_PCTL_MASK)
#define AXBS_CRS_ARB_MASK                        0x300u
#define AXBS_CRS_ARB_SHIFT                       8
#define AXBS_CRS_ARB(x)                          (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_ARB_SHIFT))&AXBS_CRS_ARB_MASK)
#define AXBS_CRS_HLP_MASK                        0x40000000u
#define AXBS_CRS_HLP_SHIFT                       30
#define AXBS_CRS_RO_MASK                         0x80000000u
#define AXBS_CRS_RO_SHIFT                        31
/* MGPCR0 Bit Fields */
#define AXBS_MGPCR0_AULB_MASK                    0x7u
#define AXBS_MGPCR0_AULB_SHIFT                   0
#define AXBS_MGPCR0_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR0_AULB_SHIFT))&AXBS_MGPCR0_AULB_MASK)
/* MGPCR1 Bit Fields */
#define AXBS_MGPCR1_AULB_MASK                    0x7u
#define AXBS_MGPCR1_AULB_SHIFT                   0
#define AXBS_MGPCR1_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR1_AULB_SHIFT))&AXBS_MGPCR1_AULB_MASK)
/* MGPCR2 Bit Fields */
#define AXBS_MGPCR2_AULB_MASK                    0x7u
#define AXBS_MGPCR2_AULB_SHIFT                   0
#define AXBS_MGPCR2_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR2_AULB_SHIFT))&AXBS_MGPCR2_AULB_MASK)
/* MGPCR4 Bit Fields */
#define AXBS_MGPCR4_AULB_MASK                    0x7u
#define AXBS_MGPCR4_AULB_SHIFT                   0
#define AXBS_MGPCR4_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR4_AULB_SHIFT))&AXBS_MGPCR4_AULB_MASK)
/* MGPCR5 Bit Fields */
#define AXBS_MGPCR5_AULB_MASK                    0x7u
#define AXBS_MGPCR5_AULB_SHIFT                   0
#define AXBS_MGPCR5_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR5_AULB_SHIFT))&AXBS_MGPCR5_AULB_MASK)

/**
 * @}
 */ /* end of group AXBS_Register_Masks */


/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS base pointer */
#define AXBS_BASE_PTR                            ((AXBS_MemMapPtr)0x40004000u)
/** Array initializer of AXBS peripheral base pointers */
#define AXBS_BASE_PTRS                           { AXBS_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros
 * @{
 */


/* AXBS - Register instance definitions */
/* AXBS */
#define AXBS_PRS0                                AXBS_PRS_REG(AXBS_BASE_PTR,0)
#define AXBS_CRS0                                AXBS_CRS_REG(AXBS_BASE_PTR,0)
#define AXBS_PRS1                                AXBS_PRS_REG(AXBS_BASE_PTR,1)
#define AXBS_CRS1                                AXBS_CRS_REG(AXBS_BASE_PTR,1)
#define AXBS_PRS2                                AXBS_PRS_REG(AXBS_BASE_PTR,2)
#define AXBS_CRS2                                AXBS_CRS_REG(AXBS_BASE_PTR,2)
#define AXBS_PRS3                                AXBS_PRS_REG(AXBS_BASE_PTR,3)
#define AXBS_CRS3                                AXBS_CRS_REG(AXBS_BASE_PTR,3)
#define AXBS_PRS4                                AXBS_PRS_REG(AXBS_BASE_PTR,4)
#define AXBS_CRS4                                AXBS_CRS_REG(AXBS_BASE_PTR,4)
#define AXBS_MGPCR0                              AXBS_MGPCR0_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR1                              AXBS_MGPCR1_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR2                              AXBS_MGPCR2_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR4                              AXBS_MGPCR4_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR5                              AXBS_MGPCR5_REG(AXBS_BASE_PTR)

/* AXBS - Register array accessors */
#define AXBS_PRS(index)                          AXBS_PRS_REG(AXBS_BASE_PTR,index)
#define AXBS_CRS(index)                          AXBS_CRS_REG(AXBS_BASE_PTR,index)

/**
 * @}
 */ /* end of group AXBS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group AXBS_Peripheral */


/* ----------------------------------------------------------------------------
   -- CAN
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Peripheral CAN
 * @{
 */

/** CAN - Peripheral register structure */
typedef struct CAN_MemMap {
  uint32_t MCR;                                    /**< Module Configuration Register, offset: 0x0 */
  uint32_t CTRL1;                                  /**< Control 1 register, offset: 0x4 */
  uint32_t TIMER;                                  /**< Free Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t RXMGMASK;                               /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  uint32_t RX14MASK;                               /**< Rx 14 Mask register, offset: 0x14 */
  uint32_t RX15MASK;                               /**< Rx 15 Mask register, offset: 0x18 */
  uint32_t ECR;                                    /**< Error Counter, offset: 0x1C */
  uint32_t ESR1;                                   /**< Error and Status 1 register, offset: 0x20 */
  uint8_t RESERVED_1[4];
  uint32_t IMASK1;                                 /**< Interrupt Masks 1 register, offset: 0x28 */
  uint8_t RESERVED_2[4];
  uint32_t IFLAG1;                                 /**< Interrupt Flags 1 register, offset: 0x30 */
  uint32_t CTRL2;                                  /**< Control 2 register, offset: 0x34 */
  uint32_t ESR2;                                   /**< Error and Status 2 register, offset: 0x38 */
  uint8_t RESERVED_3[8];
  uint32_t CRCR;                                   /**< CRC Register, offset: 0x44 */
  uint32_t RXFGMASK;                               /**< Rx FIFO Global Mask register, offset: 0x48 */
  uint32_t RXFIR;                                  /**< Rx FIFO Information Register, offset: 0x4C */
  uint8_t RESERVED_4[48];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    uint32_t CS;                                     /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
    uint32_t ID;                                     /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
    uint32_t WORD0;                                  /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
    uint32_t WORD1;                                  /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
  } MB[16];
  uint8_t RESERVED_5[1792];
  uint32_t RXIMR[16];                              /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} volatile *CAN_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register accessors */
#define CAN_MCR_REG(base)                        ((base)->MCR)
#define CAN_CTRL1_REG(base)                      ((base)->CTRL1)
#define CAN_TIMER_REG(base)                      ((base)->TIMER)
#define CAN_RXMGMASK_REG(base)                   ((base)->RXMGMASK)
#define CAN_RX14MASK_REG(base)                   ((base)->RX14MASK)
#define CAN_RX15MASK_REG(base)                   ((base)->RX15MASK)
#define CAN_ECR_REG(base)                        ((base)->ECR)
#define CAN_ESR1_REG(base)                       ((base)->ESR1)
#define CAN_IMASK1_REG(base)                     ((base)->IMASK1)
#define CAN_IFLAG1_REG(base)                     ((base)->IFLAG1)
#define CAN_CTRL2_REG(base)                      ((base)->CTRL2)
#define CAN_ESR2_REG(base)                       ((base)->ESR2)
#define CAN_CRCR_REG(base)                       ((base)->CRCR)
#define CAN_RXFGMASK_REG(base)                   ((base)->RXFGMASK)
#define CAN_RXFIR_REG(base)                      ((base)->RXFIR)
#define CAN_CS_REG(base,index)                   ((base)->MB[index].CS)
#define CAN_ID_REG(base,index)                   ((base)->MB[index].ID)
#define CAN_WORD0_REG(base,index)                ((base)->MB[index].WORD0)
#define CAN_WORD1_REG(base,index)                ((base)->MB[index].WORD1)
#define CAN_RXIMR_REG(base,index)                ((base)->RXIMR[index])

/**
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/* MCR Bit Fields */
#define CAN_MCR_MAXMB_MASK                       0x7Fu
#define CAN_MCR_MAXMB_SHIFT                      0
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MAXMB_SHIFT))&CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        0x300u
#define CAN_MCR_IDAM_SHIFT                       8
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IDAM_SHIFT))&CAN_MCR_IDAM_MASK)
#define CAN_MCR_AEN_MASK                         0x1000u
#define CAN_MCR_AEN_SHIFT                        12
#define CAN_MCR_LPRIOEN_MASK                     0x2000u
#define CAN_MCR_LPRIOEN_SHIFT                    13
#define CAN_MCR_IRMQ_MASK                        0x10000u
#define CAN_MCR_IRMQ_SHIFT                       16
#define CAN_MCR_SRXDIS_MASK                      0x20000u
#define CAN_MCR_SRXDIS_SHIFT                     17
#define CAN_MCR_WAKSRC_MASK                      0x80000u
#define CAN_MCR_WAKSRC_SHIFT                     19
#define CAN_MCR_LPMACK_MASK                      0x100000u
#define CAN_MCR_LPMACK_SHIFT                     20
#define CAN_MCR_WRNEN_MASK                       0x200000u
#define CAN_MCR_WRNEN_SHIFT                      21
#define CAN_MCR_SLFWAK_MASK                      0x400000u
#define CAN_MCR_SLFWAK_SHIFT                     22
#define CAN_MCR_SUPV_MASK                        0x800000u
#define CAN_MCR_SUPV_SHIFT                       23
#define CAN_MCR_FRZACK_MASK                      0x1000000u
#define CAN_MCR_FRZACK_SHIFT                     24
#define CAN_MCR_SOFTRST_MASK                     0x2000000u
#define CAN_MCR_SOFTRST_SHIFT                    25
#define CAN_MCR_WAKMSK_MASK                      0x4000000u
#define CAN_MCR_WAKMSK_SHIFT                     26
#define CAN_MCR_NOTRDY_MASK                      0x8000000u
#define CAN_MCR_NOTRDY_SHIFT                     27
#define CAN_MCR_HALT_MASK                        0x10000000u
#define CAN_MCR_HALT_SHIFT                       28
#define CAN_MCR_RFEN_MASK                        0x20000000u
#define CAN_MCR_RFEN_SHIFT                       29
#define CAN_MCR_FRZ_MASK                         0x40000000u
#define CAN_MCR_FRZ_SHIFT                        30
#define CAN_MCR_MDIS_MASK                        0x80000000u
#define CAN_MCR_MDIS_SHIFT                       31
/* CTRL1 Bit Fields */
#define CAN_CTRL1_PROPSEG_MASK                   0x7u
#define CAN_CTRL1_PROPSEG_SHIFT                  0
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PROPSEG_SHIFT))&CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       0x8u
#define CAN_CTRL1_LOM_SHIFT                      3
#define CAN_CTRL1_LBUF_MASK                      0x10u
#define CAN_CTRL1_LBUF_SHIFT                     4
#define CAN_CTRL1_TSYN_MASK                      0x20u
#define CAN_CTRL1_TSYN_SHIFT                     5
#define CAN_CTRL1_BOFFREC_MASK                   0x40u
#define CAN_CTRL1_BOFFREC_SHIFT                  6
#define CAN_CTRL1_SMP_MASK                       0x80u
#define CAN_CTRL1_SMP_SHIFT                      7
#define CAN_CTRL1_RWRNMSK_MASK                   0x400u
#define CAN_CTRL1_RWRNMSK_SHIFT                  10
#define CAN_CTRL1_TWRNMSK_MASK                   0x800u
#define CAN_CTRL1_TWRNMSK_SHIFT                  11
#define CAN_CTRL1_LPB_MASK                       0x1000u
#define CAN_CTRL1_LPB_SHIFT                      12
#define CAN_CTRL1_CLKSRC_MASK                    0x2000u
#define CAN_CTRL1_CLKSRC_SHIFT                   13
#define CAN_CTRL1_ERRMSK_MASK                    0x4000u
#define CAN_CTRL1_ERRMSK_SHIFT                   14
#define CAN_CTRL1_BOFFMSK_MASK                   0x8000u
#define CAN_CTRL1_BOFFMSK_SHIFT                  15
#define CAN_CTRL1_PSEG2_MASK                     0x70000u
#define CAN_CTRL1_PSEG2_SHIFT                    16
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG2_SHIFT))&CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     0x380000u
#define CAN_CTRL1_PSEG1_SHIFT                    19
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG1_SHIFT))&CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       0xC00000u
#define CAN_CTRL1_RJW_SHIFT                      22
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RJW_SHIFT))&CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   0xFF000000u
#define CAN_CTRL1_PRESDIV_SHIFT                  24
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PRESDIV_SHIFT))&CAN_CTRL1_PRESDIV_MASK)
/* TIMER Bit Fields */
#define CAN_TIMER_TIMER_MASK                     0xFFFFu
#define CAN_TIMER_TIMER_SHIFT                    0
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_TIMER_TIMER_SHIFT))&CAN_TIMER_TIMER_MASK)
/* RXMGMASK Bit Fields */
#define CAN_RXMGMASK_MG_MASK                     0xFFFFFFFFu
#define CAN_RXMGMASK_MG_SHIFT                    0
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXMGMASK_MG_SHIFT))&CAN_RXMGMASK_MG_MASK)
/* RX14MASK Bit Fields */
#define CAN_RX14MASK_RX14M_MASK                  0xFFFFFFFFu
#define CAN_RX14MASK_RX14M_SHIFT                 0
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX14MASK_RX14M_SHIFT))&CAN_RX14MASK_RX14M_MASK)
/* RX15MASK Bit Fields */
#define CAN_RX15MASK_RX15M_MASK                  0xFFFFFFFFu
#define CAN_RX15MASK_RX15M_SHIFT                 0
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX15MASK_RX15M_SHIFT))&CAN_RX15MASK_RX15M_MASK)
/* ECR Bit Fields */
#define CAN_ECR_TXERRCNT_MASK                    0xFFu
#define CAN_ECR_TXERRCNT_SHIFT                   0
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_TXERRCNT_SHIFT))&CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    0xFF00u
#define CAN_ECR_RXERRCNT_SHIFT                   8
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_RXERRCNT_SHIFT))&CAN_ECR_RXERRCNT_MASK)
/* ESR1 Bit Fields */
#define CAN_ESR1_WAKINT_MASK                     0x1u
#define CAN_ESR1_WAKINT_SHIFT                    0
#define CAN_ESR1_ERRINT_MASK                     0x2u
#define CAN_ESR1_ERRINT_SHIFT                    1
#define CAN_ESR1_BOFFINT_MASK                    0x4u
#define CAN_ESR1_BOFFINT_SHIFT                   2
#define CAN_ESR1_RX_MASK                         0x8u
#define CAN_ESR1_RX_SHIFT                        3
#define CAN_ESR1_FLTCONF_MASK                    0x30u
#define CAN_ESR1_FLTCONF_SHIFT                   4
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FLTCONF_SHIFT))&CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         0x40u
#define CAN_ESR1_TX_SHIFT                        6
#define CAN_ESR1_IDLE_MASK                       0x80u
#define CAN_ESR1_IDLE_SHIFT                      7
#define CAN_ESR1_RXWRN_MASK                      0x100u
#define CAN_ESR1_RXWRN_SHIFT                     8
#define CAN_ESR1_TXWRN_MASK                      0x200u
#define CAN_ESR1_TXWRN_SHIFT                     9
#define CAN_ESR1_STFERR_MASK                     0x400u
#define CAN_ESR1_STFERR_SHIFT                    10
#define CAN_ESR1_FRMERR_MASK                     0x800u
#define CAN_ESR1_FRMERR_SHIFT                    11
#define CAN_ESR1_CRCERR_MASK                     0x1000u
#define CAN_ESR1_CRCERR_SHIFT                    12
#define CAN_ESR1_ACKERR_MASK                     0x2000u
#define CAN_ESR1_ACKERR_SHIFT                    13
#define CAN_ESR1_BIT0ERR_MASK                    0x4000u
#define CAN_ESR1_BIT0ERR_SHIFT                   14
#define CAN_ESR1_BIT1ERR_MASK                    0x8000u
#define CAN_ESR1_BIT1ERR_SHIFT                   15
#define CAN_ESR1_RWRNINT_MASK                    0x10000u
#define CAN_ESR1_RWRNINT_SHIFT                   16
#define CAN_ESR1_TWRNINT_MASK                    0x20000u
#define CAN_ESR1_TWRNINT_SHIFT                   17
#define CAN_ESR1_SYNCH_MASK                      0x40000u
#define CAN_ESR1_SYNCH_SHIFT                     18
/* IMASK1 Bit Fields */
#define CAN_IMASK1_BUFLM_MASK                    0xFFFFFFFFu
#define CAN_IMASK1_BUFLM_SHIFT                   0
#define CAN_IMASK1_BUFLM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IMASK1_BUFLM_SHIFT))&CAN_IMASK1_BUFLM_MASK)
/* IFLAG1 Bit Fields */
#define CAN_IFLAG1_BUF4TO0I_MASK                 0x1Fu
#define CAN_IFLAG1_BUF4TO0I_SHIFT                0
#define CAN_IFLAG1_BUF4TO0I(x)                   (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF4TO0I_SHIFT))&CAN_IFLAG1_BUF4TO0I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    0x20u
#define CAN_IFLAG1_BUF5I_SHIFT                   5
#define CAN_IFLAG1_BUF6I_MASK                    0x40u
#define CAN_IFLAG1_BUF6I_SHIFT                   6
#define CAN_IFLAG1_BUF7I_MASK                    0x80u
#define CAN_IFLAG1_BUF7I_SHIFT                   7
#define CAN_IFLAG1_BUF31TO8I_MASK                0xFFFFFF00u
#define CAN_IFLAG1_BUF31TO8I_SHIFT               8
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF31TO8I_SHIFT))&CAN_IFLAG1_BUF31TO8I_MASK)
/* CTRL2 Bit Fields */
#define CAN_CTRL2_EACEN_MASK                     0x10000u
#define CAN_CTRL2_EACEN_SHIFT                    16
#define CAN_CTRL2_RRS_MASK                       0x20000u
#define CAN_CTRL2_RRS_SHIFT                      17
#define CAN_CTRL2_MRP_MASK                       0x40000u
#define CAN_CTRL2_MRP_SHIFT                      18
#define CAN_CTRL2_TASD_MASK                      0xF80000u
#define CAN_CTRL2_TASD_SHIFT                     19
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_TASD_SHIFT))&CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      0xF000000u
#define CAN_CTRL2_RFFN_SHIFT                     24
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RFFN_SHIFT))&CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_WRMFRZ_MASK                    0x10000000u
#define CAN_CTRL2_WRMFRZ_SHIFT                   28
/* ESR2 Bit Fields */
#define CAN_ESR2_IMB_MASK                        0x2000u
#define CAN_ESR2_IMB_SHIFT                       13
#define CAN_ESR2_VPS_MASK                        0x4000u
#define CAN_ESR2_VPS_SHIFT                       14
#define CAN_ESR2_LPTM_MASK                       0x7F0000u
#define CAN_ESR2_LPTM_SHIFT                      16
#define CAN_ESR�+���@\Z��˕�¬�a%�+w�A��~�� ���k1/�4�t�ހ"J��i͇0@��e� �R�+�
]-(�>BumrFH��ُO��B�r��[�h0��EU'\ɉ�MT�S�wa�+�*�#�ުHy�������Y�pq����1&}3ɸ� �}Y-��Tު)+�_$"�O>S`]�5��%�zcT�8rCoxt�mE�g���1U�d+�Q��k�E�>�"�\h:˙�[�Jq���G��De3�w���]3Ӛd��H.Z\k.� J(F�Ox镧Y��KCX����H,��C�y�U$��  ?%$�E�	!�4ݾ�Y��bu����V@-p�:�s<&F~t���}�*)|yNH�����ѶvKF�Qբ�����@8k�u�K�4�ORQ�įc�2���"�gp�\Q�%m���Z��*��?���N�۬яԉc3$�����k��UNt`vr,�(j���⬲�����La���ް��.���(���K�;o{�1�4���O�������!+Ғ�!Qrw>����ʛ�'�#㦔0�J�tF^�H��_C���뷮����ٽ��|�8���o��=S_Ҧ�(�3�M�k=$[fVOv�ϖ�D|Q~����}L�F��'E������I'՛�T� �J��q����CP�ˢ��U��+�H��U���T��Z�#�,*�{���*�6��ja�q�L�� ����=b������.��}D�^08"!ow/�����4彧�����D�0@ޯ�5��Q�#@���ʽo�6�?_ĦK�� �7�W�yv�r�� ��d��4��4�s��L��O!�^w;��\6�B�-ŲY����v�ح�1A&H�:#p�!O�u��؞li �؋o�E��3	���U�����z�O�\r�x��&cG׿Ej.�9n���"��?�n�~tF���d`	��#M�y|�&�5Ed���}���1{��P�*
�����7��f�
����)�c]IT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXFIR_IDHIT_SHIFT))&CAN_RXFIR_IDHIT_MASK)
/* CS Bit Fields */
#define CAN_CS_TIME_STAMP_MASK                   0xFFFFu
#define CAN_CS_TIME_STAMP_SHIFT                  0
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CS_TIME_STAMP_SHIFT))&CAN_CS_TIME_STAMP_MASK)
#define CAN_CS_DLC_MASK                          0xF0000u
#define CAN_CS_DLC_SHIFT                         16
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_DLC_SHIFT))&CAN_CS_DLC_MASK)
#define CAN_CS_RTR_MASK                          0x100000u
#define CAN_CS_RTR_SHIFT                         20
#define CAN_CS_IDE_MASK                          0x200000u
#define CAN_CS_IDE_SHIFT                         21
#define CAN_CS_SRR_MASK                          0x400000u
#define CAN_CS_SRR_SHIFT                         22
#define CAN_CS_CODE_MASK                         0xF000000u
#define CAN_CS_CODE_SHIFT     ��������a��^+h�b�\�s�o��ZЏS��ߋ��~��p8���ux�6����@��
4�O�v�]�����q���1�w/1�R�UMr#�����hm� G��x,�%s�%�e���/Ƀ*�r���f[�I�	�����G�E�Lw�;�D�5��`�!7��h_�O��z�0����6����G���ux ���ڠ��������-KZ��Զutcd�l2�*|���a�A��	|W���/��HDf���G�n|���x��"V}��7g]��*%K� n� i�OB� �?OxlS���yg����tξ+�u6���I3��K�;�M�H."T�V�OD��칏A`�
���]/>�Iy_jW]2[uEtf����ar�Oʹ��;jH,_��[3:?p1/����D�.�4A��E��ɉg�}2��(�XK�Ô��0��8r��57?6m���3XSLd���#)��_L��?g�_UR���b0����uBG���;��y�]<[w�D߯�ũa�'.����4t�<��R��0qc��m���(&����V�*��99�l�5��F��N��R�S4���$Ģ�� �Ĝk����ԴbU&���k����v�����-�|�o Մ�C��W���U�F4�T�.��d`��nҸFMP����7����K\�Δ����`30 ,��-��U�Za9�X�����u;b/B�#\�[�������$~��>J�E(�CJ��֔k�����92YU� Wʁ�)��5�.��h0��2Bg��bag
1�M$�W�ؚ�%HQ�Ǖ-$��F�r��mߒ!���*Y���l�|��h�4La+|����u�>�_ZmܢC�d�?�n����ct��C�1 �j�%D��V��.%��C��X�q��C�,�_
b��1�)My]IG6��nۋ��/i��p4�@��0M�kg�tC�I��9ŧ l�U���B��'�<���>���^�&]�X-������G<,�^�����VM�A�%���.��}In�~[�bV�'�g=�<�\t�+�؍}��.k����
��H�����
>�/;�n��<q W�i_��¼|�)�]D]�J��\h�?�\nw����J.�O?�����-�&��5��u���]V���飳�(�gm!��ᴎ��oG�l�#�RBK��x�� �b�j�j���<�䯋����s�B୊���/U�����r�*��=�	���6H��*ج6�����	:��o��c�~qtmP���ѧ!q�}~�4u���7� K��Mr4]Z��	�J�ԹDt����%Y0gT�{ͳ�fQDj�~s#7�:V�0�Q4��y�)�
w�G��p-�A�N�S�b�c��+K,�T:46`=j(K�f�3�		꬛Jj{�cWlb�F8�ϑSޒ���u��
�ZQG�醪��D��#{�����~.ZJ3؊�?+g���AP�V�c' `�a_�lC���nU�L�3��_9�T��|�e��7_�_�N��,ɼ��7|2�׬��94ҧ4��v��"aVJ�SԼ�'^&l�d�u��;� �jճf����^�>Qrb��Ƹ�N�� +��zO?;����7�T�3sv8�P}5��.f(����;�m�?IX�T�v��2rF�O{U(�ö�F��9@x��*�J�P3�'�)𛢧'���\q�3�5�-Q�Y=2Ŏ�h��kEO��ō|�ٺT�p���J_<%=�����R�PA�(e*#�Jd ���k[���M������|Jl��.�e�����`Ǟ��?�p#�\x�����n� p�u>�
� �4�k���iݽUHq4��k�<�Y*�o�*�L���ds<V���f��rRo���d���[��Le��ڱ$pc�r�n��CK��M��G��f�;�:�ѴR-Y��w���O�5Uvwf��� ���J��d��7��wkH�UL���c�a8@�XPu=9�8�烪i��'ɚ U��c�-����,��JU�{0�x�]�4 1�e
�J�N���KԜ���CQ��Erw�Lw|W"d94g�Wm@�H�����;x��o��8��Wֱ���\� h�t�{s5��m�I�̄'�x���"�>ߦ�C���a��mG�ŤX�3����(9���T3+�P�.�`Fw>�ȍ��dឹ�N[
�^��G�dr�*�ߧ����2|hJp�����5F�G5�f'�;q=	�n�鴓ɥ�D�b2��1G��ٟɨ�!����4�Mߡx�Ŵ�Lv~��bB���3��x�T����c����d$��|6�l�䙘Ef����yڏR"&O(~2��b��Vkb�>�M��6аY��7"�6�J�'�b�R��B|#U���vL���apL\�c�Z�O�7z����m���� u��p$?zNe�b� n^E���)#i!6O�i|�.=��9��5�����&��4v
1i.�|pf��?ʨ��_��G�p�(�&x�pv�f־��\}dXf�������>@��}Gq'�o��yW��rr|�r����:hef�_Ie�@B1��j�\��^�S8�K�]r��*58�:��B������:ݼ�
B��7A2�p!�v�A����,�H���8h��G{߿��?�Q��֬�A��:d;�A��7z�ݛ���&h%l��V��X+:��Ӏ��K���fE)�#b׽��>�O+��+ ���N�k�Su�&�M�)OL"*fH3&2���C�)�_\�hX���x���1���P�F۾T�>���y�6�G�_��7�s�LIz�Q��]�"fދ��W2q���f�x����R�����&;r��$j��`{ܞ�A7��\`�Q$�?s|l�1(5v'�xDwˋ�����;�9hꎫ\��m�r�2��Alcj)��o�3J�� � 0��kmJ�CG�+���E�E�6H��/��P2l���o����aBҲ�O�            (((uint32_t)(((uint32_t)(x))<<CAN_RXIMR_MI_SHIFT))&CAN_RXIMR_MI_MASK)

/**
 * @}
 */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base pointer */
#define CAN0_BASE_PTR                            ((CAN_MemMapPtr)0x40024000u)
/** Peripheral CAN1 base pointer */
#define CAN1_BASE_PTR                            ((CAN_MemMapPtr)0x400A4000u)
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0_BASE_PTR, CAN1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register instance definitions */
/* CAN0 */
#define CAN0_MCR                                 CAN_MCR_REG(CAN0_BASE_PTR)
#define CAN0_CTRL1     ��������a��^+h�b�\�s�o��ZЏS��ߋ��~��p8���ux�6����@��
4�O�v�]�����q���1�w/1�R�UMr#�����hm� G��x,�%s�%�e���/Ƀ*�r���f[�I�	�����G�E�Lw�;�D�5��`�!7��h_�O��z�0����6����G���ux ���ڠ��������-KZ��Զutcd�l2�*|���a�A��	|W���/��HDf���G�n|���x��"V}��7g]��*%K� n� i�OB� �?OxlS���yg����tξ+�u6���I3��K�;�M�H."T�V�OD��칏A`�
���]/>�Iy_jW]2[uEtf����ar�Oʹ��;jH,_��[3:?p1/����D�.�4A��E��ɉg�}2��(�XK�Ô��0��8r��57?6m���3XSLd���#)��_L��?g�_UR���b0����uBG���;��y�]<[w�D߯�ũa�'.����4t�<��R��0qc��m���(&����V�*��99�l�5��F��N��R�S4���$Ģ�� �Ĝk����ԴbU&���k����v�����-�|�o Մ�C��W���U�F4�T�.��d`��nҸFMP����7����K\�Δ����`30 ,��-��U�Za9�X�����u;b/B�#\�[�������$~��>J�E(�CJ��֔k�����92YU� Wʁ�)��5�.��h0��2Bg��bag
1�M$�W�ؚ�%HQ�Ǖ-$��F�r��mߒ!���*Y���l�|��h�4La+|����u�>�_ZmܢC�d�?�n����ct��C�1 �j�%D��V��.%��C��X�q��C�,�_
b��1�)My]IG6��nۋ��/i��p4�@��0M�kg�tC�I��9ŧ l�U���B��'�<���>���^�&]�X-������G<,�^�쐦cv��4���x��/���g�i;(�TEV� ��G5�ˆ���v�^!;$��d��ԓ譜���a�Ƀ۳p�%�+�|����&��t&�;��)��S�V?� ���nT�)��`I���w]3��49�y'+��h�i� T������n폀��B���E!ǃ��%T0r������^�0�e-F߻!N5=n 5SF�t}'K�����F���uV
�I�+��6�5s���Ԙ�6�A�f�����} ��T�ejc+�xBD�c���{Lm6#VB#*;6�ۅ.)���*3'�\0�zʲ*JdU{p+��ra��փ����֗������{�����/�E��`bo=�P��5�P�bQ����4��7��%=���/(O���k�_!�T�jT�;[�b݈!�d8'��Ǌ �L9�|��|�PS*K8�9u)�FD���s1��3�p+�/�4d��x;�d�㤚����6`�{���+�On̕�%ݡ������aajZ������+� �Ń��`�l�fX27L�9���Ƭ�D��8���D�E}�������Y���m�7�f0X��j�xq��RU��	#r��jҏ�]lj5ݾ)]�� &U�nT��@��K%��$X�Gnh�lҿf�-�G�_�����Н�l�`8DTS�a��f��s��y4�[�p �9����N�d�k1��]b��Ɲ��~_a@�"Ѐn�|$�OZO�a���K��=.�_�8�R�����\LK�
���c��L�w	�dxj�m,��c}����d'Ŗ{������dI����fy���*�^���`�R�\_�	��.���/zbP��������WR-:���d	�0���8���TQC�EC�.��Ƴ~f�����(��<���>֖�P�$C�G��sr��X;�&󼅠�6HǕG']�Ӆ*���[��!��rn���X�Ib�e|��Ξ{Y��
��Y/�^J�{�v������Y-�kGefine CAN0_CS3                                 CAN_CS_REG(CAN0_BASE_PTR,3)
#define CAN0_ID3                                 CAN_ID_REG(CAN0_BASE_PTR,3)
#define CAN0_WORD03                              CAN_WORD0_REG(CAN0_BASE_PTR,3)
#define CAN0_WORD13                              CAN_WORD1_REG(CAN0_BASE_PTR,3)
#define CAN0_CS4                                 CAN_CS_REG(CAN0_BASE_PTR,4)
#define CAN0_ID4                                 CAN_ID_REG(CAN0_BASE_PTR,4)
#define CAN0_WORD04                              CAN_WORD0_REG(CAN0_BASE_PTR,4)
#define CAN0_WORD14                              CAN_WORD1_REG(CAN0_BASE_PTR,4)
#define CAN0_CS5                                 CAN_CS_REG(CAN0_BASE_PTR,5)
#define CAN0_ID5                                 CAN_ID_REG(CAN0_BASE_PTR,5)
#define CAN0_WORD05                              CAN_WORD0_REG(CAN0_BASE_PTR,5)
#define CAN0_WORD15                              CAN_WORD1_REG(CAN0_BASE_PTR,5)
#define CAN0_CS6                                 CAN_CS_REG(CAN0_BASE_PTc?q\N�L��RAsF�����C��$;����>jX~�.��P�I�5�項��9��Ю7��7�{���<NJ<�����P�'�sS��`}ZR�_��E8��S9��y1汪d���QL��o*ģ�/#�	b{��6µ~R�֥bU��f~=�<��m"��>)t��џ�Qk����@����)�*W_�9S�c�-�	����.¸������� M��z.yD�dL#�52�̺׍�ЋWqh�;���=��L�=���R:Se|#P'(uà��
�<��cހ��i#'�9iKņ)���N������Cvvhh��9��_/"�������"�-��9yi��S��ElX���m}��l��fDv�o:��)z�*ᮮ~��S�z�b�e�^2a$V�x)��SJ��O@�c��(�L�j�1�+#!���{- !�����|�E]t&n(��m��8i6�I*z1�����Y�>:z�]����:m�nh^���`��7�.���<�[L�j�=<�m����h�&��� ���BY&c���d��I�
�-��Q���-����j�����8�I�/�c���m�R�����!��?�i�c�b���cQ)�\"�!��q_���Ǥ2eM����iY�1��mIi�+:c⁸�<?� \�@�CNC��Y]��a3�����+/�㔌�,.������Yؾ�ҽ;�u� ʫd��KL+��]����X�A�����3*��)�@�x�K��U�֟��}yw�i�[ܶ��&�B���d���r�d�������%��uF�z̩׆��h|4�A�2�/�x��.��/c�)WZ<�%�����kd�R���@�糙BQ@_�����!��G�,�Z;��(�b���rpr�S D$�;D3��wy)o��f=-|{�z@�a�S0��6��M������6���iW��[�/1�y��bĎ��8>aҳ嬋4'}���#�|l����7����w�6%_BASE_PTR,9)
#defyne CAN0_WORD�           !      !           CAN_WORL0_REG(CAN0_BASE_PPR,9)
#defale CANp_WORD19                     0     $  CAN_WORD1_rEG(CAN0_BASE_PTR,9)
#defyne CAN0_CS10 0                      !       CAN_CS�REG(CAN0_BASE_PTR,10)
#def)ne GAN0_IF10         (                      CAN_AD[REG(CAN0_BASE[PTR,10)
#dEfine CAF0_wORD010       �       !             CAN_WORD0_REG(CAN0_@ASE_PTR,10)
#define CAN0_WORD910             !               CAN_WORD1_REG(CAN2_BQSE_PTR,10)
#define GAN0_CS1     !                        " CAN_AS_REG(CAN0_BAS�_PTR,11)
#define CAN0_ID11                  ! 0 0         CAN_ID_REG(CAN0_BAsE_PTR,11)
#define CAN0_WORD011    (                        CAN_WORD0_REG(CAN0_BASE_PTR,�1)
#define CAN0_WORD111                             CAN_WORD1oREG,CAN0_BASE_PTR,11)
#defi.e CQN0_CR12                     0  0       CAN_CS_REG(CAN0_BAQE_PTR,12)
#tefine CAN0_ID12                 (              CAN_ID_REG(CAN0_BASE_PTR,12)
#define CAN0_WORD012  0          `               CAN_VORD0_REG(CAN0_BASE_PTR,12)
#define CAN0OWORL112                      `  !   CaN_WORD1_REG(KAF0_BASE_PTR,12)
#define CAN0_CS13      $                         CAN_CS_RGhCAN0_BASM_PTr,13)
#d%fin� CAN0_ID13   `                            CAN_IE_RMG(CAN0_BASE_PTR,1s)
#tefine CAN0_WORL013    $ !          0         � CAN_WORD0_REG(CAN0_BASE_PTR,13)
#define CAN0_WORD113          `     �         $  CAN_WORD1_REG(CAN0WBASE_PTR,13)
#define CAN0_CS14                             !  CAN_CS_REG(CAN0_BASE_PTZ14	
#define CAN0_ID14                             `  CAN_ID_REG(CAN0[BASE_PTR,14)
#define CAN0_WORL014   0              � `        CAN_WORD0_REG(CAN0_BASE_PTR,94)
#define CAN _WORD114                             CAN_WORD1_REG(CAN0_BASE_PTR,14)
#define CAN0_CS15      $(                        CAN_CS_REG(CAN0_B�SE_PTR,15)
#define CAN0_ID15                                CAN_ID_REG(CAN0_BASE_PTR,15)
#define CAN0_WORD0150           �                CAN_WORD0_REG(CQN0_BASE_PTR,15)
#define CAN0_WORD115                             CAN_WORD1_REG(CAN0_BASE_PTR,15)
#define CAN0_RXIMR0                              CAN_RXIMR_REG(CAN0_BASE_PTR,0)
#define CAN0_RXIMR1                              CAN_RXIMR_REG(CAN0_BASE_PTR,1)
#define CAN0_RXIMR2                              CAN_RXIMR_REG(CAN0_BASE_PTR,2)
#define CAN0_RXIMR3                              CAN_RXIMR_REG(CAN0_BASE_PTR,3)
#define CAN0_RXIMR4                              CAN_RXIMR_REG(CAN0_BASE_PTR,4)
#define CAN0_RXIMR5                              CAN_RXIMR_REG(CAN0_BASE_PTR,5)
#define CAN0_RXIMR6                              CAN_RXIMR_REG(CAN0_BASE_PTR,6)
#define CAN0_RXIMR7                              CAN_RXIMR_REG(CAN0_BASE_PTR,7)
#define CAN0_RXIMR8                              CAN_RXIMR_REG(CAN0_BASE_PTR,8)
#define CAN0_RXIMR9                              CAN_RXIMR_REG(CAN0_BASE_PTR,9)
#define CAN0_RXIMR10                             CAN_RXIMR_REG(CAN0_BASE_PTR,10)
#define CAN0_RXIMR11                             CAN_RXIMR_REG(CAN0_BASEOPTR,11)
#define CAN0^RXIMR12  0               " `        CAN_RXIMR_REG(CAN0_BASE_PT�,12(
#define C�N0_RXIMR53     �        (�   $         CAN_RXIMR_REG(CAN0_BASE_PTR,13)
#define CAN0_RXIMR14                !   !   $ �  CAN_RXI]R_REG(CAN0]BASG_PTR,14)
#define CAN0_RXIMR15         � $        p  ( "`  CAN_RXK�R_REG(CAN0_BESE_PTR,15)
/* CAN1 */
#def)ne CA1_MCR                                 CAN_MCR_REG(CAN1_BASE_PTP)
#define CAN1_CTRL1                               CAN_CTRL1_REG(CAN1_BASE_PTR)
#defing CAN1_IMER                   0 $ �       CAN_TIMER_REG(CAN1_BASEWPTR)
#define CAN1_RXMGMASK   0                �       CAN_RHMGMASK_REG(CQN1_BASG_�TR)
�deFiNe CAN1_RX14MASK                            CAN_RX14MAS[_REG(CAn1_BASE_PTR)
#de&ine CAN1�RX15MASK  `                      �  CAN_�X�5MASK_REG(CAN1_BASE_�TR)
#define SAN1_ECR                                 CAN_ECR_REG(CAN1[BESE_PTR)
#define CAN1_ESR1        `   0                   CAN_ESR1_REG CAN1_BAS�_PTR)
#define CAN1_IMASK1     �      `                 CAN_IMASK1_REG(CAN1_BASG_PTR)
#define CAN1_IFLAG1             "                CAN_]FLAG1_REG(AN1_BASE_PTR)
#define CAN1_CTRL2         ( 0                   SAN_CTRL2_REG(CAN1]BASE[PTR)
cdefine CAn1_ESR2                "         00    CAN_ESR2REG(CAN1_BASE_PTR)
#lefine C�N1_cSCR                                CAN_CRCX_REG(CAN1_BASE_PVR)
#define CAN1_RXFWMASK                          " CAN_RXFGmASK_REG(CAN1_BASE�PTR-
#define GQN1_RXFIR         "(          (     �   CAN^RXFIR_REG(S@N1_BASE_PTR)
#defije CAN1_CS0      (                          CAN_CS_REG(CAN1_BASE_PTR,0)
#def)ne CAN1_ID0                  �              CAN_ID_REG(CAJ1_BASE_PTR,0)
#define�CAN1_WORD00                              CAN_wORD0_REW(CAN1_BESE_PTR,0)�+define CAN1_WORD10                              CAN_WORD1_REG(CAN1_BASE_PTR,4	
#define CAN1_CS1             !       `           CAO_CS_SEG(CAN1_BASE_PTR,1)
#define0CAN1_ID1 8     $        �      `         CAN_ID_ZEG(CAN1_�ASE_PTR,1)#$efine CA1_WORE01                              CAN_WORD0_REG(CAN1_BASE_PTR,1)
#ddfine CAN1_WORD11               "      " �     CAN_WORD1_REG(CAN1_BASE_TTR,1)
#define CAN1_CS2             0                 � CAN_CS_REG(CAN1_BASE_PTR,2)
#define CAN1SID2                                 CAN_ID_REF(BA^1_BASE_PTR,2)
#d�fine CA1_WORD02!   `                    $    CAN_WORD0_REG*CAN1_BaSE_PTR,2)
#definE CAN1_WORD12                        �     CA�_WORD1_REG(CAN1_BASE_PTR,2)
!define"CAN1_CS2                                 CAN_CS_REG(CAN1_BASE_PTR,3)
#defi~e CAN1_ID3                                 CAN[ID_REG(CAN1_BASE_PTR,7)
#define CAN1_WORD03 !                            CAN_WGZD0_RG(CAN1_BAS_PTR,3)
#degine CAN1_UORD13  0                           CAnWORD1_REE(CAN1_B�SE_pTR,3)
#define CAN1_CS4        !                    "   CAN_CS_REG(CAN1_BASE_PT,4)
#denine CQF1_ID4                  ``  0        ( CAN_ID_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD04                        0     CAN_WORD0_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD340                     !       CPN_WORD1_REG(AAN1_BASE_PTR,4)
#define CAN1_CS5                                 CAN_CS_REG(CN1_BASE_PTZ,5)
#define CAL1_ID5             �                $  CAN_ID_REG(CAN1_BASE_PTR,5)
#define CAN1_WORD05     0�   0                   CANOWORDp_REG(CAN1_BASE_PTR,5)
#define CAN1_ORD15          "   �               CAN_wORD1_REG(CAN1[CASD_PTR,5)
define CAN1_CS6       �       (       `         CAN_CS_REG(CAN1_BASE_PTR,6)
#define CAN1_ID6                   (             CAN_ID_R�G(CAN1_BASE_PTR,6)
#$efine CAN1_WORD06       $ (  0            (    CAN_WORD0_REG(CAN1_BASE_PTR,6+
#definm CAN1_WOVD16 0              0             CAN]WORD1_REG(CAN1_BASE_PTR,6)
#define CAN1_CS7        0                        CAN_CS_REG(CAN1_BASE_PTR,7)
#dgfing CAN1_ID7                                 CAN_IDWREG(CAN5_BASE_PTR,7)
#define CAN1_WORD07        (  00  0              CAN_WORD0OREG(CAN1_RASE_PTR,7)
#define"CAN1__OrD17                    "         CAN_WORD1_REO(BAN1_BASE_PTR,7)
#define(CAO3_CS4                                 CAN_CS_REG(CAN1_BASE_PTB,8)
#lefine CAN!]ID8  �  (                 �         CAN_ID_REG(CAN1_BASE_PTR,x)
#define CAN1_WORD00             !         (      CAN_wORD0_REG(CAN1_BASE_PTZ<8)
#define CAN1_WOR@18                             (CAN_WORD1_REG(CAN1_BASE_PTR,8)#defi.e CAN1_CS9     (        (            (     CAN_C�_REǨCAN1_BAWE_PTR,9)
#def)ne0CAN1_IF9         !            (          CAN_ID_REG8CAN1_BASE_PTR,9)
#de&ine CAN1_WORD09                     �0       CAN_WOD0_RUG(CAN1_BASE_PTR,9)
#dufhne CAN1_WORD1=                 �            CAN_WMRD1_REG(CAN1_BASE_PTR,9)
#define CAN1_CS10   ��                           CAN_CS_VE(CAN1_BASEPTR,10�
#define CA�1_ID10                                CAN_ID_REG(CAN1_BASE_PTR,10)
#define CaN1_WORD010     `                     ( CAN_WORD0_REG(CAN1_BISE_PTR,10)
#debhne CEN1_WKRD110            "      !         CAN_WORE1_REG(CAF1_BASE_PTR,10)
#define CAN1_CS1                                CAN_CS_REG(CAN1_BASE_PVR,13)
#define CAN1_ID11                                CAN_ID_REG(CAN1_BASE_PTR,11)
#define CAN1_WORD011                             CAN_WORD0_REG(CAN1_BASE_PTR,11)
#define CAN1_WORD111                             CAN_WORD1_REG(CAN1_BASE_PTR,11)
#define CAN1_CS12                                CAN_CS_REG(CAN1_BASE_PTR,12)
#define CAN1_ID12                                CAN_ID_REG(CAN1_BASE_PTR,12)
#define CAN1_WORD012                             CAN_WORD0_REG(CAN1_BASE_PTR,12)
#define CAN1_WORD112                             CAN_WORD1_REG(CAN1_BASE_PTR,12)
#define CAN1_CS13                                CAN_CS_REG(CAN1_BASE_PTR,13)
#define CAN1_ID13                                CAN_ID_REG(CAN1_BASE_PTR,13)
#define CAN1_WORD013                             CAN_WORD0_REG(CAN1_BASE_PTR,13)
#define CAN1_WORD113                             CAN_WORD1_REG(CAN1_BASE_PTR,13)
#define CAN1_CS14                                CAN_CS_REG(CAN1_BASE_PTR,14)
#define CAN1_ID14                                CAN_ID_REG(CAN1_BASE_PTR,14)
#define CAN1_WORD014                             CAN_WORD0_REG(CAN1_BASE_PTR,14)
#define CAN1_WORD114                             CAN_WORD1_REG(CAN1_BASE_PTR,14)
#define CAN1_CS15                                CAN_CS_REG(CAN1_BASE_PTR,15)
#define CAN1_ID15                                CAN_ID_REG(CAN1_BASE_PTR,15)
#define CAN1_WORD015                             CAN_WORD0_REG(CAN1_BASE_PTR,15)
#define CAN1_WORD115                             CAN_WORD1_REG(CAN1_BASE_PTR,15)
#define CAN1_RXIMR0                              CAN_RXIMR_REG(CAN1_BASE_PTR,0)
#define CAN1_RXIMR1                              CAN_RXIMR_REG(CAN1_BASE_PTR,1)
#define CAN1_RXIMR2                              CAN_RXIMR_REG(CAN1_BASE_PTR,2)
#define CAN1_RXIMR3                              CAN_RXIMR_REG(CAN1_BASE_PTR,3)
#define CAN1_RXIMR4                              CAN_RXIMR_REG(CAN1_BASE_PTR,4)
#define CAN1_RXIMR5                              CAN_RXIMR_REG(CAN1_BASE_PTR,5)
#define CAN1_RXIMR6                              CAN_RXIMR_REG(CAN1_BASE_PTR,6)
#define CAN1_RXIMR7                              CAN_RXIMR_REG(CAN1_BASE_PTR,7)
#define CAN1_RXIMR8                              CAN_RXIMR_REG(CAN1_BASE_PTR,8)
#define CAN1_RXIMR9                              CAN_RXIMR_REG(CAN1_BASE_PTR,9)
#define CAN1_RXIMR10                             CAN_RXIMR_REG(CAN1_BASE_PTR,10)
#define CAN1_RXIMR11                             CAN_RXIMR_REG(CAN1_BASE_PTR,11)
#define CAN1_RXIMR12                             CAN_RXIMR_REG(CAN1_BASE_PTR,12)
#define CAN1_RXIMR13                             CAN_RXIMR_REG(CAN1_BASE_PTR,13)
#define CAN1_RXIMR14                             CAN_RXIMR_REG(CAN1_BASE_PTR,14)
#define CAN1_RXIMR15                             CAN_RXIMR_REG(CAN1_BASE_PTR,15)

/* CAN - Register array accessors */
#define CAN0_CS(index)                           CAN_CS_REG(CAN0_BASE_PTR,index)
#define CAN1_CS(index)                           CAN_CS_REG(CAN1_BASE_PTR,index)
#define CAN0_ID(index)                           CAN_ID_REG(CAN0_BASE_PTR,index)
#define CAN1_ID(index)                           CAN_ID_REG(CAN1_BASE_PTR,index)
#define CAN0_WORD0(index)                        CAN_WORD0_REG(CAN0_BASE_PTR,index)
#define CAN1_WORD0(index)                        CAN_WORD0_REG(CAN1_BASE_PTR,index)
#define CAN0_WORD1(index)                        CAN_WORD1_REG(CAN0_BASE_PTR,index)
#define CAN1_WORD1(index)                        CAN_WORD1_REG(CAN1_BASE_PTR,index)
#define CAN0_RXIMR(index)                        CAN_RXIMR_REG(CAN0_BASE_PTR,index)
#define CAN1_RXIMR(index)                        CAN_RXIMR_REG(CAN1_BASE_PTR,index)

/**
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CAN_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMP
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Peripheral CMP
 * @{
 */

/** CMP - Peripheral register structure */
typedef struct CMP_MemMap {
  uint8_t CR0;                                     /**< CMP Control Register 0, offset: 0x0 */
  uint8_t CR1;                                     /**< CMP Control Register 1, offset: 0x1 */
  uint8_t FPR;                                     /**< CMP Filter Period Register, offset: 0x2 */
  uint8_t SCR;                                     /**< CMP Status and Control Register, offset: 0x3 */
  uint8_t DACCR;                                   /**< DAC Control Register, offset: 0x4 */
  uint8_t MUXCR;                                   /**< MUX Control Register, offset: 0x5 */
} volatile *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register accessors */
#define CMP_CR0_REG(base)                        ((base)->CR0)
#define CMP_CR1_REG(base)                        ((base)->CR1)
#define CMP_FPR_REG(base)                        ((base)->FPR)
#define CMP_SCR_REG(base)                        ((base)->SCR)
#define CMP_DACCR_REG(base)                      ((base)->DACCR)
#define CMP_MUXCR_REG(base)                      ((base)->MUXCR)

/**
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/* CR0 Bit Fields */
#define CMP_CR0_HYSTCTR_MASK                     0x3u
#define CMP_CR0_HYSTCTR_SHIFT                    0
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK)
#define CMP_MUXCR_PSTM_MASK                      0x40u
#define CMP_MUXCR_PSTM_SHIFT                     6

/**
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base pointer */
#define CMP0_BASE_PTR                            ((CMP_MemMapPtr)0x40073000u)
/** Peripheral CMP1 base pointer */
#define CMP1_BASE_PTR                            ((CMP_MemMapPtr)0x40073008u)
/** Peripheral CMP2 base pointer */
#define CMP2_BASE_PTR                            ((CMP_MemMapPtr)0x40073010u)
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0_BASE_PTR, CMP1_BASE_PTR, CMP2_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros
 * @{
 */


/* CMP - Register instance definitions */
/* CMP0 */
#define CMP0_CR0                                 CMP_CR0_REG(CMP0_BASE_PTR)
#define CMP0_CR1                                 CMP_CR1_REG(CMP0_BASE_PTR)
#define CMP0_FPR                                 CMP_FPR_REG(CMP0_BASE_PTR)
#define CMP0_SCR                                 CMP_SCR_REG(CMP0_BASE_PTR)
#define CMP0_DACCR                               CMP_DACCR_REG(CMP0_BASE_PTR)
#define CMP0_MUXCR                               CMP_MUXCR_REG(CMP0_BASE_PTR)
/* CMP1 */
#define CMP1_CR0                                 CMP_CR0_REG(CMP1_BASE_PTR)
#define CMP1_CR1                                 CMP_CR1_REG(CMP1_BASE_PTR)
#define CMP1_FPR                                 CMP_FPR_REG(CMP1_BASE_PTR)
#define CMP1_SCR                                 CMP_SCR_REG(CMP1_BASE_PTR)
#define CMP1_DACCR                               CMP_DACCR_REG(CMP1_BASE_PTR)
#define CMP1_MUXCR                               CMP_MUXCR_REG(CMP1_BASE_PTR)
/* CMP2 */
#define CMP2_CR0                                 CMP_CR0_REG(CMP2_BASE_PTR)
#define CMP2_CR1                                 CMP_CR1_REG(CMP2_BASE_PTR)
#define CMP2_FPR                                 CMP_FPR_REG(CMP2_BASE_PTR)
#define CMP2_SCR                                 CMP_SCR_REG(CMP2_BASE_PTR)
#define CMP2_DACCR                               CMP_DACCR_REG(CMP2_BASE_PTR)
#define CMP2_MUXCR                               CMP_MUXCR_REG(CMP2_BASE_PTR)

/**
 * @}
 */ /* end of group CMP_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CMP_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Peripheral CMT
 * @{
 */

/** CMT - Peripheral register structure */
typedef struct CMT_MemMap {
  uint8_t CGH1;                                    /**< CMT Carrier Generator High Data Register 1, offset: 0x0 */
  uint8_t CGL1;                                    /**< CMT Carrier Generator Low Data Register 1, offset: 0x1 */
  uint8_t CGH2;                                    /**< CMT Carrier Generator High Data Register 2, offset: 0x2 */
  uint8_t CGL2;                                    /**< CMT Carrier Generator Low Data Register 2, offset: 0x3 */
  uint8_t OC;                                      /**< CMT Output Control Register, offset: 0x4 */
  uint8_t MSC;                                     /**< CMT Modulator Status and Control Register, offset: 0x5 */
  uint8_t CMD1;                                    /**< CMT Modulator Data Register Mark High, offset: 0x6 */
  uint8_t CMD2;                                    /**< CMT Modulator Data Register Mark Low, offset: 0x7 */
  uint8_t CMD3;                                    /**< CMT Modulator Data Register Space High, offset: 0x8 */
  uint8_t CMD4;                                    /**< CMT Modulator Data Register Space Low, offset: 0x9 */
  uint8_t PPS;                                     /**< CMT Primary Prescaler Register, offset: 0xA */
  uint8_t DMA;                                     /**< CMT Direct Memory Access Register, offset: 0xB */
} volatile *CMT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros
 * @{
 */


/* CMT - Register accessors */
#define CMT_CGH1_REG(base)                       ((base)->CGH1)
#define CMT_CGL1_REG(base)                       ((base)->CGL1)
#define CMT_CGH2_REG(base)                       ((base)->CGH2)
#define CMT_CGL2_REG(base)                       ((base)->CGL2)
#define CMT_OC_REG(base)                         ((base)->OC)
#define CMT_MSC_REG(base)                        ((base)->MSC)
#define CMT_CMD1_REG(base)                       ((base)->CMD1)
#define CMT_CMD2_REG(base)                       ((base)->CMD2)
#define CMT_CMD3_REG(base)                       ((base)->CMD3)
#define CMT_CMD4_REG(base)                       ((base)->CMD4)
#define CMT_PPS_REG(base)                        ((base)->PPS)
#define CMT_DMA_REG(base)                        ((base)->DMA)

/**
 * @}
 */ /* end of group CMT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Masks CMT Register Masks
 * @{
 */

/* CGH1 Bit Fields */
#define CMT_CGH1_PH_MASK                         0xFFu
#define CMT_CGH1_PH_SHIFT                        0
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK)
/* CGL1 Bit Fields */
#define CMT_CGL1_PL_MASK                         0xFFu
#define CMT_CGL1_PL_SHIFT                        0
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK)
/* CGH2 Bit Fields */
#define CMT_CGH2_SH_MASK                         0xFFu
#define CMT_CGH2_SH_SHIFT                        0
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK)
/* CGL2 Bit Fields */
#define CMT_CGL2_SL_MASK                         0xFFu
#define CMT_CGL2_SL_SHIFT                        0
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK)
/* OC Bit Fields */
#define CMT_OC_IROPEN_MASK                       0x20u
#define CMT_OC_IROPEN_SHIFT                      5
#define CMT_OC_CMTPOL_MASK                       0x40u
#define CMT_OC_CMTPOL_SHIFT                      6
#define CMT_OC_IROL_MASK                         0x80u
#define CMT_OC_IROL_SHIFT                        7
/* MSC Bit Fields */
#define CMT_MSC_MCGEN_MASK                       0x1u
#define CMT_MSC_MCGEN_SHIFT                      0
#define CMT_MSC_EOCIE_MASK                       0x2u
#define CMT_MSC_EOCIE_SHIFT                      1
#define CMT_MSC_FSK_MASK                         0x4u
#define CMT_MSC_FSK_SHIFT                        2
#define CMT_MSC_BASE_MASK                        0x8u
#define CMT_MSC_BASE_SHIFT                       3
#define CMT_MSC_EXSPC_MASK                       0x10u
#define CMT_MSC_EXSPC_SHIFT                      4
#define CMT_MSC_CMTDIV_MASK                      0x60u
#define CMT_MSC_CMTDIV_SHIFT                     5
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK)
#define CMT_MSC_EOCF_MASK                        0x80u
#define CMT_MSC_EOCF_SHIFT                       7
/* CMD1 Bit Fields */
#define CMT_CMD1_MB_MASK                         0xFFu
#define CMT_CMD1_MB_SHIFT                        0
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK)
/* CMD2 Bit Fields */
#define CMT_CMD2_MB_MASK                         0xFFu
#define CMT_CMD2_MB_SHIFT                        0
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK)
/* CMD3 Bit Fields */
#define CMT_CMD3_SB_MASK                         0xFFu
#define CMT_CMD3_SB_SHIFT                        0
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK)
/* CMD4 Bit Fields */
#define CMT_CMD4_SB_MASK                         0xFFu
#define CMT_CMD4_SB_SHIFT                        0
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK)
/* PPS Bit Fields */
#define CMT_PPS_PPSDIV_MASK                      0xFu
#define CMT_PPS_PPSDIV_SHIFT                     0
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK)
/* DMA Bit Fields */
#define CMT_DMA_DMA_MASK                         0x1u
#define CMT_DMA_DMA_SHIFT                        0

/**
 * @}
 */ /* end of group CMT_Register_Masks */


/* CMT - Peripheral instance base addresses */
/** Peripheral CMT base pointer */
#define CMT_BASE_PTR                             ((CMT_MemMapPtr)0x40062000u)
/** Array initializer of CMT peripheral base pointers */
#define CMT_BASE_PTRS                            { CMT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros
 * @{
 */


/* CMT - Register instance definitions */
/* CMT */
#define CMT_CGH1                                 CMT_CGH1_REG(CMT_BASE_PTR)
#define CMT_CGL1                                 CMT_CGL1_REG(CMT_BASE_PTR)
#define CMT_CGH2                                 CMT_CGH2_REG(CMT_BASE_PTR)
#define CMT_CGL2                                 CMT_CGL2_REG(CMT_BASE_PTR)
#define CMT_OC                                   CMT_OC_REG(CMT_BASE_PTR)
#define CMT_MSC                                  CMT_MSC_REG(CMT_BASE_PTR)
#define CMT_CMD1                                 CMT_CMD1_REG(CMT_BASE_PTR)
#define CMT_CMD2                                 CMT_CMD2_REG(CMT_BASE_PTR)
#define CMT_CMD3                                 CMT_CMD3_REG(CMT_BASE_PTR)
#define CMT_CMD4                                 CMT_CMD4_REG(CMT_BASE_PTR)
#define CMT_PPS                                  CMT_PPS_REG(CMT_BASE_PTR)
#define CMT_DMA                                  CMT_DMA_REG(CMT_BASE_PTR)

/**
 * @}
 */ /* end of group CMT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CMT_Peripheral */


/* ----------------------------------------------------------------------------
   -- CRC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Peripheral CRC
 * @{
 */

/** CRC - Peripheral register structure */
typedef struct CRC_MemMap {
  union {                                          /* offset: 0x0 */
    struct {                                         �W��|杼L��t�����H�fA����x�f�g�b[c���m�~`c�a�~O��\�����&��/u(6��M�D�L&��Hr�-�Aб�p��+>>�̊�E�E0�k�i�/r/y�8�F(TWh��9��1�4�ʇ���f=��b$�%�us��d�4������M1ޟp�{��V�D�Z;ɵE��3an��t>t��4��@�4�Ny�@��V/�:��S��l����yh�Rqz�M���x��w�������m͢'�عU�N�ԭ�=�E4N�ͣ�R����T�U#�ϝ���w)l�ß,HoO&��v�po8�n�§$�Sɧ�&�I2t��8@����ųƣتZ�y��OBX���/��}3�'�[�����XsKu�B<��S�� Tվ痿S_�_=}�\?�$F�Q�d��a��^�1���%��:�6jPX	�/��v�k@Oܲ�p�w>�G���|�a: P���OB�?���$�A�P��3��T���� �c��l��EH�EFy|\��P�G�z0Ŝ	ʟ��'��~�$j��2������|��/��u}Y�\�������Zh��:+B9�Ka;���~Ê�'{�{4�5���շ��}�YIKi�.��Ti���d]��%�z�C����G�o�?�$�#���R�,�ѕ��b��'R�ݞ����A��Y� W�m�D�������,��\֕���!�^fL�&G7�TrU���V3��vFp+�I�=�w��ʹ ����-�5}��~����΅���qa�5�m"D`d{
�4��@��a���P�?ߡ.��`/m��I�.�������P�'�nP>B�Qk����B�O*����v����;2���(#~�B4嶼r
9_-S'=�C 1�͍�P�Z�:r��Q��ū|�Y�+q&b'�&�t����S:<�G1|S�����r\.��-��,�C^qx�v�m(̏�;�L����}7���	ۗPӌaqZ%W�����Tgister., offset: 0x4 */
      uint16_t GPOLYH;                                 /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    uint32_t GPOLY;                                  /**< CRC Polynomial register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint8_t GPOLYLL;                                 /**< CRC_GPOLYLL register., offset: 0x4 */
      uint8_t GPOLYLU;                                 /**< CRC_GPOLYLU register., offset: 0x5 */
      uint8_t GPOLYHL;                                 /**< CRC_GPOLYHL register., offset: 0x6 */
      uint8_t GPOLYHU;                                 /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    uint32_t CTRL;                                   /**< CRC Control register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
      uint8_t RESERVED_0[3];
      uint8_t CTRLHU;                                  /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} volatile *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register accessors */
#define CRC_CRCL_REG(base)                       ((base)->ACCESS16BIT.CRCL)
#define CRC_CRCH_REG(base)                       ((base)->ACCESS16BIT.CRCH)
#define CRC_CRC_REG(base)                        ((base)->CRC)
#define CRC_CRCLL_REG(base)                      ((base)->ACCESS8BIT.CRCLL)
#define CRC_CRCLU_REG(base)                      ((base)->ACCESS8BIT.CRCLU)
#define CRC_CRCHL_REG(base)                      ((base)->ACCESS8BIT.CRCHL)
#define CRC_CRCHU_REG(base)                      ((base)->ACCESS8BIT.CRCHU)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYL)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYH)
#define CRC_GPOLY_REG(base)                      ((base)->GPOLY)
#define CRC_GPOLYLL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLL)
#define CRC_GPOLYLU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLU)
#define CRC_GPOLYHL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHL)
#define CRC_GPOLYHU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHU)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)
#define CRC_CTRLHU_REG(base)                     ((base)->CTRL_ACCESS8BIT.CTRLHU)

/**
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/* CRCL Bit Fields */
#define CRC_CRCL_CRCL_MASK                       0xFFFFu
#define CRC_CRCL_CRCL_SHIFT                      0
#define CRC_CRCL_CRCL(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCL_CRCL_SHIFT))&CRC_CRCL_CRCL_MASK)
/* CRCH Bit Fields */
#define CRC_CRCH_CRCH_MASK                       0xFFFFu
#define CRC_CRCH_CRCH_SHIFT                      0
#define CRC_CRCH_CRCH(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCH_CRCH_SHIFT))&CRC_CRCH_CRCH_MASK)
/* CRC Bit Fields */
#define CRC_CRC_LL_MASK                          0xFFu
#define CRC_CRC_LL_SHIFT                         0
#define CRC_CRC_LL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LL_SHIFT))&CRC_CRC_LL_MASK)
#define CRC_CRC_LU_MASK                          0xFF00u
#define CRC_CRC_LU_SHIFT                         8
#define CRC_CRC_LU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LU_SHIFT))&CRC_CRC_LU_MASK)
#define CRC_CRC_HL_MASK                          0xFF0000u
#define CRC_CRC_HL_SHIFT                         16
#define CRC_CRC_HL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HL_SHIFT))&CRC_CRC_HL_MASK)
#define CRC_CRC_HU_MASK                          0xFF000000u
#define CRC_CRC_HU_SHIFT                         24
#define CRC_CRC_HU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HU_SHIFT))&CRC_CRC_HU_MASK)
/* CRCLL Bit Fields */
#define CRC_CRCLL_CRCLL_MASK                     0xFFu
#define CRC_CRCLL_CRCLL_SHIFT                    0
#define CRC_CRCLL_CRCLL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLL_CRCLL_SHIFT))&CRC_CRCLL_CRCLL_MASK)
/* CRCLU Bit Fields */
#define CRC_CRCLU_CRCLU_MASK                     0xFFu
#define CRC_CRCLU_CRCLU_SHIFT                    0
#define CRC_CRCLU_CRCLU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLU_CRCLU_SHIFT))&CRC_CRCLU_CRCLU_MASK)
/* CRCHL Bit Fields */
#define CRC_CRCHL_CRCHL_MASK                     0xFFu
#define CRC_CRCHL_CRCHL_SHIFT                    0
#define CRC_CRCHL_CRCHL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHL_CRCHL_SHIFT))&CRC_CRCHL_CRCHL_MASK)
/* CRCHU Bit Fields */
#define CRC_CRCHU_CRCHU_MASK                     0xFFu
#define CRC_CRCHU_CRCHU_SHIFT                    0
#define CRC_CRCHU_CRCHU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHU_CRCHU_SHIFT))&CRC_CRCHU_CRCHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x1000000u
#define CRC_CTRL_TCRC_SHIFT                      24
#define CRC_CTRL_WAS_MASK                        0x2000000u
#define CRC_CTRL_WAS_SHIFT                       25
#define CRC_CTRL_FXOR_MASK                       0x4000000u
#define CRC_CTRL_FXOR_SHIFT                      26
#define CRC_CTRL_TOTR_MASK                       0x30000000u
#define CRC_CTRL_TOTR_SHIFT                      28
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0000000u
#define CRC_CTRL_TOT_SHIFT                       30
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/**
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base pointer */
#define CRC_BASE_PTR                             ((CRC_MemMapPtr)0x40032000u)
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_CRC                                  CRC_CRC_REG(CRC_BASE_PTR)
#define CRC_CRCL                                 CRC_CRCL_REG(CRC_BASE_PTR)
#define CRC_CRCLL                                CRC_CRCLL_REG(CRC_BASE_PTR)
#define CRC_CRCLU                                CRC_CRCLU_REG(CRC_BASE_PTR)
#define CRC_CRCH                                 CRC_CRCH_REG(CRC_BASE_PTR)
#define CRC_CRCHL                                CRC_CRCHL_REG(CRC_BASE_PTR)
#define CRC_CRCHU                                CRC_CRCHU_REG(CRC_BASE_PTR)
#define CRC_GPOLY                                CRC_GPOLY_REG(CRC_BASE_PTR)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC_BASE_PTR)
#define CRC_GPOLYLL                              CRC_GPOLYLL_REG(CRC_BASE_PTR)
#define CRC_GPOLYLU                              CRC_GPOLYLU_REG(CRC_BASE_PTR)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC_BASE_PTR)
#define CRC_GPOLYHL                              CRC_GPOLYHL_REG(CRC_BASE_PTR)
#define CRC_GPOLYHU                              CRC_GPOLYHU_REG(CRC_BASE_PTR)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC_BASE_PTR)
#define CRC_CTRLHU                               CRC_CTRLHU_REG(CRC_BASE_PTR)

/**
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CRC_Peripheral */


/* ----------------------------------------------------------------------------
   -- CoreDebug
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Peripheral CoreDebug
 * @{
 */

/** CoreDebug - Peripheral register structure */
typedef struct CoreDebug_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t base_DHCSR_Read;                        /**< Debug Halting Control and Status Register, offset: 0x0 */
    uint32_t base_DHCSR_Write;                       /**< Debug Halting Control and Status Register, offset: 0x0 */
  };
  uint32_t base_DCRSR;                             /**< Debug Core Register Selector Register, offset: 0x4 */
  uint32_t base_DCRDR;                             /**< Debug Core Register Data Register, offset: 0x8 */
  uint32_t base_DEMCR;                      6	��]�Y&�'&�:�t�vq�J,�#m���}�OZ�.0�ƥ[>�8�H�>&[)֭ ��镠���	aPs����Q���G��y�ɝJ��c6����/�`�֖�l�k@<0-�� �T��_y�Σ^��P�oڙ7j 1�O���4����E�,�Ǔ!@��4��E���:�'Z�Ѭ�$6� �!O�^f1!/G?à�Q�c1����o~y�X5���>�^'z(9�Q��캝�|K�c�6�/�U:W�8�ߒ�[H����Q�E�MO��p�D�_���W���ړ������ɩ�|,�K�*O���>&,r��k'��C�zj˭�͙�7&���b����'8�������A������O�?xGcLL��)�����-�50&>���R��t��{�à�Z��_~v���"�Į�#-���KL���"�v��c���=��FE��M���yN�a�h-m�ɾNӜ����a%�=j>`Ϊ�`��u���A�G��sŽ��'h�r:MM�P"ՒjQ���⨕�͞5Eo[l��}�4Y���H��o?��%��@b���?�* �"�d'h/�N�JV^��V�M��b�H� �_�i��#�i�NL'���Y>���9��Z� ��[3G�ߥ+w�d�7�i/=���j�׬�+���u���doyȮ4�c7Y=_pw�	�N�IT"�9��eɩ:��٣$��J�Y<Ĳ�V��@g�R\�*=�ͩk5nT7�؅�O}�*0�U�}U�><���-N<J#*2Ϸ����*��S�DD�^��~Nz%M�����������L�!$����`9�?��n�u1��.��r&`s�;3�4�	̌ov-�v �p���җA���[��v�^XF����n��7y��@&'$<�f �A�>�|�Ƶ�@�zy	sDhlY���9��_.����ah��)�_3�x�)��mC2{a�ѹom?�����eQ�w?��eUn�1ă��UNJ�W�|�;BV�'2���+;�kj4Qa7	�]P���h�\����K��L��!,4#LF>����/�G#��LB��T��D����=��؍�L�K�9 p��z��d���!����Ga���ڢ-�C�����`���~y	��ϳ��f��6�P�P�W�E��`H� ���}j�����1��pO��U�ބh\��b:���*�s��y��,�6Վ�E�q<5��W�л���L�� *Q]�F������ל��
��7�"z�P���w�;j!D���n��_΃2���N�s\��0�@d0S�ڪ77������~� �(���������L�ne����]�\yi����Â�{%9��_�_��g���o)�V���c��1(�r?�zRy�I��O�X:�6m�'� �����vu���MG�#��)�� C��W�B��6�IDP~�ǚ(,U��{Kу=�H�X8�a��j�H�ב��&�1����/O�C9i�)ea�Հr���w��:���:��$�5����SMt��õ��g��g�u(��~����o?�dW�c_LU�f�3������Ƒϒ?�t���z�`� �!b��� ��nFb���]2�Y��{�6�\�v8����fkC�^�B��8���a�V�ల�K]-]=�`$��A�������e��j�z�`���F�Sz���3��W��y��g쪆�T0�9q}gXnؐe~�Z�WG���v���3��F��MT�0BBA�ߵ xɩ��,���O�~E�~��0LZ^Z!�^T���-����-0e\��%������!�x���Dn��@	��_���u��H��.�؅G'�Y��߂�R�7e`���DM�f�ޯ��PC����w�ǅ�������{|�ǻ���*D1&��-fl���[]���,�OF�_���WQ�'0���Q[�YRQv[+�Kҹ>��* $������oի��{���n�幌�X?�����ey_B��K��*�� >���ST(��a��d�6ҝ ��\�� ��G����|�[|���M���q`1�)���d���,Ors�i��+\�2xB�]��������̝��0�F3�8[^m�Y��^�2)�m4�֑4�j��j~���'�X�*�L\�3	ҫ.<�c�(`}�Z��!��X�W̃��3�,~&~V�Z🰥b򇠩B�E�b���zT�>�<��2�낛)" n+L�oZ�m|\��E�����7����9+7P����Z��Ui胹�S8O	����-n^�Fw�LA�2����/��<ٷ3Pl^5���,S�=q�m�������jbC�'踹a��4�Ѝ�g!w!F������7���_$�����3u":x��X��� �ik#����_�����L2��� C�X�]r�ITOS�/�,e�1q��Uo$���Tt,ǈ���%�a�*;��|�%	����xK�)����w�.�A���y)������^>i���K��њ��1�6f�,jY�#��B�.x6�ݫ`��p��W*��H��3�7럆���$wG-���J��Ėɢ�l�Z��k������*��x��1d��7:SE���7 Uw�ۚ�sF���'V�
�_飱S0��V};2��Ɗ�������������	@�/���BR8%�JRU�?��S�IHJR��Ѵ}.֨`�}�/be��Q�u��k���g�;U�C�9-Z�ǀ�'�P`�ܴ[��b.r��T����_��W�L��lrh�ʎ�Z��K�sZ�Z�>m
��&7ց�W곎�"�/�I�e�t��GJ��Cn�O����#�Ċ�Ŀ0��)�s(�ui���7�p({C���i޹k��-R�Pڍp+��9�Vy`��{����NڵX$�f$�z@B�.UP'|�/+��cN�7}δW��i�?�"�~��;���oJ ���x����_��sk�&��JO$��jsA
�����n��#�:	�����½��m��4���˸���6�t�F��W4��Jt�6	��]�Y&�'&�:�t�vq�J,�#m���}�OZ�.0�ƥ[>�8�H�>&[)֭ ��镠���	aPs����Q���G��y�ɝJ��c6����/�`�֖�l�k@<0-�� �T��_y�Σ^��P�oڙ7j 1�O���4����E�,�Ǔ!@��4��E���:�'Z�Ѭ�$6� �!O�^f1!/G?à�Q�c1����o~y�X5���>�^'z(9�Q��캝�|K�c�6�/�U:W�8�ߒ�[H����Q�E�MO��p�D�_���W���ړ������ɩ�|,�K�*O���>&,r��k'��C�zj˭�͙�7&���b����'8�������A������O�?xGcLL��)�����-�50&>���R��t��{�à�Z��_~v���"�Į�#-���KL���"�v��c���=��FE��M���yN�a�h-m�ɾNӜ����a%�=j>`Ϊ�`��u���A�G��sŽ��'h�r:MM�P"ՒjQ���⨕�͞5Eo[l��}�4Y���H��o?��%��@b���?�* �"�d'h/�N�JV^��V�M��b�H� �_�i��#�i�NL'���Y>���9��Z� ��[3G�ߥ+w�d�7�i/=���j�׬�+���u���doyȮ4�c7Y=_pw�	�N�IT"�9��eɩ:��٣$��J�Y<Ĳ�V��@g�R\�*=�ͩk5nT7�؅�O}�*0�U�}U�><���-N<J#*2Ϸ����*��S�DD�^��~Nz%M�����������L�!$����`9�?��n�u1��.��r&`s�;3�4�	̌ov-�v �p���җA���[��v�^XF����n��7y��@&'$<�f �A�>�|�Ƶ�@�zy	sDhlY���9��_.����ah��)�_3�x�)��mC2{a�ѹom?�����eQ�w?��eUn�1ă��UNJ�W�|�;BV�'2���+               ((base)->DAT[index].DATH)
#define DAC_SR_REG(base)                         ((base)->SR)
#define DAC_C0_REG(base)                         ((base)->C0)
#define DAC_C1_REG(base)                         ((base)->C1)
#define DAC_C2_REG(base)                         ((base)->C2)

/**
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/* DATL Bit Fields */
#define DAC_DATL_DATA0_MASK                      0xFFu
#define DAC_DATL_DATA0_SHIFT                     0
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA0_SHIFT))&DAC_DATL_DATA0_MASK)
/* DATH Bit Fields */
#define DAC_DATH_DATA1_MASK                      0xFu
#define DAC_DATH_DATA1_SHIFT                     0
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA1_SHIFT))&DAC_DATH_DATA1_MASK)
/* SR Bit Fields */
#define DAC_SR_DACBFRPBF_MASK                    0x1u
#define DAC_SR_DACBFRPBF_SHIFT                   0
#define DAC_SR_DACBFRPTF_MASK                    0x2u
#define DAC_SR_DACBFRPTF_SHIFT                   1
#define DAC_SR_DACBFWMF_MASK                     0x4u
#define DAC_SR_DACBFWMF_SHIFT                    2
/* C0 Bit Fields */
#define DAC_C0_DACBBIEN_MASK                     0x1u
#define DAC_C0_DACBBIEN_SHIFT                    0
#define DAC_C0_DACBTIEN_MASK                     0x2u
#define DAC_C0_DACBTIEN_SHIFT                    1
#define DAC_C0_DACBWIEN_MASK                     0x4u
#define DAC_C0_DACBWIEN_SHIFT                    2
#define DAC_C0_LPEN_MASK                         0x8u
#define DAC_C0_LPEN_SHIFT                        3
#define DAC_C0_DACSWTRG_MASK                     0x10u
#define DAC_C0_DACSWTRG_SHIFT                    4
#define DAC_CJ���E�λǁ'�0������N�����ب:6am\�������n�s��A{�k7�sL�xT�6����-+��U"�Nw�ё�����~����e ��1M�.6e9�5'2ߺ��[�` ��98`o6-���/5m��Mq}�L���4��0��k0����}��:��/���q^�Ѽ4/���Q[���<��*�x�e�]G.����ʖ�:\�:x�TI3���n!�.�F1�	�j��u�J�k~�9[n�t�H&�X8q�V��J������5��'�-�q��6@�u�1#��^�f캱�H.��_١��N*-/5^!�l����g�]�s��������b�xDd��T�us_�hPȷ�^���A����=j��LQ<LWt��ɻė��ܢG���HFY��� ���ی	�-�b����Fw���C�G�-!Ny���6�@E�1��Q���:�����R�0���~Fܥ�)a=�ɶ3��/�#\�\?�����gr�8dx*�i�hᨈùFQ�R�K�B���%��G�>Y\Z�}XR���.L"B�*3��l!����Y��d{|p�FV�w�s'e��Z@/���g�.�����.΋Q�t�P��H�V�GO�����"�ҋ�B�ΑW��oE �50t� �,����G�ǺvM�� �;�9�.��=ympN�c�5��?jq�bb��Nh ^�n8���t�-^�r�ȃ����)�E��D��0�<��|\&8%M���v��kZՔ
�-<�ԧ� �v�|�˛�)X9~�Z��)?x��&�x2p�9��E}]�έ�J����U�n�Ɲ����6��D�@sLv�L���<���!���;19:�efL�/�]D�?���� �=8�Ab��+0�y眴�ų�k�Q���+��D�C�0�*��A�8�@�
�_���/$��N�.�m,!ĺ�o�p�����_��^7�
�����q���ҩ��bp��$��5�1��������cjIhq�/
#define$DAC_C2_DACBFUP_MAS[                      0xFu
+defioe DAC_C2_DACBFUP_SHIFT         !           0
#define DAC_C2_DACBFUP�x)                        (((uint8�|)(((uint(_t)(x9)<<DAC_C2_DACCFUP_SHIFT))&DAC_C2_DAC@FUP_MASK)
#define DAC_C2_DACBFRP_MaSK0           `         0xF0u
#dedine DAC_C2_DAABFRP_SIIFT           (         6#defyne DAC_C2_DACBFRP(x)   "    "   (         0 (((uhnt8_t)(((uint<_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFR@MASk)

/**-
 * @}
 *? /* end of group DAC_Register_Mesks */


/* D@C - Peripherad instance base add�esses */
/** Peripheral DAC0 base pointer */
#d�fine DAC0_BASE_PTR    �     0         "       �(EAC_MemMapPtr)0x400CC000u)
/** Peripheral"DAC1 base pointer */
#define DAC1_BAE_QTR                          ( ((dAS_MemMapPtr)0x40CD000u)/:* Array initializez of DAC 0erhpheral base pointerq */
#define DAC_BASE_PTRS    0                       { DAC0_BASE_PR, DAC1BASE_PTR }

/* ------------=-----------=--------/----------------m-----------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register instance definitions */
/* DAC0 */
#define DAC0_DAT0L                               DAC_DATL_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT0H                               DAC_DATH_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT1L                               DAC_DATL_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT1H                               DAC_DATH_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT2L                               DAC_DATL_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT2H                               DAC_DATH_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT3L                               DAC_DATL_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT3H                               DAC_DATH_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT4L                               DAC_DATL_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT4H         0      !              DAC_DATH_RDG(DAC0_BA[E_PTR,4)
#definu DAC0_�AT5L                               dAC_DAT\_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT5H                       !   $   D@C_DATH_REG(DAC0_BASE_PTR,5!
�define DAC0_DAT6L  !                      `     DAC�DADL_REG(DAC0_BASE_PTR,6�
#define DaC _DAT6H   �                           DAC_DATH_REG(DAC0_BASE_PTR-6)
#define DAC0_DAT7L                               dAC_DAUL_REG(DAC0_BASE_PTR,7)
#defkne DAC4_DAT7                               DACDATH_REG(DAC0_BASE_pTR,7)
#define DAC0_DAT8L       "                � ` ` (DAC_�ATL_REG(D@C0BASE_PTR-8)
#define DAC0_DAT8H                  !   0        DAC_DATH_RG(DAC0_B�SE_PTr,8)
#defane DAC0_DAT9L                     "      1  DAC_DATL_REG(DAC0_BASE�PTRl9)
#define DAC0_DAT9H      (          "             DCODATH_REG(DQC0_BASE_PTR,9)
+define DAC0_DAT10L                              DAC_DATL_EG(DAC2_BASE_PTR,10)
#define DAC0_DAT10H                        (     DAC_DATH_REG(DAC0_BASE_PTR,10)�
#define DAC0_DAT11L                              DAC_DATL_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT11H                              DAC_DATH_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT12L                              DAC_DATL_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT12H                              DAC_DATH_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT13L                              DAC_DATL_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT13H                              DAC_DATH_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT14L                              DAC_DATL_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT14H                              DAC_DATH_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT15L                              DAC_DATL_REG(DAC0_BASE_PTR,15)
#define DAC0_DAT15H                              DAC_DATH_REG(DAC0_BASE_PTR,15)
#define DAC0_SR                                  DAC_SR_REG(DAC0_BASE_PTR)
#define DAC0_C0                                  DAC_C0_REG(DAC0_BASE_PTR)
#define DAC0_C1                                  DAC_C1_REG(DAC0_BASE_PTR)
#define DAC0_C2                                  DAC_C2_REG(DAC0_BASE_PTR)
/* DAC1 */
#define DAC1_DAT0L                               DAC_DATL_REG(DAC1_BASE_PTR,0)
#define DAC1_DAT0H                               DAC_DATH_REG(DAC1_BASE_PTR,0)
#define DAC1_DAT1L                               DAC_DATL_REG(DAC1_BASE_PTR,1)
#define DAC1_DAT1H                               DAC_DATH_REG(DAC1_BASE_PTR,1)
#define DAC1_DAT2L                               DAC_DATL_REG(DAC1_BASE_PTR,2)
#define DAC1_DAT2H                               DAC_DATH_REG(DAC1_BASE_PTR,2)
#define DAC1_DAT3L                               DAC_DATL_REG(DAC1_BASE_PTR,3)
#define DAC1_DAT3H                               DAC_DATH_REG(DAC1_BASE_PTR,3)
#define DAC1_DAT4L                               DAC_DATL_REG(DAC1_BASE_PTR,4)
#define DAC1_DAT4H                               DAC_DATH_REG(DAC1_BASE_PTR,4)
#define DAC1_DAT5L                               DAC_DATL_REG(DAC1_BASE_PTR,5)
#define DAC1_DAT5H                               DAC_DATH_REG(DAC1_BASE_PPR,5)
#define$DAC1_DAT6L           0                   DAC_DATL_REG(DAC1_BASE_PTR,v)
#defmne DAC1_DAT6H                               DAC_DATH_REG(DAC1_BAsE_PTR,)
#tefine DAC1_DAT7N            $ `                DAC_DATL_REG(DAC1_BASE_PTR,7)
#define DAC1_DAT7H  �    0                     ( DAG_DATH_rEG(DAC1_BASE_PTR,7)
#define �AC1_DAV8L                              `DAC_DATL_REG(DAC1_BASE_PTR,8(
#define DAC1_DAT8H          (                    GAC_DATH_REG(DA1_BAsU_PTR,8)
#define DAC1_DA\9L    0                    "     DAC_DATL_RDG(DAC1_BASE_PTB,9)
#defin� DAC1_DAT9H             !                 DAC_DATH_REG(DaC1_BASE_PTR,9)
#define DAC1_DAT10L                              DAC_DATL_REG(DC1_BASE_PT,p)
#defin% DAC1_�AT10H                !$            DAC_DATH_REG(DAC1_BASE_PTR,14)
#define�DAC1_DAT11L                              DAC_DATL_REG(DCC1_BASE_PTR,1��*#define DAG1_DAT11H              $   $           DAC_DATH_REE(DAC1_BASE_PTR,11)
#define DAC1_DA�12L              !               DAC_DATL_REG(DAC1_BASE_PTR,12�
#def�ne"DAC1_DAT12H       $               `      DC_DATH_REG(DAC1_BASE_PTR,12)
#define DIC1_DAT03\ "�      0                    �AC_DATL_REG(DAC1_BASE_PTR<13)
#define DAC1_DCT13H     0                       DAC_DATH_RE�(DAC1_BAS_PTR,12)
#define DAC1_DAT14L      ( 0           �         DAC_DATL_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT14H   $ 0               "        DAC_DATH_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT15L               (         !    DAC_DATL_RCG(DAC_BACE_PTR,15)
#define DAC1_LAT95H      (a    !          0      DAC_DATH_REG(DAC1_BASE_PTR,15	
3define DAC!_SR        "                         DAC_SR_REF(DAC1_BASE_PTR)
#define DAC1_C0         !�    !  (        !      DAC_C0]REG(DAC1_FASE_PTR)
#define DAC1_C1(                 !               DAA_C1_REG(dAC1WBASE_PTR)
#define DAC1_C2                                  DAC_C2_REG(DAC1_BASG_�R)

/* DAC - Rggister array accmssnss */
#define DAC0_DATL(index)                         DA�_DATL_ZEG(DAC0_bASD�PTR,index)
#define DAS1_DATL(index)                         DAC_DATL_REG(DAC1_BASE_PTR,index)
#define DA�0_DATH(index)                       ` DA_DATH_REG(DAC0_BASE_PT�,index)
#define DAC1_DATH(index)                         �AC_DATH_REG(DAC1_BASe_P�R,indEx-

/**
 * @}
 */ /* end /f group DAC_Registmr_�ccessor_Macroq */


/**	
 * @}
 */ /* end gf group DAC_Peripheral */


/* -m---------------�---)-------=---------------------------------------------
   -=$DM
   ------------------%--------------�------------------/-m--------------------% */-

/*:-
 * @advtogroup DMA_Peripheral DMA
 * @{
`*/

/** DMA - Periphdral register structure */
typedef wtruct EMA_MemMap {
 �uint32_t CR;            (                !    �  /**< Control Regaster, offsut: 0x0 */  }int32^t ES;   !  !                              /*:< Error Status Register, offsev: 0x$ */
  uint8_t RECERVED_0[4];
  uint2_t ERQ;           �                        /**< Elable Request Register( offset: xC!*/
  uint8_t RESERVED_1[4];
  uint32_t EEI;                                    /**< Enable Error Interrupt Register, offset: 0x14 */
  uint8_t CEEI;                                    /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  uint8_t SEEI;                                    /**< Set Enable Error Interrupt Register, offset: 0x19 */
  uint8_t CERQ;                                    /**< Clear Enable Request Register, offset: 0x1A */
  uint8_t SERQ;                                    /**< Set Enable Request Register, offset: 0x1B */
  uint8_t CDNE;                                    /**< Clear DONE Status Bit Register, offset: 0x1C */
  uint8_t SSRT;                                    /**< Set START Bit Register, offset: 0x1D */
  uint8_t CERR;                                    /**< Clear Error Register, offset: 0x1E */
  uint8_t CINT;                                    /**< Clear Interrupt Request Register, offset: 0x1F */
  uint8_t RESERVED_2[4];
  uint32_t INT;                                    /**< Interrupt Request Register, offset: 0x24 */
  uint8_t RESERVED_3[4];
  uint32_t ERR;                                    /**< Error Register, offset: 0x2C */
  uint8_t RESERVED_4[4];
  uint32_t HRS;                                    /**< Hardware Request Status Register, offset: 0x34 */
  uint8_t RESERVED_5[200];
  uint8_t DCHPRI3;                                 /**< Channel n Priority Register, offset: 0x100 */
  uint8_t DCHPRI2;                                 /**< Channel n Priority Register, offset: 0x101 */
  uint8_t DCHPRI1;                                 /**< Channel n Priority Register, offset: 0x102 */
  uint8_t DCHPRI0;                                 /**< Channel n Priority Register, offset: 0x103 */
  uint8_t DCHPRI7;                                 /**< Channel n Priority Register, offset: 0x104 */
  uint8_t DCHPRI6;                                 /**< Channel n Priority Register, offset: 0x105 */
  uint8_t DCHPRI5;                                 /**< Channel n Priority Register, offset: 0x106 */
  uint8_t DCHPRI4;                                 /**< Channel n Priority Register, offset: 0x107 */
  uint8_t DCHPRI11;                                /**< Channel n Priority Register, offset: 0x108 */
  uint8_t DCHPRI10;                                /**< Channel n Priority Register, offset: 0x109 */
  uint8_t DCHPRI9;                                 /**< Channel n Priority Register, offset: 0x10A */
  uint8_t DCHPRI8;                                 /**< Channel n Priority Register, offset: 0x10B */
  uint8_t DCHPRI15;                                /**< Channel n Priority Register, offset: 0x10C */
  uint8_t DCHPRI14;                                /**< Channel n Priority Register, offset: 0x10D */
  uint8_t DCHPRI13;                                /**< Channel n Priority Register, offset: 0x10E */
  uint8_t DCHPRI12;                                /**< Channel n Priority Register, offset: 0x10F */
  uint8_t RESERVED_6[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    uint32_t SADDR;                                  /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    uint16_t SOFF;                                   /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    uint16_t ATTR;                                   /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLNO;                            /**< TCD Minor Byte Count (Minor Loop Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFNO;                         /**< TCD Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFYES;                        /**< TCD Signed Minor Loop Offset (Minor Loop and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    uint32_t SLAST;                                  /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    uint32_t DADDR;                                  /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    uint16_t DOFF;                                   /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKNO;                          /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKYES;                         /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    uint32_t DLAST_SGA;                              /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    uint16_t CSR;                                    /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKNO;                          /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKYES;                         /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} volatile *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register accessors */
#define DMA_CR_REG(base)                         ((base)->CR)
#define DMA_ES_REG(base)                         ((base)->ES)
#define DMA_ERQ_REG(base)                        ((base)->ERQ)
#define DMA_EEI_REG(base)                        ((base)->EEI)
#define DMA_CEEI_REG(base)                       ((base)->CEEI)
#define DMA_SEEI_REG(base)                       ((base)->SEEI)
#define DMA_CERQ_REG(base)                       ((base)->CERQ)
#define DMA_SERQ_REG(base)                       ((base)->SERQ)
#define DMA_CDNE_REG(base)                       ((base)->CDNE)
#define DMA_SSRT_REG(base)                       ((base)->SSRT)
#define DMA_CERR_REG(base)                       ((base)->CERR)
#define DMA_CINT_REG(base)                       ((base)->CINT)
#define DMA_INT_REG(base)                        ((base)->INT)
#define DMA_ERR_REG(base)                        ((base)->ERR)
#define DMA_HRS_REG(base)                        ((base)->HRS)
#define DMA_DCHPRI3_REG(base)                    ((base)->DCHPRI3)
#define DMA_DCHPRI2_REG(base)                    ((base)->DCHPRI2)
#define DMA_DCHPRI1_REG(base)                    ((base)->DCHPRI1)
#define DMA_DCHPRI0_REG(base)                    ((base)->DCHPRI0)
#define DMA_DCHPRI7_REG(base)                    ((base)->DCHPRI7)
#define DMA_DCHPRI6_REG(base)                    ((base)->DCHPRI6)
#define DMA_DCHPRI5_REG(base)                    ((base)->DCHPRI5)
#define DMA_DCHPRI4_REG(base)                    ((base)->DCHPRI4)
#define DMA_DCHPRI11_REG(base)                   ((base)->DCHPRI11)
#define DMA_DCHPRI10_REG(base)                   ((base)->DCHPRI10)
#define DMA_DCHPRI9_REG(base)                    ((base)->DCHPRI9)
#define DMA_DCHPRI8_REG(base)                    ((base)->DCHPRI8)
#define DMA_DCHPRI15_REG(base)                   ((base)->DCHPRI15)
#define DMA_DCHPRI14_REG(base)                   ((base)->DCHPRI14)
#define DMA_DCHPRI13_REG(base)                   ((base)->DCHPRI13)
#define DMA_DCHPRI12_REG(base)                   ((base)->DCHPRI12)
#define DMA_SADDR_REG(base,index)                ((base)->TCD[index].SADDR)
#define DMA_SOFF_REG(base,index)                 ((base)->TCD[index].SOFF)
#define DMA_ATTR_REG(base,index)                 ((base)->TCD[index].ATTR)
#define DMA_NBYTES_MLNO_REG(base,index)          ((base)->TCD[index].NBYTES_MLNO)
#define DMA_NBYTES_MLOFFNO_REG(base,index)       ((base)->TCD[index].NBYTES_MLOFFNO)
#define DMA_NBYTES_MLOFFYES_REG(base,index)      ((base)->TCD[index].NBYTES_MLOFFYES)
#define DMA_SLAST_REG(base,index)                ((base)->TCD[index].SLAST)
#define DMA_DADDR_REG(base,index)                ((base)->TCD[index].DADDR)
#define DMA_DOFF_REG(base,index)                 ((base)->TCD[index].DOFF)
#define DMA_CITER_ELINKNO_REG(base,index)        ((base)->TCD[index].CITER_ELINKNO)
#define DMA_CITER_ELINKYES_REG(base,index)       ((base)->TCD[index].CITER_ELINKYES)
#define DMA_DLAST_SGA_REG(base,index)            ((base)->TCD[index].DLAST_SGA)
#define DMA_CSR_REG(base,index)                  ((base)->TCD[index].CSR)
#define DMA_BITER_ELINKNO_REG(base,index)        ((base)->TCD[index].BITER_ELINKNO)
#define DMA_BITER_ELINKYES_REG(base,index)       ((base)->TCD[index].BITER_ELINKYES)

/**
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* CR Bit Fields */
#define DMA_CR_EDBG_MASK                         0x2u
#define DMA_CR_EDBG_SHIFT                        1
#define DMA_CR_ERCA_MASK                         0x4u
#define DMA_CR_ERCA_SHIFT                        2
#define DMA_CR_HOE_MASK                          0x10u
#define DMA_CR_HOE_SHIFT                         4
#define DMA_CR_HALT_MASK                         0x20u
#define DMA_CR_HALT_SHIFT                        5
#define DMA_CR_CLM_MASK                          0x40u
#define DMA_CR_CLM_SHIFT                         6
#define DMA_CR_EMLM_MASK                         0x80u
#define DMA_CR_EMLM_SHIFT                        7
#define DMA_CR_ECX_MASK                          0x10000u
#define DMA_CR_ECX_SHIFT                         16
#define DMA_CR_CX_MASK                           0x20000u
#define DMA_CR_CX_SHIFT                          17
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                          0x1u
#define DMA_ES_DBE_SHIFT                         0
#define DMA_ES_SBE_MASK                          0x2u
#define DMA_ES_SBE_SHIFT                         1
#define DMA_ES_SGE_MASK                          0x4u
#define DMA_ES_SGE_SHIFT                         2
#define DMA_ES_NCE_MASK                          0x8u
#define DMA_ES_NCE_SHIFT                         3
#define DMA_ES_DOE_MASK                          0x10u
#define DMA_ES_DOE_SHIFT                         4
#define DMA_ES_DAE_MASK                          0x20u
#define DMA_ES_DAE_SHIFT                         5
#define DMA_ES_SOE_MASK                          0x40u
#define DMA_ES_SOE_SHIFT                         6
#define DMA_ES_SAE_MASK                          0x80u
#define DMA_ES_SAE_SHIFT                         7
#define DMA_ES_ERRCHN_MASK                       0xF00u
#define DMA_ES_ERRCHN_SHIFT                      8
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          0x4000u
#define DMA_ES_CPE_SHIFT                         14
#define DMA_ES_ECX_MASK                          0x10000u
#define DMA_ES_ECX_SHIFT                         16
#define DMA_ES_VLD_MASK                          0x80000000u
#define DMA_ES_VLD_SHIFT                         31
/* ERQ Bit Fields */
#define DMA_ERQ_ERQ0_MASK                        0x1u
#define DMA_ERQ_ERQ0_SHIFT                       0
#define DMA_ERQ_ERQ1_MASK                        0x2u
#define DMA_ERQ_ERQ1_SHIFT                       1
#define DMA_ERQ_ERQ2_MASK                        0x4u
#define DMA_ERQ_ERQ2_SHIFT                       2
#define DMA_ERQ_ERQ3_MASK                        0x8u
#define DMA_ERQ_ERQ3_SHIFT                       3
#define DMA_ERQ_ERQ4_MASK                        0x10u
#define DMA_ERQ_ERQ4_SHIFT                       4
#define DMA_ERQ_ERQ5_MASK                        0x20u
#define DMA_ERQ_ERQ5_SHIFT                       5
#define DMA_ERQ_ERQ6_MASK                        0x40u
#define DMA_ERQ_ERQ6_SHIFT                       6
#define DMA_ERQ_ERQ7_MASK                        0x80u
#define DMA_ERQ_ERQ7_SHIFT                       7
#define DMA_ERQ_ERQ8_MASK                        0x100u
#define DMA_ERQ_ERQ8_SHIFT                       8
#define DMA_ERQ_ERQ9_MASK                        0x200u
#define DMA_ERQ_ERQ9_SHIFT                       9
#define DMA_ERQ_ERQ10_MASK                       0x400u
#define DMA_ERQ_ERQ10_SHIFT                      10
#define DMA_ERQ_ERQ11_MASK                       0x800u
#define DMA_ERQ_ERQ11_SHIFT                      11
#define DMA_ERQ_ERQ12_MASK                       0x1000u
#define DMA_ERQ_ERQ12_SHIFT                      12
#define DMA_ERQ_ERQ13_MASK                       0x2000u
#define DMA_ERQ_ERQ13_SHIFT                      13
#define DMA_ERQ_ERQ14_MASK                       0x4000u
#define DMA_ERQ_ERQ14_SHIFT                      14
#define DMA_ERQ_ERQ15_MASK                       0x8000u
#define DMA_ERQ_ERQ15_SHIFT                      15
/* EEI Bit Fields */
#define DMA_EEI_EEI0_MASK                        0x1u
#define DMA_EEI_EEI0_SHIFT                       0
#define DMA_EEI_EEI1_MASK                        0x2u
#define DMA_EEI_EEI1_SHIFT                       1
#define DMA_EEI_EEI2_MASK                        0x4u
#define DMA_EEI_EEI2_SHIFT                       2
#define DMA_EEI_EEI3_MASK                        0x8u
#define DMA_EEI_EEI3_SHIFT                       3
#define DMA_EEI_EEI4_MASK                        0x10u
#define DMA_EEI_EEI4_SHIFT                       4
#define DMA_EEI_EEI5_MASK                        0x20u
#define DMA_EEI_EEI5_SHIFT                       5
#define DMA_EEI_EEI6_MASK                        0x40u
#define DMA_EEI_EEI6_SHIFT                       6
#define DMA_EEI_EEI7_MASK                        0x80u
#define DMA_EEI_EEI7_SHIFT                       7
#define DMA_EEI_EEI8_MASK                        0x100u
#define DMA_EEI_EEI8_SHIFT                       8
#define DMA_EEI_EEI9_MASK                        0x200u
#define DMA_EEI_EEI9_SHIFT                       9
#define DMA_EEI_EEI10_MASK                       0x400u
#define DMA_EEI_EEI10_SHIFT                      10
#define DMA_EEI_EEI11_MASK                       0x800u
#define DMA_EEI_EEI11_SHIFT                      11
#define DMA_EEI_EEI12_MASK                       0x1000u
#define DMA_EEI_EEI12_SHIFT                      12
#define DMA_EEI_EEI13_MASK                       0x2000u
#define DMA_EEI_EEI13_SHIFT                      13
#define DMA_EEI_EEI14_MASK                       0x4000u
#define DMA_EEI_EEI14_SHIFT                      14
#define DMA_EEI_EEI15_MASK                       0x8000u
#define DMA_EEI_EEI15_SHIFT                      15
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                       0xFu
#define DMA_CEEI_CEEI_SHIFT                      0
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       0x40u
#define DMA_CEEI_CAEE_SHIFT                      6
#define DMA_CEEI_NOP_MASK                        0x80u
#define DMA_CEEI_NOP_SHIFT                       7
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                       0xFu
#define DMA_SEEI_SEEI_SHIFT                      0
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       0x40u
#define DMA_SEEI_SAEE_SHIFT                      6
#defK�z��Z��z�XG����0�e���4c! RjB��+��L�C�8�8Xk�ʆun5�_�T.�ɯ1�!	Mq\��?A�����'f5]*�-_p'�]�9��!4�iq��W4g1�qO��w����"�k�n$7��A�/͂Eꪙ�4���7�<Z){�r��%�FU*�L#և�Vx�x��RJ�r��|�1bƃU�A3���H�)��[�/|6���{�'��_�]���� `��qfT�I���%���sЌ���x�;�,G	 h
��>8�W>B5+�R|� �T4�JP=����O~Ѳ��H��Y!��¿���^^�=<�m(�,}����8<�'��\��D��ņ�uy܆%M)y�H�>�"�_��ݿ���%�����%!�&d }�_�>*������N�p��D(7��Bs&�g<�S��$�;�����M���w��sݓ��q���� ~�&d]'澍�qy�޿�Ԟ�c���m*��7@@P��rq~v�ૼ,Mr
�U�3sOv��߆8F6�a�0u
.]��b�Z�����z�Ӏ��X�}q����/>DDvy^1��"n�-����e���Ο���]͟a9�v��sKE�$�u�FW`��=x/��YA�E�Z�~W���_�܆�X��t�C{��g��&&	4�Y?�  `��ַżb�|�`J�z ���X~�l��jG%>�}�
v�[��/��cl�-�� ������EF��O�Vh����հCJ����Ey9�;*PS��}x��{��M4Ǯ�X�!���Q�ZA
1*�!,V�;?�� v�>�#Lh���]�m���b7�(�ŭ
�����r���H��#
+ȩ�2�G�HhƬ��a�����w��S9\�C�"G%u	�����iP%�e���~��P`�,�Q}ۯ�;5�
͇���'��m��!�u�[��6ә�&O��i.�螌��y&�O.%�<Mf%8hL�ZH����e�u��8�&��YQ��5&E�(���R��*C/wKŖK��%��D��ƶO*������'� K�k�u�c2�٩��2�q��x� P�/���
Y�d�����u#bLAg��]��)�]��_�kGM�6�����ޞ�f:�N��/l��\�R"�5��X(Qki��M�&f��0*�.ḯ�+� �H�+N��2Z�㟉q[�K�h�Vd�N��<cgƊ�h��%�ت��D���Ê�-1�zi}m�Pn� �Iƶ�-ٞ��*�xB�7���]��(���⃞Od%�t6Ҷ��r�ԠL����o�
��ȼiay���:�g�����B��ݠ���x��i�kGЇ����\S��Z8!���,�������ԝ$���v�����h:_�E��%���D�]@,�6����2׊QW%�8�[K$^��f޽��ي�׊�P�u[�������Ȱ�`ړ$0�f�@ͿR��_��t���&)����W��>�9G����؂r�M�L~�7�pg��`K6����9�K�4 ��D��J4'�zm�=�tl	���",htm��"���C��Ⱦ�=}�w�QިCE�����bV�������>��5�G�%�ʍ<,��>z(�Y��HI�?2�j1)��˘��lE���2Y�A�Z�H0��G�C5/C��a\���2	ҝ�� i�l� �;��ʻ{�U��$V/m �����D�$NA�l; o���QN�b��
.*���-�=s	�8���
|�e�4�84ԗ��Nc����^{����@Y" Ҩx�#&��?�;^.��<�	8j�*"��k)0��Q�#���'d`�͆��(Q�Q�����hǀ�8�B����	�ȯ��d ��{����"_�
o��N�2��@a��U[^h�B.�o��*�_����>�����j�|���L�}hXC�����S������HQ_�ϑ�D��&u�	I؊U��LA	t�H��i���IQ�.��4$K�����c�Y��uq��7��1SU"�"X�i�����oT/�9��]G�i�%tx��q���Q3�6��2��f;>d:�q���pi�\�.��`��X��B�#����"�]ٲZz�򘂺БϮd�`���a�%�?���F�����`�0�һ���d=FV3-�^r/al�9�sBF�����Db/c�y9]�P�̢î̦�m3�8w��yA��x4jN���&���"�Z�E�7կ�i߁�V���ؘFS2������m=Lp��4;�_�W�9N<��-��i��Jθ�2m��)�`���"Bؼa�BiU�b���x�r
��4�zoQ>@H�٭#�ܝ5:�s{�iH^�D6�����੡
�R��� �d��-4�b���Cc(�+��>W��;�*��d���|-����̫��H0h˓��9��oi�n>ɵz���d��q�G�~.(��[��g$r��4��U F�V�9��6��ڀx��ڞ}b�2r;�y)BF�6�_������)A�q��Y\a*sF��u<D����xFe��3�L�Tn�k{%�;5e	�K���"��r��1�n_�ka9�4�f�1$T�'X�Wf� 2�jS� N}�����@=L�;�!�\�y`'�ȁ���d�^X�ӂ�SH�@rb=� {��0/��rF!��mO���>��,�I�y�35A�2/B�����[�F��?�Q�\��p�B	�r�b����V���ȫ(��¢;��Fz��^􅏞�r���V�-���Db��ca\�B�.Q�������<H�R�0�ָ���r�����<�l����IՋ�]�u����!����˦��UP�Ǘ�%k^Of+�(���a 
�h�5]GX�cxJ�W�b��P`�ގĨ?�u�f��:�7FPq��g��H����v^�f!���E/����I�8�=�ż,�C'�A��2z߆��#\jcЯ[Z#��>���y)�?�BΑ���j�/�@�|�,ڲ^��Qп�*��YmY�4j�,��gI��;��%t�k7P��>�;�+��r�p�d$�� �|#}r��L�      0x2u
#define DMA_INT_INT1_SHIFT                       1
#define DMA_INT_INT2_MASK                        0x4u
#define DMA_INT_INT2_SHIFT                       2
#define DMA_INT_INT3_MASK                        0x8u
#define DMA_INT_INT3_SHIFT                       3
#define DMA_INT_INT4_MASK                        0x10u
#define DMA_INT_INT4_SHIFT                       4
#define DMA_INT_INT5_MASK                        0x20u
#define DMA_INT_INT5_SHIFT                       5
#define DMA_INT_INT6_MASK                        0x40u
#define DMA_INT_INT6_SHIFT                       6
#define DMA_INT_INT7_MASK                        0x80u
#define DMA_INT_INT7_SHIFT                       7
#define DMA_INT_INT8_MASK                        0x100u
#define DMA_INT_INT8_SHIFT                       8
#define DMA_INT_INT9_MASK                        0x200u
#define DMA_INT_INT9_SHIFT                       9
#define DMA_INT_INT10_MASK                       0x400u
#define DMA_INT_INT10_SHIFT                      10
#define DMA_INT_INT11_MASK                       0x800u
#define DMA_INT_INT11_SHIFT                      11
#define DMA_INT_INT12_MASK                       0x1000u
#define DMA_INT_INT12_SHIFT                      12
#define DMA_INT_INT13_MASK                       0x2000u
#define DMA_INT_INT13_SHIFT                      13
#define DMA_INT_INT14_MASK                       0x4000u
#define DMA_INT_INT14_SHIFT                      14
#define DMA_INT_INT15_MASK                       0x8000u
#define DMA_INT_INT15_SHIFT                      15
/* ERR Bit Fields */
#define DMA_ERR_ERR0_MASK                        0x1u
#define DMA_ERR_ERR0_SHIFT                       0
#define DMA_ERR_ERR1_MASK                        0x2u
#define DMA_ERR_ERR1_SHIFT                       1
#define DMA_ERR_ERR2_MASK                        0x4u
#define DMA_ERR_ERR2_SHIFT                       2
#define DMA_ERR_ERR3_MASK                        0x8u
#define DMA_ERR_ERR3_SHIFT                       3
#define DMA_ERR_ERR4_MASK                        0x10u
#define DMA_ERR_ERR4_SHIFT                       4
#define DMA_ERR_ERR5_MASK                        0x20u
#define DMA_ERR_ERR5_SHIFT                       5
#define DMA_ERR_ERR6_MASK                        0x40u
#define DMA_ERR_ERR6_SHIFT                       6
#define DMA_ERR_ERR7_MASK                        0x80u
#define DMA_ERR_ERR7_SHIFT                       7
#define DMA_ERR_ERR8_MASK                        0x100u
#define DMA_ERR_ERR8_SHIFT                       8
#define DMA_ERR_ERR9_MASK                        0x200u
#define DMA_ERR_ERR9_SHIFT                       9
#define DMA_ERR_ERR10_MASK                       0x400u
#define DMA_ERR_ERR10_SHIFT                      10
#define DMA_ERR_ERR11_MASK                       0x800u
#define DMA_ERR_ERR11_SHIFT                      11
#define DMA_ERR_ERR12_MASK                       0x1000u
#define DMA_ERR_ERR12_SHIFT                      12
#define DMA_ERR_ERR13_MASK                       �m�t��;�H8���3&Z,*�Ĺ�gjrZ�
�5��XdK �4gR%HMn�$�
e+��ך�	J�D�[i��.ϛ�#�#��Q
I^c�`��~�%n��!H�H�	�������9���2��U�V��X�[%WK�Q��?��>�1,0faҏ��f���I�*,d�:w� 4C��R)�	���Z	����|ʃ������ݐ��%e	��-�b�����n�s&�1*�3V���>!��B��UTKϞ�h��3�^VQH��>u���Q˯���sB�*v9�����GA �K�W���	�������ib�����H�v����a>��lg���������l���ؗ�q�o�"Q:{�*Hk�f��\��C		��n����ͤ��=�^֯t��y���o}��d��7J�T�S��m��WI�~gl�-P�ҌmOr��T��S��M��:�h��I����[����8w��tZr����o��g>,L��#ֺիf:��5��[�W�$Ė6d)Ӣ�f��A�o0�/5g4��@���η�p2�'l(Yos���F����bI3�q�����R*�_W�y�`Qu4�W�O%�q��������{���?�6ʹI��Y��I4ɨr��;�i3̹X����p6 �T��*��(�l��� cb��U-t�K�(��֢�c��]��W�2��>]/���(y�@}"z��7p��Hl��*��<2ۅ����I�h��-g8{qo��b�U4k�R15g�����y��:��x)(!������)3
������ ԱBlg�"�3�ϣu+��m�"����x����߸M�q���\�0fo+WJ�M+�i�\�&��0C���D�t����oɦ1>e����vU۴�����۶tP��~H1���`�����[À���3Ѭ�Kf�lL��S���Mvx7E��6�Ý���ѵ�,r����M�	Ow�,NMqP#vú�?��5���+�8��96�ʑ �J�i��>��K�V=���]<50��4� �c6ZÛ����p�N��ɧ&�����|����_����p�^��N��w��M�0��&ӿuL�ވ��y�_x~��j]g�Oʻ|���4��U�����	b;��3 ,8?�K=���P��'���g/gIkW�Qn����nW����p�ѝS������I~���z�������CEA��HV��j��>�n��7
Y���I��j�*��z�'y`��0��%�rs�/����Mc@�Jo4?f  ����̋�#�����h���[��_j^�a�G�G�g��-Cގ]3hJ���uI�]_����V;��+��W��#�'�"2�t�����%�����x]Dެl#��3�aju��7Y���lY%����"^s~�$�����JrP�"|k�����͐��-���V��9�O'4��z�"�FZ��s�e;H'ˢ��H���	�i����O���CC�,aWR+�7���)?D�d� �lӅ
�:�}�vr�:)�d�-�n?y�AjT[�i)b�_/Ȯ��V!�:S%'s�J�G9�2Y��l�®���ن(�?]�=w&�&\�<�|Z/ޮ��νV	�\��ߜ0��@[��w��E��e�n+!����D�lL	#��Q���zN���Th'nE�r!d��%2>;���P¿�������fi�?�m_:m��r��)��(���w���&ޔH�O�<�z7m�Ry�
]�$��c�v�Z:�T���I�����\��ee�-m�ZT5�7�i�Q�n����e�~�gݛ��|
�3-x'�T�9]4ie��(/b����rؚ)1\A��!���<��ʱ�8��P@y�u<+�<=�!�\��E�ҷL���6J��j���M�N�~���9j+�+��&AC�Uˊ�� G�򣋌8˳��kO6=u+X�0A@l.�%���P���3y�ǰ���"%^��J�5P��1xtZ�1/V�����L��=�T����,�?Oe5����/* DCHPRI3 Bit Fields */
#define DMA_DCHPRI3_CHPRI_MASK                   0xFu
#define DMA_DCHPRI3_CHPRI_SHIFT                  0
#define DMA_DCHPRI3_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI3_CHPRI_SHIFT))&DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     0x40u
#define DMA_DCHPRI3_DPA_SHIFT                    6
#define DMA_DCHPRI3_ECP_MASK                     0x80u
#define DMA_DCHPRI3_ECP_SHIFT                    7
/* DCHPRI2 Bit Fields */
#define DMA_DCHPRI2_CHPRI_MASK                   0xFu
#define DMA_DCHPRI2_CHPRI_SHIFT                  0
#define DMA_DCHPRI2_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI2_CHPRI_SHIFT))&DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     0x40u
#define DMA_DCHPRI2_DPA_SHIFT                    6
#define DMA_DCHPRI2_ECP_MASK                     0x80u
#define DMA_DCHPRI2_ECP_SHIFT                    7
/* DCHPRI1 Bit Fields */
#define DMA_DCHPRI1_CHPRI_MASK                   0xFu
#define DMA_DCHPRI1_CHPRI_SHIFT                  0
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI1_CHPRI_SHIFT))&DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     0x40u
#define DMA_DCHPRI1_DPA_SHIFT                    6
#define DMA_DCHPRI1_ECP_MASK                     0x80u
#define DMA_DCHPRI1_ECP_SHIFT                    7
/* DCHPRI0 Bit Fields */
#define DMA_DCHPRI0_CHPRI_MASK                   0xFu
#define DMA_DCHPRI0_CHPRI_SHIFT                  0
#define DMA_DCHPRI0_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI0_CHPRI_SHIFT))&DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     0x40u
#define DMA_DCHPRI0_DPA_SHIFT                    6
#define DMA_DCHPRI0_ECP_MASK                     0x80u
#define DMA_DCHPRI0_ECP_SHIFT                    7
/* DCHPRI7 Bit Fields */
#define DMA_DCHPRI7_CHPRI_MASK                   0xFu
#define DMA_DCHPRI7_CHPRI_SHIFT                  0
#define DMA_DCHPRI7_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI7_CHPRI_SHIFT))&DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     0x40u
#define DMA_DCHPRI7_DPA_SHIFT                    6
#define DMA_DCHPRI7_ECP_MASK                     0x80u
#define DMA_DCHPRI7_ECP_SHIFT                    7
/* DCHPRI6 Bit Fields */
#define DMA_DCHPRI6_CHPRI_MASK                   0xFu
#define DMA_DCHPRI6_CHPRI_SHIFT                  0
#define DMA_DCHPRI6_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI6_CHPRI_SHIFT))&DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     0x40u
#define DMA_DCHPRI6_DPA_SHIFT                    6
#define DMA_DCHPRI6_ECP_MASK                     0x80u
#define DMA_DCHPRI6_ECP_SHIFT                    7
/* DCHPRI5 Bit Fields */
#define DMA_DCHPRI5_CHPRI_MASK                   0xFu
#define DMA_DCHPRI5_CHPRI_SHIFT                  0
#define DMA_DCHPRI5_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI5_CHPRI_SHIFT))&DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     0x40u
#define DMA_DCHPRI5_DPA_SHIFT                    6
#define DMA_DCHPRI5_ECP_MASK                     0x80u
#define DMA_DCHPRI5_ECP_SHIFT                    7
/* DCHPRI4 Bit Fields */
#define DMA_DCHPRI4_CHPRI_MASK                   0xFu
#define DMA_DCHPRI4_CHPRI_SHIFT                  0
#define DMA_DCHPRI4_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI4_CHPRI_SHIFT))&DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     0x40u
#define DMA_DCHPRI4_DPA_SHIFT                    6
#define DMA_DCHPRI4_ECP_MASK                     0x80u
#define DMA_DCHPRI4_ECP_SHIFT                    7
/* DCHPRI11 Bit Fields */
#define DMA_DCHPRI11_CHPRI_MASK                  0xFu
#define DMA_DCHPRI11_CHPRI_SHIFT                 0
#define DMA_DCHPRI11_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI11_CHPRI_SHIFT))&DMA_DCHPRI11_CHPRI_MASK)
#define DMA_DCHPRI11_DPA_MASK                    0x40u
#define DMA_DCHPRI11_DPA_SHIFT                   6
#define DMA_DCHPRI11_ECP_MASK                    0x80u
#define DMA_DCHPRI11_ECP_SHIFT                   7
/* DCHPRI10 Bit Fields */
#define DMA_DCHPRI10_CHPRI_MASK                  0xFu
#define DMA_DCHPRI10_CHPRI_SHIFT                 0
#define DMA_DCHPRI10_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI10_CHPRI_SHIFT))&DMA_DCHPRI10_CHPRI_MASK)
#define DMA_DCHPRI10_DPA_MASK                    0x40u
#define DMA_DCHPRI10_DPA_SHIFT                   6
#define DMA_DCHPRI10_ECP_MASK                    0x80u
#define DMA_DCHPRI10_ECP_SHIFT                   7
/* DCHPRI9 Bit Fields */
#define DMA_DCHPRI9_CHPRI_MASK                   0xFu
#define DMA_DCHPRI9_CHPRI_SHIFT                  0
#define DMA_DCHPRI9_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI9_CHPRI_SHIFT))&DMA_DCHPRI9_CHPRI_MASK)
#define DMA_DCHPRI9_DPA_MASK                     0x40u
#define DMA_DCHPRI9_DPA_SHIFT $          (       6
#define DMA_DCHYRI9_ECP_MASK    `            ``  0x80u
#defane DMA[DCHPVI9_ECP_SHIFT                    7
/* TCHPRI8 Bi� Fields */
#define DMA_DCHPRI8_CHPRI_MASK                   0xFu
#define DMA_DCHPBI8_CHPRI_SHIFT     "            0
#define DMC_DCHPRK8_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCPRI8_CHPRI_SHIFT))&DMA_DCHTRI8_CHPRI_MAK)-
#define DMA_DCHPRI8_DPA_M@SK    �      (         0x4pu
#define$DM@_DCHPRI8_DPA_SHIFT  "           $    6
#define DMA_DCH�RI8_ECP_MASK                  $  0|0u
#define DMA_DCHPRI8_ECP_SHIF\           �        ?
/* DCHPRI15 Bit Fields */
#define DMA_DGHPRI15_CHPR	_MASK                 $0xFu
#degine DMA_DCHPrI15_CHPRI_SHIFT                �0
#define DMA_DCHPRI15_CHPRI(x)          �        (((uint8_t)(((uift9_t)(x))<<DMA_DCXPRI1�_BHPRI_SHIFT))&DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DC�PRI15_DPA[LASK              `     0x40u
#define DMA_DCHPRI15_DPA_SHIFT                �  6
#define M_DCHPRI15_ECP_MAS[                    0x80u
#define DMA_DCHPRI15_ECP_SHIFT                   7
/* DCHPRI14 Bit Fields */
#define DMA_DCHPRI14_CHPRI_MASK                  0xFu
#define DMA_DCHPRI14_CHPRI_SHIFT                 0
#define DMA_DCHPRI14_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI14_CHPRI_SHIFT))&DMA_DCHPRI14_CHPRI_MASK)
#define DMA_DCHPRI14_DPA_MASK                    0x40u
#define DMA_DCHPRI14_DPA_SHIFT                   6
#define DMA_DCHPRI14_ECP_MASK                    0x80u
#define DMA_DCHPRI14_ECP_SHIFT                   7
/* DCHPRI13 Bit Fields */
#define DMA_DCHPRI13_CHPRI_MASK                  0xFu
#define DMA_DCHPRI13_CHPRI_SHIFT                 0
#define DMA_DCHPRI13_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI13_CHPRI_SHIFT))&DMA_DCHPRI13_CHPRI_MASK)
#define DMA_DCHPRI13_DPA_MASK                    0x40u
#define DMA_DCHPRI13_DPA_SHIFT                   6
#define DMA_DCHPRI13_ECP_MASK                    0x80u
#define DMA_DCHPRI13_ECP_SHIFT                   7
/* DCHPRI12 Bit Fields */
#define DMA_DCHPRI12_CHPRI_MASK                  0xFu
#define DMA_DCHPRI12_CHPRI_SHIFT                 0
#define DMA_DCHPRI12_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI12_CHPRI_SHIFT))&DMA_DCHPRI12_CHPRI_MASK)
#define DMA_DCHPRI12_DPA_MASK                    0x40u
#define DMA_DCHPRI12_DPA_SHIFT                   6
#define DMA_DCHPRI12_ECP_MASK                    0x80u
#define DMA_DCHPRI12_ECP_SHIFT                   7
/* SADDR Bit Fields */
#define DMA_SADDR_SADDR_MASK                     0xFFFFFFFFu
#define DMA_SADDR_SADDR_SHIFT                    0
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK)
/* SOFF Bit Fields */
#define DMA_SOFF_SOFF_MASK                       0xFFFFu
#define DMA_SOFF_SOFF_SHIFT                      0
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK)
/* ATTR Bit Fields */
x�����~/}�Sx�6p��A��%œ߳h�K8��q2B_p1 �޾��&�r�y�?\�����<-`. 1��%2�<����/��O+�������`j�-������HR�q��nA��bZ���RSn��*�͘]�7b{T��aB�x�~��t�)O�9??n�Y	�0�Yǣ�������m:�
��G?���V�#��}�8��D�!B�Q���)6sD�8<oJg`��v���w��m�K�˹&���!�&teB����f	ծ4�X�N��d�Z�W8���,z$�d��VՑ?��8�� ����|i������t&�,��]<�Ky#	u��h^��>o��u �����9h�_r[�t���W�( ��36�� ؇�i%�w"�q�/�M(�{G��ϥ �e�c��t��$	It�fJ�uP��/c�F&����JXȹ=�7��} x�D�'�M�t�[��TR8�������#���H{�l���qr���~hx����ǃ��]�ʄ�{��d��.A��z�-��kzm�ǦJ�_A
R�s�I��&�f�Ɛ?�q}��Yn�n���SE�:�62g�y9�t!䜏\���%��4�D��I�=	*�
8a neF;_���;��O2���9���T�����V�L����׳��o�eq�^a]/O�5�w���TN.?��9]�H��`����
�ON@D�����ߦ����È"�:����"R�+~�m��
&��N�z��E{�z���bpǗ��˳��;6x��N���0��"Ø�ʛ�"*u|k�
�!��N���(�@%AAM�e>�)|SS����虢�nM�.����eLyo5`_Zk멃%������Q��u����L� ��e�:���z�>�+`�ۡd���F.��)>V?3��Nim%��=ܡ��rXD\pP��(*AK��Ck��>a�a��Aֻ^c�Ô�^W�YӼb��k��+:X��JX�)�3YW�S�p�;��뇴;�'d�]�MG�`����<�T\N�̈́�؉���.ڏ��%��?Q��o�E��$�c��"���f���W�55��x/�ھ�d2�U��DD�`���+�����|�/X�`']�o�W1"��;��]x����ci��E"(J��`Q��?�C/k���-�3~�^�h0a��`�g)�>q*41d>���Uk�T��¬l�H*����4;�c���*P#�?1�.�JO %|�^�j-Z�&��|�,Fy@{f�N6+P�	���
�ҭ�3��^.s|	X�[��+�j1 F�<뜺�ym\�]k����m�J=N!@m=�p�"6y!y,��>��e�+2�H��ao֠`�تW-�~p�(��C��0 ԫoH;�L,���C>�<�eI�~0�0�{��C{:R2h+FW�"W)�$��zjG�+��ɷ�W\^�$����C���O{�\SG@���n,����V"�� W''C8��܂�}���gR�P��`��D�+33����y�����k�]�h�w��p%W:���7h��D��m�w��<��kDș�nrX�!�z��_ބr�P�f�R�\(�N@^���9Q�X8��ѧs$��9�
�t�)�:&1�#b5E�#ٔ"��U �jQ�i���T#�@�F~:�y?�}�0p:H�&R��2[�#+B���Zi�����ep����"�e?��3�Z��4-hʼ[Km�|���V�9�ȡH��� �6�v/����S�p��I�Sו�^��B"j��ęh\��[�٣�b��8;��\�f{#�J��S(��ʼ�+Q��D3R��Z�IAR�R(A;�ּ!�~)T���|��Op뒑�d�y�"lケ�2(�H~^'�(n������)��qIk���Ov��%���9<����� �4����~�����h!�ϣ<�vy��k�x,����:%D��w�`3V>���ӳ]xZ
����:�;u_NZ�d۾�$������C�GS�ɠ�墓��>�8��oFYES_MLOFF_MASK           0x3FFFFC00u
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           0x40000000u
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           0x80000000u
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31
/* SLAST Bit Fields */
#define DMA_SLAST_SLAST_MASK                     0xFFFFFFFFu
#define DMA_SLAST_SLAST_SHIFT                    0
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK)
/* DADDR Bit Fields */
#define DMA_DADDR_DADDR_MASK                     0xFFFFFFFFu
#define DMA_DADDR_DADDR_SHIFT                    0
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK)
/* DOFF Bit Fields */
#defiZ�en���=��:���QI=t�~�ma
W���PP��;�HU��X�v�zv��� �5�=[>
�@����$����-_3Q�Po�H�<���X��c�+�û\���b.9�QL'�չ2������?��Cl.��w�*jU��AC�����io=ɤ�Mcڳ�����>y/"֮���<�8������1,��G�Z�e&y^���X1Z���rϚ){~�0�����&g�X-�m�n@�&o�_�4Im�)�~K"�2��(���ĉ''��ԏ����� r8�'�A�����G2��B? F�����5�-lF��S0U��<��Y�A�naI���Vje9��?E�gv��<�� �@�feҩ�w
@�@�=H��+��z�-��
��,��s�<����٧N=6Bx��H�<w����n���D�:V��!�.ঌ3vƔi鹹9
8��a!�b�aS�l-a�F�0x���y|4��I���ҷ��e\7�^�IWp��x�ꒊNe^X�<2����.7�F�
ƚ�q_��erA�'te�6Ȉk������d[���%�g��V�uR�U����t���nɼTף����$"yṯ�z,<���X�ͫ�z>|�X��7,8CI�j�<ܓy���BW^ϲ;��Fw����z�[A~�,�^��9T`<����F�����]Xh[o͞�1O�,��XY�f�ժ��30�g����q�L��P�\?�$SRz��HM�Y��Ts'�\3:��P+imPTPt�i���ʬqL'rR~W70�*��ckS�y�*��%	}-V��Ǳ8��ۇ�J�ͅ	�sv�2S���D�Ǯ�=.�t�r�[�>�Ct0�H�qf��%M%r�^�Ln�ȸt�O�>Š1�̈�2��h��7[��IC��-u�;�D5
b>��Q��k��-�'�*vL{�j�v [y�� ��� ���F�m�/K�q�3������@��+"�µ�"=,���O1��R��28��/�֭�^a�x�����~/}�Sx�6p��A��%œ߳h�K8��q2B_p1 �޾��&�r�y�?\�����<-`. 1��%2�<����/��O+�������`j�-������HR�q��nA��bZ���RSn��*�͘]�7b{T��aB�x�~��t�)O�9??n�Y	�0�Yǣ�������m:�
��G?���V�#��}�8��D�!B�Q���)6sD�8<oJg`��v���w��m�K�˹&���!�&teB����f	ծ4�X�N��d�Z�W8���,z$�d��VՑ?��8�� ����|i������t&�,��]<�Ky#	u��h^��>o��u �����9h�_r[�t���W�( ��36�� ؇�i%�w"�q�/�M(�{G��ϥ �e�c��t��$	It�fJ�uP��/c�F&����JXȹ=�7��} x�D�'�M�t�[��TR8�������#���H{�l���qr���~hx����ǃ��]�ʄ�{��d��.A��z�-��kzm�ǦJ�_A
R�s�I��&�f�Ɛ?�q}��Yn�n���SE�:�62g�y9�t!䜏\���%��4�D��I�=	*�
8a neF;_���;��O2���9���T�����V�L����׳��o�eq�^a]/O�5�w���TN.?��9]�H��`����
�ON@D�����ߦ����È"�:����"R�+~�m��
&��N�z��E{�z���bpǗ��˳��;6x��N���0��"Ø�ʛ�"*u|k�
�!��N���(�@%AAM�e>�)|SS����虢�nM�.����eLyo5`_Zk멃%������Q��u����L� ��e�:���z�>�+`�ۡd���F.��)>V?3��Nim%��=ܡ��rXD\pP��(*AK��Ck��>a�a��Aֻ^c�Ô�^W�YӼb��k��+:X��JX�)�3YW�S�p�;��뇴;�'d�]�MG���/�#}��j���+Hԓ2.O���LsˡL��&7{i���
�����V�ğ "S݊$�����u9}~��k�}���]݂�|�w�r^[�;�)hH�cE����`%�B9t4�l���� G�����Ͳ�fc�*B�#78���ͯ������	�7BW Ԏ_��q;&H�!U.JB԰�#����l��5!�#dS��[x���Ê�9����>�m��ѿ��߰��:_"�h%�H
D�T~�_p/�X�[�E�o����\�E�A�(�ɨ܌C����
�PŁ��3b�ax���y��@-'$hC!�/��My�0�N($�����?Zj�%��A�!��e[A�/�.w�X��}ޯHR�	�o;T}��eδ����Yuj�>�k�3��H�p�F������/|���m[NeX@qs�`|?�W�Qn������p�q
�]<��C�7�|���m4��Z�px���(��O��/L�#��yI�8A|��_�r����.��h��|i���|X���6/�D���L]�'i�B�1�fs,+(�t�=@?ެ>'�}�ҩ�+qu�CL��^22�����c��F*Û+E6T�7�UI��g��ygbd�ԲU5@Co��Coi0�����L��ȺA����W�DY��U/�W���wHڵ�X��w+ss�h{��<H�Q�|?��]
�f��o��M�t]h�? �퓚�a�P�6���u��էJ�O٭�����az�Z?=>��2b��+�QDuJ��]Z�L{B0��ʔ+i"�hv��Л��E=JZ
�[ϖMM��&���B1��D���SE��A�EB��񂸇+�"��6�� X�d��ÅS.{}�M�ڃ�95�C�>r�������#@Y�\ԮA�6�"=���܂�=�F��::K��f���d�Nti�!��s���x-�X���v���R��..�4�M�3�yJ��uo˷,�!l0d���o��)u�"���C� �K`�hDc���`�����}2^LINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15
/* BITER_ELINKYES Bit Fields */
#define DMA_BITER_ELINKYES_BITER_MASK            0x1FFu
#define DMA_BITER_ELINKYES_BITER_SHIFT           0
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15

/**
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base poin�0��HN=��mMUk�A�2���.�[�'�\�00Q���N��H�[|]�'�j��|����8�����z@��EXz��y�Ş���P�M�8����'QG��ƃ
�?�]XNc���ڔ^���g��T݂�����I�yPD?��&�/�2jk���5D	� �N��R�h�!���+������W}K��uU��A�i���D����f��1�.2�|x�_��X�R�	����("��'�O�d��T)�cATԁ���kѺ�w7N�J��H�@�͌���]Ύɢ,6~T�R��flR,��L?V���f�!w� �x��J"�
+s�C�dpw�R�t��,AI�v���9ǧ��KS9�}ɉ��6VgPml��v�"\��M5uG�(Î��9�g��aw�#��	Q@S	hv��/�5�Ch+5t�����}��7U�῕�B�*Kw������=H{6\<=g��ށ��{<oDS ��~��x�@ -�)�e������\��2N�@ɩ��I�"���؉�U]�|݌�������=�7ԃ��Ҙ��agf���k�	g���CDŵ�U���>e�s�Jl���	������ؤk/�l9��MJ�����g�]�k��A,{x��=��@x^��9�[|�B3xŐZ���?v�>_��խ�
���{��f᝹7�h<)��:y3��`rڪ���i�&����o�YR�����H��q*Y�9\,��
�m�r��{ҏ�9Z��z�y*��C��u�ㇸ
;ɤ�y1��3�H e�	�W�SC/o+�p�7�:
4�g},�!�tU���-33bnҍ �l��]o3Tm�V��P �DՎ(2����RQ�j��������Z
�u���h��W����V��Ő�N.�S��M�S2��?k�c���n���!P"q�UYa5�.0O^;��9�%�{�����ПQr[aà�����g��nCU��;
W�R4*Qn��:���-ak�c�ҹ�-H��o�@�PWp�sH���5���j�
#defile DMA_CERQ                   `        (    @MA_CERQ_ZEG(DMA_BASE_PTB)
#define DMA_SERQ                               (�DMA_SERQ_REG(EMA_BASE_PTR)
#define DMA_CDNE(               "                DMA_CDNE_REG)DM�_BASE_PTR)
'define D�A_SSRT     "                     `     DMA_SSRT_REG(DMA_BASE_PTR)
#define DMA_CERR                           0(   $DMA_CERR_REG(DMA_BASE_PTR)
#define DMA_CINT              !(                 DMA_CINT^REG(DOA_BASE_PTR)
#define DMA_INT        " $ �           0         DMA_INT_REG(DMA^BCSG_PTR)
cdefine DMA_ERR $                   �   �        DMA_ERR_REG(DMA_BASE_PTR)
#define DMQ_HRS                                  DMA_HRS_REG(D]A_BASE_TR)
cdefine DMa_DCHPRI3                 0        "   DMA_DCHPRI7_REE(DMA_BAE_PTR)
#define DMA_DCHPRI2                              DMA_DCHPRI2_RMG(DMA_BASE_PTR�
#define DMA_DCHPR	1     �            (           DMA_DCHPRI1_REG(DEA_BASE_PTR)
#defi.e DMA_dCHPRI0                              DMA_DCHPRI0_REG(DMA_BAYE_PTR)
#define DMA_DCHPRI7                              DMA_DCHPRI7_REG(DMA_BASE_PTR)
#define DMA_DCHPRI6                              DMA_DCHPRI6_REG(DMA_BASE_PTR)
#define DMA_DCHPRI5                              DMA_DCHPRI5_REG(DMA_BASE_PTR)
#define DMA_DCHPRI4                              DMA_DCHPRI4_REG(DMA_BASE_PTR)
#define DMA_DCHPRI11                             DMA_DCHPRI11_REG(DMA_BASE_PTR)
#define DMA_DCHPRI10                             DMA_DCHPRI10_REG(DMA_BASE_PTR)
#define DMA_DCHPRI9                              DMA_DCHPRI9_REG(DMA_BASE_PTR)
#define DMA_DCHPRI8                              DMA_DCHPRI8_REG(DMA_BASE_PTR)
#define DMA_DCHPRI15                             DMA_DCHPRI15_REG(DMA_BASE_PTR)
#define DMA_DCHPRI14                             DMA_DCHPRI14_REG(DMA_BASE_PTR)
#define DMA_DCHPRI13                             DMA_DCHPRI13_REG(DMA_BASE_PTR)
#define DMA_DCHPRI12                             DMA_DCHPRI12_REG(DMA_BASE_PTR)
#define DMA_TCD0_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_SOFN `                          DMA_SOFB_REG(DMA_BASE_PTR,0)�#define DMA_CD0_ATTR                        (   DMA_ATTROREG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLNO   `        ( "   0  DMA_NBYTES_MLNO_REG(DMA_BQSG_PTR,0)
#define DMA_TCD0_NB]TES_M\oFFNO                  DMA_NBYTES_MLOFFNO^REG(DMA_FASE_PTR, )
#define DMA_TCD0�NBITES_MLOFFYES                 DMA_NB�TES_MLOFFYES_REG(DMA_BASE_XTR,0)
#definu DMA_TCD0_SLAST         "                 EMA_SMAST_REG(DMA_BASE_PTR,0)
#define�DMA_TCD0_DAdDR !                         D]A_DADDR_REG(DMA_BASE_PTV,0(
#define DMA_TCD0_DOFN   ( (      0               DmA^@OFN_REG(DMA[BASE_PTR,1)
#define DMA_TCD0_CITER_ELINKNO           !       DMA_CITEZ_ELINK�O_REG(DMA�BASE_PTR,0)-#define DMA_TCDp_CITEBWELINKYES                 !DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,0!
#defi�e DMA_P�d0_DLASTSEA     h      0           DMA_DLAST_SGA_REG(DMAWBASE_PTRl0)
#define DMA_TCD0_KSR                           ( DMA_CSR_REG(DMA_BASE_PTR,1)
#def�ne DMA_TCD0_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD1_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_CSR                             DMA_CSR_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,1)
#define DMA_TCD2_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DADDR                           DMA_DADDR_REG(DMA_CASE_PTR,2)
#define DMA_TCD2_DOFF         !           !      DMA_DOFF_REG(DMA_B�SE_PTR,2)
#de�yne DMA_TCD2_CITER_ELINKNO                   DMA^CITER_ELINKNO_REG(DM@_BASE_PTR,2)
#define DMA_TCD2_CITEP_ELI^KYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DLASTSGA @                      DMA_DLAST_SGA_REG(DM�_BA�E_PTR,2)
#define DMA_TCD2_CSR                `            DMQ_CSR_REG(DMAYBASE_PTR,2)#def)ne DMA_TCD2_BITER_MLHNKNO                   DMA_BITER_ELINKNO_REG(DMA_BAWE_PTR,2)
#dufine DMA_TCD2_BIDER_ELINKYES!   $   !         TMA_BITER_ALINJYES_ReGhDMA_BASE_PTR,2)
#define DMA_TCD3_SADDR        "       $          DMA_SADDR_REG(DMA_BASE_TR,3)
#define DMA_TCD3_SOFG    0                       DMA_SOFF_REG(DMA_BAE_PTR,3)
#define DMQ_TCD3_ATTR �        "      (          DMA_ATTR_REG(DMA_BASEWPTR<3)
#define`DMA_TCD3_NBYTES_MLNO                     DMA_NBYTES_ILNO_BEG(DMA_BARE_PTR,3)
+define DMA_TCD3_NBYT�S_MLONGNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,3)�#define DMA_TCD3_NBYT�S_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,3)#debine dMA_TBD3_SLAST 0                     0   DMA_SLAST_REG(DMA_BASE_PTR,3)
#define DMA_TD3_ADES                           DMA_DADDR^REG(DMA_�ASE_PTR,3)
#define DMA_TCD3_DOFF                            DMa_DOFD_BEG(DMA_BASE�PTR,)
#define DMA_�CD3_CI\ER_MLINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,;)
#tefine DMAWTCD3_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_B�SE_PTR,3)
#define DMA_TCD3_DLASTSGA0                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,3)
#defi�e DMA_CD3_CSR  0     `      (             DMA_C[R_REG(DMA_BASE_PTR,3)
#define DMa_TCD3_BITEV_ELININO �                 DMA_BITER_ELIJKNO_REG(DMA_BASE_PTP,3)
#define MA_TCD3_RITER_ELINKYES                  DM_BITER_ELHNKYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD4_SaDDR       $                   DMA_SADDR_REG(DMA_BASE_PVR,4)
#definm DM�_TKD4_SOFF                       " #  DMA_SOFF_REG(DMA_BASE_PTR,4)
�define DMA_TCD4_ATDR    �                      `DMA_ATTR_ZEG(DMA_BASEWPTR,4)
#defin� DMA_TCD4_NBYTES^MLNO                     DMA_NBYTES_MLNO_REg(DmA_BASE_PTR$4)
#ddfine DMA_TCD4_NBYTES]MLOFFNO 0     $          DMA_N�YTES_MLOFFNO_REG(DMA_BASU^PTR,4-
#definE DMA_TCD4_NBYTES_MLOFF[ES               $ DMA_NBYTES[MLOFFYES_REG(DMA_BASE_PTR,4+
#define DMA_TCD4_LAST              "            DMA_SLAST_REG(DMA_BASEOPTR,4)
#de�ife DM_TCD4_DADDR     `                   " DMA_DADDR_REG(EMA_BASM_PTR,4)
#define MA_TCD4_DOFF        0"                  DMA_DOFF_REG(DMA_BAS�[PTR,4)
#define DMA_TCD4_CITER_ELIKNO                   DMA_GITER_ELINKNOOREG(DMA_BASE_PTR,4)
#definu DMA_TCD4_CITES_ELINKYES  (               DMA_CITER_MLINKYES_rEG(DMA_BASE_PTR,4)
#defile!DMA_TCD4_DLA[TSGA   $                    DMA_DLAW\_SGA_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CSR              (   "          EMA_CSR_REG(DMA_B@SE_PTR,4)
#define DMA_TCD4_BITER_ELINKNO            $      DMA_BITER_ELIN�NO_REG(DM�_BAS�_PTR,4)
#define DMA_TCD4_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD5_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_CSR                             DMA_CSR_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,5)
#define DMA_TCD6_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_CSR                             DMA_CSR_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,6)
#define DMA_TCD7_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_CSR                             DMA_CSR_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,7)
#define DMA_TCD8_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_CSR                             DMA_CSR_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,8)
#define DMA_TCD9_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_CSR                             DMA_CSR_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,9)
#define DMA_TCD10_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_CSR                            DMA_CSR_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,10)
#define DMA_TCD11_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_CSR                            DMA_CSR_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,11)
#define DMA_TCD12_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CSR                            DMA_CSR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,12)
#define DMA_TCD13_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_CSR                            DMA_CSR_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,13)
#define DMA_TCD14_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_CSR                            DMA_CSR_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,14)
#define DMA_TCD15_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_SOFF                           DMA_SOFF_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DADDR                          DMA_DADDR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DOFF                           DMA_DOFF_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_DLASTSGA                       DMA_DLAST_SGA_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CSR                            DMA_CSR_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,15)

/* DMA - Register array accessors */
#define DMA_SADDR(index)                         DMA_SADDR_REG(DMA_BASE_PTR,index)
#define DMA_SOFF(index)                          DMA_SOFF_REG(DMA_BASE_PTR,index)
#define DMA_ATTR(index)                          DMA_ATTR_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLNO(index)                   DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLOFFNO(index)                DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,index)
#define DMA_NBYTES_MLOFFYES(index)               DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,index)
#define DMA_SLAST(index)                         DMA_SLAST_REG(DMA_BASE_PTR,index)
#define DMA_DADDR(index)                         DMA_DADDR_REG(DMA_BASE_PTR,index)
#define DMA_DOFF(index)                          DMA_DOFF_REG(DMA_BASE_PTR,index)
#define DMA_CITER_ELINKNO(index)                 DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,index)
#define DMA_CITER_ELINKYES(index)                DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,index)
#define DMA_DLAST_SGA(index)                     DMA_DLAST_SGA_REG(DMA_BASE_PTR,index)
#define DMA_CSR(index)                           DMA_CSR_REG(DMA_BASE_PTR,index)
#define DMA_BITER_ELINKNO(index)                 DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,index)
#define DMA_BITER_ELINKYES(index)                DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,index)

/**
 * @}
 */ /* end of group DMA_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DMA_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMAMUX
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Peripheral DMAMUX
 * @{
 */

/** DMAMUX - Peripheral register structure */
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[16];                               /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} volatile *DMAMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register accessors */
#define DMAMUX_CHCFG_REG(base,index)             ((base)->CHCFG[index])

/**
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/* CHCFG Bit Fields */
#define DMAMUX_CHCFG_SOURCE_MASK                 0x3Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT                0
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7

/**
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base pointer */
#define DMAMUX_BASE_PTR                          ((DMAMUX_MemMapPtr)0x40021000u)
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros
 * @{
 */


/* DMAMUX - Register instance definitions */
/* DMAMUX */
#define DMAMUX_CHCFG0                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,0)
#define DMAMUX_CHCFG1                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,1)
#define DMAMUX_CHCFG2                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,2)
#define DMAMUX_CHCFG3                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,3)
#define DMAMUX_CHCFG4                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,4)
#define DMAMUX_CHCFG5                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,5)
#define DMAMUX_CHCFG6                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,6)
#define DMAMUX_CHCFG7                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,7)
#define DMAMUX_CHCFG8                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,8)
#define DMAMUX_CHCFG9                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,9)
#define DMAMUX_CHCFG10                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,10)
#define DMAMUX_CHCFG11                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,11)
#define DMAMUX_CHCFG12                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,12)
#define DMAMUX_CHCFG13                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,13)
#define DMAMUX_CHCFG14                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,14)
#define DMAMUX_CHCFG15                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,15)

/* DMAMUX - Register array accessors */
#define DMAMUX_CHCFG(index)                      DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,index)

/**
 * @}
 */ /* end of group DMAMUX_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DMAMUX_Peripheral */


/* ----------------------------------------------------------------------------
   -- DWT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Peripheral DWT
 * @{
 */

/** DWT - Peripheral register structure */
typedef struct DWT_MemMap {
  uint32_t CTRL;                                   /**< Control Register, offset: 0x0 */
  uint32_t CYCCNT;                                 /**< Cycle Count Register, offset: 0x4 */
  uint32_t CPICNT;                                 /**< CPI Count Register, offset: 0x8 */
  uint32_t EXCCNT;                                 /**< Exception Overhead Count Register, offset: 0xC */
  uint32_t SLEEPCNT;                               /**< Sleep Count Register, offset: 0x10 */
  uint32_t LSUCNT;                                 /**< LSU Count Register, offset: 0x14 */
 ����q������{t���:ģ���Y:�HP�S��'�/�4�a�!05��m�~�=�x�� ���2OK~�DF�������?���`�x������Ul��}�ΰ�MgE^��#�f����VD�֡���7��K�&B"�#U�����-���Ҡղކc��Ӂ����n�t�y���� U��I�D`*ך���ИK^����c��2�]�w����6��6�5�ų�8b�Z;�݉b��z줣q�I9%|52��x��Պ$� wR��0�L��SA�{T�,Atv��(0{,GMO	���=C����ٝ-0�䨋��Qڮ�⻆����P�0r� f��Xf�\����+�E4��eLz��6����3�:>5@��I2�C� �A�j��Z���H�����jc�;��1C��ռ�=v���F/;,	�/�+�E�ص���⧠5fN�JTk�[a8`-�ԙ�n�lv�:(����;��Z:4ж^�/7\�5��˧�G#�Tfl�OL����;�H\\��/-�#5t�Y��aVA�42!A�4y����zȍc��H�ј����ƃ��o�s�51��U��@��T��V��8���B3�#7[����}�Ji+�J�qm�C�!�u��&�K�����J��R��x�& He�Ǧ�@����371,>��՞j)g3;ʇAuN�Y_�.�X���y4H*�_=}��>m�҇���H��^^o��fZ����j��Ak�7kn����S���%	e�I*c���Wo��iͪr4>�&#!��Z�Ef8��VM#,���AV��ڵM<��j�D0C˛0dW� �>Ƒ����6ĬSm��R����'�"�̻����G[	ǐ�w�N��0p���^�ɾ�G�
cԤ�P[	�~.��^��������j ]��Ԃ4"2��[ѧ�ņ�荅�KR
������c&���sBaG��,��w��}�t�����][��E�7W������'sL�1�}�׫Ps��w����Y�w�(.c޲�;���n��7]Sܖ8P�	�=���nx�3I�`�<�ِ��b�B,���"2�o���]���
�j1uʅ8��w\h�V�>����A�����ق��>E��Y���zG����ߙ0Ŷ�}	�	9_�J?�V@��y��oU|�_�)���j���/�&>���T�Ez�1�b�]�9��u��ܝtG��|m�󂞯z�_3�Ӹ��?Q���P�Z��XɔnKV�h$DӸO�O�2���"�����|L@�)9�;��]Ox��2��Az6�[׎�J�|�P�x+if�{��o��\3�s]|�<�������<�Z������*hKJV��qr{�|�j��x��?�Ta�iNM� :wr�/jT�Q����Psڶ��r�&�ٝ��Oq�~ū嵢x��taZ?6a8�4��N���(�식˄4��������""���J�����0��#�R����K4<�95&z���E�X�)��l�YM\B����f���#OjQ+�0�-��B���˾_�W�!v��^�|m��8���ɪO����҈=lz���ԛd�h/��B���eyn����#�Ps8UdB�Y���<���}��5���#�@��)(�L���~t�RఉQ��@;��x��"m���$��ֻ�Ë}�,:yMD#���*�o_qsnod�!\�Yqv~y�!)W^q9r��G����H\B�r\X��#���L��S��n?��e��)&P���I��*l�$�t���O���]8�έ���頣�a�}E\u��-�ǟ���U���)��������;Ш�TL7��/!<���=�� �7�9��C�ҥ��E6$Of��v��
��x��@D^�N(OL*������Q�{���W��\�c��K4h���TC0J%��,�wd5,Xf�|��'}�����<����܏h���(����P�2Dt��+��yz��Z�ǟ�VQ+�a>�ڴw[�1�a� CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *DWT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register accessors */
#define DWT_CTRL_REG(base)                       ((base)->CTRL)
#define DWT_CYCCNT_REG(base)                     ((base)->CYCCNT)
#define DWT_CPICNT_REG(base)                     ((base)->CPICNT)
#define DWT_EXCCNT_REG(base)                     ((base)->EXCCNT)
#define DWT_SLEEPCNT_REG(base)                   ((base)->SLEEPCNT)
#define DWT_LSUCNT_REG(base)                     ((base)->LSUCNT)
#define DWT_FOLDCNT_REG(base)                    ((base)->FOLDCNT)
#define DWT_PCSR_REG(base)                       ((base)->PCSR)
#define DWT_COMP_REG(base,index)                 ((base)->COMPARATOR[index].COMP)
#define DWT_MASK_REG(base,index)                 ((base)->COMPARATOR[index].MASK)
#define DWT_FUNCTION_REG(base,index)             ((base)->COMPARATOR[index].FUNCTION)
#define DWT_PID4_REG(base)                       ((base)->PID4)
#define DWT_PID5_REG(base)                       ((base)->PID5)
#define DWT_PID6_REG(base)                       ((base)->PID6)
#define DWT_PID7_REG(base)                       ((base)->PID7)
#define DWT_PID0_REG(base)                       ((base)->PID0)
#define DWT_PID1_REG(base)                       ((base)->PID1)
#define DWT_PID2_REG(base)                       ((base)->PID2)
#define DWT_PID3_REG(base)                       ((base)->PID3)
#define DWT_CID0_REG(base)                       ((base)->CID0)
#define DWT_CID1_REG(base)                       ((base)->CID1)
#define DWT_CID2_REG(base)                       ((base)->CID2)
#define DWT_CID3_REG(base)                       ((base)->CID3)

/**
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DWT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Masks DWT Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group DWT_Register_Masks */


/* DWT - Peripheral instance base addresses */
/** Peripheral DWT base pointer */
#define DWT_BASE_PTR                             ((DWT_MemMapPtr)0xE0001000u)
/** Array initializer of DWT peripheral base pointers */
#define DWT_BASE_PTRS                            { DWT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DWT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DWT_Register_Accessor_Macros DWT - Register accessor macros
 * @{
 */


/* DWT - Register instance definitions */
/* DWT */
#define DWT_CTRL                                 DWT_CTRL_REG(DWT_BASE_PTR)
#define DWT_CYCCNT                               DWT_CYCCNT_REG(DWT_BASE_PTR)
#define DWT_CPICNT                               DWT_CPICNT_REG(DWT_BASE_PTR)
#define DWT_EXCCNT                               DWT_EXCCNT_REG(DWT_BASE_PTR)
#define DWT_SLEEPCNT                             DWT_SLEEPCNT_REG(DWT_BASE_PTR)
#define DWT_LSUCNT                               DWT_LSUCNT_REG(DWT_BASE_PTR)
#define DWT_FOLDCNT                              DWT_FOLDCNT_REG(DWT_BASE_PTR)
#define DWT_PCSR                                 DWT_PCSR_REG(DWT_BASE_PTR)
#define DWT_COMP0                                DWT_COMP_REG(DWT_BASE_PTR,0)
#define DWT_MASK0                                DWT_MASK_REG(DWT_BASE_PTR,0)
#define DWT_FUNCTION0                            DWT_FUNCTION_REG(DWT_BASE_PTR,0)
#define DWT_COMP1                                DWT_COMP_REG(DWT_BASE_PTR,1)
#define DWT_MASK1                                DWT_MASK_REG(DWT_BASE_PTR,1)
#define DWT_FUNCTION1                            DWT_FUNCTION_REG(DWT_BASE_PTR,1)
#define DWT_COMP2                                DWT_COMP_REG(DWT_BASE_PTR,2)
#define DWT_MASK2                                DWT_MASK_REG(DWT_BASE_PTR,2)
#define DWT_FUNCTION2                            DWT_FUNCTION_REG(DWT_BASE_PTR,2)
#define DWT_COMP3                                DWT_COMP_REG(DWT_BASE_PTR,3)
#define DWT_MASK3                                DWT_MASK_REG(DWT_BASE_PTR,3)
#define DWT_FUNCTION3                            DWT_FUNCTION_REG(DWT_BASE_PTR,3)
#define DWT_PID4                                 DWT_PID4_REG(DWT_BASE_PTR)
#define DWT_PID5                                 DWT_PID5_REG(DWT_BASE_PTR)
#define DWT_PID6                                 DWT_PID6_REG(DWT_BASE_PTR)
#define DWT_PID7                                 DWT_PID7_REG(DWT_BASE_PTR)
#define DWT_PID0                                 DWT_PID0_REG(DWT_BASE_PTR)
#define DWT_PID1                                 DWT_PID1_REG(DWT_BASE_PTR)
#define DWT_PID2                                 DWT_PID2_REG(DWT_BASE_PTR)
#define DWT_PID3                                 DWT_PID3_REG(DWT_BASE_PTR)
#define DWT_CID0                                 DWT_CID0_REG(DWT_BASE_PTR)
#define DWT_CID1                                 DWT_CID1_REG(DWT_BASE_PTR)
#define DWT_CID2                                 DWT_CID2_REG(DWT_BASE_PTR)
#define DWT_CID3                                 DWT_CID3_REG(DWT_BASE_PTR)

/* DWT - Register array accessors */
#define DWT_COMP(index)                          DWT_COMP_REG(DWT_BASE_PTR,index)
#define DWT_MASK(index)                          DWT_MASK_REG(DWT_BASE_PTR,index)
#define DWT_FUNCTION(index)                      DWT_FUNCTION_REG(DWT_BASE_PTR,index)

/**
 * @}
 */ /* end of group DWT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DWT_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Peripheral ETB
 * @{
 */

/** ETB - Peripheral register structure */
typedef struct ETB_MemMap {
  uint8_t RESERVED_0[4];
  uint32_t RDP;                                    /**< RAM Depth Register, offset: 0x4 */
  uint8_t RESERVED_1[4];
  uint32_t STS;                                    /**< Status Register, offset: 0xC */
  uint32_t RRD;                                    /**< RAM Read Data Register, offset: 0x10 */
  uint32_t RRP;                                    /**< RAM Read Pointer Register, offset: 0x14 */
  uint32_t RWP;                                    /**< RAM Write Pointer Register, offset: 0x18 */
  uint32_t TRG;                                    /**< Trigger Counter Register, offset: 0x1C */
  uint32_t CTL;                                    /**< Control Register, offset: 0x20 */
  uint32_t RWD;                                    /**< RAM Write Data Register, offset: 0x24 */
  uint8_t RESERVED_2[728];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint8_t RESERVED_3[3032];
  uint32_t ITMISCOP0;                              /**< Integration Register, ITMISCOP0, offset: 0xEE0 */
  uint32_t ITTRFLINACK;                            /**< Integration Register, ITTRFLINACK, offset: 0xEE4 */
  uint32_t ITTRFLIN;                               /**< Integration Register, ITTRFLIN, offset: 0xEE8 */
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_4[4];
  u�nt32_t ITCTRL;         �             "         /**< Integration Mode Contzol�RegiSter, offset:00xF00 */
  }int8Wt ZUSERVEF_5[156];
$ uint32_t CLAIMSDT                               /*�< Claim Tag0Set Register, offset: 0xFA1 */
  uint32_t CLAI]CLR;                               /**< Claim Tag`Cleab Register, offset: 0xFA4 */
  uint8_t RESERVED_6[8M;
  qin�32_t LAR;                             !      /**< Locj Access RewiSter, offset: 0xFB0 */
  uint32_t LSR;                                0`  /**< Lock Status Register, offset; 0xFJ4 */
  uint32_t AUTHSTATUS;                             /**<(Authenticatio. statu3 Register, offset:!0xFB: *?
  uint8_t RESEVVED_7[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0hFC8 */
  uint32_t LEVTYPE;                                /**< Device Type Identifier Register, off3et: 0xFCC */
  uint32_t PIDR4;       "         (               0/**< Peripheral Identification Register 4, offset: 0yFD0 */
  uinv32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                     �3��KiǏ�9q����ڣٯ��#ob�J1�@T3ܕ]X��'����������C���|�������e/�]��p�R��R;4+b�,D55�H�۷&����3�
�e�%-c-Nm/&k���W��;[[�+ݾT�`���G"�p�q�6���O�[F�[�H1g��U��n �"4ÿ�,m����t�F���Ҹ[K�r�8�a�p�e����K���B�[��|�4��Y��d��T���� �M�f{�P����޶!p3<�\C%t����t� !�d�)��H���P�H�@�ӽr]w��g�|�W��C���v�.,���k`�]ЬD�0����X����ACXy9�^I<��~��+�Bk�)6�ww[�ͳ���*�Jʓ8:f���}((���݌�o�< pǄi� }�$��x�[�>M��mL�1���\"o��K|�6"�S:+pU�`lo:L��wW4�=�EM�Z�h�g5x�t��.�I�v�h.�I��8����oW��˨Yd��W�b�p��
/�j�x�.4ӛ-���{+�0���u�L"�ߍ1�����B�>��N1W�V�#�RV/7��cN��c9�����VZC�ç`$�PDT��H"�N���Ȏ�[����V����	�.8;]E��M���n4�0�I���谕
E5���
��y.S�H��hL{��x\>(�:��M� !%T�/�Q�s&Y���Z������)+N:�M��Y@��b���X��!	��Ր������yt	
|"�s�ql���.6�Tп�$�SƑ��I�{�gRq(<IOQ�ax��뵎����j(}1j�e;F<9�Cĭ�z�I�ӆ[�bq��E"gR��� VB_ljѿ\�|�|����cS��h��5cX�j��-N۝��t��M��\��&�ﯥ�)�ix�Աb��Z|K���hn�W�cS'G��Թ�h�FK��BU)��i��Ϫ�l�,�J�4 4YP-��Z=|�O/�xNE���[���-�Cßp�]ѯ���٤��eeU{�;�)���D��بT���Ku��b!��s���W�P�	���1�
�������:^�\��۞�A����9XQ�x��"	�3ω�ƣ\dI�bs!S� �z����Ϭ�3(O�[:�g�{��,}�O5>�j�J6��j�ɘ%��{������b�+Igɐ>/J���X�G��9` 4��R� _���k��, l���-����H�Yql�l>��b��QeIH���6���J,R!��/u��/�����s���aQT�St��M`J�j��6a�(�Iɖ��i{țy���2V�ޮ9ذd��2_��Λ;�a��x��[*�������o����Tㄢ�0K4LJ G������x�d#ƞ.�)�D�-�2��]��L�ǐ���$�``^a&/Ӡ��x{o������9�RU���
�a2	Wj��^�ٻ�m�[#�;���a�+���f�vx%�����Üb�s��[�b���PSTN�<u����L���0�[ZR7������L�A~�~�C�ⶎ�|k��u��Ȏ�0q��(?R���!��<�#@�����h�Z��w'���_�l0�(c��`�FSФ�gK�g��F��u�?m�a�Γ�+�^Û���s��u�����o�@~Յ:�7�k��gs�p����d����<�	�+����I�����q lJjB�����Z�E�>�X�^+JO�������T��l��Ca���e(�i��H7��y)Y;�Q�����<x�8iJ�Sk��E�(6}�����a�B���'�,Cz��3B,��ٞ��Ԭ_�o���K��#(�s��� d:�u�'YB����Gޞ*KO�e�3���f����?����H���9��J���Ô�6@8Ҁ�� L����Z�& �Tw�=US�`V��{��u�Jol��[HԤ���}
d���N�3��A���=j�����5�w�;�G;�S.A����p���� ��y���F��.��^Pm�+��?O`Ю�r\��]5^\N�����ƍ�_�%tS�-�jX��J���VmAT�A��aG=~T��Gp��� b���?��)Y'��t�|"SC����d�[��pZ��p�Y�A1[�x��ow�%���6^�	�Z�O��1¨�ϔY�����x�Z5��`Y�6��� �V&�9��4�4�g� �DPX���,�F�EE�Q�/�@���X!�*@�Z�G���OtqY\T�s����S���=3�M�'�'T�@�\9��GU��W�EqiM���f=�~/N_�@×\b^����"��J)�bx��G�^O��D��I|���@g�8��sC�K[�U	v� �[�B��-=
*aa#�a����0�+LJ��j&���Q���[!o:E�m�z�\��\!4�ꄂ�?��>~��k��D w{��J�$��%�&W'�p^�+c��Љ��ՕH�����8�0�P27�6K�_��VM�gg���w�T@��E��;�P,��+Z�z�j1D������z�a�������� H�U�z4�c�x���P`�yG$U���r�d6��١T��;:�z�8�v1ik�uq�K����ǅW\�&�ݥ(�S/[W�|�F��:1�N�+U�����O{߷Ƥ��\T@p�O��k�+a��I;b���im���}kɵ_O�1�c#���&�!a^o��֯���4�z��,�UW믛��)�5$$<���p�}�k`ٌ�$7ɕ�0l!!	j��	�޵h�v��l �	R���-8!q�	Bv\TA��c�]A�UD�'_�O9D���(%�i����k^T�|g���AA���n&>Y1������G���6 �B?�Wt]Ʋ�yxd*�b��R�f��l�͑��R_0q"��~wI<��9����t�o��}7�Xp�M:X���{栏���Β�N�QSN0�Yn��*�:v� x՗�2�m*f���.I������G˖��$����"�kc�lpE�m��%cI�0�y0��q�͓ԍ�J�g���^kc@� m��3��q�	���MY(]^>ߥ�jU����C�U��O�)��(��Q�Wdl��N�J+j�Q����7u3Q@i�
7��gT��u�m7;h��D\�;g���{J[hJ�ڼ>��/s�!�IS��tNuA3�(�ß�����a����[� �M���I���h�;���R�uUi(P�7�}���9���?c'��I��^M˧&���w��W-{�<A�(N�Km�gͧ(K1Cts�Sc0"~�8bL�2�*)���2��N������Ruv�.�;9�z*/�������yTz"�훡�>���Sdǋ����w�4��_=�y) Bo�״M�g��OPsa�6��X���j3�?x7�@O!����� TK�ku����H_�}�H�,���h�e�0��U����T��f�g��
�ȷ��
�E�O��=����.��2�}w��P!�[��W5 �liс�C���I@���.Α"��*��h'Fc��X�T�!bf���iO�z`�B0.�L�c�So|n���o�H�-�kD�m�h)rC�/��r��%f�~�!��"�|ka]əD��,~4#�(jK��ͨ��\يl~��ƺ�✊�V�J�C��˪r1,�d�]� �Fh�"���l,6ua�/Ͷϐ6�'`���%� L�f��P�'O��c��Z�!���P�5K��f/`�I�'^r~��g	�"[8����}͒�H"(�����6q��|�I��	�#i���/<���n��gmPͿ65g�d+�aV:.��-�t�a��~�0�"���[ӆ3����۬��~΀h�6Y�%xs>=x�Ld�s�:�2��ke(��`�����������L��	�O=�yS�Nm-Έ=�7���m�b���q��_�5c�]���iGU�G�w@��uPnΥ/�g#P���]zӰ���KX(���R=Q'�6~�)�wa�fP.q&�q���?"�3�`�3��KiǏ�9q����ڣٯ��#ob�J1�@T3ܕ]X��'����������C���|�������e/�]��p�R��R;4+b�,D55�H�۷&����3�
�e�%-c-Nm/&k���W��;[[�+ݾT�`���G"�p�q�6���O�[F�[�H1g��U��n �"4ÿ�,m����t�F���Ҹ[K�r�8�a�p�e����K���B�[��|�4��Y��d��T���� �M�f{�P����޶!p3<�\C%t����t� !�d�)��H���P�H�@�ӽr]w��g�|�W��C���v�.,���k`�]ЬD�0����X����ACXy9�^I<��~��+�Bk�)6�ww[�ͳ���*�Jʓ8:f���}((���݌�o�< pǄi� }�$��x�[�>M��mL�1���\"o��K|�6"�S:+pU�`lo:L��wW4�=�EM�Z�h�g5x�t��.�I�v�h.�I��8����oW��˨Yd��W�b�p��
/�j�x�.4ӛ-���{+�0���u�L"�ߍ1�����B�>��N1W�V�#�RV/7��cN��c9�����VZC�ç`$�PDT��H"�N���Ȏ�[����V����	�.8;]E��M���n4�0�I���谕
E5���
��y.S�H��hL{��x\>(�:��M� !%T�/�Q�s&Y���Z������)+N:�M��Y@��b���X��!	��Ր������yt	
|"�s�ql���.6�Tп�$�SƑ��I�{�gRq(<IOQ�ax��뵎����j(}1j�e;F<9�Cĭ�z�I�ӆ[�bq��E"gR��� VB_ljѿ\�|�|����cS��h��5cX�j��-N۝��t��M��\��&�ﯥ�)�ix�Աb��Z|K���hn�W�cS'G��Թ�h�FK��BU)��i��Ϫ�l�,�J�4 4YP-������IC315;}�S��6\��!Eq�&�� ���76-���������ޓ�m��B��<]r�=���ѪVU㉤"��p�y��u)8bF�u�,wX{�4���CM���[��[�pSl���~u��Ρ�m�*��I�{���Q�Wt9S23|�]�Uآ ���"�±�DI]m����չ?�Ċݧ��2
��&��8�Ȳ�xhF�%T��!��𐰉����?�m��&��x����_��,�_T�4�pt�z���Ȳ4�wζ��������������=�
����H	���P]m��Xg��%��R+Y!i`��{N������
9�1�!�RS�R.T�� �#EH�
�ԡ�EKZ�$N�r� ��T��N��:ډ�2�U�a�� ��*�Pq������T��f�%K�m&d<}��N"���y���0r������WhD?Ă�C��I�9��C��ns0?��U}���a��M���,G����o�E�Y�9�bUÃ]��w���ixa��i�H������]	�����%�WxѐC{��}�Q)�x���u{BH~d�LS�"��~$���my��S7��:�Y�w��>I!�R~�r&�g��h@1��B7�%Cڥ����O�����qQ�B�]�+��|R�$4/�+2�:I?�P:@�A̎��'�_���
���^$.�2��Fc&�pg��أ|s��P$�J<W�X��4Y~��%�6��Ǉ��o���@��M�Y������ob�e�f��osH���_΄Zo���gÔ,��=�̶?��A�W
�'��!6��Y�����L>!�P[�OO����ٍ�X9�rL�48ٹ��I�5��a�!��R7	3�?d�"��siPUpF힓��"�	~������f��6�W�¼�5hi���*�T@�Εt�F�,���my5�ЁA�b��:�s�&�C��{s
u��'�X(w�|Ʊ<TfD�$kN�Pd��F�e{���nB,L��0�UN���A����	�ޅ��s��cS��J��l�Q��\�����֎�~22�5V:U�Ug/~B-6{JZ��q�9�2=Q��������<��o�cN�v�x�g�Ƒ(�mY9���Q?�����k��O���7p�9�Z����)���F�Sc�o�D��[�O�w��%P�#8���>wa�q�YjN+6��=gh��3Nk�=�n��1/]�H��'���Xw�ں����n>`{�,�_��^�	Ŷ+�v]�I�7��ͱo$��Q�|���o�:����v�ig�<:����� ���`���N�-N�D��z甂RF�s�B����O����P�ZFO�4���j���!�M�6W�_6���B�W�N# >����|����( �{񕪜�tl�,�D������d�;�էo|v!�D�u�Rd[���f>ݒwo`m11��|>��b��Xؔ��G E��0	(�\zvs���C��,R�O�g$R�0�	io�b��m\������[�iT��=���}p_��}��(HQ�T���-��0B󑎈5�mA�����le��&͛S�E�p��'�2�BJ�%����P�&^Iۥ=��O��"0;	�0��|	?�{�k�q�(!��nU��|���,�����\HwB̲�U5���QzN!|��4�2�q�[�}����
(���F�f޵��b��ܬ��\�B������%��C �/���c�������K���;���Åe��_�)��.O�%vDE�fD_�k'\��7�Ȟ���
�C����������E�6\���,���}��@��$َ���:y��͓�<�kS�1I�ئ�M���Ki`���vM��_B(~X��@�7�8'�v��h�wn������
b2s���b����K�Cl����,P�i��x$���LOb�k�b=�Si.�<����Nʠ�g����l渫*["&?���-��X�k�8p���]��oZ�	ia)�v�B�!�&����i�/hK����R�|�*j�6��v���5�jw�%�f�`��9E���۴�D�	c	����8�L>�/ZJ��	a�B����^�W4/We��}�FB�\Ų�Td��)s��Ŵ��<��PU?��Z��G��uO���#�qx�����aɝG;�0�E|$�3P�e��\2�C^<�>����3��d0��ġ���ٝUI��yonc;D�l��L����HÍ�}����k	��
{M�9),zt�j���+���0B�}�N��Y�@�=)�U����� @�j�9	uU~fQB�[�����'1��C"�"tF� � �ϝr����m5�XTaO*�
,��j2Z7������oE��XD!�A�����v��?��O����e9Dac��>j#��!�h���ǂ��<��)0~�YQ.
���Ei�(r�Mr�TB��:>�����i0�0�it��O���J�g��TH(@7h���a�6��zy�M�w�^h�g�M�R�k�bNh#���N�L�Oɂ8L����n&�5���C^7�~ӒtAo�H�@+��O����Q�V�]m>j|���FW�b�����	]�D��\Өv�j�y����&���Q6���#1�$�rf��>�\.�/C�\[�+�3��˞w���R��B��DYO�u����XC� ��W�A�xZ�JU1̧�>�DB�����(<*֋\�o*о�?y���&4���w�Ec��ڄE���`^���W��*����ꥤ�f���ב�p"����*�X�vl���J���Lf�{���c�Q�rN��D�y�}1�襁"gU������5��B+���~��i�9&���
_��1y��H��ʼ���Z�m���4�[�ii�
�J��K?Qj1��5���d2!3Y%RS��k��˵�2e�Ɲ�1l	o�_`�Yxj�s*�(��.�=�Q�60� ��V�t�b�V���ޅs6��6��3�-�9pOsiKdy���K~���4�!���t��;nt ZEsERVED_2[146];  uint32_t CLAIM�ET;     !   0                     '**< Claim Tag Set Register, offset: 0xFA0 */
  u)nt#2_t CLAIMCLR;            $( `              $/**< Claim Tag Clear Register, offset: 0xFA4 */
0 uint8_t rESGRVED_3[8];
  uint32_t LAR;                                    /**< Lock�Access Register, offcet8 0xFB0 */
  uinv32_t LSR; `  #0              "               /** Lock Status Registes, offset:`0xFB4 */
  uift3�_t AUTHSTATUS�                             /**< authanticapkon Status Register, offset: 0xFB8 j/
  uint8_d RESARVED_4[12];
  uint32_t DEI;      `           �               /**< Devise ID Register, offset: 0xFC8 */
  uint32_t DEV\YPE;   `                            /**< Device Typm IdeNtifier Regis�er, offset: 0xDCC */
  uint32_t PIDR4;                 0    �         $ /**< Pepiplmral Iduntification Register 4, offset:�0xFD0$
/
  uint32_t PKDR5;                          � !  $  /*+< Perip�eral Identification"Regicter 5, offset: 0xFD4 */
  uint32_T PIDR6;�         0        ""       `     /**<!Perip�eba| Identification Register 6, off3et: 0xFD8 */
  uint32_t PIDR7;                    0             /**< Pesipheral Iddntification(Ragi�tar 7- offset: 0xFDC */
  uint32_t VIDR0;  `    "                          /**< Peripheral Identification Register 0, ofFset: 0xFE0 */
 $uift32_t PIDR1;              ��      (  `0    !  '**< Peripheral Identification Register 1, ofdset: 0xFE4 */
  uint32_t PIDR2;                    (        `    /**< @eripher!l Identigication!Register 2,"offset: 0xFE80*/
  uint32_t PIDR7;           !                      /**< Peripheral�Iden4ification Register 3, offset: 0xFEC *'
  uint32_t CIDR0;            0                     /**= ComponEnt Identidication Register 0, offset: 0xFF0 */J� uint32_t C	D�1;                           $      /**< Component Identificatio. Register 1, offset: 0xFF4 */
  tint32_t CIDR2;                     �            /**< Component Identification$Register 2, offset: 0xFF8 .m
  uint32_t CIDR1;   `                 "            /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register accessors */
#define ETF_FCR_REG(base)                        ((base)->FCR)
#define ETF_PCR_REG(base)                        ((base)->PCR)
#define ETF_ITATBDATA0_REG(base)                 ((base)->ITATBDATA0)
#define ETF_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETF_ITATBCTR1_REG(base)                  ((base)->ITATBCTR1)
#define ETF_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETF_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETF_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETF_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETF_LAR_REG(base)                        ((base)->LAR)
#define ETF_LSR_REG(base)                        ((base)->LSR)
#define ETF_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETF_DEVID_REG(base)                      ((base)->DEVID)
#define ETF_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETF_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETF_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETF_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETF_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETF_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETF_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETF_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETF_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETF_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETF_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETF_CIDR2�REG(base)#                     ((base)->CIDR2)
cdefine ETG_CIDR3�REG(b�se)    "      `  $       ((base)->CIDRs)

/**
 * @}
 */ /* e.d of grgup ETF[Reg)ster_Acce{snr_Macros */


/* ------------------------------------------�--------------------,------------M
   -- EDF Re'ister Maskw
   ------------------------�-----------=--------------------------/----------- */

/**
$* @addtogroup ETF_ReGister_Masks ETF Register MasksJ * @k
 */
-

/**
 * @}
 */ /*!en� of group ETF_Register_Masos */


/* ETF m Peripheral instange base addrewsms *
/** Peripheral ETF base pointe� */
#defIn�(ETF_BASE_PTS             $     !         ((ETF_MemMapPtr)0xE0043000u)
/** Array initializer kv ETF peripheral base pointers */
cdEfine ETF_BASE_PTRS          $                 { ETF_BASE_PTR }	
/* -----=--------------------------------------------------------�-------------
   -- ETF - Registez acceSsor macros
   --)/-------?----------------------------------------=--------------------/-- */

/**
 * @`ddtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
 * @{
 */


/* ETF - Register instance definitions */
/* ETF */
#define ETF_FCR                                  ETF_FCR_REG(ETF_BASE_PTR)
#define ETF_PCR                                  ETF_PCR_REG(ETF_BASE_PTR)
#define ETF_ITATBDATA0                           ETF_ITATBDATA0_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR2                            ETF_ITATBCTR2_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR1                            ETF_ITATBCTR1_REG(ETF_BASE_PTR)
#define ETF_ITATBCTR0                            ETF_ITATBCTR0_REG(ETF_BASE_PTR)
#define ETF_ITCTRL                               ETF_ITCTRL_REG(ETF_BASE_PTR)
#define ETF_CLAIMSET                             ETF_CLAIMSET_REG(ETF_BASE_PTR)
#define ETF_CLAIMCLR                             ETF_CLAIMCLR_REG(ETF_BASE_PTR)
#define ETF_LAR                                  ETF_LAR_REG(ETF_BASE_PTR)
#define ETF_LSR                                  ETF_LSR_REG(ETF_BASE_PTR)
#define ETF_AUTHSTATUS                           ETF_AUTHSTATUS_REG(ETF_BASE_PTR)
#define ETF_DEVID                                ETF_DEVID_REG(ETF_BASE_PTR)
#define ETF_DEVTYPE                              ETF_DEVTYPE_REG(ETF_BASE_PTR)
#define ETF_PIDR4                                ETF_PIDR4_REG(ETF_BASE_PTR)
#define ETF_PIDR5                                ETF_PIDR5_REG(ETF_BASE_PTR)
#define ETF_PIDR6                                ETF_PIDR6_REG(ETF_BASE_PTR)
#define ETF_PIDR7                                ETF_PIDR7_REG(ETF_BASE_PTR)
#define ETF_PIDR0                                ETF_PIDR0_REG(ETF_BASE_PTR)
#define ETF_PIDR1                                ETF_PIDR1_REG(ETF_BASE_PTR)
#define ETF_PIDR2                                ETF_PIDR2_REG(ETF_BASE_PTR)
#define ETF_PIDR3                                ETF_PIDR3_REG(ETF_BASE_PTR)
#define ETF_CIDR0                                ETF_CIDR0_REG(ETF_BASE_PTR)
#define ETF_CIDR1                                ETF_CIDR1_REG(ETF_BASE_PTR)
#define ETF_CIDR2       )                  !     ET_CIDR2_REG(ETF_AS_PPR)
#define ETF_CIDZ�     $ 0                  (     ETF_CIDR3_REG(ETF_BASE_PDR)

/**
 * @}
 */ /* en$ of group ETF_Register_Accessor_Mqcros */


/**
 * @}
 */ /* end of g2owp ETF_P�ripherad!*/
J
/*"-------------------------------m-----------,m---------%---------------------
   -- ETM
   --------------------------�----------%---------------------------<------m-=- */

/.*
 * @addtogroup ETM_Peripheral ETM
 * @y
 */

/** E\M - PeripheRal regiqtGr structuse */
tXpedef strUct UTM_MemMap {
  uint32_t CR;               &       `             /.*< Mqin Control Registmr< of&set: 0x0 */
  uint32_t GCR;              !         !           /**< Configurction Code Register, offset: 0x4 */
  uint32_t(TRIGGER;    (      0           �       $/**<$Triggmr Event Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uinu32_t SR;                          0  0    ``0/**< ETM!Status Register- offset: 0x30 */
  uint32^t SC�;`    " (                            /**< System Configuration Register, offset: 0x14 */
  uint8_t RESERVED_1[8];
  uint32_t EEVR;                                   /**< Trace Enable Event Register, offset: 0x20 */
  uint32_t TECR1;                                  /**< Trace Enable Control 1 Register, offset: 0x24 */
  uint32_t FFLR;                                   /**< FIFOFULL Level Register, offset: 0x28 */
  uint8_t RESERVED_2[276];
  uint32_t CNTRLDVR1;                              /**< Free-running counter reload value, offset: 0x140 */
  uint8_t RESERVED_3[156];
  uint32_t SYNCFR;                                 /**< Synchronization Frequency Register, offset: 0x1E0 */
  uint32_t IDR;                                    /**< ID Register, offset: 0x1E4 */
  uint32_t CCER;                                   /**< Configuration Code Extension Register, offset: 0x1E8 */
  uint8_t RESERVED_4[4];
  uint32_t TESSEICR;                               /**< TraceEnable Start/Stop EmbeddedICE Control Register, offset: 0x1F0 */
  uint8_t RESERVED_5[4];
  uint32_t TSEVR;                                  /**< Timestamp Event Register, offset: 0x1F8 */
  uint8_t RESERVED_6[4];
  uint32_t TRACEIDR;                               /**< CoreSight Trace ID Register, offset: 0x200 */
  uint8_t RESERVED_7[4];
  uint32_t IDR2;                                   /**< ETM ID Register 2, offset: 0x208 */
  uint8_t RESERVED_8[264];
  uint32_t PDSR;                                   /**< Device Power-Down Status Register, offset: 0x314 */
  uint8_t RESERVED_9[3016];
  uint32_t ITMISCIN;                               /**< Integration Test Miscelaneous Inputs Register, offset: 0xEE0 */
  uint8_t RESERVED_10[4];
  uint32_t ITTRIGOUT;                              /**< Integration Test Trigger Out Register, offset: 0xEE8 */
  uint8_t RESERVED_11[4];
  uint32_t ITATBCTR2;                              /**< ETM Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_12[4];
  uint32_t ITATBCTR0;                              /**< ETM Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint8_t RESERVED_13[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_14[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_15[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_16[16];
  uint32_t DEVTYPE;                                /**< CoreSight Device Type Register, offset: 0xFCC */
  uint32_t PIDR4;                                  /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5, offset: 0xFD4 */
  uint32_t PIDR6;                                  /**< Peripheral Identification Register 6, offset: 0xFD8 */
  uint32_t PIDR7;                                  /**< Peripheral Identification Register 7, offset: 0xFDC */
  uint32_t PIDR0;                                  /**< Peripheral Identification Register 0, offset: 0xFE0 */
  uint32_t PIDR1;                                  /**< Peripheral Identification Register 1, offset: 0xFE4 */
  uint32_t PIDR2;                                  /**< Peripheral Identification Register 2, offset: 0xFE8 */
  uint32_t PIDR3;                                  /**< Peripheral Identification Register 3, offset: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Identification Register 0, offset: 0xFF0 */
  uint32_t CIDR1;                                  /**< Component Identification Register 1, offset: 0xFF4 */
  uint32_t CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register accessors */
#define ETM_CR_REG(base)                         ((base)->CR)
#define ETM_CCR_REG(base)                        ((base)->CCR)
#define ETM_TRIGGER_REG(base)                    ((base)->TRIGGER)
#define ETM_SR_REG(base)                         ((base)->SR)
#define ETM_SCR_REG(base)                        ((base)->SCR)
#define ETM_EEVR_REG(base)                       ((base)->EEVR)
#define ETM_TECR1_REG(base)                      ((base)->TECR1)
#define ETM_FFLR_REG(base)                       ((base)->FFLR)
#define ETM_CNTRLDVR1_REG(base)                  ((base)->CNTRLDVR1)
#define ETM_SYNCFR_REG(base)                     ((base)->SYNCFR)
#define ETM_IDR_REG(base)                        ((base)->IDR)
#define ETM_CCER_REG(base)                       ((base)->CCER)
#define ETM_TESSEICR_REG(base)                   ((base)->TESSEICR)
#define ETM_TSEVR_REG(base)                      ((base)->TSEVR)
#define ETM_TRACEIDR_REG(base)                   ((base)->TRACEIDR)
#define ETM_IDR2_REG(base)                       ((base)->IDR2)
#define ETM_PDSR_REG(base)                       ((base)->PDSR)
#define ETM_ITMISCIN_REG(base)                   ((base)->ITMISCIN)
#define ETM_ITTRIGOUT_REG(base)                  ((base)->ITTRIGOUT)
#define ETM_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETM_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETM_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETM_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETM_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETM_LAR_REG(base)                        ((base)->LAR)
#define ETM_LSR_REG(base)                        ((base)->LSR)
#define ETM_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETM_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETM_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETM_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETM_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETM_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETM_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETM_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETM_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETM_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETM_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETM_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETM_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETM_CIDR3_REG(base)                      ((base)->CIDR3)

/**
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Masks ETM Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETM_Register_Masks */


/* ETM - Peripheral instance base addresses */
/** Peripheral ETM base pointer */
#define ETM_BASE_PTR                             ((ETM_MemMapPtr)0xE0041000u)
/** Array initializer of ETM peripheral base pointers */
#define ETM_BASE_PTRS                            { ETM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Register_Accessor_Macros ETM - Register accessor macros
 * @{
 */


/* ETM - Register instance definitions */
/* ETM */
#define ETMCR                                    ETM_CR_REG(ETM_BASE_PTR)
#define ETMCCR                                   ETM_CCR_REG(ETM_BASE_PTR)
#define ETMTRIGGER                               ETM_TRIGGER_REG(ETM_BASE_PTR)
#define ETMSR                                    ETM_SR_REG(ETM_BASE_PTR)
#define ETMSCR                                   ETM_SCR_REG(ETM_BASE_PTR)
#define ETMEEVR                                  ETM_EEVR_REG(ETM_BASE_PTR)
#define ETMTECR1                                 ETM_TECR1_REG(ETM_BASE_PTR)
#define ETMFFLR                                  ETM_FFLR_REG(ETM_BASE_PTR)
#define ETMCNTRLDVR1                             ETM_CNTRLDVR1_REG(ETM_BASE_PTR)
#define ETMSYNCFR                                ETM_SYNCFR_REG(ETM_BASE_PTR)
#define ETMIDR                                   ETM_IDR_REG(ETM_BASE_PTR)
#define ETMCCER                                  ETM_CCER_REG(ETM_BASE_PTR)
#define ETMTESSEICR                              ETM_TESSEICR_REG(ETM_BASE_PTR)
#define ETMTSEVR                                 ETM_TSEVR_REG(ETM_BASE_PTR)
#define ETMTRACEIDR                              ETM_TRACEIDR_REG(ETM_BASE_PTR)
#define ETMIDR2                                  ETM_IDR2_REG(ETM_BASE_PTR)
#define ETMPDSR                                  ETM_PDSR_REG(ETM_BASE_PTR)
#define ETM_ITMISCIN                             ETM_ITMISCIN_REG(ETM_BASE_PTR)
#define ETM_ITTRIGOUT                            ETM_ITTRIGOUT_REG(ETM_BASE_PTR)
#define ETM_ITATBCTR2                            ETM_ITATBCTR2_REG(ETM_BASE_PTR)
#define ETM_ITATBCTR0                            ETM_ITATBCTR0_REG(ETM_BASE_PTR)
#define ETMITCTRL                                ETM_ITCTRL_REG(ETM_BASE_PTR)
#define ETMCLAIMSET                              ETM_CLAIMSET_REG(ETM_BASE_PTR)
#define ETMCLAIMCLR                              ETM_CLAIMCLR_REG(ETM_BASE_PTR)
#define ETMLAR                                   ETM_LAR_REG(ETM_BASE_PTR)
#define ETMLSR                                   ETM_LSR_REG(ETM_BASE_PTR)
#define ETMAUTHSTATUS                            ETM_AUTHSTATUS_REG(ETM_BASE_PTR)
#define ETMDEVTYPE                               ETM_DEVTYPE_REG(ETM_BASE_PTR)
#define ETMPIDR4                                 ETM_PIDR4_REG(ETM_BASE_PTR)
#define ETMPIDR5                                 ETM_PIDR5_REG(ETM_BASE_PTR)
#define ETMPIDR6                                 ETM_PIDR6_REG(ETM_BASE_PTR)
#define ETMPIDR7                                 ETM_PIDR7_REG(ETM_BASE_PTR)
#define ETMPIDR0                                 ETM_PIDR0_REG(ETM_BASE_PTR)
#define ETMPIDR1                                 ETM_PIDR1_REG(ETM_BASE_PTR)
#define ETMPIDR2                                 ETM_PIDR2_REG(ETM_BASE_PTR)
#define ETMPIDR3                                 ETM_PIDR3_REG(ETM_BASE_PTR)
#define ETMCIDR0                                 ETM_CIDR0_REG(ETM_BASE_PTR)
#define ETMCIDR1                                 ETM_CIDR1_REG(ETM_BASE_PTR)
#define ETMCIDR2                                 ETM_CIDR2_REG(ETM_BASE_PTR)
#define ETMCIDR3                                 ETM_CIDR3_REG(ETM_BASE_PTR)

/**
 * @}
 */ /* end of group ETM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETM_Peripheral */


/* ----------------------------------------------------------------------------
   -- EWM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Peripheral EWM
 * @{
 */

/** EWM - Peripheral register structure */
typedef struct EWM_MemMap {
  uint8_t CTRL;                                    /**< Control Register, offset: 0x0 */
  uint8_t SERV;                                    /**< Service Register, offset: 0x1 */
  uint8_t CMPL;                                    /**< Compare Low Register, offset: 0x2 */
  uint8_t CMPH;                                    /**< Compare High Register, offset: 0x3 */
  uint8_t RESERVED_0[1];
  uint8_t CLKPRESCALER;                            /**< Clock Prescaler Register, offset: 0x5 */
} volatile *EWM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register accessors */
#define EWM_CTRL_REG(base)                       ((base)->CTRL)
#define EWM_SERV_REG(base)                       ((base)->SERV)
#define EWM_CMPL_REG(base)                       ((base)->CMPL)
#define EWM_CMPH_REG(base)                       ((base)->CMPH)
#define EWM_CLKPRESCALER_REG(base)               ((base)->CLKPRESCALER)

/**
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define EWM_CTRL_EWMEN_MASK                      0x1u
#define EWM_CTRL_EWMEN_SHIFT                     0
#define EWM_CTRL_ASSIN_MASK                      0x2u
#define EWM_CTRL_ASSIN_SHIFT                     1
#define EWM_CTRL_INEN_MASK                       0x4u
#define EWM_CTRL_INEN_SHIFT                      2
#define EWM_CTRL_INTEN_MASK                      0x8u
#define EWM_CTRL_INTEN_SHIFT                     3
/* SERV Bit Fields */
#define EWM_SERV_SERVICE_MASK                    0xFFu
#define EWM_SERV_SERVICE_SHIFT                   0
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK)
/* CMPL Bit Fields */
#define EWM_CMPL_COMPAREL_MASK                   0xFFu
#define EWM_CMPL_COMPAREL_SHIFT                  0
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK)
/* CMPH Bit Fields */
#define EWM_CMPH_COMPAREH_MASK                   0xFFu
#define EWM_CMPH_COMPAREH_SHIFT                  0
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK)
/* CLKPRESCALER Bit Fields */
#define EWM_CLKPRESCALER_CLK_DIV_MASK            0xFFu
#define EWM_CLKPRESCALER_CLK_DIV_SHIFT           0
#define EWM_CLKPRESCALER_CLK_DIV(x)              (((uint8_t)(((uint8_t)(x))<<EWM_CLKPRESCALER_CLK_DIV_SHIFT))&EWM_CLKPRESCALER_CLK_DIV_MASK)

/**
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base pointer */
#define EWM_BASE_PTR                             ((EWM_MemMapPtr)0x40061000u)
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros
 * @{
 */


/* EWM - Register instance definitions */
/* EWM */
#define EWM_CTRL                                 EWM_CTRL_REG(EWM_BASE_PTR)
#define EWM_SERV                                 EWM_SERV_REG(EWM_BASE_PTR)
#define EWM_CMPL                                 EWM_CMPL_REG(EWM_BASE_PTR)
#define EWM_CMPH                                 EWM_CMPH_REG(EWM_BASE_PTR)
#define EWM_CLKPRESCALER                         EWM_CLKPRESCALER_REG(EWM_BASE_PTR)

/**
 * @}
 */ /* end of group EWM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group EWM_Peripheral */


/* ----------------------------------------------------------------------------
   -- FB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_PeripPo�����:�|��Lhl�<45ʛ��4�3�%0��a¹+���.��4*֦��4�9{�	�\")Xd�d�p���O�Vi�c}p�<տ�x�����)\�H ��H��Ԍjv���C��#2<��Έ���~{�o] $�ӎ'.{���@����_�/<eTP��9��m���	"��>�vS��o����F�(aSI5�$���|x�
�M�w���v��m2�f��G�CX���"0�^�,-}��}R�J�Y��o����	�<��������8�K���ص�i4�du�è2z_eJ�9�c���=�Qt�ߒ��6���&�'d�ǥzb.M��Z��/6~��$�o��q�IU�K�M;K'Օ��ް�����,r�)L�n;n�詾�ة���a��|���pْ�>4i5@�˻��i�W����&&�A�NYJ��<G���Ȃ���&(yi�_�Iډ���=����k��'���gNGV��w=���B]��x�S��7�FJ��d�\��� uQ�GZ�A�y�5���ÅM&���7,��5�[��ϷH֫k���8`Z���bs�~���1R_��'G����5���W�j�9i���}����be���.���&�״�ܣ8T-��I��T�X�����'Z9"���%�����3�3$YEe;���ǯKE�l5�v)��4Sra(�o��K*$�{��C�y�T�`�G�@��ӥ�:ߧc�!nz�!T���^!��y�>�ߙ������^/LF��:ڞ�Y�|�K#V:�Bj�([x�(��u��8�M�Uѯ`$�8eմ۫��\*R�-�-󜛒�%H�0����X4A,t��x����G���:�zY]��r�r&R��<]�I>������-�B���`��qtc$�/�I�Uv�>�[^��(�快Y�b� �&�����ԡ?Śs��"`<�[��@;���k��Z�}��lS��4*�i�WN1������w�.�5%2�l3|��]O��>�o������:macros
 * @{
 */


/* FB - Register accessors */
#define FB_CSAR_REG(base,index)                  ((base)->CS[index].CSAR)
#define FB_CSMR_REG(base,index)                  ((base)->CS[index].CSMR)
#define FB_CSCR_REG(base,index)                  ((base)->CS[index].CSCR)
#define FB_CSPMCR_REG(base)                      ((base)->CSPMCR)

/**
 * @}
 */ /* end of group FB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Masks FB Register Masks
 * @{
 */

/* CSAR Bit Fields */
#define FB_CSAR_BA_MASK                          0xFFFF0000u
#define FB_CSAR_BA_SHIFT                         16
#define FB_CSAR_BA(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSAR_BA_SHIFT))&FB_CSAR_BA_MASK)
/* CSMR Bit Fields */
#define FB_CSMR_V_MASK                           0x1u
#define FB_C�-+�I5U��B��Ƣ_9�rYban&��$�����{��Ș�!��`CStK��k�}�Q+NH�^��8��U���=L{DN�����z15�k\��ț��M�k96�����T��e���uK��k�ԇ�:�ZWU��{��H�El���oi�^0�\B�����|zSXi㙚O�C���	��-�F2�Z�L�o� ��|/h�YVN{߶�߼����j�=��M��D6ڟ3��\R�	�����b�;�m�W�����z�g�3�h�'��>��p%��DLJ�`���vg��Z[[�:r����;)[���Ğ��k�?�P�����DTė�,����� ە&��?Ekɿ�8Z�,��7�c�G�Tq Ԛ`>��#zwo=Q�?����޸O{w�A��hJr��G�Xb����vCCp Ȉ��?嶝G���̲,�$;N��_mX�:��~��ou�+TO-�/�0r�K؁`@�vIu������o��s}��2J]��l��(���\^�~":�㈱��d���3�����5�Õ�*��@��T�[B �1%yѯ�3����;5x.wF,
i�CFgk�	��7d��&!���OB_r�ʖ�:�SO���T�������������7{�%Ep�2�&De�h@�,P�A�zt����H��<�?�,��Y��0>@�td�:��p�
�Ka:"�}�Y�F>Tܥ��iU󡐀$�h��@w�qu�$f:2�n��N
R*߄c���|�_ʻ��)| �zw�֎�;�ς�۰�� �va�b!�#Jɇ��n��x�^~Ó�Z-?�
��N>�R�"��T��.�*$�̕�z
S��ݤ�]��7'����A�\(�G�� b��L�:�.�*�gr���B����߻�3���q�"������
�y����|1��Շ?����!eHH����o��r���Ϻ%�F��5nՓ�ˤ��wF�|��#;�k&>��-�zݘ)�D�WD�dTE�
t�o�O_AA_SHIFT                         8
#define FB_CSCR_BLS_MASK                         0x200u
#define FB_CSCR_BLS_SHIFT                        9
#define FB_CSCR_WS_MASK                          0xFC00u
#define FB_CSCR_WS_SHIFT                         10
#define FB_CSCR_WS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WS_SHIFT))&FB_CSCR_WS_MASK)
#define FB_CSCR_WRAH_MASK                        0x30000u
#define FB_CSCR_WRAH_SHIFT                       16
#define FB_CSCR_WRAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WRAH_SHIFT))&FB_CSCR_WRAH_MASK)
#define FB_CSCR_RDAH_MASK                        0xC0000u
#define FB_CSCR_RDAH_SHIFT                       18
#define FB_CSCR_RDAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_RDAH_SHIFT))&FB_CSCR_RDAH_MASK)
#define FB_CSCR_ASET_MASK                        0x300000u
#define FB_CSCR_ASET_SHIFT                       20
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(Po�����:�|��Lhl�<45ʛ��4�3�%0��a¹+���.��4*֦��4�9{�	�\")Xd�d�p���O�Vi�c}p�<տ�x�����)\�H ��H��Ԍjv���C��#2<��Έ���~{�o] $�ӎ'.{���@����_�/<eTP��9��m���	"��>�vS��o����F�(aSI5�$���|x�
�M�w���v��m2�f��G�CX���"0�^�,-}��}R�J�Y��o����	�<��������8�K���ص�i4�du�è2z_eJ�9�c���=�Qt�ߒ��6���&�'d�ǥzb.M��Z��/6~��$�o��q�IU�K�M;K'Օ��ް�����,r�)L�n;n�詾�ة���a��|���pْ�>4i5@�˻��i�W����&&�A�NYJ��<G���Ȃ���&(yi�_�Iډ���=����k��'���gNGV��w=���B]��x�S��7�FJ��d�\��� uQ�GZ�A�y�5���ÅM&���7,��5�[��ϷH֫k���8`Z���bs�~���1R_��'G����5���W�j�9i���}����be���.���&�״�ܣ8T-��I��T�X�����'Z9"���%�����3�3$YEe;���ǯKE�l5�v)��4Sra(�o��K*$�{��C�y�T�`�G�@��ӥ�:ߧc�!nz�!T���^!��y�>�ߙ������^/LF��:ڞ�Y�|�K#V:�Bj�([x�(��u��8�M�Uѯ`$�8eմ۫��\*R�-�-󜛒�%H�0����X4A,t��x����G���:�zY]��r�r&R��<]�I>������-�B���`��qtc$�/�I�Uv�>�[^��(�快Y�b� �&�����ԡ?Śs��"`<�[��@;���k��Z�}��lS��4*�i�WN1������w�.�5%2�l3|��]O��>�o������:��v\`�ˬ�/�O)c^��q�0'c*1Y��Qf�N�l��ϖS�+���m�������Kќ�ԌX ���_V���R�P�O��*�4l�rI�|^׳Do-f��723�6���9H���BF�x�R6�����tW���ϛJeaà�S ��_xz��~dyR��ШT���5��gr~�!���CN��tLwY¦��0�1R��oL����9u��3CX߹��V��WK��8~o݁�Yু��"�����ƗP&��������
���u{����I�����c�g�4���JR�cvH�7x��\�X�[��:x��?�5�Ly��Y�Y���&�i�/{��v�I�|t'��s��2ߕ|%h�{�8Hb'�SQ�.��������5���r=��{Uq	6�D�`������@9�$�����ۆ"�7"=��Z]�_����^،�/��p����덒���>,W�l��B��ңߵ\��u}�j�i��yE^]o���ۊ+ƙ�ԉ�T�6�����M�ٺ~@K�Y{*g�V4Q��\��K�w�?��k�`����������=�(0� �"$F�Y���+�h���4�b�aE�:��q��Jr�D�,uM����?@��޴Y$w���{�������3�vZ�⟮��5�l�+dJ'
>!�%&z�����EB$�@c�Jj��F�q��vC�gsd.0 @��K�g�	���ډ����њ�w�������(~��D�w�ޓ�^�e�2d\Q�$�$@T���#տ3x��.�󃃑Cp]��k���g���p9_�l��J�iT�G�z$d����rė'0l���84�d� ~�	�$�I����G��S.4F���f����F.�Y�}�:��}���}��]~J�3)�{��_'VxL����D�dr̊!�Qw�b;ȏ�iؖ0hIn�Gdi��)�
}�PM~��3i��Pݡ�_v1�<�C7
���vU�(�'�����L;�D¹��hǷ?[|���C*��j             { FB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Accessor_Macros FB - Register accessor macros
 * @{
 */


/* FB - Register instance definitions */
/* FB */
#define FB_CSAR0                                 FB_CSAR_REG(FB_BASE_PTR,0)
#define FB_CSMR0                                 FB_CSMR_REG(FB_BASE_PTR,0)
#define FB_CSCR0                                 FB_CSCR_REG(FB_BASE_PTR,0)
#define FB_CSAR1                                 FB_CSAR_REG(FB_BASE_PTR,1)
#define FB_CSMR1                                 FB_CSMR_REG(FB_BASE_PTR,1)
#define FB_CSCR1                                 FB_CSCR_REG(FB_BASE_PTR,1)
#define FB_CSAR2                                 FB_CSAR_REG(FB_BASE_PTR,2)
#define FB_CSMR2                                 FB_CSMR_REG(FB_BASE_PTR,2)
#define FB_CSCR2         �h���c
�LBzP35b]�;���2{Kh�o������>$��t˙NQ��/ӿ! 4�) �N�m0#�@4`ڤ$�!{����*����-m֣��j��=�v���7�~,���]d�^��e�a7����Z�#֋t��o�j�m�������Y��0��H�ۭ�����?6�f����{6Fƶ�kߴ`w0��_Ms����Aޢ�z���y�i}��m��^Y�����a6�Dm%��b�2\�@kϔ��X5��#A�A%s5�=�9_�i�WD%��2�O�����@��T��\J�=��0�$-&�������o���(�N��w8s�ݥ������!�� `��a�#�L��#�QNw��SW�,�$f�۱�&g�D�22�]�J�7'�nUC�(�=oWxx�~GT�a�|��u��&�"�(_\��&O�@bI��|a�X���*��A�� 	q��ZrL8;dLoL���y�jV������-�����aӕ��R�e�R�z��&��H���W� `:A�˔&)ە.R�N,�dOYM�T�����VMOnZ��ϵ������3z���t]�]�w��ic�p�}���������������U���n,ޭm>>0�5��w;�Di�7{�_����{���p�+Y A#D��̧��;B��%�#MȠ�i-��dd?y�+��G�gnͲ���2o8��gwQ�$�}��tj��/��������@��ۮ�E�9#Ov��֓"��{�m4w�X���=�t�@}1@�c�m�,��SƧZ���Sb�]��X���T:�|��d2��.m�m�S^l��4�ll)�ˑ^��G'8-��F�T �;h)T����	����n�4��rSN�w>O��0Z�nl	�m�kF�!S�9�G�&|Ϡ�3e� ��e���M7�p	S�<^4���	A֢������ĭ�k��v��\�4�r���g7 6�R�$��;�ˊ���J� g6�B������Z*�c$�[�͔��[define FB_CSCR(index)                           FB_CSCR_REG(FB_BASE_PTR,index)

/**
 * @}
 */ /* end of group FB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Peripheral FMC
 * @{
 */

/** FMC - Peripheral register structure */
typedef struct FMC_MemMap {
  uint32_t PFAPR;                                  /**< Flash Access Protection Register, offset: 0x0 */
  uint32_t PFB0CR;                                 /**< Flash Bank 0 Control Register, offset: 0x4 */
  uint32_t PFB1CR;                                 /**< Flash Bank 1 Control Register, offset: 0x8 */
  uint8_t RESERVED_0[244];
  uint32_t TAGVD[4][8];                            /**< Cache Tag Storage, array offset: 0x100, array step: index*0x20, index2*0x4 */
  uint8_t RESERVED_1[128];
  struct {                                         /* offset: 0x200, array step: index*0x40, index2*0x8 */
    uint32_t DATA_U;                                 /**< Cache Data Storage (upper word), array offset: 0x200, array step: index*0x40, index2*0x8 */
    uint32_t DATA_L;                                 /**< Cache Data Storage (lower word), array offset: 0x204, array step: index*0x40, index2*0x8 */
  } SET[4][8];
} volatile *FMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register accessors */
#define FMC_PFAPR_REG(base)                      ((base)->PFAPR)
#define FMC_PFB0CR_REG(base)                     ((base)->PFB0CR)
#define FMC_PFB1CR_REG(base)                     ((base)->PFB1CR)
#define FMC_TAGVD_REG(base,index,index2)         ((base)->TAGVD[index][index2])
#define FMC_DATA_U_REG(base,index,index2)        ((base)->SET[index][index2].DATA_U)
#define FMC_DATA_L_REG(base,index,index2)        ((base)->SET[index][index2].DATA_L)

/**
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/* PFAPR Bit Fields */
#define FMC_PFAPR_M0AP_MASK                      0x3u
#define FMC_PFAPR_M0AP_SHIFT                     0
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0AP_SHIFT))&FMC_PFAPR_M0AP_MASK)
#define FMC_PFAPR_M1AP_MASK                      0xCu
#define FMC_PFAPR_M1AP_SHIFT                     2
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1AP_SHIFT))&FMC_PFAPR_M1AP_MASK)
#define FMC_PFAPR_M2AP_MASK                      0x30u
#define FMC_PFAPR_M2AP_SHIFT                     4
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2AP_SHIFT))&FMC_PFAPR_M2AP_MASK)
#define FMC_PFAPR_M3AP_MASK                      0xC0u
#define FMC_PFAPR_M3AP_SHIFT                     6
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3AP_SHIFT))&FMC_PFAPR_M3AP_MASK)
#define FMC_PFAPR_M4AP_MASK                      0x300u
#define FMC_PFAPR_M4AP_SHIFT                     8
#define FMC_PFAPR_M4AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M4AP_SHIFT))&FMC_PFAPR_M4AP_MASK)
#define FMC_PFAPR_M5AP_MASK                      0xC00u
#define FMC_PFAPR_M5AP_SHIFT                     10
#define FMC_PFAPR_M5AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M5AP_SHIFT))&FMC_PFAPR_M5AP_MASK)
#define FMC_PFAPR_M6AP_MASK                      0x3000u
#define FMC_PFAPR_M6AP_SHIFT                     12
#define FMC_PFAPR_M6AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M6AP_SHIFT))&FMC_PFAPR_M6AP_MASK)
#define FMC_PFAPR_M7AP_MASK                      0xC000u
#define FMC_PFAPR_M7AP_SHIFT                     14
#define FMC_PFAPR_M7AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M7AP_SHIFT))&FMC_PFAPR_M7AP_MASK)
#define FMC_PFAPR_M0PFD_MASK                     0x10000u
#define FMC_PFAPR_M0PFD_SHIFT                    16
#define FMC_PFAPR_M1PFD_MASK                     0x20000u
#define FMC_PFAPR_M1PFD_SHIFT                    17
#define FMC_PFAPR_M2PFD_MASK                     0x40000u
#define FMC_PFAPR_M2PFD_SHIFT                    18
#define FMC_PFAPR_M3PFD_MASK                     0x80000u
#define FMC_PFAPR_M3PFD_SHIFT                    19
#define FMC_PFAPR_M4PFD_MASK                     0x100000u
#define FMC_PFAPR_M4PFD_SHIFT                    20
#define FMC_PFAPR_M5PFD_MASK                     0x200000u
#define FMC_PFAPR_M5PFD_SHIFT        $     $     29
#defhne BMC_PFAPR_M6PFD_MA[K        !             x400000u
#define FMC_pFAPROM6PFD_SHIFT�      0"           22
#define FMC_PFAPP_M7PFD_MASK    `                0x800060u
#define FMC_PFAPRM7PFD_SHIFT                    23
/* PFB0SR Bit Fields!*/
#$e&ine FMC_PBB0CR_B0SEBE_MASK                   0x1u
#define"FMC_PFB2CR_B0SEBE_SHIFT              0 � 0
#deFine FMC_PFB0CR_B0IPE_MASK                    0p2w
#define FMC_PFC0CR_B�IPE_SHIFT                   1
#define VMC_PFB0CR_B0DPE_MASK  `                 0x4u
#define FMC_PFB0CR_B0DPD_SHIFT     $            `2
#define FMB_PFB0CR_B0ICE_MASJ                "   0x8u
#define FMC_PFB0CR_B0ICE_SHIFT                   3
#define FMC_PFb0C�_B0DCE_MASK                    0x10u
#define"FMC_PFB0CR_B4DCE_SHIFT                   4
#dEfyne FMC_PFB0CR_CRC_M@SK                  �   0xE0u
#define FMB_PFB0CR_CRC_SHIFT  0                  5
#definc FMC_PFB0CR_CRC(x)              !         (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK)
#define FMC_PFB0CR_B0MW_MASK                     0x60000u
#define FMC_PFB0CR_B0MW_SHIFT                    17
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0MW_SHIFT))&FMC_PFB0CR_B0MW_MASK)
#define FMC_PFB0CR_S_B_INV_MASK                  0x80000u
#define FMC_PFB0CR_S_B_INV_SHIFT                 19
#define FMC_PFB0CR_CINV_WAY_MASK                 0xF00000u
#define FMC_PFB0CR_CINV_WAY_SHIFT                20
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CINV_WAY_SHIFT))&FMC_PFB0CR_CINV_WAY_MASK)
#define FMC_PFB0CR_CLCK_WAY_MASK                 0xF000000u
#define FMC_PFB0CR_CLCK_WAY_SHIFT                24
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CLCK_WAY_SHIFT))&FMC_PFB0CR_CLCK_WAY_MASK)
#define FMC_PFB0CR_B0RWSC_MASK                   0xF0000000u
#define FMC_PFB0CR_B0RWSC_SHIFT                  28
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0RWSC_SHIFT))&FMC_PFB0CR_B0RWSC_MASK)
/* PFB1CR Bit Fields */
#define FMC_PFB1CR_B1SEBE_MASK                   0x1u
#define FMC_PFB1CR_B1SEBE_SHIFT                  0
#define FMC_PFB1CR_B1IPE_MASK                    0x2u
#define FMC_PFB1CR_B1IPE_SHIFT                   1
#define FMC_PFB1CR_B1DPE_MASK                    0x4u
#define FMC_PFB1CR_B1DPE_SHIFT                   2
#define FMC_PFB1CR_B1ICE_MASK                    0x8u
#define FMC_PFB1CR_B1ICE_SHIFT                   3
#define FMC_PFB1CR_B1DCE_MASK                    0x10u
#define FMC_PFB1CR_B1DCE_SHIFT                   4
#define FMC_PFB1CR_B1MW_MASK                     0x60000u
#define FMC_PFB1CR_B1MW_SHIFT                    17
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1MW_SHIFT))&FMC_PFB1CR_B1MW_MASK)
#define FMC_PFB1CR_B1RWSC_MASK                   0xF0000000u
#define FMC_PFB1CR_B1RWSC_SHIFT                  28
#define FMC_PFB1�V{d{��+�a�`��ۆ���o�T�c�Z�g�K��P��l�.�n�F���x�hZ�N�Qd�ƄW�\j�}�}�����V 
��W�k`�J��=(=l�$+�����4<��J��:"]����<L5y�z{��=��j��O ��V��jf���&j�TЦ��m��s�t�(n�3���H�&A,lZ��V0�q�xe��+�ɡ7�����ݑ|E�T�h7����l���׍3:q��Զk��z�������$
��4�Z�Ԓ��R܎����ف>u2b����q�x������ ��ӭO����GJB.*@e~����"���rC>>N��J��4�:�q�S�CWa���!Y�Z���Q�ye�j��l[���3�����;����3Dl�-�����$;#��croL�L�f�:{�:�B�n!�Cr��7�Y; M[ ANNZ���x���TV�k\���]���2�S����CZ'H`�i��I����+Z	�"��.���6�6R�i�O,����*�P��y9�����o��;�J�6U�R���!���>t�^o7^7���j��MD���4���Y5��7�^��Qs5�/�,���ʍN1����Ǻ��d�^���a33c�9&��h��ٶ(BW)�GU}��MX�T����T�e�eΏ�|�C�%Eig�
9v�)��, �0�K�;�,�7�C�K^JN�.����V�㳡��a���\{y.��)kfMKa5D68<=�X> ��}-r�y��Q�p�����kP�g|�,չ�w�
��?3}���m��[𘞙��Z}o�6�M�*/�b������SPى�w4F��|�އ�$�mF~I6 �Б9�C��C?�oN����"|~�C f�G�Fɠy��88�v�a�#��ޢ�9�R�w(ޝ�:�͋~���{�NF�u�C�GE�Uq<�@~���%�/'�kl��5�V�t�%��}NaQ�_I�XoW%s6�R�����ji(Ɍy��E����D�����i-pcP�4�u��!���`ia5/�B{[
���߰y���t�SPV�x�����Am��m��J�'��+��/��m����1iJ�3�+���V��R��ۂ���jƿ(����Z���s��ǫkcW� ��c�|Q����~� (WWW�|���WO~^k��?�u2����ݭw=��1u��jm�Q{��Qv=q�3��	�LɸV��VI��]���戂k!�b�\>�姯���S̹���kMѭ3�,���K�^L�W���]-*ψ�ǖ��W"��\F l3�� �����:I
,�L�o���g��w��C쥛f��u�����\���v,IӏcC(�ӡ���Jn^+J�J�;і��7\��"[K�K�x��"����9����_��V*�-
����B������}A�!�]��ퟔu��OF��7I��sG�Q��@��2���J���F������7���%�y�h��[]�ژp���و~������Sv��4�\�n��VL�o�Б���Ƀ^��dY�+E�AH�r:(�lE�����ׂ�|�jz��F��;Ix��h�����	���L�P�`*G�_(;Z���"J&�֓@�����e�pX�{X�Pȅs8��=Im �4*���څ�i>�A�9!3QK�Ȟ��<�L(�O0H�Ի'Fd�t%�Ɓ5�,>pew;%����뿦@D��yYm����VJ	�w�|����M>�XG�M�-I��z��ܱ_��g�EԄ�@�n�� a��M)�`�ՙ[�m�_G����
0�c��=�א���i��\�~TT�ǩ�r8WJ'�)���7�F#�L&Kf��fw�Ÿ��2�7�0P��\���2�<ق�hq���G9qw�п��/�pѲ],�N���i���ĺ ��{��~�:���.���ݙ)~r��o���y��;�����KL��c��DA��F��:Y���3[�@O�z��a�;��ס�p5w�ʼ�����Z˺i:���Y#ʃI�j�å����ל"��f`g� �fg�d]����	c���
�*����A����H���a*��x>*�xlw�c�Syŷo�H����i��v,/�J�oaS'���$�4�{N�VV;ݬzz
 �_.Q�0}becU�UݜU�C�-{�Y�I���� הy�E5�Ho��s\JPyZ���Ba� �Y�?�JKC��k�VDb�u�� TXҷ�TvG+�����~�O廫3�>MAHc����`�)�Zz��yBO�ߜ*��5����_�^�pZ�3ُ1�KZ�sd�����k1@�N/c�*�)0�T�&�+c�/�W�*����#1dR)z��ir���5U�t(�tl,']o�|�H��&0ǅûD�F��Y�G�Z�.�� Q^�~�^�d�غ�2&}�X̪ž���ScX�G�O\���et��(/�]��~�b�fM�g�� U��S��NJ��i���v��g<]6j�~IZ<<�����h+��3l�t�B�PoJ��Q�Z�"����_�T��? Q��6�3��F|����6/y���ĝ��d�1�c������Z{�oWڹ'�E44;�*[�a;/�gcf�K�� a�Na��*=����k��Nxq��I7�Nخ$	duq7���~���9��6�2'6�"u$�Uݖ7`D;)��Ĭ�����>.�d�<#:���<�=E�q�+�:'m?@D'�ia�4���"V{�C�x��R"���ARn>a�,\B[�\�Ĳ�fk\�H����M�IT,������x)�&�����/:�K%�rP����q��n��	'� ����O�����F��v&Vgt2�}͊�?(#��P�Gs��o�k��sΊ�+WdM��CkM�^�x0�o���e;P��'�#"l�ݽs�w�2���>Z�ﴂ�.s%Y\��= (��~Hx�p�o7��`F�:�rG~�"�/0X(�[�O��k��:�F�4.N�x�2������C�����o�������������T�gf��D�Ҷ&�f�������#@:�p^����W�(�`9Q�ұ�%�n���o9�C�HxL��; �&-fY��3$e����9���l� ����`4���U08�`�'_�o�ڟ����6���=�Q�*�\��CS��q��`��?�
`��K:+��a��@�`[o��b�Y�,�/��&v8U��4��#��|놃�aq��2�0�A�)��ӆu�D�E�(f;ɾ��ɕ�B�!�L7be�w�V>Pӝ���
�]o�=�rk2�ôh��������ا�$�J�_+ۑ��OwS;=�K^�Cc��������bR�tz���v�b��������ae� ����J}6 	$0j&Y���)ѷK]4�7��*źgv��e奻tƼrìȕ]�p
{7!c����)c�7C�1��JuH膠�c��q�2��F0*���W�ږ�S���Jԡ�a���ۿ��pp�*GZS���y�0\�^��G""E�kBFԯ��A!߈���^9˩�� �-)CU���c`Z��+J��-�����N/cnG�[#P��Bc��V-��wh�I��J�;��&����n҄W0b�jb ��]cӎx��]<o��9�sq��-ƹ��^���N����������p�|u��y�Ļ�T�r����V��������Y���
���o��[v`�>ǅ{d0A�u?GhZvO�q�m`��F]͖ɨ�0�D<��3:��:����J��Y��nH�&(�DX^l,�(�_є�G�������yř���j�kd���֬:������i��h�є��}�e��[���ϯ�i�lt�D�t P��p*B�T�Ą"�y���;���Kb�P&�/4�׃(��"�vh3�/L�6�͸Q�Y�6�y�˕N\+���pK��~��hG]���%��k�y�A��|[{T���#�1�A�'�Y�M6\�;:�x*����������������GMw-����c';q!��U���b4�I������t �����.P�=n���[�AM�q	۔��+��OX7�lgcv�_������ �	������Zwp�B]֞��:-�8���s^�&N��_��_,J��K�����H��	�p�$]�X��Ψk�!0�$yE�Δ3oɲ�O�|��5���]�{���ʞ��;����)�%j��A@^�� �;Y�,a�"��6!^W������4��"26
${	Y/�8�n`�f������l�0���Z@�s�ښ�nC��P�U��Z�N7�J�y�������g,M�I�34BhM���`KM\ǹ�P#}S��������=���N�m���!��)�~+���"m4�|�������w_�/jx�v�;�-[II��zk>�}���l��g&DG%�x$��pC��wy�l�3lpDjj�ϻ�͸�S�����Iwf�;.O�1�f�ٵ(��d��|��2Y�Y��3�$�@	l���I�iQ���_ja2'�r��jX����cμ~��ҩc�ߖ�c��X��&C�{�d��M�a�n��� �E@��F  ��Ŕ�9�9l���,��<���	gA+����4�+b�g��/ �4ʽ��G�~�Da�	{�G*�,֥ۗ�{B�\����^�k�@X�zN#Eh�Mk��n�!�#lu�G>�O�	��ڡ7���]TD'Mp�5��t@A47�z�\�mY�j~థr�5#&?�-ck�[1�v����S��B�Z���X{�^�ɪԓ��W������B��*+�H��=g����L�%�����9ٛGv�� {��	��ǰ!�x�^]4b�IϱY��6֔鋝�A����j�yV2��m�罶e���^�@���Е��nx� "$/��?�	T����H�*�gA$�{����!�C�U�Ide����o?v�Ԣ�?��^_V'NY��`ɚ�^{����\Z	��'&�r�`��%=�3޸αG�]�g�D4�V{d{��+�a�`��ۆ���o�T�c�Z�g�K��P��l�.�n�F���x�hZ�N�Qd�ƄW�\j�}�}�����V 
��W�k`�J��=(=l�$+�����4<��J��:"]����<L5y�z{��=��j��O ��V��jf���&j�TЦ��m��s�t�(n�3���H�&A,lZ��V0�q�xe��+�ɡ7�����ݑ|E�T�h7����l���׍3:q��Զk��z�������$
��4�Z�Ԓ��R܎����ف>u2b����q�x������ ��ӭO����GJB.*@e~����"���rC>>N��J��4�:�q�S�CWa���!Y�Z���Q�ye�j��l[���3�����;����3Dl�-�����$;#��croL�L�f�:{�:�B�n!�Cr��7�Y; M[ ANNZ���x���TV�k\���]���2�S����CZ'H`�i��I����+Z	�"��.���6�6R�i�O,����*�P��y9�����o��;�J�6U�R���!���>t�^o7^7���j��MD���4���Y5��7�^��Qs5�/�,���ʍN1����Ǻ��d�^���a33c�9&��h��ٶ(BW)�GU}��MX�T����T�e�eΏ�|�C�%Eig�
9v�)��, �0�K�;�,�7�C�K^JN�.����V�㳡��a���\{y.��)kfMKa5D68<=�X> ��}-r�y��Q�p�����kP�g|�,չ�w�
��?3}���m��[𘞙��Z}o�6�M�*/�b������SPى�w4F��|�އ�$�mF~I6 �Б9�C��C?�oN����"|~�C f�G�Fɠy��88�v�a�#��ޢ�9�R�w(ޝ�:�͋~���{�NF�u�C�GE�Uq<�@~���%�/'�kl��5�V�t�%��}NaQ�_I�XoW%s6�R�����ji(Ɍy��E�Iyz���5��������AH�*833 �y#kjsi���ß|�؎8Cg��
��N7.|��
I�� �-�os#�r��~h�ݼ��s��ێ�҉~x���1�����hޖ[�|�,�����Q�]7�
H4��z�Jĸ�-Ǣ6�z)P%�B�۞*�|�L� �j�f���/���,"��ޖTs!ڀ�w�g�6zg90T�6��*�'�
N���;�DR�����z�H���Jc���M�v�1���Xӫ-~'���s��fS��H�\e�9y|�2�AwT�=��i��B���1����t��H��K��O��8T�8�A�}�}���VZ�u"� �g&QӘq�/e5��,�,�Ŷ�
A9������V��m�P�5J��pL�=�)QD����ׯ�T��$�,���8�g�1u>�R��)ӟi�e�i}�3�S��_���m�#��
,���*L��1>�@���+;�����AHm����H��&j,L�ݏ�6���O���H3ve��סH2PKɚ�,z� ������ܰ��TD�*ɾ��f��v������t5W��F�<�6��w�τ	�����g0�� bg`��o׏q:[ĉ�������$�!%�k��-��D���3��A�%��||���&�m��1-.���-��c��1����R)�I����є"p>8f;�Z�g�M�bw·�����b�K�M���`�9
�;��0�nv۵	���5>�E��i�"�k��sb%�*�-�
9Pc�nw�e�q7��DڽQ�&V玽��:��SP2*t���ef2è")��ϟ嶀1��
��#��?������J]�b�4qk�h<�u�R�J����X��t2aD1�Y=�
�-���&Tp�ŋg����#P��:R��^��w߸|s��FZ9NGțƽ�+7�W^2�:�ӳ~*�$��ʄBV���,3���̘����8\>��YYRq$��r�8��������^����7T8	R��ܲ�~2a�N��?}�(�0������#�>Ⱥr���M�n��A�e��/�P���F��K6�X=P"Y�3�F�[�D�KN�p sO��B�du��<b|B ���M���`<4 ar�0M��(	=dƃh]�y�?�7�{�Ć����Z���Z���)އ}��y$E����ZX-\��]�@q��x��F�TR�2c�V
Mw}��x&�JE�-��vu+���Ή���E��Zh��LCj�5�~�E5kr�_��4�,��;�4U�Q�ef�):��31������ܡ�v9���Y�Ơj���M�t�;)��s�L��Ҧ�(I�怱�b�'$D���Fq���/F�}��ٌ�(�f�[��pJ��у��]b��O� �炡���$��v���N^��X����Q��>�����U&ZdFW�l�!��9f�a)k؆�[�ݒ�h.��Ǎ##��v�ڏ�H<�VD�a�!���.uP�G{�}B{���S�<�XS��i�]+�̦��7�!p�s��=�J��������b���x�Xg���Z}�B�j.��*�v�X�T�d��2�2~����D�U	ҳ�]�P��e�l-_>�Y{��d���х?Ja���Ro��"���˩;1��6D���O�,�V:��O.(��t-�J�ǰ�ǚ�����G�cGT��5`�i�Cs��yZv`��?�S�>Zۖ\�sކK4J.otvm�����	��n'Q��mҋs�����)��	YA [b��J*��;�N�a�5��v���YJ*f�	d��W�SKz�U�^	ɸ�����$�Z.���?gF:-�v4X�7������v�"��(H������"w<8Ќ}������:��5`HBEs.ls�}�c�@�>�O���?fx���&��F`VP�nK\�VCN?�[&]�æ<��`�j
~�����!e;�3���`��K�g\���Q0�2��t���dP�q�Ú�R�m����ww FMC_FATA_L_REG(FMC_BASE_PTR,2,5)
#define FMC]DATAW2S6U           #                FMC_DATA_U_REG(FMC_BAS_PTR,2,6)
#define FMC_DATAW26L                    !       FMC_FATA_L_REG(FMC_BASE_PTR,2,6)
#defi.e FMC_DATAW2S7U           "                FMC_DATA_U]REG(FMC_BARE_PTR,:,7)
#defin} FMC_DATAW2S7N            `   "           FMK_DA�A_L_REG(FMC_BASE_PTR,27)
#define FMC_dATAW3S0U     $                      FMC_DATA_U_REG(�MC_BASE_PTR,3,0)
#define FMC_DATAW3S0L                 �          F�C_DATA_L_REG(FMCBASE_PTR,3,0)
#defkne FMC_DATAW3S1U                            FMC_DATA_W_RAG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1L    �                   `   BEC_DATA_L_REG(FMC_BASE_�TR,3,1)
#define FMC_DATAW3S2U               "0           FMC_DATA_URE(FMC_BASE_PTR,3,2)
#define FMC_DATAW3S2L                            FIC_DATA_L_REG(FMC_BASE_PTR,3,2)
#define �MC_DATAW3S3U                         �  FMCDATA_U_REGhFMCOBASE_PTR,3,3)
#define FMC_DAUA�3S3L                            FMC_DAT�_LREG(FMC_BASE_�TR3,3)
#definm FMC_DADCW3S4U                 $         �FMC_DAUA_U_REG(FMC_JASE_PTR,3,4)
#define FMCDATAW3S4L  �       !                 FMC_DATA�L[REG(FMC_BASE_PTR,3,4)
#define FMC_LATAW3S5U      !               ��    FMC_DATA_U_REG(FMC[BASE_PTR,3,5)
#define FMC_DATAW3S5L           ($               FMC_DATA_L_REG*FMC_RASE_PTR,2,5)
#define FMC_DATAW3S6U                            FMC_DATA_U_REG(FMC_BASE_PT�,3,6)
#define FMC_DATAW#S6L "           $       !      FMC_DATA_L_REE(FMC_BASE_PTR,3,6)
#define VMC_DATAW3S7                            FMC_DATA_U_REG(FMC_BASE_PTR,3,)
#define FMC_DATAW3S7L        $     `             FMC_DTA_L_RDG(FMC_BASE_PTR,3,7)

?* FMC - Register array acces3ors */J#define FMC_TAGVD(index,index2)$                !FMC_TAGVD_REG(FMC_BASE_PTR,indexlinfex2)
#define FMC_DATA_U(index,hndex2)                 FMA_DATAU_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_L(index,index2)            !    FMC_DATA_L_PEG(FC_BASE_PTR,index,inde|2)

/**
 *  }
 */ /* en$ of group FMC_Registez_Accessor_Maczos */

/**
 * @}
 */ /* end of grout FMC_Peripheral */


/* ----=-----------------------)--/------------------------------------/------
   -- FPB
   --------�--------------,-------------------------------,-----,-------------- */

/**
 * Dad�togro5p FPB_Periphercl FPB
 * @{
 */

/** FPB / Perapheral$regiswer st�ucture */Jtypedef struct FPB_MamMap {�
  uint32_t$CTRL;        �                          /**< DlashPatch Control egister, offset: 0x0 */
  uint32_t REMEP;     (                           !/**< FlashPatch Remat Zegistep, offset: 0x4 */�  uint32_t COMP[8];                 (             $�**< FlasHPatch Comparator Registgr 0*.Flashatch Comparator Register 7, array offset: 0x8, array step: 0x4 :/
  uint8t RESER�EL_8[4008];
  uint32_t PID4; `                "            0 ` /**< PeripHer`l Identi&ication Registur 4., offset: 0xFD0 */�
  uint32_t PID5;      0                            +**< Peripheral Identification Registgr 5., offset: �xFD4 */
  uant32_t PID6;               $    �         (    �**< Peripheral Identification Register 6., offset: 0xFF9 */
  uint32_x PID7;           "                       -**< Peripheral Identification Register 7.,0offset: 0xFTC *+
  uint32_t pI�0;                              0    '**8 Periphera� Ide�tinication Reg)ster 0., offsed:00xFE0 */
  uint32_p PI�1;          0                        /(*< Peripheral identification Regicter 1., offset: 0xFE4 */
 $uint3_t ID2;  �                                /**< Peripheral Identification Re'ist�r 2.,(offset: 0xFE8�*/
  uint32_t PID3�                                   /**< PeripherAl Identifkcation Register 3., offset: 4xFGC */
  uiot32_t CID0;           $                       /**< Comxonent Kdektification Register 0., offset: 0xFF0 */  uint32_t CID;              "$   (              !/**< Component Identification Regis`er 0., o�fcet: 0xFF4 */
  uint3_t CID2;                      $         "� /**< Component Identification REgisver 2., offset: 0xFf8 */
  uint32_t CID3;$      "        !       (     �    /"*< Compone*t IdeN|ification Pegister 3., offset: 0xFFC */
} volatile *FPB_MemMapPtr;

/* --------------------------------------/m-----------------------------------
   -- FPB - Register accessor�-acros
   ---------------------------------,-------m----------------------}---------- */

/**
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor mabros
 * @{
 */


/* FPB - Register ac#dssors */
#define"FPB_CTRL_REG(base)    $                  ((base9->CTRL)
#defina FPB_REMAP_REG(base!       $          0   ((base)->REMAp)
#define FPB_COMP_RAG(base,index)0   (            ((base)->COMP[index])
#dEfine FPB^PID4_REG(base)  0                (   ((base)->PID4)M
3define FPB_PID5_REG(base)    `    "             ((base)->PID5)-
#define F�b_PID6_RGG(base(0  "  $   `             (base)=>PID6)
#degin% FPB_PID_REG(bas%)(�           0         ((base)->PIF7)
#define FPB_PID0_R�G�base)                       ((base)->PID0)
#denine �PB_PID1_REG(base)                `!    (((base+->PID!)
#definm PB_PID2_REG(basa)        �        !     ((base)->PID2)
#define FPB_pIF3_REG(base)                       ((jasg)->PID3)
#define FPB_CID0_REG(bAse)       �               ((base)->CID0)
#degin� FPB_CID1_�EG(base)    `        (         ((base)->CiD1)
#defhne�FPB_CID2_REW(base)       �               ((base)->CID2)
#define FPB_CID3_REG(ba�u)(                      ((base)->SID3+

?**
 * @}
 */ '* end of gro}p FPB_Register_AccessorWMacros */


/* -------,---------------------------%---------------------------------------   -- FPB REgister Masks
   ---------------------,----------------)---------------)-----/-------------- */

/**
 * @addtgroup GPB_Rugister_Masks FPB Recister Masks
 * @{-
 */


/**
 *0@}
 */ /* end o& group FPB_Register_Masks */


/* FPB - Peripheral instance base addrdsses */
/** Peripheral FPb base poinuer */
#lmfine FPB_BASE_PTR        0             #    ` �(FPB_MelMapPtr)0xE0002000u)
.** Array initializer of FpB0peripheral base poInters */
#define FPB_BASE_PTRS                            { FPB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register instance definitions */
/* FPB */
#define FP_CTRL                                  FPB_CTRL_REG(FPB_BASE_PTR)
#define FP_REMAP                                 FPB_REMAP_REG(FPB_BASE_PTR)
#define FP_COMP0                                 FPB_COMP_REG(FPB_BASE_PTR,0)
#define FP_COMP1                                 FPB_COMP_REG(FPB_BASE_PTR,1)
#define FP_COMP2                                 FPB_COMP_REG(FPB_BASE_PTR,2)
#define FP_COMP3                                 FPB_COMP_REG(FPB_BASE_PTR,3)
#define FP_COMP4                                 FPB_COMP_REG(FPB_BASE_PTR,4)
#define FP_COMP5                                 FPB_COMP_REG(FPB_BASE_PTR,5)
#define FP_COMP6                                 FPB_COMP_REG(FPB_BASE_PTR,6)
#define FP_COMP7                                 FPB_COMP_REG(FPB_BASE_PTR,7)
#define FP_PID4                                  FPB_PID4_REG(FPB_BASE_PTR)
#define FP_PID5                                  FPB_PID5_REG(FPB_BASE_PTR)
#define FP_PID6                                  FPB_PID6_REG(FPB_BASE_PTR)
#define FP_PID7                                  FPB_PID7_REG(FPB_BASE_PTR)
#define FP_PID0                                  FPB_PID0_REG(FPB_BASE_PTR)
#define FP_PID1                                  FPB_PID1_REG(FPB_BASE_PTR)
#define FP_PID2                                  FPB_PID2_REG(FPB_BASE_PTR)
#define FP_PID3                                  FPB_PID3_REG(FPB_BASE_PTR)
#define FP_CID0                                  FPB_CID0_REG(FPB_BASE_PTR)
#define FP_CID1                                  FPB_CID1_REG(FPB_BASE_PTR)
#define FP_CID2                                  FPB_CID2_REG(FPB_BASE_PTR)
#define FP_CID3                                  FPB_CID3_REG(FPB_BASE_PTR)

/* FPB - Register array accessors */
#define FPB_COMP(index)                          FPB_COMP_REG(FPB_BASE_PTR,index)

/**
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FPB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTFL
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFL_Peripheral FTFL
 * @{
 */

/** FTFL - Peripheral register structure */
typedef struct FTFL_MemMap {
  uint8_t FSTAT;                                   /**< Flash Status Register, offset: 0x0 */
  uint8_t FCNFG;                                   /**< Flash Configuration Register, offset: 0x1 */
  uint8_t FSEC;                                    /**< Flash Security Register, offset: 0x2 */
  uint8_t FOPT;                                    /**< Flash Option Register, offset: 0x3 */
  uint8_t FCCOB3;                                  /**< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB2;                                  /**< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB1;                                  /**< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB0;                                  /**< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB7;                                  /**< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB6;                                  /**< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB5;                                  /**< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB4;                                  /**< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOBB;                                  /**< Flash Common Command Object Registers, offset: 0xC */
  uint8_t FCCOBA;                                  /**< Flash Common Command Object Registers, offset: 0xD */
  uint8_t FCCOB9;                                  /**< Flash Common Command Object Registers, offset: 0xE */
  uint8_t FCCOB8;                                  /**< Flash Common Command Object Registers, offset: 0xF */
  uint8_t FPROT3;                                  /**< Program Flash Protection Registers, offset: 0x10 */
  uint8_t FPROT2;                                  /**< Program Flash Protection Registers, offset: 0x11 */
  uint8_t FPROT1;                                  /**< Program Flash Protection Registers, offset: 0x12 */
  uint8_t FPROT0;                                  /**< Program Flash Protection Registers, offset: 0x13 */
  uint8_t RESERVED_0[2];
  uint8_t FEPROT;                                  /**< EEPROM Protection Register, offset: 0x16 */
  uint8_t FDPROT;                                  /**< Data Flash Protection Register, offset: 0x17 */
} volatile *FTFL_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros
 * @{
 */


/* FTFL - Register accessors */
#define FTFL_FSTAT_REG(base)                     ((base)->FSTAT)
#define FTFL_FCNFG_REG(base)                     ((base)->FCNFG)
#define FTFL_FSEC_REG(base)                      ((base)->FSEC)
#define FTFL_FOPT_REG(base)                      ((base)->FOPT)
#define FTFL_FCCOB3_REG(base)                    ((base)->FCCOB3)
#define FTFL_FCCOB2_REG(base)                    ((base)->FCCOB2)
#define FTFL_FCCOB1_REG(base)                    ((base)->FCCOB1)
#define FTFL_FCCOB0_REG(base)                    ((base)->FCCOB0)
#define FTFL_FCCOB7_REG(base)                    ((base)->FCCOB7)
#define FTFL_FCCOB6_REG(base)                    ((base)->FCCOB6)
#define FTFL_FCCOB5_REG(base)                    ((base)->FCCOB5)
#define FTFL_FCCOB4_REG(base)                    ((base)->FCCOB4)
#define FTFL_FCCOBB_REG(base)                    ((base)->FCCOBB)
#define FTFL_FCCOBA_REG(base)                    ((base)->FCCOBA)
#define FTFL_FCCOB9_REG(base)                    ((base)->FCCOB9)
#define FTFL_FCCOB8_REG(base)                    ((base)->FCCOB8)
#define FTFL_FPROT3_REG(base)                    ((base)->FPROT3)
#define FTFL_FPROT2_REG(base)                    ((base)->FPROT2)
#define FTFL_FPROT1_REG(base)                    ((base)->FPROT1)
#define FTFL_FPROT0_REG(base)                    ((base)->FPROT0)
#define FTFL_FEPROT_REG(base)                    ((base)->FEPROT)
#define FTFL_FDPROT_REG(base)                    ((base)->FDPROT)

/**
 * @}
 */ /* end of group FTFL_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFL Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFL_Register_Masks FTFL Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#define FTFL_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFL_FSTAT_MGSTAT0_SHIFT                 0
#define FTFL_FSTAT_FPVIOL_MASK                   0x10u
#define FTFL_FSTAT_FPVIOL_SHIFT                  4
#define FTFL_FSTAT_ACCERR_MASK                   0x20u
#define FTFL_FSTAT_ACCERR_SHIFT                  5
#define FTFL_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFL_FSTAT_RDCOLERR_SHIFT                6
#define FTFL_FSTAT_CCIF_MASK                     0x80u
#define FTFL_FSTAT_CCIF_SHIFT                    7
/* FCNFG Bit Fields */
#define FTFL_FCNFG_EEERDY_MASK                   0x1u
#define FTFL_FCNFG_EEERDY_SHIFT                  0
#define FTFL_FCNFG_RAMRDY_MASK                   0x2u
#define FTFL_FCNFG_RAMRDY_SHIFT                  1
#define FTFL_FCNFG_PFLSH_MASK                    0x4u
#define FTFL_FCNFG_PFLSH_SHIFT                   2
#define FTFL_FCNFG_SWAP_MASK                     0x8u
#define FTFL_FCNFG_SWAP_SHIFT                    3
#define FTFL_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFL_FCNFG_ERSSUSP_SHIFT                 4
#define FTFL_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFL_FCNFG_ERSAREQ_SHIFT                 5
#define FTFL_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFL_FCNFG_RDCOLLIE_SHIFT                6
#define FTFL_FCNFG_CCIE_MASK                     0x80u
#define FTFL_FCNFG_CCIE_SHIFT                    7
/* FSEC Bit Fields */
#define FTFL_FSEC_SEC_MASK                       0x3u
#define FTFL_FSEC_SEC_SHIFT                      0
#define FTFL_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_SEC_SHIFT))&FTFL_FSEC_SEC_MASK)
#define FTFL_FSEC_FSLACC_MASK                    0xCu
#define FTFL_FSEC_FSLACC_SHIFT                   2
#define FTFL_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_FSLACC_SHIFT))&FTFL_FSEC_FSLACC_MASK)
#define FTFL_FSEC_MEEN_MASK                      0x30u
#define FTFL_FSEC_MEEN_SHIFT                     4
#define FTFL_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_MEEN_SHIFT))&FTFL_FSEC_MEEN_MASK)
#define FTFL_FSEC_KEYEN_MASK                     0xC0u
#define FTFL_FSEC_KEYEN_SHIFT                    6
#define FTFL_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_KEYEN_SHIFT))&FTFL_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFL_FOPT_OPT_MASK                       0xFFu
#define FTFL_FOPT_OPT_SHIFT                      0
#define FTFL_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FOPT_OPT_SHIFT))&FTFL_FOPT_OPT_MASK)
/* FCCOB3 Bit Fields */
#define FTFL_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB3_CCOBn_SHIFT                  0
#define FTFL_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB3_CCOBn_SHIFT))&FTFL_FCCOB3_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFL_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB2_CCOBn_SHIFT                  0
#define FTFL_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB2_CCOBn_SHIFT))&FTFL_FCCOB2_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFL_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB1_CCOBn_SHIFT                  0
#define FTFL_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB1_CCOBn_SHIFT))&FTFL_FCCOB1_CCOBn_MASK)
/* FCCOB0 Bit Fields */
#define FTFL_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB0_CCOBn_SHIFT                  0
#define FTFL_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB0_CCOBn_SHIFT))&FTFL_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFL_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB7_CCOBn_SHIFT                  0
#define FTFL_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB7_CCOBn_SHIFT))&FTFL_FCCOB7_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFL_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB6_CCOBn_SHIFT                  0
#define FTFL_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB6_CCOBn_SHIFT))&FTFL_FCCOB6_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFL_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB5_CCOBn_SHIFT                  0
#define FTFL_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB5_CCOBn_SHIFT))&FTFL_FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFL_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB4_CCOBn_SHIFT                  0
#define FTFL_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB4_CCOBn_SHIFT))&FTFL_FCCOB4_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFL_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBB_CCOBn_SHIFT                  0
#define FTFL_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOBB_CCOBn_SHIFT))&FTFL_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFL_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBA_CCOBn_SHIFT                  0
#define FTFL_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOBA_CCOBn_SHIFT))&FTFL_FCCOBA_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFL_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB9_CCOBn_SHIFT                  0
#define FTFL_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB9_CCOBn_SHIFT))&FTFL_FCCOB9_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFL_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB8_CCOBn_SHIFT                  0
#define FTFL_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB8_CCOBn_SHIFT))&FTFL_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFL_FPROT3_PROT_MASK                    0xFFu
#define FTFL_FPROT3_PROT_SHIFT                   0
#define FTFL_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT3_PROT_SHIFT))&FTFL_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFL_FPROT2_PROT_MASK                    0xFFu
#define FTFL_FPROT2_PROT_SHIFT                   0
#define FTFL_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT2_PROT_SHIFT))&FTFL_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFL_FPROT1_PROT_MASK                    0xFFu
#define FTFL_FPROT1_PROT_SHIFT                   0
#define FTFL_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT1_PROT_SHIFT))&FTFL_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFL_FPROT0_PROT_MASK                    0xFFu
#define FTFL_FPROT0_PROT_SHIFT                   0
#define FTFL_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT0_PROT_SHIFT))&FTFL_FPROT0_PROT_MASK)
/* FEPROT Bit Fields */
#define FTFL_FEPROT_EPROT_MASK                   0xFFu
#define FTFL_FEPROT_EPROT_SHIFT                  0
#define FTFL_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROT_SHIFT))&FTFL_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define FTFL_FDPROT_DPROT_MASK                   0xFFu
#define FTFL_FDPROT_DPROT_SHIFT                  0
#define FTFL_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPROT_DPROT_MASK)

/**
 * @}
 */ /* end of group FTFL_Register_Masks */


/* FTFL - Peripheral instance base addresses */
/** Peripheral FTFL base pointer */
#define FTFL_BASE_PTR                            ((FTFL_MemMapPtr)0x40020000u)
/** Array initializer of FTFL peripheral base pointers */
#define FTFL_BASE_PTRS                           { FTFL_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros
 * @{
 */


/* FTFL - Register instance definitions */
/* FTFL */
#define FTFL_FSTAT                               FTFL_FSTAT_REG(FTFL_BASE_PTR)
#define FTFL_FCNFG                               FTFL_FCNFG_REG(FTFL_BASE_PTR)
#define FTFL_FSEC                                FTFL_FSEC_REG(FTFL_BASE_PTR)
#define FTFL_FOPT                                FTFL_FOPT_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB3                              FTFL_FCCOB3_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB2                              FTFL_FCCOB2_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB1                              FTFL_FCCOB1_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB0                              FTFL_FCCOB0_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB7                              FTFL_FCCOB7_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB6                              FTFL_FCCOB6_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB5                              FTFL_FCCOB5_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB4                              FTFL_FCCOB4_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBB                              FTFL_FCCOBB_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBA                              FTFL_FCCOBA_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB9                              FTFL_FCCOB9_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB8                              FTFL_FCCOB8_REG(FTFL_BASE_PTR)
#define FTFL_FPROT3                              FTFL_FPROT3_REG(FTFL_BASE_PTR)
#define FTFL_FPROT2                              FTFL_FPROT2_REG(FTFL_BASE_PTR)
#define FTFL_FPROT1                              FTFL_FPROT1_REG(FTFL_BASE_PTR)
#define FTFL_FPROT0                              FTFL_FPROT0_REG(FTFL_BASE_PTR)
#define FTFL_FEPROT                              FTFL_FEPROT_REG(FTFL_BASE_PTR)
#define FTFL_FDPROT                              FTFL_FDPROT_REG(FTFL_BASE_PTR)

/**
 * @}
 */ /* end of group FTFL_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FTFL_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Peripheral FTM
 * @{
 */

/** FTM - Peripheral register structure */
typedef struct FTM_MemMap {
  uint32_t SC;                                     /**< Status And Control, offset: 0x0 */
  uint32_t CNT;                                    /**< Counter, offset: 0x4 */
  uint32_t MOD;                                    /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    uint32_t CnSC;                                   /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    uint32_t CnV;                                    /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[8];
  uint32_t CNTIN;                                  /**< Counter Initial Value, offset: 0x4C */
  uint32_t STATUS;                                 /**< Capture And Compare Status, offset: 0x50 */
  uint32_t MODE;                                   /**< Features Mode Selection, offset: 0x54 */
  uint32_t SYNC;                                   /**< Synchronization, offset: 0x58 */
  uint32_t OUTINIT;                                /**< Initial State For Channels Output, offset: 0x5C */
  uint32_t OUTMASK;                                /**< Output Mask, offset: 0x60 */
  uint32_t COMBINE;                                /**< Function For Linked Channels, offset: 0x64 */
  uint32_t DEADTIME;                               /**< Deadtime Insertion Control, offset: 0x68 */
  uint32_t EXTTRIG;                                /**< FTM External Trigger, offset: 0x6C */
  uint32_t POL;                                    /**< Channels Polarity, offset: 0x70 */
  uint32_t FMS;                                    /**< Fault Mode Status, offset: 0x74 */
  uint32_t FILTER;                                 /**< Input Capture Filter Control, offset: 0x78 */
  uint32_t FLTCTRL;                                /**< Fault Control, offset: 0x7C */
  uint32_t QDCTRL;                                 /**< Quadrature Decoder Control And Status, offset: 0x80 */
  uint32_t CONF;                                   /**< Configuration, offset: 0x84 */
  uint32_t FLTPOL;                                 /**< FTM Fault Input Polarity, offset: 0x88 */
  uint32_t SYNCONF;                                /**< Synchronization Configuration, offset: 0x8C */
  uint32_t INVCTRL;                                /**< FTM Inverting Control, offset: 0x90 */
  uint32_t SWOCTRL;                                /**< FTM Software Output Control, offset: 0x94 */
  uint32_t PWMLOAD;                                /**< FTM PWM Load, offset: 0x98 */
} volatile *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define FTM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define FTM_CNTIN_REG(base)                      ((base)->CNTIN)
#define FTM_STATUS_REG(base)                     ((base)->STATUS)
#define FTM_MODE_REG(base)                       ((base)->MODE)
#define FTM_SYNC_REG(base)                       ((base)->SYNC)
#define FTM_OUTINIT_REG(base)                    ((base)->OUTINIT)
#define FTM_OUTMASK_REG(base)                    ((base)->OUTMASK)
#define FTM_COMBINE_REG(base)                    ((base)->COMBINE)
#define FTM_DEADTIME_REG(base)                   ((base)->DEADTIME)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)
#define FTM_POL_REG(base)                        ((base)->POL)
#define FTM_FMS_REG(base)                        ((base)->FMS)
#define FTM_FILTER_REG(base)                     ((base)->FILTER)
#define FTM_FLTCTRL_REG(base)                    ((base)->FLTCTRL)
#define FTM_QDCTRL_REG(base)                     ((base)->QDCTRL)
#define FTM_CONF_REG(base)                       ((base)->CONF)
#define FTM_FLTPOL_REG(base)                     ((base)->FLTPOL)
#define FTM_SYNCONF_REG(base)                    ((base)->SYNCONF)
#define FTM_INVCTRL_REG(base)                    ((base)->INVCTRL)
#define FTM_SWOCTRL_REG(base)                    ((base)->SWOCTRL)
#define FTM_PWMLOAD_REG(base)                    ((base)->PWMLOAD)

/**
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MODa��s���ٗ�b�\��,������k�>����uR�,����<�����N�������� ¦�y�Aj�s�- ����K�6� ����+uf�Ok1�T
�6q\����.¼�:O�h	���(�j�AHʈ�u܎��I4iȌW���敥HRu�rD�^�}>���M*`Y���n�Y�.F]{��9����O�	:����\3�0G���̍�.���+�*�m��H��Z�.z��f���r������)m�Rh/)�� ס�S'��,`+AfJ!K;��߼�������V��%~9cڝ�i�n��>v�L�n&Ͱ9��W��F~Y=���)�D�<2�.�ǫ*����8�
�6p/����J;�>��ͯ#��;N�0V�S�cJe~����**bO_��G�I���8���^؎8��)���B5R��C�Q�ѬV�(�_D�)Kb$�h#
y�Cj�p�!��'�;����'[��@���<� 3������'o,L~ܺb�uT'�ޡ,<�x׊^���Sأo� m�$ǒ�~����"�A�B����DW��� ��A��P^.)#�zU6���@'�� ܜ8@�,���i��l:f[G��ܓNt�PD{�\{�E_g����<0�D�&���.���:�#�\Qp���_�2g�}7^kER�e����#��x@��t�Q��B�B����VMF�e���[��� ;KU����g�W4����3�����k�^�㭨㞤���"%�9�s��d����-��~Mr�>ZCf2Wh�bSBn���i#�N���^�M_�{��P���$�G�#�_T��,EX�ꉾ�����>[O6֧^�5ɂ����6ն�Op$YF��,��/�����W�;��_n���α����@��]�}%���vk=���N`D�p�����B�_�,��W�e$������HkEmyC�3Y�deyjI��X�u@e��q����Nm#X4m��S�����Ys�(n��
�N����`��<oȞ�`){�[�a�AL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                 ��WSh�SJ�]�8z���u��u��A�Kp|��z�e���_r�?s���Ɖ� ��EJh�0cv{uܺ����ئ�N�/ˀ!�.�ě ��Z�o��I
�FQ:�ik�ꡲg-�"���U�pjx���I��aR\s��������Y��V��hW��v�/���?�30 �U�E!6��Bq}�R����{����G����-�����=>�S��"sl��Ru��L�s��a��&��\��'W�o�ߎnY���2ฟ{��5phփ�(q�`��5E�lW�s��MƖ�25��8��ϕa{c��nD�t� O/�3��"B-.k��?��1����Y� Y�ݗ���g\�3�a�o���^'v}�~�o(L#�kU��H��ZoS7��wHj�/�-�D#����/�r@�S�jѶ�������2jq��}Fc͚_�+A�Jl�ʐ΃1���a%��P���߀�U��[b��7���]��"���w�;��w}(Q�O)S��k���Kzr��Q�	�鏹�n�O�q1��b@��E1�}��5bqmƈO�,cp�zgÎ��4h%y��;��^�l���nbn�+�ܖ���	WF�Ղhϻ��
D7�,�h�PU�� Q!�����k7���}#����g�� ̒"g*�.�G��I�?B�wd�l��b>���~%(1!�H�w�,�	-��k�����<H��2L���K�s����1�S��Z����K�:�R.�t���x�Ʃ���EO@E{�]3�*m�\�˖[$1%$�,>�����+#���t�̕Jdʺ�|�x=3�L(��¤�I�"�C��͆�5�"ؠr|C�� �8�h�~�7CFs��Re�yG�L��t��+X�T�	��`폃9�%��C�.��,k%�-�J0Ϋb�����?��З}{�I���)�!�f��"�Gy�� ��Ӑ�>n4h����8&����j��zC����t��rh !^̻�{��)MUd�����:����Xںގ&%��T߱xOj                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1
#tmfine FTM_COMBINE_DECApEN0_MASK     0       !  0x4u
#define FTM_C_MBINE_DECAPEN0_SHIFT               2
#define FTM�COMBINE_DECAP0�MASK             "    0x8u
#tefine(FTM_OMBINE_DECAP0_SHIFT                 3
#define FTL_COMBINE_DTEN0_MSO                   0x10u
#definm FTM_COEBKNU_DTEN0_SHIFT          (       4
#defhne FTM_COMBINE_SYNCEN0_MASK              "  0x20u
#define0FTM_C�MBINE_SYNCEN0_SHIFT                5
#define FTM_COMBINE_FULTEN0_MASK                0x40u#define FTM_COMBINE_FAULPEN0_SHIFT               6
#definE FTM_COMBINE_C�MB�NE1_MISK        ! `  �  0z100u
#define F\M_COMBINE_COMBINE1_WHIFT               8
#devine FTM_COMBINE_COMP1_MASK                   0x2�0e
#define FTLOCOMBINE_COMP1_SHIFT  "          �    9
#de&ine fTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DEKAPEN1_[HIFT               10
#define FTM_COMbINE_DECAP1_MASK   "  "! (        0x8 0u
#defmne FTM_COMBINE_DECAP1_SHIFT        $        11
#define TM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0
#define FTM_DEADTIME_DTFAL(x-     (         0 !  (((Uint32_t)(((u)nt32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTRAL_MASK)
#defmne FTM_@EADTIME_DTPS_MASK  �        !     $ 0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#dEfine FTM_DEADPIME_DTPS(x)   (                 (((uint32_t)(((uint32_t)(x)-<<FTM_DEADTIME_DTS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/*$EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TR	G_MASK           �     0x1u
#ddfine FTM_EXTTRIG_CH2TRIGOSHIBT                0
+define FTM_EXTTRAG_CH3\RIG_MASK ( 0    `        0x3u
#define FTM_MXTTRIG_cH3TRIG^SHIFT                1#defyne FTM_EXTTRIG_CH4TRIG_MASC                 0x4u
#define FTM_EYTTRIG_CH4TRIG_SHIFT                2�
#define FTM_EXTVRIG_CH5TRIG_MASK                 0x8u
#define F�M_EXTTRIG_CH5TRIG_SHIFT                3
#defije!FTM_EXTTRIG_CH2TRIG_MASK             !   0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4�#eefine FTM_EXVTRIG_CH1URIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT         !      5
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0
#define FTM_FILTER_CH0FVAL(x)         ������Q�}-��Q$���j�L�|��n�Y���q6�����l��ᱏ7��=K#��W�nJ���,?mj�
@�qk�u�n�>��w�C����z_H"|�<0�';ܖ���%�אf4u��t�A~�0Bt��|���������n2�2c����L�&c��vF�0�+e��B���������G&7�7��x�[K˿�iT���I�ALX{�lEw�D��Ļ�#:-�`67��7�)6~ gӼ�Y��:��
<Rn��z?�̖<�2����/�Oڍ{$�̔9��I��`Q�8�ہ�O�d�5�}\-�5؋��6hz�jV^��lJ�ZjZ	�����zx����i�As&ˮ@����=�<7��ϟ����{t�N5n������ 9�E��u��,���/T��=�൨��8D�{`�n�.H#�8� 0rwt�û�5���O��b�����^�~(�N��/�D���iץ��U2<��9�A�Oޜx�s��S{�s���*8�����A>+��b�с��{�c)��HJiɰ�&�_��1�Z�p���1J����xg�{a�ma��{�t}R��QY���D(����[�� k���(U��Q�S@u��^�������4��c�#�׊�K�P �1OH͖ayߛ��%@i��z���2Mz/��ٲ�2�����w%��AI�ң��۝x7	S6�*�2�����^��N�V�Ŀ���y�0������%K��{��[��k1�L�m����Tn�!���ͭ��`�t7�b���[��\�̼�4�v��J���c�Y�Ӟ�s����N3����Κ��c��Ɯ,p�:��+�Ʋ�a�y�X0��rÊ	�U�5�$gѲ�A����S��ݘ��ӳt0 ��R,��d7G��f���D��p�SZ��*X$�Ps��w����j���q��r:iG�S�i�\���ɛR��l펂�̩����L��d���-*I�+��5�*M����ۼ]�x(~Xp�|����<�
�XФʹ����4��9��B^~�H��QX���I�O8�Ɛ�T�,�o�ӺjJ��dB�6I׹r�����Z�g*$ "Tm\����@�����ox�{Cރ#� �=v���@=:���M��T����H�kҜ�c_�g� �ޝY��sÿn���9��UH��K=x�]уv�L�.��	AȨV[g��Os"zd)��ۣ6����3R�	�U���(Mox~��"O�zj(J��M���u����R���SW�����4�Y��|p�+ ;u � AO9��3��C!�8��c�Z`��q=������4�����M�"e�|���H� @�!��=p����/�����6D�K)�������4�"�B$������դ+�r��OǕ+�������5$0���O�:��4n ���_���	������2�ش�lhIȿ���w�юY�K|�fXU�H�ո^|���(q�Y��h���]�
���|�SQ�l���Q���@�.�c���4�'_m#d������z"�ڃ�XۿˬQ��3��~�YJ����#йv՘Q�4k�+3*��6��/�R)�� ���}@��jfI^��j9]:�~s��`�iL�U�*�s-#��S�/��&���j�n��إ���qGIZ����(ع��W{UM��MD�^��7ܶ�9s�a�\=lсBun���r�cP��1	��;H���Cڿ�.c{��+X�3f7G�\�������٨�+�����JE�MA���]I�B/�l��W�])bu���5'�|Ζ��ô`p����l��~��هZ/WŜ~�#��3��,R�3ۿ���}|Rd)�)Rh�ќ�+��2]�?�;x����W"Yu�"�����M �X�o��,-��w3��y�E�:"e�"^���E����Ȝڍ�鈴����j��An��(P2GO/�G�ț�.�CM+5���\6�AI^OX��Aܱ`Ɓ�.5� =�K��_XƹJe�V>�1�u��"���T�'��K�XL�F��eh�c�Du�s'��0�bD"B�=A	^&��9/Ӆ�be��P�l%�G��Z��g��Bm���T�;�ť�3�m��1
xE�]c6�\�I}�T��[+}&�jmG�>��;����:�3�wT��n�ޡӤF><�4�=���*�87���g��N�%�X�[�p����e@ns@�Iޙ��wH�5%ݔE��
e�G�Z�D7)D�0��0�1`�_-�`6)�@�fDX݅���W���o����mS��gS� �6�{��ʃ�XJt�������;��~Zd8N���_$ˆ���zxTb���TVX���a�l�(ն����|�j+EB/�;�Hr%S6�|��{#:1ɕ���}�ݼ4��?@����;��P)�m2�M�����=9ʤ����˺�%7{��&	e���y���s O�p�����{K$-���swwB�$�3��M{բ��Գ�PU��fX}�(���-�{�Іx\�>_�L�Cj�E�ee:��c���-����+�l�p-�(�#p���;��C���&d��f�x�<�F��g�}d���A��7p�:y��5OE\`j��]��=e	&*�>oY��J�;-�\ѵ���G��7���R����߁8�҄�j��SG-[BZ�=�9������-��h�m�Ud|��,��M������	����������Mj����M��J��
��gʶu���0��W�6�O!DI�t��o��˃H�'����\ �xP�Z
lT��t�j��Ø��IC+�����j�5�$��!Fe�+.e��5=���'U�8&F��Ӟ�ym!pL�|��*>I�h��h������f�|�ԣs�wN�.�%�r �%���~(�;2Uz�!*�XC�!x��.�.��oCZ|/�}v��wL�n�u_�,Rq�^Sf�B�^(�}�}��D;+� �ъ,���+�R��Bb����7�c�r�~H��?~)%.�'��.s�|�x�1�X;\�I:(����U(3��D!������3v�k�Y�ێ<{kl��O��q,@��e�ڲc�C�G�9��t���%����[6)�b�Pwi3���b)b���� ʀ �q�s���0�����P��M�?���"tY�h@B������}ȁ˵ֶ���%X���y�
�Z�
�0���f�DIǓ����P�af�g/Tk����u�c4`h�	+�t��daU�Rվ���/lT��q}YOQP�a����c�Bk���������D�мAh똯�QeG6�8�{U�l��G!����
�o�tQ3��[���@��5 Sy��������ȧ�
�0�*Ю��1_��Z�D���֋���C5\���h��a��d_:�8m��x\UFb(�u����Tc�M,� ��V3=2��L���ʉR�O
���&�<�qU�T� ��rk����.�'�Yn�&�"��ڸ�%ۨL�k)F�诏��*�E�W�8L�w�&�1�o���y<�[�^�IWǴ�)k��/)�!��/��R#�� a���N��t��nj��z��B�	ʑ����kE(nռ�:�R�̋��@c�+���ڃ��<DRC<�75�<h$K���ʆ��[)�&����Ðe�h�S�Of�3{D1xL.ۆR�uM�/�?ﴳ��[���F�<WAf��HQɴ�x�32=�AV[�{8�Z%���-�,���A�_C$\.�)3���A�=]JC֞v_-ol��ڡ/��wen�� �P�j,�]��\=��~�
��'S�J�"16�0��G�44�'��������ƕ�b��k51�>�i�!�z ���t����0q(�{�5�ǅ������u��+�䏒�-O��
������}X׏$���Ѳ2a���?�Z93�)��_���)}A�4]��B��#|<�9{�N���=^����?�料��'�bveɋq~�D9L�jlU2�+
�����-xB���V�����s��F�Mkz�R`ΜˊF��G���R������\^��Bm$I��3R^������Q�}-��Q$���j�L�|��n�Y���q6�����l��ᱏ7��=K#��W�nJ���,?mj�
@�qk�u�n�>��w�C����z_H"|�<0�';ܖ���%�אf4u��t�A~�0Bt��|���������n2�2c����L�&c��vF�0�+e��B���������G&7�7��x�[K˿�iT���I�ALX{�lEw�D��Ļ�#:-�`67��7�)6~ gӼ�Y��:��
<Rn��z?�̖<�2����/�Oڍ{$�̔9��I��`Q�8�ہ�O�d�5�}\-�5؋��6hz�jV^��lJ�ZjZ	�����zx����i�As&ˮ@����=�<7��ϟ����{t�N5n������ 9�E��u��,���/T��=�൨��8D�{`�n�.H#�8� 0rwt�û�5���O��b�����^�~(�N��/�D���iץ��U2<��9�A�Oޜx�s��S{�s���*8�����A>+��b�с��{�c)��HJiɰ�&�_��1�Z�p���1J����xg�{a�ma��{�t}R��QY���D(����[�� k���(U��Q�S@u��^�������4��c�#�׊�K�P �1OH͖ayߛ��%@i��z���2Mz/��ٲ�2�����w%��AI�ң��۝x7	S6�*�2�����^��N�V�Ŀ���y�0������%K��{��[��k1�L�m����Tn�!���ͭ��`�t7�b���[��\�̼�4�v��J���c�Y�Ӟ�s����N3����Κ��c��Ɯ,p�:��+�Ʋ�a�y�X0��rÊ	�U�5�$gѲ�A����S��ݘ��ӳt0 ��R,��d7G��f���D��p�SZ��*X$�Ps��w����j���q��r:iG�S�i�\���ɛR��l펂�̩����L��d���-*I�+��5�*M����ۼ]�x(~Xp�|����<��V������"x�Y�)c0��k�pT�ո8���^�r����ə�.l�g�;���p�#.Ŝ�f��V�:zCF>�?�2�����Na���N���@�g�5t��j�>����nc��܎�W���5�I;���N��׿Q��K�����h&��&��,�e���Yb�M�@�k4D~��KH�'��?Ȭ8h�l׃8�s��>�4YƌF�|�S�7�v�0�ED��D�%�q��
u���Yvÿ��*0�_�4q}�
W���_�0�HR�Z�n,��$�
�]����Y�=�0f�
�	M���,T*}�$�Du�f���+�M� ���fo1�����z1��i�|�x���LK�)ш$�w��g(<�m5N��y�W�ie��h��P7׿+[ѩ�	��6az�͸P
�hM_JT��3�:R��,�xT����l�$2������NBR<Di����h~`Vq�m�M��$܉��g����*��<~���4-O#��T�,�Dl�d �����:w���3?�Ύ�XՐMi2�54p�b�~i�ȹ^��%B5mħ�<"a:֢_�M&I���z�����a�v�����h9o'��/���Y��w�
�#�8.����$�V���2��@t�ΑR��Jؙ�'���l'���.��x��4�_�w�g���U�m�w"z����TI!E��5�ٝ�+eK����p��tl���i�K�K���P�5]�\9�%���
Οg���F��O:�m���,��O�>�aK��#����-3Ғ�����R�&��'�_?>fp(��f�Fo�3t�n�f�7&{�A]�2� 0��m�9�LZ��C�Ĝ�:��UQ���6:�5O��}>�����/2v��.$sv$<{e�R��}N1��z9Ўԏw��e���ᦷ\�@�R� E��kS��7�	YY�8��G�W�`�ؔ2����ɓ�0���3Y��(��������5��Y���X��؁ނ�d�ǚ�)y��]х�7�ǟ\��jN~~��c7(S/
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
3eefkne FTM_SWOCTRL_CH1OCV_SHIFT                 9
#define fTM_SWOSTRL_CH2OCV_MASK          $ �     0x400U
#define0FT]_SWOCTRL_CL2OCV_SHIFT   �         `   10
#defmne FTM_SWOCTRL_CH3OCF_MASK      (  �!       0x000u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11
#define FTM_SWOCTRL_CH4OCv_MASK                  0x1�00u
#dgfane FTM_S�OCTRL_CH4OCV_SHIFT                 12
#define FTM_SWOCTPL_CH5�CV_MASK                � 0x2000u
#define FTM_sWOCTRL_CH5OCV_SHIFT!     $   �      13*#define FTM_SWOCTRL_CH6OCv_MASK                  0x4000u
#define FT]_SWOCTRL_CH6OCV_SH�FT             `  "14
#define FTM_SWOCTRL_CH7OCV_MASK                  0z8000u
#define FTM_SWNCTRL_CH7OCV_SHIFT                 15
/* PWMLOAD"Bit Fields0*/
#define FTM_PWMLOAD_CH0SEL_MARK    `  0          1x1u
#define FTM]PWMLOED_CH0SEL_SHIFT        !        0
#define NTM_PWMLOAE_C@1REL_MASK                  0xu
#define FTM_PWMLOADWCH1SEL_SHIFT                 1
deFine FTM_PWMLOAD_CH2SEL_MASK$                 0x4u
#devine FTM_PWMLOAD_CH2SEL_SHIFT               0 2
#define FTM_PWMLOAD_CH3SEL_MASK !      "    (  � 0x8u
#defing FTM_PW]LOAD_CH3SEL_SHIFT         ` (     3
#define FTM_PWMLOAD_CH4SEL_MASK               0  0x10u
define FTM_PWMLOAD_CI4SEL_SHIFT �               4
#define FTM_PWMLOAD_CH5SEL_MASK           �      0x20u
#defin FTM_PWMLOAD_CH5SEL_SHIFT  !              5
#defIne FTM_PWMLO@D_CH2SEL_MASK                  0x40u
#define FTM_PGMLKAD_CJ6SELOSHIFT           ! !   &
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMOAD_CH7SEL_SHIFT                 7
#define FTM_PWMLOAD_LDOK_�ASK  0                 0x200u
#define FTM_PWMLOAD_LDOKSHIFT             `     9

/**
 * @}
 */ /* end of group$FTM_Register_Masks */


/* FTM - Periphe�al!instance base addresses *//*( PeriPheral VUM0 base pointer */
#define FTM0_BASE_PTR    `   (                   ((FTM_MemMapPtr(0x41038000u)
/** eripheral FTM1 bcse `ointer *'
!dufine`FTM1_B@SE_PTR     `  0                 " ((NTM_MemMapPtr)0x40039000u)
/** Peripheral FTM2 base pointer */
#define FTM2_BASE_PTR                            ((FTM_MemMapPtr)0x400B8000u)
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0_BASE_PTR, FTM1_BASE_PTR, FTM2_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0_BASE_PTR)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0_BASE_PTR)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0_BASE_PTR)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0_BASE_PTR,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0_BASE_PTR,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0_BASE_PTR,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0_BASE_PTR,1)
#define FTM0_C2SC                                FTM_CnSC_REG(FTM0_BASE_PTR,2)
#define FTM0_C2V                                 FTM_CnV_REG(FTM0_BASE_PTR,2)
#define FTM0_C3SC                                FTM_CnSC_REG(FTM0_BASE_PTR,3)
#define FTM0_C3V                                 FTM_CnV_REG(FTM0_BASE_PTR,3)
#define FTM0_C4SC                                FTM_CnSC_REG(FTM0_BASE_PTR,4)
#define FTM0_C4V                                 FTM_CnV_REG(FTM0_BASE_PTR,4)
#define FTM0_C5SC                                FTM_CnSC_REG(FTM0_BASE_PTR,5)
#define FTM0_C5V                                 FTM_CnV_REG(FTM0_BASE_PTR,5)
#define FTM0_C6SC                                FTM_CnSC_REG(FTM0_BASE_PTR,6)
#define FTM0_C6V                                 FTM_CnV_REG(FTM0_BASE_PTR,6)
#define FTM0_C7SC                                FTM_CnSC_REG(FTM0_BASE_PTR,7)
#define FTM0_C7V                                 FTM_CnV_REG(FTM0_BASE_PTR,7)
#define FTM0_CNTIN                               FTM_CNTIN_REG(FTM0_BASE_PTR)
#define FTM0_STATUS                              FTM_STATUS_REG(FTM0_BASE_PTR)
#define FTM0_MODE                                FTM_MODE_REG(FTM0_BASE_PTR)
#define FTM0_SYNC                                FTM_SYNC_REG(FTM0_BASE_PTR)
#define FTM0_OUTINIT                             FTM_OUTINIT_REG(FTM0_BASE_PTR)
#define FTM0_OUTMASK                             FTM_OUTMASK_REG(FTM0_BASE_PTR)
#define FTM0_COMBINE                             FTM_COMBINE_REG(FTM0_BASE_PTR)
#define FTM0_DEADTIME                            FTM_DEADTIME_REG(FTM0_BASE_PTR)
#define FTM0_EXTTRIG                             FTM_EXTTRIG_REG(FTM0_BASE_PTR)
#define FTM0_POL                                 FTM_POL_REG(FTM0_BASE_PTR)
#define FTM0_FMS                                 FTM_FMS_REG(FTM0_BASE_PTR)
#define FTM0_FILTER                              FTM_FILTER_REG(NTM0_BASE_PTR)
#define FTO0_FLTCTRL                0            FTM_DLTCTRL_REG(FTM0_BASE_PTR) define"FTM0_QDCTRL"                       0     FTM_QDCTRL_REG(FT�0�BASG_PTZ)
!define FTM0_CONF                         0      FTM_CONF_REG(FTM0_BASE_PTR)
#define FTM0_FLTPOL                  (    $      FTM_FLTPOL_REG(FTM0_BASE_PtR)
#define FTM0_SYNCONF                             FTM_S�NCONF^REG(FTM0_BASE_PTR)
#defkne FTM0_INVCTRL                             Fte_INVCTRL_REG(FT]0_BASG_PTR)
#define FTM0_SW�KTVL                             FTM_SWOCTRL_REG(FTM0_BASE_PTR)
#define FTM0_PWMLOAD                             FTM_pWMLOA�_REG(FTM0_BACE]PTR)
-*(FTM1 �/
#define FTM1^sS                          �    �  FTM_SC_REG(FTM1_BASE_PDR)
#defioe$DTM1_CNT       $        $                FT�_C^T_REG(FTM1_BASE_PTR)
#define TM1_MOD $                               FTM_MOD_REG(FTM1BASE_PTR)
#define FTM1_C0SB                                FTM_CnSC_REG(FTM1_BASE_PTR,0)
#define FTM1_C�V    `                            FTL_CnV_REG(FTM1_BASE_XTR,0)
;define FTM1_C1SC          �                   � FTM_CnSC_REG(FTM1_BASE_PTS,1)
#define FTM1_C1V       "             0           FTM_CnV_REG(FTM1_JaSE_PTr,1)
#define FTM1_CNTIL0        �                     FTM_CNTIN_REG(FTM1_BASE_PTR)
#define FTM1_STCTUS  $              (   (      ` FTM_STATUS_REG(FTM1_BASE_PTR)
#define FTM1_LODE       `                   "    VTM_MODE_REE(FTM1_BASE_PTR9
#tefine FTM1_SYNC                           0    FTM_SYNC_REG(FTM1_�ASE_PTR)
#define FTM1_oUPINIT  (        (  0              FTM_OUTINIT_REG)FtM1_FCSE[PTR)
#dmfine FTM1_OUTMASK       (                    !FTM_OETMASK_REG(FTM1_BASE_PTR)
#define FTM1_COMB�NE                  (      `   FPM_COMBINE_REG(FTM1_BASE_PTR)
+define FTM1_DEADTIME                        (   FTM_DEADTIMD_REG(FTM1_BASE_PTR)
#define F\M1_EXTTIG                 `          FTM_EXTTRIG_REG(FTM1_BASE_PTR)
#define FTM1_PL      0     �                 "0 FDM_POL_REG(FTM1_BASE_PTR)
#defi~e FTM1]FMS                                 FTM_FMS_REG(FTM1_BASE_PTR)
#define FTM1_FILTER                              FTM_FILTER_REG(FTM1_BASE_PTR)
#define FTM1_FLTCTRL                             FTM_FLTCTRL_REG(FTM1_BASE_PTR)
#define FTM1_QDCTRL                              FTM_QDCTRL_REG(FTM1_BASE_PTR)
#define FTM1_CONF                                FTM_CONF_REG(FTM1_BASE_PTR)
#define FTM1_FLTPOL                              FTM_FLTPOL_REG(FTM1_BASE_PTR)
#define FTM1_SYNCONF                             FTM_SYNCONF_REG(FTM1_BASE_PTR)
#define FTM1_INVCTRL                             FTM_INVCTRL_REG(FTM1_BASE_PTR)
#define FTM1_SWOCTRL                             FTM_SWOCTRL_REG(FTM1_BASE_PTR)
#define FTM1_PWMLOAD                             FTM_PWMLOAD_REG(FTM1_BASE_PTR)
/* FTM2 */
#define FTM2_SC                                  FTM_SC_REG(FTM2_BASE_PTR)
#define FTM2_CNT                                 FTM_CNT_REG(FTM2_BASE_PTR)
#define FTM2_MOD                                 FTM_MOD_REG(FTM2_BASE_PTR)
#define FTM2_C0SC                                FTM_CnSC_REG(FTM2_BASE_PTR,0)
#define FTM2_C0V                                 FTM_CnV_REG(FTM2_BASE_PTR,0)
#define FTM2_C1SC                                FTM_CnSC_REG(FTM2_BASE_PTR,1)
#define FTM2_C1V                                 FTM_CnV_REG(FTM2_BASE_PTR,1)
#define FTM2_CNTIN                               FTM_CNTIN_REG(FTM2_BASE_PTR)
#define FTM2_STATUS                              FTM_STATUS_REG(FTM2_BASE_PTR)
#define FTM2_MODE                                FTM_MODE_REG(FTM2_BASE_PTR)
#define FTM2_SYNC                                FTM_SYNC_REG(FTM2_BASE_PTR)
#define FTM2_OUTINIT                             FTM_OUTINIT_REG(FTM2_BASE_PTR)
#define FTM2_OUTMASK                             FTM_OUTMASK_REG(FTM2_BASE_PTR)
#define FTM2_COMBINE                             FTM_COMBINE_REG(FTM2_BASE_PTR)
#define FTM2_DEADTIME                            FTM_DEADTIME_REG(FTM2_BASE_PTR)
#define FTM2_EXTTRIG                             FTM_EXTTRIG_REG(FTM2_BASE_PTR)
#define FTM2_POL                                 FTM_POL_REG(FTM2_BASE_PTR)
#define FTM2_FMS                                 FTM_FMS_REG(FTM2_BASE_PTR)
#define FTM2_FILTER                              FTM_FILTER_REG(FTM2_BASE_PTR)
#define FTM2_FLTCTRL                             FTM_FLTCTRL_REG(FTM2_BASE_PTR)
#define FTM2_QDCTRL                              FTM_QDCTRL_REG(FTM2_BASE_PTR)
#define FTM2_CONF                                FTM_CONF_REG(FTM2_BASE_PTR)
#define FTM2_FLTPOL                              FTM_FLTPOL_REG(FTM2_BASE_PTR)
#define FTM2_SYNCONF                             FTM_SYNCONF_REG(FTM2_BASE_PTR)
#define FTM2_INVCTRL                             FTM_INVCTRL_REG(FTM2_BASE_PTR)
#define FTM2_SWOCTRL                             FTM_SWOCTRL_REG(FTM2_BASE_PTR)
#define FTM2_PWMLOAD                             FTM_PWMLOAD_REG(FTM2_BASE_PTR)

/* FTM - Register array accessors */
#define FTM0_CnSC(index)                         FTM_CnSC_REG(FTM0_BASE_PTR,index)
#define FTM1_CnSC(index)                         FTM_CnSC_REG(FTM1_BASE_PTR,index)
#define FTM2_CnSC(index)                         FTM_CnSC_REG(FTM2_BASE_PTR,index)
#define FTM0_CnV(index)                          FTM_CnV_REG(FTM0_BASE_PTR,index)
#define FTM1_CnV(index)                          FTM_CnV_REG(FTM1_BASE_PTR,index)
#define FTM2_CnV(index)                          FTM_CnV_REG(FTM2_BASE_PTR,index)

/**
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FTM_Peripheral */


/* ----------------------------------------------------------------------------
   -- GPIO
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Peripheral GPIO
 * @{
 */

/** GPIO - Peripheral register structure */
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                   /**< Port Data Output Register, offset: 0x0 */
  uint32_t PSOR;                                   /**< Port Set Output Register, offset: 0x4 */
  uint32_t PCOR;                                   /**< Port Clear Output Register, offset: 0x8 */
  uint32_t PTOR;                                   /**< Port Toggle Output Register, offset: 0xC */
  uint32_t PDIR;                                   /**< Port Data Input Register, offset: 0x10 */
  uint32_t PDDR;                                   /**< Port Data Direction Register, offset: 0x14 */
} volatile *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register accessors */
#define GPIO_PDOR_REG(base)                      ((base)->PDOR)
#define GPIO_PSOR_REG(base)                      ((base)->PSOR)
#define GPIO_PCOR_REG(base)                      ((base)->PCOR)
#define GPIO_PTOR_REG(base)                      ((base)->PTOR)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_PDDR_REG(base)                      ((base)->PDDR)

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)

/**
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base pointer */
#define PTA_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF000u)
/** Peripheral PTB base pointer */
#define PTB_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF040u)
/** Peripheral PTC base pointer */
#define PTC_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF080u)
/** Peripheral PTD base pointer */
#define PTD_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF0C0u)
/** Peripheral PTE base pointer */
#define PTE_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF100u)
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* PTA */
#define GPIOA_PDOR                               GPIO_PDOR_REG(PTA_BASE_PTR)
#define GPIOA_PSOR                               GPIO_PSOR_REG(PTA_BASE_PTR)
#define GPIOA_PCOR                               GPIO_PCOR_REG(PTA_BASE_PTR)
#define GPIOA_PTOR                               GPIO_PTOR_REG(PTA_BASE_PTR)
#define GPIOA_PDIR                               GPIO_PDIR_REG(PTA_BASE_PTR)
#define GPIOA_PDDR                               GPIO_PDDR_REG(PTA_BASE_PTR)
/* PTB */
#define GPIOB_PDOR                               GPIO_PDOR_REG(PTB_BASE_PTR)
#define GPIOB_PSOR                               GPIO_PSOR_REG(PTB_BASE_PTR)
#define GPIOB_PCOR                               GPIO_PCOR_REG(PTB_BASE_PTR)
#define GPIOB_PTOR                               GPIO_PTOR_REG(PTB_BASE_PTR)
#define GPIOB_PDIR                               GPIO_PDIR_REG(PTB_BASE_PTR)
#define GPIOB_PDDR                               GPIO_PDDR_REG(PTB_BASE_PTR)
/* PTC */
#define GPIOC_PDOR                               GPIO_PDOR_REG(PTC_BASE_PTR)
#define GPIOC_PSOR                               GPIO_PSOR_REG(PTC_BASE_PTR)
#define GPIOC_PCOR                               GPIO_PCOR_REG(PTC_BASE_PTR)
#define GPIOC_PTOR                               GPIO_PTOR_REG(PTC_BASE_PTR)
#define GPIOC_PDIR                               GPIO_PDIR_REG(PTC_BASE_PTR)
#define GPIOC_PDDR                               GPIO_PDDR_REG(PTC_BASE_PTR)
/* PTD */
#define GPIOD_PDOR                               GPIO_PDOR_REG(PTD_BASE_PTR)
#define GPIOD_PSOR                               GPIO_PSOR_REG(PTD_BASE_PTR)
#define GPIOD_PCOR                               GPIO_PCOR_REG(PTD_BASE_PTR)
#define GPIOD_PTOR                               GPIO_PTOR_REG(PTD_BASE_PTR)
#define GPIOD_PDIR                               GPIO_PDIR_REG(PTD_BASE_PTR)
#define GPIOD_PDDR                               GPIO_PDDR_REG(PTD_BASE_PTR)
/* PTE */
#define GPIOE_PDOR                               GPIO_PDOR_REG(PTE_BASE_PTR)
#define GPIOE_PSOR                               GPIO_PSOR_REG(PTE_BASE_PTR)
#define GPIOE_PCOR                               GPIO_PCOR_REG(PTE_BASE_PTR)
#define GPIOE_PTOR                               GPIO_PTOR_REG(PTE_BASE_PTR)
#define GPIOE_PDIR                               GPIO_PDIR_REG(PTE_BASE_PTR)
#define GPIOE_PDDR                               GPIO_PDDR_REG(PTE_BASE_PTR)

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group GPIO_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Peripheral I2C
 * @{
 */

/** I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8_t A1;                                      /**< I2C Address Register 1, offset: 0x0 */
  uint8_t F;                                       /**< I2C Frequency Divider register, offset: 0x1 */
  uint8_t C1;                                      /**< I2C Control Register 1, offset: 0x2 */
  uint8_t S;                                       /**< I2C Status register, offset: 0x3 */
  uint8_t D;                                       /**< I2C Data I/O register, offset: 0x4 */
  uint8_t C2;                                      /**< I2C Control Register 2, offset: 0x5 */
  uint8_t FLT;                                     /**< I2C Programmable Input Glitch Filter register, offset: 0x6 */
  uint8_t RA;                                      /**< I2C Range Address register, offset: 0x7 */
  uint8_t SMB;                                     /**< I2C SMBus Control and Status register, offset: 0x8 */
  uint8_t A2;                                      /**< I2C Address Register 2, offset: 0x9 */
  uint8_t SLTH;                                    /**< I2C SCL Low Timeout Register High, offset: 0xA */
  uint8_t SLTL;                                    /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/**
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_DMAEN_MASK                        0x1u
#define I2C_C1_DMAEN_SHIFT                       0
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_HDRS_MASK                         0x20u
#define I2C_C2_HDRS_SHIFT                        5
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields *^G��q����q��8�p�b��dth �3��l"�V�$�a�CF`��=f�u=*)����JF��:s���1p�ΰ�ۃ�ya%Z#�� 
V\��x��y"�O�)XC��r.�BD�=v����#�/��8	��[ٓ�-�����)�����#�6�� ih�q��ݫw5'�n���B�j{Ft[��?)#�5�.B�|f��Z/݉}2�
��8�sj��Z{��D��i+ņ,�������HG�|!B�+���h�5S����Xݠ' ��X�o�xU�L]�~�}!�.�蛄y��/=����4�~�?�����5r�?�F�R%�� �d��Br�J�8���L�3���F���g��M�b/������~���yM��Vx��w`l�{������9S���E@6�qO��k%9ţ���A|3����[�6�S�}w�~T 3��=��&�aPߪ�FLӆ�ˁ���7"��6�=�29<ݴ�p����4j*�o]C����+��1h}?��	ync�p*��k}��c�w^
E5�Gb�~���pg-�|���	$��%j��'�#c��	�����/|��&����į�4k�;����K�[���{������
���E��P\8�w�zf`�E�-)W���9N���@��^*�xv������Y'\7��E0%���dZ�R0X�"���B�BsFM�XNm�f�|ŵB<����q������Q"�я�.8N3D��n
��I��ض��!Q
�rq���=�G�T���v]�PH��X�q\��B��� �w[0'?S{�ǘ<����Z��d�'�
���Y��
J�&od>B���V���c�i��Z�h	�}�)ԛM��Kxf�ɡ=����+?+a����C�����+�ܿ]_�]�ҹ�U4̝*X�浪;c:���"�N��P��ʟ�EC[W�V�β�'-��[�
W �:<��سv���!@�7=+���T��a-0��w���S�k���p��OI����M�X�|���l�s�b'"�����
�/ �we�Τag�z��4͂��jG�[�?��U�c�VEk6�t3��T�i"��/.�kn�F��04��ȋTz� ,���?�}2��F#ų�m"����j�ɷWz!;�(�?j��#�\�:�����o���`��lc/b�*�t��ʽ��QQ���`���"a��y[t���o����������"3����݈��h�zq�d[ԓb�b����g��^s�^�okׯR]h~�X_���K�%̔����]������^L l�:o�)�����)��Ikp~��A<�G����_8����zs@�a�͑4����A�CJw�;0SkLзG�/8L��Ì9��]&m,�r�܍T�ۜ����`)C�������-W�j}�����)<���#�l]+��e����=��h9�w8��ˢ3Q�?Ma�o�Q��"�\��E��x3�jd�Fv��.%H��*� �k|S��A<�P�z'h�0���8�����M���j��U�Uƅ��5��i�B�*3�cxb�v5��L�]���D4>;�m��HW&��%�Eg'[���󔾲�E���ڊ���ݲ���i�#��>T����7�j�t�Z�DO�c]����G}|.kW=ꠐ.���}[
�	a����l+C��p�>i8`c�~n��ɱ{>N�l�ѡ�+����dݎͽli+�h
��I��F�So �|���f�r�,?�y�Kw ���<G6����	V���˺_���zW6��c78לY�bDL�3~�3>V��KVrt�[��+�:����B���=ƒ���p��+�K��jpy�Q�d�,��6I�̯��i���|�-�̡��gL�/��o�
َ�ŎP�0��NB��x�#+3�����<RG����A��V��4B#�����ш�ap��=��[Y�Q�v3쩳���'�_�z
>L���s3��p̊�`;�<�~È.*�}�n9&~"�xQAV���
X�<4�?�Gm�eh16W��,f���5�s�x]�A��Z8X���1��0�����թ񂽃
ql�>������`Q�Tu�`�H�#��o�~�*?�j�Dk�e�I�}��Q�I!$$s0�(%jM��{�
�����%�4�ZW#x�_}j�UQLdHJkW��R����@��'�l�&��,}c{�I��B�#�j���9�J���kMGI�!��h~�K}e�`����s&���.͋(��%�b�!X�7B_�^X0�:�`����ĒȤ��<dx�&�R��(Oq$lҬ#Į��}�9�b���	�f�4�-�� ��1^��ƺ�I�_D��Z��ɖ��r@�i��H�o��֫��cYK�$�N���LTNɱSa��LV_eQ��f��/���P#����j+M9��^~�!*�Z���t���lU�d���
��Ժ�g������d�Sh}��p�CJ1��
4����NϞ����e�Y*��.-Lc���w��A�g8�ߵrZ�6��eiZ0~}O����a� �H�-���Kd��R^��!��%��ן�P��}2�˗>��N�n>&hMk֍W;�J�D�
�M�%����L'��y�!Pw�>!�Qj#;�d��P:sa�gZ12��1V���T�H��}ɖz���)�ȝ��i������S����d�~(5	5�!۵���W)Kŋ]_��:ǥo�7���/G�KW\��![²����D�{ŚWGVu�@z��*�c��}j�]=��c%�R"=��v��MM��ݥ�/�ڃe W��煚y��/�ގ���q���w��������g�� a�d��J�ɜ�)�F��������g[E@���ǉ��W�C�M��� ���Se�=��U�c�7+���	��xE.�\߶Z;MDmU�M�
�����������eh�B��x�%0��/]���9��6���`�l}�=�b�(��e{2>���(���<����Z_A�eS�q�h�K��2���z4�ؤ�BSl���r�NƬZ�}��q�� �L�Ƴj7.4��O�~���ٽ�O{j](k��g��D��*_�%>>V�8+�1�㍐�}���زx����Y=��	ce��<.~KN�0�Q�,O_}�on��3mP�����)��A�G��;�'\�Id��ϤV��<��o���/�(����J>AB+gv_Xe�e���_����V�2Ȼ�#���{ʽ,��E��[D�d��b�0�.����v�Wx`NV��7��i}<eg �m�U̯�/ +s���Ra�|8�g˚~�gP��.��13EY��&�dq<ٻ�'�S4Nf�fX�.�;Q�%�Ň�͞�;\���P���p�+֟��&?c��@;��ٶ`��Ol�ꓼ_�b���r|��=����]x�b}�������#�S�.���`�y�\���P=�I�~4�A^m�DҚA,�5��~�0���^������h�5��汔��
��N�Ϥߞ�\	i�y[�-��맹�����.��	PZ�ҶAQbx�R��_=�QBb�*��%T�Z���r���2��a��-y�x��1"lF��
5�I�ߔ�'�؜�-׊�;33�{����+��Bj��b�V�QE�8��s�'@s�/ܲ������-ȗ
0+Jb��O�d�~��b���b��/�N���T�I��M�Wsx��)%��gC[�+��˘���N�9�֟;�8Sa��(���@�z�O���*۔ y		9aC�Gl�d��˳c뭫�s��iRc�-�C~:���jc�w�QlÇ�t=��d�6<Z|���-2�������:z%�AkD���?-��B�R[� :����7�s`�A�iċ�tDU�/��\��Y遺I��d��	sb�`�X��e몛�_~W#�F���|�믒�.'��n.��S]�܈9|�j��>�a��؜���P=�^���{rt���	u���Xd;��g7G�`�H{9�g��`�.ine I2C1_S                                   I2C_S_REG(I2C1_BASE_PTR)
#define I2C1_D                                   I2C_D_REG(I2C1_BASE_PTR)
#define I2C1_C2                                  I2C_C2_REG(I2C1_BASE_PTR)
#define I2C1_FLT                                 I2C_FLT_REG(I2C1_BASE_PTR)
#define I2C1_RA                                  I2C_RA_REG(I2C1_BASE_PTR)
#define I2C1_SMB                                 I2C_SMB_REG(I2C1_BASE_PTR)
#define I2C1_A2                                  I2C_A2_REG(I2C1_BASE_PTR)
#define I2C1_SLTH                                I2C_SLTH_REG(I2C1_BASE_PTR)
#define I2C1_SLTL                                I2C_SLTL_REG(I2C1_BASE_PTR)

/**
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2S
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Peripheral I2S
 * @{
 */

/** I2S - Peripheral register structure */
typedef struct I2S_MemMap {
  uint32_t TCSR;                                   /**< SAI Transmit Control Register, offset: 0x0 */
  uint32_t TCR1;                                   /**< SAI Transmit Configuration 1 Register, offset: 0x4 */
  uint32_t TCR2;                                   /**< SAI Transmit Configuration 2 Register, offset: 0x8 */
  uint32_t TCR3;                                   /**< SAI Transmit Configuration 3 Register, offset: 0xC */
  uint32_t TCR4;                                   /**< SAI Transmit Configuration 4 Register, offset: 0x10 */
  uint32_t TCR5;                                   /**< SAI Transmit Configuration 5 Register, offset: 0x14 */
  uint8_t RESERVED_0[8];
  uint32_t TDR[2];                                 /**< SAI Transmit Data Register, array offset: 0x20, array step: 0x4 */
  uint8_t RESERVED_1[24];
  uint32_t TFR[2];                                 /**< SAI Transmit FIFO Register, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_2[24];
  uint32_t TMR;                                    /**< SAI Transmit Mask Register, offset: 0x60 */
  uint8_t RESERVED_3[28];
  uint32_t RCSR;                                   /**< SAI Receive Control Register, offset: 0x80 */
  uint32_t RCR1;                                   /**< SAI Receive Configuration 1 Register, offset: 0x84 */
  uint32_t RCR2;                                   /**< SAI Receive Configuration 2 Register, offset: 0x88 */
  uint32_t RCR3;                                   /**< SAI Receive Configuration 3 Register, offset: 0x8C */
  uint32_t RCR4;                                   /**< SAI Receive Configuration 4 Register, offset: 0x90 */
  uint32_t RCR5;                                   /**< SAI Receive Configuration 5 Register, offset: 0x94 */
  uint8_t RESERVED_4[8];
  uint32_t RDR[2];                                 /**< SAI Receive Data Register, array offset: 0xA0, array step: 0x4 */
  uint8_t RESERVED_5[24];
  uint32_t RFR[2];                                 /**< SAI Receive FIFO Register, array offset: 0xC0, array step: 0x4 */
  uint8_t RESERVED_6[24];
  uint32_t RMR;                                    /**< SAI Receive Mask Register, offset: 0xE0 */
  uint8_t RESERVED_7[28];
  uint32_t MCR;                                    /**< SAI MCLK Control Register, offset: 0x100 */
  uint32_t MDR;                                    /**< SAI MCLK Divide Register, offset: 0x104 */
} volatile *I2S_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register accessors */
#define I2S_TCSR_REG(base)                       ((base)->TCSR)
#define I2S_TCR1_REG(base)                       ((base)->TCR1)
#define I2S_TCR2_REG(base)                       ((base)->TCX3)
#define I2S_TCR3_REG(base)� $     "              ((base)-6TCR3)
#define I2S[TCR4_REG(fase)                       ((base)->TCR4)
#define I"S_DCR5_REG(base)                       (base)->TCR5)
#define I2S_TD_REG(base,index)           "      *(base)->TDR[index])
#defi.e I2S_TR_REG(jase,index) "                ((base)->TFR[index])
#defI~e I2S_TMR_REG(base)                        ((base)->TMR)
#degine I2S_RCsR_REG(base)!               "  �   ((base)->RCSr)
#define I2S_RCR1_REG(base)                       ((base)->RCR5)
3dedile I2S_RCR2_REG(base)                       ((base)->RCR2)
#define M2S_RCR3_REG(base)    (                  ((base)->RCR3)
#define I2S_RCR4_REG(base)      0      "       " ("base)->RCR4)
#define I2S_RCR5^REG(ba3e)                `      )(base)->RCR5)
#define I2S_RDR_REG(base,index	                  ((base)->RDR[)ndex])
#define I6S_RR_REG(base,hndex)                 ((basu)->RFR[index])
#define I2S_RMR_REG(base)    !            $      ((base)->RMR)
#define I2S[MCR_REE(base)                      0 ((base)->MCR)
#define I2S_MDR_REG(base)                        ((base)->MDR)
/**
 *�@}
 *. /" end of oroup`I2S_Register_Accessor_Mqcros *+
�

/* ------------------------------)-------%-------------------------------------
   -- I2S Register Masks
   ---------/----------------------m-----------,--------/---------------=------ */

/**
 * @addtogroup I2S[Register_Mqsks I2S Register MaskrJ * @{
 ./

/* TCSR Bit Fields */
#define I2S_TCSR_F�DE_MASK                 �     0x1U
#defije I2S_TCSR_FRDE_SHIFT   "          "       0-
#define I2S_TCSR_�WDE_MASK     "                 0�2u
#`efine I2S]TC[R_FWDE_SIFT`                  �  1
#define I2S_TCSP_FRIE_MASK                `      0x100u
#dEfine I2S_TCCR_FRIE_SHIFT            (         8
#define I2S_TCSR_FWIE_MASK                      (0p280u
+define I2S_TCSR_FWIE_SHIFT                      y
#define I2S_TCSR_FEIE_MASK        $              1x400u
#define I2S_TCSR_FEIE_SHIFT     0  #             10
#define I2S_TCSR_SEIE_MASK                       0x800u
#define I2S_TCSR_SEIE_SHIFT                      11
#define I2S_TCSR_WSIE_MASK                       0x1000u
#define I2S_TCSR_WSIE_SHIFT                      12
#define I2S_TCSR_FRF_MASK                        0x10000u
#define I2S_TCSR_FRF_SHIFT                       16
#define I2S_TCSR_FWF_MASK                        0x20000u
#define I2S_TCSR_FWF_SHIFT                       17
#define I2S_TCSR_FEF_MASK                        0x40000u
#define I2S_TCSR_FEF_SHIFT                       18
#define I2S_TCSR_SEF_MASK                        0x80000u
#define I2S_TCSR_SEF_SHIFT                       19
#define I2S_TCSR_WSF_MASK                        0x100000u
#define I2S_TCSR_WSF_SHIFT                       20
#define I2S_TCSR_SR_MASK                         0x1000000u
#define I2S_TCSR_SR_SHIFT                        24
#define I2S_TCSR_FR_MASK                         0x2000000u
#define I2S_TCSR_FR_SHIFT                        25
#define I2S_TCSR_BCE_MASK                        0x10000000u
#define I2S_TCSR_BCE_SHIFT                       28
#define I2S_TCSR_DBGE_MASK                       0x20000000u
#define I2S_TCSR_DBGE_SHIFT                      29
#define I2S_TCSR_STOPE_MASK                      0x40000000u
#define I2S_TCSR_STOPE_SHIFT                     30
#define I2S_TCSR_TE_MASK                         0x80000000u
#define I2S_TCSR_TE_SHIFT                        31
/* TCR1 Bit Fields */
#define I2S_TCR1_TFW_MASK                        0x7u
#define I2S_TCR1_TFW_SHIFT                       0
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK)
/* TCR2 Bit Fields */
#define I2S_TCR2_DIV_MASK                        0xFFu
#define I2S_TCR2_DIV_SHIFT                       0
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK)
#define I2S_TCR2_BCD_MASK                        0x1000000u
#define I2S_TCR2_BCD_SHIFT                       24
#define I2S_TCR2_BCP_MASK                        0x2000000u
#define I2S_TCR2_BCP_SHIFT                       25
#define I2S_TCR2_MSEL_MASK                       0xC000000u
#define I2S_TCR2_MSEL_SHIFT                      26
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK)
#define I2S_TCR2_BCI_MASK                        0x10000000u
#define I2S_TCR2_BCI_SHIFT                       28
#define I2S_TCR2_BCS_MASK                        0x20000000u
#define I2S_TCR2_BCS_SHIFT                       29
#define I2S_TCR2_SYNC_MASK                       0xC0000000u
#define I2S_TCR2_SYNC_SHIFT                      30
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK)
/* TCR3 Bit Fields */
#define I2S_TCR3_WDFL_MASK                       0x1Fu
#define I2S_TCR3_WDFL_SHIFT                      0
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK)
#define I2S_TCR3_TCE_MASK                        0x30000u
#define I2S_TCR3_TCE_SHIFT                       16
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_TCE_SHIFT))&I2S_TCR3_TCE_MASK)
/* TCR4 Bit Fields */
#define I2S_TCR4_FSD_MASK                        0x1u
#define I2S_TCR4_FSD_SHIFT                       0
#define I2S_TCR4_FSP_MASK                        0x2u
#define I2S_TCR4_FSP_SHIFT                       1
#define I2S_TCR4_FSE_MASK                        0x8u
#define I2S_TCR4_FSE_SHIFT                       3
#define I2S_TCR4_MF_MASK                         0x10u
#define I2S_TCR4_MF_SHIFT                        4
#define I2S_TCR4_SYWD_MASK                       0x1F00u
#define I2S_TCR4_SYWD_SHIFT                      8
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK)
#define I2S_TCR4_FRSZ_MASK                       0x1F0000u
#define I2S_TCR4_FRSZ_SHIFT                      16
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK)
/* TCR5 Bit Fields */
#define I2S_TCR5_FBT_MASK                        0x1F00u
#define I2S_TCR5_FBT_SHIFT                       8
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK)
#define I2S_TCR5_W0W_MASK                        0x1F0000u
#define I2S_TCR5_W0W_SHIFT                       16
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK)
#define I2S_TCR5_WNW_MASK                        0x1F000000u
#define I2S_TCR5_WNW_SHIFT                       24
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK)
/* TDR Bit Fields */
#define I2S_TDR_TDR_MASK                         0xFFFFFFFFu
#define I2S_TDR_TDR_SHIFT                        0
#define I2R_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&�2S_TDR_TDR_MASK)
/* TFR Bmt Fields */
#define I2S_TFZ_RFP_MASK          "  0        0  0xFu
#define I2S_TFR_RFP_SHIFT               !        0
#defI.e I2S_TFRWRVP(x)                   �       (((tint32_t)((uiot3�_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK          !           "  0xF0000u
#defIne I2S_TFR_WFP_SHIFT    $               �   16
#define I2S_T�R_WFP(x) "                         (((uinv32_t)(((uint32_t)(x)),<I2S_TFR_WFp_SIIFT()&I2SOTFR_WFP_MASki
/* TMR Bat FIelds "/
#def)ne I2S_TMR_TWM_MAS�                         0xFFFFFFFFu
#define I2S_TMR_TWM_SHIFT               0 �      0
#define I2S_TMR_TWM(x)                `          (((uint32_t)(*(uint32_t)(x))<<I2S_TMR_TWM_SIIFT))&I2S_TMR_TWM_MASK)
/* RCSR Bit Fields */
#define I2S_RCSR_FRDE_MASK                      �0x1u
#define I2S_RCSr_FRDE_HIFT                   "  0
#defi.e I2S_RCSR_FWDE_MASK                       0x2u
#define I2S_RCSR_FWDE_SHIFT                      1
#define I2S_RCSR_FRIE_MASK                       0x100u
#define I2S_RCSR_FRIE_SHIFT                      8
#define I2S_RCSR_FWIE_MASK                       0x200u
#define I2S_RCSR_FWIE_SHIFT                      9
#define I2S_RCSR_FEIE_MASK                       0x400u
#define I2S_RCSR_FEIE_SHIFT                      10
#define I2S_RCSR_SEIE_MASK                       0x800u
#define I2S_RCSR_SEIE_SHIFT                      11
#define I2S_RCSR_WSIE_MASK                       0x1000u
#define I2S_RCSR_WSIE_SHIFT                      12
#define I2S_RCSR_FRF_MASK                        0x10000u
#define I2S_RCSR_FRF_SHIFT                       16
#define I2S_RCSR_FWF_MASK                        0x20000u
#define I2S_RCSR_FWF_SHIFT                       17
#define I2S_RCSR_FEF_MASK                        0x40000u
#define I2S_RCSR_FEF_SHIFT                       18
#define I2S_RCSR_SEF_MASK                        �lХ�[u"��"d#F�/މ��䒗Z-�%�-1�GHϯ(Z'3� �O�3�N|��
7-]�b����r��ӎ��� �Њ��j�̊V�E��f``r�N63
hoX��}fG���r~�S��rҍU�L�N�F-���Ii��v��Խ�Qɤy��?��5}�%/���j[9X9Fqqގ�&�"
ese���+�YU��ڦ�<0��G��&�7�hW�gquY�'�zs�8�E�R���e#��ͬ�`��N��U�う��ޙ�G������$���-?�>�VS��x9~���Z���m���A[A����H4�.&�@Րh���??��΋yW�i�'*k��T���d-YnD�,̺����h{ ~0%S(�ͅ�w�� Wi`���� �h	��L���sў:$�J�^���Tl���:����>�����Z�Lӄ��hRGi��Z�:���M�~JDS�`|:�����#D�s{ZZ�$�*�2a/�9m2��5ɇp�%QK�t<\�?��䪦J̍���N�*�6�f{�ӏ@YI�s[�,UR#�G��<��>ope�-��鯶�'������Gh�T&�a⮲�sk|�B�{ol!���q��tP�=�u�.S���Yuۨ�ψ=(�5�����J�[�̳�8ۇ��X�G�N�8�τ����BU=_��]t#a8 00�vl;� V��	e}0��� ���N��)� �5հ;T(��C�u��W9� �;��n��BM+�+H�MU���i'!��+�|6l�ю�mć�"�M��؎
��&�V������ ����Iʔ˕��w� � T�H!��[��7΁q?��A�Z�둽�=9@
��C7a�5#��M]��ͩ&�/�W	��y� 6�[G��rܚMڪ �@鈒:�% ���5��kk&oT�h�����,�gM��yp[�:��*��CT�9��s�1�
E��}��LVj>�:����f�q~;(:��e��ɩ�h֣����A��'�l�O�:l�KJ!\bŀ�r_�ڞwuKT#j��(U䷜ l�	8�=N�X���r׆���bڌī�]�F����V��X``�T�P�AC�##<���j�E�V�O��^'2���Yy�b	��Ι��&e��
�Y��]#�r�����.6��xaAA�
I�����[�OM~H#���m<���`т�*���w8э�ːX(sW���J�����j:K�)L]b��E�k���t2�������8��
�#s3�SB�_��L���L�P�aO��=�b�g��g�� 0ml]����Wƴ���F�t��R�?�:��.����������l5	4s$wKG�Yy�kj�g9o� ��D_n��#�2��UQ�����o��ʄ:_���!
^�t@�Ɣ�3�.1_z�4���L.Uv�8��I��q�BH�O�n3~�k�bQ���rҒ����G���i�iJQ�(.HB���lp"1�?��ե B�=�n�`ݡ��o�
���Y��1�[=;���uF���	_75�ݞ�Dӻ) o���R}	$�Ӷ%ΉB� y�!�&Z
��q�]�v|�t�=a��x�C����x�<�y��+�]�zQ�e`�>3Q
�BV�}�5G�=�`޺D���2�����X�pl;�w��;LS�-���ד�'��:g͈ԑpE���f����Z��&obd�V�l���氈r {�W5����҆f�!t_[a��ꊋ��|�G�.�F��2Mv}��H�t�azd��%��R���*x���wJ0j�{��K���ϖs1׳��yJ�։Y�T}K`J�F	��#o�07��i�;cc��ϣ�-9�-�C]_wǁ�:Mըղ-��w7�D(q���w8_�Мi>(JKG����vq�����_*D���t֝*h$�sX�J'�1:��j�+abh,0u����y� �1<�:X���X��U.2�:�5������i�I.W_`�_��ڔ�+E�*Ǡ�1��v�:�6�(͹3͒*3׎��R߁|
��x�ٻp�/?����S��W���]�6���>W;E]j���40��x�r�����e[V��ۺ�B'd��$TU
�>]�G�������ӅL��k�0�T� D��ޗ_
ŁnP�AI���H+$��HKD/�`!yޅ45$��,TS���a@)�n�C G>��7K`5����R=D�nr�riq@��#����QB��<)-�F��i�1���q�U��w�}LsJ�g$���o������!0|�Ad�K��i�Xp���5 ��;th���8B�� �����X�� ��,j��e�u�`��/���%�e7�-@
$ ��t�'7�IV���d���!�_!P�?�(B�YJ��9���Ar��g���g��WJ�x$�.�v,�b-� x�(�]~���T�xx��ȩ��E�y�a<�c��.�rP*�6�w��r$�*�IR8��7$`��H�׽&-����`29���u��J�Ь���ה��3'ω����r���0ތ��q��朤�a:7cSEb���+:���r�!꺈G�ҩX��kj����t�mJ�_�h�I����?ϰU!~Q)�r���ؘ�a�J�������r�x��f"��?������&���)9���,2^���h�C�
?���7����p�'���+*	��⹶�h��R�`��T(7ޱ��q�6�]Yk�CQXRh/��0�x�4��6�*T���O�7IK��8ʆ�/�S��e@�Y"�b�"m`ʵ�v�h�%5p���������+YJ
�~��8��2��m���k����|��5�� �[�4W	"���![\�Qn�Oa�e�L���̍�R���=��
M�)��?@��MN_�6V�}-<F�"�X)��ѭ�@BA����rL��J�'���� ����̹��*@@`�v|�)]��u_���n�γ�{˦ ���S�s�]�p��
#define I2S_RCR4_FSE_SHIFT                       3
#define I2S_RCR4_MF_MASK                         0x10u
#define I2S_RCR4_MF_SHIFT                        4
#define I2S_RCR4_SYWD_MASK                       0x1F00u
#define I2S_RCR4_SYWD_SHIFT                      8
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK)
#define I2S_RCR4_FRSZ_MASK                       0x1F0000u
#define I2S_RCR4_FRSZ_SHIFT                      16
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK)
/* RCR5 Bit Fields */
#define I2S_RCR5_FBT_MASK                        0x1F00u
#define I2S_RCR5_FBT_SHIFT                       8
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK)
#define I2S_RCR5_W0W_MASK                        0x1F0000u
#define I2S_RCR5_W0W_SHIFT                       16
#define I2S_RCR5_W0W(x)       �lХ�[u"��"d#F�/މ��䒗Z-�%�-1�GHϯ(Z'3� �O�3�N|��
7-]�b����r��ӎ��� �Њ��j�̊V�E��f``r�N63
hoX��}fG���r~�S��rҍU�L�N�F-���Ii��v��Խ�Qɤy��?��5}�%/���j[9X9Fqqގ�&�"
ese���+�YU��ڦ�<0��G��&�7�hW�gquY�'�zs�8�E�R���e#��ͬ�`��N��U�う��ޙ�G������$���-?�>�VS��x9~���Z���m���A[A����H4�.&�@Րh���??��΋yW�i�'*k��T���d-YnD�,̺����h{ ~0%S(�ͅ�w�� Wi`���� �h	��L���sў:$�J�^���Tl���:����>�����Z�Lӄ��hRGi��Z�:���M�~JDS�`|:�����#D�s{ZZ�$�*�2a/�9m2��5ɇp�%QK�t<\�?��䪦J̍���N�*�6�f{�ӏ@YI�s[�,UR#�G��<��>ope�-��鯶�'������Gh�T&�a⮲�sk|�B�{ol!���q��tP�=�u�.S���Yuۨ�ψ=(�5�����J�[�̳�8ۇ��X�G�N�8�τ����BU=_��]t#a8 00�vl;� V��	e}0��� ���N��)� �5հ;T(��C�u��W9� �;��n��BM+�+H�MU���i'!��+�|6l�ю�mć�"�M��؎
��&�V������ ����Iʔ˕��w� � T�H!��[��7΁q?��A�Z�둽�=9@
��C7a�5#��M]��ͩ&�/�W	��y� 6�[G��rܚMڪ �@鈒:�% ���5��kk&oT�h�����,�gM��yp[�:��*��CT�9��s�1�
E��}��LVj>�:����f�q~;(:��e��ɩ�h֣���N���T�}�n�Ī	�k��T�YjvG�vP'�p�N0�s��PJI
t����bЎg�er�au��Ex*�N���Vr�*���˞Bj9�ɸ�\�R��i3��]�~���j��8��$�n!�?�'tӄ ,t���Y�b�aevh�PW�x^�� =�I@j��I��>tNP�<�?�br��a7KM�O�O��G�$�DN5±���������V����;�����v�tw#�-����:pR��!�˪{E����;�s#g+���c�<�L��N���c���&mUYE�F�7lk�6�(/	o�̹�I�q�0�/0t!����zO!�Z8���'z]�SM]~=�GA̙��Bwg��{�f�!?�F7�t� ��ƌ�mQ%�M��xYh�Z�f�Гb���]m��+�߀��Ƴ���`#J qX|!�pY��
��5��ۧJ��۩_��༇���B�eF`�����e����}�A���=�������2��0~�>�xc�f����R]Vv$䋦y&�HZu=�-a^���S-^��,����4$��R��,���3$K�cF�~D]@f\��2�V�x8O�i^A�\�N���4�?�i�׃�����o#��|q��l�۷�bCY��;_��d˂�C��h��(E2��%�F��S��XmD{�e��d\+�1Hl������]dɃ�$�D/rknՃ�!�������������q�!(�x^�_�C�1�J<#���x���>�p���bp���2]�I���͉ϲ�ۚGyQh�G����.����Q&���������h������A]��}����0u���wA�`�,�M����������40� b�㰤���-c�(�%�hgD�_/�·��ĵ,�Ί�Q�)#x�rgB� I�=2�6�8:� ���a B`O�}̒1�Dwa�}�KC����I��h�:R���j�h"�8~E024�����?-pEʡkY�E���{��;�6���Mm�����&�`�U��wW��H�|��ėc�I]GFE��`A>s �C���@4�`���
��Z��|ά�����p�bw���^'c�!�Y��e�؅�Z�����o���C*��JI�&o�o�$�Os�R���y�U<ܭ�.�`F�Tb�����2ހ+�L�E6�<��7/W.��%�劉S �$���8!jnXi[���>���=��I��D�o?��V
�D�������oe��5m���K+�Оq��-n7�K�����4��Ay���R�\�A���0X-�A�dk0�@��[�n�:j,��_�>`�hbm��h�u*��+F�s}J�j�>�d����TM�����>�(V�<s��+R��e4��e�j��r���U��B ����#?k �w�'K�0�R@`-wT�$ݩ|����?����A��X�Ԧ6�7�ܮ�L��zH�G���5��~����)2��ժ"$�=C6V�\�yu�D]���'�i�0ƌO!�LXW�9-�0�Bo$��ׯr���u/�KE ��QHVaqⓔnZ�����T�=�=Ijdd��%X��eg.���J�#��5�M�q+���U�9��9��� \���#�L�� ���I�,Y�noC�x�>$*�[��h:�s)���T�;;9� M�G Vʇ����w�Ӭ%�Y����Cym��b_W&�f"�i���� 5K}qN�i�N��k�ݡ�d�#")+m��t�B3�i:����嗲[#9llV A��q�tw�ka�:'OEb��ٹ'!:������p:d��'��7��K����5Q^H�#�89�p(�ul�-$�a%BJ��鹊��~P~��]�vMZ,�wf�ң��d������f�bϩ�����6�:>�R� �V _�p�y]6�oR�iR��~26�!LזK�i~�&�~�X�����ԒY�Ͳ��4&�՟�\��U9ʥi���7��jBZ��EvHwz�U��x��y�� ��a��2�}�"_N1�R&��Q�J�pXZ=�L(~s�HA�[
#dufine I2S0_TC�9                 0             0I2S_TCR1_REG(I2S�_bASE_PTR)
#define I2S0_TCR2                                I2S_TCR2_REG(A2S0_BASE_PTR)
#define I2S0_TCR3                                I2S_�CR_REG(I3S0_B�SE_PTR)
#define I2S0_TCR4       `                        I2[_TCR4_REG(I2S0_BASE_PTR)
#define I2S0_TC�5 `                      0       I6S_TCR5REG(I2W0_BASE_PTR)
#define I2S0_DR0    $                        0  I2S_TDR_REG(i2S0_BASE_PTR,0)
#define I2S0_TDR1             "                  I2S_TDR_REG(I2S0_BASE_PTP,1i
#define I2S0[TFR0   �            $ 0   !         I2S_TFR_REG(I2S0_BASE_PTR,0)
#define I2S0_TFR1                                I2S_TFR_REG(I2S0_BA�E_TT�,1)
#define I2S0_TMR                                 I2S_TMR_REG(I2S0_BASA_PTS)
#define I2S0_RCSR                          4    $I2S_VCSR_ReG(I2S0]BASE_PTR)
#fefine I2C0_RCR1"    `                          I2S�RCR1_REG(I2S0_BASE_pTR)
+define I2S0_RCR2                  "        !    I2S_RCR2_R%G(I2S1_BASE_PTR)
#defije �2S0_RCr3     $!   �    "                K2S_RCR�_REG(Y2S0_@ASE_PTR)
#defkne I2S_RCR4      �                         K2S_RCR4REG(I2�_BACE_PTR)
#define I2S0_RCR5                                I2S_RCR5_REG(I2S0_@ASE_pTR)
#define I20_RDR0             �       (          I2S_RDR_REG(I2S0_BASE_@TS,0)
#define I2S0_VDR1              $              0  I2S_RDR_REG(I2S0_BASE_PTR,5+
#define I2S0_RVR0                                I�S_RFR_REG(I2S0_BASE_PT�,0)
#defin� I2S0_RFR1       �    �   $    " (        I2SRFR_REG(I2S0^BASE_PTR,1)
#define I2S0_RM                             0   I2S_RMRWREG(I2S1_BASE_PTRi
#eefine I2S0_MCR   !0                            I2S_MCR_REG(I2S0_BASE_TTR)
#define I2S0_MDR           $      0              I2S_MDR_REG(I2S0_BACE_PPV)

/* I2S - Register arrmy accessors ./
#define I2S0_TDR(index)                "         I2S_TDR_RUG(I2S0_BASE_TTR,indux)
#define I2S0_TFR(ivdex)       $ 0  0             I2C_TFR_REG(i2S0_BASE_PTR,index)
#define(I2S0_RD(inDex)  "          !        !   I2S_RDR_REG(I2S0_BASE_PTR,indep)
#define I2S0_RfR(index)          `     !$        I2S_RFR_REG(H2S0_BASE_PTR,hndeh)

/**
 * @}
 */ -*0end of group I2S_�egkster_Accessor_Macros */


/**
 * @}
 */ /* end of groux I2S_Permpheral */

/* ------------------------------�-----------/---------------------------------
   -- ITM
$  ---------------------------------------------------------------------------- */

/**
 * @addTogroup ITM_Xerirheral ITL
 * @{ */

/** ITM -�Peripheral register structure */
type`ef struct ITM_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t �TIM_READ[32];         0                /**< Stimulus Port Register 0 (for reading)/.Stimtlus Port Register�31  for reading), array offset2 0x0, array steP: 0X4 */
   $�)nt32_t STIM_WRITE[32];                   �  "  /**< Spimulus Port RegiSter 0 (fr writing)..Stamulus!Port Register �1 (for writing), array offset: 0x0, arzay step: 0x4 (/
$ };
  uint8_t RESERVED_0[3456];
  uint32_t TER;                     !   ,   $      /**< Tracm Enable Register, offset: 0yE00 */
  uint8_t RESERVDD_1[60];
� uint32_t TPR;  "  (                       �      /**<�Trace Privilege Register, offset: 0xE40 */
  uint8_t ESERFED]2[6 ];
  uint32_t TCR;"              !          0  `      /**< Trace0Control Register, offset: 0xE80 */
  uint8_t RESERVED_3[300]; �uint32^t LAR;                               (    /**< Lock Accecs RegisTer, offset: 08FB0 */
  uint32^t LSR;                                    /**< Lock Status Register, offset: 0xFB4 j/
  uint8_t RESERVED_4[24];
  uint32_t PIT4;                         !         /**< Perhpheral Adentification Register 4., offset: 0xFD0 */
  uint32�t�PID5;       0      �         0!   �!    +"*< eripheral Identification Register 5., offse|: 0xFD4 */
 0u)nt32_t PID6;             $  �  �(              /**< P�ripheral Identification RegisteR 6., offset: 0xFD8 ./
  uint32_t PID7;                                $  /**<$Peripheral0Identification Register 7., offset: 0xFDC �/
  uint32_4 PID0;                                   /.*< Peripheral Iddntificatioj Reghster 0.< offset: 0xFE0 */	
  uint32_t PID1; (       (                         /**<(Pesipheral Identification RegisTev 0., offset: 0xFE4 */
  uint32_t PID2;                  !`        �   "  /**< Peripher!l Identification Register 2., offset: 0xFE8 */
" uint32_t PID3;    0                        �     /**< PesipheraL Identificataon Register 3., offset: 0xFEC */
  uint32_t CID0; !                "                /**< Compondnt Itentification Register 0., offset: 0yFF0 */
  uint32Wu CID1;                          "   �    /**< Compo�ent Identification Register 1>, oFfset: 0xFF4 */
  uind32_t CID2;                   (  0            /**< Component Idejtification R�gister 2., offset: 0xFF8 */
" uiot32_t CID3;            "        �         0   /**< Component Identification Register 3., onfset: 0�DFC */
} vola�ile �ITMWMemMapPtr;

/* ----------------------------------------------------)----------------------�
   -- ITM - Registe2 accessor macros
   ---------------------------------------------------.m----------=-------//--m */

/*** * @addtogzour ITM_Registar_Acces�or_Macros ITM - Begister accessor macrosJ * @{
 */


/* ITM - Register accessors */
#define ITM^STIM_READ_REG(base,index2)           ((base)->STIM_REAd[index2])
#dafine ITM_STIM_WRITE_REG(base,index2)          ((base)-?STIM_WRITE[index2])
#define ITM_TER_REW(b!se)                        (hbase)->TER)
#define ITMOTPR_REG(base)         )              ((base)->TPR)
+define ITM_TCR_ReG(bes%)  `!          (         ((base)->TCR)
#`efine ITM_LAR_REG(base)          !             ((base)->MAR)#define"ITM_LSR_REG(base)    !                   ((bese)->LSR)
#define ITM_PID4_REGhbase)       `     �         ((b�se)-~PID4)
#define ITM_PID5_REG(base)  !                    ((base)-<PID5)
#defin% YTM_PID6_REG)base)        0     0       0((base)->PID6)	
#define IDM_PID7_REG(base)                   !  0((base)->PID7)
#define ITM_P	D0_REG(base)$                      ((base)-<PID0)�
#define ITM_PID1_REG(ba3e) `   `              0  ((base)->PID1)
#debiNe ITM_PID2_REG(base9                       ((base)->pID2)
#define ITM_PID3_REG(bas%)                   �   ((base)->PID3)
�define ITM_CID0_REG(basa)      (   "            ((basm)->BID0)
#define ITM_CID1_REG(jase)   !     0       !  !   (base)->CID1)
#define ITM_CID2_REG(B�se!                       ((ba{e)-6CID2)
#define ITM_KID3_REG(base)      !             (   base)->CID3)

/�*
 * @}
 */ /* e.d of group ITM_egiqter_Accessor_Macros */


/*"--m-/-----------------------------�-----------------------------------------
   -- ITM Register Masks
   ----=-----------------------------m---------------,---------------------=--- */*/**
 *0@addtogrou� ITM_Registc2_Masks ITM Register Masjs
 * @{
 */


/**
 * @} */ /* end of crour ITM_Register_Masks */
�
/* ITM - Peripheral instance base addresses */
/** Peripheral ITM base pointer */
#defing ITM_BASE_PTR          0   !              ((ITM_MemMapPtr)0xE0000000u)
/** Array initializer of ITM peripheral base pointers */
#define ITM_BASE_PTRS                            { ITM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register instance definitions */
/* ITM */
#define ITM_STIM0_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,0)
#define ITM_STIM0_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,0)
#define ITM_STIM1_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,1)
#define ITM_STIM1_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,1)
#define ITM_STIM2_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,2)
#define ITM_STIM2_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,2)
#define ITM_STIM3_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,3)
#define ITM_STIM3_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,3)
#define ITM_STIM4_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,4)
#define ITM_STIM4_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,4)
#define ITM_STIM5_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,5)
#define ITM_STIM5_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,5)
#define ITM_STIM6_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,6)
#define ITM_STIM6_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,6)
#define ITM_STIM7_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,7)
#define ITM_STIM7_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,7)
#define ITM_STIM8_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,8)
#define ITM_STIM8_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,8)
#define ITM_STIM9_READ                           ITM_STIM_READ_REG(ITM_BASE_PTR,9)
#define ITM_STIM9_WRITE                          ITM_STIM_WRITE_REG(ITM_BASE_PTR,9)
#define ITM_STIM10_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,10)
#define ITM_STIM10_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,10)
#define ITM_STIM11_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,11)
#define ITM_STIM11_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,11)
#define ITM_STIM12_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,12)
#define ITM_STIM12_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,12)
#define ITM_STIM13_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,13)
#define ITM_STIM13_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,13)
#define ITM_STIM14_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,14)
#define ITM_STIM14_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,14)
#define ITM_STIM15_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,15)
#define ITM_STIM15_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,15)
#define ITM_STIM16_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,16)
#define ITM_STIM16_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,16)
#define ITM_STIM17_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,17)
#define ITM_STIM17_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,17)
#define ITM_STIM18_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,18)
#define ITM_STIM18_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,18)
#define ITM_STIM19_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,19)
#define ITM_STIM19_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,19)
#define ITM_STIM20_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,20)
#define ITM_STIM20_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,20)
#define ITM_STIM21_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,21)
#define ITM_STIM21_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,21)
#define ITM_STIM22_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,22)
#define ITM_STIM22_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,22)
#define ITM_STIM23_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,23)
#define ITM_STIM23_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,23)
#define ITM_STIM24_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,24)
#define ITM_STIM24_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,24)
#define ITM_STIM25_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,25)
#define ITM_STIM25_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,25)
#define ITM_STIM26_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,26)
#define ITM_STIM26_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,26)
#define ITM_STIM27_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,27)
#define ITM_STIM27_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,27)
#define ITM_STIM28_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,28)
#define ITM_STIM28_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,28)
#define ITM_STIM29_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,29)
#define ITM_STIM29_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,29)
#define ITM_STIM30_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,30)
#define ITM_STIM30_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,30)
#define ITM_STIM31_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,31)
#define ITM_STIM31_WRITE                         ITM_STIM_WRITE_REG(ITM_BASE_PTR,31)
#define ITM_TER                                  ITM_TER_REG(ITM_BASE_PTR)
#define ITM_TPR                                  ITM_TPR_REG(ITM_BASE_PTR)
#define ITM_TCR                                  ITM_TCR_REG(ITM_BASE_PTR)
#define ITM_LAR                                  ITM_LAR_REG(ITM_BASE_PTR)
#define ITM_LSR                                  ITM_LSR_REG(ITM_BASE_PTR)
#define ITM_PID4                                 ITM_PID4_REG(ITM_BASE_PTR)
#define ITM_PID5                                 ITM_PID5_REG(ITM_BASE_PTR)
#define ITM_PID6                                 ITM_PID6_REG(ITM_BASE_PTR)
#define ITM_PID7                                 ITM_PID7_REG(ITM_BASE_PTR)
#define ITM_PID0                                 ITM_PID0_REG(ITM_BASE_PTR)
#define ITM_PID1                                 ITM_PID1_REG(ITM_BASE_PTR)
#define ITM_PID2                                 ITM_PID2_REG(ITM_BASE_PTR)
#define ITM_PID3                                 ITM_PID3_REG(ITM_BASE_PTR)
#define ITM_CID0                                 ITM_CID0_REG(ITM_BASE_PTR)
#define ITM_CID1                                 ITM_CID1_REG(ITM_BASE_PTR)
#define ITM_CID2                                 ITM_CID2_REG(ITM_BASE_PTR)
#define ITM_CID3                                 ITM_CID3_REG(ITM_BASE_PTR)

/* ITM - Register array accessors */
#define ITM_STIM_READ(index2)                    ITM_STIM_READ_REG(ITM_BASE_PTR,index2)
#define ITM_STIM_WRITE(index2)                   ITM_STIM_WRITE_REG(ITM_BASE_PTR,index2)

/**
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ITM_Peripheral */


/* ----------------------------------------------------------------------------
   -- LLWU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Peripheral LLWU
 * @{
 */

/** LLWU - Peripheral register structure */
typedef struct LLWU_MemMap {
  uint8_t PE1;                                     /**< LLWU Pin Enable 1 register, offset: 0x0 */
  uint8_t PE2;                                     /**< LLWU Pin Enable 2 register, offset: 0x1 */
  uint8_t PE3;                                     /**< LLWU Pin Enable 3 register, offset: 0x2 */
  uint8_t PE4;                                     /**< LLWU Pin Enable 4 register, offset: 0x3 */
  uint8_t ME;                                      /**< LLWU Module Enable register, offset: 0x4 */
  uint8_t F1;                                      /**< LLWU Flag 1 register, offset: 0x5 */
  uint8_t F2;                                      /**< LLWU Flag 2 register, offset: 0x6 */
  uint8_t F3;                                      /**< LLWU Flag 3 register, offset: 0x7 */
  uint8_t FILT1;                                   /**< LLWU Pin Filter 1 register, offset: 0x8 */
  uint8_t FILT2;                                   /**< LLWU Pin Filter 2 register, offset: 0x9 */
  uint8_t RST;                                     /**< LLWU Reset Enable register, offset: 0xA */
} volatile *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register accessors */
#define LLWU_PE1_REG(base)                       ((base)->PE1)
#define LLWU_PE2_REG(base)                       ((base)->PE2)
#define LLWU_PE3_REG(base)                       ((base)->PE3)
#define LLWU_PE4_REG(base)                       ((base)->PE4)
#define LLWU_ME_REG(base)                        ((base)->ME)
#define LLWU_F1_REG(base)                        ((base)->F1)
#define LLWU_F2_REG(base)                        ((base)->F2)
#define LLWU_F3_REG(base)                        ((base)->F3)
#define LLWU_FILT1_REG(base)                     ((base)->FILT1)
#define LLWU_FILT2_REG(base)                     ((base)->FILT2)
#define LLWU_RST_REG(base)                       ((base)->RST)

/**
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE4_MASK                      0x3u
#define LLWU_PE2_WUPE4_SHIFT                     0
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      0xCu
#define LLWU_PE2_WUPE5_SHIFT                     2
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      0xC0u
#define LLWU_PE2_WUPE7_SHIFT                     6
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK)
/* PE3 Bit Fields */
#define LLWU_PE3_WUPE8_MASK                      0x3u
#define LLWU_PE3_WUPE8_SHIFT                     0
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      0xCu
#define LLWU_PE3_WUPE9_SHIFT                     2
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     0x30u
#define LLWU_PE3_WUPE10_SHIFT                    4
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     0xC0u
#define LLWU_PE3_WUPE11_SHIFT                    6
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK)
/* PE4 Bit Fields */
#define LLWU_PE4_WUPE12_MASK                     0x3u
#define LLWU_PE4_WUPE12_SHIFT                    0
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     0xCu
#define LLWU_PE4_WUPE13_SHIFT                    2
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT                    4
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     0xC0u
#define LLWU_PE4_WUPE15_SHIFT                    6
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
/* F1 Bit Fields */
#define LLWU_F1_WUF0_MASK                        0x1u
#define LLWU_F1_WUF0_SHIFT                       0
#define LLWU_F1_WUF1_MASK                        0x2u
#define LLWU_F1_WUF1_SHIFT                       1
#define LLWU_F1_WUF2_MASK                        0x4u
#define LLWU_F1_WUF2_SHIFT                       2
#define LLWU_F1_WUF3_MASK                        0x8u
#define LLWU_F1_WUF3_SHIFT                       3
#define LLWU_F1_WUF4_MASK                        0x10u
#define LLWU_F1_WUF4_SHIFT                       4
#define LLWU_F1_WUF5_MASK                        0x20u
#define LLWU_F1_WUF5_SHIFT                       5
#define LLWU_F1_WUF6_MASK                        0x40u
#define LLWU_F1_WUF6_SHIFT                       6
#define LLWU_F1_WUF7_MASK                        0x80u
#define LLWU_F1_WUF7_SHIFT                       7
/* F2 Bit Fields */
#define LLWU_F2_WUF8_MASK                        0x1u
#define LLWU_F2_WUF8_SHIFT                       0
#define LLWU_F2_WUF9_MASK                        0x2u
#define LLWU_F2_WUF9_SHIFT                       1
#define LLWU_F2_WUF10_MASK                       0x4u
#define LLWU_F2_WUF10_SHIFT                      2
#define LLWU_F2_WUF11_MASK                       0x8u
#define LLWU_F2_WUF11_SHIFT                      3
#define LLWU_F2_WUF12_MASK                       0x10u
#define LLWU_F2_WUF12_SHIFT                      4
#define LLWU_F2_WUF13_MASK                       0x20u
#define LLWU_F2_WUF13_SHIFT                      5
#define LLWU_F2_WUF14_MASK                       0x40u
#define LLWU_F2_WUF14_SHIFT                      6
#define LLWU_F2_WUF15_MASK                       0x80u
#define LLWU_F2_WUF15_SHIFT                      7
/* F3 Bit Fields */
#define LLWU_F3_MWUF0_MASK                       0x1u
#define LLWU_F3_MWUF0_SHIFT                      0
#define LLWU_F3_MWUF1_MASK                       0x2u
#define LLWU_F3_MWUF1_SHIFT                      1
#define LLWU_F3_MWUF2_MASK                       0x4u
#define LLWU_F3_MWUF2_SHIFT                      2
#define LLWU_F3_MWUF3_MASK                       0x8u
#define LLWU_F3_MWUF3_SHIFT                      3
#define LLWU_F3_MWUF4_MASK                       0x10u
#define LLWU_F3_MWUF4_SHIFT                      4
#define LLWU_F3_MWUF��./K��MGa�QV�`�0��fW��zb���v�P�
�L#�R<F��;#�M�X�?m�y1�۵��M'��HTG���u�<��7���VU�����[�5������1o�Հ�^��^��_<�hHe�k�<O�ʼ'���9$"�Z%D����9J�nz���{��B4�d
�!��W!G�C���G
��*n�a�a	�	Q�%bσ�]&>V-q���=×�� #ީ)��p����+6Q'*=w��E���H�!�U���K.��T�I�ze}n�j��E�IŢx�\�u��b�Q��y���@0��<�6�6W� ���(�A^G���Q�}:�yWwZ߿ʡ�$�5�2�,حz32���T^��
o(X���L���=96x�a6�t��`R�Y����5u��a�V���WC)��Kv!\��h�T�
�U��m} �>�bQv�s1��MM��c�Y���(�$���8�}sQҎ0#F�����Z��A�����Q��Db�U�&�R��"�����	y���3�����U1��	D��т�s&���>��6m���5���ex1h*�zf3
~hjht��̑���^9J;�p�A���6}����|6�Lم~��ֽ�Cbm��k�	��^L)�ۈ&�����g������Ql�&˞p���r@�#)�;�(����<�7�G��a��";C>벵��481�/�z��,����2
՞l�=e����5w7�f��e��
@#R �b+�n��p��S�eYN��m�xtDE�Qʉڌ�3�����S�]�5F3�.��d
2�κC�:an6<T�w,:�6ܢ|�Ĕ�ΰ�=���P�y���-#QG�.%���́�*Ν`��7�e����ϝ1u���#���ƕ����vu�4��'��2��׶��h������� *�Z�]:�w�s2\���o��9��ciE�h�ͨ���")�a@���=�0��ׇ�s�у           0
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK)
#define LLWU_FILT2_FILTE_MASK                    0x60u
#define LLWU_FILT2_FILTE_SHIFT                   5
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK)
#define LLWU_FILT2_FILTF_MASK                    0x80u
#define LLWU_FILT2_FILTF_SHIFT                   7
/* RST Bit Fields */
#define LLWU_RST_RSTFILT_MASK                    0x1u
#define LLWU_RST_RSTFILT_SHIFT                   0
#define LLWU_RST_LLRSTE_MASK                     0x2u
#define LLWU_RST_LLRSTE_SHIFT                    1

/**
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base pointer */
#define LLWU_BASE_PTR                            ((LLWU_MemMapPtr)0x4007C000u)
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BA/��B<��s���1�o�6�k�L��&��"m��/8��`{��8'�쎐EB9�Tѩ"}`d6�^_��#��<}��7�T�,��Pfi-Q��h�a� ت�K��(��� �/V��0E�T����.~NOhWR}���)�����
-3YL/�S7�5��P�E.Ʀ������n�h�=�U�r�[�r6�q��:V���'�&�a�Cڣ\n݉!�V�kP��c�#�f�N�����@!�;���E;®d6),W��[��P���.FG���S�˭��оėd�Ni$�A<�~=������%�ic�q�q�]���U���%M0�R+���"�݆u�L}D��Æ�#�/�2b�[�%:y3�O�\I@�5����Rc/�n:����<ʋ���=5�Q8��#TXo'��Q��,ȓ3-�h_�H%��j-�-t�����ꏕ�iM9�9b�aX�k<Uǫ{ g�L�=dg���Y��.��}�� ��#��5��D�1�'��LFy=�]�)�}��Ոt��8��t�Mb]�mv�|IM������15�ѱ��|�z����"��-2�	����J:Ų���Q���ɛ�k2}/g�T%B�sxYx�����Q,G��x(��ö�u�Ȏ�@��l���j�jcvgT�z�j�=�3㾔�e��'�YG$:���{H_�:}ON���Y�l|L%K�Y��6g2߬q��H@F��z;�����{�_���M����C��2���F��+��F�I�!��&��ذam����.O�t��L?��S��,#b�q�z��x����\������_g��V�B�&y�@��I�`c���4ځ�#�h���x��nQ��H;a�St�Szh�.�t��>�W�3���"J�H}1�t]����f���е���=dy�Ƴ[��'n�*}wk�������~��,�]��n��߅'��U�,����j����s>D�F5(�Ӭ�N^��8��$IyPF��1��D�Q�US�O-%�O7?)��\�S�ͣ7�Z���\5�����"�j����.��f%~�+�34#eQ蚖"O��O�� ��m���n!3ڈũXk(���{a��w��Ȏ��?�%!i0�>����^(۹�E�?9A0yZ(m�٩ȼU�bPdE��ɍ��
����4E�Q��%��o?�#��������J���1�!H�O��t(RE�mu�YNF�H����@��lRB��������������d��Y�	�ZDxa�i��K��cJӺ6&���#��Ju��?�ڝ�:��h��~}	.^.}+���t��wK
���%��;�p�ĕ{�`�H$<�3��#+6
�C�Vy���Ҝ�鵇$��2���D}�����6kă���^Iv�"-t>�Bw����Jd�U���%���H�fu�#d��c�=���[6�zڹ:�%�R�~���
�5��E��B=�c�K�+қ!�S�g�ok��ul���#^G6 �J�\�1��*k�{�8�͡=�5**���]ԗ�A���BcƊ��nK7�a���~p��i{����\M�S�8���,���ڈe���7*�������c�ήS_����TS��hib^_n�
"�$�t�UD��Z4�;��4Q��x��r����k��ߐ>�:���#
��Ԍ�ur9��6m��_o4�{�$��=�h��F<J�?]-/��5�D�'��m�$���|��G����@i�VY4�d;�B۔���>�j�����w�_���s~Ǉ#+W-o+&g�[���X���B�:�����V!e�!�'��d!��k�����+�b�SNH�����5)�Y�	��r��j���;�e�y��;����8�����p	��G �m�5�E�?l1�4��&d����h)�c!��	��)b�/�
d7��Ƶq�3R�K�سB�9�Փ�����fX�k-��'�=_�^�Q2�����*l"H�Β��l�C1LD	)�\���Wsw�{�t��C�fP�WVĔ��;�t�m����SQ�G�ء׭t32_t CNR;                                    /**< Low Power Timer Counter Register, offset: 0xC */
} volatile *LPTMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register accessors */
#define LPTMR_CSR_REG(base)                      ((base)->CSR)
#define LPTMR_PSR_REG(base)                      ((base)->PSR)
#define LPTMR_CMR_REG(base)                      ((base)->CMR)
#define LPTMR_CNR_REG(base)                      ((base)->CNR)

/**
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR��./K��MGa�QV�`�0��fW��zb���v�P�
�L#�R<F��;#�M�X�?m�y1�۵��M'��HTG���u�<��7���VU�����[�5������1o�Հ�^��^��_<�hHe�k�<O�ʼ'���9$"�Z%D����9J�nz���{��B4�d
�!��W!G�C���G
��*n�a�a	�	Q�%bσ�]&>V-q���=×�� #ީ)��p����+6Q'*=w��E���H�!�U���K.��T�I�ze}n�j��E�IŢx�\�u��b�Q��y���@0��<�6�6W� ���(�A^G���Q�}:�yWwZ߿ʡ�$�5�2�,حz32���T^��
o(X���L���=96x�a6�t��`R�Y����5u��a�V���WC)��Kv!\��h�T�
�U��m} �>�bQv�s1��MM��c�Y���(�$���8�}sQҎ0#F�����Z��A�����Q��Db�U�&�R��"�����	y���3�����U1��	D��т�s&���>��6m���5���ex1h*�zf3
~hjht��̑���^9J;�p�A���6}����|6�Lم~��ֽ�Cbm��k�	��^L)�ۈ&�����g������Ql�&˞p���r@�#)�;�(����<�7�G��a��";C>벵��481�/�z��,����2
՞l�=e����5w7�f��e��
@#R �b+�n��p��S�eYN��m�xtDE�Qʉڌ�3�����S�]�5F3�.��d
2�κC�:an6<T�w,:�6ܢ|�Ĕ�ΰ�=���P�y���-#QG�.%���́�*Ν`��7�e����ϝ1u���#���ƕ����vu�4��'��2��׶��h������� *�Z�]:�w�s2\���o��9��ciE�h�ͨ���")�a@���=�0��ׇ�s�у��i���`:c�G��G$د >�UlVo�2�R�����h���=u�
~`��>����|~�il�����w�2rJ���B9��[��b˴��˽;���`��8a��VS��t&��}��So������k��l� ��@�p}�O�)f;�2�Z�t�)X/!����e�D&��|�8��d�2ʳ0��i�U4�/x����V{4��TiN�ʯY�<�Q�I?%fd hz�H�i��?��3^ %]4_}vU]�D�
v��YȧC���o�J�Wk������p'+C�Y���stn\�ޠ��J��8��7wJ�PCs�~�=��\�qh%��Y`�nKA<����G97��a���
��R����%��	Xr�uc�g��`9��v';��pn��ނa���=��
1"{#0uL�/�$J%�#cj٠�~��[_Aq�`瘇����=��<A"�>��
�h�ͣ7��	VjZ{4b_����9�Ja��@"󝒃v����w�,�G�Y���oȭ�k�,��Tm�'�.тt���M=��ߞ"�[����[�`o_A�7z��oؽ��s��C�B�o�2����Qf���0�M(:��� ����>����8[5J��Հ�~||R�]R�j,��M��]o�nO��Йv����jD5��U���Q�*m�E/m���S0�X%9�խ#苕�H�)���AS�wi3��$O���j�^�O�>��O���M"7�%�+\�:	,w��:&a�k�}k(��!7�^���#?��*�g;�ծ=�S���s��$�'*j�SE����Ny�f�������d��17�cCq[�z�X�#OJ��r���P��f
����d�.�5���5��G��[)I|qf����v�1�y��ح'��ӯN�&�����~.t�G��!��QR���&�/�����"|�W���G���(��:}�3��a�pǣlr��Cj9qQI܈zz��c���/��
4������ch�}q�
d"x�A�MR_CNR_COUNTER_MASK)

/**
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base pointer */
#define LPTMR0_BASE_PTR                          ((LPTMR_MemMapPtr)0x40040000u)
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- LPTMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Register_Accessor_Macros LPTMR - Register accessor macros
 * @{
 */


/* LPTMR - Register instance definitions */
/* LPTMR0 */
#define LPTMR0_CSR                               LPTMR_CSR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_PSR                               LPTMR_PSR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_CMR                               LPTMR_CMR_REG(LPTMR0_BASE_PTR)
#define LPTMR0_CNR                               LPTMR_CNR_REG(LPTMR0_BASE_PTR)

/**
 * @}
 */ /* end of group LPTMR_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LPTMR_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCG
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Peripheral MCG
 * @{
 */

/** MCG - Peripheral register structure */
typedef struct MCG_MemMap {
  uint8_t C1;                                      /**< MCG Control 1 Register, offset: 0x0 */
  uint8_t C2;                                      /**< MCG Control 2 Register, offset: 0x1 */
  uint8_t C3;                                      /**< MCG Control 3 Register, offset: 0x2 */
  uint8_t C4;                                      /**< MCG Control 4 Register, offset: 0x3 */
  uint8_t C5;                                      /**< MCG Control 5 Register, offset: 0x4 */
  uint8_t C6;                                      /**< MCG Control 6 Register, offset: 0x5 */
  uint8_t S;                                       /**< MCG Status Register, offset: 0x6 */
  uint8_t RESERVED_0[1];
  uint8_t SC;                                      /**< MCG Status and Control Register, offset: 0x8 */
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                   /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  uint8_t ATCVL;                                   /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  uint8_t C7;                                      /**< MCG Control 7 Register, offset: 0xC */
  uint8_t C8;                                      /**< MCG Control 8 Register, offset: 0xD */
  uint8_t C9;                                      /**< MCG Control 9 Register, offset: 0xE */
  uint8_t C10;                                     /**< MCG Control 10 Register, offset: 0xF */
} volatile *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register accessors */
#define MCG_C1_REG(base)                         ((base)->C1)
#define MCG_C2_REG(base)                         ((base)->C2)
#define MCG_C3_REG(base)                         ((base)->C3)
#define MCG_C4_REG(base)                         ((base)->C4)
#define MCG_C5_REG(base)                         ((base)->C5)
#define MCG_C6_REG(base)                         ((base)->C6)
#define MCG_S_REG(base)                          ((base)->S)
#define MCG_SC_REG(base)                         ((base)->SC)
#define MCG_ATCVH_REG(base)                      ((base)->ATCVH)
#define MCG_ATCVL_REG(base)                      ((base)->ATCVL)
#define MCG_C7_REG(base)                         ((base)->C7)
#define MCG_C8_REG(base)                         ((base)->C8)
#define MCG_C9_REG(base)     �      (   �        h(base)->C9)
#lefine LCGC10_REG(base)                        ((basm)-~C10)

/**
 * @}
 */ .* end of gro}p MCG_Register_Ac#esqor_Macros */

/* �--%----------------------------------------------------%------------------
   -- MCG Re�ister Masks
   =---�------/----,------------/------------------------------------------/- */

/** * @addtogroup MCG_Register_Masks MCG Register Maskc
 * @�
 */

/* C1 Bit Fields */
#define MCG_C1_MREFSTEN_MACK                    (0x1u
#define MCG_C1_KREFSTEN_SHIFT                    0
#define`MCG_C1_IRCLCEN_MASK         !            0x2u
#define MCG_C1_IRCLKDN_SHIFT �                   1
#defkne ]CG_C1_IREFS_MASK               !        0x5u
#define MCG_C1_IREFS_SHIFT                       2�#define MCG_C1_FRDIV_MASK                        0x38u#define MCG_C1_FRDMV_SHIFT     2                 7	
!dEfine MCG_C1_FRDIV(x)     !                    (*(uint8_t)(((tint8_t)(x	)<<MCG_C1_FRDIVORHIFT))&MCG_C1_FRIV_]ASK)
#define MWG_C1_AMKS_MASK "                       0xC0u
#define CG_C1_CLKS_SHIFT �      !0         "    6
#$dfine MCG_C1_CLKS(y)                           (h(uint8_t)(((uint8�t)(x))<<MCG_C1_CLKS_SHIFT))&�CG_C1_CLKS_MASK)
/* C2 Bit Fields */
define0MCW_C2_IRCS_MASK        `                0x1�
#define MCG_C2_IRCS_SH	FT              0       $ 0
#define MCG_C2_LP_MQSK       (     !             0x2u
#define MCG_C2_LP_ShIFT     $             $      1
#d�fife MCG_C2_E�EFS0_MASK  0                    0x4u
#define MCG_C2_EREFS0_SHIFT0    !                2
#define"MCC_C2_HGO0_MASK                 $       0{8u
#define MCG_C2_HGO0_SHIFT "   (                  3
#define MCG_C2_RANGE0_MASK`                      0x30u
#$efine MCG_C2_RANGE0_SHIFT                      4
#define MSG_C0_RANGE0(xi            `            (((uint8_|)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MaSK)
#degine MCG_C2_LOCRE0_MASK      0                0x80u
#ddfine MCG[C2_LKCRE0_SHIFT   $       �          7
/* C3$Bit Fields �/
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
/* C5 Bit Fields */
#define MCG_C5_PRDIV0_MASK                       0x1Fu
#define MCG_C5_PRDIV0_SHIFT                      0
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV0_SHIFT))&MCG_C5_PRDIV0_MASK)
#define MCG_C5_PLLSTEN0_MASK                     0x20u
#define MCG_C5_PLLSTEN0_SHIFT                    5
#define MCG_C5_PLLCLKEN0_MASK                    0x40u
#define MCG_C5_PLLCLKEN0_SHIFT                   6
/* C6 Bit Fields */
#define MCG_C6_VDIV0_MASK                        0x1Fu
#define MCG_C6_VDIV0_SHIFT                       0
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV0_SHIFT))&MCG_C6_VDIV0_MASK)
#define MCG_C6_CME0_MASK                         0x20u
#define MCG_C6_CME0_SHIFT                        5
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_LOLIE0_MASK                       0x80u
#define MCG_C6_LOLIE0_SHIFT                      7
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_OSCINIT0_MASK                      0x2u
#define MCG_S_OSCINIT0_SHIFT                     1
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_LOCK0_MASK                         0x40u
#define MCG_S_LOCK0_SHIFT                        6
#define MCG_S_LOLS_MASK                          0x80u
#define MCG_S_LOLS_SHIFT                         7
/* SC Bit Fields */
#define MCG_SC_LOCS0_MASK                        0x1u
#define MCG_SC_LOCS0_SHIFT                       0
#define MCG_SC_FCRDIV_MASK                       0xEu
#define MCG_SC_FCRDIV_SHIFT                 �`0Xpq�=*#(
j�u1ޙt�Q�\�:K^[�|����\J���9�b�8��<Bb?J?�Sn����ۇ� (���Zr�������Ǭۥ�`C�z;3�Q�6޶�(4k�&lCe��������O4���~����!}_R�����7Yu�u8�����E^�;�&�;��p�L�"_Kbu1;^>6)�����a'�X�	�+�|5,A�Nnj��
�����͍����״iG����5�l����P`�X5ļ��h0�M;ۉ�(����}��6x`��"��މ=�%��ב%U7^"[��X3��n��c�/�]?��Ώ��q������sb�sM��Ƅ�j`J�D����V)r8$�m8+�I��ȻV8�6�,%��hGpy���ן/~)���W����j��6:�}�6�E����|s2eY"gH�	.�~{�qK�Ȍ�/t�^?~���q
OB�M�EK㏷\\
Ɨ�5�s�罓�K`6�|���-L˿Y�������+����`�Ń���`�jNp�3?�;�l?�
k��3���\>o�!\��܃L�:C���Fd ��Hkh��+.8�� ��؇a3h��6��,8K��ȤqׄQ��M���H�����<�p7���%�{�Q��NT�ؠMV�z��_�v"�����#9���W.��Dz��s��j�l�s�&�m�7�6�6K��������PQ���#�'�����_�0�؜�Yp���zge]�~�O4�C�!�w�����$�{;��5ٻiu��­�xi��ˣs�I���{��Z�uǕ�Q��Xd���pSc�e�Ǜ�������}[_N3��i�B�˓]vS �r����$t5y�A��&��<:ӑ����3Һ��ؼjN�6�a@������y���w@���*f"W���G*� 3%�e�����SQ�6V����GV��'�ܘ�Bp�t���V�
��􎇡�6S�ӕ�I�Hڛ:��J��l���$4�����P��R���FI����0�z���M!�s����m�E��O���HFi�ϳy���{k5R@��/�jS!��cF檝�K�;�`w2�{��Z����M���=7��/��틷���[�V*��"�Gdƀ��[�˔�F�ÉO_3V�s)gQ�m������z���W�B��t^�&�
�oB��foy�k�������3�WG*��%��a��E:h��Bq8o�t'�A�zu����*RE����TB	o�= �dB��Ƚ%ת�����:N�b��j�t�����#9d>��]�қ�"u��+5�=iI��	���D�.���cXjO�I�G1�N
8�K��#A~�n�I;e�&ٗ�.������G�A	�������;@���ˁ->�Y�c_�� ����g⟊P���,�D�M$��?��r�v�P�I߮��<�2�_��3먮��I2۹��|�Xe�b����eY������o��+�h��N��f4��C�ܼ��_��i�"��U�t����!%�t^s��5�"6�b�����U�2[ICa�� ه8$X���%���¥"(<�?1�+����]�4y傪0X�h vo;�\�|��M��/�<�J�!���sFbd���/�Ӥ���=6˧�uu٢�=��/z[�/�(f-�aX��[=��Q���s�v-��`�o�fY�ů�g^����:���,�IIn�/�.���u'Bkp�m��^�Vy��z��U}�1��g��=1���6�Gmih�E�,+�H�[�����h�^�X9�S�} �>ġ�C��$]�a�{�������jAI3��� 9���O�0l~l%������$Ώ��zNI,�@���Z�rܘH
ˇ�)2���OY3}^�LT���%�Ig��f͘�ro����41�1y2'm��j���J��?��=H���}V}0�>SGW���\�>�Z�H��l�Ae�H"Q��ݿؙ����O��5��F:BMF�� �K~P���?�����j@��kr��^�`b�������w10	���n�~�4����Ɏ�UғH�ɡє�i�E�Q�`��k�#��i�N��D탇�p㸫T5x|m�@ڏr�;��n�����q��X4Ԗ��˯�67�P�p+�w��R�
�����vҡ��Z�by���yXDo�$�Z%(�������D啒����U���[հ��x=����\yW;L��,���ќ�����o�8�z��^�*ߴ:dY}�^Ri1@@���yP-;iBG:OX�CzȄz�jH�����}T��v�<���$^��,���u�_i-2*drV4q��_-ψ
o���k��k���v눾�0]����y:�M��o�j(V�t@�)����;���^�P�%N0��� &fL�Ơ5S���u��\o��&Ͳ�53 O���D�u����q���D��1Q�]D9�i�l�}��dל���Qގ��{��\q��W�榤�i�XǠ_eP�+�������L�8�\�3�آ�WF"�D���gw����E��7%f�ҞM ͽA�%� Ճ�/�[��}��:�D�JC�6�"�tpuE�)�9�{/�_��/8�\EU�?,D�n�G�Id��O:{*��L�@_���Տ�K��"T8/y���1�۽� �B'o�R���w��ߕ����
�S���hZ�i�V8�#��1�mg�[t�`�K�;*`1�%�ZKΥL���l���5�Z��-h�*ʭ:{~�<.��U�N�o�VL�F��w�=y	�O�F�} �a=�ц���m����DAhA襽}sM���'?�\H�d5dA7��O�
{�s>��a���}�c݁1e��`��<�E�u�ʙ'3��Ģ���h��Ъ��cv!���X/'�����D�g?���= #:���S06%�`*vp���!L��U�����������5'�˨c��	G�/�RkQ�Tf�0R]oC	�x�rWSt��=�E� ��	�qӑ�:�_=��=���0�����p�$��ݯH�SFHd��:�WJ���]D�V4dٲ1f���#Ѭ�ƌ�×��� ���כ�Q>�E;m�1Y�e�#�Ӓ\G_�ށD��?6����L4�S{_��"�)Kn��uʾ.�� <���u��� �8��� qb<U2k/�5�H�Q{!��K���|hԹѯ�X���7H�&�	s�tmo�\w��;AvFS!a�~k�x��5�w����8� �����������p�ji׊0�%F�P�m��O��w��sq�-
�"���01�����x^F��/X�yƝ$�x�^a����gaV�A��.~`��EM@�����j�:n��-no6�2��z��L��zuPcQ���%�7�K��DR-ߊ��R��� ����
�늡$Қd��N\:�@�5�a���n���N\<m\���2���s�4[t����v������G6)�i��Ӄy�+7(h�U 1<��stw�T/lrd28�=���{ِ}����("�Uq��j�IA#"��U���Km��R���:e�B[\h�L��&�{��qIm�e���gA��	����Y`~�����
OB�#�������e�f�/<�I����Nn�`���S-rk�ΣR�䘛��
e���!�A�����U��W|�L}sn~(X��62���u}11���}���B�!P�����!/�O_��]:�s����OT|O����~a�YR�o�zP�Q�ʌ��̝�Z� ��uH�2vg��u孬��+��0++[i�!�;�U��+�)���?�9�ڗ�F�Y�	�J��ǎ'�g���b֬��KP��@E��"x�):��+)�՝G4��a9���p5]��h�?R]�Y�.u/F`m\��v��`�1���=KŻ��9" T�ZLfyF=�x�|waA��C��Rv��)%Bl����X�,�{�2��Unn���=+
��#K��+3�4�Q����Uc����}W��z�<OK��].A"3 �rf�_�W��!=\W)(x�	��8ĔX,i�&`�g
�9Ǹ՜o�q;����;�ȜM.��]�L��\3�[NDm�of���D�������8!����4�΢��GM+� Il)au�;���44�k� Ō���h�Fw;�5�ֻ���귖�?:-��8�B\͊%��*Eiu�~�ұ�8��j�~Qsų8�����ȯ�vL/]fYhc͕M@��B��+���,��~�E(k*M�6��Sp��@��bnŝ[إή����l� ��Q5�"��4	���j��y�De�¼��j�i	��bv��q�ŕ����������?˗;w�+���[&�J)��!A����i��Z����mi?Ķ?���z(���D��G� ���FU�|�w��s�p���܄ւ���:؎����!����u�Q���%8�B��j�V
棑�)�v#�6�$��4���^kp��*+��坞������?c�5�9c���, ̪3<n�9ˇ~�}��tpFw=M�1�m��_�g8Q��mux�Η4�(Y$TUh�@8���3.��pEX�6�7��Ds,��S�gGI��a$S4O^�Ǧ������A���2������<1D����U�#ȩ(�ɸ`UQMu��t?<�O����K!hO����L��3�'�Hx����\�����@#�1NT��Ī�,77U����W�`@h�I�|[���9tb?�LroF��ƅ��^I:-��X6���J}3q$�=�/<�$���9TP�$��9�]�ˑ;V5���^:�4ή_�`*RȻ�\:,�$�|��D�s��a���f2��R�l�VH�K�ږ�A-6b�'8(��͞4�z5���CN�����A�&�v�����Sn�H�ʵS���H����	ozx�z�Ď������������6a��sZQ�\�	O9Ǻv �>HVE�g*��s�� �P�{qf�T{v�$�քS{�z	y�0�����^�O"S(�AK��������^ �F[D��%�Q�2��I�/��>"��MV���FaY�`0Xpq�=*#(
j�u1ޙt�Q�\�:K^[�|����\J���9�b�8��<Bb?J?�Sn����ۇ� (���Zr�������Ǭۥ�`C�z;3�Q�6޶�(4k�&lCe��������O4���~����!}_R�����7Yu�u8�����E^�;�&�;��p�L�"_Kbu1;^>6)�����a'�X�	�+�|5,A�Nnj��
�����͍����״iG����5�l����P`�X5ļ��h0�M;ۉ�(����}��6x`��"��މ=�%��ב%U7^"[��X3��n��c�/�]?��Ώ��q������sb�sM��Ƅ�j`J�D����V)r8$�m8+�I��ȻV8�6�,%��hGpy���ן/~)���W����j��6:�}�6�E����|s2eY"gH�	.�~{�qK�Ȍ�/t�^?~���q
OB�M�EK㏷\\
Ɨ�5�s�罓�K`6�|���-L˿Y�������+����`�Ń���`�jNp�3?�;�l?�
k��3���\>o�!\��܃L�:C���Fd ��Hkh��+.8�� ��؇a3h��6��,8K��ȤqׄQ��M���H�����<�p7���%�{�Q��NT�ؠMV�z��_�v"�����#9���W.��Dz��s��j�l�s�&�m�7�6�6K��������PQ���#�'�����_�0�؜�Yp���zge]�~�O4�C�!�w�����$�{;��5ٻiu��­�xi��ˣs�I���{��Z�uǕ�Q��Xd���pSc�e�Ǜ�������}[_N3��i�B�˓]vS �r����$t5y�A��&��<:ӑ����3Һ��ؼjN�6�a@������y���w@���*f"W���G*� 3%�e�����SQ�6V����GV��'�ܘ�Bp�t���V�
��􎇡�6S�ӕ�I�Hڛ:��JE򜶒(��L�,u
Х��V����A>��}�55U�����'Rz�Kـ�>��	z��zp ����,�e����ԗO�Y3H�7(zL�&����s���x������}"��:v��-�Wa������¾��J����nSs/UT�>ԀOXf��z�)�� C�Z ����>�x��Je|՘�]�iv�y�)L��u����(��X,��^�svqM�R� �̞��eY��d�/b�E�{}o���1*��RA+��zL�+!'�I��pl!Xa�0��_�el���m�1g ~�I	��ۗXl�&C�$�]����a��c�(}�ɲ�Z�YοՄc��ƩD�,v9~WA�X���d-9��EeՍ�,� ����3Q���j�$z,��A1�^ʢj}��s���p�
<�)���W�*;�\,!_\��/N;B�a)��+�D~�+M^� �c,�Gz�0ܲ�;/��C�F�g��*��w�=#݆Z�zc�L�5�V���N�Fi3��2�����}j�?�u�����B���T��Ț��<Q.٭�DZ�~���m��r�R�:���(O�0�� ������)��쩴�L�&��V�t5;���#�9�~�������"��A���֪�*'b\]�����4]ށ�6=;l#4d�rbwLK��g&-��*HV��hk";V�>�RCmh%�@��:��o�Y5�����x�����]gb���ܳ����8��M����h��ː�T�k�%�nA֣�m|�9�Jz
��e�XP�0�aQSy���x8O�����t����4~�I--^�<��.2p�����ud�T�_��������0v�aa$�وN�K��ٯOW��f����	�k�����6�r���4�N@�N��Nf5�A#m�~��\����/�ʍQ8���@����e�{���"�`�ݢ���'q�˚Љ�9e �?J�c�/��OR�uh�1Ҹy�@�����g�ɇJ��ɓ�%6S2b30
/* ISR Bit Fields */
#define MCM_ISR_IRQ_MASK                         0x2u
#define MCM_ISR_IRQ_SHIFT                        1
#define MCM_ISR_NMI_MASK                         0x4u
#define MCM_ISR_NMI_SHIFT                        2
#define MCM_ISR_DHREQ_MASK                       0x8u
#define MCM_ISR_DHREQ_SHIFT                      3
/* ETBCC Bit Fields */
#define MCM_ETBCC_CNTEN_MASK                     0x1u
#define MCM_ETBCC_CNTEN_SHIFT                    0
#define MCM_ETBCC_RSPT_MASK                      0x6u
#define MCM_ETBCC_RSPT_SHIFT                     1
#define MCM_ETBCC_RSPT(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_ETBCC_RSPT_SHIFT))&MCM_ETBCC_RSPT_MASK)
#define MCM_ETBCC_RLRQ_MASK                      0x8u
#define MCM_ETBCC_RLRQ_SHIFT                     3
#define MCM_ETBCC_ETDIS_MASK                     0x10u
#define MCM_ETBCC_ETDIS_SHIFT                    4
#define MCM_ETBCC_ITDIS_MASK                     0x20u
#define MCM_ETBCC_ITDIS_SHIFT                    5
/* ETBRL Bit Fiells */
#define0MCM_ETBRL_RELOAD_MASK                    0x7FFu
#define MCM_ETBRLWRELOAD_SHIFT     ��            0
#$efine MCM_TBRL_RELOAD(x)                      (((uint32_t)(((uint32_t)(x))<<MCM_ETBRL_RELOAD_SHIFT))&MM_DTBRL_RELOAD_MASK)
/* ETBCNT Bit0Fields ./
#define MC]_ETBCNT_COUNTER_MASK                  0x7FFu#defi~e MCM_E\BCNT_COUnTER_SH@T      !      "   0
#define MCM_ETBCNT_CO�NTER(x)                    (((uint32_t)( (uint32_t)(8))�<MCM_ETBCNT_COUNTER_SHIFT))&MCM_ETBCNT_COUNTER_MASK)
/* PID Bit Fields */
#define MCM_PMD_XID_mASK       `    `   `    $   0xFFuM
#define0MCL_PID_PID_SHIFT                   `    0
#define MCM_PID_PID(p)!0                         (((uint3:_t)(((uinu32_t)(x))<<MCMWPID_PID_SHI�Ti)&MCM_PID_PID_MASK)
/**
 * @}	� */ /*`enf of froup MCM_Register^Masks */


/* MCM - Peri�heral knstance base addresses */
/** Peripheral MCM base pointer */
#tevinE ECM_BASE_PTR            �                ((MCM_MemMapPtr)0xE0080000u)/** Array$initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM */
#define MCM_PLASC                                MCM_PLASC_REG(MCM_BASE_PTR)
#define MCM_PLAMC                                MCM_PLAMC_REG(MCM_BASE_PTR)
#define MCM_CR                                   MCM_CR_REG(MCM_BASE_PTR)
#define MCM_ISR                                  MCM_ISR_REG(MCM_BASE_PTR)
#define MCM_ETBCC                                MCM_ETBCC_REG(MCM_BASE_PTR)
#define MCM_ETBRL                                MCM_ETBRL_REG(MCM_BASE_PTR)
#define MCM_ETBCNT                               MCM_ETBCNT_REG(MCM_BASE_PTR)
#define MCM_PID   $       !  `              p    MCM_PIL_REE(MCM_BSE_PTR)

/**
 * @}
 */ /* end of group MCM_Reghster_Accessor_Macros */	


/**
 * @}
 */ /* end nb group MCM_Peripheral */


/* ---=---------/--------------)---------------�---------------------,--------
   -- MP
   -----------=------------------------�%--=--%----------------------------,--- */

/**
 * @a`dtogroup MPU_Peripheral MPU
 * @{�
 */

/**0MPU*- Peryplebal register structure */
typedef struct MPU_MemMap {J  uant32_t CESR;                                   /**< Control/Error Status Register, offset: 0x0 */
  uift8Wt RESERTED0Z12];
  struct {     (                 "                 /* offqet: 0x10, array step: 0x8 */
   0uint32_t EAR;     `                              /**< Error Cddress R%gister$ slave!pobu n, erray offset: 0x10, array sdep: 0x8 */
    uint#2_t EDR;                      "0            /**< Error Da�ail Register, slave prt n,$arra9 offset: 0x14, arra� step: 0x8 */
  } SPZ];-
  uint8_t RESERVED_1[)68];
  tint32_t WORD[52][4];               0           %/**< Region Descriptor n, Word 0..Region Descriptor n$ Word 3, array offset: 8x400, array step: index*0x10, index2*0x4 */
  uint0_t RESERVED_2[832];
  uint32_t RGDAAC[12];  �         "             "  /**< egimn Descriptor Alternate AccEss Control o, array offret: 0x800, array step: 0x4$*/
} wolatile *MPU_MemMarPtr;

/* -----------%------------/--------,-------------%---------------%------------
   m- MPU - Register accessor macros
   -----�---------------,-----------------------------------------------------/ */-

/** * Baddtogro}0 MPU_Register_Acceswor_Macros MPU - Register accessor macros
 * @{
 */


/* MPU % Registes accessop{ */
#define MPU_CESR_REG(base)       0   �           �(base)->CESR)
+define MPU_EQR_REG(base,index)                  ((base)->SP[infex].EAR)
#befine MPU_EDR_REG(base,index)    $             ((b!{e)->SP[index].EDR)-
#defin% MPU_WORD_RE�(base,index(index2)  � `     ((base9->WORD[index][index2])
#d�fine MPU_RGDAAC_REGhbase,index)               ((base)->RGDAAC[index])

/**
 * @}
 */ /* end of group MPU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Masks MPU Register Masks
 * @{
 */

/* CESR Bit Fields */
#define MPU_CESR_VLD_MASK                        0x1u
#define MPU_CESR_VLD_SHIFT                       0
#define MPU_CESR_NRGD_MASK                       0xF00u
#define MPU_CESR_NRGD_SHIFT                      8
#define MPU_CESR_NRGD(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NRGD_SHIFT))&MPU_CESR_NRGD_MASK)
#define MPU_CESR_NSP_MASK                        0xF000u
#define MPU_CESR_NSP_SHIFT                       12
#define MPU_CESR_NSP(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK)
#define MPU_CESR_HRL_MASK                        0xF0000u
#defife MPU_CESRWHRL_SHIFT  ! "                  16
#dmfine MPU_CESR_HRL(x)`                     "   (((uint32_t) ((uint32_t)(x))�<MPU_CESR_HRL_SHIFT))&MPU_CESR_H�L_MASK)
#define MPU_CESR_SPERR_MASK(  (                  0xF8008000u
#define OPU_CUSR_SPURR_RHIFT               $     27
#fefine MPUWCESR_SPERR(x)           (            (((uint32_t)(((uint32_t)(x))<<MPU_CESR_SPErR_SHIFT)-&MPU_CESR_SPERR_MASK)
/* EAR Bit Fields */
#define MPU_EAR_EEDLR_MASK      !               !0xFFFFVFFFu
#define MPU_EAR_EADDR_SHIFT   $       !  "  (    0
#define MPU_EAR_EADDR(x)                         (((uint32_ti(((uint32_t)(x))<<MPU_EAR_EADDR_RHIFT))&MPU_EAR_EADDRWMCSK)
/* EDR Bit Fields */
"dafine0MPU_EDR_ERW_MASK              0$  �      0�1u
#define MPU_EDR_EZW_SHIFT      !                 0
#define MPU_EDR_EADTR_MASK                       0xEu
#defiNe(EPU_EDR_EATTR_SHIFT         0            1
#define MPU]EDR_EATT�(x)         0   (           (((uint32_t)(((ti.t32_t) x))<<MPU_EDR_EATTR_SHIFT))6MPU_eDR_EATTR_MASK)
#define MPU_EDRWEMN_MASK   "        `      4     0xF0u
#define MPU_EDR_EMN_SHIFT     $            �    "4
+defife MPU_EDR_EMN(x)                   $       ((uint32_�)(�(uint32_|9(x))<=MPU_EDR_EMN_SHHFT))&MPU_EDR_EMN_MASK)
#define MPU_�DR_EACD_MASK                        0xFFFF0�00u
#define MPE_EDR_EACD_SHIFT                    !  16
#defkne�MPU_EDR_MACL(x)                      0   (((u�nt32_t)()(uint�2_t)(x))<<MPU_EDP_EACD_SHIFT))&MPU_EDR_EACD_MASK)
/* GORD�Bit Fields */
#defin% MPU_WORD_M0UM_MASK    !             `    0x7u�#define MPU_WORD_M0UM_SHIGT            (    `    0
#d�fine(MPU_WOPD_M�UMx)                         (((uint32_t)(8(uint32_t)(8))<<MPU_W_RD_M0UM_SHIFT))&MPU_WORD^M0UM_MASK)
#define MPU_WORD_VlD_MASK                        0x9u
#denine MPU_WGRd_VLD_SHIFT            !          4
#define MpU]WORD_M0SM_MASK               !       0x18u
#define MPU_WOPL_M0SM_SHIFT                      3
#define MPUWORD_M0SM(x)       !                 (((uint32_t)(((uint32_t)(x))<<MRU_WORD_]0SM_SHIFT))&MPU_WORD^M0SM_MASK)
#define MPU_W�RD_UNDADDR_MASK                    0xFFFFFFE0u
#defioe MPT_WORD_ENDATDR_SHIFT0     �            5
#define MTU_WORD_ENDADDR(x)                      (((}int32_t)(((}int32_t)(x))<<MPU_WoRD_ENDADDR_SHIFT))&MPU_WORD_ENDADDR_MASK)
#defile MPU_WORD_SrT@DDR_MASK                    0xFFFFFFe0u
#define MPU_WORD_SRTADDR_SHIFT    $    !�!       5
#define MPU_WORD_SRTADDR(x)                      (((uint32_t)*((uilt32]t)(x#!<<MPU_WORD_SRTATDR_SLIFT))&MPU_WORD_SRTADDR_MASK)
#d%fine MPU_WORD_1UM_LASK                      �0x1C0u
#define MPU_�ORDOM1UM_SHIFT    "                 6
#$efine!MPU_WORD_M1UM(x(       0    !   "        (((uint#2_t)(((uinv32_t	(y))<<MPU_WORD_M1UM_SHIFT))&MPU_WOB_M1UM_MASK)
#define MPU^WORD_M3SM_MAWK                       0x6015
#define MPU_WORD_M1SM_SHIFT      0               9
#defkne MPU^WORD_M3SM(x)"                        (((uint32_t)(((uint32_t)8x))<<MPU_WORDM1SM_SHIFT))&MPU_WORD_M1SM_MASK)
#define MPU_WORD_M2UMWMASK                       0x7000u
#define MPU_WORD_M2UM_SHIFT                      12
#define MPU_WORD_M2UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M2UM_SHIFT))&MPU_WORD_M2UM_MASK)
#define MPU_WORD_M2SM_MASK                       0x18000u
#define MPU_WORD_M2SM_SHIFT                      15
#define MPU_WORD_M2SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M2SM_SHIFT))&MPU_WORD_M2SM_MASK)
#define MPU_WORD_M3UM_MASK                       0x1C0000u
#define MPU_WORD_M3UM_SHIFT                      18
#define MPU_WORD_M3UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M3UM_SHIFT))&MPU_WORD_M3UM_MASK)
#define MPU_WORD_M3SM_MASK                       0x600000u
#define MPU_WORD_M3SM_SHIFT                      21
#define MPU_WORD_M3SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M3SM_SHIFT))&MPU_WORD_M3SM_MASK)
#define MPU_WORD_M4WE_MASK                       0x1000000u
#define MPU_WORD_M4WE_SHIFT                      24
#define MPU_WORD_M4RE_MASK                       0x2000000u
#define MPU_WORD_M4RE_SHIFT                      25
#define MPU_WORD_M5WE_MASK                       0x4000000u
#define MPU_WORD_M5WE_SHIFT                      26
#define MPU_WORD_M5RE_MASK                       0x8000000u
#define MPU_WORD_M5RE_SHIFT                      27
#define MPU_WORD_M6WE_MASK                       0x10000000u
#define MPU_WORD_M6WE_SHIFT                      28
#define MPU_WORD_M6RE_MASK                       0x20000000u
#define MPU_WORD_M6RE_SHIFT                      29
#define MPU_WORD_M7WE_MASK                       0x40000000u
#define MPU_WORD_M7WE_SHIFT                      30
#define MPU_WORD_M7RE_MASK                       0x80000000u
#define MPU_WORD_M7RE_SHIFT                      31
/* RGDAAC Bit Fields */
#define MPU_RGDAAC_M0UM_MASK                     0x7u
#define MPU_RGDAAC_M0UM_SHIFT                    0
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0UM_SHIFT))&MPU_RGDAAC_M0UM_MASK)
#define MPU_RGDAAC_M0SM_MASK                     0x18u
#define MPU_RGDAAC_M0SM_SHIFT                    3
#define MPU_RGDAAC_M0SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0SM_SHIFT))&MPU_RGDAAC_M0SM_MASK)
#define MPU_RGDAAC_M1UM_MASK                     0x1C0u
#define MPU_RGDAAC_M1UM_SHIFT                    6
#define MPU_RGDAAC_M1UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1UM_SHIFT))&MPU_RGDAAC_M1UM_MASK)
#define MPU_RGDAAC_M1SM_MASK                     0x600u
#define MPU_RGDAAC_M1SM_SHIFT                    9
#define MPU_RGDAAC_M1SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M1SM_SHIFT))&MPU_RGDAAC_M1SM_MASK)
#define MPU_RGDAAC_M2UM_MASK                     0x7000u
#define MPU_RGDAAC_M2UM_SHIFT                    12
#define MPU_RGDAAC_M2UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2UM_SHIFT))&MPU_RGDAAC_M2UM_MASK)
#define MPU_RGDAAC_M2SM_MASK                     0x18000u
#define MPU_RGDAAC_M2SM_SHIFT                    15
#define MPU_RGDAAC_M2SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M2SM_SHIFT))&MPU_RGDAAC_M2SM_MASK)
#define MPU_RGDAAC_M3UM_MASK                     0x1C0000u
#define MPU_RGDAAC_M3UM_SHIFT                    18
#define MPU_RGDAAC_M3UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3UM_SHIFT))&MPU_RGDAAC_M3UM_MASK)
#define MPU_RGDAAC_M3SM_MASK                     0x600000u
#define MPU_RGDAAC_M3SM_SHIFT                    21
#define MPU_RGDAAC_M3SM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M3SM_SHIFT))&MPU_RGDAAC_M3SM_MASK)
#define MPU_RGDAAC_M4WE_MASK                     0x1000000u
#define MPU_RGDAAC_M4WE_SHIFT                    24
#define MPU_RGDAAC_M4RE_MASK                     0x2000000u
#define MPU_RGDAAC_M4RE_SHIFT                    25
#define MPU_RGDAAC_M5WE_MASK                     0x4000000u
#define MPU_RGDAAC_M5WE_SHIFT                    26
#define MPU_RGDAAC_M5RE_MASK                     0x8000000u
#define MPU_RGDAAC_M5RE_SHIFT                    27
#define MPU_RGDAAC_M6WE_MASK                     0x10000000u
#define MPU_RGDAAC_M6WE_SHIFT                    28
#define MPU_RGDAAC_M6RE_MASK                     0x20000000u
#define MPU_RGDAAC_M6RE_SHIFT                    29
#define MPU_RGDAAC_M7WE_MASK                     0x40000000u
#define MPU_RGDAAC_M7WE_SHIFT                    30
#define MPU_RGDAAC_M7RE_MASK                     0x80000000u
#define MPU_RGDAAC_M7RE_SHIFT                    31

/**
 * @}
 */ /* end of group MPU_Register_Masks */


/* MPU - Peripheral instance base addresses */
/** Peripheral MPU base pointer */
#define MPU_BASE_PTR                             ((MPU_MemMapPtr)0x4000D000u)
/** Array initializer of MPU peripheral base pointers */
#define MPU_BASE_PTRS                            { MPU_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros
 * @{
 */


/* MPU - Register instance definitions */
/* MPU */
#define MPU_CESR                                 MPU_CESR_REG(MPU_BASE_PTR)
#define MPU_EAR0                                 MPU_EAR_REG(MPU_BASE_PTR,0)
#define MPU_EDR0                                 MPU_EDR_REG(MPU_BASE_PTR,0)
#define MPU_EAR1                                 MPU_EAR_REG(MPU_BASE_PTR,1)
#define MPU_EDR1                                 MPU_EDR_REG(MPU_BASE_PTR,1)
#define MPU_EAR2                                 MPU_EAR_REG(MPU_BASE_PTR,2)
#define MPU_EDR2                                 MPU_EDR_REG(MPU_BASE_PTR,2)
#define MPU_EAR3                                 MPU_EAR_REG(MPU_BASE_PTR,3)
#define MPU_EDR3                                 MPU_EDR_REG(MPU_BASE_PTR,3)
#define MPU_EAR4                                 MPU_EAR_REG(MPU_BASE_PTR,4)
#define MPU_EDR4                                 MPU_EDR_REG(MPU_BASE_PTR,4)
#define MPU_RGD0_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,0,0)
#define MPU_RGD0_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,0,1)
#define MPU_RGD0_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,0,2)
#define MPU_RGD0_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,0,3)
#define MPU_RGD1_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,1,0)
#define MPU_RGD1_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,1,1)
#define MPU_RGD1_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,1,2)
#define MPU_RGD1_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,1,3)
#define MPU_RGD2_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,2,0)
#define MPU_RGD2_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,2,1)
#define MPU_RGD2_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,2,2)
#define MPU_RGD2_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,2,3)
#define MPU_RGD3_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,3,0)
#define MPU_RGD3_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,3,1)
#define MPU_RGD3_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,3,2)
#define MPU_RGD3_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,3,3)
#define MPU_RGD4_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,4,0)
#define MPU_RGD4_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,4,1)
#define MPU_RGD4_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,4,2)
#define MPU_RGD4_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,4,3)
#define MPU_RGD5_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,5,0)
#define MPU_RGD5_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,5,1)
#define MPU_RGD5_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,5,2)
#define MPU_RGD5_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,5,3)
#define MPU_RGD6_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,6,0)
#define MPU_RGD6_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,6,1)
#define MPU_RGD6_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,6,2)
#define MPU_RGD6_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,6,3)
#define MPU_RGD7_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,7,0)
#define MPU_RGD7_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,7,1)
#define MPU_RGD7_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,7,2)
#define MPU_RGD7_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,7,3)
#define MPU_RGD8_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,8,0)
#define MPU_RGD8_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,8,1)
#define MPU_RGD8_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,8,2)
#define MPU_RGD8_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,8,3)
#define MPU_RGD9_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,9,0)
#define MPU_RGD9_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,9,1)
#define MPU_RGD9_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,9,2)
#define MPU_RGD9_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,9,3)
#define MPU_RGD10_WORD0                          MPU_WORD_REG(MPU_BASE_PTR,10,0)
#define MPU_RGD10_WORD1                          MPU_WORD_REG(MPU_BASE_PTR,10,1)
#define MPU_RGD10_WORD2                          MPU_WORD_REG(MPU_BASE_PTR,10,2)
#define MPU_RGD10_WORD3                          MPU_WORD_REG(MPU_BASE_PTR,10,3)
#define MPU_RGD11_WORD0                          MPU_WORD_REG(MPU_BASE_PTR,11,0)
#define MPU_RGD11_WORD1                          MPU_WORD_REG(MPU_BASE_PTR,11,1)
#define MPU_RGD11_WORD2                          MPU_WORD_REG(MPU_BASE_PTR,11,2)
#define MPU_RGD11_WORD3                          MPU_WORD_REG(MPU_BASE_PTR,11,3)
#define MPU_RGDAAC0                              MPU_RGDAAC_REG(MPU_BASE_PTR,0)
#define MPU_RGDAAC1                              MPU_RGDAAC_REG(MPU_BASE_PTR,1)
#define MPU_RGDAAC2                              MPU_RGDAAC_REG(MPU_BASE_PTR,2)
#define MPU_RGDAAC3                              MPU_RGDAAC_REG(MPU_BASE_PTR,3)
#define MPU_RGDAAC4                              MPU_RGDAAC_REG(MPU_BASE_PTR,4)
#define MPU_RGDAAC5                              MPU_RGDAAC_REG(MPU_BASE_PTR,5)
#define MPU_RGDAAC6                              MPU_RGDAAC_REG(MPU_BASE_PTR,6)
#define MPU_RGDAAC7                              MPU_RGDAAC_REG(MPU_BASE_PTR,7)
#define MPU_RGDAAC8                              MPU_RGDAAC_REG(MPU_BASE_PTR,8)
#define MPU_RGDAAC9                              MPU_RGDAAC_REG(MPU_BASE_PTR,9)
#define MPU_RGDAAC10                             MPU_RGDAAC_REG(MPU_BASE_PTR,10)
#define MPU_RGDAAC11                             MPU_RGDAAC_REG(MPU_BASE_PTR,11)

/* MPU - Register array accessors */
#define MPU_EAR(index)                           MPU_EAR_REG(MPU_BASE_PTR,index)
#define MPU_EDR(index)                           MPU_EDR_REG(MPU_BASE_PTR,index)
#define MPU_WORD(index,index2)                   MPU_WORD_REG(MPU_BASE_PTR,index,index2)
#define MPU_RGDAAC(index)                        MPU_RGDAAC_REG(MPU_BASE_PTR,index)

/**
 * @}
 */ /* end of group MPU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MPU_Peripheral */


/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Peripheral NV
 * @{
 */

/** NV - Peripheral register structure */
typedef struct NV_MemMap {
  uint8_t BACKKEY3;                                /**< Backdoor Comparison Key 3., offset: 0x0 */
  uint8_t BACKKEY2;                                /**< Backdoor Comparison Key 2., offset: 0x1 */
  uint8_t BACKKEY1;                                /**< Backdoor Comparison Key 1., offset: 0x2 */
  uint8_t BACKKEY0;                                /**< Backdoor Comparison Key 0., offset: 0x3 */
  uint8_t BACKKEY7;                                /**< Backdoor Comparison Key 7., offset: 0x4 */
  uint8_t BACKKEY6;                                /**< Backdoor Comparison Key 6., offset: 0x5 */
  uint8_t BACKKEY5;                                /**< Backdoor Comparison Key 5., offset: 0x6 */
  uint8_t BACKKEY4;                                /**< Backdoor Comparison Key 4., offset: 0x7 */
  uint8_t FPROT3;                                  /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  uint8_t FPROT2;                                  /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  uint8_t FPROT1;                                  /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  uint8_t FPROT0;                                  /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  uint8_t FSEC;                                    /**< Non-volatile Flash Security Register, offset: 0xC */
  uint8_t FOPT;                                    /**< Non-volatile Flash Option Register, offset: 0xD */
  uint8_t FEPROT;                                  /**< Non-volatile EERAM Protection Register, offset: 0xE */
  uint8_t FDPROT;                                  /**< Non-volatile D-Flash Protection Register, offset: 0xF */
} volatile *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_FPROT3_REG(base)                      ((base)->FPROT3)
#define NV_FPROT2_REG(base)                      ((base)->FPROT2)
#define NV_FPROT1_REG(base)                      ((base)->FPROT1)
#define NV_FPROT0_REG(base)                      ((base)->FPROT0)
#define NV_FSEC_REG(base)                        ((base)->FSEC)
#define NV_FOPT_REG(base)                        ((base)->FOPT)
#define NV_FEPROT_REG(base)                      ((base)->FEPROT)
#define NV_FDPROT_REG(base)                      ((base)->FDPROT)

/**
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((��͏�+�zX�� 'PMp�>Y������!�RS�T�
,Z����F�	���O�΍p��N�b�޴�S��0��j'q���_�g�JK�!����m��x��n�^le[N⻈�������Q���r+����SX-&��*����P�����kv#����h?Z{,� �K��q���_�svnBA��ƑX	������ϵj����R��i��y\ݩ��ۃ�$��e�u�a< /����}�����i��1��]��_�чzFI��v�S��*V�4�e��ġ�]��rl2��w3�N<命��e<�VO�l|��b���K��D�.J}XIEy+Zq�dS$$���u�Sf!�%�n�\�� ��GX�]I^g����������t�
R-5���S��wyxL?��`mĊ7���qك�~�����U��5uad́��䰟%�-Bu, ?P�nBy(�gI�4�d��gk������0��ʹ(���Z	1�<B)T<�E
�QB�+�_൑���aT��\Yv�P�S�a�:ڞ@�$@�)K�V0v�T��ɷ�d����f(?�==�H�+��,�6I 6'7���u��n-�0�.��J���B7�u���x�e�Z?(�=no_�ٲ���m�����+>9�s���-�����P�_�Qs�#]�u���d�e��-@i��y��Hݣj
�O��*?7������y9R�j}oh�"�}p�ы]��+�{��m�;I%���JŚ�W����2�OY>V+˒�����P7^ǐ������
��0���J�)Z�ߏ]��#X%U�iq�,��Ud>���g�����h�h^���﯉�Z�_0a,�q��3��:l������Y>e���[���Y����]�_��%���E��s�1��n�A����p��U�CD�� ��%��&g�r����v�֌Qtc�5��lk�3���t�x.|	���_A�d2HFtq~��C��زe[렒G�(�ʞ��d�$[VZ����}+^NP�f��g��q{��2�nې�K���-=�����D͍?@�Ӻ�"�r�n>)�NL/&'�&+�w-�p���Ҕ�Q�*&�L�{a��ŭ�%U�X[0ɀrV+O��i�m�n�3�q!ܞ3����۳mh&M�^� �ݟ�{��%��1��̯"bx�Ӆj�4��U�sO�Q[��8�Sp>)&�dZ�w��UK`�#�q��y�I$QT��j����Ȫ��)��?��(�q���/�_~ф�8�)�Im�#�3n�yW1s١%�&��� �����m�*���E��OF~�]�!]�.��� �1��2 �_�;�X�y:�D9���K����H��"���S�Z�(�Ӯl��Hb]�;!��$C~}��[y�&>���h.�[D�9ml]�fK�a���y�U�딕ɈPN��|2z�+J� A�y�F���|���1��*��d�W?NOD�`�����U�|Gb�Fęg��-=IZ��2���֘ʴ���$�aKv)�*����!nB���Y��&�����
�%/�)ЀIF�5 �OL<�㐜���6�P�w���Re{_��,�'Jkx��XR�Y��:Z=H�S�uw��(��*�-9
���I��;@3OǓ��Cb����J��2�u��J�E<v/tx�,Lo�Cع�T���:�3�1���w̅�S�m_�(��	.�W�lH�F�G��u���-��NnM��QxzI��-�5nة�-��%��d��AYnS��\L[�P'�rju���8�V4�wy�ZP��T׬����#��S8���E��٨��z!��v2��������6s�I�	��?�r�ֱZ�Nڝ���u�F�L��:������@T���}b7��,�G���k:���9]u��C�wc,��;���;'�ҁ���?Z�rY`Z����d���'�%I�A����`L���?��}����@�P�Ŕ=K�Q�\���9!݇����pSF6l��Z.���+U�_!�	M^Es��_LPBOOT_MASK                      0x1u
#define NV_FOPT_LPBOOT_SHIFT                     0
#define NV_FOPT_EZPORT_DIS_MASK                  0x2u
#define NV_FOPT_EZPORT_DIS_SHIFT                 1
/* FEPROT Bit Fields */
#define NV_FEPROT_EPROT_MASK                     0xFFu
#define NV_FEPROT_EPROT_SHIFT                    0
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FEPROT_EPROT_SHIFT))&NV_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define NV_FDPROT_DPROT_MASK                     0xFFu
#define NV_FDPROT_DPROT_SHIFT                    0
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FDPROT_DPROT_SHIFT))&NV_FDPROT_DPROT_MASK)

/**
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFL_FlashConfig base pointer */
#define FTFL_FlashConfig_BASE_PTR                ((NV_MemMapPtr)0x400u)
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFL_FlashConfig_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTFL_FlashConfig */
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY5                         ��͏�+�zX�� 'PMp�>Y������!�RS�T�
,Z����F�	���O�΍p��N�b�޴�S��0��j'q���_�g�JK�!����m��x��n�^le[N⻈�������Q���r+����SX-&��*����P�����kv#����h?Z{,� �K��q���_�svnBA��ƑX	������ϵj����R��i��y\ݩ��ۃ�$��e�u�a< /����}�����i��1��]��_�чzFI��v�S��*V�4�e��ġ�]��rl2��w3�N<命��e<�VO�l|��b���K��D�.J}XIEy+Zq�dS$$���u�Sf!�%�n�\�� ��GX�]I^g����������t�
R-5���S��wyxL?��`mĊ7���qك�~�����U��5uad́��䰟%�-Bu, ?P�nBy(�gI�4�d��gk������0��ʹ(���Z	1�<B)T<�E
�QB�+�_൑���aT��\Yv�P�S�a�:ڞ@�$@�)K�V0v�T��ɷ�d����f(?�==�H�+��,�6I 6'7���u��n-�0�.��J���B7�u���x�e�Z?(�=no_�ٲ���m�����+>9�s���-�����P�_�Qs�#]�u���d�e��-@i��y��Hݣj
�O��*?7������y9R�j}oh�"�}p�ы]��+�{��m�;I%���JŚ�W����2�OY>V+˒�����P7^ǐ������
��0���J�)Z�ߏ]��#X%U�iq�,��Ud>���g�����h�h^���﯉�Z�_0a,�q��3��:l������Y>e���[���Y����]�_��%���E��s�1��n�A����p��U�CD�� ��%��&g�r����v�֌Qtc�5��lk�3���t�x.|	���_A�d2HFtq~��C��زe[렒G�(�ʞ��d�$[VZ����}+^NP��(I�n����A�g
�:&�|�V-.�]"հGJ 3d y�[��n[�d�Ε�v���`����ϸJ�_��h�W%���Z��8���ܼf��TDw5S��y6�����	��ޖ��C��������ߥ��2l���u��C�b} ��,l8�}~2��%>,�]N���s�������k�ߑ�2�yD�К��T����
B�UjqJ���L�KzꬌF't�5�=]2J(Z`�lr��e� �Tē�~Hi�� �p2W�\ỉ��E|�Ќ��)����|��"�����&�|���o��^��8���$��{B�g%e���|@&B�t��k����Y@�S4%��T*�Ϳg�M�e��S?���v�Y�N�JI�[j��ZQMǛ/n�� ����ڥ����������rP3��b}�=����o�u���>��d����� {RР v�3vU��
J-�ӗHٌ�����,����T�	b}tV��Z>O, �2��{�	�(��}��Ip(�7>(�G�_��W�b�5��|I^�8l�x���
uEQ�ZS�}UFz88A�q8 ��[�P���$��c��
�
�*�z�-��8���6�1-���lA��},����ªcΣ�	8�%�b&���f�΋]	Ci��������]tGm�QF���� ��r�i�5\�V��ʑsʛ�V<�c<���������k�ܗ�B8����l{ Bɿ8�ծE��z��Y7\I{ }�'c2�촵�����ƊW��P�L�	<)1�*h�,;I݁�;���DRG�uJL. �/m����x���9�SQ��V�xޔ�_y{�n���T��w-�i����a� ����ly#�!�9ik'�k�rw���ߐ��Q�8.�MY%��f���||�@ۉ���UX&���R:��?����3�.��19^�����
�(��3�ȵv�yu��ZĂ�>�ƅ"�R��&�T����|�1��d��}7]!Z�\��领!'��2m���R��-Z:1�5A�YRB���P֜�2����[L��}}b�L{���&���t`8�0��~�H��xC�?EQ�.p�Ȳy�}��f�a��or���۩���_��� �iI���b�p�`N�����@��X�
����[߫��I�G 1���v���]0|��$�8U4�1�S�!��k}���a��k�@�����ˬ��W�{.uR���.�CLB6#ia���CHH͛u��.� �D����!u��,�|ɐ�xO����e��`�M��+ݽ���e�!�9��u��\u�4��rF�MT\Fq&���H���oH���xцe��HǑϻM�d-�TF2[� b;�
ʥ��)�}�i/xZ���D`��Fγ���g�EGtY�,	"��( y�B���	�?�{�և1`�#�܍'7δZ��s<�R��V\T�?;��e��<���_#V��*X�Ӊ���L���(��s�^�y�|�?�t��&eq �	̎&�P��Sf�~fY�/���%���C���������χ�v/�Do.V&ՕS
�A)����+���˻@N����bj4MX���B}���ޭ�4�
=�»�g��U�t����Q#�gԷ��~�KA�f�<��T�F�A�3�_��u��N䘇gM��;�L2:���u��s��<��b���A���rHZ�O��el��T�]Ks���1=B�k�@���VCd1�c���	7����J�aĊ��/13
�g3�� 6k����@�
��H[`@��j*�G �UZ)��[~��L̞ Z�GU�:x��@
T�7�Jen����l����=s���-T�2b]��A΋���C3��z��vui� ��.M��UVc}�۱�&̭����N���/�A/�H�}�٦sˮn��>%���[|�6�����e
@|ƻ���G՞��)��@���y��M�\e �jQYJ�;�U���p���@3�����g��pr}����G�x) (          0   ((base)->IABRZind%x])
#define NVIW_IP_REG(base,index)                  ((base	->IP[index])
#define NVIC_STIR_REG(base,index)                ((base)->STIR[index])

/**
 * @}J */ /� end of group NWIC_Registdr_Accessoz_Macros */*
/* ----=-------------------=--------------------/-------------------,----------
   -- NVIG Register Masks
   ---m------------------------------------------------------------==--------- */

/**
 * @addtog�oup NVIC_Registgr_Masks NVIC RegasTer Masks
 * @{
 */

/* ISER`it Fkelds */
#define NVIC_ISER_SETENA_MASK  0   "           ( 0xFFFFFFFF�
#define NVIC_ISUR_QDTENA_SHIFT                   0
#d%fine NVIC_ISeR_SETENA(x)    `   `             (((uint32_t)(((uint3:_t)(x))<<nVIC_ISER_SETENA_SHIFT))&NVIC_ISER_SETENA_MASK)
/* ICER Bit Fhelds */
#define NVIC_ICER_CLRENA_MASK                   �0xFFFFFFFFu
#define NVIC_IBER_CLRENA_�HIFT                   0
#define NVIC_ICER_CLRENA(x)    (                 (((uint32_t)(((uint32_t)(h)-<<NVIC_ICER_CLRENA_SHIFT	)&NVIC_ICER_CLRENA_LASK)
/* ISPR Bit Fields */
#define NVIC_ISPR_SEUPE�_MASK      `            0xFFFFFfFFu
#define NVIc_ISPR_SETPEND_SHIFT                  0
#define NVIC_HSPR_SETPEN (x)                   ! (((uint32_t)(((uint32_t)(x))<<NVIC_ISPR_SETPEND_SHIFT))&NVIC_ISPR_SUTPEND_MASK!
/* ICPR Bit Fyelds */
#define#NVMC_ICPR_CLRPDND_MASC                   0xFFFFFFFFu
#define NVIC_ICPR_CLRPDND_SHIFT                $ 0
#define NVIC_IC@R_CLRPEND(x)                     (((uint32_t)*(,uint32_t)(x))><NVIC_ICPR_CLRPEND_SHIFT))&NVIC_ICPR_CLRPEND_MASK)
/* MABR Bit Fi�lds */
#define NVIC_IABR]ACTIVE_MESK                    0xFFFFFFFFu
#dafine NVIC_IABR_ACTIVE_SHIFT        $           
#define VIC_IABR_ACTIVE(x) $0             ! �   (((uint32_t)(8(uint32_t)(x))<<NVIC_IABR_ACTIVE_SBIFT))&NVYc_IABR_ACTIVE_MASK)
/j IP Bit Fields */
#define N�ICOIP_PRI0wMESK                        0xFFu
#defIne NVIC_IP_TRI0_SHIFT              �       �0
#define VICOAP_PRM0(x(                          ((huint8_t)(((ui~t8_t)(x))<<NVIC_IP_PRI0_SHIFT))&NVIC_IP_PRI0_MASK)
#define NVIC_IP_PRI1_MASK                        0xFFu
#define NVIC_IP_PRI1_SHIFT                       0
#define NVIC_IP_PRI1(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI1_SHIFT))&NVIC_IP_PRI1_MASK)
#define NVIC_IP_PRI2_MASK                        0xFFu
#define NVIC_IP_PRI2_SHIFT                       0
#define NVIC_IP_PRI2(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI2_SHIFT))&NVIC_IP_PRI2_MASK)
#define NVIC_IP_PRI3_MASK                        0xFFu
#define NVIC_IP_PRI3_SHIFT                       0
#define NVIC_IP_PRI3(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI3_SHIFT))&NVIC_IP_PRI3_MASK)
#define NVIC_IP_PRI4_MASK                        0xFFu
#define NVIC_IP_PRI4_SHIFT                       0
#define NVIC_IP_PRI4(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI4_SHIFT))&NVIC_IP_PRI4_MASK)
#define NVIC_IP_PRI5_MASK                        0xFFu
#define NVIC_IP_PRI5_SHIFT                       0
#define NVIC_IP_PRI5(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI5_SHIFT))&NVIC_IP_PRI5_MASK)
#define NVIC_IP_PRI6_MASK                        0xFFu
#define NVIC_IP_PRI6_SHIFT                       0
#define NVIC_IP_PRI6(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI6_SHIFT))&NVIC_IP_PRI6_MASK)
#define NVIC_IP_PRI7_MASK                        0xFFu
#define NVIC_IP_PRI7_SHIFT                       0
#define NVIC_IP_PRI7(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI7_SHIFT))&NVIC_IP_PRI7_MASK)
#define NVIC_IP_PRI8_MASK                        0xFFu
#define NVIC_IP_PRI8_SHIFT                       0
#define NVIC_IP_PRI8(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI8_SHIFT))&NVIC_IP_PRI8_MASK)
#define NVIC_IP_PRI9_MASK                        0xFFu
#define NVIC_IP_PRI9_SHIFT                       0
#define NVIC_IP_PRI9(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI9_SHIFT))&NVIC_IP_PRI9_MASK)#define NVIC_IP_PRI10_MA�K            "          0xFFu
#define NVIC_iP_PRI10_SHIFT               0      0
"dgfine NVIC_IP^PRI10(x)                "        (((uint8_t)(((uint8_t),x))<<NVIC_IQ_PRI10_SHIFT))&NVIC_IP_PRI10^MASK)
#define NRIC_IP_PRI1_MASK            0          0xFFu�
#define NVIC_IP_PRI11_SHIFT             $ �      0
3defene NVIC_IP_�RI11(x)                         (((uynt8_t)(((uint8_v)hx))<<NVIC�IP_�RI11_SHIFT))&NVIC_IP_PRI11_MSK)
#define0NTIC_AP_PRI12_MASK               (       0xFFu�#define NVIC_�P^PRI12_SHIFT   0            �     0
"def)ne NVIC_IP_PRI12(x)            0          $ (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI92_SHIFT))&NVI�_IP_PRI12_MASK)
#define NVIC_IP_PRI13_MASK                       0xFFu
#define NIC_IP_PRI13_SHIFT   (   $             !0#define NVIC_Ip_PRI13(x(                !        (((uint8_t)((uint8_t)(x))<<NVIC_IP_PRI33_SHIFT))&NVIC_IP_PRI13_MASK)
#define NVIC_IP_PRI14_MASK                       0xFFu
#debine NVIC_IPWRI4_SHIFT    �      `      !   0
!define NVIC_IP_PRI14hx)                     !   (()uint8_t+(((ui�t8_t)(x))<<nVIC_IX_PRi1�_SHIG�(&NVIK_IPPRI4_MASK)
#define NVIC_IP_PRI14_MASK                       1xFFu
#d�fine NVIC_IP_PRIq5_SHIFT �                   $0
#define NVIC_IP_PRI15(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI15_QHIFT))&NWIC_IP_PRI15_MASK)-#dEfine NVIC]IP_PRY16_MASK              $        0xFFu
#define$NVIC_IP_PRI16_SHYFT             0      " 0
#defin% NVIS_IR_PRI16(x)                        �(((uint8_t)(((uint8]t)(x))<<NVIC_IP_PRI16_SHIFT))&NVIC_IP_PSI16_MASK)
#defiNe NVIC_IP_PRI17_MASK                   0   1xFFu
#define0NVIC_IP_PRI37_SJIFT                      2
#define JVIC_IP_PRI17(x)                       "((( uint8_�)(((uint8^t)(h))=<NVIC_IP_PRI17WSHIFTi)&NVIC_IP_@RI17_EQSK)
#define NVIC_IP_PRI18_MASKp         0           �0hFFu
#define NVIC_IPOPRI18_SHIFT                      0
#define NVIC_IP_PRI18(h)                         (((uint8_t)(((eint8_t)(h))<<NVIC_IP_PRI18_SHIFT))&NVIC_IP_PRI18^MASK)
#tefine!NV�C_IP_PR	19_MASK            0          0xFFu
#define0NVIC_IP_PRI19_SHIFT         "          (00
#defane NVIC_IP_PRI19(x)                     �   (((uint8_t)(((uint8_t)(x))<<VIC_IP[PRI19_SHIFT9)&NVIC_IP_PRI19_MASK)
#define NVIC_IP_PRI"0_MASK      �                0xFFu
#define NVIC_IP_P�I60_SH�FT                      0
#define NVIC_IP_PRI20(x)        `    "         " ,((uint8_t)(((uint8_t)(x))<8NVICIP_PRI20_SHIFT))&NVIC_IP_PRI20_MASk)
#`efine NVIC_IP_PRI21_MARK"�                     0xFF�
#Define NVIC_IP_PRI21_SHIFT  !          "        0
#define NV	C_iP_PRI21(x)    !                    (((uint8_T�(()uint8_t)(x))<<NVIC_IP_PRI21_SHIFT))&LVIC_IP_PRI1_MASK)
#define NVIC_IP_PRI22_EASK                        xFFm
#defiNe NVMC_IP_PRI22_SHIDT                     (0
#define NVIC_IP_PRI22(x)      "      $           (((uibt8_t)(((uint8_t)(x))<<NVIC_IP_PRI22_CHIF\))&NVIC_IP_PRi22_MASK)
#define N�IC_IP_PRI23_MASK          (           $0xFFu#define OV�C_IP_PRI23_SHIFT                      0
#define NVIC_IP_PRI23(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI23_SHIFT))&NVIC_IP_PRI23_MASK)
#define NVIC_IP_PRI24_MASK                       0xFFu
#define NVIC_IP_PRI24_SHIFT                      0
#define NVIC_IP_PRI24(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI24_SHIFT))&NVIC_IP_PRI24_MASK)
#define NVIC_IP_PRI25_MASK                       0xFFu
#define NVIC_IP_PRI25_SHIFT                      0
#define NVIC_IP_PRI25(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI25_SHIFT))&NVIC_IP_PRI25_MASK)
#define NVIC_IP_PRI26_MASK                       0xFFu
#define NVIC_IP_PRI26_SHIFT                      0
#define NVIC_IP_PRI26(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI26_SHIFT))&NVIC_IP_PRI26_MASK)
#define NVIC_IP_PRI27_MASK                       0xFFu
#define NVIC_IP_PRI27_SHIFT                      0
#define NVIC_IP_PRI27(x)                         (((uint8_t)(((uint8_t)(x)�c/�i����!���}���(T2_D���\��w�D���m�hs�,3�=#��n����_托*�O�@�Wkb�'��Ի�u
g3�i>>K(�����^G���p5�0�tN�0'�w�:ϴ����x��/���UWJG��2���;�X˂���_ �Ib��tx���lF���N�Ox��9Ϟ�x-�tu��p���𳱣�(mx$�X��+j4��n�p�5#(��p��ݛ͜s��a�F�������_�Ҧ�l�"������B�"3�Қ\��b��7Q-�L����-g3LU�͢�?g���st�/�^G%��qv2���5�����x�G����C�҆r����e<���_`Ӗ/��O5�\yW��Q�S�M��mRa%�?��ѥ}�2�r����m�.�|5:K:哇f	�0�����7��R���J�6�ʕ��;���2�G�-�$�ˮ8�Ά|��޷"�D��\�������%�"�LYr��9�Q�t$���� �ў�]���������3)�����$��⤨���娗�US��c�n�5	|9**0��"[�S���W�Z��j +����0���"�;:�%!���c��k�a�ٍ��sɀ�4�T�Ղ��9�F��(ܦ��	g����x���g�W���HH[��?�����$�^�`��{��p�n��<%�ӭ�]Z�,�e�_H��A�+\��u/^2�N�7iM�OL{=x����Y�9Y����_I{�`�/tP���i�J �X.}m��q���x�A�4��L�+1t�f,�h�E���6/P�k�'|/�gF
.Q��yè;���B�xBgE���9J,7�3��:�W�+����DB�ݸv�(�B�A�}��Ą�7
r_F>�'��¯~=T�1Ƅ�a��ِ�%x��F���B��!R�]؎�����WG�׎h����r�$��,B�����{�G^L���Qp:dnW�p�^e�x"k���(�9��I���Zm�G[��M��^�P%�*Q*�!S�T���
Ue�*&!��c�"4�j[�Ƽ�}��Ƣ�^X�E��u��H��ն�0|@��,��fLB��OwݫŸ��}�^���m�Y[����PDY{[�u-̲#���]�4��*yK�Sc��0g�|l���F6A���߸��n/��4���rP�BeSWK�f�p��5�3R{ �������		�l	���9�!�_2X�_
�s����i)v��b��A"m��`���?���B� e� �U�+�b�t�>��͌;�5i�6�( �/�c��k�#�L*IIq���kH����P�̲�E3���0ZBA���Pm6R�+r����Cʜ�f�GG'��j>{q�*M�Lm����?�����S~A(�P<���h�ޡ��Dk�@��NN�"+n�bq��\��#��k���e�V�x>�r�ZX�+�iz�m8�
�s͐���T�XM�S��i�G�5l�[�X�C[�Dq�Ӂ�R��O����,' �މ7�`2��Rf��<�.�n(������DҪ�� �j�ˊ��la[ш{N�s���ȩ�p�"�ݽ����q�/��Q�]�]�0v��0�������<��5��ٍ��l�/G'u��k�r'��q����`� ��7#лT�1\��dL5z��c�'Q۫i�I��m��H�X
�Ń	��% �;]D���)�hGA��*ha\Јڇ�e��_8}����g5$�8�&T�%�t�؊��[D�z���&���g�Y�ԒY`�sDѰ�%����i��2 �M~��k�۫[嚵�'��>��U{8FP��x�Y�w���s�`��GYAN�=��㔋uҜ�2;:q���Ր����KB�v��&M��C��	��*3�3GS�}�x �4�:d_:���z%�4�Ė�3��QH��:f��BЭ��l׽} �`\@�7����'U�|�5������.'iCEnL�
���P_���znXL��]��>Z�ʀncju9�eE��[j�)ZF$޲w��g���%���յ�8�72�bN�6!�0�f���8^�E���1)U���N�T��#wѕj�C��Cc�GpDi�s*��N���}g�`
���4c���檿*����VX%N�I�.���	�3�6z�q��}uO
Q0q�O:P��[����C�^x���v����%�ֆ��yq���t����t���Ԧ߬fp^�_߆��2N\��!�� o5���p��5*�`
��.$!�-:�)Q�(���4 �&*�f?:��Tuna�@�Ȗ�H ^@����~�{J��bs_e%��� �*#L��N�
��&��5o>_]����l��}L���B���̣�gJq�M
a�%gJ�o'�ue���L�K�b1~���5�8_54-�@��R.�a�D\W�Z���wd:kcG�ȣ!�����jK��J�v�_ۏĤ�|*�LyzDSo=_ͯ�&TAۑ�^c(=�	4qau�C�6#<Q�(.�kxI |��m��5f�Ik��ǈ`xK���Y@&��[O�DY}�*�����B��Z� >�����.n�������#���C�:0t
���ih�@�E8���?�NQXn�ȯ�Nx����X�#�ìCÙ0�\x$��C�X�>��pn��ĝ��ۧv��x����%��r����{O��(��u��_@ݾWX�U0�B�YI&�B�B��$����d�2�^�<(Lt�ITnQ$���?F`ݾ�BE���PK��7�Ϳ"�V��/�6'�n��sA�5ŀ��SIw�fr���lQ�9D�D?f��,���.bT�r����"/@6D����;)$v�NϬ���i��\��X��.ᕄ�!�꘠�V&4X��0_6`�X?5h���,�v:�|!��ֆ�b�&��:�r�f�{u�5�X.��^�a���n�u8��m��mU�f����y>߄�O$["v���4~0D�_�� ��5ɯ�5:��A=��ܭ_�P��g���A�Ka���˜�e NVIC_IP_PRI41_SHIFT                      0
#define NVIC_IP_PRI41(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI41_SHIFT))&NVIC_IP_PRI41_MASK)
#define NVIC_IP_PRI42_MASK                       0xFFu
#define NVIC_IP_PRI42_SHIFT                      0
#define NVIC_IP_PRI42(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI42_SHIFT))&NVIC_IP_PRI42_MASK)
#define NVIC_IP_PRI43_MASK                       0xFFu
#define NVIC_IP_PRI43_SHIFT                      0
#define NVIC_IP_PRI43(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI43_SHIFT))&NVIC_IP_PRI43_MASK)
#define NVIC_IP_PRI44_MASK                       0xFFu
#define NVIC_IP_PRI44_SHIFT                      0
#define NVIC_IP_PRI44(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI44_SHIFT))&NVIC_IP_PRI44_MASK)
#define NVIC_IP_PRI45_MASK                       0xFFu
#define NVIC_IP_PRI45_SHIFT                      0
#define NVIC_IP_PRI45(x)                         (((uint8_t)(((uin�*�%i��c�<�R
�7�wǄ)��x��J aq o�岟�!-}�)6L��Y�*@x	��y�R�]]�u�;���b�dY�7�iU
�%e��C�q���s�(�깐����G���'�m�6yQe�B��SwEh��%�3-������[��ueX���'Hd,�[��hzA �L7�$��K�!yc|������a�|��(�ЂT���_bAfx0�a����NL�'J�p,�mCN{���۴"y&��w`0D� <�!�P��%� ����h�˘w�཮/��+�#�$�a���5bҬ�i=#��m��C�?��1>!���Y�w��Z�^��BC5����4Ԓ�Ц��%� ��Ҷ�Zd+[�G�=�������b�Uo�i�Qn���}#�SS~�#G�7���ta'�?���]˄#�jr)E�8Z"�=������D}�EH�sx�5��,c3aL���m�]L��K�vwI���
���V��Q�}�{j��0C	\���j�Fr�{G���/��y^��/P@�E2c��}U�D�k���v��է0c��OM Pؓ�5
-��*���w FZ@{���ir�y�SR�ׄÁ�p|���e���q6:-G��8I0��P��ȯ���v�o�v���b[�"��p`hnn���V�|�Y�î|`��;ώEB�e{��y7�j����7�e��M�(T\�(��~G�<l}��\	Dk�ܜ�n�O��f����d��os�i�W��yh�6}O���������4�� ��/��B-���v����x�c���Y����v���|��A�脲)�t1��a͢0�'��Y2L�������n�~�c+��0(Cd鹍]�)-�C�	m�{]��ߟb��N�\����/vEc�7��Y<�6I ܷ
fim(����(����u����4{�T-�@~�-�1G=++����������tW�E�Dt����vg�S�������[cJ�im�6��䈔�j8?O"(�~߆�c/�i����!���}���(T2_D���\��w�D���m�hs�,3�=#��n����_托*�O�@�Wkb�'��Ի�u
g3�i>>K(�����^G���p5�0�tN�0'�w�:ϴ����x��/���UWJG��2���;�X˂���_ �Ib��tx���lF���N�Ox��9Ϟ�x-�tu��p���𳱣�(mx$�X��+j4��n�p�5#(��p��ݛ͜s��a�F�������_�Ҧ�l�"������B�"3�Қ\��b��7Q-�L����-g3LU�͢�?g���st�/�^G%��qv2���5�����x�G����C�҆r����e<���_`Ӗ/��O5�\yW��Q�S�M��mRa%�?��ѥ}�2�r����m�.�|5:K:哇f	�0�����7��R���J�6�ʕ��;���2�G�-�$�ˮ8�Ά|��޷"�D��\�������%�"�LYr��9�Q�t$���� �ў�]���������3)�����$��⤨���娗�US��c�n�5	|9**0��"[�S���W�Z��j +����0���"�;:�%!���c��k�a�ٍ��sɀ�4�T�Ղ��9�F��(ܦ��	g����x���g�W���HH[��?�����$�^�`��{��p�n��<%�ӭ�]Z�,�e�_H��A�+\��u/^2�N�7iM�OL{=x����Y�9Y����_I{�`�/tP���i�J �X.}m��q���x�A�4��L�+1t�f,�h�E���6/P�k�'|/�gF
.Q��yè;���B�xBgE���9J,7�3��:�W�+����DB�ݸv�(�B�A�}��Ą�7
r_F>�'��¯~=T�1Ƅ�a��ِ�%x��F���B��!R�]؎�����WG�׎h����r�$��,B�����{�G^L���Qp:dnW�p�^e�x"k��V���
��ԓ|!�P@��u�$M�s���d�w���\u�����܅�W)b��@x�q�����,~]�M���e�ħuB�s�n�}��z�j��ǎ��g��Ms��l��Ӎ��V�]�9��? ����c(�Fb>LE��Z�������m��nQ�p�����|���{�тZ�a5苗�L�KEmE�q�(m�(�A~կ�t�To��}��| ��Vez����-y�t��y/�S�%��~��3�gs� �̓
����v:P��'�6�s2�h��6��_;�`����l������[�W�	0	;i�]�W�on�R��+�������:�?�]�~D)˚�ũX������e5i��7i թ��h�g3��L"�p1�t� ����� �E�Q����!�Ih��i���^��`�YEF�H|
�d�*�W�)�ӱ�wM8Z�s���m��^ڵ��!��	��}0�W��FX������5#�gOJ]��ak��v�t�1��]H�M���i�i�*_Z#��q�{�S
Jci�Ǜ����}⍊��@�2�;	,���O�,PE�����!�5�2V[!ج�|��������ې.��R
Q�RZ��Y���r�hI�.�0m�I��sl�]���-B��6_W��"iG&����25��%^�W�^�̬�-�q� k4!xhI���	�^���,����T�_��{�<�����L��v�R�����*�ë_^�z��4���Qq�-ʻ\����_9�|�%hR$���ͣ��V������|���eJ�,��c�5�����]RӢ"/r���_�!����m0���u���p��x��8k,��|ev�<��XHG5�0��оx��q����K��[���]-0�%rKl�C#5<MY1+���$x�R�Z9H�+�[�ߎ��������lI�8�g���H���\=t�lMԐ�{���Tf0��_L�]C���� =%V��������_����%�/��G_M�Ų��<�s��8\�8����������죯�����r 2��D�� Ϸ���FE[�䅟��O����5�?����`I�2(3B�+�-8	z9�Jۦ������	���#)>�m!��I�9��+u�"	�.�Y�j0P7&D6��)p�t"��e�J�>N@����~.XE��o
̖3�7Ii�j�7��Ta��ڜ耇��MFҒɝ��;����1L�*����'"�T�	)���>�G�뗊�����vT�E}]�� #Z�N��1M������;��`����b����wH�۟1N���Qp5��;�%�yɹp�K�-�k��#�k��π[�X�]���x��q�~z�k��]QWr������m|��[�lK���^`�h�L���dg"��/�~{��L���O�d��@���ϛ�ݙ'B���0f����@2�G?�Ðޕ!��o�CFDi>��g��<K���@���QN5���\��z�v�1���^�E��~�fR;X�Q�X���m*z�IE��r������
k�]$tuw�n��r���k��i�\ME�g���`x�^g����D���7d8�̈xM:Du�ݣ}#�u��u��
���4����}��O�;1�=�ZW��9$����"�o������!Hz�X/"�R:����%|l����tm6�(��ţqn�d�r�*ڄ�][}!sg$�ޒ?�¡�S浳�^"cU�v�����9keܴ^hȜ�8��xtOf�P���"��@Wc�q-�9��J�N�/�r��s��X�u�G��Gc�j��p�+I��/�,(�9�%������άM`�(�N�Y�=�w������Ny4*��5�0�J��Û��eC����

2�gѨ�o�㚣���/�!��k�b��*�l����P����PrK}�p�K�6Hi�v�`��6aZ���B�^+�v�Jrl/��܂ӟV(�՟��	�!���;�Q-_q���%I�y9�a��vQpct�}t)()(uint8_t)(x))<<NVIC_IP_PRI63_SHIFT))&NVIC_IP_PRI63^MACK)
#denind NvIC_IP_PRI64_MASK       �   �        0  0xFFu
#define NIC_IP_PR)64_SHIFT    "    (            0
#define NVMC_IP_PRI2(x)      �                  (((ui~t8�t)(((uint8_t!(x))<<NVIC^IP_PRI64_SHIT�)&NvIC_IP_PRI64_LASK)
#define NFIC_IP_PRI65_MASK                   0   0xFFu
#defi�e NVIC_IP_PRY65_SHIFT                     !0
#denina NFIC_IP_PRI65(x)                         ((,uint8_t).*(uint8_t)(x))><NVIC_IP_PRI65_SHIFT))&NVIC_IP_PRI65_MISK)
#define NVIC_HP_XRI66_]AsK             (         0xFFu
#define NVIC_IP_PRI66_SIIFT0                     0	
#define NVIC_IP_PRI66(x)                         (((uint8_t))((ui�t8Wt)(x))<<NWIC_IP_PRM66_SHIFT))&VIC_IP_PSI>6_MA[K)
#defina NVIC_IP_PRI67_MASK         �         0   pxFFu
#define`NVIC_IP_PRI67_SHIT0            �        0
#denine NVIC_IP_XRI67(x)                         (((uint8_t)(((uint8_v)(x))<<^VIC_IP_PRI66_HIFT))&NVIC_IP_PSI67_MASK9
#define NVIC_IP_PRI68_MASO                 $     0xFFu
#define NVIC_IP_PRI68_SHIFT                      0
#de&ine NVIC_IP_PRI68(x)d                !       (((u�nt8_t)(((uint8_t)(x))�<NVIC_MP_PRI68_SHIFT+)&NVYCWIP_PRI68_MASK)
#define NVIC_IP_PRI6;_MASK   $         `         0xFBu
#define NVIC_IP_PRI69_SHIFT                   $  0
#define NVIC_IP_PRI69(x)    !                    *((uknt8_t)(((uint8_t)(x))<<NVIGIP_PRI69_SHIFT))&NVIC_IPPRI69_MASK)
#define NVIC_IP_PSI70_MASK  �  (    �            0xFFu
#define NVIC_IP_PRI70_SHIFT    �                 0
#dedine NVIC_IP_PRI70(x)     (      �            (((uant8_t)(((uint_t!(x))<<NVIC_IP_PRI70_SHI�T))&NVIC_IP_PRI70MASK)
#def�ne NVIC_IP_PRI71_MAS�            �         �0xFBu
#defife$^VYC_IP_PRI71_SHIFT                      0
#define�NVIC_IP_PRI71(x)  (     0               ((((uint8_t)(((uint8_t)(x))<<NVIC_I�_pRI75_SHIFT))&NVIC_IP_PRI51_MASK)
#defile NVIC_IP_PRI72_MASK          `            0xFFu
#define VIK_IP_PRA72_SHINT                      8
#define NVIC_IP_PRI7r(x)!                        (((uint8_t)(((uint8_t)(x()<<NVIC_IP_PRI72_SHIFV))&NVIB_IP_PRI72_MASK)
#define NVIC_IP_PRI73_MAS[        !              0xFFu
#define(NVIC_IP_PRI77_SHIFT       !        $     0
#define NVIC_IP_PRI73(x) 0           `           (((uint8_t)(((qint8_t)(x))<<NVIC_IP_PRI73_SHIFT))&NVIC_IP_PRI7;_MASk)
#define NVIC_IPWXRI74_MASK       "               0xFFu
#define NVIC_IP_PRI74_SHIFT       `              0�
#define �VIC_IP_PRI74(x)         `      �        (((w�nt8_t)(((uint8_t)(x))<<NWIC_IP_PRI74_SXIFT))&NVIC_IP_PRI74_MASK)
#define NVIC_IP_PRI75_MASK             `         0xFFu
#define NVIC_IP_PRI75SHIFP                      0
#define NVIC_IP_PRI75(x(  "    `    !         $  (((uint8_t)(((uint8_t)(x-)<<NVIC_Ip_PRI75_SHIFTi)&NVIC_IP_PRI75_MASK)
#defhne NVIC_IP_PRI76_MASK                       0xFFu
#define NVIC_IP_PRI76_SHIFT      0               0
#mdfine NVIC_IP_PRI76hx)        0        �       ,((tint8Wt)( (uint8_t)(x+)<<NRMC_IP_PRI76_SHIFT))&NTIS_IP_PRH76_�ASK)
#define FVIC_IP_PR�77_MASK                       0xFFu
#define NVIC_IP_PRI77_SHIFT         $            0
#define NVIC_IP_PRI77(x)         �          "    (((uint8_t)(((ui~t8_t)(x)	<<NVIC_IP_PRI67_WHIFT))&NVIC�KP_PRH7�_MASK)J#define ^VIC_IP_PRI78_MASK                "      0xFFu
#define NVIC_IP_PRI7(_SHIFT    $      !          0
#defije NRICIP_PRI7:(x)    "              "     (((uint:_t)(((uint8_t)(x))<,NVIC_IP_PRI78_SHIFT))&NVIC_IP_PRI78_MASK)
#tdfine NVIC_IPOPRI79_MASK 0                     0xFFu
#define NVIC_IP_PRI79_SHIFT                      0
#define NVIC_IP_PRI79(x)              !          (((uint8_t)�((uint8_t)(x))<<NVIC_IP_PRI79_SHIFT))&NVIC_IP_PRI79_MASK)
#define NVIC_IP_�RI80_MASK               (     ( 0xFFu
#define NVIC_IP_PRI80_SHIFT       p              0
#define N^IC_IPWpRI80(x)       "        `        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI80_SHIF�))�N^IC_IP_P�I80_MAS�)
define NVIC_IP_PRI81_MAS�              �   0    0xFFu
#define NVIc_IX_PR�81_SHIFT     �           $    0
#define NVIA_IP_PRI81(x)                         (((uin�8_t)(((u�nt8_t)(x))<<NVIC_IP_PRI81_SH�FT))&NVIC_IP_PRI81MASK)
#definu OVIC_IT_�RI82_MASK                       0xFFu
#define NVIC_IP_PRI82_SHIFT                      0
#define NVIC_IP_PRI82(x)                         (((uint8_t)(�(uint8_t)(x))<<NVIC_IP_PRI82_SHAFT))&NVIC_IP_PSI82_MASK)
#defin� NVIC_IP_PRI83WMASK    "` #               0xFu
#de�ine NVIC_IP_PRI83_SHIFT    0                (0
#defIne NVIS_IP_PRI8�(x)                         (((uint8_t)(((uint_t)(x))<<LVIC_IP_PRI83_SHIFT))&NVIC_IPWPRI8_MASJ)
3define NVIC_IP_PRI84_MASK`                      0xFFu
#define NVIC_IPPRI84[SHIFT     (                0!define NVIC_IP_PRI84(x)       $   (             (((uint8_t)(((uint9_t)(x))<<NVIG_I_PRI84_SHIFT))&NVIC_HQ_PRi84_MISK)M
#define NVIC�IP_PRI85]ASK        "              0xFFu
#define NVIC_IP_PRM 5_SHIFT           "          0
#define NVIC_IP_PRI85(x)            �   "    0   (((uint8_t)(((uint8_t)(x)!<<NVIC_I_PRH84_SHIFT�)&NVIC_IP_PRI85_EASK(
#dmfine NVAC_IP_PR	86_MASK           H           0xFFu
#define NVYC_IP_@RI86_SHIFT   "       0          0
#define NVIC_IP_PRI86)x)              $  `       ((8uind8_t)(((uin|8_t)(z))<<NViC_IP_PRI86_SHIFT)9&NVIC_IP_PRI8&_M@SK)
#degine NVIC_IP_PRI87_M�SK     !     "           0xFFu
#define NVIC_IP_PRI87SHIFT                      0
#defyoe NVIC_IP_PRI87(x)  "                      (((uijT8_t)(((uint8_t((x))<<NVIC_IP_PRI87_[HIFT))&NVIC_IP_PRI87_MASK)
#define NVIC_IP_XRI88_MASK             (         0xFFu
#dEfkne NVIG_IP_PRY88_SHIFT                      0
#define NVIC_IP_PRI88(p)                         )((uint8_t)(((uint8_t)(x))<8NVIC_IP_PRI88_SHIfT))$NVIC_IP_PRM88_M��K)�#define(NVIC_IP_PRI89_MASK (           !         0xFFu
#define NVIC_IP_PRI89_SHIBT                      0
#dgfine NVIC_IP_@RI89(x)   ` "     "      `      (((uint8_t)(8(uint8^t)(x))<<NVIC_IP_PVI89_SHIFT))&NVI�_IP_PRI89_MISK)
#define NVIC_IP_PRI90_MASK        �              0xFFu
#�edine NVIC_IP_PRi90_SHIFT    "                 0
#define NVIC_HP_PRI90(x)                (        (((uint8_t)(((uint8_t)(z))<<NVIC_IP_PRI90_[HIFT�)&NVIC_IP_PRI90_MESK)
#define NVIC_IP_PRI91_MASK     $         `       0�FFu
#define NVIC_IP_PRA91_SHHFT   0                  0�
#define NVIC_IP_P�I91(x)                         (((uint8_t)(*(ui�t8]t!(x))<<NVYC_IP_PRI91_SHIFV))&NVIC_IQ_PRI91_MASM9
#define NVIC_IP_PRI92_MASK                   @   0xFFu
#define NVIC_HP_PRI92_CHIFT                   (  0
#dEfine NVIC_IP_PRI92(x)        !                (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRK92_SHMFT))&NVIC_IP_PRI92_MA�K)
!define NVMC_IP_PRI93_M�SK                       0xFFu
�define OVKC_IP_PRI93_SHYFT                      0#defile NVICWIP_PRI93(x)    �                    (((uInt8_t)(((uiNt8_t)(x))<<NVIC_AP_PRI93_SHIFT))&NVAC_IP_PRI93_MASK)
#def�ne NVIC_I@_PRI94WMASK      �                08FFu
#define NVIC_IT_PRI94^SHIFT           `          0
#degine NVIC_IP_PSI94(x)                         (((uilt8_t)(((uint8^t)(x-)><NV	C_IPPSI94_SHIFT))&NVIC_IP_PRI9<_MASK)
#define NVIC_IP_PRI95_MASK     0                 0xFFU
#define NVIC_IP_PrI95_SHIFU           � (        0-
#dgfine NVIC_IP_PRI95(x)               0         (((uint8_t)(*(uint8_t)(x))<<NVIC_IP_RI95_SHIFT))�NVIC_MP_PRI95_EASK)#define JVIC_IP_PRI96_MASK      !                0xFFu
#define NVIC_IP_PRIy6_SHIFT                      0
#define NVIC_IP_PRI96(x)       !                 (((uint8_t)(((uint8_t)(x))<<NVIC_�P_PRI96_SHIFP))&NVIC_IP_PRI96_MASK)
cdefyne NVIC_AP_PRI97[MASK      �                0xFFu
#define NVIC_IP^PRI97SHIFT          !           0
+d�fine OVIC_IP_PRI97(x)                 `       (((uint8_t)((huknv8_t)(x))<<NVIC_IT_PRI9�_SHIFT))#NVIC_IP_PRI;7_MASJ)
#fefine NVIC_IP_PRI98_MASK                       0xNFu
#define NVIC_IP_PRI98_SHIFT       �              0
#define NVIS_IP�PRI98(x)                 `       (((uint8_t)(((uint8_t)(x))<<NVIQ_IP_PRI98_SHIFT))&NVIC_IP_PRI98_MASK)
#defing NVIC_IP_PRI9y_MASK                       0xF�u
#define NVIC_IP_PRI99_SHIFT $                 !  0
#define NVIC_IP_PR	99(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI99_SHIFT))&NVIC_IP_PRI99_MASK)
#define NVIC_IP_PRI100_MASK                      0xFFu
#define NVIC_IP_PRI100_SHIFT                     0
#define NVIC_IP_PRI100(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI100_SHIFT))&NVIC_IP_PRI100_MASK)
#define NVIC_IP_PRI101_MASK                      0xFFu
#define NVIC_IP_PRI101_SHIFT                     0
#define NVIC_IP_PRI101(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI101_SHIFT))&NVIC_IP_PRI101_MASK)
#define NVIC_IP_PRI102_MASK                      0xFFu
#define NVIC_IP_PRI102_SHIFT                     0
#define NVIC_IP_PRI102(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI102_SHIFT))&NVIC_IP_PRI102_MASK)
#define NVIC_IP_PRI103_MASK                      0xFFu
#define NVIC_IP_PRI103_SHIFT                     0
#define NVIC_IP_PRI103(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI103_SHIFT))&NVIC_IP_PRI103_MASK)
#define NVIC_IP_PRI104_MASK                      0xFFu
#define NVIC_IP_PRI104_SHIFT                     0
#define NVIC_IP_PRI104(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI104_SHIFT))&NVIC_IP_PRI104_MASK)
#define NVIC_IP_PRI105_MASK                      0xFFu
#define NVIC_IP_PRI105_SHIFT                     0
#define NVIC_IP_PRI105(x)                        (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI105_SHIFT))&NVIC_IP_PRI105_MASK)
/* STIR Bit Fields */
#define NVIC_STIR_INTID_MASK                     0x1FFu
#define NVIC_STIR_INTID_SHIFT                    0
#define NVIC_STIR_INTID(x)                       (((uint32_t)(((uint32_t)(x))<<NVIC_STIR_INTID_SHIFT))&NVIC_STIR_INTID_MASK)

/**
 * @}
 */ /* end of group NVIC_Register_Masks */


/* NVIC - Peripheral instance base addresses */
/** Peripheral NVIC base pointer */
#define NVIC_BASE_PTR                            ((NVIC_MemMapPtr)0xE000E100u)
/** Array initializer of NVIC peripheral base pointers */
#define NVIC_BASE_PTRS                           { NVIC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register instance definitions */
/* NVIC */
#define NVICISER0                                NVIC_ISER_REG(NVIC_BASE_PTR,0)
#define NVICISER1                                NVIC_ISER_REG(NVIC_BASE_PTR,1)
#define NVICISER2                                NVIC_ISER_REG(NVIC_BASE_PTR,2)
#define NVICISER3                                NVIC_ISER_REG(NVIC_BASE_PTR,3)
#define NVICICER0                                NVIC_ICER_REG(NVIC_BASE_PTR,0)
#define NVICICER1                                NVIC_ICER_REG(NVIC_BASE_PTR,1)
#define NVICICER2                                NVIC_ICER_REG(NVIC_BASE_PTR,2)
#define NVICICER3                                NVIC_ICER_REG(NVIC_BASE_PTR,3)
#define NVICISPR0                                NVIC_ISPR_REG(NVIC_BASE_PTR,0)
#define NVICISPR1                                NVIC_ISPR_REG(NVIC_BASE_PTR,1)
#define NVICISPR2                                NVIC_ISPR_REG(NVIC_BASE_PTR,2)
#define NVICISPR3                                NVIC_ISPR_REG(NVIC_BASE_PTR,3)
#define NVICICPR0                                NVIC_ICPR_REG(NVIC_BASE_PTR,0)
#define NVICICPR1                                NVIC_ICPR_REG(NVIC_BASE_PTR,1)
#define NVICICPR2                                NVIC_ICPR_REG(NVIC_BASE_PTR,2)
#define NVICICPR3                                NVIC_ICPR_REG(NVIC_BASE_PTR,3)
#define NVICIABR0                                NVIC_IABR_REG(NVIC_BASE_PTR,0)
#define NVICIABR1                                NVIC_IABR_REG(NVIC_BASE_PTR,1)
#define NVICIABR2                                NVIC_IABR_REG(NVIC_BASE_PTR,2)
#define NVICIABR3                                NVIC_IABR_REG(NVIC_BASE_PTR,3)
#define NVICIP0                                  NVIC_IP_REG(NVIC_BASE_PTR,0)
#define NVICIP1                                  NVIC_IP_REG(NVIC_BASE_PTR,1)
#define NVICIP2                                  NVIC_IP_REG(NVIC_BASE_PTR,2)
#define NVICIP3                                  NVIC_IP_REG(NVIC_BASE_PTR,3)
#define NVICIP4                                  NVIC_IP_REG(NVIC_BASE_PTR,4)
#define NVICIP5                                  NVIC_IP_REG(NVIC_BASE_PTR,5)
#define NVICIP6                                  NVIC_IP_REG(NVIC_BASE_PTR,6)
#define NVICIP7                                  NVIC_IP_REG(NVIC_BASE_PTR,7)
#define NVICIP8                                  NVIC_IP_REG(NVIC_BASE_PTR,8)
#define NVICIP9                                  NVIC_IP_REG(NVIC_BASE_PTR,9)
#define NVICIP10                                 NVIC_IP_REG(NVIC_BASE_PTR,10)
#define NVICIP11                                 NVIC_IP_REG(NVIC_BASE_PTR,11)
#define NVICIP12                                 NVIC_IP_REG(NVIC_BASE_PTR,12)
#define NVICIP13                                 NVIC_IP_REG(NVIC_BASE_PTR,13)
#define NVICIP14                                 NVIC_IP_REG(NVIC_BASE_PTR,14)
#define NVICIP15                                 NVIC_IP_REG(NVIC_BASE_PTR,15)
#define NVICIP16                                 NVIC_IP_REG(NVIC_BASE_PTR,16)
#define NVICIP17                                 NVIC_IP_REG(NVIC_BASE_PTR,17)
#define NVICIP18                                 NVIC_IP_REG(NVIC_BASE_PTR,18)
#define NVICIP19                                 NVIC_IP_REG(NVIC_BASE_PTR,19)
#define NVICIP20                                 NVIC_IP_REG(NVIC_BASE_PTR,20)
#define NVICIP21                                 NVIC_IP_REG(NVIC_BASE_PTR,21)
#define NVICIP22                                 NVIC_IP_REG(NVIC_BASE_PTR,22)
#define NVICIP23                                 NVIC_IP_REG(NVIC_BASE_PTR,23)
#define NVICIP24                                 NVIC_IP_REG(NVIC_BASE_PTR,24)
#define NVICIP25                                 NVIC_IP_REG(NVIC_BASE_PTR,25)
#define NVICIP26                                 NVIC_IP_REG(NVIC_BASE_PTR,26)
#define NVICIP27                                 NVIC_IP_REG(NVIC_BASE_PTR,27)
#define NVICIP28                                 NVIC_IP_REG(NVIC_BASE_PTR,28)
#define NVICIP29                                 NVIC_IP_REG(NVIC_BASE_PTR,29)
#define NVICIP30                                 NVIC_IP_REG(NVIC_BASE_PTR,30)
#define NVICIP31                                 NVIC_IP_REG(NVIC_BASE_PTR,31)
#define NVICIP32                                 NVIC_IP_REG(NVIC_BASE_PTR,32)
#define NVICIP33                                 NVIC_IP_REG(NVIC_BASE_PTR,33)
#define NVICIP34                                 NVIC_IP_REG(NVIC_BASE_PTR,34)
#define NVICIP35                                 NVIC_IP_REG(NVIC_BASE_PTR,35)
#define NVICIP36                                 NVIC_IP_REG(NVIC_BASE_PTR,36)
#define NVICIP37                                 NVIC_IP_REG(NVIC_BASE_PTR,37)
#define NVICIP38                                 NVIC_IP_REG(NVIC_BASE_PTR,38)
#define NVICIP39                                 NVIC_IP_REG(NVIC_BASE_PTR,39)
#define NVICIP40                                 NVIC_IP_REG(NVIC_BASE_PTR,40)
#define NVICIP41                                 NVIC_IP_REG(NVIC_BASE_PTR,41)
#define NVICIP42                                 NVIC_IP_REG(NVIC_BASE_PTR,42)
#define NVICIP43                                 NVIC_IP_REG(NVIC_BASE_PTR,43)
#define NVICIP44                                 NVIC_IP_REG(NVIC_BASE_PTR,44)
#define NVICIP45                                 NVIC_IP_REG(NVIC_BASE_PTR,45)
#define NVICIP46                                 NVIC_IP_REG(NVIC_BASE_PTR,46)
#define NVICIP47                                 NVIC_IP_REG(NVIC_BASE_PTR,47)
#define NVICIP48                                 NVIC_IP_REG(NVIC_BASE_PTR,48)
#define NVICIP49                                 NVIC_IP_REG(NVIC_BASE_PTR,49)
#define NVICIP50                                 NVIC_IP_REG(NVIC_BASE_PTR,50)
#define NVICIP51                                 NVIC_IP_REG(NVIC_BASE_PTR,51)
#define NVICIP52                                 NVIC_IP_REG(NVIC_BASE_PTR,52)
#define NVICIP53                                 NVIC_IP_REG(NVIC_BASE_PTR,53)
#define NVICIP54                                 NVIC_IP_REG(NVIC_BASE_PTR,54)
#define NVICIP55                                 NVIC_IP_REG(NVIC_BASE_PTR,55)
#define NVICIP56                                 NVIC_IP_REG(NVIC_BASE_PTR,56)
#define NVICIP57                                 NVIC_IP_REG(NVIC_BASE_PTR,57)
#define NVICIP58                                 NVIC_IP_REG(NVIC_BASE_PTR,58)
#define NVICIP59                                 NVIC_IP_REG(NVIC_BASE_PTR,59)
#define NVICIP60                                 NVIC_IP_REG(NVIC_BASE_PTR,60)
#define NVICIP61                                 NVIC_IP_REG(NVIC_BASE_PTR,61)
#define NVICIP62                                 NVIC_IP_REG(NVIC_BASE_PTR,62)
#define NVICIP63                                 NVIC_IP_REG(NVIC_BASE_PTR,63)
#define NVICIP64                                 NVIC_IP_REG(NVIC_BASE_PTR,64)
#define NVICIP65                                 NVIC_IP_REG(NVIC_BASE_PTR,65)
#define NVICIP66                                 NVIC_IP_REG(NVIC_BASE_PTR,66)
#define NVICIP67                                 NVIC_IP_REG(NVIC_BASE_PTR,67)
#define NVICIP68                                 NVIC_IP_REG(NVIC_BASE_PTR,68)
#define NVICIP69                                 NVIC_IP_REG(NVIC_BASE_PTR,69)
#define NVICIP70                                 NVIC_IP_REG(NVIC_BASE_PTR,70)
#define NVICIP71                                 NVIC_IP_REG(NVIC_BASE_PTR,71)
#define NVICIP72                                 NVIC_IP_REG(NVIC_BASE_PTR,72)
#define NVICIP73                                 NVIC_IP_REG(NVIC_BASE_PTR,73)
#define NVICIP74                                 NVIC_IP_REG(NVIC_BASE_PTR,74)
#define NVICIP75                                 NVIC_IP_REG(NVIC_BASE_PTR,75)
#define NVICIP76                                 NVIC_IP_REG(NVIC_BASE_PTR,76)
#define NVICIP77                                 NVIC_IP_REG(NVIC_BASE_PTR,77)
#define NVICIP78                                 NVIC_IP_REG(NVIC_BASE_PTR,78)
#define NVICIP79                                 NVIC_IP_REG(NVIC_BASE_PTR,79)
#define NVICIP80                                 NVIC_IP_REG(NVIC_BASE_PTR,80)
#define NVICIP81                                 NVIC_IP_REG(NVIC_BASE_PTR,81)
#define NVICIP82                                 NVIC_IP_REG(NVIC_BASE_PTR,82)
#define NVICIP83                                 NVIC_IP_REG(NVIC_BASE_PTR,83)
#define NVICIP84                                 NVIC_IP_REG(NVIC_BASE_PTR,84)
#define NVICIP85                                 NVIC_IP_REG(NVIC_BASE_PTR,85)
#define NVICIP86                                 NVIC_IP_REG(NVIC_BASE_PTR,86)
#define NVICIP87                                 NVIC_IP_REG(NVIC_BASE_PTR,87)
#define NVICIP88                                 NVIC_IP_REG(NVIC_BASE_PTR,88)
#define NVICIP89                                 NVIC_IP_REG(NVIC_BASE_PTR,89)
#define NVICIP90                                 NVIC_IP_REG(NVIC_BASE_PTR,90)
#define NVICIP91                                 NVIC_IP_REG(NVIC_BASE_PTR,91)
#define NVICIP92                                 NVIC_IP_REG(NVIC_BASE_PTR,92)
#define NVICIP93                                 NVIC_IP_REG(NVIC_BASE_PTR,93)
#define NVICIP94                                 NVIC_IP_REG(NVIC_BASE_PTR,94)
#define NVICIP95                                 NVIC_IP_REG(NVIC_BASE_PTR,95)
#define NVICIP96                                 NVIC_IP_REG(NVIC_BASE_PTR,96)
#define NVICIP97                                 NVIC_IP_REG(NVIC_BASE_PTR,97)
#define NVICIP98                                 NVIC_IP_REG(NVIC_BASE_PTR,98)
#define NVICIP99                                 NVIC_IP_REG(NVIC_BASE_PTR,99)
#define NVICIP100                                NVIC_IP_REG(NVIC_BASE_PTR,100)
#define NVICIP101                                NVIC_IP_REG(NVIC_BASE_PTR,101)
#define NVICIP102                                NVIC_IP_REG(NVIC_BASE_PTR,102)
#define NVICIP103                                NVIC_IP_REG(NVIC_BASE_PTR,103)
#define NVICIP104                                NVIC_IP_REG(NVIC_BASE_PTR,104)
#define NVICIP105                                NVIC_IP_REG(NVIC_BASE_PTR,105)
#define NVICSTIR                                 NVIC_STIR_REG(NVIC_BASE_PTR,0)

/* NVIC - Register array accessors */
#define NVIC_ISER(index)                         NVIC_ISER_REG(NVIC_BASE_PTR,index)
#define NVIC_ICER(index)                         NVIC_ICER_REG(NVIC_BASE_PTR,index)
#define NVIC_ISPR(index)                         NVIC_ISPR_REG(NVIC_BASE_PTR,index)
#define NVIC_ICPR(index)                         NVIC_ICPR_REG(NVIC_BASE_PTR,index)
#define NVIC_IABR(index)                         NVIC_IABR_REG(NVIC_BASE_PTR,index)
#define NVIC_IP(index)                           NVIC_IP_REG(NVIC_BASE_PTR,index)
#define NVIC_STIR(index)                         NVIC_STIR_REG(NVIC_BASE_PTR,index)

/**
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group NVIC_Peripheral */


/* ----------------------------------------------------------------------------
   -- OSC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Peripheral OSC
 * @{
 */

/** OSC - Peripheral register structure */
typedef struct OSC_MemMap {
  uint8_t CR;                                      /**< OSC Control Register, offset: 0x0 */
} volatile *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)

/**
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#define OSC_CR_SC16P_MASK                        0x1u
#define OSC_CR_SC16P_SHIFT                       0
#define OSC_CR_SC8P_MASK                         0x2u
#define OSC_CR_SC8P_SHIFT                        1
#define OSC_CR_SC4P_MASK                         0x4u
#define OSC_CR_SC4P_SHIFT                        2
#define OSC_CR_SC2P_MASK                         0x8u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSTEN_MASK                     0x20u
#define OSC_CR_EREFSTEN_SHIFT                    5
#define OSC_CR_ERCLKEN_MASK                      0x80u
#define OSC_CR_ERCLKEN_SHIFT                     7

/**
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base pointer */
#define OSC_BASE_PTR                             ((OSC_MemMapPtr)0x40065000u)
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register instance definitions */
/* OSC */
#define OSC_CR                                   OSC_CR_REG(OSC_BASE_PTR)

/**
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group OSC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PDB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Peripheral PDB
 * @{
 */

/** PDB - Peripheral register structure */
typedef struct PDB_MemMap {
  uint32_t SC;                                     /**< Status and Control Register, offset: 0x0 */
  uint32_t MOD;                                    /**< Modulus Register, offset: 0x4 */
  uint32_t CNT;                                    /**< Counter Register, offset: 0x8 */
  uint32_t IDLY;                                   /**< Interrupt Delay Register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    uint32_t C1;                                     /**< Channel n Control Register 1, array offset: 0x10, array step: 0x28 */
    uint32_t S;                                      /**< Channel n Status Register, array offset: 0x14, array step: 0x28 */
    uint32_t DLY[2];                                 /**< Channel n Delay 0 Register..Channel n Delay 1 Register, array offset: 0x18, array step: index*0x28, index2*0x4 */
    uint8_t RESERVED_0[24];
  } CH[2];
  uint8_t RESERVED_0[240];
  struct {                                         /* offset: 0x150, array step: 0x8 */
    uint32_t INTC;                                   /**< DAC Interval Trigger n Control Register, array offset: 0x150, array step: 0x8 */
    uint32_t INT;                                    /**< DAC Interval n Register, array offset: 0x154, array step: 0x8 */
  } DAC[2];
  uint8_t RESERVED_1[48];
  uint32_t POEN;                                   /**< Pulse-Out n Enable Register, offset: 0x190 */
  uint32_t PODLY[3];                               /**< Pulse-Out n Delay Register, array offset: 0x194, array step: 0x4 */
} volatile *PDB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register accessors */
#define PDB_SC_REG(base)                         ((base)->SC)
#defi
${���K���j'}��`|x�Ndt���֚K�yN�
WR�U��~��l�����Ŵ����[�I@`��V�f�h/�;J��s�cz#��>�p���<�>��6G� �yD2���^+O�2�{wd;���貎�r�.W�����>��m����Tp���I^� G ���Ty %L�v4ݟ}�-V�����N_t��ؙ�5=A`NNs &��c�ɣ'8BwH�h��?z���"���܀&ׂ�^���|ל�����E��)��5$B�y&�p�͉cT��T&ѽ'����.�cI����	F���{��`eNYohY��ۥ�{�3�) ��F�p@��0�?���@��s�Z8���d�>Y��!C���:�M�J�!j��_�|Iΐ2���qFv;�Y��l�P���1i�)['.�E#!���p���gJAH	���ӧ���2_���U�&u�s�7��o�f����r����u����9�ԶeҮ�r�(ѫ(����������Ű�Q�J��%�ǹ>���\���϶�f�i�q�Pg�i�о �)��ʱ꽑޿��{�z�#/���O�5��Au?3�2x|����}���.�Κ�����j��U^%��Nn3��6��L�4���ɔ�YniX�e�eg�a���G=�CPU�Y����
�!��l��>���	�Ц�5uߪ�v��<ʓR���+E�8u�� ��(�'=ص�	mnq;#��u��.�ߍ���Nm�`���
o޾n\�ʿ��
�|h�$�ޏ���6�*�[-5�%+^�~�:2�=��)7�4~��/	�,w�v�)9���`N��M'\,͘~��0eF�?M�v�w��QU��-���e��L���Pd �1��o'��;�� �\���s��t����pa�����bLp�U\
�;��<y9v+``MW^�Y��n�b�zcS���~g::௯M��/يE�=��Wʕd^O�U���#K�扤$���ojzs
 * @{
 */

/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSELnV�nn=q��I�����9J$X=���-]��;
��	�M��>=�,�����B��m5`-��,�am_6n�5ȭ�A�-�b�|��n�g�۶��{䞖��8�=m~���K��r'u�����w��wz?�ᴶ�����C���n�P_��y��?8�Z'Y��6�she �Nū���2���M�&@�R�K�"�t,�\(Hɇpq1�8��]�T���<R/<��[��p�j�bO� �������־mx�����Z���m%�������%	���#9��W�A�sݞȔ3~��78m3
h%�����ޮ/+�������a�uwY�*���H&��Ь�(V�nR��$��O�a��29BSv�߯vP�bIm�|�K- �fZv�8�]x�*��8ntǿ�{*��&*`�/�j-�(��?�aE��ZQ4�E ��bȫ�:��8G��]W0�}���A��u����ĎW�e�6J9(��
Jל,J:���C���b	c�s�2df- ���P�����[�J�+�t�������O�	��*�8�	N��u���b&5�^  �6f�����pP}n��M��GD��|����#H1��L�Ѳ������RM �OI��Zy�ظ}�3��s�5k�u�۫g�qNsjcB)��Ѧɉ �(��*���D$�N�nm�_�|L�ʳ����@�ϫ�i���=w�1c ��e# C3)�A@�hg|����^�N��δ�2C��^�/4�U��$E}��8'@_G�S��8T�$�_s�o
�~ry�Җ�<�N����q���_P�$�;*�d{(��k,��̠��Ц��b�k͹6-H���P�(	�J�+-I
�B��̝�x=-h�=����u���6���R��D�?Lw>��a!2�^�?��*��\��!�D\8�����x��4���,�E8��A�rV�>ƕ�*�1W?��u��-�V3�l�\�=��D6�a�9G�/��,��	�,�Dd�?�L3�
${���K���j'}��`|x�Ndt���֚K�yN�
WR�U��~��l�����Ŵ����[�I@`��V�f�h/�;J��s�cz#��>�p���<�>��6G� �yD2���^+O�2�{wd;���貎�r�.W�����>��m����Tp���I^� G ���Ty %L�v4ݟ}�-V�����N_t��ؙ�5=A`NNs &��c�ɣ'8BwH�h��?z���"���܀&ׂ�^���|ל�����E��)��5$B�y&�p�͉cT��T&ѽ'����.�cI����	F���{��`eNYohY��ۥ�{�3�) ��F�p@��0�?���@��s�Z8���d�>Y��!C���:�M�J�!j��_�|Iΐ2���qFv;�Y��l�P���1i�)['.�E#!���p���gJAH	���ӧ���2_���U�&u�s�7��o�f����r����u����9�ԶeҮ�r�(ѫ(����������Ű�Q�J��%�ǹ>���\���϶�f�i�q�Pg�i�о �)��ʱ꽑޿��{�z�#/���O�5��Au?3�2x|����}���.�Κ�����j��U^%��Nn3��6��L�4���ɔ�YniX�e�eg�a���G=�CPU�Y����
�!��l��>���	�Ц�5uߪ�v��<ʓR���+E�8u�� ��(�'=ص�	mnq;#��u��.�ߍ���Nm�`���
o޾n\�ʿ��
�|h�$�ޏ���6�*�[-5�%+^�~�:2�=��)7�4~��/	�,w�v�)9���`N��M'\,͘~��0eF�?M�v�w��QU��-���e��L���Pd �1��o'��;�� �\���s��t����pa�����bLp�U\
�;��<y9v+``MW^�Y��n�b�zcS���~g::௯M��/يE�=��Wʕd^O�U���#K�扤$���ojzB_C1_BB_MASK                           0xFF0000u
#define PDB_C1_BB_SHIFT                          16
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK)
/* S Bit Fields */
#define PDB_S_ERR_MASK                           0xFFu
#define PDB_S_ERR_SHIFT                          0
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            0xFF0000u
#define PDB_S_CF_SHIFT                           16
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK)
/* DLY Bit Fields */
#define PDB_DLY_DLY_MASK                         0xFFFFu
#define PDB_DLY_DLY_SHIFT                        0
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK)
/* INTC Bit Fields */
#define PDB_INTC_TOE_MASK                        0x1u
#define PDB_INTC_TOE_SHIFT                       0
#define PDB_INTC_EXT_MASK                        0x2u
#define PDB_INTC_EXT_SHIFT                       1
/* INT Bit Fields */
#define PDB_INT_INT_MASK                         0xFFFFu
#define PDB_INT_INT_SHIFT                        0
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK)
/* POEN Bit Fields */
#define PDB_POEN_POEN_MASK                       0xFFu
#define PDB_POEN_POEN_SHIFT                      0
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK)
/* PODLY Bit Fields */
#define PDB_PODLY_DLY2_MASK                      0xFFFFu
#define PDB_PODLY_DLY2_SHIFT                     0
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK)
#define PDB_PODLY_DLY1_MASK                      0xFFFF0000u
#define PDB_PODLY_DLY1_SHIFT                     16
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK)

/**
 * @}
 */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base pointer */
#define PDB0_BASE_PTR                            ((PDB_MemMapPtr)0x40036000u)
/** Array initializer of PDB peripheral base pointers */
#define PDB_BASE_PTRS                            { PDB0_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros
 * @{
 */


/* PDB - Register instance definitions */
/* PDB0 */
#define PDB0_SC                                  PDB_SC_REG(PDB0_BASE_PTR)
#define PDB0_MOD                                 PDB_MOD_REG(PDB0_BASE_PTR)
#define PDB0_CNT                                 PDB_CNT_REG(PDB0_BASE_PTR(
#`efine PDB0_IDDY       (                        PDB_IDLY_REG(PDB0_BQSE_PTR)
#define PDB0_CH0C1         0                     PDB_C1_REG(PDB0_BASE_PTR,0)
#define QDB0_CH0C$ !                             PDB_S_REG(PDB_BASE_PTR,0)
#define"PDB2_CH0DLY0                    0       "PDB_DLY_REG(PDB0_BASE_PTR,0,0)	#define PDB0_CH0DLY1 `  !       " "              PDB_DLY_REG(PDB0_BACE_PTR, ,1)
#define PDB0_CH1C1                     (!        PDB_C0WREG(PDB0_BASE_PTR,1)M
#define PEB0_C@1S   $  `      !      "           PDB_S_REG(PDB0_BASE_�R,1)
#define PDB0_C@1DLY0               #             PDB_DLY_REG(PDB0_CASE_PTR,1,0)
#denine PDB0_CH1DLY1            `$      � !   !  PDB_DHY_REG)PDB0_JASE_PTR,1,1)
#definePDB0_DACINTC0!                           PDB_INTC_REG(PDB0_BASE_PTR,0)
#define PDB0_DACIN\0                             PDB_INT_RUG�PDB4_BASE_PTR,0)�#define PDB0_DACI�TC1                            PDB_KNTC_REG(PDB0_BASE_PTR,1)
#define PDB0_DACINT1 �                           PDB_INT_REG(PDB0_BASE_PTR,1)
#define PDB0_POEN                                PDB_POEN_REG(PDB0_BASE_PTR)
#define PDB0_PO0DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,0)
#define PDB0_PO1DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,1)
#define PDB0_PO2DLY                              PDB_PODLY_REG(PDB0_BASE_PTR,2)

/* PDB - Register array accessors */
#define PDB0_C1(index)                           PDB_C1_REG(PDB0_BASE_PTR,index)
#define PDB0_S(index)                            PDB_S_REG(PDB0_BASE_PTR,index)
#define PDB0_DLY(index,index2)                   PDB_DLY_REG(PDB0_BASE_PTR,index,index2)
#define PDB0_INTC(index)                         PDB_INTC_REG(PDB0_BASE_PTR,index)
#define PDB0_INT(index)                          PDB_INT_REG(PDB0_BASE_PTR,index)
#define PDB0_PODLY(index)                        PDB_PODLY_REG(PDB0_BASE_PTR,index)

/**
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PDB_Peripheral */


/* ----------------------------------------------------------------------------
   -- PIT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Peripheral PIT
 * @{
 */

/** PIT - Peripheral register structure */
typedef struct PIT_MemMap {
  uint32_t MCR;                                    /**< PIT Module Control Register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    uint32_t LDVAL;                                  /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    uint32_t CVAL;                                   /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    uint32_t TCTRL;                                  /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    uint32_t TFLG;                                   /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register accessors */
#define PIT_MCR_REG(base)                        ((base)->MCR)
#define PIT_LDVAL_REG(base,index)                ((base)->CHANNEL[index].LDVAL)
#define PIT_CVAL_REG(base,index)                 ((base)->CHANNEL[index].CVAL)
#define PIT_TCTRL_REG(base,index)                ((base)->CHANNEL[index].TCTRL)
#define PIT_TFLG_REG(base,index)                 ((base)->CHANNEL[index].TFLG)

/**
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */
/�*
 * @addvogroup P	T_Zegister_Mesks PIT Register Oasks
 * @{
 */

/* LCR Bit Fyelds */
#define PIT_MCR_FRZ_MaSK                     (   4x1u
#define RT_MCR_FRZ_SHIFT              `         0
#d5file PIT_MCR_MDIS_MASK 0             0     0  0x:u
#define PIDMCR_MDIS_SHIFT                  0    1
o* LDVAL Bit Fields */
#definD @�T_LDVAL_TSV_MA[K              �        0xFFFFFFFF5
#define PIT_LDVAL_TSV_SHIFT        !             0
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK)
/* CVAL @ht Fields */
#define PIT_CVAL_TVL_MASK           (  $    0 "  0xFFFFFFOFu
#define PIT_CVAL_TVL_SHIF�                       0
#�efine PIT_CVAL_DVL(x)                $         (((uint12_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SLIFT))&PYT_CVAL[TVL_MASK)
/* TCTRL Bit Fiulds */
#define`PIT_TCTRL_TEN_MASK    �     0            0x1u
#define PIT_TCTRL_�EN_SHIFT         0            0#define PIT_TCTRL_TIE_MASK                       0x2u
#define PIT_TCTRL_TIE_SHIFT                      1
#define PIT_TCTRL_CHN_MASK                       0x4u
#define PIT_TCTRL_CHN_SHIFT                      2
/* TFLG Bit Fields */
#define PIT_TFLG_TIF_MASK                        0x1u
#define PIT_TFLG_TIF_SHIFT                       0

/**
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base pointer */
#define PIT_BASE_PTR                             ((PIT_MemMapPtr)0x40037000u)
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register instance definitions */
/* PIT */
#define PIT_MCR                                  PIT_MCR_REG(PIT_BASE_PTR)
#define PIT_LDVAL0                               PIT_LDVAL_REG(PIT_BASE_PTR,0)
#define PIT_CVAL0                                PIT_CVAL_REG(PIT_BASE_PTR,0)
#define PIT_TCTRL0                               PIT_TCTRL_REG(PIT_BASE_PTR,0)
#define PIT_TFLG0                                PIT_TFLG_REG(PIT_BASE_PTR,0)
#define PIT_LDVAL1                               PIT_LDVAL_REG(PIT_BASE_PTR,1)
#define PIT_CVAL1                                PIT_CVAL_REG(PIT_BASE_PTR,1)
#define PIT_TCTRL1                               PIT_TCTRL_REG(PIT_BASE_PTR,1)
#define PIT_TFLG1                                PIT_TFLG_REG(PIT_BASE_PTR,1)
#define PIT_LDVAL2                               PIT_LDVAL_REG(PIT_BASE_PTR,2)
#define PIT_CVAL2                                PIT_CVAL_REG(PIT_BASE_PTR,2)
#define PIT_TCTRL2                               PIT_TCTRL_REG(PIT_BASE_PTR,2)
#define PIT_TFLG2                                PIT_TFLG_REG(PIT_BASE_PTR,2)
#define PIT_Z��O�m��g���G��2L�-��8ٛ=������s�B�2�!��թ��˖gT���������3|�eJ��u9!�E&fؑ�o�ѰÕ�7�C���H
п�p�7�pב�C�-N#�����w �t	��Ybf�.��E0液��Sbc߼u����LHJbp�
�)�e�KT)+^���Є���q|����fg\��i�jM ��Z�W?��0�S��`��hs�׏S ]�okmh�"-�R�8�=����mļ�~G���9,2��@�?�feHD��v�-AX�=���z�5.ơ~�^��7���O�!�M�ͮ�ll5�稙����\e�  #j���]w%���g��n|B"*YU��r�l�v����C����ϥc�䒇��Iv��6=6���_d���v�d���=�c�OF�ە�z
逶�T�ib5�'<y��-"v�*�G<qv��� �0+{<߁Xv�g?^Zc�{�����Z����L~�� ����>�5�������%~�����t�ީ^z΋��Õ��}Yl�h�7ڎ���D��Y-���\�O�oS�W��;�k�D|�c��	(3m��p�D ��I��;��k��s��	�Iѓ5����(#���������K���EoH<z��t��Q��c���̊�� u3`l��>��x�m8`���窯�`�p����*�����_^8����yb���0�*��=�8��=.?1� �?�f��A�sV|Fw���|�b��&�S'�\��=��}�5b��i�V=��v��bKpA��z��%����c�}=a���2�a�ho����p"��&jr��{Q�Ό���{S��4%�f4)Sվm�X�ց�DcW�`��!�dh�_A�Yof�l�X�4،�ÆhMf}���.�}b��άd����>q��5^��M�#�Q2��D����VÁ�>'���u�ȟ��c�QJ�L���b�C/>�:AU���dl�J��(G�`nq�$S��$�`�ú=E�D�N{�D��į~��&�m�BR�31KgN@�t�v�{������:Q���]0w��{�>w=�D��'�T(��[O����t�I�H9��U��c�ZC�+��߱G��{!m6m(P?��X���)w[;wT�O���pbl<F�r;���떊�;�����;�ޯqf{����[5�=J�˞�)��#���Ew7յ�̾%������y��Vo7����5k�Fm&�C���Y��e'�G2�`o��/$��D�O���J8��RG+&��MԨC��V����AL5M S�v�I4r�ڕv%_^:���]@�m� �!S�Go�k�o��n�[Ҹ�nT��r�|eLEfJ\[Q�
th�!�c��b�!�>_�H@�Pջbo��9�AS��n�+�m�����վ�4�j��ԂN�jJ`rd��M��o�-�ib�_�i�$9�C��l)@���i��C$�R��d�ψ>����J��T����$�Pg��\9��m���g�i_��:e�Cy�f�s����G���W��j�=�K���L)4dե�]-!���,���;?fP�����Q���a�!����-T�ȁ9;��"B[�ɏ��3+}R_k��JG���ߊ�=I�!��P*J Uvγ�����a�;e�ar/y�@��U|5��s�nU\��E�۵�|�����8욓�a!�^>��kO�OXE�wYo`��k]�eg�z�s��Hxf"��?�a2�	�~�y�S��Nt���y�&�V��[���s�+&E'JtMnѸ9�H����G�jN��4�B`MF����1Z	���?�(H7��7}���X��'��)|�El���;zt�;^�߶jæ�WB���ch��G8��&*�4_���&VZ7H@�Һ8cq�_�0�N.�����&_����_qY��l��6/v:m"��A�4D$��'��Jɸa�ʞ\��(d0�;�"�������T�Z�;�	>�*-����q�ϸּ�F�a梁ٸ_�0�0�����&@�Sg�
���c6?/* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_ACKISO_MASK                    0x8u
#define PMC_REGSC_ACKISO_SHIFT                   3
#define PMC_REGSC_BGEN_MASK                      0x10u
#define PMC_REGSC_BGEN_SHIFT                     4

/**
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base pointer */
#define PMC_BASE_PTR                             ((PMC_MemMapPtr)0x4007D000u)
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_LVDSC1                               PMC_LVDSC1_REG(PMC_BASE_PTR)
#define PMC_LVDSC2                               PMC_LVDSC2_REG(PMC_BASE_PTR)
#define PMC_REGSC                                PMC_REGSC_REG(PMC_BASE_PTR)

/**
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/**
 * @}
 */ /*Z��O�m��g���G��2L�-��8ٛ=������s�B�2�!��թ��˖gT���������3|�eJ��u9!�E&fؑ�o�ѰÕ�7�C���H
п�p�7�pב�C�-N#�����w �t	��Ybf�.��E0液��Sbc߼u����LHJbp�
�)�e�KT)+^���Є���q|����fg\��i�jM ��Z�W?��0�S��`��hs�׏S ]�okmh�"-�R�8�=����mļ�~G���9,2��@�?�feHD��v�-AX�=���z�5.ơ~�^��7���O�!�M�ͮ�ll5�稙����\e�  #j���]w%���g��n|B"*YU��r�l�v����C����ϥc�䒇��Iv��6=6���_d���v�d���=�c�OF�ە�z
逶�T�ib5�'<y��-"v�*�G<qv��� �0+{<߁Xv�g?^Zc�{�����Z����L~�� ����>�5�������%~�����t�ީ^z΋��Õ��}Yl�h�7ڎ���D��Y-���\�O�oS�W��;�k�D|�c��	(3m��p�D ��I��;��k��s��	�Iѓ5����(#���������K���EoH<z��t��Q��c���̊�� u3`l��>��x�m8`���窯�`�p����*�����_^8����yb���0�*��=�8��=.?1� �?�f��A�sV|Fw���|�b��&�S'�\��=��}�5b��i�V=��v��bKpA��z��%����c�}=a���2�a�ho����p"��&jr��{Q�Ό���{S��4%�f4)Sվm�X�ց�DcW�`��!�dh�_A�Yof�l�X�4،�ÆhMf}���.�}b��άd����>q��5^��M�#�Q2��D����VÁ�>'���u�ȟ��c�QJ�L���b�C/>�:AU���dl�J��(G�`nq�$S��$�`�ú=E�D�N{�Dm-P�Ҁ��::�^��_��w�DwP��J.~c6�y����9�K���zEL�3��g>������nJ2�d'�98��Gˮz(t��^��oYCd70)���@�EP� @����Ǝ^<��V6a`[��ͬ��GT�V�S��K*UlJG�3�䄂r���K�%a�1�D"���22 _�3�V��(a��J����NKPe�
{���0���Э�ͼ=�%PW�F�2��	�hoD��4ek��N#���eHy�ID����\��C��M|l���Q�釁3qи���A%<�+�� ���I�4� /W�_|<�l�'�#��E�{=B)-�_1I�R�y��L'���`Y�V�h�>��g�p�p��w���j�#�o��K�t⦊�	�B�
g�#�d�`��1��:�����l%����I���4R�p��_Gv��A��I�7��\��b���~�N#2Pӄ����$�)/�»�:��-�i0�U�8�\`���[���FfgbO���:;W�ܥx�#�ޔ �{R�6����`'�5F./Z�4���)p&��,��răw��ƠG;n��b��Q��8��Ev}�4"�\�R&�
�qa4f�Mp�I#��t��ШK���-���5��6}��+�rc�#�y���*�u5�N��ƹ��|C�u�����z"��l��D^����jw��9x�9:�Y�5�L�v3N(�'Y.ؤ��i�.�T�a�y�(�WX�jk�]�M�NY}��WOM�՗ }�z9���E�%a����cz��5�?}��5���>�F�v�H+�k	��g9��tt"�ݟ?�[��B�V��ܯ��E�?�O孬�R6pw�D4_�u�U^j�Qr�K�k?�v�y��O�vd�B�+Ά�+�{iIf|��k�Ԅ,�SZ؈c����/[2{�����f=o�}:�>р!��[����#�,+1d���!�<���{`��N��(Z��t����Km��H¿.��/�h�h��T@K@��#�$�g����	�R�y~���(��z~�t�����|���o��8��`f�}ԫ	1�bXc�x�F/=[NݵZ�i�%���^sT�<����h��*yUf��a��qy[ok���(����� [�0�q�.&Z�yܥ��5�>�(f������CP �0HwC���?�I��b����	a��o8�X��G��m?{4��?d?�?[���Yy(0C����'���{��q��g3gT�e'�vȃ� \$�J�FC�&�|&8�,�����n�b%��zk�hmx s������k�񔮎̅�-ڝ4Y�'ڦ{�hHv{[����ӷ�@�n�l��h�x�\I�HX��k"l�R< .�a�1H�0�:������xu5u�&M�����}�����M޲�c���74x�Y�:hP+���S���?7���u��
�Mfѡd�(/f!�+q�2MkeL�g B*���F�-6�4��檀��&y�fCM�b�K�������!t��rQ���� �i5��]���k�`�c��m��q�������tZ��5����_a�#�R*{��r��&��rd�3eW<,
7�XN#I����r���/X-�P�#0�Tc��7��GiQ��� Vi/����"���2c]G��6hѼ�_��"����.*��w�X��	�x�N�*�[�k����f�vT�����/�:���C��0S4��Nį�7�)�0����όN_��S&��L�1<&`?9���@@~���$�-�y�c�b�:�p��;�!��'���3��M���������FIo�B�r/�q�Ӎ+ �wW�h�ڽ����\ge�ʏ۪��6}��<�<5|�U�n,4`!�zv�I�z�̽��BIR.	���9:>��g$��=�����5$WYa��8W����MWe�m5}=����IV3�O@�����~2��}VL����0Kbk�
o�O��#���C��z`1��+ٜ@��qr���{ X3}]%*[�OFT 0  "        `    `    8
#define!PORT_PCR_MU�(x)                         !(((uint32_t)(((uint36_t+(x))<<PORT_PCR_MUX_SHIT))&XORT_PCR_MUX_MASKi
#define PORT_PCR_LK_MASJ                         0x8000u
#define POBT_PCR_LK_SHIFT   ! !      $         ! 15
define PORT_QCR_IRQC_MASK       0               0xB0000u
#define PORT_PCR_IRQC_SHIFT    "                 16
#lefif�0PORT_PCR_IRQC(x)                         (((uint32_t)(((qint32_t)(x))<<PNR\_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MAS)
#define PORT_PCR_ISF_MASK      "                 0p100�000u
#define PORT_PCR_IS_SHIFT                       24
/* GPCLR Bit Fields(*/
#dedine PORT_WPGLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT  0                 0*#define PORT_GPCLR_GPWD(x)      (            $   (((tint32_t)(((uint32_t�(x))<|@ORT_GpcLR_GPSD_SHIF�))&POrT_GPCMR_GPWD_MASK)
#define PORT_GPCR_GPWEMASK         !           0xFFFF000u
#define PORT[GPCLR_GPWE_SHIFT                    16
#defive POZT_GPCLR_GPWA(x)      `        $       (((uin432_�)(((uifu32_t)(x))<<PORT_GPCLR_GPWE_sHIFT))&PORT_GPCLR_GPWE_MASK)
* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MAS_             (       0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT0                   �
#de&ine PORT_GPCHR_GPWD(x)0               (      (((uint32_t-(((uint32_t)(xi)<<PORT_GPCHR_GPWD_SHIFT))&POR�_FPCHR_GPWD_MASK)#define PORT_gPCh�_GPWE_MASK              &    (  xFFFF0000u
#definu PGRT_GPCXr_GPWE_SHIFT$       !           16
�defing PGRT_GPAHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GpWE_SHIFU))&PORT_GPCHR_GPVE_MASK)
/* ISFR Bit Fields */�#defije PORT_ISVR_ISF_MASK                  `    08FFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF(yi    (                    (huint;2_t)(((uint30_t)(x))<<PORT_ISFR_ISF_SHIFT1)&PORT_ICFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MACK         (             0xFFFFFFFFu
#define PORTOTFER_DFE_SHIFT                      0
#define PORT_DFER_DFE(x)!   `                    (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/**
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base pointer */
#define PORTA_BASE_PTR                           ((PORT_MemMapPtr)0x40049000u)
/** Peripheral PORTB base pointer */
#define PORTB_BASE_PTR                           ((PORT_MemMapPtr)0x4004A000u)
/** Peripheral PORTC base pointer */
#define PORTC_BASE_PTR                           ((PORT_MemMapPtr)0x4004B000u)
/** Peripheral PORTD base pointer */
#define PORTD_BASE_PTR                           ((PORT_MemMApPtr)0x4004C000u)
/** eripheral"P_RTE base pointez */
#d�fine PORTE_BASE_PTR   0                       ((PORT_MemMapPtr)0x4004D400u)
/*+ array ifitializer of PORT peripheral base pOinters */#define PORT_BASE_PTRS                           { PORTA_BASE_PTr, PORTB_BASE_PTR, PORTC_BASE_PTRl PoRTE_BASE_PTR,"POZTE_BASE_PDR }

/* ----------------------,--------------)------m-,/�---------------�----------
   -- PORU - Bdgister accessor macros
  �--%--=---------------------------------------------)------m---------------- */

/**
 * @addtogroup PORT�Register_Accessor_]acros PORT - Register accesskr macros
 * @{
 */

/* PKRT - Register instange defioktions */
/* PORTA */
#defin� PORTA_PCR0      �           !            PORT_PCR_REG(PORTA_BASE_PTR,0)
#define PORTA_PCR1                              !PORT_PCB_REG(PORTA_BASE_PTP,1!
#define PORTA_PCR2           !          "        PORT_PCR_REG*PORTA_BASE_PTR,2)
#defi�e PORTA_PCR3                  !            PORT_PCR[REG(PORTA_BASE_PTR,3)
#define PORTA_PCR4                               PORT_PCR_REG(PORTA_BASE_PTR,4)
#define PORTA_PCR5                               PORT_PCR_REG(PORTA_BASE_PTR,5)
#define PORTA_PCR6                               PORT_PCR_REG(PORTA_BASE_PTR,6)
#define PORTA_PCR7                               PORT_PCR_REG(PORTA_BASE_PTR,7)
#define PORTA_PCR8                               PORT_PCR_REG(PORTA_BASE_PTR,8)
#define PORTA_PCR9                               PORT_PCR_REG(PORTA_BASE_PTR,9)
#define PORTA_PCR10                              PORT_PCR_REG(PORTA_BASE_PTR,10)
#define PORTA_PCR11                              PORT_PCR_REG(PORTA_BASE_PTR,11)
#define PORTA_PCR12                              PORT_PCR_REG(PORTA_BASE_PTR,12)
#define PORTA_PCR13                              PORT_PCR_REG(PORTA_BASE_PTR,13)
#define PORTA_PCR14                              PORT_PCR_REG(PORTA_BASE_PTR,14)
#define PORTA_PCR15                              PORT_PCR_REG(PORTA_BASE_PTR,15)
#define PORTA_PCR16                              PORT_PCR_REG(PORTA_BASE_PTR,16)
#define PORTA_PCR17                              PORT_PCR_REG(PORTA_BASE_PTR,17)
#define PORTA_PCR18                              PORT_PCR_REG(PORTA_BASE_PTR,18)
#define PORTA_PCR19                              PORT_PCR_REG(PORTA_BASE_PTR,19)
#define PORTA_PCR20                              PORT_PCR_REG(PORTA_BASE_PTR,20)
#define PORTA_PCR21                              PORT_PCR_REG(PORTA_BASE_PTR,21)
#define PORTA_PCR22                              PORT_PCR_REG(PORTA_BASE_PTR,22)
#define PORTA_PCR23                              PORT_PCR_REG(PORTA_BASE_PTR,23)
#define PORTA_PCR24                              PORT_PCR_REG(PORTA_BASE_PTR,24)
#define PORTA_PCR25                              PORT_PCR_REG(PORTA_BASE_PTR,25)
#define PORTA_PCR26                              PORT_PCR_REG(PORTA_BASE_PTR,26)
#define PORTA_PCR27                              PORT_PCR_REG(PORTA_BASE_PTR,27)
#define PORTA_PCR28                              PORT_PCR_REG(PORTA_BASE_PTR,28)
#define PORTA_PCR2�`                             PORT_PCR_REG(PORTA_BASE_PTR,29)
#define PORTA_PCR30      0  (                    PORT_PCR_REG(PORTA_BASE_PT�,30)
#defije PNRTA_PCR31 (                      �     PORT_PCR_REG(PORTA_BASE_PTR,31)
#define PORTA_GPCLR          (         ! `       PORT_GPCLR_REG(PORTA_BASE_PTR)
#define PO�TA_GPCHR          `      �            POR�_GPCHR_REG(TORTA_BASE_PTR)
#devine PORTA_ISFR                       0 !     PORT_ISFR_REG(PORTA_�ASE_PTR)
#define PORTA_DER                 �   �         PORT_DFER_REG(PNRTA_RASE_PTR)
#define PORTA_DFCR   �                  "     �  @ORT_DFCROREG(PORTA_BAS�_PTR)
#define!PORTA_DFWV       !                    `  PORT_DFWR_RGG(PORTA_BASE_PTR)
/* PORTB *'
#defi�e PORTB_PCZ0                               QORT_PCR_RUG(pORTB_BASD_PTR,0)
#define PORDB_PCR1             `            "    PORT_PCR_REG(POrTB_BASE_QTR,1)
#defije RORTB_PCR2                               PORT_QCR_REG(PORTB_BASE_PTR,2)
#define PORTB_PCR3 �            "                PORT_PCR_REG(PORTB_BASE_PTR,3)
#define PORTB_PCR4                               PORT_PCR_REG(PORTB_BASE_PTR,4)
#define PORTB_PCR5                               PORT_PCR_REG(PORTB_BASE_PTR,5)
#define PORTB_PCR6                               PORT_PCR_REG(PORTB_BASE_PTR,6)
#define PORTB_PCR7                               PORT_PCR_REG(PORTB_BASE_PTR,7)
#define PORTB_PCR8                               PORT_PCR_REG(PORTB_BASE_PTR,8)
#define PORTB_PCR9                               PORT_PCR_REG(PORTB_BASE_PTR,9)
#define PORTB_PCR10                              PORT_PCR_REG(PORTB_BASE_PTR,10)
#define PORTB_PCR11                              PORT_PCR_REG(PORTB_BASE_PTR,11)
#define PORTB_PCR12                              PORT_PCR_REG(PORTB_BASE_PTR,12)
#define PORTB_PCR13                              PORT_PCR_REG(PORTB_BASE_PTR,13)
#define PORTB_PCR14                              PORT_PCR_REG(PORTB_BASE_PTR,14)
#define PORTB_PCR15                              PORT_PCR_REG(PORTB_BASE_PTR,15)
#define PORTB_PCR16                              PORT_PCR_REG(PORTB_BASE_PTR,16)
#define PORTB_PCR17                              PORT_PCR_REG(PORTB_BASE_PTR,17)
#define PORTB_PCR18                              PORT_PCR_REG(PORTB_BASE_PTR,18)
#define PORTB_PCR19                              PORT_PCR_REG(PORTB_BASE_PTR,19)
#define PORTB_PCR20                              PORT_PCR_REG(PORTB_BASE_PTR,20)
#define PORTB_PCR21                              PORT_PCR_REG(PORTB_BASE_PTR,21)
#define PORTB_PCR22                              PORT_PCR_REG(PORTB_BASE_PTR,22)
#define PORTB_PCR23                              PORT_PCR_REG(PORTB_BASE_PTR,23)
#define PORTB_PCR24                              PORT_PCR_REG(PORTB_BASE_PTR,24)
#define PORTB_PCR25                              PORT_PCR_REG(PORTB_BASE_PTR,25)
#define PORTB_PCR26                              PORT_PCR_REG(PORTB_BASE_PTR,26)
#define PORTB_PCR27                              PORT_PCR_REG(PORTB_BASE_PTR,27)
#define PORTB_PCR28                              PORT_PCR_REG(PORTB_BASE_PTR,28)
#define PORTB_PCR29                              PORT_PCR_REG(PORTB_BASE_PTR,29)
#define PORTB_PCR30                              PORT_PCR_REG(PORTB_BASE_PTR,30)
#define PORTB_PCR31                              PORT_PCR_REG(PORTB_BASE_PTR,31)
#define PORTB_GPCLR                              PORT_GPCLR_REG(PORTB_BASE_PTR)
#define PORTB_GPCHR                              PORT_GPCHR_REG(PORTB_BASE_PTR)
#define PORTB_ISFR                               PORT_ISFR_REG(PORTB_BASE_PTR)
#define PORTB_DFER                               PORT_DFER_REG(PORTB_BASE_PTR)
#define PORTB_DFCR                               PORT_DFCR_REG(PORTB_BASE_PTR)
#define PORTB_DFWR                               PORT_DFWR_REG(PORTB_BASE_PTR)
/* PORTC */
#define PORTC_PCR0                               PORT_PCR_REG(PORTC_BASE_PTR,0)
#define PORTC_PCR1                               PORT_PCR_REG(PORTC_BASE_PTR,1)
#define PORTC_PCR2                               PORT_PCR_REG(PORTC_BASE_PTR,2)
#define PORTC_PCR3                               PORT_PCR_REG(PORTC_BASE_PTR,3)
#define PORTC_PCR4                               PORT_PCR_REG(PORTC_BASE_PTR,4)
#define PORTC_PCR5                               PORT_PCR_REG(PORTC_BASE_PTR,5)
#define PORTC_PCR6                               PORT_PCR_REG(PORTC_BASE_PTR,6)
#define PORTC_PCR7                               PORT_PCR_REG(PORTC_BASE_PTR,7)
#define PORTC_PCR8                               PORT_PCR_REG(PORTC_BASE_PTR,8)
#define PORTC_PCR9                               PORT_PCR_REG(PORTC_BASE_PTR,9)
#define PORTC_PCR10                              PORT_PCR_REG(PORTC_BASE_PTR,10)
#define PORTC_PCR11                              PORT_PCR_REG(PORTC_BASE_PTR,11)
#define PORTC_PCR12                              PORT_PCR_REG(PORTC_BASE_PTR,12)
#define PORTC_PCR13                              PORT_PCR_REG(PORTC_BASE_PTR,13)
#define PORTC_PCR14                              PORT_PCR_REG(PORTC_BASE_PTR,14)
#define PORTC_PCR15                              PORT_PCR_REG(PORTC_BASE_PTR,15)
#define PORTC_PCR16                              PORT_PCR_REG(PORTC_BASE_PTR,16)
#define PORTC_PCR17                              PORT_PCR_REG(PORTC_BASE_PTR,17)
#define PORTC_PCR18                              PORT_PCR_REG(PORTC_BASE_PTR,18)
#define PORTC_PCR19                              PORT_PCR_REG(PORTC_BASE_PTR,19)
#define PORTC_PCR20                              PORT_PCR_REG(PORTC_BASE_PTR,20)
#define PORTC_PCR21                              PORT_PCR_REG(PORTC_BASE_PTR,21)
#define PORTC_PCR22                              PORT_PCR_REG(PORTC_BASE_PTR,22)
#define PORTC_PCR23                              PORT_PCR_REG(PORTC_BASE_PTR,23)
#define PORTC_PCR24                              PORT_PCR_REG(PORTC_BASE_PTR,24)
#define PORTC_PCR25                              PORT_PCR_REG(PORTC_BASE_PTR,25)
#define PORTC_PCR26                              PORT_PCR_REG(PORTC_BASE_PTR,26)
#define PORTC_PCR27                              PORT_PCR_REG(PORTC_BASE_PTR,27)
#define PORTC_PCR28                              PORT_PCR_REG(PORTC_BASE_PTR,28)
#define PORTC_PCR29                              PORT_PCR_REG(PORTC_BASE_PTR,29)
#define PORTC_PCR30                              PORT_PCR_REG(PORTC_BASE_PTR,30)
#define PORTC_PCR31                              PORT_PCR_REG(PORTC_BASE_PTR,31)
#define PORTC_GPCLR                              PORT_GPCLR_REG(PORTC_BASE_PTR)
#define PORTC_GPCHR                              PORT_GPCHR_REG(PORTC_BASE_PTR)
#define PORTC_ISFR                               PORT_ISFR_REG(PORTC_BASE_PTR)
#define PORTC_DFER                               PORT_DFER_REG(PORTC_BASE_PTR)
#define PORTC_DFCR                               PORT_DFCR_REG(PORTC_BASE_PTR)
#define PORTC_DFWR                               PORT_DFWR_REG(PORTC_BASE_PTR)
/* PORTD */
#define PORTD_PCR0                               PORT_PCR_REG(PORTD_BASE_PTR,0)
#define PORTD_PCR1                               PORT_PCR_REG(PORTD_BASE_PTR,1)
#define PORTD_PCR2                               PORT_PCR_REG(PORTD_BASE_PTR,2)
#define PORTD_PCR3                               PORT_PCR_REG(PORTD_BASE_PTR,3)
#define PORTD_PCR4                               PORT_PCR_REG(PORTD_BASE_PTR,4)
#define PORTD_PCR5                               PORT_PCR_REG(PORTD_BASE_PTR,5)
#define PORTD_PCR6                               PORT_PCR_REG(PORTD_BASE_PTR,6)
#define PORTD_PCR7                               PORT_PCR_REG(PORTD_BASE_PTR,7)
#define PORTD_PCR8                               PORT_PCR_REG(PORTD_BASE_PTR,8)
#define PORTD_PCR9                               PORT_PCR_REG(PORTD_BASE_PTR,9)
#define PORTD_PCR10                              PORT_PCR_REG(PORTD_BASE_PTR,10)
#define PORTD_PCR11                              PORT_PCR_REG(PORTD_BASE_PTR,11)
#define PORTD_PCR12                              PORT_PCR_REG(PORTD_BASE_PTR,12)
#define PORTD_PCR13                              PORT_PCR_REG(PORTD_BASE_PTR,13)
#define PORTD_PCR14                              PORT_PCR_REG(PORTD_BASE_PTR,14)
#define PORTD_PCR15                              PORT_PCR_REG(PORTD_BASE_PTR,15)
#define PORTD_PCR16                              PORT_PCR_REG(PORTD_BASE_PTR,16)
#define PORTD_PCR17                              PORT_PCR_REG(PORTD_BASE_PTR,17)
#define PORTD_PCR18                              PORT_PCR_REG(PORTD_BASE_PTR,18)
#define PORTD_PCR19                              PORT_PCR_REG(PORTD_BASE_PTR,19)
#define PORTD_PCR20                              PORT_PCR_REG(PORTD_BASE_PTR,20)
#define PORTD_PCR21                              PORT_PCR_REG(PORTD_BASE_PTR,21)
#define PORTD_PCR22                              PORT_PCR_REG(PORTD_BASE_PTR,22)
#define PORTD_PCR23                              PORT_PCR_REG(PORTD_BASE_PTR,23)
#define PORTD_PCR24                              PORT_PCR_REG(PORTD_BASE_PTR,24)
#define PORTD_PCR25                              PORT_PCR_REG(PORTD_BASE_PTR,25)
#define PORTD_PCR26                              PORT_PCR_REG(PORTD_BASE_PTR,26)
#define PORTD_PCR27                              PORT_PCR_REG(PORTD_BASE_PTR,27)
#define PORTD_PCR28                              PORT_PCR_REG(PORTD_BASE_PTR,28)
#define PORTD_PCR29                              PORT_PCR_REG(PORTD_BASE_PTR,29)
#define PORTD_PCR30                              PORT_PCR_REG(PORTD_BASE_PTR,30)
#define PORTD_PCR31                              PORT_PCR_REG(PORTD_BASE_PTR,31)
#define PORTD_GPCLR                              PORT_GPCLR_REG(PORTD_BASE_PTR)
#define PORTD_GPCHR                              PORT_GPCHR_REG(PORTD_BASE_PTR)
#define PORTD_ISFR                               PORT_ISFR_REG(PORTD_BASE_PTR)
#define PORTD_DFER                               PORT_DFER_REG(PORTD_BASE_PTR)
#define PORTD_DFCR                               PORT_DFCR_REG(PORTD_BASE_PTR)
#define PORTD_DFWR                               PORT_DFWR_REG(PORTD_BASE_PTR)
/* PORTE */
#define PORTE_PCR0                               PORT_PCR_REG(PORTE_BASE_PTR,0)
#define PORTE_PCR1                               PORT_PCR_REG(PORTE_BASE_PTR,1)
#define PORTE_PCR2                               PORT_PCR_REG(PORTE_BASE_PTR,2)
#define PORTE_PCR3                               PORT_PCR_REG(PORTE_BASE_PTR,3)
#define PORTE_PCR4                               PORT_PCR_REG(PORTE_BASE_PTR,4)
#define PORTE_PCR5                               PORT_PCR_REG(PORTE_BASE_PTR,5)
#define PORTE_PCR6                               PORT_PCR_REG(PORTE_BASE_PTR,6)
#define PORTE_PCR7                               PORT_PCR_REG(PORTE_BASE_PTR,7)
#define PORTE_PCR8                               PORT_PCR_REG(PORTE_BASE_PTR,8)
#define PORTE_PCR9                               PORT_PCR_REG(PORTE_BASE_PTR,9)
#define PORTE_PCR10                              PORT_PCR_REG(PORTE_BASE_PTR,10)
#define PORTE_PCR11                              PORT_PCR_REG(PORTE_BASE_PTR,11)
#define PORTE_PCR12                              PORT_PCR_REG(PORTE_BASE_PTR,12)
#define PORTE_PCR13                              PORT_PCR_REG(PORTE_BASE_PTR,13)
#define PORTE_PCR14                              PORT_PCR_REG(PORTE_BASE_PTR,14)
#define PORTE_PCR15                              PORT_PCR_REG(PORTE_BASE_PTR,15)
#define PORTE_PCR16                              PORT_PCR_REG(PORTE_BASE_PTR,16)
#define PORTE_PCR17                              PORT_PCR_REG(PORTE_BASE_PTR,17)
#define PORTE_PCR18                              PORT_PCR_REG(PORTE_BASE_PTR,18)
#define PORTE_PCR19                              PORT_PCR_REG(PORTE_BASE_PTR,19)
#define PORTE_PCR20                              PORT_PCR_REG(PORTE_BASE_PTR,20)
#define PORTE_PCR21                              PORT_PCR_REG(PORTE_BASE_PTR,21)
#define PORTE_PCR22                              PORT_PCR_REG(PORTE_BASE_PTR,22)
#define PORTE_PCR23                              PORT_PCR_REG(PORTE_BASE_PTR,23)
#define PORTE_PCR24                              PORT_PCR_REG(PORTE_BASE_PTR,24)
#define PORTE_PCR25                              PORT_PCR_REG(PORTE_BASE_PTR,25)
#define PORTE_PCR26                              PORT_PCR_REG(PORTE_BASE_PTR,26)
#define PORTE_PCR27                              PORT_PCR_REG(PORTE_BASE_PTR,27)
#define PORTE_PCR28                              PORT_PCR_REG(PORTE_BASE_PTR,28)
#define PORTE_PCR29                              PORT_PCR_REG(PORTE_BASE_PTR,29)
#define PORTE_PCR30                              PORT_PCR_REG(PORTE_BASE_PTR,30)
#define PORTE_PCR31                              PORT_PCR_REG(PORTE_BASE_PTR,31)
#define PORTE_GPCLR                              PORT_GPCLR_REG(PORTE_BASE_PTR)
#define PORTE_GPCHR                              PORT_GPCHR_REG(PORTE_BASE_PTR)
#define PORTE_ISFR                               PORT_ISFR_REG(PORTE_BASE_PTR)
#define PORTE_DFER                               PORT_DFER_REG(PORTE_BASE_PTR)
#define PORTE_DFCR                               PORT_DFCR_REG(PORTE_BASE_PTR)
#define PORTE_DFWR                               PORT_DFWR_REG(PORTE_BASE_PTR)

/* PORT - Register array accessors */
#define PORTA_PCR(index)                         PORT_PCR_REG(PORTA_BASE_PTR,index)
#define PORTB_PCR(index)                         PORT_PCR_REG(PORTB_BASE_PTR,index)
#define PORTC_PCR(index)                         PORT_PCR_REG(PORTC_BASE_PTR,index)
#define PORTD_PCR(index)                         PORT_PCR_REG(PORTD_BASE_PTR,index)
#define PORTE_PCR(index)                         PORT_PCR_REG(PORTE_BASE_PTR,index)

/**
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PORT_Peripheral */


/* ----------------------------------------------------------------------------
   -- RCM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Peripheral RCM
 * @{
 */

/** RCM - Peripheral register structure */
typedef struct RCM_MemMap {
  uint8_t SRS0;                                    /**< System Reset Status Register 0, offset: 0x0 */
  uint8_t SRS1;                                    /**< System Reset Status Register 1, offset: 0x1 */
  uint8_t RESERVED_0[2];
  uint8_t RPFC;                                    /**< Reset Pin Filter Control register, offset: 0x4 */
  uint8_t RPFW;                                    /**< Reset Pin Filter Width register, offset: 0x5 */
  uint8_t RESERVED_1[1];
  uint8_t MR;                                      /**< Mode Register, offset: 0x7 */
} volatile *RCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register accessors */
#define RCM_SRS0_REG(base)                       ((base)->SRS0)
#define RCM_SRS1_REG(base)                       ((base)->SRS1)
#define RCM_RPFC_REG(base)                       ((base)->RPFC)
#define RCM_RPFW_REG(base)                       ((base)->RPFW)
#define RCM_MR_REG(base)                         ((base)->MR)

/**
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* SRS0 Bit Fields */
#define RCM_SRS0_WAKEUP_MASK                     0x1u
#define RCM_SRS0_WAKEUP_SHIFT                    0
#define RCM_SRS0_LVD_MASK                        0x2u
#define RCM_SRS0_LVD_SHIFT                       1
#define RCM_SRS0_LOC_MASK                        0x4u
#define RCM_SRS0_LOC_SHIFT                       2
#define RCM_SRS0_LOL_MASK                        0x8u
#define RCM_SRS0_LOL_SHIFT                       3
#define RCM_SRS0_WDOG_MASK                       0x20u
#define RCM_SRS0_WDOG_SHIFT                      5
#define RCM_SRS0_PIN_MASK                        0x40u
#define RCM_SRS0_PIN_SHIFT                       6
#define RCM_SRS0_POR_MASK                        0x80u
#define RCM_SRS0_POR_SHIFT                       7
/* SRS1 Bit Fields */
#define RCM_SRS1_JTAG_MASK                       0x1u
#define RCM_SRS1_JTAG_SHIFT                      0
#define RCM_SRS1_LOCKUP_MASK                     0x2u
#define RCM_SRS1_LOCKUP_SHIFT                    1
#define RCM_SRS1_SW_MASK                         0x4u
#define RCM_SRS1_SW_SHIFT                        2
#define RCM_SRS1_MDM_AP_MASK                     0x8u
#define RCM_SRS1_MDM_AP_SHIFT                    3
#define RCM_SRS1_EZPT_MASK                       0x10u
#define RCM_SRS1_EZPT_SHIFT                      4
#define RCM_SRS1_SACKERR_MASK                    0x20u
#define RCM_SRS1_SACKERR_SHIFT                   5
/* RPFC Bit Fields */
#define RCM_RPFC_RSTFLTSRW_MASK                  0x3u
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK)
#define RCM_RPFC_RSTFLTSS_MASK                   0x4u
#define RCM_RPFC_RSTFLTSS_SHIFT                  2
/* RPFW Bit Fields */
#define RCM_RPFW_RSTFLTSEL_MASK                  0x1Fu
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK)
/* MR Bit Fields */
#define RCM_MR_EZP_MS_MASK                       0x2u
#define RCM_MR_EZP_MS_SHIFT                      1

/**
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base pointer */
#define RCM_BASE_PTR                             ((RCM_MemMapPtr)0x4007F000u)
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- RCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RCM_Register_Accessor_Macros RCM - Register accessor macros
 * @{
 */


/* RCM - Register instance definitions */
/* RCM */
#define RCM_SRS0                                 RCM_SRS0_REG(RCM_BASE_PTR)
#define RCM_SRS1                                 RCM_SRS1_REG(RCM_BASE_PTR)
#define RCM_RPFC                                 RCM_RPFC_REG(RCM_BASE_PTR)
#define RCM_RPFW                                 RCM_RPFW_REG(RCM_BASE_PTR)
#define RCM_MR                                   RCM_MR_REG(RCM_BASE_PTR)

/**
 * @}
 */ /* end of group RCM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- RFSYS
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Peripheral RFSYS
 * @{
 */

/** RFSYS - Peripheral register structure */
typedef struct RFSYS_MemMap {
  uint32_t REG[8];                                 /**< Register file register, array of��\ �}r����{�ݼ�M�;Y0J�[���Ha����٢Y�Nu$r�U7�Zn�?�~�OmRF��A*�L	ǿп�B�u��ñ��T|S!~�sS|�SPpTy�Ug�~���9�ݤ�@�|e�U����c>�0�
k\i΀���.�c
�לĚM�ьʶQ��� P��	��|smM 1h��^�i��¬L2G��U�9�:D�@/���f����ߐ2̢=��q�_�cC�Ҿg�H"*Ƣ��X��򓱙 �?M!�W��r��TN\��gmu�k��7B��<��=�@�i2�i�Q���2�M��/��$G��qÕ�F�F+�5H���3܎���bJ����2Y��9�����=��:,pHVG?,,۞�_,�h��p.����]��P�\ȭT�u�q�l	}�·64�SG)U|�1Z�c�ׂ0�@�5�.�R�c�t�.�N�ql��9�A��3 ��rW�T�T�x#�'3���<���C$`zx��Li\95oA>io���Jm#j���e��)�I<�:�y�a�Z��n`YqK�Q�����Z�[�'+�[.���l�E����*�<H�p�6�%HV��,���������������}����ӉV6��V�,bl�z� p���vo�+�D��i~1�N��X�x���nУ`�!#�&����5E��U7���o���`q�Nb=�/��^a���������������X�>��3����X��Z�f�){�20���4s�F`y��[w}���<���#ѥ����MK�ϰX���ll�Vc���/���3I����*�f3YNU�����VE��&2	�q2�U���wo]�Q�=d�pk�,w\�E�M�(���+�"��͏���&�8��v�1� n���m{L��@�{LU���4�� �l����{d�_ށ���!���H��k��N �s���.��C����ݓP?$|t�+�dB7�D���%w��$+���!�-P�
=o�C�Co x�	��O���w�Q5�r�5'4 �n+P-rx�7����6T���KT�	J�R�I��5R;~������"�f�\N��±g��֢"��hp������BuJ��h=!�'z(��h���X���;�1���m�uqMhA='����v�mSP �q���֜H><�L�����s�|��+Ӹ}�Z�����suFr(Dy�)�˹_�+5D�OC�-�YG�4Z1����*�D>u��3���9Q 3Wp��$E�k{����Y��.�$��\�����B�N7����ķMS���	9��R'�,�Iny��y�0�\N���1�<s���������v,"A������׍���C�&qsY�{؆���*�;��=��\|�	�Q� Ɖ�j����4���>�֕�
ã������G��?�K���ü���<$5�s	y�ֵ�:.�5��&ӹ)��&�M�:"�fIjq�X�IW'��xOl�Y��1g�����N��;����R5�T��҅;t��l6)�A�#v`6���M�rhw�݉l��lx8�e���GgV��B�H��5Ш/�|j��Rn8r^�
J9�^O!ml��-�����7
�ِ�YJv��!�#�5Ϭ���B<�}B􄅧��$<SM�X�D-7_
�Zn�DY�x���]p#8mw�[�6�J�&|�زp
��E+o$4Z�jm�d.킖wLRZ��&%[��ک��iR�êZS1�u���п��~诅�,[gs	X*����CV�'�hZ� c�>����i�)�"I�8�dYdk��L4�+�[¾�H-�Nbc"��'�3`e�"&�O�v@�,V6��$��F��(���2>~1�U|;��R��s�z�٦��L24����7 z��g���g�͛�~��-q�N����t̓�2���ͳ��V<��)�/{��r"��H�߃x���4�-�A[��b��H����qԛz|%4����!����"�v����cBi�>�g��Nxpointers */
#define RFSYS_BASE_PTRS                          { RFSYS_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros
 * @{
 */


/* RFSYS - Register instance definitions */
/* RFSYS */
#define RFSYS_REG0                               RFSYS_REG_REG(RFSYS_BASE_PTR,0)
#define RFSYS_REG1                               RFSYS_REG_REG(RFSYS_BASE_PTR,1)
#define RFSYS_REG2                               RFSYS_REG_REG(RFSYS_BASE_PTR,2)
#define RFSYS_REG3                               RFSYS_REG_REG(RFSYS_BASE_PTR,3)
#define RFSYS_REG4                               RFSYS_REG_REG(RFSYS_BASE_PTR,4)
#define RFSYS_REG5                               RFSYS_REG_REG(RFSYS_BASE_PTR,5)
#define RFSYS_REG6                               RFSYS_REG_REG(RFSYS_BASE_PTR,6)
#define RFSYS_REG7                               RFSYS_REG_REG(RFSYS_BASE_PTR,7)

/* RFSYS - Register array accessors */
#define RFSYS_REG(index)                         RFSYS_REG_REG(RFSYS_BASE_PTR,index)

/**
 * @}
 */ /* end of group RFSYS_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RFSYS_Peripheral */


/* ----------------------------------------------------------------------------
   -- RFVBAT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Peripheral RFVBAT
 * @{
 */

/** RFVBAT - Peripheral register structure */
typedef struct RFVBAT_MemMap {
  uint32_t REG[8];                                 /**< VBAT register file register, array offset: 0x0, array step: 0x4 */
} volatile *RFVBAT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RFVBAT - Register accessor macros
   ---------------------------------------------------------------------------- */
��\ �}r����{�ݼ�M�;Y0J�[���Ha����٢Y�Nu$r�U7�Zn�?�~�OmRF��A*�L	ǿп�B�u��ñ��T|S!~�sS|�SPpTy�Ug�~���9�ݤ�@�|e�U����c>�0�
k\i΀���.�c
�לĚM�ьʶQ��� P��	��|smM 1h��^�i��¬L2G��U�9�:D�@/���f����ߐ2̢=��q�_�cC�Ҿg�H"*Ƣ��X��򓱙 �?M!�W��r��TN\��gmu�k��7B��<��=�@�i2�i�Q���2�M��/��$G��qÕ�F�F+�5H���3܎���bJ����2Y��9�����=��:,pHVG?,,۞�_,�h��p.����]��P�\ȭT�u�q�l	}�·64�SG)U|�1Z�c�ׂ0�@�5�.�R�c�t�.�N�ql��9�A��3 ��rW�T�T�x#�'3���<���C$`zx��Li\95oA>io���Jm#j���e��)�I<�:�y�a�Z��n`YqK�Q�����Z�[�'+�[.���l�E����*�<H�p�6�%HV��,���������������}����ӉV6��V�,bl�z� p���vo�+�D��i~1�N��X�x���nУ`�!#�&����5E��U7���o���`q�Nb=�/��^a���������������X�>��3����X��Z�f�){�20���4s�F`y��[w}���<���#ѥ����MK�ϰX���ll�Vc���/���3I����*�f3YNU�����VE��&2	�q2�U���wo]�Q�=d�pk�,w\�E�M�(���+�"��͏���&�8��v�1� n���m{L��@�{LU���4�� �l����{d�_ށ���!���H��k��N �s���.��C����ݓP?$|t�+�dB7�D���%w��$+���!�VBAT_REG_LH_MASK)
#define RFVBAT_REG_HL_MASK                       0xFF0000u
#define RFVBAT_REG_HL_SHIFT                      16
#define RFVBAT_REG_HL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HL_SHIFT))&RFVBAT_REG_HL_MASK)
#define RFVBAT_REG_HH_MASK                       0xFF000000u
#define RFVBAT_REG_HH_SHIFT                      24
#define RFVBAT_REG_HH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HH_SHIFT))&RFVBAT_REG_HH_MASK)

/**
 * @}
 */ /* end of group RFVBAT_Register_Masks */


/* RFVBAT - Peripheral instance base addresses */
/** Peripheral RFVBAT base pointer */
#define RFVBAT_BASE_PTR                          ((RFVBAT_MemMapPtr)0x4003E000u)
/** Array initializer of RFVBAT peripheral base pointers */
#define RFVBAT_BASE_PTRS                         { RFVBAT_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- RFVBAT - Register accessor macros
   ---------------------------------------���t<\��H�0�j1����3I,Xɝ�Ǘ��Z��ܿ��N�/OD��S#�1t]�چ7�cH�cޤ��Ko����Oѝsk�S^H~�Y<��͒�i���KX:�V����Y[��f������AJ@B�%�xn��z��C9J��|�\���2�D�_R���,�	~ʮB�n�E�p:Z��Ԗ9AlV]񘠤�i��ez�b»� �Y��	yƀ�Q��4�]
�pP��MR�uA1{�4��UCaΝ	[��1�t=+ƫ�$�7�9[U�F�:ꦉ2=�az�E�Nq��-��h�Я�Sd�	���6��4�N�^����:�����'wzv^�'�<�֮�_�|	�Ξk	�ڴ{'�K�1��e+SJB���A���L�A�8��e�I~�LƩ��� ߽/�@
$����J����9�y �����/���~^�Z@R{ &FE�O��%6�B �4�R��aơsY��p�*�(3�B�_:����d����ACKN2�D\$��3)8,cN�^� b�C3'#ǥ����[qB
O�A�]Z38Zq��^����^ZJ�p�6P���ɏE|��L�EnZ�x�%�J?���
�ȩ�'���2J>d�A�f��=n���п�r 8��B�A�㑌����I�u����tQ�A���>���*4��d���!���I�xI�� ���$��	�41�C:�/�����Ab|���ǡC�24�הU��y�4���p ���,�Ț�\9�#��'�+��A�hkf%��r�#����N�VB|M6�5����ل���ڍ��rT���aNv��.Q!���LB�V���c8t4M�)��d��E����<�H(%�d���9�e��m8ѫ��X֧�g0e������b��b��k	S>�i���ڹ)������Z���U�;�� K�"V�ev�Y���հi�K�1��'���lI�ߝ�0J�m�C�Z;;@ʢB݀�� ~u� */ /* end of group RFVBAT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RFVBAT_Peripheral */


/* ----------------------------------------------------------------------------
   -- RTC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Peripheral RTC
 * @{
 */

/** RTC - Peripheral register structure */
typedef struct RTC_MemMap {
  uint32_t TSR;                                    /**< RTC Time Seconds Register, offset: 0x0 */
  uint32_t TPR;                                    /**< RTC Time Prescaler Register, offset: 0x4 */
  uint32_t TAR;                                    /**< RTC Time Alarm Register, offset: 0x8 */
  uint32_t TCR;                                    /**< RTC Time Compensation Register, offset: 0xC */
  uint32_t CR;                                     /**< RTC Control Register, offset: 0x10 */
  uint32_t SR;                                     /**< RTC Status Register, offset: 0x14 */
  uint32_t LR;                                     /**< RTC Lock Register, offset: 0x18 */
  uint32_t IER;                                    /**< RTC Interrupt Enable Register, offset: 0x1C */
  uint8_t RESERVED_0[2016];
  uint32_t WAR;                                    /**< RTC Write Access Register, offset: 0x800 */
  uint32_t RAR;                                    /**< RTC Read Access Register, offset: 0x804 */
} volatile *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register accessors */
#define RTC_TSR_REG(base)                        ((base)->TSR)
#define RTC_TPR_REG(base)                        ((base)->TPR)
#define RTC_TAR_REG(base)                        ((base)->TAR)
#define RTC_TCR_REG(base)                        ((base)->TCR)
#define RTC_CR_REG(base)                         ((base)->CR)
#define RTC_SR_REG(base)                         ((base)->SR)
#define RTC_LR_REG(base)                         ((base)->LR)
#define RTC_IER_REG(base)                        ((base)->IER)
#define RTC_WAR_REG(base)                        ((base)->WAR)
#define RTC_RAR_REG(base)                        ((base)->RAR)

/**
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* TSR Bit Fields */
#define RTC_TSR_TSR_MASK                         0xFFFFFFFFu
#define RTC_TSR_TSR_SHIFT                        0
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK)
/* TPR Bit Fields */
#define RTC_TPR_TPR_MASK                         0xFFFFu
#define RTC_TPR_TPR_SHIFT                        0
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK)
/* TAR Bit Fields */
#define RTC_TAR_TAR_MASK                         0xFFFFFFFFu
#define RTC_TAR_TAR_SHIFT                        0
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK)
/* TCR Bit Fields */
#define RTC_TCR_TCR_MASK                         0xFFu
#define RTC_TCR_TCR_SHIFT                        0
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK)
#define RTC_TCR_CIR_MASK                         0xFF00u
#define RTC_TCR_CIR_SHIFT                        8
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK)
#define RTC_TCR_TCV_MASK                         0xFF0000u
#define RTC_TCR_TCV_SHIFT(             $!        �6
#defhne RTC_TCR_TCV(x)                `          (((uint32_t)(((uynt32_t(*h)9<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK)
#define rTC_TCROCIC_M@SK                         0xFF00000u
#dafine RTC_TCR_CIC_SXIFT                        2t
#define RTC_TCROCIC(x)           "               (()uint32_t)(((uint32_t)(x))<4RTCTCR_CIC_SHIFT))&RTC_TCR_CIC_MACK)
/* �R Bit Fields */
#define RT�OCR_SWR_MASK                     "  $ 0x1u
#define RtC_CF_SWR_SHIFT                         0
#define RTC^CR_WP�_MASK                          0x2u
#define RTC_CR_WPE_SHIF�                         1
#define RTC_CR_SUP_MASK   �                      0x4u
#debkne RTC_CR_SUP�SHIFT             (         ! 2
#define RTC_�R_UM_MASK                           0x8u
#define RTC_CR_UM_SHIFT                      `   3
#define RTC_CP_OSCE_MASK             (           0x10 u
#define RTC_CR_OSCE_SHIFT                        8
#define RTC_CR_CLKO_MACK      `  0              `0x20�u
#define RTC]CR_CLKO_SHIFT                        9
#define RTC_CR_SC16P_MASK                        0x400u
#define RTC_CR_SC16P_SHIFT                       10
#define RTC_CR_SC8P_MASK                         0x800u
#define RTC_CR_SC8P_SHIFT                        11
#define RTC_CR_SC4P_MASK                         0x1000u
#define RTC_CR_SC4P_SHIFT                        12
#define RTC_CR_SC2P_MASK                         0x2000u
#define RTC_CR_SC2P_SHIFT                        13
/* SR Bit Fields */
#define RTC_SR_TIF_MASK                          0x1u
#define RTC_SR_TIF_SHIFT                         0
#define RTC_SR_TOF_MASK                          0x2u
#define RTC_SR_TOF_SHIFT                         1
#define RTC_SR_TAF_MASK                          0x4u
#define RTC_SR_TAF_SHIFT                         2
#define RTC_SR_TCE_MASK                          0x10u
#define RTC_SR_TCE_SHIFT                         4
/* LR Bit Fields */
#define RTC_LR_TCL_MASK                          0x8u
#define RTC_LR_TCL_SHIFT                         3
#define RTC_LR_CRL_MASK                          0x10u
#define RTC_LR_CRL_SHIFT                         4
#define RTC_LR_SRL_MASK                          0x20u
#define RTC_LR_SRL_SHIFT                         5
#define RTC_LR_LRL_MASK                          0x40u
#define RTC_LR_LRL_SHIFT                         6
/* IER Bit Fields */
#define RTC_IER_TIIE_MASK                        0x1u
#define RTC_IER_TIIE_SHIFT                       0
#define RTC_IER_TOIE_MASK                        0x2u
#define RTC_IER_TOIE_SHIFT                       1
#define RTC_IER_TAIE_MASK                        0x4u
#define RTC_IER_TAIE_SHIFT                       2
#define RTC_IER_TSIE_MASK                        0x10u
#define RTC_IER_TSIE_SHIFT                       4
#define RTC_IER_WPON_MASK                        0x80u
#define RTC_IER_WPON_SHIFT                       7
/* WAR Bit Fields */
#define RTC_WAR_TSRW_MASK                        0x1u
#define RTC_WAR_TSRW_SHIFT                       0
#define RTC_WAR_TPRW_MASK                        0x2u
#define RTC_WAR_TPRW_SHIFT                       1
#define RTC_WAR_TARW_MASK                        0x4u
#define RTC_WAR_TARW_SHIFT                       2
#define RTC_WAR_TCRW_MASK                        0x8u
#define RTC_WAR_TCRW_SHIFT                       3
#define RTC_WAR_CRW_MASK                         0x10u
#define RTC_WAR_CRW_SHIFT                        4
#define RTC_WAR_SRW_MASK                         0x20u
#define RTC_WAR_SRW_SHIFT                        5
#define RTC_WAR_LRW_MASK                         0x40u
#define RTC_WAR_LRW_SHIFT                        6
#define RTC_WAR_IERW_MASK                        0x80u
#define RTC_WAR_IERW_SHIFT                       7
/* RAR Bit Fields */
#define RTC_RAR_TSRR_MASK                        0x1u
#define RTC_RAR_TSRR_SHIFT                       0
#define RTC_RAR_TPRR_MASK                        0x2u
#define RTC_RAR_TPRR_SHIFT                       1
#define RTC_RAR_TARR_MASK    �c���:� &U�g��$MJuR�G�/��0|H��F��S/ĕ8M4�$�r�
Wu�n�es�SD^cx��@)Y�����5�XWOu��	�Co�c��s/.X -���CjF���V��E0	��Vp���Gn/�PHp<�t�V@�!1o"�x�"f$�;����[7�Byx�o�Q�C��
�\��X �=�akP���Vǜ�tM�-x�U����/{n�(����*q���Nv�8'sPa�y�"�y�7���}8�^	�EƗD��>��y&��4�/E���n|�|�QAF��O��X�_��kD��F-���S �,3
��ID�o�i7}�{�9�`WxmV��BAT��є�A�6du�s��!��T�k�s"�yi�.��l z��gĔ�c8 l��'���@#8�tM���)�)�R�"X�ѻ��Qʁ���r�m!q+�.P�M�]�R�k��~�B!������Xagy�W�{T2/�n�:(#�.��B?���	wKK���̝u;����?�<�<̟��{Tus[t?�Y)Z����)��xZ��7�.���V��Y��'�Z���$P�ga���*j���H�K��,��!�[������
�3u�ˏ�`n�S�3�l� �`eY�VS��eT��e�qu�C�z���Ѷ]T%c4��'h��]��)����ilz����w�Q�3Zr%��q���}��(�j�V��Ӹͱlg������W�?~_R$��J�'�3K�.�ʣ�
�b���Q���������?l#5��"Z�M��p��^
a6'd*�	����E��!���1k*;e��H���欍��O�[��y�l��гe�ʎ�|�1��-���ü�����Lʼh�\�nI?��}�I(��_���._�f�`qX���148�s�.NƯ�x��}��[�P�:�ad�fT�p��%�:#;�3º�d�����:0ɛ���� ���% D�����=:!����v#��nç�T��w����}�~.�[�<����n���?�lx�g�J2NUu��Dæu|6ȸFϩ!8��3_3��3�I&�R<�(2�NR��M$T���I��1�K9!lqޅ�$� ��Aw\&EP�Ƿ<,�����H=��[ }���Jc"r�]E}r1�;�HD�2Be}�\�oj�W�[A�7��?g�>W�x�:�p��J_��ٷc�Dn�H������~O��ا�i&�Aâ���dy���cZ�zWC~�1�j��n!S����L�^�7����{��0`��4�)	��@E�&�5$�գbW�pO��-�ZY�g���[�dSGy��ID�o�i7}�{�9�h_:,ͱO_'�����;k� UP�I��-��?�l�s 6�DX���F>B��)���f~Lerl��'���Hay�1D����Z� �x�gZ����3�����p�u[>WC�M/��>�"�� �F��:�h������/WGX�Z�2A]�C�9lIe�`��1\�}ƙz49����6DQ���g�M�[�nH����1
/6�{"\��ZO��;��K��r�g���5�4�a�bU�=�ϛw�ga��m��x^	���-��9�[����"�n����@zi�20����z�1�xA��G�"$
�_S��eT��e�qu�C�z����>+FC��%��j@��E��Ԧ%nZ{͹��M��V�3[eB��0��}��(�j�V��Ӹͱlg�����S��BM^$��h�OK�[�K����.�H�����������
>Wve�ǻ@%��U�$��?I"st7e�v�۽����\���wR>Wt\tkƭ$�͛���h���=��a�n����ǃ�q�<�� ���α�����AǱe�Q�cD2�{��6Z��5��M �
�vmJ���ua$8�(w�5 ���
��p��V�]�7�li�kY�}��r(�7.6�>Ϸ������EB���n��Oň�W]t;��(��P�yyi� Ł�	h\��a��~��}����}�?j��Ğs������{M(�
��G��Y��N]� !�3�)x�"!�WO�a��0��|��.��+u�nl}���㻹H-oknש���\L���<�~bO�1�j���&S�Q�� :G�fm.�V@e���RW��-�BSH�&�N���z���9�����Pc���c,��e-���̩�n��WV]$K�~f�6uI8U���C�m�t����1F��?�"`3M�+\c-L��YF����Y�=��p� J�@������H���_w�]t(}(��J}���=W��xR����c���[G��=�2|mo�ϲ�|�yD��'vt�*�qm [)���,�?�7烖����HX�^�A[xaE���;H�#C���eOS&������	�tg�Qԇ�K���NU���{�镽>��޿����Qy�����k��|������.����,<���d��2?�ײ�.ͼ��"�~a|��mт~��g�mﳶ$�s�<���f��_�Cj��W��yj��-�-N�<j�/�6���O���N��A���'��XPD�Q�P��o�1IB��M�K��3N��`�,�l:����i���AFL�$PTh�[��0��B��So<s��(ےm�G?���:C��͌A��ݜ	[1FĽ	�W����m������hEz`�^+�����o�a����S*����=�y��/+okzɵ�R�{��ɛ"P�G�ɐ8�<אڙ��g�Q�c竀;)d&6Ϩ5˂�I�ZhB�|�"�!���J]��ב,��M A�sTJ_��Y�o�6c�X�ǰ]�wf/!�����5p?4hUK��hH����Z���_���j��C� 13Ou�ݼz��+@�=[���4�BD^�J"ϡ�Õz2�+�f�5+����J駰FK�6 �е�Ա��=���吚|�}��Ut	�����Q�I��%��4ڞ ��bcH��=ukM_U���4�O�'y�
��x;'��ܭv�z��I?��g��p�����M��t^�/򰍘�f����ћ���$��#�l��vy$m���3r�C�"��w���Ŝf�X��-���Fa�htۢ>y���G�d2c�*bE��
}/���
�#�K�.�O����i���c�\��v3W��8��7Va	�/Q��̻�l�ڇ�Ƞ��s,�׵����PE�usC�@� ��������v�b�ƭCАCd|(�U�d�ʽ:y����0,�?�Re�%^ͶNl�|͎7��ȭ��,�a8�RXr������c�2�������A�c��B��W����gw�u�[٤"ќ�t͔��Ţ�(��"�'�.a�Ǌ_�����?K��3���UD��f�E��j4�zϿ5ip|�'�Gu�^i�sr1�Pr�"���8�{�tU�Ҍ���#��Q~}
��g�i� y��S� qU�qƨ�W�S��拉��3q`�,f��bJ�/�mx�Q�DB-�=��*��l������\�1��K �Zy��9x�J���O�A;��B��AE�+�E�a���V��PY�$���a߉���?hkT.Xپ�H�u��N6Tô�>f M�
$�K�f$b�$AS��ݕwT�jE���]��&��8�ק��e�#�Y�8��M�Ie�w��I��ͼW��0a����_6��o�.6ߗw�9���c=��>����G�H���R���bcB��??=��`]�ɪ�r0�������
^��嵗Z)�臤�8�
G�c��\f���C�ȒP����'��~u�#�Y�5�@���[�#��"���}�w.���M^����Z�0��_f�\���,�b�\#KY�[��,�*.%�����v�u"�X�.�2�=X[0��lǥD�����Nj/a##ۮ�ސh�Н���Liu)1vaQ�?ҚHY[30�a-E���/8�D��#v�!Ygٵw�4�������Z�!��5���f�n����\�6�Ϳ�j�O�X�	 ��	t-]����
GC�KW��%�ۃة��(C��|�@�K)I�KS�a�ڎ�p�)a0�Q�zMG����c��S�� ��i\4(���䱩I:-G��G�;{�`���Dn�@;'ܳ	iZJ[��!:}#�|�J�,��ll��Y���^������ٖ?�t
W��^\�9?g2���oYm�>�;�d��#ϫyI�Ѫz��S=\����
7!�1T��������ܹX[E�<�`Ou4֑�*� 5�B��@,���y�3-`�	�-(�t}��y0�B�%,'�\���ǖ �M#��� ��~/�9ng�񄛻�@D��ET��*��V~�oy:K�4�S���������K	����A�\�xDP�ʥ]֤ ZQW*�)-.��B�I����>D��(�2��s$����A����L��2H�I����"Q`OV�CYAltl�;�2=�M��0UQ �K�z3��E0Z�4:0w�w2H. _BFV�6\D�m�f�^<˺ىH5?em:YT>�	3(шV@\М�un�h@��$:��']B�
w![��''�(H�մ?ʈ	t7@�D��7Ϗ9R%�S�J#i��t�'�oZK����~�PU(��G�+���(��v���E�z�@�R��Û���a�wF�L�A�5�B���^G�K&�E9��,��t�2*�(��3��ј�hB�,�[�dK7vo�	%C ����iަ��{��t! B��h�2M܀��Vws���"&9���e{����j�Bx�H)/H�x�1���#��\\��4�؟�������UF���(��_e�`���N㾝^����c_���V� �)8'���
���t}H��V�J.�>-�i� �	x�{��V8!���XǄ uP/ tm�\~�r~Q��C�����6����Z���3���t�Y��:��i� � �a��"`$�1�1���!�'��u{��3Cdn���Tc�Hȶmf��×�{��P�8���"i��QJ�f*q2�R㡡d��c���:� &U�g��$MJuR�G�/��0|H��F��S/ĕ8M4�$�r�
Wu�n�es�SD^cx��@)Y�����5�XWOu��	�Co�c��s/.X -���CjF���V��E0	��Vp���Gn/�PHp<�t�V@�!1o"�x�"f$�;����[7�Byx�o�Q�C��
�\��X �=�akP���Vǜ�tM�-x�U����/{n�(����*q���Nv�8'sPa�y�"�y�7���}8�^	�EƗD��>��y&��4�/E���n|�|�QAF��O��X�_��kD��F-���S �,3
��ID�o�i7}�{�9�`WxmV��BAT��є�A�6du�s��!��T�k�s"�yi�.��l z��gĔ�c8 l��'���@#8�tM���)�)�R�"X�ѻ��Qʁ���r�m!q+�.P�M�]�R�k��~�B!������Xagy�W�{T2/�n�:(#�.��B?���	wKK���̝u;����?�<�<̟��{Tus[t?�Y)Z����)��xZ��7�.���V��Y��'�Z���$P�ga���*j���H�K��,��!�[������
�3u�ˏ�`n�S�3�l� �`eY�VS��eT��e�qu�C�z���Ѷ]T%c4��'h��]��)����ilz����w�Q�3Zr%��q���}��(�j�V��Ӹͱlg������W�?~_R$��J�'�3K�.�ʣ�
�b���Q���������?l#5��"Z�M��p��^
a6'd*�	����E��!���1k*;e��H���欍��O�[��y�l��гe�ʎ�|�1��-���ü�����Lʼh�\�nI?��}�I(��_���._�f�`qX���148�s�.NƯ�x��}��[�P�:�ad�fT�p��%�:#;�3º�d�����:0ɛ���� ���% D�����=:!����v#��nç�T��w����}�~.�[�<�����n�>
�#0��X��w��OJ�dܘ� 	q�I_��b�a��EG3���Y3ׄ�k;��A�KwfӴE#�ė�e9־���Z	��%�"�KMo����R�e�k6��a:M�0�VJ e����s�o>�6�Sr�� �]���(���܄2-K��=\�q�T������c��Z[P)F�c&A
�~>{݀����:��v�펂K)��M�~\>@�&Qn A��TK����D�"�36��F�������<���e;v�6GC��/fw���0Z��u_󍵮D݂�ݕ0�\Ŷ���:��F{�T�|`V$���&��3艌����3�MY�C�C	:NSaW���h�i�$�~K
'&���Ԏ�	�^J�^���&�
��uxҸ�}��ܪ=��Q������Ki�̳͆�1��H�����4���ܑ�$^���)��bd����{��!�wL�@,L��W����)�pޅ������b�g�_�Cj��W��yj�� �.
T�u$�/�Uĕ��0冟]��a��;�v���S����<�tN����@�` ����	�do�����i���;*"�2WI�8��B����oIX��>��q�]8���}Oo'��z��2݀| ��z08k�M���D���a�ʨ��gMl�pֶ�̺&�5���ɓl�����-���ACo`U>W���CY�J��ӛ3]�7 �G�]������7�c竀;)d&6Ϩ5˂�I�DO!Aʻn�>�t����fc��<����#<�.Jm��BIV� ��e&�B���1�k3l`�6��ީ�M.7	.<0-��z@�� ��9��m�*��}���-m�SYZ)�Ժ	�p�G:�H?�Ö�~+U�i᨟��m2�b�f@�Ī��l˞�bmi�H,�ƶۜ;��h������(���6Q������&�J��c6��4��b�u
,��\,1.��mm�&dT��s0�D��6ob����0�����l��`��Ҵ�to��Ev�֌���)����ы���G��,�F��#0j1���.<�ux'�+�ʟN�9O��ӑ�n�Q��^���%���_���<�F
�8B��M���"�{*�y��o.�>Q��Я��x>�
oj��*�)ҵ��� f�5̒E)h�DQ��̻�l�ڇ�Ƞ��J�ǥ�o�ͫzF�?? �V#��10��������#K�˖h*��gh8��^S	�+���-����Wy�y�&��0s?��UG�b
љK��r�ߩ�%�a8�RXr������k�{����W��o�S�_PT��P�)�$n����'�^H�]�w>��䲃,Tޝ��ŀR��l�t�P��������^;�����<'��f���}�6��5cQ�$�3�,�Y�q@X�2����K�Gb�Ͽ��F�w�#;:C��"�i�g��p�[F�&6����co�8���!z	{�R��,�/�mx�Q�DB-�=��*��o��C�\�ŋ0�Dk��`,�:�S8C��"�3����R;��F�L�AV�#��j���Z��X�G���K�����I wT%Y���:���:W~ ��t�MI+s�"�(�M�V>%jw�Ӵ�Q�F|���<��a��,�����T?�s�o�92ә0�^�.[�A��I���W�� 9���U9ҝw�^2U��!�+]���bE}��]����"�<���q7���6��??=��`]�ɥ�x,�k��ݔ��Y�Ć��f��䥀�>�fȶWՋoF����������5��tj��I�l�9Ɯ�J����J��h��Q��l�=;�q�r��)�Y�e�_f�\���#�h�%p47s�K x�	���SޔS^�y���QKhp��fȈn���E�]xX=+���ւ�ٕ����=f;N"hY�6Ά;:9rZS�c[ �@\�-��P�HYR��%�$�$#����;�%��8f�H����2�o9�	�����1Ee����
�O�+�#��ln@sSK      "          0x4�0200u
#define SCB_ICSR_ISRPENDING_SHIFT                22
#ddfine SCB_ICSR_ISRPREEiPT_MASK               ( 0x800000e
#define �CB_ICSR_ISRPREEMPT_SHIFT               023
3d%fine SCB_ICSR_PENDSVALR]MASK                  0x2000000w
#define SCB_ICSR_PELDSTCLP_SHIFT                 25
#define SCB_ICSR_PEFDSTSET_MASK `        0       0x4000000U
#define SCB_YCSR_PENDSTSET_SHIFT                 26
#define SCB_ICSR_PENDRVCLR_MASK    0             0x8000000u
#define SCB_ICSS_SENFSVCLR_SHIFT    !!           27#define SCB_ICSR_PENDSVsET_MASK 0                0x10000000u
#defife SCR_ICSROPENDSVSAT_SHIFT    0            28
#defing RCB_ICSR_NMIPENDSET_MASK             �   0x800000004
#define SCB_ICSR_NMIPEN�SET_SHIFT                3q
/* VTOR Bit Fields */
#define SC@_VTOV_TBLOFF_MASK              0     0xFFFFFF80u
#define Sc_VTOR_BLKFF_SHHFT                    7
#define SCB_VTOR_TBLOFF(x)          0      $     (((uint32_t)(((uint32_t)(x)�<<SCB_WTOR_TBMOFF_SHIFT))&SCB_TOR_TBLOFF_MAK)
/* AIrCR Bit Fields */
#define SCB_AIRCR_VECVREQET_MASK                 0x0u
#define SCB_AIRCR_VECTRESET_SHIFT                0
#define SCB_AIRCR_VECTCLRACTITE_MASK             0x2u
#dufane SCB_AIRCR_VECTCLRACTIVESHIFT!           1
#define SCB_AIRCR_SYSRGSETREQ_ASK               0x4u
#define(SCB_AIRCR_SYSVESGTREQ_SH�FT          ,   2
#define SCB_EIRCR_PRIGROP_M@SK $                0x700u
#de$ine SCC_AIRCR_PRIGROUP_SHIFT                 8M
#define SCB_AIRCR_PRIGROUP(x)      `             (((uint#2_t)(((5int32_t)(y))<<SCb_AIRCR_PRIGROUP_SHIFT))&SCB_AIRCR_PRIGROUP_MESK)#define SCB_@IRCR_ENDIANNESS_MASK `   `          0x8000u
#defife SCB_AIRCRWANDIANNESS_SHIFT               5
#fefine SCB_AIRCR]VECTKEY_MASK                   0xFFFV0000u
#dEfine SCB]AIRCR_VECTKEYSHIFT        "   "�  ``16
'define SCB_AIRCR_VECPKEY(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_AIRCR_VECTKEY_SHIFT))&SCB_IIRSR_VECTKEY_MASK)
/*�SCR Bit Fiehds */
#define SC_SCR_SLEEPONEXIT_MASK    �            0x2u
#define SCB_SCR_SLEEPONEXIT_SHIFT                1
#define SCB_SCR_SLEEPDEEP_MASK                   0x4u
#define SCB_SCR_SLEEPDEEP_SHIFT                  2
#define SCB_SCR_SEVONPEND_MASK                   0x10u
#define SCB_SCR_SEVONPEND_SHIFT                  4
/* CCR Bit Fields */
#define SCB_CCR_NONBASETHRDENA_MASK              0x1u
#define SCB_CCR_NONBASETHRDENA_SHIFT             0
#define SCB_CCR_USERSETMPEND_MASK                0x2u
#define SCB_CCR_USERSETMPEND_SHIFT               1
#define SCB_CCR_UNALIGN_TRP_MASK                 0x8u
#define SCB_CCR_UNALIGN_TRP_SHIFT                3
#define SCB_CCR_DIV_0_TRP_MASK                   0x10u
#define SCB_CCR_DIV_0_TRP_SHIFT                  4
#define SCB_CCR_BFHFNMIGN_MASK                   0x100u
#define SCB_CCR_BFHFNMIGN_SHIFT                  8
#define SCB_CCR_STKALIGN_MASK                    0x200u
#define SCB_CCR_STKALIGN_SHIFT                   9
/* SHPR1 Bit Fields */
#define SCB_SHPR1_PRI_4_MASK                     0xFFu
#define SKB_ShPR3_PRI_4_SHIFT                    0�#define SCB_SHPR1]PRI_4(x)                       ((�uint32_t)(((uint32_t)(x))<<SCB_SHPR1_pRI_4_SHIfT))&SCB_SHPR1_PRI]4_MASK)
#define RCB_SHPR1_PRY_5_MASK   (      $     `    0xFF00u
#define SKB_SHPR1_PRI_5_SXIFT"   (`              8
#define SCB_SHPR1_PRI_5(x)  $       (           "(((uint32_t((((uint32_t)(x))<<SCB_SHPR1_PRI_5_SHIFT))&SCB_SHXR1_TRI_5_MASK)
#define SCB_SHPR1_PRI_6_MAK     0     `    0    0xFF0000u
#eefine SCB_SHPR1_PRI_6_SHIFT          0         16
#defiNe WCB_SHPR1_PRI_6(x-                       (((uint32_t-(((uint32^t)(x))<<SCBSHPR1_PRI_6_SHIFT)9&SCB_SHPR1_PRI_6_MASK+
o* SHPR2 Bit Fiulds */
#define SCB_SHPR2_PRI_11�M�SK                (   0xFF000000u
#define SCB_SHPR2_PRI_11_SHIFT  "                24
#define SCB\SHPR2_PRI_15(x)           "          (((uint32_t)()(uint32_t)(x))<<SCB_SHPR2_PRI_11_SHIFT))&CCB_SHPR2OTRI_11_mASK)
/* SHPR3 Bit Fields */#define SCB_SHPR3_PRI]14_MASK  `                 0xFF0000u
#define SCB_SHPR3_PRI_14_SHIFT        0 `        16
#define SCB_SHPR3_PRI14(x)                      (((uint32_t)(((uint32_t)(x))=<SSB_SHPR3_PPI_14_SHIFT)+&RCB_SHPR3_PRI_14_MASK)#define SCBWSHQR3_PRI_15_MASK                    0xFF002000u
#define SCB_SHPR3_PRI_15_SHIFT                   24
#define(SCB_SHPR3_PRI_15 x)(               "     (((uint2_t)(((uint32_t)(x))<<SCB_SHPR3_PRI_15_SHIFT))&SCF_SHPR3_PSI_15_MASK(
/* �HCSR Bit Fields�*?
#define SCB_SHCRR_MEMFAULTACT_MSJ          !    0x1u
#define SCB_SHCSR_MMMFAuLTCCT_SHIFT              0M
#define SA_SHCSRBU�AULTACT_MASK               0x2u
#define SCB_SHCSR_BQSFAULTACT_SHIFV!             1
#devinm SCB_SHCSB_USGFAULTACT_IASK               0x8uM
#deFine SCB_SHCSR_USGFAULTAT_SHIFT             03
#define SCB_sHCSR_SVCALLACT_MASK     !           0x80u
#defiNe SCB_SHCSR_WVCALLACT_SHIFT    @           6
#deg�ne SCB_SHCSR_MONITORACT_MASK    `(         0x100u
#define SCB_SHCSR_MONITORACT_SHIFT         0     8
#defije SCBOSHCSR_QENDS^AcT_MARK                0x400u
#lefine SC�_SHCSs_PENDSVACT_SHIFT                10*#define GCB_SHCSR_SYWTICKACT_MASK        !    $( 0x800u
#define �CB_SHCSR_SYSTIKACT_SHIFT               21J#define SCB_SHCSR_USGFAULTPENDED_MASK            0x1000u
#define SCB_SHCSR_USGFAULTPENDED_SHIFT           12
#define SCB_SHCSRWMEMFAULTPENDED_MASK            0x2000u
#tefin SCB_SHCSR_MEMFAULTPENDED_SHIFT    &(     13
#define SCB_SHCSR_BUSFAULTPENDED_MA[    � "     0x4000u
#define SCB_SHCSR_BUSFAULTPENDED_SHIFT           10
#definu SCB_SLCSR_SVCALLPEND�D_MASK              0x8000u
#define SCB_[HCSR_SVCALLPENDED_SHIFT 0    !      15
#define sCB_SHCsR_MEMFAULTENA_MASK               0x10000u
#define SCJ_SCSR_MEMFAULTENA_SHIFT      `       16
#define SCB_SHCSR_BUSFAULTENA_MAS[      �      � 4x00000u-
#define SC�_SHCSR_BUSFAULTENA_SXIFT            ! 17
#tefine SCB_SHCSR_USGFaULTENA_MASK               0x4000�u
#define SAB�SHC�R_USGFAULTENA_SHIFT              18
/* CFSR Bit Fialds */
#defin% SCB_CFSR_IACCVAOL_MASK   $               0x0u
#define SCB_CFSR_IACCVIOL�SHIFT    `             0
#define SCB_CFSR_DACCVIOL_ASK          �        0x2U
#define SCB_CFSR_dACCVIOL_SHIFT  !               1
#define SCB_CFSR_MUNSTKEPR_MASK  0               0x8u
#define SCB_CFSR_�UNSTKERR_SHIFT                 3
#define(SBB_CDSR_MSTKERR_IWK   "                0x10u#define SCB_CFSR_ESTKERR_SHIFT         (         4
#define SCB_CFSZ_LLSPERR_OASK                    0x20u
#defind SCB_CNSR_MNSPERRWQHIT �           `     5
#define CCB]CFSR_MMARVALKD_MASK    `  0      "   0x80u#definm SCB_CFSR_MM@RVALITSHIFT                07J#defije SCB_CFSR_IBUSERR_MAQ[                   00x100u
#define sCB_CFSR_�BUSERRQHIFT                   8
#define SCB�CFSR_PRECISERR_]AQK                  0�200u
#defqne SCB_CFSR_PRECISERR_SHIFT                 9
#define SCB_CFSR_IMPRECISERR_MASK                0x400u
#ddfine SCB_CFSR_IMPRECISERR_SHMFT "             14
#define SCB_CFSR_UNSTKERR_MASK      �            0x800u
#tefine SCB_CFSZ_UNCTKERR_SHIFT(        0        11
#define SCB[CFSR_STKERR_MASK  #                  0x1000u
#define SCB_CFSR_STKERR_SHIFT           �  $     12
#define SCB_CFSR_LCPERR_MASK   `                 0x2000u
�define SCB_CFSR_LSPERR_SXIFT                ` ! 13
#define SCB_CFSR_BFABVALID_OASK                  0x8000u
#define SCB_CFSRBDARVALID_SHIFT         0     � 15
#define SCF_CFSR_UNDEFINSTr_]ASK                 0x10000u
#defyne SCB_CFSR_UNDEFINSTR_WIIFT    !           16
#defi.e SCCWCGSR_INVSTATE_MASK             $     0x20000u
#define SCB_CFSR_INVSTATE_SHIFP                  97
#define SCB_CFSR_INVPC_MASK           !      !0!"0x40000u
#define SCB_CFSR_INV@C_SHIFT (                   18
#de�ioe SCB_CFSR_NOCP_MASK"    `                 0x80000u
#define SCB_CFSR_NOCP_SHIFT               `      19
#define SCB_CFSR_UNALIGNED_MASK                  0x1000000u
#define SCB_CfSR_UNAMIGNED_WHIFT         �   !   24
#define SCB_CFSR_DIVBY^ERO_MASK                  0x2000000u
#define RCB_CFSRDIVB]ZERO_SHIFT                 25
/* HGSR Bit Fields */
#define SCB_HFSR_VECTTBL_MASK                    0x2u
#define SCB_HFSR_VECTTBL_SHIFT                   1
#define SCB_HFSR_FORCED_MASK                     0x40000000u
#define SCB_HFSR_FORCED_SHIFT                    30
#define SCB_HFSR_DEBUGEVT_MASK                   0x80000000u
#define SCB_HFSR_DEBUGEVT_SHIFT                  31
/* DFSR Bit Fields */
#define SCB_DFSR_HALTED_MASK                     0x1u
#define SCB_DFSR_HALTED_SHIFT                    0
#define SCB_DFSR_BKPT_MASK                       0x2u
#define SCB_DFSR_BKPT_SHIFT                      1
#define SCB_DFSR_DWTTRAP_MASK                    0x4u
#define SCB_DFSR_DWTTRAP_SHIFT                   2
#define SCB_DFSR_VCATCH_MASK                     0x8u
#define SCB_DFSR_VCATCH_SHIFT                    3
#define SCB_DFSR_EXTERNAL_MASK                   0x10u
#define SCB_DFSR_EXTERNAL_SHIFT                  4
/* MMFAR Bit Fields */
#define SCB_MMFAR_ADDRESS_MASK                   0xFFFFFFFFu
#define SCB_MMFAR_ADDRESS_SHIFT                  0
#define SCB_MMFAR_ADDRESS(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_MMFAR_ADDRESS_SHIFT))&SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define SCB_BFAR_ADDRESS_MASK                    0xFFFFFFFFu
#define SCB_BFAR_ADDRESS_SHIFT                   0
#define SCB_BFAR_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_BFAR_ADDRESS_SHIFT))&SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define SCB_AFSR_AUXFAULT_MASK                   0xFFFFFFFFu
#define SCB_AFSR_AUXFAULT_SHIFT                  0
#define SCB_AFSR_AUXFAULT(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_AFSR_AUXFAULT_SHIFT))&SCB_AFSR_AUXFAULT_MASK)

/**
 * @}
 */ /* end of group SCB_Register_Masks */


/* SCB - Peripheral instance base addresses */
/** Peripheral SystemControl base pointer */
#define SystemControl_BASE_PTR                   ((SCB_MemMapPtr)0xE000E000u)
/** Array initializer of SCB peripheral base pointers */
#define SCB_BASE_PTRS                            { SystemControl_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register instance definitions */
/* SystemControl */
#define SCB_ACTLR                                SCB_ACTLR_REG(SystemControl_BASE_PTR)
#define SCB_CPUID                                SCB_CPUID_REG(SystemControl_BASE_PTR)
#define SCB_ICSR                                 SCB_ICSR_REG(SystemControl_BASE_PTR)
#define SCB_VTOR                                 SCB_VTOR_REG(SystemControl_BASE_PTR)
#define SCB_AIRCR                                SCB_AIRCR_REG(SystemControl_BASE_PTR)
#define SCB_SCR                                  SCB_SCR_REG(SystemControl_BASE_PTR)
#define SCB_CCR                                  SCB_CCR_REG(SystemControl_BASE_PTR)
#define SCB_SHPR1                                SCB_SHPR1_REG(SystemControl_BASE_PTR)
#define SCB_SHPR2                                SCB_SHPR2_REG(SystemControl_BASE_PTR)
#define SCB_SHPR3                                SCB_SHPR3_REG(SystemControl_BASE_PTR)
#define SCB_SHCSR                                SCB_SHCSR_REG(SystemControl_BASE_PTR)
#define SCB_CFSR                                 SCB_CFSR_REG(SystemControl_BASE_PTR)
#define SCB_HFSR                                 SCB_HFSR_REG(SystemControl_BASE_PTR)
#define SCB_DFSR                                 SCB_DFSR_REG(SystemControl_BASE_PTR)
#define SCB_MMFAR                                SCB_MMFAR_REG(SystemControl_BASE_PTR)
#define SCB_BFAR                                 SCB_BFAR_REG(SystemControl_BASE_PTR)
#define SCB_AFSR                                 SCB_AFSR_REG(SystemControl_BASE_PTR)

/**
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SCB_Peripheral */


/* ----------------------------------------------------------------------------
   -- SDHC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Peripheral SDHC
 * @{
 */

/** SDHC - Peripheral register structure */
typedef struct SDHC_MemMap {
  uint32_t DSADDR;                                 /**< DMA System Address register, offset: 0x0 */
  uint32_t BLKATTR;                                /**< Block Attributes register, offset: 0x4 */
  uint32_t CMDARG;                                 /**< Command Argument register, offset: 0x8 */
  uint32_t XFERTYP;                                /**< Transfer Type register, offset: 0xC */
  uint32_t CMDRSP[4];                              /**< Command Response 0..Command Response 3, array offset: 0x10, array step: 0x4 */
  uint32_t DATPORT;                                /**< Buffer Data Port register, offset: 0x20 */
  uint32_t PRSSTAT;                                /**< Present State register, offset: 0x24 */
  uint32_t PROCTL;                                 /**< Protocol Control register, offset: 0x28 */
  uint32_t SYSCTL;                                 /**< System Control register, offset: 0x2C */
  uint32_t IRQSTAT;                                /**< Interrupt Status register, offset: 0x30 */
  uint32_t IRQSTATEN;                              /**< Interrupt Status Enable register, offset: 0x34 */
  uint32_t IRQSIGEN;                               /**< Interrupt Signal Enable register, offset: 0x38 */
  uint32_t AC12ERR;                                /**< Auto CMD12 Error Status Register, offset: 0x3C */
  uint32_t HTCAPBLT;                               /**< Host Controller Capabilities, offset: 0x40 */
  uint32_t WML;                                    /**< Watermark Level Register, offset: 0x44 */
  uint8_t RESERVED_0[8];
  uint32_t FEVT;                                   /**< Force Event register, offset: 0x50 */
  uint32_t ADMAES;                                 /**< ADMA Error Status register, offset: 0x54 */
  uint32_t ADSADDR;                                /**< ADMA System Addressregister, offset: 0x58 */
  uint8_t RESERVED_1[100];
  uint32_t VENDOR;                                 /**< Vendor Specific register, offset: 0xC0 */
  uint32_t MMCBOOT;                                /**< MMC Boot register, offset: 0xC4 */
  uint8_t RESERVED_2[52];
  uint32_t HOSTVER;                                /**< Host Controller Version, offset: 0xFC */
} volatile *SDHC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros
 * @{
 */


/* SDHC - Register accessors */
#define SDHC_DSADDR_REG(base)                    ((base)->DSADDR)
#define SDHC_BLKATTR_REG(base)                   ((base)->BLKATTR)
#define SDHC_CMDARG_REG(base)                    ((base)->CMDARG)
#define SDHC_XFERTYP_REG(base)                   ((base)->XFERTYP)
#define SDHC_CMDRSP_REG(base,index)              ((base)->CMDRSP[index])
#define SDHC_DATPORT_REG(base)                   ((base)->DATPORT)
#define SDHC_PRSSTAT_REG(base)                   ((base)->PRSSTAT)
#define SDHC_PROCTL_REG(base)                    ((base)->PROCTL)
#define SDHC_SYSCTL_REG(base)                    ((base)->SYSCTL)
#define SDHC_IRQSTAT_REG(base)                   ((base)->IRQSTAT)
#define SDHC_IRQSTATEN_REG(base)                 ((base)->IRQSTATEN)
#define SDHC_IRQSIGEN_REG(base)                  ((base)->IRQSIGEN)
#define SDHC_AC12ERR_REG(base)                   ((base)->AC12ERR)
#define SDHC_HTCAPBLT_REG(base)                  ((base)->HTCAPBLT)
#define SDHC_WML_REG(base)                       ((base)->WML)
#define SDHC_FEVT_REG(base)                      ((base)->FEVT)
#define SDHC_ADMAES_REG(base)                    ((base)->ADMAES)
#define SDHC_ADSADDR_REG(base)                   ((base)->ADSADDR)
#define SDHC_VENDOR_REG(base)                    ((base)->VENDOR)
#define SDHC_MMCBOOT_REG(base)                   ((base)->MMCBOOT)
#define SDHC_HOSTVER_REG(base)                   ((base)->HOSTVER)

/**
 * @}
 */ /* end of group SDHC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SDHC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Masks SDHC Register Masks
 * @{
 */

/* DSADDR Bit Fields */
#define SDHC_DSADDR_DSADDR_MASK                  0xFFFFFFFCu
#define SDHC_DSADDR_DSADDR_SHIFT                 2
#define SDHC_DSADDR_DSADDR(x)                    (((uint32_t)(((uint32_t)(x))<<SDHC_DSADDR_DSADDR_SHIFT))&SDHC_DSADDR_DSADDR_MASK)
/* BLKATTR Bit Fields */
#define SDHC_BLKATTR_BLKSIZE_MASK                0x1FFFu
#define SDHC_BLKATTR_BLKSIZE_SHIFT               0
#define SDHC_BLKATTR_BLKSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<SDHC_BLKATTR_BLKSIZE_SHIFT))&SDHC_BLKATTR_BLKSIZE_MASK)
#define SDHC_BLKATTR_BLKCNT_MASK                 0xFFFF0000u
#define SDHC_BLKATTR_BLKCNT_SHIFT                16
#define SDHC_BLKATTR_BLKCNT(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_BLKATTR_BLKCNT_SHIFT))&SDHC_BLKATTR_BLKCNT_MASK)
/* CMDARG Bit Fields */
#define SDHC_CMDARG_CMDARG_MASK                  0xFFFFFFFFu
#define SDHC_CMDARG_CMDARG_SHIFT                 0
#define SDHC_CMDARG_CMDARG(x)                    (((uint32_t)(((uint32_t)(x))<<SDHC_CMDARG_CMDARG_SHIFT))&SDHC_CMDARG_CMDARG_MASK)
/* XFERTYP Bit Fields */
#define SDHC_XFERTYP_DMAEN_MASK                  0x1u
#define SDHC_XFERTYP_DMAEN_SHIFT                 0
#define SDHC_XFERTYP_BCEN_MASK                   0x2u
#define SDHC_XFERTYP_BCEN_SHIFT                  1
#define SDHC_XFERTYP_AC12EN_MASK                 0x4u
#define SDHC_XFERTYP_AC12EN_SHIFT                2
#define SDHC_XFERTYP_DTDSEL_MASK                 0x10u
#define SDHC_XFERTYP_DTDSEL_SHIFT                4
#define SDHC_XFERTYP_MSBSEL_MASK                 0x20u
#define SDHC_XFERTYP_MSBSEL_SHIFT                5
#define SDHC_XFERTYP_RSPTYP_MASK                 0x30000u
#define SDHC_XFERTYP_RSPTYP_SHIFT                16
#define SDHC_XFERTYP_RSPTYP(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_XFERTYP_RSPTYP_SHIFT))&SDHC_XFERTYP_RSPTYP_MASK)
#define SDHC_XFERTYP_CCCEN_MASK                  0x80000u
#define SDHC_XFERTYP_CCCEN_SHIFT                 19
#define SDHC_XFERTYP_CICEN_MASK                  0x100000u
#define SDHC_XFERTYP_CICEN_SHIFT                 20
#define SDHC_XFERTYP_DPSEL_MASK                  0x200000u
#define SDHC_XFERTYP_DPSEL_SHIFT                 21
#define SDHC_XFERTYP_CMDTYP_MASK                 0xC00000u
#define SDHC_XFERTYP_CMDTYP_SHIFT                22
#define SDHC_XFERTYP_CMDTYP(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_XFERTYP_CMDTYP_SHIFT))&SDHC_XFERTYP_CMDTYP_MASK)
#define SDHC_XFERTYP_CMDINX_MASK                 0x3F000000u
#define SDHC_XFERTYP_CMDINX_SHIFT                24
#define SDHC_XFERTYP_CMDINX(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_XFERTYP_CMDINX_SHIFT))&SDHC_XFERTYP_CMDINX_MASK)
/* CMDRSP Bit Fields */
#define SDHC_CMDRSP_CMDRSP0_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP0_SHIFT                0
#define SDHC_CMDRSP_CMDRSP0(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_CMDRSP_CMDRSP0_SHIFT))&SDHC_CMDRSP_CMDRSP0_MASK)
#define SDHC_CMDRSP_CMDRSP1_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP1_SHIFT                0
#define SDHC_CMDRSP_CMDRSP1(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_CMDRSP_CMDRSP1_SHIFT))&SDHC_CMDRSP_CMDRSP1_MASK)
#define SDHC_CMDRSP_CMDRSP2_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP2_SHIFT                0
#define SDHC_CMDRSP_CMDRSP2(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_CMDRSP_CMDRSP2_SHIFT))&SDHC_CMDRSP_CMDRSP2_MASK)
#define SDHC_CMDRSP_CMDRSP3_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP3_SHIFT                0
#define SDHC_CMDRSP_CMDRSP3(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_CMDRSP_CMDRSP3_SHIFT))&SDHC_CMDRSP_CMDRSP3_MASK)
/* DATPORT Bit Fields */
#define SDHC_DATPORT_DATCONT_MASK                0xFFFFFFFFu
#define SDHC_DATPORT_DATCONT_SHIFT               0
#define SDHC_DATPORT_DATCONT(x)                  (((uint32_t)(((uint32_t)(x))<<SDHC_DATPORT_DATCONT_SHIFT))&SDHC_DATPORT_DATCONT_MASK)
/* PRSSTAT Bit Fields */
#define SDHC_PRSSTAT_CIHB_MASK                   0x1u
#define SDHC_PRSSTAT_CIHB_SHIFT                  0
#define SDHC_PRSSTAT_CDIHB_MASK                  0x2u
#define SDHC_PRSSTAT_CDIHB_SHIFT                 1
#define SDHC_PRSSTAT_DLA_MASK                    0x4u
#define SDHC_PRSSTAT_DLA_SHIFT                   2
#define SDHC_PRSSTAT_SDSTB_MASK                  0x8u
#define SDHC_PRSSTAT_SDSTB_SHIFT                 3
#define SDHC_PRSSTAT_IPGOFF_MASK                 0x10u
#define SDHC_PRSSTAT_IPGOFF_SHIFT                4
#define SDHC_PRSSTAT_HCKOFF_MASK                 0x20u
#define SDHC_PRSSTAT_HCKOFF_SHIFT                5
#define SDHC_PRSSTAT_PEROFF_MASK                 0x40u
#define SDHC_PRSSTAT_PEROFF_SHIFT                6
#define SDHC_PRSSTAT_SDOFF_MASK                  0x80u
#define SDHC_PRSSTAT_SDOFF_SHIFT                 7
#define SDHC_PRSSTAT_WTA_MASK                    0x100u
#define SDHC_PRSSTAT_WTA_SHIFT                   8
#define SDHC_PRSSTAT_RTA_MASK                    0x200u
#define SDHC_PRSSTAT_RTA_SHIFT                   9
#define SDHC_PRSSTAT_BWEN_MASK                   0x400u
#define SDHC_PRSSTAT_BWEN_SHIFT                  10
#define SDHC_PRSSTAT_BREN_MASK                   0x800u
#define SDHC_PRSSTAT_BREN_SHIFT                  11
#define SDHC_PRSSTAT_CINS_MASK                   0x10000u
#define SDHC_PRSSTAT_CINS_SHIFT                  16
#define SDHC_PRSSTAT_CLSL_MASK                   0x800000u
#define SDHC_PRSSTAT_CLSL_SHIFT                  23
#define SDHC_PRSSTAT_DLSL_MASK                   0xFF000000u
#define SDHC_PRSSTAT_DLSL_SHIFT                  24
#define SDHC_PRSSTAT_DLSL(x)                     (((uint32_t)(((uint32_t)(x))<<SDHC_PRSSTAT_DLSL_SHIFT))&SDHC_PRSSTAT_DLSL_MASK)
/* PROCTL Bit Fields */
#define SDHC_PROCTL_LCTL_MASK                    0x1u
#define SDHC_PROCTL_LCTL_SHIFT                   0
#define SDHC_PROCTL_DTW_MASK                     0x6u
#define SDHC_PROCTL_DTW_SHIFT                    1
#define SDHC_PROCTL_DTW(x)                       (((uint32_t)(((uint32_t)(x))<<SDHC_PROCTL_DTW_SHIFT))&SDHC_PROCTL_DTW_MASK)
#define SDHC_PROCTL_D3CD_MASK                    0x8u
#define SDHC_PROCTL_D3CD_SHIFT                   3
#define SDHC_PROCTL_EMODE_MASK                   0x30u
#define SDHC_PROCTL_EMODE_SHIFT                  4
#define SDHC_PROCTL_EMODE(x)                     (((uint32_t)(((uint32_t)(x))<<SDHC_PROCTL_EMODE_SHIFT))&SDHC_PROCTL_EMODE_MASK)
#define SDHC_PROCTL_CDTL_MASK                    0x40u
#define SDHC_PROCTL_CDTL_SHIFT                   6
#define SDHC_PROCTL_CDSS_MASK                    0x80u
#define SDHC_PROCTL_CDSS_SHIFT                   7
#define SDHC_PROCTL_DMAS_MASK                    0x300u
#define SDHC_PROCTL_DMAS_SHIFT                   8
#define SDHC_PROCTL_DMAS(x)                      (((uint32_t)(((uint32_t)(x))<<SDHC_PROCTL_DMAS_SHIFT))&SDHC_PROCTL_DMAS_MASK)
#define SDHC_PROCTL_SABGREQ_MASK                 0x10000u
#define SDHC_PROCTL_SABGREQ_SHIFT                16
#define SDHC_PROCTL_CREQ_MASK                    0x20000u
#define SDHC_PROCTL_CREQ_SHIFT                   17
#define SDHC_PROCTL_RWCTL_MASK                   0x40000u
#define SDHC_PROCTL_RWCTL_SHIFT                  18
#define SDHC_PROCTL_IABG_MASK                    0x80000u
#define SDHC_PROCTL_IABG_SHIFT                   19
#define SDHC_PROCTL_WECINT_MASK                  0x1000000u
#define SDHC_PROCTL_WECINT_SHIFT                 24
#define SDHC_PROCTL_WECINS_MASK                  0x2000000u
#define SDHC_PROCTL_WECINS_SHIFT                 25
#define SDHC_PROCTL_WECRM_MASK              D<<�iBt�C�^o!v�e�|�&е�q�{"L��zC!
�M#5=�K���8� ���VS�\�C�L��F9;~������"�f�L��ҡw��;��?��6%�����7�yJ|��~*:�-x$��h���X���;�1���m�uc]EkBxaKȷ!��SP�M2g#���l���ڕNI	�?�����s�|��+Ӹ}������&Pdc$Ld�~���?zi�
c�<
r�Z�3+�MF(����O�;Ra��Z���0W`D	#���k�B��r�����
�0���X������D�MgH����ķMS���	)��B7 �<�dDz�@_�'�V�$=�߷j�W�6<���������`":n2u�Ƣ���׍���n�%56�5]��ض�D�d����p\�hn�M�:ړ�t����=���>�֕�
óY�������<�:���W'����-D_I�R%YΤā�VU�fwZ��&��Z��C�2�V]�t;3R�Fo�s`=X��wS{	�E��;k/�����b��U����
-G�3��v��H�}&9�Q�v[J5�W���r#���`�r��$<D�M��0�)jC��W�:��J��P�gû@vXQ�
z8H�7(pOm��-�����N	����K3���P�#¨����i\�,q����I] &�X�D-7_
�Zn�L�&���oW<nvj|�;�!�<��
��x��R w(4[�m�Z䋐q?+)��CB4�Y����.:'���3&u��ְ��������AZ\	lҍ���U�#��!�祹N7A�3�4I�SC�6;0��~�D8�;�z5͈�h�0"n�[�t��}# �`g�'�4@�8Z I�~ox�^Ye�zh�z�����t!y1�&|Tz��RF��=E�(�ӹ��[[����2Sp��f���i�Ў���J�+�������2���ͳ��V4��]�|��q&�����(��W�[�?4��!��'Є��P5��3V5q}����d���^؟|�����dW!�$��Թx2�ꓙ�z������$��V�C��	Ʊ�|U 9c�1
�c���9��Ȁ}�^�=���]�D�;�|���k/̄���Y�l������x�8I�2i�.�9���6�sd��ؕ�e\�|ú}ϓqu}��ڔWD=�h$6L,Uc��
U�$A���k���Y�O���U�84KJ�Z-e1�L�Nps�]%���]��
�c�mEO�������U�	���b�\=�%%�i��Pk+U����!�=#�UT���.���hw&;-��{�6Sj��D7q��,m{,wA��b?�@����Mr����&������Č�k�^�m�\�`ؔ��]`�¾*	4[.4dqVuk���$�@��N�@�E;��fK@������K�S�~�*6��蕍����	�?OD,��A�k�1��g\JA3oD�_ii̟�X����Ȋ��L��T�i��ṣ��Kȕ]���t��)�*���~���%��_Qw�!������~�vGbU=>YUN���߆����ck���5�yj/��OX�W� ���'�6�,D��ڲ�[�&�#�5�{����
�r��Kժ�h�ᨶ}��;p�M����m?������1&?
�,Xg��n�v�!m,�\u��2��I��(	#f�\)�&���Z�PK�><L�ك��I� ����F����"	՚a����{����U#�"�c�0	�>iu;كޛ���/K�ޥ��V]4�bm��-�? ���-�!��t;���7�+9"铁��4�sJ�?�_�gY$�~D��d0A����|x��v'wO]��u���\����쿴 �� g�Į��m�%�Q��>��7�Spx�6�5�[�)����EQ���iBkP�">������{����@�k� H8�&/xX��K%}	�ZG�궠G��b��.��zQ+�����8;��Zy\2눳�p�<�t��ra�p�%?5,~<�:ۍAh!3�r��LH�Z����Q� �������4)d	f��cV�efine SDHC_IRQSTAT_DINT_MASK                   0x8u
#define SDHC_IRQSTAT_DINT_SHIFT                  3
#define SDHC_IRQSTAT_BWR_MASK                    0x10u
#define SDHC_IRQSTAT_BWR_SHIFT                   4
#define SDHC_IRQSTAT_BRR_MASK                    0x20u
#define SDHC_IRQSTAT_BRR_SHIFT                   5
#define SDHC_IRQSTAT_CINS_MASK                   0x40u
#define SDHC_IRQSTAT_CINS_SHIFT                  6
#define SDHC_IRQSTAT_CRM_MASK                    0x80u
#define SDHC_IRQSTAT_CRM_SHIFT                   7
#define SDHC_IRQSTAT_CINT_MASK                   0x100u
#define SDHC_IRQSTAT_CINT_SHIFT                  8
#define SDHC_IRQSTAT_CTOE_MASK                   0x10000u
#define SDHC_IRQSTAT_CTOE_SHIFT                  16
#define SDHC_IRQSTAT_CCE_MASK                    0x20000u
#define SDHC_IRQSTAT_CCE_SHIFT                   17
#define SDHC_IRQSTAT_CEBE_MASK                   0x40000u
#define SDHC_IRQSTAT_CEBE_SHIFT                  18
#define SDHC_IRQSTAT_CIE_MASK             ��&����`w0י�9(~���W��4BM�P�j�'��%��ZY��X�2a�����<Z��ߒ��jA���0t�`��Kصpۭ��B�a��Ȝ��j�r��&@���)��,��>b�p�r*������Av&���̦�qa=B�l�����'�Q���a��r�s�	[�����*su�����=�mJ���ߙQJ���-?J���+)����2teX��[���pi���^%F�+Qnzt@`]����%<��u��Ix�_���0|��#��1JL�^8���=m�"�(jFn�;�� p/�	�K�>�؍�է�հ͛�;'h�� AQo�=D�JK~bԓg���{�z��V��vl�{�֤i��d}��es�o�T;����j]��}a ��ޝ�>LCNhq$SF��F@Q����?�y8�0m�\;z��-R�z�0EYx��?;�}�]\���i
��m��g�S�ru��Z����V?���p%Z5�`�Ӛ@h� 9&K���z\�o���k8Xx����4�
+��4�7�p|0���:�#�'����A�{R���2E���foi����Ob<� 8o荈<_�}�)XI_�� T�����4�
-��.�֛�p�Qu2Z`O�Ǿ��O\w�L�%�N�����p�?�k��w
f|�ﶫr� �L?�%��Py�&a�s�� ���%��^s�.bv�vu<_`wLf������ЭB[���7{V��[�3�UY0�A��>n�8ǽž"Ru���U]���sh[TBB�K�������u��d��04&F��WyG�!�.r��@GZl�WWK��X�S�UY��i�����>�:YHc�;]�ᵹ Ը*.�<F�F���XD�e:�pf�8B��M��g�L���EOx���$)����RY��E��O,$�9���W�����＊��E�����j~��s)\ p����7�Y4�_��
8$��RF�Ԉ�{���X�>i�FTl�iS��            0x8u
#define SDHC_IRQSTATEN_DINTSEN_SHIFT             3
#define SDHC_IRQSTATEN_BWRSEN_MASK               0x10u
#define SDHC_IRQSTATEN_BWRSEN_SHIFT              4
#define SDHC_IRQSTATEN_BRRSEN_MASK               0x20u
#define SDHC_IRQSTATEN_BRRSEN_SHIFT              5
#define SDHC_IRQSTATEN_CINSEN_MASK               0x40u
#define SDHC_IRQSTATEN_CINSEN_SHIFT              6
#define SDHC_IRQSTATEN_CRMSEN_MASK               0x80u
#define SDHC_IRQSTATEN_CRMSEN_SHIFT              7
#define SDHC_IRQSTATEN_CINTSEN_MASK              0x100u
#define SDHC_IRQSTATEN_CINTSEN_SHIFT             8
#define SDHC_IRQSTATEN_CTOESEN_MASK              0x10000u
#define SDHC_IRQSTATEN_CTOESEN_SHIFT             16
#define SDHC_IRQSTATEN_CCESEN_MASK               0x20000u
#define SDHC_IRQSTATEN_CCESEN_SHIFT              17
#define SDHC_IRQSTATEN_CEBESEN_MASK              0x40000u
#define SDHC_IRQSTATEN_CEBESEN_SHIFT             18
#define SDHC_IRQSTATEN_CIESEN_MASK               0x80000u
#define SDHC_IRQSTATEN_CIESEN_SHIFT              19
#define SDHC_IRQSTATEN_DTOESEN_MASK              0x100000u
#define SDHC_IRQSTATEN_DTOESEN_SHIFT             20
#define SDHC_IRQSTATEN_DCESEN_MASK               0x200000u
#define SDHC_IRQSTATEN_DCESEN_SHIFT              21
#define SDHC_IRQSTATEN_DEBESEN_MASK              0x400000u
#define SDHC_IRQSTATEN_DEBESEN_SHIFT             22
#define SDHC_IRQSTATEN_AC12ESEN_MASK             0x1000000u
#define SDHC_IRQSTATEN_AC12ESEN_SHIFT            24
#define SDHC_IRQSTATEN_DMAESEN_MASK              0x10000000u
#define SDHC_IRQSTATEN_DMAESEN_SHIFT             28
/* IRQSIGEN Bit Fields */
#define SDHC_IRQSIGEN_CCIEN_MASK                 0x1u
#define SDHC_IRQSIGEN_CCIEN_SHIFT                0
#define SDHC_IRQSIGEN_TCIEN_MASK                 0x2u
#define SDHC_IRQSIGEN_TCIEN_SHIFT                1
#define SDHC_IRQSIGEN_BGEIEN_MASK                0x4u
#define SDHC_IRQSIGEN_BGEIEN_SHIFT               2
#define SDHC_IRQSIGEN_DINTIEN_MASK               0x8u
#define SDHC_IRQSI\�������L���6X�jN(�ӥ�C���ء�t�[po�Ɠi��i�2���"Ve9�A4f�=yj�U�.��gQ���)7y�LyQi�憝���db$��P��2���l�G��ȌJ��[�w� i[�6j�~^��ԠBY�ֹ�����3��h~@�����/��s�w���:��o���;ȕ=v�]5�m��WҎH��q�����OP���ǥTt�U�N�ב�r�0�����|Z�nXx�ʍ����� �ǗT��2x\�N.6S��cd�f+t!��J]�p�f2�PC��KJ�e�M����N��h��Ȭ���E3^�����@m�����.U�`�r����?�����jM�Lf��g��i���~������&�۫��E4����H)c����ҵs�nu�n�</�x�	*�<f(�0�+%�j�;�~�F�2�v3�l���4�ǔ�U��=�S��}��o�l�c�,�.!`�nQ��R��>��m��(�b�q I�L�M�u�ى� -��)тo�����Hۥ�E�B��b�+X��N���v@8B6�=h�'��3�J��:�`�͸�{����Yf`��(�'Zk�z9�t��-����c��%�8*-]�a���r�(<�%�O�©"�]2��Զ!,��K3Z@t�&�"�BK��1(A3��M�ک�2u1�b��7$�%a�4�L�
@4�́�_�L\��@�����K)�
x?xMK��(��0���@旅k�#����2�}�2�O[�rD����=׋���5��Fq��p	*���b�A�sL��P�����=ۃ�[7�l�������u'W0�Ԥ��/��-8z�)NSHc��<�kQ����_\sw���S�r����'�}|Xp�=N��%�c^��TDLv(�o螛����PWT�+�=Ӂ�6�?7�*kF�b��U���ބ�]��ux�Ş.�7�a��b����v�,Lj��'�i�>��$�g����z�Ă![�h�G�qA`�"�̓;��U�{��L��⍓7�n�%hs�������2�����Z(�E��2){^6k�����<�E�2zݠ�u-���WNK2���G�e�/��[0�
|���]d�}�+��Y3����NXв8�Hzo�	+ѽ2�#�=o�E���D>�����8y���vv�Sk:���	`4�iE2+x�PUL���Ѯ�X����=/���9�-�s��0�h�H�f펁�y+4���0�{����,�� ��+L��/��)�V"Ml��摬]��^������}Zo:y�(9�����?���?K�����+9J��a��=�Vc��ӯ�]�'�j���j��Z1����ҵ�E6��ʮ�K��"a�:��#�9�̈�8�O=>���%O��$<�1�S/bY�8��[>� %l�b�1%����d���)�.UW
'�������~IEN��!jq��6�%)���:S���*�<��=Vi&w���b!8���'�� �]Ҽ=���z�'�����Z/X�Ӿ�C�cN��1���a�.��c=�}��Y�N�L��
?i1�4<�fO�d�g��Թ!O�1j�L��"�<O�)ضĴ~��v�kq��Ѵ^�������Ei]=K�h�UE�<�1~2��"HZ��=t��׹� b�s�9�iu�B]Њ�L%�Av�)˪��t ��"㦒�]�B$�J������|	N>�}g$��K�y
�iR�� ��1��˯���l)kj�$�,�`�:��rL,68VT�2��筓y;;Y��&x�[�FV����`���z��^�ID�\�]΃��wx�����À1����c8t��n�z;��L��>�Y�,��ʱ}�=��Z6����j�/^�t��(��-��3RN��Qˏ����"QvἪ.���E)��H�`w�T�Ն���p�����؋�e����:T��cɈ���zv��ȡ�݅�4��]�P�A~nz�����`S�a�
�ܤ�j
v
%k���:����F92I�L֖fine SDHC_AC12ERR_AC12IE_@ASK          $      0x10u-
#d��ine SD@C_AC12ERR_AC12IE_SHINT                4
#define SDHC_QC12ERR_CNIBAC12E_MESK  `           0x80u
#define SDHC_AC12ERR_CNIBAC12E_SHIFT(            7
/* H�SApBLT @it Fields */
#define SDHC_HTCAPBLT_MBL_MASK  !        "  !    0x70000u�
#dafine SDHC_HTC�PBLT_MBL_SHIFT                  16
#define SDHC_HTCAPBLT�MBL(x)                   $ (((uint32_t)(((uint32_t)hx))<<SDHC_H�CAPBLT_MBL_SHIFU))&�DHC_HTCAPBLT_MBL_MASK)
#define SDHC_HTCAPBLT_ADMAS_MaSK                (0x100000u
�Define SDHC_HTCAPBLT_ADMAS_SHIFT                20
#defioe SDHC_HTCAPBLT_HSS_MASK                   0x200000u
#define SDHC_HTCAPBLT_HSS_SHIFT                  21
#define SDHC_ITAPLT_DMAS_MASK   `              0x440000u
#define RDHC_HTCAPBLT_DMAS_SHM�T                 22
#deviFe SDHC_HTCAPBLT_SRS_MASK                   0x800000u
#define SDHC_HTcAPBLt_SRS_SHIT                  23
#define SDHC_HPCAPBLT_VS33_MASK   (              0x1000000u
#define SLHC_HTC@PBLT_VS33_SHIFT            "    24
#define SDHC_HTCAPBLT_VS30_MASK                  0x20000 0u
#define SDLC_HTKAPBLT_VS30_SHIFT                 25#define SDHC_HTCAPBLTVS18_MASK (                0x4000000u
#define SDHC_HTCAPBLD_VS18_SIIFT                 26
/* WML!B�t Fields */
#define QDHC_WML_VDWML_MASK                 `    0xFFa
#define�SDHC_WML\RDWML_SHIFT    `           !    0-
#define SDHC_WM\_RDWML(x)   !                    (((uint32_t)(h(uint32_t)(x))=<SDHC_WML_RDWML_SHIFT))&SDHC_SML_RDWML_MASK)
#define SDHCWML_WRWML_YASK   (                  0xFF0000u
#lefine CDHC_WML_VBWML�SHIFT                     16
#define SDHC_WML_WRWML(x)                        (((}int32t)(((uint32_t)(x))<<SDHC_WML_WRWML_HIT))&SDHC_ML_WRWML_MASK)
/* FEVT Bit Faemds */
#define SDHC_FEVT_AC12NE]MASK                    1x1u
#defmne SDHC_FEVT_CC12NE_SHIFT                   0
#de��ne SDHCOFEVT_AC12TOEWMASK                   0x2u
#defhne SDHC_FEVT_AC12TOE_SHIFT                  q
#d%fine SDHC_FEVT_AC12CE_MASK       "    `       0x4u
#define SDHC_FEVT_AC12CE_SHIFT                   2
#define SDHC_FEVT_AC12EBE_MASK                   0x8u
#define SDHC_FEVT_AC12EBE_SHIFT                  3
#define SDHC_FEVT_AC12IE_MASK                    0x10u
#define SDHC_FEVT_AC12IE_SHIFT                   4
#define SDHC_FEVT_CNIBAC12E_MASK                 0x80u
#define SDHC_FEVT_CNIBAC12E_SHIFT                7
#define SDHC_FEVT_CTOE_MASK                      0x10000u
#define SDHC_FEVT_CTOE_SHIFT                     16
#define SDHC_FEVT_CCE_MASK                       0x20000u
#define SDHC_FEVT_CCE_SHIFT                      17
#define SDHC_FEVT_CEBE_MASK                      0x40000u
#define SDHC_FEVT_CEBE_SHIFT                     18
#define SDHC_FEVT_CIE_MASK                       0x80000u
#define SDHC_FEVT_CIE_SHIFT                      19
#define SDHC_FEVT_DTOE_MASK                      0x100000u
#define SDHC_FEVT_DTOE_SHIFT                     20
#define SDHC_FEVT_DCE_MASK                       0x200000u
#define SDHC_FEVT_DCE_SHIFT                      21
#define SDHC_FEVT_DEBE_MASK                      0x400000u
#define SDHC_FEVT_DEBE_SHIFT                     22
#define SDHC_FEVT_AC12E_MASK                     0x1000000u
#define SDHC_FEVT_AC12E_SHIFT                    24
#define SDHC_FEVT_DMAE_MASK                      0x10000000u
#define SDHC_FEVT_DMAE_SHIFT                     28
#define SDHC_FEVT_CINT_MASK                      0x80000000u
#define SDHC_FEVT_CINT_SHIFT                     31
/* ADMAES Bit Fields */
#define SDHC_ADMAES_ADMAES_MASK                  0x3u
#define SDHC_ADMAES_ADMAES_SHIFT                 0
#define SDHC_ADMAES_ADMAES(x)                    (((uint32_t)(((uint32_t)(x))<<SDHC_ADMAES_ADMAES_SHIFT))&SDHC_ADMAES_ADMAES_MASK)
#define SDHC_ADMAES_ADMALME_MASK                 0x4u
#define SDHC_ADMAES_ADMALME_SHIFT                2
#define SDHC_ADMAES_ADMADCE_MASK                 0x8u
#define SDHC_ADMAES_ADMADCE_SHIFT                3
/* ADSADDR Bit Fields */
#define SDHC_ADSADDR_ADSADDR_MASK                0xF�FFFFFCu
#define SDHC_IDSADDR_ADSADDR_SHIFT         (     2
#define SDHCWADSADDR_ADSADDR(x)             !    )((uint#2_t)(h(uint32_t)(x))<|SDHC_ADSADDR_ADSADDR_S�FT))&SDHC_ADSADdR_ADSADDR_MASK)
/*"VENDOR Bit Fields */
#define SDC_VENDOR_EXTDM�EN_MASK    !          !0x1u
#define SDHC_VGNDOR_EXTDMAEN_SHIF�  $      0     0
#define SDHC_VENDOR_EXBLKNU_MASK                 0x2u
#define!SLHC_VENDOR_E�BLKNU_SHIFT  (             1
#define SDHC_VENDOR_ILTSTVAL_MASK (     `        pxFV0000u
#define SDHC_VENDOR_INTSTVAL_SHIFT               16
!define SDHC_VEN@OR_INTSTVAL(x)                  (((uint32t)(((eint32_t)(x))<<SDHC_VENDOR_HNDSTVAL_SHIFT))&SDHC_VE�DOR_INTSTVAL_MASK)
/* MMCBOOT Bit Gields */
#define`SD_MMcBOOT_D�OCVACK_MASK          !    0xFu
#define SDHC_MMCBOOT_DTOCVICK_SHiFT              2
#define SDHC_MMCFOOT_DTOCVACK(x)                 (((uint32_t)(((tint32_t)(x))<<SDHC_MMCBOOt_DTOCVACK_SHIFT))&SDHC_EMCBOOT_DTOCVACK_MAQK)
#define SDHC_MMCBOOU_BOOTAGK_MASK                0x10u
#define SDHC_MMCBOOT_BOOTACK_SHIFT               4
#define SDHC_MMCBOOT_BOOTMODE_MASK               0x20u
#define SDHC_MMCBOOT_BOOTMODE_SHIFT              5
#define SDHC_MMCBOOT_BOOTEN_MASK                 0x40u
#define SDHC_MMCBOOT_BOOTEN_SHIFT                6
#define SDHC_MMCBOOT_AUTOSABGEN_MASK             0x80u
#define SDHC_MMCBOOT_AUTOSABGEN_SHIFT            7
#define SDHC_MMCBOOT_BOOTBLKCNT_MASK             0xFFFF0000u
#define SDHC_MMCBOOT_BOOTBLKCNT_SHIFT            16
#define SDHC_MMCBOOT_BOOTBLKCNT(x)               (((uint32_t)(((uint32_t)(x))<<SDHC_MMCBOOT_BOOTBLKCNT_SHIFT))&SDHC_MMCBOOT_BOOTBLKCNT_MASK)
/* HOSTVER Bit Fields */
#define SDHC_HOSTVER_SVN_MASK                    0xFFu
#define SDHC_HOSTVER_SVN_SHIFT                   0
#define SDHC_HOSTVER_SVN(x)                      (((uint32_t)(((uint32_t)(x))<<SDHC_HOSTVER_SVN_SHIFT))&SDHC_HOSTVER_SVN_MASK)
#define SDHC_HOSTVER_VVN_MASK                    0xFF00u
#define SDHC_HOSTVER_VVN_SHIFT                   8
#define SDHC_HOSTVER_VVN(x)                      (((uint32_t)(((uint32_t)(x))<<SDHC_HOSTVER_VVN_SHIFT))&SDHC_HOSTVER_VVN_MASK)

/**
 * @}
 */ /* end of group SDHC_Register_Masks */


/* SDHC - Peripheral instance base addresses */
/** Peripheral SDHC base pointer */
#define SDHC_BASE_PTR                            ((SDHC_MemMapPtr)0x400B1000u)
/** Array initializer of SDHC peripheral base pointers */
#define SDHC_BASE_PTRS                           { SDHC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros
 * @{
 */


/* SDHC - Register instance definitions */
/* SDHC */
#define SDHC_DSADDR                              SDHC_DSADDR_REG(SDHC_BASE_PTR)
#define SDHC_BLKATTR                             SDHC_BLKATTR_REG(SDHC_BASE_PTR)
#define SDHC_CMDARG `      " !               $   SDHC_CM�ARG_REG(SDHK_BASE_PTR)
#define SDHC_XFERTYP     !                   $   SDHC_XFERTYP_REG(SDH_BASE_XTR)
#define SHC_CM�RSP0                         !   SDHC_CMDRSP_REG(SDHC_BAWE_PTR,0)
#define S\@C_CMDRSP1                             SDHC_CMDRSP_REG*SDHC_BASE_PTR,1)
#de&ine S@HC_CMDRSP2     0                     $ S�HC_CMD�SP_REG(SDHC_BASE_PTR$2)
#define SDHC_CMDRSP3        $              !     SDHCOCMDRSP_REW(SDHC_BASE_PTR,3)
#define SDHC_DATPORD                             SDHC_DATPORT_RUG(SDC_BASE_PTR)
#define SDHC_PRSSTAT !            `  0  (        SDHC_PRSSTAT_REG(SDHC_BASE_PTR)
#definE(SDHC_PROCTL    (                       ` SDHC_PROCTL_REE(SDHC_BASE_PTR)
#define SDHC_SYSCTL    !      "    $             SDHC_YSCTL_REG(SDLC_BASE_PTR9
#define SDHC_IRQSTAT      (                      SDHC_IRQSTAT_REG(SDHCWBASE_PTR)
#define SEHC_IRQST@TEN       `     `             SDHC_IRQSTATN_REG(RDHC_FASE_PTR(
#define �DHC_KQSIGEN     �$         (           SDHC_IRQdX��}��[��e�>��Un���ʊA|~I�!;���pkc��O~>/�����V*�<c=���WE*��]-h�䷃��2� nqV�ff��6Abc��~�[]mĉI��D'����� [߾zmG��h;	F�A������g[�|%6	:%�����D�J��@^w�Ƭ���<%m� ';UB>�&ݮPȈ��A��I�@���n�b� ̺�̘B��Spmn1fc�M#,8hMci��Z'
r�a!OpVc)*���WtC�S�9q��hħ�R��cg���g��(I)�cJ��q�slK�>�Xf�&�vk<����� �����V)ȿ��ex�}���an!"��(�
N�2�k��̘�Y��o�е�Ȋ�ǯ�l�;Ԟ�j�1Ts�Y�V[h�A�@U������D4*!��F���|�0��~��"���W���(\��t\��s�t�"V�*�&QJt���g���T���kIr��U��b��aIm��\�)-Y=�����C$&������姆P�f�e�� ��k��ʝ��*�hv�wєeG�=_ /�� �e,��dN�ǁ��0R7��E��3,�~��&�}���4i�C¡�������o]��e�U�}t���1&�<N�OW�d���u�Q�_�a��	��Q%�0k&�
��Y�q� �ʟf;�1�&�*#��>��_0�����������/π	�����}�)6�	����l�ky�ы�̙��\= ]<1�H^؊� W��
K5I�e��գN��(s`�����qg�DD�����V��*�	�rx;�I=(������:�7ӓ�0��|��xr� 0K��=
S�J�W͜J�4V�dx��q�3x�VB4�Qjz��޲5lժ��Z9�7�1��_�	�>�o��i�f��_���dt�փ򙋼�s3�q���Er�o����!@��;�Cꭄ!���n��ݓJ�b$#ݴ~�=;�-/e����	�R�y~���(��z~�t�����|���o��8��`f�}ԫ	1�bXc�x�f""0VNݸ$�	����^s.s�1����
��',��8��|1-���%����� [�0�q�.&Z�yܥ��5�>�(f������CP �=Ou>d���8�i��e����@8ƌ0z��kl�s:��)o9~�s�\�?[���Ck|u@<����]�Ŭd��8��p(Hq�d-�TⶬSz$��FT�e�h'6��5:�����"�[��65�krp9�ѯِ�a����ٛ��c��4B�H��u�;	:���ӷ�@�n�l��h�x�\I�HW���	.�5e-7�m�t�6�����*�G�u���W��w��������p�̋iq;�8v0�:?q_���!�x��s^D���u��
�Mfѡd�"%ޙa	Q�:q�%xr�cB+���l��ʰ���ò
K�fS�b�D������Aɟuz�� 6�Ԡ��R�>bҸ㭽N�\�y��hq��j�������tZ��5����_q�7��x)?I��<���Ce��[T�	[%6X+�NQ@���I�r���`k��90�`�� �5���jIz ����7���6tIV��Ks���_���v����]nZ`��g�I�#�<�]�o�4���n��n �	'��wz���3�IH�����`}]�L�qF�փ6�oC�Z@5��Τ��ia+��>M�^�L�duh4,+`���04e���$�u�i�N$�&�[s�5ȬT�U��dU���Vb��.������Z���  _�B�7h�"��>$�|T�c���ٲ�g�/Ȕ��ǃ�)��h�NP�'�HKrZ�m�c�z�����GlJe>4���IUpJ̍V��N�yh�z�c��5$WYa��8W����Ma6�R~����BC�xsֳ���P��_qy�қ�\![ss� `�e��v���[��jJC��:p��{�� A���d	-f0<]&L�Bʼ@�Y�ۘ��	��!�t��5���0(�\�,Tڃ�f���kn)��c��[��U�a븢56���L]���;TH�Zˌ��F�gV b2t�K�0��7�e�~B.�w��aND�Fvm�7�lL�h�Y��H�M�3I�7�p�JΫp�9�y}<�W�ۣn�Y<�gD�Ǔ���ޒ�g��5����~�>�M�u����J3OyCj�Zǟ�J^ I:h�=Ch����0E���aR����<�Cd����/p�!��B��!�b|wD�"���_|r�d�&�4N��Ap/Bsf9hyM�n�P���8dH�_ep��`(p�qʚ�?�g��I��G��k=U���������zvh�@kD1,����a5�p�Ӡ��|��:����b[�!����x�Љ{ߤh3?69x��R����lBq��H1�l�ѵ� ���gb�l�̾ν]�v������n!��̇Tj=8_H���q��h�e��LFqh��d�4��z���
r�(z2�ؐ8-����]�tX)>�n=�o!/����9�����.R���U���`J\�����c�
�m]�������ob�Z����~��0ܶ.�����!|]�`y�RV�4�$v>Ǵ�M��2��(d���샩	֮���[W4��ђ�3kŁ�3}	�m��~��"��/����ShM��Q-���~U���8���$���)���6������è����+#�o��3���;��AGd�����~<��vv8T>��q�+��V{mZ��&�P,����/_@q3	�])\&�i������C�2�!,�
{l��0����$ Zx���f�H�S6����ԟQ��fM]s��M�-k ��C6�A;�&��v����6��sfEr�l�U6�XK�W�_ӌ���4Z��u����T��zA+ �xߋ���	��}T�Sݱߕ��9u�d����gf ��6�}N9w��;R��¥Yk���g,Ë�����t����<�1lzp¼v�i�����aLQ�Ġ�S��&�	;G�h]�91s&NM�a1�?�O>�����}�G^�}=v��b�~r� ��:�M)��qM\����&�6�73:�.�O���J�e����G��VZ4dWY��?���)w[;wT�O���pbl<F�r4������;k�������슉}|HA�	���65�Ol�̙�#��#���Dx7Ĥ���2ɓ��I����I��ӹ{Y�uQ�'���B��e'�G2�`o��/$��D�O���J8��X[+@����L������A@zgE<S�k�&X'&ƅ�X-]��֤� P�}�o�E*�h�Mp�;��:c�/ⲙay��'�_Nd7-/8Q�
th�!�c��b�.�4C�Z���&*��p���=�Y�o�����ե�2�3���Y��?$x:����I�h�0+�M�(�$#o�3<�cj���%M���.f�1��!���n����R>g��Q�����D`�Oj�I`��]#ξ�%�d �KYc-�N�Ef�7�������߰g�!�S���N	i���_
2S�߆ze���;2kP��ݽ�Q��(�uA����n���k;Ʌa�믻�3S>3��.7��Q4��X�Ώ~D�i��s_X�������l�p.�)]e"d�]�z�R~528��7_�pJ.��!����|��қ�7淹�k!�z��$� �adz+*'�5�oH�h�e�^BE7��/�E�A�I�c�B�E�Z]1���x�}���f���w�\&g+4��6�;���z�VX�}w䳤K�.	_��NҶ6X)���t�k :��Y�Ή&r
ܚOn��e"�Aa���6wy�6S�һgΫ�ZO���^= ��q<Q��"
�1§[�nVY3F?���18]��8�L>��ڢ�&ۏ��\s��l��;"{?hm��	�4WE|��I�0�D��*���Q��FO�pE�h]����@���Y�W�6�3�' ��ͩ|�µ۱�C� �����]e��.����h9�?I�ħ�FM�vld+��{Z��i��rtL~�2�љ���g�b��ZN_��˲ҵ~Ӷ�X�`5�XԓF�;�����u8�g�0�d�a�^��=_I|@�X���
P(\Mꭉ��s��񳻨��b̘�)C*���J\n"���>�ը��9��9��;��8�0_UX��=)JT��ߕ��ϙ CĤ]�z)
��o,y�)��G�A����"�t�~�t�Cә�!��xKW�`?b@��)���Y�"��x3�|.�<��+�q�I p:8����~��$��$�R׮�jǔs?���$�5f@d	�X,қ�"�~%Z+�����y�d�4=b�>�)�>@?Tv!��W/`_�%2���vP�{7�n�]���N�%���0ޒ�A��i�h�ʴ9��4G�-�oy�@pE�z�1�fۺ7��;#/��S���"rv��'�� ���
n�'��?K�x�%ߌ�/ ���-�5��IH�� �tL��J�KՔ��gA�Gyt�E:EI�*��A��_�(��w1��c#i`9�)���
ȩ����_��1s��+���O����&����0'����qU���Y�	5Dp]f�H?�X�M��\��ն�p,���h�GVESL�)��U����Eb|_��KT��ل��p���m��Z������Z���>5�BWG��V���h�����ij.L��j�����ꔶ�����.�O.��ˢ�Ւ�b�Hvx���k-M�����vj�c�X�Mk��R)��G�_��v��r��7y;m�)_l��k��MN�ŽD���1�O�]/rS�n��W���2M(V�u��mN����p�'o9e�I`�r/������H�A�]%��ɡg��b���^�׈:�#0���q���2k�Q�y7ěa�fDF��&�8��:(M�"-0�ea8�
)�Vex7(�UӤj���5��l���:;�]��=ij4q�\�n��H$����+�av����}�b:�w�д��VVy�
7؅	dX��}��[��e�>��Un���ʊA|~I�!;���pkc��O~>/�����V*�<c=���WE*��]-h�䷃��2� nqV�ff��6Abc��~�[]mĉI��D'����� [߾zmG��h;	F�A������g[�|%6	:%�����D�J��@^w�Ƭ���<%m� ';UB>�&ݮPȈ��A��I�@���n�b� ̺�̘B��Spmn1fc�M#,8hMci��Z'
r�a!OpVc)*���WtC�S�9q��hħ�R��cg���g��(I)�cJ��q�slK�>�Xf�&�vk<����� �����V)ȿ��ex�}���an!"��(�
N�2�k��̘�Y��o�е�Ȋ�ǯ�l�;Ԟ�j�1Ts�Y�V[h�A�@U������D4*!��F���|�0��~��"���W���(\��t\��s�t�"V�*�&QJt���g���T���kIr��U��b��aIm��\�)-Y=�����C$&������姆P�f�e�� ��k��ʝ��*�hv�wєeG�=_ /�� �e,��dN�ǁ��0R7��E��3,�~��&�}���4i�C¡�������o]��e�U�}t���1&�<N�OW�d���u�Q�_�a��	��Q%�0k&�
��Y�q� �ʟf;�1�&�*#��>��_0�����������/π	�����}�)6�	����l�ky�ы�̙��\= ]<1�H^؊� W��
K5I�e��գN��(s`�����qg�DD�����V��*�	�rx;�I=(������:�7ӓ�0��|��xr� 0K��=
S�J�W͜J�4V�dx��q�3x�VB4�Qjz��޲5lժ��Z9�7�1��_�	�>�o��i�f��_���dt�փ򙋼�s3�q���Er�o����!@��;�Cꭄ!���n��ݓJ�b$#ݴ~���֝ɸ��,1��3�G�E[�mTn󨍭�L�_҂��h{��=�C����`c�k�I}�-��M����6f��#�Pt/�J��uhg�v�8�ǖ��H�_���Aߌｘ�{nzh���xo]�����1d�Qz�	Y�A�I��C��F�ӵ��5�2)R����5D��6}g���Kj���`�p�+jI&ӫ.6���,�A_���\Χ����?���9�[�;_���j>Ĩ�N����'7�Qi�{��G�* �6[���9���9�v�w�Â��j�*��),�f�����2dv��Y;�Fjk7���7�v��!��?C^�R�f��0����#�|~��3Ǭꏺ��6�N$�YF��cd�����̕>�Q!��i�жr땅�x* j�sp0��Z���&_�/���_��ET�A-Pa
w����Ň�ь�7� �R��⼾&A���5�W�2�Nc�#��)��4]D=�-�F!�z�������vS�%F���3���[�y�fn�f�4n���R=��.g4�MJ?@kj�tt�1���p�T�E�}���u�$1�z�Ja�������jJ�c�8��Ɵ*9���H�����-B���X�!"P�)�>ml[��דl���� ��8�O�<W���:��[���
(�\���OG�w�mmvڤ8+�	%�7V�4c� ��"I�jp,�.����O�w�=;o�̂��I����#."ċ�ђMI��ܚ� �Jꏽ;�:]N^�����`s'�6k���X��(�ԧ�R�Ϻb��c�CUG�ʖr��f̻�� �������\`�Y�-�=9^�n:�R��� '�P��B;�̈o��`��7:����~�/�*��t�P7���+A�a�=��U�ʷ+�K�>�n{"D�rKD����˺�Mh 	��)}�����@%Z�I�V&�b��#0���<ݢ'g�p�PԿ/'ep}
 ݎ!
,��hx���X���ن���Ko��`3��,
��z�K|v˾V�*�
QLAC|Q�k��*��N�Q��_&��3�L��7z�������!���^�M�2�,��ؤ���`Yz��������X8�$H��U/�m"�ٚ�d��g��E�:���.h�Ɛ�E����N� C�����_^�U	��)"�f��!P����o�!���٫�2 +�`a�$�h�FY$&S����̓��24��aj�mC���5Yټc%�9a���Y��`��2���G�_+I0-��^�h���Ĝm���8,��dt��'�s�LjH4�v�v�-1�t���+�<hݪ7'-�7-��D���v�T�1����)(p�����F���,
�TN/�݉X>0�����2;;XvI(X��hZ�p�����,���~�Ĥ�y������ r��E[Q��s�b8���S�C���#�I�oy����2O��OI&�R �RNH3� �h4&���X�:$V߁X8�t=yo�5����T�ͼ��!�x�T����M�J�x�����%~��
���t���;���N��dȞ��tYs�R�6���g���UGb���F��oY�z-��n�%S�V�k��?	"��_�L�� �Z�)�+�c��z��z}�6��E����pQE�݊ӥ���H۾�UOv:����i��b�������ҋ�vu@@��M�*p��B�ʒ ���K����߰N������rt(�K���A��!��YcN�H{��MZ[&�a�hL��i�A�sV|Fw���|�h��&�b�$��(��@�tE���u��{�!�RzV�t�P�'���I��i�PaϠ�|�!�Yx���B��yT`�������[2�F�k"
^} ���X�ց�DcW�`��3�Nk��To��!�X�����PjFqh��?%=� ��?.����-蠮@�>>��w��]�V�Bv� ���>�u���1���k����z�9#�uL���b�C/>�:AU���ԨNo��G�V44�DVK�5A���V���k�d�<>�  "            0x40000u
#define"SIM]SOPT2_UQBSRC_S�IFT                  (18
#define!SIE_SOPT2_SDHCSRC]MASK                   0x3 000000u
#`efioe SIM_SOPT2SDHCSRC_SHIFT            ! ( ` 20
#deFine0SIMSOPT2_SDHCSRC(x) `                  (((uint32_d)(((uint32[t)(x))<<SIM_SOPT2_SDHCSRC_sHIFT))&SIM_SOPT2_SDHCSRC_MASJ)
/: SOP�4 Bit Fields */
#defhne SIM_SOPT4_FTM0FLT0_MASK        �         0x1u
#denine SIM^SOPT4FTM0FLT0_SHIFT  ("             0
#define SIM_OP4_FTM0FLT1_MASK                  0x2u
#define SIM_SOPT4_FTM0FLT1_SHIFT                 1
#define SIM_SOPT4_FTM0FLT2_MASK                  0x4u
#define SIM_SOPT4_FTM0FLT2_SH	FT�   !        �   2#define SIM_SOPT4_FTM1FLT0_MASK             `    0x10u
#define SIM_S�PT4_FTL1FLT0_SHIFT                 4
#define SIM_SOPT4_FTM2FLT0_MASK       $          0x100u
#define SIM_SOPT4_FTM2FLT0_HIFT                 8
#define SIM_SOPT4_FTM1CH0SRC_MASK                0xC0002u
#define RIM_SOPT4_FTM0CH0SC_SHIFT    �          18
#define SIM_SOPT4FTM0CH0SRC(x)                  (()uin�32_t)(((eint32_t)(x))<<SIM�SOPT4_FTM1C0SRC_SHIFT))&SIM_SKPT4_DTM1CH0SC_MASK)
#defiNe SMM_SOPT4_FTM2CH0SRC_MASK           `    0x300001u
#defile SIM_So�T4_DTM2CH0SRC_SHIFT               20
#define �I]_SOPT4FTM2CH0SRC(x)        �         (((uint32_t)(((uint32_4)(x))<<SIO_SO@T4_FTM2C�0SRC_SHIFT))&SIM_SOPT4_FTM2CH0SRC_MASK)
#define SIM_SOPT4_FTM0CLKSEL_mASK          $     0x1000000u
#defile SIM_SOPT4_FTM0CLKSEL_�HIFT       !       24
#define SIM_SOPT4_FTM1CLJSEM_MASK                0x2000000u
#defile SIM_SOPT4_FTM1CLKSEL_SHIFT             $ 25
#define SIM_[OPT4_FT�2CLKSEL_MASK        "     !  x4000000u
#define SIM_SOPTt_FTM2CLKSEL_SHIDT        �      26
#defane SIM_SOPT4_DTM0TRG0QRCEASK   (          !0x10000000u
#define SIM_SOPTt_FTM0TRG0SRC_sHIFT              28
#defind SIM_SOPT4_FTM0TRG1SRC_MASK           (   0x60000000e
#define SIM_SOPt4_FTM0TSG1SRC_SHIFT              29
/* SOPT5 BiT Fields *?
#d�fine SIM_SOPT5_UART0TxSRC_IASK       �        0x3u
#define SIM_SOPT5_UART0TX[RC_SHIFT       �       0
#define SIM_SOPT5_URT0TXSRC(x)                 0(((uint32_t)(((uiot32Ot)(x))<|SIM_SOPT5_UART0TYSRC_SHIFT))&SKM_SOPT5_WART0TXSRK_MASK)
#define SI]_SOPT5^UART0RXSRC_MASK   $  ( "       0xCu
#define SIM_SOPT5_UART0BXSRC_SHIFT�              2
#define SIM_COPT5_UART0RXSPC(x)!0                (((uint32_t))()uint32_t)(x))<<SIM�SOPT5_UART0RXSRC_ShIFT))&SIM_SOPT5_UART1RPSRC_M�SK)
#define"SIM_SOPT5_UART1TXSRC_MASK   (         0 ,0x30u
#define SIM_SPT5_UART1TXSRC_SHIFT  �            4
#defane SIM_SOP5_UART1TXSRC(x)            !     (((uint32_t)(((uint22_t)(x))<,SIM_SOPT5�UAPT9TXSRC_SHIFT))&SIM]SOPT5_UAR�1TXSRCMQSK)
#define SIM_SOPT5_UART1RXSRCWMASK`      `   �   "0xC0u#define SI]_SOPT5_UART0RXSRC_SHIFT           !   6
#deFine SIM_SOPT5_UARTRXSRC(x)                  (((uint3:_t)(((uint32_t)(x))<<SIM_S_PT5_URT1RXQRC_SLIFT))&SIM_SOPT5WUAZT1RXSRC_ASK)
/* SOPT7 Bit Fields */
#define SIM_SOQT_ADC0TRGSEL_MASK                0xFu
#define SIM_SOPT7_ADC0TRGSEL_SHIFU               0#define SIM_SOPT7_ADC0TGSEL(x)   $    0         *((umnt32_t)(((u)nt32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIBT))&SIM_SOPT7_ADC0TRGWEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK 0           0z10u
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT 0          4
#define CIM_SOPT7_ADC0ALTTRGEN_MASK0(    � �     0x80u
#devine SIM_SMPT7_ADC0ALTTZGEO_SHIFT �  `      0 7
#define �IM_SOPT3_ADC1TRGSL_MAsK !           `  0xF00u
#define SIM_SOPT7_ADC1TRGSEL_SHIFT   "       `   8
#define SIM_SOPT7_ADC1TRGSEL)x)�                 (((uint32_t)((uinT32_t)(x))<<SIM_S_PT7_ADC1TRGSED_SHIFT))&SIM_SOPT7_ADC1\RGSEL_MASK)
#defmne SIM_SOPT7_ADC1PRETRGSEL_]ASK  (          0x1000u
#define SIMOSOPT�_ADC1PRETRGSEL_SHIFT            12
#define SIM_SOPT7_ADC1ALTTRGEN_MASK    (         0x8000u
#define S	M_SOpT7_ADC1ALTTRGEN_SHIFT             15
/:`SDI@ Bit F�elds */
#define(SIM_SDID_PAnID_MASK   "                  0xFu
#defmne SIM_SDID_PINID_SHIFT                     0*#define SIM_SD�D_PINI�(x)                        (((uint32_t)(((Uint32_t)(x))<<SIM_SDKD_PINID_SHIFT))&SIM_SDID_@INID_MASK)
#define$SYM_SFID_FAMIDMASK         !            0x70u
#define SI_S@ID_FAMID_SHIFT  "          `  �!  `4
#define SIM_SDI_FAMHD(�) !                "     (((uint;2_t)8((uinp32_t)(x))<<SIM_SDID_FAMID_SMIFT))&SIM_SDID^FAMID_MASK)
#defin� SIM_SDID_REVID_MASK       ` "      $     8xF00u
#define SIM[SDID_REVID_SHIFT    �   h     0 (    12
#define SIM_WEID_REVID(x)        $        0      (((uint32_|)8((uint2_t)(x))=<SIM_[DID_R�VID_SHIFT))&SIM_SDID_REVID^MASK)
/* SCGc9 Bit Fields */
#define SIM_SCGG1_UART4_MISK                  !  0x480u
#denine SIM_SCGC1_UART4�SHIFT      "             10
#define SIM_SCGC1_UART5_MASK            $   �   �0x800u
#dEfine SIM�SCGC1WUART5_SHIFT                    11
/* SKVC2 Bit Fields$*/*#define SIE_SCGC2_DAC4[MACK              `       0x100 u*#define SiM_SCGC3_DAC8_SHIFT0           $        12
#define SIM[SCGC2_DAC1_MASK                      �x2000u
#define SIM_SCGC2_DAC1_SHIFT     `            0  13
/* SCGC3 Bit Fields */#define SIM_SCEC3_FLEXCAN1_MCSK         !        0x10u
#define0SIM_SCGC3_FLEXCAN1_SHIFT     �           4
#defi�e SIM_SCGC3_SPI2_MASK                      0X1000u
#define SIM_SCGC3_SPI2_SHIFT0               0�!  12
#def�ne SIM_SCGC3_SDHC_MASK $            "       0x20000u
#define SIM_SCGC3_SDHC_SHIFT       0             17
#define SIM_SCGC3_FTE2_MASK         $`         ( 0x1000000u
#define SIM_SCGC3_FTM2_SHIFT               ` 4   24
#Define SIM_SCGC3_ADC1_MASk                      0x8000000u
#define SIM_SCGC3_ATC1_SHIFT      `           "  27
?* SCGC4 Bit Fields */
"def)ne SIM_SCGC<_EWM_MASK           `           0x2u
#define SIM_SCGc4_EWM_SHIF\ ,   $    0           1
#defAne SIM_SCGC<_BMT_MASK         �        !    0x4u
#dgfi�e SIM_SBGC4_CMT_SHIFT         !            2
#dEfine SIM_SCGA4_I2C0_MASK  �                   0x40u
#define SIM_SCGC4_I2Cp_SHIFT                     6
#deFine SIM_SCGC4_I2C1_MASK      8               0x80u
#degane SIM_SCGC4_I2�1_SHIFT                     7
#define SIM_SCGC4_UART0_MASK    0               !0y400u
#$efine RIM_SCGC4_UART0_SH�FT                   (10
#define SIM_SCGC4_UART1^MASK   `      0          0x800u
#Defina SIM_SCGC4_UART1_SHIFT                    11
#ddfine SIM_SCGB4_UART2_MAS                     0y1000u
#define SYM_sCGC4_UART2OSHMFT                    12#define SIM_S�GC4_UART3_MASK  $   0         !    0x000u
#define SI-_SCGC�_UART3_SHIFT         0          13
'define SYM_SCGC4_USBOTG_MACK `   0     �  0     0x40000u
#define SIM_SCGC4_USBOTG_SHIFT        �         `18
#define SIM_SCGC4_CMP_MASK     0`                0x80000u
#define SKM_SCCC4[CMP_SHIFT$    `     (    "     19
#define SMM_SCGC4_VREF_MASK                      0x100000u
#define SIM_SCCC4_VREF_SH�FT               !     �0
#dgfine CIM_SCEC4]NLWU_MASK                $     0x1000 000u
#defije S�M_SCGC4_LLWU_SHIFT                     28
/* SCGC4 Bit Faelds */
#defyne SIM_SCGC5_LPTIMER_MASK                   0x1u
#define Im_SCGC5_LPTIMER_SHIFT             !    0
#defhne SIM_SCGC5_TSI_MASK !"                    0x20u
#define WIM_[CGC5_TSISHIFT               0      5
#definc SIM_SCGC5_PORTA_MASK             `   (   8x200u
#define SIM_SCGC5_RORTA_SHIFT                    9
#defi�e SIMOSCGC5_PRTB_LASK           ! $  0    0x400u
#defi�e SIM_SCGC5_PORTB_SHIFT             !      10
#define SIM[SCGB5_PORTC_MCSK                 !   0x800u
#define SIM_SCGC5_PORTC[SHIFT  (               ` 11
'define SIM_SCGC5_PORTD_MASK                     0x1000u
#define SIM_SCGC5_PORTD�SHIFT                �   12
#define SIM_SCGC5_PORTE_MASK     �      0     "  0x20p0u
#define SIM_SAGW5_PORTe_XHIFT                    13
/* SGGC6 Bit Fields */
#defi.e SIM_SCFC6_FTFL_MASK                      0x1u
#define SHM_SCGC6_FUFL_SHIFT                     
#d%dine SIM]SCGC6_DMAMUX_MASK                    0x2u
#define SIM_ScGA6_�MAMUZ_SHIFT                   3
#define SIM_RCGC6_FLEXCAN0_MASk                 �0x10u
#define SIM_SCGC6_FLEXCAN0_SXIFT                 4
#define SIM_SCGC6_SPI0_MASK                      0x1000u
#define SIM_SCGC6_SPI0_SHIFT                     12
#define SIM_SCGC6_SPI1_MASK                      0x2000u
#define SIM_SCGC6_SPI1_SHIFT                     13
#define SIM_SCGC6_I2S_MASK                       0x8000u
#define SIM_SCGC6_I2S_SHIFT                      15
#define SIM_SCGC6_CRC_MASK                       0x40000u
#define SIM_SCGC6_CRC_SHIFT                      18
#define SIM_SCGC6_USBDCD_MASK                    0x200000u
#define SIM_SCGC6_USBDCD_SHIFT                   21
#define SIM_SCGC6_PDB_MASK                       0x400000u
#define SIM_SCGC6_PDB_SHIFT                      22
#define SIM_SCGC6_PIT_MASK                       0x800000u
#define SIM_SCGC6_PIT_SHIFT                      23
#define SIM_SCGC6_FTM0_MASK                      0x1000000u
#define SIM_SCGC6_FTM0_SHIFT                     24
#define SIM_SCGC6_FTM1_MASK                      0x2000000u
#define SIM_SCGC6_FTM1_SHIFT                     25
#define SIM_SCGC6_ADC0_MASK                      0x8000000u
#define SIM_SCGC6_ADC0_SHIFT                     27
#define SIM_SCGC6_RTC_MASK                       0x20000000u
#define SIM_SCGC6_RTC_SHIFT                      29
/* SCGC7 Bit Fields */
#define SIM_SCGC7_FLEXBUS_MASK                   0x1u
#define SIM_SCGC7_FLEXBUS_SHIFT                  0
#define SIM_SCGC7_DMA_MASK                       0x2u
#define SIM_SCGC7_DMA_SHIFT                      1
#define SIM_SCGC7_MPU_MASK                       0x4u
#define SIM_SCGC7_MPU_SHIFT                      2
/* CLKDIV1 Bit Fields */
#define SIM_CLKDIV1_OUTDIV4_MASK                 0xF0000u
#define SIM_CLKDIV1_OUTDIV4_SHIFT                16
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV3_MASK                 0xF00000u
#define SIM_CLKDIV1_OUTDIV3_SHIFT                20
#define SIM_CLKDIV1_OUTDIV3(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV3_SHIFT))&SIM_CLKDIV1_OUTDIV3_MASK)
#define SIM_CLKDIV1_OUTDIV2_MASK                 0xF000000u
#define SIM_CLKDIV1_OUTDIV2_SHIFT                24
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV2_SHIFT))&SIM_CLKDIV1_OUTDIV2_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 0xF0000000u
#define SIM_CLKDIV1_OUTDIV1_SHIFT                28
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK)
/* CLKDIV2 Bit Fields */
#define SIM_CLKDIV2_USBFRAC_MASK                 0x1u
#define SIM_CLKDIV2_USBFRAC_SHIFT                0
#define SIM_CLKDIV2_USBDIV_MASK                  0xEu
#define SIM_CLKDIV2_USBDIV_SHIFT                 1
#define SIM_CLKDIV2_USBDIV(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV2_USBDIV_SHIFT))&SIM_CLKDIV2_USBDIV_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_FLASHDIS_MASK                  0x1u
#define SIM_FCFG1_FLASHDIS_SHIFT                 0
#define SIM_FCFG1_FLASHDOZE_MASK                 0x2u
#define SIM_FCFG1_FLASHDOZE_SHIFT                1
#define SIM_FCFG1_DEPART_MASK                    0xF00u
#define SIM_FCFG1_DEPART_SHIFT                   8
#define SIM_FCFG1_DEPART(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_DEPART_SHIFT))&SIM_FCFG1_DEPART_MASK)
#define SIM_FCFG1_EESIZE_MASK                    0xF0000u
#define SIM_FCFG1_EESIZE_SHIFT                   16
#define SIM_FCFG1_EESIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_EESIZE_SHIFT))&SIM_FCFG1_EESIZE_MASK)
#define SIM_FCFG1_PFSIZE_MASK                    0xF000000u
#define SIM_FCFG1_PFSIZE_SHIFT                   24
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK)
#define SIM_FCFG1_NVMSIZE_MASK                   0xF0000000u
#define SIM_FCFG1_NVMSIZE_SHIFT                  28
#define SIM_FCFG1_NVMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_NVMSIZE_SHIFT))&SIM_FCFG1_NVMSIZE_MASK)
/* FCFG2 Bit Fields */
#define SIM_FCFG2_MAXADDR1_MASK                  0x7F0000u
#define SIM_FCFG2_MAXADDR1_SHIFT                 16
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK)
#define SIM_FCFG2_PFLSH_MASK                     0x800000u
#define SIM_FCFG2_PFLSH_SHIFT                    23
#define SIM_FCFG2_MAXADDR0_MASK                  0x7F000000u
#define SIM_FCFG2_MAXADDR0_SHIFT                 24
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK)
#define SIM_FCFG2_SWAPPFLSH_MASK                 0x80000000u
#define SIM_FCFG2_SWAPPFLSH_SHIFT                31
/* UIDH Bit Fields */
#define SIM_UIDH_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDH_UID_SHIFT                       0
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDH_UID_SHIFT))&SIM_UIDH_UID_MASK)
/* UIDMH Bit Fields */
#define SIM_UIDMH_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDMH_UID_SHIFT                      0
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK)
/* UIDML Bit Fields */
#define SIM_UIDML_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDML_UID_SHIFT                      0
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK)
/* UIDL Bit Fields */
#define SIM_UIDL_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDL_UID_SHIFT                       0
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK)

/**
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base pointer */
#define SIM_BASE_PTR                             ((SIM_MemMapPtr)0x40047000u)
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SOPT1                                SIM_SOPT1_REG(SIM_BASE_PTR)
#define SIM_SOPT1CFG                             SIM_SOPT1CFG_REG(SIM_BASE_PTR)
#define SIM_SOPT2                                SIM_SOPT2_REG(SIM_BASE_PTR)
#define SIM_SOPT4                                SIM_SOPT4_REG(SIM_BASE_PTR)
#define SIM_SOPT5                                SIM_SOPT5_REG(SIM_BASE_PTR)
#define SIM_SOPT7                                SIM_SOPT7_REG(SIM_BASE_PTR)
#define SIM_SDID                                 SIM_SDID_REG(SIM_BASE_PTR)
#define SIM_SCGC1                                SIM_SCGC1_REG(SIM_BASE_PTR)
#define SIM_SCGC2                                SIM_SCGC2_REG(SIM_BASE_PTR)
#define SIM_SCGC3                                SIM_SCGC3_REG(SIM_BASE_PTR)
#define SIM_SCGC4                                SIM_SCGC4_REG(SIM_BASE_PTR)
#define SIM_SCGC5                                SIM_SCGC5_REG(SIM_BASE_PTR)
#define SIM_SCGC6                                SIM_SCGC6_REG(SIM_BASE_PTR)
#define SIM_SCGC7                                SIM_SCGC7_REG(SIM_BASE_PTR)
#define SIM_CLKDIV1                              SIM_CLKDIV1_REG(SIM_BASE_PTR)
#define SIM_CLKDIV2                              SIM_CLKDIV2_REG(SIM_BASE_PTR)
#define SIM_FCFG1                                SIM_FCFG1_REG(SIM_BASE_PTR)
#define SIM_FCFG2                                SIM_FCFG2_REG(SIM_BASE_PTR)
#define SIM_UIDH                                 SIM_UIDH_REG(SIM_BASE_PTR)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM_BASE_PTR)
#define SIM_UIDML                                SIM_UIDML_REG(SIM_BASE_PTR)
#define SIM_UIDL                                 SIM_UIDL_REG(SIM_BASE_PTR)

/**
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- SMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Peripheral SMC
 * @{
 */

/** SMC - Peripheral register structure */
typedef struct SMC_MemMap {
  uint8_t PMPROT;                                  /**< Power Mode Protection register, offset: 0x0 */
  uint8_t PMCTRL;                                  /**< Power Mode Control register, offset: 0x1 */
  uint8_t VLLSCTRL;                                /**< VLLS Control register, offset: 0x2 */
  uint8_t PMSTAT;                                  /**< Power Mode Status register, offset: 0x3 */
} volatile *SMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register accessors */
#define SMC_PMPROT_REG(base)                     ((base)->PMPROT)
#define SMC_PMCTRL_REG(base)                     ((base)->PMCTRL)
#define SMC_VLLSCTRL_REG(base)                   ((base)->VLLSCTRL)
#define SMC_PMSTAT_REG(base)                     ((base)->PMSTAT)

/**
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLLS_MASK                    0x2u
#define SMC_PMPROT_AVLLS_SHIFT                   1
#define SMC_PMPROT_ALLS_MASK                     0x8u
#define SMC_PMPROT_ALLS_SHIFT                    3
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    0x8u
#define SMC_PMCTRL_STOPA_SHIFT                   3
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
#define SMC_PMCTRL_LPWUI_MASK                    0x80u
#define SMC_PMCTRL_LPWUI_SHIFT                   7
/* VLLSCTRL Bit Fields */
#define SMC_VLLSCTRL_VLLSM_MASK                  0x7u
#define SMC_VLLSCTRL_VLLSM_SHIFT                 0
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK)
#define SMC_VLLSCTRL_RAM2PO_MASK                 0x10u
#define SMC_VLLSCTRL_RAM2PO_SHIFT                4
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0x7Fu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/**
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base pointer */
#define SMC_BASE_PTR                             ((SMC_MemMapPtr)0x4007E000u)
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SMC_Register_Accessor_Macros SMC - Register accessor macros
 * @{
 */


/* SMC - Register instance definitions */
/* SMC */
#define SMC_PMPROT                               SMC_PMPROT_REG(SMC_BASE_PTR)
#define SMC_PMCTRL                               SMC_PMCTRL_REG(SMC_BASE_PTR)
#define SMC_VLLSCTRL                             SMC_VLLSCTRL_REG(SMC_BASE_PTR)
#define SMC_PMSTAT                               SMC_PMSTAT_REG(SMC_BASE_PTR)

/**
 * @}
 */ /* end of group SMC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SPI
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Peripheral SPI
 * @{
 */

/** SPI - Peripheral register structure */
typedef struct SPI_MemMap {
  uint32_t MCR;                                    /**< Module Configuration Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  uint32_t TCR;                                    /**< Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    uint32_t CTAR[2];                                /**< DSPI Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    uint32_t CTAR_SLAVE[1];                          /**< Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
  uint8_t RESERVED_1[24];
  uint32_t SR;                                     /**< DSPI Status Register, offset: 0x2C */
  uint32_t RSER;                                   /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    uint32_t PUSHR;                                  /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    uint32_t PUSHR_SLAVE;                            /**< PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  uint32_t POPR;                                   /**< POP RX FIFO Register, offset: 0x38 */
  uint32_t TXFR0;                                  /**< DSPI Transmit FIFO Registers, offset: 0x3C */
  uint32_t TXFR1;                                  /**< DSPI Transmit FIFO Registers, offset: 0x40 */
  uint32_t TXFR2;                                  /**< DSPI Transmit FIFO Registers, offset: 0x44 */
  uint32_t TXFR3;                                  /**< DSPI Transmit FIFO Registers, offset: 0x48 */
  uint8_t RESERVED_2[48];
  uint32_t RXFR0;                                  /**< DSPI Receive FIFO Registers, offset: 0x7C */
  uint32_t RXFR1;                                  /**< DSPI Receive FIFO Registers, offset: 0x80 */
  uint32_t RXFR2;                                  /**< DSPI Receive FIFO Registers, offset: 0x84 */
  uint32_t RXFR3;                                  /**< DSPI Receive FIFO Registers, offset: 0x88 */
} volatile *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register accessors */
#define SPI_MCR_REG(base)                        ((base)->MCR)
#define SPI_TCR_REG(base)                        ((base)->TCR)
#define SPI_CTAR_REG(base,index2)                ((base)->CTAR[index2])
#define SPI_CTAR_SLAVE_REG(base,index2)          ((base)->CTAR_SLAVE[index2])
#define SPI_SR_REG(base)                         ((base)->SR)
#define SPI_RSER_REG(base)                       ((base)->RSER)
#define SPI_PUSHR_REG(base)                      ((base)->PUSHR)
#define SPI_PUSHR_SLAVE_REG(base)                ((base)->PUSHR_SLAVE)
#define SPI_POPR_REG(base)                       ((base)->PgU��9{���|��o!4��\d��IJ�n�/0�j�N�;m���H�����!@V@���n���a�v�! �n�}h�	�88k�TO0����艞6���Ce�7À�a+�V>��(۸S�ؕd�r�p��Y�V��%�U6��zn>�r��>!Q��f��Q�1p��.�u�Ɂ��A���V[DXpO�$���Q���`eet��HH�?2$�:ێb˹b\�5����y�5Т����R��jN��H����@(Rz���`&;}26�^����J�I"����r&�� ¡8(�׳�M��|�.G��.#�<�q��⹂����H����?�d�f1k9��$���t0���F_u��u�u��}��8�ˢ��y���Ka�J܋7\]����uI&�b	�[yRL5�L��v���N���ŨR��C��_������+������w�2��|��f(�r���~�J�D(�ͩ�_9�Y��]�f~0ӊ ��F�+�9A� ,���3�:^���Vqg2M��]#/}D����Ҭ=�"&�t֒|0
��p;��zD2��2��5_Uf>7��*���@���Pkd�r2����>`icLK����(<���{�����hS7l��&ԄI��/g�����oڠ�ku�Vx�ۈ2��^51�K�e%�=�Y5��\���$	�wr<-p6�g7�]�s=m�\��?U�0��mͷ��-����G!,H���W(�~\D~�J��*������"q�j�[���d�I���4���p����SI �O�[T�Ύj��,�_/5睗)�ͯ3�����U-�k� e1�M{�l��/'5wI=�[0^o3�w�t�E��5�OE�[�pϣ�XR��Z�1��1���!�&H��=�=h��c�/Z�Ŋ����+Ku'�|([N�ɉ�(b��<�O�z�
N9o����7���ӌy4���o�%ڄ�L�1��Z̒X��>d����8w
%��N�MASK                     0x300u
#define SPI_MCR_SMPL_PT_SHIFT                    8
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_SMPL_PT_SHIFT))&SPI_MCR_SMPL_PT_MASK)
#define SPI_MCR_CLR_RXF_MASK                     0x400u
#define SPI_MCR_CLR_RXF_SHIFT                    10
#define SPI_MCR_CLR_TXF_MASK                     0x800u
#define SPI_MCR_CLR_TXF_SHIFT                    11
#define SPI_MCR_DIS_RXF_MASK                     0x1000u
#define SPI_MCR_DIS_RXF_SHIFT                    12
#define SPI_MCR_DIS_TXF_MASK                     0x2000u
#define SPI_MCR_DIS_TXF_SHIFT                    13
#define SPI_MCR_MDIS_MASK                        0x4000u
#define SPI_MCR_MDIS_SHIFT                       14
#define SPI_MCR_DOZE_MASK                        0x8000u
#define SPI_MCR_DOZE_SHIFT                       15
#define SPI_MCR_PCSIS_MASK                       0x1F0000u
#define SPI_MCR_PCSIS_SHIFT                      16
#define SPI_MCR_PCSIS(x)            G��ྕ�+����{�sN)��_���<�}��vykJ�n��%2x�*פ?K���&��Y4�����2�����a��4�BՁ<�p_Q��&��#�`��ok���(ϕ��F�Y��@1�H�5
s^t��Kg|��q7����g����5F ^[a�P��ˏ�$o�Z�_U��1��='��(�hHo%��Q�KWr�N]h��lz.�㤳ܔ�R�5]z���q���8����̷~����g(���%>� �C��˙�+kg�S/M�����>�\�rIC��xŎ��Yƌ�i�?"��K,��q̎J`�n���ۮU�b��$.�GG��_��瘁����1�B���Uⵢy���˱�z+�ϛ_�<�y�~�+t�`$�τ�٬8"�n���q�%3 �����%���3�m�oX<fh�̌�x��������*�Yg��F��c�AS୼�y��+��[q���6��m����T�x^5@����gI��M�[�k|Iv���Sn��@k8�t�����-��I�'�p��n�BKt���b��Ӑ�ڼhpaB]���J�
I.C��վ+h�����]pY���AɊ50�'��[��S7����#\5�n�pєơSf'���G-h�� a�%��<6�]ʢ�sb�aSZ����.\�Q
H=1�����m����a��ZyG�L \~,���{:)�[8cP�ԢdyL��_C�����C.G��p�pb�T(�Aws��qc��5iF����%��؀� ����#=fr��{�>�v^�%~�_�X'b���c�1y��j�7�>a����V�O��\>^φ)��<N��$��M��<V�C���>�j�R�9~�@��Jn���|hz�ɑ8�梼}��6�(@w�!h%��|X��/!I�>L)k�3��ah�j=�S� ����z���D����:�]�M��X� �������+��[]�=��	���O���|9!�`-U[!	8��A,�`+uA>8k�����A�q��2�BW�	2��v���1�\n��)]B)g���G�+Ί^+��l4R��Z/e�3|�,�Af�W���L�8֖�3[�[�E��H�mY^�q?�t烳�GR�,�L�fҗ���"C�����)4���]��pB��96(��6ï�hU;Z�z�ɝ+ `u�V�8L��h`��G����kG"y�o����A]��1�2o+Q����&��{��~O��1�(�]�Yctg��I
?���3+�v`ϓ������{\B$9I�_�)Ӆ�c.���}-MD.�dbë���6y�g��FCx��V4��w�l6}���3��S�G�y.�=���R�w�ڽL}�v��f�z�l���@)�]�&r�wO��W�4��JGh�Z�����l�$|nzS/�@�W� �xLu�],���럥��f»<���d�=h�W/[��߇J�l�0�w�6�l��0DP3��uY99n:�ǝ:�݄��S���N)��n86������\!"���LX�{p�Q���o�@n⚵�+����pxP�����}M?0�R� ϫ��c�M\'��Ά1*j`��I�z�^���G,<�/��	)�N���8���������$� ��^_��}�Iv��-����1��;-R���6
_����nCI�e尕2��L�\ϗ�#㼠�&J���ވY�+�E��Wg}��|ONQ���7��4w�ϡ�l��(��S���& u�~�$����=�Y���#�C�p�Pɒ�y����û��\�y0��U�&�X��g[��!��=�7)FC�2��sf��B*-	�� �Ƿ������q>��6�*}�������eg^I��	�ڸ�
Z�~�`L�bⱄ�l�x�ާ㒃�k{?����-P촃�л%rZ�Vc�������#��r�dU"�Xz����I�e"���TN�_@6%'C�ڜdVqPc���[ٿ��5̕C��B�/L�-`��EO(�*�O������!R��yw%�۸��<�0R��C����*��R)�\H3Xg4/b|J޶���N��_��	:x��&�P�8Ί5@�$0�������J�ڒS֔���L\w���=4D��L"���t��`<#i�3��>��4�GyȠ>�����mւ���s^��B�+�BҀJ�+�g�U�fS�"�P��#l~������[ޮ3K�}WE��������9��b6�֓��<s�5,;Bd:?���~��i���B�R	����X
L���CX��W3,,cK^�j
����wG�$7��<τ<�X���8�WA�BK��01�Ŧ(+V%xk��Wx�����?�s�å�W��-���*H��]�5�Rw��M��ZVE�O�ɺ*��v%��CwP��{�ۛ�����$������u�@='��)�7�m�	;\6�&"�J�qc��G��7��M㠃?k�nc������R)6.J�=a��/����_d$dxn��e��hҤ���y���T1,L�f�O�F�v�{�}���X������:� �2-sN��Ѹ��D������G��K+��b3E��9zN�� h�^���zx&6�$�1�e2�~�ݨ�1���'C�3��HhQ-Z�e�G�a���.��/�&����'E�l��T��^��Wc�~����O�cOY=�h+���	癅�T?��P2�39՟x�,����f���U<w%#�+�
�,|z�&>?Q:����u��\��r�-J�D��wew�ʔ�;�kJ>Z�b��m "��;Cf�5F�Ö��,�$2��>�y{Hs�-��ȕ`�yVVVF���a6Ot��`M��f4]i>E��͋��_��ƛ��V�����0f�x̳����j�4�y�gj�2`��U���,���ȑ[���%^o5I���D�lc6v�����Lk�5�a�tVt�~�ȌTjv�����Q��o`���kv_T��T��OO�|�7gB�숤���gr��u8����-��i�Ⓥfi��@�(���W�L��Q|trҾ�z�!_:�1iNރx/����c<T����ݘP�3��gU��9{���|��o!4��\d��IJ�n�/0�j�N�;m���H�����!@V@���n���a�v�! �n�}h�	�88k�TO0����艞6���Ce�7À�a+�V>��(۸S�ؕd�r�p��Y�V��%�U6��zn>�r��>!Q��f��Q�1p��.�u�Ɂ��A���V[DXpO�$���Q���`eet��HH�?2$�:ێb˹b\�5����y�5Т����R��jN��H����@(Rz���`&;}26�^����J�I"����r&�� ¡8(�׳�M��|�.G��.#�<�q��⹂����H����?�d�f1k9��$���t0���F_u��u�u��}��8�ˢ��y���Ka�J܋7\]����uI&�b	�[yRL5�L��v���N���ŨR��C��_������+������w�2��|��f(�r���~�J�D(�ͩ�_9�Y��]�f~0ӊ ��F�+�9A� ,���3�:^���Vqg2M��]#/}D����Ҭ=�"&�t֒|0
��p;��zD2��2��5_Uf>7��*���@���Pkd�r2����>`icLK����(<���{�����hS7l��&ԄI��/g�����oڠ�ku�Vx�ۈ2��^51�K�e%�=�Y5��\���$	�wr<-p6�g7�]�s=m�\��?U�0��mͷ��-����G!,H���W(�~\D~�J��*������"q�j�[���d�I���4���p����SI �O�[T�Ύj��,�_/5睗)�ͯ3�����U-�k� e1�M{�l��/'5wI=�[0^o3�w�t�E��5�OE�[�pϣ�XR��Z�1��1���!�&H��=�=h��c�/Z�Ŋ����+Ku'�|([N�ɉ�(b��<�O�z�
N9o����7���ӌy4���o�%ڄ�L�1��Z̒X��>d����8w
%��N���%)ƫ�������6��c��<�>�P[����-��>��#�J?k�F�'�;B��9Q8���FZ%ψn^�Δ�8`���������<���'�ҡr�я%����v���`(�ƍ�<��J�K$���bT#�ԯ]X,o�(�(����^l�-��:y�;i��-#�îվ}��Y9�__��T��9�>��*k�E�x��"��a���iTh��!��s��Ð�h;����Z�$υj+��+����`����ώ�"[�ݕ�e��\#[k�`�&����$l�N�۟�,-0b��)5s�*V�+|�`�-}�n����C텅�kqW?�z]��Js|8��2�iK�C:�z�J�12[T5n�v�/*�f�@��cj^��K�q�G�5^^'Pw&� �\`S!=}aC�u��t���I��"��XÞ�v��ƾ��v�R��N����
��uo:ݜ�*/���I�U�'��,����vqBhSU&��?$|g.?9{b�%���J׈	�t=5�б����ч;�ԟH �^�8�-�/UP�������{���4o��O]>��� �@�o��k��ٿ$���{��>�^��M��t�Ip}�-eLW�����I<p����܆�/l�uZ�F�dv�EW�:���g7�ą�����	0��\P�6�X��������H�g���S��T��LW3��ʣu��"���*�ZV��l?C�@v �֬��m�L0-"++�Gs1հ��0�E��]V��#�J=�li�[��k��!��#3�]St@J�?e�ső��]�ӠL�!8�*�x#�8�&�������
&(�tr���n���>Gr���!z
K�/+N]�8�� 81���Q�-D��p��S�����^�A&�҆��X��nxʃ�W�Ӫ{NI��&%����%�!�ى|�R���\��S\L��e�2H�30�L�ش��#� �3����S���3���@�d-��N�ǁ�p|�g�Vi�}��H����TmO�|N��_�J��CZ������X��ZίaΘ`��rWt�k#�xͽG���C�v����8��,0��X	-�"��i��qL;T*cֿ%Z��ǉl�vV���E�6"�b�Ɵ4��ӥ��ZYZ֭���Ts�$��.7=^��v0��|"z(1�@�>t�-��
�h���GP���
�=/y��b��;�qa`Թq�t/�-�L�����ps,@�@��2o�^'�uB1�CO��W4�f/��F��ÛԵ-�9�3���Y�ɳ��i��s0p--uW���F�kxc/�)T�y��c��{�DE��QĻ*��C��իdbHp�U	J�N�K���*�7�0K�]"C�"�8�0Ǝ�{eJ�
�m�l(�ةxh��a���IZW0�4���EO ��P��6���!�;�-q���n�	�=�Ww�!�|��'a^v���X�Pe	�	�0;�"T�X�d2��j�x�L���䀑㋧l"�%e�\\�GG���,���L&����O��ƍ�~�Q��D����l�g,7Z72�L�T�'iɓ����y^~��[B�H3 ��ʸ`Ki������ܜ�"�):R�;���U��3��)L ��Vڑ �T������:�h7ܻ=��3?���C�S���>z�U��g��������H�p������=r���Ykxsd��!��-���e龑����`�g�G����+Q�	u6G
��l��&i��x�
s To'[K@����K|�6N������>U�=��/#7w���D��~hr�g<A1,���VI��\k������&�Sl�U���,�*?�;�PKK����ky�hT���׺��b�&棖?��|��kn�ck=�Y��.:
`�&���9b?�p�أ(��9�?y�X2�+F�w%±��'�4g�S�Y�ezH܈Q�ۿ +��h����ݧ��#SPs���Xϥ�l?s'��S�sv �����c���t~;0$�<"ziF'q���>M�R�(.�Q]��&���p6:cRS_MASK                  0x10000u
#define SPI_RSER_RFDF_DIRS_SHKFT         !       16
#define SPI_RSER_RFDF_Rm_MASK                    0x20�00u
#define SPI_RSER_RFDF_RE_SHIFT   (               17
#define SPI_RSER_ZFKF_RE_MASK      $       �    `0x80001u
#define SPI_RSMR_RFOF_RSHIFT         0        "18
#define SPI_RSER[TFFF_DIRC_MASK                  0x1000000u
#define SPI_RSER_TFFF_DIRS_SHIFT                 24
#defife SPI_RSEP_TFFFSE_MASK        � !         0x2000000u
#define SPI_RSER_TFFF_RE_SH�FT       (        !  25
#define SPI_RSER_TFUF_RE_MASK    0          `    0x8000000U
#define SPI_SSER_TFUF_RE_SHIFT         !         27
#define!SPI_SSER_EOQF_RE_LASK                  ` 0x10000000u
#deFine SPA_RSER_EOQF_RE_WHIFT            0      r8
#define SPI_VSER_TCF_RGWMASK                     0h80000000t
#define RPI_RSER_TCF_RE_SHIBT $                  31
/* PUSHR Bit Fields */
#define SPI_PUSHR_TXDATA_MASK                 (  0xFFFFu
#define SPI_PUSHR[\XDATA_[HIFT      (            p
#define CPI_PUCHV_TYDA\A(x)          (        $  (((tint32_t)(((uynt32_t)(x))><SPI_PUSHR_TXDATA_S@IFT))&S�I_PUSHS_TXDATA_MASK)J#defin% SPI_XUSHR_PCS_MASK                       0x3F000u
#define(SPI_PUSHR_PCS_SHIFT                      16
#define SPI_PUSHR_PCS(x) "                       (((uint32_t)(((uint32_t)(x!)<<SPI_PUSHR_PCS_SHIFT))&SPI_PUSHR_PCS_MASK)
#dedine SPI_PUSHR_CTCNT_OAS�                !    0x4000000u
"define SPI_PUSHR_CTCNT_SHIFT                    26
#defhne SPI_PUSHR_EOQ_MASK � 0                   0x8000�00u
#define SPI_PUSHR_EOq_SHIFT                      27
#define SPI_PUSHR_CTAS_MASK                (     0x70000200u
#defing SPI_PUSHR_CTAS_GHIFT                     28
#define SPH_PUSIR_CTAS(x)                   (    (((uint32Ot)(((uint2_t)(x))<<SPA_PUSHR^CTAS_SHAFT))&SPI_PURHR_CTAS_MASK)
#define SPI_PUSHR_COJT_MASK    !  *              0x80000000u
!define S@I_PUSHR_CONT_SHIFT                     31
/n PUSHROSLAVE Bit Fields */
#define SPI_PUSHR^SLAVE_TXDATA_MAS�              0xFFFFu
#define SPI_PUCHR_[LA�E_TXDATA_SHIFT             0
#defhne SPI^PU[HR_SLAVE_TXDA\A(x) �              (((uint32_t)(((uint32_t)*x))<<SPI_PUSHRSLAVE_TXDATA}SHIFT))&SPI_PUSHR_SLAVE_TXDATA_IASK);* P_PR Biu Fields */
#define SPI_POPR_RXDATA_MASK          �         1xFFFFFFFFu
#define SPIWPOPR_RXDATA_SHIFT     �     "        0
#define SPI_POPR_RXDAtA(x)             (         (((uint32_t)(((uint32_t)(x))<<SPI_POPR_RXDATA_SHIFT))&SPI_POPR_RXDAUA_MASK)
/+ TXFR0 Bit Fields */
#define SPI_TXFR0_TXDATA_MASK                  ! 0xFFFFu
#defyne SPI_THFB0_TXDATA_SHIFT                   0M
#defife SPI_TXFR0_TxDATA(x)                      (((uint32_t)(((uint32_t)(z))<<SPK_TXFR0_TXDaTA_SHIFD))&SPI_TXFR0_TXDATA_MASK)
#defmne SP�_TXFR0_TXCMD_TXDA\A_MASK              0xFFFF0000u
#def)ne SPI_TXFR0_TXCMD_TXDAPA_SHIFT         !   16
#lefine SPI_TXFR0OTXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<SPI_TXFR0_TXCM@_TXDATA_SHAFT))&SPI_TXFR0_TXCED_TXDATA_M�SK)
/* TXFR1 Bit Fields */
#deFine SPI_TXFR1_TXDAT�_MARK      $             0xFFFFu
#dEfine SPI_TXFR1_TXDATA_SHIFT                   0
#define SPI_TXFR1_TXDATA(x)                      (((uint32_t)(((uint32_t!(x9)<<SPI_TXFR_TXDATA_SHIFT))&SPI_TXFR1_TXDATA_MSK9
+defIne�SPI_TXFR1_TXCMD_TXDATA_MASK               xFFFF0000u
#define SPI_TXFR1^TXcMD_TXDATA_SHYFT   0         16
#define SPI_TXFR1_TXCMD_TXDATA(x)                (((uint30_t),((uint32_t),x))<<SPI_TXFR1_TXCMD_TXDATA_SHIGT))&SPI_TXFS1_TXCMD_TXATA_MASK)
/* TXFS2 Bit Fields */
#�efine SPI_TXFR2_TXDATA_MASK                    0xFFFFu
#define`SPI_TXFR2_TXDATA_SHIFT                   0
#defmne SPI_TXFR2_VXDATA(x)         $       !    (((uint32_t)((uint32_t)(x))<<SPI_TXFr2_TXDATA_SHIFT()&SPI_TXFR2_TXDATA_MASK)
#define SPI�TXFR2_THCMD_TXDATA_MASK              8xFFFF0000u
#define SPI_PXFR2_TXCMD_DXDATA_SHIFT  "      `   1>
#ddfine SPI_TXFR2_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))4=SPI_TXFR2_TXCMD_TXD�TA_SHIFT))&SPH_TXFR2_TXCMD_TXDATA_�ASK)
/* TX�R3 Bit Fields`*/
#define SPI_TXFR3_TXDATA_MASK              0 (   0xFFFFu
#define SPI_TXFR3_THDATA_SXIFT          *        0
#define s�I_TXR3_TX\ATA(�)       (              (((uint32_t)(((uint32_t	(x))<<SPI_TXFR3_TXARA_SHHFT))&SPI_TXFR�_TXDATA_MASK)
#define RPI_TXFR3_TXCMD_TYDATA_MASK             "0xFFFF0000u
#def)nm CPI_TXFR3_TXCMD_TXDATA_SHIFT  (        � 16
#define SPI_TXFR3_TXCMD_TPDATA(x)      "   $     (((uint32_t)(((uint32_t)(x))<<SPI_T\FR3_TXCMD_TXDATA_SHIFT))6SPI_TXFR3_TXCMD_TXDATA_M@SK)
/* RXFR0 Bit Fields *?
#define SPI_RXFR0_RXDATA_MASK                    0xFFFFNFFFu
#define SPI_RXFR0_RXDATE_SHIFT                   0
#define SPI_RXFR0_RXDAT(x)         �    �       (((uift32_t)(((uint32_t)(x))<<SPI_ZXfR0_RXDA�A_SHIFT))&SPI_RYFR0_RXDATA_MASK)
/* RXFR1 B)t Fi�lds �/
#D-nine SPI_RXDR1ORXDAA_MASK      0             0xFFFFFFFFu
#defin% SPI_RXFR1_RXDATA_SHIFT                   0
#eefine SPI_RXFR1_RXDAT(x)    (       (         (((uint32_t+(((uint32_t)(x))<<RPI_RXFR1_RXDATA_SJIFT))6SPI_RXNR1�RXDATA_MASK)
/* RXFS2 Bit Fields */
#define SPI_RXFR2_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR2_RXDATA_SHIFT                   0
#define SPI_RXFR2_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR2_RXDATA_SHIFT))&SPI_RXFR2_RXDATA_MASK)
/* RXFR3 Bit Fields */
#define SPI_RXFR3_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR3_RXDATA_SHIFT                   0
#define SPI_RXFR3_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR3_RXDATA_SHIFT))&SPI_RXFR3_RXDATA_MASK)

/**
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base pointer */
#define SPI0_BASE_PTR                            ((SPI_MemMapPtr)0x4002C000u)
/** Peripheral SPI1 base pointer */
#define SPI1_BASE_PTR                            ((SPI_MemMapPtr)0x4002D000u)
/** Peripheral SPI2 base pointer */
#define SPI2_BASE_PTR                            ((SPI_MemMapPtr)0x400AC000u)
/** Array initializer of SPI peripheral base pointers */
#define QPI_BASE_PTRS          �                 { SPI0_BASE_PTR, SPI1_BASE_PTR, SPI2_BASE_PTR }�
/* ---------�--�-----------=---------------m----------,------------------------
   - SPA - Register qccessor macros
   --,----------=------------------,----------,------------------------------- */

/
*
 * @Addtogrout SPI_Register_Accessor_Macro{ SPI - Regisueb accessor macros
 *!@{
 */


/* SPI - Registe2 instAnce definitions 
/
/* SPI0 */
#define SPI0_MCR                        "        SPI_MCR_REG(SPI0_BASE_PTR)
#define SPY0_TCR!                                SPI_TCR_REG(SPI0_BASE_PTP)
#fefine SPI0_CTAR0                               �PI_CTAR_REG(SPI_BASE_PTR,0)
#define SPI0_CTAR0_SLAVE                        "SPI_�TAR_SLAVE_REG(SPI0_BASE_PTR,�)
#define �PI0�CTAS1                          ` `  SPI_CTAR_REU(SPI0_BASE_PTR,1)M
#define SPI0_SR        �                       ! SRI_SR_REG(SPI0_BASE_PTR)
#define�SPY0_RSER     (0                         SPI_RSeR_REG(SPI0�BASE_PTR)
#define SPI0_PUSHR                               SPI_PUSHR_REG(SPI0_BASE_PTR)
#define SPI0_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI0_BASE_PTR)
#define SPI0_POPR                                SPI_POPR_REG(SPI0_BASE_PTR)
#define SPI0_TXFR0                               SPI_TXFR0_REG(SPI0_BASE_PTR)
#define SPI0_TXFR1                               SPI_TXFR1_REG(SPI0_BASE_PTR)
#define SPI0_TXFR2                               SPI_TXFR2_REG(SPI0_BASE_PTR)
#define SPI0_TXFR3                               SPI_TXFR3_REG(SPI0_BASE_PTR)
#define SPI0_RXFR0                               SPI_RXFR0_REG(SPI0_BASE_PTR)
#define SPI0_RXFR1                               SPI_RXFR1_REG(SPI0_BASE_PTR)
#define SPI0_RXFR2                               SPI_RXFR2_REG(SPI0_BASE_PTR)
#define SPI0_RXFR3                               SPI_RXFR3_REG(SPI0_BASE_PTR)
/* SPI1 */
#define SPI1_MCR                                 SPI_MCR_REG(SPI1_BASE_PTR)
#define SPI1_TCR                                 SPI_TCR_REG(SPI1_BASE_PTR)
#define SPI1_CTAR0                               SPI_CTAR_REG(SPI1_BASE_PTR,0)
#define SPI1_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI1_BASE_PTR,0)
#define SPI1_CTAR1                               SPI_CTAR_REG(SPI1_BASE_PTR,1)
#define SPI1_SR                                  SPI_SR_REG(SPI1_BASE_PTR)
#define SPI1_RSER                                SPI_RSER_REG(SPI1_BASE_PTR)
#define SPI1_PUSHR                               SPI_PUSHR_REG(SPI1_BASE_PTR)
#define SPI1_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI1_BASE_PTR)
#define SPI1_POPR                                SPI_POPR_REG(SPI1_BASE_PTR)
#define SPI1_TXFR0                               SPI_TXFR0_REG(SPI1_BASE_PTR)
#define SPI1_TXFR1                               SPI_TXFR1_REG(SPI1_BASE_PTR)
#define SPI1_TXFR2                               SPI_TXFR2_REG(SPI1_BASE_PTR)
#define SPI1_TXFR3                               SPI_TXFR3_REG(SPI1_BASE_PTR)
#define SPI1_RXFR0                               SPI_R�.���g�T!���V;+�J:�/����d�c���XO�[���\Ac��;|Ɇ���s��]�Y�5y
�v����j�$~��T��>��
J�BmzŹ�� ��e��$�m��΂ap��O��� �bK��4���1F���)���x�k򙨑�@bov����]MY6g3_���k�����	���a����x�8��KKp�{v�s@����	�a;��P�f%�3���F�P�3����ZOu�A�R-��y?u[Lē;M�J�c7�g�|Y�P� N���4駱s�w|� I!(��51��L��cC�"�R�5�>�Q 5G{K�{��w�r� [$��N����I�_���#���ْHs �b�}��m{Č^ѻ�� Б�5m�eC�����4LL"��p&鮾+��4@�:�S���T�'r�:��B���M7/�e�zMc¦�YO3IK�{u�&N� u�2�Չ	�@3���IxA.[����	b����Tqr�C�+0r�N�t�ޜ2�LJ&�	СmM�H��-�)Kf�$�h�q������|/�/d،���_�P�QHf"����!���1�¿vS@�G&���s*֓g*�Su�/+P��س���K!#��j�
�O�櫿\!��=�/��K=���Q��\�7)"m7n{vi��w�uA�h���6��
rȦ[d�N9�i4��p��T��WNk�����?�ܐf�%i����-�`Dbm`|Y�B���*�5�����>T�h�*��Ro��ߤM�-X/�<n���\�����
Y�C��P��G+A r�6pp�̀D#�����%x �x�:�x��N��1��*i51�H˛T��6��8�%o���1��\էcE�(�n�j��H�n��'P��~Ԙ�}�o����!����: ��Z�﮳��EC�	�;@�D	C{<p���HZI7�4P=�M]�g��w�F�7s�F���Ս��Ў��VWq?����*D��bY��cwNl�
�a�HR��C�;	e��v�&!��܀[�1��V��cG���FÆ��~�r,���W������zN���eO����j*�xF0��د�Z�s'm �c���Q��4�}05�Y�z��_� ��K>� h:���u���J{2E�f����n�0ݬ��ݐy�3�.�[���I�R0Z�sZ�����&9t�[���z�^�_���Li�}��(S���XئzyW�F ��$5��G{F�U���;hL�ȜJo��^�V-Y�7�_����V%[6�[�	�~�E&E�pP���*Z3�B�f;&�;��)���oΧ��/��K��W��^У���f��S�ğcT�'�\�7�{�ILcu(��۬�����>H��Z�X8'�Z�Cd�
9��c�5���f�］`X�u�L��ٴ�:�}�_a��1_��9�mE�*�UA��`�V��*�PQ4���(x+���ο�2�[W:�e�VN�W����}_�#[�W!�:�Nw4Vtps�������Q�Po����a�rE�s6���S��r�'����x�?y�����-�12��H���6�D�H/l���Ы�?��@��Y�	��O\�g��a�#�R/!��,Ϻ#�3t8"�;A���	��ʫtJ��V|����=��|�K��_
٧�5���Ir�o�+	� �m���m�G|u�TE��hڍ٠�oއa�w�c����7����_�V�A��H��^�G��lу�]�GK}jE�6�.6��ۻ"�N��߹ʎQ3���Mǫgi�·��6�߉��TJ�+�b�O���ƀ)��Z�e`ܽ���e
�����&K�D�8vҭ\r!m�Aw��$�=�	�9�.�E���	L@�;�%�֓Cϥ6ފ^���G�����}$���^� B���[��%a���&Dv��"�{C�\��Iv�t���Y	AD��I�
�厚�G~�Mux��U(��[��,)�(��qz�����55��fk�d�/@������ �[��9<~�S�CvS�x�>vi�	U�[>x�qxJB˯m�l�TB����7"�L�^>�)�U���+���e���	<2��	G��:�#
_�kZ!g�{{CN��O��g�eu�B�E�·Vw��^��8����]�o����bI՚����Z�M�0M�������]-U����])�~�+GՐ���l�&|�+�7� =+?5�����,�� �Yꇉ4�u�x`�&o�3wK!��!T�ͣVص�R�K������/4��d\J�̷����%{e�$0�C ��|b���m�yEOl�.,yGMx��M�L
��^XC�;��QA8��Yx�՟�K��"��t�	�U5����f1���LF�>q�+��(_�:�?,��W��*:��u+ϰ���%
�#ۥ���!�{9����\��s��o��zǂ������7.%aU^{f��E ������j�����X��ȼ�'�����Tb��ޯ�b��dK`D!s\ A�9�6dx'[fV6X�|R}d��'T��WP���B� �Y����i�pV
>���j��RP�e^f�b�LS"� �f�9��X�f��)�SCuH|x�|Ց�£��u6��G�꿝��h�X�Sr�1
ѱ�D9׍�S�Gm��䄴��i0�����u}ύ����xX��A,O��N��k���;�z�7�c�	 �=�b����)k]��dweف� ���c�x�AT�܇��?jK{�5S�ͪ�\T.��ETN��IW-��g/M�`k��T��޾��'6.{�3q+�"��S�T��gu��I.nX��C�G�����B����6x?8�ݖd�;�Qi�hk��]<�e`z%�YE��C����L;T��k�,�=���xH\E�� W
�+p����Ky_���p 	����sޠr�#�_�����J^[w��E�!�?��qI��u���ƴR���^��k���}���g<,KV�+M>�%`}$��<��U`�{�{�4NԺ��'��� 1���7���|�6G�����c��r��K_{�y�JB�q}��������e|���k���v���߇X���m�V��CPퟞ��n���I�G'G/�����v��as�����_��
fs�`@�����vX����L�p�c�)�	�`��t)ƿ�b�9�=v&B����v�Q&Q�c��LtL~y�6/��[�p�o��y�\Rj79�}�w�q*��,j_q��$2�M)J\��;�AK�t��ԫ�p��A����������]�� {r4vm��؏iriX���+�D�ܪ$��iq�;�y��^�}%^�e&��Gd�'+&�����=Q�$#ǽ���P{<W �p#�^�8P4PaqQ��1�$A�~/����.�k٫��{�.[.Jͺ��(#;�`!��5D0|K��4��]��(kd��l��K�hN��Gz���r�<t���ݟ	��0�Ȍ��Q�+x��qǟ0��K��N�Q�����w5�q�/�B�L����M����X�j�Z���.�n{̡C�(4�"���}�}T�|�]�8tj��Rf3�1�
n)��U�J��!�>�����ٲ<X�)Դ�
v����{��$GG<��7��[uK��d��0�M^�ϋ�v<�@�5��H�Ս0��c-�����1���ƒ�*
e>������ ��gT�?��϶�αp�rO�4W�++�<�:(h�L�of?.�ݣ����}�N����
�O�;�u�c�@��ҿ����TC|M���#�d,y��y���KռA5��e���ʜ��2�!m�x�Ń=�SqV���Z-LR��ՐO�@:�VC�e	{�]�I�:�U�Ή��-���$�&pP;@��;3��}��U��͞�޶�����@ q���֘��z{(�/�6�p��u�e�p�po�]��l��rs���p��˓JoE�|"����'��O��}(���˖7&���Ŗ��È�J^�7%�%8r���{��)h�c�����.���g�T!���V;+�J:�/����d�c���XO�[���\Ac��;|Ɇ���s��]�Y�5y
�v����j�$~��T��>��
J�BmzŹ�� ��e��$�m��΂ap��O��� �bK��4���1F���)���x�k򙨑�@bov����]MY6g3_���k�����	���a����x�8��KKp�{v�s@����	�a;��P�f%�3���F�P�3����ZOu�A�R-��y?u[Lē;M�J�c7�g�|Y�P� N���4駱s�w|� I!(��51��L��cC�"�R�5�>�Q 5G{K�{��w�r� [$��N����I�_���#���ْHs �b�}��m{Č^ѻ�� Б�5m�eC�����4LL"��p&鮾+��4@�:�S���T�'r�:��B���M7/�e�zMc¦�YO3IK�{u�&N� u�2�Չ	�@3���IxA.[����	b����Tqr�C�+0r�N�t�ޜ2�LJ&�	СmM�H��-�)Kf�$�h�q������|/�/d،���_�P�QHf"����!���1�¿vS@�G&���s*֓g*�Su�/+P��س���K!#��j�
�O�櫿\!��=�/��K=���Q��\�7)"m7n{vi��w�uA�h���6��
rȦ[d�N9�i4��p��T��WNk�����?�ܐf�%i����-�`Dbm`|Y�B���*�5�����>T�h�*��Ro��ߤM�-X/�<n���\�����
Y�C��P��G+A r�6pp�̀D#�����%x �x�:�x��N��1��*i51�H˛T��6��8�%o���1��\էcE�(�n�j��H�n��'P��~Ԙ�}�o����!����: ��Z�﮳��EC�	�;@�D	C{<p���HZI7�4P=�M]�g��w�F�7s�F���Ս��Ў��VWq?����*b�|\O�?�ꮏU�8�~�	�r��}p)��Q�D���8��y���s^�g4��h�g^���_���=At��:c
Vp�r$�|�u�!�w���g��.VyD5�ti[��?�l�e��}O��$7�lM��Ї�h�)`�'�p�0�K c�>Ӎw�?ڮ��Z#h�EjI��T���i�k�)-��6�5p^�Y�dLꂁ'����D2��)P����$T��^~׮!��F,��01{��vW�NÚ�]�
3��^?�O]=D�w�}�8f�?P��q[��b�w¬Z41umO3�嬠�ߢű�A>&P��ć1�g��$��SI�(�tL�䛗�֙��;��;���+�FLzV����Ѐ��ʟ��x,��!L �H9�3h�v���$['����UsY�$yx�˛2ӻ*g�j���]{8O��I U���ٌF�e�s:P��..&�M�g�#�!jR 3�*���o�MA����%���0Y�"��lo��)VeP�Oe�3cY���A$730��T��ߧ���-A;�{F�w��̦�T����
�(��%�ΏG�Q5�+b"��>����U�TKVj#'�B�nM�Y�p�z��7�
�V�b��|�#���ډ��;���N�f��~~�8�`��d>I68b���2�� ����5�}�+�>�G ������S�DR㹺a-������m�<溶���/�*�������WK�%�V˱�o�!s�b�R	��Re-i��Ǘ%ލF�;(-�U U��R�m�{g*A�Op�����J��V�2�Ks��խ�\B�*�G�(�Ob���T�KJ���L�9�^i�PB
���~�����zm%\�.P�C��#���H��5)�('�o1m{\D�H05r�7k}-��c�e�ʋ�y��4݃B���B�MzE�a��B�v�"��;��P�L���HY���87f�ݹ��*�&�/R�����xM�h��!#���)��Nq
x��Ů����*{͏Pٿ����dj�������`��8����N�t)��Ŝc�Ѝ�m5����"��N��7d�5������%Ip�+S��������yf�.z������H�D3�M�)*�<g�xK�/�����A\�Z(#���wRw����߰�w9a�1��&>X}ɲH��ۧ �o�
g�;\hWl|�=�f5Q��k,���&��)1E,}�"q*���-bX�C5�dT
\��#m����&��1tT��`��ܺ�8�OIձ*C$O�-O��xK��A&�j�a�%g��\���X=�K�x��r�X��8��\��R�b��N]J!���P{H��᮸[ǔ�,c����!�<�~�"���	�����t$��\�,n�(��R�j�|ə��t���֨8����m'�V3t��SJ����}MV�&^����Ի��)4q�i����;���s�_{��p�(c
D-p���]���{]�DU�䠠�v�t��ޜx��;�����\lX�&j�?r�M{필T�I:5��`���Nc�M����V@��{`�n^�5ۨ�%������Nr;��4�?��ܞ\�E��/χ	��~��-�+�"x������mU���*�a
����X��&���UG�yhT��.<t�b#=�\G���MWVhV�ʕ�^6�� �qC�ٹ0�w���x�!>�[�H��ڄ7ѯ�.��x�P?<.��I�� j�J��9:CV���s=�����;�Iv!�#��(Y���$����r;��C�[���<�Z2���t,�E�So���T�ږ�Q�=線K�X#���f���<���I�-��L�� �}���95��\����	��_/�/|�(��,2���V��=Ts�F�]/0���o�q��j�T�LǛ4C��(|���o��74��(��9&��j��]�m�
�S���#̔��p#�Ȥ�+�<T���;�Gg{j3Em��cq�?����t�*��$Ҹ�禌xv0���1���5�?~�.7��32_t SSPSR;     0 �                   (      /**< Supported Paballel Port Size Registe3, offset: 0x0 */
  uint32_t CSPSR;              �                �  /**< Curreft Parallel�Port Size Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  uint32_t ACPZ;                                   /**8 Asynghronous Clock Pre3caler Register, offset: 0x10 *?
  uint8_t RESERVED_1[200];*$ uint32]t SPPR;                                   /**< SelEcted Pin Trotocol ReGister, offset: 0xF0 "/
  uint8_t RDSERVED_2[524];
  uint3�_t FFSR;                               ` ` /**< Formatter and Flush Status Register, offset:$0x300 */
  uint32_t FFCR;                      `        �   /**< �oreatter and Flush Control Register, offset: 0xs04 */
  uint32_t FSCR;    (        `          `  �       /*+< Formatter(SynchrOnization Co7nter Register, offse|:!0x308 */
" uin\8_t RESERVED_3[3036];
  uinu#2_t`TRIGER;          $                    �/**< Trmgger Register, offset8 0xEE8 *�
  uint32_t FIFODATA0;         �      $     !  !    /**4 FIFODATA0 Register, offset: �xDEC */	
  uint32_t ITATBCTR2;                              �**< Integration Test ATB Coltvol 2 Register, offset: 0xeF0 */
  uij�8Ot RESERVED_4[4];
 (uint32_t ITQTBCTR0;                ,   !         /**< Intmgration Test ATB Control 0 Recistev, ofnset: 0xEF8 */
 "uint32_t FIFODATA1;                           0  /**< fIFODETA5 egIster, offset: 0xEFC */
  uint32_t ITCTRD;       0  "   �0         �      �/**< Integrathon Mnde Control Register, offset: 0xF00 */
` uint8_t RESERVED_5[176];
  uint32_t CLAIMSMT;            0                  /*"< Cl`im Dag S%t register, offset:�0xFA0 */
  uint32_t CLAIMCLR;                          $    /**< Clail Tag Clear Register, offset: 0xFA4 */  uint8_t RESERVED_6[32];
  uint32_t DEVID;       0                "         /**< TPIU_DEVXD Begist�r, offset:$0xFC */
  u�nt0_t RESERVED_7[4];
` uint32_t PiD4;   " �      (         `            /**< Peripheral Ieentification Rueister 4., offset: 0xFD0 */
  uint32[t PID5;                                  /**<�Peripheral Idenuification Regisde� 5>, offset: 0xFD4 */
  uint32_t PID6;    0       0!                     /j*< Peripheral Identificqtion Regist�r 6., mffset: 0xFD8 */
  uint32_t PID7;           !                       /**< Periphe�al Identif�catiOn Zegister 7., offset: 0xFDC */
  uint32_t PID0;                         `         /**<`Peripheral Identification Register 0., offset: 0xFE0 */  uint32_t PID1;   (            "                  /�*< Peripheral Identifiaation Register !., offset* 0xFE4 */
  uint32_t PID2;  !       "                   "    /**| Per)pheral Identification Register 2., offset:"1zF�8 */
  wint32_t PID3;               0                   /**< Peripheral Identification RegisteR 3., offset: 4xFE� */
  uint32_t CID0;  "                 "            " +(*< Component Iemntification Register 0., offset: 0xF�0 */
( uint32_T CID1;                              !    /**< Cmmponent Identification Registur 1., offset: 0xFF4 */
  }int32_t CHD2;        "               �       $  /**< CoMpone.t Identificatyon Register 2., nffset: 0xFF8 */
  uint12_t CI\4;                         $         /*"< Component Id%ntification register 3., offset:  xFFC */
} volauile *TPIU_MemapPtr;

/* -�-------------------------------m--------------------------------%---------
   -- TPIU - Register accessor macros�   -------------------------------------------------�---------/--------------- */

/**
 : @addtogroup TPIU_Rugister_Accessor_Macros TPIU - Regisuer accessor!macro�
 � @{
 */


/* TPIU - Register accessors */
#definu TPIU_SSPSR_REG(baqe)       `      $     (((base)->SSPSR)
#define TPIU_CSPSR_REG)ba�e)               0  "  ((bas%)->CSPWR)
#define TPIU_ACPR_REG(base)      `             ! ((base)=>ACPR)
#define TPIT_SPPR_REG(base	        "    (   !    ((base)->SPPR)
#dedine TPIU_FFSR_REG(base)            (    !  ( ((base)->FFSB)
#define TPIU_FFCR_REE(base)                      ((base)->FFCR)
#define TPIU_FSCR_REG(bas%)                 �    ((base)->FSCR)
#definw TPIU_\RIGGER_REG(base)         `         )(bace)->TRIGGER)
#define TPIU_FIFKDAVA0_REG(basu)     !           ((base)->FIFODA\A0)
#define TPIu�ITATBCTR2_REG+base)         (       ((base)->IT TBCTR2)
#denine TPIU_ITATBCTR0_REG(base) % `          `  ((base)->ITATBATR0)#lefine T@IU_FIFODATA1_REG(bas�)        �        �(base)->FIFODATA1)
#define TPIU_ITCTRL_REG(basu)                   (("ase)->ITCTRL)
cDefhne TPIU_LAIMRET_REO(base)                  ((baqe)->CNAIMSET)
#define TP�U_CLAIMCLR_REG(base)    0             (8base)->CLAIMCLR)
#define TPI]_DEV	D_REG(base)                     ((base)->D�VID)
#define TPIU_PID4_REG(base)4                     ((ba{e)->PID4)
#define TPIU_�ID5_REG(base)                      ((bese)->PID5)
#defi.% TPIU_PID6_REW(Base)                      ((base)->PID)
#define TPIU_PIE7_REG(base)             �        ((base)->PID7)#define TPIU_PID0_BEG(base) !                    ()base)->PID0)
#define TPIU_PID1_REG(base)     0  $ $           ((ba{e)->PID1)J#def�ne TPIU_PID2_REG(base)       !       ` 0    ((base)->PID2)
#denine TPIU_PID3_REG(base)                      ((base)->PID3)#define TQIU_CID0_BEG(base) �         �          ((base)->CID�)
#define TPIU_CID1_REG(base)                      ((base)-.CID1)
#define TPIU_CIL2_REG(base)                      ((baqe)%>cID2)
#define0TPIU_CID4_REG(base)!                     ((bqse)->CID4)

/**
 * @} */ /* end f group TPIU_Register_Accessor_MacRos */


/� --------------------------------,----------------/------------------------
   -- TPIU Register Masks
   --------�----------------------------------------------------------=--%--- */

/**
 * @addtogroup$TPIU_Rdgister_Masks TPIU Register Masks
 *$@{
 */


/**
 ( @}
 */ /+ end Of grOup TPIU_Rggister_�as�s */


�* TPIU - Peripheram instance base addressec */
/** �eripher!l TPIU bas� pointer */#define TPI�_BASE_PTR                            ((TPIU_EemMapPtr)0xE0040 00u)
o** Array inytializer of TPKU peripherel base poinders */
#define$TPIU_BASE_PTRS  0            !           {�TPIU_BASE_PTR }
/* ---------------------,-=-----=------)---------------------�-----------------
   -- TPIU - Register ac#essor macros
   ----------------)-)-----------)--------)------------------------------------ +/

/**
 * @addtogroup TPiU_Register]Accessor�Macros TPIU - Segister acc%ssor macros
 * @{
 "/


/* TPIU"- Regisvep instance�definitions */
/* TPIU */
#define TPI�_SSPSr                !              TPIQ_SSQSR_REG(TPIU_BASE_PTR)
#define TPIU_CSPSR               "               TPIU_CSPSR_REG(TPIU_BASE_PTR)
#$efine!TPIU_ACPR   "          `                 TPIU_ACPR[REG(TPIU_BASEPTR)
#define TPIU_SPPR       $                  `     TPIU_S@PR_REG(TPIUBSE_PTR)
#define TPIU_FFSR                               �TPIQ_FFSR_REG(TPIU_BASA_PTR)
#dgfine TPMU_FFCR    �                           TPIU]�FCR_REG(TPIU_BASE�PTR)
#dufi�e TPIU_FSCV        (                      !TPIUONSCR_REG TPIU_BASE_PTR)
#defI�e TPIU_TRIGGER                             TPAU_TRIGGER_REG(TPIU_BAE_PTR)�#define TPIU_FIFODATA0                           TPIU_FIFODaTA0_REG(TPIU_BASE_PTR)
#define TPIU_ITATBCTR2                        �  TPIU_ITaVBCVR2_REG(TPIT_BASE_PTR)*#define TPIE_ITATBGTZ0    "                      TPIU_ITATBCtR _REG(TPIU_BASE_PTR!
#define DPIU_FIFODATA1                           TpIU_FIFODATA1_REG(TPIU_BASE_PTR)
#Define UP�U_ITCTRL                        !(  " TPIU_ITCTRL_REG(TPMU_BASE_PTR)
#defind TPIU_CLAIMSET !                  �       TPIU_C�AIMSETREG(TPIU_BASE_P�R)
#defin� TPIU_CLAIMCLR                            TPIU_CLAIMCLR_ZEG(TPIU_BASE_PTR)
#$efine TPA�_DEVID                      $   �    TPIU_DEVID_REG(PI_BASE_PTR)
#define TPIU_PID4     "                        " TPIU_PID4_REG(TPIU_BASE_PTR)
#define TPIU_PID5        "                       VPIU_PID5_REG(TPIU_BAS�_PTR)
#deFine TPIU_PID6                                TPIU_PID6_REG(TPIU_BASEWPTR)
#defiNe TPIU_PID7        $                  "    TPIU_PID7_REG(TPIU_BASE_PTR)
�defiNe TPYU_PID0        "                       TPIU_PID0_REG(TPIU_BASE_PTR)
#define TPIU_PID1                                TPIU_PID1_REG(TPIU_BASE_PTR)
#define TPIU_PID2                                TPIU_PID2_REG(TPIU_BASE_PTR)
#define TPIU_PID3                                TPIU_PID3_REG(TPIU_BASE_PTR)
#define TPIU_CID0                                TPIU_CID0_REG(TPIU_BASE_PTR)
#define TPIU_CID1                                TPIU_CID1_REG(TPIU_BASE_PTR)
#define TPIU_CID2                                TPIU_CID2_REG(TPIU_BASE_PTR)
#define TPIU_CID3                                TPIU_CID4_REG(TPIU_BASE_PTR)

/**
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group TPIU_Peripheral */


/* ----------------------------------------------------------------------------
   -- TSI
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Peripheral TSI
 * @{
 */

/** TSI - Peripheral register structure */
typedef struct TSI_MemMap {
  uint32_t GENCS;                                  /**< General Control and Status register, offset: 0x0 */
  uint32_t SCANC;                                  /**< SCAN Control register, offset: 0x4 */
  uint32_t PEN;                                    /**< Pin Enable register, offset: 0x8 */
  uint32_t WUCNTR;                                 /**< Wake-Up Channel Counter Register, offset: 0xC */
  uint8_t RESERVED_0[240];
  uint32_t CNTR1;                                  /**< Counter Register, offset: 0x100 */
  uint32_t CNTR3;                                  /**< Counter Register, offset: 0x104 */
  uint32_t CNTR5;                                  /**< Counter Register, offset: 0x108 */
  uint32_t CNTR7;                                  /**< Counter Register, offset: 0x10C */
  uint32_t CNTR9;                                  /**< Counter Register, offset: 0x110 */
  uint32_t CNTR11;                                 /**< Counter Register, offset: 0x114 */
  uint32_t CNTR13;                                 /**< Counter Register, offset: 0x118 */
  uint32_t CNTR15;                                 /**< Counter Register, offset: 0x11C */
  uint32_t THRESHOLD;                              /**< Low-Power Channel Threshold register, offset: 0x120 */
} volatile *TSI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register accessors */
#define TSI_GENCS_REG(base)                      ((base)->GENCS)
#define TSI_SCANC_REG(base)                      ((base)->SCANC)
#define TSI_PEN_REG(base)                        ((base)->PEN)
#define TSI_WUCNTR_REG(base)                     ((base)->WUCNTR)
#define TSI_CNTR1_REG(base)                      ((base)->CNTR1)
#define TSI_CNTR3_REG(base)                      ((base)->CNTR3)
#define TSI_CNTR5_REG(base)                      ((base)->CNTR5)
#define TSI_CNTR7_REG(base)                      ((base)->CNTR7)
#define TSI_CNTR9_REG(base)                      ((base)->CNTR9)
#define TSI_CNTR11_REG(base)                     ((base)->CNTR11)
#define TSI_CNTR13_REG(base)                     ((base)->CNTR13)
#define TSI_CNTR15_REG(base)                     ((base)->CNTR15)
#define TSI_THRESHOLD_REG(base)                  ((base)->THRESHOLD)

/**
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/* GENCS Bit Fields */
#define TSI_GENCS_STPE_MASK                      0x1u
#define TSI_GENCS_STPE_SHIFT                     0
#define TSI_GENCS_STM_MASK                       0x2u
#define TSI_GENCS_STM_SHIFT                      1
#define TSI_GENCS_ESOR_MASK                      0x10u
#define TSI_GENCS_ESOR_SHIFT                     4
#define TSI_GENCS_ERIE_MASK                      0x20u
#define TSI_GENCS_ERIE_SHIFT                     5
#define TSI_GENCS_TSIIE_MASK                     0x40u
#define TSI_GENCS_TSIIE_SHIFT                    6
#define TSI_GENCS_TSIEN_MASK                     0x80u
#define TSI_GENCS_TSIEN_SHIFT                    7
#define TSI_GENCS_SWTS_MASK                      0x100u
#define TSI_GENCS_SWTS_SHIFT                     8
#define TSI_GENCS_SCNIP_MASK                     0x200u
#define TSI_GENCS_SCNIP_SHIFT                    9
#define TSI_GENCS_OVRF_MASK                      0x1000u
#define TSI_GENCS_OVRF_SHIFT                     12
#define TSI_GENCS_EXTERF_MASK                    0x2000u
#define TSI_GENCS_EXTERF_SHIFT                   13
#define TSI_GENCS_OUTRGF_MASK                    0x4000u
#define TSI_GENCS_OUTRGF_SHIFT                   14
#define TSI_GENCS_EOSF_MASK                      0x8000u
#define TSI_GENCS_EOSF_SHIFT                     15
#define TSI_GENCS_PS_MASK                        0x70000u
#define TSI_GENCS_PS_SHIFT                       16
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK)
#define TSI_GENCS_NSCN_MASK                      0xF80000u
#define TSI_GENCS_NSCN_SHIFT                     19
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK)
#define TSI_GENCS_LPSCNITV_MASK                  0xF000000u
#define TSI_GENCS_LPSCNITV_SHIFT                 24
#define TSI_GENCS_LPSCNITV(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_LPSCNITV_SHIFT))&TSI_GENCS_LPSCNITV_MASK)
#define TSI_GENCS_LPCLKS_MASK                    0x10000000u
#define TSI_GENCS_LPCLKS_SHIFT                   28
/* SCANC Bit Fields */
#define TSI_SCANC_AMPSC_MASK                     0x7u
#define TSI_SCANC_AMPSC_SHIFT                    0
#define TSI_SCANC_AMPSC(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMPSC_SHIFT))&TSI_SCANC_AMPSC_MASK)
#define TSI_SCANC_AMCLKS_MASK                    0x18u
#define TSI_SCANC_AMCLKS_SHIFT                   3
#define TSI_SCANC_AMCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMCLKS_SHIFT))&TSI_SCANC_AMCLKS_MASK)
#define TSI_SCANC_SMOD_MASK                      0xFF00u
#define TSI_SCANC_SMOD_SHIFT                     8
#define TSI_SCANC_SMOD(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_SMOD_SHIFT))&TSI_SCANC_SMOD_MASK)
#define TSI_SCANC_EXTCHRG_MASK                   0xF0000u
#define TSI_SCANC_EXTCHRG_SHIFT                  16
#define TSI_SCANC_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_EXTCHRG_SHIFT))&TSI_SCANC_EXTCHRG_MASK)
#define TSI_SCANC_REFCHRG_MASK                   0xF000000u
#define TSI_SCANC_REFCHRG_SHIFT                  24
#define TSI_SCANC_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_REFCHRG_SHIFT))&TSI_SCANC_REFCHRG_MASK)
/* PEN Bit Fields */
#define TSI_PEN_PEN0_MASK                        0x1u
#define TSI_PEN_PEN0_SHIFT                       0
#define TSI_PEN_PEN1_MASK                        0x2u
#define TSI_PEN_PEN1_SHIFT                       1
#define TSI_PEN_PEN2_MASK                        0x4u
#define TSI_PEN_PEN2_SHIFT                       2
#define TSI_PEN_PEN3_MASK                        0x8u
#define TSI_PEN_PEN3_SHIFT                       3
#define TSI_PEN_PEN4_MASK                        0x10u
#define TSI_PEN_PEN4_SHIFT                       4
#define TSI_PEN_PEN5_MASK                        0x20u
#define TSI_PEN_PEN5_SHIFT                       5
#define TSI_PEN_PEN6_MASK                        0x40u
#define TSI_PEN_PEN6_SHIFT                       6
#define TSI_PEN_PEN7_MASK                        0x80u
#define TSI_PEN_PEN7_SHIFT                       7
#define TSI_PEN_PEN8_MASK                        0x100u
#define TSI_PEN_PEN8_SHIFT                       8
#define TSI_PEN_PEN9_MASK                        0x200u
#define TSI_PEN_PEN9_SHIFT                       9
#define TSI_PEN_PEN10_MASK                       0x400u
#define TSI_PEN_PEN10_SHIFT                      10
#define TSI_PEN_PEN11_MASK                       0x800u
#define TSI_PEN_PEN11_SHIFT                      11
#define TSI_PEN_PEN12_MASK                       0x1000u
#define TSI_PEN_PEN12_SHIFT                      12
#define TSI_PEN_PEN13_MASK                       0x2000u
#define TSI_PEN_PEN13_SHIFT                      13
#define TSI_PEN_PEN14_MASK                       0x4000u
#define TSI_PEN_PEN14_SHIFT                      14
#define TSI_PEN_PEN15_MASK                       0x8000u
#define TSI_PEN_PEN15_SHIFT                      15
#define TSI_PEN_LPSP_MASK                        0xF0000u
#define TSI_PEN_LPSP_SHIFT                       16
#define TSI_PEN_LPSP(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_LPSP_SHIFT))&TSI_PEN_LPSP_MASK)
/* WUCNTR Bit Fields */
#define TSI_WUCNTR_WUCNT_MASK                    0xFFFFu
#define TSI_WUCNTR_WUCNT_SHIFT                   0
#define TSI_WUCNTR_WUCNT(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_WUCNTR_WUCNT_SHIFT))&TSI_WUCNTR_WUCNT_MASK)
/* CNTR1 Bit Fields */
#define TSI_CNTR1_CTN1_MASK                      0xFFFFu
#define TSI_CNTR1_CTN1_SHIFT                     0
#define TSI_CNTR1_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR1_CTN1_SHIFT))&TSI_CNTR1_CTN1_MASK)
#define TSI_CNTR1_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR1_CTN_SHIFT                      16
#define TSI_CNTR1_CTN(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR1_CTN_SHIFT))&TSI_CNTR1_CTN_MASK)
/* CNTR3 Bit Fields */
#define TSI_CNTR3_CTN1_MASK                      0xFFFFu
#define TSI_CNTR3_CTN1_SHIFT                     0
#define TSI_CNTR3_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR3_CTN1_SHIFT))&TSI_CNTR3_CTN1_MASK)
#define TSI_CNTR3_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR3_CTN_SHIFT                      16
#define TSI_CNTR3_CTN(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR3_CTN_SHIFT))&TSI_CNTR3_CTN_MASK)
/* CNTR5 Bit Fields */
#define TSI_CNTR5_CTN1_MASK                      0xFFFFu
#define TSI_CNTR5_CTN1_SHIFT                     0
#define TSI_CNTR5_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR5_CTN1_SHIFT))&TSI_CNTR5_CTN1_MASK)
#define TSI_CNTR5_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR5_CTN_SHIFT                      16
#define TSI_CNTR5_CTN(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR5_CTN_SHIFT))&TSI_CNTR5_CTN_MASK)
/* CNTR7 Bit Fields */
#define TSI_CNTR7_CTN1_MASK                      0xFFFFu
#define TSI_CNTR7_CTN1_SHIFT                     0
#define TSI_CNTR7_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR7_CTN1_SHIFT))&TSI_CNTR7_CTN1_MASK)
#define TSI_CNTR7_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR7_CTN_SHIFT                      16
#define TSI_CNTR7_CTN(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR7_CTN_SHIFT))&TSI_CNTR7_CTN_MASK)
/* CNTR9 Bit Fields */
#define TSI_CNTR9_CTN1_MASK                      0xFFFFu
#define TSI_CNTR9_CTN1_SHIFT                     0
#define TSI_CNTR9_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR9_CTN1_SHIFT))&TSI_CNTR9_CTN1_MASK)
#define TSI_CNTR9_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR9_CTN_SHIFT                      16
#define TSI_CNTR9_CTN(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR9_CTN_SHIFT))&TSI_CNTR9_CTN_MASK)
/* CNTR11 Bit Fields */
#define TSI_CNTR11_CTN1_MASK                     0xFFFFu
#define TSI_CNTR11_CTN1_SHIFT                    0
#define TSI_CNTR11_CTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR11_CTN1_SHIFT))&TSI_CNTR11_CTN1_MASK)
#define TSI_CNTR11_CTN_MASK                      0xFFFF0000u
#define TSI_CNTR11_CTN_SHIFT                     16
#define TSI_CNTR11_CTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR11_CTN_SHIFT))&TSI_CNTR11_CTN_MASK)
/* CNTR13 Bit Fields */
#define TSI_CNTR13_CTN1_MASK                     0xFFFFu
#define TSI_CNTR13_CTN1_SHIFT                    0
#define TSI_CNTR13_CTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR13_CTN1_SHIFT))&TSI_CNTR13_CTN1_MASK)
#define TSI_CNTR13_CTN_MASK                      0xFFFF0000u
#define TSI_CNTR13_CTN_SHIFT                     16
#define TSI_CNTR13_CTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR13_CTN_SHIFT))&TSI_CNTR13_CTN_MASK)
/* CNTR15 Bit Fields */
#define TSI_CNTR15_CTN1_MASK                     0xFFFFu
#define TSI_CNTR15_CTN1_SHIFT                    0
#define TSI_CNTR15_CTN1(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_CNTR15_CTN1_SHIFT))&TSI_CNTR15_CTN1_MASK)
#define TSI_CNTR15_CTN_MASK                      0xFFFF0000u
#define TSI_CNTR15_CTN_SHIFT                     16
#define TSI_CNTR15_CTN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_CNTR15_CTN_SHIFT))&TSI_CNTR15_CTN_MASK)
/* THRESHOLD Bit Fields */
#define TSI_THRESHOLD_HTHH_MASK                  0xFFFFu
#define TSI_THRESHOLD_HTHH_SHIFT                 0
#define TSI_THRESHOLD_HTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_HTHH_SHIFT))&TSI_THRESHOLD_HTHH_MASK)
#define TSI_THRESHOLD_LTHH_MASK                  0xFFFF0000u
#define TSI_THRESHOLD_LTHH_SHIFT                 16
#define TSI_THRESHOLD_LTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_LTHH_SHIFT))&TSI_THRESHOLD_LTHH_MASK)

/**
 * @}
 */ /* end of group TSI_Register_Masks */


/* TSI - Peripheral instance base addresses */
/** Peripheral TSI0 base pointer */
#define TSI0_BASE_PTR                            ((TSI_MemMapPtr)0x40045000u)
/** Array initializer of TSI peripheral base pointers */
#define TSI_BASE_PTRS                            { TSI0_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros
 * @{
 */


/* TSI - Register instance definitions */
/* TSI0 */
#define TSI0_GENCS                               TSI_GENCS_REG(TSI0_BASE_PTR)
#define TSI0_SCANC                               TSI_SCANC_REG(TSI0_BASE_PTR)
#define TSI0_PEN                                 TSI_PEN_REG(TSI0_BASE_PTR)
#define TSI0_WUCNTR                              TSI_WUCNTR_REG(TSI0_BASE_PTR)
#define TSI0_CNTR1                               TSI_CNTR1_REG(TSI0_BASE_PTR)
#define TSI0_CNTR3                               TSI_CNTR3_REG(TSI0_BASE_PTR)
#define TSI0_CNTR5                               TSI_CNTR5_REG(TSI0_BASE_PTR)
#define TSI0_CNTR7                               TSI_CNTR7_REG(TSI0_BASE_PTR)
#define TSI0_CNTR9                               TSI_CNTR9_REG(TSI0_BASE_PTR)
#define TSI0_CNTR11                              TSI_CNTR11_REG(TSI0_BASE_PTR)
#define TSI0_CNTR13                              TSI_CNTR13_REG(TSI0_BASE_PTR)
#define TSI0_CNTR15                              TSI_CNTR15_REG(TSI0_BASE_PTR)
#define TSI0_THRESHOLD                           TSI_THRESHOLD_REG(TSI0_BASE_PTR)

/**
 * @}
 */ /* end of group TSI_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group TSI_Peripheral */


/* ----------------------------------------------------------------------------
   -- UART
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Peripheral UART
 * @{
 */

/** UART - Peripheral register structure */
typedef struct UART_MemMap {
  uint8_t BDH;                                     /**< UART Baud Rate Registers: High, offset: 0x0 */
  uint8_t BDL;                                     /**< UART Baud Rate Registers: Low, offset: 0x1 */
 ��}�
��2�&߫�&�lw)�s7����6�e*��^<N):��:aҡ:WC��*"!�L��mի�d_��~E;���̆x֛(���gį��u���U���͒�_e���d����[9��v��*ـ�3/���]��{�^%cQ��l[��z�2Jo�J.��ѥ�"L�d���E�#��r/ �b�EJF��˔�w%������8�Dע�����D���z�����.^F�m?�u�#��`b�C��`UQs'C0#�CȕeTf`�e��6X�e�����w�k�N�� ���eG2N��?�NK'Sp�F���	ڬ ����!�+�8�Q1�+���p����&4�y�o�Ѽ)���=����}g���]a����,ll6���K�y� �?��|��c��� 9����EL+������ �E.�.X��'��	��I*��2vA~����|+�J�&���N�мY䪻�������C�VӉ*� `n%ihW%��lC�	�ۯ���֘��&M��ٝ�Cʹ���eg���@A�����x��gEWz� �e�T��B2������>D��+U��U{����,l�6�r�ET�|{�K>[����r8��; #%�}��n�"lc�=ƐqsYMՈ׸j'�4�nz��2"����P���J�N�C�-���2�y %�n�=��n��	��&U�v��ig9'ۋ�JL�o�g�Ki8�;�a\+��mo?���H��*?�Q8Qؔ�G^�=x�#y35�Pf,p��"��w_F�A3Й����Dʡ�[=�tN��+�Ն��a~A�Y������8��B (���o�phҝ
���P�y��y�ƥSa]ؑ
z�k��C��}j�d�/标p6��\�`����DA�.�����c��E�k�F&�c����Wa*����5H�<F�f�����f���zk�lS=��C�M�8���9�V;���fD�]��2roK���f}7���#G�A�Xca��2�6h{h���b?�z�   /**< UART Extended Data Register, offset: 0xC */
  uint8_t MODEM;                                   /**< UART Modem Register, offset: 0xD */
  uint8_t IR;                                      /**< UART Infrared Register, offset: 0xE */
  uint8_t RESERVED_0[1];
  uint8_t PFIFO;                                   /**< UART FIFO Parameters, offset: 0x10 */
  uint8_t CFIFO;                                   /**< UART FIFO Control Register, offset: 0x11 */
  uint8_t SFIFO;                                   /**< UART FIFO Status Register, offset: 0x12 */
  uint8_t TWFIFO;                                  /**< UART FIFO Transmit Watermark, offset: 0x13 */
  uint8_t TCFIFO;                                  /**< UART FIFO Transmit Count, offset: 0x14 */
  uint8_t RWFIFO;                                  /**< UART FIFO Receive Watermark, offset: 0x15 */
  uint8_t RCFIFO;                                  /**< UART FIFO Receive Count, offset: 0x16 */
  uint8_t RESERVED_1[1];
  uint8_t C7816;                                   /**< UART 7816 Control Register, offset: 0x18 */
  uint8_t IE7816;                                  /**< UART 7816 Interrupt Enable Register, offset: 0x19 */
  uint8_t IS7816;                                  /**< UART 7816 Interrupt Status Register, offset: 0x1A */
  union {                                          /* offset: 0x1B */
    uint8_t WP7816_T_TYPE0;                          /**< UART 7816 Wait Parameter Register, offset: 0x1B */
    uint8_t WP7816_T_TYPE1;                          /**< UART 7816 Wait Parameter Register, offset: 0x1B */
  };
  uint8_t WN7816;                                  /**< UART 7816 Wait N Register, offset: 0x1C */
  uint8_t WF7816;                                  /**< UART 7816 Wait FD Register, offset: 0x1D */
  uint8_t ET7816;                                  /**< UART 7816 Error Threshold Register, offset: 0x1E */
  uint8_t TL7816;                                  /**< UART 7816 Transmit Length Register, offset: 0x1F */
  uint8_t RESERVED_2[1];
  uint8_t C6;                                      /**< UART CEA709.1-B Control Register 6, offset: 0x21 */
  uint8_t PCTH;                                    /**< UART CEA709.1-B Packet Cycle Time Counter High, offset: 0x22 */
  uint8_t PCTL;                                    /**< UART CEA709.1-B Packet Cycle Time Counter Low, offset: 0x23 */
  uint8_t B1T;                                     /**< UART CEA709.1-B Beta1 Timer, offset: 0x24 */
  uint8_t SDTH;                                    /**< UART CEA709.1-B Secondary Delay Timer High, offset: 0x25 */
  uint8_t SDTL;                                    /**< UART CEA709.1-B Secondary Delay Timer Low, offset: 0x26 */
  uint8_t PRE;                                     /**< UART CEA709.1-B Preamble, offset: 0x27 */
  uint8_t TPL;                                     /**< UART CEA709.1-B Transmit Packet Length, offset: 0x28 */
  uint8_t IE;                                      /**< UART CEA709.1-B Interrupt Enable Register, offset: 0x29 */
  uint8_t WB;                                      /**< UART CEA709.1-B WBASE, offset: 0x2A */
  uint8_t S3;                                      /**< UART CEA709.1-B Status Register, offset: 0x2B */
  uint8_t S4;                                      /**< UART CEA709.1-B Status Register, offset: 0x2C */
  uint8_t RPL;                                     /**< UART CEA709.1-B Received Packet Length, offset: 0x2D */
  uint8_t RPREL;                                   /**< UART CEA709.1-B Received Preamble Length, offset: 0x2E */
  uint8_t CPW;                                     /**< UART CEA709.1-B Collision Pulse Width, offset: 0x2F */
  uint8_t RIDT;                                    /**< UART CEA709.1-B Receive Indeterminate Time, offset: 0x30 */
  uint8_t TIDT;                                    /**< UART CEA709.1-B Transmit Indeterminate Time, offset: 0x31 */
} volatile *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor ma��}�
��2�&߫�&�lw)�s7����6�e*��^<N):��:aҡ:WC��*"!�L��mի�d_��~E;���̆x֛(���gį��u���U���͒�_e���d����[9��v��*ـ�3/���]��{�^%cQ��l[��z�2Jo�J.��ѥ�"L�d���E�#��r/ �b�EJF��˔�w%������8�Dע�����D���z�����.^F�m?�u�#��`b�C��`UQs'C0#�CȕeTf`�e��6X�e�����w�k�N�� ���eG2N��?�NK'Sp�F���	ڬ ����!�+�8�Q1�+���p����&4�y�o�Ѽ)���=����}g���]a����,ll6���K�y� �?��|��c��� 9����EL+������ �E.�.X��'��	��I*��2vA~����|+�J�&���N�мY䪻�������C�VӉ*� `n%ihW%��lC�	�ۯ���֘��&M��ٝ�Cʹ���eg���@A�����x��gEWz� �e�T��B2������>D��+U��U{����,l�6�r�ET�|{�K>[����r8��; #%�}��n�"lc�=ƐqsYMՈ׸j'�4�nz��2"����P���J�N�C�-���2�y %�n�=��n��	��&U�v��ig9'ۋ�JL�o�g�Ki8�;�a\+��mo?���H��*?�Q8Qؔ�G^�=x�#y35�Pf,p��"��w_F�A3Й����Dʡ�[=�tN��+�Ն��a~A�Y������8��B (���o�phҝ
���P�y��y�ƥSa]ؑ
z�k��C��}j�d�/标p6��\�`����DA�.�����c��E�k�F&�c����Wa*����5H�<F�f�����f���zk�lS=��C�M�8���9�V;���fD�]��2roK���f}7���#G�A�Xca��2�6h{h���b?�z�        ((base)->ED)
#define UART_MODEM_REG(base)                     ((base)->MODEM)
#define UART_IR_REG(base)                        ((base)->IR)
#define UART_PFIFO_REG(base)                     ((base)->PFIFO)
#define UART_CFIFO_REG(base)                     ((base)->CFIFO)
#define UART_SFIFO_REG(base)                     ((base)->SFIFO)
#define UART_TWFIFO_REG(base)                    ((base)->TWFIFO)
#define UART_TCFIFO_REG(base)                    ((base)->TCFIFO)
#define UART_RWFIFO_REG(base)                    ((base)->RWFIFO)
#define UART_RCFIFO_REG(base)                    ((base)->RCFIFO)
#define UART_C7816_REG(base)                     ((base)->C7816)
#define UART_IE7816_REG(base)                    ((base)->IE7816)
#define UART_IS7816_REG(base)                    ((base)->IS7816)
#define UART_WP7816_T_TYPE0_REG(base)            ((base)->WP7816_T_TYPE0)
#define UART_WP7816_T_TYPE1_REG(base)            ((base)->WP7816_T_TYPE1)
#define UART_WN7816_REG(base)                    ((base)->WN7816)
#define UART_WF7816_REG(base)                    ((base)->WF7816)
#define UART_ET7816_REG(base)                    ((base)->ET7816)
#define UART_TL7816_REG(base)                    ((base)->TL7816)
#define UART_C6_REG(base)                        ((base)->C6)
#define UART_PCTH_REG(base)                      ((base)->PCTH)
#define UART_PCTL_REG(base)                      ((base)->PCTL)
#define UART_B1T_REG(base)                       ((base)->B1T)
#define UART_SDTH_REG(base)                      ((base)->SDTH)
#define UART_SDTL_REG(base)                      ((base)->SDTL)
#define UART_PRE_REG(base)                       ((base)->PRE)
#define UART_TPL_REG(base)                       ((base)->TPL)
#define UART_IE_REG(base)                        ((base)->IE)
#define UART_WB_REG(base)                        ((base)->WB)
#define UART_S3_REG(base)                        ((base)->S3)
#define UART_S4_REG(base)                        ((base)->S4)
#define UART_RPL_REG(base)                       ((base)->RPL)
#define UART_RPREL_REG(base)                     ((base)->RPREL)
#define UART_CPW_REG(base)                       ((base)->CPW)
#define UART_RIDT_REG(base)                      ((base)->RIDT)
#define UART_TIDT_REG(base)                      ((base)->TIDT)

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                      ` 7
/* S1 Bit Fyends */
#eefine UART_S1_PB_MASK                          0x1u
#define UART_S1_PF_SIIFD                         0
#define UARU_S1FE_MASK                       !  0x2u
#define UART_S1_FE_SHIFT                       ` 1
#d%fine UART_S1_NF_MCQK                   �      0x4u
#define UART_S1_NF_SHIFT               $         2
#define UART_S1_OR_MASK                          0x8u�#define UART_S1_OR_SHIFT       " !   0           3
#defije UART_S1_HDLe_MASK0                       0x10u
#define UART_S1_IDLE_SHIFT                 `     4
#defina UAPT_S1_RDRF_MASK           �    $       0x24u
#de&ine UART_S1_RDRFWSHIFT      0   `            5
#define UARD_S1_TK_MASC         !            "   0x40u
#define UERTOS5_TC_SHIFT       "        0        6
#define UaRT_S1_TDRE_MASK   "           "    �   0x80u
#define UART_S3_TDRE_SHIFT                       7
/* S2 Bit F)elds */-
#define UARTWS2_RAF_MASK                         0x1u
#define UCRT]S2_RAf_SHIFT              0         0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA1_MA_SHIFT))&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x))<<UART_MA2_MA_SHIFT))&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* IR Bit Fields */
#define UART_IR_TNP_MASK                         0x3u
#define UART_IR_TNP_SHIFT                        0
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x))<<UART_IR_TNP_SHIFT))&UART_IR_TNP_MASK)
#define UART_IR_IREN_MASK                        0x4u
#define UART_IR_IREN_SHIFT                       2
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK              *\J���3cD�㡼ܲ^�_/"@Y�E�S���n�<?�}��p�E�g#T��@+���Xt�ELP+\��1�/]����^i�H�x�4𦖑uV�p�e}��3u��+�� �:��%����g��:X��������%�c��t�U���e�Q�q%=�ɓ��ņf��B>��2Ǳa�� R�Ţ��7��+���5h��|�=@zd�����k����F��2�6�8o�1�X�=����a"b׊�z��t��5}Q�6��*B�gU����qG�}_�Yι�`�_юR�ף������@�)�\n�@m��x�&��z�?_^n�n�����L����_� &��D�9�'����Ď��&���^������!��C�(M
<����ս'��CcN7��,������T�x�x��P�tL���|��6�	sRBS�F-��D2A>�5���4��1��=S:,��Z��?��Vej�ff��{����X�Zx줇��%��죿�<x)���CN�n`݁]zH��=!b��Х������q>��x_�v#Z�U��q%,��⃢����ܤ��F�2BuHR�� �j�TMz��O������2�#����9��m9N='�s �؇'�\��\E:=G�L�=�HQ1Ģ*�O�(_�z߄�T��{�⑾3e��g�1)�#��Z!��c��۶+���������%�?뿂�d��Q��b��'t���qI58U8ۭY���+�z����9<�{��U�T��pb������d��xi��ߑ%=���e�<& �X��N��]�a� ��(�*�ik\�=������:0ɑ��?u#�2�K��)\�}m�"�B���߆+����;����>���������+���"�W5����\$Y�G���ۯ����N�\c��M����
�k ��vӠ�]�6��n�n���0s{b�������D��@0������44����٢�7�G%�0Ύ�&�f�R-����/h�(;4�r����Tw���S\�h_?sG�n	ZUbV>�4����n�8s�:���y��=%�����Ǖ��Gl�s�^���t#�4������/Iҡ�C�湔�=��fT���׮��Z�r�#����������z�@��D������.ї�}���¹��IN�e�;� �� 5�(��CϪ��m�z�Z��L�[�$w��#%����?u"j�|�S3�a�K�@UD�ꩋO�`14�
�D��� 0������y�o2/�EJ!]B���}�-�ᡠ�Ei���6����M5�E6ٵ�$�p��W5՘�>������l[t�<�PN0��E�! �~���4�^�kV���/���ѥC:h}n� b�xy����dQq�W����Ҍ~�
�٨���yEf(y�H����mh�lOJT9��s0��gxK�C�r`�ͬ�`�5O�p�H�V��K��\:�=�<37��D��B�z�����s?������u��i�+������q�F�ĥ��G�����(q;�'��U����&l���C�G&�Lx���h��m|�cj���N�&���w�e_��
��_�|ʝ�킚umT��b���u��C��/^�LI�1�>���#n��d�;��o�M�J�c��zO�kޯa\��W�д����0Y`�K?��?�������z���I)9]���7���CK�6|ҭJh7�;����U�	�����y�v |/Z�G�{<am�A4�Em9����A�63��4%�f��159�n�=1�.����_n��T3��{Q�j���6q���WPJ���Ʀ��V�C5���l̠9L|Oj^^NȜ��V�1&����A���l��N!a����f����ձ����%��7���v�����R�'%3�C��9��
�gj���mPII*�)���2]e0g�W��܌�ѹ��T㷑���K�+fݳ3d��U��(���͗�H��=+�Cyqע���A����j!����E� :gJs�jS�ԫ�n��>-3�f4��m$#��F�� �>ia�t�}?)9[��9�,D���lG��K+]��#�p�!�z��e��+WE�JܶfY�x2�u���mBN�C��σ8y��������f�!�@gҧ�=�Jhz���E�œ�԰���ܧ��2JS���8�߶xg7v�f�ꥌ����xD��U���u�)=nD����-"bY-�q�CtE+X6B��!#��V�� �߼ yk���Q��ҵ�ˋ\��Q�MŦOh���wLN������ �r��G��{��M��i�5GĢEI�j	@�tU!���xW#Ѝ�b% v���ӏ�6��tr!�5� M���{��5U�)#�^�nt� ���� �<�m���B}d�����{J}�"�Pk�� �c4��tM�k�A!���ȀX�%_:&}��7�-*�~�6�!��e����2'����S�<���ຒ�O!4���Ԥ|�v�S�W6� A��x׳<�5r&�Y��������K�k"��u�"�@kD�Ѱ1���˕#�ۘ ����oŀd�m��˰���w3D|��$ 
��7!N9�Ԟ�_�pQ&�3�J$���-o[�c��}/72��&%|#��<�\���DJ2�,�e������Ć�m��Vy�3~�e�����|+�����̡�I�4��	a��k�{�*��lZ%zpR�ꅆ�4`���� �Q`1J�8��p��N �[B6W4&v����)L_h5�������97�����`��`�=[���-j�ɿ������ی�R���=|D��[�����rVaH{�������(0��V�m�o�&J�bgs�X2�TR�!LX���͡ܛ�Yrt70 �O,��x�1�}�R����Ht>���*�����)���|T0�%Y�p�f��~�)6�*�n���lmLm��-#�ںo�lO�_��:C��A"��Εe��7}#�#�.v�3q)���+
�+�)0xm��!�n�
�S�.��?H���;�	A<�1�2S܂䦗�x��=-��x�k���pɁ���r*��pɤ��vS�������1�䅐�����]X���#�l�k�\��^¯Σ��e�l���N'<ɚ�<��K
Gx&^���V��}l}t~#Z}A>�I��#̛WE���ˍG��X˝�)��sd)xs��eΞ�#����+�><�>���Ӧ|�L����P[LZ�=[<�:�ҷ�z�J�B-%��CC�y�3����G�����jw���Q�<;&5�FwM#%�ѣ�<3�w��)�M<F�us�� 8�Z9��a������?��	7:ƜN%u��z̟���KÅ8��(L(?�աwP��Bٜ��f�Л��8�˺i�&��L���;\����dGFzn����*I<����;ېh����}�f}7��#mI*M���^�
u4<Unf�lP��rO�77H���9[�z���\|� .7�z��]S]�i��`0PIm<*��أR���@�Jէ�6y��5�����w�PI�Y�b9q�Q�Ao���J�\�}�oGJ������`T?d߆�c؉�J+;L���,�nS�4���z�x߱�A�yc7���l��}��ˡ���ժ�!#?�S���|xį��EZ&����ǛE$P�+?�U ���~�5 GTm�3����׼.	BoQ���$��a$�n�>�T~�ە�S-�<[�Ҩ�*�s{^"(҆��
��x]34�^2v���;�F�h����r�ɸ����rE��R�ő�W�vM��Xb��o�V�?�O�k!��������l�_�=2C����o����*� N�jE��	}bm�FM�<��)��� �פ�� �/�-���\򍝊�j=���x{%ʘ�Z6�Tq����充�ˉ����A��([�:"��N��l�f������cD���r`w�z$�'k�����R�#В��i��}����Y�`��S��ZF*\J���3cD�㡼ܲ^�_/"@Y�E�S���n�<?�}��p�E�g#T��@+���Xt�ELP+\��1�/]����^i�H�x�4𦖑uV�p�e}��3u��+�� �:��%����g��:X��������%�c��t�U���e�Q�q%=�ɓ��ņf��B>��2Ǳa�� R�Ţ��7��+���5h��|�=@zd�����k����F��2�6�8o�1�X�=����a"b׊�z��t��5}Q�6��*B�gU����qG�}_�Yι�`�_юR�ף������@�)�\n�@m��x�&��z�?_^n�n�����L����_� &��D�9�'����Ď��&���^������!��C�(M
<����ս'��CcN7��,������T�x�x��P�tL���|��6�	sRBS�F-��D2A>�5���4��1��=S:,��Z��?��Vej�ff��{����X�Zx줇��%��죿�<x)���CN�n`݁]zH��=!b��Х������q>��x_�v#Z�U��q%,��⃢����ܤ��F�2BuHR�� �j�TMz��O������2�#����9��m9N='�s �؇'�\��\E:=G�L�=�HQ1Ģ*�O�(_�z߄�T��{�⑾3e��g�1)�#��Z!��c��۶+���������%�?뿂�d��Q��b��'t���qI58U8ۭY���+�z����9<�{��U�T��pb������d��xi��ߑ%=���e�<& �X��N��]�a� ��(�*�ik\�=������:0ɑ��?u#�2�K��)\�}m�"�B���߆+����;����>���������+���"�W5����\$Y�G���ۯ����N�\c��M����
�k ��vӠ�]�6��n�n���0s{b�������D��@0������44����٢�7�G%�0Ύ�&�f�R-)��b��d���p��F������P���h(f��i#7[�짼��.���{��t3`rs���$B�T��^�-'�_��)8��z�k��>�D���p����X������� J8�U=�e�=y}b7�t�:��,%�ᵧ��hR�mm�yZM�����^>J��z�C��T�d`1�6��
#�i�D1�N�ݴ��Iq���k-������/1��3� � �i�v?SP��7�k"�D����x�U�Y����LG��_y+!:�e�I�M�%�6��'�(8����FuО?uv|�P��F��硇*�hz��Z��kpy_S�8c!�)T	��dp>1 ���[���4�}i��?�� WxNȖl�a<��sqX��/r���44�H�bW:Հ��h��Y�?��?2iR�(	�f�Z-MdDQ�~�,Ǌ����X~�6��I���y���t�L�Y��tE;)�B��h˙�XgԂK(�[HT��\����C��QM�K�y?-~ɢa�Ů�Wk������c�
�41��*����Ӆ���N�0�-�54q�����|
�Y���Z7�T��L�_�}Y��%Ey���]A��ow��Β׹͙ih}F��hV������� ��`��0_VÚcjM���pw<9�l�a&�v�����r�SD�&���#��px���&f�+�Z2\<�����-v>���cW[�b�P:0�w�=���ޱ1�v�7�*�3<�� K�rTʛ r��O�����'K���K3�[����}�&�����1���)���\p�I�?�Z�<d�����b���Ղ��`��ֈn���a�S ���mw��J_B� ��L�J`a9�l����jͮ����v�*��D7�(�T~,�ӧ�3�"g��s�,��/���Q}�����6
�~�����
ćg�g�S/prt���A�O�Yj5Z��jM�i��up���
-���b�����7��5�D��B"��2*}��:9<hqo���Q����4zt(�SДAM��r����g9�� �um3�i¸�Ò�,\�QIγHt�t�2vڹu���\~���+��c�gb�6�$�p����[A�Z>�B��Tb�g���A�e��q�0��'O�ht;Y�W� e�m�|���n�&��d�&䪥�Q��HE����}��{{܅�:�1��%��<m'���C�Ȃ�G�H�Q�R�k��^�6��5�����gsT�zS��R��+£j�����1�J�����t�EBXT[|�����O�N��Y-Wdu?��ɖ��	�	���J&��mSa�_���$�0	��K�7d�_#���v5�+3�XZB8E?c�|nZ&14�������Z#��ۼMZ��p�I�wv}@�ۂ���y�8�8�]�;����/!^��k��7����~���o��	���翽Ӂ!�	4�G�L���Lb����7��wT�'�a�l��,c�G�u��l�6ϋߘپ-������Ig+j�}Z/��U��CZ�i\HD]��6�`¢��*qɻ��Do�}�ȴT�3f�9��)�!�u�ݿ唛.�mi�&z6�G�p+��w�����?��]�w�Go��Kxv9��^G���7u�	���]���|Jз��oo�Ϯ�w_�1��}�uΤ�"�q�h�{@t0���S4����68w�>J�vs��ӏ����|��c�D�����ȶ��B&7x�uKp�U��f9��D)�NJ��1=����X%i��D� �8EC����R����qr�rT�:��7����ߡ�H�������<M�������'�㦿��0����g���z�8��Y*��2EU�5�@��j15���9E
 ������羞0�C�H�h�6�,g?��E�Xo.h���pv��R�����U�G`9��TN��9��m��� �f��xW3�-2(;�O�O�>�ɬf�e}~g��_��L��%�%(�!��'���D���eOrk��z@B�
퍏�(���Tt
�,��H�/���m��}�*���ά$���$S7�|�B�ί�F��SnPCTL_PCTL_MASK)
/* B1T Bit Fields */
#define UART_B1T_B1T_MASK                        0xFFu
#define UART_B1T_B1T_SHIFT                       0
#define UART_B1T_B1T(x)                          (((uint8_t)(((uint8_t)(x))<<UART_B1T_B1T_SHIFT))&UART_B1T_B1T_MASK)
/* SDTH Bit Fields */
#define UART_SDTH_SDTH_MASK                      0xFFu
#define UART_SDTH_SDTH_SHIFT                     0
#define UART_SDTH_SDTH(x)                        (((uint8_t)(((uint8_t)(x))<<UART_SDTH_SDTH_SHIFT))&UART_SDTH_SDTH_MASK)
/* SDTL Bit Fields */
#define UART_SDTL_SDTL_MASK                      0xFFu
#define UART_SDTL_SDTL_SHIFT                     0
#define UART_SDTL_SDTL(x)                        (((uint8_t)(((uint8_t)(x))<<UART_SDTL_SDTL_SHIFT))&UART_SDTL_SDTL_MASK)
/* PRE Bit Fields */
#define UART_PRE_PREAMBLE_MASK                   0xFFu
#define UART_PRE_PREAMBLE_SHIFT                  0
#define UART_PRE_PREAMBLE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_PRE_PREAMBLE_SHIFT))&UART_PRE_PREAMBLE_MASK)
/* TPL Bit Fields */
#define UART_TPL_TPL_MASK                        0xFFu
#define UART_TPL_TPL_SHIFT                       0
#define UART_TPL_TPL(x)                          (((uint8_t)(((uint8_t)(x))<<UART_TPL_TPL_SHIFT))&UART_TPL_TPL_MASK)
/* IE Bit Fields */
#define UART_IE_TXFIE_MASK                       0x1u
#define UART_IE_TXFIE_SHIFT                      0
#define UART_IE_PSIE_MASK                        0x2u
#define UART_IE_PSIE_SHIFT                       1
#define UART_IE_PCTEIE_MASK                      0x4u
#define UART_IE_PCTEIE_SHIFT                     2
#define UART_IE_PTXIE_MASK                       0x8u
#define UART_IE_PTXIE_SHIFT                      3
#define UART_IE_PRXIE_MASK                       0x10u
#define UART_IE_PRXIE_SHIFT                      4
#define UART_IE_ISDIE_MASK                       0x20u
#define UART_IE_ISDIE_SHIFT                      5
#define UART_IE_WBEIE_MASK                       0x40u
#define UART_IE_WBEIE_SHIFT                      6
/* WB it Fi�lds */
#define UART_WB_WBASG_MASK                       0xFFu
#define UART_WB_�BASE_SHIBU  0         �         0�#define UART_WB_WBASE(x)    0   $                (((uin48_t)(((uint8_t)(x!)<<UART_WB_WBASE_SHIFT�)&UART_WB_WBASE_mASK)
/* S3 Bit Fields�*/
#define!�ART_S�_TXFF_MAsK                        0x1u
#define UIZT_S3�DXFF_SHIFT                       0
#define ART_S3_PSF_MASK                       $ 2x2u
#de�ine UARP_S3_PSF_SHIFT       "                1
#define UART_S3[PCTEF_MASK              !  0     0x4u
#d%fine UARt_S3_PCTEFWSHIVT                    0 2
#define UERT�S3_@TXF_MASK                        4|8u
#define UART_S3_PTXF_SHIFT     0             `   3#tefine UART_S3_PRXF_MSK                   0    0x10U
#define UART_S�_PRXF_SHIFT    00        $     !  4
#de&ine UART_S3_ISD_MASK            0            1x20u
#define UART_S3_ISD_SHIFT          (             5
define UARVS3_WBEF_MASK                        0x40u
#define UART_S3_WBEF_SHIFT                       6
#define UART_S3_PEF_�ASK                         0|80u#denine UART_S3_PEF_SHMFT      (                 7
/* S4 Bit Fieles */
#define UART_S4_FE_MASK                          0x1uM
'defiog UART_S4_FE_SHIFT     � `  $              0
#dufine UART_S4_ILCV_MACK 0                      0x2u
#dufane UART_S4_ILCV_SHIFT                     " 1
#define UART_S4_CDET_MASK                        0xCu
#�efine UART_S4_DET_SHIFT                       2
#define UART_S4_CDET(x)                          ()(uint8_t)(((uint8_t)(x))<<UART_S4_CDET_SHIFT))&UART_S4_GDET_]ASK)
#define UART_S4_INITF_MARK             !�        0x10u
#de�ine U�RT_S4_INITF_S@IFT                      4
/* RPL Bkt Fields j/
#define UAR�_RPL_RPL_MASK                        0xFFu
#defioe UART_RPL_RPL_SHIFT       `  "            0
'define UART_ZPL_RPL(x)      "    $      b    !  (((uint8_4)(((uint8_t)(x))<<UART�RPL_RPL_SHIFT))&UABT_RPL_RPL_MASK)
/* RPREL @it Fields */
#eefine UART_RPRELRPREL_IASK    "               0xFFt
+define UAR\_RPRED_RPREL_SHIFT                   0
#define UART_RPREL_RPREL(x)                      (((uint8_t)(((uint8_t)(x))<<UART_RPREL_RPREL_SHIFT))&UART_RPREL_RPREL_MASK)
/* CPW Bit Fields */
#define UART_CPW_CPW_MASK                        0xFFu
#define UART_CPW_CPW_SHIFT                       0
#define UART_CPW_CPW(x)                          (((uint8_t)(((uint8_t)(x))<<UART_CPW_CPW_SHIFT))&UART_CPW_CPW_MASK)
/* RIDT Bit Fields */
#define UART_RIDT_RIDT_MASK                      0xFFu
#define UART_RIDT_RIDT_SHIFT                     0
#define UART_RIDT_RIDT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_RIDT_RIDT_SHIFT))&UART_RIDT_RIDT_MASK)
/* TIDT Bit Fields */
#define UART_TIDT_TIDT_MASK                      0xFFu
#define UART_TIDT_TIDT_SHIFT                     0
#define UART_TIDT_TIDT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_TIDT_TIDT_SHIFT))&UART_TIDT_TIDT_MASK)

/**
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peri0heral UAPT0 base pointer */
#define UART0_BARE_PTR         `                 ((UART}emMapPtr)0x4006A000u)
/** Peripheral UART1 base pointer$*/
#defIne UARU1�BARE_P�B        0                  ((UART_M%mMapXtr)0x4006B00u)
/** Peripheral UIST2 base pointer */
#define uART2_BASE_PTR      (                  ! ((UARt_MemMapPtr)0x4006C000�)
/** Perixheral UART3 base point�r */#define URT3_BASE_PTR        0                  ((UART_MemMapPtr)0x4006�0"0u)M
/** P�ripheral UART4 base pointer */
#define UART4_BASE_PDR      $                   ((UART_MemMapPdr)0x400EA000u)
/** Peripheral UART5�base pointer */
#define UART5_BASE_PTR             �        `    ((UART_MemMapPts)0x400Eb000u)
/** Array inktia,izer of UART peRipheral�base pointess */
#ddfine(UART_BASE_PTRS                          { UCRT0_BASE_PTR, UARV1_BASE_PTR, UART2_BASE_PTR, UART3_BASE_PTR, UART4_BASEPTR, UART5_BASE_PTR }

/* ---------------------------------------------------------------------------
   -- UART - Regis�er accessor macros
   ----------,-----�----------------------�---------=------/------%------------ "/

/**
 . @a`dtogroup UART^Register_Ackessor_Macros UART - Register accessor macros
 * @{
 */


/* UART!- Register instance definitions */
/* UART0 */
#fefinE UART0_BDH       $                        UART_BDH_EG(UCRT0_BASE_PTR)
#de&y�e UART0_BdL                                UART_BTL_RE�(UART0_BASE_PUV)*#define UART0_C1                       $         UART_C1_REG(UART0_BASE_PTR)
#defyn% UART0_C2              !     (            ET_C2_REG(UART0_BASE_PTR)
#define UART0_S1!                                UART_S1_REG(UART0_BASE_XTR)
#define UART0_S2`       (                 "      UARU_S2_REG(WART0_BASEOPPR)
#define UA�T0_C3       $                    "    UAPT_B3_REG(UAR�0_BASE_PTR)
#define UART0_D                                  UART^D_REO(UAR�0_BASE_PTR)
#define UART0_MA1                                UART_M1_REG(UART0_BASE_PTR�
#define UART0_MA2           !  0                 UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4   (                `            UART_C4_REG(UARU0_BA[E_PTR)
#dmfine UQRT0_C5      0     (   0                UARTC5_REG(UART0_BASE_PTR)�
#define UART0_ED           `     0               UART_ED_REG(UART0_JASE_PtR)
#define URT0_MODEM    (           $             UART_MODEM_R�G(UAT0_BACE_PTR)
#define UART0_Ir   (          $                 0UART_IR_REW(UART0_BASD_PTR)
#$efine UART0_PFIFO   "              0      "    UART_FIFO_REG(TART0_BASE_PTR)
#defi�e UART0_CFIFO               $              UART_CFIO_REG(UARTp_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_RG(UART0_BASE_PTR)
#defi�e UART0_TWFIFO                 (           UART_TWFIFOOREG(UART0_BASE_PTR)
#define UART0_TCFIFO               !         @   UART_TFIFO_REG(UART0_BASE_PTR)
#dedine UART0_RWIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO      ,              `       UART[RCFIFO_RE(UART0_BASE_PTR)
#define!UART0_C7816                 `            UART_C7816_REG(UART0_BASE_PTR)
#define UART0_IE7816                             UART_IE7816_REG(UART0_BASE_PTR)
#define UART0_IS7816                             UART_IS7816_REG(UART0_BASE_PTR)
#define UART0_WP7816T0                           UART_WP7816_T_TYPE0_REG(UART0_BASE_PTR)
#define UART0_WP7816T1                           UART_WP7816_T_TYPE1_REG(UART0_BASE_PTR)
#define UART0_WN7816                             UART_WN7816_REG(UART0_BASE_PTR)
#define UART0_WF7816                             UART_WF7816_REG(UART0_BASE_PTR)
#define UART0_ET7816                             UART_ET7816_REG(UART0_BASE_PTR)
#define UART0_TL7816                             UART_TL7816_REG(UART0_BASE_PTR)
#define UART0_C6                                 UART_C6_REG(UART0_BASE_PTR)
#define UART0_PCTH                               UART_PCTH_REG(UART0_BASE_PTR)
#define UART0_PCTL                               UART_PCTL_REG(UART0_BASE_PTR)
#define UART0_B1T                                UART_B1T_REG(UART0_BASE_PTR)
#define UART0_SDTH                               UART_SDTH_REG(UART0_BASE_PTR)
#define UART0_SDTL                               UART_SDTL_REG(UART0_BASE_PTR)
#define UART0_PRE                                UART_PRE_REG(UART0_BASE_PTR)
#define UART0_TPL                                UART_TPL_REG(UART0_BASE_PTR)
#define UART0_IE                                 UART_IE_REG(UART0_BASE_PTR)
#define UART0_WB                                 UART_WB_REG(UART0_BASE_PTR)
#define UART0_S3                                 UART_S3_REG(UART0_BASE_PTR)
#define UART0_S4                                 UART_S4_REG(UART0_BASE_PTR)
#define UART0_RPL                                UART_RPL_REG(UART0_BASE_PTR)
#define UART0_RPREL                              UART_RPREL_REG(UART0_BASE_PTR)
#define UART0_CPW                                UART_CPW_REG(UART0_BASE_PTR)
#define UART0_RIDT                               UART_RIDT_REG(UART0_BASE_PTR)
#define UART0_TIDT                               UART_TIDT_REG(UART0_BASE_PTR)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1_BASE_PTR)
#define UART1_BDL                                UART_BDL_REG(UART1_BASE_PTR)
#define UART1_C1                                 UART_C1_REG(UART1_BASE_PTR)
#define UART1_C2                                 UART_C2_REG(UART1_BASE_PTR)
#define UART1_S1                                 UART_S1_REG(UART1_BASE_PTR)
#define UART1_S2                                 UART_S2_REG(UART1_BASE_PTR)
#define UART1_C3                                 UART_C3_REG(UART1_BASE_PTR)
#define UART1_D                                  UART_D_REG(UART1_BASE_PTR)
#define UART1_MA1                                UART_MA1_REG(UART1_BASE_PTR)
#define UART1_MA2                                UART_MA2_REG(UART1_BASE_PTR)
#define UART1_C4                                 UART_C4_REG(UART1_BASE_PTR)
#define UART1_C5                                 UART_C5_REG(UART1_BASE_PTR)
#define UART1_ED                                 UART_ED_REG(UART1_BASE_PTR)
#define UART1_MODEM                              UART_MODEM_REG(UART1_BASE_PTR)
#define UART1_IR                                 UART_IR_REG(UART1_BASE_PTR)
#define UART1_PFIFO                              UART_PFIFO_REG(UART1_BASE_PTR)
#define UART1_CFIFO                              UART_CFIFO_REG(UART1_BASE_PTR)
#define UART1_SFIFO                              UART_SFIFO_REG(UART1_BASE_PTR)
#define UART1_TWFIFO                             UART_TWFIFO_REG(UART1_BASE_PTR)
#define UART1_TCFIFO                             UART_TCFIFO_REG(UART1_BASE_PTR)
#define UART1_RWFIFO                             UART_RWFIFO_REG(UART1_BASE_PTR)
#define UART1_RCFIFO                             UART_RCFIFO_REG(UART1_BASE_PTR)
/* UART2 */
#define UART2_BDH                                UART_BDH_REG(UART2_BASE_PTR)
#define UART2_BDL                                UART_BDL_REG(UART2_BASE_PTR)
#define UART2_C1                                 UART_C1_REG(UART2_BASE_PTR)
#define UART2_C2                                 UART_C2_REG(UART2_BASE_PTR)
#define UART2_S1                                 UART_S1_REG(UART2_BASE_PTR)
#define UART2_S2                                 UART_S2_REG(UART2_BASE_PTR)
#define UART2_C3                                 UART_C3_REG(UART2_BASE_PTR)
#define UART2_D                                  UART_D_REG(UART2_BASE_PTR)
#define UART2_MA1                                UART_MA1_REG(UART2_BASE_PTR)
#define UART2_MA2                                UART_MA2_REG(UART2_BASE_PTR)
#define UART2_C4                                 UART_C4_REG(UART2_BASE_PTR)
#define UART2_C5                                 UART_C5_REG(UART2_BASE_PTR)
#define UART2_ED                                 UART_ED_REG(UART2_BASE_PTR)
#define UART2_MODEM                              UART_MODEM_REG(UART2_BASE_PTR)
#define UART2_IR                                 UART_IR_REG(UART2_BASE_PTR)
#define UART2_PFIFO                              UART_PFIFO_REG(UART2_BASE_PTR)
#define UART2_CFIFO                              UART_CFIFO_REG(UART2_BASE_PTR)
#define UART2_SFIFO                              UART_SFIFO_REG(UART2_BASE_PTR)
#define UART2_TWFIFO                             UART_TWFIFO_REG(UART2_BASE_PTR)
#define UART2_TCFIFO                             UART_TCFIFO_REG(UART2_BASE_PTR)
#define UART2_RWFIFO                             UART_RWFIFO_REG(UART2_BASE_PTR)
#define UART2_RCFIFO                             UART_RCFIFO_REG(UART2_BASE_PTR)
/* UART3 */
#define UART3_BDH                                UART_BDH_REG(UART3_BASE_PTR)
#define UART3_BDL                                UART_BDL_REG(UART3_BASE_PTR)
#define UART3_C1                                 UART_C1_REG(UART3_BASE_PTR)
#define UART3_C2                                 UART_C2_REG(UART3_BASE_PTR)
#define UART3_S1                                 UART_S1_REG(UART3_BASE_PTR)
#define UART3_S2                                 UART_S2_REG(UART3_BASE_PTR)
#define UART3_C3                                 UART_C3_REG(UART3_BASE_PTR)
#define UART3_D                                  UART_D_REG(UART3_BASE_PTR)
#define UART3_MA1                                UART_MA1_REG(UART3_BASE_PTR)
#define UART3_MA2                                UART_MA2_REG(UART3_BASE_PTR)
#define UART3_C4                                 UART_C4_REG(UART3_BASE_PTR)
#define UART3_C5                                 UART_C5_REG(UART3_BASE_PTR)
#define UART3_ED                                 UART_ED_REG(UART3_BASE_PTR)
#define UART3_MODEM                              UART_MODEM_REG(UART3_BASE_PTR)
#define UART3_IR                                 UART_IR_REG(UART3_BASE_PTR)
#define UART3_PFIFO                              UART_PFIFO_REG(UART3_BASE_PTR)
#define UART3_CFIFO                              UART_CFIFO_REG(UART3_BASE_PTR)
#define UART3_SFIFO                              UART_SFIFO_REG(UART3_BASE_PTR)
#define UART3_TWFIFO                             UART_TWFIFO_REG(UART3_BASE_PTR)
#define UART3_TCFIFO                             UART_TCFIFO_REG(UART3_BASE_PTR)
#define UART3_RWFIFO                             UART_RWFIFO_REG(UART3_BASE_PTR)
#define UART3_RCFIFO                             UART_RCFIFO_REG(UART3_BASE_PTR)
/* UART4 */
#define UART4_BDH                                UART_BDH_REG(UART4_BASE_PTR)
#define UART4_BDL                                UART_BDL_REG(UART4_BASE_PTR)
#define UART4_C1                                 UART_C1_REG(UART4_BASE_PTR)
#define UART4_C2                                 UART_C2_REG(UART4_BASE_PTR)
#define UART4_S1                                 UART_S1_REG(UART4_BASE_PTR)
#define UART4_S2                                 UART_S2_REG(UART4_BASE_PTR)
#define UART4_C3                                 UART_C3_REG(UART4_BASE_PTR)
#define UART4_D                                  UART_D_REG(UART4_BASE_PTR)
#define UART4_MA1                                UART_MA1_REG(UART4_BASE_PTR)
#define UART4_MA2                                UART_MA2_REG(UART4_BASE_PTR)
#define UART4_C4                                 UART_C4_REG(UART4_BASE_PTR)
#define UART4_C5                                 UART_C5_REG(UART4_BASE_PTR)
#define UART4_ED                                 UART_ED_REG(UART4_BASE_PTR)
#define UART4_MODEM                              UART_MODEM_REG(UART4_BASE_PTR)
#define UART4_IR                                 UART_IR_REG(UART4_BASE_PTR)
#define UART4_PFIFO                              UART_PFIFO_REG(UART4_BASE_PTR)
#define UART4_CFIFO                              UART_CFIFO_REG(UART4_BASE_PTR)
#define UART4_SFIFO                              UART_SFIFO_REG(UART4_BASE_PTR)
#define UART4_TWFIFO                             UART_TWFIFO_REG(UART4_BASE_PTR)
#define UART4_TCFIFO                             UART_TCFIFO_REG(UART4_BASE_PTR)
#define UART4_RWFIFO                             UART_RWFIFO_REG(UART4_BASE_PTR)
#define UART4_RCFIFO                             UART_RCFIFO_REG(UART4_BASE_PTR)
/* UART5 */
#define UART5_BDH                                UART_BDH_REG(UART5_BASE_PTR)
#define UART5_BDL                                UART_BDL_REG(UART5_BASE_PTR)
#define UART5_C1                                 UART_C1_REG(UART5_BASE_PTR)
#define UART5_C2                                 UART_C2_REG(UART5_BASE_PTR)
#define UART5_S1                                 UART_S1_REG(UART5_BASE_PTR)
#define UART5_S2                                 UART_S2_REG(UART5_BASE_PTR)
#define UART5_C3                                 UART_C3_REG(UART5_BASE_PTR)
#define UART5_D                                  UART_D_REG(UART5_BASE_PTR)
#define UART5_MA1                                UART_MA1_REG(UART5_BASE_PTR)
#define UART5_MA2                                UART_MA2_REG(UART5_BASE_PTR)
#define UART5_C4                                 UART_C4_REG(UART5_BASE_PTR)
#define UART5_C5                                 UART_C5_REG(UART5_BASE_PTR)
#define UART5_ED                                 UART_ED_REG(UART5_BASE_PTR)
#define UART5_MODEM                              UART_MODEM_REG(UART5_BASE_PTR)
#define UART5_IR                                 UART_IR_REG(UART5_BASE_PTR)
#define UART5_PFIFO                              UART_PFIFO_REG(UART5_BASE_PTR)
#define UART5_CFIFO                              UART_CFIFO_REG(UART5_BASE_PTR)
#define UART5_SFIFO                              UART_SFIFO_REG(UART5_BASE_PTR)
#define UART5_TWFIFO                             UART_TWFIFO_REG(UART5_BASE_PTR)
#define UART5_TCFIFO                             UART_TCFIFO_REG(UART5_BASE_PTR)
#define UART5_RWFIFO                             UART_RWFIFO_REG(UART5_BASE_PTR)
#define UART5_RCFIFO                             UART_RCFIFO_REG(UART5_BASE_PTR)

/**
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group UART_Peripheral */


/* ----------------------------------------------------------------------------
   -- USB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Peripheral USB
 * @{
 */

/** USB - Peripheral register structure */
typedef struct USB_MemMap {
  uint8_t PERID;                                   /**< Peripheral ID register, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                  /**< Peripheral ID Complement register, offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t REV;                                     /**< Peripheral Revision register, offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                 /**< Peripheral Additional Info register, offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                /**< OTG Interrupt Status register, offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                  /**< OTG Interrupt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                 /**< OTG Status register, offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                  /**< OTG Control register, offset: 0x1C */
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                   /**< Interrupt Status register, offset: 0x80 */
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                   /**< Interrupt Enable register, offset: 0x84 */
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                 /**< Error Interrupt Status register, offset: 0x88 */
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                   /**< Error Interrupt Enable register, offset: 0x8C */
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                    /**< Status register, offset: 0x90 */
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                     /**< Control register, offset: 0x94 */
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                    /**< Address register, offset: 0x98 */
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                /**< BDT Page Register 1, offset: 0x9C */
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                 /**< Frame Number Register Low, offset: 0xA0 */
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                 /**< Frame Number Register High, offset: 0xA4 */
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                   /**< Token register, offset: 0xA8 */
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                 /**< SOF Threshold Register, offset: 0xAC */
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                /**< BDT Page Register 2, offset: 0xB0 */
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                /**< BDT Page Register 3, offset: 0xB4 */
  uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    uint8_t ENDPT;                                   /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                 /**< USB Control register, offset: 0x100 */
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                 /**< USB OTG Observe register, offset: 0x104 */
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                 /**< USB OTG Control register, offset: 0x108 */
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                 /**< USB Transceiver Control Register 0, offset: 0x10C */
  uint8_t RESERVED_25[7];
  uint8_t USBFRMADJUST;                            /**< Frame Adjust Register, offset: 0x114 */
} volatile *USB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register accessors */
#define USB_PERID_REG(base)                      ((base)->PERID)
#define USB_IDCOMP_REG(base)                     ((base)->IDCOMP)
#define USB_REV_REG(base)                        ((base)->REV)
#define USB_ADDINFO_REG(base)                    ((base)->ADDINFO)
#define USB_OTGISTAT_REG(base)                   ((base)->OTGISTAT)
#define USB_OTGICR_REG(base)                     ((base)->OTGICR)
#define USB_OTGSTAT_REG(base)                    ((base)->OTGSTAT)
#define USB_OTGCTL_REG(base)                     ((base)->OTGCTL)
#define USB_ISTAT_REG(base)                      ((base)->ISTAT)
#define USB_INTEN_REG(base)                      ((base)->INTEN)
#define USB_ERRSTAT_REG(base)                    ((base)->ERRSTAT)
#define USB_ERREN_REG(base)                      ((base)->ERREN)
#define USB_STAT_REG(base)                       ((base)->STAT)
#define USB_CTL_REG(base)                        ((base)->CTL)
#define USB_ADDR_REG(base)                       ((base)->ADDR)
#define USB_BDTPAGE1_REG(base)                   ((base)->BDTPAGE1)
#define USB_FRMNUML_REG(base)                    ((base)->FRMNUML)
#define USB_FRMNUMH_REG(base)                    ((base)->FRMNUMH)
#define USB_TOKEN_REG(base)                      ((base)->TOKEN)
#define USB_SOFTHLD_REG(base)                    ((base)->SOFTHLD)
#define USB_BDTPAGE2_REG(base)                   ((base)->BDTPAGE2)
#define USB_BDTPAGE3_REG(base)                   ((base)->BDTPAGE3)
#define USB_ENDPT_REG(base,index)                ((base)->ENDPOINT[index].ENDPT)
#define USB_USBCTRL_REG(base)                    ((base)->USBCTRL)
#define USB_OBSERVE_REG(base)                    ((base)->OBSERVE)
#define USB_CONTROL_REG(base)                    ((base)->CONTROL)
#define USB_USBTRC0_REG(base)                    ((base)->USBTRC0)
#define USB_USBFRMADJUST_REG(base)               ((base)->USBFRMADJUST)

/**
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/* PERID Bit Fields */
#define USB_PERID_ID_MASK                        0x3Fu
#define USB_PERID_ID_SHIFT                       0
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USB_IDCOMP_NID_MASK                      0x3Fu
#define USB_IDCOMP_NID_SHIFT                     0
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USB_REV_REV_MASK                         0xFFu
#define USB_REV_REV_SHIFT                        0
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USB_ADDINFO_IEHOST_MASK                  0x1u
#define USB_ADDINFO_IEHOST_SHIFT                 0
#define USB_ADDINFO_IRQNUM_MASK                  0xF8u
#define USB_ADDINFO_IRQNUM_SHIFT                 3
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IRQNUM_SHIFT))&USB_ADDINFO_IRQNUM_MASK)
/* OTGISTAT Bit Fields */
#define USB_OTGISTAT_AVBUSCHG_MASK               0x1u
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0
#define USB_OTGISTAT_B_SESS_CHG_MASK             0x4u
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2
#define USB_OTGISTAT_SESSVLDCHG_MASK             0x8u
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         0x20u
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5
#define USB_OTGISTAT_ONEMSEC_MASK                0x40u
#define USB_OTGISTAT_ONEMSEC_SHIFT               6
#define USB_OTGISTAT_IDCHG_MASK                  0x80u
#define USB_OTGISTAT_IDCHG_SHIFT                 7
/* OTGICR Bit Fields */
#define USB_OTGICR_AVBUSEN_MASK                  0x1u
#define USB_OTGICR_AVBUSEN_SHIFT                 0
#define USB_OTGICR_BS��3��{��b?:�EA�ʥ�]}�G�K%�p�:�U,��_�����a
sX�+��*u�I���΋ ����?۝��Nvs����揫�Z*����mʕ`̺X�t�����ʞW#����1�\���y0���,�u͵����(�!�+����c��P����,�k�?��&���PZ鍻�����$��z2��|�������<jw�`$���7~^ג�j���@���X�7�L��b�k�c��$J��v?�eu"`��*FV��jX~u����Pp��d�� ?�Q 4V���>ǁ1�{�������9�XLP���=�Ҹv���g-z�p4�����X@�đR�<m�K�--��HAe�Mv!��;���8+��FanH�D���_"� �j�[;����3���H���dFQ��_�zn���F�1B,'�:��&a������Vi�)&�n�{�,}��I��!�$Pպ���f<�#�
Ȇˡ���i,ek�����h	f�F������r�Z�q-��v�����u� [�rPʩ�n"B=o$ʰ���h�*a�b�~v��X����X����r�,�ݷ�pYsozr�Nq��f�iS�s8�.��5i�����^�g��Ŋ� �k��ptm6L`̰� V���B��q��������h]���\Q*o��r�"�L ��(m�1�ϕ{�i^��SN?��|��z�rGQ���q�ѧ�룦��j<l���XZp���)�N=;���2=;Oߜ� "
���G�=�D�_�m�i�4҅��+5�/L�}y�/�O++��3�p��ɬW| �
�Ng��u�~���q8P."���^2D��f�hk	�$�V����Cnm�d'��x@�WY�_ȘSn{��ԁIpy�tQ<H힡�B�긑K�+������Yb����Ӫ>7���Sk�C�ư�/5��iq�f������b�@B��:��8�i�{b��������ш���Gӳ�ѥt�/���L�>�@0u
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6
#define USB_OTGSTAT_ID_MASK                      0x80u
#define USB_OTGSTAT_ID_SHIFT                     7
/* OTGCTL Bit Fields */
#define USB_OTGCTL_OTGEN_MASK                    0x4u
#define USB_OTGCTL_OTGEN_SHIFT                   2
#define USB_OTGCTL_DMLOW_MASK                    0x10u
#define USB_OTGCTL_DMLOW_SHIFT                   4
#define USB_OTGCTL_DPLOW_MASK                    0x20u
#define USB_OTGCTL_DPLOW_SHIFT                   5
#define USB_OTGCTL_DPHIGH_MASK                   0x80u
#define USB_OTGCTL_DPHIGH_SHIFT                  7
/* ISTAT Bit Fields */
#define USB_ISTAT_USBRST_MASK                    0x1u
#define USB_ISTAT_USBRST_SHIFT                   0
#define USB_ISTAT_ERROR_MASK                     0x2u
#define USB_ISTAT_ERROR_SHIFT                    1
#define USB_ISTAT_SOFTOK_MASK                    0x4u
#define USB_ISTAT_SOFTOK_SHIFT                   2
#define USB_ISTAT_TOKDNE_MASK                    0x8u
#define USB_ISTAT_TOKDNE_SHIFT                   3
#define USB_ISTAT_SLEEP_MASK                     0x10u
#define USB_ISTAT_SLEEP_SHIFT                    4
#define USB_ISTAT_RESUME_MASK                    0x20u
#define USB_ISTAT_RESUME_SHIFT                   5
#define USB_ISTAT_ATTACH_MASK                    0x40u
#define USB_ISTAT_ATTACH_SHIFT                   6
#define USB_ISTAT_STALL_MASK                     0x80u
#define USB_ISTAT_STALL_SHIFT                    7
/* INTEN Bit Fields */
#define USB_INTEN_USBRSTEN_MASK                  0x1u
#define USB_INTEN_USBRSTEN_SHIFT                 0
#define USB_INTEN_ERROREN_MASK                   0x2u
#define USB_INTEN_ERROREN_SHIFT                  1
#define USB_INTEN_SOFTOKEN_MASK                  0x4u
#define USB_INTEN_SOFTOKEN_SHIFT                 2
#define USB_INTEN_TOKDNEEN_MASK                  0x8u
#define USB_INTEN_TOKDNEEN_SHIFT                 3
#define USB_INTEN_SLEEPEN_MASK                   0x10u
#define USB_INTEN_SLEEPEN_SHIFT                  4
#define USB_INTEN_RESUMEEN_MASK                  0x20u
#define USB_INTEN_RESUMEEN_SHIFT                 5
#define USB_INTEN_ATTACHEN_MASK                  0x40u
#define USB_INTEN_ATTACHEN_SHIFT                 6
#define USB_INTEN_STALLEN_MASK                   0x80u
#define USB_INTEN_STALLEN_SHIFT                  7
/* ERRSTAT Bit Fields */
#define USB_ERRSTAT_PIDERR_MASK                  0x1u
#define USB_ERRSTAT_PIDERR_SHIFT                 0
#define USB_ERRSTAT_CRC5EOF_MASK                 0x2u
#define USB_ERRSTAT_CRC5EOF_SHIFT                1
#define USB_ERRSTAT_CRC16_MASK                   0x4u
#define USB_ERRSTAT_CRC16_SHIFT                  2
#define USB_ERRSTAT_DFN8_MASK                    0x8u
#define USB_ERRSTAT_DFN8_SHIFT                   3
#define USB_ERRSTAT_BTOERR_MASK                  0x10u
#define USB_ERRSTAT_BTOERR_SHIFT                 4
#define USB_ERRSTAT_DMAERR_MASK                  0x20u
#define USB_ERRSTAT_DMAERR_SHIFT                 5
#define USB_ERQ3*�����="�W�QѸ��1����f���x�@ZF�[�u��������^�:���/���{�s%��v�ni=�ˆ2�k�y�^9��{��(�(}���)fD���ܧ��'W{X�j���_���2�3݁-� �z�ĀKk'E����#K)w�*��Nٍȷ���L�څv	̱��O�Cϴ�j��O���Nku�|��|		O�HV�/�)����(��2y�A:���W�Y��yA��J�n�O��n'*�j�}y��*�|��FL��<ySJ|اk�#�S����냋4Սu�q`�Nn����ƨeS�5�$r�� ����3aY���|aW��|�wc�r�2��0\(6?@��I�UI>@v%��Y������|��o����ϧ�Zys�i:i�ٮ<R�$��A (�N���x��5,��v�����:�W9Y��ƹ�)�<�n���,����R��ϭ1����<cm�ǝ���TqA'����K��|�C�؄�}2y M�Y�K'��8�@��l��Uv`�g���(-z
J,$��!q��H?���Uꆋ�D_�#���Oc#2�^�L���飂�ΏWt+@@=��)Q��@�)w ҇/�3e[���)��̻��)'�=��ׯKӁ-02�V���c��#0ϣΤ�C	��o�å��L�ݦ��;*�U#%�<�Dŷ�rt��<o	�3��q��]�����\���2ҩ��E���JX"<����o���~�=������a'R��|��B��s��H�_����rR{Q��~U9kCQ�͚�8ZD�H���m͡\H6�=�)4� cg��t��#�����k�����n���XG��Sf$D$�,ړ"�:�
6G_6g���9��OZ�k&���� -��O-���XS�ݔ��)�o&-���ƊSY�do'�[��?�.�Z��~E�U�f��0*��9�ŝ0��������<��|�`!r����x�/����.Lqe��D�S9|��}                         0x8u
#define USB_STAT_TX_SHIFT                        3
#define USB_STAT_ENDP_MASK                       0xF0u
#define USB_STAT_ENDP_SHIFT                      4
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USB_CTL_USBENSOFEN_MASK                  0x1u
#define USB_CTL_USBENSOFEN_SHIFT                 0
#define USB_CTL_ODDRST_MASK                      0x2u
#define USB_CTL_ODDRST_SHIFT                     1
#define USB_CTL_RESUME_MASK                      0x4u
#define USB_CTL_RESUME_SHIFT                     2
#define USB_CTL_HOSTMODEEN_MASK                  0x8u
#define USB_CTL_HOSTMODEEN_SHIFT                 3
#define USB_CTL_RESET_MASK                       0x10u
#define USB_CTL_RESET_SHIFT                      4
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          0x20u
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5
#define USB_CTL_SE0_MASK                         0x40u
#define USB_CTL_SE0_SHIFT                        6
#define USB_CTL_JSTATE_MASK                      0x80u
#define USB_CTL_JSTATE_SHIFT                     7
/* ADDR Bit Fields */
#define USB_ADDR_ADDR_MASK                       0x7Fu
#define USB_ADDR_ADDR_SHIFT                      0
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       0x80u
#define USB_ADDR_LSEN_SHIFT                      7
/* BDTPAGE1 Bit Fields */
#define USB_BDTPAGE1_BDTBA_MASK                  0xFEu
#define USB_BDTPAGE1_BDTBA_SHIFT                 1
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USB_FRMNUML_FRM_MASK                     0xFFu
#define USB_FRMNUML_FRM_SHIFT                    0
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USB_FRMNUMH_FRM_MASK                     0x7u
#define USB_FRMNUMH_FRM_SHIFT                    0
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USB_TOKEN_TOKENENDPT_MASK                0xFu
#define USB_TOKEN_TOKENENDPT_SHIFT               0
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  0xF0u
#define USB_TOKEN_TOKENPID_SHIFT                 4
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK)
/* SOFTHLD Bit Fields */
#define USB_SOFTHLD_CNT_MASK                     0xFFu
#define USB_SOFTHLD_CNT_SHIFT                    0
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USB_BDTPAGE2_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE2_BDTBA_SHIFT                 0
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USB_BDTPAGE3_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE3_BDTBA_SHIFT                 0
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USB_ENDPT_EPHSHK_MASK                    0x1u
#define USB_ENDPT_EPHSHK_SHIFT                   0
#define USB_ENDPT_EPSTALL_MASK                   0x2u
#define USB_ENDPT_EPSTALL_SHIFT                  1
#define USB_ENDPT_EPTXEN_MASK                    0x4u
#define USB_ENDPT_EPTXEN_SHIFT                   2
#define USB_ENDPT_EPRXEN_MASK                    0x8u
#define USB_ENDPT_EPRXEN_SHIFT                   3
#define USB_ENDPT_EPCTLDIS_MASK                  0x10u
#define USB_ENDPT_EPCTLDIS_SHIFT                 4
#define USB_ENDPT_RETRYDIS_MASK                  0x40u
#define USB_ENDPT_RETRYDIS_SHIFT                 6
#define USB_ENDPT_HOSTWOHUB_MASK                 0x80u
#define USB_ENDPT_HOSTWOHUB_SHIFT                7
/* USBCTRL Bit Fields */
#define USB_USBCTRL_PDE_MASK                     0x40u
#define USB_USBCTRL_PDE_SHIFT                    6
#define USB_USBCTRL_SUSP_MASK                    0x80u
#define USB_USBCTRL_SUSP_SHIFT                   7
/* OBSERVE Bit Fields */
#define USB_OBSERVE_DMPD_MASK                    0x10u
#define USB_OBSERVE_DMPD_SHIFT                   4
#define USB_OBSERVE_DPPD_MASK                    0x40u
#define USB_OBSERVE_DPPD_SHIFT                   6
#define USB_OBSERVE_DPPU_MASK                    0x80u
#define USB_OBSERVE_DPPU_SHIFT                   7
/* CONTROL Bit Fields */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          0x10u
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4
/*"USBTRC0 Bit Fields */
#define USB_USBTRS0_USB_RGSUEE_INT_]ARK  $       0x1u
#define USB_USBTRC0_ESB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_SYNC_DET_MESK                0x2u
#define USB_USBTRC1_SYNC_DET_SHIFT       !       1
#define USB_USBTRC0_USBRESMEN_MASK               0x20U
#define USB_USBTRC2_USBRESMEN_SHIFT"             5
#define USB_USBTRC0_USBRESET_MA�K              $ 0x80u
#define USB_USBTRC0_USBSUSET_CHIFT               6
/* USBFRmADJUST Bit Fields �/
#define USB_USBFRMAEZUST_ADH_MASK                0zFFu	
#define0USB_USBFRMADJUST_CDJ_SHIFT          !    0
#define USJ_USBNRMADJUST_AD�(x)         �        8((uin�8_t	(((uint8_t)(x))<<USB_USBFRMADJUST_ADN_SHAFT))&USB_USBVRMADJUST_ADJ_MASK)

/**
 * @}
 */ /* �nd of gro}p USB_Register_Masks */


/* USB - Peripheban instance "ase addresses */
/** Peripheral US@0 base0pointer */
#define USB0^BASE_PTR      !       $  (         b((USB_MemMapP4r)0x40072020u)
/** Array inivializer of USB peripheral base pointers *
#define QSB_BAQE_PTrS             `       "      { USB1_JSE_PTR }

/* -----------------------m--------------------------),------------------------�
   -- USB - Register accEssor macros-
   ------------------=%--=----,---------=-----------------------------------=-- */

/+*
 * @addtogroup USB_Register_Accassor_Macros USB - Registgr accessor macros
 * @{
 *'


/* USB - Register inst`nce definit�ons */
/* UQB0 */
#define USB0_PERID                               USB_�ERID_REG(URBp_BASE_PPR)
#define TSB0_IDCOMP             `!      !        USB_IDCOMP_REG(USB0_BACE_PTR)
#devine USB_REV                         !       USB_RER_REG(USB0_BASE_PTR)
#define USB0_ADDINFO                             USB_ADDINFO_REG(USB0_BASE_PTR)
#define USB0_OTGISTAT         ( 0                USB_OTGISTATWREG(USBp_BASE_PTR)
#define USB0_OT�IAR                  $           UWB_OTFICR_REG(USB0_�ASE_PTR)
#defin� USB0_OTGSTIT           �     (           USB_OTGSTAT_REG(USB0_BASE_TTR)
#define USB0_OTGCTl           ��        $        USB_OTGCTL_REG(USB0_BASE_PTR)
#define USB0_ISTAT                               USB_ISTAT_REG(USB0_BASE_PTR)
#define USB0_INTEN                               USB_INTEN_REG(USB0_BASE_PTR)
#define USB0_ERRSTAT                             USB_ERRSTAT_REG(USB0_BASE_PTR)
#define USB0_ERREN                               USB_ERREN_REG(USB0_BASE_PTR)
#define USB0_STAT                                USB_STAT_REG(USB0_BASE_PTR)
#define USB0_CTL                                 USB_CTL_REG(USB0_BASE_PTR)
#define USB0_ADDR                                USB_ADDR_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE1                            USB_BDTPAGE1_REG(USB0_BASE_PTR)
#define USB0_FRMNUML                             USB_FRMNUML_REG(USB0_BASE_PTR)
#define USB0_FRMNUMH                             USB_FRMNUMH_REG(USB0_BASE_PTR)
#define USB0_TOKEN                               USB_TOKEN_REG(USB0_BASE_PTR)
#define USB0_SOFTHLD                             USB_SOFTHLD_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE2            SEQ_RES_MASK               0x30000u
#define USBDCD_STATUS_SEQ_RES_SHIFT              16
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_RES_SHIFT))&USBDCD_STATUS_SEQ_RES_MASK)
#define USBDCD_STATUS_SEQ_STAT_MASK              0xC0000u
#define USBDCD_STATUS_SEQ_STAT_SHIFT             18
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_STAT_SHIFT))&USBDCD_STATUS_SEQ_STAT_MASK)
#define USBDCD_STATUS_ERR_MASK                   0x100000u
#define USBDCD_STATUS_ERR_SHIFT                  20
#define USBDCD_STATUS_TO_MASK                    0x200000u
#define USBDCD_STATUS_TO_SHIFT                   21
#define USBDCD_STATUS_ACTIVE_MASK                0x400000u
#define USBDCD_STATUS_ACTIVE_SHIFT               22
/* TIMER0 Bit Fields */
#define USBDCD_TIMER0_TUNITCON_MASK              0xFFFu
#define USBDCD_TIMER0_TUNITCON_SHIFT             0
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_define USB0_ENDPT11                             USB_ENDPT_REG(USB0_BASE_PTR,11)
#define USB0_ENDPT12                             USB_ENDPT_REG(USB0_BASE_PTR,12)
#define USB0_ENDPT13                             USB_ENDPT_REG(USB0_BASE_PTR,13)
#define USB0_ENDPT14                             USB_ENDPT_REG(USB0_BASE_PTR,14)
#define USB0_ENDPT15                             USB_ENDPT_REG(USB0_BASE_PTR,15)
#define USB0_USBCTRL                             USB_USBCTRL_REG(USB0_BASE_PTR)
#define USB0_OBSERVE                             USB_OBSERVE_REG(USB0_BASE_PTR)
#define USB0_CONTROL                             USB_CONTROL_REG(USB0_BASE_PTR)
#define USB0_USBTRC0                             USB_USBTRC0_REG(USB0_BASE_PTR)
#define USB0_USBFRMADJUST                        USB_USBFRMADJUST_REG(USB0_BASE_PTR)

/* USB - Register array accessors */
#define USB0_ENDPT(index)                        USB_ENDPT_REG(USB0_BASE_PTR,index)

/**
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USB_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBDCD
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Peripheral USBDCD
 * @{
 */

/** USBDCD - Peripheral register structure */
typedef struct USBDCD_MemMap {
  uint32_t CONTROL;                                /**< Control register, offset: 0x0 */
  uint32_t CLOCK;                                  /**< Clock register, offset: 0x4 */
  uint32_t STATUS;                                 /**< Status register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t TIMER0;                                 /**< TIMER0 register, offset: 0x10 */
  uint32_t TIMER1;                                 /**< TIMER1 register, offset: 0x14 */
  uint32_t TIMER2;                                 /**< TIMER2 register, offset: 0x18 */
} volatile *USBDCD_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros
 * @{
 */


/* USBDCD - Register accessors */
#define USBDCD_CONTROL_REG(base)                 ((base)->CONTROL)
#define USBDCD_CLOCK_REG(base)                   ((base)->CLOCK)
#define USBDCD_STATUS_REG(base)                  ((base)->STATUS)
#define USBDCD_TIMER0_REG(base)                  ((base)->TIMER0)
#define USBDCD_TIMER1_REG(base)                  ((base)->TIMER1)
#define USBDCD_TIMER2_REG(base)                  ((base)->TIMER2)

/**
 * @}
 */ /* end of group USBDCD_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Masks USBDCD Register Masks
 * @{
 */

/* CONTROL Bit Fields */
#define USBDCD_CONTROL_IACK_MASK                 0x1u
#define USBDCD_CONTROL_IACK_SHIFT                0
#define USBDCD_CONTROL_IF_MASK                   0x100u
#define USBDCD_CONTROL_IF_SHIFT                  8
#define USBDCD_CONTROL_IE_MASK                   0x10000u
#define USBDCD_CONTROL_IE_SHIFT                  16
#define USBDCD_CONTROL_START_MASK                0x1000000u
#define USBDCD_CONTROL_START_SHIFT               24
#define USBDCD_CONTROL_SR_MASK                   0x2000000u
#define USBDCD_CONTROL_SR_SHIFT                  25
/* CLOCK Bit Fields */
#define USBDCD_CLOCK_CLOCK_UNIT_MASK             0x1u
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            0
#define USBDCD_CLOCK_CLOCK_SPEED_MASK            0xFFCu
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           2
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_CLOCK_CLOCK_SPEED_SHIFT))&USBDCD_CLOCK_CLOCK_SPEED_MASK)
/* STATUS Bit Fields */
#define USBDCD_STATUS_SEQ_RES_MASK               0x30000u
#define USBDCD_STATUS_SEQ_RES_SHIFT              16
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_RES_SHIFT))&USBDCD_STATUS_SEQ_RES_MASK)
#define USBDCD_STATUS_SEQ_STAT_MASK              0xC0000u
#define USBDCD_STATUS_SEQ_STAT_SHIFT             18
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_STAT_SHIFT))&USBDCD_STATUS_SEQ_STAT_MASK)
#define USBDCD_STATUS_ERR_MASK                   0x100000u
#define USBDCD_STATUS_ERR_SHIFT                  20
#define USBDCD_STATUS_TO_MASK                    0x200000u
#define USBDCD_STATUS_TO_SHIFT                   21
#define USBDCD_STATUS_ACTIVE_MASK                0x400000u
#define USBDCD_STATUS_ACTIVE_SHIFT               22
/* TIMER0 Bit Fields */
#define USBDCD_TIMER0_TUNITCON_MASK              0xFFFu
#define USBDCD_TIMER0_TUNITCON_SHIFT             0
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TUNITCON_SHIFT))&USBDCD_TIMER0_TUNITCON_MASK)
#define USBDCD_TIMER0_TSEQ_INIT_MASK             0x3FF0000u
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            16
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TSEQ_INIT_SHIFT))&USBDCD_TIMER0_TSEQ_INIT_MASK)
/* TIMER1 Bit Fields */
#define USBDCD_TIMER1_TVDPSRC_ON_MASK            0x3FFu
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           0
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TVDPSRC_ON_SHIFT))&USBDCD_TIMER1_TVDPSRC_ON_MASK)
#define USBDCD_TIMER1_TDCD_DBNC_MASK             0x3FF0000u
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            16
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TDCD_DBNC_SHIFT))&USBDCD_TIMER1_TDCD_DBNC_MASK)
/* TIMER2 Bit Fields */
#define USBDCD_TIMER2_CHECK_DM_MASK              0xFu
#define USBDCD_TIMER2_CHECK_DM_SHIFT             0
#define USBDCD_TIMER2_CHECK_DM(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_CHECK_DM_SHIFT))&USBDCD_TIMER2_CHECK_DM_MASK)
#define USBDCD_TIMER2_TVDPSRC_CON_MASK           0x3FF0000u
#define USBDCD_TIMER2_TVDPSRC_CON_SHIFT          16
#define USBDCD_TIMER2_TVDPSRC_CON(x)             (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_TVDPSRC_CON_SHIFT))&USBDCD_TIMER2_TVDPSRC_CON_MASK)

/**
 * @}
 */ /* end of group USBDCD_Register_Masks */


/* USBDCD - Peripheral instance base addresses */
/** Peripheral USBDCD base pointer */
#define USBDCD_BASE_PTR                          ((USBDCD_MemMapPtr)0x40035000u)
/** Array initializer of USBDCD peripheral base pointers */
#define USBDCD_BASE_PTRS                         { USBDCD_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor m�cros
 * @{
 */
M
M�/* USBDCD - Register instance def�nitions *'
/* USBDCD */
#define USBDCD_�ONTROL                           USBDAD_CO�TROL_REG(USBDCD_JASD_PTR)
#defife UScDCD_CLOCG             �`      �    �  USBDAD_CLOCKREG(USBDCD_BASE_PTR)
#define USBDCD_STATUS       "       (            USBDCD_STATUS_REG(USBDCD_BASE_PTR)
#defija USBDCD_TIMER0                          � USBDCD�UAMER0_REG(USBDCD_BASE_PTR)	
#defioe UBDCD_TIMER1 ! !                    �   USBDCD_TIMER1_ReG(USBDCD_BASE_P�R)
#defind USBDCD_TILER2                            USBDCD_TMMER2_REG(�SBDCD_BASE_PTR)

/**
 * @}
 */ /* end of!group USBDCD_Register_Accessor_Macros */


/**
 * @}
 */ /* ene Of grouP USBDCD_Peripheral */


/* --------------------------/--------------------------)----------------------
   -- VRE�*   ----------------)-m----------------------------------=------------------- :/

/**
 * @addfogpou� FREF_Tdripheral VREB
 * @{
 */

/** VREF % Peripheral regisTer struct5re */
typedef struct VREFOMemMap {
  uift8_t TRM;                       (        8    /**< VREF"Trim`Se'ister, �ffset; 4y0 */
  uint8_t SC;     `       "      `      0         (#**< VREF Status ant Control Vegister, offset: 0x1 */
} volatile *VREF_MemMap@tr;

/* --------�------------------------)----m---------------------)-------�-------   -- VREF - Reister acaessor lacros
   --------�-------------------/.---------------,------------------------------ */

/**
 * @a�dogroep VREF_Begister_Accessor[Macros VREF - Re�ister`accessor m�cros
 j @{
 */


/* VREF - Register acce�sors */
#defineaVREF_TRM_REG(base)            "        ` ((base)->TRE)
#$efinu VREF_SC_REG(bas�)                        ((base)->SC)

/**
 * @} */ /* end of �roup VRAF_Register_Acce;sor_Macros */*

/* ------------------------------------------------%--------------------------
  0-� VRE Regisder Masks
   -----------=------------------------------m-------------�---------=------ */

/**
 * @addtogroup VREF_Register_MaSks VREF R%gaster Masks
 * @{
 */

/* TRM Bit Fields */
#define VREF_TRM_TRIM_MASK                       0x3Fu
#define VREF_TRM_TRIM_SHIFT                      0
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK)
#define VREF_TRM_CHOPEN_MASK                     0x40u
#define VREF_TRM_CHOPEN_SHIFT                    6
/* SC Bit Fields */
#define VREF_SC_MODE_LV_MASK                     0x3u
#define VREF_SC_MODE_LV_SHIFT                    0
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK)
#define VREF_SC_VREFST_MASK                      0x4u
#define VREF_SC_VREFST_SHIFT                     2
#define VREF_SC_ICOMPEN_MASK                     0x20u
#define VREF_SC_ICOMPEN_SHIFT                    5
#define VREF_SC_REGEN_MASK                       0x40u
#define VREF_SC_REGEN_SHIFT                      6
#define VREF_SC_VREFEN_MASK                      0x80u
#define VREF_SC_VRDFEN_SHIFT  0                  7

/**
 * @}
 */ '* end of grnup VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/** Peripheral ^REF base poiNter */
#define VREB_BAE_PTR    $                 `     ((VREF_MemMapPtv)0x40074000u)
?�* Array initializer of VREF peripheral basu pointers */
#defIne VREF_BASE_PTRS                           { VREF_BASE_PTR }

/: ---------�--------�-m-----------------------------------m-------------------
   --!VWDF - Rdgistur accessor macros
   -------%--,---------------------�-------------------%---------------------- */
/**
 * @addtogrup VREF_Register_Accessor_MacRns VREF - Register acsessor macros
 * @{
 */


/* VREF - Register instance defknityons */
?* VRUF */	
#define VREF_TRM  �              (               VSEFWTRL_REG(VREF_BASE_PTR)
#define VREF_SC  `                  0  (     �   VREF_SB_REG(VREF_BCSE_QTR)

/**
 * @}
 */ /* end of group VREF_Register_Ac�essor_Macros */


/+*
 * @]
 */ /* end of grnup WREF_Peri`heral */


/* -----------------------------)�--------�---------------------------------/--   -- WDOG
   ----------------------------/-------------------------------------�--------- *'

/**
 * @addtogroup WDOG_Puripheral WDOG
 * @{ */

/** WDG - Peripheral register structure */
typedef struct WDOGMemMap {  uint16_t STBTRLH; $           "                  /
*< Watchdo� Status`�od Con4rol Regis4er High, offset: 0x0 */
  uint16_4 STCVRLL;                   �        "  �/**< Watchdog Status and Control Regiqter Low, offset: 0x2 */
  uint16_t TOWALH;                             �   /**< Watch�oe Time-out Value Registe� High, ofbset: Px4 */
  uind16_t TOVALL;            �         `          /**< Watchdog"Time-out Va�ue Register(Low, offset: 0x6 */-
  uint1�_t W�NH;   !        0                      /**< Watchdog Windo Register"High, offset 0x8 */
  uint16_t SINL;               (                   /**< Wetchdog Window Regisuer Low, offset: 0xA */
  uint16_t REFRESH;           "        $           /**< Watchdog ReFresh register,$offset: 0xC */
  uint1>_t UNLOCK;     `  �                       �/**< Gatchdog Unlock register, o&fset: 0xE */�  uint16_t�TMROUTH; (     �                0       /**< Watchdof Timmr Output Reoi3ter Hig�, offset: 0x10 */
  uint16_t TMROET�;         $                (     /**< Watahdog Timer Outpup Register Mow, offset: 0x1" */
  uint16_t RSTCNT;   (                 d           /**< Watchdog Reset Sount register, kffset: 0�14 *.
  uint16_t PRESC;                                  /**< Watch`og Prescaler register, offset: 0x16 
/} volatile *WDOG_MemMapPtr;

/* ---------------�----�----------)----------------/%----------�---------%--)--
   -- WDOG - Register accessor maCros
   -------------%-------%-------------=--------------/---------------------m-- */

/**
 * @addtogroup WDOG]Register_Accessob_Macros WDOG - Register accessor macros
 * �{
 */


/* WDOG - Register agcessors */
#define WDOG_STCTRLH_RAG(base)(                  ((base)->TCTRLH)
#define WDOG_STCTRLL_REG(b`se)0        "         ((base)->STCTRLM)
#define WDOG_TOVALH_REG(base)                    ((base)-?TOVALH)
�define GDOG_TOVALL_REG(base)                    ((base)->TOVALL)
#defind WDOF_WINH_REG(base)        !          �  ((base)->WINH)
#define WDOG__INL_R�G(base)                      ((bis%)->WINL)
#define WDGG_REFRECH_REG*base)    "     $        ((base)->REFRESH�
#defije WDOG_UNLOCK_REG(base)                !   ((base)->UNLOCK)
#define WDOG_TMROUT�_REG8base)                   �(base)->TMROUTH)
#dafine WTOG]TMROUTLWREG(base)                   ((base)-6TMROUTL)
#dafine WDOG_RSTNT_REG(base)                    )(baseh->RSTCNT)
#define WDOG_PREWC_REG("asg)                   0 ((base)->PRgSC)

/**
 *0@}
 */ .* end of group WDOG_Registur_Accessor_Macros */

/* -----------------=----)----------------------------------------,----------
 ! )- WDoG Register Masks
   --)----------------------------------------------------------------%-------- */

/**
 * @addtogroup`GDOG_Registe2_Masks �OG Register Ma�ks
 *"@{
 */

/* SVCTRLH Bit Fields */
#defhne WDOG_STCTRLH�WDOGEN_MASK(                0x1u
#define WDOG_STCTLH_WDOGENSHIFT            $   0
#tufine WDOG_STCTRLH_CLSRc_MASK     $           0x"u
#definE WDOO_STCTRLH_CLKSRC_SHIFT �              1
#define W@OG_[TCTRLH_IR�RSTEN_MASK               0x4u
#tefine0WDOG_STCTRLH_IRQRSTEN_SHIFT              2
#defin� WDOG_STCTRLH_WINENMASK          0       0x8u
#define WDOG_STCRLH_wINEN_SHIFT               � 3
#define WDOG_STCTZLH_ALLOWUPDATe_MASK            0x10u
define WDOG_RTCTRLH_ALLOWUTDATE_SHIFT           4
#$ef�ne WDOG_STCTRLH_DBGEN_MASK         $ �    $ 0x20u
#define WDOG_STCTR\H_DBGEJ_SHIFT           $     5
#define WDOG_STCTRLH_STOPEN_MASK     !           0x40u
#define WDOG_CTCTRLH_STMPEN_SHIFT   "            6
#define WOG_SUCTRLH_WAITEN_MISK              $  2x80u
#define WDOG_STCTRLH_WAITEN_SHIFT                7
#def)ne WDOG_STCTRMH_TESTWDOG_M�SK               0x400u
#define SDOG_STCTRL�_T�STWDO�_SHYFT              10
#define WDOG_STCTRLH_TESTSEL_MASK                0x800u
#define WDOG_STCTRLH_TESTSEL_SHIFT               11
#define WDOG_STCTRLH_BYTESEL_MASK                0x3000u
#define WDOG_STCTRLH_BYTESEL_SHIFT               12
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK)
#define WDOG_STCTRLH_DISTESTWDOG_MASK            0x4000u
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14
/* STCTRLL Bit Fields */
#define WDOG_STCTRLL_INTFLG_MASK                 0x8000u
#define WDOG_STCTRLL_INTFLG_SHIFT                15
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK)
/* REFRESH Bit Fields */
#define WDOG_REFRESH_WDOGREFRESH_MASK            0xFFFFu
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK)
/* UNLOCK Bit Fields */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              0xFFFFu
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK)
/* TMROUTH Bit Fields */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           0xFFFFu
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK)
/* TMROUTL Bit Fields */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            0xFFFFu
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK)
/* RSTCNT Bit Fields */
#define WDOG_RSTCNT_RSTCNT_MASK                  0xFFFFu
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK)
/* PRESC Bit Fields */
#define WDOG_PRESC_PRESCVAL_MASK                 0x700u
#define WDOG_PRESC_PRESCVAL_SHIFT                8
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK)

/**
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base pointer */
#define WDOG_BASE_PTR                            ((WDOG_MemMapPtr)0x40052000u)
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG */
#define WDOG_STCTRLH                             WDOG_STCTRLH_REG(WDOG_BASE_PTR)
#define WDOG_STCTRLL                             WDOG_STCTRLL_REG(WDOG_BASE_PTR)
#define WDOG_TOVALH                              WDOG_TOVALH_REG(WDOG_BASE_PTR)
#define WDOG_TOVALL                              WDOG_TOVALL_REG(WDOG_BASE_PTR)
#define WDOG_WINH                                WDOG_WINH_REG(WDOG_BASE_PTR)
#define WDOG_WINL                                WDOG_WINL_REG(WDOG_BASE_PTR)
#define WDOG_REFRESH                             WDOG_REFRESH_REG(WDOG_BASE_PTR)
#define WDOG_UNLOCK                              WDOG_UNLOCK_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTH                             WDOG_TMROUTH_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTL                             WDOG_TMROUTL_REG(WDOG_BASE_PTR)
#define WDOG_RSTCNT                              WDOG_RSTCNT_REG(WDOG_BASE_PTR)
#define WDOG_PRESC                               WDOG_PRESC_REG(WDOG_BASE_PTR)

/**
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group WDOG_Peripheral */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/**
 * @}
 */ /* end of group Peripheral_defines */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup Backward_Compatibility_Symbols Backward Compatibility
 * @{
 */

#define SDHC_WML_WRBRSTLEN_MASK                  This_symbol_has_been_deprecated
#define SDHC_WML_WRBRSTLEN_SHIFT                 This_symbol_has_been_deprecated
#define SDHC_WML_WRBRSTLEN(x)                    This_symbol_has_been_deprecated
#define CAN_IMASK2_REG(base)                     This_symbol_has_been_deprecated
#define CAN0_IMASK2                              This_symbol_has_been_deprecated
#define CAN1_IMASK2                              This_symbol_has_been_deprecated
#define CAN_IMASK2_BUFHM_MASK                    This_symbol_has_been_deprecated
#define CAN_IMASK2_BUFHM_SHIFT                   This_symbol_has_been_deprecated
#define CAN_IMASK2_BUFHM(x)                      This_symbol_has_been_deprecated
#define CAN_IFLAG2_REG(base)                     This_symbol_has_been_deprecated
#define CAN0_IFLAG2                              This_symbol_has_been_deprecated
#define CAN1_IFLAG2                              This_symbol_has_been_deprecated
#define CAN_IFLAG2_BUFHI_MASK                    This_symbol_has_been_deprecated
#define CAN_IFLAG2_BUFHI_SHIFT                   This_symbol_has_been_deprecated
#define CAN_IFLAG2_BUFHI(x)                      This_symbol_has_been_deprecated
#define DAC_DATL_DATA_MASK                       DAC_DATL_DATA0_MASK
#define DAC_DATL_DATA_SHIFT                      DAC_DATL_DATA0_SHIFT
#define DAC_DATL_DATA(x)                         DAC_DATL_DATA0(x)
#define DAC_DATH_DATA_MASK                       DAC_DATH_DATA1_MASK
#define DAC_DATH_DATA_SHIFT                      DAC_DATH_DATA1_SHIFT
#define DAC_DATH_DATA(x)                         DAC_DATH_DATA1(x)
#define MCG_S_LOLS0_MASK                         MCG_S_LOLS_MASK
#define MCG_S_LOLS0_SHIFT                        MCG_S_LOLS_SHIFT

/**
 * @}
 */ /* end of group Backward_Compatibility_Symbols */


#else /* #if !defined(MCU_MK20D10) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MCU_MK20D10) */

/* MK20D10.h, eof. */
