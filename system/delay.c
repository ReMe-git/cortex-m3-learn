#include "core_m3.h"

void delay_us(uint32_t delay_us)
{
  uint32_t count= 0x00;
  for(;delay_us> 0;delay_us--)
  {
    for(;count< 300;count++);
  }
}

void delay_ms(uint32_t delay_ms)
{
  for(;delay_ms> 0;delay_ms--)
  {
    delay_us(1000);
  }
}
