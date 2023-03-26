#include "HardwareDef.h"

#ifndef _GPIO_H
#define _GPIO_H

/*input mode*/
#define GPIO_MODE_AIN ((uint32_t)0x00)
#define GPIO_MODE_IN_FLOATING ((uint32_t)0x04)
#define GPIO_MODE_IPD ((uint32_t)0x08)
#define GPIO_MODE_IPU ((uint32_t)0x08)
/*output mode*/
#define GPIO_MODE_OUT_OD ((uint32_t)0x04)
#define GPIO_MODE_OUT_PP ((uint32_t)0x00)
#define GPIO_MODE_AF_OD ((uint32_t)0x08)
#define GPIO_MODE_AF_PP ((uint32_t)0x0c)
/*speed mode*/
#define INPUT_SPEED ((uint32_t)0x00)
#define OUTPUT_SPEED_10MHz ((uint32_t)0x01)
#define OUTPUT_SPEED_2MHz ((uint32_t)0x02)
#define OUTPUT_SPEED_50MHz ((uint32_t)0x03)
/*GPIO pin*/
#define GPIO_PIN_0 ((uint16_t)0x1)
#define GPIO_PIN_1 ((uint16_t)0x2)
#define GPIO_PIN_2 ((uint16_t)0x4)
#define GPIO_PIN_3 ((uint16_t)0x8)
#define GPIO_PIN_4 ((uint16_t)0x10)
#define GPIO_PIN_5 ((uint16_t)0x20)
#define GPIO_PIN_6 ((uint16_t)0x40)
#define GPIO_PIN_7 ((uint16_t)0x80)
#define GPIO_PIN_8 ((uint16_t)0x100)
#define GPIO_PIN_9 ((uint16_t)0x200)
#define GPIO_PIN_10 ((uint16_t)0x400)
#define GPIO_PIN_11 ((uint16_t)0x800)
#define GPIO_PIN_12 ((uint16_t)0x1000)
#define GPIO_PIN_13 ((uint16_t)0x2000)
#define GPIO_PIN_14 ((uint16_t)0x4000)
#define GPIO_PIN_15 ((uint16_t)0x8000)

typedef struct GPIO_init_struct
{
	uint16_t GPIO_PIN;
	uint32_t GPIO_MODE;
	uint32_t SPEED_MODE;
} GPIO_init_struct;

void GPIO_init(GPIO_TypeDef *GPIOx,GPIO_init_struct *init_struct);
void GPIO_setBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN);
void GPIO_resetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN);
uint8_t GPIO_readOUTDataBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN);
uint16_t GPIO_readOUTData(GPIO_TypeDef *GPIOx);
uint8_t GPIO_readINDataBit(GPIO_TypeDef *GPIOx,uint16_t GPIO_PIN);
uint16_t GPIO_readINData(GPIO_TypeDef *GPIOx);
void GPIO_write(GPIO_TypeDef *GPIOx,uint16_t val);
#endif
