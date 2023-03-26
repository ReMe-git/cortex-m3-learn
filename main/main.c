#include "main.h"

int main(void)
{
  GPIO_init_struct gpio_struct;
  gpio_struct.GPIO_PIN= GPIO_PIN_13;
  gpio_struct.GPIO_MODE= GPIO_MODE_OUT_PP;
  gpio_struct.SPEED_MODE= OUTPUT_SPEED_50MHz;

  rcc_APB2CLK_conf(APB2_GPIOC,enable);	
  
  GPIO_init(GPIOC,&gpio_struct);
  GPIO_setBits(GPIOC,GPIO_PIN_13);

  while(1)
	{
    GPIO_resetBits(GPIOC,GPIO_PIN_13);
    delay_ms(500);
    GPIO_setBits(GPIOC,GPIO_PIN_13);
    delay_ms(500);
	}

  return 0;
}
