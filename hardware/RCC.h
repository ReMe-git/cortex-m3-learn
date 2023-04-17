#include "HardwareDef.h"
#ifndef _RCC_H
#define _RCC_H

/*系统时钟源*/
#define SYSCLK_HSI ((uint32_t)0x00000000)
#define SYSCLK_HSE ((uint32_t)0x00000004)
#define SYSCLK_PLL ((uint32_t)0x00000008)
/*APB1时钟*/
#define APB1_TIM2 ((uint32_t)0x00000001)
#define APB1_TIM3 ((uint32_t)0x00000002)
#define APB1_TIM4 ((uint32_t)0x00000004)
#define APB1_TIM5 ((uint32_t)0x00000008)
#define APB1_TIM6 ((uint32_t)0x00000010)
#define APB1_TIM7 ((uint32_t)0x00000020)
#define APB1_TIM8 ((uint32_t)0x00000040)
#define APB1_SPI2 ((uint32_t)0x00004000)
#define APB1_SPI3 ((uint32_t)0x00008000)
#define APB1_USART2 ((uint32_t)0x00020000)
#define APB1_USART3 ((uint32_t)0x00040000)
#define APB1_UART4 ((uint32_t)0x00080000)
#define APB1_UART5 ((uint32_t)0x00100000)
#define APB1_I2C1 ((uint32_t)0x00200000)
#define APB1_I2C2 ((uint32_t)0x00400000)
/*APB2时钟*/
#define APB2_AFIO ((uint32_t)0x00000001)
#define APB2_GPIOA ((uint32_t)0x00000004)
#define APB2_GPIOB ((uint32_t)0x00000008)
#define APB2_GPIOC ((uint32_t)0x00000010)
#define APB2_GPIOD ((uint32_t)0x00000020)
#define APB2_GPIOE ((uint32_t)0x00000040)
#define APB2_TIM1 ((uint32_t)0x00000800)
#define APB2_SPI1 ((uint32_t)0x00001000)
#define APB2_USART1 ((uint32_t)0x00004000)
/*总线时钟频率结构体*/
typedef struct clock_freq_st
{
	uint32_t SYSCLK_FREQ;
	uint32_t AHB_FREQ;
	uint32_t APB1_FREQ;
	uint32_t APB2_FREQ;
	uint32_t ADC_FREQ;
} clock_freq_st;

uint32_t RCC_sysclkSrc(void);
void RCC_clocksFreq(clock_freq_st *clocks);
void RCC_apb1Conf(uint32_t clock,uint8_t state);
void RCC_apb2Conf(uint32_t clock,uint8_t state);
#endif
