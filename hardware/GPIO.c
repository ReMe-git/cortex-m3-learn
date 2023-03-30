#include "HardwareDef.h"
/*GPIO初始化结构体*/
typedef struct GPIO_init_st
{
	uint16_t GPIO_PIN;
	uint32_t GPIO_MODE;
	uint32_t SPEED_MODE;
} GPIO_init_st;

void GPIO_init(GPIO_TypeDef *GPIOx,GPIO_init_st *init_st)
{
	uint32_t mode_conf= init_st->GPIO_MODE| init_st->SPEED_MODE;
	uint16_t pin_conf= init_st->GPIO_PIN;
	uint8_t pin_count= 0x00;
//配置低位寄存器CRL
	if((pin_conf|0xff00)!= 0xff00)
	{
		for(;pin_count< 0x08;pin_count++)
		{
			mode_conf= (mode_conf<< 4);
			pin_conf= (pin_conf>> 1);

			if((pin_conf|0xfffe)== 0xffff)
			{
				GPIOx->CRL|= mode_conf;
			}
		}
	}
//配置高位寄存器CRH
	pin_count= 0x00;
	mode_conf= init_st->GPIO_MODE|init_st->SPEED_MODE;
	pin_conf= (init_st->GPIO_PIN>> 8);

	if((pin_conf|0xff00)!= 0xff00)
	{
		for(;pin_count< 0x08;pin_count++)
		{
			mode_conf= (mode_conf<< 4);
			pin_conf= (pin_conf>> 1);

			if((pin_conf|0xfffe)== 0xffff)
			{
				GPIOx->CRH|= mode_conf;
			}
		}
	}

}
//使GPIO对应Pin置1
void GPIO_setBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN)
{
	GPIOx->BSRR|= GPIO_PIN;
}

//使GPIO对应Pin置0
void GPIO_resetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN)
{
	GPIOx->BRR|= GPIO_PIN;
}

//读取对应Pin的输出值
uint8_t GPIO_readOUTDataBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN)
{
	if(GPIOx->ODR& GPIO_PIN== GPIO_PIN)
	{
		return (uint8_t)0x01;
	}
	else
	{
		return (uint8_t)0x00;
	}
}

//读取对应GPIO的输出值
uint8_t GPIO_readINDataBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN)
{
	if(GPIOx->IDR& GPIO_PIN== GPIO_PIN)
	{
		return (uint8_t)0x01;
	}
	else
	{
		return (uint8_t)0x00;
	}
}

//读取对应Pin的输入值
uint16_t GPIO_readOUTData(GPIO_TypeDef *GPIOx)
{
  return (uint16_t)(GPIOx->ODR);
}

//读取对应GPIO的输入值
uint16_t GPIO_readINData(GPIO_TypeDef *GPIOx)
{
  return (uint16_t)(GPIOx->IDR);
}

//向对应GPIO写入val值
void GPIO_write(GPIO_TypeDef *GPIOx,uint16_t val)
{
  GPIOx->ODR= val;
}
