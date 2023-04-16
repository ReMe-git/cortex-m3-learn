#include "HardwareDef.h"

#define DMA_CCR_MASK ((uint16_t)0x0000)
#define DMA_CHANNEL_ENABLE ((uint16_t)0x0001)
#define DMA_CHANNEL_DISABLE ((uint16_t)0xfffe)

/*DMA初始化结构体*/
typedef struct DMA_channelInit_st{
  uint16_t DMA_DIRECTION;
  uint16_t DMA_CIR_MODE;
  uint16_t DMA_PER_INC;
  uint16_t DMA_MEM_INC;
  uint16_t DMA_PER_SIZE;
  uint16_t DMA_MEM_SIZE;
  uint16_t DMA_PRY_LEVEL;
  uint16_t DMA_MEM2MEM;
  uint16_t DMA_DATA_NUMBER;
  uint32_t DMA_PER_ADDRESS;
  uint32_t DMA_MEM_ADDRESS;

} DMA_channelInit_st;

void DMA_channelInit(DMA_Channel_TypeDef *channel,DMA_channelInit_st *init_st)
{
  uint16_t tmp_val;
  
  channel->CCR&= DMA_CCR_MASK;
  tmp_val= channel->CCR;

  tmp_val|= init_st->DMA_DIRECTION;
  tmp_val|= init_st->DMA_CIR_MODE;
  tmp_val|= init_st->DMA_PER_INC;
  tmp_val|= init_st->DMA_MEM_INC;
  tmp_val|= init_st->DMA_PER_SIZE;
  tmp_val|= init_st->DMA_MEM_SIZE;
  tmp_val|= init_st->DMA_PRY_LEVEL;
  tmp_val|= init_st->DMA_MEM2MEM;

  channel->CCR= tmp_val;

  channel->CNDTR= init_st->DMA_DATA_NUMBER;
  channel->CPAR= init_st->DMA_PER_ADDRESS;
  channel->CMAR= init_st->DMA_MEM_ADDRESS;

}

void DMA_enableChannel(DMA_Channel_TypeDef *channel,uint8_t state)
{
  if(state!= disable)
  {
    channel->CCR|= DMA_CHANNEL_ENABLE;
  
  }
  else
  {
    channel->CCR&= DMA_CHANNEL_DISABLE;
  
  }

}

uint8_t DMA_checKSign(DMA_TypeDef *dma,uint32_t sign)
{
  if((dma->ISR& sign)== sign)
  {
    return true;
  
  }
  else
  {
    return false;
  
  }

}

