#ifndef _NVIC_H
#define _NVIC_H


void NVIC_groupConf(uint32_t config);
void NVIC_enableIRQ(uint32_t number,uint8_t state);
void NVIC_setPend(uint32_t number,uint8_t state);
void NVIC_setPriority(uint32_t number,uint8_t priority);
void NVIC_setSYSPriority(uint32_t number,uint8_t priority);

#endif
