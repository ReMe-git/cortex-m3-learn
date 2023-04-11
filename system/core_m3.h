#ifndef _CORE_M3_H
#define _CORE_M3_H

#define int32_t int
#define uint32_t unsigned int
#define int16_t short
#define uint16_t unsigned short
#define int8_t char
#define uint8_t unsigned char
#define bool_t uint8_t


#define false 0
#define true !false
#define disable 0
#define enable !disable
#define NULL 0

/*base address*/
#define PERIPH_BASE ((uint32_t)0x40000000)
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
/*
typedef struct
{
  uint32_t CR;
  uint32_t CSR;
} PWR_TypeDef;
*/

typedef struct
{
  uint32_t ACR;
  uint32_t KEYR;
  uint32_t OPTKEYR;
  uint32_t SR;
  uint32_t CR;
  uint32_t AR;
  uint32_t RESERVED;
  uint32_t OBR;
  uint32_t WRPR;
} FLASH_TypeDef;

//#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
//#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

#endif
