#include "HardwareDef.h"
/*总线时钟频率结构体*/
typedef struct clock_freq_st
{
	uint32_t SYSCLOCK_FREQ;
	uint32_t AHB_PRES;
	uint32_t APB1_PRES;
	uint32_t APB2_PRES;
	uint32_t ADC_PRES;
} clock_freq_st;

//查看系统时钟源
uint32_t rcc_SYSCLK_src(void)
{
	return (uint32_t)(RCC->CFGR& ((uint32_t)0x0000000c));
}

//查看各总线频率
void rcc_CLOCKS_freq(clock_freq_st *clocks)
{
	clocks->SYSCLOCK_FREQ= (uint32_t)(RCC->CFGR& ((uint32_t)0x00ff000f));
	clocks->AHB_PRES= (uint32_t)(RCC->CFGR& ((uint32_t)0x000000f0));
	clocks->APB1_PRES= (uint32_t)(RCC->CFGR& ((uint32_t)0x00000700));
	clocks->APB2_PRES= (uint32_t)(RCC->CFGR& ((uint32_t)0x00003800));
	clocks->ADC_PRES= (uint32_t)(RCC->CFGR& ((uint32_t)0x0000c000));
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
