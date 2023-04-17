#ifndef _DMA_H
#define _DMA_H

#define DMA_DIRECTION_PER ((uint16_t)0x0000)
#define DMA_DIRECTION_MEM ((uint16_t)0x0010)

#define DMA_CIR_MODE_ENABLE ((uint16_t)0x0020)
#define DMA_CIR_MODE_DISABLE ((uint16_t)0x0000)

#define DMA_PER_INC_ENABLE ((uint16_t)0x0040)
#define DMA_PER_INC_DISABLE ((uint16_t)0x0000)

#define DMA_MEM_INC_ENABLE ((uint16_t)0x0080)
#define DMA_MEM_INC_DISABLE ((uint16_t)0x0000)

#define DMA_PER_SIZE_8BITS ((uint16_t)0x0000)
#define DMA_PER_SIZE_16BITS ((uint16_t)0x0100)
#define DMA_PER_SIZE_32BITS ((uint16_t)0x0200)

#define DMA_MEM_SIZE_8BITS ((uint16_t)0x0000)
#define DMA_MEM_SIZE_16BITS ((uint16_t)0x0400)
#define DMA_MEM_SIZE_32BITS ((uint16_t)0x0800)

#define DMA_PRY_LEVEL_LOW ((uint16_t)0x0000)
#define DMA_PRY_LEVEL_MED ((uint16_t)0x1000)
#define DMA_PRY_LEVEL_HIGH ((uint16_t)0x2000)
#define DMA_PRY_LEVEL_MAX ((uint16_t)0x3000)

#define DMA_MEM2MEM_ENABLE ((uint16_t)0x4000)
#define DMA_MEM2MEM_DISABLE ((uint16_t)0x0000)

#define DMA_SIGN_TEIF_1 ((uint32_t)0x00000008)
#define DMA_SIGN_TEIF_2 ((uint32_t)0x00000080)
#define DMA_SIGN_TEIF_3 ((uint32_t)0x00000800)
#define DMA_SIGN_TEIF_4 ((uint32_t)0x00008000)
#define DMA_SIGN_TEIF_5 ((uint32_t)0x00080000)
#define DMA_SIGN_TEIF_6 ((uint32_t)0x00800000)
#define DMA_SIGN_TEIF_7 ((uint32_t)0x08000000)

#define DMA_SIGN_HTIF_1 ((uint32_t)0x00000004)
#define DMA_SIGN_HTIF_2 ((uint32_t)0x00000040)
#define DMA_SIGN_HTIF_3 ((uint32_t)0x00000400)
#define DMA_SIGN_HTIF_4 ((uint32_t)0x00004000)
#define DMA_SIGN_HTIF_5 ((uint32_t)0x00040000)
#define DMA_SIGN_HTIF_6 ((uint32_t)0x00400000)
#define DMA_SIGN_HTIF_7 ((uint32_t)0x04000000)

#define DMA_SIGN_TCIF_1 ((uint32_t)0x00000002)
#define DMA_SIGN_TCIF_2 ((uint32_t)0x00000020)
#define DMA_SIGN_TCIF_3 ((uint32_t)0x00000200)
#define DMA_SIGN_TCIF_4 ((uint32_t)0x00002000)
#define DMA_SIGN_TCIF_5 ((uint32_t)0x00020000)
#define DMA_SIGN_TCIF_6 ((uint32_t)0x00200000)
#define DMA_SIGN_TCIF_7 ((uint32_t)0x02000000)

#define DMA_SIGN_GIF_1 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_2 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_3 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_4 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_5 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_6 ((uint32_t)0x01000000)
#define DMA_SIGN_GIF_7 ((uint32_t)0x01000000)

/*DMA初始化结构体*/
typedef struct DMA_channelInit_st{
  uint8_t DMA_CHANNEL;
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


void DMA_channelInit(DMA_Channel_TypeDef *channel,channelInit_st *init_st);
void DMA_enableChannel(DMAChannel_TypeDef *channel,uint8_t state);
uint8_t DMA_checKSign(DMA_TypeDef *dma,uint32_t sign);
void DMA_clearSign(DMA_TypeDef *dma,uint32_t sign);
#endif
