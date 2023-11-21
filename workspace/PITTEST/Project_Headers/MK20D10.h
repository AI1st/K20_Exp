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
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* SC1 Bit Fields */
#define ADC_SC1_ADCH_MASK                        0x1Fu
#define ADC_SC1_ADCH_SHIFT                       0
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK)
#define ADC_SC1_DIFF_MASK                        0x20u
#define ADC_SC1_DIFF_SHIFT                       5
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
/* CFG1 Bit Fields */
#define ADC_CFG1_ADICLK_MASK                     0x3u
#define ADC_CFG1_ADICLK_SHIFT                    0
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       0xCu
#define ADC_CFG1_MODE_SHIFT                      2
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK)
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
#define ADC1_SC1A                                ADC_SC1_REG(ADC1_BASE_PTR,0)
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
#define ADC1_CLPD                                ADC_CLPD_REG(ADC1_B1
�g�EdmF���T����!�>�;�B��@����d�B�r?�o1�'�w�d��Aw��1�9�<c�ı���>�H�ހ����2I��TWv��aO�vP�Lbk��6~�~��W�٤�g:֛m����(ci�����ً�Q�Y�� �S�-h������@';}։���o���$���ϴp�ď��z���\�L�7�3L��y�%�(<|GC��M�;B2G�� �2�%�U���f��J���w݀���ɟ*�Yr8��)�@�{o���6��.6=X���5���^p�^�i����?������I�zJ)*`��'�^�/F�\�m��6ds(�(¯�	:��+$,��=��&�@%s�G�e)��7Bk������GB$2Ig���G����Z�m+ �8 l�|6��d�@����.�WH_S���kbâ��o��k��Ѫ���'X�W�����IŰU�>9�&��X����TN��#��bMÆ[r���3�E�}S40��j̡G�$���m�p}ܱ�.��Y[:��;ةڍ���!���`6��I��.���NZ�[�T�ƭkG8��3&��ab��삀R�z�m��V��z,.ϻ��B��$.	�
K��������Z����L_p7,ď����JF���o�j�
I^���C��\7��<�i�+��ma����#�XmP胤3X�^�-��/�SQ�E)A-e`�s��H�UcHj#h!���4��b��d��,�_��o׬Yge�}�����KFu�Ã�W����lZ^\npw&L�鵭x,vAۇ]�O�~E��<k������`�5�<i֝�@�:���[q ��j��:X�T]�m�Rʆv�q�5��E�>�\�oNA|��lRG!��6����8Z9�{���E�`axZ����u�=V_����kf"���t/�q����ηBO-��9��b��Et��أC`J4�7��Żx(��MT�x��w��@{�}��9define ADC1_CLM0                                ADC_CLM0_REG(ADC1_BASE_PTR)

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
  uint32_t PACRJ;              ^\U"J�h#.v\�(ğ[�yl��s���m���3�d��_��s�8,�܌�ʽ�d%�Hru�� ����=�O�Æ���Ԕ[T�&�d�MAU���!#��u�Ļ޸9J_0���_	V�0��g����H��v��њ�{ (�w�xSO�a*�A����i[^��*_t� ՚轼��� [M�����s�ԕ��c1�g+{�`Ў�+�j�#���L��f,@f-�w�"���tbr!��S�CI7�O�o�.BP�
���Y��I���e�R�U�����y����N
���
l�/s�X����G�b��qvWyI���)M�zPJڶ�a]�/��x�'�(ֹ�I�VPJ�����J����bǚy3d���Xc���`���g"�8��"��:���Ύ�j���r�'QO9FK␭��#�QH"��
�<T]�\�)&M����Ľ̿�G���M�K�`)H=��pCLg�ӂ} 1�hui^�W�+j7��g'���M�"����o �9�:���\1Vql �:ˇ3a
L�SX??ݏ�E��㮻��/D��2��-wc?��K�%^����D	7@��N�R�v8��M|" �<q�Ǡ�X�����a���~Q>�����'�"ܞH�^5������{�����tw�7�֋�Ԧo��h�c�*�{�2>N���C� �̾���]a�����7&���'��*8���w?u�v�V��$�av��W�,�J=�~�9�+�-F@��~��,x��S��Y S�'���S,�y2VG���RC1d��8�9%���$ݚAٻ�D��gx���-�2u9q��.�$�b�% k�$��Q�#��M�Md9�<��[&H6�ܞ��)>b'�07]�X�3����2o.%M#�O���Y�(0AA�Z쪆�'���M�����f���X�p�\鯬*kǮ�^Z�c�"��C��C}"f�K�5 ��R{Ĕ�)�7W��<�@`�%�A�E?��//��Q!(�7w�1��+�x�/G����^��Ho�C-���N:hqs�5�l`�⴩�b���p�<��rJ8���A��^�M$iS�1T�|�"nF+GaD��4�6s�!G@;�#Y�m`ϒ5�(�ؙ#>(�aË��A�D�Щ���RN}iY���jz��~�k�7/&zO�2�*�PY@e��jP��~Fٔ�q��;�ѭΠ�ŏ�}���bݸ~ Nd��Y��n���mu��2ٻi%+�@�si�89�~^D)�gLV�R��nW7�h�U��ϼ�b���n�P�-��2���F��:)��k�%Uf:�&�a�E ��e�z�����cgl���#Q�ڑ�B���KUO*]�!���K�����|mc��� �&2?Rܺ!�e?��6��S�R�.��H#�c5	M���
9	l��b�^ 3k�u��+�޶��$�.P�MيY�hUI�ѥ��U𓳌є�,1���\}����fH���d:�wys~�U��,!-�'i�M����&�OF�ce�v ˲�)�|C9�� �K� ���q�/~?��[�>�lR�qѧ1�{^0��PJ)��=u���	��$u�� �b�~4�6v�E��Tn<�&�I��l�@Ň��0� �7y�:⹔|S ��DX�'m#G���4�_z=B:��e��k5�i���k���R�-���@"������.�C��FV4�X�?̒e]��c6�r��	�Ka�dD���D/6��+uU����s�Uq�/t�mb����P�$>^{��uS�C&m��Y���<Xd��za�kbH�t�@�b�������(��X�7-Y$�l��h���j�Ͱ�]�D_�%�zb3K")��Xi��4���$t�� �7p��6Ix9z��4]�	NB�����3ceu�`o�*�W����6�P8�0f	��ڝ��<�#��w��\�&�_�~f�)�}�id_Khڕc�V�#_�%y��ES⒁��~��S�YpP"p����+��L݀e8�]4�y	MҼ`T.,$��6��Ӱ'^�'p���+�9Uv��<+��\�x���e�:��͸x�%���/�A��R���?N����ח�����r�>v#:�|�X^2հ8�����L,N�Z�ä$�~j\�>��U�v_�X�N����~d�ꎌw�൘�Z�bG�k���*��F���Uw�g˻��7��3�
�&Q�f�T,uQ��.����P���żjImmJ�OB���N��{��Mh�-`�_�'Co<��x�j�MIE@���3��:��0�i��+��+
�́Y�t�w+�!�(���4\N3��m���>�fR����d�$�P%7����@�kC���'��<i����V��{��l�w�e������+����R�q�H	ہ�{���1S��TVZ�N�/\T�/��Vt�+ſ���o�\*ݎ+w
n���Z�4��4�Zz�4��՟$/�Qm .y��y�J�z�d�I���U��b��B�Q�fe�M������v�!����p�k=��2��fjZ	����W���~	Ǳ�SF�).P=����nFi�_B�&�}Y��I������C�a��#��=�R�[-K�]l����m��t�C�P��Q���x��qU��B��t�R�,��p�2��p���@	t'�Ы	47>u�<�d�`��	� ���,�i��,��wKet�T�ȽR�જ��%�\pn��.V��b�{
�!� ށ�3V+<�x4�������U�j��Ihqܢc�C�BWս}�+q��4�@��c�D�ۧ`��YpCG<�Q���ة���@fRN[�m;�ٮ�Ȼr0.vØ�BUD���#��hL �!�����hx�JN��'3�J��ɴ6`E,5q��뢫 :�@�G�g���[xrT�NY^�Wʹt)�~VB���C�t��zÁ��_qW��tDZ��0Q��o�L~�I��,�	� &��B�T(ѿ��h����Ȱ�&�O<	�����dt�@9�����  0x2000u
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
#define AIPS_PACRB_SP5_MA[�                      0x400u
#define AIPS_PACRB_SP5_SHIFT                     !0
#define AIPS_@ICRB_TP4_MASK  `    �              0x1000u
#define AIPS_PACRB_TP4_SHIFT             !    0  12
#definu AIPS_PACRB_WP4_MASK                      0x2000u
#define AIPS_PACRB_WP4_SHIFT     �    (  " �     53
#defife AIS_PARB_SP4_MASK                     $0xt000u
#define AIPSPACRB_SP4^SHIFT                     14
#define AIPS_PACRB_TP3_MASK                      0x14000u
#define AIPS_PACRB_TP3_JIFT    (  $ !           16
#defyne AIPS_PACRB_WP3_MASK                      0x20000u
#define AIPS_PACRB_WP3_SHIFT             !       17
#define AIPS_PACRB_SP3_MASK                      0|40002u
#dmfine!AIPS_PACRB_sP3_SHIFT `             `     18
#define AIPS_PACRB_TT2_MASK          $` "       "0x1p0000u
#defhne AHPS_PACRB_TP2_SHIFT        `          � 20
#fefine AIPS_PACRB_WP2_MASK      `         (     0x200000u
#defing AIP_PCRB_WP2_SHIF        $            21
#debine AIPS_PACRB_SP2_MASK                      0x400000u
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
#define AI�h��h������EԸ�c�-�)��)�_����E�&��c���uA5]�FˬxZzu���e�*�c&H<����!@���+����Kcʓ`����E�'��s1Kq�ȈtDbÖ�˭�(�%�eg��H�"��<M���2��0�W/�5b�]�o�E).�".�-y_<r���Ҭs>\]~,��K��chS��	(���Z��w+{(]lA7�`�f��M�;[9ql�1:���>5�38�A��6e��UR���7��x���(�~Q-����}�A+㻧�-k�%`��nx
Mj&oj���/i؍�u#IL�Ϩ,��v��]=R�_+�;����9�ydɤ�8�I���hN;M<._����W)���a�m��u��?�ͬ^
{&l��W|ç�h�_5�����E�X��� �Ի���{W�@�]��w	������k����v�~�����ݫ������V.�h&��W,��b��Sd��k��T�!�^�DQq�S���<�Ĩ^����&B����D����;^���c�Èj�'�9����&�Ⳑ�W��İ�I�D#��t�6gg+���H�9!�P7��4��G#�ӹ
Y�2�0�E�9 ���ml�1��Ƨlǵ{9>�!��L��b^dn����a�A<<�#���;��󨀂��������@�"�����@��1����zB�Y�]m6S+h����tI�G�>���$"g%�)#���xn���;�����3�R#� C��q��
:����,.�37�8&�1p��/*���<B���2
�}�|����7�/�r�����zD�a��T�
�W8�����^��3�I��6ta��`	�6�y���er������cn�����9��'ި���6�<�z����Rq��~�K�Q��"}Q*/L����U��e�T�$�@
�#�-&��>�)ט���`����v��6]���U�SBC�7�=�Eb�(:(Ӓ���Sh��>�
y��u�S�0,��1�L+K�l3�Yllm[���f�Y@:x�x��V���_pf*hB�[q����\7L�6���-�������$5��Ӹ6k���`�ϧ8�8��Pl3#��Y��p�BQ���F����Lӊ�HE���Ha�p���EY����#�:VDï���e+�/�h����%g�7�N�1z1�KN���V��L	�#�o�@�t�Z[n��z��ª����^)�3���l�[�������>��MG�����ơ�(��]��<���m�z����e��f��F��!��pA�1��x��T��C:1ol.@��˚��x\�-݁�:�1�&28L�s�#��$����y��|[6&_d'��1&?�lBR�s���gl�b旌�u���wp��c�1�� �@��k9�T�(�����"�3C~y2��!�(㵇u	X���fA���uJN�T��|x�"�g�2���'��k��Dy<b	A �k��ύ)�h���Cf���}� ����mw���uX�$s�����ѣ֛�����TT2i[G��.5��P�E�#M�h�9���ʆ�b_%;Vi�H]��	�8��djgG�-;���rp4�ML�3��Z�~B;m����S	��dcĊrƫc�����־8 L��nXWo*�S�y��SD���H�تٳ"FX_���3��І�l���V��Β��H�(LR<����" ���_�HN��f��A�h��W2�@X.q�	�o�88��A�\˜�n�cq���F�3BJ�����r~���.�Z�T�� m.����&[	��3+�M���;�S��I �Զ��U�!�J�g��
�\)7�Ba�fi�����by�ؑ�c�͘F���Ƌc"%�* :Tz��ڗnp���Jm,?�YuhB�e2ձ�+�4�k'�)�C�-	{��<���a2��OF����W�~�[��G5�IB69��>r����� ��������/Rʷ8�H2�l��ń#��ņο�y���_݃             30
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
#define AIPS_PACRH_WP4_MASK �                   "0x2000u
#define AIPS_PACRH_WP4_SHIFT                     13B#define AIPS_PACRH_SP4_MASK                      0x40p0}
#define AIPS_PACRH_SP4_SHIFT                     14
#define EIPS_PACRH_TP3_MASK        `'(         ! 0x10000u
#define AIPS_PACRH_TP3_[HIFT                     16
#define AIpS_PACRH_WP3_MASK    0           ($    0x20400u
#define AYPS_PACRH_Wp3_SHIFT                     07
#define AIPS�PACRH_SP3_MCSK!       0             0x40 00u
#dmfine AIPS_PACRH[SP3_HIFT        �       0    18
#defina AIPS_PACRH_TP�_MASK                      0x100000u
#define AIPS_PACH_TP2_SHIFT        �            20
#define IIPS_PACRH_WP2_MASK                      0x200000u
#define AIPs^PACRH_WP2_SXIFT        `   !0       21
#define AIPS_PASRH_SP2_MASK                      0x400000u
#defin� AKPS_PACRH_SP2_SHIDT             $       22
#def)nm AIPS_PACRH_UP1_MASK                      0x1800000u
#define AIPS_PACRH_TP1_SHIFT 0                   24-
#defhnu IYPS_PACRH_WP1_MASK     �                �x2000080u
#defin% AIPS_PACRH_WP1_SHIFT                     25
#define AI�S_PACRH_SP_MASK       �      �       0x4000000u
#define AIPS_PARH_SP1_SHIFT            $      " 24
#defing AipS_PACRH_TPpWMASK      (               0x10000000u
#defin� AIPS_PACR
_TP0_SHIFT0      �             28
#define AITS_PACBH_WP0_MASK     � (              0x20000000u
#define AIPS_PACRH_WP0_SHIFT                    029
cdefine AIPS_PACRH_SP0_MASK                      8x40000000u
#define AIPS_PACPH_SP0_SHIFT !          0        30
/* PAKRI Bit Fields */
#define AIPS_PACRI_TP7_MASK                      0x1u
+define AIPS_PACRIOTP7_SHIFT    `                0
#�efine AIPS_VACRI_wP7�MASo            $         0x2u
#defyne AIP_PACRY_WP7_SHIFT      �              1
#define AIPS_PCRI_Sp7_MASK         (            0x4u
#define AIPS_PACRI_SP7_SLIFT                 0   2
#dafin% AIPS_PACRI_TP6_MASK             (        0x10u
#fefine AIPS_PACRI_TP6_SHIFT          �          4
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
#define AIPS_PACRM_SP5_SHIFT                     10
#define AIPS_PACRM_TP4_MASK                      0x1000u
#define AIPS_PACRM_TP4_SHIFT                     12
#define AIPS_PACRM_WP4_MASK                      0x2000u
#define AIPS_PACRM_WP4_SHIFT                     13
#define AIPS_PACRM_SP4_MASK                      0x4000u
#define AIPS_PACRM_SP4_SHIFT                     14
#define AIPS_PACRM_TP3_MASK                      0x10000u
#define AIPS_PACRM_TP3_SHIFT                     16
#define AIPS_PACRM_WP3_MASK                      0x20000u
#define AIPS_PACRM_WP3_SHIFT                     17
#define AIPS_PACRM_SP3_MASK                      0x40000u
#define AIPS_PACRM_SP3_SHIFT                     18
#define AIPS_PACRM_TP2_MASK                      0x100000u
#define AIPS_PACRM_TP2_SHIFT                     20
#define AIPS_PACRM_WP2_MASK                      0x200000u
#define AIPS_PACRM_WP2_SHIFT                     21
#define AIPS_PACRM_SP2_MASK                      0x400000u
#define AIPS_PACRM_SP2_SHIFT                     22
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
#define AIPS1_PACRO                              AIPS_PACRO_R5t��6u$���+~����"�{�r��j�0t���������;o�*c�k��'��w���k�pc����+��+��Թ��K9(��m:	9z���&6�I�F'��^�S!��W�Ӥ�)~��+����x i������ؓFk�&N���^�d���Nɿ�$^C=U����<��l�$�����$Ҋ۹�(���s�l��Qv�]�P��<vH)/n��=B�;O?J��-�?�(�X���k��G���f������7u�TѴa��-���tR���Ypou����~�Z��Sm�A�d����?����골�i9o��\$r'm�	�*�S�"K�Q��`��;i~%�%Ϣ�=��&YdߑDx��j�MI=��;$��Qn)ɛ縘Q�
v4Fp��W��j����:�&B~�'j�x.��e�Cͮ�&��m�HAT<R
�0J��%QT7����&�
a�����'d���QƢ�I���mm�t������ ��l���~Q��S7Ƅ
�2��2| ����m�:���"�b	m���e��I[0��ة�����3f���Ub��I��.���NZ�[�T�ƭdM8��`@r��q:������)�>=���9}r��̟�R׼
#4�T4�I���Q�����,����\d#,ˢ����ة���i;6�����~��N�.�xɤ�>��ف/�?�ګ]��O�d��zX�^�G3BA* S�=���E|,D,w-s��<�^1�x��O��	C���~��#w�)�W���4u�����W����lZ^\npw&L�鵭x,vAۈW�O�;¿~$��4����j�f�nћ�^�H��V7<��#�·+X�@�5�&��"�h�D65�^�5{�a�G�oB(��8 "R֕@����CH*��*��E�`1����M�eG�� �d.�J4$���B�
խ�+S��N+��y��,�g� Ŵ̎i`}�N$�I��'O�x��w��@{�}��9/**< Master General Purpose Control Register, offset: 0x800 */
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
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PSS_M0SHIfTi)&AXBS_PRS_M�MASK)
#define AX�S_PRS_M1_MASK                         0x70u
#define AXBS_PRQ_M1_SHIFT   d                !   4
#define AXBs_PRs_M1(x)          �    0    `      (((uint32_t)(((uint32_t)(x))<<AXB_PRS_M1_SHIFT))&AXBS_PRS_M1_MASK)
#define AXBS_PRS_M2_MASK                         0x700u
#define AXBS_PRS_M�_SHIFT  �!                    8
#define AXBS_PRS_�2(x)                        " �(((uint32_t)(((uinx32_�)(x))<<AXBS_PRS_M2_SHIFT))&AXBS_PRS_M2_MASK)
#define aXBS_PRS_M3_MASK                         0x7000u
#$mfine AXBSOPRS_M3_SHIFT  `                    012
#define AXJS_TRS_O3(x) $              "     `    (((uint32_t!(((}int32_t)(x))<<AXBS_RRC_M3_SHIFT))&AHBS_PRS_M3_MASK)
#define AXBS_PRS_M4_]ASK    ! `      !0    `     0x70000u
#define AXBS_PRS_M4_SHIFT              "         16
#define AXBSOPRS_Mt(x)!                          8((uint32_t)(((uint32_t)*x))<<AXBS_PRS_M4_SHIFT))&AXBS_PRS_M4_EASK)
�define AXBS_PRS_M5_MASK `                       0x700000u
#defane AXBS_RS_M5_SHIFT                        20
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
#defyne AXBS_CRS_RO_SHIFT                 0      31
/* MGPCR0 Bit Fields */
#define AYBS_MGPKR0AULB_MASK    (               0x7w
#define AXBW_MGP�R0_AULB_SHIFT               "   0
#devine AXBS_MGPAR0_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AX@�_MGPCR0_A]LB[SHIFT))&AXBS_MGPCR0_AULB_MASK)/* MGPCR1$Bit Fields */
#define EXBS_MGPCR1_AULB_mASK �    "           ( 0x7u
#define AXBS_MGPCR1_AULB_SHYFT          !        0
+define AXBS_MGPCR1_AULF(x)         `            (((uind32_t)(((uin|;2_t)(x))<=AXBS_MGPCR_AULB_SHIFT))fAXBS_MGPCR1_AUMB_MA[K)/* MGPCR2 Bit Fields */-�#define AXBS^M�PCP2_AULB_MAWK$                   0x7u
#defi~e AXBS_MGPCR2_AULB_SHIFT                   0#define AXBS_MGPCR2_IULB(x)     $0               ((uint32_t)�((uint32t)(x))<<AXBSMGPCR2_AULB_RHIFT))&AXBS_MGPSR2_AULB_MASK)
/* MGPCR4 Bit Fields */
#define AXBS_MGPCR0_AULB_MASK        0           0x7u
#define AXRS_MGPCR4_AULB_SHIGT                `  0#define(AXBS_MGPCR4_AULB(x) 0                    (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR4_AULB_SHIFT))&AXBS_MGPCR4_AULB_MASK)
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
  uint32_t TIMER;   $                     `        /**<0Free Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  wint32_t RXMGMASK;                2         $    /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  tint2_t RX14MASK;                  �  "         /**< Rx 14 Mask re'ister, off{et: 8x14 */
  uint32_t RX15MASK;   �                 (    (    /**<0R8 05 Masc begis4er, offset: 0x8 */
  uijt32_t ECR;                 !                  /**<(Error Counter, offset: 0x1C */
  uint32_t ESR1;�                                ` /**< ErrOr and Stat5s 1 register, /ffset: 0x20 */
  uint8_t RESERVED_1[4];
  uint32_t IMASK1;   "   `                 0      $/**< Interrupt Masks 1 register, offse�:"0x68 */
  uint8_t RESERVED_2[4];
  uint32_t IFLAG1;             !         (     $   /**< Interrupt Flags 1 begister, offset" 0x30 */
  uijt32_t CT�L2?                           !      /**< Control 2$rewisteb, offset: x34 */
  uift32_t ESR2;                        "���m��0��� ���K��}�N򐖅��I�čz<l�[)ᤩ�W���ۼ��J�H*;V����ެ���1����>p\��SK5�#��џ���+��)�R�G�4&B�W]CS��9����p�����B!ן�wS#��^�l�S,'���.סRl�|rp66�g��%Z�J/�W�a�0P~���F��5!�[V_����>����x������m�}�G�s���2����җ�I�犮��:��	�G�{��ϑ
T&5Vۤ�)��+����D�T�\�."�F�T&N�%����֠u����і8΅���n(r'�^<((d���|-�^]�M뱆�9�c��x��fN�c��m8Dp��VbBPĚK�5X)��3\�:q��$�p�jl���K�Wj�k9�1�.�
͠�Jn����"��_N%��An��^�Yԡ��9�g"2��k��e��b%�Tu�^OF���.U�s͚�Mlk�h�S��V*¬�o�$�S��'?v�P�h�����m�7�	@���{��D%`���!�Y,��L�1������Q�Ir����-Lq^�n6�����f��Ċ���kxl�oH<&K}��=Ƽ���~�t�ݶf���ݍIVM��Mz�$m�@z�5B���H�['�@�u)lT6�q��ATK�>j3�T�����Y�Y����FS�W��-|-�z㫣����\�t�����|;��eU���A����2�N|�w!���+������;A���fp��,kJ�Xk
ь$0֋N�.˰;�|�R����Pl�:����82<�=j�����L�/�VNY׵A�]�D%{�P�Hn�v��p���9I��<x���$;��)p��w��7�=ʜ�tཝs̀��\���١Me��I�a��Ќ�X���W��Rq�﷐5�%G���%�x �V2F�=KB���	�m{�m<����f����u�&��7!��kn�F�K            /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
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
#defin�\��+��X��o/~=u�t�UI��W��C:���Pg�ˮ�Q�2"�2p�J%bt�s�����P�n~�i�A���H/�O�;��T*k�S�U$���E�=�4��v�����2a���)a"k�M;�?�������#Exzuf)��ӼӺG�p	��0�%їǵi ���������J��������I��,���09��ܓXn�����|�}Y!��p?P�W)�*��x㡬����tuLH6봩[���;�e��}�Á5�柿�m�W�B�����7��Y+d�0��,[��,�'ᴅ3�c3ϱM�A����1����Cj׏q�d2Q0�o� ��!�(I>D%���� {b1�L��h,~�fc؉������*˨I�M_y�bnW�yB�}Q��Q�*�������;��;6�P//g޿��<�=sf�k���e�_�,Y,�<eD�i{f*Q�g���	�:�1iw��|R�Bu���	u��L�����Œ�R~X����������Zt�p�g��R��t�$�)���Z{D��S?��2EIK���b�x��ˌ�2�<�Y��>��E6 !Cٷ����_b�%.�*�0 d)�W7�%UkXmyBPV��ٜ�D��&wq�`(B����Es��)޿�Yl0���p�h)�lE�3�_����������E���+��zL�������~��&ïw��J�����a߅D&Sf�>�|�ו7%�Z]�O�tV�љY����q�Ӕ�?䃽:^ �A�T��R4*����?�"
|lM�2V쉀5���_�=�x���'~��+��oȳ!�i^���C�mY��E�3\o%쌬r�qeF�!%qB�� �TJ����K8�xU&���̒��b���v,���}�S�l��	+Z4oS����^�4���^5�j1��;9e�"���r�C�k4D�-�Q�����	�7-Z蒭���<�W�������C�; o�*�K�JA�R_WAKMSK_MASK                      0x4000000u
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
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PRESDIV_SHIFT))&CAN_CTR\1_PRESDIV_MASK)
/* TIMER"Bit Fields */
#define CAN_TIMER_TIMER_MASK                     0xNFFFu
#define CAN_TIMER_TIMER_SHIFT�               $   0
#define CAN_TIMER_TIMER)x)        (  (           ((huint32_t)(((wint32_|)(x))<<CAN_TIMER[TIMER_RHIFT)+&CAN_TIMER_TIMEB_MASK)
%* RXMGMASK Fit Fields */
#debine CAN_RXMGMASK_OGMASK  �     `            0xFFFFFfFFu
define CAN_RXMGMASK_MG_SHIFT                    0
#defmne CAN_RXMGMASK_MG(x)             "         (((uint32_t)(((uint;2_t)(x))<<CAN_RXMGMAWK_MG_SHIFT))&CAN_RXMGMASK_MG_MASk)
/*�RX14MASK(Jit Fields */
#define CAN_RX34MASK_RX14M_MARK      `           08FFFFFFFFu#define CAN_RX14MASK_RX14M_SHIF�       `         0
#define CAN_RX14MASK_RX14M(x)  $    $            (((uint32_t)(((uint32_t)(x))<<CAN_RX1tMASK_RX14M_SHIFT))&CAN_RX14MASK_RX14M_MASK)
/* RX15MASK �it Fields */
#$efine CAN_RX55MASK_RX15M_MASK     "            0xBFFFFFFFu
#define CAN_RX15MASC_RZ�5M_SHIFT     0            
#defije CAN_RX5MASK_RX15M(x)        "           (((uint30_t)(((uint32_t)(x))<<CAN_RX15MASK_RX15M_SHIFT))&CAN_RX15MASK_RX15M_MASK)
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
#define CAN_ESR1_ACKERR_MASK       !          (  0x2000u
#$efine CAN_ESR9_ACKERR_SHIFT                    13
#define CAJ_ESR1_BIT0ERR_MESK                    0x4000u-
#define CIN_ESR1_BIT0ERR_SHYFT                   14
#defin% CAN_ESR1_BIT1ERB_MASK           (        0x8000u
#define CAN_DS^1_BIT1ERR_SHIFT  " $              05
#define CAN_ESR1_RWRNINV_MASK                  ( 0x10000u
#define CAN_ESR1_VWRNINT_SHIFT                   06
#define CAN_ESR1_TWRNANT_MASK        " "         0x20000u
#define CAN_ESR1_TWRNINT_[HIFT                   17
3define CAN_ESR1_SyNCL_MASK               $      0x40000u#define CAN_USR1_SYNCHOSIIFT!            *   "   18-
/* IEASK1 Bit Fields */
#d�fine CAN_IMASK1_BUFLM_MASK               !  ( 0xFFFFFFFFt
#degine CAN_IMASK1WBUFLL[SIFT                   0
#define CAN_KMASK1_BUFLM(x)                      (((uint32�t)(((uint32_t)(x	)<<CAN_AMASK1_BUFMM_SHIFT))&CAN_IMASK1_BQFLM_MASKi
/*0IFLAG1 @it Fields */
#define CAN_IFLAG1_BUF4TO0I_MASK                 0�1Fu
#define CAN_IFLAG1_BUF4T0I_SHIFT                0
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
#define �AN_CTRL2_MRP_SHIFT      `               18
#define CANOCTBL2_TASD_MASK                      0yF80000u#define CAN_CTRL2_TAWD_SHIT   �       !      `  19
#defife CAN_CTRL2_TASD(x)                      ! (((uint32_t�(((uijt32_t)(x))<<CAN_CTRL2_TASD_SHIFT))&CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                   �  0|F000010uJ#define CANC�RL2_RFFN_SHIFT      �          �   24
#define CAN_CTRL2_RFFN(x)          !             (((uint32_t)(((uift32_t)(x))<<CAN_CTRL2_RF�N_SHIFT))&SAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_WRMDRZ_MASK              (   " 0x10000000u
#define CAN_STRL2_WRIFRZ_S�IFT  `            "   28
/* ESR2 Bit Fimlds */
#define CAN_ESR2_IMB_MSK       0     (          0x2000u
#define CAN_ESR2_HMB_SHIFT     $     0      "    13
#define CAN_ESR2_VPS_MASK  $ �                   0x4000u
#defkNe CAN_ESR2_VPS_SHIFT               "   (   14
#defing CAN_ESR2_LPTM_MASK              p      0 0x7F0000u
#define CAN_ESR2_LPTM�SHIFT                      16
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_LPTM_SHIFT))&CAN_ESR2_LPTM_MASK)
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
#define CAN1_CS11                                CAN_CS_REG(CAN1_BASE_PTR,11Y�>d�.�Io`.@�n���K�5|߉����=��G����� �E���~}����Wn�nAg���3#G9����D���m�[�U<�Q���&��X<��̀|(��Ӻ�	�+Mh��C��fpB�[�ڈ~"\o��Տ�{#-��Ӱ7)O��-��݉e$}~SE�ޭf�2��r�����NJZUo�,n�}�O�!Y/�/{�F
b�1 � �4�&��%���2�a\)�G�r�6�����y��+�t@s_��}\Z��w�\c2��}�p��*#�Gq�g�H�v�3V�,k�r?�;B��}=�mۇ2�����5�����_R�/�^��7�ėJ�J�W���@�
sD$�F�6����5/.��|�]�!W�9<��B�J��o-�O��nx۽����]�_�2�>j�~"����{-�X�����ɵ���xNGC6e�����/���[}i�OQYE,/Sm�Ec���*c�,&O����⹶����9,D�L1)@�	w���N&%��/�b,ɴF�6ʥ@OR��erbTd/u��L̽*��U��2V�K���$��x.�Ik5h�ǰL��!�?1�P�m�i��l�@�:M$#�����7�<�Ai29�OW��G�ڜFL2ZLɃūT�b8R�h���(W����x^�c�3�8T�{��y�j�e����Ϣ%�n���WSy��VJ��s,��'���Ð�)K��>���l<��O!٥KA�U�j��"yG�RDKp�"����4Cw��"#Ia�'���6��H�{�x��I
 �c ��҉���]SO��7�����=��]LEm��
-JÒ�b
e芹D�s.���W
P�v�k��DM
�QT����+�M��)�/�K�0.e��3\s���0{����AE���D���m��S:y�e�B�]rö_���%�&��G ��d�d����܇M��m�x`�ң��T�u	�����)Viq�+���4V�$P�#�XB�kv���])��#˝�1��%q_REG(CAN1_BASE_PTR,14)
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
#define CMP_CR0_REG(base) �KC��H�ǁ*%�Y�~���j�V���l�]���2�8���:RSYw}����N$$^�y�0���@��;�����
��2�Zv�Z�d@n���ҚL֫r��H�V�r≑#5�G��6��<a�� "l#�#���i�
3�Fl�I[�6 L��]-��Ea�2X�CUĮ ��.��P��i��j�(��[ٓ�T(��5������6,�1$�)������ǂ~wXN��<�ho0��ø]9M����0X�:S����n���MѾ��)%?6pl�P�����>�7�D���ٹO�aF�w7U>N<wޕ���=Y�$����aC��Ԟt����y�������\�v�mm��ݝ�����2%������/̒oc4�<S�Tѳmڕ��+L�ݺfn�_��Ld[ .�'��ڠ�!����bU��g�����YF��A<oaZE��i؉�;���p��W�5���Dv��a2�\E���q�W������'| ͣ�|~�9��ؐ��Y�=A��x���?���`��@d~|����	-�z��Ei����~Qi�P�0m Oq/Qf|�Ϯ��\�
�_h���Ab�vz�~��xDZ����_@9�E0���&x����S⬧}������j�F��%d�����7\O�a��A K�Y��r���3,j�8�v��z���_�����g���(��3�f�5M+��²(��Z��9�i����v��j97��j�x��&<���zM��4+k"��^xli�4؈1"���;PA$_���j����%���p�������Wo��9�iT{����l+R��"��,��26lڣ��q�N���҅��>D[_��4`���WK罗P��d���at$�ؖ�h��JS�P'k���,��d���7H��M�/&j�i��Q�z?�R�uB	��iJp�#�Tq;5-���~��t��8K�!	ӕ���7��a�w��2Ɛ�R{��qk����OB�㕇���]@?z�8R������T�M��-,��7A����f+��\��s��}9�?�6$g��?We��sh!"��� �w�=��Z��J�i?@<��
���0l��0�Q���	7�����U1q�r5��js��r���=*Anv�cc��(OM�i�Ȝ̝�4JOQyᶬ��XV{_�PMO�	��2H7�#�L0K3ՠ@I��*&����3^Ηo]���ٞoe�B/åR{F�������s~����<�S{���
#��ҭ�Rlq��U��fT��_�n9.������t
9X����b�(7�~[�\3����"���\j�#���h9��!��M�$�&����}����,u�1��A�|����Oϟ�$� ���A�F;��Ѭ�Gw{P~�؜*I��[�(s�3R�Z�^����r���v��ah��	$�DÅ�ř��O7R(�RR�G�| ���uC�r�mm�1I;X��pI�'�_w�}�n�р��:��@E)�Q�S�̎<N��S�~�w�6�����O���9�prKdx��2�AF�b������C#�P����l�����&"݅��k|\~*����y_/AA��[�����Ճ�N�C���q��}�����I&��ڕV*D�4�,
:�0k�E�L��<��ҳ��x 8؞��3�;H���P�����o� FLWWSE���I��a|'�H����ۀ�� pm��a�8Z�����o"@;�������6ܱT�1��o�U��FF��.�Aw��$j"�(�:�9��� �
�����ιm�4�@���
,�t�-eJhQ�P}a
�|�?fE����L�e�ω g�V�y�r�N�7���`�o]P��I��<4Y
�P��AH1;�ֳ�J5�ȉ�M�����Gxw#���R");-j�dvG*���8�X�~3������G�g"0��*�;�P�
�$1F�c�߯���0&'N���~�(�]6�Be CMP_FPR_FILT_PER_SHIFT                   0
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
#define CMP2_SCR                       �   !     CMP_SCR_REG(CMP2_BASE_PTR)
#define CMP2_DACCR (          "        "         CMP_dASCR_BAg(CMP2_B�SE_PTR)
#degine CM�2_MUXCR          `  0                 CMQ_MUXCR_REO(CMP2_BASE_PTR)

/**
 * @}
 *' /* end of group CMP_Regirter_Acceqsor_Macpos */


/**
 * @}
 :/ /* end of gbo5p CMP_Peripjeral */

/* ----------------------------------------------------)-----------------------   -- CMT
   -----------m�---------------------------------%----------------------------- */

/**
 * @addtogrou0 CMT_Per�ph%ral CMT
(* @{
 
/

/** CMT - Peripheral reGisteb structure */
typedef str}ct CMT_]emMap {
  uint8_t�KGH1;        "                    a      /**<"CMT Carrier Generator High Data RegisteR 1, ofFset: 0x0 */
  uint8_t CGL1;        0                      "    /**< CMT Carrier Generator Low Data Register 1, offset: 0x1 */	
  uint8_t CGI;      $                       !     /**< CMT Carrmer GenErator Hmgi Data Register 2, offset: px2 */
  uint8_t CGL2;(                        �          o**< CMT Carrier Ge~erator Low Data Register 2, offset: 0x3 */
` uint8_t OC;               0  �  0           (    /*+< CMT _utput Control Register, offset: 0x4$*/
  uint8_t MSC;                                    (/**< CMT Modulator Status and Conurol RegiSter, offset: 0x5 */
  uint8_t CMD1;            $                       /�*< CMT Modulator Data Register Mark High, offset: 0x6 */
  uint8_t CMD2;  0       `    (                    /**< CMT MoDulator Data Register Mqrk Low, offsev:!0xw */
  uint8_t C]D3;                 8       !       $ `/**< CMT Modulatop Dat` RegiSter!Space High, offset: 0x8 */
  uint8_t CMD4;          d    "                    /**< CMT Modulator Data Rugister Sp`ce Low- offwet: 0x)!*/
  uint8_t PPS;                                     /**< CMT Primery�Prescaler Register, offsev: 0xA!*/
  uint8_t DMA;     �                           `   /*.< CIT(Direct0Memiry Access Register, offset: 0hB */
} volatile *CMT_MemMapPtr;

/* ----m---------------------------------------------,------------------------
   -- CMT - Register ac#dsSor macros
   ---------)-------�------/------------=------,-------=----------�)---------- */

/**
 * @addtogroup CMT_Register_Eccessor_Mac2os CMT - Register dccessor macros
 * @{
 */

/* CMT - R�gister accessors */
#define$CMT_CGH1_RG(basm)                       ((base)->CGH1)
#define CMT_CGL1_REG(base)   0  (     $    �     ((basa)->CGD1)
#define CMT_CGH2_REG(base)                       ((base)->CGH2)
#define CMT_CWL2_REG(base)         (             (8base)->CGL2)
#define CMT_OC_REG(base)                         ((base)->MC)
#define CMT_MSC_REG(base)        `               ((base)->MSC)
#defIn' CMT_CMD1_REG(base)                       ((base)->CMD1)
#define CMTCMT2_R�G(base)            �      0   ((base)->CMD2(
#def)ne CMT_CMD3_REG(base)                       ((base)->CMD39
#define CMT_CMD4_REG(base)           $           ((base*->CMD6)
#lefine CMT_PPS�REG(base)    !                   ((base)->PPS)
#define CMT_DMA_REG(bas�)            $           ((base)->DMA)

/*�
 * @}
 */ /* eod of group �MT_Rewirter_Accessor_Macros */

/* ---)--------%--m)-----------------------------------)-------------�---------
   -- CMT REgister Masks
   ----�----%-----%-------/---------------%------------------/----------------- */

/**
 * Taddtogroup CMT_Register_Masks CIT Regi3t�r Masks
 * @{
`*/

/* CGH1 Bit Fiulds */
#define CMT_CGH1_PH_MASK            `            0xFFu
#define cMT_CGP1_PL_SHIFT                   $    0
#defioe CMT_CGH1_PH(x)           !!      (       (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))"CMT_CGH1_PH_MSK)
/* CGL1 Bit Fields */
#define CMT_CGL1_PL_MASK   (       `             0xFFu*#define CMT_CGL1_PL_SHIFT              !         0
#define CMT_CGL1_PH(x)                           (((uiot8_t)(((uint8_q)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL!_PL_MASK)/* CGH2 Bit Fields */
#definE CMT_CGH2_SH_MASK                         0xFFw
#dufing CMT_CGH2_SH_SHIFT(                        
#define CM\_CGH2_SH(x)  �                        (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK)
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
      uint16_t GPOLYL;                                 /**< CRC_GPOLYL re �ɭ""�[ބ�K
a��3��Y>�h�����l%X�PTF����_��bWh���	ʶ�3�cΐ=w_ǜA���Ī�GzRj�mt�r������8z��~k�HLVҙ�>\\���Q����R9��n�&������EKZ`E��s�������
����w��H$��>HB-F�V�@V�����^�bإ�%R���Q�*�F'��F����%�)�)�`��̱�)�X��H��G�����?5E=���I�e�bͳ�(�&Ϭ�7����Zk�d_��̺��{�����'��G7����>Ā9�A�@
���Y�a8Qѵ��0�����Y����oD��{�=�QH�h\d+����8�C�'gv��7�RMJ�|]9ޚ)��,��B����HP]Qh���.l�	?n�+���'�
�� yy�	�|�o�T�D��@���ݖ�h�:͌RZ��'�� ����;�ª�����`:�x�%���
A�!�Y �PO�>�b*�ř�р Fr���"���(�c�Z	9U�1Udw�h�y�X�A��P�+�GuJ��G�\�EC����7��ܵhe	�`����ܘ/�n���i�g�cb����R�#rмh]@��F���iid$o�2�'�;iU��z��b�}?T^�
u�P���)������n�m��yKp��cc��UZ��z�'�
B�#�wQ��Uɭx-�K�	\{�q׀V�8 lAw\���+�C$��D*R���O�1�m:>���L~�}X��2חWe�lW_��Z�sv�t~7a�fu-�:WP~N�N�����*'R�_�4iwʸF�)�1W>�@���J������`]�(ǥp罒�h�Xȳ����&�TcC�R��F���k�C"���!N ?�r �x�cU��勽�Np� �]�'{{��T�ԋ"�%�t�f��[oI�/`�)/��S���D��U ݭN@�iH'��:8�r�(�h|^�Su�J_�uX[��#Jt8_t CTRLHU;                                  /**< CRC_CTRLHU register., offset: 0xB */
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
#define CRC_CRC_HL_MASK                  0       0xFF0000u
#defkne CRC_CRA_HL_SHIFT   !                    `16
#define CRC_CRC_HL(x)             0    $       ( (((uint32_t)(((uint32_t)(x!)<<CRC_CRC_HL_SHIFT))&CRC_CRC_�L_OASk)
#define CRC_CRC_HU_]ASK                         (0xFFp0000u
#define(CRC_CRC_HU_SHIFT       �(                24
#define CRC_CRC_HU(x)  $    "                 (0 (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HU_SHIFT))&C�C_CRC_HU_MASK)
*0CRCLL Bit Fields */
#denine CRB_CRL_CRCLL_MASK                   ! pxFFu
#define CRCOCRCLL_CRCLL_QHIFT                    0
#defile CRC_CPCLL_C�CLL(x)            0          (((uint8_t)(((Uint8_t)(x))<<CRC_CRCLL_CRCLL_SHIFT))&CRC_CRCLL_CRCLL_MASK)
/* CRCLU Bit Fields */
#define CRCWCRCLU_CRCLU_MASK       0            �0xBFu
#define CRC_CRCLU_CRCLU_SHIFT                    0
cdefine CRC_CRCLU_CRCLU(x)                     � (((uint8_t)*((uint8_t)(x))<<CRB_CRCLU_CRCLU_SHIFT))&CRC_CRCLU_CRCLU_MARK)
/* CRCHL Bit Fields */
#eefina CRC_CRCHL_CRCHL_MASK    0         (      0xFFu
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
  uint32_t INT;                             0݄�<}'{)�K�>7��oOl�X�R|U*�9��Ej����R���,�gRE���֭�,RI<���^�Qٜ4�+m6Sx%yj���"z�ۮ�t��y2�%"����)7�:K��d�|E�&��&��8�U��bB�-D�+��L׍�UŜ$5�e	�s�L౱v3��k�M�>EUc����Q߷0��%R�Y��:�j5P��djnWu{�F1��ҩ����i�ŉǲ_'��OYz��	`�c�XSH�g��<��E�&(jl�x����|Go̭�X(dyE4�a�$�Su}�y�ߑ�;D���v�5��>,9f�������ħ�����^�e1اJ7��L��Y�n����X[u�b��\X��H��kq���f��\�=�O5����#��r;�n��с���ѻ9~�k$~K���w
�X��{��Y܁��]m�c��#�K+���J��wM�]�Ex�LUz�%�}��Ƽ��k�2*b?:�Z�/�3B�42|a���ǭd�к��}��9c`|�<%��d!,<g�'�����ֆ��a�c汘tsN�[��i0��k������ڦK��I��P�s8��R�✫�ٲ�m�\�/v@�����MΛ`�`2ʲ���0
95������I5ɪ�J!!{�NC����,q���3��6iFQwXŧ�-��]#�[])����IrtxH! 7A��(������ҥ�\rX�I�^���8|�4�h���К�$N�͈�-6ȍ��V2�
y��zhWt���㾿�3�k	�oq�O�Z�	V���p�`h�;�Fc5!$��H-0� �e)�0�ǳ+颯�ՠn��?X���zc��*f�8���
�{_�G�y"�a����O��;d��\�۞�o�������<O�6���M:�q��_C��`Xr�R��]��M1Hx���@����
W�9�&�FY���(s�
y��[�+u��X9��bd1���p޽^l���b���v�OS�M��e�Wf����1��&6���"X�@��)�%�  �Q��G���n@�=��m�bfƧ�]w��"#h	�\���L[Rֽ�,@���{�Q��uZ�s�e�)M>�h�������s���0ܤ�nW։7|��R/�I�T�'���|��@G�^Hh=�����{j�8�$b�5�84^A+%�^.�T�K���O��6^#��6�//�����_��4%��^�5���:��Q�2������OQ]E��c��bJ��ļ9!���n,��n�<�݆*�	���(�a����S����cTywW�gD��z�� ,��a=5Lc������_�RGO�/1�Wʝt�P�]AikyI�^��'5�Z	��AQ�b�nƳ�1�K�4�-�P�F�Fݳ/3I0I��˻z�qb�cJR1@�Jx��yɣ���a��F�n�jْD%޻?GD�eY3���yE+ �j.�# &�s�����9Ϗ��#�yu�����B}�FZ�WL{����uhs̿V�1�!�H�rh@J��zA��"���:�Q�.��Ț������%u��1i�����=�q��[D�o��^+��7A�� #����EB�7�|7���v�)rLU�rB���M7u�°藕kb(���ćC3�͋C�2��:�����.}&va8���i�LQk�w��� >y�>qd�;�}����{�)���S�yF����|���������3�,�W|��i�����L�S�j0�9os�9�k�k��gd�b<�p@3^EZ ��jN��ء�ú��b�	7��]���<���ʡ>*��-�2����+)�H�\Ōۦf2�4X���KF��=販�6yka%�h�%��H�P�A0t%tV�v����\d�Q�*� X��FY���Kn��."��v�Iա���Oe��ԥ�u���h�+�ѻ���_�WG"�w9��]�/"����N��mq�Q�$��A�"%і�������$��$(�g*�N!+�<��iJ�״�ˏh�5�ƍ~��%�Jn�ݱAvHzף��	�             /* offset: 0x1000, array step: 0x20 */
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
#define DMA_TCD3_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_SLAST                           DMA_SLAST_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DADDR                           DMA_DADDR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DOFF                            DMA_DOFF_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_DLASTSGA                        DMA_DLAST_SGA_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_CSR                             DMA_CSR_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(DMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(DMA_BASE_PTR,3)
#define DMA_TCD4_SADDR                           DMA_SADDR_REG(DMA_BASE_PTR,4)
#define DMA_TCD4_SOFF                            DMA_SOFF_REG(DMA_BASE_PTR,4)
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
#define DMA_T�5M�س6e�j������������u�5�'����$�-��n-~���LP�4�\;��D���u��	� �}H�!&�k�C	���3�5����C2���H�̙*�o�>��*˧c�j!���屾S{ShL�5�����R+tRr"a����K����&�������d�����y�ܣº��gd9[b�Y����	b`cg��~��A���A
��)m��޼����L���a�eڪ/7�B�(�u�Nb4.�-l��V�8D�~kg鄺]ӖO{�/���˝������m/�Cbk�<�aA��myu�Ѳ(���Q��uQ���`@�S>�0�ib/l��\�N/܂y�J�˙��۱hʣ� �E����n�;vOlˁ���F�;;��kN�,P���:�����p�����a!DC/�dS���2�g*�r3#�!2o	{�n�'���JO��*@����,zZ�:��ʴ�#�jZL��!��	�Eg�>���ʹ�ݨvx���T���Y�]UX���:��J�=�O���?AF�MN��4������Ei���F�Y�\�&V�:��L:LUMѓt�Zb0���E���#nD�͟%���e����J��Z�}����k�L2�2s���]2�A�S�0�"�$5�-��(X7v��g����Bթ�h2n|�uޯ|3��g�Q�p�#i���Ɗ��ޣu�^�_�\��d7�'�|�g^ط��;��LV��.�������3d�ݿ�����N8�:ye���~M�Oۉ�Mk+O����� �QҤ�3��^k,/���и)aGtF���?��x �Hh��E�����gl��JV�h��~�Pq�a�-t=�!�X�r+���T�<O��N�.�p�ԉfe�S%�B
$`�)�/�u��v%W<��v �HSq�#ؽ�����F�/���?œ�$��[G �0z��e|�բ�%�d H�`?��ܾ����w5.|_�o�Kc&[���u��D-�DA�:(	Q��`���3�l�9�)                    DMA_DLAST_SGA_REG(DMA_BASE_PTR,5)
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
#define DMA_TCD10_CITER_ELINKNO                  DM30ӡY���K�Qi�U{���u� ���n�]�F"S�x=����ط��>p�!k�J�7l39��8���9�(�7�6Ѕ3[�H�˲��ت�FO�d��͊H����|*:27�n��n�;���OAv����',������>?:lq*�[V�;��$a>�
����;&5o`�2 ��&K�赡8	�Tzʁw�N�o����֖ޙ�9\���M�C �I��9��Bm5t]�FM��/�+�,�u�F��h���Q�8!#��1�G�ҍA ,�/ZU���Z��-�����Z���~LW����ޜ;C���	�ܓ
_�|���X��b�� �+�uY�Ҽ��:����쾭��e�藐~���Cm�G������&��}����q2��bC,�K_$je���5<���Y��=��۱_� �)�'x�B��%+)a��,Ȝ����=��N�d	8�Dϩ����N�z&��I&kj{�jN�,D�>�(��uHA9�U����K5�y0݇މ����d>`*���(ݓ�V2���A����x�,�n4H��8��BG���?������i/lT\y�g]���a,Zw�f>��>�܎p[�׎߾W=;���6�=[n\�+wn����c�:*�D�-�R��^ze�� �W�B�f�at���ld�=��J
�P�����{O�s�q�4�e[��
$��j��L5i�Ag~)�֭�E��}�6 BZ~�]�����;)#j|��?ef���I�@k��Œf�O�3�����g�aQ�%th����j|y�y��O���(.ה5�6]�Ŭ��D] �+�����wRuӃ���fc-4]����y	(���>���ȥSe����ʉ��^04e^=��������*n��En]�W�Tg>���L�B5�#�ao�Bq��$`�����2��w8� ٿV�շ�U�`�x�_?�H�cϮ��A���������&l0cK:cz��>���t�4�f����Z���٪�������|�{��Vv��     DMA_SLAST_REG(DMA_BASE_PTR,11)
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
 ������ɥR���
��F��̠�@�B�d�)����Y|R�B:��״� ���^���V./j�$��i�g�7�"�˾�����פ��|_�Y��?g�/����t��߻&pdu�~
�A�S�b��Z�$]�MyH�-��04K �ܹs�����:��1����}�\7<�D@.��yf^v��֫���0�Ts���<){��X0���qv������׶/�,���:�#e�C���dӀI�����ϊ��E�d�b����X$�a�:�k$���P��K��b99T׬�<̈́�)���(�ČWR�'x䔀�L���m�#�f_ʑf6��6ׅ��j�� j�[
,gDd���`1|��0�r!��K�b<*��gpt�����Y�(�q�:T4���;"��;C��e�_X�;�'OR�~7��uP��Rˁ��'���
�duVg���u}%*��k�zΧ�gyW!864k��|�%%�Xl��x��Md�����)�	઼k��+�:�kJϗ|���=�mF����bh#��/��o�����B���M-�P�Ox8?�ɥ�f��M*����$�� �𤵩�es��ٟ�>Q,�����|���I3#��/,.>�}t�PF���tm�[₃��Y(���iij3�����`��D���������'o������Ks���@&�����]�O<��?84\�������<%��
ya|�8u��	,9�Ϙ?���H�in�!��]$~%J�.�Y��9��y��1W���1ڋR�tl���mk��;A�,�+⫶K�9��Zʪ��y��f`7�Wl}����$,�j@'�kF�H\��S`�d���r_DC���MU%�I�w��m�f���g�>�A�j|Jq޸'5HJ�t�@���T e�R��/����7��.��`byz%$n3p[1N4�^q�JC�ħ��vK�%gRȠ��$d@�>zCX�p�<w����t�hu�3B��WPp�4U>�{�P�䨼�w���  uint32_t PID6;                                   /**< Peripheral Identification Register 6., offset: 0xFD8 */
  uint32_t PID7;                                   /**< Peripheral Identification Register 7., offset: 0xFDC */
  uint32_t PID0;                                   /**< Peripheral Identification Register 0., offset: 0xFE0 */
  uint32_t PID1;                                   /**< Peripheral Identification Register 1., offset: 0xFE4 */
  uint32_t PID2;                                   /**< Peripheral Identification Register 2., offset: 0xFE8 */
  uint32_t PID3;                                   /**< Peripheral Identification Register 3., offset: 0xFEC */
  uint32_t CID0;                                   /**< Component Identification Register 0., offset: 0xFF0 */
  uint32_t CID1;                                   /**< Component Identification Register 1., offset: 0xFF4 */
  uint32_t CID2;                                   /**< Component Identification Register 2., offset: 0xFF8 */
  uint32_t��X％+fcVee|B���hͦ�.:*�GN�N����@������؊�Yߡ'�ez��~�_��>d���y��|��R�������n��B (/�tM�s!��0|��RH�����'����K1g��Z_�49w��}$� g]�2�}c<�@_m���ءO`F�)��	�k�{I:7���&Q��V-�PA�<N���L���]@��ƙO]hª��o�MoQ��L��1�A3<]y�/m�3��ܑY��h>�u�Zݲ�sx6��T������X��A�d!v
��Jb:<C%,�rA��[Y���{���������g�/A����V�1���:���2~x�Q�p��\6�;*�tO�)��o�l���v8g��w�E,[,\��X����y����K���B�ݽ�����h_�.:n.q&ka)�E�UV�\��8F_V�@3e�t��>�r�4ER�7��hl��9��ԩ�K6���{��U[8�_�bq���Q�@~m��0:���Z[����,/�}��O�QI����`Q���T��%@�`n}�ArCv�P1�������7g��@����&��2�-�z'�{��d���>�gŕ�{)��,J���c���(w�m��c\H-M�!�.O���	E�L���>䎡�g�e�b�d�
�Af��ơ���C�
�g�ߘ��w�`P��S8�=�i��@+L�$ߛEx����o�q��R�d��i5��fa������7^{A�#�)VW�O�p�|��*���֚2|�ΆXL���z:�E��-!\���y&��_K�h�N�O�s�o7��^�K��I0յ�U5�� r�/�zm���m��hxLѐe����ϔ���3�Zѽ�E��kB�puZM_3�3�c���Se��$�2"(�'�9&G�sL�d��|r����j7�	s�W�{b�^0cOO����Ng��A��H������Q��`���b��A�����R�m��TE��(g�se,index)                 ((base)->COMPARATOR[index].COMP)
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
#define DWT_MASK1                                DWT_MASK_REG(DWT_BASE_P�R,1)
#define DWT_FUNCTION1                            DWT_FUNCTION_REG(DW_BASE_PTR,1(
#define`DWT_COMP2     0                   (      DWT_COMP_RdG(DWT_BASE_PTR,2)
#define DWT_MASK2                    !           DWT_MASK_REG(DWT_BASE^PTR,2)
#define DWT_FUNCTION2                            DWT_FUnCTION_REG(dWT_BASE_PTR,2)
#define dWT_COMP3    (            !              DWT_COMP_REG(DWT_BASE_PTR,3)
#define D[t_MASK3                     !          FWT_MASK_�EG(DWT_BASE_PTR,3)
#define DWT_FUNCTION3      !            $        DWT_FUNKTIGL_REG(DWT[BASE_PTR,3)
#devine DWP_PID4    0                            DWT_�ID4_REG(DWT_BASE_PTR)
#define DWT_PID5                                 DWT_ID5_REG(DWT_BASE_PTR)
#fefine0DWT_PID6                            (    DWT_RID6_REG(DWT_BASE_PTR)
#defin� DWT_PID7�                                DWT_PID7_REG(DWT_BASE_PTS)
#define DWT_�ID0             (                 ! DWT_@ID0_REG(DWT_BASE_PTR)
#define DWT_PID0   0              (              DWT_PID1RE�(DWT_BASE_PTR)
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
  uint32_t PIDR5;                                  /**< Peripheral Identification Register 5 offsetz 0xFD4 */
  uint32_t PIDR6;                               !  /**<`Peraphercl HduntificationdRUgaster 6, offset�"0xFD8 */
  uint32_t PYDR3;    `              (   0          /**<`Peripheral �dentification REgister 7, offset: 0xFDC *
  uint32_t PIDR0;                       (     �    /**< P�ripheral Identification Registar 0, onfset: 0xFE0 */
  uind32_t PIDR1;                                  /*"< Peripheral Id�ntification egister 1, offset: 0xFE4 */
  uint;2_t PIDB2;    (   �                         /**< Peripheral Identifikation Register 6, offset: 0xE8 */
  uint32_t PIDR3;  " �    �   "              "     /**< Peripheral Identification Register 3, offwet: 0xFEC */
  uint32_t CIDR0;                                  /**< Component Mdentification Register$0, offset: 0xBF0 */
$ uint3:_t`CIDR1;             � $      !           /**< Component Identifica�ion Register 1, offset: 0xFF� *�
  uint32_u CIDR2;                                  /**< Component Identification Register 2, offset: 0xFF8 */
  uint32_t CIDR3;                                  /**< Component Identification Register 3, offset: 0xFFC */
} volatile *ETB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ETB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ETB_Register_Accessor_Macros ETB - Register accessor macros
 * @{
 */


/* ETB - Register accessors */
#define ETB_RDP_REG(base)                        ((base)->RDP)
#define ETB_STS_REG(base)                        ((base)->STS)
#define ETB_RRD_REG(base)                        ((base)->RRD)
#define ETB_RRP_REG(base)                        ((base)->RRP)
#define ETB_RWP_REG(base)                        ((base)->RWP)
#define ETB_TRG_REG(base)                        ((base)->TRG)
#define ETB_CTL_REG(base)                        ((base)->CTL)
#define ETB_RWD_REG(base)                        ((base)->RWD)
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
#define ETB_PIDR5                                ETB_PIDR5_REG(ETB_BASE_PTR)
#define ETB_PIDR6                                ETB_PIDR6_REG(ETB_BASE_PTR)
#define ETB_PIDR7                                ETB_PIDR7_REG(ETB_BASE_PTR)
#define ETB_PIDR0                                ETB_PIDR0_REG(ETB_BASE_PTR)
#define ETB_PIDR1                                ETB_PIDR1_REG(ETB_BASE_PTR)
#define ETB_PIDR2                                ETB_PIDR2_REG(ETB_BASE_PTR)
#define ETB_PIDR3                                ETB_PIDR3_REG(ETB_BASE_PTR)
#define ETB_CIDR0                                ETB_CIDR0_REG(ETB_BASE_PTR)
#define ETB_CIDR1                                ETB_CIDR1_REG(ETB_BASE_PTR)
#define ETB_CIDR2                                ETB_CIDR2_REG(ETB_BASE_PTR)
#define ETB_CIDR3                                ETB_CIDR3_REG(ETB_BASE_PTR)

/**
 * @}
 */ /* end of group ETB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ETB_Peripheral */


/* ----------------------------------------------------------------------------
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
  uint32_t SCR;                          ��L4��q����ۛW��>�䣈|��K��Mۜ�H�;
ֶc$�,4�n�K�>�����i�zDԼ�����ùX1En�=/]{�X�g����e�z�>��w-��M�?0�S��z�G�x�̶�~#��G��~��ɀ}t��r!Y��aʏD�C2�Q�~*8����s�?ڠ}y��Ӎ���q��Ș��Uq��3W�2��xTN�v��+!���e�7P�o4>���Y�У�G����-�(� �t���|���;�S�wa�,q�z�e�tͤ�e�9H��[��J�Ⱦ���L0�t{G9�V�G�c�J[�� ��-���������̀Oƨ������y>���ǝ���ͅk5�.�4�q���>C}A%<�<6�k7��޷���	�^�Q���b�ӏ�Ҭ�e5G��k�e��h"ʓ`����ۈ[u��ZW|h�WωUg��Yq�ʥ���g^���;wG�^��[�!i�<���b�d.lx�[���8�1!@e�O �E�'  ՗�Yg��}��N��y��F~#��Z)�x	/E��"����
I��"&�;�)�z/����g�ls��xJ-L' �1H�c������-A����c��������$���O?v℘�Izn Hc�WpJ��5m)?��AW���sHk�_P˸� k��5����:�Ι�l����� �<f���M�?�SC��e�r!�ކR�a f�T����|hɹ�k�9o�h�\؍��?Jʃ5T�,�H75��> h�n�\��m��}IJS�&`�0������8���F�=�@���u��rn���͏�]8�n�'�q�F����3��iA�VX։�$j+9'b"�}�Yf�8�B��M��z�UQ�w�*�ArI��b+�j��_hHd���ߠY���URXTVP*�,��|Y��m�M�U�K����d�i.�R�G�͌����4_з1R�GhѣUq^JO�kU�ջ�ӆ5�����J��5��ԧ���� uint8_t RESERVED_5[4];
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
  uint32_t ITATBCTR0;                              �G�G���<���t�5��'�`�����.�$��ŝ�>�q�I4�j�Xo�!��N������o��elk@ܝH���;rF:VK���9��җ�,Ƈ���q���]�vm�ym��>6:�� ��eDw-;�c2��M�N����1���z�縠S�xi�?�U^����@���i�E��0x�=Fht�S��(�
=<@����!���b�mV(��j�_�R�~O��6/�;����-�F�!5ݬ�n��V�fr�
�
��&q4}�I�Qr���l�I�{�6V�U�ոS.$Ǯ�S8������%/!i(t���G$�A�o���|		e)}\!�v��1*�7g���3D��||����"��9z���A?5Z��5��e�T*��3i@��0?��E�c�{��h��O铀���beo���)�Y��q�*<Z�5;�^�tĭ���D:~	#߇SaX���ӊ�	\�x�Lfڢ������xx)��8n�ݔ�0n������Ѫ	�2$Lr`���O�H�qZ�-��\�X��J��%;�a�h7��/)@~�X�XJ�]�Q:"�8xW�'���z�%�	����^ǐ�!*g"�S�f�۽�>!�vv^Y:�4�����镴�_S�.V�r)��M�j���H��f)�j��?&|���(�-e�=R�k�0�r�P��j�85=� ��"�W�O�r�k}��@�&�T���V�*��j����>��`�?��x@������?2<`�9F8WJ�Q�V�:$@?y�~D ߦ���iQ��G'(�S�mK���wo9���`���n?�[͝B�5�ٖ@L���x���8x؇W{u{��}eF��yE3$4��}��3�?����Ų��/2ӕ�w�Y|�l�Z�چ����i�]��MףZ^ܸc-Ѽy��#��Ԥ�痡5`fi?����a�Ij9D��u�(�Os`�Q}&�/��P�˺�23�݅<p$_��v?�Q���>����ʙyz�ku�$                             /**< Peripheral Identification Register 5, offset: 0xFD4 */
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
#define ETM_FFLR_REG(baseP������َq�݀<nGx�F���-�I���#��Pn	����k*�c�"�/,'܂7��_09qt����(94����^����Iww�ѕ�5�����l5�g~e�֙�0/��gS���^@j�(�TN�Cd�0ӏ1Y��o�r��o��� ��h����1�K�jc�� �ɝ���{��y�%1֌?���b���s�ô6u0O��:�rl�~��� ��i�U���J����ǨľH~6�o�E;#ɪ��'f-�^�鵅��sQ�b��t��c���{�HVTf�'sBM��_�>M�J	�"���>vq���(:R L�^e�����؊b'��**�3�F�񦈜���S-����`��>��kB�;z�y�S_A�!2�DL!��%�!���T�8����OqP�S\�ة�I�K9�Bms��+��g��K^��/�Mq�3J�'���x:�����VCS�/�6cd �֗�ON(��y[B�⇴�"�}�wͫ���hbf' ��|�CϣPao`[�s����E�v�V�i�,܎�ea�o�V�}�w�w��n7��o7ߟ��ʇ��� ��e��c�6�Nh��ۢ	��k��G�xj.�}�Y���`�W*$��B͜�[O�������V���-��g�G���W���K��G�=j/���1��y������w�B_�y��>�{1��2��Fk�)r�%�F��[��fVʿW]����v��G�<d
q�^O����U��nu8�C��>z�5�P�}U���;Q��Ssl��"*k:��� ���B�f�eCX2�v��7RW+ >#T��W�76*���ѐ0�:�%��f��T@�s}�����H�S�����:>NS7�v6��am~���3Vz�����͘�,;P��xo�K6h�[:���c�Ȁ����Z���C�D�v���ٵZ�ff�=,,gq���TmIs;�'A/rH[�����Y�MUP2*Z���gRD��v	� �&p����5o�t|�!��h�#�0(nl����/cۻ�>��	V9�m������Q
��~U�l�CO3c�'Up����)��z�/n�p*	#<d��� S�T�V�p��0��T5�7�����~=�^���l�
^+�(x�B����'���&]��_�墨�nHm?�۱7��&�=Sb(6oO�;�t�;6N��'��Y��B�mZ�]����<��rw��s`P��Z�ی�\���<��� ��><%�o�oH��כy]u�!���+�:]ۡb��杷dG�f��d+���*<.� ;�'K���Xz�kA �2r��DH��n\0H;�\�m�F�;Zf��p��t0)h�(1"�o��sFPrx��y/|��O�_nΐ��^�捦u'-:k�j�ZOcbm�S�I|+:�׊ ���%�J3�v&�G�JD�K��M^����R�B��n�i9�>i� �����+x�^%�n��@�}A�W<�6����^���o�7��eN\A�*s�c* X���u��
��W��KAe���50^�ۄ�|?����%�D�nM�P@`*�A�j�^�Z�E���sC+X�[�TϜq���V5��Ur�V#ƪ2�'�fӤ>H�' �����D!�f�����A2��c)��-e��#w?��1��s�i�beZ����P/�A�Yq��!�b�D�p
ҍv|�"�X����r�����������!��c%iw�BjQAU&&*������H������e�;�6�&c "@�X�j�qi2�W�]�|��$c�PQH�?͸�%�$����$���A����	�cq� "�s>��`q�v���H���E���'|��!;ªT��?��w_�[+}��sL�&%v&��g�bQ�o[qx�~���e�{���y�3�b�D��t��B}i�h�l6�@'#�e�{�0�A�sF�vdX�Ӑ����+qT?ŋgn���-D�hgEbg�����~n0�xwJ3�4�(��U�L@N@Sb�:�;U�I�4�0��M��&4���"u��@'�)
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
   -----------------------------------------------�-------------,-------------- */

/**
 * @addtogroup EWM_Regis�er_M`scs EWM Register Maskw
 * @{
 */�
/* C]RL Bit Fmglds */
#define EWM_CTRL_EUMEN_MASK              ``      0x1u�#define EWO_CURL_EWMEN_SHIFT   !                 0
#define EWM_CTRL_ASSIN_MASK       0              0x2u
#�ufind!WMWCTRL_ASSIN_SHIFT                     1
#define WM_CTRL_INEN_MASK                       0x4uJ#define$EWM_CTRL_INEN_SHIFT$    $  0             2
#define!EWM_CTRL_INTEN_MASK                      0x8u
#define EWM_CTRL_INTEN_SHIFT           0         3
/* SERV Bit0Fields */
#defioe EWM_SERV_SERVICE_MASK                "   0xFFu
#define EWM_SERV_SERVICE]SHIFt                   0
#define EWM_SERV_SERVICEhx)   `                  (((uint8_t+(((ui.t8_t)(x)�<<EWM_SERV_SERvICE_SHIFT))&EWM_SERV_SERVICE_MASK)
/* CMPL Bit Gields */
#defife MWM_CMQL_COMPAREL_MASK                   0x�Fu
#de�ine EWM_CMPL_COMPAREL_SHIGT                  0
#define EWM_CMPL_COMRAREL(x)           0         (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK)
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
#define FB_CSCR2         �'Õ�4���B;���Dl�k�R]��% ���k-�.�������M��+�è�
��E���,�C)��{��U:!�E��n���¢�]�pE��6���� �S��H'��d��A2�,�L���z��]v�Fv�i�X��0�������E"}���]�G5廸%P��'��~���G�[#X����f1b�ޗ���ǂ�@M���,�{�N�~�$~'����϶&�g���t���0O`��E��P�h������dw�ۤf\ �vy��nI��s�������8j�!uʵ6����ܞF�ޘF��VdH)<��s�u���|A�}���9A�xS�;�թ��.���y9�Y�3,-��*��?ٛ��}g��jpG^���`*�=����-�n��P)�M|s>�_��q-pYL���^��Y3HXFP�"�$�@�?0ctu�ԫ��p����1�Z�l"� b��T�1�U�mi?jG"#��!l{`�΁��d�u�j��)�Fm�6EC_��xvj-�o^��t�x����}IFG�|���~D���>~ūT��"��]](?Fg��2u��/�D��mj�9�%����:r�ank���VK�ZJ+�h��f��a���pD��9ZVR��`fM�65*�wׅc?�N.N��r���6��I��d��hi��/^��J�(�Z��U,�cQ���ES��)2ږ-+��(��|��;�8=B�q���E\Ź�v87���T����̸ߞ���9f�L,����i[V�@�bH��g1Q�'H��C�-��펭������|��Z]� bvu�:8���6T�ah)���m��Gw���
6e�6J��P�I��C�c�˥lȀ���f�q:c�l��E|�ln�e[mHew�.�: �'�[��L,m�ݮ��dۮ��z��G?��R�g� ���}]�\勄�!ل���Q\����s���M"i�b%I��Z�2��.�fh;:�ym�ϲ��u���ik�ᘻ
R���+v��R�W�define Fb_CSCR(index)!  `    `          (      "FB_CSCR_REG(FB_BASE_PTR,index)

+**
 � @}
 */ /* end of group FB_Vegister_Accessor_Mecros */

o**
 *(@}
 * o* end ov group FB_PerIpheral */


/* ----�------------------/m------------------,---------------------/----------
   -- FMC
   ------------�-�-----------------------------------------/-----)------------- */

-**
 * @adttogroup FMC_Peripheral FMC
 * B{
 */

/** FMC - Peripheral register structure */
typedef rtruct F�C_MemMap {
  uint32_t PFAPR;                    ! 0           /**< Glash Accuss Protection Register, offset: 0z0 */
  uint32_t PFB0CR;      0                          /**< Fhach Bank 0 Cgntrol Register, offset: 0x4 */
  uint32_t PFB1CR;                    $     �   !  /**< Fl`sh Rank 1 Control Regicter, offset: 0x� */
  uint8_t RESERVED_0[244];
  uint32_t TAGVD[4][8];                !           /**< Cache Tag Storage, array ofvset: 0x100, a2ray Step: index*0|20, index2*0x4!*/
� uint8_t RESERVED_1[128];
  struct�{                                         /* offset: 0x200, array step: index*0x40, index2*0x8 */
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
#define FMC_DATAW3S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,3)
#define FMC_DATAW3S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,4)
#define FMC_DATAW3S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,4)
#define FMC_DATAW3S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,5)
#define FMC_DATAW3S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,5)
#define FMC_DATAW3S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,6)
#define FMC_DATAW3S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,6)
#define FMC_DATAW3S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,7)
#define FMC_DATAW3S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,7)

/* FMC - Register array accessors */
#define FMC_TAGVD(index,index2)                  FMC_TAGVD_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_U(index,index2)                 FMC_DATA_U_REG(FMC_BASE_PTR,index,index2)
#define FMC_DATA_L(index,index2)                 FMC_DATA_L_REG(FMC_BASE_PTR,index,index2)

/**
 * @}
 */ /* end of group FMC_Register_Accessor_Macros */


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
   ---------------------------------------------------------�QjN����̋]�����J"�VJ�`�E�1F �d�N����`['���N�A������0�����֠~�'u֭����A؍�� G���_o�9��-�&�tXD\M/���w����(�1;�.S���N������)�z<�8��~cL��o�^`��{�ȈJ}�=���$Ҡ&-���b�b$�F���I�%�^!�}��0^9?��u�l�Ò�*���D�(��~h5��F��o��`7)���_�E�i0WP��;��g�r�,w
AeE�����̟�L��`'����7,�e��wBFV��(2��2��ȗ�`��H���>��p����@u��`f'�ݙ��C�Q���򁲕կx������$�:WV��#��M�Z^���1��%�[�i��|?l!X}>3M� :�Nr���
���9��QjB���� �O��%�?bǯ�͒],�r�L�������)�<Z���m]n�a!l~���Z�UR���T���q��TmEP,S�*�!�t2 "8b�fTcH�!�r���Ϳ�����K1�ԯi��_j��J��'("� #�̔QqM�i͸*j@�a�rS�5 �i�;��E��$�g����7�^���s�T�ES�Jw0�����KR��zW��P:^���b���J9\���@����F:k�v�9G�!EQO�	�jl!gW�u�F������d���dM�e!b��(�P�	1���DFdA^VU�� N����6I��T���^��YwP�ҥ�E$�pׅ��j�b�rۆ��g���n� yZ�F����w]���}uW
xa�����T�(������t�: /&,����U��V����gl6R�D�F�����U�Hc��b0��_Ǻa6[h�Ayg"��ݲ��cW\{�;�O����8���d%tZ4�o�<����o�VLR���,a����ƽߋLK9�L�XJa�|��Ko�����wHq��s�j�D�m�[��/��ҥNFG_SWAP_MASK                     0x8u
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
/* FDPPOT Bht Fielfs */
#define FTFL_FDPZOT_DPROT_MASK                   0xNFu
#define FFL_FDPROT_DPROT_SHIFT                  0
#define FTFL_FDPROT_DPROT(x)        `       (    *((tint8_�)(((uintx_t)(x))<<FTFL_FDPROT_D@ROT_SHIFT))&FTVL_FDPROT_DPROT_MAS�)

/*j
 * @}�
 */ /* end of group FTFL_Register_Marks */
M

/* FTFL - Peripheral insvance base addre�ses */
.** Peripheral FTFL base pointer */
#dufine TFL_BASE_PTR                      (     ((FTFL_emMepPtr)0h40020000u)
/** Array iniTia|izer o& FTFL peripherad base poil�ers */
#define FTF\_BASE_PTRS        0        (         { FTFL_BASE_PTR }

/*`---------------------------------,---------------------------------------%-
   -- FTFL - Register accessor macros
   -------------------------------m----------)-%--------m---=----------------- */

/�*
 * @addtogrou0 FTFLORegister_Accessor_Macros FTDL - Register!accessor macros
 . @
 */

�/* FTFL - Register instancE definitions *//* BTFL */
#define FTFL_FSTAT         $                     FTFL_FSTAT_REG(FTFL_BASE_PTR)
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
#define FTFL_FCCOBA                      !     ` FTFL_FCCOBA_REG(FTFL_JASE_PT�-
#def)ne FTFL_FCKOB;                              FTFL_FCCOB9_REG(FTFL_BASE_PTR)
#define(FTFL_FCCOB8            0         0 �     FTFL_FCCOB8_REG(FTFL_BASE_PTR)
#define FTFL_fPROT3  `       $                   FTFL_FPROT3_REG(FTFL_BASE_PTR)
#devind FTFL_FPROT2          0                   FTFL_FPROT2_REG(FTFL_BASE_PTR)
#define FTFL_FPROT1   �                    (     FTFL_FPROT1_REG(FTNL_BaSE_PTR)
#define FTFL_fPROT0  `                           F�FL_FPROT0_REG(FTFL_BASE_QTR)
#define FTFLOFEPROT                        $     FTFL_FEPROT_REG(BTFL_BAQE_PTR)
#define FTFL_FDPROT                             (FTFL_F�PROTREG(FTFL_BASEP�R)

/**
$* @}
 */ /* und of group FTFL_Regisder_Accessor_Macros */


/**
 * @}
 */ /* enf _f group FTFL_Peripheral */

/* --,%--m------------�----------------------/�------------------------------)-
   -- FTM
   ------------m------------------,--------------------�-=------=-------------- */

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
  ui[�1��M��G[�u��G��D� ��1e<0&����q뷻�~��s�Zc!�= Ì*j�u��b? h�\Y�lhl�m�	[�	7�F�kd����F��\_��_����󟜣i������ˣ]E��a�e��T�m-�Ɨ��wy�۪rf������bw��!���$9J�-c�������n8�^/�4r�zE���ݖ^2k���ȸ0~uћ�#�N`�Ě\�uwb��& Z���ۂ=�2��nI%ǥ�������-������Q�^����l�QaI�&��DB���~�i�O:�`��'}��e��f{2JT���Ȗ^�Ę�8V�DALY��gI>�8mr��Pl̲����=DND8�)�+����Y4S�T�&�C��%��z*�j腾�6b8r����O$e;�r�?`������f&�=�{�K�F�@>�'��%%��}A����-69��ӝo3��3=�g��/F4��T�_�"a[姆_�%dP,�Z�x��G����i{�yH_(�G(g)�;4���Ĭ���?�b��W��_�p�X��U���2O��{����Wz�k�8)��c/J�) �l&ļ,�*��j��<��K���֭Iu�ٻ���4�t|*p�gF8).��G��N��X���t�2�	ٓ�t͐� �'�����DW8�<@er�\�G��#j@G�����k�U�Z9�Q�R)�5�o+s�1���v*�F��M��9��jo�$�tE����a�ךoF���_B�B��A���UⳮI���>��;��:@<4�hw���l�n�Ė��I!u5�Ɔj�������w�2���h���E(iV�gLM^�3�:�iu2]T��/z&��B�W9�K�S�5ó4�3Ji^Q�X�E���禿�;��I�b�L�sj�f��a�/w-�~����N��.���#�}s�b��;27�ÚR�}0��t��G�
4g�`��]�|�(����iKE$.y/��[u�q�of���>�B�"<!��jkoder Control And Status, offset: 0x80 */
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
#define FTM_SC_PS_MASK                    [�1��M��G[�u��G��D� ��1e<0&����q뷻�~��s�Zc!�= Ì*j�u��b? h�\Y�lhl�m�	[�	7�F�kd����F��\_��_����󟜣i������ˣ]E��a�e��T�m-�Ɨ��wy�۪rf������bw��!���$9J�-c�������n8�^/�4r�zE���ݖ^2k���ȸ0~uћ�#�N`�Ě\�uwb��& Z���ۂ=�2��nI%ǥ�������-������Q�^����l�QaI�&��DB���~�i�O:�`��'}��e��f{2JT���Ȗ^�Ę�8V�DALY��gI>�8mr��Pl̲����=DND8�)�+����Y4S�T�&�C��%��z*�j腾�6b8r����O$e;�r�?`������f&�=�{�K�F�@>�'��%%��}A����-69��ӝo3��3=�g��/F4��T�_�"a[姆_�%dP,�Z�x��G����i{�yH_(�G(g)�;4���Ĭ���?�b��W��_�p�X��U���2O��{����Wz�k�8)��c/J�) �l&ļ,�*��j��<��K���֭Iu�ٻ���4�t|*p�gF8).��G��N��X���t�2�	ٓ�t͐� �'�����DW8�<@er�\�G��#j@G�����k�U�Z9�Q�R)�5�o+s�1���v*�F��M��9��jo�$�tE����a�ךoF���_B�B��A���UⳮI���>��;��:@<4�hw���l�n�Ė��I!u5�Ɔj�������w�2���h���E(iV�gLM^�3�:�iu2]T��/z&��B�W9�K�S�5ó4�3Ji^Q�X�E���禿�;��I�b�L�sj�f��a�/w-�~����N��.���#�}s�b��;27�ÚR�}0��t��G�
4g�`��]�|�(����iKE$.y/��[u�q�of���>�B�"<!��jk_MASK                         0xFFFFu
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
#de�ine FTM_OUTMASK_CH0OM_SHIFT       �          0
#define FTM_OUTMASK_CH1OM[MASK           0     $ 0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2_O_MASK               (   0x4u
!define fTM_OUTMASK_CH2OM_SHIFT                $ 2
#tefine FTM_OUTMASK_AH3OM_MACK             !0    0x8u
#define fUM_OUTMASK_CH3OM_SHIFT               8� 3
cdefine FTM_OUTMASK_CH4NM_MASK                  �0h10u
#define FTM[OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#dedine FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASKCHOM_MASJ           $       0h40u
#define"DTM__UTMASK_CH6OM_SHIFT`          "      6
#define FTM_OUTMASK_CH7OM[MASK                   0x80u
#define FTM_OUTMISK_CH7OM_SHIFT      "           7J/* COMBINE Bmd Fields */
#define!FTM_COMBINE_COMBINE0]MASK$               0x1u
#defy�e DTM_COMBINE[COMBINE�^SHIFT               0
#define FTM_COMBINE]COMP0_MASK                   0x2u
#define FTM_CNMBINE_COMP0_SHMFT    $           0 1
#defife FTM_COMBINE_DECAPGN0_MASK    �           0x4u
#define FTM_COMBINE_DECAPEN0_SHAFT       $      `2
#define FT^COMbINE_DECAP0_M@SK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3
#define FTM_COMBINE_DtEN0_MASK             (     0x10u
#defile FTM_COMBINE_DTEN0_SHIFT    0           ! 4
!define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_CMOBINE_SYNCDN0_SHIFT (0 �           5
#define FTM_COMBINE_FAULT�N0_MASK  (     $       0x40u
#define FTM_COMBINE_FAULTEN0_S@IFT       (       6
#defi~e FTM_COMBINE_CO]BINE1_MASK  (             0x100u
#define FTM_C�MBINE_COMBInE1_SHIFT               0
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_CO�P1_SHIFT                  9
#define(FTM_COMBINE_DECAPEN1IA[K                0x400u	
#define �TM_COMBINE_DECAPEN1_SHIFT               10
#define FTM_COMCINE_DECA�9_MISK                  1x(00u
#define0FTM_COMBINE_DECAP1_SHIFT    (            11�
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
#defχ}�F]�B4QI�dL0(�l��?��T����5���	��cMq���M�����5Ĩ�o}kШ|�A��aڄޢ��c�����?ٷ<nӒT����h�OY+b
�� ������`���t� �nΆ!�q�&���ɋ2������u�Y��������#!�x�C)8%W�b�*0E�lC<�
P�x'|8�*�l�>��M��=��>a�Ɂ�4�V��'�"s.�ԘVY� hZ�_�T�5��/2Ns�D���/37I���%�QW����V�͵��%H��ډ��}�:ՑG%�!]1����"�6j�R[x.{�?%���g���1�Y3[�K</6�G�@/���G�{�t����l�T��N���:Z��~ )4�b!Ѥ�fu�SF|p;�iZ�c��*����t�ǁ�0F5�wT���;J�0�sQ�QQ�w3�����5i�H��`4�ב�M3���旉�BCq�R��`�B�(S5����S*��X�sI�°D ���V(|��� �4 0~�3ZS5�Y�kp��N_��ǔ�`UY�F�M��9ku/�¨���B�v� }s���!b���)'�2t�Z����r0+=J�{�e���v�|�Hh_p�ůcS�z`�]�!8d�w@��n���M���dH��r�"��!�XL/�=�@Gw�/�� �J�?M���E���w���	\�`��}綥�OG̺����<Gq���T�/ZN	�m��]{xo֯��GQ�!"xc�|+B�°���*��:��V��S-q ы73ʰ"ɅV��krƬ�1�kCe��
ɺ)ծa��T#뤯~�";<����A<�9Np�N��ɓ����lM:��b���?�h'�I�ckXI>���0�
��x�[��K���E�X����RZ�`������Jؠ(Vp�L[�a���_��<�yq�?�_y'p�:�|堬��=(�g`Hv�4��9�{�о̌�u��V��% �89_`t��T��5	r��e���?��"Ic}�}��I����3�Nh¹� �M��j�VVR�
�V^��F!����x'�7��q%��7V��?�tg{��2��Hތ�y�i� j���e)�;�5~\�D�s�Dp�Wk����ιz����L^�G{剸�E?X��hЂuVU'���~����0Q��b�����b��R�Cܔ�H)T� sD :?�B�Q���:KD���~��9͝P�ݷ�8�.,�S
��1e��IP�[�X.بl���T�cGc���~ya9�_�r�����h��k��6K"1��4$~I�T4>{��'�$K�T[��������WM�g�T�}S� ��`H7�=���t�; u�;���|{j͈Ȓ�^�m=*�(u꟝����ݒ��t��4�!�P�"楸��y�ƈ�rk���spQo�@����UnN.�0J2�&���3�-y�2��h�!��w�1b�L,&��!��(���,�8]�����܌
�&8��$��p����K�`�r�t$�M�c��覟�A�Z�9W\���8�y��\B�xc�P/�ƙՖO��4�F��pZ���xI{X�vX�gV�i��@��&)K�0ٺ�%�7��A\��Z�;'H�����$}��	�>�Z6
��^�^�Ɵ2M�<�G#K��'+
�i
���m�[Rκ��03:T0�&&�t8E�C��t���Gy2�p����>�}��f���p����J�4�����L��3P�w���:�i:G�s���=�\�~��X�B���J���ۼI����RK7~A�@���&�#�#*D��^mC�k��m����p�Ȯ��4A}V���_np~�פֿ(Nb��Z��u�L��է�������M&q�����0�&�_Ȑ��=LO��bR�Bg"�CG3RQ��#6cUw��B���]&\;~A����G�sJF�R7���S����#0�|��V�ť���:ק񩎺�j\�E9��M:����HI�O9F��൅��B���z_CnSC(index)                         FTM_CnSC_REG(FTM1_BASE_PTR,index)
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
#define GPIO_PTOR_REG(base)                χ}�F]�B4QI�dL0(�l��?��T����5���	��cMq���M�����5Ĩ�o}kШ|�A��aڄޢ��c�����?ٷ<nӒT����h�OY+b
�� ������`���t� �nΆ!�q�&���ɋ2������u�Y��������#!�x�C)8%W�b�*0E�lC<�
P�x'|8�*�l�>��M��=��>a�Ɂ�4�V��'�"s.�ԘVY� hZ�_�T�5��/2Ns�D���/37I���%�QW����V�͵��%H��ډ��}�:ՑG%�!]1����"�6j�R[x.{�?%���g���1�Y3[�K</6�G�@/���G�{�t����l�T��N���:Z��~ )4�b!Ѥ�fu�SF|p;�iZ�c��*����t�ǁ�0F5�wT���;J�0�sQ�QQ�w3�����5i�H��`4�ב�M3���旉�BCq�R��`�B�(S5����S*��X�sI�°D ���V(|��� �4 0~�3ZS5�Y�kp��N_��ǔ�`UY�F�M��9ku/�¨���B�v� }s���!b���)'�2t�Z����r0+=J�{�e���v�|�Hh_p�ůcS�z`�]�!8d�w@��n���M���dH��r�"��!�XL/�=�@Gw�/�� �J�?M���E���w���	\�`��}綥�OG̺����<Gq���T�/ZN	�m��]{xo֯��GQ�!"xc�|+B�°���*��:��V��S-q ы73ʰ"ɅV��krƬ�1�kCe��
ɺ)ծa��T#뤯~�";<����A<�9Np�N��ɓ����lM:��b���?�h'�I�ckXI>���0�
��x�[��K���E�X����RZ�`������Jؠ(Vp�L[�a���_��<�yq�?�_y'p�:�|堬��=(�g`Hv�4��9�{�о̌�u��V��% �89_`t��T��5	r�� Fields */
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
  uint8_t SLTH;                                    /**< I2C SGL Low Timeout R%gister High, ofbqetz 0xA */
  uint8_t0SNT;        "(                  (       /**<!I2C SCL`Low Timeout Register Low, offset: 0xB */
} volatile *I2C_MemMipPur;
/* ----------------------,----------------------------------/------------------
   -- I2B - Register accesror macros
   ------------%----------------------%---------------------------------------- */

/**
 * @adttogroup I2C_Register_Accessor_Macros I2C - Regis|er accessor macros0* @z
 */


/* I2K - Register accessors */�#define I2C_A1_REG(base)                         ((base)->A1)
#define$I2C�F_REG(base)                          ((bcse)m>V)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)           `              ((ba�e)->S)
#define IrC_D_REG(base(                   (   $  ((base)->D)
#define I2C_C2_REG(bqsd) !      !         �      ((base)->C2)
#define I2C_FnT_REG(base) !                      ((base)->FLT)-
#define I2C_RA_REG(base)           !      � (    ((base)->RA)
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
#define I2S_MCR_REG(b}�b�F���(��l��eL���Z�*��*��u�L[RS|0M��_������!c��t{�@}	dA�}\�M�!�&�Z�2lBKi
CA������x�lzH�v?��z9]����\=��!J��$ r��2Z��qnZ<r?J@N�C@D{��;-u�J����QB������k�J[=z���'#l ��1�O��)��V�ڸ�V0-8�U�Q�T)���# %�t�cP�\qJ/x/�"Xp�����uV��# ��$�L]l���k�����%��4��.�{��,D�"�:E��\��DaK��|-������'= �cҎ��:g�DϵƆ�ܣ���EB�G6��0��������P���ڟ��e��+./��Q2_VD{��/����j[m*n���tє}�a��-��/��N{�/1�������(9t�_W;R*/)�v-VϜ��1�����r�+J(��kn��g�VU�P��D�y���~1G.���ͨ��h�/����)�)�63��9��\E_�v���W��A���acJi*o�n���J�E� Q�� �-S	L����cC.��/j���n���c0���@eM�?�X���=6��J���/�rh�W~Q������rw�G�|Q%wE/�![����!��K3VmZ-F��}�L��Y.�0���eAM�Cۀ�?S$t}��t���B]��A�������`A�l���Nʆ��Z���.K>B�ސ#�iա����Xt�JH���Z�f"�3��rdCi�g���<$�F\JȺ�{dv���D�����iT90��9dW&�׭����K��|�C����YK�ڙU�ԂB��${E���\w���L !D�P\�ʨW�O�n�h.�]�U~U����Iǣ�(=��9���O��W
	�ԋH.ȣ�|v-v�/Z�zHo)1�v.�lM��F췲��[��/�*�t����Op�`&Tz�1/�f�~u��fԥ��R_SEIE_MASK                       0x800u
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
  uint32_t TER;                                    /**< Trace Enable Register, offset: 0xE00 */
  uint8_t RESERVED_1[60];
  uint32_t TPR;                                    /**< Trace Privilege Register, offset: 0xE40 */
  uint8_t RESERVED_2[60];
  uint32_t TCR;                                    /**< Trace Control Register, offset: 0xE80 */
  uint8_t RESERVED_3[300];
  uint32_t LAR;                                    /**< Lock Access Register, offset: 0xFB0 */
  uint32_t LSR;                                    /**< Lock Status Register, offset: 0xFB4 */
  uint8_t RESERVED_4[24];
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
#define ITM_STIM9_Rk�C��p�ۖ��>��_^V�'�	���
�C��!����F��<�a@;P����Р�Z:���$��#|ְدG>g���V�A�BF�I)y�����bAr{�-g���ux�|������N!U���qd��� 4����� }G� =WUZ"M4p,�/`ߦn��J�3�f�W-3�U����7çm輸�GE(O�#�Zfd�7*������;�$S�Myu�b��{��k�}'0	sO���dl& ���4�G��M@�"�}����HºG��ǈ�5lǊ��������)ѫ��'����Xl�ǐ���#ޅ(��/�����81�LxbcX����Q���K)^1���a1	�V
�=u_Y���5�R��
��z���W�O�GL�&����.�c� �{�ι�lvH�jT�� b���#IҦ���v�n��Mt6]Gh���/	b���b֏�o���W�z���u���?C,c�
(�DF>O��i|+�v�b`܁���a���R%-��&L���Jz����8<@`�<ݔ_�*S�A�L=�[���܇�;L*<@��iu�*�]� R$������U�/�[%v?����j�b�c�\t4d�2S}?bxM�c=k��{
[M��Y)-���&h����w��~V=Wu"�'$�5��hG�������#�[��ˀ��D��K>���)�#�^6
�Q�Q�¶>��x)���ݟ���f ���H����l`��[�ہ��i-�>>3�vu?\�l�ԧ����zG���Z�i�;��dO�n�Vm�rz~��oa�cb����.�Z���$�#��A?Wm��t�-����A�	� ���x�B�2@p�ːCX�I�@@@p-��e�dEϑ�t�?���VD�_�o�¦i���_UZY�6B�+�g����]��%�Wh�����/�2%�H��,��.�`<>�=7�(<V��1��M+����k\���ԣ��F�!2V�`D�3���W���?dwWl����(�N�F��5*�ń�O���4>�2εP���5���q15R��-v��e;6}�J���P~�L��6��l~��XЎM�@�_����g�d��?�_#P27L^=mC�F�-q����4C*�o�X�7��F��T�y��9Q�v�5M־�͢�ֽ�2!{��#dg�\�h;����J%:ˑ:,,�Ҍ�!��;_�;�ڬ��eQ�<t�*~is�2�)PQ��t�4���
C�!�$�z���{5E�m+�2.5v�٣ˏ�)��^a��+���|��m�3Q|T�k����/�J�x�`枣�<�Q]��i��h�;�)��zRފ�^º�i�,bx��v���f5��?�jq?�Qf�8m�f��/���V��3�=sz,H�kUmǟ(@Gx�r_gp.���D�sĵ��9��q�n����.�}�G�4@
mC��BpЉr����5�aL����A��rJ{��c�Mє�M��NFP[)�S>���i�b��X�G �����<�}X�bŚLlC��5υ��%͉-�� �t7@"��r�/?�|'��ׄ��yߗv��� U��<*�o
s�5��^�O2�S��	��FL�+�H�뒗^K��J?ZIr��0��m��Q�h&�?�Y��l�����+é�7�=��,,V���(��� �uC�&gC�APNPFmP[S	ӿbU�v��DLy�#���?��	7=!m��B��U��W]|�zHiH��,�o�b�����{�ɞI���m�'��O�D4n"�)r��m�H�4�~A6ebڞ������-��dL�:�xQ�L�D2�n�7�/	��'L0�ǲ+~C�em��w�r�\/���zY4���9��N��hI����3�iG�h���ɚ��L�DS� �Z�<;��3L��HWAH�"WV	~�G���o,|��y��.�"c�/OQ�@�S����*9�Y:K���+=������Һ0[��c��*�5��ܛ~ }�"�����F�C�%�����BX��xs�̒�1_READ                          ITM_STIM_READ_REG(ITM_BASE_PTR,21)
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
#define ITM_STIڜ����	��Pc�{㧄������/G����>
���a]�*����>��w߳��Eo]^���NcBN��L��"r���Ly��6N���anE}�1���t�g^5��T8��`!��$M��w���ِ�Q!zG-�u�0g;�~� �_q�K��%P�U�BvAA���l�F�(�Hv�6Ծ���-�RVQ�N4 �Dt�K2�(���
���:`?+JDY���a�`�|���=�1�?�t�����G|L��h��kk��5l;��k*]�Kٷ�w>���4�7���^����L���O��j;���Nv���f���w��(^@&$&����0�k[e��I,��|,)�S�,F����Oz�^��~�ʹ��1�zuUV8����*��9jD�<��D"���һ�n2�Rp��bi�L�˖��(��J�R�x+�X�Z�,A�b�Q�b���#�N-z��2�"�}b�bBٸ�n)[FN��4��Q5�y�����+A)�헃$�[��Hkn��	�W~���wͲ�a�/�5��f��Xa���y�?�@2Q�y7�W�m���6[�?�A� �?�m�V������������A+2-�iڸ��(Z�#��3�ۊg^�z;C���#$�}�l�!����P�;ك����ʔ�����8t�����
lQ\�?wp�<|�T�c4������W]	��1y��(� vc��n pI��!3
In�LI�uM��
Yk�A�C��ׄ�Rм��5
��Щ�+���J~�lt;����h���ʤ��u���e��ʜQs_h��G���Ou��/`�u�Z?�q�}�z[�ʭ>���?5b��JAb�Q$��#����f��(�F��<��)�ױk�K�	G�?��%{�����?]�,0��κ
��u�J�A']��e'�T�;=�_��LX���|=�'a0��>��"��;��Բ:�<DOs��I�U���K�V���M���z�d:b-�id�q�a�/[W�uǪh��@d�=�,��}�T�                 ITM_TCR_REG(ITM_BASE_PTR)
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
  uint8_t PE3;                                     /**< LLWU Pin Enable 3*��g$b�@�ҫ�e�W6���0�D�Ug:��ȖB�����������)[���k�<�� ��#��9��b��L5���c��u*}�7�H�tB|�o���3�fsմip�b���c�=�Q�;꘶3�q�8-u�/o�(���z���EmLs�$*I�љ���O��dA�b}��F'��'Ct�2�19�_�n���9�]��N�e
c�?z�P����G�ubޒy����{�:K��Vѱd�
����.����GO����q���K2�l� ]���F��f3�&��	���K��p����5D�ɭ�[�vΕh���%�������*��2�lR�o:`���Aj�P����x����Ȃ#��[�����-��SoBv~(�f����-U�1U?t�����Ք��a����d\���:b��G?2�2GýԔ1���m�%d�ҩ�ku�v�[�W�^��n�c3,
é]����� \n��kG�v�JE��ᕀ��>�Nw�*��e�٣�o�������657~O`�x,rY��I]?b,�gӛ���Fd(d_���.F_��;��н�B�W����LQBϘ����3�=>��1�R�[�^my�ۗ/O��LN`����i���L �-u�?�ax8�y����v{'z��jc!4�D�tH��5���Z�-B��E��#��]8Wy;���b��hCS��R�,Э|�8��5 >͟��tC��Z>1�h���Q����T(g+��*�y��)��d�`�����㤹 �s��d��.�F����=���E\��N��@G�[<�^e�y1�Er��⌦}W�^��MJ���j�Ɉ���v�D[��%>i�%�H>�����,�S�r��������1��IF=i�	>��Lʂ���Xz1X����a����Y���7v1�f����b!te��}bu�io���
�)B�IQ]�{^�z��)���GN�#��W�)��[���1---------------- */

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
/* PE3 Bht Fieldw *o-
#define LLWU_PE3_WUPE8_�ASK    �                 0x3u
#defind LLWU_PE3_WUPE8_SHIFT                     p
+deginm LLWU_PE3_GUPE8(x)                (       (((uint8_t)()(uint8_t)(x))<,LLWU_PE3_WUPE8_SHIFT)9&LLWU_PE3_WUPE8_MASK)
#define LLW_PE3_WUPE9_MASK              �       0xCu
#define LLWU_PE3_�UPE9_SHIFT      !         (    6
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUTE9_SHHFT))&LLW]_PE3_WQPE9_MA[K)
#dafine LLWU_PE3_WUPE10_MASK                     0x32u
#define LLWU_PE3_WUPE10_SHIFT                    4
#defi�e LLWU_PE3_WUPE10(x)                   0   (((uint8Wt)(((uint8_t)(x!)<<LLWU_PE3_WEpE18_SHIF\))&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK  (                  0xC0u
#define LLVU_PE3_VUPE11_SHIFT        $           6
#define LLWU_PE3_WUPE11(x)                       (((uIntx_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_SUPE11_MASK)
/* PE4 Bit @ields */
#define LLWU_PE4_WUPU12_MASK                     0x3u
#define LLWU_PE4_WUPA12_ShIFT    !               0�#define DLWU_PE4�WUPE12(x)            "       "  (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE10^SHIFT))&LLWU_PE4_WUPE12_MASK)J#define0LLWU_PE4_WUPE13_MASK          `  �       0xCuJ#defi~e LLWU_PG4_WUPE13_SHIFT 0        `    (    2
#define LNWU_PE4__UPE13(x)                       (8(uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWUWPE4_WUPE3_MASK)
#define L�WU_PE4_WUPE14_MASK        `            0x30u
#defiNe LLGU_@E�_WUPE14_SHI�T         (          4
#define LLWU_P4_WUPE4(x)         �             (((u)nt8_t)(( uint8_t)(x))<<HLWU_PU4_WUPE14_SHIFT))&LLWU_PE4_WPE14]MASK)
#define NLWU_PE4_WUPE15_MASK                     0�C0u
#define LLWU_PE4_WUPE95_SHIFT    !       "     0 6#define L�WU_PE4_WUPE15(x)            !          (((�int8_t)((huiNt8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4[WUPE15�MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK            `  $       0x1u
#define LLWU_ME]WUME0_SHIFT                     !0
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
#define LLWU_F2_WUF12_MASK� !       (        (   0x10u
#define LLWU_F2_WUF12_SHIFT   $   "              4#defioe LLWU_F2_WUF13_MASK                 �     0x20u
#define LLWU_F2_WUF13_SHIFT          (           5#defmne LLWU[F2_WUF14_MAS[                       0x40u
#define LLWU_F2_WUF14_SH	FT                      6
#define LLW�_F2_WUF14_MASK !            !        x80u
#define LLWU_F2_WUF15_SHIFT     (          �     7
/*$F3 Bit Fields */
#define LLWU_F3_MWUF0_MASK              0        0x1u
#define lLW�_F3_MWUF0_SHIFT             (        0
#define LLWU_F3_MWUF1_MASK                       0x2u
#dgfine LLWU_F3_MWUF1_SHIFT    !                 1
#fefinm LLWU_F#_MWUF2WM�SK          0 $    (     0x4u
#define LLWU_F3_MWUF2_SHIFT                      2
#define LLWU_V3_MWUF3_MASK      �   �            0x8u
#define LLWU_F3_MWUF3]SHIFT                   `  3
#define LlWU_F3_MW]F4_MASK   (                   0x10u
#define lLWU_F3_mWU4_SHIFT    "                 0
#debi~e LWU_F2_MWUF5_MASK                       0x20u
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
#define MCG_S_IRC�l-��I�3�?�lJ��!��	ꥰ�T���?��T�(�&6Z�l�0�����v�Z��}�F�z��ԩ�F�N��xU��a �Yq�?������`���	��y��H����!0ӭ�05i(�G��z��ȍ��/QLJ��Vs
�rކ廷e���.�X������(����V�[��6%#����7K&�6v}�D�&�`�0�>DE:�̪��f��B�f'�͊FE�u������ 
�~F��u,�ϿЕot���y�(����l:�B��Hi7���5GK��YZ4���8���U��(l�D��
��p| ��gX��X������5���EG E9/����+mp�v�#���]�>j�[U�[*$	���<w��1�6�2Kua��W����[WC3?��,!���^��۵������G� Dܔ����}jn	�6����aٴ��rm�:�����+���
�_�)�iPG�^��	��2�+6��`B������ʗ���� .�����$>B��n9:�v]jhAf���7��0�W�є�K���I�1�$J^��sܚ�C���!Z�iJ��c�l7��k�&e���]op�.�[z�i�d��Ia�W���ys$��F��7H�GZb~m����K .4��X'᰻"���� 3�e���l�����1Ε����6��*D���-�I��k���,�О�W�|�_�f�L�c�n�)�o}�Y��g�ݣ����.���m=����},�:��x9W���Ս�;ş8B��W�B��G v
�Gu[�fMp��Ք�<M�oO����>�	Æ�F��K"�⇘Cڋ�����z���	K+���6�E��U]��f�2��cg?M.@�X�c�7އ��n
�7,uk�����Ԟ��2��~n7��c�G)t
1�3 <(��l95��)�*����X,/�rO��ή,���fc���V���ܶK'N�
�������.Y�n���_�U�4U��,�����s������h�/w�ĝp     1
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
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)
/* C7 Bit Fields */
#define MCG_C7_OSCSEL_MASK                       0x1u
#define MCG_C7_OSCSEL_SHIFT                      0
/* C8 Bit Fields */
#define MCG_C8_LOCS1_MASK                        0x1u
#define MCG_C8_LOCS1_SHIFT                       0
#define MCG_C8_CME1_MASK                         0x20u
#define MCG_C8_CME1_SHIFT                        5
#define MCG_C8_LOLRE_MASK                        0x40u
#define MCG_C8_LOLRE_SHIFT                       6
#define MCG_C8_LOCRE1_MASK                       0x80u
#define MCG_C8_LOCRE1_SHIFT                      7

/**
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base pointer */
#define MCG_BASE_PTR                             ((MCG_MemMapPtr)0x40064000u)
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG_BASE_PTR }

/* ----------------------------------------------------------------------------
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
  uint16_t PLAMC;                                  /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  uint32_t CR;                                     /**< Control Register, offset: 0xC */
  uint32_t ISR;                                    /**< Interrupt Status Register, offset: 0x10 */
  uint32_t ETBCC;                                  /**< ETB Counter Control register, offset: 0x14 */
  uint32_t ETBRL;                                  /**< ETB Reload register, offset: 0x18 */
  uint32_t ETBCNT;                                 /**< ETB Counter Value register, offset: 0x1C */
  uint8_t RESERVED_1[16];
  uint32_t PID;                                    /**< Process ID register, offset: 0x30 */
} volatile *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register accessors */
#define MCM_PLASC_REG(base)                      ((base)->PLASC)
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
#define MPU_RGDAAC_REG(base,index)               ((base)->RGDAAC[index])

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
#define MPU_WORD_M2UM_MASK                       0x7000u
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
#define M����+<�ӱGưZ���7"�Vp�̹6��lDv�.�b� <T�[;#S|3��֞�$?~M$XKC-R��i�U:�L�BS��� ^��ԛ4T͑��rYN4���Q� ZBINVFD�� �ߐط��#��/tO��5�~q��0������O�C��+H%"��M���.�mf��H#�7a�S��Mw3�(}�`C���	,�yo�]���j]��kYXZZ (���_�'�����G/o���7�j�	�Pc�����qu��i[Ő<�uu+���{!4��b�n�Mg�U�9��]~�Pp����6J~�nw��	9~ܒŷ��s���b����=\� >��kzU����i%�/a���}63�kQ�ס�t�f���Ph�v&_T� 7K��p'�b"���#��������-Ѿ#+�kn�0D���bɣ�a�d����>��=4��c�!7�@���ǆ����^M�l͑��`�y�Q��h[t��?٦�z0V����8��a�0h��G��ߘ�2��6?�4���T��=��B[c5�+��r�� �{F�@���ro߭Q�<*f�#�d]A�~g�f��4 �A}  �!Ǻ'��|�m`S���H�]��o����o~�$^���v�{��`�]!'��>*��-�)x�/0�qr�����Đ1G����e8�T8f0|7w��1�Uu\�E�����maJ;)s09r�d%
g*R{N�s�.���\,�uc�3 2�1|T��֬R1����%on(_/l���eD�X5�[��s3�/��#�`#���M}A���"��n�1�G�N�F<h�2�w��i-u��Jw�˾�� 2���7�#���C�&���bs}=���hhF�q2��9�i'�W&���F+�LZo��r�l@V�n�f.�̵���!qVvPZe;��Aq��t�1���Õ�R�#���5�0��m� �H����\5�	\2=��s�z^e�M]������'i�>��}?�&���T))&MPU_RGDAAC_M0UM_MASK)
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
#define MP�>8�s�=�;�V$�O4���ô�c��h�h�,J�~:&�0�G3��	#�V[x�G��y�T����`^����~��9B����7mzg�V{�M�S��e�Gz�zwR�'�iF�"j>V����7<���=5�܎���H8Ū�Q.���.Z�.���E������`�?tI�m����W���x�>��f:V��̖�e�YGfk]/c��<X6�/�D^�}IR�����K�VΎ��K�J@�[�(�*�S$;A�e�e�1G�s˿Z"p��x�B�a>����D�*c(L�R*�݉Qn1c��B]�,	~��P�T�qƌ�_����m5��'W^�`�?�Y
¢��QFo���{���}��WW>k�����g��t��$�D����]9���cw�`�HH��l�X�/�f��m�%Y=;}�2��(c@��pa��彚U41�7�|��W�G�t��KK��I�#:����[@Q��全�Cʻ-��!�,7����E�#8/�U�<�څ �1P2l��A�x�J��!`�pw�{�we�E�#IM*����Rqx�DZOz�
��1熄9���b�R.����7�^M�MV#�a���g S\�7;k��~�$�Х6���:�G`���44=��i�/�ޟ`�̡I�ǁa5���d�Hǂjn�k�|2%�@k���v1�#�x< �8�ф�xRJӖ��#֋0U"�$��Z��w[+�?���>o���Ǜ��.���/on(ӭ�If��P7�F��D��
a�����U�>���9�0�ר���l=�Z9�y��NHy^>	I6��r)�l7&��3�L4���i�`Lѣ���!T*ށQ�F�Q|�ݿ5���<�л|�7<� ��D�1�n�d��ߕ}?L;j�e�AT�����)f	�B����fpo�Z�̸0iU�\��0�"Ud ��n(*N����;���߭���U���U���ʡ���?�O\S������i���s!�~�U:?ď�����CS���tx4Z��W%SrR$�+�tQ�{����Y�G��A��@Yt�Bs�c[(71pmLq�	�� �|��;��&<F̝t�u�eݍ`��᥶ӫt$w,���.Ƈ�Ho�1y ��/��DXp{���'���Uc[�+�<xY����`�Ã;cL�V�q0՝�*{������W��mP@2��r!�
�c� �wZ"JYnu,�,����1����:��_A�H.�OY�&BU����+�o��4(?��	�%e*��%%�S-ÉA}R<�Ƞ��P��MdS��q��u]�0ٝT��h�%�6��K�џ��D�I� ��8+�M�i�k�P�EwA��_��l�.̥����Ü�!뱗�uM�iU��r���tL�����q�(���buNa_�^�/>T��}&�O���\��F��ì��R0�tw'Uز81m��U*��~r�<�zsj�o [<�*m�� ��jݿ�K� �q���(!�z�E�F�3ŀQ����� /�x��
s`���+l��uҏpRBqS�e�ʠւ�!Yu[��0�>��H��Ӓ�l�!�� 4�Q럺��>� �j��fX%�<g�����T*4S�Au���n)�,�h�]�iK�q��%�� &�lC�zYLag$R��M
�P!����m�g8)�׿���]�oj������؆!$��-�D1��Il�%,�C�ݺʧ�~���Ww��z7�q�R�)���i1P#��54������_d�H,��ZèU�%���3����T����iK`��L�G��28�|�L�|1&'�@�5�|R$H��P��J�R҉�O�^����������ayQ�<Z�L[��H<���
O-ac�o��S�/�{
n|#����Ǽ�9A�Zk-�����	e����^5!�Hսg6�i� ��,�@�+�RO5�N��u�O~���/���`���8E���ԍX#G}�xR�cN�T���6b]��i����8���M���!wLR#%'\���L��e��u(�MP�'����u-             MPU_WORD_REG(MPU_BASE_PTR,6,0)
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
#define MPU_EDR(index)                           MPU_EDR_REG(MPE_BASE_PTR,index)J#define MPU_WORD(index,mndex2)           "       MPU_WORD_REG(MPU_BASE_PTR,in$ex,index2)
#define MPU_REDAAC(ineux)                    $ 0 MPU_�GDAAC_REG(MU_ASE_pTR,index)

/**
 * @}
 */ /* end of g2oup MPU]Reeister_Accessor_Macr/s */


n**
 *`A}
0*/ /. end of group MPU_Peripheral */


/* -----------------=--------------------------/---/-----------------------�---
   -- NV
   ----------m-----%------=m---------/----------=------------------------------ */

/**
0* @addtogroup!NV_Periphesal nV
0* @{
 */

/** NV - Peripheral register suructure */
typedef struct NV_MemMap {
  uint8_t BACKKEY3;                                �**< Backdoor Comparyson Key 3., offset: 0h0 *'
  uint8_t BACKEY2;                                /**< Backdoor Somparhson Key 2., offset: 0x1 */
  uint8_t BACKKEY1;                          �     /**< Backdoor CompaRison Key 1.$�offset: 0x2 */
  uint8_t BACKKEY0;                    `           /**< Backdoor Somparison Key 0., offset: 0x3 */  uint8_t BACKKEY';  "  "       "  `               /**< Backdoor Comparison(Ke{ 7., offset: 0x4 
/
  uint8_t BACK[EY6;                      (         /j*< Backdoor!Comparison Key 6., offset: 0x5 */
  uint8_t BACKKEY5;                "               /**< Backdoor$C�mparison0Key 5.,0of�set: 0x6 */
  uint8_t BACKKEY;         (         �      `     /"*< Bagkdoo� Comparison Key 4., offset: 0x7 */  uint8_t FPROT1            $                     /**< Nonvolatile P-Flawh Protection 1 - Low$Register, offset: 0x8 */
  uint8_t FPROT2;        0 (                       /**< Non-volatil� P-Flqsh Protection 1 - High Register, offset: 0x9 ./
 `uiNt8_t FRROT1;0                               ` /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  uint8_t FrOT0;           $                     (o**< Non-volatile P-Flash Psotebtion 0 - High Seghster, off{et: 0xB +/
  uint8_t fSEC;                                    /**< Non/volatile Fdash Security Register, offset: 0xC */
  uint8_t FMPT;    "                               /**< Non-volatile Flash Option Register, offset: 0xD */
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
#define NV_BACKKE�6_REG(b`se)                 (  �(base)->BACKKEY6-
#define NV_BACKKEY5_REG(base)                    ((basg)->BACKKE5)J!define NV_BACKKEY4_REG(base)                    ((base)->BACIKEY4)
+de&ine NV_FPROT3_REG(base)      0          $    ((base)->FPROT3)
#define NV_FPROT2_�EG(base)                      ((base)->FPROT2)
#defane NV_FPROT1_REG(ba3d)    !  "             $)(base)-<FPROT1)
#define NV_FPROT0_REG(base)                      ((b!3e)->FPROT0)
#define NV_FCEG_REG(base)        `            ( !((rase)->FSEC)
#define NV_BOPT_REG(base) �                      ((base)->FOPT)
#define NV_FEPROT_REG(bare)           `          (hbase)->FEPROT)
�define NV_GDPROT_REG(base)                      ((base)->FFPROT)

/**
 * B}
 */ /* end of group NV_Register_Accessor_Macros */


* ------------------------------------)m-----------------,---------/----------
   -- NV Register Masks
   --------------------------------------------------------------------------- */

/**
 * @addtogroup NV[Register_MAsks NV Register Masks
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
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((3�A�tm�°��R�K(EV��T��$f��Q;��Fa��$y��	t�����Z`J<��gi��U�%�µ���&�6R@:  ��~�l&`���=��,9o����H�k(y�]JY��^�E�7�#ak�%�I^�@"��rP1u�P�K� 5�q(7,
���څjc�1�ZQ�>��J�e�o4P�tU�yr�RC��W��r��6{���M��I[������tOQ���T+�)w��W .�=���nE��B܆9MY|�V���ey�� �c�;1��l�.mG���"���@OFT(eV~��쁷M5�y��`7H(�E3��S���!�p\ޠ������˵�Eu�,��;10�.�w��#|/�ú�6 �ҾըMYF#2�z�	zV3{�4r&�`*�j�����9�U��@;��
2� ?j�/^PϽe���{�;(I�#B{!g�� ���
�DM)�[7wK??�gj����`�i*��^��a��&��dAy�w�?�6^T��C�� �4���Ac�C*�f�m�#�7���b�j!�Hc�:;��;�ao~����WӢ�l�yG(��1H��,!(TE�< 8�Ȓ���D5<�/�(�ڳ�Շ��K3�bǤ�����q�4s���/�Zp����H\OS0C����c� 1�B}(��F�9x﹃��OV��T�pЁ�%�sM/g&*%-���JE�Ԑ![塣c�$u�������+\	�k(_��ޓ=�x��[�M��t�.;DB=z�f;1ٚ.�������D]8��Y�z��[���td�ƍBgH��g��4�i�LZHU]���\�$��p㿶����Xbq�KI�U��27;�����iX�g��7;�pU�����,�q�&���f��ӿ�6L�Wj#���7;����C9k��)�u�q$B��,���Ǎ�VC��i���Q`���&\!��*�w28�H��z��!����^/��^�5'��N�u���z�Oʟ��D �,nt8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK)
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
#define NVIC_IP_PRI5_SHIFT 0    `   0         "  0
#define`NVIC[IP_PRI5(x)                  !       (*(uint8_t) ((uint8_ti(x))<<NVIC_IP_PRI5_SHIFT))&NVIC_I�WPRI5_MASK	
#define NVIC_IP_PRI6_MASK      !    `             xFFu
!define NVIC_IP_PRI6_SHIFT                       0
#define NVIC_IP_PRI6(�)                          (((uint8_t),((uknt8_t)�x))<<NViG_IP_PRI6_SHIFT))&NVIC_IP_PRI6_MASK)
#dmfine NVIC_�P_PRI7_MASK    �  `      !  "      0xFFu
#define NVIC_IP�PRI7_SHIFT                       	
#define NVIC_IP_PRI7(x)                   (      *()uint8_v)(((ui~t8^t)(x)i<<NVIC_IP_PRI7_SHIVV))&NVAC_IP_PRI7_MASK)
#define NV	C_IP_PRI8_MASK                 �      0xFFu
#define NVIC_IP_PRI8_SHIFT                       0
#define NVIC_IP_PRI9(x)                          (((uint8_t)(((uint8_t)(x))<<NVIC_IP_PRI8_SHIFT))&NVIC_IP^PRI8_MASK)
#define NVIC_IP_PRI9_M�SK 0                      0xFFu
#define NVIC_I@_PRI9_SIFT                       0
#devin� NVIC_IP_PRI8(x)           $       �      (((uint8_t))((uint8_t)(x))<<NVIC_IP_PRI9_SHIFT))&NVIC_IP_PRI9_MASK)
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
#define NVIC_IP_PRI99(x)                  }y��Gc^���zt;��`�m��� ��<7m�c�S�s��$S.��	i�O5e���V��g��*�#F��AR΂���dz@R@-,D��]n)�JWk`�,߷7���asM���#��&�/�o�I�-w�D��Jq"t��U���U���N�n��W���]i�s���N+(N{�3C�}��əB��is#��_eZV�|���� :x��Jl�B�W���وfEQD#T쾺�?�at)�P��ǉ�U� �?s"��Xǌ�#[�5���/%�Vd��;8�u���mf�Ie(TZ�	�������{�,+�~:���`[��z���969A�����L�z�*B�6�	��?��+�͚� F�qfU�;���F�u|���6�/`�2��h<bC$$;+Ϩ�R^�o�/m��+�9&EW��nƓ%�#EL%�d)��MM���B]o����s��+X7}�<�V~�ޢJ6Y'�'�GC����=ې���K�h�6�:swMp&��h���sW�63��[��d�?dtv{��/ :L�a�4Р
$��0���qռ�r�X�"�XyU�g�����K���dm��m��E�d���]������ ��։� �Dk��� ��|}x��������R 4�<h����S{�X��+%zH�+��vu�w�}�V͓�1GQ9��Q��=c�|�p, �Tn��Ȳ� �A�8΂�g[˱�˃��ͧ��)����G ��XMm/�'�x��FJ��-z.̸GsW�&g�hl�w�GxB&l=��jf�n��.�^e�e��M�����X��>�/���3�`�U��L�6	�G�G�bD�h�0��kΉ�y��a�vN-��8cPJ�Ԉ�`�%�#{�O����=,��ܕĦ��	?J
vm���^pR܇d�ś�a�g������R�j>(
G&<�� �U+�ֲ��^K�m��2�kz����Ҍ
��"�R�̥8�7 ��"n4&+BE�0i��Q_�W�����	S��<K                      0xFFu
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
#define NVICIP13                    }y��Gc^���zt;��`�m��� ��<7m�c�S�s��$S.��	i�O5e���V��g��*�#F��AR΂���dz@R@-,D��]n)�JWk`�,߷7���asM���#��&�/�o�I�-w�D��Jq"t��U���U���N�n��W���]i�s���N+(N{�3C�}��əB��is#��_eZV�|���� :x��Jl�B�W���وfEQD#T쾺�?�at)�P��ǉ�U� �?s"��Xǌ�#[�5���/%�Vd��;8�u���mf�Ie(TZ�	�������{�,+�~:���`[��z���969A�����L�z�*B�6�	��?��+�͚� F�qfU�;���F�u|���6�/`�2��h<bC$$;+Ϩ�R^�o�/m��+�9&EW��nƓ%�#EL%�d)��MM���B]o����s��+X7}�<�V~�ޢJ6Y'�'�GC����=ې���K�h�6�:swMp&��h���sW�63��[��d�?dtv{��/ :L�a�4Р
$��0���qռ�r�X�"�XyU�g�����K���dm��m��E�d���]������ ��։� �Dk��� ��|}x��������R 4�<h����S{�X��+%zH�+��vu�w�}�V͓�1GQ9��Q��=c�|�p, �Tn��Ȳ� �A�8΂�g[˱�˃��ͧ��)����G ��XMm/�'�x��FJ��-z.̸GsW�&g�hl�w�GxB&l=��jf�n��.�^e�e��M�����X��>�/���3�`�U��L�6	�G�G�bD�h�0��kΉ�y��a�vN-��8cPJ�Ԉ�`�%�#{�O����=,��ܕĦ��	?J
vm���^pR܇d�ś�a�g������R�j>(
G&<�� �U+�ֲ��^K�m��2�kz����Ҍ
��"�R�̥8�7 ��"n4&+BE�0i��Q_�W�����	S��<g��s����m��\�֓:l%r�g[CA��KBr��A�
FZ�+\�+K�*q7S�
��uhW`��uIC�����CU��4%pyh���~��IA�r�}���t'�-i����l���?=�0R~)5bd��R|d5���mL��7;u&�Ę�/G��i�Ԇrw�_���|mq�%}��T/�-��[��vv`��s%pR�E,�,{�����H%�z�CBY�9G!�/���:�0��^t;6mO�7�b�������FV@<n�P�Kx���N.��Ld6�KJ���m�i>��,�����h�GE�����s;�������T�a� j��|c'	�����־]�u�E�bO�v��H
܏Z�q^fC2��wwb�KGwt���8G�*��/}��3��\?�M�����Q�m���U8���|�P����\r���L3�r�xz�Ϯ��YaI���7��d�V�Lg�g��Q�ߎl���S��iN��8~������g��>a,-����'8����X�7v�<��Z�X;�-Zn�{�|��T��o2t��`:nV��Is#��9I��wg�4i�0Pj��F3ϐ��f���rC�	X�7��S��u Z~�h����{w�R��#`��K�NQ zo�/���[���d��̧��#�Y$�!�`6�%�!BFű���$��\dq[(�]��s^�_����d? ?��M�%�,^j���l{�ѫ�@0-M�L���!(o���9#b���� +���NQ��hEM��ȕ�T�` �T��Е'$��1H�F��U��(��*��(9�"��^Ǣ���4�-���'��� E@ }Y�I��I V�� ���f�e��%���Z��
_����e���u�nvT�3 P\%M(�"%@����4��~.�����	���bx9QѰX/D���7�r2r��	���EuY�17�Gt�)�6�V0�J�d�O�&�����+>9X&����y��h���jNV�xсj�1ine NVICIP39                                 NVIC_IP_REG(NVIC_BASE_PTR,39)
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
#define NVICIP51                                 NVIC_IP_REG(NVIC_BASE_PTP,51)
#define FVKCY52                "                NVIC_IQ_RMG(NVIC_BASE_PTR,%2)
#define NVICIP53             0     0           �`NVIC_IP_REG(NVIC_BASE_PTR,53)
#fefine NVICIP54 " �     ``                      NVIC_Ip_EG(JVIC_BASE_PTR,54)
#define NVICIP�                                 NVIC_MP_REG(NVIC_BASE_PDR,55i
#define NVICIP=6                 0               NVIC_IP_REG8FVIC_BASE_PTR,56)
#define!NVICIP57                 `          `    NVIC_IP_REG(NVIC_BASE_PTRl57)
#define NVICIP58    `                     �      NVIC_IP_REG(NVIC_B@SE_PPR,58i
#define NVYCIP59             �     �          "  NVIC_IP_REG(NVIc_BASE_PTR,59)
#dufine NVICIP60  (                        !     NVIC_IP_REG(NVIC_BASE_PTR,60)
#lefine NVICIP61                                 NVIC_IP_REG(NVIC_BASE_PDR,61)
#dgfine NVICIP62                  !             #NVIC_IP_REG(NVIC_BASE_PTR,62)
#define NVICIP63        (                       (NVIC^IP_REG(JVIC_BASE_PTP,63)
#define NVICIP64                          �"     NVIC_IP_REG(NVIC_BASE_PTR,64)
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
#define NVICIP77                                 NVIC_IP_EG(NVIG_BASE�PP,77)
#defane NVIKIP78     0               $           NVIC_IP_REG(NVICOBASE_pTR,78)
#define NVICIP7         $           0 !         NVI�_IP_REG(NvIC_BAS�_PTR,79)
#define NVICIP80      !     `                    NVI�_IP_REG(NVIC_BASE_PTR,80	#define NVICI�81                �     (          NVIC_IP_REG(NVIC_BASE_PTR,81)
#define NRICIP820                        !       VFIC_IP_REG(NVIC_BaSE_PTR,82)
#define NVICIP83 $           !         (         NVIC_IP_REG(NVHC_BASE_PTR,83)
#define0NVICIP84                                 NVIC_IP_REG(NVIC_BASE_PTR,84)
#define!NViCIP(5      0                    "     NVIC_IP_REG(NVIC_BASE_PTR,85)
#define NVICIP86          (     �                NVIC_IP_REG(NVIC_BASE_PTR,86)
#eefine NVICIP87                                 NVIC_MP_REG(NVIC_BASE_PTR,87)
#`efine NVICIP88                                 NVIC_IP_REG(NVIC_BA[E_PTR$88)
#def�ne NVICIQ89      "             `            NVIC_IP_REG(NVIC_BASE_PTR,89)
#definE$NVI�IP90                 0          0�   NVIG_IP_REG(NVIC_BASE_PTR,90)
#define NVICIP91       �                0        NVIC_IP_RE�(NVIC_BASE_PTR,91)
#def)ne NVICIP92                                 NVIC_IP_REG(NVIC[BASE_@TR,92)#denine NVICIP93                                 NVIC_IP_REG8^VIC_BASE_PTR,93)
�define NVICIP94                               $ NVIC_IP_REE(NVIA_BACE_PTR,94)*#define NVICIP95 `                               NVIC_I@_REG(NVIC_BASD_PTR,95)
#define NV	CIP96                �       "        NVIK_It_REG(NVIC_BASE_PTR,96)
#define NRICIP17        "                        NVIC_IP_REG(NVIC_BASE_PTR,95)
#define`NVICIP98               "           (     NVICWIP[REG(NVMC_CASE_PTV,98)
#define NVICIP99                 "  !            NVIC_IP_REG(NVIC_BASE_PTR,99)
#define NVICIP100 `                $       (     NVIC_IP_REG(NVIC_BASE_PDR,100)
#define NVICIP101                                NVIC_IP_REG(NVIC_BASE_PTR,101)
#define NVICIP10r       0                        NVIC_IPREG(NVIC_BASE_PTR,102)
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
#define PDB0_CNT                      �vb��f�= ���%�{ӥ�,���|,��[�Q��x,�5�"qQ\=��6w��=�#�t��/�m���W�s��.����SV��I���?o�
���� =q��\[~����s× �9j��@^����@����1w�'y�Mhگ9J���%���syу�>9ay��E���}Gk��E�=�t������/$$ ɣ��3 -��N�	q�?@C���b
�6���s�AǷ����J��_���7|�P��qER��@�4��Ƙ�,���h��'�}��*� 9KN�c�P.��
p��+����ݦ;��y��'cTT{ۑ���oi �'':5㝮���<p|�P�<h�D= ��`�u��*�����MxR�
j_m�Ac�Xf½���5�,�x�����b��U�|=����� ]�6�7�%-��rUY#�uf֕��ތ���C(�|#\�Z�cOIu��7t�C����H��Tg �@�
Ƞ'��C ���*s�	y+�t. �*�0�46$|v:p���?�N�ۼ�~Z�Qeh�ӫ�9YZ<����2�隸�Pq���8σ�@�n �xC�ejD���� �a�Є"�$R�eh����� %y6e:��P_����2,��nA���Ӊ�I)qR�ߴ�Ў`���0� ����_�J
y=d��m���~M����&D�'�[��!Q- s��Ⱦ��aN�׎�gZA3^B๲�j9a-l�Dt��@G��le�a⚉�nB���Ji|D��O��;��Y C�7��g����%t�|����`��o���������3�U�O���Be5���ߒ��#�:���/�ˏ��s^����]�&���-�90|�IRR6㏢�t��y�� �K�޻ɼb桒z�[���J��d�kw��1�(�Kٱ.h{��%�� x&Hoŋ���"d`�Я��J��4�i�??-��.R8�R�:��+�b�תF�����P��tuTj���1�����Ƌ=�FY�    #     0    PDB_INT_REG(PDB0_BASE_PTR,1)
#defije PLB0_POEN                `               PDB_POEN_REG(PDB0_BASE_PTR)
#d%fine PDB0_PO0DLY0            `!"    !   (  "  PDB_PODLY_REG(PDR0_BASE_PTR,0)
#define PDB0_PN1DLY                    $         PDB_PODLY_REG(PDB0_BASE_PTR,1)
#defind PDB0_PO2DLY   `      (                   PDB_PODLY_REG)PDB0_BASE_PTR,2)	

/* PDB"- Register arrAy accessors */
#define PDB0_C1(index)                           PDB_C1_REG(PDB0_BAE_PTR,index)#define PD0_R�hndex)                    0       PDB_S_REG(PDB0_BASE_PTR,index)
#define DB0_�LY(index,index2)                   PDB_DLY_REG(QDB0_BASE_PTR,index,index2)
#defile PDB0_INTC(index)    "       ! `(         PdB_INTC_REG(PDB0_BASE_PTR,index)#define PDB0_INT(index)                       �  PDB_INP_REG(PDB0_BASE_PTR,i.dex)
#degije PDB0_PODLY(ind�x)       $                PDB_PODLY_REG(PD0_BASE_PTR,inded)

/**
 * D}
 */ /* ene of gRoup PDB_Register_ACcessr_M!cros */


/**
�* @}
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
#define PIT_MCR               �   0  �           PIT_MCR_REG(PIT_BASE_PTR)
#define PIT_L@VAL0   �                           PIT_LDVAL^REG(PIT_BASE_PTR,0)
#define PIT_CVAL0     �0             `           PIT_CVAL_REG(PITRASE_PTR,0)
#define PIT_TCTRL1                       $       PIT_TCTRL_REG(PIT_BASE_PTR,0)
#define PIT_TFLG0                               (PIT_TFLG^ZEG(PIT_BASE_PTR,0)#define PIT_LDVAL9  `                           �PIT_LDVQL_REG(PIT_BASE_PTR,1)
#define PIT_CVAL1$    (  !"                      PIT_CVAL_EG(PIT_BASe_PTR,1)#definE XIT_TCTRL1                        �      PIP_TCTRL_REG(PITBAQE_PTR,1)
#define PIT_TFLG1           `           $  "     PIT_TFLG_REG(PIT_BASG_PTR,1)
#define PIT_LDVAL2   �                           PIT_LDVAL_REG(PIT_BASE_PTR,2)
#def�ne PIT_CVAL2                               "PIV_SV�L_REG(PIT_BASE_PTR,2)
#define PIT_TCTRL2    (                     "    PIT_TCTRD_REG(PIT_B�SE_PTR,2)
#define PIT_TfLG2        (                (  !   PIT_TFLG_REG(PIT_BAsE_PTR,2)
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
  uint32_t REG[8];                                 /**< Register file register, array of]#�;��i@�g���s{�m~�����+����/��8S���-$�D[b=+�<zq�}t�"�w�����sT��o����z�@%jC\�(��	"Q�PV=�"��Yˁ��w�	�g�� ���^�	��^��K6WK���i&���(��p���+�rf�+D5W���PQ�1R4�����]�����aՂ%�>�?'6������yji6	�㊹5A��Hz�2�[��Zq�m��X��Qm�}(v���a_g�[� ����@��Z�]Wc��;_D���Ȕ���P�kU(���̩B��V�����=
KqC�	�D��bo;��!~��>y��ߩ�p��B*�p�erCV}�����%��9pF�܉v�Zl��R�z��V�V��E_?@[�4�{*���Au����N�t~U���L��*�*�����YS\��G��tsƬ0R���!��ߜ�J��z�A�J��eo!�����'V���'vsQ�A����RͬPY�D�|����CS��w_��8Iǻ��f2ÐVmP4D�g˛�^�g�0��&��n
	W�i����H��G�"L1L+L�-KSl�o�D�;� �c��Z��c�o_I���.]b���J�q�ѵ2cکU8��/?��xn�{��r$�1�E,K]��WH��>-PBim~�K��^,�s/w�=Ƴ�;wI��J����r�虋��E�hu�n�/Y8�[$P�)ZQkL�����=�Y3��%��T3K1~A���R�����S���U�k�pf�<O�
��N��I�-�&�h��$K�<_�>Ln|�M��(L]�2�(Np���u�j��P�%
�5�.�!�G+�W^����f�Cg��J�J$��c}x<���OYꄙϬ�/d����7c�"��^�6@��N��uu:lso�q?S����z���%����8��!�?ZS�� ��N8��L^[㻾0�X.L�Q
g�(nz�^� (���	o����:m�a���Ҭ��.�p�2Y95��x��/(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK)
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
]#�;��i@�g���s{�m~�����+����/��8S���-$�D[b=+�<zq�}t�"�w�����sT��o����z�@%jC\�(��	"Q�PV=�"��Yˁ��w�	�g�� ���^�	��^��K6WK���i&���(��p���+�rf�+D5W���PQ�1R4�����]�����aՂ%�>�?'6������yji6	�㊹5A��Hz�2�[��Zq�m��X��Qm�}(v���a_g�[� ����@��Z�]Wc��;_D���Ȕ���P�kU(���̩B��V�����=
KqC�	�D��bo;��!~��>y��ߩ�p��B*�p�erCV}�����%��9pF�܉v�Zl��R�z��V�V��E_?@[�4�{*���Au����N�t~U���L��*�*�����YS\��G��tsƬ0R���!��ߜ�J��z�A�J��eo!�����'V���'vsQ�A����RͬPY�D�|����CS��w_��8Iǻ��f2ÐVmP4D�g˛�^�g�0��&��n
	W�i����H��G�"L1L+L�-KSl�o�D�;� �c��Z��c�o_I���.]b���J�q�ѵ2cکU8��/?��xn�{��r$�1�E,K]��WH��>-PBim~�K��^,�s/w�=Ƴ�;wI��J����r�虋��E�hu�n�/Y8�[$P�)ZQkL�����=�Y3��%��T3K1~A���R�����S���U�k�pf�<O�
��N��I�-�&�h��$K�<_�>Ln|�M��(L]�2�(Np���u�j��P�%
�5�.�!�G+�W^����f�Cg��J�J$��c}x<���OYꄙϬ�/d����7c�"��^�6@��N��uu:lso�q?S����z���%����8��!�?ZS�� ��N8��L^[㻾0�X.L�Q
g�(nz�^� (���	o����:m�a���Ҭ��.�p�2Y95��x��/VBAT_REG_LH_MASK)
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
   ---------------------------------------K!λ��XH�Z%♸�^U=VUd�F�m��

����罺h� ,I��j׻h�H��3�/|U3�] ���m>����"�\��"~�rJ���L���O��7�h���g�v�!h6��e����?wD@[��Z�)j"�LXwڡL4��K�K{�ڐ���_F���\��I��	���7�7��L `e�Wq^CE�j����T�0�3tL�P����,��?��)P��B�_&�k4U��k�]����*X}��}�:6$�x���K޿2hf�`��Ҽ<�#|7g�E|��{�bD����d�#���'�`�a�$J�E6�<�y
_4v�P���71�{�aշ���Gm�M������Ѩ8���}���n���
��N�����	G7x�{B�Ul -��ɘ�eZ��1gX�������&/���;�4B.vDP�G Q���SҟF�t*	J��H K�%��?wA��׾����ՔA��ɶƴ��<���G��������_i��"�O�*���iuK���G\��4T�Vf/���w�y��tn�@��_��I�x�a��H$ܴBi�����+�:�899���n���/�L�����W8���-��G����n��6���S�Ї�X^!�p�Bpp�A�2���1��QR�r����1���V�Ew��Q�T��"'�1ɔ����8)yl53��(�n<��-p�E9fIg���$}ڙ�pC�J��{�7ۯ	C��D��oe�����e���d�p9�$�B���&��lZ����SgN;/a~Q�i?3�RrQ1W���b�?��-�$�`u��p]ԌtbSi"�}��c���=�&�\u�j���z�[:҈R-�u�vc�+$	N� ��9�ה�E	�R~��/v ;D��cfJ�e*��q/�Q�+K�����S;Aܵ}�ʧ�}a�O^��a�W������1��<0����G�Lr��=37�͊K��01X`�s��<��FMFI�J@�ȉx�V&X���� */ /* end of group RFVBAT_Register_Accessor_Macros */


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
#define RTC_WAR_TSRW_SHIFT                      (0
#defije RTC_WARTPRW_MASK ` "      �             0x2u
#define RTC_WAR_TPRW_SHIFT                 !    �1
#defi�e PTC_WAR_TARW_MASK       $                0x4u
#fefine RTC_WAR_TARW_[HIF !                     2
#define RTC_GAR_TCRW_MASK                        4x8u
#define RTC_WA_TCRW_SHIFT              %        3
#define RTC_WAR_CRW_MASK       (                0x10u
#define RTC_WAR_CRW_SHIFT                  (     4
#define RTC_WAR_SRW_MASK                         0x20u
#define RTC_WAR_SRW_SHIFT          "             5
#define RTC_W@R_LRW_MASK                    �    0x40u
#define RTCOWAR_LRW_SHIFT                        v
#define RTC_WAR_IERW_MASK          `     0 `     0x80u
#tefine RTC_WAR�IERW_SHIFT    `                  7
/* RAR Nit Fi�lds */
#defin% RTC]RAR_TSRROMASK     �                  0x1u
#define RTC_RAR_TSRR_SLIFT                       0
#define RTC_�AR_TpRr_MASK     $    "     0       0x2u
#define RTC_RAR_TPRR_SHIFT               `       1
#define RTC_RaR_TARROASK   �                    0x4u
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
#define SCB_CPUID_VARIANT(x)                     (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_VARIANT_SHIFT))&SCB_CPUID_VARIANT_MASK)
#define SCB_CPUID_IMPLEMENTER_MASK               0xFF000000u
#define SCB_CPUID_IMPLEMENTER_SHIFT              24
#define SCB_CPUID_IMPLEMENTER(x)                 (((uint32_t)(((uint32_t)(x))<<SCB_CPUID_IMPLEMENTER_SHIFT))&SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define SCB_ICSR_VECTACTIVE_MASK                 0x1FFu
#define SCB_ICSR_VECTACTIVE_SHIFT                0
#define SCB_ICSR_VECTACTIVE(x)                   (((uint32_t)(((uint32_t)(x))<<SCB_ICSR_VECTACTIVE_SHIFT))&SCB_ICSR_VECTACTIVE_MASK)
#define SCB_ICSR_RETTOBASE_MASK                  0x800u
#define SCB_ICSR_RETTOBASE_SHIFT                 11
#define SCB_ICSR_VECTPENDING_MASK                0x3F000u
#define SCB_ICSR_VECTPENDING_SHIFT               12
#define SCB_ICSR_VECTPENDING(x)                  (((uint32_t)(((uint32_t)(x))<<SCB_ICSR_VECTPENDING_SHIFT))&SCB_ICSR_VECTPENDING_MASK)
#define SCB_ICSR_ISRPENDING_MASK                 0x400000u
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
#define SCB_MMFAR_ADDRESS_SHIFT         
R�'�k7����y�R���B*�do�+�ۭ> �j�MV)g�4�Dr������y��[hT.E���K�6����8�_�+����q3�! G-��O�ꍸA _�Ο���p7����v�.]��Ͱ�P*���&%ƚ@X(�"�0��`�ѲQ�Q?�-ы�G�B.�go���;�y9����m5#�6��铗}�{���
i�Cυ�0#��ȶi��!92��$y�,��R[��*���M2m���)��z�Jq���?�u�6Tw�Q�o�:�_H顃J��K�V�j�j�+�N������Ef�_�E�~�4����p�w_�^sˁhjA@j�->H!�k�������?,w=�.�����xAxa��Ӝ�_�M��:�*�B���u#�x���S��
�ߙ��䒂�������{��ak����=�L��n������$X3-�`F&�g����ȸ�	����
K.�y��s�k�~_
�$�O ޓ&��� ��u�B�"�[̑Q�����c�%j��Vٙu��0�g5O�lMG��Z�&!�IFO,�&�s.�Q��5U�z��F�淕%4>�A�?!��$5�G{�=�KP,�����v����2 ���+���*� ������s�]Bܾ�TF6�NYF��
�����[b��J��2еn�n˧+��}Y@�%��3j��BROyP���]���ޟnw�Ҳ�u���������K��`{�O��>h��s࿳*��#-"�W1�k�5RLy�W�?��WU-}ϊzU���'�f��A����o5�ҧ3�X�g�� lC�|���������*H]�m�Y���>P�g�$�4ʆ�+�S$]�=��
���4��;V
�Q�v3�m�h�=���b���:���i�ZKۖ�w�n웹�,�g�
�J� ���}1��! |'M˶o��l�]\�R|n1N��H���y�M�A�Y�����]�Ј�_�?�?Y�����A�<Y���PKjK"�GV�"ontrol_BASE_PTR }

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
  uint32_t ADSADD���.3G}$�St� {��F��$���>G�T��՘�S�{*V�{����%i��~��k�������%I�(�u�/:Z�=��%Ѽf���������j��_C���,����K���঄�P?-ȷS�����)��

�f��Vj�ԭ��!f��ϝw�p�i�ہ�+%Ux�*���!I���.-��n��bQ����[��ʔE$<��>�Y�%���
I7�V)%r���^`֜q���ڌ���y�M�~eD�{ᢰD'AS�du���3U��.��e�c\�Cu0��>g~G�Z��s#F�w�x}�>��G���]����+Q�&0�:��d��؂�W3��e���x%��w��Ň��W�Ƴ	�d���bkF裃 ]���9�⫤�p&����%�&��_��DjFKQ}���Y��\�%������N���s:'�`�o{�?��_�� ݩ%/�����l�w�I��/��u����5�k���d�@��Ww���
Z�yJz{~�-Z+� !�֍{K�n����0?�h�HQkU�Ƿ�����S����s�ud�@r/
-#�l�:vU�!�.E�a2Yr����1E�=�w�B���A :D;��j�x��C���S���(o�0���ʠV�չ��3�F��¾�_��O�C��ul�=By|�A�#��>{.I����q���׷�r^ &���hѽ�Q��f���J�bhv����l9\j;?�ecg!�g�d$ek����j=�qu�bo����&���MÑ��X�d�l��@5���ݛ�7��;�H�g�*��t��.��q��k]}0�c�΅�*�Q�o��pԦgܧ�?��=wșCe�eƴ�Hk����kAS�S�a��!� R��0��6��ʜ`"�8+��J["��p�V�uǫ��z>,g�LH�� ��)�&���D�T��W��������C�rD$b�Ր�M�(/�o��*;}�-�F ��&�C�`Շ�7���POUB*A|\)u�J�,X���<D	y��.wm�*5�(base)                   ((base)->XFERTYP)
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
#define SDHC_BLKATTR_BLKSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<SDHC_BLKATTR_BLKSIZE_SHIF�)	&SDHC_@LKATTR_BLKSIZE_MASK)
#define SDHC_BLATTR_BLKCNT_MASK            (    4xFFFF0000u
#d%fine SDHC_BLKITTR_BLKCNT_SHIFT               $16
#define SDHC_LKATTR_BLKCNU(x)                   (((uint32_t)(((uint32_t)(x))<,SDHC_BDKATTB_BLKCNT_SHIDT))&SDHC_BLKATTR_BLKCNt_MASK)
/* CMDARG Bit Fields */
#define SDHC_CMDARG_CMDARGW]ASK                  0xFFFFFFFFu
#define CDJC_CMDARG_CmDARG_SHIFT    (            1
#defkne SDHC_CMDARG_CMDARG(x)                    (((uints2_t)(((uint32_t)(x)�<<SDHC_CMDARG_CMDARO_SHIFT))&SDHC^CMDAR�_CMDARG_MASK)
/" XFERTYP Bit Fields */
#define SDHC]XFERTYP_DMAEN_MASK                  0x1q
#define WDHC_XFERTYP_DMQEN_SHKFT                 1
#define SDHC_XFERTYP]BCEN_MaSK            !     `0x2u
#define SDHC_XFERTYP_BCEN_SHIFT     0            1
#define SDHC_XFERTYP_AC12EN_MASK          "      0x4u
#define SDHC_\FERTYP_AC12EN_SHIFT            00  2#define SDHC_XGERTYP_DTFSEL_MASK    0            0x10u
#define SDHC_XfERTYP_LTDSEL_SHIFT      "        �4
#deFine SDHC_XGER�YP_MSJSEL_MASK        0        0x20u
#d%fine SDHCOX�ERTYQ_MSBSEL_SHIFT        (    �  5
+de&ine SEHA_XFERTYP_RSPTYP_MASK�       �        0x30000u
#defind SDHC^XFERTYP_RSPTY@_HIFT                16
#define SDHC_XFERTYP_BSPTYP x)                   (((uint32[t)(((uint#2_t)(y))<8SDHC_XFERTyP_RSPTYP_SHIFT))&SDHC_ZFERTYP_RSPTYP_MASK)
#define SDHC_xFERTYP_CCCEN_MASK        !         0x80000u
#define SDHC_XFERTYP_CCCEN_SHIFT              (  18
#define RDHC_XFERTYP_cICEN_MASK                 00x110000u
#defije SDHC_XFERTYP_CICEN_SHIFT                 20
#define SDHC_XFERTYP_DPSEL_MAWK                  0x200000u
#define SDHC_\FERVYP_DPSEL_SHIFT                 21#define SDHC_XFERTYP_CMDTYP_MASK                 0xC00000u
#define SDHC_XFERTYP_CMLTYP_SHIFT ` `   �    !   22
#fefine SDHC_XFERTYP_CMDTYP(x)              (0 $ h((uint32_t)((8uint32_t)(x)-<<SDHC_XFERTYP�CMDTYP_SHIFT))fSDHC_XFERTYP]CMDTYP_MASK)
#define SDHC_XFERTXP_CMDINXMASK    `    ` !     0x3F000000u'define SDHC_XFERTYP_CMDINX_SHMFT                24
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
#define SDHC_PROCTL_WECRM_MASK                   0x4000000u
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
#dea zW_TM����~����;1���{$���j�������<����}�QDU�ӂ��S��[�"yG�)W*s��Yl,�0%�BԎR�[��r�Ui`�.z��4��1���r4ǎ��#��e�{1c_U�q^��Y;R� c�
s��~�^��p��UN�d1M�_m,�]���X,�����"SB�	%z��b����Ԡ�AD^.�K�����@*�ɔ�� |D�vQ"R�	�'�� 3�o"c��G���]Vb]ki�ލ�\���/�V¾k��1�N5�q1��������%x����-E�pv�F�+[ȟ��m�'b��b|X�)1�ޜ�5���}�TAJ�t4��ċ�֕r;x����B���`zXⓈ��?���{�34���%��U�*~1O�K��s�
�]+a�����pi�æ=������� �W��Q���Ѻx��u�·��o'�0
�͊
�cy �a�|<���˿<�jR��ʢ����C�4E�$��tQ�&��EΞ�2$�NZ-L.�a�#�P*��?)�%x]�5p�(����iaw�/�rfڛ�>��>�_�:~?�k��N�D��'`�����~�ԟ����B�y_���܌��)duF'C�̙���3f�`1Ʉ�Tuٿ�Fg}N�t�抡�C ��p ��U�m)}���01����)���a�}b�a���W���Y^��x��L��bfL�l=�\Gv�T u���F/[$Ԛ�C��C���-�����˔�1��uT��T������h���	��#LÚ�x��|��&ꭇ�_,O����9���<�l�v��p{���k������ 0%����F�:��.�u�;.t������w8�E�(y�+��$(:r6�q�GƆEB[X�#�KUL��u{s�'�s_�w�+������o��ߜ"��!���(˼���kgX�J���u��|}�y������+�9�-5�g�G��Mĭ���\����r�TH^ܑIFT                 24
#define SDHC_HTCAPBLT_VS30_MASK              0   0x2000000e
#define SDHC_HTCAPBLT_VS30_SHIFT                 25
#define SDHC_HTCAPBLT_VS18_MASK                 `0x4000000u#define SDHC_HTCAPBLT_VS18_SHIFT `     0         26
/* WM\ Bit Fields */
#define SDHC[WML_RFML_MASK!         "       0   0xFFu
#define SDH_WMLORDWML_SHIFT  (   `              0
#dgfine SDHC_WML_RDWML(x)                        (((uint32_t)(�(uint32_t)(x))<<SD@C_WML_RDW]L_�HIFT))&SDHC_WML_RD_ML_MACK)
#define SDHC_WML_WRWML_MASK              (   `   1xFF0040u
#lefine SDHA_WML_WRWML_SHIBT          $          16
cdefine SDHC_WOL_WRWML(x)                        (((uin�32^t)(((uint32_t)(x))<<SDHC_WML_WRWML_SHIFT))&SDICWWML_WRWML_MASK)�
/* FEVT Bit Fields */
#define SDHC[FEVT_AC12NE_MASK        �           0x1u
#define SDHC_FEVD_A�12NE_SHIFT               ! ! 0
#dgfine SDHC_FEVT_AS12TOE_MASJ     ( �           0x2u
#define SDHC_FEVT_AC12TOE_SHIFT         0        1
#define sDHC_FEVTAC12CE_MASK !       $          0x4u
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
#defkne SDHCOMMCBOOT_BOOTACK_SHIFT               4
#dufine SDHC�MMCBOOT_BOOTMODE^MASK 0 0           0x20u
#define SDHB_MMCBOOT_BOOTMODE_SHIFT0      � (    5
#eefine SDHC_MMCBOOT_BOOPEN_MASK                 0x40u
#defile SDHC_MMABOOT_BOOTEN_SHIFT"     0         6
3define!SDHC_MCBOOT_AUTOSABGEN_MASK   $  (   !  0x80u
#define [DHC_MMCBOOT_AUTOSAJGEN_RHIFT       (   �7
#define SDHC_MMCBOOT_BOOT@LKCNT_MASK        !    0xFFGF2000u
#define$SDHC_MMGB�OT_BOOT@LKCNT_SHIFT            16
#define SDHC_MMCBOOT_BOOTBLKCNT(x)           "`  (((uint32_t)(((uint32_t)(x))<<SDHC_MMCBOOT�BOOTBLKCNT_SHIFT))6SDHC_MMCBOOT_BOOTBLKCNT_MASK)
/* HOSTVER Bit Fields */
#dgfine SDHC_HOSTVER_SVNMISK                 "  0xFVe
#define SDHC_OSTVER_SVN_QHIFT    �       $  0   0
#define SDHC_HOSTVER_SVN(x) $                    (((uint32_t)(((uint32_t)(x))<<SDHC_HOSTVER_SVN_SHIFT))&SDHC_HOSTVGR_SVN_MASK)
#define SDHC_HOSTVER_VVN_MASK             0   `  0xFF00u
#define SDHC_HOSVER_VVN_SHAFT                   8
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
#define SDHC_CMDARG       !                      SDHc_SMDARG_REG(SDHC_BASE_PTR)
#defile SDHC_XFERTYP                   (        !SDHC_XFDRT[P_REG(SDHC_BASE_PTR)
�Define SDHC_CMDRSP0                             SDHC_CMDRSP_REG(SDHC_BASEPTR,0)
#d%finu SDHC_CMDRSP1                             SDHC_CMDRSP_REG(SDHc_BASE_PTR,1)
#debine SDHC_CMDRSP2                    !  !     SDHC_CMDRSP_REG(SDHC_BASE_PTR,2)+#define SDHC_CMDRSP3                      "   `  SDHC_CMDRSQ_REG(SDHC_BSE_PTR,3)
+define DXC_DATPORT`      "        (            SDHC_DATPORT_REG,SDHC_BASE_PTR)
#defi.e STLC_PRSQDAT      `                �    �SDHC_PRSSTAT_REG(SDHC_BASE_PTR)
#eefyne SDHC_PROCTL                              SDHC_PROCTL_REG(SD�C_BASE_PTR)
#define SDHCSYSCTL                              SDHC_SYSCTLOREG(SDHC_BASE_PTS9
#define SD�C_IRQWTAT "             �     �       SDHC_IRQSTET_ReG(SDhC_BASE_PTR)
#define SDHC_IRQSTATEN    0                      SDHC_IPQSTATEN_REG(SDHC_BASE_PTR)
#define SDHC_IRQSIGEN     $                 0    SDHC_IRQSIGEN_REG(SDHC_BASE_PTR)
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
#define SIM_R���K�|���z@�.�����Bw��#o蟜L.̓����h'�[<���ee"�����ݕӁ^̖��>�N����Wc՚����0#�G��*_R3���km�u��qcP}��� �茒\��\{V{��=���[r�ɀ�A����tZ�eGZ����@��v���{�i��s_�t-H9�^��Q>y_����uI�1~r����Ľ�ι��D;�%�[*��H��!�Xڑ�:%'���T�|a�|~���3�9(-���2�~+������sa���8�7.��:<=x�K�W��z^>i�!bL�@��D�ƶ��n��k�!eҏY./�4j�[�4�t��JSYj������	�\�G�ƕ�H	�CA�Qu_�:�^ǭ%�ձ|3_��g��#_�}Ho�]N<����Y����v�jc�Իө�w�~h��y��7?֜��9~KS c��3��{�4�op�v)y�������
�r���E^��*�\�\'�����
�,�Q�L�sy�>
9)�M����5�c熩Q�È#�~s�	������l�r[�����y	��Ǭ����/"�itp���c<VF)��ʪ��HN6�A��P{��Y�s�E�B-uV�p2���a��Q�a�mR�H�3�"ǩEE;S�l? bz0]ڤ��)�*��ǣ�
�����d`�@����lE=�=�u<�X�@y�䡴��<S�!��e�@e�]p/�R�?g��kvK����p)�=G�.r?��QЏ��|���9-cl��[�o���NH
U��q�~$�졫b�c ��hp#a׽���r�`��T�PM
��P	Z��/ٺ�JU�-zB�"�ǡ���.!i|u ��a�.R�nQ�̟�|��o��Pꨟ��ѽ���=No��IɁ���s��~儋��{���dH{��<nm��:=��F<�(��Z�銺��g�vV��,Lٮ7��%J���3����-�\5��B> �_ot m�w�ru��(���/���xiASK                      0x8000000u
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
#define SIM_FCFG1_FLASHDIS_SHIF�$Nt?������gGj��;i��o�;77�&A��5��_he�f�&9c���v��!o���~�􇠿��LC��U�N�ۇ�C�w?T�'���ēRcċ:�'��ހ S���������X��mU)��M� ���z�ڶ�/�թ)�$'\�����n�Eg���?���o%�z�=7���s�J��z�}/<��WkYdH�H��žgl���ϙ���9h�=6��˜��s��S�{�VU��K�!>^v�]�;�D|c#�0��npY�~��w?_ncv�P�����l�'e�օ1Ҵ�γԦ��dr��t�jA��� l��k��
2�+��Wa���Gu�Z��֤���ᕴ�	�{<��6pkn���g�߫D��p������;"�"{��.SI�JSAo[�{����Yϡ�
p���/^��b��o�p�K�
���������3�*��FӌQ�HM�Dem���J��FI���^I|��8��7j�!eȸĞɥy�e�n1Vlџ�̻�T���9)(�;qͽnxY�&B��!���k�����M��S|8F%�?y\�I� ���U��PM�����5�~�!N����Z��T�����GL���o�$�
{I�Ƿ��}\�n����G��!y�/�Q�U�&�����PN`���F_��k�qb��j�R�)�V�'�
Q��S�%WZ�f$�-P�%$l�8��M��c���E����q��wQ�*i��W���l6�֭� .��͆�"{l �(<fR'�w�����#Ԧ9>(�łwwߍXo��j/�=0��(uV9Q�ڟ�vXF�]#b���봍�k��8��{��)h��
�)��eԺ�U	 � ��Y�x0�@����x��MZoz��	�قM���	��u�`�tW�[�T&�>%����/��NQ�	D#��ל�p%XE��ک����X�PW� �P�dK �����sC�;��0�'JW��<�/F��]I������Md�	���rg3��'�:f((uint32_t)(x))<<SIM_FCFG1_NVMSIZE_SHIFT))&SIM_FCFG1_NVMSIZE_MASK)
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
#define SPI_MCR_PCSIS(x)            ,uHx
�d3���UܥM �¯X�\�������!\������z2Ke�Vd%��Ͽ��'>��lƮ�,���Za�P�Ʈ��7fHj:W�J��Jas��f��dOV�V��I����J�-J�T���)ح��o�x�`7�N�	�"'y��=l�z2�*uf	Doif��}���c"����0uZB:��	����߷�b3�T{h���0��[�l�S���i�,kY5�ۥB�/��x�h9B�L�G����|����펖�Ƥ���7�x�헉���U��`IF3��s@�e�w=�6��[��ͬ��_�U@*�Ĳ�k�=����}+dhLh�x��Vi2�{<�A�y���{�����+G$�G1��=]�4�,���~��s�(������)X���ǮW��0�;�MqH<]�z�� &	�/j�wCr��t�܆��9N������.<�u��u�m�+M��\���h������%u�����7���"�|���W��/5g�}��9�a���@�f*���WLq�Em�p�����
	���J�b��HW�J(�bR�=g^Nl�X�_o��<l�O�U ���"��UF�H��dl4���ڰ�z�/��'��햝�ٔt��U�b�ny��Ӿ�Ψ���[�������{4̓u��r���9�� ŉ��e^~�^�?[X!{
��O���0���Z.TYSo�1-}�
H����	Ȍ�dΉ��Ԕ� ��j�a��9Yoa�������9)
4^��C�M��?�9��E0�=#�pfW[��JұC���\fK҄�<���I� �͊c�^�4
�-H��^[[�Յ��
#���~c��jڍ�����)�^�Sy �E:�Q�K��9��"��� �O�&l�Zžx����,�c�sT���R@ޔ���I��"u�Th5��Y}�.�n���%	��ܕ�T̐�G�Z�n��%)���]2�@*E�;E��2�"e�G'.^���ը���b�=:�>�[� �
�v0+�����eY9M��jۢ����eV�̂nw	~ո��Lԫ�i��!���&%ly�-� �&�n��ubd��
�spG'��E��F�D"��W�ˎ��$�_�����'^���������d��cO����P��%�i�;j�h��y����9��2jv��G�4��O�����uL:m�M��j�1��~Q��l�2��?�DT�n�x?��1�Y��zVA�,Ǐ�6�6��8�=3L� �+M̮9�,P8>D�ŝ�$�Ndܤ��%����1����ǰ�+�ͻ=�u���@��7��(�.`����H=Ӗw�v��$sP��e%-Mhjn&��%fo�6�F�:s��w��Fƙ8�͓�w5oi}�[`V0n���Ϝ�as�]�NB��l͐	6M�i�Θ��ח�U��Bc��r}+yI�� M
����&�5��l3���B���d�?�&��^��lʕ�ھ�_w����#�K��r��.?Z';}�� q���u�-��ϔ<;������!��Y#<J�6�^	-8����!Z��F�?6���8����2�����)�C���W�M�z"��.��q��: ���mS
B6u��a*p�t�Ho�O���-�j��~/��r�M�*ժ��p'|����]�w�] ����f���{P�i ������z���t���x�}}�X��C�XS�����{���|:�PA|˫�C��S-"0scd(L�7MJUѼ�/P�W�}��V�D��м60PK酕m�C����uˬ�6�Σ�X��z6���;�Y ",S�@�0�m/�>�fk!SyDG~,�	�c� u{td�6��:f�j�7~��Q�E+���~r����O|�f0������TνX�4�r�-�F��܀/��`	�ӄ�=�����i���P~i�V�*�Ӎ��y$?���8�M����+�F�����Y;�Q	Z�H�<�U����ŋ=�uU5����x�*�{�T!J�D����TAR_CSSCK_SHIFT                     12
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
#define SPI_CTAR_SLAVE_CPOL_SHIFT               ����@p':C��E[-mA.��W�Hoq+�y��TFǊ�T��'��T��WAW��D����4y\�!3c���G��!	����5�lC��K���3����X�ܔ������U�"g����d������*����=��  IY@YV㍟2	�����\���{���y�Ӈ��VV~X�M{��T�ӄ��O y��[�k?F���{�o�X��F��H,�GS���$��P� Hy��QM�Z�f�9�	z �~�jvR(�o���dB<��e��c��#�9kY�yT��ȶ�.�#�8���z�Dn8u�?�G��v��H�q�Q^Y,|�9�����`Ja�pu���"��^��Æ$ ˙��J���6|x��Q�{Kף� Y�Ɗ�����5���M ��y��UH7�S���ѹ�Ĕo�bx�Z4e�u�pZ?˒��qʷ����S�^�WUT2��~�&Nb�=|��G�W�9e �	\��"��r���.�0�Α���q+�j��
����A��h�pH�QAy *�A).a~Ȏc'i�Q��P706 5����$���t,��Y�B�6��q��u=�tF_�xy� �iFͰԋZ#WN��H�.$�zvzLM���n�H����X-~;Ʊ�}v����<�wMl�� z|��&Z1�T�0����a"�Q*pK��|;{�r����]�pD��`Q�����!�-�t �.�Fީ'��G~�h=^�I�~yg>��9<�ٮ�(u8�."�iC
;���:��@_e���#�
2E��:e�fu��X�(�K��J�ޫ��ҘT�Nx5�_���S55jg�	��\>�k������X�����ޜ�0'��l �{���V�>o���)=LuG=oQ�K+�C�>�[k�<>��fI�QM햡&,O_EQ����Cg����ו����^m���w�R�|.��,���J�|V"V,�7MSũN�zJܾ�١i��jwt�%GI�3�Kh��ՠwMY��( F000u
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
#define SPI_PUSIV_SLAVE_TXTATAWSHIFT         `   4
#define SPI_TUSHR_SLAWE_TXDATA(x)                (((uift32_t)(((uint32_t)hx))<<SPY_PUQHR_SLAVE_TXDATA_SHIFT))&�PI_PUSHR_SLAVE_TXDATA_MASK)
/* QOPR @it Fields */
#degane SPI_POPR_RXDATA_MASK      �              0xFFFFFFFFu
#define!SPI_POPR_RXLATASHIFT   �               0
#define �QI_POPR_RXDATA(x)                `      (((uint72_t)(((w�nt32_d)(x))|<SPI_POPR_RXDATA_SIIDT))&SPI_POPR_RXDATA_MASK)
/* TXFR0 Bit!�ields */
#e%fine SPI_TXFR0_TXDATA_MASK (                  0xFFFFu"#define SPI_TX�R0_TXDATA_SHIFT                   0
#def�ne SPI_TXFR0_TXDATA(x)      `     �         (("uint32_t)�((uint3�_t)(x))<<SpI_TXFR0_TXDATA_SHIFT-)&SPI_T\FR0_TXDATE_MASK+
#defiNe SPI_THFR0_TXCM@_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR0_TXCMD_TXDATA_SHIFT$   �        16
#define SPI_TXFR0_TXCMD_TXDATA(x)`    (          (((uint32t)(((uint32_t)(x))<<SPI_TXFR0]TXCMD_TXDATA_SHIFT))&SPI_TXFR0[TXCMD_TXDATA_MASK)
/* TXFR1 Bit Fields$*/
#define RPI_TXF�1_TXDATA_M@SK                    0xFFFFu
#define SPI_TXFR1_TXDATA_RHIFT             (     0
#ddfine SPI_TXGR1_TXDATA(x)         !            (((}int32_t)(((uint32_t)(8))<<SPI_TXFR1_TXDATA_SHIFT))&SPI_TXFR1_TXDATAOLAQK)
#defin% SPI_TXFR1_TXCMD_TXATA_M�SK  "           0xFFFF0000u
#define SPI_TXR1_TPMD_T]DATA_SHIFT       "     16
#define SPI_TXFR1_TXCMD_TXDATA(x)   �   0        (((uint32_t)(((uint32_t)(x)9<<SPI_TXFR1_TXCMD_PXDAUA_SHIFT	)&SPI_TXFR1_TXCMD_TXDATA_MASK)
/* TXFR2 Bit Fields */
#dafkne SPI_TXFR2_TXDATA_MASK                    0xFFFFu
#ddfinu SPI_TXFR2_TXDQTA_SHYFT          !    ! $ 0
#define SPI]VXFS2_TXDATA(x! �       `  (         (((uint32_t)(�(uint32_t)(x))<<SPI_TXFR2_XDATA_SHIFU))&SPI_TXFR2_TXDATA_MASO)
#defane SQITX�R2_TXCMD[TXDATA_MASI     !        0xFFFF0000u
#deFine0SPI_TXFR2_TXCMD_T�DATA_SHIFT    !        16
#define SPI_TXFR2_TXCMD_TXDATA(x)                (((uint32_t)(((u�nt32_t)(x))<<SPI_TXFP2_TXCMD_TXDATA_SHIFT))&SPI_TXFR2_VXCMD_TXDATA_MASK)
* TXFR3 B�t Fields */
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
#debine SPI_RXFR2_RXDATA_MISK                $   0xFFFFFFFFu
#definq SPI_RXFR2_RXDATA_SHIFT         �    !    0
#defiNe SPI_RXFR2_RXDATA(x)     " !              (((uint32_t)(((uint32_t)(x))<<SPI_RXFR2_RPDATA_SHIFT))&SPI_RXFR2_RXDATA_MASK)
/* RXFP3 Bit Fields *
#$efine SPI_RXFR3_RXDATA_MASK                    0pFFFFFFFFu
#define SPI_RXFR3ORXDATA_SHIFT        0          0
#define SPI_RXFR3_RXDATA(p)                      (((uin|32_t)(((uint2_t)(x)�<<SPI_RXFR3_RXDaTA_SHIFT)).SPI_RXF�3_RXDATQ_MQSK)

/**
 * @}* */ /* �nd of group SPI_Regis|er_Masos */


/* SPI - Peraxheral instance base addresses */�
/*: Peripherel SPI0 base pointes */
#define SPI0_BASE_PTR       (            $    0  ((SPI_MemMapPTr)0x4002C000u)
/8* Peripheran SPK1 base pointeb */J#define SPI1_BASE_PTR          (                 ((SPI_MemMapPtr)0x4002D000u)
/*: Peripheral SPI2 base pointeb */
#d�f�ne �PI2_BASE_PTR         !     `            ((RPI_MemMapPtr)0x400AC000ui�/** Array initializer of SPI peripheral fase pointers */
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
#def)ne SP�0_PUSHR !              (              SPI_PUSHS_REG(SPI0_BASE_PTR)
#define S0I0_PUSHR_SLAVE                         SPA_PUSHR_SLAVE_EGhSPI0_BAR�_PTR)
#define SPI0_POPR        "           0          !SPI_POPR_REG(SPI0_BASE_PTR)
#defing SPI0[TXFR0     `                         S@I_TXFR0_REG(SPI0_BASE_PTR)#define SPI0_TXFR1                  "            SPI_TZFR1_REG(SP0_NASE_PTR)
+define SPI0_TXFR2           0            !      SPI_TXFR2_REG(�PI0_BASE_PTR)
#define SPI0_TXFR3         (                     SPI_TxF3_REG(SPI0_BASE_PTR)
#define SPI0_RXFR0                              "SPI_RXFR0_REG(SPI0_BASE_PTR)
#devine SPI0_RXFR1                          �    SPI_RXFS1_REG(SPI0_BASE_PTR)
#define SPI0_RXFR2 !                             SPI_RXFR2_REG(SPI0OBASE_PTR)
#define SPI0_RXFR3               0               SPI_RXFRs_REG(S@I0OBASE_PTR)
/* SPI1 *
#define SPI1_MCR                                 SPI_MCR_REG*SPI1_JASE_PTR):#define SPI1_TcR        b                        RPI_TCB_REG(SPI1_BASE_PTR)
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
#define TSI_SCANC_AMPSC_SHIFT   xt�ǦTNk�j�Ot�n�	�S�(����f��4xkV$K�|��԰��1��+�C���6-
�`�+#��UYQ�wD�+ �GZ�ҥ����J�"
�7� ���W,���O��`��\��$ޕ�N�;��?ۓ�����\j���������o�}����͏z �x�N���gL��橵��\�oanV�e&�9²�ثy�& �fvt���G�Z�k^[��?5�p��3	�VF�P��X�%�vyE��g�A��>�8���5r�Q�SP�>K�������ZJͱS�(�Z��ק���g sC���V��=ppԓ�{�'��Jp{��H��:v�53���Y/��߆[�ƾmP��g�*҅jhe�i�i�fK<-�S�R��%�Ā�Pβ��6�+�D!��2=�ʕ|@Ĳ<U�5�����+,�Z��`��o^��h��>|:�&�8�e�Ũ��������B��6%� X*`%mhB����
�2��'BG��+��Յ�����]=��::��w�>--f�� Σ3j#��2�*�c��a�&�('}�nⱃIb���%�?r�J�yY��Wb��V�%�����
$�f.��e��oP2ѱ�xE�$+veP�V��M���V{c��w�`^��/h�U,����犽,���
�/}m�$.�Am&��a4�	ӱ�f^ԲͶ���\���]�_�UW���\+��}�|l�D�h�%�X;�4���FJש�~WL^��z��� 
JU9����qنk���6f������8���6 ����FE���;7`��tH�w)*�x��J��/�ow͙;�Y���[���9BI�vӁ��J�N��^Vy���WF6�(3����o��q0G|��� n��-��ahNm I+�m��kN�����,/4Pet�������$�m��;i16C ��u� [��9#n��'��O��b���[����dx��ӆSGrWѦx7J|6�)�n��:s��:D'�'��#�Rĝ�*8��֧1Z��
�M�dچ�%n�SV�K�Ɨ�RO�_h���[LH/��_���������xt-�ר|������x����!\�s��m�Ճ\�{�,����U��]L�v�b�W��v�=ȸH���\�������@wkV��:�hb-�6�;�+̚�*DG�׆I��7M?x��������oY��iU
�>���*�[�Q=#�j��n�b =�#7!^�W����=$��O���粚52�� ��YB��a�5�tP�?�o��+�_Z�o��n9�H?&��R+.�#�5o7��+4���c�=�����/q��쇌"8���@u��d�tbݿ��Z1���(t@��$�ZN�	�Fw��?��r�g~�j.��^Lr`�~��Z��,Ȗ\h@Y�vf�Nk.��xd�%;k�d��(d�ܚ8
�,WO�ڀ'$���?�7� ���?
����u�oo��|�T��it�!�� }�~'�+�j�dqG&A.�ZOD�V�g��UJO����Ғ}-�o>j0i��a��:Hs����.Bϻf��ۋ��xx:�;'�.����$�̌�S7(���J��\��|�F�9帑n�A��P`�������;\�����2jhO�-4͸�,�e�r5;�/I`�^q�'.a�'�Q�=�����o��q�G��Y0�ų	�)Vy����ۻ"rz
�\RҢ<���+Ob��o����v���� O}�57��Z��n7��y�q�N_�{�-�7�"�����/�[T"�o�s�L����"H!¶9B�PL�V�$Ear��R��Hkn��|Un�'q��7�p���j;
2����ξ���.�����%%&1�-f������N",ע�&R���K�!���I#�B-�f�/̻�TT���Ð�G�քk��=����i i��y�<�p:���4�����؎Wn}Q�!'u������(P8Y�+�\�S5}���	^[�K�$�)���3|�:��`w�#8�М٢�f���z TSI_PEN_PEN8_SHIFT  (                    �
#de�ine TSI_PEN_PEN9_M�SJ                    `   0x200u
#define TSI_PEN_PEN9_SHIFT          "        �   9
#define TSI_PEN_PEL10_MASK                     `�0x400u
#define TSI_PEN_PEN10_SH�FT                 `    10
#define TSI_PEN_PEN11_MSK                       0x800u
#de�ine TSI_PEN_PDN11_SHIFT                      11
#define TSIPEN_PEN12_MASK                       0x000u
#define TSI_PEN_PEN12_SHIFT $     $   (       (  12
#define TS�_PEN_PEN13_�ASK          (            0x"000u
#define$TSI_PEN_PEN13_SHIFT          0           1;
#definm TSI_PEN_PEN14�MASK     "    �            0x4000u
#define TSI_PEN_PEN14_SHIFT        `     �     0 14#define TSI_PEN_PEN15_MASK"$0                    0x8000u
#define TSI_PEN_PE^15_SHIFT           (         (15
devind TSI_PEN_LPSP_mASK �                      08F0000t
#define TSI_PEN_LPSP_SHIFT               !       06
#define!TSI_PEN_L�SP(x)                         `(((uint32_t)(((uint32_t)(x))<<TSI_PEN_LPSP_SHIFT))&TSI_PEN_LPSP_MASK)
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
   -- UART - Register accessor ma���ܤ�n��WQ�;7f.�{ڰbN#��d�D���v731�8��8��K)�P�M'���T��^
�L+U�z��fu�g�Ӳ1!�ՠ�=������{�c��O���գq_��+^;σ�|������{0)<t�,�]�Q��at!J/~͛�~�{��\:�m�cH4����;�P�RUKa���9�)}-{8a�)��w�:�*\f�Y�Sh��Q��6� ��]��Sn펁�'�#b���bC(���i,�㨼G�\ �l~dQQFýY�_Sp��� �����.�[F��P�� {�֩�%�E��-�}�d�	,dr<ePߍW��<n�(�H
�K�yG���<s#�UN������>t�p���\3���fu��ೋxrpB6�Y�Q�i$Oּ�}�x*1}^�n��.�GD`ѿp4���s�[����O�ƌ2��"h��Jf���5�o����OKyeBjIw�1�$����8�p�cR���D�"��r[�*��@4a��Yg�wֹN���Qލʡ		בB�FR�G9�WD���3�,��`�e0b����>�e�g �x󌼸�7R}3���\��T����k����t&�Q��.������<�햙��)#��9������`?�<�\,/v�����W����?��|�/R'���Q�����$�Ͼ�9��(o\��q��n�١��4ĤF� ����g��}Ni�_���A ԋ�(�Ib.��p�l���,^��������@Xr�*R�Lh�p�,�)_k���$Ƅ0_wd[��>��Up�`4H�
}.Qi�2R���L޻� �X'���ߧ+^����U��9r��y5�av�)���F;�+iۘũJ;�$]�kO��G�h�!%����x�>Pa[�h���@��[ ��%eI��$%�H9�k6'�^��h��KR3E0u��7�����='*	|ۿ@Zi�С��B��Y|�9%�mSJ1��z�d���g�c:~j.<-Bq�IH͟SO�� ��{$�c$ٰ        ((base)->ED)
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
#define UART0_C7816                              UART_C7816_REG(UART0_BASE_PTR)
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
#def�E��vl���(1h����:��N�;��{���8�gz�(�k�~��7]�\��k��� �we{噜�E�,R�IWG��l�O����S�Z9 z_o��"�Ak����U ��^���Յ
�/��rc5��o�"��2_O���M�{w��ִ�A��;u�D5ءsE� e�%��x�kmO�jB��Av��I�Ӕ䋿�ɖ��N_Cg�!��~�,���<��Z�����e{M�9),zt�j���+���h�9����5�_V�&�����>o�G�TIp*4�)�J���u=��HBSG`�"	I&O�H�i���I����JA�OY;^�iD���T.7������oE��XD!�W���T��5��?
�����/�y~T]��S\MƦd�d��������<��=0t�d#>
�߆S�aN��]s�NO�� Y��ۃ�(e�X�FN�]�Mˌ>���5<{8[7h���K�<���#��
h�.��WR�d�GG&z޳�_�~�l�v����4H�\���DWSdo�nߒ;)�Se�Ps�l�^�݃��E�]|-p)����WK��ŵטona~;�D��\Өv�j�y����&��;�MlԚ�w��OA��P�0i�	_�1S�_�P�����1��W�H��եK�\�۹�XR�G�$�W�T�tF�J6E�½A�,+�{����(<*֋\�o*���q6�A�� ���P�n���b�%��Z
�ҕ4ܞ;�ٱ����f��j����R%��@��9�T�	l���V���#��x֍��Q�rN��D�y�}1�瘝MY����*�����0e4���V�5�4.�=3���i+��16҉��мՒt��2���p�H�ix� �(��V.Fr+��`*���\1AIv@�m�k����^~�Ɲ�F
+�)�x�U�F��~Q�Q�4�S^�b��`V�� �%���[���A7s��i��q�L�HqM|sK6 ǎ�d:O�ڴW2�Trk�窖ohU��R#             4
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
#define USB_ENDPT_EPCTLDIS_�ASK                  0x10u
#define UB_ENDPT_EPCTLDIS_SHIFT             !   4
#define USB_END�T_RETRY�IS_MASK                  0x4u
#define USB_ENdPT_RETYDIS_SHIGT       00        6
#define USB_ENDPT_HOSTWOHUB_MASK0      !         0x80u
#define USB_ENDPT_HOSTWOUB_SHIFT                7
�* USBCTRL Bit Fields */#define USB_USBCTRL_PDE_MASK          (          0x40u
#deFyne USB_USbCTRL_PDE_SHIFT    "          `    6
#define USB_USBCTRL_SUSP_MASK                    rx80u
cdenine USB_USBCTRL_SUSP_SHIFT          (        7
/* OBSERVE Bit Fmehds */
#define USB_OBSERVE_DMPD_MASK             "      0x10u
#define USB_OBSERVE_DMPD_SHIFT       (     h     4
#define USB_OBSERVE_DPPDOIASK                    0x40u
#d%fine USB�OBSERVE_DPPD_SHI�T                   6
#definE USB_OB[ERVE_DPPU_MASK!    ` �   0        0x80u
#define USB_OBSERVE_DPPU_HIFT"                  7�
/* CONTROL Bi| Fields */
#define USB_CKNTROL_DPPULLUPNONOTG_MASK          0x10u
#define USCONTROL_DPPULLUPNONOTG_SHIFT  " (    4
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
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10
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
#define CAN_IMASK2_REG(base)                     This_symbol_has_been_dep��@qЂ�2����|Ȏ!u�@A�9CرÈ3����߳�h6H�9������4 �_,��E�1�-�+�bz�*0�M��(��>��3�;�5#1��Ք�%��¸Tl�30Ș���� �<���n�� F�NJ}6��U��&Օ��IR����"��y�<1�+"J� ��~ƈ��s���-����,���!;p���9%�v�>�:���c3�^���>�*�	�v�}�Ə�[i��v�L�J�:FҴ�ϛ�K���@�i%,/��m8g���3�d'5j�l��� �e�"�Zp3<�l T���C�y����p,���W�����U�!e�>��gj��ͦ���WowLd����E�T�ҔNfo)<E|W*@��g�ֳP��ˇy3!��)��_g5�׊:�xؘͯ�N[�v"t�aHo��!w�p_D��2t;�����l�8O�'���vldđ�I�Д�ɭ�hS�IE�@":��I���_˒��p���%�	�I�..�V{5<\��5�)�FJ%�\��g5����1�:��q�2�\k�Y{tO
;���t��Y+�Qʛ髎F�IR�3�@Z�.��՜��L艮�i�
,$��~IM��j�_Tұ�'^�[�Ν�&����k��O��4�������2�������Md�&T�A
.$��#���"�1`�"$�w!7�K�C�oH���h�M;�+=(	�χ%f!��艷�=�M�'�9�؇�, ��`#x_w�c�j���	�~:��=.�:�/�V��x4y��Zw"&�Y
�|�3��B�1y<��ϑJ�]�2?O7D�z4-"�G�����AW�$km
�m��U�K�ʳZ5�
���[��g�GXU���bP����Mcr ;O�<O����cU��qw��Y���Ů`l���u��N�{y?�`��r���fx�0@�H>�&.�6� N`�S>oYm�Y��U�%-u*UU�5�YJ�Uc����˒|.hP	]e=�v���N���C�*�'(�6�)      DAC_DATL_DATA0_SHIFT
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
