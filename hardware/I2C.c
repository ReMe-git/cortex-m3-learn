#include "HardwareDef.h"
#include "RCC.h"

#define I2C_CR1_PE_SET ((uint16_t)0x0001)
#define I2C_CR1_PE_RESET ((uint16_t)0xfffe)

#define I2C_CR1_START_SET ((uint16_t)0x0100) 
#define I2C_CR1_START_RESET ((uint16_t)0xfeff) 

#define I2C_CR1_STOP_SET ((uint16_t)0x0200)
#define I2C_CR1_STOP_RESET ((uint16_t)0xfdff)

#define I2C_CR1_ACK_SET ((uint16_t)0x0400)
#define I2C_CR1_ACK_RESET ((uint16_t)0xfbff)

#define I2C_CR2_FREQ_RESET ((uint16_t)0xffc0)

#define I2C_CCR_FS_RESET ((uint16_t)0x0fff)

#define I2C_CR1_CLEAR_MASK ((uint16_t)0xfbf5)

typedef struct I2C_init_st
{
  uint32_t I2C_CLK_SPEED;
  uint16_t I2C_MODE;
  uint16_t I2C_FAST_DUTY;
  uint16_t I2C_OWN_ADDRESS1;
  uint16_t I2C_ACK;
  uint16_t I2C_ACK_ADDRESS;
} I2C_init_st;

err_t I2C_init(I2C_TypeDef *I2Cx,I2C_init_st *init_st)
{
  //时钟分频
  uint16_t tmp_val;
	uint16_t result;
	uint16_t i2c_freq;
	uint32_t clock_freq= 8000000;
  clock_freq_st clock_st;

  tmp_val= I2Cx->CR2;
  tmp_val&= I2C_CR2_FREQ_RESET;

	//获取APB1总线时钟频率
  rcc_CLOCKS_freq(&clock_st);
	clock_freq=clock_st.APB1_FREQ;
	//设置I2C分频2~36MHz
	i2c_freq= (uint32_t)(clock_freq/ 1000000);
  tmp_val|= i2c_freq;
	I2Cx->CR2= tmp_val;
	//禁用I2C模块以配置
	I2Cx->CR1&= I2C_CR1_PE_RESET;
	tmp_val= 0x0;
	//标准模式配置
  if(init_st->I2C_CLK_SPEED<= 100000)
  {
		//设置SCL时钟
		if((result= (uint16_t)(clock_freq/ (uint16_t)(init_st->I2C_CLK_SPEED* 2)))< 0x04)
		{
			return I2C_ERR_CCR_TOOLOW;
		}
		else
		{
			tmp_val|= result;
		}
		//设置最大上升时间
		I2Cx->TRISE|= (uint16_t)(i2c_freq+ 1);
  }
	//高速模式配置
  else
  {
		//根据占空比配置时钟寄存器		
		if(init_st->I2C_FAST_DUTY= 0x8000)
		{
			result= (uint16_t)(clock_freq/ (uint16_t)(init_st->I2C_CLK_SPEED* 3));
		}
		else
		{
			result= (uint16_t)(clock_freq/ (uint16_t)(init_st->I2C_CLK_SPEED* 25));
		}
		if(result& I2C_CCR_FS_RESET== 0)
		{
			return I2C_ERR_CCR_TOOLOW; 
		}
		result|= init_st->I2C_FAST_DUTY;
		//配置最大上升时间
    I2Cx->TRISE = (uint16_t)((i2c_freq* 300/ 1000)+ 1);  
		tmp_val|= result;
	}
	//配置时钟寄存器CCR
	I2Cx->CCR|= tmp_val;
	//使能I2C
	I2Cx->CR1|= I2C_CR1_PE_SET;
	//清除ACK,SMBUS,SMBTYPE
	tmp_val= I2Cx->CR1;
	tmp_val&= I2C_CR1_CLEAR_MASK;
	//配置I2C模式,是否应答
	tmp_val|= (uint16_t)(init_st->I2C_MODE| init_st->I2C_ACK);
	I2Cx->CR1= tmp_val;
	//设置自身地址或者目标地址
	I2Cx->OAR1|= (uint16_t)(init_st->I2C_OWN_ADDRESS1| init_st->I2C_ACK_ADDRESS);

	return ERR_NONE;
}

void I2C_cmd(I2C_TypeDef *I2Cx,uint8_t state)
{
	if(state!= disable)
	{
		I2Cx->CR1|= I2C_PE_SET;
	}
	else
	{
		I2Cx->CR1&= I2C_PE_RESET;
	}
}

void I2C_start(I2C_TypeDef *I2Cx,uint8_t state)
{
	if(state!= disable)
	{
		I2Cx->CR1|= I2C_CR1_START_SET;
	}
	else
	{
		I2Cx->CR1&= I2C_CR1_START_RESET;
	}
}

void I2C_stop(I2C_TypeDef *I2Cx,uint8_t state)
{
	if(state!= disable)
	{
		I2Cx->CR1|= I2C_CR1_STOP_SET;
	}
	else
	{
		I2Cx->CR1&= I2C_CR1_STOP_RESET;
	}
}

void I2C_ack(I2C_TypeDef *I2Cx,uint8_t state);
{
	if(state!= disable)
	{
		I2Cx->CR1|= I2C_CR1_ACK_SET;
	}
	else
	{
		I2Cx->CR1&= I2C_CR1_ACK_RESET;
	}
}

void I2C_call(I2C_TypeDef *I2Cx,uint8_t state);
void I2C_sendData(I2C_TypeDef *I2Cx,uint8_t data);
void I2C_sendAddress(I2C_TypeDef *I2Cx,uint8_t address);
uint8_t I2C_receiveData(I2C_TypeDef *I2Cx);

