#include "HardwareDef.h"
#include "delay.h"

#define HSE_STARTUP_TIMEOUT ((uint32_t)0x000003e8)
#define RCC_CR_HSEON ((uint32_t)0x00010000)
#define RCC_CR_HSERDY ((uint32_t)0x00020000)
#define FLASH_ACR_PRFTBE ((uint32_t)0x00000010)
#define FLASH_ACR_LATENCY ((uint32_t)0x00000007)
#define FLASH_ACR_LATENCY_2 ((uint32_t)0x00000002)
#define RCC_CFGR_HPRE_DIV1 ((uint32_t)0x00000080)
#define RCC_CFGR_PPRE2_DIV1 ((uint32_t)0x00000500)
#define RCC_CFGR_PPRE1_DIV2 ((uint32_t)0x00002000)
#define RCC_CFGR_PLLSRC ((uint32_t)0x00010000)
#define RCC_CFGR_PLLSRC_HSE ((uint32_t)0x00010000)
#define RCC_CFGR_PLLXTPRE ((uint32_t)0x00020000)
#define RCC_CFGR_PLLMULL ((uint32_t)0x003c0000)
#define RCC_CFGR_PLLMULL9 ((uint32_t)0x001c0000)
#define RCC_CR_PLLON ((uint32_t)0x01000000)
#define RCC_CR_PLLRDY ((uint32_t)0x02000000)
#define RCC_CFGR_SW ((uint32_t)0x00000003)
#define RCC_CFGR_SW_PLL ((uint32_t)0x00000002)
#define RCC_CFGR_SWS ((uint32_t)0x00000008)

extern void Exit(void);
void systemclk_set(void);

void system_init(void)
{
//RCC寄存器的初始化
  RCC->CR |= (uint32_t)0x00000001;
  RCC->CFGR &= (uint32_t)0xF0FF0000;
  RCC->CR &= (uint32_t)0xFEF6FFFF;
  RCC->CR &= (uint32_t)0xFFFBFFFF;
  RCC->CFGR &= (uint32_t)0xFF80FFFF;
  RCC->CIR = 0x009F0000;
//设置系统时钟
  systemclk_set();
}

/*系统时钟频率为72MHz*/
void systemclk_set(void)
{
  uint32_t count= 0;
  uint32_t state= 0;
//启动外部高速时钟(HSE)
  RCC->CR|= (RCC_CR_HSEON);
//等待启动
  do{
    state= RCC->CR& RCC_CR_HSERDY;
    count++;  
  } while((state== 0)&& (count!= HSE_STARTUP_TIMEOUT));
//检查HSE是否启动成功
  if ((RCC->CR& RCC_CR_HSERDY)!= (uint32_t)0x0)
  {
    state= (uint32_t)0x01;
  }
  else
  {
    state= (uint32_t)0x00;
  }  
//启动成功
  if (state== (uint32_t)0x01)
  {
//启用flash的预取缓冲区
    FLASH->ACR|= FLASH_ACR_PRFTBE;
//设置缓冲区时延在48MHz~72MHz
    FLASH->ACR&= (uint32_t)(~FLASH_ACR_LATENCY);
    FLASH->ACR|= FLASH_ACR_LATENCY_2;    
//设置AHB总线为2分频
    RCC->CFGR|= RCC_CFGR_HPRE_DIV1;
//设置APB2总线为2分频
    RCC->CFGR|= RCC_CFGR_PPRE2_DIV1;
//设置APB1总线为4分频
    RCC->CFGR|= RCC_CFGR_PPRE1_DIV2;
//清空CFGR寄存器的PLLSRC,PLLXTPRE,PLLMULL
    RCC->CFGR&= (uint32_t)(~(RCC_CFGR_PLLSRC| RCC_CFGR_PLLXTPRE| RCC_CFGR_PLLMULL));
//设置PLL时钟源为外部高速时钟,设置倍频器为9倍频
    RCC->CFGR|= (RCC_CFGR_PLLSRC_HSE| RCC_CFGR_PLLMULL9);
//使能PLL时钟
    RCC->CR|= RCC_CR_PLLON;
//等待PLL使能
    while((RCC->CR& RCC_CR_PLLRDY)== 0)
    {
    }
//清空CFGR的SW,并设置PLL为系统时钟
    RCC->CFGR&= (uint32_t)(~(RCC_CFGR_SW));
    RCC->CFGR|= RCC_CFGR_SW_PLL;    
//等待设置PLL为系统时钟
    while ((RCC->CFGR& RCC_CFGR_SWS)!= (uint32_t)0x08)
    {
    }
  }
//如果无法启动HSE时钟则进入推出函数
  else
  {
    Exit();
  }
}
