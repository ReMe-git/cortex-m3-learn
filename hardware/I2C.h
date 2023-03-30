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
/*Address Direction*/
#define I2C_ADDRESS_READ ((uint8_t)0x0000)
#define I2C_ADDRESS_SEND ((uint8_t)0x0001)

typedef struct I2C_init_st
{
  uint32_t I2C_CLK_SPEED;
  uint16_t I2C_MODE;
  uint16_t I2C_FAST_DUTY;
  uint16_t I2C_OWN_ADDRESS1;
  uint16_t I2C_ACK;
  uint16_t I2C_ACK_ADDRESS;
} I2C_init_st;

err_t I2C_init(I2C_TypeDef *I2Cx,I2C_init_st *init_st);
void I2C_cmd(I2C_TypeDef *I2Cx,uint8_t state);
void I2C_start(I2C_TypeDef *I2Cx,uint8_t state);
void I2C_stop(I2C_TypeDef *I2Cx,uint8_t state);
void I2C_ack(I2C_TypeDef *I2Cx,uint8_t state);
void I2C_sendData(I2C_TypeDef *I2Cx,uint8_t data);
void I2C_sendAddress(I2C_TypeDef *I2Cx,uint8_t address,uint8_t direction);
uint8_t I2C_readData(I2C_TypeDef *I2Cx);
#endif
