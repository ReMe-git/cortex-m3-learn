#include "HardwareDef.h"

#ifndef _I2C_H
#define _I2C_H

typedef struct I2C_init_st
{
  uint32_t I2C_CLK_SPEED;
  uint16_t I2C_MODE;
  uint16_t I2C_FAST_DUTY;
  uint16_t I2C_OWN_ADDRSS1;
  uint16_t I2C_ACK;
  uint16_t I2C_ACK_ADDRESS;
} I2C_init_st;

void I2C_init(I2C_TypeDef *I2Cx,I2C_init_st *init_st);
#endif
