#include "core_m3.h"
#include "errDef.h"

#ifndef _HARDWARE_H
#define _HARDWARE_H

typedef struct
{
    uint16_t CR1;
  uint16_t  RESERVED0;
    uint16_t CR2;
  uint16_t  RESERVED1;
    uint16_t SMCR;
  uint16_t  RESERVED2;
    uint16_t DIER;
  uint16_t  RESERVED3;
    uint16_t SR;
  uint16_t  RESERVED4;
    uint16_t EGR;
  uint16_t  RESERVED5;
    uint16_t CCMR1;
  uint16_t  RESERVED6;
    uint16_t CCMR2;
  uint16_t  RESERVED7;
    uint16_t CCER;
  uint16_t  RESERVED8;
    uint16_t CNT;
  uint16_t  RESERVED9;
    uint16_t PSC;
  uint16_t  RESERVED10;
    uint16_t ARR;
  uint16_t  RESERVED11;
    uint16_t RCR;
  uint16_t  RESERVED12;
    uint16_t CCR1;
  uint16_t  RESERVED13;
    uint16_t CCR2;
  uint16_t  RESERVED14;
    uint16_t CCR3;
  uint16_t  RESERVED15;
    uint16_t CCR4;
  uint16_t  RESERVED16;
    uint16_t BDTR;
  uint16_t  RESERVED17;
    uint16_t DCR;
  uint16_t  RESERVED18;
    uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;

typedef struct
{
    uint16_t CR1;
  uint16_t  RESERVED0;
    uint16_t CR2;
  uint16_t  RESERVED1;
    uint16_t SR;
  uint16_t  RESERVED2;
    uint16_t DR;
  uint16_t  RESERVED3;
    uint16_t CRCPR;
  uint16_t  RESERVED4;
    uint16_t RXCRCR;
  uint16_t  RESERVED5;
    uint16_t TXCRCR;
  uint16_t  RESERVED6;
    uint16_t I2SCFGR;
  uint16_t  RESERVED7;
    uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;

typedef struct
{
    uint16_t SR;
  uint16_t  RESERVED0;
    uint16_t DR;
  uint16_t  RESERVED1;
    uint16_t BRR;
  uint16_t  RESERVED2;
    uint16_t CR1;
  uint16_t  RESERVED3;
    uint16_t CR2;
  uint16_t  RESERVED4;
    uint16_t CR3;
  uint16_t  RESERVED5;
    uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;

typedef struct
{
    uint16_t CR1;
  uint16_t  RESERVED0;
    uint16_t CR2;
  uint16_t  RESERVED1;
    uint16_t OAR1;
  uint16_t  RESERVED2;
    uint16_t OAR2;
  uint16_t  RESERVED3;
    uint16_t DR;
  uint16_t  RESERVED4;
    uint16_t SR1;
  uint16_t  RESERVED5;
    uint16_t SR2;
  uint16_t  RESERVED6;
    uint16_t CCR;
  uint16_t  RESERVED7;
    uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;

typedef struct
{
    uint32_t EVCR;
    uint32_t MAPR;
    uint32_t EXTICR[4];
  uint32_t RESERVED0;
    uint32_t MAPR2;  
} AFIO_TypeDef;

typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
} RCC_TypeDef;

typedef struct
{
  uint16_t CRH;
  uint16_t  RESERVED0;
  uint16_t CRL;
  uint16_t  RESERVED1;
  uint16_t PRLH;
  uint16_t  RESERVED2;
  uint16_t PRLL;
  uint16_t  RESERVED3;
  uint16_t DIVH;
  uint16_t  RESERVED4;
  uint16_t DIVL;
  uint16_t  RESERVED5;
  uint16_t CNTH;
  uint16_t  RESERVED6;
  uint16_t CNTL;
  uint16_t  RESERVED7;
  uint16_t ALRH;
  uint16_t  RESERVED8;
  uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;

/*APB1*/
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800)
#define TIM12               ((TIM_TypeDef *) TIM12_BASE)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00)
#define TIM13               ((TIM_TypeDef *) TIM13_BASE)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000)
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART4               ((USART_TypeDef *) UART4_BASE)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define UART5               ((USART_TypeDef *) UART5_BASE)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
/*APB2*/
#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define AFIO                ((AFIO_TypeDef *) AFIO_BASE)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
#define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x4000)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x4400)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x4800)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4C00)
#define TIM9                ((TIM_TypeDef *) TIM9_BASE)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x5000)
#define TIM10               ((TIM_TypeDef *) TIM10_BASE)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x5400)
#define TIM11               ((TIM_TypeDef *) TIM11_BASE)
/*AHB*/
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)

#endif
