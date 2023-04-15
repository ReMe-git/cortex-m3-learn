#include "HardwareDef.h"

#define SPI_CR1_MASK ((uint16_t)0x3800)
#define SPI_MODE_SPI ((uint16_t)0xf7ff)
#define SPI_CR1_ENABLE ((uint16_t)0x0040)
#define SPI_CR1_DISABLE ((uint16_t)0xffbf)
#define SPI_CRC_ENABLE ((uint16_t)0x2000)
#define SPI_CRC_DISABLE ((uint16_t)0xdfff)
#define SPI_CRCNEXT_ENABLE ((uint16_t)0x1000)
#define SPI_CRCNEXT_DISABLE ((uint16_t)0xefff)
#define SPI_SSOE_ENABLE ((uint16_t)0x0004)
#define SPI_SSOE_DISABLE ((uint16_t)0xfffb)

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


void SPI_init(SPI_TypeDef *SPIx,SPI_init_st *init_st)
{
	uint16_t tmp_val;

	tmp_val= SPIx->CR1;
	tmp_val&= SPI_CR1_MASK;

	tmp_val|= init_st->SPI_MODE;
	tmp_val|= init_st->SPI_DIRECTION;
	tmp_val|= init_st->SPI_DATAFPS;
	tmp_val|= init_st->SPI_CPOL;
	tmp_val|= init_st->SPI_CPHA;
	tmp_val|= init_st->SPI_FIRST;
	tmp_val|= init_st->SPI_NSS;
	tmp_val|= init_st->SPI_BAUDPRE;

	SPIx->CR1= tmp_val;
	
	SPIx->I2SCFGR&= SPI_MODE_SPI;

	SPIx->CRCPR= init_st->SPI_CRCPLOY;

}

void SPI_enable(SPI_TypeDef *SPIx,uint8_t state)
{
	if(state!= disable)
	{
		SPIx->CR1|= SPI_CR1_ENABLE;
	}
	else
	{
		SPIx->CR1&= SPI_CR1_DISABLE;
	}

}

void SPI_writeData(SPI_TypeDef *SPIx,uint16_t halfWord)
{
	SPIx->DR= halfWord;

}

uint16_t SPI_readData(SPI_TypeDef *SPIx)
{
	return SPIx->DR;

}

bool_t SPI_checkSign(SPI_TypeDef *SPIx,uint16_t sign)
{
	if((SPIx->SR& sign)== sign)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//根据芯片是否拥有CRC来决定是否使用
void SPI_enableCRC(SPI_TypeDef *SPIx,uint8_t state)
{
	if(state!= disable)
	{
		SPIx->CR1|= SPI_CRC_ENABLE;
	
	}
	else
	{
		SPIx->CR1&= SPI_CRC_DISABLE;
	
	}

}

void SPI_checkCRC(SPI_TypeDef *SPIx,uint8_t state)
{
	if(state!= disable)
	{
		SPIx->CR1|= SPI_CRCNEXT_ENABLE;
	
	}
	else
	{
		SPIx->CR1&= SPI_CRCNEXT_DISABLE;
	
	}

}
/*使用硬件NSS在输出时应使能SSOE*/
void SPI_enableSSOE(SPI_TypeDef *SPIx,uint8_t state)
{
	if(state!= disable)
	{
		SPIx->CR2|= SPI_SSOE_ENABLE;

	}
	else
	{
		SPIx->CR2&= SPI_SSOE_DISABLE;

	}

}

