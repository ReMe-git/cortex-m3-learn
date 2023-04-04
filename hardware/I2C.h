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
#define I2C_ADDRESS_READ ((uint8_t)0x0001)
#define I2C_ADDRESS_SEND ((uint8_t)0x0000)
/*Address Type*/
#define I2C_ACK_ADDRESS_7BIT ((uint16_t)0x0000)
#define I2C_ACK_ADDRESS_10BIT ((uint16_t)0x8000)


/*MASTER MODE EVENT*/
#define  I2C_EVENT_MASTER_MODE_SELECT                      ((uint32_t)0x00030001)  /* BUSY, MSL and SB flag */
#define  I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED        ((uint32_t)0x00070082)  /* BUSY, MSL, ADDR, TXE and TRA flags */
#define  I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED           ((uint32_t)0x00030002)  /* BUSY, MSL and ADDR flags */
#define  I2C_EVENT_MASTER_MODE_ADDRESS10                   ((uint32_t)0x00030008)  /* BUSY, MSL and ADD10 flags */
#define  I2C_EVENT_MASTER_BYTE_RECEIVED                    ((uint32_t)0x00030040)  /* BUSY, MSL and RXNE flags */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTING                 ((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */
#define  I2C_EVENT_MASTER_BYTE_TRANSMITTED                 ((uint32_t)0x00070084)  /* TRA, BUSY, MSL, TXE and BTF flags */
/*SLAVE MODE EVENT*/
#define  I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED          ((uint32_t)0x00020002) /* BUSY and ADDR flags */
#define  I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED       ((uint32_t)0x00060082) /* TRA, BUSY, TXE and ADDR flags */
#define  I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED    ((uint32_t)0x00820000)  /* DUALF and BUSY flags */
#define  I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED ((uint32_t)0x00860080)  /* DUALF, TRA, BUSY and TXE flags */
#define  I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED        ((uint32_t)0x00120000)  /* GENCALL and BUSY flags */
#define  I2C_EVENT_SLAVE_BYTE_RECEIVED                     ((uint32_t)0x00020040)  /* BUSY and RXNE flags */
#define  I2C_EVENT_SLAVE_STOP_DETECTED                     ((uint32_t)0x00000010)  /* STOPF flag */
#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTED                  ((uint32_t)0x00060084)  /* TRA, BUSY, TXE and BTF flags */
#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTING                 ((uint32_t)0x00060080)  /* TRA, BUSY and TXE flags */
#define  I2C_EVENT_SLAVE_ACK_FAILURE                       ((uint32_t)0x00000400)  /* AF flag */

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
void I2C_sendByte(I2C_TypeDef *I2Cx,uint8_t byte);
void I2C_sendAddress(I2C_TypeDef *I2Cx,uint8_t address,uint8_t direction);
uint8_t I2C_readByte(I2C_TypeDef *I2Cx);
uint8_t I2C_checkEvent(I2C_TypeDef *I2Cx,uint32_t event);
#endif
