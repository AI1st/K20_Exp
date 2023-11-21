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

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0006u

/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (32u*((uint32_t)&(Reg) - (uint32_t)0x40000000u)) + (4u*((uint32_t)(Bit))))))

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                /**< Initial Stack Pointer */
  INT_Initial_Program_Counter  = 1,                /**< Initial Program Counter */
  INT_NMI                      = 2,                /**< Non-maskable Interrupt (NMI) */
  INT_Hard_Fault               = 3,                /**< Hard Fault */
  INT_Mem_Manage_Fault         = 4,                /**< MemManage Fault */
  INT_Bus_Fault                = 5,                /**< Bus Fault */
  INT_Usage_Fault              = 6,                /**< Usage Fault */
  INT_Reserved7                = 7,                /**< Reserved interrupt 7 */
  INT_Reserved8                = 8,                /**< Reserved interrupt 8 */
  INT_Reserved9                = 9,                /**< Reserved interrupt 9 */
  INT_Reserved10               = 10,               /**< Reserved interrupt 10 */
  INT_SVCall                   = 11,               /**< Supervisor call (SVCall) */
  INT_DebugMonitor             = 12,               /**< Debug Monitor */
  INT_Reserved13               = 13,               /**< Reserved interrupt 13 */
  INT_PendableSrvReq           = 14,               /**< Pendable request for system service (PendableSrvReq) */
  INT_SysTick                  = 15,               /**< SysTick Interrupt */
  INT_DMA0                     = 16,               /**< DMA Channel 0 Transfer Complete */
  INT_DMA1                     = 17,               /**< DMA Channel 1 Transfer Complete */
  INT_DMA2                     = 18,               /**< DMA Channel 2 Transfer Complete */
  INT_DMA3                     = 19,               /**< DMA Channel 3 Transfer Complete */
  INT_DMA4                     = 20,               /**< DMA Channel 4 Transfer Complete */
  INT_DMA5                     = 21,               /**< DMA Channel 5 Transfer Complete */
  INT_DMA6                     = 22,               /**< DMA Channel 6 Transfer Complete */
  INT_DMA7                     = 23,               /**< DMA Channel 7 Transfer Complete */
  INT_DMA8                     = 24,               /**< DMA Channel 8 Transfer Complete */
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
  INT_LVD_LVW                  = 36,               /**< Low Voltage Detect, Low Voltage Warning */
  INT_LLW                      = 37,               /**< Low Leakage Wakeup */
  INT_Watchdog                 = 38,               /**< WDOG Interrupt */
  INT_Reserved39               = 39,               /**< Reserved Interrupt 39 */
  INT_I2C0                     = 40,               /**< I2C0 interrupt */
  INT_I2C1                     = 41,               /**< I2C1 interrupt */
  INT_SPI0                     = 42,               /**< SPI0 Interrupt */
  INT_SPI1                     = 43,               /**< SPI1 Interrupt */
  INT_SPI2                     = 44,               /**< SPI2 Interrupt */
  INT_CAN0_ORed_Message_buffer = 45,               /**< CAN0 OR'd message buffers interrupt */
  INT_CAN0_Bus_Off             = 46,               /**< CAN0 bus off interrupt */
  INT_CAN0_Error               = 47,               /**< CAN0 error interrupt */
  INT_CAN0_Tx_Warning          = 48,               /**< CAN0 Tx warning interrupt */
  INT_CAN0_Rx_Warning          = 49,               /**< CAN0 Rx warning interrupt */
  INT_CAN0_Wake_Up             = 50,               /**< CAN0 wake up interrupt */
  INT_I2S0_Tx                  = 51,               /**< I2S0 transmit interrupt */
  INT_I2S0_Rx                  = 52,               /**< I2S0 receive interrupt */
  INT_CAN1_ORed_Message_buffer = 53,               /**< CAN1 OR'd message buffers interrupt */
  INT_CAN1_Bus_Off             = 54,               /**< CAN1 bus off interrupt */
  INT_CAN1_Error               = 55,               /**< CAN1 error interrupt */
  INT_CAN1_Tx_Warning          = 56,               /**< CAN1 Tx warning interrupt */
  INT_CAN1_Rx_Warning          = 57,               /**< CAN1 Rx warning interrupt */
  INT_CAN1_Wake_Up             = 58,               /**< CAN1 wake up interrupt */
  INT_Reserved59               = 59,               /**< Reserved interrupt 59 */
  INT_UART0_LON                = 60,               /**< UART0 LON interrupt */
  INT_UART0_RX_TX              = 61,               /**< UART0 Receive/Transmit interrupt */
  INT_UART0_ERR                = 62,               /**< UART0 Error interrupt */
  INT_UART1_RX_TX              = 63,               /**< UART1 Receive/Transmit interrupt */
  INT_UART1_ERR                = 64,               /**< UART1 Error interrupt */
  INT_UART2_RX_TX              = 65,               /**< UART2 Receive/Transmit interrupt */
  INT_UART2_ERR                = 66,               /**< UART2 Error interrupt */
  INT_UART3_RX_TX              = 67,               /**< UART3 Receive/Transmit interrupt */
  INT_UART3_ERR                = 68,               /**< UART3 Error interrupt */
  INT_UART4_RX_TX              = 69,               /**< UART4 Receive/Transmit interrupt */
  INT_UART4_ERR                = 70,               /**< UART4 Error interrupt */
  INT_UART5_RX_TX              = 71,               /**< UART5 Receive/Transmit interrupt */
  INT_UART5_ERR                = 72,               /**< UART5 Error interrupt */
  INT_ADC0                     = 73,               /**< ADC0 interrupt */
  INT_ADC1                     = 74,               /**< ADC1 interrupt */
  INT_CMP0                     = 75,               /**< CMP0 interrupt */
  INT_CMP1                     = 76,               /**< CMP1 interrupt */
  INT_CMP2                     = 77,               /**< CMP2 interrupt */
  INT_FTM0                     = 78,               /**< FTM0 fault, overflow and channels interrupt */
  INT_FTM1                     = 79,               /**< FTM1 fault, overflow and channels interrupt */
  INT_FTM2                     = 80,               /**< FTM2 fault, overflow and channels interrupt */
  INT_CMT                      = 81,               /**< CMT interrupt */
  INT_RTC                      = 82,               /**< RTC interrupt */
  INT_RTC_Seconds              = 83,               /**< RTC seconds interrupt */
  INT_PIT0                     = 84,               /**< PIT timer channel 0 interrupt */
  INT_PIT1                     = 85,               /**< PIT timer channel 1 interrupt */
  INT_PIT2                     = 86,               /**< PIT timer channel 2 interrupt */
  INT_PIT3                     = 87,               /**< PIT timer channel 3 interrupt */
  INT_PDB0                     = 88,               /**< PDB0 Interrupt */
  INT_USB0                     = 89,               /**< USB0 interrupt */
  INT_USBDCD                   = 90,               /**< USBDCD Interrupt */
  INT_Reserved91               = 91,               /**< Reserved interrupt 91 */
  INT_Reserved92               = 92,               /**< Reserved interrupt 92 */
  INT_Reserved93               = 93,               /**< Reserved interrupt 93 */
  INT_Reserved94               = 94,               /**< Reserved interrupt 94 */
  INT_Reserved95               = 95,               /**< Reserved interrupt 95 */
  INT_SDHC                     = 96,               /**< SDHC Interrupt */
  INT_DAC0                     = 97,               /**< DAC0 interrupt */
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
  INT_Reserved111              = 111,              /**< Reserved interrupt 111 */
  INT_Reserved112              = 112,              /**< Reserved interrupt 112 */
  INT_Reserved113              = 113,              /**< Reserved interrupt 113 */
  INT_Reserved114              = 114,              /**< Reserved interrupt 114 */
  INT_Reserved115              = 115,              /**< Reserved interrupt 115 */
  INT_Reserved116              = 116,              /**< Reserved interrupt 116 */
  INT_Reserved117              = 117,              /**< Reserved interrupt 117 */
  INT_Reserved118              = 118,              /**< Reserved interrupt 118 */
  INT_Reserved119              = 119               /**< Reserved interrupt 119 */
} IRQInterruptIndex;

/**
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Peripheral type defines
   ---------------------------------------------------------------------------- */

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
  uint32_t CLPD;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x34 */
  uint32_t CLPS;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x38 */
  uint32_t CLP4;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x3C */
  uint32_t CLP3;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x40 */
  uint32_t CLP2;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x44 */
  uint32_t CLP1;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x48 */
  uint32_t CLP0;                                   /**< ADC Plus-Side General Calibration Value Register, offset: 0x4C */
  uint32_t PGA;                                    /**< ADC PGA Register, offset: 0x50 */
  uint32_t CLMD;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x54 */
  uint32_t CLMS;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x58 */
  uint32_t CLM4;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x5C */
  uint32_t CLM3;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x60 */
  uint32_t CLM2;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x64 */
  uint32_t CLM1;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x68 */
  uint32_t CLM0;                                   /**< ADC Minus-Side General Calibration Value Register, offset: 0x6C */
} volatile *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
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
 * @addtogroup ADC_ºİs"ÆËú•Æ¾ˆË…IËàXÊÉ¬²J¶°u#¹*‰qëïùL‚¯–Ò`_Ó‚Û”Ï³i°*·Õ&Şò›”mQ'ÁTÚz6’â0iD-ö8ç@ !?ÚÃ]•Êø£ÿŒ0Cò†bBjîˆ“V³b2ØrUV)ºoN^Ô6E®³fŠ+^UPY@WŸúvIpè¾pğ\ğq¥]¼ŠÆ¦ïJhÉÄ\ÄLÏ"â<«"Pˆ/µ‹õICQ¸V©Èß-§d ÁXjâ>§ZÜ¿İc•ı•"†¼ò‘Fÿ˜étT„¯³ìLĞÃî¾ÛTZ­q÷º’]­Ó¾ÆBªkd‰½ìh±Qè@ô\>Øôx¨)™c%_·ÏQÖ{ÉVµëìÃ<J©€ºÎ¤!J]­ùt&ÏZÌğÚ ò*_	Úšºz€gæ^ÖÆÄ¢zVğ+Õ³t	Xi|ë/ş]ıĞôO_œ[-æÃ&…/åÆœ8Ùg*¹5gö9‰ÉIZ30. '•ªù÷rü¤ò‘Ç§2f™¿]Àõíµ¢-ÎÏv=êö®ØzŞ&È‘¨;~ÃÂı®è‡çOKMjÉ­!çê|ÃÚIå·£O¥õŠ?%Æá6¿&²Ê›?+úvQI,EÑÆkwË˜Ài·&ãÿ=HfŠQ[è‰ÀJ7Å5î	X‘éø–½wrCy¤ÚOş¿÷¢~%ŒèZš‰ñ”©vÒ|k†şå9EráÆY~% w9îôœ˜ğ‡˜Üí·ë‘u›¾X#òù€ıšĞ²3w6;‘Ú³—£š;p#Ÿ†bf…~½ıàÀd€Û4¾†Cş$©Ãï$ª~ÂÖñm.t€TËGf³J–ÍŒS+É¸bWjcJ âª ±ü]ÿÕ#ZrÁÈè¡jÌKˆ÷w±é~àÎLé8w¡°wŠxÖQ…ò*¹ô¼¸²“?¯/ùµÑÏaÉ‘‡	Lz>´êD±D9®Ûª‰.´F‡°C\°ˆ÷ú¬E'X°<£'¶y[@Æ
	ºÛ˜.î2ÆC.¸R{+42`_´’–nà°æDŠèïw6ÍŞ~í}¯¶`$Cğ!'šaJ+tÅdê$i™P¥Yş_ß”ÙÊd¤±¹1e®69 ÖËû‹Õ‘N£<–õ×NÀ$f°EoÙJ^LÀÎ>‹¢«.4Î7+JzE±.&’¼øoÄ;«s·ï T+­\7¥L*©ú}$¸²
oø“ãƒÆYûÉ¹càèÿÄÕ%ª
ëö	Q#Â9¡ı|ÎFŒéÌuøª£4Ì¾OÉN–Y·¡ĞÚ›ÒuTkäGVzzô?AÓÜûÓ?¥„P]¥ÃĞˆàßhZTµñÚÛG           (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     0x10u
#define ADC_CFG1_ADLSMP_SHIFT                    4
#define ADC_CFG1_ADIV_MASK                       0x60u
#define ADC_CFG1_ADIV_SHIFT                      5
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      0x80u
#define ADC_CFG1_ADLPC_SHIFT                     7
/* CFG2 Bit Fields */
#define ADC_CFG2_ADLSTS_MASK                     0x3u
#define ADC_CFG2_ADLSTS_SHIFT                    0
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      0x4u
#define ADC_CFG2_ADHSC_SHIFT                     2
#define ADC_CFG2_ADACKEN_MASK                    0x8u
#define ADC_CFG2_ADACKEN_SHIFT                   3
#define ADC_CFG2_MUXSEL_MASK                     0x10u
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
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       0x4u
#define ADC_SC2_DMAEN_SHIFT                      2
#define ADC_SC2_ACREN_MASK                       0x8u
#define ADC_SC2_ACREN_SHIFT                      3
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
/* SC3 Bit Fields */
#define ADC_SC3_AVGS_MASK                        0x3u
#define ADC_SC3_AVGS_SHIFT                       0
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        0x4u
#define ADC_SC3_AVGE_SHIFT                       2
#define ADC_SC3_ADCO_MASK                        0x8u
#define ADC_SC3_ADCO_SHIFT                       3
#define ADC_SC3_CALF_MASK                        0x40u
#define ADC_SC3_CALF_SHIFT                       6
#define ADC_SC3_CAL_MASK                         0x80u
#define ADC_SC3_CAL_SHIFT                        7
/* OFS Bit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFFu
#define ADC_OFS_OFS_SHIFT                        0
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK)
/* PG Bit Fields */
#define ADC_PG_PG_MASK                           0xFFFFu
#define ADC_PG_PG_SHIFT                          0
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK)
/* MG Bit Fields */
#define ADC_MG_MG_MASK                           0xFFFFu
#define ADC_MG_MG_SHIFT                          0
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK)
/* CLPD Bit Fields */
#define ADC_CLPD_CLPD_MASK                       0x3Fu
#define ADC_CLPD_CLPD_SHIFT                      0
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#define ADC_CLPS_CLPS_MASK                       0x3Fu
#define ADC_CLPS_CLPS_SHIFT                      0
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK)
/* CLP4 Bit Fields */
#define ADC_CLP4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK)
/* CLP3 Bit Fields */
#define ADC_CLP3_CLP3_MASK                       0x1FFu
#define ADC_CLP3_CLP3_SHIFT                      0
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Fields */
#define ADC_CLP2_CLP2_MASK                       0xFFu
#define ADC_CLP2_CLP2_SHIFT                      0
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK)
/* CLP1 Bit Fields */
#define ADC_CLP1_CLP1_MASK                       0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
#define ADC_CLP0_CLP0_MASK                       0x3Fu
#define ADC_CLP0_CLP0_SHIFT                      0
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK)
/* PGA Bit Fields */
#define ADC_PGA_PGAG_MASK                        0xF0000u
#define ADC_PGA_PGAG_SHIFT                       16
#define ADC_PGA_PGAG(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_PGA_PGAG_SHIFT))&ADC_PGA_PGAG_MASK)
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
#define ADC_CLM3_CLM3_MASK                       0x1FFu
#define ADC_CLM3_CLM3_SHIFT                      0
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK)
/* CLM2 Bit Fields */
#define ADC_CLM2_CLM2_MASK                       0xFFu
#define ADC_CLM2_CLM2_SHIFT                      0
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK)
/* CLM1 Bit Fields */
#define ADC_CLM1_CLM1_MASK                       0x7Fu
#define ADC_CLM1_CLM1_SHIFT                      0
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK)
/* CLM0 Bit Fields */
#define ADC_CLM0_CLM0_MASK                       0x3Fu
#define ADC_CLM0_CLM0_SHIFT                      0
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK)

/**
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base pointer */
#define ADC0_BASE_PTR                            ((ADC_MemMapPtr)0x4003B000u)
/** Peripheral ADC1 base pointer */
#define ADC1_BASE_PTR                            ((ADC_MemMapPtr)0x400BB000u)
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0_BASE_PTR, ADC1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC0 */
#define ADC0_SC1A                                ADC_SC1_REG(ADC0_BASE_PTR,0)
#define ADC0_SC1B                                ADC_SC1_REG(ADC0_BASE_PTR,1)
#define ADC0_CFG1                                ADC_CFG1_REG(ADC0_BASE_PTR)
#define ADC0_CFG2                                ADC_CFG2_REG(ADC0_BASE_PTR)
#define ADC0_RA                                  ADC_R_REG(ADC0_BASE_PTR,0)
#define ADC0_RB                                  ADC_R_REG(ADC0_BASE_PTR,1)
#define ADC0_CV1                                 ADC_CV1_REG(ADC0_BASE_PTR)
#define ADC0_CV2                                 ADC_CV2_REG(ADC0_BASE_PTR)
#define ADC0_SC2                                 ADC_SC2_REG(ADC0_BASE_PTR)
#define ADC0_SC3                                 ADC_SC3_REG(ADC0_BASE_PTR)
#define ADC0_OFS                                 ADC_OFS_REG(ADC0_BASE_PTR)
#define ADC0_PG                                  ADC_PG_REG(ADC0_BASE_PTR)
#define ADC0_MG                                  ADC_MG_REG(ADC0_BASE_PTR)
#define ADC0_CLPD                                ADC_CLPD_REG(ADC0_BASE_PTR)
#define ADC0_CLPS                                ADC_CLPS_REG(ADC0_BASE_PTR)
#define ADC0_CLP4                                ADC_CLP4_REG(ADC0_BASE_PTR)
#define ADC0_CLP3                                ADC_CLP3_REG(ADC0_BASE_PTR)
#define ADC0_CLP2                                ADC_CLP2_REG(ADC0_BASE_PTR)
#define ADC0_CLP1                                ADC_CLP1_REG(ADC0_BASE_PTR)
#define ADC0_CLP0                                ADC_CLP0_REG(ADC0_BASE_PTR)
#define ADC0_PGA                                 ADC_PGA_REG(ADC0_BASE_PTR)
#define ADC0_CLMD                                ADC_CLMD_REG(ADC0_BASE_PTR)
#define ADC0_CLMS                                ADC_CLMS_REG(ADC0_BASE_PTR)
#define ADC0_CLM4                                ADC_CLM4_REG(ADC0_BASE_PTR)
#define ADC0_CLM3                                ADC_CLM3_REG(ADC0_BASE_PTR)
#define ADC0_CLM2                                ADC_CLM2_REG(ADC0_BASE_PTR)
#define ADC0_CLM1                                ADC_CLM1_REG(ADC0_BASE_PTR)
#define ADC0_CLM0                                ADC_CLM0_REG(ADC0_BASE_PTR)
/* ADC1 */
#define ADC1_SC1A                                vÔaqNß èj
÷üZúó'8aÄ¸Şbñ¦:®\lù	ã6'9ùem…u¡©@ĞEàÆåLß K…Á™âwÃa°2Gk|ÚŞQ"5€˜ÖãP|•ùûı}I¿f³9uÅ/íú&3å“$.!G¨­ï¼Lo9—Lêà‰m
òû—2»`‡ß“#o!ãD{(;¼«n?Ú<¥OgUQG,\n4{ÁT¬ı ‘ôy-,Z­'4¡CMa iÌßm’ÚÕ¦%ÃE©Dƒ“ûÍªîã‰Wvlg¥UÁİÒL^Èdbîçü,P¼°Ş@6:$ËÖ=6ç¬â0MN°bIïá>©ÒõkÎ"Ïš¥^Íe;½¬ÔşñXV¡d-:íoüt%©ëœ)ÇÃğ9ì0}ğLe‚î0¯Ù…WXÌáîDöºŠ(h¶È½¿ti`Ş7Lûg†EÄ>‡˜‹H8ªïvò"cf|Íu57‹ñûšâöÖq¾èãÔmíÓ·n)5Svø’(°¦<8%vü&L7°^…ˆ ˆØÇ.>·X°Lq˜k¿¾pÒ»©®_I»µ¾©ûQç–?GCi"è•¬L¢pÌ_ºğÍa­?ú}ìŞ[,×eP%´q®ïO»PHZbt|±è&?~»J-Ë¨e‘Q'št¼Ó˜Œ6¸u¼©3Ûä{Œ¦#.¨eß(`2Ğª÷·µò·`nSa>
	İ±†ì
ÿzŸ%EŸÄ®ñÕ¯iWÛèä-*Ú5oµ–ÌmN–Mën®OÇPu¬)¦ìl-wáBƒÆĞ¾ı±ÃÙ1[†Š,½„ögxÎ;ÕñÍõ­…&”(£¨!p €")‹¬—ÔÿeÓ2KÁ´¹;0L,òPªµ0º€õå`æQ3ív6b-”bĞO»¾áX±2NpÙÇbxÂù,3¬§¬ºv¬.km„ıò+H±šx	í˜öû£‰0D	†N®¾HœÇ¨Ó &ãÍ82DÜ"K±è›\&+x¶öó½€_ë‹0¥L%€ƒ“—ËÜĞ_ıÈV1aœÕ~B
V“Ò”q-ÆÃ·
Ï-~¨YÙ„¹mG¿_ÿŒ+À\.zo· ”EÜŒj€6¥µUõŠ³ê:%0A¸Z•¾(ë[Ÿt˜.ıM<©ØÁTúïĞTšÅ.a:‹@X„ÆİŸëªâä6c7DVÎëåÁzO£5TŸ*›÷¿¬ÜÃ|(ÕZ¾¹éÜ©ÑnÛ#Z6“4¼V\Ô¼ìå
 ‘;ØU§úy’‰à]%ÚfÖŞ,kÅ­z°¹¡"†wÕ€ˆzHİ-Ø¹ºë“Ä‹·ASE_PTR)
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
#YdÚˆDlÃ-’Å¬DFSß^®@çEÂŸû3pÆú¡^¿ÏMwÇ
šx¨ºÃæs=Æ×J4AJÁÌP&çk.$[®:¦Á”Ùdë‹´Lí?0D²aûèpT†96?æÜ<cÎM“Pgk+/Íï³XW#–Ñ¬®=3Ÿy*©áİÇÍ™V§PìšÏ"*°¸eìšµîŞ²A9•å°o‹ˆPN“7+X”Š|öšTÈ#ÖìW"Mû³a¥E_…^Ğ1 «éÏFWSş?ã’«ŒÄgvCÌŒİ¡Îzï–şfPÓ|°mFof³6I«ëæÁyI˜bŸ‚œNBß~,îŒi81ƒ!«:QËìe&û~X¸IkùèSöXÁ,@û¶È~ıéØl}"«É($dËÁ§–RÛX¼uQOëÖl“J¯ìœyµf®Píù(4Q,
‹ó }°ÔîrÌšz_5±	­“•â­ÈL°£6Ç	asy‚L÷‹ş†wÄ
6H}Éß*Ñoé3Êí¿£Ş‚c›”g/cMh„S@[ã³”KîŒß­rj€•%¹õ—ÙÎÒšvƒ¤„œk¾‹¼­{‚&3ólÙ…`†òÖtÖÓ‚Î4R,xK¶Eı)1Ãñ,™(ë‘Í:ÜÂ]6±0bÎ ô8{a×Òx4Ç&<à˜m[ãNJµWœ™Û7>Q(rÃ`tì,Jû·»vf-k;oœ]§©üË‚‚[ËH„O"º£D“şºa\wóÌ½ŸxæŒÍTÆHK©Üo(n{<cò¨}#fŸ)Ñ&³eçJâ9#ê…°x§’0‘·ä[Ñı‡èÌ”¤a¥Ì…t<Ì}ñ/™˜7#mQ:jÍ\Æ·Ü\-[wWªĞV)_€ü•àÖÓ9Ê¤L¹ğ
O ØşšÁ/ŸX¬1eCjqlV¦Ê‰ğ*x"ÉMá«ygÄ§î·Ò½ü@;ÕüoYitÛ¬o•‚ÈËø”Îø€n›ÇÊˆ€91¾dU]Šú:-zåG~e(ÃÔ‘HÓ-a$aéqÖeßHJ[ı	>æxÊûçu£†`'*öÅ›±şÊ¹Vä3ˆlŠÙ³¬‡®è&Aé*>o3°'>„ıÂ{Ë}™ÿßÖ©d^õ«–D/­u²“à}™D%nSŒá¥Õ»ÿ¤²!Äó-ØsÓâİÖA«Wv<‚|àKšMíåîªÊ”·ŠÚœz¯e e˜Àí5àtàùl´ªĞhU,vcyÃOnÀi“MîSD$I½èy1éÊäH]­Ì¼*-1>2ƒœ°uà)ƒ«•ÖÃòi7J”/¬g.åRºèìTmËâSó¿~”ˆƒ;Eò4d®ş6\ë««U=ÄØ1çfw¾œ=BŒN¬Ïg-KrV8ğ S]ûÓÏ;/…ÉD#fî”?n‰ÈõP÷lÔ¥%C¯~Õ…P"Ô ÓéàëPÎÄ‚&ĞÁÇì§|È—»FÃ–Ya'çmZ`|@[V˜Á¡²ê°iïa½eˆ1ô‘çê2Pgü=U?åc@zÆØ »g8¸ÛôY/%ÇqŠ#Éø}-`óoBÊ™
Lä4¢à-¦$˜XR*ôUİŞ÷lo÷óìóÌğŸ'€à¦šYùÀû±–+Ê?&¥±øH9£ã~Xğ8Äâu¥h%‡Ñ¾`Û0a${S –ûò<é·yİ°0‚-Aiöod‘Ş|Ã•Üœ1ØVâš`2ÔÓ¬"¬uÃ¸†âÒ41 ´eü|êßLÎ0vŸ¦³Ú§L„ç·Ë:œœb_œ½ €z‡¨l.…¯ø³70¿¹eÙµğ*G±ù #–¥‡MUjØr<u«Ê7e£`¦¦xxoãO–>Æã\™Q\téûè";Ûâìú¦Ö-Õ MhE<ŸfÌ÷ëIZ†Ú¢Rx‘Tì“ÏI&^lŸª]a»(u4é.|ÿ¹ÜĞÈ8W’i¼ÚA“QM-\òOÚñ)ÌìP‡04Õy¼‹şœÙZO˜ïbªàe¥íiÊÃKœdÂï
íñFå§p3ÔÂ%fÃº¸ĞÌ¶Ì ŠÁÙF–·C3_Ù´ñ›·vâ†oÒaÛT´üÜv?ó¶Ï¶Ã¹/Áş?„M,vØÓ“”Cğ]ËÅ¨|[©8ÔqDJfÌScšô†,øÓ¦¬ªqÑT	w8èuÈÈÓØ‹Lb;éŸ¹S¥Ï›Y£›!]¤ë‹P¾*ötR`úƒ
>.&V‡Ÿ„àÀTH;ÀòT½ÑÖœQîV©o(¿Ô„¨ùXÍüŠ‚³à}¨:ÂÏÃ/1|güáÀªŸÚÉu´ãî{¾I™ÈiÀ§VëÑş›ãåX}ô+FóÊåê‰N2×ñ¤]ÛÖvEæpÍtc«ÛC¬-ò™l®qÜ°³¹$º¬L]€ˆªÜèïK†G®§™^Iê¼!/Û‚RtƒIaµi[]õS­™<€[wÚŞB§ÇI HÜŸwh²:õ£ns@8~„Ğuˆq¦)ãt'‡1Ÿ’½-áüNfH:!MKĞÏš*¸œ‘ÒóG$¸/µ3Ğ¤2å ×ü^‚ïôùCã“ìãq@n—pRÄÊå-9@ò!Ùı²BG½¯                    /**< Peripheral Access Control Register, offset: 0x54 */
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
 * @addtogroup AIPS_Register_Accessor_Macros AIPS vÔaqNß èj
÷üZúó'8aÄ¸Şbñ¦:®\lù	ã6'9ùem…u¡©@ĞEàÆåLß K…Á™âwÃa°2Gk|ÚŞQ"5€˜ÖãP|•ùûı}I¿f³9uÅ/íú&3å“$.!G¨­ï¼Lo9—Lêà‰m
òû—2»`‡ß“#o!ãD{(;¼«n?Ú<¥OgUQG,\n4{ÁT¬ı ‘ôy-,Z­'4¡CMa iÌßm’ÚÕ¦%ÃE©Dƒ“ûÍªîã‰Wvlg¥UÁİÒL^Èdbîçü,P¼°Ş@6:$ËÖ=6ç¬â0MN°bIïá>©ÒõkÎ"Ïš¥^Íe;½¬ÔşñXV¡d-:íoüt%©ëœ)ÇÃğ9ì0}ğLe‚î0¯Ù…WXÌáîDöºŠ(h¶È½¿ti`Ş7Lûg†EÄ>‡˜‹H8ªïvò"cf|Íu57‹ñûšâöÖq¾èãÔmíÓ·n)5Svø’(°¦<8%vü&L7°^…ˆ ˆØÇ.>·X°Lq˜k¿¾pÒ»©®_I»µ¾©ûQç–?GCi"è•¬L¢pÌ_ºğÍa­?ú}ìŞ[,×eP%´q®ïO»PHZbt|±è&?~»J-Ë¨e‘Q'št¼Ó˜Œ6¸u¼©3Ûä{Œ¦#.¨eß(`2Ğª÷·µò·`nSa>
	İ±†ì
ÿzŸ%EŸÄ®ñÕ¯iWÛèä-*Ú5oµ–ÌmN–Mën®OÇPu¬)¦ìl-wáBƒÆĞ¾ı±ÃÙ1[†Š,½„ögxÎ;ÕñÍõ­…&”(£¨!p €")‹¬—ÔÿeÓ2KÁ´¹;0L,òPªµ0º€õå`æQ3ív6b-”bĞO»¾áX±2NpÙÇbxÂù,3¬§¬ºv¬.km„ıò+H±šx	í˜öû£‰0D	†N®¾HœÇ¨Ó &ãÍ82DÜ"K±è›\&+x¶öó½€_ë‹0¥L%€ƒ“—ËÜĞ_ıÈV1aœÕ~B
V“Ò”q-ÆÃ·
Ï-~¨YÙ„¹mG¿_ÿŒ+À\.zo· ”EÜŒj€6¥µUõŠ³ê:%0A¸Z•¾(ë[Ÿt˜.ıM<©ØÁTúïĞTšÅ.a:‹@X„ÆİŸëªâä6c7DVÎëåÁzO£5TŸ*›÷¿¬ÜÃ|(ÕZ¾¹éÜ©ÑnÛ#Z6“4¼V\Ô¼ìå
 ‘;ØU§úy’‰à]%ÚfÖŞ,kÅ­z°¹¡"†wÕ€ˆzHİ-Ø¹ºë“Ä‹·ase)                     ((base)->PACRN)
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
#define AIPS_MPRA_MTW4_MASK                    õ“éü>Œ«Z¥n#8"´J¿:à¡•¨·­«“ï_£'Ğ2'Gµ«Gù8µŸ‡e¯”uİ>>ñ"\½2“b‹&`Ï§GZM17ZÍ!İ*´ìû_`*¦íÀ¸éÓıÚ2l£çšÂˆÒP]Ş°²H¨ixsE)%<4na è™Z«Î"†ÙÖ»÷!
;ÖÉ§ä-%»ßÁ¶p¹êÑN¤@hÌºhŸ=^†º"8cz³ŸĞšXş5J1@ÈOÊHJå0*:{¯5£™2…¡kK¿ äŠ«ªô+'F÷•ô¸ÍC1²¤°½-„¾.ÒùÀÓİá±¯±jb0W_,Â®ı*Ìd†¬8k@¦¶²§ƒìN¨¿£‹ånó\ÛEja.Ô
x0#ÓÆá?<ü‡AÙÌBúK; l†Ë“¤Ú•S¨¹1GÌprwƒúmşjS˜=©EÓá•XîS‰Ê<Bx·¯»\Jãå şş€# >\w¤Œ	¡áGõo‹ı[oR*Œg}yÁ¹ÊhA/âÎè3¤Ñ ¤ù	Â˜v
v—ßüÓæ!4bÃïÁœa^'ë*f·êŠ=@øC¨t¤åÓÓã;»øœ‚ûVõQ,ÆÔ±t1Tà­—2ö^)BçŸ^‰¤„!”Pf5¡Y€˜HC!…Æ{h¬©âùR;,~ªéä~×¥Pø&5šîÒöF‰>×OCµ$ïbŒ‘&CFZ6y¸V*¶ñtkeÌz…Ãªİë
„ˆIçI÷å	gZ¶³ÕrÆx5ÛnAŸA6GŒ )¸õ¿ƒ#å3ÜŒÌ¸B´€¹şâpù¸àEÈïgü!NãE›¦à{Ö•×­	HÈÕÚD‡o»ÈjÒ÷Ÿ¿0Ù;aœOÜè0Ä»4’)b 2tP¯·ºÆé)ê
ÌE‘îvjÇ;¦¶=Q“jĞñ‹:0äŸù/L†ø‡}„qc¦û(ìùT~Jæ ÃíÕÙ“+@ƒê,t¬vcËQº”÷Ñ}ê¶‘î½2nútE8©d-HE¹ÈL¬Ü˜Ïn"‘¢,¹¿ùE P
yÑÉ¤DxæFbHˆÇ8¦ŒÆÑ_&æ”rìº•+jïzHH¹<¶Ş\8şxÄğ‰¬2€6Øìet°/ÜKõ€ÃúÌ=¯êÊG—ö°¶¤ Æ—YÈà"<\¯f|-ÀráWÈ§–½¡:Ëõ/›QN$Ğ†ºø›ãN7åãÅP%±2›NPeäÜ8‹<WXÃH©û‚!"á6Z3Z-Üm”üùÓü¯™F)ë×µÅN¼f¯3ZğÆ˜*’g¹HlàcÇ6Dsèµ¥!«»¾-zÚÎœu O
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
#define AIPS_PACRC_SP4_MASK                      0x400°u
#define AIPS_PACRC_SP4_SHIFT                     14
#Define AIPS_PACRC_ĞP3_MASK     `          !     0x10000u
#define AIPS_PACRC_TP3_SHIFT            (        ±6
#define AIPS_PACRC_WP3_MASK                      0x20000u
#define$AIPS_PACRC_WP2_SHIFT     "     0         17
#define AIPS_PACRC_SP3_MASK                   " 0x40000u
#define EIPS_PACRC_SP3_SHIFT                     18Š#defIne AIPS_PACRS_TP2_MASK                      0xq00000u
#`agind AIPS_PACRC_TP2_SHIFT                     20
#define AIPS_PACRÃ_WP2_MASK (                    ø200002u
#define AIPS_PACRC_WP2_SHIFT"      (             21
#define"AIPS_PaCRC_SP2_MASK                      0x400000u
define AIPS_ĞACRC_Sp2_SHIFT"            *       22
#define AIPs_PACRC_TP1_MASK      ! 0 $           0ø1008000u
#define AIPS_PACRC_TP1_SHIfT                     ²4
#define AIPSP@CRC_WP1_MASK                !     0x204000u
#define AIPS_PACRC_WP1_SHIFT       $0            25
#defile AIPS_PACRC_SP1MASK      "               0x4000000u
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
#define AIPS_PACRF_TP6_MASK                      0x10u
#define AIPS_PACRF_TP6_SHIFT                     4
#define AIPS_PACRF_WP6_MASK                      0x20u
#define AIPS_PACRF_WP6_SHIFT                     5
#define AIPS_PACRF_SP6_MASK                      0x40u
#define AIPS_PACRF_SP6_SHIFT                     6
#define AIPS_PACRF_TP5_MASK                      0x100u
#define AIPS_PACRF_TP5_SHIFT                     8
#define AIPS_PACRF_WP5_MASK                      0x200u
#define AIPS_PACRF_WP5_SHIFT                     9
#define AIPS_PACRF_SP5_MASK                      0x400u
#define AIPS_PACRF_SP5_SHIFT                     10
#define AIPS_PACRF_TP4_MASK                      0x1000u
#define AIPS_PACRF_TP4_SHIFT                     12
#define AIPS_PACRF_WP4_MASK                      0x2000u
#define AIPS_PACRF_WP4_SHIFT                     13
#define AIPS_PACRF_SP4_MASK                      0x4000u
#define AIPS_PACRF_SP4_SHIFT                     14
#define AIPS_PACRF_TP3_MASK                      0x10000u
#define AIPS_PACRF_TP3_SHIFT                     16
#define AIPS_PACRF_WP3_MASK                      0x20000u
#define AIPS_PACRF_WP3_SHIFT                     17
#define AIPS_PACRF_SP3_MASK                      0x40000u
#define AIPS_PACRF_SP3_SHIFT                     18
#define AIPS_PACRF_TP2_MASK                      0x100000u
#define AIPS_PACRF_TP2_SHIFT                     20
#define AIPS_PACRF_WP2_MASK                      0x200000u
#define AIPS_PACRF_WP2_SHIFT                     21
#define AIPS_PACRF_SP2_MASK                      0x400000u
#define AIPS_PACRF_SP2_SHIFT                     22
#define AIPS_PACRF_TP1_MASK                      0x1000000u
#define AIPS_PACRF_TP1_SHIFT                     24
#define AIPS_PACRF_WP1_MASK                      0x2000000u
#define AIPS_PACRF_WP1_SHIFT                     25
#define AIPS_PACRF_SP1_MASK                      0x4000000u
#define AIPS_PACRF_SP1_SHIFT                     26
#define AIPS_PACRF_TP0_MASK                      0x10000000u
#define AIPS_PACRF_TP0_SHIFT                     28
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
#define AIPS_PACRG_TP2_SHIFT                     20
#define AIPS_PACRG_WP2_MASK                      0x200000u
#define AIPS_PACRG_WP2_SHIFT                     21
#define AIPS_PACRG_SP2_MASK                      0x400000u
#define AIPS_PACRG_SP2_SHIFT                     22
#define AIPS_PACRG_TP1_MASK                      0x1000000u
#define AIPS_PACRG_TP1_SHIFT                     24
#define AIPS_PACRG_WP1_MASK                      0x2000000u
#define AIPS_PACRG_WP1_SHIFT                     25
#define AIPS_PACRG_SP1_MASK                      0x4000000u
#define AIPS_PACRG_SP1_SHIFT                     26
#define AIPS_PACRG_TP0_MASK                      0x10000000u
#define AIPS_PACRG_TP0_SHIFT                     28
#define AIPS_PACRG_WP0_MASK                      0x20000000u
#define AIPS_PACRG_WP0_SHIFT                     29
#define AIPS_PACRG_SP0_MASK                      0x40000000u
#define AIPS_PACRG_SP0_SHIFT                     30
/* PACRH Bit Fields */
#define AIPS_PACRH_TP7_MASK                      0x1u
#define AIPS_PACRH_TP7_SHIFT                     0
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
#define AIPS_PACRI_WP6_MASK                      0x20u
#define AIPS_PACRI_WP6_SHIFT                     5
#define AIPS_PACRI_SP6_MASK                      0x40u
#define AIPS_PACRI_SP6_SHIFT                     6
#define AIPS_PACRI_TP5_MASK                      0x100u
#define AIPS_PACRI_TP5_SHIFT                     8
#define AIPS_PACRI_WP5_MASK                      0x200u
#define AIPS_PACRI_WP5_SHIFT                     9
#define AIPS_PACRI_SP5_MASK                      0x400u
#define AIPS_PACRI_SP5_SHIFT                     10
#define AIPS_PACRI_TP4_MASK                      0x1000u
#define AIPS_PACRI_TP4_SHIFT                     12
#define AIPS_PACRI_WP4_MASK                      0x2000u
#define AIPS_PACRI_WP4_SHIFT                     13
#define AIPS_PACRI_SP4_MASK                      0x4000u
#define AIPS_PACRI_SP4_SHIFT                     14
#define AIPS_PACRI_TP3_MASK                      0x10000u
#define AIPS_PACRI_TP3_SHIFT                     16
#define AIPS_PACRI_WP3_MASK                      0x20000u
#define AIPS_PACRI_WP3_SHIFT                     17
#define AIPS_PACRI_SP3_MASK                      0x40000u
#define AIPS_PACRI_SP3_SHIFT                     18
#define AIPS_PACRI_TP2_MASK                      0x100000u
#define AIPS_PACRI_TP2_SHIFT                     20
#define AIPS_PACRI_WP2_MASK                      0x200000u
#define AIPS_PACRI_WP2_SHIFT                     21
#define AIPS_PACRI_SP2_MASK                      0x400000u
#define AIPS_PACRI_SP2_SHIFT                     22
#define AIPS_PACRI_TP1_MASK                      0x1000000u
#define AIPS_PACRI_TP1_SHIFT                     24
#define AIPS_PACRI_WP1_MASK                      0x2000000u
#define AIPS_PACRI_WP1_SHIFT                     25
#define AIPS_PACRI_SP1_MASK                      0x4000000u
#define AIPS_PACRI_SP1_SHIFT                     26
#define AIPS_PACRI_TP0_MASK                      0x10000000u
#define AIPS_PACRI_TP0_SHIFT                     28
#define AIPS_PACRI_WP0_MASK                      0x20000000u
#define AIPS_PACRI_WP0_SHIFT                     29
#define AIPS_PACRI_SP0_MASK                      0x40000000u
#define AIPS_PACRI_SP0_SHIFT                     30
/* PACRJ Bit Fields */
#define AIPS_PACRJ_TP7_MASK                      0x1u
#define AIPS_PACRJ_TP7_SHIFT                     0
#define AIPS_PACRJ_WP7_MASK                      0x2u
#define AIPS_PACRJ_WP7_SHIFT                     1
#define AIPS_PACRJ_SP7_MASK                      0x4u
#define AIPS_PACRJ_SP7_SHIFT                     2
#define AIPS_PACRJ_TP6_MASK                      0x10u
#define AIPS_PACRJ_TP6_SHIFT                     4
#define AIPS_PACRJ_WP6_MASK                      0x20u
#define AIPS_PACRJ_WP6_SHIFT                     5
#define AIPS_PACRJ_SP6_MASK                      0x40u
#define AIPS_PACRJ_SP6_SHIFT                     6
#define AIPS_PACRJ_TP5_MASK                      0x100u
#define AIPS_PACRJ_TP5_SHIFT                     8
#define AIPS_PACRJ_WP5_MASK                      0x200u
#define AIPS_PACRJ_WP5_SHIFT                     9
#define AIPS_PACRJ_SP5_MASK                      0x400u
#define AIPS_PACRJ_SP5_SHIFT                     10
#define AIPS_PACRJ_TP4_MASK                      0x1000u
#define AIPS_PACRJ_TP4_SHIFT                     12
#define AIPS_PACRJ_WP4_MASK                      0x2000u
#define AIPS_PACRJ_WP4_SHIFT                     13
#define AIPS_PACRJ_SP4_MASK                      0x4000u
#define AIPS_PACRJ_SP4_SHIFT                     14
#define AIPS_PACRJ_TP3_MASK                      0x10000u
#define AIPS_PACRJ_TP3_SHIFT                     16
#define AIPS_PACRJ_WP3_MASK                      0x20000u
#define AIPS_PACRJ_WP3_SHIFT                     17
#define AIPS_PACRJ_SP3_MASK                      0x40000u
#define AIPS_PACRJ_SP3_SHIFT                     18
#define AIPS_PACRJ_TP2_MASK                      0x100000u
#define AIPS_PACRJ_TP2_SHIFT                     20
#define AIPS_PACRJ_WP2_MASK                      0x200000u
#define AIPS_PACRJ_WP2_SHIFT                     21
#define AIPS_PACRJ_SP2_MASK                      0x400000u
#define AIPS_PACRJ_SP2_SHIFT                     22
#define AIPS_PACRJ_TP1_MASK                      0x1000000u
#define AIPS_PACRJ_TP1_SHIFT                     24
#define AIPS_PACRJ_WP1_MASK                      0x2000000u
#define AIPS_PACRJ_WP1_SHIFT                     25
#define AIPS_PACRJ_SP1_MASK                      0x4000000u
#define AIPS_PACRJ_SP1_SHIFT                     26
#define AIPS_PACRJ_TP0_MASK                      0x10000000u
#define AIPS_PACRJ_TP0_SHIFT                     28
#define AIPS_PACRJ_WP0_MASK                      0x20000000u
#define AIPS_PACRJ_WP0_SHIFT                     29
#define AIPS_PACRJ_SP0_MASK                      0x40000000u
#define AIPS_PACRJ_SP0_SHIFT                     30
/* PACRK Bit Fields */
#define AIPS_PACRK_TP7_MASK                      0x1u
#define AIPS_PACRK_TP7_SHIFT                     0
#define AIPS_PACRK_WP7_MASK                      0x2u
#define AIPS_PACRK_WP7_SHIFT                     1
#define AIPS_PACRK_SP7_MASK                      0x4u
#define AIPS_PACRK_SP7_SHIFT                     2
#define AIPS_PACRK_TP6_MASK                      0x10u
#define AIPS_PACRK_TP6_SHIFT                     4
#define AIPS_PACRK_WP6_MASK                      0x20u
#define AIPS_PACRK_WP6_SHIFT                     5
#define AIPS_PACRK_SP6_MASK                      0x40u
#define AIPS_PACRK_SP6_SHIFT                     6
#define AIPS_PACRK_TP5_MASK                      0x100u
#define AIPS_PACRK_TP5_SHIFT                     8
#define AIPS_PACRK_WP5_MASK                      0x200u
#define AIPS_PACRK_WP5_SHIFT                     9
#define AIPS_PACRK_SP5_MASK                      0x400u
#define AIPS_PACRK_SP5_SHIFT                     10
#define AIPS_PACRK_TP4_MASK                      0x1000u
#define AIPS_PACRK_TP4_SHIFT                     12
#define AIPS_PACRK_WP4_MASK                      0x2000u
#define AIPS_PACRK_WP4_SHIFT                     13
#define AIPS_PACRK_SP4_MASK                      0x4000u
#define AIPS_PACRK_SP4_SHIFT                     14
#define AIPS_PACRK_TP3_MASK                      0x10000u
#define AIPS_PACRK_TP3_SHIFT                     16
#define AIPS_PACRK_WP3_MASK                      0x20000u
#define AIPS_PACRK_WP3_SHIFT                     17
#define AIPS_PACRK_SP3_MASK                      0x40000u
#define AIPS_PACRK_SP3_SHIFT                     18
#define AIPS_PACRK_TP2_MASK                      0x100000u
#define AIPS_PACRK_TP2_SHIFT                     20
#define AIPS_PACRK_WP2_MASK                      0x200000u
#define AIPS_PACRK_WP2_SHIFT                     21
#define AIPS_PACRK_SP2_MASK                      0x400000u
#define AIPS_PACRK_SP2_SHIFT                     22
#define AIPS_PACRK_TP1_MASK                      0x1000000u
#define AIPS_PACRK_TP1_SHIFT                     24
#define AIPS_PACRK_WP1_MASK                      0x2000000u
#define AIPS_PACRK_WP1_SHIFT                     25
#define AIPS_PACRK_SP1_MASK                      0x4000000u
#define AIPS_PACRK_SP1_SHIFT                     26
#define AIPS_PACRK_TP0_MASK                      0x10000000u
#define AIPS_PACRK_TP0_SHIFT                     28
#define AIPS_PACRK_WP0_MASK                      0x20000000u
#define AIPS_PACRK_WP0_SHIFT                     29
#define AIPS_PACRK_SP0_MASK                      0x40000000u
#define AIPS_PACRK_SP0_SHIFT                     30
/* PACRL Bit Fields */
#define AIPS_PACRL_TP7_MASK                      0x1u
#define AIPS_PACRL_TP7_SHIFT                     0
#define AIPS_PACRL_WP7_MASK                      0x2u
#define AIPS_PACRL_WP7_SHIFT                     1
#define AIPS_PACRL_SP7_MASK                      0x4u
#define AIPS_PACRL_SP7_SHIFT                     2
#define AIPS_PACRL_TP6_MASK                      0x10u
#define AIPS_PACRL_TP6_SHIFT                     4
#define AIPS_PACRL_WP6_MASK                      0x20u
#define AIPS_PACRL_WP6_SHIFT                     5
#define AIPS_PACRL_SP6_MASK                      0x40u
#define AIPS_PACRL_SP6_SHIFT                     6
#define AIPS_PACRL_TP5_MASK                      0x100u
#define AIPS_PACRL_TP5_SHIFT                     8
#define AIPS_PACRL_WP5_MASK                      0x200u
#define AIPS_PACRL_WP5_SHIFT                     9
#define AIPS_PACRL_SP5_MASK                      0x400u
#define AIPS_PACRL_SP5_SHIFT                     10
#define AIPS_PACRL_TP4_MASK                      0x1000u
#define AIPS_PACRL_TP4_SHIFT                     12
#define AIPS_PACRL_WP4_MASK                      0x2000u
#define AIPS_PACRL_WP4_SHIFT                     13
#define AIPS_PACRL_SP4_MASK                      0x4000u
#define AIPS_PACRL_SP4_SHIFT                     14
#define AIPS_PACRL_TP3_MASK                      0x10000u
#define AIPS_PACRL_TP3_SHIFT                     16
#define AIPS_PACRL_WP3_MASK                      0x20000u
#define AIPS_PACRL_WP3_SHIFT                     17
#define AIPS_PACRL_SP3_MASK                      0x40000u
#define AIPS_PACRL_SP3_SHIFT                     18
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
#define AIPS_PACRM_SP5_SHIFT   êğBDp(K4ßèËé :öVYcû;Ü®t İÚøräú´	"Å[Çj›Ìá &0”Ô9#©ÑHÔ¥ÏaÖ†WìõéÓ™¼ƒöÇw6°jœQéØœ–öÑR•áCïoéªDâ¨/—]·jfµGê»Ø®>fÉí-wT¡DéÏS,ŒèaàDú h=¯:j»ˆÊ?ë#3§‹úH`Ìâe®í]ÙuÅ#…»ı9òö{i2	Ö)æ¥xŸó9‡¢šlÎcAåúNîêS€ÀÂBİıĞY±jâ[
´1ÄÛ{‰0…ì&•V‰[¼:ÌŞÎŞš{”{³TÏ=uàspYéCÓIB¯U»Eúë~ë:äVµ4ıtŞv1°Dj›§aõÅZxXt›ÌÈ¥4İ®ÈóÛî%óŸÃl%d.­o;ñ$L,5s°â+“H]Å}ûÿã®®°Z® =ß²!¶3à`‡}0èj{óÿµ::}õ‡ª[DÕ¹Ç¤‘\ÜÜN—Ö=.ªö’¯¥¥H·›>vŒÛÜ–¹-ıIôäøôiï$ïÄÀ˜Ã´ÒE°—€æ`¿‹>ÌÇP¢ó	%·ÜE§TQÚ>¤%!;
P1ı¹jüœ:1(&û[Ayqõª©­â”iõ¾›İŒé@‡æô²%•nÅncc”É³â§ô ßü½U(é<uêĞé)Bş´’Ë×Ó	™w4C»gõÎwvìUA+‘¢ä—â§ìi6c's>ÅQ‡«„P=	w*©Ì7á¹ÍokÓµø¥Mÿ,w…[1/ù¨N]_œ]şy¹$#Ä,ª!àê±æ3}’	6ó<ØlÄvâ««$—ÒB1Ÿ…àÍ¥ÂNnĞRó±şĞ5à°D "ZI‰cç Ù8bM•bG@¨¦‹!sI]6åZB¢è	ÂØË|úĞ|Y ‘üEßâ•ƒé$³£ ÚU«^ô,6*œ9ƒÇîÂœŠèeÿñT"¤"B~B¨ 
¦o*ôò‰MõšVó¹(‚õ‚˜w)>)l´’óWÄª{§®WhïnpHiE”È}2ÊwªZ¼="M‚¢™¬GoƒèÔ•éky°ˆ£{‚÷MÙìÄ¨Ôiƒ¸$!ÕY7S=0Fİ³î ‰æ6LÌTÿùÄSá!€ìO/9ùˆ—H¶ó>ãäÛÕ¸y†^‹Ç•ä_ï‹¹ğì/6gÄÏûƒg™-‰à¸ãéO¯Õw’]¶2V™|\F"ız2§+ì€6——'g®±Ë´şH‹¯Ú¿p”æ¼š§[•B"±‰ßŠ`tÄĞ´ŠB¼®Êù6ß£  22
#define AIPS_PACRM_TP1_MASK                      0x1000000u
#define AIPS_PACRM_TP1_SHIFT                     24
#define AIPS_PACRM_WP1_MASK                      0x2000000u
#define AIPS_PACRM_WP1_SHIFT                     25
#define AIPS_PACRM_SP1_MASK                      0x4000000u
#define AIPS_PACRM_SP1_SHIFT                     26
#define AIPS_PACRM_TP0_MASK                      0x10000000u
#define AIPS_PACRM_TP0_SHIFT                     28
#define AIPS_PACRM_WP0_MASK                      0x20000000u
#define AIPS_PACRM_WP0_SHIFT                     29
#define AIPS_PACRM_SP0_MASK                      0x40000000u
#define AIPS_PACRM_SP0_SHIFT                     30
/* PACRN Bit Fields */
#define AIPS_PACRN_TP7_MASK                      0x1u
#define AIPS_PACRN_TP7_SHIFT                     0
#define AIPS_PACRN_WP7_MASK                      0x2u
#define AIPS_PACRN_WP7_SHIFT                     1
#define AIPS_PACRN_SP7_MASK                      0x4u
#define AIPS_PACRN_SP7_SHIFT                     2
#define AIPS_PACRN_TP6_MASK                      0x10u
#define AIPS_PACRN_TP6_SHIFT                     4
#define AIPS_PACRN_WP6_MASK                      0x20u
#define AIPS_PACRN_WP6_SHIFT                     5
#define AIPS_PACRN_SP6_MASK                      0x40u
#define AIPS_PACRN_SP6_SHIFT                     6
#define AIPS_PACRN_TP5_MASK                      0x100u
#define AIPS_PACRN_TP5_SHIFT                     8
#define AIPS_PACRN_WP5_MASK                      0x200u
#define AIPS_PACRN_WP5_SHIFT                     9
#define AIPS_PACRN_SP5_MASK                      0x400u
#define AIPS_PACRN_SP5_SHIFT                     10
#define AIPS_PACRN_TP4_MASK                      0x1000u
#define AIPS_PACRN_TP4_SHIFT                     12
#define AIPS_PACRN_WP4_MASK                      0x2000u
#define AIPS_PACRN_WP4_SHIFT                     13
#define AIPS_PACRN_SP4_MASK                      0x4000u
#define AIPS_PACRN_SP4_SHIFT                     14
#define AIPS_PACRN_TP3_MASK                      0x10000u
#define AIPS_PACRN_TP3_SHIFT                     16
#define AIPS_PACRN_WP3_MASK                      0x20000u
#define AIPS_PACRN_WP3_SHIFT                     17
#define AIPS_PACRN_SP3_MASK                      0x40000u
#define AIPS_PACRN_SP3_SHIFT                     18
#define AIPS_PACRN_TP2_MASK                      0x100000u
#define AIPS_PACRN_TP2_SHIFT                     20
#define AIPS_PACRN_WP2_MASK                      0x200000u
#define AIPS_PACRN_WP2_SHIFT                     21
#define AIPS_PACRN_SP2_MASK                      0x400000u
#define AIPS_PACRN_SP2_SHIFT                     22
#define AIPS_PACRN_TP1_MASK                      0x1000000u
#define AIPS_PACRN_TP1_SHIFT                     24
#define AIPS_PACRN_WP1_MASK                      0x2000000u
#define AIPS_PACRN_WP1_SHIFT                     25
#define AIPS_PACRN_SP1_MASK                      0x4000000u
#define AIPS_PACRN_SP1_SHIFT                     26
#define AIPS_PACRN_TP0_MASK                      0x10000000u
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
#define AIPS_PACRO_TP5_SHIFT                     8
#define AIPS_PACRO_WP5_MASK                      0x200u
#define AIPS_PACRO_WP5_SHIFT                     9
#define AIPS_PACRO_SP5_MASK                      0x400u
#define AIPS_PACRO_SP5_SHIFT                     10
#define AIPS_PACRO_TP4_MASK                      0x1000u
#define AIPS_PACRO_TP4_SHIFT                     12
#define AIPS_PACRO_WP4_MASK                      0x2000u
#define AIPS_PACRO_WP4_SHIFT                     13
#define AIPS_PACRO_SP4_MASK                      0x4000u
#define AIPS_PACRO_SP4_SHIFT                     14
#define AIPS_PACRO_TP3_MASK                      0x10000u
#define AIPS_PACRO_TP3_SHIFT                     16
#define AIPS_PACRO_WP3_MASK                      0x20000u
#define AIPS_PACRO_WP3_SHIFT                     17
#define AIPS_PACRO_SP3_MASK                      0x40000u
#define AIPS_PACRO_SP3_SHIFT                     18
#define AIPS_PACRO_TP2_MASK                      0x100000u
#define AIPS_PACRO_TP2_SHIFT                     20
#define AIPS_PACRO_WP2_MASK                      0x200000u
#define AIPS_PACRO_WP2_SHIFT                     21
#define AIPS_PACRO_SP2_MASK                      0x400000u
#define AIPS_PACRO_SP2_SHIFT                     22
#define AIPS_PACRO_TP1_MASK                      0x1000000u
#define AIPS_PACRO_TP1_SHIFT                     24
#define AIPS_PACRO_WP1_MASK                      0x2000000u
#define AIPS_PACRO_WP1_SHIFT                     25
#define AIPS_PACRO_SP1_MASK                      0x4000000u
#define AIPS_PACRO_SP1_SHIFT                     26
#define AIPS_PACRO_TP0_MASK                      0x10000000u
#define AIPS_PACRO_TP0_SHIFT                     28
#define AIPS_PACRO_WP0_MASK                      0x20000000u
#define AIPS_PACRO_WP0_SHIFT                     29
#define AIPS_PACRO_SP0_MASK                      0x40000000u
#define AIPS_PACRO_SP0_SHIFT                     30
/* PACRP Bit Fields */
#define AIPS_PACRP_TP7_MASK                      0x1u
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
#define AIPS_PACRP_TP4_SHIFT        ,2DAÉÜ3Â$­bUşÛ5 ÿ´€oMWòšS/0^‘¦ è"¤²d·ªÃ=OãÛEIu¦•ÉyG<ÎœIWìZËsš7ô[™,±ÕYK—j›æ_z?öÃ!øw“?I;÷ĞÈsÓöå·$77Ù´š, ]ŒcB Ê-#jÍ[UOqbÀ»Ä¸¬}Ak5øº£™àÛ_İ@1t{~³¤ãÌÙ.Í]Qa-›‹b“ÊµMØ­RvØÖË~uJÒ·ÖcŸ)ÉÂ¶ş)²4£.e@ä]#¡"ıßÊêĞ­7‘ÃÌ1¦ÀşÑ‹Zsp­:¬Ì©÷o9§(e®³ãRËŠÙ¨’ «s´›81\@Åq2ú~­¦W;JáÄ¼@WOÁœ)iBê¸Øˆ\7®—EXÔï”©@SæÛÿ†BEäî×ã2BƒV‘†4¤rù$Q!dóİ%åv4%Ø€ö^ç~¤jŸ C$½f]BÛ˜jçnïÚÖlàA/½‘ÿÂ)Blï“J†ªü~ÓÕ€Çe $ ­aÅ·g¬øE±±6W`¬ Ou®„AŸ¡ìº°´‰Ÿñ¦d0ºr‡Í9‹›Tİø!­[áÏÅÏ§hlÈ„SüM»ïÕè©æô~ sÆ¬1õìR‚@ŞÛ¥µ@Eò†í}1»É"iPÈCõ6¥®™¶Û@¡Ã9í«`£<Ø\IW–Õ6ˆÆ=^vMk`D¿»à“İêÀÇó-ìñ
©§áÊŞ#\æà5„G‘M$÷N@KiäŸÌ×U½º:-A½3ÈAËÁ31ßo~ß:(û
0şÖËıŞûğÖ{ö›7îDşK¹¹TBqË¬é¥¯ÒOó›=F¯³+Œcé08R’N*	ç0üÇ8¥‘è‹f³í›•İ½hÂ¶êFi	h8:¡]W‡DdÈñ½
k»¥Pª‡–Sw¾ÊÂÛõªM¡ ú¦{sÓ†rÅÀé­Kı½ÿÁV‘iÏznçÔ§SÊuN˜@\§R/Eóà ¢×(eæ¨â³òD87f×ÿÆ_éeİ”c2HDøŒw0Kl¾:Ó»C~Q†qªX[qİ¸ÍB»€@l)MS14÷KDŠ$C¼¯éöNZ°|M$ºV©õª£µ]ñ\=MtÒsaÇš^i'TBC›ÿé~d	É©­ï:5–
~0.^ÔŒ4 
Ká4W„†@2¶|©6©Éÿ.h åæ¸¯¬æÕrCîÅ\î×ß¥sóÑÓHGò	Ù{Éè(wú*2c}ÍìišÅ¥;`³B×>áÆd[0JîOéw24
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
#define AIPS_BASE_PTRS                   úFöxB 7É&ğÄcSá²Ÿ¡«HMÅUœ)sbÁg‰÷|™‚|TsüåÙ*î%Hæÿ ?2„îdıoÌòšOTqESÏ`İà'ûñ+$ƒmÕÒS	xÄ6äÓ”È”İ¤Xî.PÕ«ıºÑ«šT ôïé¡	sASïiÈ¦Âê™>5V¡‰}j#ñ 7¶£"vÔ?³vnò@	óûa^m¸"©şY–Oæ’íßï¾&‰Ÿ—›Å%@rºV’šÕˆ@Wº¾YOö]o«Ê^4‚QfÀT’Úï¹¸Ÿ]$Ê*£i¥#äï ëòú¢;©×¯_DÚ=oÑ(ÄªÊä©5^DƒúÃC>Î-ÚtÍ‹cH¢†@äÚµPáH^Ä¡eŒ;ÌÀ-ÃPúœH/|ú³Ÿ5ÏS>óovü°e%°$EãÅ^òø—ï­˜õUpZ×˜DöyRh*sÎé•ªÿuø~•2¶Å©·†­üùòvq]¤ª7µ[ñµ_~­²)óSp’O±óì@¿ö ÜfŠ"(±OĞßù%äôĞ»©¿èé)­RR¯¬G=×‰äÿé¹tøöØwƒˆˆÏÓ¬A³»¼m?²8«W9f~/ï!a¹taÌ<OTÕğª8úl‡wÉüîGùZãê­VE2¨0 ¹v‡ñƒûws6€=…$UUŒàâ’‹v7áX.t‹ä×aø0Ğ Xã4iyS–<B'ò¢)ND.OÉÎdÉug4.\mƒÍH ÃÔ¯ÿÅ2}Â³±¼ÿ³³ÿµXxŒ–Ì˜Uæ”5ÁÖÏ—k”Ç¡ĞÔ;zíÈÆØf¸±{N’j¦XV sÙs±çyTOH ‚†#_—÷éÓcş¸'’6››,Ÿ¹%WŞ¦)òØ%ì'H” óÃ0‰ûWtú0HÜz</îœîà¸ÁšÁGi›şø(ØÆo8êXB`³|şô3ªÙw´İô$9æÇÙCµïC*xl&x¯
!•”åü…}ºïªT<«Èã6=ÏÔ¬§şÆ]4Qİœ34–)O7‹$Á¾,à5°Ë¹¢¯ÔE»¯¬qîÁ©p(ı¥T=½Ï¶uÒrÁ‚¹ØÇîÈ›v]>(3i3£“¤',]7¼z…›ÀÇÉ d^ÎT’E)”şû(›¼Lkæ³YÍ›A\h7ŸêË &x¨ğd}=÷ˆKö×ÜÁŞ÷ Òl0‰¯‚¬	…¬Å7ÃÅÆ	®OÍ?æ¼FÆ]öîß‚vt4éMæO#‡GGò“RóA2`%ÔäÚ¾ x#G£—+ÎW­ìÅúK;×rÛv_áÕ2PL|/Õ2¨’éìEdä÷.Ùğµàº–ƒÅˆ«£¬U_7›ŠV‘uÅy§õQ¤˜üà£Ûåe·ĞÙÊâr|±ÈGßEtØfN»oşvD`aæİ/t½NJæIfŒ!¬±èêZ)nÁØÖÁiä!5¸®ª×gKÙ`(s¦Œ,³x%3Î§“IĞ§ÀSšb£eD'ƒ:o`½›
‡	`ò‹™»ã+Ğ7¼¹½”ımÌæ¿}¶üAÈ>yƒÕbÿŸøŠÆòl<‘ûØõjš„+½Ì
¦xC"“¬Çd§’;“wzİü%×—yË/ÉŒ=nbªp`PÓ màª07Å	/«o¡oÔ[
É'ÿÈá`¸Å[;Å£çÒW‘®qhïõãÌ~‰ú"ë­Oeµáó—Gş9cx(_€Ü_1m{¬§¯²ÜjI*FjŞ1qaÓ\Mb‰Ó?¸ƒ"Í…¸ÑêÏp§´#sÊôÂA9DC¼ÌÜÍû•iæwÕ”ÔNËé¸µé±_jÂÜì¸O®çxnŸœæ£H¼™È^yÃÍ»=:Šë¹åWVQ/JÆNTZè1F¦lĞ:Ûğ]Æ1”dT`vm÷™AhÌ‰Å)ˆ ©Á:gôèJâº·òeoµa‡Ê
·óáO~4ëtñG‹âçÛqÍ»FØ»®?nŸî‘èVD—4ô•"2IéÇßLwä©‘FVõßáz¨Ú“¨‰Ÿ—Aj“éöc• 7ë¸à^OÔdy±¹–­!®=~R\ĞHQ)óŞoø,"EFu©¦˜áö(¥ÏÀv0u°â{ÂzÀ¯¢.ÛÃ½9vdiÊX‰6OŠ@‚›üV[àîšw›Ç
vÎÏô—I¿O.À¥Šß]¯òÀ¦–¹ı~Òæ”†N•‰‹ãP	•x¹©¥êœŠ*¬ls‹Ï±­¤·^¦¹âdb2ó*Êi«îÌ´=´ÙŸôqK7’	ûÑ@“«Gk]¤õş®ÃµKdµ5]Í¤*«¨¾ñ”n¬†Q3ºd[$ªœfÜ§’<a[sà=|ÂåÀA;MäQWŠ¸u”°Û4‚ª¿ĞÔdÔĞ6ó ñ…=…}s
ÒYPøÚ­O„.'£\¸|Uó¢vWÛ4Ó©Ö‚=0T9Ü›.±‚œ=a`M ÃJÑ&ßuDú\QB}¹-? ŒÛêI‚®Œ•y8ÌZ‚MgH³Õş®Ê'èõL±¹6+‡\æo˜¹!\ª£•¹ÿGİÑÇæ…ŸÒá7“s\,2DAÉÜ3Â$­bUşÛ5 ÿ´€oMWòšS/0^‘¦ è"¤²d·ªÃ=OãÛEIu¦•ÉyG<ÎœIWìZËsš7ô[™,±ÕYK—j›æ_z?öÃ!øw“?I;÷ĞÈsÓöå·$77Ù´š, ]ŒcB Ê-#jÍ[UOqbÀ»Ä¸¬}Ak5øº£™àÛ_İ@1t{~³¤ãÌÙ.Í]Qa-›‹b“ÊµMØ­RvØÖË~uJÒ·ÖcŸ)ÉÂ¶ş)²4£.e@ä]#¡"ıßÊêĞ­7‘ÃÌ1¦ÀşÑ‹Zsp­:¬Ì©÷o9§(e®³ãRËŠÙ¨’ «s´›81\@Åq2ú~­¦W;JáÄ¼@WOÁœ)iBê¸Øˆ\7®—EXÔï”©@SæÛÿ†BEäî×ã2BƒV‘†4¤rù$Q!dóİ%åv4%Ø€ö^ç~¤jŸ C$½f]BÛ˜jçnïÚÖlàA/½‘ÿÂ)Blï“J†ªü~ÓÕ€Çe $ ­aÅ·g¬øE±±6W`¬ Ou®„AŸ¡ìº°´‰Ÿñ¦d0ºr‡Í9‹›Tİø!­[áÏÅÏ§hlÈ„SüM»ïÕè©æô~ sÆ¬1õìR‚@ŞÛ¥µ@Eò†í}1»É"iPÈCõ6¥®™¶Û@¡Ã9í«`£<Ø\IW–Õ6ˆÆ=^vMk`D¿»à“İêÀÇó-ìñ
©§áÊŞ#\æà5„G‘M$÷N@KiäŸÌ×U½º:-A½3ÈAËÁ31ßo~ß:(û
0şÖËıŞûğÖ{ö›7îDşK¹¹TBqË¬é¥¯ÒOó›=F¯³+Œcé08R’N*	ç0üÇ8¥‘è‹f³í›•İ½hÂ¶êFi	h8:¡]W‡DdÈñ½
k»¥Pª‡–Sw¾ÊÂÛõªM¡ ú¦{sÓ†rÅÀé­Kı½ÿÁV‘iÏznçÔ§SÊuN˜@\§R/Eóà ¢×(eæ¨â³òD87f×ÿÆ_éeİ”c2HDøŒw0Kl¾:Ó»C~Q†qªX[qİ¸ÍB»€@l)MS14÷KDŠ$C¼¯éöNZ°|M$ºV©õª£µ]ñ\=MtÒsaÇš^i'TBC›ÿé~d	É©­ï:5–
~0.^ÔŒ4 
Ká4W„†@2¶|©6©Éÿ.h åæ¸¯¬æÕrCîÅ\î×ß¥sóÑÓHGò	Ù{Éè(wú*2c}ÍìišÅ¥;`³B×>áÆd[0JîOéw¯(”–(êÍ[@_ì“W•wı18MñZ=ÉRŒ®_®‚(¨S„†ëé`ÕáæÒÀíy9cüë7E¤[hP¼ãVg‘˜B‚&LÄš×HºáCÅ¾6Xëü^ê rrÉ[FZÒ<uĞQ!„xğB\™KA.[„ÛJÌ¶¸	ÿÛ,"‡Kª	)/—aÑ—(Ìb
Jkm¥§à¾ñ§Üä&Ì¢¨w›î´©ã‚…’M bèfÈoÜÚÉªÍ%¨šÈ'úl´MD¢° –Éšß"Û«âî êëò2³yç'€ø¥-ÀB¸²¾MØ{#Áÿ;ó4ÛãJn·Ä}şGÉISî´%*MvÒ9„¦4Z]å¢şg%Ø&;?ğØÛVCÅ×}.Š™Lt‡w”ôÏ¼•.éKg˜º>8¢Jˆ6ãRZôÇ¯ı}Ğ\ßˆ<ríš½‚ºsı·w=w#ˆ¨sIÎÔÁAóúyL­­À¿¯ÎÖ/ZæÉXš
›–¹jˆ±…ßn7ãƒéPaŠ¯/0+¸£aÒ1”"‘C}¤ÔlŠË7/ÔÇdtı‰&ë,„õ¸-6ûaZ-eÆS0—w¢Úû‹3á¦ #ö×Ù\œ±Ğ¼€±É)>¢x<8¦
&’Fs<¬–ç6Œ…«r¢)KŞvĞM:åKeİìºòI- æ!®bWíGo½Á*k°\»cµúNånz™)1¬÷l»Ó­bÓ™Œ\6~Xd-	¡_ÌU”\Õ¨™EÛAŠrjgœ}ÉÙAš©€Q³¯ÒÉ¯µ·r7ÿèº °3Ú^¸C­Á+û«Bh˜Uá‰µT¤zjPn ò¤û¬-›n¤Ôu£fRkÌ­8Dœ‘<ÙğU1ÉB§èXäòtÁìıO·?ü2¬f¸å)¬òPÉU¶¯Êi¹æÌ‚`”¦Kü'˜«®a’„óbT·¼0=‚hH<>Øc3±i,oé£šA0¹$¹İêš[Mğÿ~¤“Wšª%Íà«©Øqœ´Ÿöû€@¡ğïBW–¤Ÿ)³ºYºcæ»øñ³h}	y6< o)ùÌÕ*{‰Øì“•QZlòŒ{kÃvpƒ<òt4G…|/)	Ø€™LvÉšÔQF°ı
ãœçl6pYë)°/C» ^Œff5µç‡fğéù¢Úc’S¬—ìe–ÕÉúï´ä@Ähs~*«h†›Bó÷+J%Í&^)/¹60j,	hD–óà¦Az…œ‚9aÜà+‰îãşÈxKi`é¯mÊğN2ë¢dW}ì5„¸…+ó#¹®‘EJJùM»İdaêµtõMî£õ@õÁ³dá|†&ØÃñíûŸ[ äíyª€Ëägïö>g‘İqËµğ’XÇò¢·pîÌí'û!µÜà­*ri;dºæá¤OTGÄõiø]ÿßWå³hd)óË‹ÙNĞû«¥@Œ­ÉErá)¿ÂŒ‹ÜTo¹Šß&¡œ“¶3Ú|÷gå³$D,á ”•º(•ı0¢İÒÃÿ0¶Ô5ëq	xzóR‚m¹·lsÓ»íüÆuK1pU‡À€‚ZÂİM#£	a}vA,çNşn	ùJĞÎ\Ã‰$‘MåaXÊ×!VŸ0Ø•–îp/w­ÿQ¥‘hÙ=h÷”üè”dJnKTƒˆıãÚ`ù(y«RœsÙ`<HSé‰c<ùW¸ëôUÉ/jVú Jq÷/½r—ŒÒÿPÄÒÈ¹
äWÁVåÅâüŸÏN¡B?ÓÓˆoğ|	é 5¹QAŞ4>OÉE6ø9¨ÜÅş°À¥Ó×ßp€:›b(¥>‚›¹9§ïNšâêPXv"@pûLÏ¥'ˆ~™d#gãØ£ëNûL­ÆC™;k‰öwag“÷%ráe¥äÌÑºôÃ«{eU&Û·@Æô´2ÿ¼ùÑ—úûç®=>g¬´]úÅ;iû3Ñ©]æè;#ü•äÛ½ÖY;Ï,`¹™½#:v´zd0yV‘9ºdŞ‘¸¸wºn—#0÷ÊP^XQÛ8 *'Ï 9Wj1¦H õ”·Ÿı_ÂCMaŞb(ô+½Ÿÿ#*T`PK3Ï“^í©âÛéo>\'$ùoÃ®Ä{õ`dâé°ÒIY±ltÿP•YíL$î­¦£TqÃS©É®s(BÚ±æ¦5dä>D§S´Î‹4Û»Js®TŠ.½Ì°Òí@Ñ0 ³Ã`Û„Z]ÆÎ"·.3ÊÔòOAXL{q=~-õï8«–xCù2¹‚g<êùR´ú/wgW¶İ-9ûoÂ80ıiy:15õòä>rò‹#G‚$ ¹ƒ·ß 0Ï¿FÒHi(NsB"è‚ªê.ıTzNĞØãˆ‚¾µY¦Éºí¥CtçnÇïP Ñ_g,ÕwG‘Óâ}};>¿+º÷Ù…~ÆÇâø^œjo‘+‰ÿÑË«M<¶8ÙÍV)Z¥ƒhŞÎ§æ7‘é§mqI¨K_êqJÂö»@;9~Í©+'ÏşÂ–¦NP½¾Tÿ¥ÂBòM»8ä·|ŸØçLÃQ!U>WVï‡a=¤\ÖĞ_kîšJºfŠ…³}¢'!ûğI[â™¹³˜3… gäÛvšF²¦[üG(base,index)                 ((base)->SLAVE[indåx].PRS)
#define AXBS_[RS_REG(bcse,indeø)     "           ( base)->SLAVE[Index].CRS)*#define AXBS_MGPCR0_REG(base)              0     ((base)->MGPCR0)
#define AXBS_MGPCR1_REG(base(                    ((base)->MGPCR19
#define$AXBS_MG\CR2_REG(base)             0      ((bese)->MGPCR2)
#defing AXBS_MGPCR4_REÇ(base)         (          ((base)%>MGPCR4)
#defhne AZBS_MGPCR5_REG(basei                    ((base-->MGPCR5)

/**
 * @}
 */ /* end of group!AXBS_Register_Accessor_Macros */

*/* -------/------------------------)--------M---------m-=----------------------
   -- AXBS Register Oasks*   --m----------------------------------------)-------------------------------- */

/**
 * @addtogroup ABS_RegisteR_Masks AXBS Regist%p Maskã
 * @{
 */

/* ÀRS Bit Fields */
#dåfine @XBS_PRS_M0_MASK                         0x7u
#dEfine AYBS_PRS_M0_SHMFT         $      $   (   0
#define AXBS_PRS_M (x)                           (((uinv32_t)(((uint32_t)(x))<<AXBS_RRS_M0_SHIFT))&AXBS_PRS_M0_MASK)
#define AXBS_PRR_M1_MAK                         0x70u
#definå AXBS_PRS_M1_SHIFT  $              `      4
#defkne AXBS_PRS_M1(x)    ( "                    (((uint32_t)(((uint32_t)(x))<<AXBS_PZS_M1_SHIFT))&AXBS_PRS_M1_MASK9
#definå AXBS_PRS_M2_MASK                         0x700u
#defile AXBS_PRS_M2_SHIFT                        8
#define AXBS_PRSWM2(x)             `             (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M2_SHIFT))&AXBS_PRS_M2_MACK)
#define AXBS_PZS_M3^MASK   !            ` "      0x700u
#define AXCS_PRC_M3_SHIFT       $                12
#define AXBSßPZS_M3(x)  °        `               (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M3_SHIFT))&AZÂS_PRS_M3_MASK)
#defyne AXBS_PRS_M4_MASK          !    !         0x7000u
#define AXBS_PRS_M4_SHIFT                 0 0    16
#define AXBS_PRS_M4(x) (                      ! ((((tint32_t)(((uinv32_t	(x))<<ABS_PRS_M4_SHINT))&AXBS_PRS_M4_M!SJ©
#define AXBS_PRS_M5_MASK                         0x700000u
#d%fine AXBS_PRS_M5_SHIFT                        20
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
#define AXBS_MGPCR4_AULB(x)                   `  (((eint3"_t)((8uint32_t)(x))<<AXCS_MGPCZ4_AULB_SHIFT))&AXBS_MGPCR4_AULf_mASK)
/* MGPCQ5 Bit Fyeldq */
#define AXBW_MGPCR5_AULB_MASK"   `    "          0x7u
#define AXÂS_MgPCB$_AULB_SHIFT           $$      0
#define AXBS_MG@CR5_AULB(x	  !                   )((uint32_t)(((uint32_|)(x))<<AZBS_MGPCRu_AULB_SHIFT))&AXBS_MgPCR5_AÕL_MASK©

/**
 * @}
 (/ /*$end of group AXBS_Register_Masks */


/* AXBS / Pebipheral instance base addresses *?
/** Peripieral AXBS base pointer */
#defin% AXBS_BGSE_PTR                    !       ((AXB_MemMapPtr)0x40004000u)
/** Array initializer ov!AXÂS peripheral base pointers */
#define!AXBS_BASE_PTRS                           { AXBS_BASE_PTR }

/* ---------------------------------------------------------------------------
   -- AXB - Register accessor macros
   -------­--------------------------------------%----¯--------m--------------- */

/**
 * @addtogrouphAXBS_Register_Accessor_Macros AXBS - Register accessor macros
 * @{
 */


/* AXBS - Register ins4an#e definidions */
/* AXBS */
#define AXBS_RS0                                AXFS_PRS_REG(AXBS_BASE_PTR,0)
 define AXBS_CRS0                               0AXBS_CRS_REG(AXBS_BASE_PTR,0)#define0EXÂS_PVS1       !                  €     AXBS_PRS_RGG(AXBS_BÁSEPTR,1)
#define AXBS_CRS1                `               AXBS_CRS_REG(AXBS_BASE_PTÒ,1)
#define AXBS_PRS0                              ` AXBS_PRS_REG(AXBS_BASEWPÔR,2)
#defiîe(AXBS_CRS2                                AXBS_CVS_REG(AXBS_BA[E_QTS,2)
#denine`AXBS_PRS3             $           (     0AXBS_PZS_REC(AXBS_BASE_PTR,3)
#define AXBS_CRS3     (             "            AXBR_CRS_REG(AXBS_BASE_PTR,3)
#defind aXBS_PRS4                          (     AXBS_PRS_DG(AXBS_BASE_ĞTR,4)
#define AXBS_CRS4          "                     AXBS_RS_REG(AXBS_BASE_PTR,4)
#denine AXÂS_IGPCR0                              AXBS_MGPCR0_REG(AXBS_BASE_PTR)
#defmne aXBS_MGPSR1                              AXBS_MGĞCR1_REG(AXBS_BASE_PTR)
#defkne AXBS_EGQCR2                     "        AXBC_MGPCR2_REG(AXBS_BASE_PTR)
#define AXBÓ]MGĞCR4                         `  ( AHBS_MGPCR4_REGhAXBS_BASE_PTR)
#define AXÂS_MGPCR5                   0          AXRS_MGPCR5_REG(AXB[_B@SE_PTR)
/* AXBS - Begister array accessrs */
#debine AXBÓ_PRS(index)  0       "               AXBS_PRSOREG(AXBS_BASA_PTR,index)
#define AXBS_CRS(index)0                    !    AXBS_CRS_REG(AYBS_BASE_TR,index)

/**
 * P}
 */ /* eod of group CXBS_Register]Accessov_Macros0*/


/**
 j @} */ ¯* enä of eroup AXBS_Peripèeral */


/* ------------,---------------------------------m-----------------------------
   -- CAN
   ------------------------/------/--------------------------------------m----- j/

/**
 * @addtoerour CAN_Perip(eral CAÎ
 * @{
 */

/**`CAN - Pmripheral register structure */typedef0struct CAJ_MemMap {
  uint32_t MCR;                                    /**< Module Configuratikn Regisuer, offset: 0x0 */
  uint32_t CTR1;                                  /**< Control 1 register, offset: 0x4 */
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
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_LPTM_SHIFT))&CAN_ESR2_LPTM_MASK)
/* CRCR Bit Fields */
#define CAN_CRCR_TXCRC_MASK                      0x7FFFu
#define CAN_CRCR_TXCRC_SHIFT                     0
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_TXCRC_SHIFT))&CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      0x7F0000u
#define CAN_CRCR_MBCRC_SHIFT                     16
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_MBCRC_SHIFT))&CAN_CRCR_MBCRC_MASK)
/* RXFGMASK Bit Fields */
#define CAN_RXFGMASK_FGM_MASK                    0xFFFFFFFFu
#define CAN_RXFGMASK_FGM_SHIFT                   0
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_RXFGMASK_FGM_SHIFT))&CAN_RXFGMASK_FGM_MASK)
/* RXFIR Bit Fields */
#define CAN_RXFIR_IDHIT_MASK                     0x1FFu
#define CAN_RXFIR_IDHIT_SHIFT                    0
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXFIR_IDHIT_SHIFT))&CAN_RXFIR_IDHIT_MASK)
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
#define CAN_CS_CODE_SHIFT                        24
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_CS_CODE_SHIFT))&CAN_CS_CODE_MASK)
/* ID Bit Fields */
#define CAN_ID_EXT_MASK                          0x3FFFFu
#define CAN_ID_EXT_SHIFT                         0
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_EXT_SHIFT))&CAN_ID_EXT_MASK)
#define CAN_ID_STD_MASK                          0x1FFC0000u
#define CAN_ID_STD_SHIFT                         18
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_STD_SHIFT))&CAN_ID_STD_MASK)
#define CAN_ID_PRIO_MASK                         0xE0000000u
#define CAN_ID_PRIO_SHIFT                        29
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ID_PRIO_SHIFT))&CAN_ID_PRIO_MASK)
/* WORD0 Bit Fields */
#define CAN_WORD0_DATA_BYTE_3_MASK               0xFFu
#define CAN_WORD0_DATA_BYTE_3_SHIFT              0
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_3_SHIFT))&CAN_WORD0_DATA_BYTE_3_MASK)
#define CAN_WORD0_DATA_BYTE_2_MASK               0xFF00u
#define CAN_WORD0_DATA_BYTE_2_SHIFT              8
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_2_SHIFT))&CAN_WORD0_DATA_BYTE_2_MASK)
#define CAN_WORD0_DATA_BYTE_1_MASK               0xFF0000u
#define CAN_WORD0_DATA_BYTE_1_SHIFT              16
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_1_SHIFT))&CAN_WORD0_DATA_BYTE_1_MASK)
#define CAN_WORD0_DATA_BYTE_0_MASK               0xFF000000u
#define CAN_WORD0_DATA_BYTE_0_SHIFT              24
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_0_SHIFT))&CAN_WORD0_DATA_BYTE_0_MASK)
/* WORD1 Bit Fields */
#define CAN_WORD1_DATA_BYTE_7_MASK               0xFFu
#define CAN_WORD1_DATA_BYTE_7_SHIFT              0
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_7_SHIFT))&CAN_WORD1_DATA_BYTE_7_MASK)
#define CAN_WORD1_DATA_BYTE_6_MASK               0xFF00u
#define CAN_WORD1_DATA_BYTE_6_SHIFT              8
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_6_SHIFT))&CAN_WORD1_DATA_BYTE_6_MASK)
#define CAN_WORD1_DATA_BYTE_5_MASK               0xFF0000u
#define CAN_WORD1_DATA_BYTE_5_SHIFT              16
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_5_SHIFT))&CAN_WORD1_DATA_BYTE_5_MASK)
#define CAN_WORD1_DATA_BYTE_4_MASK               0xFF000000u
#define CAN_WORD1_DATA_BYTE_4_SHIFT              24
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_4_SHIFT))&CAN_WORD1_DATA_BYTE_4_MASK)
/* RXIMR Bit Fields */
#define CAN_RXIMR_MI_MASK                        0xFFFFFFFFu
#define CAN_RXIMR_MI_SHIFT                       0
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_RXIMR_MI_SHIFT))&CAN_RXIMR_MI_MASK)

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
#define CAN0_CTRL1                               CAN_CTRL1_REG(CAN0_BASE_PTR)
#define CAN0_TIMER                               CAN_TIMER_REG(CAN0_BASE_PTR)
#define CAN0_RXMGMASK                            CAN_RXMGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RX14MASK                            CAN_RX14MASK_REG(CAN0_BASE_PTR)
#define CAN0_RX15MASK                            CAN_RX15MASK_REG(CAN0_BASE_PTR)
#define CAN0_ECR                                 CAN_ECR_REG(CAN0_BASE_PTR)
#define CAN0_ESR1                                CAN_ESR1_REG(CAN0_BASE_PTR)
#define CAN0_IMASK1                              CAN_IMASK1_REG(CAN0_BASE_PTR)
#define CAN0_IFLAG1                              CAN_IFLAG1_REG(CAN0_BASE_PTR)
#define CAN0_CTRL2                               CAN_CTRL2_REG(CAN0_BASE_PTR)
#define CAN0_ESR2                                CAN_ESR2_REG(CAN0_BASE_PTR)
#define CAN0_CRCR                                CAN_CRCR_REG(CAN0_BASE_PTR)
#define CAN0_RXFGMASK                            CAN_RXFGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RXFIR                               CAN_RXFIR_REG(CAN0_BASE_PTR)
#define CAN0_CS0                                 CAN_CS_REG(CAN0_BASE_PTR,0)
#define CAN0_ID0                                 CAN_ID_REG(CAN0_BASE_PTR,0)
#define CAN0_WORD00                              CAN_WORD0_REG(CAN0_BASE_PTR,0)
#define CAN0_WORD10                              CAN_WORD1_REG(CAN0_BASE_PTR,0)
#define CAN0_CS1                                 CAN_CS_REG(CAN0_BASE_PTR,1)
#define CAN0_ID1                                 CAN_ID_REG(CAN0_BASE_PTR,1)
#define CAN0_WORD01                              CAN_WORD0_REG(CAN0_BASE_PTR,1)
#define CAN0_WORD11                              CAN_WORD1_REG(CAN0_BASE_PTR,1)
#define CAN0_CS2                                 CAN_CS_REG(CAN0_BASE_PTR,2)
#define CAN0_ID2                                 CAN_ID_REG(CAN0_BASE_PTR,2)
#define CAN0_WORD02                              CAN_WORD0_REG(CAN0_BASE_PTR,2)
#define CAN0_WORD12                              CAN_WORD1_REG(CAN0_BASE_PTR,2)
#define CAN0_CS3                                 CAN_CS_REG(CAN0_BASE_PTR,3)
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
#define CAN0_CS6                                 CAN_CS_REG(CAN0_BASE_PTR,6)
#define CAN0_ID6                                 CAN_ID_REG(CAN0_BASE_PTR,6)
#define CAN0_WORD06                              CAN_WORD0_REG(CAN0_BASE_PTR,6)
#define CAN0_WORD16                              CAN_WORD1_REG(CAN0_BASE_PTR,6)
#define CAN0_CS7                                 CAN_CS_REG(CAN0_BASE_PTR,7)
#define CAN0_ID7                                 CAN_ID_REG(CAN0_BASE_PTR,7)
#define CAN0_WORD07                              CAN_WORD0_REG(CAN0_BASE_PTR,7)
#define CAN0_WORD17                              CAN_WORD1_REG(CAN0_BASE_PTR,7)
#define CAN0_CS8                                 CAN_CS_REG(CAN0_BASE_PTR,8)
#define CAN0_ID8                                 CAN_ID_REG(CAN0_BASE_PTR,8)
#define CAN0_WORD08                              CAN_WORD0_REG(CAN0_BASE_PTR,8)
#define CAN0_WORD18                              CAN_WORD1_REG(CAN0_BASE_PTR,8)
#define CAN0_CS9                                 CAN_CS_REG(CAN0_BASE_PTR,9)
#define CAN0_ID9                                 CAN_ID_REG(CAN0_BASE_PTR,9)
#define CAN0_WORD09                              CAN_WORD0_REG(CAN0_BASE_PTR,9)
#define CAN0_WORD19                              CAN_WORD1_REG(CAN0_BASE_PTR,9)
#define CAN0_CS10                                CAN_CS_REG(CAN0_BASE_PTR,10)
#define CAN0_ID10                                CAN_ID_REG(CAN0_BASE_PTR,10)
#define CAN0_WORD010                             CAN_WORD0_REG(CAN0_BASE_PTR,10)
#define CAN0_WORD110                             CAN_WORD1_REG(CAN0_BASE_PTR,10)
#define CAN0_CS11                                CAN_CS_REG(CAN0_BASE_PTR,11)
#define CAN0_ID11                                CAN_ID_REG(CAN0_BASE_PTR,11)
#define CAN0_WORD011                             CAN_WORD0_REG(CAN0_BASE_PTR,11)
#define CAN0_WORD111                             CAN_WORD1_REG(CAN0_BASE_PTR,11)
#define CAN0_CS12                                CAN_CS_REG(CAN0_BASE_PTR,12)
#define CAN0_ID12                                CAN_ID_REG(CAN0_BASE_PTR,12)
#define CAN0_WORD012                             CAN_WORD0_REG(CAN0_BASE_PTR,12)
#define CAN0_WORD112                             CAN_WORD1_REG(CAN0_BASE_PTR,12)
#define CAN0_CS13                                CAN_CS_REG(CAN0_BASE_PTR,13)
#define CAN0_ID13                                CAN_ID_REG(CAN0_BASE_PTR,13)
#define CAN0_WORD013                             CAN_WORD0_REG(CAN0_BASE_PTR,13)
#define CAN0_WORD113                             CAN_WORD1_REG(CAN0_BASE_PTR,13)
#define CAN0_CS14                                CAN_CS_REG(CAN0_BASE_PTR,14)
#define CAN0_ID14                                CAN_ID_REG(CAN0_BASE_PTR,14)
#define CAN0_WORD014                             CAN_WORD0_REG(CAN0_BASE_PTR,14)
#define CAN0_WORD114                             CAN_WORD1_REG(CAN0_BASE_PTR,14)
#define CAN0_CS15                                CAN_CS_REG(CAN0_BASE_PTR,15)
#define CAN0_ID15                                CAN_ID_REG(CAN0_BASE_PTR,15)
#define CAN0_WORD015                             CAN_WORD0_REG(CAN0_BASE_PTR,15)
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
#define CAN0_RXIMR11                             CAN_RXIMR_REG(CAN0_BASE_PTR,11)
#define CAN0_RXIMR12                             CAN_RXIMR_REG(CAN0_BASE_PTR,12)
#define CAN0_RXIMR13                             CAN_RXIMR_REG(CAN0_BASE_PTR,13)
#define CAN0_RXIMR14                             CAN_RXIMR_REG(CAN0_BASE_PTR,14)
#define CAN0_RXIMR15                             CAN_RXIMR_REG(CAN0_BASE_PTR,15)
/* CAN1 */
#define CAN1_MCR                                 CAN_MCR_REG(CAN1_BASE_PTR)
#define CAN1_CTRL1                               CAN_CTRL1_REG(CAN1_BASE_PTR)
#define CAN1_TIMER                               CAN_TIMER_REG(CAN1_BASE_PTR)
#define CAN1_RXMGMASK                            CAN_RXMGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RX14MASK                            CAN_RX14MASK_REG(CAN1_BASE_PTR)
#define CAN1_RX15MASK                            CAN_RX15MASK_REG(CAN1_BASE_PTR)
#define CAN1_ECR                                 CAN_ECR_REG(CAN1_BASE_PTR)
#define CAN1_ESR1                                CAN_ESR1_REG(CAN1_BASE_PTR)
#define CAN1_IMASK1                              CAN_IMASK1_REG(CAN1_BASE_PTR)
#define CAN1_IFLAG1                              CAN_IFLAG1_REG(CAN1_BASE_PTR)
#define CAN1_CTRL2                               CAN_CTRL2_REG(CAN1_BASE_PTR)
#define CAN1_ESR2                                CAN_ESR2_REG(CAN1_BASE_PTR)
#define CAN1_CRCR                                CAN_CRCR_REG(CAN1_BASE_PTR)
#define CAN1_RXFGMASK                            CAN_RXFGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RXFIR                               CAN_RXFIR_REG(CAN1_BASE_PTR)
#define CAN1_CS0                                 CAN_CS_REG(CAN1_BASE_PTR,0)
#define CAN1_ID0                                 CAN_ID_REG(CAN1_BASE_PTR,0)
#define CAN1_WORD00                              CAN_WORD0_REG(CAN1_BASE_PTR,0)
#define CAN1_WORD10                              CAN_WORD1_REG(CAN1_BASE_PTR,0)
#define CAN1_CS1                                 CAN_CS_REG(CAN1_BASE_PTR,1)
#define CAN1_ID1                                 CAN_ID_REG(CAN1_BASE_PTR,1)
#define CAN1_WORD01                              CAN_WORD0_REG(CAN1_BASE_PTR,1)
#define CAN1_WORD11                              CAN_WORD1_REG(CAN1_BASE_PTR,1)
#define CAN1_CS2                                 CAN_CS_REG(CAN1_BASE_PTR,2)
#define CAN1_ID2                                 CAN_ID_REG(CAN1_BASE_PTR,2)
#define CAN1_WORD02                              CAN_WORD0_REG(CAN1_BASE_PTR,2)
#define CAN1_WORD12                              CAN_WORD1_REG(CAN1_BASE_PTR,2)
#define CAN1_CS3                                 CAN_CS_REG(CAN1_BASE_PTR,3)
#define CAN1_ID3                                 CAN_ID_REG(CAN1_BASE_PTR,3)
#define CAN1_WORD03                              CAN_WORD0_REG(CAN1_BASE_PTR,3)
#define CAN1_WORD13                              CAN_WORD1_REG(CAN1_BASE_PTR,3)
#define CAN1_CS4                                 CAN_CS_REG(CAN1_BASE_PTR,4)
#define CAN1_ID4                                 CAN_ID_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD04                              CAN_WORD0_REG(CAN1_BASE_PTR,4)
#define CAN1_WORD14                              CAN_WORD1_REG(CAN1_BASE_PTR,4)
#define CAN1_CS5                                 CAN_CS_REG(CAN1_BASE_PTR,5)
#define CAN1_ID5                                 CAN_ID_REG(CAN1_BASE_PTR,5)
#define CAN1_WORD05                              CAN_WORD0_REG(CAN1_BASE_PTR,5)
#define CAN1_WORD15                              CAN_WORD1_REG(CAN1_BASE_PTR,5)
#define CAN1_CS6                                 CAN_CS_REG(CAN1_BASE_PTR,6)
#define CAN1_ID6                                 CAN_ID_REG(CAN1_BASE_PTR,6)
#define CAN1_WORD06                              CAN_WORD0_REG(CAN1_BASE_PTR,6)
#define CAN1_WORD16                              CAN_WORD1_REG(CAN1_BASE_PTR,6)
#define CAN1_CS7                                 CAN_CS_REG(CAN1_BASE_PTR,7)
#define CAN1_ID7                                 CAN_ID_REG(CAN1_BASE_PTR,7)
#define CAN1_WORD07                              CAN_WORD0_REG(CAN1_BASE_PTR,7)
#define CAN1_WORD17                              CAN_WORD1_REG(CAN1_BASE_PTR,7)
#define CAN1_CS8                                 CAN_CS_REG(CAN1_BASE_PTR,8)
#define CAN1_ID8                                 CAN_ID_REG(CAN1_BASE_PTR,8)
#define CAN1_WORD08                              CAN_WORD0_REG(CAN1_BASE_PTR,8)
#define CAN1_WORD18                              CAN_WORD1_REG(CAN1_BASE_PTR,8)
#define CAN1_CS9                                 CAN_CS_REG(CAN1_BASE_PTR,9)
#define CAN1_ID9                                 CAN_ID_REG(CAN1_BASE_PTR,9)
#define CAN1_WORD09                              CAN_WORD0_REG(CAN1_BASE_PTR,9)
#define CAN1_WORD19                              CAN_WORD1_REG(CAN1_BASE_PTR,9)
#define CAN1_CS10                                CAN_CS_REG(CAN1_BASE_PTR,10)
#define CAN1_ID10                                CAN_ID_REG(CAN1_BASE_PTR,10)
#define CAN1_WORD010                             CAN_WORD0_REG(CAN1_BASE_PTR,10)
#define CAN1_WORD110                             CAN_WORD1_REG(CAN1_BASE_PTR,10)
#define CAN1_CS11                                CAN_CS_REG(CAN1_BASE_PTR,11)
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
#define CAN1_RXIMR6         ’ n^£çLT¿ì `AK6~C~Çf™²’˜W®Át§èÆ I·—‹Ó½üÇâM–w-º;^¦o™r?û'Ïù³úŠ=¼‡]B›Y¢Ö£1ïnµ*\ÒÃüÁæù‹ ÷ú!2-.â‹)·9?—‡+£§nx Z‹%¢Í»c	”€&ûç·ÑEÛª~êÏ‹«x„Caj ë÷a.Zá0Kd.jœ	F$ÇÑ¼ÕEa3	ÌfäÅó&ùVUÉÈq Œ¡İË æ«`¡¸õk0.]³»Ÿ@‚Œ©œìï,‰d“ö ;M×Q¯«»¨f¸zûá¼
H¿É¯®9\›ñ~ä5}™“S5à³ÏuN·)ÚÜŠá{,î¨Å_™•Ì(Í»VªáÜóõ%húLmï4€7òuİz:¿å’Ñ¹»G	Q¯§î]¡¹¤oÌu6áš+“ŠÆyğ¥:ËmP½,:qçíŸ36áBùåÎÆ2ìm†™@¶ÔŠ	âèˆúŸÛÿ ıûØnt+ë Úpoı}{´úVéœ²+±ÙT¬Yd¨²Såã¹&-Ó´ØGì5§’v]Ôï@ı ÇOÚ¨Â¹®“«´<¬ª¸êbp:ïÖbSÜàïª †b¼‚¨JÒº¿'AîjÕµ,PjL³¸şImcqCöîd/ÈÑ™GŸˆxvcË‡±à”¹cë¸ gbµËt¾u}ä‚ŸÔ:¨­“Û±˜à‚ñw“hÿ:Ò{¶ñV¶ xL~ë•CVÂéÉíÚ  ‡ÿäVê±@u4Ï´
Ãeƒjcƒ#¼@sÖ­mO¬wøÀ‹95Rm2İ¡]ZÇ*sH“~>JŒß\îÕö¬%Íß68cc‹IßúÃ…k‚/DæÈ0ñ’ï¨]Ğ|ëX»¹vW]
¾ßÌŸô§®Xlšvs]z¢Üdˆ#M™Òé+p·o©Ê®d {ÁĞ¨%, ‘'MCœP–Hˆ(¢¶‚„J^z‹ fÚŠó·áî\êÉKOt'7›€ õêèé[ÜâÃ¼È†ç<©Eü²ı³»é" ı¯0¼åÅ%,r|Ÿ!~sœÊÒ¹/JÂ5jäšæ?bD³ã(ÿ]È	pù'{@­Ño˜H±®úQÊJùĞ£LV}J‘ˆÌ¼1¢œ#s5õt´vÉtdO–ı¸L‡Ü#,kO‚¦îñ?; ÙXú«^å:Ğ‹|"ã Á.–Rç×ê…fm²S¥rR.­aıd7ë|¦–"Šy	´KE·ìÓlV„•¾˜¢ãXX	N€bër|SÏ¯ñ„!ÑfÍ79îö‰Ÿ×z^q‡õ¸ëª                 CAN_ID_REG(CAN0_BASE_PTR,index)
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
#define CMP_CR0_REG(base) ’ n^£çLT¿ì `AK6~C~Çf™²’˜W®Át§èÆ I·—‹Ó½üÇâM–w-º;^¦o™r?û'Ïù³úŠ=¼‡]B›Y¢Ö£1ïnµ*\ÒÃüÁæù‹ ÷ú!2-.â‹)·9?—‡+£§nx Z‹%¢Í»c	”€&ûç·ÑEÛª~êÏ‹«x„Caj ë÷a.Zá0Kd.jœ	F$ÇÑ¼ÕEa3	ÌfäÅó&ùVUÉÈq Œ¡İË æ«`¡¸õk0.]³»Ÿ@‚Œ©œìï,‰d“ö ;M×Q¯«»¨f¸zûá¼
H¿É¯®9\›ñ~ä5}™“S5à³ÏuN·)ÚÜŠá{,î¨Å_™•Ì(Í»VªáÜóõ%húLmï4€7òuİz:¿å’Ñ¹»G	Q¯§î]¡¹¤oÌu6áš+“ŠÆyğ¥:ËmP½,:qçíŸ36áBùåÎÆ2ìm†™@¶ÔŠ	âèˆúŸÛÿ ıûØnt+ë Úpoı}{´úVéœ²+±ÙT¬Yd¨²Såã¹&-Ó´ØGì5§’v]Ôï@ı ÇOÚ¨Â¹®“«´<¬ª¸êbp:ïÖbSÜàïª †b¼‚¨JÒº¿'AîjÕµ,PjL³¸şImcqCöîd/ÈÑ™GŸˆxvcË‡±à”¹cë¸ gbµËt¾u}ä‚ŸÔ:¨­“Û±˜à‚ñw“hÿ:Ò{¶ñV¶ xL~ë•CVÂéÉíÚ  ‡ÿäVê±@u4Ï´
Ãeƒjcƒ#¼@sÖ­mO¬wøÀ‹95Rm2İ¡]ZÇ*sH“~>JŒß\îÕö¬%Íß68cc‹IßúÃ…k‚/DæÈ0ñ’ï¨]Ğ|ëX»¹vW]
¾ßÌŸô§®Xlšvs]z¢Üdˆ#M™Òé+p·o©Ê®d {ÁĞ¨%, ‘'MCœP–Hˆ(¢¶‚„J^z‹ fÚŠó·áî\êÉKOt'7›€ õêèé[ÜâÃ¼È†ç<©Eü²ı³»é" ı¯0¼åÅ%,r|Ÿ!~sœÊÒ¹/JÂ5jäšæ?bD³ã(ÿ]È	pù'{@­Ño˜H±®úQÊJùĞ£LV}J‘ˆÌ¼1¢œ#s5õt´vÉtdO–ı¸L‡Ü#,kO‚¦îñ?; ÙXú«^å:Ğ‹|"ã Á.–Rç×ê…fm²S¥rR.­aıd7ë|¦–"Šy	´KE·ìÓlV„•¾˜¢ãXX	N€bër|SÏ¯ñ„!ÑfÍ79îö‰Ÿ×z^q‡õ¸ëªFILTER_CNT_SHIFT                 4
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
#define CMP0_FPR                              "  CMP_FPR_REG(CMP0_BASE_PTR)
#define CMP0_SCR                                !CMP_SCRWREG(CMP0_BASU_PTR)
#define CMP0_DACCR    !         #    ((          CMP_DACCR_REG(CMP0_BASEPTR)
#define CMP2_MQXCR                              (CMP_MUXCR_REG¨CMP0_BASE_PtR)
/* CMP1 */
#define CMP1_CR0   $                           0 CMP_CR0_REG(BMP1_BASe_PTR)
#define CMP1_CR1                        0        CMP_CR1_REG(CIP1OBASE_PTR)
define CMP1_FR                                 CMP_FPR_REG(CMP1_BASE_PTR)#define CMP1_SCR !                 "             CMP_SCR_SÅG(CMP1_BASE_PTR)
#ddfine CMP1_DACCR                               CMP_DACCR_REG(CMP1_BASE_PTR)
#define!CMP1_MUXCR               $               CMP_MUXCR_REG(CMP1BASE_PDR)
/* CMĞ2 */
#define CMP2_CR0       (        !       $    "   CMP_CR0_REG(CMP2_BASE_PTR)
#Define CMP2_CR1$                                CMPßCR1_REG(CMP2_BASE_PTR)
#devine CMP2WFPR                            $    CMP^FPR_REG(CMP2_BASE_PTR)
#define(CMPr_SCR                                 CMP_SCR_REG(CMP2_BASE_PTR)
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
  uint8_t CGL2;                                 `  /**<0CMT Carrier Generator Low ata Register 2, offset:"0x3 */
 $uint8_t OC+                         ! $  $       /**< CMT Outpu$ Control Register, offsEt: 0x4!*/
  uift8_t MSC;                0                   `/**< CMT Modulatkr Stadus and Contrl Regi;ter, offset: 0x5 */
  uint8_t CMD0;             "     `                /**< CM Mïdulatoğ Data Register Mark High, kffset: 0x6 */
  uint8_t CMD2;        0          !                /**< CMT ModulAtor Data Regisôer Marë Low,!offsdt: 0ø7 */
  uint8_t CMD3;              0                     /**< CM Modulator Data Register Space High, off{et: 0x8 */
  uint8t CMD4;    (   `                           /**< CMT Modulator Data Register Space Low, offcet: 0x9 */
  uknt8_t PPS;!                                    /**< CMT Primary Prescaler Register, offset: 0xA */
  uint0_t$DMA;(                                    /**< CMT Direct Memory Access Register, nffset: 0xB */
u volatile *CMT_MgmMapPtr;

/* ----------------------------------,----------------------)------------------
   -- MT - Ragister accessor macros
 0 -----------------------------=--------------------------------------------- */

/**
 * @aDdtogroup CMT_Register_Accessor_Macroq CMT - REoister!accessor macros
 *"@{
 */


/* CMT - ReGiwter`accessors */
#define CMT_CGH1_REG(base)                  0    (8base)-<CGH1)
"dåfine CMt_CGL1_REG(base)                       ((base)->CGL1)
#define CMT_CGH2_REG(base)   0                   ((basu)->CGH2)
#defile CMT_CGL2_REg(base)         "             ((base)->CGL2)
#lefin% CMU_OC_REG(baóe)                    !    ((bace)->OC)
"define CMT_MSC_REG(baså)                        ((base)->M[C)
#define CMT_CD0_REG(base)         $             ((base)->CMD1	
#definE CMT_CMD2_REG(base)                       ((bqse©-<CML2)
#define CMT_CMD3_rEG(base)        "              ((base)->CMD3)
#defkne CMT_CMP4_REG(base)                     ¤ ((base)->CMD4)
#define CMT_pPS_REG(base	  $     (               ((base)->PPS)
#define CMT_DA_REGbase)                        ( base)->DMA)

/**
 * @}J((- /* end of group CMT_Registmr_Accessor_Macros */


/* --------------------------------------------------------)-------------------
   -- CMT Register Masks
   -------------------------------------------------------------------­------- */

/*+
 * @addtogroup CMT_Register_Masks CMT Register Maskr
 * @{
 */

/* CWH1(Bit Fields */#define CMT_CGH1_PH_MASK !                       0xFFu
#define CM\_CGH1_PH_SHIFT                    `   0
#define CMT_CGH1_PH(x)                          $(((uint8t)(((uint8_t)(x)i<<CMT_CGH±_PH_SXIFV))&CMT_CGH1_PH_MASK)
/**CGL1 Biu Fields */
#define CMT_CGL1_PL_MASK      "      0           0xFFu
#fefine CMT_CGL1_PL_SHIFT0              !        0
#define CMT_ÃGL1_PL(x)                    !  (  $((8uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_cGL1_PL_MASK)
/* ÃGH2 Bit Fields */
#define CMT_CGH2_SH_MASK                        $2xFFu
#define CMT_CGH:_SH_SHIFT  $                     0
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
    struct {                                         /* offset: 0x0 */
      uint16_t CRCL;                                   /**< CRC_CRCL register., offset: 0x0 */
      uint16_t CRCH;                                   /**< CRC_CRCH register., offset: 0x2 */
    } ACCESS16BIT;
    uint32_t CRC;                                    /**< CRC Data register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      uint8_t CRCLL;                                   /**< CRC_CRCLL register., offset: 0x0 */
      uint8_t CRCLU;                                   /**< CRC_CRCLU register., offset: 0x1 */
      uint8_t CRCHL;                                   /**< CRC_CRCHL register., offset: 0x2 */
      uint8_t CRCHU;                                   /**< CRC_CRCHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      uint16_t GPOLYL;                                 /**< CRC_GPOLYL register., offset: 0x4 */
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
  uint32_t base_DEMCR;                             /**< Debug Exception and Monitor Control Register, offset: 0xC */
} volatile *CoreDebug_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register accessors */
#define CoreDebug_base_DHCSR_Read_REG(base)      ((base)->base_DHCSR_Read)
#define CoreDebug_base_DHCSR_Write_REG(base)     ((base)->base_DHCSR_Write)
#define CoreDebug_base_DCRSR_REG(base)           ((base)->base_DCRSR)
#define CoreDebug_base_DCRDR_REG(base)           ((base)->base_DCRDR)
#define CoreDebug_base_DEMCR_REG(base)           ((base)->base_DEMCR)

/**
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CoreDebug Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Masks CoreDebug Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group CoreDebug_Register_Masks */


/* CoreDebug - Peripheral instance base addresses */
/** Peripheral CoreDebug base pointer */
#define CoreDebug_BASE_PTR                       ((CoreDebug_MemMapPtr)0xE000EDF0u)
/** Array initializer of CoreDebug peripheral base pointers */
#define CoreDebug_BASE_PTRS                      { CoreDebug_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- CoreDebug - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CoreDebug_Register_Accessor_Macros CoreDebug - Register accessor macros
 * @{
 */


/* CoreDebug - Register instance definitions */
/* CoreDebug */
#define DHCSR_Read                               CoreDebug_base_DHCSR_Read_REG(CoreDebug_BASE_PTR)
#define DHCSR_Write                              CoreDebug_base_DHCSR_Write_REG(CoreDebug_BASE_PTR)
#define DCRSR                                    CoreDebug_base_DCRSR_REG(CoreDebug_BASE_PTR)
#define DCRDR                                    CoreDebug_base_DCRDR_REG(CoreDebug_BASE_PTR)
#define DEMCR                                    CoreDebug_base_DEMCR_REG(CoreDebug_BASE_PTR)

/**
 * @}
 */ /* end of group CoreDebug_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CoreDebug_Peripheral */


/* ----------------------------------------------------------------------------
   -- DAC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Peripheral DAC
 * @{
 */

/** DAC - Peripheral register structure */
typedef struct DAC_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    uint8_t DATL;                                    /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    uint8_t DATH;                                    /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  uint8_t SR;                                      /**< DAC Status Register, offset: 0x20 */
  uint8_t C0;                                      /**< DAC Control Register, offset: 0x21 */
  uint8_t C1;                                      /**< DAC Control Register 1, offset: 0x22 */
  uint8_t C2;                                      /**< DAC Control Register 2, offset: 0x23 */
} volatile *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros
 * @{
 */


/* DAC - Register accessors */
#define DAC_DATL_REG(base,index)                 ((base)->DAT[index].DATL)
#define DAC_DATH_REG(base,index)                 ((base)->DAT[index].DATH)
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
#define DAC_C0_DACTRGSEL_MASK                    0x20u
#define DAC_C0_DACTRGSEL_SHIFT                   5
#define DAC_C0_DACRFS_MASK                       0x40u
#define DAC_C0_DACRFS_SHIFT                      6
#define DAC_C0_DACEN_MASK                        0x80u
#define DAC_C0_DACEN_SHIFT                       7
/* C1 Bit Fields */
#define DAC_C1_DACBFEN_MASK                      0x1u
#define DAC_C1_DACBFEN_SHIFT                     0
#define DAC_C1_DACBFMD_MASK                      0x6u
#define DAC_C1_DACBFMD_SHIFT                     1
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      0x18u
#define DAC_C1_DACBFWM_SHIFT                     3
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        0x80u
#define DAC_C1_DMAEN_SHIFT                       7
/* C2 Bit Fields */
#define DAC_C2_DACBFUP_MASK                      0xFu
#define DAC_C2_DACBFUP_SHIFT                     0
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      0xF0u
#define DAC_C2_DACBFRP_SHIFT                     4
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK)

/**
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base pointer */
#define DAC0_BASE_PTR                            ((DAC_MemMapPtr)0x400CC000u)
/** Peripheral DAC1 base pointer */
#define DAC1_BASE_PTR                            ((DAC_MemMapPtr)0x400CD000u)
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0_BASE_PTR, DAC1_BASE_PTR }

/* ----------------------------------------------------------------------------
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
#define DAC0_DAT4H                               DAC_DATH_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT5L                               DAC_DATL_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT5H                               DAC_DATH_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT6L                               DAC_DATL_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT6H                               DAC_DATH_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT7L                               DAC_DATL_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT7H                               DAC_DATH_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT8L                               DAC_DATL_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT8H                               DAC_DATH_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT9L                               DAC_DATL_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT9H                               DAC_DATH_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT10L                              DAC_DATL_REG(DAC0_BASE_PTR,10)
#define DAC0_DAT10H                              DAC_DATH_REG(DAC0_BASE_PTR,10)
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
#define DAC1_DAT5H                               DAC_DATH_REG(DAC1_BASE_PTR,5)
#define DAC1_DAT6L                               DAC_DATL_REG(DAC1_BASE_PTR,6)
#define DAC1_DAT6H                               DAC_DATH_REG(DAC1_BASE_PTR,6)
#define DAC1_DAT7L                               DAC_DATL_REG(DAC1_BASE_PTR,7)
#define DAC1_DAT7H                               DAC_DATH_REG(DAC1_BASE_PTR,7)
#define DAC1_DAT8L                               DAC_DATL_REG(DAC1_BASE_PTR,8)
#define DAC1_DAT8H                               DAC_DATH_REG(DAC1_BASE_PTR,8)
#define DAC1_DAT9L                               DAC_DATL_REG(DAC1_BASE_PTR,9)
#define DAC1_DAT9H                               DAC_DATH_REG(DAC1_BASE_PTR,9)
#define DAC1_DAT10L                              DAC_DATL_REG(DAC1_BASE_PTR,10)
#define DAC1_DAT10H                              DAC_DATH_REG(DAC1_BASE_PTR,10)
#define DAC1_DAT11L                              DAC_DATL_REG(DAC1_BASE_PTR,11)
#define DAC1_DAT11H                              DAC_DATH_REG(DAC1_BASE_PTR,11)
#define DAC1_DAT12L                              DAC_DATL_REG(DAC1_BASE_PTR,12)
#define DAC1_DAT12H                              DAC_DATH_REG(DAC1_BASE_PTR,12)
#define DAC1_DAT13L                              DAC_DATL_REG(DAC1_BASE_PTR,13)
#define DAC1_DAT13H                              DAC_DATH_REG(DAC1_BASE_PTR,13)
#define DAC1_DAT14L                              DAC_DATL_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT14H                              DAC_DATH_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT15L                              DAC_DATL_REG(DAC1_BASE_PTR,15)
#define DAC1_DAT15H                              DAC_DATH_REG(DAC1_BASE_PTR,15)
#define DAC1_SR                                  DAC_SR_REG(DAC1_BASE_PTR)
#define DAC1_C0                                  DAC_C0_REG(DAC1_BASE_PTR)
#define DAC1_C1                                  DAC_C1_REG(DAC1_BASE_PTR)
#define DAC1_C2                                  DAC_C2_REG(DAC1_BASE_PTR)

/* DAC - Register array accessors */
#define DAC0_DATL(index)                         DAC_DATL_REG(DAC0_BASE_PTR,index)
#define DAC1_DATL(index)                         DAC_DATL_REG(DAC1_BASE_PTR,index)
#define DAC0_DATH(index)                         DAC_DATH_REG(DAC0_BASE_PTR,index)
#define DAC1_DATH(index)                         DAC_DATH_REG(DAC1_BASE_PTR,index)

/**
 * @}
 */ /* end of group DAC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DAC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMA
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Peripheral DMA
 * @{
 */

/** DMA - Peripheral register structure */
typedef struct DMA_MemMap {
  uint32_t CR;                                     /**< Control Register, offset: 0x0 */
  uint32_t ES;                                     /**< Error Status Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  uint32_t ERQ;                                    /**< Enable Request Register, offset: 0xC */
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
  ñ×‹(ß«®Èi=É}=(¡¹à^Õ÷Ä×•YëÁíÊxæŠ%WvŸ lÛ0¶¨
·£.íı^‹\X¬NÃãzsœä:bw”¦º] <=½£¦è€	S¶,•ÜOû)j=B²À÷gßaÑKõª ¤ìµ9÷d±ÌqyØÃ:­
•ú²yA“	+Ğ´nc[	¿1>/ûü~7KQ=ÌNnÀç×¹Êxß¨Pƒ±”âıü€İq»$t£"lc4LNŸ+éø¶'İÜÉÌuÌ=²¦+†hxt m`¨&‰_†½ş–—ˆYmÀ¤şÏ §ˆ)ê)EÄåïp%şd!d}Òk\	/ÉêÚ°˜§mO–aÒN/‹Æg†	–´êŞ–ğy¹„‰&K1Èu—'½¯[_ö›ËÕØîÛÁ¤R'#gÏ—®~‚:¢ˆ6Á¿!ÅeItœ[¶¼ÃxTä#†ÌóH&C¸ÜU%TÛ™wã»S¤ÆÚb](÷i"1Pî“Û7:ÉÅæm¼ÁÇ‡"¤ÇŞ_ŞnRUv' “©cJñG?¤ƒÆ«ŠìNŒzÅûÚZ_ÒáB29aı8‚gjëúª\•®l¤`ü$L»Ö,´«ô›;í*;q
1“z"Ù8ˆÅw–iI{S¹O¿†ó$éï:		(®âCÈ1ù"öàÿóÂ€çF2Üİ¤R{kF*tæØ˜O;Ô¼b¤Pş×-ØŞÎ
èÈÂĞ‡4G2gğvNÑ^Ãg…W@³c·›|j…pfä¢˜‹n=g×~hö›X‡ öEÖÂ‚¹QÑ>Û—¹Š¹²ì®kO¢jô{¿”Âi~ËŸêòÿßŒÁ=˜àÄ|“JøÇY,qWÔó³úhÑå.Ç5¦	ğH~×6İÆXÏ^>À¸ª¦ÌU™×ô£‹àö|g¥ÓmÂâ¦C&M¤'kÚCÀÕ™;[ôÄÍ‰¹èñlXõÕ“‘ÖÏQ·±ñ¹Ëh¡Ø8uĞanx«Â4í?pÍL'/¶ˆ£ŸÃğMsÖêØ6%9šÃÓAC7bt¦Lßí]cvMCX{Z!•P öÊ»Eû¼4a¤ü|5Şì Ë[ë
Î˜İB8Tø±fıNoİU q	_û[Í	½¹—ı÷6‚üõ e(€Û9–8·'ı—YpA)7nõŞ“÷ën˜*7]—>ÄÃ¡`rÄWHô| ¦É°èYY,òGBĞ#~à$Ìô>)*ÚLÅõªdıW++i)Ô§Ûô)LÇ=û#yÏ¢~Ú›,È¸å9›Ó¯ßtÙØi=…|Ô4DÊOƒh€‡´é_ò6şs%ô°¢°ñ×‹(ß«®Èi=É}=(¡¹à^Õ÷Ä×•YëÁíÊxæŠ%WvŸ lÛ0¶¨
·£.íı^‹\X¬NÃãzsœä:bw”¦º] <=½£¦è€	S¶,•ÜOû)j=B²À÷gßaÑKõª ¤ìµ9÷d±ÌqyØÃ:­
•ú²yA“	+Ğ´nc[	¿1>/ûü~7KQ=ÌNnÀç×¹Êxß¨Pƒ±”âıü€İq»$t£"lc4LNŸ+éø¶'İÜÉÌuÌ=²¦+†hxt m`¨&‰_†½ş–—ˆYmÀ¤şÏ §ˆ)ê)EÄåïp%şd!d}Òk\	/ÉêÚ°˜§mO–aÒN/‹Æg†	–´êŞ–ğy¹„‰&K1Èu—'½¯[_ö›ËÕØîÛÁ¤R'#gÏ—®~‚:¢ˆ6Á¿!ÅeItœ[¶¼ÃxTä#†ÌóH&C¸ÜU%TÛ™wã»S¤ÆÚb](÷i"1Pî“Û7:ÉÅæm¼ÁÇ‡"¤ÇŞ_ŞnRUv' “©cJñG?¤ƒÆ«ŠìNŒzÅûÚZ_ÒáB29aı8‚gjëúª\•®l¤`ü$L»Ö,´«ô›;í*;q
1“z"Ù8ˆÅw–iI{S¹O¿†ó$éï:		(®âCÈ1ù"öàÿóÂ€çF2Üİ¤R{kF*tæØ˜O;Ô¼b¤Pş×-ØŞÎ
èÈÂĞ‡4G2gğvNÑ^Ãg…W@³c·›|j…pfä¢˜‹n=g×~hö›X‡ öEÖÂ‚¹QÑ>Û—¹Š¹²ì®kO¢jô{¿”Âi~ËŸêòÿßŒÁ=˜àÄ|“JøÇY,qWÔó³úhÑå.Ç5¦	ğH~×6İÆXÏ^>À¸ª¦ÌU™×ô£‹àö|g¥ÓmÂâ¦C&M¤'kÚCÀÕ™;[ôÄÍ‰¹èñlXõÕ“‘ÖÏQ·±ñ¹Ëh¡Ø8uĞanx«Â4í?pÍL'/¶ˆ£ŸÃğMsÖêØ6%9šÃÓAC7bt¦Lßí]cvMCX{Z!•P öÊ»Eû¼4a¤ü|5Şì Ë[ë
Î˜İB8Tø±fıNoİU q	_û[Í	½¹—ı÷6‚üõ e(€Û9–8·'ı—YpA)7nõŞ“÷ën˜*7]—>ÄÃ¡`rÄWHô| ¦É°èYY,òGBĞ#~à$Ìô>)*ÚLÅõªdıW++i)Ô§Ûô)LÇ=û#yÏ¢~Ú›,È¸å9›Ó¯ßtÙØi=…|Ô4DÊOƒh€‡´é_ò6şs%ô°¢°ine DMA_ES_REG(base)                         ((base)->ES)
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
#define DMA_SEEI_NOP_MASK                        0x80u
#define DMA_SEEI_NOP_SHIFT                       7
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                       0xFu
#define DMA_CERQ_CERQ_SHIFT                      0
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       0x40u
#define DMA_CERQ_CAER_SHIFT                      6
#define DMA_CERQ_NOP_MASK                        0x80u
#define DMA_CERQ_NOP_SHIFT                       7
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                       0xFu
#define DMA_SERQ_SERQ_SHIFT                      0
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       0x40u
#define DMA_SERQ_SAER_SHIFT                      6
#define DMA_SERQ_NOP_MASK                        0x80u
#define DMA_SERQ_NOP_SHIFT                       7
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                       0xFu
#define DMA_CDNE_CDNE_SHIFT                      0
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       0x40u
#define DMA_CDNE_CADN_SHIFT                      6
#define DMA_CDNE_NOP_MASK                        0x80u
#define DMA_CDNE_NOP_SHIFT                       7
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                       0xFu
#define DMA_SSRT_SSRT_SHIFT                      0
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       0x40u
#define DMA_SSRT_SAST_SHIFT                      6
#define DMA_SSRT_NOP_MASK                        0x80u
#define DMA_SSRT_NOP_SHIFT                       7
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                       0xFu
#define DMA_CERR_CERR_SHIFT                      0
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       0x40u
#define DMA_CERR_CAEI_SHIFT                      6
#define DMA_CERR_NOP_MASK                        0x80u
#define DMA_CERR_NOP_SHIFT                       7
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                       0xFu
#define DMA_CINT_CINT_SHIFT                      0
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       0x40u
#define DMA_CINT_CAIR_SHIFT                      6
#define DMA_CINT_NOP_MASK                        0x80u
#define DMA_CINT_NOP_SHIFT                       7
/* INT Bit Fields */
#define DMA_INT_INT0_MASK                        0x1u
#define DMA_INT_INT0_SHIFT                       0
#define DMA_INT_INT1_MASK                        0x2u
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
#define DMA_ERR_ERR13_MASK                       0x2000u
#define DMA_ERR_ERR13_SHIFT                      13
#define DMA_ERR_ERR14_MASK                       0x4000u
#define DMA_ERR_ERR14_SHIFT                      14
#define DMA_ERR_ERR15_MASK                       0x8000u
#define DMA_ERR_ERR15_SHIFT                      15
/* HRS Bit Fields */
#define DMA_HRS_HRS0_MASK                        0x1u
#define DMA_HRS_HRS0_SHIFT                       0
#define DMA_HRS_HRS1_MASK                        0x2u
#define DMA_HRS_HRS1_SHIFT                       1
#define DMA_HRS_HRS2_MASK                        0x4u
#define DMA_HRS_HRS2_SHIFT                       2
#define DMA_HRS_HRS3_MASK                        0x8u
#define DMA_HRS_HRS3_SHIFT                       3
#define DMA_HRS_HRS4_MASK                        0x10u
#define DMA_HRS_HRS4_SHIFT                       4
#define DMA_HRS_HRS5_MASK                        0x20u
#define DMA_HRS_HRS5_SHIFT                       5
#define DMA_HRS_HRS6_MASK                        0x40u
#define DMA_HRS_HRS6_SHIFT                       6
#define DMA_HRS_HRS7_MASK                        0x80u
#define DMA_HRS_HRS7_SHIFT                       7
#define DMA_HRS_HRS8_MASK                        0x100u
#define DMA_HRS_HRS8_SHIFT                       8
#define DMA_HRS_HRS9_MASK                        0x200u
#define DMA_HRS_HRS9_SHIFT                       9
#define DMA_HRS_HRS10_MASK                       0x400u
#define DMA_HRS_HRS10_SHIFT                      10
#define DMA_HRS_HRS11_MASK                       0x800u
#define DMA_HRS_HRS11_SHIFT                      11
#define DMA_HRS_HRS12_MASK                       0x1000u
#define DMA_HRS_HRS12_SHIFT                      12
#define DMA_HRS_HRS13_MASK                       0x2000u
#define DMA_HRS_HRS13_SHIFT                      13
#define DMA_HRS_HRS14_MASK                       0x4000u
#define DMA_HRS_HRS14_SHIFT                      14
#define DMA_HRS_HRS15_MASK                       0x8000u
#define DMA_HRS_HRS15_SHIFT                      15
/* DCHPRI3 Bit Fields */
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
#define DMA_DCHPRI9_DPA_SHIFT                    6
#define DMA_DCHPRI9_ECP_MASK                     0x80u
#define DMA_DCHPRI9_ECP_SHIFT                    7
/* DCHPRI8 Bit Fields */
#define DMA_DCHPRI8_CHPRI_MASK                   0xFu
#define DMA_DCHPRI8_CHPRI_SHIFT                  0
#define DMA_DCHPRI8_CHPRI(x)                     (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI8_CHPRI_SHIFT))&DMA_DCHPRI8_CHPRI_MASK)
#define DMA_DCHPRI8_DPA_MASK                     0x40u
#define DMA_DCHPRI8_DPA_SHIFT                    6
#define DMA_DCHPRI8_ECP_MASK                     0x80u
#define DMA_DCHPRI8_ECP_SHIFT                    7
/* DCHPRI15 Bit Fields */
#define DMA_DCHPRI15_CHPRI_MASK                  0xFu
#define DMA_DCHPRI15_CHPRI_SHIFT                 0
#define DMA_DCHPRI15_CHPRI(x)                    (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI15_CHPRI_SHIFT))&DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DCHPRI15_DPA_MASK                    0x40u
#define DMA_DCHPRI15_DPA_SHIFT                   6
#define DMA_DCHPRI15_ECP_MASK                    0x80u
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
#define DMA_ATTR_DSIZE_MASK                      0x7u
#define DMA_ATTR_DSIZE_SHIFT                     0
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       0xF8u
#define DMA_ATTR_DMOD_SHIFT                      3
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      0x700u
#define DMA_ATTR_SSIZE_SHIFT                     8
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       0xF800u
#define DMA_ATTR_SMOD_SHIFT                      11
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK)
/* NBYTES_MLNO Bit Fields */
#define DMA_NBYTES_MLNO_NBYTES_MASK              0xFFFFFFFFu
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK)
/* NBYTES_MLOFFNO Bit Fields */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           0x3FFFFFFFu
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          0
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            0x40000000u
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            0x80000000u
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31
/* NBYTES_MLOFFYES Bit Fields */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          0x3FFu
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         0
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           0x3FFFFC00u
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
#define DMA_DOFF_DOFF_MASK                       0xFFFFu
#define DMA_DOFF_DOFF_SHIFT                      0
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK)
/* CITER_ELINKNO Bit Fields */
#define DMA_CITER_ELINKNO_CITER_MASK             0x7FFFu
#define DMA_CITER_ELINKNO_CITER_SHIFT            0
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15
/* CITER_ELINKYES Bit Fields */
#define DMA_CITER_ELINKYES_CITER_MASK            0x1FFu
#define DMA_CITER_ELINKYES_CITER_SHIFT           0
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15
/* DLAST_SGA Bit Fields */
#define DMA_DLAST_SGA_DLASTSGA_MASK              0xFFFFFFFFu
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             0
#define DMA_DLAST_SGA_DLASTSGA(x)                (((uint32_t)(((uint32_t)(x))<<DMA_DLAST_SGA_DLASTSGA_SHIFT))&DMA_DLAST_SGA_DLASTSGA_MASK)
/* CSR Bit Fields */
#define DMA_CSR_START_MASK                       0x1u
#define DMA_CSR_START_SHIFT                      0
#define DMA_CSR_INTMAJOR_MASK                    0x2u
#define DMA_CSR_INTMAJOR_SHIFT                   1
#define DMA_CSR_INTHALF_MASK                     0x4u
#define DMA_CSR_INTHALF_SHIFT                    2
#define DMA_CSR_DREQ_MASK                        0x8u
#define DMA_CSR_DREQ_SHIFT                       3
#define DMA_CSR_ESG_MASK                         0x10u
#define DMA_CSR_ESG_SHIFT                        4
#define DMA_CSR_MAJORELINK_MASK                  0x20u
#define DMA_CSR_MAJORELINK_SHIFT                 5
#define DMA_CSR_ACTIVE_MASK                      0x40u
#define DMA_CSR_ACTIVE_SHIFT                     6
#define DMA_CSR_DONE_MASK                        0x80u
#define DMA_CSR_DONE_SHIFT                       7
#define DMA_CSR_MAJORLINKCH_MASK                 0xF00u
#define DMA_CSR_MAJORLINKCH_SHIFT                8
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         0xC000u
#define DMA_CSR_BWC_SHIFT                        14
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK)
/* BITER_ELINKNO Bit Fields */
#define DMA_BITER_ELINKNO_BITER_MASK             0x7FFFu
#define DMA_BITER_ELINKNO_BITER_SHIFT            0
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK)
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
/** Peripheral DMA base pointer */
#define DMA_BASE_PTR                             ((DMA_MemMapPtr)0x40008000u)
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros
 * @{
 */


/* DMA - Register instance definitions */
/* DMA */
#define DMA_CR                                   DMA_CR_REG(DMA_BASE_PTR)
#define DMA_ES                                   DMA_ES_REG(DMA_BASE_PTR)
#define DMA_ERQ                                  DMA_ERQ_REG(DMA_BASE_PTR)
#define DMA_EEI                                  DMA_EEI_REG(DMA_BASE_PTR)
#define DMA_CEEI                                 DMA_CEEI_REG(DMA_BASE_PTR)
#define DMA_SEEI                                 DMA_SEEI_REG(DMA_BASE_PTR)
#define DMA_CERQ                                 DMA_CERQ_REG(DMA_BASE_PTR)
#define DMA_SERQ                                 DMA_SERQ_REG(DMA_BASE_PTR)
#define DMA_CDNE                                 DMA_CDNE_REG(DMA_BASE_PTR)
#define DMA_SSRT                                 DMA_SSRT_REG(DMA_BASE_PTR)
#define DMA_CERR                                 DMA_CERR_REG(DMA_BASE_PTR)
#define DMA_CINT                                 DMA_CINT_REG(DMA_BASE_PTR)
#define DMA_INT                                  DMA_INT_REG(DMA_BASE_PTR)
#define DMA_ERR                                  DMA_ERR_REG(DMA_BASE_PTR)
#define DMA_HRS                                  DMA_HRS_REG(DMA_BASE_PTR)
#define DMA_DCHPRI3                              DMA_DCHPRI3_REG(DMA_BASE_PTR)
#define DMA_DCHPRI2                              DMA_DCHPRI2_REG(DMA_BASE_PTR)
#define DMA_DCHPRI1                              DMA_DCHPRI1_REG(DMA_BASE_PTR)
#define DMA_DCHPRI0                              DMA_DCHPRI0_REG(DMA_BASE_PTR)
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
#define DMA_TCD0_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_CSR                             DMA_CSR_REG(DMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,0)
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
#define DMA_TCD2_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_CSR                             DMA_CSR_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,2)
#define DMA_TCD3_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_–í°K¦¤Ô9-ê$R¡ÊÑ8Ÿ:ã«²«- Oô#|hmx±İY$ÇÈ‰jÀÁ\×§cå3ÑÎ¸‰=|Î|HÖ¾Es¯>_^9r©Ap
:2ÃªàqWÏgÃ‰XLË‚lÆ5%÷ÂôÏrC|GTÇ@è™EoŸÎVÀåZs.Â«µ›(ÕMâ•ÖÛËäØå4ˆpóEÊµò,Ï$Œ­-÷Ú‰x8Z‡ù’QÔõ6W÷İ;ÍÄæ*oF†Î‡,æş™s0w#ÂŞº u× /}	‹lm7 ½?ö
Q>òƒ›¾ñäÇú§+µüaÑDYZÛq}Ú£—¤œ/pñ‚Qöuk{(±rÃiòUy¶=‘P{[İĞÑr¼Z=3OÒ+{“~Èì¤425çúIÓ®–cw+é‡½£3Çî‹|IßàòıùSİğ@“§'å‘- [Ú0£(t	‰f~tòsšæõÅ‰xL±uM-Š=D?) ØÈÑÃĞle~¤zs6Š¶üææ/._/¶1äË+9ÇÆSêa£­)¦D–â¤Æ²%¿_şÇ‰lx„´ÿ]nó¿	sœTTEqñ¡ïÏêåº¬Ë
4š~¨µ\ü#)«;û]ŞÎ¸f <aÆm¤¸\·Ár[ØtáXh4@Â¸R(ˆ[æµ2"4y‹ôjSû¯øÊIÑÊ‡áF
Mâ×óšŸgy"â„Ñ/#ÈÄ†=±š¿¹-éˆàfïŞG+|ë9PíN!¯F}ÌªBW>‰õ~ŠZŞ/¨<và€5Ã)‘²½bÙ>¹0uÃTÊ(ÑÅOßÍÿTënïÄç\4ø$8ƒ_.èjFWå©ÈÌÎË…IKok'›nz>¸ñ­º¨Q€ŠøÍ.İ_m£WÚCêË@ÌØ¶v™‡)ıy¦¡«Ytİê„å_âÙu·úäô[óÎ@öÑIÒ2€ŒÛšl÷ºF`¬&áeñıyÂİ¸+rÒBZƒƒK^*|ô™ 4…dSzµEÑë"õš/'>Ú£I›ıÂæK&¥9ÙœšÓßs@L4Å@$š@hDÔû ZhS')»é§V×vF‰ğÚÁfhNúls–`iÈ+ „z—tèGX6IuØıâİ³Ã	8w½ÔŒ÷,¤ù¼ÿ¾:<4Åå „¦7'|–fe©èŠ±‰ps¥#Ë^~qªÎ+{Ì$'¦q°GÌo0Ñ·È.â£ÅŒøÖÿŸÁ–—WPC;6»«Oß`X’ÄÊ¹óL›æÁ¤~¹ôfœ )¥t¯³KèçZæÔ@šĞâ  ¯62ç—‰L=ì*ÌW¾Y
#define DMA_TCD4_ATTR                            DMA_ATTR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_CSR                             DMA_CSR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,4)
#define DMA_TÇ~% gnKğsW$¡PJü,¦}àfB!e~ıjCÚ!op´ÖÕ°Rñ—To­Œ\î®ÉîÿpgÙB1#>uRââá¢æqh©Şiû¶MZ»É
S0Å¸~%½(A6}ŞÈPläNè{ş*C7Æ;şdÆ«Ùñq)æEGg|„øTÉu+ëë%R´ü<fAí.Ô}0æƒªĞ~)›¯®lc6üí+ôùB`*=* >%2ïù/±í‚ŠÏ¡//ì—kP‚¬ãz*O(¥œDîÜÚ#ûÖä`É{5TÌ53\hœºû´;ù¬‚Ä½ÎÎw	èŒLpB‡ìëjÂ‰H‡“:§†14ôÌÂ\ôÅ Vû*®`¥S_úË?f;_ #TîáÇİXî}I¢”ùYRš‰W8{ãÉaØz&„MbÅçÊzŠ‰Ä¦;,/Ã¯k¨_Ó/ŠÃ©ö-¿ÌZwhé™R^4÷ªâ9zî'*qtÇĞ}—`ŞCìlÀÖ×÷¶OğÔªçN¨~é»@!Chƒ’Üßge¥·ü1wÒ‹ö*vñW%a­mÔá"Ë…Gíï¡'<£›zDÖ2h—·_ƒˆ343D5N¡9‚Ö\³ØÚ,^ä¼ÎãmÒjÌÇ@ôY®H™o£­ÆıF¸Ãğíúf¶óıPg3xà<…=ãˆùÜDF;$ÿuò´ËP•ZJ n\ãï„ÀˆÌ+‰ˆ4›ì=nú-.l‹õ¯6bK'–ˆğI–£ZÁ»÷{  ”FoVGÄ†R·÷SN-Ãí,ÍÜ”‰]-‘Æ@(™ÀiVÒîNÚ£ÌôT‚é¸PËšùQÎCÆv)Ğ¹-à(®øÇvÅ#“ÅÄ÷é©ê²CÈ"|æ*j)².€ûĞ%[ÉÀ¬¼ 8\jÜ¢7ü³ÑÀâN³G/>ø
=ó*{ÊZ¼FûZD•Cµelı™2SBí²ÿr‘1ˆ·n]ëûÇ¥-ü>Í:¶ğ*Ì†Z{:Tš0±n~¡s— g\Çbƒ5ÆğÚA%¯µş5ïŞ;“[vóo3ÈøhÂIôò
ï7sÔPTwa‰%TÍ„£iB±vBgqµÜÌ°rNUÙ?Ğ:xFPØ¾ƒ¥²¾›Ü’:tå
éı»âÉF.8Â	Î‰×¿ÃÖ{On¦@„=Qt4ğ_ÿéP°LûÕheˆealùSN½Ñ,xbG,yŸÛ ¦§3blq¦„ÔXZu{*ğ,è©æÓšÅ*~OáÈdç´³3e–‡ËëJğı±×U-a4È¾_›4@[ßÙÄ‚ÕÏ»±g_dÛÍ                    DMA_DLAST_SGA_REG(DMA_BASE_PTR,5)
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
#define DMA_Ç~% gnKğsW$¡PJü,¦}àfB!e~ıjCÚ!op´ÖÕ°Rñ—To­Œ\î®ÉîÿpgÙB1#>uRââá¢æqh©Şiû¶MZ»É
S0Å¸~%½(A6}ŞÈPläNè{ş*C7Æ;şdÆ«Ùñq)æEGg|„øTÉu+ëë%R´ü<fAí.Ô}0æƒªĞ~)›¯®lc6üí+ôùB`*=* >%2ïù/±í‚ŠÏ¡//ì—kP‚¬ãz*O(¥œDîÜÚ#ûÖä`É{5TÌ53\hœºû´;ù¬‚Ä½ÎÎw	èŒLpB‡ìëjÂ‰H‡“:§†14ôÌÂ\ôÅ Vû*®`¥S_úË?f;_ #TîáÇİXî}I¢”ùYRš‰W8{ãÉaØz&„MbÅçÊzŠ‰Ä¦;,/Ã¯k¨_Ó/ŠÃ©ö-¿ÌZwhé™R^4÷ªâ9zî'*qtÇĞ}—`ŞCìlÀÖ×÷¶OğÔªçN¨~é»@!Chƒ’Üßge¥·ü1wÒ‹ö*vñW%a­mÔá"Ë…Gíï¡'<£›zDÖ2h—·_ƒˆ343D5N¡9‚Ö\³ØÚ,^ä¼ÎãmÒjÌÇ@ôY®H™o£­ÆıF¸Ãğíúf¶óıPg3xà<…=ãˆùÜDF;$ÿuò´ËP•ZJ n\ãï„ÀˆÌ+‰ˆ4›ì=nú-.l‹õ¯6bK'–ˆğI–£ZÁ»÷{  ”FoVGÄ†R·÷SN-Ãí,ÍÜ”‰]-‘Æ@(™ÀiVÒîNÚ£ÌôT‚é¸PËšùQÎCÆv)Ğ¹-à(®øÇvÅ#“ÅÄ÷é©ê²CÈ"|æ*j)².€ûĞ%[ÉÀ¬¼ 8\jÜ¢7ü³ÑÀâN³G/>ø
=ó*{ÊZ¼FûZD•Cµelı™2SBí²ÿr‘1ˆ·n]ëûÇ¥-ü>Í:¶ğ*Ì†Z{:Tš0±n~¡s— g\Çbƒ5ÆğÚA%¯µş5ïŞ;“[vóo3ÈøhÂIôò
ï7sÔPTwa‰%TÍ„£iB±vBgqµÜÌ°rNUÙ?Ğ:xFPØ¾ƒ¥²¾›Ü’:tå
éı»âÉF.8Â	Î‰×¿ÃÖ{On¦@„=Qt4ğ_ÿéP°LûÕheˆealùSN½Ñ,xbG,yŸÛ ¦§3blq¦„ÔXZu{*ğ,è©æÓšÅ*~OáÈdç´³3e–‡ËëJğı±×U-a4È¾_›4@[ßÙÄ‚ÕÏ»±g_dÛÍ                DMA_CSR_REG(DMA_BASE_PTR,9)
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
#define DMA_TCD12_NBYTES_MLNO                    DMA_NBYTES_MLNO_REE(DMA_BASEPTR,12)
#äefine DMA_TCD12_NBXTES_MLOFFNO                 dMQ_NBYTES_MLOFFNO_REG(DMA_CASE_PÔR,12)
#tefine DMA_TCD12_NBYTES_MLOFFYES          0     DMA_OBYTES_MLOFFYES_REG(DIA_BASE_PTR,12)
#define DMA_TCD12_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DADDR                  `       DMA_DADDR_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_DOFF    (       !              DMA_DOFF_REG(DMA_BASM_PTR,1r)
#define DMA_TCD12_CITER_ELINJNO                  DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKYES                 DIA_CITER_ELKJKYS_REO(DMA_BASE_PTR,12)
#define DMI_TCD12_DLASTSGA                       DOA_DLAS_SGA_REG(DMA_BESE_PTR,12)
'define DMA_PCD12_CsR              0*          0 DMA_CSR_REG(DMA_BA[E_PTR<12)
#define(DMA_TCD12_BITER_GLINKNO                $ DOA_BITER_ELINKNO_REG(DM_BASE_PUR,12)
#define DMQ_TCD12_BKTER_ELIKYEC      !          DMA_BITER_ELINJYES_REG(DMA_BASE_PTR,12)
#$efine DMA_TCD13_SADDR                          DMA_SADDR_REG(DMA_BASE_PTR,13)
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
#define DMA_TCD13_BIUER_ELINKNO             "    DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,13)
#definå DMA_TCD13_BITER_ELINKYES!        0      DMA_BITER[ELINKYES_REG(DMA_BASE_PTR,13)
#define DMA_DCD14_SADDR      `      (            DMA_SADDRWREG)DMA_BASE_PTR,14)
#define DEA_TCD14_SOÆF       4                  DA_SOFF_REG(DMA_BASE_PTR$14)
#define DMA_TCD14_ATTR                           DMA_ATTR_REG(DMA_BASE_PTR,14)#define DMA_UCD94_NBYTES_MLNO             (      DMA_NBYTUS_MLNOREG(DMA_BASE_PTR.14)
#define DMA_TCD14_NBYTES_MLONFNO   !             DMa_NBYTES_MLOFFNOOREE(DMA_BASEOPTR,14)
#define"DMA_TCD1t_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYEÓŞREG(DMA_BASE_PTR,14)
#define DMA_TCD14_SLAST                         "DMA_SLaST_REG(DMA_BASE_PTR,14)
#define(DMA_TCD14_DADDR                          DMAOTADDR_REG(DMaßBASE_PTR,14)
#dafine DMA_TCD14_DMFF                        "  DMA_DOFFREG(DMA_RASEWPTR,14)
#defIne DMA_TCD14_CITER_ELINKN_                  DMA_CITER_ELÉNKNO_REG(DMA_BASE_PTR,14)
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
#define DMA_TCD15_SLAST                          DMA_SLAST_REG(DMA_BASE_PTR,15)#define DmA_TCD15_DQDDR  (     !                 DMÁ_DADDB_REG(DMA_BASE_PTR,11)
#define DMA_TCD15_DOFF           `               DMA_DOFF_REG(DMA_BASE_PTR,15)
#define TMA_TCD15_CÉTEB_ELINKNO            0     DMA_CiUER_ELINKNO_REG(DMA_BASE_PTR,15i
#dmfine DMA_TCD15_CITER_ELINKYEC                 ÄLA_CITER_ELINKYES_REG(DMA_BASE_PTR,15(
#define DMA_TCD15_DLASTSGI                       DMA_DLASTßSGA_REG(DMA_BASE_PTR,15)
#define DMA_TCD15_CSR0        $    `             DMA_CSR_REE(DMA_BASE_PTR,15)
3define DMA_TCD15_BITER_ELINKNO       !     (    DMA_BITER_ULINKNO_REG(LMA_BASE_PTR,15)
#defin% DMA_TCD15_BITER_EDINKYES              "  DMA_BITER_ÅLINKYESßREG(DMA_BASE_PTR,15)

/* DMA - Regéstev apray accessors */
#define DMA_SADDR(index)  (           "        ( DMA_SADDR_REGDMA_BASE_PTR,index)
#denine DMA_SOFF(index)                 b        DMA_SOFF_BMG(DMA_BASE_PTR,index)
#define DMA_ATTR(index)                !         DMA_ATTR_REG(DMA_BASE_P\R,index)
#define DMA_NBYTES_MLNO)index) 0       "         DMA_NBZTES_MLNO_REG(DMI_BASE_PTR,inäex)
#define DMA_NBYTES_MLOFFNO(index)       `        DMA_NBYTES_MLOFFNO_REG DMA_BASE_PTR,index)
#defmne DMA_NBYTES_MLÏFFYES(indez)               DMA_NBYTESOMLOFFYES_REGèDMABASE_PTR,index)#defhne DMA_SLAST(index)         !      !        DEA_SLAST_REG(DMA_BASE_PTR,index)
#dafine DME_DADDR(index)                         DMA_DADDR_REG(DMA_BASE_PTR,ifdex)
#define DMA_DOF&(index(                       0  DMA_DOFF_RGG(LMA_BASE_PTR,index)
#fefine DMA_CITER_ELINKNO(indep)      "          DME_CITER_ELINKNO_REG(DMA_BASG_PTR,index)
#define DMA_CIER_ELINKYES(index)         `      DMA_GITER_ELINKYES_REG(DMA_BASE_PTR,index)
#define DMA_DL@ST_SGA(intex)   $       `         DME_DLAST^SGA_REG(DMA_BASE_PTR,index)
#devine DMA_CSR(index)   $              `  0   " DMA_CSR_VEG(DMA_BASE_PTR,index)
#define DMABITE_ELINKNO(index!       `         @MA_BITER_ELKNINO_REG(DMA_BASE_PTR,index)
#define DMA_BITER_ELINKYES(index)         0      DMA_BITR_ELMNKYES_REG(DMA_BASE_PTR,index)

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
  uint32_t FOLDCNT;                                /**< Folded-instruction Count Register, offset: 0x18 */
  uint32_t PCSR;                                   /**< Program Counter Sample Register, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x10 */
    uint32_t COMP;                                   /**< Comparator Register 0..Comparator Register 3, array offset: 0x20, array step: 0x10 */
    uint32_t MASK;                                   /**< Mask Register 0..Mask Register 3, array offset: 0x24, array step: 0x10 */
    uint32_t FUNCTION;                               /**< Function Register 0..Function Register 3, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } COMPARATOR[4];
  uint8_t RESERVED_0[3952];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
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
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_7[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
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
  uint32_t CIDR2;                     À$»á©z×îCß>ã˜ï*
(Z"jù~Š‚HÂşá­´ewbº±4ÿ˜&"tÆ]Æ×€‘f©K­ËJ2òÕ(&«ÏÂ×Ø«ÿI>ıœıïç¨eÆP¤>Ø³Ô}4Kÿí¤J½é¸/š–úü¤h-S‡?÷&TR"*m9êssÿ5#WÇØ7fËı¾à`ÇÏQş¿WdÙò4†œõå?îVıÿ9`öQ×^Üp½Bò	u•è¼‰s¥,Ğ¬Ğ–vå„‹IÅ©\Æ” ™¯£\ŒQµqÌ@vE›=:gZéj ˆÑx^ÏËZ{v:âàŞƒ¾ZkO˜{šÅr¹+pÑRöO¿ÄÁÄ"0›ï¬gi
ÔI6 $”äöŒü 9Z'
uE`Ç@‚)H%Î¡—Òë¿$^æÃOß‡tõòF¥¹œ]Ä1ÂØ
«\-Â*ïû g=xÿ¹Ç›¾Û œEºşàQ~oˆò·«‹ì ™Ò`äŠoBãœ‰§«Ü4Uòá#–:Kªñ{ïÛ¶¿;XÃ"”ıWŸ5•U0·†ÇñVh»ó~Ù<ÕıW1*ÕÉšß”«Â¾z(åÀÕBíL_tİh»Û¤MËÒMMq¨F$s´r@x÷úY™r­D"$Üÿœ:j‹õ´ì
×”â&xÁzV¦Gy^œ‰0VRÉ¿›e»ûä-|ÇNoú>W/I†Š™Ô1çêñ5ds-ÕÑ'k=\¬7*÷‚kCÌ/¦KÁN‘áqM7¦çˆ8İT³‘ñ˜ëü.³±øËÄMßLDÄk‘eçfXìá„0râôFÒMˆbb?­À¼&Àc'G§­kÒE×Zš.”Jó^Z•„?óÍñºŞº™bpq¼ø‹X«wT–OæŸN·µ^NP¶×8D¸ŞKÎ+“×šXÓq¸‰¶ Ğ·Örs6ºä$¦L èô¡·!äÕÛË˜l÷Qh4—¬¯'!J×ŞÃ«Ú¡p"ßE¼@h”àUŠ›ÃÇ¾/4$œ™x]*ÁÅQŸp†7qÏBuö²İ°ÁX:hÉ,‰9ßƒ^d‚+Y?oÅ±ÜÖó¶ã;›Ûüq¬Nİ¶õvÆ|e{pèëÿ,Tå…Nå™L®õå¶ÙÍ*Ú­w²/cI­()è]2¤ıCzÓİ.0'Ú‚p–¸oÓèi²Şä¦> ½-É:“}wlÆï[ETÊyå*ÊTµ;•eÎÅVóŸª”¨ƒ=o6I9ävã9¨ô÷»PPå©“+@&£™C?¢º¾%                     ((base)->RWD)
#define ETB_FFSR_REG(base)                       ((base)->FFSR)
#define ETB_FFCR_REG(base)                       ((base)->FFCR)
#define ETB_ITMISCOP0_REG(base)                  ((base)->ITMISCOP0)
#define ETB_ITTRFLINACK_REG(base)                ((base)->ITTRFLINACK)
#define ETB_ITTRFLIN_REG(base)                   ((base)->ITTRFLIN)
#define ETB_ITATBDATA0_REG(base)                 ((base)->ITATBDATA0)
#define ETB_ITATBCTR2_REG(base)                  ((base)->ITATBCTR2)
#define ETB_ITATBCTR1_REG(base)                  ((base)->ITATBCTR1)
#define ETB_ITATBCTR0_REG(base)                  ((base)->ITATBCTR0)
#define ETB_ITCTRL_REG(base)                     ((base)->ITCTRL)
#define ETB_CLAIMSET_REG(base)                   ((base)->CLAIMSET)
#define ETB_CLAIMCLR_REG(base)                   ((base)->CLAIMCLR)
#define ETB_LAR_REG(base)                        ((base)->LAR)
#define ETB_LSR_REG(base)                        ((base)->LSR)
#define ETB_AUTHSTATUS_REG(base)                 ((base)->AUTHSTATUS)
#define ETB_DEVID_REG(base)                      ((base)->DEVID)
#define ETB_DEVTYPE_REG(base)                    ((base)->DEVTYPE)
#define ETB_PIDR4_REG(base)                      ((base)->PIDR4)
#define ETB_PIDR5_REG(base)                      ((base)->PIDR5)
#define ETB_PIDR6_REG(base)                      ((base)->PIDR6)
#define ETB_PIDR7_REG(base)                      ((base)->PIDR7)
#define ETB_PIDR0_REG(base)                      ((base)->PIDR0)
#define ETB_PIDR1_REG(base)                      ((base)->PIDR1)
#define ETB_PIDR2_REG(base)                      ((base)->PIDR2)
#define ETB_PIDR3_REG(base)                      ((base)->PIDR3)
#define ETB_CIDR0_REG(base)                      ((base)->CIDR0)
#define ETB_CIDR1_REG(base)                      ((base)->CIDR1)
#define ETB_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETB_CIDR3_REG(base)                      ((base)->CIDR3)

/**
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Masks ETB Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETB_Register_Masks */


/* ETB - Peripheral instance base addresses */
/** Peripheral ETB base pointer */
#define ETB_BASE_PTR                             ((ETB_MemMapPtr)0xE0042000u)
/** Array initializer of ETB peripheral base pointers */
#define ETB_BASE_PTRS                            { ETB_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register instance definitions */
/* ETB */
#define ETB_RDP                                  ETB_RDP_REG(ETB_BASE_PTR)
#define ETB_STS                                  ETB_STS_REG(ETB_BASE_PTR)
#define ETB_RRD                                  ETB_RRD_REG(ETB_BASE_PTR)
#define ETB_RRP                                  ETB_RRP_REG(ETB_BASE_PTR)
#define ETB_RWP                                  ETB_RWP_REG(ETB_BASE_PTR)
#define ETB_TRG                                  ETB_TRG_REG(ETB_BASE_PTR)
#define ETB_CTL                                  ETB_CTL_REG(ETB_BASE_PTR)
#define ETB_RWD                                  ETB_RWD_REG(ETB_BASE_PTR)
#define ETB_FFSR                                 ETB_FFSR_REG(ETB_BASE_PTR)
#define ETB_FFCR                                 ETB_FFCR_REG(ETB_BASE_PTR)
#define ETB_ITMISCOP0                            ETB_ITMISCOP0_REG(ETB_BASE_PTR)
#define ETB_ITTRFLINACK                          ETB_ITTRFLINACK_REG(ETB_BASE_PTR)
#define ETB_ITTRFLIN                             ETB_ITTRFLIN_REG(ETB_BASE_PTR)
#define ETB_ITATBDATA0                           ETB_ITATBDATA0_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR2                            ETB_ITATBCTR2_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR1                            ETB_ITATBCTR1_REG(ETB_BASE_PTR)
#define ETB_ITATBCTR0                            ETB_ITATBCTR0_REG(ETB_BASE_PTR)
#define ETB_ITCTRL                               ETB_ITCTRL_REG(ETB_BASE_PTR)
#define ETB_CLAIMSET                             ETB_CLAIMSET_REG(ETB_BASE_PTR)
#define ETB_CLAIMCLR                             ETB_CLAIMCLR_REG(ETB_BASE_PTR)
#define ETB_LAR                                  ETB_LAR_REG(ETB_BASE_PTR)
#define ETB_LSR                                  ETB_LSR_REG(ETB_BASE_PTR)
#define ETB_AUTHSTATUS                           ETB_AUTHSTATUS_REG(ETB_BASE_PTR)
#define ETB_DEVID                                ETB_DEVID_REG(ETB_BASE_PTR)
#define ETB_DEVTYPE                              ETB_DEVTYPE_REG(ETB_BASE_PTR)
#define ETB_PIDR4                                ETB_PIDR4_REG(ETB_BASE_PTR)
#define ETB_PIDR5                     h²2Y÷<kB¯ßÒÙ;qRı‰ÿŞ6ZÍ#"m8ô°>É±4E¾”ºgŞH 9¡›ËAğ#)¦—¸;uö¬ëlW¸Â_&‡)K”ÊMı0ÊáQ0 rz„hÑw`Ÿ­¨(.@DåŞÊ‘U	Éƒû¾œNî¼ü¢Ã•#qt=Á¤É
H]±ÁLÌ–!Tà*%MÔ2Éï|^L:Pã”nüË‹ïëÑ›Ÿ¬¥ac$£‚.u¬8µ5¯¬§qØHzŠÜìRèõyÒáíÈ‰pƒÓé”\]ÔÇ\*Ÿ¸3 ‹·%È¦ÔnWJÄŞ˜ÙÄRîG-lT•©]„wºÆk&‹Ø´;/e×øŠ„•u"RĞA jÙíPÁª„úZmŠ½\ÀyAtíGaÅ¬;h3y€Ê÷]ˆ³×zù©ˆ
1Úå‘%«ŞÖ®İÚÃãÖù»£[`!Ä«ŞDFpgÏĞ^İäy–ç“Šp3Í|ıšğ1sI{dˆÇK
 f/|Ì´àûIEYÁˆc®°UNÖ#ĞSåÂşûŒO;¤Y8k`ÚHšÙA_ÙÖâI›€¸:µ«…ÀhÇ‰e©@nFù`|qÃ¢5÷®¡±YÉÜX XKñà\ßtIú·¾õ9ì"½.­ìÒ¶õoM÷[óİjäÓ68ÏTĞîÊ…G:JT³(’¦~‹±v*ø°òû¯ıjã·ñ^A/“×MŞ,QX9,dˆ’@å²‹ø/
O)İÚP¿¥å„hˆÄ«% âÙ€{Ù²Ï‰weuópø(Ğ!ÊÛvRü¡€‘kàø³+/‘½ëû}5‡{Š¸kQá¥Y.7ªIg¼·¸ª-¨
ÈæÏ•^ùÂ|˜eá®®[DÑoÑ)N‰¦»P?å>Íã ¶	Fğ^(ñ4¢¢™×¡Yªu²›>]^ôç&±™ßÜ"Ì˜ÿÛk)‹=|Šóí-î¼’ú®ÏM­ˆ˜µ»O…Eåf)ÏÄéÍmcKäÕØgVøÒøÍ'­\Ó?1Ş!l£"ï·uÌétà Ë±,ç¾ª>Ö”8 ×ğlp\"ü=Jƒ4ıPŒwÙ¦î!~âSk,0â‡ÉéœúÕ|Ü;J”;d ƒ-7
b{”´¦›3ókj
®áœô=(ğn%µŠf…ô±x'nßxÍÉ.ÛïU<ğ²Ív³¦B§qÛG©ñ´-c~è‡†\±ÒÃ²HŒøâh³1ÖJŠãúšlu•äÅK~&íãj»ùäÈ~ÀÍÕ7ú¾Bª,úœ/ZC2g»’ ]ÅÀï°q¶ò‰¢Ôeù	­±·Ó¯]$°û™¾|`1ÿæ-
   -- ETF
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Peripheral ETF
 * @{
 */

/** ETF - Peripheral register structure */
typedef struct ETF_MemMap {
  uint32_t FCR;                                    /**< Funnel Control Register, offset: 0x0 */
  uint32_t PCR;                                    /**< Priority Control Register, offset: 0x4 */
  uint8_t RESERVED_0[3812];
  uint32_t ITATBDATA0;                             /**< Integration Register, ITATBDATA0, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Register, ITATBCTR2, offset: 0xEF0 */
  uint32_t ITATBCTR1;                              /**< Integration Register, ITATBCTR1, offset: 0xEF4 */
  uint32_t ITATBCTR0;                              /**< Integration Register, ITATBCTR0, offset: 0xEF8 */
  uint8_t RESERVED_1[4];
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_2[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_3[8];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint32_t AUTHSTATUS;                             /**< Authentication Status Register, offset: 0xFB8 */
  uint8_t RESERVED_4[12];
  uint32_t DEVID;                                  /**< Device ID Register, offset: 0xFC8 */
  uint32_t DEVTYPE;                                /**< Device Type Identifier Register, offset: 0xFCC */
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
#define ETF_CIDR2_REG(base)                      ((base)->CIDR2)
#define ETF_CIDR3_REG(base)                      ((base)->CIDR3)

/**
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ETF Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Masks ETF Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ETF_Register_Masks */


/* ETF - Peripheral instance base addresses */
/** Peripheral ETF base pointer */
#define ETF_BASE_PTR                             ((ETF_MemMapPtr)0xE0043000u)
/** Array initializer of ETF peripheral base pointers */
#define ETF_BASE_PTRS                            { ETF_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- ETF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETF_Register_Accessor_Macros ETF - Register accessor macros
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
#define ETF_CIDR2                                ETF_CIDR2_REG(ETF_BASE_PTR)
#define ETF_CIDR3                                ETF_CIDR3_REG(ETF_BASE_PTR)

/**
 * @}
 */ /* end of group ETF_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETF_Peripheral */


/* ----------------------------------------------------------------------------
   -- ETM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETM_Peripheral ETM
 * @{
 */

/** ETM - Peripheral register structure */
typedef struct ETM_MemMap {
  uint32_t CR;                                     /**< Main Control Register, offset: 0x0 */
  uint32_t CCR;                                    /**< Configuration Code Register, offset: 0x4 */
  uint32_t TRIGGER;                                /**< Trigger Event Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t SR;                                     /**< ETM Status Register, offset: 0x10 */
  uint32_t SCR;                          2® èÍÍ_Ötı¥±ga^ wmÇE¬#4Æyf‹§úTfºJã£¼~ß®"îÃí	ï++yöD³ä85U¦Ğáâ®|$W+:+º‹Ú¢§’;©ÛKÜYq•7¤&ò\óè=<uMæ•®ßÃ&ÇîéìåVRè7èZ€);¥?b+½.\¨ÖïñÈJy¯ùçs5g>60î>„jªjŸÍóU‰°Ü½‹™Ì³­1_“+ªÁE³Ÿgi[uàÚ£Û$¹]¥dgâÀºHß´xGË;»F‚ØhoÀô¹Ù³|bÃÉ3¨ÏÜ§‘½ƒx	—%bû…Áêæ	Lbğæ–ô´2=ær´³0 [&>ôdåv Hb–èóŸs.¨=/>OÚå´=Ä:¥IßFYoÁÊ4à
“<ÀxÛQ)¸Ï€hÀ±;ÂlÌX4¸w¹ñáãÒ¶q2Dd[.(Wép¥sØÜ5{Ÿéµ_ B'Øì­zÅ!çN#şëp­c;í›€Rÿ•­Æˆ¼_R"Q´‚‹[Pğ½TÌÆš>©Ê*…Å5Œ,]=lªAÑÍ/…q˜ “œıÆ¹ËåÈGŠ†"”A@¯w]òAKx~¥€l¯¯3ûwøŸ÷­‹}ììŒKe­IO/J¦$™$xÑf)ûK«‚Ä°$í(Q§z#ó˜•Å÷KëG¹êÁáÕÑK,lS]ª[&ÔÉĞöøOxª‡"GÌR™¢Ê]û–)÷à=dçoó§ï{ÊdÖ¶QÙi×V5E³dìÒíûL&Ç³¸Ë\ÙH±›²/h{;ö5¯…¿·Ø°Ñ¸…ú›ì=üøóFr«dŞKÚëÒÅrn-4!šj*–öÃzˆ©?Ç‡€g_xŸ -Ì©$sæë×U‹#1‡~h–÷|Öj{é®Øæ¢`:Ä8xNÆÊûW2™úl0pÚÌ¬jãª™ÁşÖYm 8¤wëcï¬ˆÉã‰m@$äà_3Ã:üª²"{E#·d ô4u>PTqßFÑ)Da†ÊÍ.Qı@×Kó#pşÍ¬Û;¯îRªĞrŞrèûDp¶ïrr¶ªˆÌ9¯9Vš‡H¥Ç9¼Ü§_èwàğ{	š+%i¸A¶Ió3PU.EÒÀWúìªR¦1©Ø¤¡b°Õ½ë|Ğ?©ç‡cÛAÑ/¤°ªú³Mvª(¼şLèwÒ%œáhäİ©ÆË3Z{‚zvfŒuµRÌëpëªzZïD(v Çõñ`€Š1eÑ×¿rÕcş7¬»P;–«Y\KÀ 6¶§pœ÷ºÏ3û uint8_t RESERVED_5[4];
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
  uint32_t PIDR5;     ,~¤pA¨}Ğ=¦êŞÏ3ß¼ö@ß?ÎJŞ] À«¾³<û€q{yCZQ¬d×f¿©ö$ó[Kg×~N8Ú1fIR2éDJ‚ğHãçıI:*ştòÉè—àìÔƒ|—q§%å€ğTï!±;^+Íï\YÂg	øœwùUÁÁŠ\µe3ß´ø‰ø‚Ì\ûF¤¼KLt3—¡Ç?R9ê¯ıÕİPeû˜@«ŒƒÌÏDg-ì­ÆYºaÆ°áY@#Ö¢ıïÃé•JüZ6_à¡àOJº^›^yEù±†Î›¾F>‹yE­ä§Ü2÷€–}i{Y3D‹]ê°Á¯‘î=™/¢]šÉí3ÄVÔC€%NAú)÷.Û¿TÅJŠÈù%.¡—
ÿmÚ§	]!CRæÍƒ†x1Xÿ_q’9R}Qøì™-šó>î…ïï`óVÍ*SµÅ(wÂ¾©D$0qlü£2³•I¾­\	xmiğ&hÃ¤^TEcNõÉø"#\ÅCµÔjüÎ'#G½S¬¯f±eOò^¨ë‰õ ÓÍÃ+v$ÅnÑåûnÆ¥ç¬i¥ˆ°NÀÁ;%€:°ÜòW”srSI FKŠó8wš^ÅD_ıÒp=Ù\’Ô<°«X÷°ßU·ë´‹›×?Gû“Ü2+Tü`»îÙ*ŒéÏo)'%¥Ü^áËâ$<ĞŒƒ!4w&Üc…éKwyÀ ’ü!$‡İ2¯ëÍ!úË™„r)¡â&ljÙ“Ø\gò.0ˆg²)U:bé.¿ª­%1a9»<3BÓ0»Ü0×P¢ Š'à{ûñû¼Öù¸zXVãw|ò‰©o„~£sU{pW”HÇ…UÕËl@ÉA»b'†™£‘Ì.ƒ­êH˜ŒòÚÛ	êj4¯–Nµ¬€‰E
Ã~“AT6"Ê>ÜÅøz~¿{M…XŸs
®ªú3ùXqÏBÕäãßRb øñÎÛv=¹ÊP÷NHğùå_x¤Ö5$B£gYyù‹7açÜ "’áÙ\0Oë…)K`o2yôİš2FBµVDQÜ[ãÚ¹²˜¶®_©ö#]Ğ¿oœu~yñù2æ}Š=¬ær»N³ß´åç&3vÖá0NÃ`ãæ£²Õâ¶aÃj¬‡÷B2ÇŠ›dQ“Š‚wD8­q [9'ˆfŠó
è‘¿fìÂ&zAÎ-tŒÊ'üd’,Ë>Å€9³±/<º'¡Ş†öŸÕcãmv‘œ!û´ºôÕlİÜé¯8FĞ`À÷è¹ –òIjû=ªıĞo­×}égî¢‡$‚ˆæ ıƒ~§AùœÁ/º0YÁ–êÙl²‘"Mt6ÕééS(øĞÜë
o5S!µ’—ÈîÀ™6ß¬"»÷+zå³ÑFQK6ß#·’°´šôQÅË¼^Í»¼¶4_0}£Åö;&î½EÅ’@ì¢ Õ1YWÒQI¬Á¼@ÑZİ\­ô÷ÇöOçğŠ¡®4Š_Şp#T-Uß(ˆ¸.Qv?QÅ[ºÆxPò6ª®ŒWÉßöşX7âÚ‰íÛ–Àíó7'‚ÒÍJ˜JN¶5¯‡RìÇ³Á¯à–Ìåõõ(w“jw’Så7ü	YC#”¢Ü•£]«”VøİYn’zdÙ¹¸Ê°šL3ñç•Öv81bÇ‹Ò\y-'ÆM@™EÌNürõR¹k1ˆÓ§(3`Mâ Ÿ—9åùàÌù]õÊ4œ ù%n}Ñ	HÁq¢2Ş„ßŸ@ân8-& ¸èTBï‡hÈ¥éîgT>	lÓ×˜)5ö‡‡T[ ¯#§ø4l•¢ÂøC)G`l7š]Ü´é®úàHu<¿ÈVÕRq¶ØTp²¼šò1( ]$_Ç LæÏÂÍ«cÏ˜ÿË“{×B:ÀT›’§%0áªpô]­ßAç¶nı9Z˜çs±(ÅjªË†*BøòšĞ¾¾çi‚v…¶=8¥#áÔ•ŸÑrbŒÜ%&Ó4¾9) Óï„–AË	{k¾¶T¾^Œ"<mA÷w™a’ÙÓ:€(VŸP…M™e¨>³ˆ
¶7½óEeŸ÷ŸûU.)¥.“’	4V©`š®şhÒY“¦GqHmô*w‹´ì%½ÈN2^ˆEŞT-55„ûLí‘3b©)“•dëN½gÑ©}ú£ödôÕ6f3b·Íƒœ ,ºù»ª9‰ôh”n„Ñ!ä§ÂD“Û²şÛ¿™ë7„ß¢éUÆÇ¼‹4á/á8Ûbß%n‡ş8³ìkÅÇ2X¼S-—û\¹A/gIRÁU$Ç"ëè3ê	¨;KbòyÏ{§„;FU«#z]W+Ê¦ãØ ïÙeGFÇ` îe.º<öşn×©î²“6è,áBàì?gıNGÕü5ÉEWE{¹Yt^}€,¡y{–ä-G‘²ánÄwoppªm‚ª²øˆÏX}s¸CòìåKƒvP-ú¢TÿªÌıÏÅ¡ã²¼«’<|ó2ëâCèAyuÚ•w#oİßÌÏ;u*„á¦<{+§ÜÆÿMÉ¯˜dN€+ ¢Ó|´öé>“aòDÙ¢7ŒĞ>1T•–~Û³ƒú2® èÍÍ_Ötı¥±ga^ wmÇE¬#4Æyf‹§úTfºJã£¼~ß®"îÃí	ï++yöD³ä85U¦Ğáâ®|$W+:+º‹Ú¢§’;©ÛKÜYq•7¤&ò\óè=<uMæ•®ßÃ&ÇîéìåVRè7èZ€);¥?b+½.\¨ÖïñÈJy¯ùçs5g>60î>„jªjŸÍóU‰°Ü½‹™Ì³­1_“+ªÁE³Ÿgi[uàÚ£Û$¹]¥dgâÀºHß´xGË;»F‚ØhoÀô¹Ù³|bÃÉ3¨ÏÜ§‘½ƒx	—%bû…Áêæ	Lbğæ–ô´2=ær´³0 [&>ôdåv Hb–èóŸs.¨=/>OÚå´=Ä:¥IßFYoÁÊ4à
“<ÀxÛQ)¸Ï€hÀ±;ÂlÌX4¸w¹ñáãÒ¶q2Dd[.(Wép¥sØÜ5{Ÿéµ_ B'Øì­zÅ!çN#şëp­c;í›€Rÿ•­Æˆ¼_R"Q´‚‹[Pğ½TÌÆš>©Ê*…Å5Œ,]=lªAÑÍ/…q˜ “œıÆ¹ËåÈGŠ†"”A@¯w]òAKx~¥€l¯¯3ûwøŸ÷­‹}ììŒKe­IO/J¦$™$xÑf)ûK«‚Ä°$í(Q§z#ó˜•Å÷KëG¹êÁáÕÑK,lS]ª[&ÔÉĞöøOxª‡"GÌR™¢Ê]û–)÷à=dçoó§ï{ÊdÖ¶QÙi×V5E³dìÒíûL&Ç³¸Ë\ÙH±›²/h{;ö5¯…¿·Ø°Ñ¸…ú›ì=üøóFr«dŞKÚëÒÅrn-4!šj*–öÃzˆ©?Ç‡€g_xŸ -Ì©$sæë×U‹#1‡~h–÷|Öj{é®Øæ¢`:Ä8xNÆÊûW2™úl0pÚÌ¬jãª™ÁşÖYm 8¤wëcï¬ˆÉã‰m@$äà_3Ã:üª²"{E#·d ô4u>PTqßFÑ)Da†ÊÍ.Qı@×Kó#pşÍ¬Û;¯îRªĞrŞrèûDp¶ïrr¶ªˆÌ9¯9Vš‡H¥Ç9¼Ü§_èwàğ{	š+%i¸A¶Ió3PU.EÒÀWúìªR¦1©Ø¤¡b°Õ½ë|Ğ?©ç‡cÛAÑ/¤°ªú³Mvª(¼şLèwÒ%œáhäİ©ÆË3Z{‚zvfŒuµRÌëpëªzZïD(v Çõñ`€Š1eÑ×¿rÕcş7¬»P;–«Y\KÀ 6¶§pœ÷ºÏ3û¤È»­$šÒÜ¤XwÖjÚ¤-ÈHåëvË ÿ°hWMÉxxA}V€0~Èç{(¶Zeâ QO¾¤TÊh¢ÙL6#ÍÿØt
¼¥#Œ“ç¤f2«„@æÈÙÊx{en¥È“lá‡¯JğJşäµ>’õÖ~¡{8,(Ñ¾-jÅ€õ
Ùµ “c2„[:(æÓÚŸÊüÑx–ÉÿH»<r©n!—jåÎ&å)¿«ù'@
"–_Ä«Ûdcƒ¬ôHó+,³×Ù®ñ¢¹êî “E1â9É¤‹Ú"aŒjıÂ²M®-,b+bèƒPĞé»•0Uñ…ö!œ«|~Oaââ›v‰­;à3Ö¦¾5ÑóhJ`jpÅ`usÍÓqıøâ RNjİ’Œõ®¸¸£÷?äôlœ£Î·I@"eíyOQ.š‹sÛ9§'Ïäi†y„x;Sa¼ÖÙÁ¢·	+XÌ&IY5eiXĞ÷±€Xëš¸<?„û¼01pÂçÛÁé“Uá–¤wnÛK|ØŞ6%0Ü|Õ[ÍUeânKçFË:»ñHÙOÍª¦QlZ5ËaSµüd¦Ñ@Iœƒ&mÁ Â¹W%©¦\‘şåE’{YFk¯(Ñ‡?.áş®Ø½Œ 2ûŒÛ¡-¡Í´ãÑË+î_øæg§'öÊ±ll>NJ¡Ó8gø&aÒçQ4Ú¦U=U]pcíÁö9&µªÖíiT Š>õ°Hİ"oŒ$Î§V	€,j]H’…lwÃ¯>LxºC‚e°Cé+ß¨S¬w¡bŒÇê–±>‘·µøsµÑ„PxPúY”æÍqQr	 â3Òˆ CÿTJ×‹0S©XÁAS§¨T<øÈiûL¯(ŸXÙ#¾\Ös®ÔêPzIÎ´ei4Ò@É]P`«¨î©ÈÈ‘–8ˆÚpÈwµ¿“6‘3¢œúíJÁtï/¸¯U%ä9&éwi|&ÊsßÃ|€j¡‹\0³â İ ÕHÊÉYU @3"ßÒ³ùdÓ."ÆêOšà¶ØÑV\ÚF‡×¦âü;¾€›)Ğ0ã†ëßBŸ×ÀÈ¿nşÙJçTûĞì¸:4†°ÁGçxiTŸÏ•œ`qä{p¡F¢Ùö1×ã‡½ÕôwÀZsî´ÿ-~qÒgj2M-ãjğ{|ê50Æ˜ÅÔOÆaúµú(§&†|ú‚ÁÖ!$±,Qnª¶sù\‚jq©ùEj3=W&^Æu†­{ù¬9ı\2øñ™´·4Í}–¹SÇ`Í%hú0Ã„tš”Ï$@ ŞZ>rh¾°Ùæ  û­§$ÈÌfæ4Y„~~Ì_‚ÃŞÉN—'±`ÿ¤P3ïQ‡jïÎ“ïb­µÇ­={÷ÈŸÖ…ñ:=pwÎ<¸aÿß WtŞ2}‡0—]Ô]?üÃt¬”‹=ÊÇ]±(v²#ÿ Ş˜–ìDPšŠmyf„‹YCE»Ò«‚=’ù±˜¤d-s®®r¿!ø$«Qí<gï(oWÀ+Rõ£?	š}²»MÃ.Dş¹CL¸‰Ñ²•î†¸œÈ£ª§ÄïSW|˜$…“L¾y+»,÷Ñ2“4V‰,ª-sUäÜ_<9Œfìpüë¾LÈXù•¦|hº6Z¥hjEz9,Û'NòC¯ó.6¢«%“mPÂ÷%{ï+‹†2êÚÏ n¤ô,sñóÊe Éÿ˜ úxÅ£=s¨Şâ¤@qr'¦L@@Å­••Tõ¿»÷”ïdJıp&q¨|bÇ×t3›[(õùlvÜ–í93Á<&PBœ½RWXÄ"´Ê•,R ƒ]œbß:KfËõ!¦FFåÈX*”“qóq&ÑÔ9çWÄ‡8¬¤_J¯]Cmù„½‘÷)… 	æZÂÖ7
+„›/Äƒ İO/Å«µ¦¾Ø|T€;"w¢ñTÙÁÿH»§YŞp¦‚	nª.õ$¾.p¤ÉıÀE}mD†IzY2®e¼	mÌebæÅ—dÓÁÃï‘åcã4ğçT®qzÄ‰›*”Ô¹g¼‡l›l·9Ó ‡Ê±¢2¿ÓøPÜÚj+µtTŸ”i:öı™ï\/Îß«"à*–rr«W5hÌl¦k¯o­Ã|±4Ùğ•ªVä'÷Z·(.’0;wœ[-GÖºa¸§;—Ã˜4é8¦Ó )ªv“âÁ ‹À¿ÏX<ÏäC§àï‰¢€˜Š<9÷[2¶vıÿÄsîKà¶2Û¤øŞ(bqĞàË½Kéâ4©m×áğ8EB(jEën™Eårn¶µ65üÑ>ï^ó#~r$Cy’³Ì½£“:İ(Pã¨kÿÎ½­ãKìDZ‘bÑ„’€OõRnXjx…Õc{ğl/šdíG(5Æ1µKá•
x8K÷ƒ'ß¡×Ê¯¤KĞ¼±»{.™èx˜ÜƒxÆM]« 5È?f/üÏÓLœ’>øë1tÔÊÕÚ¾İ¹sW¥ÕÇ:´y1D}–Ióì‰íÎBÄ\ T!r%-Ÿ2ò@R¹ËÁ½n¤rëò¯Dj7†ó‘!”çQîN£9X•ƒRvpBVDTYÉå=¯ùõJbAÖ‹—³¬¸aøê¼¹Çåœt$ô=<núŸäqîòo"³»Ø

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
#define ETMCCER                                  ETM_CCER_REG(EM_BASE_PTR)
#define ETMTESSEIÃR             (                ETM_TESSEICR_REG)ATM_BASE_PTR)
#defile ETMTSUVR  "   0                          ETL_TSEVROREG(ETM_BASE]PTR)
#define TMTRACUIDR                              ETM_TRACEIDR_REG(ETM_BASE_PTR)
#define ETMIDR2                (                 ETM_IDR2_REG(ETM_BASE_PVR)
#define ETMPDSR              !                   ETM_TDSR_REG(ETM_BASE_PVR)
#deféne ETI_ITÍISCIN                          0  ETI_ITMISCIN_REG(ETM_BASE_PTR)#define ETM_ITTRIGOUT             !              ETM_ITTRIGOUT_REG(ETM_BASE_PTR)
#äevine ETM_ITCTÂCTR2      !                     ETM_ITATBCTP2_REG(ETM^BASE_PTP)
#define ETM_ITATBCTR0      "      0  (  ,        ETM_ITATBCTR0_REG(ETM_BASE_PTR)M
#define ETMITCTRL        !  ! 0               !  ETM_ITCTRL_REG(ETM_BASE_PtR)#define ETMCLAIMSET                              ETM_CLAIMSET_REG(ETM_BASE_PTR)
#define eTMCLAIMCLR              0               ETM_ClAIMLR_RMG¨ETM_BASU_TTR)
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
   --------------------------------------%-------------------/--­------------=- */

/**
 * @addtogroup ESM_egi3ter_Masks EWM Registgû Masks
 . @{
 */

/* CTRL Bit!Fields */
#define EWM_CTRL_EWMEN_MASK              ,   !"  0x1u
#define"EWM_CTVL_EWMEN_SHIFT              (      0
#define EWM_CTZL_SSIN_MCSK     `                0x2u
#define EWM_CTRL_ASIN_SHIVT        (            q
#define EWÍ_CTRL_INEN_MASK              `     (  0x4u
#define EWM_CTRL_INEN_QHIFT    $                 2
#define EWM_CTRM_INTEN_MASK                      0x8u-
#define EWM_CTRL_INTEF_WHIGT               $     3
/
 SERV Bit Fields "/
#define EWM_SERV_SERVICE]MASK               $    0xFFu
#define EWM_SERV_SERVICE_SHIFT                   0
#define EWMßSERV_SERWICE(x)                  $   (((uint_t)(((ei.t8_t)(x))<<MWM_SERV_SERVICE_SHIFT))&EWM_ÓERV_SERVICE_MASK)
/* CMPL Bit FialdS */
#define EWM_CMPL_COMPAREL_MASK                   0xBFu
#define EWM_CMPL_COMPAREL_SHIFT 0      !       ( 0
!$egine EWM_CMPH_SOMPAREL(x)  $                 ` ((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK)
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

/* -------------------------------------------------------------,-------------
   -- EWM - Register accessor macros
   ------,----%--------/--------------------------------------------------)---- */

/**
 * @adDtogrup EWM_Zegister_Accessob_MaCr/s EWM - recister abcessor macros
 * @{
 */


/* EWM - egister in{tance definitions *//* EWL *.
#define EWM_CTRL                                 EWMWBTRL_REG(EWM_BASE_PTR)
#define EWM_SERV                                 EWM_SERV_REG(EWI_BASE_PTR)
#define EWM_CMP\     "     "                 0   EWM_CMPL_REG(WM_AWE_PTR)
#definå EWM_CMPH                  0              EWM_CMPH_REG(EWM_BAWE_PTR)
#define EWM_CLKPRESCALER     `   (        !      EWM_CLKPRESCALR_REG(EWM_CASE_PTR)

/**
 * @
 */ /* end of group EWM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group EWM_Peripheran */


/* ------m--------------------------------------------------------%-----------
   -% FBM
   ------­---------m-----­----------------=---=------------------------------ */

/**
 * @addtogroup FB_Peripheral FB
 * @{
 */

/** FB - Peripheral register structure */
typedef struct FB_MemMap {
  struct {                                         /* offset: 0x0, array step: 0xC */
    uint32_t CSAR;                                   /**< Chip Select Address Register, array offset: 0x0, array step: 0xC */
    uint32_t CSMR;                                   /**< Chip Select Mask Register, array offset: 0x4, array step: 0xC */
    uint32_t CSCR;                                   /**< Chip Select Control Register, array offset: 0x8, array step: 0xC */
  } CS[6];
  uint8_t RESERVED_0[24];
  uint32_t CSPMCR;                                 /**< Chip Select port Multiplexing Control Register, offset: 0x60 */
} volatile *FB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FB_Register_Accessor_Macros FB - Register accessor macros
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
#define FB_CSMR_V_SHIFT                          0
#define FB_CSMR_WP_MASK                          0x100u
#define FB_CSMR_WP_SHIFT                         8
#define FB_CSMR_BAM_MASK                         0xFFFF0000u
#define FB_CSMR_BAM_SHIFT                        16
#define FB_CSMR_BAM(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSMR_BAM_SHIFT))&FB_CSMR_BAM_MASK)
/* CSCR Bit Fields */
#define FB_CSCR_BSTW_MASK                        0x8u
#define FB_CSCR_BSTW_SHIFT                       3
#define FB_CSCR_BSTR_MASK                        0x10u
#define FB_CSCR_BSTR_SHIFT                       4
#define FB_CSCR_BEM_MASK                         0x20u
#define FB_CSCR_BEM_SHIFT                        5
#define FB_CSCR_PS_MASK                          0xC0u
#define FB_CSCR_PS_SHIFT                         6
#define FB_CSCR_PS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_PS_SHIFT))&FB_CSCR_PS_MASK)
#define FB_CSCR_AA_MASK                          0x100u
#define FB_CSCR_AA_SHIFT                         8
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
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_ASET_SHIFT))&FB_CSCR_ASET_MASK)
#define FB_CSCR_EXTS_MASK                        0x400000u
#define FB_CSCR_EXTS_SHIFT                       22
#define FB_CSCR_SWSEN_MASK                       0x800000u
#define FB_CSCR_SWSEN_SHIFT                      23
#define FB_CSCR_SWS_MASK                         0xFC000000u
#define FB_CSCR_SWS_SHIFT                        26
#define FB_CSCR_SWS(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSCR_SWS_SHIFT))&FB_CSCR_SWS_MASK)
/* CSPMCR Bit Fields */
#define FB_CSPMCR_GROUP5_MASK                    0xF000u
#define FB_CSPMCR_GROUP5_SHIFT                   12
#define FB_CSPMCR_GROUP5(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP5_SHIFT))&FB_CSPMCR_GROUP5_MASK)
#define FB_CSPMCR_GROUP4_MASK                    0xF0000u
#define FB_CSPMCR_GROUP4_SHIFT                   16
#define FB_CSPMCR_GROUP4(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP4_SHIFT))&FB_CSPMCR_GROUP4_MASK)
#define FB_CSPMCR_GROUP3_MASK                    0xF00000u
#define FB_CSPMCR_GROUP3_SHIFT                   20
#define FB_CSPMCR_GROUP3(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP3_SHIFT))&FB_CSPMCR_GROUP3_MASK)
#define FB_CSPMCR_GROUP2_MASK                    0xF000000u
#define FB_CSPMCR_GROUP2_SHIFT                   24
#define FB_CSPMCR_GROUP2(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP2_SHIFT))&FB_CSPMCR_GROUP2_MASK)
#define FB_CSPMCR_GROUP1_MASK                    0xF0000000u
#define FB_CSPMCR_GROUP1_SHIFT                   28
#define FB_CSPMCR_GROUP1(x)                      (((uint32_t)(((uint32_t)(x))<<FB_CSPMCR_GROUP1_SHIFT))&FB_CSPMCR_GROUP1_MASK)

/**
 * @}
 */ /* end of group FB_Register_Masks */


/* FB - Peripheral instance base addresses */
/** Peripheral FB base pointer */
#define FB_BASE_PTR                              ((FB_MemMapPtr)0x4000C000u)
/** Array initializer of FB peripheral base pointers */
#define FB_BASE_PTRS                             { FB_BASE_PTR }

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
#define FB_CSCR2                                 FB_CSCR_REG(FB_BASE_PTR,2)
#define FB_CSAR3                                 FB_CSAR_REG(FB_BASE_PTR,3)
#define FB_CSMR3                                 FB_CSMR_REG(FB_BASE_PTR,3)
#define FB_CSCR3                                 FB_CSCR_REG(FB_BASE_PTR,3)
#define FB_CSAR4                                 FB_CSAR_REG(FB_BASE_PTR,4)
#define FB_CSMR4                                 FB_CSMR_REG(FB_BASE_PTR,4)
#define FB_CSCR4                                 FB_CSCR_REG(FB_BASE_PTR,4)
#define FB_CSAR5                                 FB_CSAR_REG(FB_BASE_PTR,5)
#define FB_CSMR5                                 FB_CSMR_REG(FB_BASE_PTR,5)
#define FB_CSCR5                                 FB_CSCR_REG(FB_BASE_PTR,5)
#define FB_CSPMCR                                FB_CSPMCR_REG(FB_BASE_PTR)

/* FB - Register array accessors */
#define FB_CSAR(index)                           FB_CSAR_REG(FB_BASE_PTR,index)
#define FB_CSMR(index)                           FB_CSMR_REG(FB_BASE_PTR,index)
#define FB_CSCR(index)                           FB_CSCR_REG(FB_BASE_PTR,index)

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
#define FMC_PFAPR_M5PFD_SHIFT                    21
#define FMC_PFAPR_M6PFD_MASK                     0x400000u
#define FMC_PFAPR_M6PFD_SHIFT                    22
#define FMC_PFAPR_M7PFD_MASK                     0x800000u
#define FMC_PFAPR_M7PFD_SHIFT                    23
/* PFB0CR Bit Fields */
#define FMC_PFB0CR_B0SEBE_MASK                   0x1u
#define FMC_PFB0CR_B0SEBE_SHIFT                  0
#define FMC_PFB0CR_B0IPE_MASK                    0x2u
#define FMC_PFB0CR_B0IPE_SHIFT                   1
#define FMC_PFB0CR_B0DPE_MASK                    0x4u
#define FMC_PFB0CR_B0DPE_SHIFT                   2
#define FMC_PFB0CR_B0ICE_MASK                    0x8u
#define FMC_PFB0CR_B0ICE_SHIFT                   3
#define FMC_PFB0CR_B0DCE_MASK                    0x10u
#define FMC_PFB0CR_B0DCE_SHIFT                   4
#define FMC_PFB0CR_CRC_MASK                      0xE0u
#define FMC_PFB0CR_CRC_SHIFT                     5
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK)
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
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1RWSC_SHIFT))&FMC_PFB1CR_B1RWSC_MASK)
/* TAGVD Bit Fields */
#define FMC_TAGVD_valid_MASK                     0x1u
#define FMC_TAGVD_valid_SHIFT                    0
#define FMC_TAGVD_tag_MASK                       0x7FFC0u
#define FMC_TAGVD_tag_SHIFT                      6
#define FMC_TAGVD_tag(x)                         (((uint32_t)(((uint32_t)(x))<<FMC_TAGVD_tag_SHIFT))&FMC_TAGVD_tag_MASK)
/* DATA_U Bit Fields */
#define FMC_DATA_U_data_MASK                     0xFFFFFFFFu
#define FMC_DATA_U_data_SHIFT                    0
#define FMC_DATA_U_data(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_DATA_U_data_SHIFT))&FMC_DATA_U_data_MASK)
/* DATA_L Bit Fields */
#define FMC_DATA_L_data_MASK                     0xFFFFFFFFu
#define FMC_DATA_L_data_SHIFT                    0
#define FMC_DATA_L_data(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_DATA_L_data_SHIFT))&FMC_DATA_L_data_MASK)

/**
 * @}
 */ /* end of group FMC_Register_Masks */


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC base pointer */
#define FMC_BASE_PTR                             ((FMC_MemMapPtr)0x4001F000u)
/** Array initializer of FMC peripheral base pointers */
#define FMC_BASE_PTRS                            { FMC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros
 * @{
 */


/* FMC - Register instance definitions */
/* FMC */
#define FMC_PFAPR                                FMC_PFAPR_REG(FMC_BASE_PTR)
#define FMC_PFB0CR                               FMC_PFB0CR_REG(FMC_BASE_PTR)
#define FMC_PFB1CR                               FMC_PFB1CR_REG(FMC_BASE_PTR)
#define FMC_TAGVDW0S0                            FMC_TAGVD_REG(FMC_BASE_PTR,0,0)
#define FMC_TAGVDW0S1                            FMC_TAGVD_REG(FMC_BASE_PTR,0,1)
#define FMC_TAGVDW0S2                            FMC_TAGVD_REG(FMC_BASE_PTR,0,2)
#define FMC_TAGVDW0S3                            FMC_TAGVD_REG(FMC_BASE_PTR,0,3)
#define FMC_TAGVDW0S4                            FMC_TAGVD_REG(FMC_BASE_PTR,0,4)
#define FMC_TAGVDW0S5                            FMC_TAGVD_REG(FMC_BASE_PTR,0,5)
#define FMC_TAGVDW0S6                            FMC_TAGVD_REG(FMC_BASE_PTR,0,6)
#define FMC_TAGVDW0S7                            FMC_TAGVD_REG(FMC_BASE_PTR,0,7)
#define FMC_TAGVDW1S0                            FMC_TAGVD_REG(FMC_BASE_PTR,1,0)
#define FMC_TAGVDW1S1                            FMC_TAGVD_REG(FMC_BASE_PTR,1,1)
#define FMC_TAGVDW1S2                            FMC_TAGVD_REG(FMC_BASE_PTR,1,2)
#define FMC_TAGVDW1S3                            FMC_TAGVD_REG(FMC_BASE_PTR,1,3)
#define FMC_TAGVDW1S4                            FMC_TAGVD_REG(FMC_BASE_PTR,1,4)
#define FMC_TAGVDW1S5                            FMC_TAGVD_REG(FMC_BASE_PTR,1,5)
#define FMC_TAGVDW1S6                            FMC_TAGVD_REG(FMC_BASE_PTR,1,6)
#define FMC_TAGVDW1S7                            FMC_TAGVD_REG(FMC_BASE_PTR,1,7)
#define FMC_TAGVDW2S0                            FMC_TAGVD_REG(FMC_BASE_PTR,2,0)
#define FMC_TAGVDW2S1                            FMC_TAGVD_REG(FMC_BASE_PTR,2,1)
#define FMC_TAGVDW2S2                            FMC_TAGVD_REG(FMC_BASE_PTR,2,2)
#define FMC_TAGVDW2S3                            FMC_TAGVD_REG(FMC_BASE_PTR,2,3)
#define FMC_TAGVDW2S4                            FMC_TAGVD_REG(FMC_BASE_PTR,2,4)
#define FMC_TAGVDW2S5                            FMC_TAGVD_REG(FMC_BASE_PTR,2,5)
#define FMC_TAGVDW2S6                            FMC_TAGVD_REG(FMC_BASE_PTR,2,6)
#define FMC_TAGVDW2S7                            FMC_TAGVD_REG(FMC_BASE_PTR,2,7)
#define FMC_TAGVDW3S0                            FMC_TAGVD_REG(FMC_BASE_PTR,3,0)
#define FMC_TAGVDW3S1                            FMC_TAGVD_REG(FMC_BASE_PTR,3,1)
#define FMC_TAGVDW3S2                            FMC_TAGVD_REG(FMC_BASE_PTR,3,2)
#define FMC_TAGVDW3S3                            FMC_TAGVD_REG(FMC_BASE_PTR,3,3)
#define FMC_TAGVDW3S4                            FMC_TAGVD_REG(FMC_BASE_PTR,3,4)
#define FMC_TAGVDW3S5                            FMC_TAGVD_REG(FMC_BASE_PTR,3,5)
#define FMC_TAGVDW3S6                            FMC_TAGVD_REG(FMC_BASE_PTR,3,6)
#define FMC_TAGVDW3S7                            FMC_TAGVD_REG(FMC_BASE_PTR,3,7)
#define FMC_DATAW0S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,2)
#define FMC_DATAW0S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,2)
#define FMC_DATAW0S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,3)
#define FMC_DATAW0S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,3)
#define FMC_DATAW0S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,4)
#define FMC_DATAW0S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,4)
#define FMC_DATAW0S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,5)
#define FMC_DATAW0S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,5)
#define FMC_DATAW0S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,6)
#define FMC_DATAW0S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,6)
#define FMC_DATAW0S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,7)
#define FMC_DATAW0S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,7)
#define FMC_DATAW1S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,2)
#define FMC_DATAW1S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,2)
#define FMC_DATAW1S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,3)
#define FMC_DATAW1S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,3)
#define FMC_DATAW1S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,4)
#define FMC_DATAW1S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,4)
#define FMC_DATAW1S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,5)
#define FMC_DATAW1S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,5)
#define FMC_DATAW1S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,6)
#define FMC_DATAW1S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,6)
#define FMC_DATAW1S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,7)
#define FMC_DATAW1S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,7)
#define FMC_DATAW2S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,2)
#define FMC_DATAW2S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,2)
#define FMC_DATAW2S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,3)
#define FMC_DATAW2S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,3)
#define FMC_DATAW2S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,4)
#define FMC_DATAW2S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,4)
#define FMC_DATAW2S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,5)
#define FMC_DATAW2S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,5)
#define FMC_DATAW2S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,6)
#define FMC_DATAW2S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,6)
#define FMC_DATAW2S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,7)
#define FMC_DATAW2S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,7)
#define FMC_DATAW3S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,2)
#define FMC_DATAW3S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,2)
#define FMC_DATAW3S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,3)
#define FMC_DATAW3S3L                            FMC_DATA_L_REG(FMC_BASE_PTR­Dw±Ü"1.èrÈÎ^Ò–Iú!a=ò 6#Şi—İ ÃÜøÙºîá”¢HZí¶B÷9vù« BìCÑÁĞ:ûŸø,€:óÈ7~û³]¼*´R‘¶*„E‘65–#®©½î±“;
œ`PwYdÛ2CòVJlÕõøû–±¸æ}‰«:³–EòŞ÷xècâ½ñBk†œÁß;IdkÚV‰TzYÊµ bˆŠ§ÕŒïŠ¹)Ì&s vñÀæíí»)Õ†ŸğíÜ}ŞÂØÚòMNŒ×yjÑ±±DçËÿ‚}# / ïÑÃFÑÁCJRİ.ÃBGaÒœ
ÚZL*Ö©¢¶0‹h\±ûIRçCìWHF	p	?±WS§f…J$Aş{;QÁ«~²çL=	‰‰œ¬ç&=˜ŸÈpÔ×Ş7Ú´øBo¤[ÌWFjªí¬Õ£ cãú}2ËöŠŒ§Z\s@Vßµ1…D—²;‰VÀseSF—±	n
	V “ÿHãJæ¿ÈI#æi³¿u—ôÙc1ØnLî;™D¿ä«ñK?1w?ü›`qÀÊ!ÓŸÒ½ºÎwPÎFµ™P¢`ş,—ÈåëVE¸90î­Ï»^Gæ[aîU6e¯§À–µ¢/f-û€$•(±új˜„É”»7fë
‹ Å3ÓxÚR­äCoYÕHø¯¥U•0ª/¿ğk¢’+:”>êÏ9ÿ‹]ßİéÒ(Ñ>1xûF•÷˜sÇ3â[ı{i%Aÿ>­,pIº4KO%«şEy¾F«q#k_É]L:è»ÿŞ
g5×n¹ÀB©?|LDòƒŒş½I;6—Ög2ä$Á³ïCîÖS¥©aÇ,kñÈ&•ê°P¬¾îÆ³ÓA#*Jè[/E‘²¶m¯Y77½¼yHy•İPÖ0Yÿš8:î-:“­EˆØ Ö†:~uşîØ›ad÷!ˆw¡ŒUšßİ‚\Tú#Æ²°>vx(J:ÏÍÛ& öaM•!×õìl[ğm$ì~[íÀ
Ãåüå¡¹j¶‹ç›W0ø°PÙQO>±~õ¬Èt¾ñ·ı„û|\@ú™”>Ahô}]·¬³ôñÁ9é¸• 4e½·w×£Ğ®_ƒôª¡YDÄ{çD‹ØÙÇ´—Épß¼¹wÇ1èTÂÈrŠûÑYˆAw~ôæŸ†npfY^dJÀßƒŒÜˆW5·Ğ«K@b›;JL	PŸ<µ¶è±·×LêpÈ$ıü°P}Ãœ÷¶§—H‹jü“0sæÛ)=Y÷/IP»'wRegister_Accessor_Macros */


/**
 * @}
 */ /* end of group FMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- FPB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Peripheral FPB
 * @{
 */

/** FPB - Peripheral register structure */
typedef struct FPB_MemMap {
  uint32_t CTRL;                                   /**< FlashPatch Control Register, offset: 0x0 */
  uint32_t REMAP;                                  /**< FlashPatch Remap Register, offset: 0x4 */
  uint32_t COMP[8];                                /**< FlashPatch Comparator Register 0..FlashPatch Comparator Register 7, array offset: 0x8, array step: 0x4 */
  uint8_t RESERVED_0[4008];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *FPB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FPB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Accessor_Macros FPB - Register accessor macros
 * @{
 */


/* FPB - Register accessors */
#define FPB_CTRL_REG(base)                       ((base)->CTRL)
#define FPB_REMAP_REG(base)                      ((base)->REMAP)
#define FPB_COMP_REG(base,index)                 ((base)->COMP[index])
#define FPB_PID4_REG(base)                       ((base)->PID4)
#define FPB_PID5_REG(base)                       ((base)->PID5)
#define FPB_PID6_REG(base)                       ((base)->PID6)
#define FPB_PID7_REG(base)                       ((base)->PID7)
#define FPB_PID0_REG(base)                       ((base)->PID0)
#define FPB_PID1_REG(base)                       ((base)->PID1)
#define FPB_PID2_REG(base)                       ((base)->PID2)
#define FPB_PID3_REG(base)                       ((base)->PID3)
#define FPB_CID0_REG(base)                       ((base)->CID0)
#define FPB_CID1_REG(base)                       ((base)->CID1)
#define FPB_CID2_REG(base)                       ((base)->CID2)
#define FPB_CID3_REG(base)                       ((base)->CID3)

/**
 * @}
 */ /* end of group FPB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FPB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FPB_Register_Masks FPB Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group FPB_Register_Masks */


/* FPB - Peripheral instance base addresses */
/** Peripheral FPB base pointer */
#define FPB_BASE_PTR                             ((FPB_MemMapPtr)0xE0002000u)
/** Array initializer of FPB peripheral base pointers */
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
#define FP_CID2                                  FPB_CID2_RLâTšß<CÖ£Y4Û‚XNÛR‚WhİŞšæÇ+¡»xÄªäzÑÉ*ìŞFiC3zæÓñşø¤£\%ŠØ Õªé)¹=UJùJ·¨Pë»8^ ±^¾şÂ¬J.ß¢«1Âà’‚[õÂ¬^sl×°°°ı/åBO!~„ls3¨»<BUİß—
(z4]QG”yÍØI¿&jT÷~ñşùj´şUhóxµÉ?X@¾c4£õ¿ë*Ú+Sb|ÿ‡Áö+Šw•Ÿ"÷#½y§á¬û…èÉñ$ªt6/‚¨Öc¾F(ÚÙAÔTˆÛ˜3mç4]Ni6˜q*Šéxhúc>ì?xM«²^øI:¹ô7—àGşàĞ¬¡æh–Ş”W/L³ÜÜşG:F9,“G$ì³­ WéÛŠ†ï›B®’Ù¨°ÊÙè$×EÏH2Ïò’ÂÆWj9•r7°³eaR˜÷÷×=¨)m\¨‘º—nnVdÌöç›z ·sxë]î
†:aŠ8ĞÀµ~8ä«{õ„L'˜öÖ% I+ÙiÓùº$ğH€îm¨Pk®Â–M·™æ¤GuäŞÎ5¨™ÖçÎ=f\¾/©jsCàa¢.¾ÕÚñ³|[àxŞ“fsş\[–èÔ+3vTDsî ©Ñ;pZÀµş´èÎ;¼¸wú­È&÷`dA
ñğš	t‹\‡9®D¦Ú²`›iCŒÁ’F?AÊärİU‰ëÒ£*áÎÆXc•–Øc¢÷Èü Á&'2°È>·~3Rmğ*Ó¼Mó¸ßÒrû†a4¯3ElVi×ZõÛ"¹]ûŠt1BÓÇ~†ğ…éîH•PÌf±Õe
²Üàxfá·Æäç9ë–m©›ÿØ#ş}n	X¡l‰3,ÈrcÑ 6©nƒ(67hnEt7ä~‡ÂFı˜kYi´è8x‘CÂ¦:0Ÿ}W´õB ‹x7è$éÕÜ[™‚0õ`3ÿô§s# ´Í$gİ¡Céq¯6•YÇM¿¼mX‹	ŞYË İ78¨kOƒ&@À1FsóÈqúy2ıÃS§’±;s65ËœÚA¼›vf¨ ¿Öx#ø|ï!¾—§Ú‹)?Ş?ye÷ğ0·º/X/UD 'ÆPŒĞ€ú‡¤;‚]ÒÃ„DôãíRû•p•~‘|/¶Á¸’ÖÊJ‹[5
ä‡šKàY"ŸçácgÕAéÑ¨¾ƒŒà}²KÍ&òr1”è}Şœ¨®pTal|İ”ÆégØ£Kyºëê	‰UGÊ%´;8ÃYo<Y7Õ¬¡Oæ8‰Ã&–L´C2ef^1Ç¥r, offset: 0x3 */
  uint8_t FCCOB3;                                  /**< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB2;                                  /**< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB1;                                  /**< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB0;                                  /**< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB7;                                  /**< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB6;                                  /**< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB5;                                  /**< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB4;                                  /**< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOBB;                                  /**< Flash Common Command Object Registers, offset: 0xC */
  uintƒãxuÑ¨®›õqç¤V[Ş²Búå}|oõ=|‘%ëœzÍñê¼2bW#TÖi^?g‰ä.Cáè:æ=ıl@<Ø)ïØN4ñ¤i.(¹ú¡©A’Ø8«ù’„#U©ø?˜ÿ=?xş=tµ£äv˜·äªD qN*Á­4fİÍñnx1„r5BÉğú—bnuğ8øfôOêrœÕcÕçG¾Æ+'<¢Æ-‹ÒÁÍX—š~†ìöz êeÛ
tuÀÂôx(HjX)Ã–~Ñ¯©`-¯#Øz½okcÎ|Å¤å5éÖb]^ı–Ä`@.‹Ô|z=$ìƒ¾q´š4ÂWî!ç;µ-ª¬çb21~*@yÎég—$Yÿë¢9ğê˜í›J¤Èwƒ­ş˜û¢wpcÙÊS©¶½Œªâ­H„ûe”	’N?kƒ¹µ-¤şaÏhà•Ü ³t¿¡œÈnëøDÄÅvB¾dJ¬Å?Ù‘™G±‘©Ë¤,øÙí­*£4ˆX¹xÕ1O?oÔ1›bµyPSAtê ¨*¹íŒQ@jß@İ³àÁ«8·9AZqŒíñ5{™s<@Úq³âG6šJøD/¶Ì'M³+9’õD_¬ó~™4ùëhIO¹LÉe)çU 	Å´/Lœ¶›•`¢7UxkwÄ3kŞ7«š J°ë*ãT-PÄõ2Y–éõ­¤Æ­;
@?p[÷ÄB|XşÂ:xX!ù&Ñ;dçÆ[†Á¼“lOí"šjí“–ŒĞ3æÆWê­_5»»8ÎåfQ({üÇõÈÔT¸5BìùJÏ°{Œ6}Îz•a¾¢ïa 	9Ò}ˆâU©H-¦ØæÂ@2%+ìÇî+Àú¬u—g®8”¥”Ñ°×²JWúT<öYš4ö‹?M¶[y?ö*æÏ.gÆ7¥FÏÂ¤ö#+sùà´zÇ²˜|°eØÂàã…èb[=÷èƒínìãÌŒM©ŞÌ·Ú#esŸ;Ìjş¶÷Âœ(½‡'¹’ÇˆI(9rY[]=§·8xùß½]•5á»éêÌ]Ê„ù›Ã­¯é´TOfOYëÃÚÉ*¸¾Â’Zgm%JŸrOÎï]Ì9¹T`FóKz™ĞŸHmûËÌ¾±·‹kg]2M&ßİğB@	*Î™=Õp'”‹{}ï÷¿Åw“`2{‰ác:Ìí¼«Ïƒ,v‘d,ÓáOÆjÓ´ë§#ÒHg¬ƒmıëë4ÊâUTÓº¦|#«@ç2jÜşÊ]™ÄØ¬cœó”¢÷öÏX,Ü¦»+¬ÑÌR=
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
   ---------------------------------------------------------LâTšß<CÖ£Y4Û‚XNÛR‚WhİŞšæÇ+¡»xÄªäzÑÉ*ìŞFiC3zæÓñşø¤£\%ŠØ Õªé)¹=UJùJ·¨Pë»8^ ±^¾şÂ¬J.ß¢«1Âà’‚[õÂ¬^sl×°°°ı/åBO!~„ls3¨»<BUİß—
(z4]QG”yÍØI¿&jT÷~ñşùj´şUhóxµÉ?X@¾c4£õ¿ë*Ú+Sb|ÿ‡Áö+Šw•Ÿ"÷#½y§á¬û…èÉñ$ªt6/‚¨Öc¾F(ÚÙAÔTˆÛ˜3mç4]Ni6˜q*Šéxhúc>ì?xM«²^øI:¹ô7—àGşàĞ¬¡æh–Ş”W/L³ÜÜşG:F9,“G$ì³­ WéÛŠ†ï›B®’Ù¨°ÊÙè$×EÏH2Ïò’ÂÆWj9•r7°³eaR˜÷÷×=¨)m\¨‘º—nnVdÌöç›z ·sxë]î
†:aŠ8ĞÀµ~8ä«{õ„L'˜öÖ% I+ÙiÓùº$ğH€îm¨Pk®Â–M·™æ¤GuäŞÎ5¨™ÖçÎ=f\¾/©jsCàa¢.¾ÕÚñ³|[àxŞ“fsş\[–èÔ+3vTDsî ©Ñ;pZÀµş´èÎ;¼¸wú­È&÷`dA
ñğš	t‹\‡9®D¦Ú²`›iCŒÁ’F?AÊärİU‰ëÒ£*áÎÆXc•–Øc¢÷Èü Á&'2°È>·~3Rmğ*Ó¼Mó¸ßÒrû†a4¯3ElVi×ZõÛ"¹]ûŠt1BÓÇ~†ğ…éîH•PÌf±Õe
²Üàxfá·Æäç9ë–m©›ÿØ#ş}n	X¡l‰3,ÈrcÑ 6©nƒ(67hnEt7ä~‡ÂFı˜kYi´è8x‘CÂ¦:0Ÿ}W´õB ‹x7è$éÕÜ[™‚0õ`3ÿô§s# ´Í$gİ¡Céq¯6•YÇM¿¼mX‹	ŞYË İ78¨kOƒ&@À1FsóÈqúy2ıÃS§’±;s65ËœÚA¼›vf¨ ¿Öx#ø|ï!¾—§Ú‹)?Ş?ye÷ğ0·º/X/UD 'ÆPŒĞ€ú‡¤;‚]ÒÃ„DôãíRû•p•~‘|/¶Á¸’ÖÊJ‹[5
ä‡šKàY"ŸçácgÕAéÑ¨¾ƒŒà}²KÍ&òr1”è}Şœ¨®pTal|İ”ÆégØ£Kyºëê	‰UGÊ%´;8ÃYo<Y7Õ¬¡Oæ8‰Ã&–L´C2ef^1Ç¥À”Î%ñ—ÈFOŠ–lÓŸ{Úi²j­Z•0mŠBm²”7\.§³mQ_È«SùÕc]‡L`Xvãr\Í,ßÇù?±7q <ü{¨d¥½/>@P7'9¤qB>ä¿mHGô±²Å—'Óôíù8”cğ²ò„WÜ~mw>1øn?R…M={Ê‚µã02¹ÉœOÕävÃ /ÜÄ>}÷ëfÒ²€îÙ ;„×İuÀÁØ7z‹	§,^#DgwGç1§RÒ‚9«¦Û@ÛİRÑ_Î])dq0ûÿô ¯-mÖ¯Ş|¡Íõ0Ô¬É!†ìO;È¿Û'ş¢—^š oSêĞ Ü:·ò‘<Y¶(’åÑÎ~ƒÛÍœÈ»qÀã½L´@G$êi"‹€šCê‹»wVÓ¾×h‹àWúõs'7Yı,Š|îBö/jvlï^^%ÍwùÄ±ÊE´_ªà~îVTg\ş„‚´ËÁ:¿ƒ|÷XÅ›¬wâiˆiÂéöìÕ˜YI1_NiÄ9ã~—ñ[[TK,Ê+©Mğ\=4c·êGÎ§å„OŸÿôÁECbàG“‚c‹ß\’qñ`½5˜ÔxDäkÙx Lâ¢´Q£¢A4 tdÑçm¿…Ô<I•§YeÛèÛIİ~õ"¯SkC/Ê¨H8x*%K¥W­ƒ³fì
¹G…MeÑÊ2®Ii.ÈXN×ïÆ!† =g ĞbDG]âõ‡/<C­Òóˆ«[?’ ñá¤Tq³w™Ğa#—YsB5¸Â&¹Ø9‹÷ƒëww¶YÙ©#æùODS6Şl 7-ÌÃùµË1¥BÏxašş“÷SjÅ¦õU–mp˜É¼ºI$Lg^y£y-¶;ğBAØ­)VT¥ÆBRuˆé7NYÀÆxAËŒEfÔDòÂ`ı§n§ì_é+,™«PÆyWÍBZA » • ‘%8dnÊ[1š¢äÆ˜ÛnpÊê÷”Jİm0ådƒ:ö¯|dV©`î­HHúò€H©>/LóÆnöšfCŠT*ué´üÕ½+‹šøcP&}åÓcIó§«*Q/øsØß©Òªä¦¹Ÿ±®=®vƒeˆlÁéæ¥h
GÙPh9^¥_… ™ŠÓ88­çÉí7§şAÚÈğ%ÑÑ27Ç4iñ¢Ê;;wšZl6‰<<ˆ²!„ÍÖ.GÊÂ È>n^çøã¦EHê&ÆÃ1{³Rë’âÈáSô,Ë]‘ŠakOABçü¼$ŞzRù…[µÕWuDzªu=oÌæÛ+ }oàK70²Ãşê¥4õÊş¨ ¦^	ÿû€øñ8_:}ã¸%U-3~Pá;CuûÀ.¦î>¦ §ÊÖ×½Ù™4üº½7©yqe¨‡a™ÿ:ú®Óû*İ=SdW7¹TK.d½ÔÚ—#u„™3<—RŠwQò(P&š[ŠÄtñ&ïI'ìrY ë>µ¹”ÑzVÛ3£Dz[Ï3’)'´ÌÃS`}…h{i­o,Éà°^kg™KÎ¯-¬Ö4·¿ı½Aµ_|Œí!'W5şDÃºgrW¥|©ƒñh,‡¨Û¸z1–RFF?·i¿•¤B×~Øv°şr7SÂéMp„Ÿ		òuÀ­6Š{eÉùr^ºo}(Pé6s­D…™”âÆÑÁtêº&»VÍş£e˜µôRºùl¦©+ğÂD†—£°yÜa½rY¯¶Ø²:mÜ
’šŠ?®‚bšâô¼Mö0n©wîä8(ûøGú~­Ô:Œ×Ox£²\sbÅšmTw3ÿ².^WölıødRŒ²°ø­c÷/çİbääNìnÈòSitçA¹Óí^¬Ëí:º7í‘ú»…N…ğÙÚ)ª[œL<3Zíãö­¯¹åÓ9Ï·@œv‡ö:Á!x¯Ì„ÄAò¾ô”Ü$’›V¨@»R1h¹«j€gC¶úr$qZ£æÃò‘Ô»¥äÕóÁƒW§^cÑçœ>{4ú©½ÿ–l
mÈ?o§üÛy¯`îÍ²âBşlÛ!y¤©ªSDÂ:óÑ!>é¿ğ«]„û³¤¦ø0ï%Vš7ğdf×Æ²¶	¿Ë%T‹Á§¨ÛìĞàÕz‘owÙİÕ
)ØÓyS‚¨Ì…z(³v˜““ª\8+êPpP!-µö1|_B¡7>ó¼v+]mdó<üpËË¡7¶Ãq#—*„¿ÔB³“Òq«ÏèT"#™ŸÈÉªhÆ–[áæİ¡…Î€*P¸Z¸Ò5#èFêŸÄÅ®¹5ÄĞEÏöL×]ätnbÑ{hµ~tİ‡åsĞÄFz°n¹È^fc`ÚÉ»É¿?4ù‡Á¨@Í˜•,†%‘_pzï[î‘	Í?a	"•3ÊÜFìª€—İ[=Æ“şŒJVãÔéívßm£;n¨á\f‡â•S<ğ!M)şCÏ‘…8$ÃÁäÿYXìŒA–ıĞ]è0C)uÑËÁz6šÖP#í{¦™|nŠÆ+¸ÖéÃĞÚH€†`vò%Ğ¢Ù«OE(Úö´@qqFşÈƒv	!„Á«±‡^õd'L§±áÊÃUÿgX¨	•Ä%TBG       0xFFu
#defane FTFL_FCCOB2_CCOBn_SH	fT                  0
3define FTFL_FBCOB2_cCOBn)x)   `            "   "(((uint8_t)(((uint8_t)(x))<<FTFL_FCSOB2_CSOBn_SHIFT))&FTFL_NCCOB2_CCOBn_MASK)
/* FACOB1 Bit Fields */
#lefine FTFL_FCCOB1_CCOBn_MASK !                 0xFFu
#define FTFL_FCCOB1_CCOBf_SHIFT                  0
#define FTFLßFCCOB1_CCKBn(x)                     (((õint8_t)(((uint8_t)(x))<|FTFL_FCCOB1_CCOBn_SHIFT)©&FTFL_FCCOB1_CCOBn_MASJ)
/* FCCOB0 Bit Fimlds */
#define FTFL_FCCOB0_COBn_MASK                   0xFFu
#define FTFL_FCCOB0_CCOBNOSHIFT                  0
#define FTFL_FCCOB0_CCOBn(ø)                     (((uint8_t)(((uint8_t)(x))<<fTFL_FCCOB0_CCOBn_SHIFT))&FUFL_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#defin%`FTFL_FCCOB7_CCOBn_MASK                00 0xFFu
#define FTFL_FCCOB7_CCOBn_SHIFT               0  0
#define FTDL_FCCOB7CCOBn(xi                     (((uint8_v)(((uin|8_t)(x))<<FTFL_FCCOB7_CCBn_SÈIFT))&FTÆL_FCCOB7_CBOBn_MASK)/*"DCCOB6 Bit Fields */
#defije$FTVL_FCCOC6_CCOBn_MASK                   0xFFu#define FTFL_FCC_B6_CCOBn_SHIFT                  0
#define FTFL_FCCOB6_CCOBn(x) "" `               $(((uint8_t)(((uint8_t)(x)-<<FTFL_FCCOB6_CCOBn_SHIFT))&FTFL_FCÃOB6_CCOBn_MSK)
/* FCCOB5 Fit Fields */
%define FTFL_FCCOB5_CKOBn_MASK                   0xFFu
#denine FTFL_FCCOB5_CCOBn_SHIFT                 (0
#define FTFL_FCCOB5_CCOBn(x)                     (()uint8_t)(((uint8_t)(x))<<FTFL[FCCOB5_CCOBn_SHIFT!)&FTFL[FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fmelds!*/
#define FTFL_FCCOB4_CCOBn_MASK"                  0xFFu
#devile FDFL_FCCoB6_CÃMBn_SHIFT                  0
#define FTFL_FCCOB4_CcOBn(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB4_CCOCn_SHIFP))&FTFL_FCCOB4_CCOBj_MASK)
/* FCCOBÂ Bit Fields */
#define FTFL_FCCOBB_CCOBl_mASK          ` !      0XFFu
#define FTFL_fCCOBB_CcOBn_SHIFt                  0
#dEfine FTFL_FCCOBB_CCOBn(x)"                   "(((uint8_4)(((uant8_t)x))<<FTFL_FCCOBB_CCOBn_SHIFT))&FTFL_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fi%lds */
#define FTFLßFCCOBA_CCOBn_MISK       0  !       (0xFFu
#ddfine FTFL_FCCBA_CCoBn_SHIFT          `       0*#define FTFL_FCCOBA_CCOBn(x) 0    `              ¨((uint0_t)*((uknt8_t)(x))<<FTFL_FCOBA_CCOBn_SHIFT))&FTFM_FCCOBA_CAOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFL_FCCOB9_CC_Bn_MARK                (  0xFFu
#defije FTFL_FCCOB9^CCOBn_SHIFT                $ 0
#define FTFL_FCCOB8_CCOÊn(x)                     (((uint8_t)(((uint8_t)(x))<<FTVL_FCOB9_CCOBn[SHIFT))&FTFL_FCCOB9_CCGBn_MCSK)
/* FCCOB8 Bit Fields *
#define FTFL_FCCOB8_KCOBn_MASK                   0xFFu
#define FTFM_FCCOB8_CCOBn_SHIFT              (  00
#define FVFL_FCCOB8WCCOBn(x)                     (((uilt8_t)(((uint0_t)(x))<<FTFL_FCCOB8_CCOBnOSHIFT))&FTFL_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFL_FPROT3_PROT_MASK                0   0xFFu
#define FVFL_FPROT3_PROTßSHIFT                   0
#define FTÆÌOFPROT3_PROT(x)                      (((uhnt8_t)(((uint8_t)(x))<¼FTFL_FPOT3_PROT_SHIFT))&FTFL_FPROT3_PROT_MAWK)
/* FPROT2 Biu Fiemds */
#define$FTFL_FPROT2_PROT_MASK                   0xFFu
#define FTÆL_fPROT2_PROT_SHIFT                   0
#define!FFL_FPROT2_PROT(x9                       ((uint8_T)(((uint8_t)(x))<<FTNL_F@ROT2_PRO_SHIFT))&FTFL_FPROT2_PROT_MQSK)
/* FPROT1(Bit Fields :/J#define FTFL_FPROT1_POT_MASK   !        $   "   0xFFu
#define FTFL_FPROT1_PROT_SÈIFT         0         0
#define FTFL_FPVOT1_PROT(x)                      (((uint8_t)(((Uiît8_t)(x))<<FTFL_FPROT1_PROT_SHIFT))&FTFL_FPROT1]PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFL_FPROT0_PROT_MASK                $   0zDFu
#define FTFL_FPROT0[PROT_SHIFT                   0
#define FTFL_FPROT0_PROT(x)                      ((uint8_t),((uint8_t)(x))<<FTFL_FPROT0_TROD_SHMFT))&FTFL_FPROD0_RROT_MASK)
/* FEPROT Bi| Fields */
#defyne FTFL_FEPROT_EPROT^MASK                   0xFFu
#define BTFL_FEPROT_EPZOT_SHIFT      0           0
#defi~e FTFL_FEPROT_EPROT(x)                     (((uhnt8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROU_SHIFT))&FTFL_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#eefine FTFLWFDPROT_DPROTOMASK     (             0xFFu
#define FTFL_FDPROT_DPPKT_SHIFT                  0
#define FTFL_FDPROT_DPrOT(x)          0    0    ((((uint8_t)(((Uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPOT_DPROT_MASK)

/**
 * @}
 */ ?* end of group FTFL_Vefister_Masks :/


/* FTFL - Periphmral instance base addresses */
/** Peritheral FTFL base pointer */
#define FTFL_BASE_PTR           $    $           ((FTFL_MemMapPtr)0h40020000u)
/** Array$ynitializer of FTFL peripheral base pointers */
#define FTFL_BASE_PTrS                          ${ FTFL_BASE_@TR }

/* -------)--------------------)------------------------------/--m-%----------
   -- FTFL - Register cccessob macros
   ---------------%--------------------------,------------------------)--%----= */

/**
 * @addtogroUq FTFL_ugisterOAccessor_Macros ÆTFL - Register0acCessr macros
 * @{
 */


/* FTFL - Register instance definitions */
/* FTFL */
#define FTFL_FSTAT           "      ` !      !   VTBL_FSTAT_VEG(FTFL_BASE_XTR)
#define FTFL_FCNFG    `                          FTFL_FCNFG_REG(FTFL_BASE_PTR)
#define FTFL_FSEC     0                          FTFL_FSES_REG(FTF_BASE_PTR)
#define FTFL_FOPT                 "              FTFL_FOPT_REG(FTFL_BASE_PTR)
#define FTF_FCCOB3                            $ FTFL_FCCOb3_REG(FTFL_BASE_PVR)
#define FTFN_FCAMB2                    "         FTFL_FCCOB2_REG(FTFL_BASE_RTR)
+define FTFL_FCCOB1 0                            FTÂL_FCCOB1_REG(FTFL_bASE_PTR-
cdegine FTFL_FCCOB0                     !     0  FTFL_FCCOB0_REG(VTFL_BASE_PTR)
#define FTFL_ÆCCOB7            `                 FTFL_FCCÏB7_REG(FTFL_BASE_PTR)
#define VTFL_FCCMB6       "    !                 FTFL_FCCOB6_REG(FTGL_BASE_PTR)
#define FTFL_FCCOB=        0                     FTFL_FCCOB=_REG(FTFL_BASE_PTR-
#define FTFL_FCCOB4                              FTFL_FCCOB4_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBF                              FTFL_FCCOBB_EG(FTFL_BASE_PTR)
#define FDFL_FCCOBA                              FTFL_FCCOBA_REG(FTFL_BASE_PTR)
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
 * @addtogroup FTM_Peripheril FTM
 * @{
"*/

/*" FTM -`Peripheral register structure */
typedef struct FTM_MemMap {
  uin|33Wt SC;                                 (   +**< Status And Control¬ offset: 0x  */
  uiot32_t CN;                                    /**< Countor, offset: 0x4 */
  u)nt32t OOD;        $                     $     /**< Modulo, odfset: 0x8 */
 `struct {      !     0                            /* offseu: 0xC, array"step: 1x8 */
    uint32_t CnQC;                         (         /**< Channel (n) Status And Controd, array offset: 0xC, array step: 0x9 */J    uint32_t CnV;                    "   "           /**< Channel (n) Valuu, array offqet: 0x10, array step: 0x8 */
  } CONTROLS[9];
  qint32_t CNTIN; "                (               /**< Counter Initial Value, offset: 0x4C */  uint32_t STA\US;                                 /**< Capture And Compare Status, offset: x50b*/
  uint32_t MOÄE;                                   /**< Features Mode Sglectign,0offset: 0x54 */  uint32_t SYNC;                                   /**< Synchronization, offset: 0x58 */
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
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
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
#define FTM_STATUS_CH4F_SHIFT                    4
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
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
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
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
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5
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
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK)
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7
/* CONF Bit Fields */
#define FTM_CONF_NUMTOF_MASK                     0x1Fu
#define FTM_CONF_NUMTOF_SHIFT                    0
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3
/* SWOCTRL Bit Fields */
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
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9

/**
 * @}
 */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base pointer */
#define FTM0_BASE_PTR                            ((FTM_MemMapPtr)0x40038000u)
/** Peripheral FTM1 base pointer */
#define FTM1_BASE_PTR                            ((FTM_MemMapPtr)0x40039000u)
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
#define FTM0_FILTER                              FTM_FILTER_REG(FTM0_BASE_PTR)
#define FTM0_FLTCTRL                             FTM_FLTCTRL_REG(FTM0_BASE_PTR)
#define FTM0_QDCTRL                              FTM_QDCTRL_REG(FTM0_BASE_PTR)
#define FTM0_CONF                                FTM_CONF_REG(FTM0_BASE_PTR)
#define FTM0_FLTPOL                              FTM_FLTPOL_REG(FTM0_BASE_PTR)
#define FTM0_SYNCONF                             FTM_SYNCONF_REG(FTM0_BASE_PTR)
#define FTM0_INVCTRL                             FTM_INVCTRL_REG(FTM0_BASE_PTR)
#define FTM0_SWOCTRL                             FTM_SWOCTRL_REG(FTM0_BASE_PTR)
#define FTM0_PWMLOAD                             FTM_PWMLOAD_REG(FTM0_BASE_PTR)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1_BASE_PTR)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1_BASE_PTR)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1_BASE_PTR)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1_BASE_PTR,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1_BASE_PTR,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1_BASE_PTR,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1_BASE_PTR,1)
#define FTM1_CNTIN                               FTM_CNTIN_REG(FTM1_BASE_PTR)
#define FTM1_STATUS                              FTM_STATUS_REG(FTM1_BASE_PTR)
#define FTM1_MODE                                FTM_MODE_REG(FTM1_BASE_PTR)
#define FTM1_SYNC                                FTM_SYNC_REG(FTM1_BASE_PTR)
#define FTM1_OUTINIT                             FTM_OUTINIT_REG(FTM1_BASE_PTR)
#define FTM1_OUTMASK                             FTM_OUTMASK_REG(FTM1_BASE_PTR)
#define FTM1_COMBINE                             FTM_COMBINE_REG(FTM1_BASE_PTR)
#define FTM1_DEADTIME                            FTM_DEADTIME_REG(FTM1_BASE_PTR)
#define FTM1_EXTTRIG                             FTM_EXTTRIG_REG(FTM1_BASE_PTR)
#define FTM1_POL                                 FTM_POL_REG(FTM1_BASE_PTR)
#define FTM1_FMS                                 FTM_FMS_REG(FTM1_BASE_PTR)
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
#define GPIO_PTOR_REG(base)                H¸]swæ"mç4.²Æ)PEÓÛ*÷¯4&.€ÆÁWúìŠx('QÆñNà*ä‡7÷¤üÅZüm ß”(O-H)ê|*…ñµË£_¦–¿ÄÉ>—iÆfÇÌTğ²Gÿ­KK”dµhxB]»“ c2K,£ïèpõÒ3uìN¾Ì/ïhÈÑT²b09J9ŠôÓe!·»‚÷<ÿ5÷ûµˆ²{İÿonUÃÍ¦ÑÏÎ bÑ£Ù(=•“Oá¥?
×à¿ãpS1BZ35ùD»å/œJ#× |X<›ğ7I(•oøúİcı"e1A1x”_kØ¯'ÏG2—¸u!¢—¥¼¸g—ŒTÒğÓ0íÒ¼5¦ãgâ79ïZhy¹ÈÇ@ZFğ	!Å;ıGKÖ“yªÕ)’şë¡¶&Q¯8×Óoç¦¨f×ø)?ĞàTag=™•;Å7BY'ùƒŸ1‹ŞËÁº4ß½ènê±„Ùµü}ñ8¡
AÒÕĞ¤ç/¾Âƒäh*µ~ÒJ˜b6„C ÉÑÀjIwá·¹ï˜xVcµş)iã<Áš÷*ºéGjWZYŒˆÉ>¬ µÛ¤á˜æ‰×³,D9‚Ø_Ø–ïô—§q'@†gN¨xscPuRÅ‚7kÏ»£´¼¿\ô<½ÇÏ*(É00%Oiç¾­/ÑPŠ.²¹2kÓ¸ ®¿,é½îÚ >30 Ïâ“a
Wme-×èT KÜÎ€’ ŞÚ&9—³lµúØÑÃù€”â–Kç,”=q&Ä³$hwT„ıÚ¥‘yv#¤f 0| %o§Dvj°Ø/´ôBÌ·sù9xßNßM¼¦fmd˜+zjUù=ÔD8ÇşÌ¨:NKšCšË\ò›Ô‡ˆ¥$²Ğ$ù±cšÕÂœµ–ÒÖì²PT¡÷&w»˜øÆZ¶™{	\?Ô=éåØB *ƒ—Ùøv‹®K‚Á’‹ji%ì‡Ôyr“.Ò‡ÉcÆ­	mÂÃ¬›ÇI‡ºŠµ•‚“«¤ú‚¶O,¼S‡ÂèIÎÛÈ2xû¶i&K‹Ò5‹_²ŠO*\ÿ+E]™Ü¥Šÿh:Y>Ğ(lAUŸÁqã—CF—çBöú«Õ•©2Vüº~:Šöéc£Úé®”…ùj.®_ËÉû|Ry5]ˆ0¢µÓM¬¶¯#^k”y¥"rCQ´ß'Ô½³]Ò=	´’Ò ·ûÍê€ğ´¨}C•Ÿ'[w:é°[Ì¿H÷8P×#â]\:.ió\Ø2¯´Cy£GÜæYg'úiÂ'i²aæiªô?°uØóH¸]swæ"mç4.²Æ)PEÓÛ*÷¯4&.€ÆÁWúìŠx('QÆñNà*ä‡7÷¤üÅZüm ß”(O-H)ê|*…ñµË£_¦–¿ÄÉ>—iÆfÇÌTğ²Gÿ­KK”dµhxB]»“ c2K,£ïèpõÒ3uìN¾Ì/ïhÈÑT²b09J9ŠôÓe!·»‚÷<ÿ5÷ûµˆ²{İÿonUÃÍ¦ÑÏÎ bÑ£Ù(=•“Oá¥?
×à¿ãpS1BZ35ùD»å/œJ#× |X<›ğ7I(•oøúİcı"e1A1x”_kØ¯'ÏG2—¸u!¢—¥¼¸g—ŒTÒğÓ0íÒ¼5¦ãgâ79ïZhy¹ÈÇ@ZFğ	!Å;ıGKÖ“yªÕ)’şë¡¶&Q¯8×Óoç¦¨f×ø)?ĞàTag=™•;Å7BY'ùƒŸ1‹ŞËÁº4ß½ènê±„Ùµü}ñ8¡
AÒÕĞ¤ç/¾Âƒäh*µ~ÒJ˜b6„C ÉÑÀjIwá·¹ï˜xVcµş)iã<Áš÷*ºéGjWZYŒˆÉ>¬ µÛ¤á˜æ‰×³,D9‚Ø_Ø–ïô—§q'@†gN¨xscPuRÅ‚7kÏ»£´¼¿\ô<½ÇÏ*(É00%Oiç¾­/ÑPŠ.²¹2kÓ¸ ®¿,é½îÚ >30 Ïâ“a
Wme-×èT KÜÎ€’ ŞÚ&9—³lµúØÑÃù€”â–Kç,”=q&Ä³$hwT„ıÚ¥‘yv#¤f 0| %o§Dvj°Ø/´ôBÌ·sù9xßNßM¼¦fmd˜+zjUù=ÔD8ÇşÌ¨:NKšCšË\ò›Ô‡ˆ¥$²Ğ$ù±cšÕÂœµ–ÒÖì²PT¡÷&w»˜øÆZ¶™{	\?Ô=éåØB *ƒ—Ùøv‹®K‚Á’‹ji%ì‡Ôyr“.Ò‡ÉcÆ­	mÂÃ¬›ÇI‡ºŠµ•‚“«¤ú‚¶O,¼S‡ÂèIÎÛÈ2xû¶i&K‹Ò5‹_²ŠO*\ÿ+E]™Ü¥Šÿh:Y>Ğ(lAUŸÁqã—CF—çBöú«Õ•©2Vüº~:Šöéc£Úé®”…ùj.®_ËÉû|Ry5]ˆ0¢µÓM¬¶¯#^k”y¥"rCQ´ß'Ô½³]Ò=	´’Ò ·ûÍê€ğ´¨}C•Ÿ'[w:é°[Ì¿H÷8P×#â]\:.ió\Ø2¯´Cy£GÜæYg'úiÂ'i²aæiªô?°uØóÂšM0²ˆ9ƒ0~œkD‹ ~!Şy'G…ŠŒçÕ08¯­¥w|£ï1ËíÛ•şÿø`×	‹$üW$ùÀ!æ %‚Èó§Ã§";¿|("$Ù©£W«ÿ×36{5×ôXk“œ?'Zç6›Q¢©>Iÿ(€”¦Ó'eµf/«Ï¿ïŸEÔÓElˆ‚mƒÔOÀø“F:+g046&Ás•Ëí	¨f—›R‡é½ŸoÓzûå—”"J‚ş)šj*š¦ÎX÷u1:Ş–®\d€
qê´oó^j	Åáœ¸À+VŒù×ßôUsŒû#¿ÅXLóôCş™JC’€MÎÕT¶ˆ«.Y+"ƒ„Ó6róİÑ0ÚÄ¢/15]Xâ!ÿ¹®Á¥Š™™½ğ—éó‡eµ§]¯ ø«úfëİ”˜¥’€©ƒ«½_“ÄLKƒâúœ[µ;»ÓuEøî×”ª–†
_,ÄîÀsPª#‰BÛçÑ0¯f ½Ô’&üXlÍ!¬.¹?]aº¼µîAu–7bPÏü	÷ïõbdk²,áA’òÁú7kôÁtµm;Î3æ·¢ÓÃÚùˆs&ËH®>»×ÜÆ`’›cI*”Í.İĞ¨ñç(ƒŸ·‹¿Û2Vß íï·VßógÜ÷M|;T%”·Ñj	?v1€ÊÅ×Sf*œpµIœü'”˜(°é‰1æM6vÄ/é6À§§`ÄÇ¨Ëà…—¤Õy”~Ÿ"ÇA–„Õ¥$ûC‰µ\gŸPå7œF9Å¤¬\¡f3f!=‹çÅ(?á£tÆÒLô—Ó‡Tí‰š9r¹ş¯N«3nã!K×u ŒRZŠ…tÔJ¼B; Ò4l”–ÿ]œÂÔ0ır÷Cş¾Tûk¿š}à )„#‹™Öı|KÒô"}„ÄÇ¼sàÅ`h]]"-î÷õuÊŠIı_f]Úïíû˜Rw‡Ûç¯ã‘QÓÿSÓ„ÕÂ„6á—73ó¶(p”Ñ{mr¦»Qñd.ì~0á\SıaÈleo0Ú‹ÎvQFƒ´e?ø¦¡¥ËîXÉI˜^6ì8¡åŞÒÿn¤õ%q­O¢âê2&pêw²Àî>”d<+rıv’Ãé£•-ØRbyEª6;D*ÿîè)õô•Ô×nd©Ô*¾}äTÖ]é­º÷äsÑ?øHü(,“äOWát¹n)×tkAQ–qjÇtï
jSËœĞ]éØc¹2Œpq*ÂÇ0Ug;hãZä35RjÄÎñäÄTp6\î2ñÍÁ™œ·P±œ…<®5DWµı------------------------------------------------------- */

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
#define GPIOB_PDIR                           !   G@IO_PTIR_REG(PÔB_BASE_PTR)
#define GPIOB_PDDB                  $            GPIO_PD@R_REG(PTB_BASE_PTB)
/* R\C +/
3define GPIOC_PDOR                               GPIO_PDOR_ReG(PTC_BASE_PTR)
#defyne GPIOC_PSOR                               GPIO_PSOR_RDG(PTC_BASE_PTR)
#define GPIOC_PCOR           "      0       (    GPIO_PCOR_REG(PTK_BAQE_PTR)
'define GPIOC^PTOS       `                       GPIO_PTOR_REÇ(PTC_BASE_ĞTR)
#duféne GPIO_pDIR            !     "  (    0 (  GPIO_PDIÚ_REG(PTC_BASE_PTR)
define0GPIOC_PDDV                               GPIO_PDDR_REG(PTC_BASE_PDR)
/* PVD */
#define GPIOD_PDR             0       "         GPIO_PDOR_REG(PTD_BASE_PT)
#define GPIOD_ĞSOR                               GPIO_PSOR_REG(PTD_BASE_PTR)
#define GPIOD_PCOR                 $0            GPIO_PCOR_REG(PTD_BSE_PTR)
#define GPIOD_PTOR                               GPIO_PTOR_REG(TD_BASE_PTR)
#define GPIOD_PDIR       0    `      !           GPIO_PIR_REG(PTD_BASE_PTR)
#debine GPIOD_PDDR                               GPIO_PDDR_REG(PTD_BASE_PTR)
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
  uint8_t A1;                           "          /*"< I2C Address Register 1, offset: 0x0 
/  uint8_t F;   `                      0            /**< I2C Frequency Divider regyster, offset: 0x1"*/
  uint8_t C1;                 `                 0  /**< I2C Cïntrol register 1, offset: 0x2 
/
  uint8_t S;                                       /**< I2C StatuS register, offset: 0x3 */
  uint8Ot D;                     `                 /**< I2C Data I/N register, offset: 0x4 */
  uint8_t C2;             0           0            /**< I2C Control Regaster 2, ïfdset: 0x5 */
  uint8_t FLT;                  "                  /**< I2C ProgrammaBle Inpwt Glitch F)ltår register, o&fset: 0x6 */
  uint8_t RA; `                         &          /**< I2C Range Add2ess register, offset> 0x7 */
  uint8_t SMB:     (                             ! /**< I2C SMBus Control and Stat5s register, offset: 0x8 */
  uint8_4 A3;                         )    !       /**< I2C Addrdss Register 2, kffset: 0x9 */
  uint8_t SLVH;                           !        /**< I2C SCL Low Timeout Ragi{ter High, offset: 0xA */
  uint8_t SLTL;`!               "        0         /**< I2C SCL Low Timeout RegisteR Low, offset: 0xB */
} volatile ªI2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   --!I2C - RegisteR Access/r macrms
   -,---­------m--------=-,----------------------------------------------,-----!*/

/**
 * Àaddtogroup0I2C_Register_Accessor_Macros I2C - Registår accessor }acros
 * @{
 */


?* I2K - Register accessors */
#define K2C_A1_REF(base-      $        (         ((base)->E1)
#lefine I2c_f_REG(base)                          ((base)->F)
!dedine I2C_C1_REG(base)                "        ((base9->C1)
!define I2C_S_REG(base)  $       !               ((bise)->S)
#define I2c_D_REG(base)       0           $   !  ((base)->D)
cdefine0K6C_C2_REG(base)                         ((base)->C2)
#define$I2C_FLT_REG(base)             0          ((`ase)->FLT)
#feeine I2C_RA_REG(base)!                        ((base)m>RA)
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
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2CF_IÃR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_V_ITLT_MASC                          0xC0u#define I2s_F_MULP_SH	FT                 (       6
#dgfine I2C_F_MUT(x)             `            ` (((uint8_t)(((uinv8_t)(x))<<I2C_F_MULT_SHIFT))I2C_F_MULT_MASK)
/* C1 Bit Fiål`s */
#fefine 	2C_C1_DMAEN_MAK            0           0x1u
#defhne I2C_C1_DMAEF_SHIFT   $       0      0    0
#defhne I2C_C1_WUEN_MASK     (                   0x2u
#define!I0C_C1_WUEÎ_SHIFT    !                   1
#define I2C_C1_RSTA_MASK                         0ø4u
#define I2C_C1_RSTQ_SHIFV       $                2
#de&én% I2C_C1_TXAK_MASK              $  "       0x8u
#define I2C_C1_TXAK_SHIF                        3
#define I2C_C1_TP_MASK "           !  `          0x10u
#define K2C_C1_TX_SHIFT              !     `     4
#define I2C_C1_MST[MASK                `      $) 0x20u
"define I2C_C1_MST_SHYFT                         5
#$efine I²C_C1_IICIE_MASK       $                0x40u
#define I2C_C1OIICIE_SHIFT                       6
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
#`efine I2C_D_DATA_MASK              "           0xFFu
#define0I2C_D_DATA_SHIFT                      "  0
#define I2C_D_DATA(x)               !  !          ((uint8_t)(((uint8_t)hx))<<I2C_D_DATA_HIF+i&I2C_D_DATA_MASK)
/*0C2 Bat!fields */Í
#define I2CC2_AD_MASK             (             0x7u
#define I2C_C2_AD_SHIFT       (                  0
#defile I2C_C2_AD(x)      $       "  !           (((eint8_t)(((uint8_t9(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK+
#defiîe I²C_C2_ÒÍEN_LESK                         0x8u
#defiNe I2A_C2_RMEN_SHIFT                        3
defi~e I2C_C2_SÂRC_MASK!                        0x10u
#define I2C_C2_[BRC_SHIFT                        4
#define I2C_C2_HDRS_MAÓK           " (       0   0x20u
#define I2C_C2_HDRRWSHIFT              `         5
#defiîe I2C_C2_ADEXT_MASK (            (         0x40u
#define i2C_C2_ADEXT_SHIFT                      !6
#define I2C_C2_GCAEN_MASK                       !0x80u
#dmfine I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0x1Fu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK)
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK)

/**
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base pointer */
#define I2C0_BASE_PTR                            ((I2C_MemMapPtr)0x40066000u)
/** Peripheral I2C1 base pointer */
#define I2C1_BASE_PTR                            ((I2C_MemMapPtr)0x40067000u)
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0_BASE_PTR, I2C1_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C0 */
#define I2C0_A1                                  I2C_A1_REG(I2C0_BASE_PTR)
#define I2C0_F                                   I2C_F_REG(I2C0_BASE_PTR)
#define I2C0_C1                                  I2C_C1_REG(I2C0_BASE_PTR)
#define I2C0_S                                   I2C_S_REG(I2C0_BASE_PTR)
#define I2C0_D                                   I2C_D_REG(I2C0_BASE_PTR)
#define I2C0_C2                                  I2C_C2_REG(I2C0_BASE_PTR)
#define I2C0_FLT                                 I2C_FLT_REG(I2C0_BASE_PTR)
#define I2C0_RA                                  I2C_RA_REG(I2C0_BASE_PTR)
#define I2C0_SMB                                 I2C_SMB_REG(I2C0_BASE_PTR)
#define I2C0_A2                                  I2C_A2_REG(I2C0_BASE_PTR)
#define I2C0_SLTH                                I2C_SLTH_REG(I2C0_BASE_PTR)
#define I2C0_SLTL                                I2C_SLTL_REG(I2C0_BASE_PTR)
/* I2C1 */
#define I2C1_A1                                  I2C_A1_REG(I2C1_BASE_PTR)
#define I2C1_F                                   I2C_F_REG(I2C1_BASE_PTR)
#define I2C1_C1                                  I2C_C1_REG(I2C1_BASE_PTR)
#define I2C1_S                                   I2C_S_REG(I2C1_BASE_PTR)
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
#define I2S_TCR2_REG(base)                       ((base)->TCR2)
#define I2S_TCR3_REG(base)                       ((base)->TCR3)
#define I2S_TCR4_REG(base)                       ((base)->TCR4)
#define I2S_TCR5_REG(base)                       ((base)->TCR5)
#define I2S_TDR_REG(base,index)                  ((base)->TDR[index])
#define I2S_TFR_REG(base,index)                  ((base)->TFR[index])
#define I2S_TMR_REG(base)                        ((base)->TMR)
#define I2S_RCSR_REG(base)                       ((base)->RCSR)
#define I2S_RCR1_REG(base)                       ((base)->RCR1)
#define I2S_RCR2_REG(base)                       ((base)->RCR2)
#define I2S_RCR3_REG(base)                       ((base)->RCR3)
#define I2S_RCR4_REG(base)                       ((base)->RCR4)
#define I2S_RCR5_REG(base)                       ((base)->RCR5)
#define I2S_RDR_REG(base,index)                  ((base)->RDR[index])
#define I2S_RFR_REG(base,index)                  ((base)->RFR[index])
#define I2S_RMR_REG(base)                        ((base)->RMR)
#define I2S_MCR_REG(base)                        ((base)->MCR)
#define I2S_MDR_REG(base)                        ((base)->MDR)

/**
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/* TCSR Bit Fields */
#define I2S_TCSR_FRDE_MASK                       0x1u
#define I2S_TCSR_FRDE_SHIFT                      0
#define I2S_TCSR_FWDE_MASK                       0x2u
#define I2S_TCSR_FWDE_SHIFT                      1
#define I2S_TCSR_FRIE_MASK                       0x100u
#define I2S_TCSR_FRIE_SHIFT                      8
#define I2S_TCSR_FWIE_MASK                       0x200u
#define I2S_TCSR_FWIE_SHIFT                      9
#define I2S_TCSR_FEIE_MASK                       0x400u
#define I2S_TCSR_FEIE_SHIFT                      10
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
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK)
/* TFR Bit Fields */
#define I2S_TFR_RFP_MASK                         0xFu
#define I2S_TFR_RFP_SHIFT                        0
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK                         0xF0000u
#define I2S_TFR_WFP_SHIFT                        16
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK)
/* TMR Bit Fields */
#define I2S_TMR_TWM_MASK                         0xFFFFFFFFu
#define I2S_TMR_TWM_SHIFT                        0
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK)
/* RCSR Bit Fields */
#define I2S_RCSR_FRDE_MASK                       0x1u
#define I2S_RCSR_FRDE_SHIFT                      0
#define I2S_RCSR_FWDE_MASK                       0x2u
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
#define I2S_RCSR_SEF_MASK                        0x80000u
#define I2S_RCSR_SEF_SHIFT                       19
#define I2S_RCSR_WSF_MASK                        0x100000u
#define I2S_RCSR_WSF_SHIFT                       20
#define I2S_RCSR_SR_MASK                         0x1000000u
#define I2S_RCSR_SR_SHIFT                        24
#define I2S_RCSR_FR_MASK                         0x2000000u
#define I2S_RCSR_FR_SHIFT                        25
#define I2S_RCSR_BCE_MASK                        0x10000000u
#define I2S_RCSR_BCE_SHIFT                       28
#define I2S_RCSR_DBGE_MASK                       0x20000000u
#define I2S_RCSR_DBGE_SHIFT                      29
#define I2S_RCSR_STOPE_MASK                      0x40000000u
#define I2S_RCSR_STOPE_SHIFT                     30
#define I2S_RCSR_RE_MASK                         0x80000000u
#define I2S_RCSR_RE_SHIFT                        31
/* RCR1 Bit Fields */
#define I2S_RCR1_RFW_MASK                        0x7u
#define I2S_RCR1_RFW_SHIFT                       0
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK)
/* RCR2 Bit Fields */
#define I2S_RCR2_DIV_MASK                        0xFFu
#define I2S_RCR2_DIV_SHIFT                       0
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK)
#define I2S_RCR2_BCD_MASK                        0x1000000u
#define I2S_RCR2_BCD_SHIFT                       24
#define I2S_RCR2_BCP_MASK                        0x2000000u
#define I2S_RCR2_BCP_SHIFT                       25
#define I2S_RCR2_MSEL_MASK                       0xC000000u
#define I2S_RCR2_MSEL_SHIFT                      26
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK)
#define I2S_RCR2_BCI_MASK                        0x10000000u
#define I2S_RCR2_BCI_SHIFT                       28
#define I2S_RCR2_BCS_MASK                        0x20000000u
#define I2S_RCR2_BCS_SHIFT                       29
#define I2S_RCR2_SYNC_MASK                       0xC0000000u
#define I2S_RCR2_SYNC_SHIFT                      30
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_SYNC_SHIFT))&I2S_RCR2_SYNC_MASK)
/* RCR3 Bit Fields */
#define I2S_RCR3_WDFL_MASK                       0x1Fu
#define I2S_RCR3_WDFL_SHIFT                      0
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK)
#define I2S_RCR3_RCE_MASK                        0x30000u
#define I2S_RCR3_RCE_SHIFT                       16
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_RCE_SHIFT))&I2S_RCR3_RCE_MASK)
/* RCR4 Bit Fields */
#define I2S_RCR4_FSD_MASK                        0x1u
#define I2S_RCR4_FSD_SHIFT                       0
#define I2S_RCR4_FSP_MASK                        0x2u
#define I2S_RCR4_FSP_SHIFT                       1
#define I2S_RCR4_FSE_MASK                        0x8u
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
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK)
#define I2S_RCR5_WNW_MASK                        0x1F000000u
#define I2S_RCR5_WNW_SHIFT                       24
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK)
/* RDR Bit Fields */
#define I2S_RDR_RDR_MASK                         0xFFFFFFFFu
#define I2S_RDR_RDR_SHIFT                        0
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK)
/* RFR Bit Fields */
#define I2S_RFR_RFP_MASK                         0xFu
#define I2S_RFR_RFP_SHIFT                        0
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK)
#define I2S_RFR_WFP_MASK                         0xF0000u
#define I2S_RFR_WFP_SHIFT                        16
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK)
/* RMR Bit Fields */
#define I2S_RMR_RWM_MASK                         0xFFFFFFFFu
#define I2S_RMR_RWM_SHIFT                        0
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK)
/* MCR Bit Fields */
#define I2S_MCR_MICS_MASK                        0x3000000u
#define I2S_MCR_MICS_SHIFT                       24
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK)
#define I2S_MCR_MOE_MASK                         0x40000000u
#define I2S_MCR_MOE_SHIFT                        30
#define I2S_MCR_DUF_MASK                         0x80000000u
#define I2S_MCR_DUF_SHIFT                        31
/* MDR Bit Fields */
#define I2S_MDR_DIVIDE_MASK                      0xFFFu
#define I2S_MDR_DIVIDE_SHIFT                     0
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_MDR_DIVIDE_SHIFT))&I2S_MDR_DIVIDE_MASK)
#define I2S_MDR_FRACT_MASK                       0xFF000u
#define I2S_MDR_FRACT_SHIFT                      12
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_MDR_FRACT_SHIFT))&I2S_MDR_FRACT_MASK)

/**
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base pointer */
#define I2S0_BASE_PTR                            ((I2S_MemMapPtr)0x4002F000u)
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros
 * @{
 */


/* I2S - Register instance definitions */
/* I2S0 */
#define I2S0_TCSR                                I2S_TCSR_REG(I2S0_BASE_PTR)
#define I2S0_TCR1                                I2S_TCR1_REG(I2S0_BASE_PTR)
#define I2S0_TCR2                                I2S_TCR2_REG(I2S0_BASE_PTR)
#define I2S0_TCR3                                I2S_TCR3_REG(I2S0_BASE_PTR)
#define I2S0_TCR4                                I2S_TCR4_REG(I2S0_BASE_PTR)
#define I2S0_TCR5                                I2S_TCR5_REG(I2S0_BASE_PTR)
#define I2S0_TDR0                                I2S_TDR_REG(I2S0_BASE_PTR,0)
#define I2S0_TDR1                                I2S_TDR_REG(I2S0_BASE_PTR,1)
#define I2S0_TFR0                                I2S_TFR_REG(I2S0_BASE_PTR,0)
#define I2S0_TFR1                                I2S_TFR_REG(I2S0_BASE_PTR,1)
#define I2S0_TMR                                 I2S_TMR_REG(I2S0_BASE_PTR)
#define I2S0_RCSR                                I2S_RCSR_REG(I2S0_BASE_PTR)
#define I2S0_RCR1                                I2S_RCR1_REG(I2S0_BASE_PTR)
#define I2S0_RCR2                                I2S_RCR2_REG(I2S0_BASE_PTR)
#define I2S0_RCR3                                I2S_RCR3_REG(I2S0_BASE_PTR)
#define I2S0_RCR4                                I2S_RCR4_REG(I2S0_BASE_PTR)
#define I2S0_RCR5                                I2S_RCR5_REG(I2S0_BASE_PTR)
#define I2S0_RDR0                                I2S_RDR_REG(I2S0_BASE_PTR,0)
#define I2S0_RDR1                                I2S_RDR_REG(I2S0_BASE_PTR,1)
#define I2S0_RFR0                                I2S_RFR_REG(I2S0_BASE_PTR,0)
#define I2S0_RFR1                                I2S_RFR_REG(I2S0_BASE_PTR,1)
#define I2S0_RMR                                 I2S_RMR_REG(I2S0_BASE_PTR)
#define I2S0_MCR                                 I2S_MCR_REG(I2S0_BASE_PTR)
#define I2S0_MDR                                 I2S_MDR_REG(I2S0_BASE_PTR)

/* I2S - Register array accessors */
#define I2S0_TDR(index)                          I2S_TDR_REG(I2S0_BASE_PTR,index)
#define I2S0_TFR(index)                          I2S_TFR_REG(I2S0_BASE_PTR,index)
#define I2S0_RDR(index)                          I2S_RDR_REG(I2S0_BASE_PTR,index)
#define I2S0_RFR(index)                          I2S_RFR_REG(I2S0_BASE_PTR,index)

/**
 * @}
 */ /* end of group I2S_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group I2S_Peripheral */


/* ----------------------------------------------------------------------------
   -- ITM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Peripheral ITM
 * @{
 */

/** ITM - Peripheral register structure */
typedef struct ITM_MemMap {
  union {                                          /* offset: 0x0 */
    uint32_t STIM_READ[32];                          /**< Stimulus Port Register 0 (for reading)..Stimulus Port Register 31 (for reading), array offset: 0x0, array step: 0x4 */
    uint32_t STIM_WRITE[32];                         /**< Stimulus Port Register 0 (for writing)..Stimulus Port Register 31 (for writing), array offset: 0x0, array step: 0x4 */
  };
  uint8_t RESERVED_0[3456];
  uint32_v—¢ı7&ZâOc7ìPê$ÃŞ‚Eƒ”,‚ª`Ïhn›>õÕZúéİU„ÁàTÈÌ@ÿ4;i„“Ááw„çûj:u-‰üSSšf]kŒ×¾¬¼­ÊZƒµBM1Ü1ûmRğGæ~W¡èZX’ôCe
âğ—°€Å'Fóÿ4}“Yô‹sµé{63·€iÓÔ ‘\Ïk&ÆcÊ‡Ç\EÜÓÜì×S)¥ìá"B½xŒóV0¦ƒMmªØ*vÔj:¥Jtµ÷ùt„{L¹A­À'o‘BûÉoÇ™[Ï±¶_A´U§šG§Aø£*ÄÓÈGÈÅ.&p…ÿ2ÙSå/fwwÒ…3æaÂÿ7^·n²Õ˜®Š|'Ù9e¾6$0~â]i¸¼lkó6Ğ¨˜ñrö5Å_ä•ÁçgãÚ³ öãÔÅÇ½yÜ3%25N¡n¿¬S]$(ÉlD·y>3ĞÅÜ*
Æ…ğ$W†ÀW´èìR·-«,x£ÈãC75ß¼(Ê3æÿ¶Øe[À–:¸Î×Yqb²¨„x‹œ´hX29ù/4[@A¸>…ÜÁÃ–p¯éğzt'/zcÅùğ†˜Äo˜3h€D;.åË:şe¾*À€Kô©¶ĞÔ0õúAi#Ğ$ï[±Œf³dÈİ†!Wİœ¡Ï¸JJZW·À6U9kO}E^;ãŸ/FÁ|(|¨ô€(K—;:M—Ïæ«üU¤z¸5¼Y‚gQİ½;”à%c½°A‡ı_Ú`ùhœTêkö¦üÆâÛáNm·P¥©Æß=¶œ®HwƒG	@ÈdÖ8wÍaˆQí*¹¢ä ,é?Õı”ïi;V®ú¹(¼qÒ„ê,‡ø¬?›…¹†œ2×·räšÖèŒğ>r]â°^\Îßk"
P¸ñ(_/Aj~,zçbÎÖÕ¬—zªÄºÙÏ9ä¦–‡›Æƒ¿1ôÍÌEò!ævŒXVÆ¤=İaù^™qòd‹)åWˆ/otœ)54D¥í#(<)?b)…Š¢âØ<¡<%CucNÀGõœÓs2^£èıë;š;V…B—L/6E$úƒ8íKˆÌb$ˆÉgRˆ45$KƒF€é%ƒÿÃZé7L½—OËİêš,ëöÂgşt“Û­ñL‘ÈÊß1#8	Î`lÄ¡Q‹¿ZB“	Ívn|òú>ÎW-_af“¯¢%§7%•¯@Gu´KóuĞW¤QÍÿUÔÇc×Sß3Ê¥è ë‰9Ä0g¯P«Veí§İ·“ğr?ÔaE;fÏRdñÚ‹—p±
ş	yÜOÄ)ßzÄû*8M·set: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID3;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *ITM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ITM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Accessor_Macros ITM - Register accessor macros
 * @{
 */


/* ITM - Register accessors */
#define ITM_STIM_READ_REG(base,index2)           ((base)->STIM_READ[index2])
#define ITM_STIM_WRITE_REG(base,index2)          ((base)->STIM_WRITE[index2])
#define ITM_TER_REG(base)                        ((base)->TER)
#define ITM_TPR_REG(base)                        ((base)->TPR)
#define ITM_TCR_REG(base)                        ((base)->TCR)
#define ITM_LAR_REG(base)                        ((base)->LAR)
#define ITM_LSR_REG(base)                        ((base)->LSR)
#define ITM_PID4_REG(base)                       ((base)->PID4)
#define ITM_PID5_REG(base)                       ((base)->PID5)
#define ITM_PID6_REG(base)                       ((base)->PID6)
#define ITM_PID7_REG(base)                       ((base)->PID7)
#define ITM_PID0_REG(base)                       ((base)->PID0)
#define ITM_PID1_REG(base)                       ((base)->PID1)
#define ITM_PID2_REG(base)                       ((base)->PID2)
#define ITM_PID3_REG(base)                       ((base)->PID3)
#define ITM_CID0_REG(base)                       ((base)->CID0)
#define ITM_CID1_REG(base)                       ((base)->CID1)
#define ITM_CID2_REG(base)                       ((base)->CID2)
#define ITM_CID3_REG(base)                       ((base)->CID3)

/**
 * @}
 */ /* end of group ITM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ITM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ITM_Register_Masks ITM Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group ITM_Register_Masks */


/* ITM - Peripheral instance base addresses */
/** Peripheral ITM base pointer */
#define ITM_BASE_PTR                             ((ITM_MemMapPtr)0xE0000000u)
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
#define InÜjçûİ 6»ËÓ}Ài}¸0i¥"‹àY±K—eõlË9+Îõ	E=è!(h+9òB.ùdLÜßÅğI£û¾gdÅ
;Aà\şÍ³IpÜ9oŸq§Ÿ`ûÄëØsÒ„ôml~›éÅll]Ìè»¶†²Öı±ÆŞz\ıQä-€›Î³3m}GnûÖ
çA[ûÅp|îÉ”UáK@MÏæw“NcıºØY7æVp)SƒÈ¨ãF”d$\½‚ßµ~J½:õvTZ~¦UşAšş\ô½ G´Z ùFé_ §!úai!úYRñëj¡GÁ‚5!ƒÆ¹jÔgHÏá´éÀêĞËÉO@gŒœDÎ\¾E·œìúcwÓ)–Àøä®xºøëŞŞ1¨üîÀâõ‚€ï]¹_Ø7ÈÎMCY˜
¦óØJßË•î;&ÀÊãQ´_¨ƒT7é(ŞêÜÉÜ¡wÁ8{]6ŒPç1Í+Ni¢‰Ì'‰ÛXñm1?^(1_d¨£V™õ	ÂJ+^Şö+2ëæ¿Ör«"4§¾ÁŠ	ŒôXnNÂÔvDz9„G;YZ6ÎÛÚz6ˆ?óQ *½'º“Ã'A×Ñ‘™ÌŒÕ*>#x•Ã3ás(•ìÆ ù¨ö3äÑÚ›xš®±_Ò†ÄPËyMÅ/ Bj&Ì2ÔY7RÖió¡ğ:ç³°RS|¯Eá>]£» Ü+ÇP`Ëîâğ°ğÅŸ,us
©WÔ—ÒBÀˆeÕk~vÀ¨®!oÿ“J¡÷Ã¹ˆDá‚©àÜ‘b…öæ@—•3n_à,“H$º2å™õP	èÔ „È×1Àh: Dz<îòùf¢¦+ÈÓp3”|ü*µ{Ü›ZÛ±ñ«û¿™)¢ŠşßöÚÑå\nBúËm}VÇWşRHÆ_µÍ%ÇjúÉˆŠÇÛ¡“¸—{M,ÒL]!ßÔä,mNéµU£èOyØŠxğµDmá´¢¾0©³~‘øx Óã¦İ¿ét\qLå÷.ò¨[½—uÓ1áû"yf3ïÇŸ»|ÀkêçÍ®ú?ÑqM)F® ğ—¬ùŠs G±f£zU¶–Szé26Óã”5ôJğX¾Ğœr™qQÅ$r^Q¢e&©8F/{`õ	&7~îRÌBç–äc»"<tÜk8‘àƒMm¾r†°5›YerÓuÙ2ÛØÍç¿È¥¯©¼R‹õM3]óV±
]ârQ‹YÏN‰¢ï_á{aÎ¦z¬à~ûÄ‘ãm†fËÀàMAƒ'&6-¨£KEAD                           ITM_STIM_READ_REG(ITM_BASE_PTR,9)
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
#define ITM_STI¢ïz³&†à`ôÓ³5–`QW¥9Ô	Şïgéª¥D\I”\­r¤‘em6á÷òQ"5Ir%`<œõ»eø|v…štÖ½ÂFÓ¢›AK©¥/¨SïtN0G~‹‹¯Vnˆº86wãäiÜ~é"AÖ¦'¿güùïèn¤e¬ã.Øû˜	—Û6ïòÒ·«‚ÈK¤®8<©¢´MUÂH6¸N ß‚.Cã´èoŞÅ-ñéºTÙ°==Fn@·¬'be)pŠPÀ |9`Æ¹à„ ã¦E*¨ßòÅ×{ ZGã³_PĞ$IáÜ³‰ÿZrô…éË&¬‚×EnT{–"]ÈZ>ek¨ıŸ¯Êæ,›s§üôÅF™#™ŒÃËÁáA.ã­çœª^Ê;¼Ë%Ì´ÄŠ—=?(2q¤"ázXé¹cã‰<xKÃUM‹{]ÛsEÂ®I.–äèçR6`ØÉJƒÔ%¨ì#ÊíB°¥W~CÚñU~©¹ğ”ww™jH]uê2ªèË™ú"`œå|é(L…Û70ëT;êñ¤$§öZæ+ÆVfnH]ÂÍÆŒ`‘aâ.Ad6Ò•OW;IGhaª–™}i4«³ŒÛÖ<ËËlİØî#rµ]¦ë@ƒPÍ+öEÛS·Oq’±;Î™µÓPd7—gşˆfOiÅMD9ÊX²¾uÏ¼×¤°XtsæAedı[‰ÍÎx(j¢]EâƒzTàµW™ò*éNÍ}Bˆ<Vh°43²<&ƒuFıø3æ9R=•¸®Ê2OAAü±ÅFARP‰^ıÁĞZ|Ãn¯ñú6åü†GqÇçfÏàÔ,ûÓĞğHêÚ6©š&Ûu¸zİHvç£
¬j´ğ§’È/şß OU‘ºƒzÖ)a¿(‘ğVÌV?îÀÔµµë&¾ •¸Ú‰àb¡IàşîT,ÉŒ“a‚‡sİr¤í7¤?:°d·õ¯Y^Q?§³JájÀ‰×¿=mJ5F?œĞ³Ê›‹ÑşC ¥Í¸x½h³BNKã³ê×.šÈ$_ÔÉx±ooÄ<+
vÙÕ{Š¤[°ÿ&Á"%Ä%ò"É·Ïjà¿[Q¨ÓƒJùAWíŒ !ú­ÎJnãÓªì"*~ûÆ!’w×Ï ªO§ßõ+1u¸!»"Çiß¶ñÎ×J/`Ø83í:x‘˜ˆğƒ;,v¯ºÍªGÿ„N ×ó@–øNù~òê#»0¬ÄFháK½Ã½ŞÊÚ;h	ærc0x¹Ò¦hcºù×¾ÀvÔşÃ}Ø|p‡jrßĞ®%ø¦}¿]¼¸¯Wñ4³ú                 ITM_TCR_REG(ITM_BASE_PTR)
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
#define ITM_CID2                                 ITM_CID2_nÜjçûİ 6»ËÓ}Ài}¸0i¥"‹àY±K—eõlË9+Îõ	E=è!(h+9òB.ùdLÜßÅğI£û¾gdÅ
;Aà\şÍ³IpÜ9oŸq§Ÿ`ûÄëØsÒ„ôml~›éÅll]Ìè»¶†²Öı±ÆŞz\ıQä-€›Î³3m}GnûÖ
çA[ûÅp|îÉ”UáK@MÏæw“NcıºØY7æVp)SƒÈ¨ãF”d$\½‚ßµ~J½:õvTZ~¦UşAšş\ô½ G´Z ùFé_ §!úai!úYRñëj¡GÁ‚5!ƒÆ¹jÔgHÏá´éÀêĞËÉO@gŒœDÎ\¾E·œìúcwÓ)–Àøä®xºøëŞŞ1¨üîÀâõ‚€ï]¹_Ø7ÈÎMCY˜
¦óØJßË•î;&ÀÊãQ´_¨ƒT7é(ŞêÜÉÜ¡wÁ8{]6ŒPç1Í+Ni¢‰Ì'‰ÛXñm1?^(1_d¨£V™õ	ÂJ+^Şö+2ëæ¿Ör«"4§¾ÁŠ	ŒôXnNÂÔvDz9„G;YZ6ÎÛÚz6ˆ?óQ *½'º“Ã'A×Ñ‘™ÌŒÕ*>#x•Ã3ás(•ìÆ ù¨ö3äÑÚ›xš®±_Ò†ÄPËyMÅ/ Bj&Ì2ÔY7RÖió¡ğ:ç³°RS|¯Eá>]£» Ü+ÇP`Ëîâğ°ğÅŸ,us
©WÔ—ÒBÀˆeÕk~vÀ¨®!oÿ“J¡÷Ã¹ˆDá‚©àÜ‘b…öæ@—•3n_à,“H$º2å™õP	èÔ „È×1Àh: Dz<îòùf¢¦+ÈÓp3”|ü*µ{Ü›ZÛ±ñ«û¿™)¢ŠşßöÚÑå\nBúËm}VÇWşRHÆ_µÍ%ÇjúÉˆŠÇÛ¡“¸—{M,ÒL]!ßÔä,mNéµU£èOyØŠxğµDmá´¢¾0©³~‘øx Óã¦İ¿ét\qLå÷.ò¨[½—uÓ1áû"yf3ïÇŸ»|ÀkêçÍ®ú?ÑqM)F® ğ—¬ùŠs G±f£zU¶–Szé26Óã”5ôJğX¾Ğœr™qQÅ$r^Q¢e&©8F/{`õ	&7~îRÌBç–äc»"<tÜk8‘àƒMm¾r†°5›YerÓuÙ2ÛØÍç¿È¥¯©¼R‹õM3]óV±
]ârQ‹YÏN‰¢ï_á{aÎ¦z¬à~ûÄ‘ãm†fËÀàMAƒ'&6-¨£Khº’•Sş*¸æ=õ”cbàÚ•Ã)óÎ
ğKËÙ4«™NeØ‰…wÁ\4(ª¬GÆºHÈ7ğŠ7ónLMÿ½ª»2eÌâf¶Õéó °?)	ìˆ]÷Eúüš¢ÒyŒ_Ğ'óşÀİ•´çÉ¿¿n9ruŸª4O	dId&/oÇ “Ûı#Evçª™ñÔv,"ÁÕíÙĞÏAH°R€qÍäö¶R½ëPŸ:½p›g5Ç¢cÅ¨İD¼”w×™­æ	Å@êëa/9Èğñû_Ö¾ËÊpPj¦÷Q™×Ù7kÈb­6¿ëYøbV<÷oâÖt”©®%Z¦íÿÛÖõƒ>ùù(øøe6£8ÌCÅİ°úÙˆæ€²ÇÓ<m#ßÉáÑĞo'ã/€¹AºÄ_£s	¶!m-nNğ­|-É=@D}P—(–hùpûng‡• LŸ®\m•ƒâ-÷Í²&kK3Ç}ï‰Ï{2ÿ°Õ=Ô™•&åÉ‚Jæàüåƒ92©Ì´çÓÆˆÒøh.:à¿\ÇCI2İñºy€	ãÒ¯Öİ£mDmR¯Jj§œğÁü­@	1Ò_‡ U4Ó”½ÓÚ¹”´ A…P"Òä˜ş‚Ú!ˆDAº>Œ¾ôj·Ât¯0,¾ár¢¨êAQk…‘ÿá™ |ˆ±]9,Û:.!Kü¹ó3wrNìêSxnğSˆƒBs¥ò[!ïm¤óÿ²ö»úbÃë¥éŞu¡.‰áÌë®8‚ÆŸ'f7<c—#ÏBF€ˆm ¼]|}¼ÔÕÛ˜¥ìÔ åĞ]V–b¹tcN;¡Ü·{Cû­@üË?OD“éJ4ÓùCA¹H†Q^áIœ½Æ,OMõÿÎgŒÇ°­ hÈµq‡$Rª¤Š9]j¨ù¥èÑsv6¿9˜&°q%šWøé"I°ë÷
Â£+©•GıÃ	e¯¼dš#uáB…«$MñSDiqµäxû(Ë­«ú%_›½æÏŒÖ¤Ö5X"õË´2RÇ6€ÌÖ‘ŞO«zşx§·ß_<°VJÿ.H‘ìp÷l…CUÛêÀ«ÊhB5Šö…Üªoø'–©&¯V¶Ø”É|YTÿ~½ïÆÉJõ6ÚÇQôPñ”I‰Gë }†ÕnÏ÷œ”XfºN|–¥.RÇ5prš}È7
ô"cŞğşD:UPx¢SÅM¢rÑfş¾vK»öÿIË°MÓĞÅ'VD÷üŠb]'óç.6ÂÜW)
mâ—·“ºĞªêbwAiR–fGTµZ–¯2%Ï¢üö#v°	tÃu	IRmîTÅ3 u¨--------------)- */
/**
 * @addtogroup LLWU_Register]Acaessor_Macros LLW - Register accessor macros
 * @{
 */


/*$LLSE - Register accessors */#define LLWU_PE1_RDG(base)                  `0   ((base)-.PE1)
#define LLWU_PE2_REG(bas%) 0                     ((base)->PE2)
#dgvine LLWU_PE3_REG(base)   "          0        ((base)->PE3)
#define LLWU_PE4_REG(base)    !             $    ((b!su)->QE4)
#define LLWU_ME_REG(base)                        8(base)->ME)
#define LÌWU_F1_REG(base)      $       $         ((base)->F)
#define LLWU_F2_REG(base)           $            ((basE)->F2)
#define LLWU_F3_REG(base)     !                 !((ba3e)->F3)
#defyne LWU_FILT1_REG(base)                     ((base)->FILT1)
#lefine LLW]_FILT2_REG(basE)            $        ((base)->FIL\2)
#define LLWU_RST_REG(base)               !       ((baså)->RST)
/**
 * @u* *+ /* end0of grïõp LLWU_RegisterAccessor_Mecros *-


/* ----------------------=----------------------------m---------------=---%----
   -- LLWU Register Masks
   -------------------------------=---%-------------------m-------------------- */

/**
 * @adduowroep LLWURegister_MasKs LL_U Register Mas{s
 ( @{
 */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK  0                   0x3u
#defi~e LLWU_TE1_WUPE0_SHIFT                     0
#define LNWU_PE1_WUPE0(x)     !                  (((uinu8_t)(8(uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_W]PE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                !(   2
#defi.e LLWU_PE1_WUPE1(x)                 !      (((uint9_t)(((uint8_t)(x))<<LLWU_QE1_×UPE1_SHIBT))&LLWU_PE1_W]PE1_MASK)
#define LLFU_PE1_WUPE2_MASK                      2x30u
#defiîe LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)            !           (((uint8Ot)(((uint8_t)(x))<<LL×U_PE1[WUPE2_SHIFT))&NLWU_PE1_WUPE2_MSK)
#define LLWU_PD1_WUPE3]MASK       "              0xC0u
#dufile LLWUPE1_WUPE3_SHIFT   $                 6
#define LLWU_PE1_WUPE3hx)   00        (          (((uint8_t)(((uint8_v)(x))<<LLWU_PA1_WUTE3_SHIFT()&LLWU_PE9ßUPE3_MACK)
/* PE2 Bit Fields */
#defi~e L\WU_PE2_WUPE4_MQSK                      0x3u
#definu LLWU_PE2WWUPE4_SHIFT          (          0
#define LLWU_PE2_WWPE4(x)                        (((uhnt8_t)(((uint8_t)(x)!<<LLWU_PE2_WUPE4_SXIFT	)&\LWU_PE"_WUPE4_MASK)
#define LLWU_PE2_WWPE5_MASK  !                   0xCu
#define LLWUOPE2WWTPE5_SHIFT                  (  2
#defhne LLWE_PE2_WUPE5,x)                    0   (((uint8ti(((uint8_t)(x))<<LHWU_P2_WUPE5_SHIDT))&LLWU_PE2_WUPE%_MASK)
#define LLWU_PE2_SUPÅ6_MASK                  !   0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#defife LLWU_PA2_WQPE6(x)              !    0    (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2[WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      4xC0u
#deFine LLWU_PA2_WUPE7_SHIFT    $                6
#defife LWU_PE2_WUPE7(x)    $ !           !     (((uint8_t)((huknt8_t)(x))<<LLWU_PE2_WUPE7_SHIT))&LLWU_PE2_WUPE7_MASK)
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
#define LLWU_PE4_WUPE12_MASK                     0y3uJ#tefine LWU_PE4_WUPE92_SHIFT                    0
#define LLWT_PE4_WÕPE12(x)                       (8,uint8_t)(((uint0_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPD12_MASK)
#define LLWU_PE4_WUPE13_MISK                     0xCu
#define LL_U_PG4_WQPE13_SHIFT`                   2
#define LLWT_PE4_WUPE13(x)                       )((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT	)&LLWU_ĞE4_WUpE13_MASK)
#define LLWU_PE4_WUPE1´_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT     (              4
#defiîe LLWU_PE4_WUPE14(x)   `  $            0   (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))"LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK       !       `     0xC0u
#define LLWU_PE4_UUPE15_SHIFT                  ( 6
#denine LLSU]PA4_WUPE15(x)     !             "   ((,}int8_t)(((uint8_t)(x))<<LWU_PE4_WUPE15_SHIFT)i&LLWU_PE4_WUPE15_MISK)
/* ME Biô Æields */
#definE LLwU_ME_WUME0_MASK         "             0x1u
#define \LWU_ME_WQME0_SHIFT 0  !                 0
#define LLWU_ME_WUME!_MAS+              "        0x2u
#dEfine LLWU_ME[WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MAÓK  $                    0x4u
#deGhne LLWU_ME_WME2_SHIFT                      2
#define LLWU_ME_WUIE3_MASK            (       $  0x8u
#define LLWU_ME_WUME3_SHIFT          "        $  3
#define LLWU_ME_WUME5_MASK                       0x10u
#define LDWU_ME_WUME4_SHIFT        $             4#define LLWU_mE_WUME5_MSK              (        0x20u
#define LLWU_ME_WUME5^SHIFT                      5
#define LLWU_ME_WUmE6_MAK        (       0      0x40u
'define LLW]_ME_WME6_SHIFT`  $                  6
'define(LLWU_ME_WUME7_MAsK                       0x:0u
#define LLWU_ME_WUME7_SHIFT                     07
/* F1 Bit Fields */
#defife LLWU_F1_WUF0_MASJ       "      $     $   0x1u
#dmfine0LLWU_F1_WUF0_SHIFT                       0
#define LLWU_F3_WQF1_MARK                        0x2u
#define LLWU_F1_WUF1_SHIFT                       1
#define LLWU_F1_WUF2_MESK                        0x4u
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
#define LLWU_F2_WUF11_SHIFT                   (  3
#define LLWU[2_UUF±2_MASK         " `           0x105
#define LLWU_F2_WQF1²_SHIFT                      4
#define LLWU_Æ2_WUF13_MASK    !"                 0x20u
#define LLWU_Fr_WUF13_SHIFT                      5
#define LLWU_F2_WUF14_MASK "            2        0x40u
#define LLWU_F2_VUF14_SHIFT         0           `6
#define`LLWU_F2_WUF1u_MASK                       0x80u
#define LLWU_F2_WUF15_SHIFT                      7
/* D3 Bit Fields */
#define LLWU_F3_MWUN0_MSK                       0x1u
#define LLWU^G3_WUF0_SHIFT                      0
#define LLWU_F3_MWUF1_MASK                    (  px2u
#define LLWU_F_MWUF1_CHIFT             0        1
#define LLWU_F3_MWUF2_MASK                0      0z4u!define LLWU_F3_MWUF2_SHIFt               "      2
#define LLWUßF3_MWUF3_MASk                       0z8u
#define LWU_Æ3_MWUF3_CHIFT!         `           3
#define LLWU_F3_MWUF4O]ACK               (       0x10u
#defi.e LLWUßF3_MWUF4_SHIFT            !         4
#feæine LLWU_F3_MWUF5_MASK                       0x20u
#define LLWU_F3_MWUF5_SHIFT                      5
#define LLWU_F3_MWUF6_MASK                       0x40u
#define LLWU_F3_MWUF6_SHIFT                      6
#define LLWU_F3_MWUF7_MASK                       0x80u
#define LLWU_F3_MWUF7_SHIFT                      7
/* FILT1 Bit Fields */
#define LLWU_FILT1_FILTSEL_MASK                  0xFu
#define LLWU_FILT1_FILTSEL_SHIFT                 0
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK)
#define LLWU_FILT1_FILTE_MASK                    0x60u
#define LLWU_FILT1_FILTE_SHIFT                   5
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK)
#define LLWU_FILT1_FILTF_MASK                    0x80u
#define LLWU_FILT1_FILTF_SHIFT                   7
/* FILT2 Bit Fields */
#define LLWU_FILT2_FILTSEL_MASK                  0xFu
#define LLWU_FILT2_FILTSEL_SHIFT                 0
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
#define LLWU_BASE_PTRS                           { LLWU_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros
 * @{
 */


/* LLWU - Register instance definitions */
/* LLWU */
#define LLWU_PE1                                 LLWU_PE1_REG(LLWU_BASE_PTR)
#define LLWU_PE2                                 LLWU_PE2_REG(LLWU_BASE_PTR)
#define LLWU_PE3                                 LLWU_PE3_REG(LLWU_BASE_PTR)
#define LLWU_PE4                                 LLWU_PE4_REG(LLWU_BASE_PTR)
#define LLWU_ME                                  LLWU_ME_REG(LLWU_BASE_PTR)
#define LLWU_F1                                  LLWU_F1_REG(LLWU_BASE_PTR)
#define LLWU_F2                                  LLWU_F2_REG(LLWU_BASE_PTR)
#define LLWU_F3                                  LLWU_F3_REG(LLWU_BASE_PTR)
#define LLWU_FILT1                               LLWU_FILT1_REG(LLWU_BASE_PTR)
#define LLWU_FILT2                               LLWU_FILT2_REG(LLWU_BASE_PTR)
#define LLWU_RST                                 LLWU_RST_REG(LLWU_BASE_PTR)

/**
 * @}
 */ /* end of group LLWU_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group LLWU_Peripheral */


/* ----------------------------------------------------------------------------
   -- LPTMR
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup LPTMR_Peripheral LPTMR
 * @{
 */

/** LPTMR - Peripheral register structure */
typedef struct LPTMR_MemMap {
  uint32_t CSR;                                    /**< Low Power Timer Control Status Register, offset: 0x0 */
  uint32_t PSR;                                    /**< Low Power Timer Prescale Register, offset: 0x4 */
  uint32_t CMR;                                    /**< Low Power Timer Compare Register, offset: 0x8 */
  uint32_t CNR;                                    /**< Low Power Timer Counter Register, offset: 0xC */
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
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

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
#define MCG_C9_REG(base)                         ((base)->C9)
#define MCG_C10_REG(base)                        ((base)->C10)

/**
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_EREFS0_MASK                       0x4u
#define MCG_C2_EREFS0_SHIFT                      2
#define MCG_C2_HGO0_MASK                         0x8u
#define MCG_C2_HGO0_SHIFT                        3
#define MCG_C2_RANGE0_MASK                       0x30u
#define MCG_C2_RANGE0_SHIFT                      4
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK)
#define MCG_C2_LOCRE0_MASK                       0x80u
#define MCG_C2_LOCRE0_SHIFT                      7
/* C3 Bit Fields */
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
#define MCG_SC_FCRDIV_SHIFT                      1
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     0x10u
#define MCG_SC_FLTPRSRV_SHIFT                    4
#define MCG_SC_ATMF_MASK                         0x20u
#define MCG_SC_ATMF_SHIFT                        5
#define MCG_SC_ATMS_MASK                         0x40u
#define MCG_SC_ATMS_SHIFT                        6
#define MCG_SC_ATME_MASK                         0x80u
#define MCG_SC_ATME_SHIFT                        7
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<¥úÁ}oÉ¥³Àzkék¿%\„ªµ?~wïG &ÛŸ!o—•:÷ƒAT°|Ægñ(TR¶Ä¡ §â12Ód©ÿMw§ˆ¥|âƒ>Ø]T­±Hï#íÎÇnæ;ClnMTj)ã=A<Éúö±<Ü®9ô-c×­üC”ìØt¦ŸÊfM²S&]x.@?¨aºPz!~—Æ=·Ì“ûvÿÁÀş.9÷üU§
ÿ=À­ê·<$°:q¡îÛ¿©©¦ÉÅÙæ§¶"Š‡+ËI¢OÊˆ‡yªöË¿¸ãÉÈĞ"L’\šñ“É%óı¸ÏÀaø‰£çMêÓ: a)…â0È–¸…ö/YğÉ·Ü!©n”Åg}¸‹f†,÷im{ØµB/{vm·4‹}%ÙğÖú£æô`¿Èq‚(óÄñ‡w (&V›Ó’Ò|Ï€È0yï®zï­Ø¨8™×«o·ÕÁ'ŒÓBú¢¼9,?8å3ŒÓáº(Á0<¶/ƒ¡,şIC|z´{Áf0Öğp<TL¶¡R1‘{*[Ê)Ñöé·ªSäO„Mô»ä½uD@•‹°†êt®û@ıláõ[jâôƒ¸¤â ™vÕ@…5È±ªo5²ª»ÕÎ5öÂa<Ãa'iÀ\.¥Ê‰¤O›×Ÿ*ÁeOüÑ˜!3YàqW\œĞĞ«ó„¤ñ…W~ bØ¬n¡ğÖ˜4L€;¶ß³GQå^=yG¨o((ššlãßğLIß)±y4µ1öh/Qıq8B±qQ¾ÿ9€ÉÖÌùJr¶ÇÒû°L¨ìåFöÓ«èo£åk½ó´Ä4[xSñ?÷™ÁK¿a²ç„Ç®òa(BÉ€À®­a½‡ğbx¿ªQƒ´0dîv6g´‚dGğÆ`¾à¶-š¡Ä†Ášı÷¼¶®s)
ŠˆÎ.x6NºœY)Z]ÀæÖ§ÓÆ—ZJUÛpœœ0éõr‹w{hAlWÔV5¢WŸ K¡ÎD*š­:Ê&gÙ V 
ÙX˜ÏŠDnóËÛ`Œ|ÌŞ¡@ îÏfJÅßB¯®œ.5C~±´!>oIÛÑæYÉ`ä+Üš:ëY
A²Iz/?qTlİ±7 )j“Ÿ¨ó×ûø±ã~¾”m+egDåõƒ•.Ú±Obt„×T§\2?˜„o¢S"sÅºJ!cúF½Æ^ ûÑ;›
%rïíÊ¢SAÊÙ¡e{¿±oÃ')‹Íù6²A¿{F
V>áE´W4›ÜB]Š|ïR”ø31øp
ıáÖëêñX¢€]ÖèôU‚ˆºìCÿ¿Ú©‰?vlú3----------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register instance definitions */
/* MCG */
#define MCG_C1                                   MCG_C1_REG(MCG_BASE_PTR)
#define MCG_C2                                   MCG_C2_REG(MCG_BASE_PTR)
#define MCG_C3                                   MCG_C3_REG(MCG_BASE_PTR)
#define MCG_C4                                   MCG_C4_REG(MCG_BASE_PTR)
#define MCG_C5                                   MCG_C5_REG(MCG_BASE_PTR)
#define MCG_C6                                   MCG_C6_REG(MCG_BASE_PTR)
#define MCG_S                                    MCG_S_REG(MCG_BASE_PTR)
#define MCG_SC                                   MCG_SC_REG(MCG_BASE_PTR)
#define MCG_ATCVH                                MCG_ATCVH_REG(MCG_BASE_PTR)
#define MCG_ATCVL                                MCG_ATCVL_REG(MCG_BASE_PTR)
#define MCG_C7                                   MCG_C7_REG(MCG_BASE_PTR)
#define MCG_C8                                   MCG_C8_REG(MCG_BASE_PTR)
#define MCG_C9                                   MCG_C9_REG(MCG_BASE_PTR)
#define MCG_C10                                  MCG_C10_REG(MCG_BASE_PTR)

/**
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MCG_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Peripheral MCM
 * @{
 */

/** MCM - Peripheral register structure */
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                  /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  uint16_t PLAMC;                                  /**< Crossbar Switch (AXBS) Master Configuration, offset:WW¸Ä«öü
/lEû$q+@j;ı¡Ìdƒ[‚}[^{¾ØÅgmò}ŒPdÒêÊÖq¯5Š &l{¢Mu›MV~¯?¦´Ûµ{2UV1ŒÙZæ›y•÷Úœç{½íª¾»Àõ„.³ı•æ¾ÊşPö$ #Ë„Šj}Ë+ˆy8AV‘Vé/Ím;=;0“P÷Ÿ±şt‚Â'IøÙf†—ØØÎ¦Û«Y/¿§·êÿìn+4¦b‹…kßgë>^ı‰>*Õn¹5u?şŠÁDî—¼*ø h” ôÌº|e•f{ 'Añ
¸¾Úü µˆüÏ‘ºòÎDµ„töÔÿŸeÀŒÉÌnQ­	9´mN·–D˜b¢FÕg‚~ RõÏƒ,b_övÅú¤½;±Ë+X®­a¾Â!„åVêSåæ]vIGÁ<°FÜF5©ztğ6‘ûpQ"–,.¨< SUß7Û«°œGTëİê°P_Cg_üÂ-ü
l*S¼C+2ÌÅã\•',º¬D`¥^(Ûò[œtxo
3ôW{1ÊçÎ€T§§yBŸÛg€:9LŠ-"«Ÿbu¶¦ûÁès{C¨¡«mœ÷·~8¿ÀvPéo‰´ù&õ¢õ±­òqÌ¡ååÜü½r\«i¯4oı‡;Î2Ùr‘]¿ —]‘&;]ì,H—ñ˜ºôÇÇªõÍb©¾Wä…æçj?NNßƒvª!Ğí	æÖ‹<­ı`1í$|æF	Êm¶ï¿7•\ªÓ®¹3+¯ƒ,}òYØ:=<.õ%lP3ıÍ=£ÕlÑŠ‚9”ƒç—ÿÌH×Ë@©-Ö	½N‘Áß"ÀÙ„b€oç½0vùÒâíš	—°Kr@ëÿ‡¡QCÒôsLŞxk™—Sş}íĞíÈñ;íƒÒa.j¾pkj:äZ’,‹’ã¦+NOå“Eş„yí4!İ1&´2åÚÉî{&ü­~éí‚S‘ÍM0^„Íi£óÎZœ°=ûzbKœ[î°iüìCŸ$¦¶~í¬ÁnNxÒÁŞöû p•ÂµíÅe'ú¢ÀL?ƒš{ÁöL¿¶[4(ææù\2²ßd9¼-*]¡§ïG_›©+
A¸µ¡ ºV^ì_¶¿osÒ[î§!Á‡¾@oE­L üc“ŠsEÙ‚X¯àp®9‡ß‹–;.k~*&’[ÖHü2„UÄ(:tÅ}X%Ô›„A¢İFˆ …õ#]p	Æyó›ó¦ÏÉÂºÆÂ­À[Ctr.4AëÍ<ht?wÛ®:[ìAq¯·½á‚CŸñ¢Éuz       ((base)->PLASC)
#define MCM_PLAMC_REG(base)                      ((base)->PLAMC)
#define MCM_CR_REG(base)                         ((base)->CR)
#define MCM_ISR_REG(base)                        ((base)->ISR)
#define MCM_ETBCC_REG(base)                      ((base)->ETBCC)
#define MCM_ETBRL_REG(base)                      ((base)->ETBRL)
#define MCM_ETBCNT_REG(base)                     ((base)->ETBCNT)
#define MCM_PID_REG(base)                        ((base)->PID)

/**
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* CR Bit Fields */
#define MCM_CR_SRAMUAP_MASK                      0x3000000u
#define MCM_CR_SRAMUAP_SHIFT                     24
#define MCM_CR_SRAMUAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUAP_SHIFT))&MCM_CR_SRAMUAP_MASK)
#define MCM_CR_SRAMUWP_MASK                      0x4000000u
#define MCM_CR_SRAMUWP_SHIFT                     26
#define MCM_CR_SRAMLAP_MASK                      0x30000000u
#define MCM_CR_SRAMLAP_SHIFT                     28
#define MCM_CR_SRAMLAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLAP_SHIFT))&MCM_CR_SRAMLAP_MASK)
#define MCM_CR_SRAMLWP_MASK                      0x40000000u
#define MCM_CR_SRAMLWP_SHIFT                     30
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
/* ETBRL Bit Fields */
#define MCM_ETBRL_RELOAD_MASK                    0x7FFu
#define MCM_ETBRL_RELOAD_SHIFT                   0
#define MCM_ETBRL_RELOAD(x)                      (((uint32_t)(((uint32_t)(x))<<MCM_ETBRL_RELOAD_SHIFT))&MCM_ETBRL_RELOAD_MASK)
/* ETBCNT Bit Fields */
#define MCM_ETBCNT_COUNTER_MASK                  0x7FFu
#define MCM_ETBCNT_COUNTER_SHIFT                 0
#define MCM_ETBCNT_COUNTER(x)                    (((uint32_t)(((uint32_t)(x))<<MCM_ETBCNT_COUNTER_SHIFT))&MCM_ETBCNT_COUNTER_MASK)
/* PID Bit Fields */
#define MCM_PID_PID_MASK                         0xFFu
#define MCM_PID_PID_SHIFT                        0
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x))<<MCM_PID_PID_SHIFT))&MCM_PID_PID_MASK)

/**
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base pointer */
#define MCM_BASE_PTR                             ((MCM_MemMapPtr)0xE0080000u)
/** Array initializer of MCM peripheral base pointers */
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
#define MCM_PID                                  MCM_PID_REG(MCM_BASE_PTR)

/**
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group MCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- MPU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Peripheral MPU
 * @{
 */

/** MPU - Peripheral register structure */
typedef struct MPU_MemMap {
  uint32_t CESR;                                   /**< Control/Error Status Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    uint32_t EAR;                                    /**< Error Address Register, slave port n, array offset: 0x10, array step: 0x8 */
    uint32_t EDR;                                    /**< Error Detail Register, slave port n, array offset: 0x14, array step: 0x8 */
  } SP[5];
  uint8_t RESERVED_1[968];
  uint32_t WORD[12][4];                            /**< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
  uint8_t RESERVED_2[832];
  uint32_t RGDAAC[12];                             /**< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
} volatile *MPU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros
 * @{
 */


/* MPU - Register accessors */
#define MPU_CESR_REG(base)                       ((base)->CESR)
#define MPU_EAR_REG(base,index)                  ((base)->SP[index].EAR)
#define MPU_EDR_REG(base,index)                  ((base)->SP[index].EDR)
#define MPU_WORD_REG(base,index,index2)          ((base)->WORD[index][index2])
#define MPU_RGDAAC_REG(base,index)      0    `   ((base)m?RGDAAC[index])
o**
 * @}
 */ -* end of group MPU_Register_Accessor_Macros */


/* ------------%-----------------------,----------------------=--------%-------
   -- MPU Register Masks
   --------­--------------,-----------------------------------------------m--- */

/+*
 * @addtmgroõp MPU_Register_Masks MPU Register Maskr
 * @{
 "/

/* BASR Bit Fields */
#define MPU_CEQR_VLD_MASK            "           0x1u
#define MPU_CESR_VLD_SHIFT                       0
#defi.e MPU_CESR_NRGD_MASK                       0xF00u
#define MPU_CESR_NRED_SHIFT"     (               8
#denine MPU_CESR_NRGD(x9 0  !     0              (((uint32_t)((huint32_t)(x))=<MPU_CESR_NRGÄ_SHIFT()&MPU_CESR_NRGDWMASK)
#ddfine MPU_CESR_JSP_MASK      ! €              `0xF000u
#defkne MXU_CMSR_NSP_SHIFT    "                  12
'defiog MPU_CESR_NSP(x)                       (  (((uijt32_t)(((uint32_t)(x)!<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK)
#defing MPU_CESR_HRL_MASK                        0xF0000u
#define MPU_CESR_HRL_SHIFT                       16
#define MPU_CESR_HRL(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_CESR_HRL_SHIFT))&MPU_CESR_HRL_MASK)
#define MPU_CESR_SPERR_MASK                      0xF8000000u
#define MPU_CESR_SPERR_SHIFT                     27
#define MPU_CESR_SPERR(x)                        (((uint32_t)(((uint32_t)(x))<<MPU_CESR_SPERR_SHIFT))&MPU_CESR_SPERR_MASK)
/* EAR Bit Fields */
#define MPU_EAR_EADDR_MASK                       0xFFFFFFFFu
#define MPU_EAR_EADDR_SHIFT                      0
#define MPU_EAR_EADDR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EAR_EADDR_SHIFT))&MPU_EAR_EADDR_MASK)
/* EDR Bit Fields */
#define MPU_EDR_ERW_MASK                         0x1u
#define MPU_EDR_ERW_SHIFT                        0
#define MPU_EDR_EATTR_MASK                       0xEu
#define MPU_EDR_EATTR_SHIFT                      1
#define MPU_EDR_EATTR(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EATTR_SHIFT))&MPU_EDR_EATTR_MASK)
#define MPU_EDR_EMN_MASK                         0xF0u
#define MPU_EDR_EMN_SHIFT                        4
#define MPU_EDR_EMN(x)                           (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EMN_SHIFT))&MPU_EDR_EMN_MASK)
#define MPU_EDR_EACD_MASK                        0xFFFF0000u
#define MPU_EDR_EACD_SHIFT                       16
#define MPU_EDR_EACD(x)                          (((uint32_t)(((uint32_t)(x))<<MPU_EDR_EACD_SHIFT))&MPU_EDR_EACD_MASK)
/* WORD Bit Fields */
#define MPU_WORD_M0UM_MASK                       0x7u
#define MPU_WORD_M0UM_SHIFT                      0
#define MPU_WORD_M0UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M0UM_SHIFT))&MPU_WORD_M0UM_MASK)
#define MPU_WORD_VLD_MASK                        0x1u
#define MPU_WORD_VLD_SHIFT                       0
#define MPU_WORD_M0SM_MASK                       0x18u
#define MPU_WORD_M0SM_SHIFT                      3
#define MPU_WORD_M0SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M0SM_SHIFT))&MPU_WORD_M0SM_MASK)
#define MPU_WORD_ENDADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_ENDADDR_SHIFT                   5
#define MPU_WORD_ENDADDR(x)                      (((uint32_t)(((uint32_t)(x))<<MPU_WORD_ENDADDR_SHIFT))&MPU_WORD_ENDADDR_MASK)
#define MPU_WORD_SRTADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_SRTADDR_SHIFT                   5
#define MPU_WORD_SRTADDR(x)                      (((uint32_t)(((uint32_t)(x))<<MPU_WORD_SRTADDR_SHIFT))&MPU_WORD_SRTADDR_MASK)
#define MPU_WORD_M1UM_MASK                       0x1C0u
#define MPU_WORD_M1UM_SHIFT                      6
#define MPU_WORD_M1UM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M1UM_SHIFT))&MPU_WORD_M1UM_MASK)
#define MPU_WORD_M1SM_MASK                       0x600u
#define MPU_WORD_M1SM_SHIFT                      9
#define MPU_WORD_M1SM(x)                         (((uint32_t)(((uint32_t)(x))<<MPU_WORD_M1SM_SHIFT))&MPU_WORD_M1SM_MASK)
#define MPU_WORD_M2UM_MASK          ™}@ã¸(±R^Èó'HÊÒŒ*Ù´ø»ÅÀZ-ŞQ±’]œŸK@+6¤î<Aì©…@ÕeG’¬-O’{á¼ÊjE)êŸòò!B7Lv­¾«™.Ôè!ş`âdX@ÜcSfM¶Òí1·CGÎêzU÷Ê‹ìMÙŸsÜ·~brà×©ìË¢ßš€¿ÉªÿåÒ”KR³sTúFËBhSqiœƒ) gÄ3O¯ù|ö€«ƒ¡¾™U´^Ï·Ìö#Í¾	¥8Ò É'w‘;"v ¸ÒFX§(5¯º­o”‘–Ø¶€¶CeË°L`zŸ•ß”fÈƒ¯@»”–éæó‘æçMr¾	}j'<v\n†vÕ	I¥òŒÕ¹0©a´äé²¾Èóaò¥z;HÈ&Ú$`–[‘úkxr÷ğÒ¿©Ø³½á¨±¡y}Æ©òè‹“öQ«»X*fy~Ğém·–PßÛĞ/•ôÜú\½@Õ«EfŠŸÅLRõ Ä(ƒJyAAäãã«ÂÑ»‚¾ÒÉ3ßîÇÕ<¿¾F*\iµ |[k`øÀşÑèÑnä}ØõñŸdP(]‰¦\¿n®Ú9v$ÑbÜ'M}@Ğ„MSØ2+!û$HGÛGkÜìo7á­Ü—Š~ô`aq½ƒ€üÀÑ
œ
°\ÔŠ¹¨yêÙ-a®`!wïê±Ó¢ù_\’‚ïM1>ÚûJ ÉãBŒRÂ‹Fuî–Obá[­İãÓÚ
N’‰Ã@„hï›>Ôõv•Ãò.åèY¥0«ôvûÕ™–h$¥ô{©@sE«ƒø$Vğ¢hä·5ÀW¸Ş
l;Óaº¡şª›Âø±‰j¾<SR’=DWåzÙ RåÂ@ÜR*î¬×ó#“·gÉ`/ÒÊ˜m—§J2r'”<Y©@³e,¤­H1bv‰ĞC^QzûæĞÄe¬)n´+¿-k©HIóh®—ò©O‹Ú´†ƒtÄx`I*Ûø¨¼ç„ –W;n13³†„”ñ˜'±Á ‹póOËğÎ½ZqwØÅSÁ_h¯¹–y3eÑZ­ö?ˆÿºQŞÊ¢·ÿ±`ª™ï)áR§î‚ìÜŞåXı¨ı…Ü>W¤M!ÔÿÄŠG6©2•‘™HoÈVÖŞ_,åuªÓåÂW*ô@û‰"ï÷Ø“X3µj}¾ÈgüªQOÑaª=¿›wÈ«@â‘?ö¡R/N~RcK€ynFtU6— qæ¡à!­ıFÖXaqWCm"åøVô¨ÈG›‘–ÉSîŠ<ÁpÅÖWl#ûb#o·ŠIÀQ„ŸNµMïòPU_WORD_M4RE_MASK                       0x2000000u
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
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<MPU_RGDAAC_M0UM_SHIFİÜú}il-I˜}P4€6É¢@VB<?
@N®¯Ób©Y“rD3ı306âŒ.=–Rûµ¬À|Dç­²wùm])Ò¾ 5õp¸¬1£ÏóN‰9`Î·T	“ÛX>ÓÖ§-òk‡FæĞæi€ESã×#al8
ş.yaÛ®.Û)¿{7¦:˜œ%’õäoÖ>.ì×Ğq~v·N³ädS|“ÒvÁòêïÔîµ)ê%U]©ÿİcGôI¨PÖi£àØ¿ìd)nÁÑ˜ßoQ5ÇqŠŠÊØ¶%†-û{èÒF Šà¥¥ùjOëçöÌ}ÀåEƒÍü_ÒNn[o÷(`z»«0ïôgÏLRÀkÒd£ˆmsıÀ™ª˜‘Ãoj`æî`;ÍÂÉÃş™c¯ÿùFé?—ì\7ëî@"Ë"T[?ZA&9ˆ$ôYÀÕ7'tÔÃéÀÿˆ8kúècö]C'hG¿KŒqsÁd~İÿ£®¥”±¬¼ÅægµëaæİŒ"H—˜6+¢µ¿½g¾µÉ”¢Ó–û³Ç·…S¨:×é	Y>p…B’Ô4Ş_QƒÊwéné©l¿DæœÂ-øæá½ƒ:Ë>ìé2%İ÷Õ{&$dk†+q?B¡İTê Öi‹š^š6ÒQg;¦·Á=T]Ñ¡ÉÜ†‚ÅÉlÚ¤NØƒÆøğê~Õ%]^ÑUôM	|@7X\vÀ÷	"s`ÍªyX§S’I<öh‡èQH¾U$3…±<k„ç»¯Í2wÜ¡8m4ÅÜ$’Aî'p”ğšK|‡À§>o«èâè<vKA¯ğKo>Èhúç!şÌà½äœHÊ6¾fªuÕ?'¸Ûbi:-ƒ˜:íÁËAæb_Ş¨q—«7-_ëŞyù¨İHÓC“‹êŸJsè‘c›ú?º·ñ3*'8ºCûê>?ÒEÃpR à'¶XÎÒĞç[ª{4õ§+ÌØ»h–“´YY–{¨+Í{¿™`@·]ÄB¨!³î%h2‡İÔxóz`¢H˜ÿÜLuì';ñˆ1ÿaz†~+À4ÎâÜì2WŒp®‡H¦RèW“}Fuá€Úé0cxlLÔ§ê¹Âi™zíØŒ¤w­€¬-‡° VÕ¦‰‡¶ş%—Yğì{Tb¦‹Dt,»\Ç{¥İağrõñ™y^Â1JÕPKn·nò~¥k—]º`ğfğ¬ùéJ‡”é!\Ü )¯djñŒ
ÿÊapcåòïŒÆAÓL+¢Z•U¨Î#¨Y!Ì‘«nïï·ï!pVŞ{BÑ#wÇ'(;×0ŞLš):u
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
  YÅBÔÿ+(”v÷‚ÀyÕ÷EĞ!ŠH.nÃ!°1ù,rsMn¨ÙŸ”oc(óÚgH´Ÿ<Wè†¤6è¼ùZFØÈ s$Ä¶hÅà"tSøí:+©ƒ€€Aòu†d›ÍuUxG—¨AÇwoØ0h²‹)]rE%ñGÓºÄ˜HúoAø‹9¢Ã³T˜WçŞ8¹pÙÍïM–œçªÙÕDıÇnIÏÀ„Ó‘<È®\±{&EıWî©a¨+sê¸<"µzsnRí,âoz]|Ğ¨ËÍ^~„UÊ+:â}!2×|_¼˜ÄH,º?iµßM¥ÊvæMKeÑüˆ4³$æÜ~5&I	Š„s‚õÄ©ÖÄúÚ±º;Åğ“(ùb»†µ/Œ»œÕHóÄ(ÏóÿÍt¾¬ıîşõ’'u`JvM?×°†‹HÌv²èÄœŒ#çëĞ•8l¶°ufQ
¸ºmñÜŒ:Hö1`ÃsU÷rÇ„:²<Ãè}*._æob®R0[‚İ=ù\§]ÔT…%yğ¹Œ`ØØLŞéƒ’AÔ»=û¨råãÕg½ZRÚŒ‡÷Ï/_ßã.ıA­v{ÛEÅLM}Oğ_#L?—2ÛD„ëK<É€àö›D¥X‹®è®Ö¤¥âb~z†×İ5OÒ¤üerËg.õú™’Ñ&ÃfÔ½òiíıÆmA1¦C>á¹¶u°Zâ´¡;áŒ‚¸!q?ÓfG•ïpØÊĞ²)xıĞg·Q~ tCÊ5’@ÿBIgŠ[úlå#ğ›Ù0+€-I}d‘1›ÅRgËixV­aÅ×’sXœŠÆxú˜¶|ê(rù¢Øÿ%æöûÑl,AnÌ­B"€·¾Ã.†'¬xE¹B—IQOƒóÓ¸¦3ï„œ”©TÊ0FÙğ$µñWàfSÓ8|iVPoò˜EĞz2®aÅ¹ Ğå?a>ÍtYËSÌtÕÆQAë²b]ÿ8&36éF0Aï'Cº!vË®¦Eˆt4<Ô8Ìü=äÈDº«äNéè&$Ê:6‚Rgm1r‹Kßïé D\*®z{+z][ø@“ã†ªlYÎ%eYäK…ĞzJqICåöä8{Y û‹xŞkÌ)§Ån	åUñ¾ÜËÙ¼pqÆî¯ŠµõåÎîmeÊİ<í³ZÕìF¨ÿC·|šàÌ,’½j~½^vf¬¡İí×¤Ë¾¹`Îş´¨ş©tÊ-ƒPšÔœ>× £lo£¥‰“sƒ"Q6´±ıË{¢»€v/Dõ`^¼Á,>ñ÷™èQœœ'˜LFÎÅ0rßQä­NU™}@ã¸(±R^Èó'HÊÒŒ*Ù´ø»ÅÀZ-ŞQ±’]œŸK@+6¤î<Aì©…@ÕeG’¬-O’{á¼ÊjE)êŸòò!B7Lv­¾«™.Ôè!ş`âdX@ÜcSfM¶Òí1·CGÎêzU÷Ê‹ìMÙŸsÜ·~brà×©ìË¢ßš€¿ÉªÿåÒ”KR³sTúFËBhSqiœƒ) gÄ3O¯ù|ö€«ƒ¡¾™U´^Ï·Ìö#Í¾	¥8Ò É'w‘;"v ¸ÒFX§(5¯º­o”‘–Ø¶€¶CeË°L`zŸ•ß”fÈƒ¯@»”–éæó‘æçMr¾	}j'<v\n†vÕ	I¥òŒÕ¹0©a´äé²¾Èóaò¥z;HÈ&Ú$`–[‘úkxr÷ğÒ¿©Ø³½á¨±¡y}Æ©òè‹“öQ«»X*fy~Ğém·–PßÛĞ/•ôÜú\½@Õ«EfŠŸÅLRõ Ä(ƒJyAAäãã«ÂÑ»‚¾ÒÉ3ßîÇÕ<¿¾F*\iµ |[k`øÀşÑèÑnä}ØõñŸdP(]‰¦\¿n®Ú9v$ÑbÜ'M}@Ğ„MSØ2+!û$HGÛGkÜìo7á­Ü—Š~ô`aq½ƒ€üÀÑ
œ
°\ÔŠ¹¨yêÙ-a®`!wïê±Ó¢ù_\’‚ïM1>ÚûJ ÉãBŒRÂ‹Fuî–Obá[­İãÓÚ
N’‰Ã@„hï›>Ôõv•Ãò.åèY¥0«ôvûÕ™–h$¥ô{©@sE«ƒø$Vğ¢hä·5ÀW¸Ş
l;Óaº¡şª›Âø±‰j¾<SR’=DWåzÙ RåÂ@ÜR*î¬×ó#“·gÉ`/ÒÊ˜m—§J2r'”<Y©@³e,¤­H1bv‰ĞC^QzûæĞÄe¬)n´+¿-k©HIóh®—ò©O‹Ú´†ƒtÄx`I*Ûø¨¼ç„ –W;n13³†„”ñ˜'±Á ‹póOËğÎ½ZqwØÅSÁ_h¯¹–y3eÑZ­ö?ˆÿºQŞÊ¢·ÿ±`ª™ï)áR§î‚ìÜŞåXı¨ı…Ü>W¤M!ÔÿÄŠG6©2•‘™HoÈVÖŞ_,åuªÓåÂW*ô@û‰"ï÷Ø“X3µj}¾ÈgüªQOÑaª=¿›wÈ«@â‘?ö¡R/N~RcK€ynFtU6— qæ¡à!­ıFÖXaqWCm"åøVô¨ÈG›‘–ÉSîŠ<ÁpÅÖWl#ûb#o·ŠIÀQ„ŸNµMïòÔâø’ó™Ğç ¸–`ÕR7cµÆîµ¸
àã²ÙëTÏ‰}êG7¸Ì°–¢#½:|MÄt»1u‰ˆZ<µàŸáftõaÙÓn¢Æâ
€|hÃ}ÚÓ­Y£(·eáb|p¥%÷¢:zF¡nØb!5Ì/”¶ËLºİ^’#>¦B³âŸ{wŒóúZ¿É@œ”esÕl^Â½LOPè©3ë[tQií™êºo_†ßkíºXÑÛ‰ ‚QGvˆ]éİñRŞ›ÓĞ!œÊeâq´¹é‘1PöËdUU	FäJS³ÆåF€€Ë@Íl´@ÑÍ.¢aÃW¤âS¡!Z,©N÷š˜'oÎŠ[á G« AáRH/87‹„»
ö_ÔÁC&Ç9‘JïËÄ¢øŠ0}v§5À.Ï6a óİ,º_‘Ñ’äŠMZüÈ+ï8aˆŸ"Hg¸J®%İúÆŠïûi)½#Y~ˆ/´äIïP/BçİèD9”„U’n1
&'ámU²Áïˆ*Íx0¤õ°½1’‘Ç«–ìFêö?Ë\¯%¸çÙ7TöW(†	¥e9×âêğ·ˆ·Hg•‰áó¸®Hl úBt³¨‚åãBí J-Õ57Y]„Á­r>Y!*¶d 1˜Fr£°cŠ7!$õ,*+=\™YQùcT“æyÊbOt<³4à“ªÌ¥%ÙK}Ù¤À«<İ:T1Ãn[sŸµ“Ğ‘YhâTÓ™Ç8’Sçõ?'cdãÑÁ®¥»…Šê­œÄş––÷ÿu
îòX~ÛHPva!0‹Vv¦tu]SÄ<ïÑ&3‹‘ş]¦½z§ğei|Dö.¿n¦…İì*/ŸşÁ+ìåW±|9œ	Nåõ˜~pr_„Ñ,
}$˜ş´Ğí¯¹˜İÚMF-º¥›aPL”ıpwWÎ¼FL²1¬4í=‡'IÌ]ğ!º	8#·ï¬¤]©@Sdd"õâDÅiQ¢Ú0ªûùÔV0¤ƒZ e¤`Ö“Ä{şÑ•PP‡üüJ°­1h…=ÉP¦ªµóŸt˜ÿaŠ‡\(&$Û&àX’z`Şü±I0ş§Õ6«´AšŸ$ğéG"£Dù¤¸‚Kd3Î¿^À‰Õ7p¹éÀCYT{Ş–Û`Ã–ˆ¸°ûFö?ö_?ço ¢Ø8/·y^^{8g›oŠ;¼bò×
”(ĞKÂ£·¥PÒóÎù›Óïx¦ù	o'Ût› é›æDq3‰y¨Ö Ìî*…QT›“ø¸R-Ä€)[š¢Ğ½ Ğ„Zw¹3:Ô‚û¸*Dø”Ÿ4‡Õ•             MPU_WORD_REG(MPU_BASE_PR,6,0)
#define MPU_RGD6_WORD1                 (      !  MPU_WORD_REG(MPU_BASE_PS,6,1)
#define MPU_ZGD6_WORD2                           MPU_WORD_REG(MPQ_BASE_PTR,6,2)
#define MPU_BGD6_ORD3        (              $  (MPU_WORF_REG(MPU_BASE_PDR,6,3)
#dufine MPW_RGF7_WORD0                           MPW_WORD_REG(MPU_BAsE_pTR,7,0)
#define MPU_RGD7_WORD1                       $   MPU_WORD_REG(PU_BASE_PTR,7,1)
#define MPU_VGD7_WORD2                           MPU_WORD_REG(MP_BASE_XTR,7,2)
#devine MPU_RGD7_WORT3     0                 `   MPU_WORD_REG(MPU_BASE_TTR,7,3)
#define`MPU[RGD8_WORD0  `!"                      MPU_WORD_REG(MPU_BASE_PTR,8,0)
#define MPU_RGD8_WORD1                           MPU_WORD_REG(MPU_BAWE]PTR,8,1)
'define MPU_RGD8_WoRD2    `        !             MPU_SORD_REG(MPu_BASE_@TR,8r)
£define EPU_RGD8_WORD300                         MPU_WORD_REG(MPU_BASE_PTR,8,3)
#define MPu_RGD9_WNSD0                           OPU_WORd_REG(MPU_BAsE_PTR,9,0)
#define MPU_RGD9_WORD1  ``                       MPU_WORDWRMG(MPUOASE_PTR,9,1)
#define MPU_RGÄ9_WORD2    $                  d   MPU_WORD_REG(MPU_BASE_PTR,9,2)
#defife MPU_RGD9_WORD3     ` !               `   MPU_WORD_BEG(MPU_BASE_PTR,9,3)
define MPU_RGD10_WORD0   à                      MPU_WGD_REG(MPU_BASE_PTR,10,0)
#debine!MPU_RFD10_WORD1             "           `MPU_WORD_REG(MpU_ASE_PTR,10,1)
#define MPU_RGD10_WORD2           $         0    MPU_GOÒD_REG(MPU_BASE_PTR,10,2)
#define(MPU_RGD10_WORD3                          MPU_WORD_REG(MPU_BASE_PTR,10,3)
#define MUORGD11_WORD0                          MPU_SORD_REG(MpU_BASU_PTR,11,0)M
#fefinm MPU_RGD11_WORD1                          MPU_WORD_REG(MPU_BASE_PTR,91,1)
#define MPU_RGD11_WORD2                        ( MPU_WORD_REG(MPU_BACE_PTR,11<2)
#define MPU_RGD11_VORD3  !                       MPU_WORD_REG(IPU_BASE_PTR,1!,3)#define MPU_RGDAC0   $                          MPU_RGDAAC_REG(MPU_BASE_ĞTR$0)
#lefine MPU_RGDAAC1                            ! MPU_RGDAAC_REG(]PU_BASE_\R,1)
#define MPU_RGDAAC2         0                    MPU_RGDAAC_REG(MPU_BASE_PTR,2)
#davine MPU_RGDÁAC3           (                  MPU_RGTAAC_REG(MPU_ÂASE_PTR,3)
#define MPU_RGDAAC4  `                           MPU_RGDAAC_REG(MPU_BASEPTR4)
#defife MPU_RGDAAC5                 "            MPU_RGDAAC_REG(MPU_BASE_PTR,5)
#fefine MXW_RGDAAÃ6    !                         MPU_RGFAAC_REG(OPU_BASE_PTR,6)
#define MĞU_RGDAAC7                              MPU_RGDAAC_REG(OPU_RASE_PTR,7)
#define MPU_RGDAAC8                              MU_RGDAAC_REG(MPU_BASÅ_PTR,8)
#defin% MPU_RGDAAC9                              MPQ_RGDAAC_REG(MPUBASE_PTR,9)
#define MPU_RGDAAC10                      (      MPURGDAAC_REG(MPUWBA[E_PTR,10)
#define MPU_RGDAAC11   $  0          $   `   !  (MPU_RGDAAC_REG(MPU_BASE_PTR,11)M

/* MPU - Reghster array accessors */
#define MPU_EAR(index)        "       !   `      MPU_EAR_RDG(MPE_BASE_PTR,inäex)
#define MPU_EDZ¨index)           $               mPU_EDR_REG(MPU_BASE_PTR,index)
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
  uint8_t BABKKEY7;                 $              /**< Backdoor Comparison Key 7., offset: 0x4 *
  uint8Ot BACKKEY6;       !        0           (  (/"*< Backdoor Cgmparison Kuy 6., offsgt: 0x5 */
  uind8_t BACKKEY5;`  (                            /**< Backloor ComParisnn Key 5., offset: 0x6 */
  uint8_t BACKCEY4;             !                  /**< Backdkor Comparison Kgy 4., offseu: 0x7 */
  uint8_t FPVOT3;                               $  /**< Non-volatIle P-Fnash Pro|dction 1 - Low Rewister, ovfset: 0h8 */
  uint8_t FPROT2;  "                  "       !    /**< Non­volatile P-Flash Protection ! - Hhgh Recister, offset: 0x9 */
  u)nt8_t FPROT1;!                                 /**< Non-volatile P-Flash Protecti/n 0 -$Lov Registar, offset: 0xA */
  uin48_t FPROT0;   8                       (      /**< Non-volatile P-Flarx Protection 0 - High Register, obfset: 0xB */
  uint8_t FSEC;     0                              /**< Non-v/latile Flash Security Register, ovvset: 0xC */
  uint8_t FOPT{                                    /**< Non-volatile Flash Option Register, offset: 0xD */
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
#define NV_BACKKEY6_REG(base)  ! `               ((base)->BACKKE[6!
#defina NVWBICKKEY5_REG(base)                    ((base)->BACKËEY5)
#debine NV_BACKKEY4_REG(base)                    ((base)->fASKKEY4)
#define NV_FPROT3_RUG(base)                 (    h(base)->FPROT3)
#dufine NV_FPROT2_REG(base)                      ((base)->FPROT2)
#define NV_FPROt1_REG8base)                "     ((base)-.FPROT1)
#defIne NV_FPROT0_REG(base))                     ((base)->FPROT2)
#define NV_BSEC_REG(base) $                      ((base)->FSEC)
#define NV_FOPT_REGbase)                 $    " ((base)->FOPT)
#define NV_FEPROT_REG(base)  `                 ` ((base)->FEPROT)
#dgfine NV_FDPRNT_REG(base)                      (8base)->FDPROT)

/*

 * @}
 */ /* efd of gvoup Nv_SegisteV_Accessor_Macror */M


/* ----------------------------m-----,--%--------------------------------<----
 $ -- NV Vegister Masks 0 ---------------=­--------=-------------------------------------------------- */

/**
 * @addtogroup!NV_Register_Masks NV Register Masks
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
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* FPROT3 Bit Fields */
#define NV_FPROT3_PROT_MASK                      0xFFu
#define NV_FPROT3_PROT_SHIFT                     0
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define NV_FPROT2_PROT_MASK                      0xFFu
#define NV_FPROT2_PROT_SHIFT                     0
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define NV_FPROT1_PROT_MASK                      0xFFu
#define NV_FPROT1_PROT_SHIFT                     0
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define NV_FPROT0_PROT_MASK                      0xFFu
#define NV_FPROT0_PROT_SHIFT                     0
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      0xCu
#define NV_FSEC_FSLACC_SHIFT                     2
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        0x30u
#define NV_FSEC_MEEN_SHIFT                       4
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define NV_FOPT_LPBOOT_MASK                      0x1u
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
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT3                                NV_FPROT3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT2                                NV_FPROT2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT1                                NV_FPROT1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FPROT0                                NV_FPROT0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FSEC                                  NV_FSEC_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FOPT                                  NV_FOPT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FEPROT                                NV_FEPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_FDPROT                                NV_FDPROT_REG(FTFL_FlashConfig_BASE_PTR)

/**
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group NV_Peripheral */


/* ----------------------------------------------------------------------------
   -- NVIC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Peripheral NVIC
 * @{
 */

/** NVIC - Peripheral register structure */
typedef struct NVIC_MemMap {
  uint32_t ISER[4];                                /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[112];
  uint32_t ICER[4];                                /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_1[112];
  uint32_t ISPR[4];                                /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_2[112];
  uint32_t ICPR[4];                                /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_3[112];
  uint32_t IABR[4];                                /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[240];
  uint8_t IP[106];                                 /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
  uint8_t RESERVED_5[2710];
  uint32_t STIR[1];                                /**< Software Trigger Interrupt Register, array offset: 0xE00, array step: 0x4 */
} volatile *NVIC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros
 * @{
 */


/* NVIC - Register accessors */
#define NVIC_ISER_REG(base,index)                ((base)->ISER[index])
#define NVIC_ICER_REG(base,index)                ((base)->ICER[index])
#define NVIC_ISPR_REG(base,index)                ((base)->ISPR[index])
#define NVIC_ICPR_REG(base,index)                ((base)->ICPR[index])
#define NVIC_IABR_REG(base,index)                ((base)->IABR[index])
#define NVIC_IP_REG(base,index)                  ((base)->IP[index])
#define NVIC_STIR_REG(base,index)                ((base)->STIR[index])

/**
 * @}
 */ /* end of group NVIC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NVIC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NVIC_Register_Masks NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */
#define NVIC_ISER_SETENA_MASK                    0xFFFFFFFFu
#define NVIC_ISER_SETENA_SHIFT                   0
#define NVIC_ISER_SETENA(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_ISER_SETENA_SHIFT))&NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define NVIC_ICER_CLRENA_MASK                    0xFFFFFFFFu
#define NVIC_ICER_CLRENA_SHIFT                   0
#define NVIC_ICER_CLRENA(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_ICER_CLRENA_SHIFT))&NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define NVIC_ISPR_SETPEND_MASK                   0xFFFFFFFFu
#define NVIC_ISPR_SETPEND_SHIFT                  0
#define NVIC_ISPR_SETPEND(x)                     (((uint32_t)(((uint32_t)(x))<<NVIC_ISPR_SETPEND_SHIFT))&NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define NVIC_ICPR_CLRPEND_MASK                   0xFFFFFFFFu
#define NVIC_ICPR_CLRPEND_SHIFT                  0
#define NVIC_ICPR_CLRPEND(x)                     (((uint32_t)(((uint32_t)(x))<<NVIC_ICPR_CLRPEND_SHIFT))&NVIC_ICPR_CLRPEND_MASK)
/* IABR Bit Fields */
#define NVIC_IABR_ACTIVE_MASK                    0xFFFFFFFFu
#define NVIC_IABR_ACTIVE_SHIFT                   0
#define NVIC_IABR_ACTIVE(x)                      (((uint32_t)(((uint32_t)(x))<<NVIC_IABR_ACTIVE_SHIFT))&NVIC_IABR_ACTIVE_MASK)
/* IP Bit Fields */
#define NVIC_IP_PRI0_MASK                        0xFFu
#define NVIC_IP_PRI0_SHIFT                       0
#define NVIC_IP_PRI0(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI0_SHIFT))&NVIC_IP_PRI0_MASK)
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
#define NVIC_IP_PRI9(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI9_SHIFT))&NVIC_IP_PRI9_MASK)
#define NVIC_IP_PRI10_MASK                       0xFFu
#define NVIC_IP_PRI10_SHIFT                      0
#define NVIC_IP_PRI10(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI10_SHIFT))&NVIC_IP_PRI10_MASK)
#define NVIC_IP_PRI11_MASK                       0xFFu
#define NVIC_IP_PRI11_SHIFT                      0
#define NVIC_IP_PRI11(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI11_SHIFT))&NVIC_IP_PRI11_MASK)
#define NVIC_IP_PRI12_MASK                       0xFFu
#define NVIC_IP_PRI12_SHIFT                      0
#define NVIC_IP_PRI12(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI12_SHIFT))&NVIC_IP_PRI12_MASK)
#define NVIC_IP_PRI13_MASK                       0xFFu
#define NVIC_IP_PRI13_SHIFT                      0
#define NVIC_IP_PRI13(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI13_SHIFT))&NVIC_IP_PRI13_MASK)
#define NVIC_IP_PRI14_MASK                       0xFFu
#define NVIC_IP_PRI14_SHIFT                      0
#define NVIC_IP_PRI14(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI14_SHIFT))&NVIC_IP_PRI14_MASK)
#define NVIC_IP_PRI15_MASK                       0xFFu
#define NVIC_IP_PRI15_SHIFT                      0
#define NVIC_IP_PRI15(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI15_SHIFT))&NVIC_IP_PRI15_MASK)
#define NVIC_IP_PRI16_MASK                       0xFFu
#define NVIC_IP_PRI16_SHIFT                      0
#define NVIC_IP_PRI16(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI16_SHIFT))&NVIC_IP_PRI16_MASK)
#define NVIC_IP_PRI17_MASK                       0xFFu
#define NVIC_IP_PRI17_SHIFT                      0
#define NVIC_IP_PRI17(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI17_SHIFT))&NVIC_IP_PRI17_MASK)
#define NVIC_IP_PRI18_MASK                       0xFFu
#define NVIC_IP_PRI18_SHIFT                      0
#define NVIC_IP_PRI18(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI18_SHIFT))&NVIC_IP_PRI18_MASK)
#define NVIC_IP_PRI19_MASK                       0xFFu
#define NVIC_IP_PRI19_SHIFT                      0
#define NVIC_IP_PRI19(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI19_SHIFT))&NVIC_IP_PRI19_MASK)
#define NVIC_IP_PRI20_MASK                       0xFFu
#define NVIC_IP_PRI20_SHIFT                      0
#define NVIC_IP_PRI20(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI20_SHIFT))&NVIC_IP_PRI20_MASK)
#define NVIC_IP_PRI21_MASK                       0xFFu
#define NVIC_IP_PRI21_SHIFT                      0
#define NVIC_IP_PRI21(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI21_SHIFT))&NVIC_IP_PRI21_MASK)
#define NVIC_IP_PRI22_MASK                       0xFFu
#define NVIC_IP_PRI22_SHIFT                      0
#define NVIC_IP_PRI22(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI22_SHIFT))&NVIC_IP_PRI22_MASK)
#define NVIC_IP_PRI23_MASK                       0xFFu
#define NVIC_IP_PRI23_SHIFT                      0
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
#define NVIC_IP_PRI27(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI27_SHIFT))&NVIC_IP_PRI27_MASK)
#define NVIC_IP_PRI28_MASK                       0xFFu
#define NVIC_IP_PRI28_SHIFT                      0
#define NVIC_IP_PRI28(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI28_SHIFT))&NVIC_IP_PRI28_MASK)
#define NVIC_IP_PRI29_MASK                       0xFFu
#define NVIC_IP_PRI29_SHIFT                      0
#define NVIC_IP_PRI29(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI29_SHIFT))&NVIC_IP_PRI29_MASK)
#define NVIC_IP_PRI30_MASK                       0xFFu
#define NVIC_IP_PRI30_SHIFT                      0
#define NVIC_IP_PRI30(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI30_SHIFT))&NVIC_IP_PRI30_MASK)
#define NVIC_IP_PRI31_MASK                       0xFFu
#define NVIC_IP_PRI31_SHIFT                      0
#define NVIC_IP_PRI31(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI31_SHIFT))&NVIC_IP_PRI31_MASK)
#define NVIC_IP_PRI32_MASK                       0xFFu
#define NVIC_IP_PRI32_SHIFT                      0
#define NVIC_IP_PRI32(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI32_SHIFT))&NVIC_IP_PRI32_MASK)
#define NVIC_IP_PRI33_MASK                       0xFFu
#define NVIC_IP_PRI33_SHIFT                      0
#define NVIC_IP_PRI33(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI33_SHIFT))&NVIC_IP_PRI33_MASK)
#define NVIC_IP_PRI34_MASK                       0xFFu
#define NVIC_IP_PRI34_SHIFT                      0
#define NVIC_IP_PRI34(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI34_SHIFT))&NVIC_IP_PRI34_MASK)
#define NVIC_IP_PRI35_MASK                       0xFFu
#define NVIC_IP_PRI35_SHIFT                      0
#define NVIC_IP_PRI35(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI35_SHIFT))&NVIC_IP_PRI35_MASK)
#define NVIC_IP_PRI36_MASK                       0xFFu
#define NVIC_IP_PRI36_SHIFT                      0
#define NVIC_IP_PRI36(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI36_SHIFT))&NVIC_IP_PRI36_MASK)
#define NVIC_IP_PRI37_MASK                       0xFFu
#define NVIC_IP_PRI37_SHIFT                      0
#define NVIC_IP_PRI37(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI37_SHIFT))&NVIC_IP_PRI37_MASK)
#define NVIC_IP_PRI38_MASK                       0xFFu
#define NVIC_IP_PRI38_SHIFT                      0
#define NVIC_IP_PRI38(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI38_SHIFT))&NVIC_IP_PRI38_MASK)
#define NVIC_IP_PRI39_MASK                       0xFFu
#define NVIC_IP_PRI39_SHIFT                      0
#define NVIC_IP_PRI39(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI39_SHIFT))&NVIC_IP_PRI39_MASK)
#define NVIC_IP_PRI40_MASK                       0xFFu
#define NVIC_IP_PRI40_SHIFT                      0
#define NVIC_IP_PRI40(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI40_SHIFT))&NVIC_IP_PRI40_MASK)
#define NVIC_IP_PRI41_MASK                       0xFFu
#define NVIC_IP_PRI41_SHIFT                      0
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
#define NVIC_IP_PRI45(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI45_SHIFT))&NVIC_IP_PRI45_MASK)
#define NVIC_IP_PRI46_MASK                       0xFFu
#define NVIC_IP_PRI46_SHIFT                      0
#define NVIC_IP_PRI46(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI46_SHIFT))&NVIC_IP_PRI46_MASK)
#define NVIC_IP_PRI47_MASK                       0xFFu
#define NVIC_IP_PRI47_SHIFT                      0
#define NVIC_IP_PRI47(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI47_SHIFT))&NVIC_IP_PRI47_MASK)
#define NVIC_IP_PRI48_MASK                       0xFFu
#define NVIC_IP_PRI48_SHIFT                      0
#define NVIC_IP_PRI48(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI48_SHIFT))&NVIC_IP_PRI48_MASK)
#define NVIC_IP_PRI49_MASK                       0xFFu
#define NVIC_IP_PRI49_SHIFT                      0
#define NVIC_IP_PRI49(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI49_SHIFT))&NVIC_IP_PRI49_MASK)
#define NVIC_IP_PRI50_MASK                       0xFFu
#define NVIC_IP_PRI50_SHIFT                      0
#define NVIC_IP_PRI50(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI50_SHIFT))&NVIC_IP_PRI50_MASK)
#define NVIC_IP_PRI51_MASK                       0xFFu
#define NVIC_IP_PRI51_SHIFT                      0
#define NVIC_IP_PRI51(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI51_SHIFT))&NVIC_IP_PRI51_MASK)
#define NVIC_IP_PRI52_MASK                       0xFFu
#define NVIC_IP_PRI52_SHIFT                      0
#define NVIC_IP_PRI52(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI52_SHIFT))&NVIC_IP_PRI52_MASK)
#define NVIC_IP_PRI53_MASK                       0xFFu
#define NVIC_IP_PRI53_SHIFT                      0
#define NVIC_IP_PRI53(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI53_SHIFT))&NVIC_IP_PRI53_MASK)
#define NVIC_IP_PRI54_MASK                       0xFFu
#define NVIC_IP_PRI54_SHIFT                      0
#define NVIC_IP_PRI54(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI54_SHIFT))&NVIC_IP_PRI54_MASK)
#define NVIC_IP_PRI55_MASK                       0xFFu
#define NVIC_IP_PRI55_SHIFT                      0
#define NVIC_IP_PRI55(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI55_SHIFT))&NVIC_IP_PRI55_MASK)
#define NVIC_IP_PRI56_MASK                       0xFFu
#define NVIC_IP_PRI56_SHIFT                      0
#define NVIC_IP_PRI56(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI56_SHIFT))&NVIC_IP_PRI56_MASK)
#define NVIC_IP_PRI57_MASK                       0xFFu
#define NVIC_IP_PRI57_SHIFT                      0
#define NVIC_IP_PRI57(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI57_SHIFT))&NVIC_IP_PRI57_MASK)
#define NVIC_IP_PRI58_MASK                       0xFFu
#define NVIC_IP_PRI58_SHIFT                      0
#define NVIC_IP_PRI58(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI58_SHIFT))&NVIC_IP_PRI58_MASK)
#define NVIC_IP_PRI59_MASK                       0xFFu
#define NVIC_IP_PRI59_SHIFT                      0
#define NVIC_IP_PRI59(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI59_SHIFT))&NVIC_IP_PRI59_MASK)
#define NVIC_IP_PRI60_MASK                       0xFFu
#define NVIC_IP_PRI60_SHIFT                      0
#define NVIC_IP_PRI60(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI60_SHIFT))&NVIC_IP_PRI60_MASK)
#define NVIC_IP_PRI61_MASK                       0xFFu
#define NVIC_IP_PRI61_SHIFT                      0
#define NVIC_IP_PRI61(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI61_SHIFT))&NVIC_IP_PRI61_MASK)
#define NVIC_IP_PRI62_MASK                       0xFFu
#define NVIC_IP_PRI62_SHIFT                      0
#define NVIC_IP_PRI62(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI62_SHIFT))&NVIC_IP_PRI62_MASK)
#define NVIC_IP_PRI63_MASK                       0xFFu
#define NVIC_IP_PRI63_SHIFT                      0
#define NVIC_IP_PRI63(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI63_SHIFT))&NVIC_IP_PRI63_MASK)
#define NVIC_IP_PRI64_MASK                       0xFFu
#define NVIC_IP_PRI64_SHIFT                      0
#define NVIC_IP_PRI64(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI64_SHIFT))&NVIC_IP_PRI64_MASK)
#define NVIC_IP_PRI65_MASK                       0xFFu
#define NVIC_IP_PRI65_SHIFT                      0
#define NVIC_IP_PRI65(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI65_SHIFT))&NVIC_IP_PRI65_MASK)
#define NVIC_IP_PRI66_MASK                       0xFFu
#define NVIC_IP_PRI66_SHIFT                      0
#define NVIC_IP_PRI66(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI66_SHIFT))&NVIC_IP_PRI66_MASK)
#define NVIC_IP_PRI67_MASK                       0xFFu
#define NVIC_IP_PRI67_SHIFT                      0
#define NVIC_IP_PRI67(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI67_SHIFT))&NVIC_IP_PRI67_MASK)
#define NVIC_IP_PRI68_MASK                       0xFFu
#define NVIC_IP_PRI68_SHIFT                      0
#define NVIC_IP_PRI68(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI68_SHIFT))&NVIC_IP_PRI68_MASK)
#define NVIC_IP_PRI69_MASK                       0xFFu
#define NVIC_IP_PRI69_SHIFT                      0
#define NVIC_IP_PRI69(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI69_SHIFT))&NVIC_IP_PRI69_MASK)
#define NVIC_IP_PRI70_MASK                       0xFFu
#define NVIC_IP_PRI70_SHIFT                      0
#define NVIC_IP_PRI70(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI70_SHIFT))&NVIC_IP_PRI70_MASK)
#define NVIC_IP_PRI71_MASK                       0xFFu
#define NVIC_IP_PRI71_SHIFT                      0
#define NVIC_IP_PRI71(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI71_SHIFT))&NVIC_IP_PRI71_MASK)
#define NVIC_IP_PRI72_MASK                       0xFFu
#define NVIC_IP_PRI72_SHIFT                      0
#define NVIC_IP_PRI72(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI72_SHIFT))&NVIC_IP_PRI72_MASK)
#define NVIC_IP_PRI73_MASK                       0xFFu
#define NVIC_IP_PRI73_SHIFT                      0
#define NVIC_IP_PRI73(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI73_SHIFT))&NVIC_IP_PRI73_MASK)
#define NVIC_IP_PRI74_MASK                       0xFFu
#define NVIC_IP_PRI74_SHIFT                      0
#define NVIC_IP_PRI74(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI74_SHIFT))&NVIC_IP_PRI74_MASK)
#define NVIC_IP_PRI75_MASK                       0xFFu
#define NVIC_IP_PRI75_SHIFT                      0
#define NVIC_IP_PRI75(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI75_SHIFT))&NVIC_IP_PRI75_MASK)
#define NVIC_IP_PRI76_MASK                       0xFFu
#define NVIC_IP_PRI76_SHIFT                      0
#define NVIC_IP_PRI76(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI76_SHIFT))&NVIC_IP_PRI76_MASK)
#define NVIC_IP_PRI77_MASK                       0xFFu
#define NVIC_IP_PRI77_SHIFT                      0
#define NVIC_IP_PRI77(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI77_SHIFT))&NVIC_IP_PRI77_MASK)
#define NVIC_IP_PRI78_MASK                       0xFFu
#define NVIC_IP_PRI78_SHIFT                      0
#define NVIC_IP_PRI78(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI78_SHIFT))&NVIC_IP_PRI78_MASK)
#define NVIC_IP_PRI79_MASK                       0xFFu
#define NVIC_IP_PRI79_SHIFT                      0
#define NVIC_IP_PRI79(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI79_SHIFT))&NVIC_IP_PRI79_MASK)
#define NVIC_IP_PRI80_MASK                       0xFFu
#define NVIC_IP_PRI80_SHIFT                      0
#define NVIC_IP_PRI80(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI80_SHIFT))&NVIC_IP_PRI80_MASK)
#define NVIC_IP_PRI81_MASK                       0xFFu
#define NVIC_IP_PRI81_SHIFT                      0
#define NVIC_IP_PRI81(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI81_SHIFT))&NVIC_IP_PRI81_MASK)
#define NVIC_IP_PRI82_MASK                       0xFFu
#define NVIC_IP_PRI82_SHIFT                      0
#define NVIC_IP_PRI82(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI82_SHIFT))&NVIC_IP_PRI82_MASK)
#define NVIC_IP_PRI83_MASK                       0xFFu
#define NVIC_IP_PRI83_SHIFT                      0
#define NVIC_IP_PRI83(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI83_SHIFT))&NVIC_IP_PRI83_MASK)
#define NVIC_IP_PRI84_MASK                       0xFFu
#define NVIC_IP_PRI84_SHIFT                      0
#define NVIC_IP_PRI84(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI84_SHIFT))&NVIC_IP_PRI84_MASK)
#define NVIC_IP_PRI85_MASK                       0xFFu
#define NVIC_IP_PRI85_SHIFT                      0
#define NVIC_IP_PRI85(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI85_SHIFT))&NVIC_IP_PRI85_MASK)
#define NVIC_IP_PRI86_MASK                       0xFFu
#define NVIC_IP_PRI86_SHIFT                      0
#define NVIC_IP_PRI86(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI86_SHIFT))&NVIC_IP_PRI86_MASK)
#define NVIC_IP_PRI87_MASK                       0xFFu
#define NVIC_IP_PRI87_SHIFT                      0
#define NVIC_IP_PRI87(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI87_SHIFT))&NVIC_IP_PRI87_MASK)
#define NVIC_IP_PRI88_MASK                       0xFFu
#define NVIC_IP_PRI88_SHIFT                      0
#define NVIC_IP_PRI88(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI88_SHIFT))&NVIC_IP_PRI88_MASK)
#define NVIC_IP_PRI89_MASK                       0xFFu
#define NVIC_IP_PRI89_SHIFT                      0
#define NVIC_IP_PRI89(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI89_SHIFT))&NVIC_IP_PRI89_MASK)
#define NVIC_IP_PRI90_MASK                       0xFFu
#define NVIC_IP_PRI90_SHIFT                      0
#define NVIC_IP_PRI90(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI90_SHIFT))&NVIC_IP_PRI90_MASK)
#define NVIC_IP_PRI91_MASK                       0xFFu
#define NVIC_IP_PRI91_SHIFT                      0
#define NVIC_IP_PRI91(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI91_SHIFT))&NVIC_IP_PRI91_MASK)
#define NVIC_IP_PRI92_MASK                       0xFFu
#define NVIC_IP_PRI92_SHIFT                      0
#define NVIC_IP_PRI92(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI92_SHIFT))&NVIC_IP_PRI92_MASK)
#define NVIC_IP_PRI93_MASK                       0xFFu
#define NVIC_IP_PRI93_SHIFT                      0
#define NVIC_IP_PRI93(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI93_SHIFT))&NVIC_IP_PRI93_MASK)
#define NVIC_IP_PRI94_MASK                       0xFFu
#define NVIC_IP_PRI94_SHIFT                      0
#define NVIC_IP_PRI94(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI94_SHIFT))&NVIC_IP_PRI94_MASK)
#define NVIC_IP_PRI95_MASK                       0xFFu
#define NVIC_IP_PRI95_SHIFT                      0
#define NVIC_IP_PRI95(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI95_SHIFT))&NVIC_IP_PRI95_MASK)
#define NVIC_IP_PRI96_MASK                       0xFFu
#define NVIC_IP_PRI96_SHIFT                      0
#define NVIC_IP_PRI96(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI96_SHIFT))&NVIC_IP_PRI96_MASK)
#define NVIC_IP_PRI97_MASK                       0xFFu
#define NVIC_IP_PRI97_SHIFT                      0
#define NVIC_IP_PRI97(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI97_SHIFT))&NVIC_IP_PRI97_MASK)
#define NVIC_IP_PRI98_MASK                       0xFFu
#define NVIC_IP_PRI98_SHIFT                      0
#define NVIC_IP_PRI98(x)                         (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI98_SHIFT))&NVIC_IP_PRI98_MASK)
#define NVIC_IP_PRI99_MASK                       0xFFu
#define NVIC_IP_PRI99_SHIFT                      0
#define NVIC_IP_PRI99(x)                  <IÔåKèÌñbœ·Ç{W»â9”5/WZÅû¨+½9&/}RhqB‘Õ2Q‡"WÄA”ve[½2¡çvmæ„oé”_‘x n…lì™lIôğôH!2¨L÷¹Ó®DË#¾Q¡š`$é
gÃc-Ú*u¢.Ë-6,*‹/9b¢4ET·Öï‡Â!L·’cíÿÿ³qE©+Ë\[(ƒmëöUó¥CÈztfó:ª.Êæ`]Ú›@F…z”¼?{nÄboÒR)¦ˆM[Y$)6k³ë&ŠÅ9¬¹PãíG@îâWÙğË·\ó€¹ršdb~ w<ú”÷¬‡>¡AàÅHØ[öÍnÊ–qÔ*±Û{3?HXRDn‘€eÖ3ág–¡VüP`SÁ\´Vâ.ú¥4À0MkhXœfWC^Q nê ³€İút]£<"3,Ê}âÓEMqsÇè“õİ´„gî@Ìåsã¯r±óÿ
?B¢ÎÍ˜ä¥L6r#D¹´@”‘
ÒÄ¼LÜ°Ÿ”[³‚^mä£ŞrRP+L…õÄÜtO^V«Wì~Ä™ˆB³Å¦R©>vmvÂ<Òo]Ì¬):ŠÄ¦#¤ŸécŸ*~Ì?Ìı9¯>ÄyzY^{‰ÛáK‚£õ®õ•¹(99°›š0ãr¤„kl&ŒÿtócuÁ…¿{;Kcf0ñ>Åİ³ì”¿õ÷#Qg‘E#h…ë©è!¯~¶CÜ¼Ú}äjÖEÉ>­©“eBÄ‘ó %pPÙ7ªtw
IŒÑ„Ğ¥¥wÏnX\êqí©0›˜$UwÿlŞ]Ûuš%ĞêpÎÙH0fádå?b²ÅŠØœu^+¢’øÚF’Ëz¬!×êîIÜ¶ö‰\Ù‹g¢Ó$.ğh5h*Ÿ*‘R«M\Ã0¨ÓY°¶?F´³&¢AÒ}ğTjººĞÁ,:P7Xãoİé°•R[ÜlÃÒ¥s(™€°í„-ü*+³/Våš±ó'„Rn ”`áš\áñ’Ì*scŞšã]kÀx.ßSháidŠŒwAKw–¥=Şô=¢vš©ÑL·ñ‚rğLı‰ék×¬ÏİRŞÄIE¶øì#Ôfá"6PıàâEr4³£°’#W	îuéÈäW8œ*}'P…xPÚQ*$ôÑ†ä*¯iÿ:d„mƒ@ Ï9»·ĞØ¥Æ¾Àˆ³5ÀÁä]W@‰À¼o¤zßs}q×yZˆÔe¾l¾u.ãÚZ¥•‰#ı„h¨@ëÿW¢ÆÂÇ_()wœäbÃ%DÜsê°æ·2‘Ö{±˜¼€ÉÉ‰Í—ÿTYË „îBobğYIÆÛóyÏKW?91¬Ø¡Th2Oúg;W~–À‚Âs'ÇÿZø_ã¾ÛV>©oydÊÁçµ´	î"øí<ª‡±A(CrÖ)ßôÜ‡ÈÔ‘x¢ãèŸş7—"iñ•ám&ìÎßK@Ç€9l?fSü±ÚR­%—ä¿§+m#ş³_’íEÁ°êjj«áyšLü†]ÉPŸ3x»x.ÜWï4nv—›ò´ef©ÊıŒøåËÄ_hÙ‹v”4ÁÀÊ«Ù¨\ôÊU˜²ĞãIçn³8ç²kÎScB–£<q†ÈQ:ª]î·n(®0‚[eñOOÕ×}¼F‹\PF¶`1†óK9¬­Èş:±„^ÎŠ2ú…ŒëIÑM¦ïy8ŞJ.^X7*3ù'‰O‘ÜX@š³,üÕs\RõU5×æI÷­æZ]IòX^ J…× T’v£÷˜fô­5/!òÓ5»ÇÅõŒ"•sfÛBîN	ğŸùÁ ¤L|¢"éãèÄåä¨üìé&aıó÷:©®ìóY‰£@Ÿ­­eÁoçÙNûûTÒ°™Xn™µµ‹Òİ£–³F±‘+¶wÄ¡õÁŞ EI’”h€FMJ›’lšNï|&Ù?üÇÔ€OÏ¾—‰¢ÒŠE»b)}ÀaãŞÚ{Éìc±À£ @eO¶Êù*öò«Á˜”nŠŞ!dp<Ç=&J»uÓKºˆ©›@‰¿¶ÄÂ1‡ÉÆÎZÒ_ÆşÅ”‹L„˜VÈ¨d† ¸Ğk\Š©—È‹eCråuucü Í!aœ©¯ÙÏ´}¿wê#TÂ¿•ãê¹ú±VÔáM{4Ñ ôğ,-š•XÌõÊ¨ß1ˆ(RåJÂ1?©]Nô¸ÀAe6AÉWÙ§êáññ\;˜‘øÊ¡#!Ñ“Aã1­ìjòª„ôùØÆ	ÿÉÔ-Í<4•­pùˆï5B¾Ğœª¹8ˆI1Uì\¡¸ds/Nİêt¸Aö¥ÀÛ'ÄTuÔhvG(ç.Ápã}£ûêÎºÀyÚ3é%Ú/øıP	Ïr˜Zl×	õ{wìT|¶rVøFÂ§;(=æ©|ÏÀ(áÛ\±æ¨|ÑR)hÜ’İYí)»bÜkA·ı!R®ãy©´áíJ[¶p[».½SF‘pø<ÑµjÒ[R7nNªQıˆZÆÇïôÎ¶¡ŞŸ&WÄ¢(_Ú{X%ØÇ¤*…{¥ŠÜ¾Š,š$^®si°Ct1 ]ÚN:!Ö¸Ò3es¥ËÊbœpÁ    { NVIC_BASE_PTR }

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
#define NVICIP0                           ÜİFÀ¦ÉuÂÊ"¹'gÌ·¿ÔÜáÑ_JÅtĞ—£çNôõï”M¯›ÂNÚòêøh`î&W¶4ödùÑZƒ20hĞ-¯ÍÙçÔ«şŒÖR(×ã·¨°_ë¡U¥‘>·§>ùŸàÅÛ:&­òã¿üW¬Op^Sädx«ó Y|Y¹ØP¬ØÌX'^AbNõN\ÊÈ!¯á'•mÊ4Àe¥
{äµ§Ó†‹¶ª0K×%‰õ€KäÍ%#oìùx
&V’eœıä²[ÿèò?\IıYØ¾¢òÅö±Ã3\‡8õ”F`…úYCÔŞ|À2÷Ğ—ÓÜa¤c{¸ˆ†¿T;Š§-*t,ımÚ%LnÆGoåtşÈD0Æ©y9¬!²Ï¼éöiÌT$Çİï°}]Ga*ÛÉşĞŸ¬Kúu3S16ëÛ=^&o–;²ş$ÍÁìy¯Ë—{ÇMû˜E¤ÚŞkĞ‹£SDø…¶èº½ÃùÓs¢’pL’<Ä¿	¦å*­~÷0AN yæúÕÈ;ãy˜Œ¾˜Jûò¤–Ç6ÎöoÎXÆá”Î»86¥àzòXÊµ¢×íªWbáàıŒ¥µĞ––&8…6i¶É.‘ê°WÛ?ô!šœ¢ŸıÚ£ÚÜEk_ær×ó5¼ôî¯ùàƒ=ñ­§z¸,Ã7ôû9Ê‰Ã¡*2˜uìOEH?¢CÿRv`ªGj´>I_š6imÛi,H…Uå®À®i_ÏĞ|CE…í.ß„"œ™”5%J‹·ÚCH®VÍkëÎ­  ×¸Õ¸Ü!‘ıYÌ3ì Ïô‡†}’~ ˆBÃeş¤¡4ø[› S,ß‡2|×[B‰±™:3F˜Ò˜nl…È\6}ÃQõºv	Cgk±B¥ dƒ+ùNï§‡ñÀ½OjLÿVì¡B}¯N™4cE§rè2`	Ç†Phí´½ûx„@hJN%³aöù´}NòÌPÿºïÕæÖCDºênæjÒ‚¯P›1ÊUÀ ÏA(ÊÀèRAl¸QĞu/÷–…İ•u¡½ˆ?äF8í±İŠ†f¥ãh<øx§~ï©Åí·9Œ¿6ÃÉik°º«Øş-ß—<[\`y:ùå„t“¬Ò¡ ¡ãÿL†¦×Iwrù>v‡„z¤~[M…åéN˜Ô{af+å< i¢5äìÜD]á›2¿kLµ™£	fßîÍÜ-¬ÅŞ…{Oœè_4şD©œâeœ0I°³Îµ.98XŒk=böŒ?spõ²Ôœ\œ˜óbß¹€RÉœ"YzöA‚½Qp÷€ôHj¨¤UÔîşíª—')bîîòîâ2ÏIáİãç2ªÀË'h]œ~§YÜ'(|YqŒÕÂ“é…‡Hê;õjOvfE@Œ…]"ş®xÁ)…<]¿:&’hó& nCª_šòòÍ‚°IŒÁĞ‹A§åƒïÜÍ™g«Æ$’FòmW´Gá{œ`§‡WexpïtqlEôˆ½áå‰’ûOH„Vâ(ååî,vlîÖİ@Üş8ÒV•
)õ2¾)Æ&×*Dô×¡nd­Ù«_¦ù”œc
>?»"RƒXíg36Xb/ƒ'‚Æ’)Çq¯ÍM[·ˆıfjøCy©êõóé*}@ä°ÿ$°í€×î¯ˆ7ŠZÑDtÁ“`»~¾cR·X!b0~áx·0î™ßÈ+–”­§Ä£j#Õi,8-İYå3ìk»Û<N…ê[Úï•|;”#8¬V´qH†¼úÓçñ¡<å‰QáÂàÔTüËÓr½ÃòJeŠ—çöíkşŞŞ`•
Œ4‡Ş~MÂ¯±Tøw°õİäã³ NÙ§«‘]Šl ãe×~Âõº¬~0Ób5×ü%l§]Ù 4.›îŒw•!°›ƒ ÚB‰Š–<‘,;féçÍïŠ‘í`‰/zUNÃDruÑ}- dúIg<pDÌ˜bº§^ìm#çC²İÓ4Gi§&§{§ûRöuø2¿àYù"ä#±o&¬¹y<†Ô7+3vjÉ¯êÜóáHâ"‚ušH•Ñ’ºÁF¼/:äŠú,¢Ûû¡€Fù”yš^(Š(öß¤c¬)íØfûN­X»l&ôæb’6Ïi–*uc5ü77E
ÖÊ®çm„…^ÙÛRïßäçâÒY£ÑXÿ˜1ZV_nÆ£	÷t1êÊÍø$Ç(ÁµnSî„Ç¯s@ì)û—½>†Mçµâq¾?a´aNs,Ô-oovÄ‰#8.XÛ!GlˆºW•]'ß'!¿ÇÊ/}„,£›Zlãí¯)ô{Î¥]Y»ò2¶°õ×ï‘‚ZòÁ=5HÕ­ÃËåuÓ=$EİYÚ‰‰ÂQJÊĞÑH÷èÜ‡œT”Ó~šÃb/ØÄ(åÃ–‹ˆPsjiBÁ¥eç	ñıöùj«	xHÕìëJ¤š	àW‡ø&0nBÿêó1­in¨£FLûÏ[%+ÿ+±RäŠt>£ö`·ƒ3~e(Ô¢@€³dkÄ§¨ƒ)ïL.õ‚9ÔáÒÆÇØÄCêµÚ•J#-œH¬q¸ã˜ˆÄ˜µ<°G«Û'ŸØzÍÕ[ª.c¥å«GÒô                             NVIC_IP_REG(NVIC_BASE_PTR,26)
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
#define NVICIP51                                 NVIC_IP_REG(NVIC_BASE_PTR,50)
cdefine NVICIP52        0                 (   $  NVIC_IP_REG(NVIG_BASE_PTR,52)
#define0NVICIP53                                 NVIC_IP_REG(NVIC_BASE_PÔR,53)
+define`FVICHP54                                 NVIC_IP_REG¨NVIC_BASE_PT,54)
#$efine NVICIP55                           $     NVIC_IP_BEG(NVIC_BASE_PTR,45)
#define!NVICIP56     (                           NVIC_IP_REG(NVIC_BAsE_PTR,56)*#define NTICIP57        $   (                    NVIc_IP_REG(N^IC_BASEOPTR,57)
#define NVICIP58                                 NVIC_IP_REG(NRIC_BASE_PTR,58)
#define NVICIP59    0                           0NVIC_AP_REG(NvIC_BASE_P\R,59)
#define NVÉCÉĞ60        0                        NVIC_IP_REG(NVHC_BASE_PTR,60)
#define NVICIP61      0                          NVIC_IP_REG(NVIC_BASE_PTR,61)
#define"NVICIP62                                 NVIC_IP_REG(NVIC_BASE_PTR,62)
#define NVHCIP63    (                        (   NVIC_IP_ÒEG(NVIC_BASE_PTR,63)
#define NVICIP64                                 NVIC_IP_REG(NVIC_BASE_PTR,64)
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
#define NVICIP77                         `       NÖIC_IP_REF(NVIC_BA[E_PTR,77)
#define NVICIP78(                 `             0NVIC_IP_REG(NVIC_BASE_PTR,78)	
#define NVICHP79$       0                    (   NVIC_IP]RmGhNVIC_BASE_PTR,79)
#define NVICIP80  "  $                           NVÉC_IP_RMG(NVICßBASE_PTR,80)
#definm NVICIP81         a                       NVIC_I_REG(NVIC_BASE_PTR¬81)
#tefine NVICIP82                                 NVI_IP_REG(NVIC_BASE_PTR,82)
#define NVICIP3                                 NVIC_IQ_REG(NVIC_BASE_QTR,83+
#define NVICIP84         !                  (    NVIC_IP_REÇ(FVIC_BASE_PTR,84)
#$efine NVICIP85   0     0      "                NVIC_IPßRE(NVIC_BAWE_PTR,85)
#define NVICIP86  $  $               "     `     NVIC_IP_REG(NVIC_BARE_PTR,86)
#define NVICIP87                                 NVI[_IP_REG(NVIC_BESEPTZ,87+
#define NVICIP88                 0        `      NVIC_IP_REG(NVIC_BASE_PTR,88)
#defIne NVICIQ89                                 NVIC_IP_REG(NVIC_BASEPTR,8y)
#degine NVICHP90  0                        "     NVIC_IP_REG(NVIC_BASE_PTRl90)J#degine NVÉCIP91                     (     !     NVIC_IP_RG(NVI_BASE_PTR,91)
#define NVICIP92                                 NVIC_IP_REG(NVIC_BASE_PTR,92)
#dafine NVICIP93  $                       `      NVIC_IP_REG(NVÉC_BAQE_PTV,93)
#define NVIcIP94  $                             (NVIC_IP_REG(JVIC_BASD_PTR,94)
#define NVICIP95                "                NVIC_IP_REG(NVIC_ASE_PtR,95)
#define NVICIP96                  !              NvIS_IP_RG(NVIC_BASE_PTR,96)
#define NVICIP97      0$      0                  NFIC_IP_REG(NVIC_BAÓE_PTP,97)#define NVICIP98"         "                      NVIC_IP_REG(VIC_BASE_PTR$98)
#defi.e0NVICIP99                             (0  NVIC_IP_REG(NVIC_BASEßPTR,99)
#define NÖICIP100                                NVIC_IP_REG(NVIC_BQSE_PTR,100)
#define NVÉCIP101                     0          NVIC_IP_REG(NVIC_BASE_PTR,101)
#define"NVICIP102                            `   NVIÃ_IP_REG(NVIC_BASE_PTR,102)
#define NVHCIP103                  !             NVIC_IP_SEG(NVIC_BASE_TR,103)
£define NVICIP104         (                      NVIC_IP_REG(NVÉC_BAE_PTR*104)
#define NVIÃIP105                                NVIC_IP_REG(NVIC_BARE_PTR,105)
#d$fije NVICSTIR     0                           IC_STIR_REG(NVIC_BAS_PTR,0)

/* NViC - Register array accesso{s */
#define NVIÃ_ISEr(index)                   0 "   NVKC_ISER_REG(NVIC_BASE_PTR,index)
#define NVIC_ICER(in`ex)    0                   `NVIC_ICEPßREG(NTIC_BAS_PTR,index)
#$efine NVIG_ISPR8index)  (                      NVIC_ISP_REG(NVIC_BASE_PTR,index)
#define NVIC_ICPR(in`ex)(                        NVICOICPR_REG(NVIC_BASE_PTR,index)
#define NVIC_IABÒ(index)$                        NVIC_IABR_VEG(NVIC_@ASE_PTR,index)
#defije NVIC_YP index)                           NVIC_IP_REG(NVIC_BASE_PTR<mndex9
#define NVIC_STIR(index) )             `         NVIC_STIR_REG(NVIC_BASE_PTR,index)

/**
 ( @}
 */ /
 enD of group NVIC_Register_Accessor_Macros */


'**
 * @}
 */ ?* end of group NVIC_Peripheral */


/*(-----------m-----------,---/-­-----------------%----------------------------
   --!OSC
   /---------------}----------------------------------------m------------------ */

/**
 * @`ddtogroup OSC_Peripheral$OSC
 * @;
 */
Œ
/** OSC % Peripheral register structere */
typedef struct OSC_LemMap {
  uint8_t R;     (                                /**< OSC Control Reghster, offset: 0x0 :/} volatile *OSCMemMapPtò;

/* -------,--------------------------%------------------------------=-=--------   -- OSC - RegistEr accessos macros
 ` ---------------------------------------%------------------------------------(*/

/** * @addtogroup OSC_Reghrter_Accesqor_Magr/3 OC - Register accessor macros
(* @{
"*/


/* OSÃ(- Register accessorq */
#define OSC_CR_REG(base)  0                      ((base)->CR)

/**
 * @}
 */ /* end of group OSCRegister_Accessnr_Macroq */

/* ­-----------------------------------,--------)------­-----------------------
   --(OSC RegistEr M!sks
   ----------------------­----------­--------------------------=------/--­--=-- */

/**
 * @!ddtogroup OSC_Register_Masks OSC!Register Masks
 * @{
 *

/*0CR Bid Fiel`s */
#definu OSC_CR_SC16P_MASK                        0x1u
#defmne OSÃßCR_Sc16P_SHIFD                       0
#define OSCCR_SC8p_MASK                        "0x2u
#define OSC_Cr_SC8p_SHIFT          0             1-
#define OSC_CROSC4P_MASK                         0x4u
#dåfine OSB_CR_SC4P_SHIFT            `         ! 2
#define$OSC_CR_SC2P_MASK       $             (   0x0u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSÔEN_MASK                     0x20u
'defhne OSC_CR_EREFSTEN_SHiFT       "            5
#define OQC_CR_ERGLKEN_mASK                !     0x80u
#debmne OSC_CR_ERCLKEN_SHIFT            `        7

/**
 * @}
 */ /* enf of grnup OSC_Register_Masks */


/* OSC - Ğeripheral instance fase addsesses */
/*j Pgripheral OSC báse pointer */
#defyne$OsC_BASE_PTR                             ((OSC_MemMapPtr)0x40065000u)
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
#define PDB_MOD_REG(base)                        ((base)->MOD)
#define PDB_CNT_REG(base)                        ((base)->CNT)
#define PDB_IDLY_REG(base)                       ((base)->IDLY)
#define PDB_C1_REG(base,index)                   ((base)->CH[index].C1)
#define PDB_S_REG(base,index)                    ((base)->CH[index].S)
#define PDB_DLY_REG(base,index,index2)           ((base)->CH[index].DLY[index2])
#define PDB_INTC_REG(base,index)                 ((base)->DAC[index].INTC)
#define PDB_INT_REG(base,index)                  ((base)->DAC[index].INT)
#define PDB_POEN_REG(base)                       ((base)->POEN)
#define PDB_PODLY_REG(base,index)                ((base)->PODLY[index])

/**
 * @}
 */ /* end of group PDB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PDB_Register_Masks PDB Register Masks
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
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK)
/* C1 Bit Fields */
#define PDB_C1_EN_MASK                           0xFFu
#define PDB_C1_EN_SHIFT                          0
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          0xFF00u
#define PDB_C1_TOS_SHIFT                         8
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           0xFF0000u
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
#define PDB0_CNT                                 PDB_CNT_REG(PDB0_BASE_PTR)
#define PDB0_IDLY                                PDB_IDLY_REG(PDB0_BASE_PTR)
#define PDB0_CH0C1                               PDB_C1_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0S                                PDB_S_REG(PDB0_BASE_PTR,0)
#define PDB0_CH0DLY0                             PDB_DLY_REG(PDB0_BASE_PTR,0,0)
#define PDB0_CH0DLY1                             PDB_DLY_REG(PDB0_BASE_PTR,0,1)
#define PDB0_CH1C1                               PDB_C1_REG(PDB0_BASE_PTR,1)
#define PDB0_CH1S                                PDB_S_REG(PDB0_BASE_PTR,1)
#define PDB0_CH1DLY0                             PDB_DLY_REG(PDB0_BASE_PTR,1,0)
#define PDB0_CH1DLY1                             PDB_DLY_REG(PDB0_BASE_PTR,1,1)
#define PDB0_DACINTC0                            PDB_INTC_REG(PDB0_BASE_PTR,0)
#define PDB0_DACINT0                             PDB_INT_REG(PDB0_BASE_PTR,0)
#define PDB0_DACINTC1                            PDB_INTC_REG(PDB0_BASE_PTR,1)
#define PDB0_DACINT1                             PDB_INT_REG(PDB0_BASE_PTR,1)
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

/**
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/* MCR Bit Fields */
#define PIT_MCR_FRZ_MASK                         0x1u
#define PIT_MCR_FRZ_SHIFT                        0
#define PIT_MCR_MDIS_MASK                        0x2u
#define PIT_MCR_MDIS_SHIFT                       1
/* LDVAL Bit Fields */
#define PIT_LDVAL_TSV_MASK                       0xFFFFFFFFu
#define PIT_LDVAL_TSV_SHIFT                      0
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK)
/* CVAL Bit Fields */
#define PIT_CVAL_TVL_MASK                        0xFFFFFFFFu
#define PIT_CVAL_TVL_SHIFT                       0
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK)
/* TCTRL Bit Fields */
#define PIT_TCTRL_TEN_MASK                       0x1u
#define PIT_TCTRL_TEN_SHIFT                      0
#define PIT_TCTRL_TIE_MASK                       0x2u
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
#define PIT_LDVAL3                               PIT_LDVAL_REG(PIT_BASE_PTR,3)
#define PIT_CVAL3                                PIT_CVAL_REG(PIT_BASE_PTR,3)
#define PIT_TCTRL3                               PIT_TCTRL_REG(PIT_BASE_PTR,3)
#define PIT_TFLG3                                PIT_TFLG_REG(PIT_BASE_PTR,3)

/* PIT - Register array accessors */
#define PIT_LDVAL(index)                         PIT_LDVAL_REG(PIT_BASE_PTR,index)
#define PIT_CVAL(index)                          PIT_CVAL_REG(PIT_BASE_PTR,index)
#define PIT_TCTRL(index)                         PIT_TCTRL_REG(PIT_BASE_PTR,index)
#define PIT_TFLG(index)                          PIT_TFLG_REG(PIT_BASE_PTR,index)

/**
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group PIT_Peripheral */


/* ----------------------------------------------------------------------------
   -- PMC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Peripheral PMC
 * @{
 */

/** PMC - Peripheral register structure */
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                  /**< Low Voltage Detect Status And Control 1 register, offset: 0x0 */
  uint8_t LVDSC2;                                  /**< Low Voltage Detect Status And Control 2 register, offset: 0x1 */
  uint8_t REGSC;                                   /**< Regulator Status And Control register, offset: 0x2 */
} volatile *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */
#define PMC_LVDSC1_REG(base)                     ((base)->LVDSC1)
#define PMC_LVDSC2_REG(base)                     ((base)->LVDSC2)
#define PMC_REGSC_REG(base)                      ((base)->REGSC)

/**
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


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
 */ /* end of group PMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PORT
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Peripheral PORT
 * @{
 */

/** PORT - Peripheral register structure */
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  uint32_t GPCLR;                                  /**< Global Pin Control Low Register, offset: 0x80 */
  uint32_t GPCHR;                                  /**< Global Pin Control High Register, offset: 0x84 */
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                   /**< Interrupt Status Flag Register, offset: 0xA0 */
  uint8_t RESERVED_1[28];
  uint32_t DFER;                                   /**< Digital Filter Enable Register, offset: 0xC0 */
  uint32_t DFCR;                                   /**< Digital Filter Clock Register, offset: 0xC4 */
  uint32_t DFWR;                                   /**< Digital Filter Width Register, offset: 0xC8 */
} volatile *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#define PORT_PCR_REG(base,index)                 ((base)->PCR[index])
#define PORT_GPCLR_REG(base)                     ((base)->GPCLR)
#define PORT_GPCHR_REG(base)                     ((base)->GPCHR)
#define PORT_ISFR_REG(base)                      ((base)->ISFR)
#define PORT_DFER_REG(base)                      ((base)->DFER)
#define PORT_DFCR_REG(base)                      ((base)->DFCR)
#define PORT_DFWR_REG(base)                      ((base)->DFWR)

/**
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1
#define PORT_PCR_SRE_MASK                        0x4u
#define PORT_PCR_SRE_SHIFT                       2
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4
#define PORT_PCR_ODE_MASK                        0x20u
#define PORT_PCR_ODE_SHIFT                       5
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
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
#define PORTD_BASE_PTR                           ((PORT_MemMapPtr)0x4004C000u)
/** Peripheral PORTE base pointer */
#define PORTE_BASE_PTR                           ((PORT_MemMapPtr)0x4004D000u)
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORTA */
#define PORTA_PCR0                               PORT_PCR_REG(PORTA_BASE_PTR,0)
#define PORTA_PCR1                               PORT_PCR_REG(PORTA_BASE_PTR,1)
#define PORTA_PCR2                               PORT_PCR_REG(PORTA_BASE_PTR,2)
#define PORTA_PCR3                               PORT_PCR_REG(PORTA_BASE_PTR,3)
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
#define PORTA_PCR29                              PORT_PCR_REG(PORTA_BASE_PTR,29)
#define PORTA_PCR30                              PORT_PCR_REG(PORTA_BASE_PTR,30)
#define PORTA_PCR31                              PORT_PCR_REG(PORTA_BASE_PTR,31)
#define PORTA_GPCLR                              PORT_GPCLR_REG(PORTA_BASE_PTR)
#define PORTA_GPCHR                              PORT_GPCHR_REG(PORTA_BASE_PTR)
#define PORTA_ISFR                               PORT_ISFR_REG(PORTA_BASE_PTR)
#define PORTA_DFER                               PORT_DFER_REG(PORTA_BASE_PTR)
#define PORTA_DFCR                               PORT_DFCR_REG(PORTA_BASE_PTR)
#define PORTA_DFWR                               PORT_DFWR_REG(PORTA_BASE_PTR)
/* PORTB */
#define PORTB_PCR0                               PORT_PCR_REG(PORTB_BASE_PTR,0)
#define PORTB_PCR1                               PORT_PCR_REG(PORTB_BASE_PTR,1)
#define PORTB_PCR2                               PORT_PCR_REG(PORTB_BASE_PTR,2)
#define PORTB_PCR3                               PORT_PCR_REG(PORTB_BASE_PTR,3)
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
#define PORT‡ÔÙÕµBÔ—‘ŞÏ]fh#èâì`‹éç9¿â1¾–ŠğÑú”v­60Ô¦q¿ÊÄIv5ô€‡¡R_©`8:ß(’&"u¹‘Mƒ™Ûéá‹~ÊÖzu&÷€nËŒ°¥±š¡ˆdÆÒ–ÿ<—Â:h¾A°%)y¡cÓ-`ní3`ş‰³œF¼"%íÔ5,süÒV>úÖ3ª h‰†v[lVyí¸Ü6è+°?Ûû)›/†p<šè.ˆ×l…÷R€­ I„ã:Aq•g×;nĞ1}nÁo
"¥<ö7-'£Á\à#(À‰_GæsEbgÎß•‰6­¨@¢#x?†¶ƒ‡óğb¨PÅ6„:Ù6C2ØFJÇÆP©µÇiû®AOCN¿všÃë˜ ”ş.N7½³Úxø­r¥”’MÂÓB`İùÁ¬Xf>Õ6@orÔù›¢Må°&§şºóÅ^®¸™É"7†b‡6ğ€Õ6Ñò>&'ù{eSƒ“3(¶&¼oÓ"ÿ|ZaC¤|XG¹4ùJ–<>nÁÍ0«øƒ9•éØ]}RèDáœÃå¿4Úî;{©°Ï³üMè6!<-°fjóı}©ÜY†5ÌØßĞä4ë´Ò#ËÇb?µ0½
QXã“‘U£Ö34(õœ#÷z–\c9zoŸ
?yÆm[C°§Ó:¤snqşI%‘ì~Ï-vã¡Çu[ŒÊÀ¡U¬Šˆ&Şj7æ<İ©²@8Y‰dç«[£Ñ!ë •½;m-şÄc[-×ïMóUDm'Ä‘jXÇ@_Kz|™´ÖQîçö\@ H¥ôİ¸ÇX[Ç¤ªÉKí)™:„F9…|(àbNŠ–n}±‹vgl6¬½„­ã`srÒ¯/Ll™Ùj™Â®U±ìÎ¿x¦8ïú1ár€ßOU©¼F7²•´šÁ{LÙ­´ûóÊhç‹óDîš9¬ÆîóS1xñgt#¯é™ıAÎ¿3™ÅĞ
FšYM(Ò_:>3í(ù-'±o/ üÊ1õ×,:–5şßpÎˆyÒyaŞ\ÿ˜;’UV&±u"õîAš›Ïáû¨MòYè†)ş–K¡p¡"DóıâÇ„øU€¾:¿{³Zr×£›Ç
~c.‘)¥ h©ıR:âdyÈ¢È÷x~¡3·Ôaó\FµÇw\ÃQ=GæôP¼Fû£¯)8ımƒ»ë´?úpxæ\yo–>m£øı¹èšFû[•sï°ÚÑ ¢BæÀ¬üw_QDK«P¬¿`Ÿã†6ÉO”üú°‹8×Lî²€+Ë2÷rL‘n@dY[e™ù†ß’QP(Hd+Ú+Çœc¼q‰$öİn)AÚÔ§,¾É+ŞÄJöÍ¡,@h‹îÁ{
•Ğ>æJòh~Á„Ù’%°"(û¤‹ì¢mšBë¹,òî ÜÁ‚µÈĞÍÂş’èöİ¢%ß†¢Ì+hÄúŸ£a³äâ§ù‹nŠB6¯Ì¤bÎØğ•üİo«J?>…hû¬j“›íåùÇ5ÈmF‰½ ‰nÀ3Ñõ½bcX¾{ö–ÖûÈbulZÓ²é'„VLáÚÖÏ¬M†Æ<Z “^¥}ëE!.¢´£e 7Q»2KÑ’î0¤¡ãµ]a8òæ["vß¤'·ş>F(`uaªÌvy‚ªß·ºaa“vTxı™¬K±ô¸°XêÙÇw!Zv1á,h¾õ†…Ö-º†Æ•^èe!¥²±o//wØVkŸúğ:'·÷„»¹¤Öş¿#c^bÌHº¦•ÕÛÙî& ‹ÙOõ{+æ…³‚;0$ÅøGğ.œDØy÷Š7±´ş{³éß%ğgëëF%Æç_åw]Ú´İaœ‹Á¶åŠ)8Æùazó8Gd¡{õYrÜ>yÿ£Œ’½âyÙäÌ²eÅA^Ä€ÀG™bî›Òà×yfÂ·åW8›ç¿j[¢šm
¿”š§Qã×Hv”¾G€ë[·¶@÷÷@F½’Ì»´Õ¦{rlñÉğ
ç^Ü_Ú™v{Pƒzì	LâQZM‰Xm¥OØéíİ£µù<Ä?lõèç`ò$xş‚şæŠü¹]šõgß`£·»L¨bÈş¹ÔØlÄ¸ùo™çv„HÜJª²{ÈµÉ‘%9@u·Ÿ×¿<+Ê)óâñ©¼íb³…ßØ„\`„…ˆÕá_†S
*ˆ–Eéi¹ì¯í$îp“/•İÏ2ÿ¾ "ĞÄºş`!#…¨9Û>¨"Ÿº|²F¶5%æx…İc×O´Š¿Al‘I9N¦UEñ0gíUÍAŒ:zÁjñõ ï‡&çÎbò€´€!x¶ûÍe3õñT6ØR„z_&Ny¹ÿjî&/İ¡‡9šr3GN¢<lèdÎ}GÊHP‘[4Ñt2cU]~6¬4¸lç‘hfË–T¯ŞQ>-ÚĞBÒ`“°2»Õ=ÊXÊŸ½gëæ_”zc’Iõê¶÷<M <½1c¬†%€í§uWJ'VÖ·UsÎ«¢B…]ìşt	úĞ2Q¦B¯È+ªÎTÄ97‹ÚX++¿ÍˆNˆ‰@¯û¡‡¥S¹únOcMZĞ¯Yn9'lª-ö¿DÆ<U,œ*Ó$âî£ˆ\äO~†'å0/]İ¤T¹ûF.Nßüå;H~oßÏ—ï|P«¯V”‹©AóÌld®õ®´À—{DU®çUàÂGøyËS…(¿½ÏŞ”)ßğ,$8l?â$òß|¾aYƒïç™ªıé¥ÆQ ÕiœÒ5ªÜØÄğD9±ø^(R«¼å—ŒG*¥/#ˆy“»6Î¾6 ĞÀ]ê()¦˜eìbÄ¢B>wº.ìWBİ‹Û“+‘unnˆ=4pG‰Îœ­a3“ª¨ø€ˆ#<*]<y£Hiêäs.p&ş‹(Seô< ø´ï¹gwú¥cd6k®j›@±«X­‰]{Ê¾9±Ø‡[ò><¶‰ıç«g³öûéŞ],qwin ğ»”ømú$atåÍ:Q•JÙ/[—NóÀ¥Ù?÷3<Ó‚g-Dì=gé³|ŒkÎ•¹ .ŞÙ²À–&5}pk»8âÆ÷ªdê€=x ¥i=ÅeğÀ›jËÃ/~ñ®0gr ²ç$LÑ»ğË}²œ+ÿ’Ivúñu9	ø“Ñ1š,²*ıÈ¡ê*&©Â:ÛA-„·ˆR\!w¬¯^÷°#fFÀ®#É ÔÈû—!¢LY—ˆS¸Ù=`ø[£‹h_ÍÛ¬Ïo–Ü•’´§;—dÆäÄÕEy¨úÄh^#Ä„6e…ñ£Ü¾×drUdtÿ¬hó‡O±ß#åœİ)2éw`J¸&%r•gœÔ«?±;OÌÖUEºQUO}º€BÖ/­©¢½àêayz—V¥ÚÂ5ºõ!†Ä	
gÊ®gÏÜ©(ü'+‰’Ü:f<Ì>cÍg¡6Í¬à·ß{–ó*_>CTÇ:~ˆ4K¦Ù>•Ôx¨’‹Ï›Ã4Úú..ZiêÚªâYÏÈnjÉÒ”Oàwş$ñEù¦^Â¦'Où-.úÁ†·×j‰ÊŠ´0-5âlÑC¢€q¬8ÌÁ0{SlV¹¿ám4.QQ-úÏ_¹z¾WCıºÕ“É›xmç_~|^y
½©İ‘:¥³„/£.9¨©ÕÛ½®K‰“IM”ÿ[³ÈSêºÈQ_?¤—ıpIÙäÚ¤~‚¬Œ‘YíaGû†_õzÒ³UEÑV÷uÎÈJ:zCÈlZ&œ'TòSû®u=N™ù‘fãázKC|uÏrÆ=ÿ§w@|\ ¬*MµƒØNêGDÄèö´]ÄzìC‘}Ğ|Èˆ+®¾çÌ úÜÿ4FI`}á4ãB×·ı-°CCú…?ÉóAè‡7ØvÉz³>¥y8 ]{S›´ šÛ’èŒ›(ì7ØÙüûÎº‹ÌîİÜEï	ğ"¤g-beò‰*!HS)TdğEyôeıã¤pØ­V¬à`Ó“êÙÉŠÕÏ1JÙÈQ¦"£aº®×ÚÏ«òÂ4©Ç‰Šˆ±¿=­N~ÃùÀ›g§*±	rJ©iO~4‹;ŸÂ`’ŒÔ‡¨R>ïhÉŸ8ç	~ ğq‰”ŞhÊ1'$mNn¸åmû·(˜Cğw'¸§¬"ÀìÃÚ§ÔJVüöŸNÅ©—Ğ‰Ò“»ãH‹:ùÖÇ>Å´Á®ûÖl]‡À¢Î>y=1ŞÁïºYìA-OB}¿}ô²¬SN«Ûö['*á@s¦˜¢íù.%fÏ»íX®Ån—§
AÑªïğ»cã¶–ÿŸ¨: ¬ê“4Í=–³ğ§a¿·­W#jGh†¤°\u@ìóiµm·~*Å'¼„õ`– äÏ”ÛfÇêë¬ÀÉó[Ël¶JÙyö6REÀïÃõ)Ù—û›¥xÈ	Fø‡wE)1H£§µLßsg‰”;#i,i`P745èfT¸¢?vû¸Éğ¨¯k(!5´áêÈÄœV®!]íôÉ]æCsN'öV‰˜6u”•OC–Ï‰µœ%5Hœãx°ÖGcn4¶z«+ITÉîÏ§8f/LQ•€øßjÃ¿½¿“ßìfÓcº=	¨WğcæÒÈ#Fibõ¬QiÌ¹âv¬=Í’˜ú/³å$‚·`ı†Ã±9{¡wı£|Pï6â*-ıYÜ·İœôâ¨¼LKW£\ˆÉ²u‰Ô6©:ù]N£»M“˜p,œbş¸"5y™”*âêãxh-Â_G¹E¾GŠ[ëIABfá&9§Æ-è”´Ò)€ÎI·3MH[Å¬(^¿~KlÙåRÇ +tAG×9([“\İ,Péšíg†>kÕ2^é†’Ÿ’°CÌ]†Cú´ª´XÍüùÄ48zuJ­ {*ÌåU‰üÆ×T\h‚ZÊ¨âç§eæRî°[e¬V&±\ÂT ÀİKeEĞÄü­Ó%úT®ğ•±P}×‡m+Ö;gì# ,`}‘`qfÈMNNe
=@ËÕcœ$YBÏL—È.Ç²ëíœ¦ğ	'ÎB0&d¹BmU|N·Åß·&¥'ø¤<Ú7ÛsªC0™³p
·[)m!'ç*ÇÀ½F”óüY·T-Jw§ßõ—éfî.X¾¶ÚÿàröOÙDVÔ8lT8”¼èßŠø}ÃÑÌMlQ¯%‹Ù˜ı6œ¸öbÈÁ˜Î“•_Cá²÷F’Œ{’ö-7u^Á¬Ö¸®Ü7O?­»gš‰æf…üg‹òåÜ7<›šÎ-ˆØ”m:0b8æø.• Å§ø,c²CR28                              PORT_PCR_REG(PORTC_BASE_PTR,28)
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
#define PORTD_PCR15 ‡ÔÙÕµBÔ—‘ŞÏ]fh#èâì`‹éç9¿â1¾–ŠğÑú”v­60Ô¦q¿ÊÄIv5ô€‡¡R_©`8:ß(’&"u¹‘Mƒ™Ûéá‹~ÊÖzu&÷€nËŒ°¥±š¡ˆdÆÒ–ÿ<—Â:h¾A°%)y¡cÓ-`ní3`ş‰³œF¼"%íÔ5,süÒV>úÖ3ª h‰†v[lVyí¸Ü6è+°?Ûû)›/†p<šè.ˆ×l…÷R€­ I„ã:Aq•g×;nĞ1}nÁo
"¥<ö7-'£Á\à#(À‰_GæsEbgÎß•‰6­¨@¢#x?†¶ƒ‡óğb¨PÅ6„:Ù6C2ØFJÇÆP©µÇiû®AOCN¿všÃë˜ ”ş.N7½³Úxø­r¥”’MÂÓB`İùÁ¬Xf>Õ6@orÔù›¢Må°&§şºóÅ^®¸™É"7†b‡6ğ€Õ6Ñò>&'ù{eSƒ“3(¶&¼oÓ"ÿ|ZaC¤|XG¹4ùJ–<>nÁÍ0«øƒ9•éØ]}RèDáœÃå¿4Úî;{©°Ï³üMè6!<-°fjóı}©ÜY†5ÌØßĞä4ë´Ò#ËÇb?µ0½
QXã“‘U£Ö34(õœ#÷z–\c9zoŸ
?yÆm[C°§Ó:¤snqşI%‘ì~Ï-vã¡Çu[ŒÊÀ¡U¬Šˆ&Şj7æ<İ©²@8Y‰dç«[£Ñ!ë •½;m-şÄc[-×ïMóUDm'Ä‘jXÇ@_Kz|™´ÖQîçö\@ H¥ôİ¸ÇX[Ç¤ªÉKí)™:„F9…|(àbNŠ–n}±‹vgl6¬½„­ã`srÒ¯/Ll™Ùj™Â®U±ìÎ¿x¦8ïú1ár€ßOU©¼F7²•´šÁ{LÙ­´ûóÊhç‹óDîš9¬ÆîóS1xñgt#¯é™ıAÎ¿3™ÅĞ
FšYM(Ò_:>3í(ù-'±o/ üÊ1õ×,:–5şßpÎˆyÒyaŞ\ÿ˜;’UV&±u"õîAš›Ïáû¨MòYè†)ş–K¡p¡"DóıâÇ„øU€¾:¿{³Zr×£›Ç
~c.‘)¥ h©ıR:âdyÈ¢È÷x~¡3·Ôaó\FµÇw\ÃQ=GæôP¼Fû£¯)8ımƒ»ë´?úpxæ\yo–>m£øı¹èšFû[•sï°ÚÑ ¢BæÀ¬üw_QDK«P¬¿`Ÿã†6ÉO”üú°‹8×Lî²€+Ë2÷rL‘n@dY[e™ù†ßBÕ»ïƒÇ‰Õtl›X¯ÒıáÛ‘¸mgÑ_ô/),lĞæùÜn~c °†P8³¾ÛæôÌ‘û«P>~3µ’*%¢x)“¤bÿ±Ji·ÎR'>œú87F/šOfÈ+m/†Rn4Ä9ôŸèé?å]‘Ó½ŸTÊ×ş÷°èÓX^
ÒÄZM±&0cQ;1± 
Çõ=êA4âáè×–Ved-zx¾ç¤Şí÷'Éèd„Ëõª¤u1»*qéˆN•ĞÀÑHí—ENXC« Ó‚ØœŠyÙ]ß™Û¼FÅß™<·0µ0Ôk ¦ãÀyMS¬KaéŠ'’%™ÇrÕáf&™ÙAr°T§ÒÊ n0ëq‚ş@Çº.	Îb“–&MÉ/ü ª“1_Öÿ€%°pSBÍ–‰B“şŸLè·‡™Ï¬$¢°Éø?,Øjt¹ahOgK.•òÙ€º1#Fü§{ªÉW½z‡ÓL?åöDã¿û1¤ÄÖ¦ÑúåúOªU²‡©xÊ£OùR{PçİŞ<a,3cŸ±â‹j:Ï#›óPºğ>åéh1FÔ¦&_t6-v›<º{í$Õ·øzäoo~Ëîí®£Q†q;F1Ac¯j~§>5[O~Ö+é-2ÙFƒú`Ö€‰\aÒ¥/2;au±Šÿ­ù<5óöˆÕP ƒ¶‹a´W F)öPƒüîWÜª™¿À]£¤¹h«sñä3Q¨ùI×­â\ÓmÖêˆwA»çh±`t\Äu)yi!2œö­‡uüÎioj¤MM ÇóÚƒôØZdGÿ/ïyLşÕãŞ«ùL™Ù4<Ú=şˆ«'‹ŸÃö= 2M¤AÁD¾F\Gú"Ò¨RşfíİYù¶¼şxÔ5×ß½“j6‹x„0~ZºŸ@åHÄb˜¬î’2œ-ØTK`uşĞ!‰+«ŠÖTñ¡‘ñ®Åê…ÎğÂJ6IX_
ì€9_(SŸ„¢‘ Õ|ê®dgò.1P•ˆ6bS\)="‚…U÷1ì%É}—ı(ú¬y×Ç/‹À›wúŸAÓyh©­ˆ‘[]krö,JÎ£l}¤”¨_ã,ÿ$ ¨mŸwiç]ˆıf†¿Ğrw}İb¾®,¥ÏJ7]mN)Û&õ·`¿Xfl~Bø9~İĞ8q	ÙJŞG=üõ ‚z`@d‡0›@‰ø“"Z
|Ü>T(÷ËFˆM‘3=£†Ï³–r:7’uÿ i_LEáµlh©rÊÉ;ªcñ(ï²ôÈ÷HÅ›69&ˆü&%Úòu¨ç-'²cı9Ñm.¨orí$K?.c¿;H«œøD‘¤¢è˜Îbòšvø2                               PORT_PCR_REG(PORTE_BASE_PTR,2)
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
#define PORTB_PCR(index)                         PORT_pCR_REG(PORTB_RASE_PTR,index)
#define ROÒTS_PCR(index)        !          " (   PORT_PCR_REG(PORTC_BASE_PTR,index)
#define PORT_PCR(indey)    $                    PORT_PCR_VEG(P_RTD_BASE_PTR,Index)Š#define POPTE_PCR(index)    $                    PORT_PCR_REG(PORTEZBASE_PTR,index)

/**
 * @}
 */ /* end of group PORT_Begéster_Accescor_Macros */


/**
 * @}
 */ /* end of group PORT_Peripheral0*/


/* -----=-----------------------------%------------------------------­---------
   -- RCM
   -----------------------------------%----------------------------­----------- */

/**
 * @addtogroup!RCM_Reòipheral RCE
 * @{
 */

/** RCM - Peripheral register {tructure */
typedef!struot RCm_MemMax"{
  uint8_t SRS2; "                                  /**< System Reset Status Registev 0, Offset: 0x0 */
  uint8_t SRS1;                            0       ¯**< System Reset Status Register 1, offset: 0x1 */
  uint8_t RESERVED_0[2];
  uint¸_t RPFC;(     !                             /**< Reset Pin Filter Control register, offset: 0x4 */
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


/* ----------------------)---------------------m-------------------------------
   -- RCM Register Masks
   -----------------------------/-%----,/-----------------m-¯----------------- */

/**
 * @addtogrouğ!RCM_Begistep_Másks RCM Register Masks
 * @{	 */

/ª SRSp(Bit Fields */
#define RCM_SRS0_WAKEUP_MASK      $              0x1u
#debine RCM_SRS0_WAKEUP_SHIFT             0      0
#define RCM_SRR0_LVD_MaSK                        0h2u-
#define RCM_SRS0_LVD_SHIFT                       1
#define RCM_SRS0_LOC_MASK           "            0x4u
#definm RCL_SRSp_LOC_RXIFT                  "    2
#define RCM_SRS0_LOL_MASK                 0      0x8u
#define RCM_SRS0_LOL_SHIFT                      "3
#define PCM_SRS_WdOG_MASK                       0x20u
#define RCM_SRS8_WDOG_SHIFT                      5
#define ZCL_SRS0_PIN_MASK   "       (            0x$0u
#define RCM_SRS0_PIN_S(IFT    "      `           6
define RCM_SRS0_POR_MASK                 !      0x80u
#`efmne RCM_SRS0_@OR_SHIFT                       7
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
#define RCM_PPFC_SSTFHTSS_SHIFT           "      2/* RPFW"Bit Gields */	
#define RCM_RPFW_RSTFLTSÅL_MASK        "  "      0ø1Fu
#define RCM_RPFW_RSTfLTSEL_CHIFÔ                 0
#define PCM_RPFW_RSTGLTSEL(x)                    (((uint8_t)(((uint8_t)(X))<<RCm_RPFW_RSTFLTSGL_SHIFT))&RCM_RPFW_RSTFNTSEL_MASK)
/* MR Bit Fields */
#define RCM_MR_EZP_MS_MASK      0                0x2u
#define RCM_MR_EZP_MS_SHIVT"               0     1

o**
 * @}
 */ /* end mf group RCM_Reçister_Iasks */


/* RCM - PårIpheral instance base addressew(*/
/** Peripheral RCM base pninter 
/
#degine RCM_bASE_PTR0!                 "   !     ((RCM_MemMapPtri0x4007F000u)
/*( Array initializer og RÃM peripheral base pgmnters */
#define RCM_BASE_PTRS         "        (         {0RM_BASE_PTR }

/* -----------------------------------------)-------------------------------
   -- RCM - Register accessor macros
   -------------------+----------------------------=-­------------------------ */

/**
 * @addtogroup RCI_Regaster_Accdssor_Macros RCM - Register accessor macros
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
  uint32_t REG[8];                                 /**< Register file register, array offset: 0x0, array step: 0x4 */
} volatile *RFSYS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RFSYS - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Accessor_Macros RFSYS - Register accessor macros
 * @{
 */


/* RFSYS - Register accessors */
#define RFSYS_REG_REG(base,index)                ((base)->REG[index])

/**
 * @}
 */ /* end of group RFSYS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RFSYS Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFSYS_Register_Masks RFSYS Register Masks
 * @{
 */

/* REG Bit Fields */
#define RFSYS_REG_LL_MASK                        0xFFu
#define RFSYS_REG_LL_SHIFT                       0
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK)
#define RFSYS_REG_LH_MASK                        0xFF00u
#define RFSYS_REG_LH_SHIFT                       8
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK)
#define RFSYS_REG_HL_MASK                        0xFF0000u
#define RFSYS_REG_HL_SHIFT                       16
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK)
#define RFSYS_REG_HH_MASK                        0xFF000000u
#define RFSYS_REG_HH_SHIFT                       24
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK)

/**
 * @}
 */ /* end of group RFSYS_Register_Masks */


/* RFSYS - Peripheral instance base addresses */
/** Peripheral RFSYS base pointer */
#define RFSYS_BASE_PTR                           ((RFSYS_MemMapPtr)0x40041000u)
/** Array initializer of RFSYS peripheral base pointers */
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

/**
 * @addtogroup RFVBAT_Register_Accessor_Macros RFVBAT - Register accessor macros
 * @{
 */


/* RFVBAT - Register accessors */
#define RFVBAT_REG_REG(base,index)               ((base)->REG[index])

/**
 * @}
 */ /* end of group RFVBAT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RFVBAT Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Register_Masks RFVBAT Register Masks
 * @{
 */

/* REG Bit Fields */
#define RFVBAT_REG_LL_MASK                       0xFFu
#define RFVBAT_REG_LL_SHIFT                      0
#define RFVBAT_REG_LL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LL_SHIFT))&RFVBAT_REG_LL_MASK)
#define RFVBAT_REG_LH_MASK                       0xFF00u
#define RFVBAT_REG_LH_SHIFT                      8
#define RFVBAT_REG_LH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LH_SHIFT))&RFVBAT_REG_LH_MASK)
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
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RFVBAT_Register_Accessor_Macros RFVBAT - Register accessor macros
 * @{
 */


/* RFVBAT - Register instance definitions */
/* RFVBAT */
#define RFVBAT_REG0                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,0)
#define RFVBAT_REG1                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,1)
#define RFVBAT_REG2                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,2)
#define RFVBAT_REG3                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,3)
#define RFVBAT_REG4                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,4)
#define RFVBAT_REG5                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,5)
#define RFVBAT_REG6                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,6)
#define RFVBAT_REG7                              RFVBAT_REG_REG(RFVBAT_BASE_PTR,7)

/* RFVBAT - Register array accessors */
#define RFVBAT_REG(index)                        RFVBAT_REG_REG(RFVBAT_BASE_PTR,index)

/**
 * @}
 */ /* end of group RFVBAT_Register_Accessor_Macros */


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
#define RTC_TCR_TCV_SHIFT                        16
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK)
#define RTC_TCR_CIC_MASK                         0xFF000000u
#define RTC_TCR_CIC_SHIFT                        24
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK)
/* CR Bit Fields */
#define RTC_CR_SWR_MASK                          0x1u
#define RTC_CR_SWR_SHIFT                         0
#define RTC_CR_WPE_MASK                          0x2u
#define RTC_CR_WPE_SHIFT                         1
#define RTC_CR_SUP_MASK                          0x4u
#define RTC_CR_SUP_SHIFT                         2
#define RTC_CR_UM_MASK                           0x8u
#define RTC_CR_UM_SHIFT                          3
#define RTC_CR_OSCE_MASK                         0x100u
#define RTC_CR_OSCE_SHIFT                        8
#define RTC_CR_CLKO_MASK                         0x200u
#define RTC_CR_CLKO_SHIFT                        9
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
#define RTC_RAR_TARR_MASK                        0x4u
#define RTC_RAR_TARR_SHIFT                       2
#define RTC_RAR_TCRR_MASK                        0x8u
#define RTC_RAR_TCRR_SHIFT                       3
#define RTC_RAR_CRR_MASK                         0x10u
#define RTC_RAR_CRR_SHIFT                        4
#define RTC_RAR_SRR_MASK                         0x20u
#define RTC_RAR_SRR_SHIFT                        5
#define RTC_RAR_LRR_MASK                         0x40u
#define RTC_RAR_LRR_SHIFT                        6
#define RTC_RAR_IERR_MASK                        0x80u
#define RTC_RAR_IERR_SHIFT                       7

/**
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base pointer */
#define RTC_BASE_PTR                             ((RTC_MemMapPtr)0x4003D000u)
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register instance definitions */
/* RTC */
#define RTC_TSR                                  RTC_TSR_REG(RTC_BASE_PTR)
#define RTC_TPR                                  RTC_TPR_REG(RTC_BASE_PTR)
#define RTC_TAR                                  RTC_TAR_REG(RTC_BASE_PTR)
#define RTC_TCR                                  RTC_TCR_REG(RTC_BASE_PTR)
#define RTC_CR                                   RTC_CR_REG(RTC_BASE_PTR)
#define RTC_SR                                   RTC_SR_REG(RTC_BASE_PTR)
#define RTC_LR                                   RTC_LR_REG(RTC_BASE_PTR)
#define RTC_IER                                  RTC_IER_REG(RTC_BASE_PTR)
#define RTC_WAR                                  RTC_WAR_REG(RTC_BASE_PTR)
#define RTC_RAR                                  RTC_RAR_REG(RTC_BASE_PTR)

/**
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group RTC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SCB
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Peripheral SCB
 * @{
 */

/** SCB - Peripheral register structure */
typedef struct SCB_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t ACTLR;                                  /**< Auxiliary Control Register,, offset: 0x8 */
  uint8_t RESERVED_1[3316];
  uint32_t CPUID;                                  /**< CPUID Base Register, offset: 0xD00 */
  uint32_t ICSR;                                   /**< Interrupt Control and State Register, offset: 0xD04 */
  uint32_t VTOR;                                   /**< Vector Table Offset Register, offset: 0xD08 */
  uint32_t AIRCR;                                  /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  uint32_t SCR;                                    /**< System Control Register, offset: 0xD10 */
  uint32_t CCR;                                    /**< Configuration and Control Register, offset: 0xD14 */
  uint32_t SHPR1;                                  /**< System Handler Priority Register 1, offset: 0xD18 */
  uint32_t SHPR2;                                  /**< System Handler Priority Register 2, offset: 0xD1C */
  uint32_t SHPR3;                                  /**< System Handler Priority Register 3, offset: 0xD20 */
  uint32_t SHCSR;                                  /**< System Handler Control and State Register, offset: 0xD24 */
  uint32_t CFSR;                                   /**< Configurable Fault Status Registers, offset: 0xD28 */
  uint32_t HFSR;                                   /**< HardFault Status register, offset: 0xD2C */
  uint32_t DFSR;                                   /**< Debug Fault Status Register, offset: 0xD30 */
  uint32_t MMFAR;                                  /**< MemManage Address Register, offset: 0xD34 */
  uint32_t BFAR;                                   /**< BusFault Address Register, offset: 0xD38 */
  uint32_t AFSR;                                   /**< Auxiliary Fault Status Register, offset: 0xD3C */
} volatile *SCB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros
 * @{
 */


/* SCB - Register accessors */
#define SCB_ACTLR_REG(base)                      ((base)->ACTLR)
#define SCB_CPUID_REG(base)                      ((base)->CPUID)
#define SCB_ICSR_REG(base)                       ((base)->ICSR)
#define SCB_VTOR_REG(base)                       ((base)->VTOR)
#define SCB_AIRCR_REG(base)                      ((base)->AIRCR)
#define SCB_SCR_REG(base)                        ((base)->SCR)
#define SCB_CCR_REG(base)                        ((base)->CCR)
#define SCB_SHPR1_REG(base)                      ((base)->SHPR1)
#define SCB_SHPR2_REG(base)                      ((base)->SHPR2)
#define SCB_SHPR3_REG(base)                      ((base)->SHPR3)
#define SCB_SHCSR_REG(base)                      ((base)->SHCSR)
#define SCB_CFSR_REG(base)                       ((base)->CFSR)
#define SCB_HFSR_REG(base)                       ((base)->HFSR)
#define SCB_DFSR_REG(base)                       ((base)->DFSR)
#define SCB_MMFAR_REG(base)                      ((base)->MMFAR)
#define SCB_BFAR_REG(base)                       ((base)->BFAR)
#define SCB_AFSR_REG(base)                       ((base)->AFSR)

/**
 * @}
 */ /* end of group SCB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SCB Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SCB_Register_Masks SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define SCB_ACTLR_DISMCYCINT_MASK                0x1u
#define SCB_ACTLR_DISMCYCINT_SHIFT               0
#define SCB_ACTLR_DISDEFWBUF_MASK                0x2u
#define SCB_ACTLR_DISDEFWBUF_SHIFT               1
#define SCB_ACTLR_DISFOLD_MASK                   0x4u
#define SCB_ACTLR_DISFOLD_SHIFT                  2
/* CPUID Bit Fields */
#define SCB_CPUID_REVISION_MASK                  0xFu
#define SCB_CPUID_REVISION_SHIFT                 0
#define SCB_CPUID_REVISION(x)                    (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_REVISION_SHIFT))&SCB_CPUID_REVISION_MASK)
#define SCB_CPUID_PARTNO_MASK                    0xFFF0u
#define SCB_CPUID_PARTNO_SHIFT                   4
#define SCB_CPUID_PARTNO(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_PARTNO_SHIFT))&SCB_CPUID_PARTNO_MASK)
#define SCB_CPUID_VARIANT_MASK                   0xF00000u
#define SCB_CPUID_VARIANT_SHIFT                  20
#define SCB_Chº_ÊÏ‰ù›wİŸhÉ¨uòÖ&iÎF×oi‹GØät¹D"ƒL´`À!· ZªÏ£Ş—2ä·‹I7ª¤ºòÜ* oª‚Æ°á¹%ÜiŒU€JŠNxu3
&+mO–‰Œ:xEÎv5!ZözPxæt€á‰±[‹‡èl¹]hL)"”Û¾Ö¡FâHÚúø*yÌ.¼ßÎÊø59£„ÅŒN1èİÊ—İÑP½«×ïªÕ¨L‚[¯=ùóRäº•S¶_N™-~q6ØÔß$)¸¬ßì|?,Ï™fn5âÁt„ëÇ2LÄÆĞCoMÕYwî¿±ºñ}™1VöO†?„HŞ"uL';Î6e[]Ç	Lü+ËXÖ¥(šl2hâ/ã,7Â„¶ê“óŞÓ¨'x‰Š†µ¶{Û6(œÈïÊ4†Š¸ø<.©}-•/‡P‡Şb€›YóşäÙ¼£!ÃîRŸÀB‡$qñ‰%\ê‡B‹Æ)¸,©÷fCoş)0…KNnÎe²À¸D)ëõ7™YT.òª;…sÃ—µ¡>ìæTÂĞ¤Ën^v5õÒ^÷:xÓ›ĞD£eÃ>Åh´B0nx›¼™b­ÿfcD°Lí½]/92‰?ïRçñ!QùRşçxü˜x{vÈOcw1óùáÍœ=È·IÍA¶F×§1°tKÀ¶~M¿Õ²:SÏaƒb¹ä{^OùÖ«ˆİ_‘…(+~\Â_…åjXi1¬—"8b7éËØW³«½<ªä|Z*q[jK¬kÏ9µ
–ç[ßgõ;;6r-›·†çØH­6%ÙA¹YiÚĞÍ¿
)ö–ÑÅ©`3Tı²|ş­eÂ“&ª@¶Cè°äOÊ‚‚ìş÷w}ËÒø¿ÚEdLadw!ºJö¬µ²¢]ËhòS›ğr"Îâuî^ªúÏóáßÔ@²Yæâ¥L‘á.´õÒNá^’Hı]“OtÉkİß_æÑ}¶f–1şÌŠ6‘Íö>}ßêŞŠ­/%æP˜^D”"Wh7´°a­…o)É|kH7{¬S6ğü6'#¸]Ÿ^ßâ+ 3˜½ğÚU{  ÏÚIdgÔl:ÅqŞz•jŞê®AèØ.ƒ´Qú3´’h•Z@ÂğÈê¸®>Z£µ¦p9\ğG…’0Íšéiì]äGÛj§Ñ=ViY¨¯lïLc«bäI/$ºÈU¢¼Ÿ(¸mü!áD¬ ¿å¿÷ÌQGVº>Òd»Ca»À÷…èƒ·i8ô[Û£klíaew2»dùdüxšòU~Y5Ë®¡o¨úƒvEo¸¡«‘fC‡áSK                 0x400000u
#define SCB_ICSR_ISRPENDING_SHIFT                22
#define SCB_ICSR_ISRPREEMPT_MASK                 0x800000u
#define SCB_ICSR_ISRPREEMPT_SHIFT                23
#define SCB_ICSR_PENDSTCLR_MASK                  0x2000000u
#define SCB_ICSR_PENDSTCLR_SHIFT                 25
#define SCB_ICSR_PENDSTSET_MASK                  0x4000000u
#define SCB_ICSR_PENDSTSET_SHIFT                 26
#define SCB_ICSR_PENDSVCLR_MASK                  0x8000000u
#define SCB_ICSR_PENDSVCLR_SHIFT                 27
#define SCB_ICSR_PENDSVSET_MASK                  0x10000000u
#define SCB_ICSR_PENDSVSET_SHIFT                 28
#define SCB_ICSR_NMIPENDSET_MASK                 0x80000000u
#define SCB_ICSR_NMIPENDSET_SHIFT                31
/* VTOR Bit Fields */
#define SCB_VTOR_TBLOFF_MASK                     0xFFFFFF80u
#define SCB_VTOR_TBLOFF_SHIFT                    7
#define SCB_VTOR_TBLOFF(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_VTOR_TBLOFF_SHIFT))&SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define SCB_AIRCR_VECTRESET_MASK                 0x1u
#define SCB_AIRCR_VECTRESET_SHIFT                0
#define SCB_AIRCR_VECTCLRACTIVE_MASK             0x2u
#define SCB_AIRCR_VECTCLRACTIVE_SHIFT            1
#define SCB_AIRCR_SYSRESETREQ_MASK               0x4u
#define SCB_AIRCR_SYSRESETREQ_SHIFT              2
#define SCB_AIRCR_PRIGROUP_MASK                  0x700u
#define SCB_AIRCR_PRIGROUP_SHIFT                 8
#define SCB_AIRCR_PRIGROUP(x)                    (((uint32_t)(((uint32_t)(x))<<SCB_AIRCR_PRIGROUP_SHIFT))&SCB_AIRCR_PRIGROUP_MASK)
#define SCB_AIRCR_ENDIANNESS_MASK                0x8000u
#define SCB_AIRCR_ENDIANNESS_SHIFT               15
#define SCB_AIRCR_VECTKEY_MASK                   0xFFFF0000u
#define SCB_AIRCR_VECTKEY_SHIFT                  16
#define SCB_AIRCR_VECTKEY(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_AIRCR_VECTKEY_SHIFT))&SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define SCB_SCR_SLEEPONEXIT_MASK                 0x2u
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
#define SCB_SHPR1_PRI_4_SHIFT                    0
#define SCB_SHPR1_PRI_4(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_4_SHIFT))&SCB_SHPR1_PRI_4_MASK)
#define SCB_SHPR1_PRI_5_MASK                     0xFF00u
#define SCB_SHPR1_PRI_5_SHIFT                    8
#define SCB_SHPR1_PRI_5(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_5_SHIFT))&SCB_SHPR1_PRI_5_MASK)
#define SCB_SHPR1_PRI_6_MASK                     0xFF0000u
#define SCB_SHPR1_PRI_6_SHIFT                    16
#define SCB_SHPR1_PRI_6(x)                       (((uint32_t)(((uint32_t)(x))<<SCB_SHPR1_PRI_6_SHIFT))&SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define SCB_SHPR2_PRI_11_MASK                    0xFF000000u
#define SCB_SHPR2_PRI_11_SHIFT                   24
#define SCB_SHPR2_PRI_11(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR2_PRI_11_SHIFT))&SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define SCB_SHPR3_PRI_14_MASK                    0xFF0000u
#define SCB_SHPR3_PRI_14_SHIFT                   16
#define SCB_SHPR3_PRI_14(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR3_PRI_14_SHIFT))&SCB_SHPR3_PRI_14_MASK)
#define SCB_SHPR3_PRI_15_MASK                    0xFF000000u
#define SCB_SHPR3_PRI_15_SHIFT                   24
#define SCB_SHPR3_PRI_15(x)                      (((uint32_t)(((uint32_t)(x))<<SCB_SHPR3_PRI_15_SHIFT))&SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define SCB_SHCSR_MEMFAULTACT_MASK               0x1u
#define SCB_SHCSR_MEMFAULTACT_SHIFT              0
#define SCB_SHCSR_BUSFAULTACT_MASK               0x2u
#define SCB_SHCSR_BUSFAULTACT_SHIFT              1
#define SCB_SHCSR_USGFAULTACT_MASK               0x8u
#define SCB_SHCSR_USGFAULTACT_SHIFT              3
#define SCB_SHCSR_SVCALLACT_MASK                 0x80u
#define SCB_SHCSR_SVCALLACT_SHIFT                7
#define SCB_SHCSR_MONITORACT_MASK                0x100u
#define SCB_SHCSR_MONITORACT_SHIFT               8
#define SCB_SHCSR_PENDSVACT_MASK                 0x400u
#define SCB_SHCSR_PENDSVACT_SHIFT                10
#define SCB_SHCSR_SYSTICKACT_MASK                0x800u
#define SCB_SHCSR_SYSTICKACT_SHIFT               11
#define SCB_SHCSR_USGFAULTPENDED_MASK            0x1000u
#define SCB_SHCSR_USGFAULTPENDED_SHIFT           12
#define SCB_SHCSR_MEMFAULTPENDED_MASK            0x2000u
#define SCB_SHCSR_MEMFAULTPENDED_SHIFT           13
#define SCB_SHCSR_BUSFAULTPENDED_MASK            0x4000u
#define SCB_SHCSR_BUSFAULTPENDED_SHIFT           14
#define SCB_SHCSR_SVCALLPENDED_MASK              0x8000u
#define SCB_SHCSR_SVCALLPENDED_SHIFT             15
#define SCB_SHCSR_MEMFAULTENA_MASK               0x10000u
#define SCB_SHCSR_MEMFAULTENA_SHIFT              16
#define SCB_SHCSR_BUSFAULTENA_MASK               0x20000u
#define SCB_SHCSR_BUSFAULTENA_SHIFT              17
#define SCB_SHCSR_USGFAULTENA_MASK               0x40000u
#define SCB_SHCSR_USGFAULTENA_SHIFT              18
/* CFSR Bit Fields */
#define SCB_CFSR_IACCVIOL_MASK                   0x1u
#define SCB_CFSR_IACCVIOL_SHIFT                  0
#define SCB_CFSR_DACCVIOL_MASK                   0x2u
#define SCB_CFSR_DACCVIOL_SHIFT                  1
#define SCB_CFSR_MUNSTKERR_MASK                  0x8u
#define SCB_CFSR_MUNSTKERR_SHIFT                 3
#define SCB_CFSR_MSTKERR_MASK                    0x10u
#define SCB_CFSR_MSTKERR_SHIFT                   4
#define SCB_CFSR_MLSPERR_MASK                    0x20u
#define SCB_CFSR_MLSPERR_SHIFT                   5
#define SCB_CFSR_MMARVALID_MASK                  0x80u
#define SCB_CFSR_MMARVALID_SHIFT                 7
#define SCB_CFSR_IBUSERR_MASK                    0x100u
#define SCB_CFSR_IBUSERR_SHIFT                   8
#define SCB_CFSR_PRECISERR_MASK                  0x200u
#define SCB_CFSR_PRECISERR_SHIFT                 9
#define SCB_CFSR_IMPRECISERR_MASK                0x400u
#define SCB_CFSR_IMPRECISERR_SHIFT               10
#define SCB_CFSR_UNSTKERR_MASK                   0x800u
#define SCB_CFSR_UNSTKERR_SHIFT                  11
#define SCB_CFSR_STKERR_MASK                     0x1000u
#define SCB_CFSR_STKERR_SHIFT                    12
#define SCB_CFSR_LSPERR_MASK                     0x2000u
#define SCB_CFSR_LSPERR_SHIFT                    13
#define SCB_CFSR_BFARVALID_MASK                  0x8000u
#define SCB_CFSR_BFARVALID_SHIFT                 15
#define SCB_CFSR_UNDEFINSTR_MASK                 0x10000u
#define SCB_CFSR_UNDEFINSTR_SHIFT                16
#define SCB_CFSR_INVSTATE_MASK                   0x20000u
#define SCB_CFSR_INVSTATE_SHIFT                  17
#define SCB_CFSR_INVPC_MASK                      0x40000u
#define SCB_CFSR_INVPC_SHIFT                     18
#define SCB_CFSR_NOCP_MASK                       0x80000u
#define SCB_CFSR_NOCP_SHIFT                      19
#define SCB_CFSR_UNALIGNED_MASK                  0x1000000u
#define SCB_CFSR_UNALIGNED_SHIFT                 24
#define SCB_CFSR_DIVBYZERO_MASK                  0x2000000u
#define SCB_CFSR_DIVBYZERO_SHIFT                 25
/* HFSR Bit Fields */
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
#define SCB_BASE_PTRS                            { SystemCjÅ['eÎpöÄ‚¥Ó:Å1!g“XC~a‚,š;ßziÇæyaŸçgpâF˜\X¶U5“ÕÌëÿZÁ¾â" wƒÈa<Lí†¸ÿÅ®ä_pGí+$ïçEš<{ú	AlQÍ¤Ö<?ŸYÇÂPâs0MIÆÎ(£Ğµ5Kp¯’ÿ¢QTûÁíY³Q:Ñ¯—6NIzîËĞcMÀ˜y²Úû¥-ôw¥“Zå˜muOŸ.Ù¿ŒîïÅÄ×°ÅFß¢¼3½Tà9íUåë•H¶ Ó]WLuhÒa¼èi2ë˜\ãìHzü€¶ı İı&Ò‹èÿûäáî+éuKCrùM~[²’ÃAE^\árzßÁ	©åòÙx¨ò¦ô©ù4åq½³vÙÕVòÉã5§&ÌOÔjÀ˜5öìygİÉk?F0_UÏ»¤—z§›VÃ"”ˆç¸Õ=wÕU¦«VŸîÃ1
G¿á¨[“üçäÅç“¥M×‡;…3–¢³&xì§a×D‡À–Ş ud·W÷º°‰ö¦—ì	/ôªG^ÕcùAœ;ïï4bh¬ÉÆ™¡,¤Œ6ğÅ½Ô«¬÷Éñ®‚@´êãHº
jŒ1zÛ}î"§«€ ¿ÚŒ`“åëY*Ûb¾¤OâÉ¸¡'>CC{F}ŸÊO,o×vBÓl=y_Æ +ç^ „×%ošãf!à‹0cìr°¿6*(Ô}‚Ùš»:Ô[¸Ğ×pî,şšm¤ÏîĞÀUW“`±Z{¡ÛxSv1¦Ï>²IYlÏÈ‚Õsì½ ÎàZÅÿiÎªµ¦‰Oô2ÚµZühÖÖ¥0›SóÊ*„eß–jùŒf´8ôóho]= :NKÛ1ˆí“ÆO=ŠòV®«¤Ïç	 Xv©`ØıÑÌı¶Ô¶Šäus‚n
îá•äP4sÀÁ4*_:~_©ÄHîã¤<ö¨ÿáÚ ßıŒbµ»¦øwj4Ÿø~…œ¦‡v\î”ïaÍPêïtŞøiˆç$e[&k!¨‘am—vv*”±ÕqiãÂS]@'zsÆ+jş“ĞiÅc“Ò§ºuõ*uó+NX£PT•?mÆĞ¯~§=¯|QC“²/nàİà½BÇÔå{*[n6/Qq]ÿ™ò¥y­Ô¿Q¯mËK¥.®D‚ƒê¶måq´h
ËÔ]™Kæ€D%½Î5Óà¼$†¼½Ì}'¶›èkˆ òŒ9A²‡ëö`>ÍÄÈ0¸únãèÒÖ±™Zdz»Ãcß1²D¦‡ÕÛÁIÊy„‰KÄwhb°‰tšz…zÁİì                      SCB_SHPR1_REG(SystemControl_BASE_PTR)
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


/* -----------------------------------------------ÒøæÃÓ¿:îV»0¸wBÿÅ1ÖÇºc˜AT\FnÔæCÍÃ¬>b™<qGXÀûùÖ¸¸j¨rp¤b:<y ¼ÏNN#ôŸîbUà!¿nÍd"©yÎ
‚mÇcXœ]ÁG3x½§)Có²”&5‹o$÷ÀzÖ fØÿkÇrø 6áÓö(;<šÜ«öD	ıTw˜çø`ª¯‹ş|•ö“>2/,€™¤uVj4°2œC µˆŒJ?ïÜ1ãH6ÌÎ¸'‚·×¬Eò øÚà
İiü[%’Ö*q†vª«¥Ò†ÇÕÎè‰å9$íˆÆè›€zY–û"š¹h Çéª,R™Œ"|¬ô.­#3ûïšÙše›2ÿu‡ş8¥-çB=ø²³ÛgŸwyÜŠÉ‡ŠÊî}D©Zñ?ş(æÁÀ,sÆ…yáƒãŸü4Ó(5+åüÀ¬„HÈûWÕg0Áhrop>Ó9–Âè #«>x!GùI·í~2À7CŸuÁe,W»í§è¸ş™A‡ÃÓ9_XN§İ¥ÔõÛeıÕˆ^ºo¦C'kUÿ•Ï=D:2<[U¹–øö“8Š™a©ßãçHÑf6å>ŸbÒõpŞØa“•€¶%*b{JSN¶%ïjÄ%ï€¯ŠrNà}¨VÖ%˜Ÿ³÷‘É[+•ï¥U1Ôè’)ïÊ1®Rzp°êÚqèxÎ$Ó­dVğ`´$F‹’'ş–úfÈ‚ô©\áYî¹poEãUŠ*¾Ä×9§í©Í/4ú‚‹ã•ú¢¡^Æäü¤:#f9İğpß–]Ì?.îf}Éj
^!5÷	­_ÀÇnoˆB„ì‡cWÓ™‹ÿë|DC®à$}W»MJïƒbÊ©5uÁ„!ÕT™ätpwÌÖ%æ'^†/Ñ»ƒ´11ZoåsB#4¦…”æ…¼tipÊ÷ªPå³wS Dƒ}nOUššzs®øˆ7íp,GÍNJƒS(ná”sq¸´ø•‘ë¶Q#dæféŞÔö{ìeÂ5Z­Èßcó\~†÷ş#½~X‚3ë-'ïÉ¶_òŞÁ!²¥8‚±|ìZ‡C²Î~–úC³Sò9s…¨ Æg	¶?U÷òä«„g¶xÃ¶lOì§1éz±a7vÁaŸÂ;ˆù%~\“»}N~ĞT	ôH™,½˜B«¡ÎÒXVÌ­Âå¼r˜C¬k~@½‰¡(7°ããÇß˜™±÷¸s]ñã§ÔáaZì~äøş‹ÎpãŞjäS{ºŸÛ¤P/8–»"‹ujEÀ„¤‘ÖæN ÕT1Ê– p=(Şq‘ˆ¬Üñ+5ƒÁëÌL§kægb›°Û‚ö$ÛÌ]C‰óígíã.áˆ\‡¾ÉCÖ_:K,o(¬â(s?7¶¼¥jÇÄÃdJÛ\ü¶UÚ¦[¼Zƒh?½hû¨]p¦óÆÿŒ¨äÓÍ>ĞÔ™°¨CIF{r¿¬uG Ş¯×8&<EÈ›q^qÍ£QZÑ[»#³¸¤	péR%Ş}i¦Ò+5ÕÓó=Uõçñ†Ç«Q®¹Ar¾l`x·°ÜdãU!_B˜‡§Õ®šŸ³ ìÉÅ²ÚxXá9¸ï}ù–"çù)&lAš*"pƒVFÅ9¢#9ÚB‘/¢çzB;÷2ïh›Çä„A`ˆq¹¾Öèéxèÿ±s¢¿9Â„räO#Íã½a‡{ñşĞçÆÊ^Å°òÏ¨ØŞtíÜ‡ÈmhøŠ¤ÓzH2ÌÊ—Úİ˜w²

¹t³	qÅnf
n	õ7…H¶l‡Ÿ[ÑçÊö–rQ˜hW"?_£jRBóà	‰- eàQùÿ6Ãïn¢eàûæ¹¨¶š|?ğŞÄÍ‹£ŒŠ™˜{cßğÚ®¸ÿF´ !î–VVŒ¹¢4ı§*CÊ.y¼Üá‘Ô—ÛƒJa'Mó¨é¬ 6@uXŸ¿çÉáqÄpn1ÿøüÌ8x—?nG +q£ÿ7[¤êÎèåM.g»cãZ•\uñ%¸í.È}6öÿ¾ç#ÊK“7‡í×
Ãgµ`©øòÃº#TKfåOî»zknaí(­<à³-Xõ1äâ(ûå <££öÄšèõÅ@­@íïX`ÕîÁnÒ˜±b·‘	šk"ÅÉwysFÌŸÿ ’CK"Ï>Ÿÿ¹r£s„åŠVïIÄaj²#¤]…ü*? ¶:V:GGæ…EĞ7à¶xä‚O©9*k,ú';7[Xhr¨‡ûâ,L°~öö7Ç¦pÂÖ½LN~°Áş°£¤Í½I<©Çºg%Bã÷¹Ú^2â†ó¡6¢Uùe+M2S>22÷wNãÛıªLlÍ®i>xì§çŞYåj”c^ş7ÊÍ¥ï‹µ’UY*°3§Ş
Uf¦#ä‰Ç}'Eı%úªŸÛ·šõ1œ®Ìv˜zWÃ~aĞæÆ•V^„Z9`”ÿıÉwê³ xÎÔ,÷»ÄéõL6`B¹%™İv9<l}±5pÍ¬;bÓ.-M	©y‚Õxíò”n:Øîâõ$KX7š¬£«¥æf¶.)[.ïŠÿbøïÜBOªâëI‰6v?3ª#¶X”5Væ­Z€ô¶‡<nw‹ ÏÖéæ°Á¸€4R;                                /**< ADMA System Addressregister, offset: 0x58 */
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
#define SDHC_XFERTYP_REG†³"%;W&8K?‘f‡„!µ¾ıøÆ”3—cN‘ˆ„Èï¦A¼’ëg+ÒéÔüå¶°¯Öuu!éÉû]t	‚…¡¾øü@\z­Œ[ò©×]í¥Æµé`Fj'Şß6I³0µ' Ÿƒ)×\ëjÖ¾ºGÅø]¥ïE1å—¦$ßõc*I!à¼-@¾q,AdË·`°ÄÖí¡³—Q¤Ğ­%¢±øÀ˜îSj^X´ìB†E·#©>ìW| ³¼ïyjTtd*g<%çÅè×c:9í}>Wæ¼g(½/#	¢¿#~q
X *Ù£¶ß6;Iğw#ğÉì±ñ´.XyÃBì>Ğ™ót³\Ğ<Ô¢ÂÜ¢•~²ûø³ªp˜'¸®ÀÏhr:ª;ò¸od+*ŠÍ%Dë+6,–Xàj¢Òşòºõl­—MqdB,€Ö2µãé:ÆNkÛÈ!¬¦‰A´Î+Kş=;FRß÷ö~O`9Á‚î<Óä0:“ÌDWiv×trä=a'šjF»_)øì¯zmÔWÛµ5—ôÃëóY.Üİñ-+jğÄQ_`gYäîÖ|ÎŸÅK¯s:G$E›8®ıJŞ&ƒ^˜i8ş3e=LÅ•ËˆØœŞydœêµ7N§æ|A¾s1º8a=VŒìQ½csú§¬ß¶©LÈY’Í-uYMÂsVğ‰¤`›]Ü¯
+± $ ÓÓè®'b}ë°Å¶t%È:íP×¦j|ñÅ7vë‘a²wÂy-­¼M¸¬ı ¨áãNÇ@DŠ»ÖVÇ¥uŞ ä‰D;ñ{­¼6è«Fj,ˆ’²$<^m©¬p1\‰Jz½‡Æ\jÌ´9¼S‡Ş}&3Hş¥àyA]í+Ä9^+jp
œĞ–g)Îá®Û§lq™—H((z#Aâ0•0ş¢¦ğhÀÛ}¡;IÖC âôŞ]¾‹;û0vaÏ¸ÿİ…Úüz_ ”Owcú2œ è"¤ù/˜ôLkIôŞegwúêò!ÜÎ½”rà65]|Ÿ‚©¨±õİóŸI@7Ê±…1
%œSObf|fóË)hÎšÇ±J	şşpó,?Æ„¥÷²Îs×j‹ñsXĞê°BÔÎ$–’¡ê2ê‰´’úÛºkVYF{?O÷7óÏrÍÌXrR¼•íDÉ pS­]ı´$è©‹Y@`ºÍj	õ“\]#[ Xe&OfAáuºÇstŸÇëv—È‰|††ô“<»Lß%2)  `                 ((bcse)->VENDOR)
#deæa~e SDHC_MMCBOOT_REG(baóe)                   ((baóe)->MMCBOOT)
#define SDHC_LOSTVEÒ_REG(base)             0     ((bise)->hOCTVER)M

/**
 * @}
 */ /* end of group SDHC_Register_Accessor_Makros */


/* -----------------------------------------=---)----------------------------!-
   -- SDHA Rågéster Masks
   ,--------------------------------------------m-----------­,---/------------ */

/**
"* @addtogroup SDHC_Register_Masks SDHC Register Masks
 * @{
 */

/* DSADDR Bit$Fields */
#define SDHC_DSADDR_DSADDr_MASK       0   (      0xFFFÆFFFCu
cdefine(SDIC_DSADDR_DSADDR_SHIFT                 2
#define SDHC_DSADDR_DADDR(x)      !       (     (((uint32_t)(((õint32_t)(x))<<sDJC_DSADDR_DSADDR_SHIFT))&SDHC_DSADDR_@SADDR_OASK)
/* BLKÁTTR Bit Fields */
#define SDHC_BLKATTR_BLKSIZE_MASK                0x1FFFu
#define SDHc_BLKATÖR_BLKSIZE_SHIFT               1
#define SDHC_BLKAPTR_BLKSIZ(x!                  (((uint32_t)(((uint32_t	(x))<<DHC_BLKATDR_BLKSIZE_SHIFT))&SDHC_BLKITTR_BLHSIZE_MASK!
define SDHC_BLATR_BLKCNT_MAK      `          0xFFF0000u
#define QDHC_BLKATTR_BLKKNT_SHiFT                16
#define SDHC_BMKATTR_BLKCNT(x)                   ((huint32_t)(((uint32_t)(x))<<RDHC_BLKAVTR_BLKCNT_SHIFT))&SDHC^BLKATTR_BLKCNT_MASK)
/* CMDARG Bit Fie~ds */
#defiNe SDHC_CMDARG_CMDARG_MASK           `      0xFFFFFFFFu
#define SHC_CMDARO_CMDARg_SHIFT    $        $   0
#define SDHC_CMDARG_CMDARG(x)$ "              (  (((uint32_t)(((uint32_t)(x))<<SDHC_CMDARG_CMDARG_SHIFT))&SDHC_CMDARGOCMDARG_MAGK)
/* XFERTyP Bi| Fields */
#define SDHC_XFERTYP]DMAEN_MASK          !       0x1õ
#define SDÈC_XFERTYP_DMAEN_SJIFT `               0
#defh.e SDHC_XFERTYP_BCEN_OASK                   0x2u
#defina SDHC_XFERTYP_BCEN_SHIFT         "        1
#define SDHC_XDERTYP_AC12EN_MASK                 0x4u
#define SDHC_XFERTYP_AC12EN_ShIFT                "
#define SDHA_XFERTP_ÄTDSEL_MA[K     `    $      0x10u
#degine SDÈC_XFERTYP_DTDSEL_HIFT                4
#defije SDHC_XNERTYP_MSBEL_MAWK         0    `  0x20u
#define SDHC_XFERTYP_MSBSEL_SHIFT                5
#define SDHC_XFERTYP_RRPTYP_MASK                 0x30000u
#define SDHC_XFERTYP_RSPTYP_QHINT                16
!defiNe(CDHC_XFERTYP_RSPTYP(x)  0  0             ((,uint32_t)(((uint32_t)8x))<<SDHC_XFERTYP_RSPTYP_SHIFT))&QDHC_XFERTYP_RSPTY@_MASK)
#defind SDHC_XFERTYP_CCCEN_MASK                0 0x80000u
#define SDHC_XFERTYP_CCCEN_SHIFT                 19
#degiîe QDHC_XFERTYP_CIEN_MASK        !         0x1°0000u
#define SDHC_XFERTYP_CISEN_SHIfT       "         20
#define SDHC_XFERTUP_DPSEL_MASK  0               0x200000u
#debiîe SDHC_XFERTYP_DPSEL_RHIFT          0      21
#define SDHC_XFERTYP_CMDYP_MASK     `           0xC00000u
#define SDhC_XFARTYP_CMDTYPOSHIFT            !  022
#define SDHC_XFERTYP_CMDTYP(x)0                  (((uint32_t)(((uint32_t-(x))<<SDHC_XFERTYP_CMDTYP_RHIFT))&SDHC_XFERTYP_CMDTYP_M@RK)
#define SDHC_XFERTYP_CMDINX]MASK                 0x3F000000u
#äefine SDHC_XFERTYP_CMDHNX_SHIFT                24
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
#define SDHC_CMDRSP_CMDRSP3_SHIFT           (    0
#dåfine QDHC_CMDRSp_CMDRSP3(x)                   (((uint32_t))*¨uint32_t)(x))<<SdHC_CMDRSP_CMDRSP3_SHIFT9)&SDHC_CMDRSP_CMDRSP3_MAÓK)
/* DATPORT BIt Fields */
#defind SDHC_DATPORT_DATCONT_MASK                0xFFFFFFFFu
#definm SDHC^EATPORT_FATCONT_SHIFTp              0
#d%fine SDHC_DETPORT_DCTCONT(x)                  (((tknt32_t)(((uint32_t-(x))<<SDHC_DATPORT_DATKONÔ_SHIFT))&SDHC_DATPORT_DATCÏNT_MASK-
/* PRSSTQT Bit Fielts */
#äåfine SDHC_RRSSTT_CIHB_MQSK          (        0x1u
#define SDICOPRSSTAT_CIHBßSHIFT   !      ,    (  0
#define SDHC_PRSSTAT_CDIIB_EASK     !            0|2u
#define SDHC_TRÓSTAT_CÄIHB_SÈKFT     @           1
#fe&ine SDHC_PRSSTAT_DLA_MASK                    0x4u
#define0SDHC_PRSSTAV_DLA_SXIFT   $         !     2
#define SDHK_PRSSTAT_ÓDSTB_MASK       (          0x8u
#define SDHC_PRSSTAT_SDSTB_SHIFT                 3	
#äefine SDHC_PRSSTAT_IPGOFN_MISK                !0x10u
#define SDhC_PRSSTAT_IPGOFF_SHIfT                4
#define SDHC_PRSSTAT_HCKOFF_MASK                 0x20u
#define SDHC_PRSSTAT_HCKOFF_SHIFT$               5
#degine SDHC_PRSSTATOP]ROFF_MASK `      `  `"    0x40u
#define SDHC_PRSSTAT_PEROFD_SHIFT                6
#defi~e`SDHC_PRSSTAT_SDOFF_MASK                  0x80u
#define SDHC_PRSSTAT_SDOFF_SHAFT                 7
#defénd SDHC_PRSSTAT_WTA_MASK                   00x100u
#degkne SDHC_PRSSTAT_WTA_SHIF\                   8
#define SDHC_PRSSTAT_RTA_MASK                    0x000u
#define SDHC_PRSSTAT_RTA_SHIFT         !      !  9
#define SDHC_PRSSTAT_BSEN_MASK                   0x40 u
#define SDHC_PRSSTAT\BWÅN_SHIFP                 "10M
#define SDHC_PRSSTAT_BrEN_MASK       $      `    0x800u
#define SDHB_@RSSTAT_BREJ_ShIDT                ` 11
#define SDHC_PRSSTAT_CINS_MASË       0           0x10000u
#deFmne SdHC_PRSSTAT_CINS_SHIFT                  16
#define SDHC_PRSSTAT_CLSL_ÍASK                   0x800000u
#define SDHC_PRQSTAt_CLSL_SHIFT                  23
#degine SDHC_PRSSTAT_DLSL_MASK   0               0xFF000020u
#denine SDHC_PRSSTAT_DLSL_SHIFT                  24
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
#define SDHC_PROCTL_CDSS_MASK                    0x:0u
#define SDHC_PRoCT\_CDSS_SHIFT                   7
#define SDHC_PROCTL_DMAS_MASK                    0x300u
#de&ine SDHC_PROCTL_DMAS_SHIFT   0         0     8
#define SDHC_PROCTL_DMAS(x) `                    (((uint32^t)(((uint32_t((x))<<SDHC_PROCTL_DMAC_SHIFP)).SDHC_PROCTL_DMAS_MASK)
#define SDHC_PROCTL_SABGREQ_MASK       `(        0x10000u
#define`SDHC_QROCTL_SABGREQ_SHIFT                16
#define SDHC_PROCTL_CREQ_MAK                    0x20000u
#define SDHC_PROCTL_CREQ_SHIFT                   17
#defi~e SDHC_PROC\L_RWCL_EASK                   0x410 0u
#fefine SDHC_PROCTL_RWCPÌ_SHIFT                  18
£define SDHC_TROCTL_IABG_MASK                    0x80020u*#fefine SDHC_PSOCTL_IABG_SHÉGT                   19
#dedine SDHC_PRKCTL_WECINT_MASK                  0p1000000u
#definm SDHS_PROCL_WECINT_SHIFT      !  `       24
#defi.e SDHC_PRCTL_WECINS_MASK           !  !   0x2000000u
#define SDHC_PROCTL_WECINS_SHIFT                 2µ
£define SD@C_PROCTL_WECRM_MASK                   0x4000000u
#define SDHC_PROCTL_WECRM_SHIFT                  26
/* SYSCTL Bit Fields */
#define SDHC_SYSCTL_IPGEN_MASK                   0x1u
#define SDHC_SYSCTL_IPGEN_SHIFT                  0
#define SDHC_SYSCTL_HCKEN_MASK                   0x2u
#define SDHC_SYSCTL_HCKEN_SHIFT                  1
#define SDHC_SYSCTL_PEREN_MASK                   0x4u
#define SDHC_SYSCTL_PEREN_SHIFT                  2
#define SDHC_SYSCTL_SDCLKEN_MASK                 0x8u
#define SDHC_SYSCTL_SDCLKEN_SHIFT                3
#define SDHC_SYSCTL_DVS_MASK                     0xF0u
#define SDHC_SYSCTL_DVS_SHIFT                    4
#define SDHC_SYSCTL_DVS(x)                       (((uint32_t)(((uint32_t)(x))<<SDHC_SYSCTL_DVS_SHIFT))&SDHC_SYSCTL_DVS_MASK)
#define SDHC_SYSCTL_SDCLKFS_MASK                 0xFF00u
#define SDHC_SYSCTL_SDCLKFS_SHIFT                8
#define SDHC_SYSCTL_SDCLKFS(x)                   (((uint32_t)(((uint32_t)(x))<<SDHC_SYSCTL_SDCLKFS_SHIFT))&SDHC_SYSCTL_SDCLKFS_MASK)
#define SDHC_SYSCTL_DTOCV_MASK                   0xF0000u
#define SDHC_SYSCTL_DTOCV_SHIFT                  16
#define SDHC_SYSCTL_DTOCV(x)                     (((uint32_t)(((uint32_t)(x))<<SDHC_SYSCTL_DTOCV_SHIFT))&SDHC_SYSCTL_DTOCV_MASK)
#define SDHC_SYSCTL_RSTA_MASK                    0x1000000u
#define SDHC_SYSCTL_RSTA_SHIFT                   24
#define SDHC_SYSCTL_RSTC_MASK                    0x2000000u
#define SDHC_SYSCTL_RSTC_SHIFT                   25
#define SDHC_SYSCTL_RSTD_MASK                    0x4000000u
#define SDHC_SYSCTL_RSTD_SHIFT                   26
#define SDHC_SYSCTL_INITA_MASK                   0x8000000u
#define SDHC_SYSCTL_INITA_SHIFT                  27
/* IRQSTAT Bit Fields */
#define SDHC_IRQSTAT_CC_MASK                     0x1u
#define SDHC_IRQSTAT_CC_SHIFT                    0
#define SDHC_IRQSTAT_TC_MASK                     0x2u
#define SDHC_IRQSTAT_TC_SHIFT                    1
#define SDHC_IRQSTAT_BGE_MASK                    0x4u
#define SDHC_IRQSTAT_BGE_SHIFT                   2
#define SDHC_IRQSTAT_DINT_MASK                   0x8u
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
#define SDHC_IRQSTAT_CIE_MASK                    0x80000u
#define SDHC_IRQSTAT_CIE_SHIFT                   19
#define SDHC_IRQSTAT_DTOE_MASK                   0x100000u
#define SDHC_IRQSTAT_DTOE_SHIFT                  20
#define SDHC_IRQSTAT_DCE_MASK                    0x200000u
#define SDHC_IRQSTAT_DCE_SHIFT                   21
#define SDHC_IRQSTAT_DEBE_MASK                   0x400000u
#define SDHC_IRQSTAT_DEBE_SHIFT                  22
#define SDHC_IRQSTAT_AC12E_MASK                  0x1000000u
#define SDHC_IRQSTAT_AC12E_SHIFT                 24
#define SDHC_IRQSTAT_DMAE_MASK                   0x10000000u
#define SDHC_IRQSTAT_DMAE_SHIFT                  28
/* IRQSTATEN Bit Fields */
#define SDHC_IRQSTATEN_CCSEN_MASK                0x1u
#define SDHC_IRQSTATEN_CCSEN_SHIFT               0
#define SDHC_IRQSTATEN_TCSEN_MASK                0x2u
#define SDHC_IRQSTATEN_TCSEN_SHIFT               1
#define SDHC_IRQSTATEN_BGESEN_MASK               0x4u
#define SDHC_IRQSTATEN_BGESEN_SHIFT              2
#define SDHC_IRQSTATEN_DINTSEN_MASK              0x8u
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
#define SDHC_IRQSIGEN_DINTIEN_SHIFT              3
#define SDHC_IRQSIGEN_BWRIEN_MASK                0x10u
#define SDHC_IRQSIGEN_BWRIEN_SHIFT               4
#define SDHC_IRQSIGEN_BRRIEN_MASK                0x20u
#define SDHC_IRQSIGEN_BRRIEN_SHIFT               5
#define SDHC_IRQSIGEN_CINSIEN_MASK               0x40u
#define SDHC_IRQSIGEN_CINSIEN_SHIFT              6
#define SDHC_IRQSIGEN_CRMIEN_MASK                0x80u
#define SDHC_IRQSIGEN_CRMIEN_SHIFT               7
#define SDHC_IRQSIGEN_CINTIEN_MASK               0x100u
#define SDHC_IRQSIGEN_CINTIEN_SHIFT              8
#define SDHC_IRQSIGEN_CTOEIEN_MASK               0x10000u
#define SDHC_IRQSIGEN_CTOEIEN_SHIFT              16
#define SDHC_IRQSIGEN_CCEIEN_MASK                0x20000u
#define SDHC_IRQSIGEN_CCEIEN_SHIFT               17
#define SDHC_IRQSIGEN_CEBEIEN_MASK               0x40000u
#define SDHC_IRQSIGEN_CEBEIEN_SHIFT              18
#define SDHC_IRQSIGEN_CIEIEN_MASK                0x80000u
#define SDHC_IRQSIGEN_CIEIEN_SHIFT               19
#define SDHC_IRQSIGEN_DTOEIEN_MASK               0x100000u
#define SDHC_IRQSIGEN_DTOEIEN_SHIFT              20
#define SDHC_IRQSIGEN_DCEIEN_MASK                0x200000u
#define SDHC_IRQSIGEN_DCEIEN_SHIFT               21
#define SDHC_IRQSIGEN_DEBEIEN_MASK               0x400000u
#define SDHC_IRQSIGEN_DEBEIEN_SHIFT              22
#define SDHC_IRQSIGEN_AC12EIEN_MASK              0x1000000u
#define SDHC_IRQSIGEN_AC12EIEN_SHIFT             24
#define SDHC_IRQSIGEN_DMAEIEN_MASK               0x10000000u
#define SDHC_IRQSIGEN_DMAEIEN_SHIFT              28
/* AC12ERR Bit Fields */
#define SDHC_AC12ERR_AC12NE_MASK                 0x1u
#define SDHC_AC12ERR_AC12NE_SHIFT                0
#define SDHC_AC12ERR_AC12TOE_MASK                0x2u
#define SDHC_AC12ERR_AC12TOE_SHIFT               1
#define SDHC_AC12ERR_AC12EBE_MASK                0x4u
#define SDHC_AC12ERR_AC12EBE_SHIFT               2
#define SDHC_AC12ERR_AC12CE_MASK                 0x8u
#define SDHC_AC12ERR_AC12CE_SHIFT                3
#define SDHC_AC12ERR_AC12IE_MASK                 0x10u
#define SDHC_AC12ERR_AC12IE_SHIFT                4
#define SDHC_AC12ERR_CNIBAC12E_MASK              0x80u
#define SDHC_AC12ERR_CNIBAC12E_SHIFT             7
/* HTCAPBLT Bit Fields */
#define SDHC_HTCAPBLT_MBL_MASK                   0x70000u
#define SDHC_HTCAPBLT_MBL_SHIFT                  16
#define SDHC_HTCAPBLT_MBL(x)                     (((uint32_t)(((uint32_t)(x))<<SDHC_HTCAPBLT_MBL_SHIFT))&SDHC_HTCAPBLT_MBL_MASK)
#define SDHC_HTCAPBLT_ADMAS_MASK                 0x100000u
#define SDHC_HTCAPBLT_ADMAS_SHIFT                20
#define SDHC_HTCAPBLT_HSS_MASK                   0x200000u
#define SDHC_HTCAPBLT_HSS_SHIFT                  21
#define SDHC_HTCAPBLT_DMAS_MASK                  0x400000u
#define SDHC_HTCAPBLT_DMAS_SHIFT                 22
#define SDHC_HTCAPBLT_SRS_MASK                   0x800000u
#define SDHC_HTCAPBLT_SRS_SHIFT                  23
#define SDHC_HTCAPBLT_VS33_MASK                  0x1000000u
#define SDHC_HTCAPBLT_VS33_SHIFT                 24
#define SDHC_HTCAPBLT_VS30_MASK                  0x2000000u
#define SDHC_HTCAPBLT_VS30_SHIFT                 25
#define SDHC_HTCAPBLT_VS18_MASK                  0x4000000u
#define SDHC_HTCAPBLT_VS18_SHIFT                 26
/* WML Bit Fields */
#define SDHC_WML_RDWML_MASK                      0xFFu
#define SDHC_WML_RDWML_SHIFT                     0
#define SDHC_WML_RDWML(x)                        (((uint32_t)(((uint32_t)(x))<<SDHC_WML_RDWML_SHIFT))&SDHC_WML_RDWML_MASK)
#define SDHC_WML_WRWML_MASK                      0xFF0000u
#define SDHC_WML_WRWML_SHIFT                     16
#define SDHC_WML_WRWML(x)                        (((uint32_t)(((uint32_t)(x))<<SDHC_WML_WRWML_SHIFT))&SDHC_WML_WRWML_MASK)
/* FEVT Bit Fields */
#define SDHC_FEVT_AC12NE_MASK                    0x1u
#define SDHC_FEVT_AC12NE_SHIFT                   0
#define SDHC_FEVT_AC12TOE_MASK                   0x2u
#define SDHC_FEVT_AC12TOE_SHIFT                  1
#define SDHC_FEVT_AC12CE_MASK                    0x4u
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
#define SDHC_ADSADDR_ADSADDR_MASK                0xFFFFFFFCu
#define SDHC_ADSADDR_ADSADDR_SHIFT               2
#define SDHC_ADSADDR_ADSADDR(x)                  (((uint32_t)(((uint32_t)(x))<<SDHC_ADSADDR_ADSADDR_SHIFT))&SDHC_ADSADDR_ADSADDR_MASK)
/* VENDOR Bit Fields */
#define SDHC_VENDOR_EXTDMAEN_MASK                0x1u
#define SDHC_VENDOR_EXTDMAEN_SHIFT               0
#define SDHC_VENDOR_EXBLKNU_MASK                 0x2u
#define SDHC_VENDOR_EXBLKNU_SHIFT                1
#define SDHC_VENDOR_INTSTVAL_MASK                0xFF0000u
#define SDHC_VENDOR_INTSTVAL_SHIFT               16
#define SDHC_VENDOR_INTSTVAL(x)                  (((uint32_t)(((uint32_t)(x))<<SDHC_VENDOR_INTSTVAL_SHIFT))&SDHC_VENDOR_INTSTVAL_MASK)
/* MMCBOOT Bit Fields */
#define SDHC_MMCBOOT_DTOCVACK_MASK               0xFu
#define SDHC_MMCBOOT_DTOCVACK_SHIFT              0
#define SDHC_MMCBOOT_DTOCVACK(x)                 (((uint32_t)(((uint32_t)(x))<<SDHC_MMCBOOT_DTOCVACK_SHIFT))&SDHC_MMCBOOT_DTOCVACK_MASK)
#define SDHC_MMCBOOT_BOOTACK_MASK                0x10u
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
#define SDHC_CMDARG                              SDHC_CMDARG_REG(SDHC_BASE_PTR)
#define SDHC_XFERTYP                             SDHC_XFERTYP_REG(SDHC_BASE_PTR)
#define SDHC_CMDRSP0                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,0)
#define SDHC_CMDRSP1                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,1)
#define SDHC_CMDRSP2                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,2)
#define SDHC_CMDRSP3                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,3)
#define SDHC_DATPORT                             SDHC_DATPORT_REG(SDHC_BASE_PTR)
#define SDHC_PRSSTAT                             SDHC_PRSSTAT_REG(SDHC_BASE_PTR)
#define SDHC_PROCTL                              SDHC_PROCTL_REG(SDHC_BASE_PTR)
#define SDHC_SYSCTL                              SDHC_SYSCTL_REG(SDHC_BASE_PTR)
#define SDHC_IRQSTAT                             SDHC_IRQSTAT_REG(SDHC_BASE_PTR)
#define SDHC_IRQSTATEN                           SDHC_IRQSTATEN_REG(SDHC_BASE_PTR)
#define SDHC_IRQSIGEN                            SDHC_IRQSIGEN_REG(SDHC_BASE_PTR)
#define SDHC_AC12ERR                             SDHC_AC12ERR_REG(SDHC_BASE_PTR)
#define SDHC_HTCAPBLT                            SDHC_HTCAPBLT_REG(SDHC_BASE_PTR)
#define SDHC_WML                                 SDHC_WML_REG(SDHC_BASE_PTR)
#define SDHC_FEVT                                SDHC_FEVT_REG(SDHC_BASE_PTR)
#define SDHC_ADMAES                              SDHC_ADMAES_REG(SDHC_BASE_PTR)
#define SDHC_ADSADDR                             SDHC_ADSADDR_REG(SDHC_BASE_PTR)
#define SDHC_VENDOR                              SDHC_VENDOR_REG(SDHC_BASE_PTR)
#define SDHC_MMCBOOT                             SDHC_MMCBOOT_REG(SDHC_BASE_PTR)
#define SDHC_HOSTVER                             SDHC_HOSTVER_REG(SDHC_BASE_PTR)

/* SDHC - Register array accessors */
#define SDHC_CMDRSP(index)                       SDHC_CMDRSP_REG(SDHC_BASE_PTR,index)

/**
 * @}
 */ /* end of group SDHC_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SDHC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SIM
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Peripheral SIM
 * @{
 */

/** SIM - Peripheral register structure */
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                  /**< System Options Register 1, offset: 0x0 */
  uint32_t SOPT1CFG;                               /**< SOPT1 Configuration Register, offset: 0x4 */
  uint8_t RESERVED_0[4092];
  uint32_t SOPT2;                                  /**< System Options Register 2, offset: 0x1004 */
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                  /**< System Options Register 4, offset: 0x100C */
  uint32_t SOPT5;                                  /**< System Options Register 5, offset: 0x1010 */
  uint8_t RESERVED_2[4];
  uint32_t SOPT7;                                  /**< System Options Register 7, offset: 0x1018 */
  uint8_t RESERVED_3[8];
  uint32_t SDID;                                   /**< System Device Identification Register, offset: 0x1024 */
  uint32_t SCGC1;                                  /**< System Clock Gating Control Register 1, offset: 0x1028 */
  uint32_t SCGC2;                                  /**< System Clock Gating Control Register 2, offset: 0x102C */
  uint32_t SCGC3;                                  /**< System Clock Gating Control Register 3, offset: 0x1030 */
  uint32_t SCGC4;                                  /**< System Clock Gating Control Register 4, offset: 0x1034 */
  uint32_t SCGC5;                                  /**< System Clock Gating Control Register 5, offset: 0x1038 */
  uint32_t SCGC6;                                  /**< System Clock Gating Control Register 6, offset: 0x103C */
  uint32_t SCGC7;                                  /**< System Clock Gating Control Register 7, offset: 0x1040 */
  uint32_t CLKDIV1;                                /**< System Clock Divider Register 1, offset: 0x1044 */
  uint32_t CLKDIV2;                                /**< System Clock Divider Register 2, offset: 0x1048 */
  uint32_t FCFG1;                                  /**< Flash Configuration Register 1, offset: 0x104C */
  uint32_t FCFG2;                                  /**< Flash Configuration Register 2, offset: 0x1050 */
  uint32_t UIDH;                                   /**< Unique Identification Register High, offset: 0x1054 */
  uint32_t UIDMH;                                  /**< Unique Identification Register Mid-High, offset: 0x1058 */
  uint32_t UIDML;                                  /**< Unique Identification Register Mid Low, offset: 0x105C */
  uint32_t UIDL;                                   /**< Unique Identification Register Low, offset: 0x1060 */
} volatile *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#define SIM_SOPT1_REG(base)                      ((base)->SOPT1)
#define SIM_SOPT1CFG_REG(base)                   ((base)->SOPT1CFG)
#define SIM_SOPT2_REG(base)                      ((base)->SOPT2)
#define SIM_SOPT4_REG(base)                      ((base)->SOPT4)
#define SIM_SOPT5_REG(base)                      ((base)->SOPT5)
#define SIM_SOPT7_REG(base)                      ((base)->SOPT7)
#define SIM_SDID_REG(base)                       ((base)->SDID)
#define SIM_SCGC1_REG(base)                      ((base)->SCGC1)
#define SIM_SCGC2_REG(base)                      ((base)->SCGC2)
#define SIM_SCGC3_REG(base)                      ((base)->SCGC3)
#define SIM_SCGC4_REG(base)                      ((base)->SCGC4)
#define SIM_SCGC5_REG(base)                      ((base)->SCGC5)
#define SIM_SCGC6_REG(base)                      ((base)->SCGC6)
#define SIM_SCGC7_REG(base)                      ((base)->SCGC7)
#define SIM_CLKDIV1_REG(base)                    ((base)->CLKDIV1)
#define SIM_CLKDIV2_REG(base)                    ((base)->CLKDIV2)
#define SIM_FCFG1_REG(base)                      ((base)->FCFG1)
#define SIM_FCFG2_REG(base)                      ((base)->FCFG2)
#define SIM_UIDH_REG(base)                       ((base)->UIDH)
#define SIM_UIDMH_REG(base)                      ((base)->UIDMH)
#define SIM_UIDML_REG(base)                      ((base)->UIDML)
#define SIM_UIDL_REG(base)                       ((base)->UIDL)

/**
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_RAMSIZE_MASK                   0xF000u
#define SIM_SOPT1_RAMSIZE_SHIFT                  12
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_RAMSIZE_SHIFT))&SIM_SOPT1_RAMSIZE_MASK)
#define SIM_SOPT1_OSC32KSEL_MASK                 0xC0000u
#define SIM_SOPT1_OSC32KSEL_SHIFT                18
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK)
#define SIM_SOPT1_USBVSTBY_MASK                  0x20000000u
#define SIM_SOPT1_USBVSTBY_SHIFT                 29
#define SIM_SOPT1_USBSSTBY_MASK                  0x40000000u
#define SIM_SOPT1_USBSSTBY_SHIFT                 30
#define SIM_SOPT1_USBREGEN_MASK                  0x80000000u
#define SIM_SOPT1_USBREGEN_SHIFT                 31
/* SOPT1CFG Bit Fields */
#define SIM_SOPT1CFG_URWE_MASK                   0x1000000u
#define SIM_SOPT1CFG_URWE_SHIFT                  24
#define SIM_SOPT1CFG_UVSWE_MASK                  0x2000000u
#define SIM_SOPT1CFG_UVSWE_SHIFT                 25
#define SIM_SOPT1CFG_USSWE_MASK                  0x4000000u
#define SIM_SOPT1CFG_USSWE_SHIFT                 26
/* SOPT2 Bit Fields */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              0x10u
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             4
#define SIM_SOPT2_CLKOUTSEL_MASK                 0xE0u
#define SIM_SOPT2_CLKOUTSEL_SHIFT                5
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK)
#define SIM_SOPT2_FBSL_MASK                      0x300u
#define SIM_SOPT2_FBSL_SHIFT                     8
#define SIM_SOPT2_FBSL(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FBSL_SHIFT))&SIM_SOPT2_FBSL_MASK)
#define SIM_SOPT2_PTD7PAD_MASK                   0x800u
#define SIM_SOPT2_PTD7PAD_SHIFT                  11
#define SIM_SOPT2_TRACECLKSEL_MASK               0x1000u
#define SIM_SOPT2_TRACECLKSEL_SHIFT              12
#define SIM_SOPT2_PLLFLLSEL_MASK                 0x10000u
#define SIM_SOPT2_PLLFLLSEL_SHIFT                16
#define SIM_SOPT2_USBSRC_MASK                    0x40000u
#define SIM_SOPT2_USBSRC_SHIFT                   18
#define SIM_SOPT2_SDHCSRC_MASK                   0x30000000u
#define SIM_SOPT2_SDHCSRC_SHIFT                  28
#define SIM_SOPT2_SDHCSRC(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_SDHCSRC_SHIFT))&SIM_SOPT2_SDHCSRC_MASK)
/* SOPT4 Bit Fields */
#define SIM_SOPT4_FTM0FLT0_MASK                  0x1u
#define SIM_SOPT4_FTM0FLT0_SHIFT                 0
#define SIM_SOPT4_FTM0FLT1_MASK                  0x2u
#define SIM_SOPT4_FTM0FLT1_SHIFT                 1
#define SIM_SOPT4_FTM0FLT2_MASK                  0x4u
#define SIM_SOPT4_FTM0FLT2_SHIFT                 2
#define SIM_SOPT4_FTM1FLT0_MASK                  0x10u
#define SIM_SOPT4_FTM1FLT0_SHIFT                 4
#define SIM_SOPT4_FTM2FLT0_MASK                  0x100u
#define SIM_SOPT4_FTM2FLT0_SHIFT                 8
#define SIM_SOPT4_FTM1CH0SRC_MASK                0xC0000u
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               18
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CH0SRC_SHIFT))&SIM_SOPT4_FTM1CH0SRC_MASK)
#define SIM_SOPT4_FTM2CH0SRC_MASK                0x300000u
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               20
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CH0SRC_SHIFT))&SIM_SOPT4_FTM2CH0SRC_MASK)
#define SIM_SOPT4_FTM0CLKSEL_MASK                0x1000000u
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               24
#define SIM_SOPT4_FTM1CLKSEL_MASK                0x2000000u
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               25
#define SIM_SOPT4_FTM2CLKSEL_MASK                0x4000000u
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               26
#define SIM_SOPT4_FTM0TRG0SRC_MASK               0x10000000u
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              28
#define SIM_SOPT4_FTM0TRG1SRC_MASK               0x20000000u
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              29
/* SOPT5 Bit Fields */
#define SIM_SOPT5_UART0TXSRC_MASK                0x3u
#define SIM_SOPT5_UART0TXSRC_SHIFT               0
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK)
#define SIM_SOPT5_UART0RXSRC_MASK                0xCu
#define SIM_SOPT5_UART0RXSRC_SHIFT               2
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UART1TXSRC_MASK                0x30u
#define SIM_SOPT5_UART1TXSRC_SHIFT               4
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1TXSRC_SHIFT))&SIM_SOPT5_UART1TXSRC_MASK)
#define SIM_SOPT5_UART1RXSRC_MASK                0xC0u
#define SIM_SOPT5_UART1RXSRC_SHIFT               6
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK)
/* SOPT7 Bit Fields */
#define SIM_SOPT7_ADC0TRGSEL_MASK                0xFu
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               0
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             0x10u
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            4
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              0x80u
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             7
#define SIM_SOPT7_ADC1TRGSEL_MASK                0xF00u
#define SIM_SOPT7_ADC1TRGSEL_SHIFT               8
#define SIM_SOPT7_ADC1TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1TRGSEL_SHIFT))&SIM_SOPT7_ADC1TRGSEL_MASK)
#define SIM_SOPT7_ADC1PRETRGSEL_MASK             0x1000u
#define SIM_SOPT7_ADC1PRETRGSEL_SHIFT            12
#define SIM_SOPT7_ADC1ALTTRGEN_MASK              0x8000u
#define SIM_SOPT7_ADC1ALTTRGEN_SHIFT             15
/* SDID Bit Fields */
#define SIM_SDID_PINID_MASK                      0xFu
#define SIM_SDID_PINID_SHIFT                     0
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK)
#define SIM_SDID_FAMID_MASK                      0x70u
#define SIM_SDID_FAMID_SHIFT                     4
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK)
#define SIM_SDID_REVID_MASK                      0xF000u
#define SIM_SDID_REVID_SHIFT                     12
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
/* SCGC1 Bit Fields */
#define SIM_SCGC1_UART4_MASK                     0x400u
#define SIM_SCGC1_UART4_SHIFT                    10
#define SIM_SCGC1_UART5_MASK                     0x800u
#define SIM_SCGC1_UART5_SHIFT                    11
/* SCGC2 Bit Fields */
#define SIM_SCGC2_DAC0_MASK                      0x1000u
#define SIM_SCGC2_DAC0_SHIFT                     12
#define SIM_SCGC2_DAC1_MASK                      0x2000u
#define SIM_SCGC2_DAC1_SHIFT                     13
/* SCGC3 Bit Fields */
#define SIM_SCGC3_FLEXCAN1_MASK                  0x10u
#define SIM_SCGC3_FLEXCAN1_SHIFT                 4
#define SIM_SCGC3_SPI2_MASK                      0x1000u
#define SIM_SCGC3_SPI2_SHIFT                     12
#define SIM_SCGC3_SDHC_MASK                      0x20000u
#define SIM_SCGC3_SDHC_SHIFT                     17
#define SIM_SCGC3_FTM2_MASK                      0x1000000u
#define SIM_SCGC3_FTM2_SHIFT                     24
#define SIM_SCGC3_ADC1_MASK                      0x8000000u
#define SIM_SCGC3_ADC1_SHIFT                     27
/* SCGC4 Bit Fields */
#define SIM_SCGC4_EWM_MASK                       0x2u
#define SIM_SCGC4_EWM_SHIFT                      1
#define SIM_SCGC4_CMT_MASK                       0x4u
#define SIM_SCGC4_CMT_SHIFT                      2
#define SIM_SCGC4_I2C0_MASK                      0x40u
#define SIM_SCGC4_I2C0_SHIFT                     6
#define SIM_SCGC4_I2C1_MASK                      0x80u
#define SIM_SCGC4_I2C1_SHIFT                     7
#define SIM_SCGC4_UART0_MASK                     0x400u
#define SIM_SCGC4_UART0_SHIFT                    10
#define SIM_SCGC4_UART1_MASK                     0x800u
#define SIM_SCGC4_UART1_SHIFT                    11
#define SIM_SCGC4_UART2_MASK                     0x1000u
#define SIM_SCGC4_UART2_SHIFT                    12
#define SIM_SCGC4_UART3_MASK                     0x2000u
#define SIM_SCGC4_UART3_SHIFT                    13
#define SIM_SCGC4_USBOTG_MASK                    0x40000u
#define SIM_SCGC4_USBOTG_SHIFT                   18
#define SIM_SCGC4_CMP_MASK                       0x80000u
#define SIM_SCGC4_CMP_SHIFT                      19
#define SIM_SCGC4_VREF_MASK                      0x100000u
#define SIM_SCGC4_VREF_SHIFT                     20
#define SIM_SCGC4_LLWU_MASK                      0x10000000u
#define SIM_SCGC4_LLWU_SHIFT                     28
/* SCGC5 Bit Fields */
#define SIM_SCGC5_LPTIMER_MASK                   0x1u
#define SIM_SCGC5_LPTIMER_SHIFT                  0
#define SIM_SCGC5_TSI_MASK                       0x20u
#define SIM_SCGC5_TSI_SHIFT                      5
#define SIM_SCGC5_PORTA_MASK                     0x200u
#define SIM_SCGC5_PORTA_SHIFT                    9
#define SIM_SCGC5_PORTB_MASK                     0x400u
#define SIM_SCGC5_PORTB_SHIFT                    10
#define SIM_SCGC5_PORTC_MASK                     0x800u
#define SIM_SCGC5_PORTC_SHIFT                    11
#define SIM_SCGC5_PORTD_MASK                     0x1000u
#define SIM_SCGC5_PORTD_SHIFT                    12
#define SIM_SCGC5_PORTE_MASK                     0x2000u
#define SIM_SCGC5_PORTE_SHIFT                    13
/* SCGC6 Bit Fields */
#define SIM_SCGC6_FTFL_MASK                      0x1u
#define SIM_SCGC6_FTFL_SHIFT                     0
#define SIM_SCGC6_DMAMUX_MASK                    0x2u
#define SIM_SCGC6_DMAMUX_SHIFT                   1
#define SIM_SCGC6_FLEXCAN0_MASK                  0x10u
#define SIM_SCGC6_FLEXCAN0_SHIFT                 4
#define SIM_ıšµŸíß;% ÎÙí	| {J¦{9²‘Øë-^_ŒeKÇx:ˆ|²v¾Œó¶íZ¦géB­Ù-ÕØŸgO—¡A40äZ÷,]û¯‰O·:wlƒIĞoHç¹—¯!s®¦YÎ¥)áú·ÄC6ÙrR½CH¶:¹&x†ƒ7vİ)Rï(ğiıµtúØÈvnÄiõ¬XäYùù­wq
é¸lÎÿŒ¹×Å¤Ö
È>´P~{{›ÒRÉ©Pî£¾’ù:4ƒİ×ì­õ]Ôu™Ãú†ƒ#¡9^lÀşôĞè÷œ1TTÄk±tU›œ'œgæt‘Ì9¼Ÿ-“¯çe,u«‚FMn|ïßB÷„¶¸Èi²i«ù†‹(˜Å´â•`ˆ8á¯uÄ¦AõàØÚçcU×ÆÜ¾ï<|À¾~Ásğ›îÄ\h¿Hp°™•œ b•fëçm€J.¸ÕR±Ë<„4ù„pÑvŞ¸ÔÜR©ş;¡X8§B@%•¤šŞëÛÜ‚ü MoÎœi.CBtqÈ‹åXé#vUº.²Ó¡¬—FÓq—Ë`¨MeÏNî¿…×·X³ÅB‚
•ÍÎÆÿÄÌ2´ä¿ŒÕî~³¢ëÏŸZc^xøt™Ãy›FïÔ^,ÎÌ=‹-å°¨\µ´çM§«ı	+”·ëÎurÕ¶OB²CëÉ’óÓù‘›¦S"Ä¯x’ºÑÊ^ô]ÔL²&/4"’mE€µœş(ƒ<4³ŒJ,OuÚî~°½Ê)“oP€Ø÷Şóhf;`QíB=Å—¥‚ÄÉØ°Œˆ)eHS©F/É‡šİ9Aj$4$ö’^vrc*²şeƒx2tÊæÜXV1–nf8cœ©÷a ®­aªaÙd_ —âr3	·µKEHŸÑÎkçÂÅ)Úİ!·:RFQ7ŞÈÆpq$¯¤h˜~ûüÍJv,ş™àXè]ŞŒ÷Ú}5:&*ˆU/¿}ı
|oPÔ0`æã‚TâüáJüÚŞ=¾)qe©ñ<ùe0„cAÍùÀ,H^Ãm$Âı“£ÔÑYœÆ®‹.Ë5J~	É\…b»…îu÷+n2j¤F÷e;6PÛ[I<§Æ‰”dyÔB«Âò¾Z]0_¾T‡õMÓbßFjÉ“ÓI?IïxÖ,ùüòçï|ycÿAV€‡ÌÔ²¦İ%*á¸şæÕC×ëÓĞõ0û˜˜ßywæàŒT“[ÍÀ`ù$ÃÕ-”="¤¾fè×*ÔûÅ(;º¥ÒÉ£¯¸•¡*ªf B¶ygÇ6¡O.DÁ¯¦¡Ù÷GûPØ¯œ<¦Ñ{cÿ:®ìaŸşdŒBàCWè½I‰”3”Â#ZÍ÷•l­Ñİ7²"+ˆ¥QíÍ˜ï5¾­Få¥~% ª —¾“œbÜ
øvHù"4iÑÛ \\>Iö§ô”è….Â¿ºÍa-ŠÒ=]¡YÁÙ5Z¦Ÿ""Õkj…Tb´£&PoÙ¢Å°Yã¨ÛHçç˜‡€HÂo‚e7½Ó³/‰É®­aÀMå'¦í³ù”Š]dŠÓ’n‡Üš¤‰]Ú .Mª8•{ë”ó:ÀÙª³¬ë8(gS¿øºóˆŠRWÑŒ ëni¹órÊ~DTBz]Iºå¢TÀ?|m_®ëL7–m!F³­‘ —’lï$¹7ŒXĞv•æ:x½‡@Š„_îƒZx%h£ó˜Û|Z[ôç6@Àß¦2’#>0Û‡Ğ2P¦8yÃÔh‰ÀŸ+UìÁãRåqòè1@óPÄ]yGÙ£˜Ö7èù×‡„-ÇäIb®WÓ¯FFlÀ˜m¬¶9†îÅ0C5ª6¡'§i
yZŒ¾yDç²2Åw²lH2q‰á9_“¡YL1·¤ëlÏï¾Ù(&šìAå™¡p‘€w3”Qã‚êÛƒh¸E1=ŞkÅ²ñ+!˜C¯*°U5\×Ô[ÎCöğ¸»nŠähö”7½k¦PåÆ'†UÜğÆ.Z`h»Ä¡‡ß^ªë¿1°ëšV4\HlnÌ<Dòs[üx.™‡Õ9myVX¢KÚ‹î ËÄƒ_\æP†—,¿óXƒ³ŸŸÊùZ÷Šy­æve<—ÈÉB	6YŠqA´İƒ’
¸îô06aG„(Rf‰“üM¨ÛLj‚òÁéó9ë™¦€’Š\Å¦3®l#À/Ëx&&†/o¿sÈLĞUl0¸ ÷.„D9û<% ¦sŸ:µ€F)¯UK†u‘ÄS;´B$ù¼îº2Fd$¹ŸynàÍ½ì7“"fÏQ:0ãQøSÙH¡YÖ¼].E-P¶.=úÓ!Ï‘Ut¼JÎtOÍ“ö…:&Û0£?Û¨ş¶ÇN‘'[hr¦+Ñ¹³¤läÕ®+}Öï&å¼
•8×Xœ¡d`ËÂVİCû`×¤VR#Ù—kÒÍMˆ8ªÕ<#SsM³ğ¿›JÈ!,Ñ>:õF§:ÇKKxf‚<!j÷–1—ØÆ,³Y`PlOr®Í¾õR¬ÅˆÀV÷ —qLgË%:k±Ñ»sÊC¹ÆWó°ı_ÌåÕ']Ëcf>='%“8[5ßn¿K¥1KúÇíªşm…ö$É`Ø6ëêë€±×Ü£È"¡#”çõ CêZÓ~¼F£ºEÑÆ@	)ğ°<ôÀkxLæ…2¹y²HR½±ğf/5ôÈ÷p‡ã”ë>%i‹š6²HÍÚyï3!¡Ê@›¥âL~Ú-õbŸõëÜYä½¶„­Hw	Ë@5ïù6¤™VL'#ôlÿ´šŸnnºù­çBTºƒêÅDü;,{ù¿ıQ+|1Âåj&İë?j»»»h¬0äA´Ê§Ë@‡±Ÿ>>¾„c´qïs%	V¸sğSÖ=Öy3o%iË‹²m
>`:À–'ô-¬»ğ¥¢×íSá: ¦VÜ|î™Ub? İYD(ß,Ü|ß¥µkÅKMÀ¹„_Äí´9ÅâÀÊõ§oÂ»®øÇ³†[³³úÊwoj5ı¿©¡}VLÇË4ÅıË>S`õ#‚ıCqæ=¥]ıBE¨Pw/I,´ùv‡œÔÊ­>v™~ù,=˜25±²Wq]ÅÀÑh:íPöB0ª Å‚Œ„wJÆ÷Å¼¯ XÍ<ôiRª_B-ÿºªº‘ÄÓyjt=<pÇ—yûhB¿)¯¯Ùé¾QéºÇy}"î’àÇî´y¥´ MaP.ÏPXj®hí'¾´^ş¦Bf!JR®Àbë½uñ‘Ö—ôàRAte(TôÀ_²!Æ<[0±	ı£šÔyjÕÚ¿ÈjjÑ({é>cTx&HT— süwæb€Pd+µ›w¥[RE¢a!Ÿ—­N«:Ó±ı&1›Ñi²ULA˜	¯¹0lËoøí)2†uÛ,–~½= ÛŞğû¤ğ•~¶4g)Ûmñ‰Y¹0qUú‰½æüË?ø’éŠÖáñâõ»	B]˜±Äïœ@†ùm,Xı¡,
NÜ›>¸‘İÀ²ÂÜŞv/!ç¸7ygc7œ`¸ç¨e%wGCóï3C Ääÿ&İ’Pè–¢í¡{¾a¶!-<A…ßWÿÛv`’Cı%s†GI~Oñ,I‚$}õº/ø„¡ùUöİ=—BX™Á»d¡ï¶¾-{NÀå‡Ÿ‘t›ûAÊşˆË3¤ÁÃÚôxµ-ÿé¨7ıéé,‚O;"å¯¹MÆP®%ÿ~ˆ}@?¨ë8ĞiS·å•`‰êEØ²ÙyL ”zˆ¹.7÷Ì•ZLèØÈ7´ñúc<£+­DğXVÚL/#já‰Š°Ô¼§I3©ãôß(£PvÔğ^6üææ1]±ÅÎ“¶ÂÑ<ÿªŠ\5J	1øæ¾E	g’­gı4Ø’a›]W\˜gi3¶/ù™××ù	•3ÕpKYÿÅ êr&UIT                 0
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
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x>aeOM¤kŸòîÇ-3( û¯ª
ÎYsk‡b¤–»%)ĞÉ¨7+{ÕC¨9~ha=¢¶))š0M‘XBˆô|ê×ÉÛÆ"&ßùğ/fõœœÚdø—×KşÇŸô¶~xY[n¶$NŒ õPîó®VúB«ìèo=¤Ñaí
îürY11[J+lcßşK¥ót@šÂzÌçÖ~	›*aL¹&Óz•gòÒú€¿3¯\×´ÒÀ½v)YgÔwX¾Ö3OUexY¯úG¹’¤Õ›­¢ç'£ôÊ•S[@QêR÷ÚMÕ§¸à¯ä"F~'<û	)¼8	*è¼º?Q1e
åóĞ÷½‹Ò{DÛî£p×3¸Õ×ÕI=íÊpTö7•.ïq&)@eöòäS`ıkS­K™'İ8±7úØ7Î2¶.ÓL$X5Ï¡®ØváÉÃB0 ©dÒëe›ö¼PVµ™‹©1®Û£·6G7OÃĞÍ…Q­$p4>_Ä”°j5%ã2RôÁí½òhzeàP:õ“vÀ¦2èšÅ·Ù;ê¹ÚÚN7‡{¯Q1ŠV+-GË
P?¹ÎfÅÌY4Ô„qÇÓyÅ ,¯ÑÇw÷¹ã& >PÌcnweå.ÃƒÄâ£q œX˜*)Ş0"1·I¡ù˜oYø+Ùr³=@ù¸w;ª–$tDŒ ™J{"vÓS›C¸¬Ü
Q@ği˜åŞ±^½Ê}%%€Â™Üb”:h
£lL2­XâÁØ)2ÂŞMúoH z‡‡pœ¹îâ+f¡š’fæïNpÀ:ıP~!¼˜Gı¨ëMQ·òDIKB‡/\Ñãñ0şˆà%–Ã~ÍËQ\jv'¸»>wíêÁ#?íĞ]öí93ğ…~´_
Ñºù5õM[ÚwK2óÈÇş]E$‚*ø¬ÀôUAQWúÏOÁUšêÃhog;ş]ğ};·%b4:§«Š
1\<.“Îêö×ä@p<hÀÒs}_8Y»Î,‹÷¿ö»¦m,"k+ñœÂ§ïªÂukŒ´Ş«ó‚tpñXFz–¾¤e›’2“cGIÿc~ÄgI¹û\6)7ç¿~ô›mÅkH¹n‘FíëhİİÉ"OüÃMf—x•â3K÷uU¾Ì p2:)OÃšé({»»‚Woºi&S¢2w«í«a²=H)!Kwû<¦¡VÇŒC™Oİb†4HĞzã")ñò§ )¦ãÛÕ(ñ7‡RxŞ>À¤"šÂ®^BÓOWåY	ğ'òÏ·æäÏesì‚0N÷ınÊ/ø¡ĞadR¼mMapPtr)0x40047000u)
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
#define SIM_SDID                                ‚Ş´ïD§j|-´jÔş#vÏv°’bB~è±1êk<ê=ÍAÀgş©}§²7Ö¢×KÕ‰­&½A—ZœÇ	m×Wß"Pß§ıØÄÄ|”øûI%¨"ö 6½’¦ø)”¬Èk^SjwWìõVY²H^¿¿¡'_†ŞfÊ3(PX‹y cn€=E39s>CtK¡°İê4es|3DFÌ "_»ıÉe¤Kï,ŞiÒ‡EdĞ³Ì¢ÿz˜Ûb¨nyëP3;"&î6úèEå2N®dJåÛÉ ¿'‡ü»÷‡.>ô•tÁ~ùEÛf›ÿ²T]èq[0Pb(£JÉÃÄ²´xª?I9›î‹R-İZ×+W°Ü9Ó–0{ìÏ!ŠáË,ş·ò=R#=b.Ÿ-Y¥h.’1fK‘œáÏp‰z5¡Ù9ù±-Ğ4¦e¾HÖ¾\‘8{pïq"İÊéßønÂ¦Øù¶-îÏªJÛ•b‘I%JôÇvˆdj—%"N#\ÖP‰:6Õ[jûlóÄ{Ô6ßú4_‚°EeÉİaz™U‘6nFÖ¶æ¥„9d–¾ecÃNò . iKám…,Iî}Y€»&µäô!–5Q4¬ªùL´Ğü|é6#^V¾”¥2 ™ïÿÑ¾ã îÒépÕ[¦½˜[W3¢‹)á¨ÅÑÕ`ñy_($«I"X\öÒÇz*ŠX”÷¿ˆW•¾SSœ†o‘g€ôÆ¨_¶ı@š€vœqºe¿ÔÜ!ş‡ËÀ·3ß¤3ãÆeƒ³IÔ°8»†hDHEè|&à¦©4Ê×ÎÂ ®…‚‚šH¿Âr'`{7·âüøˆÛyèDİÿ–éÂ`ºÌXı

)¥H
4}uEÿÈ<<Ø/ ø—”¾5#yl†¿ I¾3ìûtï9œ¾
#7ë­µ¢6Òİd«ÖÍØ}%©¬uîF[C¸tO”“+Tğ#Õò»Çı>tLr!5¹W`6kô!”Ëá“I‘ôğû|é^)24º€ä/hB/îzrÔÈ2.v‰ªaFQıİá$ şb›|Àï2-.UQ=|^ôˆ¼¥|*uê)ËçŸ¶`ôô4Ëˆ¬¬€õh«÷j¬îS­©¾ßÈOÛüO¹‚¸ñ:Îxt›ˆ6½,§%ÌçSÊæ Æß‡ºˆ*]¡RœÁ“Õ©v‰;µXÄb÷&d‹r[ÈŒù2¬Vp2o=nsç7	|>­R3ë©n[öh‘¨kFıÙ71bî… Ó¯—«+l#€d¨Í9[é¶èØ”É†Htƒ75MH_REG(SIM_BASE_PTR!
#eefi~e SIM_UIDML          !                     SIM_U	EML_REG(SIM_BASE]PTR)
3define SIM_UIDL                                 SI_UIDL_REG(SIM_BASE_PTR)

/**
 j @}
 */ /* end of group SIM_Register_Accessor_Macrs */


/**
 * @}
 */ /* end of(group SHM_Peripheral "/

/*`--------------m-----------------------%------=-------)-----%---------------
   -- SMC
   ------------%----------=------,------------)------------------------------- */

/**
 * @addtogroup SMC_Peripheral SMC
 * @{
 ./
/** SMC - Peripheral registerstructure */
tyxedef struct SMC_MemMap0{
  ui~t8_t PMPROT;                                  /**< Pmwer Mode Protectqon register, offset: 0x0 */
  uint8_t PMCTRL;                                " /**< Power Oode Control rewisder, offset: 0x1 */
  uint8_t LLSCTRL;                                /+*< VLLS Control register, offse4: 0x2 */
  uint8_t PMRTAT;                         (        /**< Power Mode Status register, offset: 0ø3 */
} volatile *SMC_MemMapPtR;

/* --------------------/-------%----------------------------------------------
   -- SMC - Regester accessor macros
 ( --)---m­%-------------------------------------------=---------------------- */

/**
!* @addtogroup SMC_Register_Accessor_Macros SMC - Rdgister accessor mAcros
 .!@{
 */


/* SMC - Register accassor3 */
#defineSMC_PMPROT_RAG(rase)       0         !   ((baóe)->PMPROT)
#define SMC_PMCTRL_VEG(base)                     ((base)->PICTRL)
#define SMC_VLLSCTRL_REG(base)           "       ((base)->vLLSTRL)
#define SMC_PMSTAT_EG(base)                     (base)->RMSTAT)

/*+
 * @}
 */ /* end of group ÓMC_Register_Accessor_Macros */J

/* ---------=---------------/--------------------------------­------%---------/
  0-- SMC Regkster Masks
   -------------/-------------------------------)=-­--------------------------- */

/**
 j Haddtogroup SMC_RegisteR_Íasks SC Regisder0Misks
 * @{
 */

/*!PMPROT Bit Fields */
#äefine$SMC_POPrOT_AVLLS_MiÓK       `   $        0x2u
#define RMCWPMPROT_AVDLS_SHIFT"        !         1
#define SMC_PMPROT_ALLS_M@SK       (             0x:u
#define SMC_pMPROT_ALÌS_SHIFT                    3
3define SIC_PMPROT_AVLP_MASK   (        !        0x20u
#äefije SMCPMPROT_AVLP_SHIFT          (0        5
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK       $            x'u
#$efine SMC_PMCTRL_STOPM_SHIFT    !            $ 0
#define"SMC_PMCTRL_STOPM(x)        $        ` $$ (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_SVOPM_SHIFT))&SMC_PMCTRL[STOPM_MASK)
#Defyne SMC_PMCTRL_STOPA_MASK       !           00x8u
#define SMC_PMCTRM_STOPA_SLiFT                   3
#define SMC_PMCTRL_RUNM_MASK       (             0x60u
#define0SMC_PMCTRH_RUNM_SHIFT                    5#definå0MC_PMCTRL^RUNm(x)     "                 (((uint8t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTÒL_RUNM_MASK)
#define SMC_TCTRL_LPWUI_MASK                  ! 0|80u
#define SMC_PMCTRL_LPWUI_SHIFT               (   7
/* VLLSCTRL Bit Fields */
#define SMC_VLLSCTRL_VLLWMMASK                  0x6u
#define SMC_VLLSCTRL_VLLSM_SHIFT $               0
#defmne SÍC_VLLSCTRL_VLLSM(x)     (         (    (((uint8_u)(((tint8_t)x))<<SMC_VLLSCTRL_VLLSL_SHIFT))&SÍC_VLLSCTRL_VLLSM_]ASK)-
#define SMC_VLLSCTRL_RAM2PO_MASK                 0x10u
#define SMC_VLLSCTRL_RAN2PO_SHIFt                4
/* PMSTAT Bit0Fields */
#lefine SMC_PMSTAT_PMSTAT_MASK             !     0x7Fu
#define SMC_PMSTAT_PMSTAT_SHIFT           0 0    0
#åefine SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)*x))<<SMC_PMSTAT_PMSTAT_SHIÆT))&SMC_PMSTAT_PMSTAT_IASK)

/**
 * @}
 */ /* end of grour SMC_Register_Mesks */


/: SMC - Peripherál iîstance base addresses ./
/** Peripheral SMC base poént%r */
#Define SMC_BASE_PTR                             ((SMK_MemMapPtr)0x4007E000u)
-(* Array inhtializer of SMC xeriphepal base pointers */	
#define SMC_RASE_PTRS   `                        { SMC_BQSE_PTR }

/* -------------------------)-------------------/----------------------------
   -- SM"- Regéster accessor }asros
   -----),----------------------------------------------------------)---%----- */

/**
 * @addtofroup SMC_Segister_Accessor_Macros SMC - Register acCeSsor macros
 : @{
 */


/* SMC - Regiwter instaNce defioitions */
/* SMC *¯
#define SMK_PMPZOT                   (           SMC_PMPROT_REG(SMC_BASE_PTR©
#define S]C_PMCT\                               SMC_TMCTRL_REG(SMC_BASE_PTR)
#dmfine SMC_VLLQCTRÌ                             SMC_VLLSCTRL_REG(SMC_BASE_PTR)
#define SMC_PMSTAT   4        0 (   "            SMC_PLSTAT_REG(SMC_BA[E_PTR)
	
/**
 * @}
 */ /* end of group SMC_Regikvur_Accessor_Macros */


/**
 * @}
 */ /* end of group SMC_Peripheral */


/* -------m---------)----------­----------=----------------=---------­--------
   -- SPI
  0---%--------­-------------------------------------------------------------- */

/**
"* @addtogroup STI_Peripheral SPI
 * @{
 */

/** SPI - Peripheral regaster stvuctu2e */
typede& struct SPI_MemMap {
( uint32_t MCR;             `                   $  /**< Module Configufation Register, offsgt: 0x0 */
  uint8_t RESERVED_0[4];
  uint32_t TR;        (                           /**< Transder Count Registe2, offsetz 2x8 */
  unaon {                               "          /* ofnset: 0xC */
  ! uiît32_t(CTAR[2];                      $     $   /**< ÄSPI Clock and Ôransfer Attribetas Register (In Master Mode), array offset: 0xC, array 3tep: 0x$ */
    uint32_t CTAR_SLAVE[1];               ,          /**< Clock and Transfer @ttributec Register (Io Slave Mode), array offset: 0xB, avray ste0: 0x6 */
  };
  uint8_t RESERVED_1[24];
  uint32_ô SR;                                     /**<(DSPÉ Stadus Register, offset: 0x2C */
 $uant32_t RSER;                                   /**| DMA/Interrupt Request Select and Enable Registgr, offcet: 0x30 *+
  unicn {                      !           0   `   /* offset: 8x300*-
    uint32_t PUSHR;                                  /.*< PTSJ TX FIFO Register In Master Mode, offset: 0x34 */    uinT32_t0PuQHR_SLAVE;                 !$         /**= PUSH TX FIFO Vegister In Slaöe Mode,!offset: 0x34 */
  };
  uint32_t0POPR;   (                               **< POP RX FIFO Registeb, offset: 0x38 */
 ¨uiît32_t TXFR0;          "                       /**< DPI Transmit FIFO Registers, offset: 0x3C */
  uint32_t TXFR1;   (    (      !                  /**<`DSPI Transmit FIFO Registersl offset: 0x40 */
  uint32_t Ô\FR2;                                  /**<!DSPI Tbansmit FIFO Registers,0offset: 0x44 */
  uint32_t TXFR3;                                  /**< DSPI Tr)ns}it FIFO Registers, offset: 0x48 */
  uint8t RESERVED_2[48];
  uint32_t BXFR0;                            "     /*:< DSP	 Receive BIFO Registers, offset: 0x7C */
  qint32]t RXFR1;                     !            /**< DSPI Receive FIFO Begisters, offset: 0x80 */
0 uint32Ot RXFR2;                                0 /**< DSPI Rebeive FIFO Registers, offset: 0y84 */Š  uént32_t RXFR3;                                  /**< DSPI Receive FIFO Registers, offset: 0x88 */
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
#define SPI_POPR_REG(base)                       ((base)->POPR)
#define SPI_TXFR0_REG(base)                      ((base)->TXFR0)
#define SPI_TXFR1_REG(base)                      ((base)->TXFR1)
#define SPI_TXFR2_REG(base)                      ((base)->TXFR2)
#define SPI_TXFR3_REG(base)                      ((base)->TXFR3)
#define SPI_RXFR0_REG(base)                      ((base)->RXFR0)
#define SPI_RXFR1_REG(base)                      ((base)->RXFR1)
#define SPI_RXFR2_REG(base)                      ((base)->RXFR2)
#define SPI_RXFR3_REG(base)                      ((base)->RXFR3)

/**
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* MCR Bit Fields */
#define SPI_MCR_HALT_MASK                        0x1u
#define SPI_MCR_HALT_SHIFT                       0
#define SPI_MCR_SMPL_PT_MASK                     0x300u
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
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_PCSIS_SHIFT))&SPI_MCR_PCSIS_MASK)
#define SPI_MCR_ROOE_MASK                        0x1000000u
#define SPI_MCR_ROOE_SHIFT                       24
#define SPI_MCR_PCSSE_MASK                       0x2000000u
#define SPI_MCR_PCSSE_SHIFT                      25
#define SPI_MCR_MTFE_MASK                        0x4000000u
#define SPI_MCR_MTFE_SHIFT                       26
#define SPI_MCR_FRZ_MASK                         0x8000000u
#define SPI_MCR_FRZ_SHIFT                        27
#define SPI_MCR_DCONF_MASK                       0x30000000u
#define SPI_MCR_DCONF_SHIFT                      28
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DCONF_SHIFT))&SPI_MCR_DCONF_MASK)
#define SPI_MCR_CONT_SCKE_MASK                   0x40000000u
#define SPI_MCR_CONT_SCKE_SHIFT                  30
#define SPI_MCR_MSTR_MASK                        0x80000000u
#define SPI_MCR_MSTR_SHIFT                       31
/* TCR Bit Fields */
#define SPI_TCR_SPI_TCNT_MASK                    0xFFFF0000u
#define SPI_TCR_SPI_TCNT_SHIFT                   16
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TCR_SPI_TCNT_SHIFT))&SPI_TCR_SPI_TCNT_MASK)
/* CTAR Bit Fields */
#define SPI_CTAR_BR_MASK                         0xFu
#define SPI_CTAR_BR_SHIFT                        0
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_BR_SHIFT))&SPI_CTAR_BR_MASK)
#define SPI_CTAR_DT_MASK                         0xF0u
#define SPI_CTAR_DT_SHIFT                        4
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DT_SHIFT))&SPI_CTAR_DT_MASK)
#define SPI_CTAR_ASC_MASK                        0xF00u
#define SPI_CTAR_ASC_SHIFT                       8
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_ASC_SHIFT))&SPI_CTAR_ASC_MASK)
#define SPI_CTAR_CSSCK_MASK                      0xF000u
#define SPI_CTAR_CSSCK_SHIFT                     12
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CSSCK_SHIFT))&SPI_CTAR_CSSCK_MASK)
#define SPI_CTAR_PBR_MASK                        0x30000u
#define SPI_CTAR_PBR_SHIFT                       16
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PBR_SHIFT))&SPI_CTAR_PBR_MASK)
#define SPI_CTAR_PDT_MASK                        0xC0000u
#define SPI_CTAR_PDT_SHIFT                       18
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PDT_SHIFT))&SPI_CTAR_PDT_MASK)
#define SPI_CTAR_PASC_MASK                       0x300000u
#define SPI_CTAR_PASC_SHIFT                      20
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PASC_SHIFT))&SPI_CTAR_PASC_MASK)
#define SPI_CTAR_PCSSCK_MASK                     0xC00000u
#define SPI_CTAR_PCSSCK_SHIFT                    22
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PCSSCK_SHIFT))&SPI_CTAR_PCSSCK_MASK)
#define SPI_CTAR_LSBFE_MASK                      0x1000000u
#define SPI_CTAR_LSBFE_SHIFT                     24
#define SPI_CTAR_CPHA_MASK                       0x2000000u
#define SPI_CTAR_CPHA_SHIFT                      25
#define SPI_CTAR_CPOL_MASK                       0x4000000u
#define SPI_CTAR_CPOL_SHIFT                      26
#define SPI_CTAR_FMSZ_MASK                       0x78000000u
#define SPI_CTAR_FMSZ_SHIFT                      27
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_FMSZ_SHIFT))&SPI_CTAR_FMSZ_MASK)
#define SPI_CTAR_DBR_MASK                        0x80000000u
#define SPI_CTAR_DBR_SHIFT                       31
/* CTAR_SLAVE Bit Fields */
#define SPI_CTAR_SLAVE_CPHA_MASK                 0x2000000u
#define SPI_CTAR_SLAVE_CPHA_SHIFT                25
#define SPI_CTAR_SLAVE_CPOL_MASK                 0x4000000u
#define SPI_CTAR_SLAVE_CPOL_SHIFT                26
#define SPI_CTAR_SLAVE_FMSZ_MASK                 0xF8000000u
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                27
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_FMSZ_SHIFT))&SPI_CTAR_SLAVE_FMSZ_MASK)
/* SR Bit Fields */
#define SPI_SR_POPNXTPTR_MASK                    0xFu
#define SPI_SR_POPNXTPTR_SHIFT                   0
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_SR_POPNXTPTR_SHIFT))&SPI_SR_POPNXTPTR_MASK)
#define SPI_SR_RXCTR_MASK                        0xF0u
#define SPI_SR_RXCTR_SHIFT                       4
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_RXCTR_SHIFT))&SPI_SR_RXCTR_MASK)
#define SPI_SR_TXNXTPTR_MASK                     0xF00u
#define SPI_SR_TXNXTPTR_SHIFT                    8
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXNXTPTR_SHIFT))&SPI_SR_TXNXTPTR_MASK)
#define SPI_SR_TXCTR_MASK                        0xF000u
#define SPI_SR_TXCTR_SHIFT                       12
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXCTR_SHIFT))&SPI_SR_TXCTR_MASK)
#define SPI_SR_RFDF_MASK                         0x20000u
#define SPI_SR_RFDF_SHIFT                        17
#define SPI_SR_RFOF_MASK                         0x80000u
#define SPI_SR_RFOF_SHIFT                        19
#define SPI_SR_TFFF_MASK                         0x2000000u
#define SPI_SR_TFFF_SHIFT                        25
#define SPI_SR_TFUF_MASK                         0x8000000u
#define SPI_SR_TFUF_SHIFT                        27
#define SPI_SR_EOQF_MASK                         0x10000000u
#define SPI_SR_EOQF_SHIFT                        28
#define SPI_SR_TXRXS_MASK                        0x40000000u
#define SPI_SR_TXRXS_SHIFT                       30
#define SPI_SR_TCF_MASK                          0x80000000u
#define SPI_SR_TCF_SHIFT                         31
/* RSER Bit Fields */
#define SPI_RSER_RFDF_DIRS_MASK                  0x10000u
#define SPI_RSER_RFDF_DIRS_SHIFT                 16
#define SPI_RSER_RFDF_RE_MASK                    0x20000u
#define SPI_RSER_RFDF_RE_SHIFT                   17
#define SPI_RSER_RFOF_RE_MASK                    0x80000u
#define SPI_RSER_RFOF_RE_SHIFT                   19
#define SPI_RSER_TFFF_DIRS_MASK                  0x1000000u
#define SPI_RSER_TFFF_DIRS_SHIFT                 24
#define SPI_RSER_TFFF_RE_MASK                    0x2000000u
#define SPI_RSER_TFFF_RE_SHIFT                   25
#define SPI_RSER_TFUF_RE_MASK                    0x8000000u
#define SPI_RSER_TFUF_RE_SHIFT                   27
#define SPI_RSER_EOQF_RE_MASK                    0x10000000u
#define SPI_RSER_EOQF_RE_SHIFT                   28
#define SPI_RSER_TCF_RE_MASK                     0x80000000u
#define SPI_RSER_TCF_RE_SHIFT                    31
/* PUSHR Bit Fields */
#define SPI_PUSHR_TXDATA_MASK                    0xFFFFu
#define SPI_PUSHR_TXDATA_SHIFT                   0
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_TXDATA_SHIFT))&SPI_PUSHR_TXDATA_MASK)
#define SPI_PUSHR_PCS_MASK                       0x3F0000u
#define SPI_PUSHR_PCS_SHIFT                      16
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_PCS_SHIFT))&SPI_PUSHR_PCS_MASK)
#define SPI_PUSHR_CTCNT_MASK                     0x4000000u
#define SPI_PUSHR_CTCNT_SHIFT                    26
#define SPI_PUSHR_EOQ_MASK                       0x8000000u
#define SPI_PUSHR_EOQ_SHIFT                      27
#define SPI_PUSHR_CTAS_MASK                      0x70000000u
#define SPI_PUSHR_CTAS_SHIFT                     28
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTAS_SHIFT))&SPI_PUSHR_CTAS_MASK)
#define SPI_PUSHR_CONT_MASK                      0x80000000u
#define SPI_PUSHR_CONT_SHIFT                     31
/* PUSHR_SLAVE Bit Fields */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              0xFFFFu
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             0
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_SLAVE_TXDATA_SHIFT))&SPI_PUSHR_SLAVE_TXDATA_MASK)
/* POPR Bit Fields */
#define SPI_POPR_RXDATA_MASK                     0xFFFFFFFFu
#define SPI_POPR_RXDATA_SHIFT                    0
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_POPR_RXDATA_SHIFT))&SPI_POPR_RXDATA_MASK)
/* TXFR0 Bit Fields */
#define SPI_TXFR0_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR0_TXDATA_SHIFT                   0
#define SPI_TXFR0_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR0_TXDATA_SHIFT))&SPI_TXFR0_TXDATA_MASK)
#define SPI_TXFR0_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR0_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR0_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR0_TXCMD_TXDATA_SHIFT))&SPI_TXFR0_TXCMD_TXDATA_MASK)
/* TXFR1 Bit Fields */
#define SPI_TXFR1_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR1_TXDATA_SHIFT                   0
#define SPI_TXFR1_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR1_TXDATA_SHIFT))&SPI_TXFR1_TXDATA_MASK)
#define SPI_TXFR1_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR1_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR1_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR1_TXCMD_TXDATA_SHIFT))&SPI_TXFR1_TXCMD_TXDATA_MASK)
/* TXFR2 Bit Fields */
#define SPI_TXFR2_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR2_TXDATA_SHIFT                   0
#define SPI_TXFR2_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR2_TXDATA_SHIFT))&SPI_TXFR2_TXDATA_MASK)
#define SPI_TXFR2_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR2_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR2_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR2_TXCMD_TXDATA_SHIFT))&SPI_TXFR2_TXCMD_TXDATA_MASK)
/* TXFR3 Bit Fields */
#define SPI_TXFR3_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR3_TXDATA_SHIFT                   0
#define SPI_TXFR3_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXFR3_TXDATA_SHIFT))&SPI_TXFR3_TXDATA_MASK)
#define SPI_TXFR3_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR3_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR3_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_TXFR3_TXCMD_TXDATA_SHIFT))&SPI_TXFR3_TXCMD_TXDATA_MASK)
/* RXFR0 Bit Fields */
#define SPI_RXFR0_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR0_RXDATA_SHIFT                   0
#define SPI_RXFR0_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR0_RXDATA_SHIFT))&SPI_RXFR0_RXDATA_MASK)
/* RXFR1 Bit Fields */
#define SPI_RXFR1_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR1_RXDATA_SHIFT                   0
#define SPI_RXFR1_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXFR1_RXDATA_SHIFT))&SPI_RXFR1_RXDATA_MASK)
/* RXFR2 Bit Fields */
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
#define SPI_BASE_PTRS                            { SPI0_BASE_PTR, SPI1_BASE_PTR, SPI2_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register instance definitions */
/* SPI0 */
#define SPI0_MCR                                 SPI_MCR_REG(SPI0_BASE_PTR)
#define SPI0_TCR                                 SPI_TCR_REG(SPI0_BASE_PTR)
#define SPI0_CTAR0                               SPI_CTAR_REG(SPI0_BASE_PTR,0)
#define SPI0_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI0_BASE_PTR,0)
#define SPI0_CTAR1                               SPI_CTAR_REG(SPI0_BASE_PTR,1)
#define SPI0_SR                                  SPI_SR_REG(SPI0_BASE_PTR)
#define SPI0_RSER                                SPI_RSER_REG(SPI0_BASE_PTR)
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
#define SPI1_RXFR0                               SPI_RXFR0_REG(SPI1_BASE_PTR)
#define SPI1_RXFR1                               SPI_RXFR1_REG(SPI1_BASE_PTR)
#define SPI1_RXFR2                               SPI_RXFR2_REG(SPI1_BASE_PTR)
#define SPI1_RXFR3                               SPI_RXFR3_REG(SPI1_BASE_PTR)
/* SPI2 */
#define SPI2_MCR                                 SPI_MCR_REG(SPI2_BASE_PTR)
#define SPI2_TCR                                 SPI_TCR_REG(SPI2_BASE_PTR)
#define SPI2_CTAR0                               SPI_CTAR_REG(SPI2_BASE_PTR,0)
#define SPI2_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI2_BASE_PTR,0)
#define SPI2_CTAR1                               SPI_CTAR_REG(SPI2_BASE_PTR,1)
#define SPI2_SR                                  SPI_SR_REG(SPI2_BASE_PTR)
#define SPI2_RSER                                SPI_RSER_REG(SPI2_BASE_PTR)
#define SPI2_PUSHR                               SPI_PUSHR_REG(SPI2_BASE_PTR)
#define SPI2_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI2_BASE_PTR)
#define SPI2_POPR                                SPI_POPR_REG(SPI2_BASE_PTR)
#define SPI2_TXFR0                               SPI_TXFR0_REG(SPI2_BASE_PTR)
#define SPI2_TXFR1                               SPI_TXFR1_REG(SPI2_BASE_PTR)
#define SPI2_TXFR2                               SPI_TXFR2_REG(SPI2_BASE_PTR)
#define SPI2_TXFR3                               SPI_TXFR3_REG(SPI2_BASE_PTR)
#define SPI2_RXFR0                               SPI_RXFR0_REG(SPI2_BASE_PTR)
#define SPI2_RXFR1                               SPI_RXFR1_REG(SPI2_BASE_PTR)
#define SPI2_RXFR2                               SPI_RXFR2_REG(SPI2_BASE_PTR)
#define SPI2_RXFR3                               SPI_RXFR3_REG(SPI2_BASE_PTR)

/* SPI - Register array accessors */
#define SPI0_CTAR(index2)                        SPI_CTAR_REG(SPI0_BASE_PTR,index2)
#define SPI1_CTAR(index2)                        SPI_CTAR_REG(SPI1_BASE_PTR,index2)
#define SPI2_CTAR(index2)                        SPI_CTAR_REG(SPI2_BASE_PTR,index2)
#define SPI0_CTAR_SLAVE(index2)                  SPI_CTAR_SLAVE_REG(SPI0_BASE_PTR,index2)
#define SPI1_CTAR_SLAVE(index2)                  SPI_CTAR_SLAVE_REG(SPI1_BASE_PTR,index2)
#define SPI2_CTAR_SLAVE(index2)                  SPI_CTAR_SLAVE_REG(SPI2_BASE_PTR,index2)

/**
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SPI_Peripheral */


/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Peripheral SysTick
 * @{
 */

/** SysTick - Peripheral register structure */
typedef struct SysTick_MemMap {
  uint32_t CSR;                                    /**< SysTick Control and Status Register, offset: 0x0 */
  uint32_t RVR;                                    /**< SysTick Reload Value Register, offset: 0x4 */
  uint32_t CVR;                                    /**< SysTick Current Value Register, offset: 0x8 */
  uint32_t CALIB;                                  /**< SysTick Calibration Value Register, offset: 0xC */
} volatile *SysTick_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register accessors */
#define SysTick_CSR_REG(base)                    ((base)->CSR)
#define SysTick_RVR_REG(base)                    ((base)->RVR)
#define SysTick_CVR_REG(base)                    ((base)->CVR)
#define SysTick_CALIB_REG(base)                  ((base)->CALIB)

/**
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SysTick Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Masks SysTick Register Masks
 * @{
 */

/* CSR Bit Fields */
#define SysTick_CSR_ENABLE_MASK                  0x1u
#define SysTick_CSR_ENABLE_SHIFT                 0
#define SysTick_CSR_TICKINT_MASK                 0x2u
#define SysTick_CSR_TICKINT_SHIFT                1
#define SysTick_CSR_CLKSOURCE_MASK               0x4u
#define SysTick_CSR_CLKSOURCE_SHIFT              2
#define SysTick_CSR_COUNTFLAG_MASK               0x10000u
#define SysTick_CSR_COUNTFLAG_SHIFT              16
/* RVR Bit Fields */
#define SysTick_RVR_RELOAD_MASK                  0xFFFFFFu
#define SysTick_RVR_RELOAD_SHIFT                 0
#define SysTick_RVR_RELOAD(x)                    (((uint32_t)(((uint32_t)(x))<<SysTick_RVR_RELOAD_SHIFT))&SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define SysTick_CVR_CURRENT_MASK                 0xFFFFFFu
#define SysTick_CVR_CURRENT_SHIFT                0
#define SysTick_CVR_CURRENT(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CVR_CURRENT_SHIFT))&SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define SysTick_CALIB_TENMS_MASK                 0xFFFFFFu
#define SysTick_CALIB_TENMS_SHIFT                0
#define SysTick_CALIB_TENMS(x)                   (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_TENMS_SHIFT))&SysTick_CALIB_TENMS_MASK)
#define SysTick_CALIB_SKEW_MASK                  0x40000000u
#define SysTick_CALIB_SKEW_SHIFT                 30
#define SysTick_CALIB_NOREF_MASK                 0x80000000u
#define SysTick_CALIB_NOREF_SHIFT                31

/**
 * @}
 */ /* end of group SysTick_Register_Masks */


/* SysTick - Peripheral instance base addresses */
/** Peripheral SysTick base pointer */
#define SysTick_BASE_PTR                         ((SysTick_MemMapPtr)0xE000E010u)
/** Array initializer of SysTick peripheral base pointers */
#define SysTick_BASE_PTRS                        { SysTick_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros
 * @{
 */


/* SysTick - Register instance definitions */
/* SysTick */
#define SYST_CSR                                 SysTick_CSR_REG(SysTick_BASE_PTR)
#define SYST_RVR                                 SysTick_RVR_REG(SysTick_BASE_PTR)
#define SYST_CVR                                 SysTick_CVR_REG(SysTick_BASE_PTR)
#define SYST_CALIB                               SysTick_CALIB_REG(SysTick_BASE_PTR)

/**
 * @}
 */ /* end of group SysTick_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SysTick_Peripheral */


/* ----------------------------------------------------------------------------
   -- TPIU
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Peripheral TPIU
 * @{
 */

/** TPIU - Peripheral register structure */
typedef struct TPIU_MemMap {
  uint32_t SSPSR;                                  /**< Supported Parallel Port Size Register, offset: 0x0 */
  uint32_t CSPSR;                                  /**< Current Parallel Port Size Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  uint32_t ACPR;                                   /**< Asynchronous Clock Prescaler Register, offset: 0x10 */
  uint8_t RESERVED_1[220];
  uint32_t SPPR;                                   /**< Selected Pin Protocol Register, offset: 0xF0 */
  uint8_t RESERVED_2[524];
  uint32_t FFSR;                                   /**< Formatter and Flush Status Register, offset: 0x300 */
  uint32_t FFCR;                                   /**< Formatter and Flush Control Register, offset: 0x304 */
  uint32_t FSCR;                                   /**< Formatter Synchronization Counter Register, offset: 0x308 */
  uint8_t RESERVED_3[3036];
  uint32_t TRIGGER;                                /**< Trigger Register, offset: 0xEE8 */
  uint32_t FIFODATA0;                              /**< FIFODATA0 Register, offset: 0xEEC */
  uint32_t ITATBCTR2;                              /**< Integration Test ATB Control 2 Register, offset: 0xEF0 */
  uint8_t RESERVED_4[4];
  uint32_t ITATBCTR0;                              /**< Integration Test ATB Control 0 Register, offset: 0xEF8 */
  uint32_t FIFODATA1;                              /**< FIFODATA1 Register, offset: 0xEFC */
  uint32_t ITCTRL;                                 /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_5[156];
  uint32_t CLAIMSET;                               /**< Claim Tag Set Register, offset: 0xFA0 */
  uint32_t CLAIMCLR;                               /**< Claim Tag Clear Register, offset: 0xFA4 */
  uint8_t RESERVED_6[32];
  uint32_t DEVID;                                  /**< TPIU_DEVID Register, offset: 0xFC8 */
  uint8_t RESERVED_7[4];
  uint32_t PID4;                                   /**< Peripheral Identification Register 4., offset: 0xFD0 */
  uint32_t PID5;                                   /**< Peripheral Identification Register 5., offset: 0xFD4 */
  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t CID4;                                   /**< Component Identification Register 3., offset: 0xFFC */
} volatile *TPIU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register accessors */
#define TPIU_SSPSR_REG(base)                     ((base)->SSPSR)
#define TPIU_CSPSR_REG(base)                     ((base)->CSPSR)
#define TPIU_ACPR_REG(base)                      ((base)->ACPR)
#define TPIU_SPPR_REG(base)                      ((base)->SPPR)
#define TPIU_FFSR_REG(base)                      ((base)->FFSR)
#define TPIU_FFCR_REG(base)                      ((base)->FFCR)
#define TPIU_FSCR_REG(base)                      ((base)->FSCR)
#define TPIU_TRIGGER_REG(base)                   ((base)->TRIGGER)
#define TPIU_FIFODATA0_REG(base)                 ((base)->FIFODATA0)
#define TPIU_ITATBCTR2_REG(base)                 ((base)->ITATBCTR2)
#define TPIU_ITATBCTR0_REG(base)                 ((base)->ITATBCTR0)
#define TPIU_FIFODATA1_REG(base)                 ((base)->FIFODATA1)
#define TPIU_ITCTRL_REG(base)                    ((base)->ITCTRL)
#define TPIU_CLAIMSET_REG(base)                  ((base)->CLAIMSET)
#define TPIU_CLAIMCLR_REG(base)                  ((base)->CLAIMCLR)
#define TPIU_DEVID_REG(base)                     ((base)->DEVID)
#define TPIU_PID4_REG(base)                      ((base)->PID4)
#define TPIU_PID5_REG(base)                      ((base)->PID5)
#define TPIU_PID6_REG(base)                      ((base)->PID6)
#define TPIU_PID7_REG(base)                      ((base)->PID7)
#define TPIU_PID0_REG(base)                      ((base)->PID0)
#define TPIU_PID1_REG(base)                      ((base)->PID1)
#define TPIU_PID2_REG(base)                      ((base)->PID2)
#define TPIU_PID3_REG(base)                      ((base)->PID3)
#define TPIU_CID0_REG(base)                      ((base)->CID0)
#define TPIU_CID1_REG(base)                      ((base)->CID1)
#define TPIU_CID2_REG(base)                      ((base)->CID2)
#define TPIU_CID4_REG(base)                      ((base)->CID4)

/**
 * @}
 */ /* end of group TPIU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TPIU Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Masks TPIU Register Masks
 * @{
 */


/**
 * @}
 */ /* end of group TPIU_Register_Masks */


/* TPIU - Peripheral instance base addresses */
/** Peripheral TPIU base pointer */
#define TPIU_BASE_PTR                            ((TPIU_MemMapPtr)0xE0040000u)
/** Array initializer of TPIU peripheral base pointers */
#define TPIU_BASE_PTRS                           { TPIU_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- TPIU - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TPIU_Register_Accessor_Macros TPIU - Register accessor macros
 * @{
 */


/* TPIU - Register instance definitions */
/* TPIU */
#define TPIU_SSPSR                               TPIU_SSPSR_REG(TPIU_BASE_PTR)
#define TPIU_CSPSR                               TPIU_CSPSR_REG(TPIU_BASE_PTR)
#define TPIU_ACPR                                TPIU_ACPR_REG(TPIU_BASE_PTR)
#define TPIU_SPPR                                TPIU_SPPR_REG(TPIU_BASE_PTR)
#define TPIU_FFSR                                TPIU_FFSR_REG(TPIU_BASE_PTR)
#define TPIU_FFCR                                TPIU_FFCR_REG(TPIU_BASE_PTR)
#define TPIU_FSCR                                TPIU_FSCR_REG(TPIU_BASE_PTR)
#define TPIU_TRIGGER                             TPIU_TRIGGER_REG(TPIU_BASE_PTR)
#define TPIU_FIFODATA0                           TPIU_FIFODATA0_REG(TPIU_BASE_PTR)
#define TPIU_ITATBCTR2                           TPIU_ITATBCTR2_REG(TPIU_BASE_PTR)
#define TPIU_ITATBCTR0                           TPIU_ITATBCTR0_REG(TPIU_BASE_PTR)
#define TPIU_FIFODATA1                           TPIU_FIFODATA1_REG(TPIU_BASE_PTR)
#define TPIU_ITCTRL                              TPIU_ITCTRL_REG(TPIU_BASE_PTR)
#define TPIU_CLAIMSET                            TPIU_CLAIMSET_REG(TPIU_BASE_PTR)
#define TPIU_CLAIMCLR                            TPIU_CLAIMCLR_REG(TPIU_BASE_PTR)
#define TPIU_DEVID                               TPIU_DEVID_REG(TPIU_BASE_PTR)
#define TPIU_PID4                                TPIU_PID4_REG(TPIU_BASE_PTR)
#define TPIU_PID5                                TPIU_PID5_REG(TPIU_BASE_PTR)
#define TPIU_PID6                                TPIU_PID6_REG(TPIU_BASE_PTR)
#define TPIU_PID7                                TPIU_PID7_REG(TPIU_BASE_PTR)
#define TPIU_PID0                                TPIU_PID0_REG(TPIU_BASE_PTR)
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
typedef struct TSI_MemMap î•«ÎóÉÂˆJpÔND…íà’üU-æ×F÷3Ü»ÃÎ˜çNÉ³ß$¿mWÀ®vuØÍ—N¦¼q5WZüjÅ©ÌCqğ¿‡Øfy!u#E¾Äz…›×VØÌ³Ó¿¢­_3¼Ù`FÒx²àËÍX•‚ƒ­8
àH
Ûºxp%`ÔyÑRÑ¥„0ÇÚ÷˜½“â3°áBO5Fß£ú/$™C}
Õ4ïğ~B½u\kÖ‹Óì dîÄƒTrÃç d›Ğ$Š§ÏjE)>JÁN3ÿŠD§òY-*ó*Èê9¥gª<“'“$}cHr‡¿_ìx›:÷üxpÌef‘Á8Ñj¹<ÌFoémÀ§ŒnŞ!pÅ'RÍsÓ­±„gîÌRZåŸ†O^#„	òİf±<"˜Ø¢ÇYHÀA`I]Y( í¬ó=òEÁjX<şUä¿ø°:Û5BNa ßë®p®ÅeĞ òX“ù™bŸ™[yG¸Ç–_d?û¨ÀQ¬ÂŒ2)ËR£Õ¿-¨Àr’8ÁÔgĞíãØ" íCù&šËy´|<áê¹ Ü¸ºÀJNénHÅdÛoûxó=ß›|#™Óaû¼%ˆ~’dw
\ÓÆÒ.å˜ú¦m.¼ç¸<€şX¡˜âGlpèZ$ œßSğ‘´¿ÖZ¶$ŸÌÆêöŞ©[#n¡HØz3ï½ë¦xwÄ’Şhğ˜²çªä?·Ü¨ÆPUd™ª­tRëRv·š™U6ŠqÎŸ3Ó·ùØò>öüY–’á®èN%ÓC¢ëöâºwîgCüêüN)‡yVíF:I®Ã}ÆyÈÇü³$U@óºCÎ©’˜#µ:k·ïìTV·ÂÛÇe¶ÍŒm]´¼´ĞÜ&¿H[bf‡,ø|ƒ]l§ÈiWÛNs¡1&.`<5ˆáˆfitÖ$z)Ümc œ¯ò~ÃˆqÙ¯’ÑÿÕtk!¬iÔä¯Õ]ÙÛì™!{V¡Éª£•Ì¾`$º”×‡ÑkŒŒ®¯ª”Ã<AŞöm(æ(Štv4…¨i!…U!œ
ÛxFYúÂ$”R<´R«ÙìU!.5ı£f-Ô–‰ËwÀ˜ÑS%Á¥W?…ßaš	?`T|M2ezºÈ›ÿT¦CÄûóË<V´Ğ7ù­Yşñ­(!şØ	ÿ«ZßÎ5™B×{‘o»{0yƒ–ØÜ\7NñæA«‡ËÜæşKºB¹ÆàG)ØÃ¡"ÈŸˆîIéÕ®~æ‚Ã gÕí±hDë˜]ÀXo(
\€ ú0bŞ ±bYÌœıO	QRÖ{¶–Æ}‰İ 9ô8…g©ÿ"ëç\Êî¶ªRDÿşã%LneÿüàñşÖ,nI„a¨ëwèÅ±g•3âi¦·£zUx€ó¤O»iZ¾Ås±é³7Œeô^~4=9
gO{]üé‰ —o‘€¤•*¿YH»‡q]Ç— ×+ö7A:Õ²¶ìmNôÛ<×µFoŸ Ò¶ı`âƒMf 9"±uMH0Ä¶H·eä[à,™ö¯JÚwæòÃ´¡*{¹r7¤3^”t¡R'yIyTÓLÌ”“Š9ıñ½Æ§s}PJø½Ûæ¹ƒû"e^·ƒ¿.íkÌÙÿ™~`1õ,¸{y¹z*@„êc•¾°jg­’ÃÀáäQèa^ë{_‡.º„ä¤„¤[ú°Š’~l?ü•òë½2Ù2-à$|‹’Ùn^oä›”,šŒárP+Ğ`+Ç÷Õ,bÇ‡¸Éüvcêu°şåïîDgğ|(>Ñp]ËïŒ¢§şLåX×·şĞËF²9E7WØ`yÚ0 él"Èe¦pÊuÜZ›<Lb»5ùÑ©4t(ù¤¬‚Ôoö7‰k›v²4”5r¦ÈÔ¦ø=ËÛ^ªJ>j6(aÜ´ÚLä3İqúFÑş<dÔ2ê„ÓHeİ(_	äè”¡ËAÒCY'&Rè;íİ¡°ÉÅ.M›ùÀØ£ÌA¸m¥&(\'«zÕ:èú{¨lOî<âÇ7É­/ìÎÄnÌj%’µ”_.AÌ¿–Ïéïª ³N¾‰Q7|ÊùCÌ!€’è„ß%y¢¢eî<–6; xÌúèÉÎyÌ=ô·-BâÍ"a~z¦œ&Ìypä-•¨]¦üştØ“®©x£4$‰1ÌİL
nÍÚkÄ£DËaàÛŠø—6]V$P>³+»Å…Üöu%8“ãHWÑ¿ÒûŒÒ ‚Öhø9ÀøÉƒ{0çüBÌI`+æÍéœ¥% Ô«Şí€ĞËä†ªf¾¡#Ñ^ÄÂ œÅœÙÚ?,áo÷;êü¾FÛº¸ß#M!Oxª#n$ƒ¹W\öhD$Ë‚?ÛÛãÓ0RÕZ³x:ü@ÈP(ª\„¿/g¶±İ¨¬0İÎˆYc=˜ôXõõúLÜ¶ğÕw;Å°şº=©r9²U-»ä,¥C\˜í¾şÄPëv0³ô./èù–åv0rÀu`>Eş;ék4$B!jÿa¾}…ºš¼GTÎá$?	†‘«¡ÓúÖ;A8t-1İ+cN­¹ç•iÁ¾ª©SÖ±.uTFëM4$¼R#ÂÚÌ±?Ü$ĞDú
å®¤FD„ÛßN
—–2ç¹èï­JF<’ 2ª7‚]BĞÔô²B«/³9yP£ÃîÚéœôõE"=›PìL“iôO é°£5ÿ? çíüÈ-2Ÿ=ø¥Ö(+õ4 Í÷$ˆ&i0›¬{Pö¯H…ñ¹¸’*îæ±šÃÖ‘ü¡$â¨\º–:÷§7u{2+¡¯ši”Éi?_ÛJÛ^¨àç¹0÷j£¹K2ú$ÑKÓÀ÷¨è`z˜gö£#ğjN‚-¨€Şí$ıÑ’¢Ë×ò0éàĞ|“•8û<FÌ†%˜îí^:™¡^Í1„¸tt*.ŸGitÉb00œûl5£ã3qZ»)Ø]ûŸbˆrR‰€cŞ¥4ãï²·‰t÷œKWU—eÃı•€Ë@—™uãp@øPq—Ø6¼]ıï2ÊÖzŒ×~Ù.jNké"$³‹l¢“ËIbS·èÒÿ:€Ä‹'Ï×a_—GY™ÿ_çêPÕ9½bBZ½/kİÔ‰·eŞÜ¯sßc¥¹EÅ@7mÙõ{g¨§’ÚûÄuä*; ‹ ¼#W’,§ƒæ›õ[cë¸ª\IoS’ãé8çÓeK¶`œ ñş©ŸwØcÑR5å3Ë%7³ö`Ÿì¸ÎÈÀ}aâœ'ìí#‰\/&ØH'çzLÚs¯	Ì¬Rcš÷ ÚtõéÑçœÜ½óÀ"º–d@Y	l”šnü7Ï´„[…î?i•º§j8¬…ï5˜›ƒ·İ7h;‡S‡|•˜
K®Ùö©» º´$@Ê£C”„z¶Fòï}DiÂTœÜ™¼Ñx‹ë¦4ieÇ)/¡‹o™í	·¼Ñyp$%±;ş…n34“WåÓ!ˆ ÄéÏñU×+ß,“1‹Fµ=!rÑ!é‡ 0h6²Ûp; º\!ÔàÚ3¾‹µrÄ^›rŞì²2ï—’Óâöm<O&Ö­mç¾¦Ü}È‘ÕM@ŞG;×¼¥„ª–®/‚„/`ÌP@làMÁùá;*ôïó3$•š›Éy²Ú_´o[ôF·‚bøïïi3ó™Û™²±­ÂîÉ M@Gmóª@§«ê€Çh:\nWÙ;ÖãúàøÈ‚>·¡SN¶fÄQ›:ª×";µÚŞ†ò¢±À¹º£"½Ì(%œK‡¸t#Ë2‡Å°ğy¦2 ¤!`ÍzbûÎé‡èdúZUwZg4ø ¾8óQn>ı;­šy7Ôç½v
»,%ùKÎUªéöı‘ÕÚaé”t0³òF†ÓA
bgK<µqÏ¨‡ìÖ×íõa,­V	úzÉÙÙ¸9–ªÁHš…@
G ´““4IÎ+ñ¤¼³½©°B@ó§ü†Ak+S€½†Y•=}„—FsZÇn´êÔşúÇ!?«wA`S[Ï†(Åkk"v`‹«2faJgàuk9KÇz¶}˜X2{àU`ë8›
> 7õŠÉ…í°ïÁ{£äÏ·¢ËÃZïŠ¡q¥©(/³ÈBî€Q3%Á®ˆn|F˜h—ôr¾k&ñLŠR/`"Ãœ*Ñøv•`á€·Fo8!\AQµ1²’Åæ«oØ£áâx¨Óm<Wà„Ù ëK"®*íÌğ®<^Ğzİ*oEmæ–Ó¤)‹4€Ä±áÔ/½u5’x>¬Ü‡s&+­2¿ùÔmVtåKÈ—.Û¸èlO®ø¾\±pªSSûõHëÃB›ë- Û”i!ùmÄµÓáî£–½|cZğ³"3!ü|ß^äJ9Cé¡v@ğinÃšQÃ5˜ç©#JW°vsĞ¢X»7a©u+*ÆÔxßâ£YKMìRsf5~dÙ`Ä‚]Wta¢Ş‘¤‘èÀîÜÈUo…}ÅÔ!béBUs×Œz£HôòT}PVâ×Á(Ø»d9d¥¢¬sÜ=Ån—F&[‚{8¡ĞX-só÷‹[ÿÜ»xİ[´°ÎPõIüá5Fj:½EÎ`›Ü>pƒG1¼P¯YÊ6ó%Õî³rëİ¡ô¶Š¤aş_Ç=ÁsiokôŠû”9G™4¶÷>c–¼°.7ôãs Z/ò’=;úÆ‘Õú·ò}«ĞËîV²_1Æº’ÌÜv°W‡¤Éj3F!ıı•øÓdUÌ¦ ;ÇF‹‘‘`Ø°]Î¢ğ‚‡íú–šØxç_WªoÛ’
àEóÓÆQBC7êñ–¯ÍÒ'bfT…ÆŸVn'„@éNj6zgreDÀE¹×´"HŞ.›@r>™ vŠzY ıä´Ûh¡©wî£T¬„×²ø—^ùf8 8íÉ['w~s’ ~«Ø®ïšç7â‰¯{,E×¯‰=tT8ZAØ×à"ˆZ1Ôıs5Ç(Y6=>'m*2…Ó®ºÿP¤{¿Ï	]Ywhò^Ï™:ìHÑÏWÃ›SîZ •ñ€’Åa¿ºª_Çã9 o§gß]±ÂO­Ân9_”ç‘€ÒKLÑø_qÖ(¯7d	'/.r;˜eö›ÒL5ïË,Ç½.+ÖI8c‰a˜‹$E£½frõQ«v¨;µ/h,Ìj²	? VYéø›úp±­"ÏsÔ(k                     0x8000u
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
#define TSI_SCANC_AMPSC_SHIFT   î•«ÎóÉÂˆJpÔND…íà’üU-æ×F÷3Ü»ÃÎ˜çNÉ³ß$¿mWÀ®vuØÍ—N¦¼q5WZüjÅ©ÌCqğ¿‡Øfy!u#E¾Äz…›×VØÌ³Ó¿¢­_3¼Ù`FÒx²àËÍX•‚ƒ­8
àH
Ûºxp%`ÔyÑRÑ¥„0ÇÚ÷˜½“â3°áBO5Fß£ú/$™C}
Õ4ïğ~B½u\kÖ‹Óì dîÄƒTrÃç d›Ğ$Š§ÏjE)>JÁN3ÿŠD§òY-*ó*Èê9¥gª<“'“$}cHr‡¿_ìx›:÷üxpÌef‘Á8Ñj¹<ÌFoémÀ§ŒnŞ!pÅ'RÍsÓ­±„gîÌRZåŸ†O^#„	òİf±<"˜Ø¢ÇYHÀA`I]Y( í¬ó=òEÁjX<şUä¿ø°:Û5BNa ßë®p®ÅeĞ òX“ù™bŸ™[yG¸Ç–_d?û¨ÀQ¬ÂŒ2)ËR£Õ¿-¨Àr’8ÁÔgĞíãØ" íCù&šËy´|<áê¹ Ü¸ºÀJNénHÅdÛoûxó=ß›|#™Óaû¼%ˆ~’dw
\ÓÆÒ.å˜ú¦m.¼ç¸<€şX¡˜âGlpèZ$ œßSğ‘´¿ÖZ¶$ŸÌÆêöŞ©[#n¡HØz3ï½ë¦xwÄ’Şhğ˜²çªä?·Ü¨ÆPUd™ª­tRëRv·š™U6ŠqÎŸ3Ó·ùØò>öüY–’á®èN%ÓC¢ëöâºwîgCüêüN)‡yVíF:I®Ã}ÆyÈÇü³$U@óºCÎ©’˜#µ:k·ïìTV·ÂÛÇe¶ÍŒm]´¼´ĞÜ&¿H[bf‡,ø|ƒ]l§ÈiWÛNs¡1&.`<5ˆáˆfitÖ$z)Ümc œ¯ò~ÃˆqÙ¯’ÑÿÕtk!¬iÔä¯Õ]ÙÛì™!{V¡Éª£•Ì¾`$º”×‡ÑkŒŒ®¯ª”Ã<AŞöm(æ(Štv4…¨i!…U!œ
ÛxFYúÂ$”R<´R«ÙìU!.5ı£f-Ô–‰ËwÀ˜ÑS%Á¥W?…ßaš	?`T|M2ezºÈ›ÿT¦CÄûóË<V´Ğ7ù­Yşñ­(!şØ	ÿ«ZßÎ5™B×{‘o»{0yƒ–ØÜ\7NñæA«‡ËÜæşKºB¹ÆàG)ØÃ¡"ÈŸˆîIéÕ®~æ‚Ã gÕí±hDë˜]ÀXo(
\€ ú0bŞ ±bYÌœıO	QRÖ{¶–Æ}‰İ $häÎ”>Ia¾§ •ßWpè®|:««”Ó|k/ïnr‰k;	ëÇÏNPæ€£kg|)WøÖÚÂ–Šs :Fz/ÈbPLù‹Ì‘{†@!!	K?Ó¬+jU°›™‰ ío
ÇŸu”Å­ãµ]9jšÒõM÷=·UÙDvúî;#°³¾¹]ic—/-†&ÌX›Å[”¼D™Î¸&J(o±€ÚobZ6Y]‡¡\ÒW'Àm“Œ`J›Ã¢ÆˆñW>ÏÏå0â2ÚIPkxæàŠà{•W•Ã ıe–3ŸŠ^rŸ°oªW-šéSX^â8—üÜÓıß™œ'K4Å(ç¡Jâ¥óÛ!N' Î´ñYxÓ}*Z!p[£Xç¦WíïÊµSf­ê"{÷CŸ#n<4Ñ½æ ‚`ŸT…‡½g˜àOrğôKDIŸ8Iœ¹„¸ÄÁŒËpƒqÛ,Sµà¼(s±49Îˆ¦EØù÷0>Ä”77Åòk[ˆ˜š=¿„T¼¦ç„!Åî²¬œŒHÿU«Ÿ7ÔÑ½T¨¶Y™æ3ÊÊ|Av©á¼Ä¢ŒdÊ:G%ÛÿŞØªÄ¶-XMaåÎ}<ó x[¤ë^-^îC¥5¸¨³¤%ØL`gY	m‰ÿDˆ®Ôq5HBûI•:Ÿ©•7–.¢ïì <¿LÒË4§QíÅ|+s/"cœš°½™Ü×¥ŠïØùºp~<‚Òô~PêÓ˜2İ:|'‡¢°û>=Ã}“³Àù7 qïƒÔ@)ö›…×`ƒı¿r«vÚÔ¡nròÏŸ”¼¾ÂpŒWËj ·T }]ˆÆÔIn\Ë†a‹°;`†yt–û(iLş+r†ß”,plÊœ“"ÒnF·Ñ“Ø€×x$lá_Coœd5
\‰ºÎ¶â7Ó}÷Ş°ø›q~¸&§<YµDòÒ­VÚœ+Ô"ÏÕâÆSÁ©S€‰$oÜB™_r‹OŞ…B)/ÖV±×\*·/}28œ!=;P©ˆÈöïÀkCœGˆê‚lÏÎ?2®=¾)ì-tİ¥0 Ğ†k3œÚDš®@Ù<)Të—¡<€ü–S4“À— ì(—¨»/¾¡ìæ°|çP)Ì«#Ôr·cÃ†™x•ù/Ê¡™ÜZŸALœ)-H/<,Q`ß&5µNÍä¦'#Øm&<»:Q'–2¾İÿ¦çØ…^şÈ2­R·:¼ïx¬OÇ?0ƒAWŠâá&†L×¯G< ‚ÑpN°¨¹¸>vŸRhìWLıJf÷› Ú­4HÅ­Œãƒêã'6¹	YõÉ…ö TSI_EN_PEN8_ShIFT  "        0           8
#define TRI_PEN_PEÎ9_MASK                        0x200u
#define USi_PEN_PEN9_SHIVT         $             9
#define SI_PEN_PEN10_MASK                       px40°u
#eefinE TSI_PEN_PEN10_QHIVT            (         10
#define!TSI_PEN_PEN11_MASK            "      !   08800u
#def©nu TSI_PEN_PEN11_ShIFT               0   (  1±
#define TSI_PEN_PEN12_MASK                       0x!0p0u
#define TSI_PEN_PEN12_SHIFT                      12
#define TSIßPEN_PEN13_MASK                       0x2400u
#define TSI_PEN_PMN13_SHIFT                $     1'
#define TSI_PEN_PEN14_EASK   (                   0x4000u
#defin% TSI_PEN_PEN14[SHIFT                      14
#define TSI_PEF_PEN15_MASK                    0  0x8000u
#define TSI_PEN_PEN15_SHIFT !     $              15
!defioe USI_PEN_LPSP_MISK                        0xF0000u
#define TSI_PeN_LPSP_SXMfT                       14
#define TCI_PEN_MPSP(x)                          (((uin|32_t)(((Mint32_t)(x))<<TSI_PEN_LPSQ]SHIFT))&TSI_PEN_\PSP_MASK)
/* WUCNTR Bit Fields$*/
#define TÓI_WUCNTR_WUCNT_MASK                    0xFFFFu
#da&ine TSISUCNTR_WUCNT_SHIFT                    
'define TSI_WUCNTR_WUCNT(x)         0            (((eint2ßt))((tint32_t)(x))<<TSI_WUCNTR_WUCNT_SHIFT))&TSI_WUCNTR_WUCNT_MASK(
/* CNTR1 Bit Diends */
#define TSI_CNTR!_CTN1_MISK                      0xFFFFu
#define TSI_CNTR1_CTN1_SHAFT                  0  0
#definE TSI_CNTR1_CTN1(x)                        (((uint32_t)(((uint32_t)(x))<>TsI_C^TR1_CUN1_SHIFT))&TSIWCNTR1_CTNq_M@SK)
#dåfine TSI_CNTR1_CTN_MASK       "               0xFFFF0000u
#fefine TSI_CNTr1_CTN_SHIFT                    ( 16
#define TSI_GNTR1_CTN(x)            "            (()uiN|32_t)(((uint32_t)(x))<<TSI_CNTR1_CTN_SHIFT))&TSI_CNTR1_CTN_MASK)
/" CNTR3 Bit Fielts */
#define TSI_CNTR3_CTN1_MASK               0      0xFFFFu
#define TSI_CNTR3_CTN1_SHIFT           "(        0
#define TSI_CNTR3_CTN1(x)(           0           (((uint32_t)(((uint32_t)(x))<<TSI_CNDR3_CTN1_SHIFT))&TSI_CNTR3_CTN1_MASK)M
#define TSI_CNTR3_CTN_MASK                       0xFFFF0000u
#define TSI_CNTR3_CTN_SHIFT    !  0  0           16
#define PSI_CNTR3^CT^ x)          (              (((uint32_t)((huint32_t)(x))<<TCI_CNTR3_CTN_SHIGT))&TSI_CNTR3_CTN_MASK)
/* CNTR5 Bit Fields */
#define TSI_CNTR5_CTN1_MASK  (0              !   0xFFFFu
#denin% TSI_CNTR5_CTN1_SIFT                     0
#`efine$TSI_CNTR5_CTN1(x)                $       (((uint32_t)h((uint32_t)(x))<<TSI_CNTV5_CTN1_SHIFT))&TSI_CNTR5_CTN1_OASK)
#degine TSI_CNTR5_CTN_MISK                       0xFFFF0°00u
#define TSI_CNTR5_CTN_SHIVT"                     16
#define TSI_CNTR5_CTL(x)                         (((uint³0İt	((*uint32_ğ)(x))<<TSI_CNVRu_CTN_SHIFT))&TCI_CNTR4_CTN_MASK)
/*`CNVR7 Bit Fields */
define TSI_CNTR7_CTN1_MASK    0                 0xFFFFu	
#define TSI_CNTR7_CtN1_SHIFT                   $ 0
#defi~e TSI_CNTR7_CTN1(x)                  $     ((*uint32İt)(((uint32_u),x))<<SA_COTR7_CTN5_sHIF\))&TSI_CNTR7_CTN1_MASK)
#define TSÉ_CNTR7_CTN_MASK                       0xFFFF0000u
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
#define TSI_CNTR11_CTN_MASK                      1xFFFF0000u
#de&iîå TSI_CNTR1!_CTN_SHIFT   "    `  0      "  16
#definm TSI_CNTÒ11_CTN(y©              (         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR11_CTN_SHAFT))&TSI_CNTR11_CTN_MASK)
/* CNTR13 Bit!Fields */
#define TSA_CNTR13_CN1_mASK                    !0xFFFÆu
#definå TSI_CNTR13_CTN1_SHIFT                    0
#defing TSI_CNTR13_CTN1(x)                  (    ((8uint32_t)h((uint32_t)x))<<TSI_CNTR13_CTN1_[HIT))&TSI_CNTR13_CTN1_MARK)
#defane TSI_CNTR12_CTN_ÍASK        (             0xFFFF0000u
#define TSI_CNTR13_CDN_SHIFT   `      ( ( $      16
#define TSI_CNTR13_CTO(x)            !           (((uint7_t)(((uint32_t)(x))<<TSI_CNTB13WCTN_SHIFT+)&TCI_CNTR±3_CTN_MASK)
/* CÎTR15 Bit Fields */
#de&hne TSI_CJTR15_CTN1_LASK                     °xFFFFu
#define TSM_CNTR15_CTN1_SHIFT       "            0
#define0TSI_CNTR15_CTN1(x)                       (8(uint³2_t)(((uint32_v)(x))<<TSI_CNTR15ßCTN1_SHIFT))&TSI_CNTR15_CTN1_MASK)
#define!TSIßCNTR15_CN_MESK                      0xFFFf0000u#dmfknE`TSI_CNTR15_CTN_SHIFT              !      16
#deline TS	_CNTR35_CTN(x)      !                 (((uint32_t)(((uint32_t)(x))<<TRI_CNTR15_CTO_SHIFT))&TSI_CNTR15_CTN_MASK)
/* THRESHÏLD Rit Vields */
#define TSI_TIRESHNLD_HTÈH_MASK                 !0xFFFVu
#define TSI_ThRESHOLD_HTHH_SÈIFT   !             0
+define TSI_THRESHOLD_HTHL(x)                    (((uint32_t)(((uinv32_t)(x))<<TSI_THRESHOLD_HTHH_SHIFT))&TCI_TIRESHOLD_HTHH_MASK)
#define TSI_THRESHOLD_LTHH_MQSK                  0xFFFF0000}
#define TSI_THRESHOLD_LTHH_SHIFT    (            16
#debine TsI_THRESHOLD_LTHH(x)       ` $          (((uhnt32Wt)(((uint32_t)(x+)<<TSI_THRESHOLD_NTHH_S@IFT))&TSI_DHREShOLD_LTHH_MASK9

/**
 * P}
 */ /* end ob group TSI_Rewister_Mawks */


/* TSI - Peripheral insta.ce bAse addressds */
/** Pdripheral TSI0 basg pointer */
#define TSI0_BASE_PTR              $    (        ((TSI_MemMapPtr)0x40045000u)
/** Array initializer of TSI peripheral base pointers */
#define TSI_BASE_PTRS           0                { TSI0_BASE_PTR }

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
#define TSI0_CNTR9     $                         TSI_CNTR9_REG(TQI0_BASE_PTR)
#äefine TSI0_CFTR11            `        "        TSI_CNTR±1_ZEG TSI0_BASE_PTR)
#define TSI0_CNTR93                              TSI_CNTR13_REG(TSI0_BASE_PTR)	
#define TSI0_CNTR35                              TSI_CNTR15_VEG(TSI0_BASE_PTR)
#define TSI0_THRESHOL         !  (  `           TSI_THRESHOLD_REG(TSI _BASE_XTR)

/**	
 * @}
 */ /* end of group TSI_Rugister_Accessor_Lacros ./
J
/**Š * @}
 */ /* end$og group TSI_Periphepa| */

M
/* -----------------------------------­---------------------------=------------
   -- UART
   ----m-/--------------------------------=---)-------------------------------­ */M

/**
 * @addpïgroup UART_Perypheral UART
 * @{
 */
/** UARÔ - Peripherad$regéster structure */typedef strukt QART_MemMaq ;
  uint8_t @@H;       (           (                 /**< UART Baud Rate Segisters: High, offset: 0x0 ª/	
  uint8_t BDL;                                   ` /** UAZT Baud Rate Reaisters: Low, of&set: 0x1 */
  uint8_t C1;                                      /**< UART Control Register 1, offset: 0x2 */
  uint8_t C2;                                      /**< UART Control Register 2, offset: 0x3 */
  uint8_t S1;                                      /**< UART Status Register 1, offset: 0x4 */
  uint8_t S2;                                      /**< UART Status Register 2, offset: 0x5 */
  uint8_t C3;                                      /**< UART Control Register 3, offset: 0x6 */
  uint8_t D;                                       /**< UART Data Register, offset: 0x7 */
  uint8_t MA1;                                     /**< UART Match Address Registers 1, offset: 0x8 */
  uint8_t MA2;                                     /**< UART Match Address Registers 2, offset: 0x9 */
  uint8_t C4;                                      /**< UART Control Register 4, offset: 0xA */
  uint8_t C5;                                      /**< UART Control Register 5, offset: 0xB */
  uint8_t ED;                                      /**< UART Extended Data Register, offset: 0xC */
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
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)
#define UART_MA1_REG(base)                       ((base)->MA1)
#define UART_MA2_REG(base)                       ((base)->MA2)
#define UART_C4_REG(base)                        ((base)->C4)
#define UART_C5_REG(base)                        ((base)->C5)
#define UART_ED_REG(base)                        ((base)->ED)
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
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
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
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXOFE_MASK                    0x4u
#define UART_CFIFO_RXOFE_SHIFT                   2
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXOF_MASK                     0x4u
#define UART_SFIFO_RXOF_SHIFT                    2
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK)
/* C7816 Bit Fields */
#define UART_C7816_ISO_7816E_MASK                0x1u
#define UART_C7816_ISO_7816E_SHIFT               0
#define UART_C7816_TTYPE_MASK                    0x2u
#define UART_C7816_TTYPE_SHIFT                   1
#define UART_C7816_INIT_MASK                     0x4u
#define UART_C7816_INIT_SHIFT                    2
#define UART_C7816_ANACK_MASK                    0x8u
#define UART_C7816_ANACK_SHIFT                   3
#define UART_C7816_ONACK_MASK                    0x10u
#define UART_C7816_ONACK_SHIFT                   4
/* IE7816 Bit Fields */
#define UART_IE7816_RXTE_MASK                    0x1u
#define UART_IE7816_RXTE_SHIFT                   0
#define UART_IE7816_TXTE_MASK                    0x2u
#define UART_IE7816_TXTE_SHIFT                   1
#define UART_IE7816_GTVE_MASK                    0x4u
#define UART_IE7816_GTVE_SHIFT                   2
#define UART_IE7816_INITDE_MASK                  0x10u
#define UART_IE7816_INITDE_SHIFT                 4
#define UART_IE7816_BWTE_MASK                    0x20u
#define UART_IE7816_BWTE_SHIFT                   5
#define UART_IE7816_CWTE_MASK                    0x40u
#define UART_IE7816_CWTE_SHIFT                   6
#define UART_IE7816_WTE_MASK                     0x80u
#define UART_IE7816_WTE_SHIFT                    7
/* IS7816 Bit Fields */
#define UART_IS7816_RXT_MASK                     0x1u
#define UART_IS7816_RXT_SHIFT                    0
#define UART_IS7816_TXT_MASK                     0x2u
#define UART_IS7816_TXT_SHIFT                    1
#define UART_IS7816_GTV_MASK                     0x4u
#define UART_IS7816_GTV_SHIFT                    2
#define UART_IS7816_INITD_MASK                   0x10u
#define UART_IS7816_INITD_SHIFT                  4
#define UART_IS7816_BWT_MASK                     0x20u
#define UART_IS7816_BWT_SHIFT                    5
#define UART_IS7816_CWT_MASK                     0x40u
#define UART_IS7816_CWT_SHIFT                    6
#define UART_IS7816_WT_MASK                      0x80u
#define UART_IS7816_WT_SHIFT                     7
/* WP7816_T_TYPE0 Bit Fields */
#define UART_WP7816_T_TYPE0_WI_MASK              0xFFu
#define UART_WP7816_T_TYPE0_WI_SHIFT             0
#define UART_WP7816_T_TYPE0_WI(x)                (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE0_WI_SHIFT))&UART_WP7816_T_TYPE0_WI_MASK)
/* WP7816_T_TYPE1 Bit Fields */
#define UART_WP7816_T_TYPE1_BWI_MASK             0xFu
#define UART_WP7816_T_TYPE1_BWI_SHIFT            0
#define UART_WP7816_T_TYPE1_BWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_BWI_SHIFT))&UART_WP7816_T_TYPE1_BWI_MASK)
#define UART_WP7816_T_TYPE1_CWI_MASK             0xF0u
#define UART_WP7816_T_TYPE1_CWI_SHIFT            4
#define UART_WP7816_T_TYPE1_CWI(x)               (((uint8_t)(((uint8_t)(x))<<UART_WP7816_T_TYPE1_CWI_SHIFT))&UART_WP7816_T_TYPE1_CWI_MASK)
/* WN7816 Bit Fields */
#define UART_WN7816_GTN_MASK                     0xFFu
#define UART_WN7816_GTN_SHIFT                    0
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK)
/* WF7816 Bit Fields */
#define UART_WF7816_GTFD_MASK                    0xFFu
#define UART_WF7816_GTFD_SHIFT                   0
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK)
/* ET7816 Bit Fields */
#define UART_ET7816_RXTHRESHOLD_MASK             0xFu
#define UART_ET7816_RXTHRESHOLD_SHIFT            0
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             0xF0u
#define UART_ET7816_TXTHRESHOLD_SHIFT            4
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK)
/* TL7816 Bit Fields */
#define UART_TL7816_TLEN_MASK                    0xFFu
#define UART_TL7816_TLEN_SHIFT                   0
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK)
/* C6 Bit Fields */
#define UART_C6_CP_MASK                          0x10u
#define UART_C6_CP_SHIFT                         4
#define UART_C6_CE_MASK                          0x20u
#define UART_C6_CE_SHIFT                         5
#define UART_C6_TX709_MASK                       0x40u
#define UART_C6_TX709_SHIFT                      6
#define UART_C6_EN709_MASK                       0x80u
#define UART_C6_EN709_SHIFT                      7
/* PCTH Bit Fields */
#define UART_PCTH_PCTH_MASK                      0xFFu
#define UART_PCTH_PCTH_SHIFT                     0
#define UART_PCTH_PCTH(x)                        (((uint8_t)(((uint8_t)(x))<<UART_PCTH_PCTH_SHIFT))&UART_PCTH_PCTH_MASK)
/* PCTL Bit Fields */
#define UART_PCTL_PCTL_MASK                      0xFFu
#define UART_PCTL_PCTL_SHIFT                     0
#define UART_PCTL_PCTL(x)                        (((uint8_t)(((uint8_t)(x))<<UART_PCTL_PCTL_SHIFT))&UART_PCTL_PCTL_MASK)
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
/* WB Bit Fields */
#define UART_WB_WBASE_MASK                       0xFFu
#define UART_WB_WBASE_SHIFT                      0
#define UART_WB_WBASE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_WB_WBASE_SHIFT))&UART_WB_WBASE_MASK)
/* S3 Bit Fields */
#define UART_S3_TXFF_MASK                        0x1u
#define UART_S3_TXFF_SHIFT                       0
#define UART_S3_PSF_MASK                         0x2u
#define UART_S3_PSF_SHIFT                        1
#define UART_S3_PCTEF_MASK                       0x4u
#define UART_S3_PCTEF_SHIFT                      2
#define UART_S3_PTXF_MASK                        0x8u
#define UART_S3_PTXF_SHIFT                       3
#define UART_S3_PRXF_MASK                        0x10u
#define UART_S3_PRXF_SHIFT                       4
#define UART_S3_ISD_MASK                         0x20u
#define UART_S3_ISD_SHIFT                        5
#define UART_S3_WBEF_MASK                        0x40u
#define UART_S3_WBEF_SHIFT                       6
#define UART_S3_PEF_MASK                         0x80u
#define UART_S3_PEF_SHIFT                        7
/* S4 Bit Fields */
#define UART_S4_FE_MASK                          0x1u
#define UART_S4_FE_SHIFT                         0
#define UART_S4_ILCV_MASK                        0x2u
#define UART_S4_ILCV_SHIFT                       1
#define UART_S4_CDET_MASK                        0xCu
#define UART_S4_CDET_SHIFT                       2
#define UART_S4_CDET(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S4_CDET_SHIFT))&UART_S4_CDET_MASK)
#define UART_S4_INITF_MASK                       0x10u
#define UART_S4_INITF_SHIFT                      4
/* RPL Bit Fields */
#define UART_RPL_RPL_MASK                        0xFFu
#define UART_RPL_RPL_SHIFT                       0
#define UART_RPL_RPL(x)                          (((uint8_t)(((uint8_t)(x))<<UART_RPL_RPL_SHIFT))&UART_RPL_RPL_MASK)
/* RPREL Bit Fields */
#define UART_RPREL_RPREL_MASK                    0xFFu
#define UART_RPREL_RPREL_SHIFT                   0
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
/** Peripheral UART0 base pointer */
#define UART0_BASE_PTR                           ((UART_MemMapPtr)0x4006A000u)
/** Peripheral UART1 base pointer */
#define UART1_BASE_PTR                           ((UART_MemMapPtr)0x4006B000u)
/** Peripheral UART2 base pointer */
#define UART2_BASE_PTR                           ((UART_MemMapPtr)0x4006C000u)
/** Peripheral UART3 base pointer */
#define UART3_BASE_PTR                           ((UART_MemMapPtr)0x4006D000u)
/** Peripheral UART4 base pointer */
#define UART4_BASE_PTR                           ((UART_MemMapPtr)0x400EA000u)
/** Peripheral UART5 base pointer */
#define UART5_BASE_PTR                           ((UART_MemMapPtr)0x400EB000u)
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0_BASE_PTR, UART1_BASE_PTR, UART2_BASE_PTR, UART3_BASE_PTR, UART4_BASE_PTR, UART5_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0_BASE_PTR)
#define UART0_BDL                                UART_BDL_REG(UART0_BASE_PTR)
#define UART0_C1                                 UART_C1_REG(UART0_BASE_PTR)
#define UART0_C2                                 UART_C2_REG(UART0_BASE_PTR)
#define UART0_S1                                 UART_S1_REG(UART0_BASE_PTR)
#define UART0_S2                                 UART_S2_REG(UART0_BASE_PTR)
#define UART0_C3                                 UART_C3_REG(UART0_BASE_PTR)
#define UART0_D                                  UART_D_REG(UART0_BASE_PTR)
#define UART0_MA1                                UART_MA1_REG(UART0_BASE_PTR)
#define UART0_MA2                                UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4                                 UART_C4_REG(UART0_BASE_PTR)
#define UART0_C5                                 UART_C5_REG(UART0_BASE_PTR)
#define UART0_ED                                 UART_ED_REG(UART0_BASE_PTR)
#define UART0_MODEM                              UART_MODEM_REG(UART0_BASE_PTR)
#define UART0_IR                                 UART_IR_REG(UART0_BASE_PTR)
#define UART0_PFIFO                              UART_PFIFO_REG(UART0_BASE_PTR)
#define UART0_CFIFO                              UART_CFIFO_REG(UART0_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_REG(UART0_BASE_PTR)
#define UART0_TWFIFO                             UART_TWFIFO_REG(UART0_BASE_PTR)
#define UART0_TCFIFO                             UART_TCFIFO_REG(UART0_BASE_PTR)
#define UART0_RWFIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO                             UART_RCFIFO_REG(UART0_BASE_PTR)
#define UART0_C7816                           †’ğ†D‡{RGˆ˜/*/;~×İÑ¿XãÛ+aÑ˜5İS¬ÄGîXÑ™Rjº 1²yğ÷$RšpHÈ;‘2Ú‡E±í•˜-®Áú¤Q‘¼Óª3¾¯sÃ»tçGİ'[X;…>‘Ãù…“Ê}TŠö‹`C/Q!÷4~­ŞsTõ%)¶_Ä²ì›'u¢·Ì7Æ,èæ"XO•ê¡Şjœâw[„œ3ıñßcj0ñ`­Øê#±À‹(~µoo"ÇØ¾*˜Ò3ÙğXõŞ,>ÖO¸°à{%Šiâ˜Hj£ m×[˜lœ(?³+Möâ]ËéIĞ-òıQ[Şh¥t:?¹.0¹ò?‹#ı·@D£â…Zå
Æê˜¥8I»n£e*glÛIİ‘³ÃMù÷×Ş÷‡Áöš óÈ!P
x_¼=28²Í-RÎÎg08fFv!º>Ğ;Ü(èVAê¯z~#‚qé´(Œ˜9Góœ#?ãÀßÜàØ¬-Qk†õçU7Y±Ïè1ÏT)™j%’º¯“ønŒ÷ÎµÂC°ˆñ\t`Ò|›Çsm¥Éa*5t³mu¤WâÌu23xÅÉw:4}8@bÕæ:íûİµ=Ãà7p¹b§ôBğº	yÀ Öh+ªóı¸ÎŸjÆjÈ[Ê`ô’##Ô•>ztã;â×Ñù”ƒ<«.¦O™ØÎš®¹§zÎ=&_§á[4*èÉĞµbO9ªOWIJ ƒ°yÉìH~Ã®ÛË?õf°¢Hg+9w8DàéŞ¾Íufæ¤$bÍà8¶Ybâz¼)àÜ9S+°ë)¯C·ñÑ·ì€ÒıÔ¹c7+ÄrĞLÜM£RDNwCå á8vB2tkX©º‚#äâŠş‹Ÿ¶#ŠQ–‹áÙsj@åß¡	}îèOÅ…LÚ4$\ÅvÚ^áô¹PÎ3ËĞ£|­Kı1Œ¯»"ôÆhƒG|¿òDÖ×^–$)?˜Õ€@ÏqØQËí’¿fªéğÊET›Ì_,	\G£°/D´C½J¨¼1dCnÿ˜2~dC›¡İKÃlÄ‰	P©şz{§o"9rCXæÕ¸g^ü“ Í;”Ö\xŠs!å#?ñU¥6¸ª8÷rÅïoÃuÉ~Õ“ÓTÉuÿçMÚ¿‡ÒÛ¿2•Ü¨iÃÏÚV‹yPm bx¢t½UÌäáã‚à£YÇÃêxª0f[úiË‚’aP¦Æ¯†İF¤åğs©d„vœWÕÿS)pÆ¡1<æjÅö‘ô¦T©i–Ìš)ÿ¿˜ı'ÌkÊ2q~ëkÔq^}ÌÇı}ŸŞM¨v&wÄ˜ÿ8Om
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
#define UART2_CFIFO                  }v°U•#RàÆş8~®¾¢ñênœ“¨ƒÀ–mgÉñ¬8›‚²7Í±R“¦âiìî<F–éyø¥7>Òoú†`–foa.¦ætgœĞ©(Èz5)ª3"p<}§w,/›síqÍ@A¹±¢ S]Cè§mÖ0P«ëé¸µò^¿úÉ¢e>M,·“\{qt*‰:¸$ÖïÊ›)HJ£\'&bÍsU7ÖÒë¶ê¨Áòeİ¾¨&>îß7û†My¾ËQ791^¯ØÃ2ÃAéè,qÔë*€Š~O‹f½f¥8|‰d|ãÏÅš¹D>bd¿ÁC)x~¿6b½=Bœ¤«òC§{G}c{ØLDÄ”Œê4B4ØBš
ë	pİ¤Œ"?/.Æó©õŸ8ş¾l“àÃbÔ¨çi•íóª¾KQ¤,l)Õ&cîÀvêm—c¢ğ‘×+_˜Ò~oì}jîU¬ÍŞB0¤~•i(ˆM®iÖ|…“õ³ÛéÙõn#Gôu´ók…¾$U¤ª5iÓ æ¶FS¼šÂ‰ù<¼UŞœ†{Ë]¢ò×í& 3ÂfÑ°hÒdÔò*c.†úkH0öY+p'Uo_-KFn¦÷Jq°Ô;¾«(
ï]FZàŠÓ›B#ÔveLJhã¨>&Å´¤µ¸‰šd(+·`¾æo:äĞFí£ìÜ´x}!O€%y(‘¸ìÅÉ»B°¿ 0˜·Ë¶Ì-cD”Ü36 GL¤Å”ïŸÖÈ¯{ècİ¯W|u~6ÿ¥şÙÓ¢	“U}×Üó,9İ‹¹sL9N”§º·=„&Ğûòç:m·}˜/¨›Ä×w†\Ûè÷•c€»Ñ®àCÜ‹‹´!ÙbbPşoVEj&ma=üSDlúƒ«&«şª™såÅ”íÉ™XQ,ûA—­õ3†õŸ2
§¡B0[ÃR%ÊúVOÜ&ÅĞ
ôÔş„qíÊÔaê³İ†– |ÈMÒ«Ó³ê£>¿Íwšı9œ„¾Ü½áßr`.!"u9Lû>Q¢372²ÒÈô¨K½&ö¹6»¸2D]¼m|[ÓÜµğj¯‹ÎÎôÅjŒ¶'³HéÅ7ÑEPêP)¦6êI(ÚT^g‚XR¡ÈÉbİ„Í•e–ğ#½çfV™Fm‡O¢Wc„Ü @¤bK5pK
øîHÁÒÏ@ã£j`n¼8gs]ky4#*‚Mkd	5F%V}æ1=_Ô„B•Ğ.mŠ²B‰WØcõä•%$Ód+É}b\ëÕ32–Íæ3õn³I+Ç–Z²(ô´øÙ€àáÑ…ÊÉÈÖĞÓê+†’ğ†D‡{RGˆ˜/*/;~×İÑ¿XãÛ+aÑ˜5İS¬ÄGîXÑ™Rjº 1²yğ÷$RšpHÈ;‘2Ú‡E±í•˜-®Áú¤Q‘¼Óª3¾¯sÃ»tçGİ'[X;…>‘Ãù…“Ê}TŠö‹`C/Q!÷4~­ŞsTõ%)¶_Ä²ì›'u¢·Ì7Æ,èæ"XO•ê¡Şjœâw[„œ3ıñßcj0ñ`­Øê#±À‹(~µoo"ÇØ¾*˜Ò3ÙğXõŞ,>ÖO¸°à{%Šiâ˜Hj£ m×[˜lœ(?³+Möâ]ËéIĞ-òıQ[Şh¥t:?¹.0¹ò?‹#ı·@D£â…Zå
Æê˜¥8I»n£e*glÛIİ‘³ÃMù÷×Ş÷‡Áöš óÈ!P
x_¼=28²Í-RÎÎg08fFv!º>Ğ;Ü(èVAê¯z~#‚qé´(Œ˜9Góœ#?ãÀßÜàØ¬-Qk†õçU7Y±Ïè1ÏT)™j%’º¯“ønŒ÷ÎµÂC°ˆñ\t`Ò|›Çsm¥Éa*5t³mu¤WâÌu23xÅÉw:4}8@bÕæ:íûİµ=Ãà7p¹b§ôBğº	yÀ Öh+ªóı¸ÎŸjÆjÈ[Ê`ô’##Ô•>ztã;â×Ñù”ƒ<«.¦O™ØÎš®¹§zÎ=&_§á[4*èÉĞµbO9ªOWIJ ƒ°yÉìH~Ã®ÛË?õf°¢Hg+9w8DàéŞ¾Íufæ¤$bÍà8¶Ybâz¼)àÜ9S+°ë)¯C·ñÑ·ì€ÒıÔ¹c7+ÄrĞLÜM£RDNwCå á8vB2tkX©º‚#äâŠş‹Ÿ¶#ŠQ–‹áÙsj@åß¡	}îèOÅ…LÚ4$\ÅvÚ^áô¹PÎ3ËĞ£|­Kı1Œ¯»"ôÆhƒG|¿òDÖ×^–$)?˜Õ€@ÏqØQËí’¿fªéğÊET›Ì_,	\G£°/D´C½J¨¼1dCnÿ˜2~dC›¡İKÃlÄ‰	P©şz{§o"9rCXæÕ¸g^ü“ Í;”Ö\xŠs!å#?ñU¥6¸ª8÷rÅïoÃuÉ~Õ“ÓTÉuÿçMÚ¿‡ÒÛ¿2•Ü¨iÃÏÚV‹yPm bx¢t½UÌäáã‚à£YÇÃêxª0f[úiË‚’aP¦Æ¯†İF¤åğs©d„vœWÕÿS)pÆ¡1<æjÅö‘ô¦T©i–Ìš)ÿ¿˜ı'ÌkÊ2q~ëkÔq^}ÌÇı}ŸŞM¨v&wÄ˜ÿ8Om

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
  uint8_t PERID;          0   $                 !  /**< Peripheral ID regis|er, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                            "     /**< Periphercl ID Complemend reg)ster, offset: 0x4 */
  uint8_t RMSERVED1[3İ;
  uint8_t REV;                                     /**< Perkpieral Revision(register, offset: 0x8 */
  uint8_| RESERVED_2Z3];š  uint8_t ADDI^FO;         !   0           0       /**< Peripheral Addi|ional Info!registez, offset: 0xC */
  uint8_t RESERVED_3[3];
  uént8_t OTGI[TAT;                                /**< OTG Interzupô Status rdgisteb, offset: 0x10 */
  uint8_t RESERVED_$[3];
  uilt8_t OTGICR;                          `       /**< OTG Interruxt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                   (         0!  /**< OTG StaTu3 register, offset: 0818 */
  uint8_t RESERVED_6[3];
  uint8Wt OTGCTL;        0                   !    !/**<!OTG C/ntroì reomster, offset: 0x1C */
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
#define USB_OTGICR_BSESSEN_MASK                  0x4u
#define USB_OTGICR_BSESSEN_SHIFT                 2
#define USB_OTGICR_SESSVLDEN_MASK                0x8u
#define USB_OTGICR_SESSVLDEN_SHIFT               3
#define USB_OTGICR_LINESTATEEN_MASK              0x20u
#define USB_OTGICR_LINESTATEEN_SHIFT             5
#define USB_OTGICR_ONEMSECEN_MASK                0x40u
#define USB_OTGICR_ONEMSECEN_SHIFT               6
#define USB_OTGICR_IDEN_MASK                     0x80u
#define USB_OTGICR_IDEN_SHIFT                    7
/* OTGSTAT Bit Fields */
#define USB_OTGSTAT_AVBUSVLD_MASK                0x1u
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0
#define USB_OTGSTAT_BSESSEND_MASK                0x4u
#define USB_OTGSTAT_BSESSEND_SHIFT               2
#define USB_OTGSTAT_SESS_VLD_MASK                0x8u
#define USB_OTGSTAT_SESS_VLD_SHIFT               3
#define USB_OTGSTAT_LINESTATESTABLE_MASK         0x20u
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5
#define USB_OTGSTAT_ONEMSECEN_MASK               0x40u
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
#define USB_ERRSTAT_BTSERR_MASK                  0x80u
#define USB_ERRSTAT_BTSERR_SHIFT                 7
/* ERREN Bit Fields */
#define USB_ERREN_PIDERREN_MASK                  0x1u
#define USB_ERREN_PIDERREN_SHIFT                 0
#define USB_ERREN_CRC5EOFEN_MASK                 0x2u
#define USB_ERREN_CRC5EOFEN_SHIFT                1
#define USB_ERREN_CRC16EN_MASK                   0x4u
#define USB_ERREN_CRC16EN_SHIFT                  2
#define USB_ERREN_DFN8EN_MASK                    0x8u
#define USB_ERREN_DFN8EN_SHIFT                   3
#define USB_ERREN_BTOERREN_MASK                  0x10u
#define USB_ERREN_BTOERREN_SHIFT                 4
#define USB_ERREN_DMAERREN_MASK                  0x20u
#define USB_ERREN_DMAERREN_SHIFT                 5
#define USB_ERREN_BTSERREN_MASK                  0x80u
#define USB_ERREN_BTSERREN_SHIFT                 7
/* STAT Bit Fields */
#define USB_STAT_ODD_MASK                        0x4u
#define USB_STAT_ODD_SHIFT                       2
#define USB_STAT_TX_MASK                         0x8u
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
/* USBTRC0 Bit Fields */
#define USB_USBTRC0_USB_RESUME_INT_MASK          0x1u
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_SYNC_DET_MASK                0x2u
#define USB_USBTRC0_SYNC_DET_SHIFT               1
#define USB_USBTRC0_USBRESMEN_MASK               0x20u
#define USB_USBTRC0_USBRESMEN_SHIFT              5
#define USB_USBTRC0_USBRESET_MASK                0x80u
#define USB_USBTRC0_USBRESET_SHIFT               7
/* USBFRMADJUST Bit Fields */
#define USB_USBFRMADJUST_ADJ_MASK                0xFFu
#define USB_USBFRMADJUST_ADJ_SHIFT               0
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK)

/**
 * @}
 */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base pointer */
#define USB0_BASE_PTR                            ((USB_MemMapPtr)0x40072000u)
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register instance definitions */
/* USB0 */
#define USB0_PERID                               USB_PERID_REG(USB0_BASE_PTR)
#define USB0_IDCOMP                              USB_IDCOMP_REG(USB0_BASE_PTR)
#define USB0_REV                                 USB_REV_REG(USB0_BASE_PTR)
#define USB0_ADDINFO                             USB_ADDINFO_REG(USB0_BASE_PTR)
#define USB0_OTGISTAT                            USB_OTGISTAT_REG(USB0_BASE_PTR)
#define USB0_OTGICR                              USB_OTGICR_REG(USB0_BASE_PTR)
#define USB0_OTGSTAT                             USB_OTGSTAT_REG(USB0_BASE_PTR)
#define USB0_OTGCTL                              USB_OTGCTL_REG(USB0_BASE_PTR)
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
#define USB0_BDTPAGE2                            USB_BDTPAGE2_REG(USB0_BASE_PTR)
#define USB0_BDTPAGE3                            USB_BDTPAGE3_REG(USB0_BASE_PTR)
#define USB0_ENDPT0                              USB_ENDPT_REG(USB0_BASE_PTR,0)
#define USB0_ENDPT1                              USB_ENDPT_REG(USB0_BASE_PTR,1)
#define USB0_ENDPT2                              USB_ENDPT_REG(USB0_BASE_PTR,2)
#define USB0_ENDPT3                              USB_ENDPT_REG(USB0_BASE_PTR,3)
#define USB0_ENDPT4                              USB_ENDPT_REG(USB0_BASE_PTR,4)
#define USB0_ENDPT5                              USB_ENDPT_REG(USB0_BASE_PTR,5)
#define USB0_ENDPT6                              USB_ENDPT_REG(USB0_BASE_PTR,6)
#define USB0_ENDPT7                              USB_ENDPT_REG(USB0_BASE_PTR,7)
#define USB0_ENDPT8                              USB_ENDPT_REG(USB0_BASE_PTR,8)
#define USB0_ENDPT9                              USB_ENDPT_REG(USB0_BASE_PTR,9)
#define USB0_ENDPT10                             USB_ENDPT_REG(USB0_BASE_PTR,10)
#define USB0_ENDPT11                             USB_ENDPT_REG(USB0_BASE_PTR,11)
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
 * @addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros
 * @{
 */


/* USBDCD - Register instance definitions */
/* USBDCD */
#define USBDCD_CONTROL                           USBDCD_CONTROL_REG(USBDCD_BASE_PTR)
#define USBDCD_CLOCK                             USBDCD_CLOCK_REG(USBDCD_BASE_PTR)
#define USBDCD_STATUS                            USBDCD_STATUS_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER0                            USBDCD_TIMER0_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER1                            USBDCD_TIMER1_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER2                            USBDCD_TIMER2_REG(USBDCD_BASE_PTR)

/**
 * @}
 */ /* end of group USBDCD_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USBDCD_Peripheral */


/* ----------------------------------------------------------------------------
   -- VREF
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Peripheral VREF
 * @{
 */

/** VREF - Peripheral register structure */
typedef struct VREF_MemMap {
  uint8_t TRM;                                     /**< VREF Trim Register, offset: 0x0 */
  uint8_t SC;                                      /**< VREF Status and Control Register, offset: 0x1 */
} volatile *VREF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register accessors */
#define VREF_TRM_REG(base)                       ((base)->TRM)
#define VREF_SC_REG(base)                        ((base)->SC)

/**
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Masks VREF Register Masks
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
#define VREF_SC_VREFEN_SHIFT                     7

/**
 * @}
 */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base pointer */
#define VREF_BASE_PTR                            ((VREF_MemMapPtr)0x40074000u)
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF_BASE_PTR }

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros
 * @{
 */


/* VREF - Register instance definitions */
/* VREF */
#define VREF_TRM                                 VREF_TRM_REG(VREF_BASE_PTR)
#define VREF_SC                                  VREF_SC_REG(VREF_BASE_PTR)

/**
 * @}
 */ /* end of group VREF_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group VREF_Peripheral */


/* ----------------------------------------------------------------------------
   -- WDOG
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Peripheral WDOG
 * @{
 */

/** WDOG - Peripheral register structure */
typedef struct WDOG_MemMap {
  uint16_t STCTRLH;                                /**< Watchdog Status and Control Register High, offset: 0x0 */
  uint16_t STCTRLL;                                /**< Watchdog Status and Control Register Low, offset: 0x2 */
  uint16_t TOVALH;                                 /**< Watchdog Time-out Value Register High, offset: 0x4 */
  uint16_t TOVALL;                                 /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  uint16_t WINH;                                   /**< Watchdog Window Register High, offset: 0x8 */
  uint16_t WINL;                                   /**< Watchdog Window Register Low, offset: 0xA */
  uint16_t REFRESH;                                /**< Watchdog Refresh register, offset: 0xC */
  uint16_t UNLOCK;                                 /**< Watchdog Unlock register, offset: 0xE */
  uint16_t TMROUTH;                                /**< Watchdog Timer Output Register High, offset: 0x10 */
  uint16_t TMROUTL;                                /**< Watchdog Timer Output Register Low, offset: 0x12 */
  uint16_t RSTCNT;                                 /**< Watchdog Reset Count register, offset: 0x14 */
  uint16_t PRESC;                                  /**< Watchdog Prescaler register, offset: 0x16 */
} volatile *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#define WDOG_STCTRLH_REG(base)                   ((base)->STCTRLH)
#define WDOG_STCTRLL_REG(base)                   ((base)->STCTRLL)
#define WDOG_TOVALH_REG(base)                    ((base)->TOVALH)
#define WDOG_TOVALL_REG(base)                    ((base)->TOVALL)
#define WDOG_WINH_REG(base)                      ((base)->WINH)
#define WDOG_WINL_REG(base)                      ((base)->WINL)
#define WDOG_REFRESH_REG(base)                   ((base)->REFRESH)
#define WDOG_UNLOCK_REG(base)                    ((base)->UNLOCK)
#define WDOG_TMROUTH_REG(base)                   ((base)->TMROUTH)
#define WDOG_TMROUTL_REG(base)                   ((base)->TMROUTL)
#define WDOG_RSTCNT_REG(base)                    ((base)->RSTCNT)
#define WDOG_PRESC_REG(base)                     ((base)->PRESC)

/**
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* STCTRLH Bit Fields */
#define WDOG_STCTRLH_WDOGEN_MASK                 0x1u
#define WDOG_STCTRLH_WDOGEN_SHIFT                0
#define WDOG_STCTRLH_CLKSRC_MASK                 0x2u
#define WDOG_STCTRLH_CLKSRC_SHIFT                1
#define WDOG_STCTRLH_IRQRSTEN_MASK               0x4u
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2
#define WDOG_STCTRLH_WINEN_MASK                  0x8u
#define WDOG_STCTRLH_WINEN_SHIFT                 3
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            0x10u
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4
#define WDOG_STCTRLH_DBGEN_MASK                  0x20u
#define WDOG_STCTRLH_DBGEN_SHIFT                 5
#define WDOG_STCTRLH_STOPEN_MASK                 0x40u
#define WDOG_STCTRLH_STOPEN_SHIFT                6
#define WDOG_STCTRLH_WAITEN_MASK                 0x80u
#define WDOG_STCTRLH_WAITEN_SHIFT                7
#define WDOG_STCTRLH_TESTWDOG_MASK               0x400u
#define WDOG_STCTRLH_TESTWDOG_SHIFT ~´±;˜‡uåw“šŞ1›LJ;(šfñ1>´0÷LÓıc=ğ{	Ïğ¾ê›ñ4NcØŒLd¥¼˜­˜­:æ¯u
OÄCTù×v…en°x®6»ÉşÅ•Ùiûƒ…ÁDè%GD„è¬REÁK?;0Ü8PÅø 8âeh"„)¬üéÔ·cäñÛ­ÍÙé¿^`‹ú÷ŞTş1˜¡¾Ôì'­fš¦Ù²Q¢/Dëm<AŞ{?+Ç÷¯uéà(Y·²Å_6·ó@,ÆR¤öƒ÷áÒHrrÚqËK™©	†*fP¬*?ªò·ŸÎ©Hµ‹LÎbÅª' „Š…ĞÇ[õ¢•G~5Ûìd-¹`ul¡\ü HRt˜’ÅSPåGqwêã.©óäÏ¡asg-8 ‹±íÏ7BtpI­¥XL©âÛf½¤Ñ¯Ï¨WµV«
+íÜú;}3…™uáÚäÀ')½%òK:®g(›ÍnG€óú!|¦$;Za—õ}¹HÔQÖŠÑnh®Ó—àñ¬¡txÃš‰Ó¶ùŒ¾^N(Â_J^àÂ[Û„ÅÔìMK±ur[>,%ïìëÑ×Z©7^JïfT$Ñ£HßÉ­]ø…¹"
HaĞØ¨£ê¢¨ÛHÓêéYm—…á…¤>‚imI4â¢d†²G#ïÅ²ß[§aÛãg[Gr–}á,e¼'½ÇËÈâ>P=¯ç‘Œ5êÜ:.¸É‡	çşÀÿ¶ÜM‚hµt»çŞ€k¥ÊZÏ¢Y´]7ôÇ2<Üq˜ÏµBeë÷O¤—sí !
³vÀ×y8?ºD÷=(•ÜK…­¨Ù“Oí›ë¸ûÍWÃÑïu†	q-üÊU¤fNx’ä-¿§5Á¢$¾Î¬Øv§¢ÉØ9:Ms§«&¢O%!ÎÏíĞó9¹ì³™’oèWBCEÕÈÄp¿Åû‚F%WmäÂĞ¤[+ŒŒcPmøJøğ^åş:@[)&¤¥=RZÃæ’"PSÁYÑñs¥•Qì÷‘KŸ,£C	œ:QĞ_›ËE¨Úà„|’ñÉÍé…®ìhk-K·Ùw¡ÂÜàÈmj%t÷|ÎyX‹xÅ,¬¾6á-c;=ıÔV50_ğ!Å YÈÑ˜ßkOÂš ƒëeq>3]{£ÎªA¹ßxÿÿbÈB7ÖãĞ.|Ä”Í)zU™«?"kE7;øõÇéi Ô®aÏŸğ!ˆspsè‹Fë¯óÔ0üS8 jMùƒ{'ÓKÆkoG©„Ò,:¬„ë‰dĞb`>Ú¢¾ÀáKfjÎş…WÒ¤BÊwûB¬çò·Z"B÷!Œ•'‡Ä†Ì¦“V^Éô;è%’YGÏ	"%ûµı+WKÈMàPÇ¾×’zJöl="Ğpû«ÉÏOv1.„WWïCWÉ½sêH8”;“Ç*7ÂÆ|/K4Cä[ğ¤/ …˜aÛáª…Ÿk²XyWÂ0°ıŞ¯ÜÃM¥dÔnh~ÕiÖÈX£–Ù‚	#lr½ìÑèJ‘NVu³]yÖû^èeízÏ˜+™ú³9mî¿¸JñÙà š8÷Ğu3ô¦ÌBÑ†aıfhÁ³Ü] ¸àJJAwîÈd~(ÌÑ‹²Ò›éQ¸i&µõ9h¢}ÿè…{Îy—äß¿-İçqHÈ`‹K©5ô§eØ}ZÂåİ„‘$j¦õ‰?úyC«|–µR!vóÓ|¦Ãäÿ×1ı"Xn8¾‰%¦ˆj»Â¸Ä¡Â¿_ÈúB22#Ê5ù†4Ô¢ÆÆUTe®ÿ2}R¥´S]Sp31-†ú% ½[İ‹^Ri XöõîÁ½†cTÆu-şÒ×4èë¥mÚŒA2ùYîè4N¦sÜj‡4†öŠş“’ß6ÍL%WøÅ¯ÃsÈêuj¤¾kûVg!c~	ĞÑz>ûå…#~Óî¼’ §V-Í¯ê;ñXEÏ“æ*ãîªt$r&>{|:p2ù7ÓáTG }›gø,ø“Ğsw!ímµnëK›…i”ÌºŞxCRëï@ÿ«¦¦2£Û_@´äŠ\Äyb‚z±)Ó?¼	t•æˆèD×ä±?ÛïF¿)Qíÿ3\*…Ä|aˆáá²œ¥Yo:±€%€™'•L×ôù­ö¬è9ÒVŒ…ô#³Z¥›£üùã3ƒ8àeVšö¯ÒvÇFI>bƒß?ªl59âNV·7}é¿¾¶1S-,Dj¡¹I‘¼ªâ"ÍHKØE‡y^"ÑlŸ¿IX;)Ñç[ßc¿ÔÓ7í4’†ÔÖ÷VQ¢ß@>à.vän`\³YĞ·aº­x½Ğ8î´êé/‚uˆ²ì ÃR&%4(YÑïĞÏJ©ù[UWÕüX.nÀ3ı·+Šd¿;Éwµ±°/l~8Ù¬<ƒ÷™%Õ{ŒNß.ÔÅ"Fš67jªUˆşË˜¨÷Ğ3Ò€şÑÑˆ÷>ÏŸ•‚#{òòÊ\ŞvıuqRÈ‡bÚ˜Æ:M
Q YÁŠáãöºHø›R¢Š-]cä	­lq&SÈøsÉò×üÆ’{¢.qx›ŸÄ-Qô•·ğªÍ3Ìä%ië)$Cut¹İ¬^ßÑp‹lğêüú‚¨_'G¶õ&B‘—XéëÚM¡Z >†ƒË%µì›Ñ{âÂNBé‘6Á„.r¢½±}sî~ó/øZ¬? •ı'dy\´+@,!àl¯İ‘ˆf;k’5j%ú˜ÚßCq Sl}’	ÈÔbpKSdü÷åWâB[›§¹î§qXˆ·G+œêBá›2™¶†h'Ö¯ˆ–éŸ®‰˜RòÊ"ªdƒûèùÏÒ’½HÓU«·›K~™vîzb·KÈ `*»Ô{É€œÕ¦$É|*¸øÚ\kœü•ŒRÏ$7ôYx.°5†Ãè²€ú\ï®„ˆî~(®´ôáµt]Ñ 9Y·äÈltÑËU{éÍJ[üF
n(×V¸§·#Ş/öx0Ù)Ëk>{;§3ÓjÎ–rrnje´±-áİ2îƒÊøaŸ®ÀPjzû\®›†_Æ0m'ÚEk".oea·Ğ“C\?îbUQ´0°z¼â±Íußæ72*c³ù’Š&Ã5'ÎÂÏY¢MŒ¼çÄûØ«°5*2“M»!!òwï(ôğLÌ˜ÀVBjÌQÿ]X‰VMe®½‚ÓÑ)å÷U:	š‚£µOë,z¥{˜ç$ËÁo§wôb‹ƒú.¼¡ï"åÆ`—Sà‚ïôØóHæ\m7^IÔˆÑ'yŞÄW|îø4èp®6ÄSTÈ‘†d[¦ü8 «Ú»¥k4)Ş¶¸°\X}"®ËmïÊĞHû²l@ü×v˜Ö¨İg`µ°ï÷€‰ÅÑ«wMÔ~à$Ax1W¸ûC•±ù…Ff k¯¶,o¢ÆØ6³‚”–’£§œH»Å˜4Ç‡ãXDM&†‚¨:|MÊKZr§İ‹JŞÍ¥TnÍVBø¾rÄ—+ìåûíÆİñô{.ê—¾Õ:zLë5è[ß½œ¬Ö]ëp=½NUKş³CîÛ­@¤2Q€w	‚³¨
k³t2	Úyâ¿""89ÕãY|)2›¥WÔ÷j‰×éR"aÁ>
wÉâ„+'6ÙÓğ>”ı£r˜Z©hÓ]|¿-ÓH«ñìÒ÷Âošu?íCÀä¤/õ¡'2Pâ+ï¼ï£M(”Í­ƒÕo¤‹Æ0;µÓ¼^AËÆÈ† Ş ×ü’ôì 2:¤yæ¸y9¶OT]Ş7,`©¿ÊÃüÈ´1B`UÂ¦ÜoL%Í”J.^§fíyòœg­ø2^ZÃÀ~ê€£Lj‘’½„ùÈçpÁ°¥)%Ïm=Ş‚­½	¦'Jı¶óÚŞZõŠ#æƒ´3ÍY¡°­|5×a|àE¤°Ömd­âVfèFHŠ3¹ş.z'”//1uÅ8à‡ãN1*…u]ûÜ äŸèZa°*Æ'ü~˜KgÂ
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
 */ /ó#]3–•6×íOØåq§æ}n°rCQR3ÕÆØïĞì„èw7t9r~´æºPAsfôÇ:‰;Irx[ÁÃòˆRÍ±öRú§×3Ã8è§5Ğê«XÑ2íòw«‘ğ4¢Gh)'0ş½Yİ¿ÓâM™óí{Á;/¾?…ÑŒfÇ~ü¾àØÉOç»­ş-è»M—%¨5nVp[KÅûAÓ·K?½ÓD½ÍHØ­SŸ2ôešFÙ©åŒ(
áp>QÔÒ4™V‡èØ_NKİ´Å@’äA—®fñ¯6XrÒç"{ºlş±#†ÃWt²ÀÍ5V×Ô.b–T‚š8ªzåÀ…wÁUG@·ËÛ°ÊÈ¨O#w”Ò£Àæ…&*üá[w]"˜1ïA‡™PvİD““äıã«³bÀ!0L4®6Ã3ğî¼‚Nî.»ÍbÄ "sxárì­Ş¾±Ø9Ò§ÛS§í}İ<]i\=ïâ…µêµÓOuÊ…@VÕ§nxVŞVøjÑòVòYõå†øUW+éÂ”Ó÷‚ªY×.ñõ€£ı,gò7¼l}¦½áƒ‡A>·‰İ7Ñzl]„xiQ.›˜}¤éwâ¿/¯ò›@æzxa?­Ü÷uÂweÆM8YÚ2ÈÛßÖGôÔ…m…Œmá^3…¿Y– 3e¨’„b6Q{é³=NP®ªß“–aæòIş°“Ú€ÊAÈf:ÌÁ‰¬×ÌKd5ì†ø­5ÎÕC]RšGG?^~uÁÃHî	œŸh»åuSr€­¡ÔZE”¤‹Î®±8ª4cÊ¢û
ğæqJÿàæóS÷Fì&_ÚÓ9¢×:xMøM<´íãì@ÀH±ó¿/hø>F)iµ ,+M|’æÈÃ·vY:(4ºÖİÖ%n4§¾£ZóòÍ“¿£}r%q<)‘gÉuçé÷é²ÒİÜt !Û[µ]q6B$­,I|àá^~µZ‰¢“EOãrä/3z<`qÑU’&§?ƒ&wÿ‹îLüwN˜„e~‡X^_Êó¥Ä_©LŠY¡ímš~¡ÔŞ?Ï½Øä|Å7Â"§*j¡šÃ£ÊjÄÕ³H6eŒ´;¦ŸÊ3µ	+ÒY<ôWşónËcƒ‹0‹ÆT‰É6¥nÿ[Ç5WTè¼ô¼íašBÚŞb“Wh‹œc1 mäè$›¸!ÁjÇ¹eÿwq˜¾uzªd¿­¦ğ#@iºjzµ‚ïV6*øsy^º²|.jM¡ßûülX‚œ•î&h3­«“ß5¦Ó–‚4 N$æE½Èó¶B»¹GY¹oà‰0á2~´±;˜‡uåw“šŞ1›LJ;(šfñ1>´0÷LÓıc=ğ{	Ïğ¾ê›ñ4NcØŒLd¥¼˜­˜­:æ¯u
OÄCTù×v…en°x®6»ÉşÅ•Ùiûƒ…ÁDè%GD„è¬REÁK?;0Ü8PÅø 8âeh"„)¬üéÔ·cäñÛ­ÍÙé¿^`‹ú÷ŞTş1˜¡¾Ôì'­fš¦Ù²Q¢/Dëm<AŞ{?+Ç÷¯uéà(Y·²Å_6·ó@,ÆR¤öƒ÷áÒHrrÚqËK™©	†*fP¬*?ªò·ŸÎ©Hµ‹LÎbÅª' „Š…ĞÇ[õ¢•G~5Ûìd-¹`ul¡\ü HRt˜’ÅSPåGqwêã.©óäÏ¡asg-8 ‹±íÏ7BtpI­¥XL©âÛf½¤Ñ¯Ï¨WµV«
+íÜú;}3…™uáÚäÀ')½%òK:®g(›ÍnG€óú!|¦$;Za—õ}¹HÔQÖŠÑnh®Ó—àñ¬¡txÃš‰Ó¶ùŒ¾^N(Â_J^àÂ[Û„ÅÔìMK±ur[>,%ïìëÑ×Z©7^JïfT$Ñ£HßÉ­]ø…¹"
HaĞØ¨£ê¢¨ÛHÓêéYm—…á…¤>‚imI4â¢d†²G#ïÅ²ß[§aÛãg[Gr–}á,e¼'½ÇËÈâ>P=¯ç‘Œ5êÜ:.¸É‡	çşÀÿ¶ÜM‚hµt»çŞ€k¥ÊZÏ¢Y´]7ôÇ2<Üq˜ÏµBeë÷O¤—sí !
³vÀ×y8?ºD÷=(•ÜK…­¨Ù“Oí›ë¸ûÍWÃÑïu†	q-üÊU¤fNx’ä-¿§5Á¢$¾Î¬Øv§¢ÉØ9:Ms§«&¢O%!ÎÏíĞó9¹ì³™’oèWBCEÕÈÄp¿Åû‚F%WmäÂĞ¤[+ŒŒcPmøJøğ^åş:@[)&¤¥=RZÃæ’"PSÁYÑñs¥•Qì÷‘KŸ,£C	œ:QĞ_›ËE¨Úà„|’ñÉÍé…®ìhk-K·Ùw¡ÂÜàÈmj%t÷|ÎyX‹xÅ,¬¾6á-c;=ıÔV50_ğ!Å YÈÑ˜ßkOÂš ƒëeq>3]{£ÎªA¹ßxÿÿbÈB7ÖãĞ.|Ä”Í)zU™«?"kE7;øõÇéi Ô®aÏŸğ!ˆspsè‹Fë¯óÔ0üS8 jMùƒ{'ÓKÆkoG©„Ò,:¬„ë‰dĞb`>Ú¢¾ÀáKfjÎş…WÒ¤BŠG7d>y¨BEdØFš`&°v+¢%|xòã‹#è@võ®¡æ7ªN÷¯”ÄT	È¦fyU„DD¹ÖË	š:Å\¿BÑà‘Í=§—bwMôXÌ ~U-3ş™aOw"¬¢œïÆßmWç™dr
4qİY‘şô$Z·a™f´³†5Öd¦OñÃˆÜó{õ±¿˜¯ „6uŸ’À;]µ#.1ßUX[Jv¼(=+&=&§(›iPÔ`ƒ'»e‰g"@Â®ø¯q¹[B-‚Ìç¦|sò‚vªöàâ2æ©Á#Â‚Sb©r½P>(P’(@¢¤ƒ µEI´aÏ¹şïN >M{ç¶O:¥s;7ì_+“|tğ,^3XA§4OvşŠ”Ô‰±ªhJıÿ-¦ •‰Ÿ“ÿİÙÒ‰îÎÙ “ıóüğ¥•ƒM¯H‘H¬*˜b5|ªÂ‚…1 ö…RQ[A~ÙOnŒx¾ÂŸNT½H8œlêŸoµ_Ş|…¸Zg—iO ñÆ¹$(³*- F£ÒhñÛs,­Ï%s|KiBñ©ş´(ú‚(ï:Ô“šÈµ£Šhã[U¶µº·×=÷ñôM€”³ËÑíÅÂ+)Æ:ê<)è_X†á8´q‰Ü·É‡!ïyEL¬”Â$»¤ãİ]Í¢²+
+=­º—B´0S¦Ü+9P*6BxfÔrÏL¿fZkÔ`Û$ãÅ$·.ÀufÒÎô:B–m„{Ş«I¶.I¸&¬m?¹¡VÕ‰^ì#
;ãô)í'*K33§.íı3öJ?œğtj! ¾ÿ¤2XTD9 ,{,«©\÷-—|ª—=‹Ç7$üˆD$åv²ºêî—œU‡³sHZ¦®Ş« Q;’<dõ¬;7ØßH¨§i$ğöDÅG4»úgŸŸTÏ{#ÑJOßªv™ÛæÍQ¬F ±ı]åpy¢Àº:P~<€N‚8aƒ€ÍÙµ=œÄòä€é±+eÇm\ô¼‚GTE-¤&rıA”"ØqÁ¹~Ùx{
Ÿö—ß’
!×GĞäjÚè>›Z‹/œV‡GÚ}t)¶à0§HÏØU¨¥”Nz4Ê}¦ÿ€ »K@ŞÎä‹ÇcAÚ·wV:á-)³lƒºwwËâ×u#pÉo¡aÎÜ²@-Hìøä%¢+A(í+¹šùGC4«bpş”Âl8³ELÑ†mIK— `in®­Ï™ÏxĞ€Èd{fkÍ$36Ô‚}ÛÇÙ{mú¼yÒ`ìR~ï˜–S~·sÅ0ìS©'ç¿ëÑ‹hbxD];N) */

/* MK20D10nh, eo&. 
/
