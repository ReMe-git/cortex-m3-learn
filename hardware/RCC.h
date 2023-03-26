#include "HardwareDef.h"
#ifndef _RCC_H
#define _RCC_H

/*系统时钟源*/
#define SYSCLK_HSI ((uint32_t)0x00000000)
#define SYSCLK_HSE ((uint32_t)0x00000004)
#define SYSCLK_PLL ((uint32_t)0x00000008)
/*时钟频率*/
#define SYSCLK_HSI_8MHz ((uint32_t)0x00000000)
#define SYSCLK_HSE_8MHz ((uint32_t)0x00000004)
#define SYSCLK_PLL_HSI_8MHz ((uint32_t)0x00000008)
#define SYSCLK_PLL_HSE_8MHz ((uint32_t)0x00030008)
#define SYSCLK_PLL_HSE_16MHz ((uint32_t)0x00010008)
#define SYSCLK_PLL_HSE_24MHz ((uint32_t)0x00050008)
#define SYSCLK_PLL_HSE_48MHz ((uint32_t)0x00110008)
#define SYSCLK_PLL_HSE_56MHz ((uint32_t)0x00150008)
#define SYSCLK_PLL_HSE_72MHz ((uint32_t)0x001d0008)
/*ADC分频*/
#define ADC_PRES_2 ((uint32_t)0x00000000)
#define ADC_PRES_4 ((uint32_t)0x00004000)
#define ADC_PRES_6 ((uint32_t)0x00008000)
#define ADC_PRES_8 ((uint32_t)0x0000c000)
/*APB2分频*/
#define APB2_PRES_NONE ((uint32_t)0x00000000)
#define APB2_PRES_2 ((uint32_t)0x00002000)
#define APB2_PRES_4 ((uint32_t)0x00002800)
#define APB2_PRES_8 ((uint32_t)0x00003000)
#define APB2_PRES_16 ((uint32_t)0x00003800)
/*APB1分频*/
#define APB1_PRES_NONE ((uint32_t)0x00000000)
#define APB1_PRES_2 ((uint32_t)0x00000400)
#define APB1_PRES_4 ((uint32_t)0x00000500)
#define APB1_PRES_8 ((uint32_t)0x00000600)
#define APB1_PRES_16 ((uint32_t)0x00000700)
/*AHB分频*/
#define AHB_PRES_NONE ((uint32_t)0x00000000)
#define AHB_PRES_2 ((uint32_t)0x00000080)
#define AHB_PRES_4 ((uint32_t)0x00000090)
#define AHB_PRES_8 ((uint32_t)0x000000a0)
#define AHB_PRES_16 ((uint32_t)0x000000b0)
#define AHB_PRES_64 ((uint32_t)0x000000c0)
#define AHB_PRES_128 ((uint32_t)0x000000d0)
#define AHB_PRES_256 ((uint32_t)0x000000e0)
#define AHB_PRES_512 ((uint32_t)0x000000f0)
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
	uint32_t SYSCLOCK_FREQ;
	uint32_t AHB_PRES;
	uint32_t APB1_PRES;
	uint32_t APB2_PRES;
	uint32_t ADC_PRES;
} clock_freq_st;

uint32_t rcc_SYSCLK_src(void);
void rcc_CLOCKS_freq(clock_freq_st *clocks);
void rcc_APB1CLK_conf(uint32_t clock,bool_t state);
void rcc_APB2CLK_conf(uint32_t clock,bool_t state);
#endif
