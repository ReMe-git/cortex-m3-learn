#ifndef _SPI_H
#define _SPI_H

//SPI_MODE
#define SPI_MODE_SLAVE ((uint16_t)0x0000)
#define SPI_MODE_MASTER ((uint16_t)0x0104)
//SPI_DIRECTION
#define SPI_DIRECTION_2L_FULL ((uint16_t)0x0000)
#define SPI_DIRECTION_2L_RD ((uint16_t)0x0400)
#define SPI_DIRECTION_1L_RX ((uint16_t)0x8000)
#define SPI_DIRECTION_1L_TX ((uint16_t)0xc000)
//SPI_DATAFPS
#define SPI_DATAFPS_8BITS ((uint16_t)0x0000)
#define SPI_DATAFPS_16BITS ((uint16_t)0x0800)
//SPI_CPOL
#define SPI_CPOL_LOW ((uint16_t)0x0000)
#define SPI_CPOL_HIGH ((uint16_t)0x0002)
//SPI_CPHA
#define SPI_CPHA_1EDGE ((uint16_t)0x0000)
#define SPI_CPHA_2EDGE ((uint16_t)0x0001)
//SPI_FIRST
#define SPI_FIRST_MSB ((uint16_t)0x0000)
#define SPI_FIRST_LSB ((uint16_t)0x0080)
//SPI_NSS
#define SPI_NSS_HARD ((uint16_t)0x0000)
#define SPI_NSS_SOFT ((uint16_t)0x0200)
//SPI_BAUDPRE
#define SPI_BAUDPRE_2 ((uint16_t)0x0000)
#define SPI_BAUDPRE_4 ((uint16_t)0x0008)
#define SPI_BAUDPRE_8 ((uint16_t)0x0010)
#define SPI_BAUDPRE_16 ((uint16_t)0x0018)
#define SPI_BAUDPRE_32 ((uint16_t)0x0020)
#define SPI_BAUDPRE_64 ((uint16_t)0x0028)
#define SPI_BAUDPRE_128 ((uint16_t)0x0030)
#define SPI_BAUDPRE_256 ((uint16_t)0x0038)
//SPI_SIGNS
#define SPI_SIGN_SBY ((uint16_t)0x0080)
#define SPI_SIGN_OVR ((uint16_t)0x0040)
#define SPI_SIGN_MODF ((uint16_t)0x0020)
#define SPI_SIGN_CRCERR ((uint16_t)0x0010)
#define SPI_SIGN_UDR ((uint16_t)0x0008)
#define SPI_SIGN_TXE ((uint16_t)0x0002)
#define SPI_SIGN_RXNE ((uint16_t)0x0001)

typedef struct SPI_init_st{
  uint16_t SPI_MODE;
	uint16_t SPI_DIRECTION;
  uint16_t SPI_DATAFPS;
  uint16_t SPI_CPOL;
  uint16_t SPI_CPHA;
  uint16_t SPI_FIRST;
  uint16_t SPI_NSS;
	uint16_t SPI_BAUDPRE;
	uint16_t SPI_CRCPLOY;
} SPI_init_st;


void SPI_init(SPI_TypeDef *SPIx,SPI_init_st *init_st);
void SPI_enable(SPI_TypeDef *SPIx,uint8_t state);
void SPI_writeData(SPI_TypeDef *SPIx,uint16_t halfWord);
uint16_t SPI_readData(SPI_TypeDef *SPIx);
bool_t SPI_checkSign(SPI_TypeDef *SPIx,uint16_t sign);
void SPI_enableCRC(SPI_TypeDef *SPIx,uint8_t state);
void SPI_checkCRC(SPI_TypeDef *SPIx,uint8_t state);
void SPI_enableSSOE(SPI_TypeDef *SPIx,uint8_t state);

#endif
