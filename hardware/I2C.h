#include "HardwareDef.h"

#ifndef _I2C_H
#define _I2C_H

/*I2C_MODE*/
#define I2C_MODE_DEFAULT ((uint16_t)0x0000)
/*FAST_DUTY*/
#define I2C_FAST_DUTY_0 ((uint16_t)0x8000)
#define I2C_FAST_DUTY_1 ((uint16_t)0xc000)
/*I2C_ACK*/
#define I2C_ACK_Y ((uint16_t)0x0400)
#define I2C_ACK_N ((uint16_t)0x0000)

typedef struct I2C_init_st
{
  uint32_t I2C_CLK_SPEED;
  uint16_t I2C_MODE;
  uint16_t I2C_FAST_DUTY;
  uint16_t I2C_OWN_ADDRSS1;
  uint16_t I2C_ACK;
  uint16_t I2C_ACK_ADDRESS;
} I2C_init_st;

err_t I2C_init(I2C_TypeDef *I2Cx,I2C_init_st *init_st);
void I2C_enable(I2C_TypeDef *I2Cx,uint8_t state);
#endif
