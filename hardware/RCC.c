#include "HardwareDef.h"

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

/*总线时钟频率结构体*/
typedef struct clock_freq_st
{
	uint32_t SYSCLK_FREQ;
	uint32_t AHB_FREQ;
	uint32_t APB1_FREQ;
	uint32_t APB2_FREQ;
	uint32_t ADC_FREQ;
} clock_freq_st;

//查看系统时钟源
uint32_t rcc_SYSCLK_src(void)
{
	return (uint32_t)(RCC->CFGR& ((uint32_t)0x0000000c));
}

//查看各总线频率
void rcc_CLOCKS_freq(clock_freq_st *clocks)
{
	switch((uint32_t)(RCC->CFGR& ((uint32_t)0x00ff000f)))
  {
    case SYSCLK_HSI_8MHz:
      clocks->SYSCLK_FREQ= 8000000;
      break;
    case SYSCLK_HSE_8MHz:
      clocks->SYSCLK_FREQ= 8000000;
      break;
    case SYSCLK_PLL_HSI_8MHz:
      clocks->SYSCLK_FREQ= 8000000;
      break;
    case SYSCLK_PLL_HSE_8MHz:
      clocks->SYSCLK_FREQ= 8000000;
      break;
    case SYSCLK_PLL_HSE_16MHz:
      clocks->SYSCLK_FREQ= 16000000;
      break;
    case SYSCLK_PLL_HSE_24MHz:
      clocks->SYSCLK_FREQ= 24000000;
      break;
    case SYSCLK_PLL_HSE_48MHz:
      clocks->SYSCLK_FREQ= 48000000;
      break;
    case SYSCLK_PLL_HSE_56MHz:
      clocks->SYSCLK_FREQ= 56000000;
      break;
    case SYSCLK_PLL_HSE_72MHz:
      clocks->SYSCLK_FREQ= 72000000;
      break;
    Deafult:
      clocks->SYSCLK_FREQ= 0;
      break;
  }
#define AHB_PRES_NONE ((uint32_t)0x00000000)
#define AHB_PRES_2 ((uint32_t)0x00000080)
#define AHB_PRES_4 ((uint32_t)0x00000090)
#define AHB_PRES_8 ((uint32_t)0x000000a0)
#define AHB_PRES_16 ((uint32_t)0x000000b0)
#define AHB_PRES_64 ((uint32_t)0x000000c0)
#define AHB_PRES_128 ((uint32_t)0x000000d0)
#define AHB_PRES_256 ((uint32_t)0x000000e0)
#define AHB_PRES_512 ((uint32_t)0x000000f0)
/*AHB*/
  switch((uint32_t)(RCC->CFGR& ((uint32_t)0x000000f0)))
  {
		case AHB_PRES_NONE:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ;
			break;
		case AHB_PRES_2:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 2;
			break;
		case AHB_PRES_4:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 4;
			break;
		case AHB_PRES_8:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 8;
			break;
		case AHB_PRES_16:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 16;
			break;
		case AHB_PRES_64:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 64;
			break;
		case AHB_PRES_128:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 128;
			break;
		case AHB_PRES_256:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 256;
			break;
		case AHB_PRES_512:
			clocks->AHB_FREQ= clocks->SYSCLK_FREQ/ 512;
			break;
	}
/*APB1*/
  switch((uint32_t)(RCC->CFGR& ((uint32_t)0x00000700)))
  {
		case APB1_PRES_NONE:
			clocks->APB1_FREQ= clocks->SYSCLK_FREQ;
			break;
		case APB1_PRES_2:
			clocks->APB1_FREQ= clocks->SYSCLK_FREQ/ 2;
			break;
		case APB1_PRES_4:
			clocks->APB1_FREQ= clocks->SYSCLK_FREQ/ 4;
			break;
		case APB1_PRES_8:
			clocks->APB1_FREQ= clocks->SYSCLK_FREQ/ 8;
			break;
		case APB1_PRES_16:
			clocks->APB1_FREQ= clocks->SYSCLK_FREQ/ 16;
			break;
	}
/*APB2*/
  switch((uint32_t)(RCC->CFGR& ((uint32_t)0x00003800)))
  {
		case APB2_PRES_NONE:
			clocks->APB2_FREQ= clocks->SYSCLK_FREQ;
			break;
		case APB2_PRES_2:
			clocks->APB2_FREQ= clocks->SYSCLK_FREQ/ 2;
			break;
		case APB2_PRES_4:
			clocks->APB2_FREQ= clocks->SYSCLK_FREQ/ 4;
			break;
		case APB2_PRES_8:
			clocks->APB2_FREQ= clocks->SYSCLK_FREQ/ 8;
			break;
		case APB2_PRES_16:
			clocks->APB2_FREQ= clocks->SYSCLK_FREQ/ 16;
			break;
  }
/*ADC*/
	switch((uint32_t)(RCC->CFGR& ((uint32_t)0x0000c000)))
	{
		case ADC_PRES_2:
			clocks->ADC_FREQ= clocks->SYSCLK_FREQ/ 2;
			break;
		case ADC_PRES_4:
			clocks->ADC_FREQ= clocks->SYSCLK_FREQ/ 4;
			break;
		case ADC_PRES_6:
			clocks->ADC_FREQ= clocks->SYSCLK_FREQ/ 6;
			break;
		case ADC_PRES_8:
			clocks->ADC_FREQ= clocks->SYSCLK_FREQ/ 8;
			break;	
	}
}

//APB1总线时钟配置
void rcc_APB1CLK_conf(uint32_t clock,bool_t state)
{
  if(state== disable)
  {
    RCC->APB1ENR&= ~clock;
  }
  else
  {
  RCC->APB1ENR|= clock;
  }
}
//APB2总线时钟配置
void rcc_APB2CLK_conf(uint32_t clock,bool_t state)
{
  if(state== disable)
  {
    RCC->APB2ENR&= ~clock;
  }
  else
  {
    RCC->APB2ENR|= clock;
  }
}
