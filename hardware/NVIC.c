#include "HardwareDef.h"

#define VECTKEY_WRITE ((uint32_t)0x05fa0000)
#define VECTKEY_READ ((uint32_t)0xfa050000)
#define VECTKEY_MASK ((uint32_t)0x0000ffff)

void NVIC_groupConf(uint32_t config)
{
  uint32_t tmp_val;

	tmp_val= VECTKEY_WRITE| config;
	
	*AIRCR|= tmp_val;

}

void NVIC_enableIRQ(uint32_t number,uint8_t state)
{
	uint32_t tmp_val;

	tmp_val= (uint32_t)(0x01<< number% 32);

	if(state!= disable)
	{
		*(NVIC_SETENA+ number/ 32)|= tmp_val;

	}
	else
	{
		*(NVIC_CLRENA+ number/ 32)&= ~tmp_val;

	}

}

void NVIC_setPend(uint32_t number,uint8_t state)
{
	uint32_t tmp_val;

	tmp_val= (uint32_t)(0x01<< number% 32);

	if(state!= disable)
	{
		*(NVIC_SETPEND+ number/ 32)|= tmp_val;

	}
	else
	{
		*(NVIC_CLRPEND+ number/ 32)&= ~tmp_val;

	}

}

void NVIC_setPriority(uint32_t number,uint8_t priority)
{
	*(NVIC_SETPRI+ number)= priority;

}

void NVIC_setSYSPriority(uint32_t number,uint8_t priority)
{
	*(NVIC_SETSPR+ number)= priority;

}

