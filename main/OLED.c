#include "HardwareDef.h"
#include "delay.h"
#include "RCC.h"
#include "I2C.h"
#include "GPIO.h"

#define MAX_LINE_DOTS_NUMBER 128
#define MAX_CIRCLE_DOTS_NUMBER 64
#define MAX_ELLIPSE_DOTS_NUMBER 64

typedef struct line_st{
	uint8_t bg_dot[2];
	uint8_t ed_dot[2];
	uint32_t dots_number;
	uint8_t dots_set[MAX_LINE_DOTS_NUMBER* 2];
} line_st;

typedef struct circle_st{
	uint8_t md_dot[2];
	uint8_t r;
	uint32_t dots_number;
	uint8_t dots_set[MAX_CIRCLE_DOTS_NUMBER* 2];
} circle_st;

typedef struct ellipse_st{
	uint8_t md_dot[2];
	uint8_t a;
	uint8_t b;
	uint32_t dots_number;
	uint8_t dots_set[MAX_ELLIPSE_DOTS_NUMBER* 2];
} ellipse_st;

static uint8_t oled_mem[128][8];

void OLED_writeCmds(uint8_t *cmd,uint8_t len)
{
  int i;

  I2C_start(I2C1,enable);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
	
  I2C_sendAddress(I2C1,(uint8_t)0x78,I2C_ADDRESS_SEND);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  
  for(i= 0;i< len;i++)
  {
	  I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,cmd[i]);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}
  
  I2C_stop(I2C1,enable);
}

void OLED_clear(void)
{
  uint32_t i,n;

  I2C_start(I2C1,enable);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));

	I2C_sendAddress(I2C1,(uint8_t)0x78,I2C_ADDRESS_SEND);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  
  for(i= 0;i< 8;i++)
  {
 	  I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,0xb0+ i);	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,0x00);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));  
    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,0x10);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    for(n= 0;n< 128;n++)
    {
  	  I2C_sendByte(I2C1,(uint8_t)0xc0);
	    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	  
      I2C_sendByte(I2C1,(uint8_t)0x00);
	    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));  
    }
  
  }

  I2C_stop(I2C1,enable);
}

void OLED_memClear(void)
{
	int i,n;
	for(i= 0;i< 128;i++)
	{
		for(n= 0;n< 8;n++)
		{
			oled_mem[i][n]= (uint8_t)0x00;
		
		}

	}
}

void OLED_init(void)
{
  uint8_t init_cmd[28]={0xae,0x20,0x10,0xb0,0x00,0x10,0xc8,0x40,0x81,
                        0xff,0xa1,0xa6,0xa8,0x3f,0xa4,0xd3,0x00,0xd5,
                        0xf0,0xd9,0x22,0xda,0x12,0xdb,0x20,0x8d,0x14,
                        0xaf};
  GPIO_init_st gpio_st;
  I2C_init_st i2c_st;

  RCC_apb2Conf(APB2_GPIOB,enable);	
  gpio_st.GPIO_PIN= GPIO_PIN_6| GPIO_PIN_7;
  gpio_st.GPIO_MODE= GPIO_MODE_AF_OD;
  gpio_st.SPEED_MODE= OUTPUT_SPEED_50MHz;
  GPIO_init(GPIOB,&gpio_st);
  
  RCC_apb1Conf(APB1_I2C1,enable);
  i2c_st.I2C_MODE= I2C_MODE_DEFAULT;
  i2c_st.I2C_CLK_SPEED= 400000;
  i2c_st.I2C_FAST_DUTY= I2C_FAST_DUTY_0;
  i2c_st.I2C_OWN_ADDRESS1= 0x0078;
  i2c_st.I2C_ACK= I2C_ACK_N;
  i2c_st.I2C_ACK_ADDRESS= I2C_ACK_ADDRESS_7BIT;
  I2C_init(I2C1,&i2c_st);
  I2C_cmd(I2C1,enable);
  
  delay_us(100);
  OLED_writeCmds(init_cmd,27);
  
  OLED_clear();
	OLED_memClear();
  OLED_writeCmds(&init_cmd[27],1);
}

void OLED_close(void)
{
   I2C_start(I2C1,enable);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));

	I2C_sendAddress(I2C1,(uint8_t)0x78,I2C_ADDRESS_SEND);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

	I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	  
	I2C_sendByte(I2C1,(uint8_t)0xae);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  
}

void OLED_open(void)
{
  
  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	  
	I2C_sendByte(I2C1,(uint8_t)0xaf);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_stop(I2C1,enable);
}

void OLED_setDot(uint8_t x,uint8_t y)
{
  uint8_t dotType[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};


  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0xb0+ y/ 8));	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0x0f& x));	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0x10| (x>> 4)));
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  I2C_sendByte(I2C1,(uint8_t)0xc0);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		
  oled_mem[x][y/ 8]|= dotType[y% 8];
  I2C_sendByte(I2C1,oled_mem[x][y/ 8]);	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

void OLED_rmDot(uint8_t x,uint8_t y)
{
  uint8_t dotType[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0xb0+ y/ 8));	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0x0f& x));	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  I2C_sendByte(I2C1,(uint8_t)0x80);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
  I2C_sendByte(I2C1,(uint8_t)(0x10| (x>> 4)));
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  I2C_sendByte(I2C1,(uint8_t)0xc0);
	while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		
  oled_mem[x][y/ 8]&= dotType[y% 8];
  I2C_sendByte(I2C1,oled_mem[x][y/ 8]);	
  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

void OLED_setDots(uint8_t *dots,uint32_t num)
{
  uint32_t i;
  uint8_t dotType[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

	for(i= 0;i< num;i++)
  {
    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,(uint8_t)(0xb0+ dots[i* 2+ 1]/ 8));	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,(uint8_t)(0x0f& dots[i* 2+ 0]));	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,(uint8_t)(0x10| (dots[i* 2+ 0]>> 4)));
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    I2C_sendByte(I2C1,(uint8_t)0xc0);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		
		oled_mem[dots[i* 2+ 0]][dots[i* 2+ 1]/ 8]|= dotType[dots[i* 2+ 1]% 8];
    I2C_sendByte(I2C1,oled_mem[dots[i* 2+ 0]][dots[i* 2+ 1]/ 8]);	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  }

}

void OLED_rmDots(uint8_t *dots,uint32_t num)
{
  uint32_t i;
  uint8_t dotType[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

  for(i= 0;i< num;i++)
  {	
		I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
		I2C_sendByte(I2C1,(uint8_t)(0xb0+ dots[i* 2+ 1]/ 8));	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    
    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,(uint8_t)(0x0f& dots[i* 2+ 0]));	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    I2C_sendByte(I2C1,(uint8_t)0x80);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
    I2C_sendByte(I2C1,(uint8_t)(0x10| (dots[i* 2+ 0]>> 4)));
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    I2C_sendByte(I2C1,(uint8_t)0xc0);
	  while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		
		oled_mem[dots[i* 2+ 0]][dots[i* 2+ 1]/ 8]&= dotType[dots[i* 2+ 1]% 8];
    I2C_sendByte(I2C1,oled_mem[dots[i* 2+ 0]][dots[i* 2+ 1]/ 8]);	
    while(!I2C_checkEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  }

}

void OLED_setLine(line_st *line)
{
	int x,y,dx,dy,count,ax,ay;

	x= line->bg_dot[0];
	y= line->bg_dot[1];

	if(line->ed_dot[0]>= line->bg_dot[0])
	{
		dx= line->ed_dot[0]- line->bg_dot[0];
		ax= 1;
	}
	else
	{
		dx= line->bg_dot[0]- line->ed_dot[0];
		ax= -1;
	}
	
	if(line->ed_dot[1]>= line->bg_dot[1])
	{
		dy= line->ed_dot[1]- line->bg_dot[1];
		ay= 1;
	}
	else
	{
		dy= line->bg_dot[1]- line->ed_dot[1];
		ay= -1;
	}

	if(dx>= dy)
	{
/*浮点*/
		float d= 0.0f;
		float k= (float)dy/ dx;

		for(count= 0;count< dx;count++)
		{
			line->dots_set[count* 2+ 0]= (uint8_t)x;
			line->dots_set[count* 2+ 1]= (uint8_t)y;
			x+= ax;

			d= d+ k;

			if(d>= 0.5f)
			{
				y+= ay;
				d= d- 1.0f;
			}

		}

/*整形*/
/*
		int p= 2* dy- dx;
		for(count= 0;count< dx;count++)
		{
			dots[count* 2+ 0]= (uint8_t)x;
			dots[count* 2+ 1]= (uint8_t)y;
			x+= ax;

			p=p+ 2* dy;

			if(p>= 0)
			{
				y+= ay;
				p= p- 2* dx;
			}

		}
*/
	}
	else
	{
/*浮点*/
		float d= 0.0f;
		float k= (float)dx/ dy;

		for(count= 0;count< dy;count++)
		{
			line->dots_set[count* 2+ 0]= (uint8_t)x;
			line->dots_set[count* 2+ 1]= (uint8_t)y;
			y+= ay;

			d= d+ k;

			if(d>= 0.5f)
			{
				x+= ax;
				d= d- 1.0f;
			}

		}
/*整形*/
/*
		int p= 2* dx- dy;
		for(count= 0;count< dy;count++)
		{
			dots[count* 2+ 0]= (uint8_t)x;
			dots[count* 2+ 1]= (uint8_t)y;
			y+= ay;

			p=p+ 2* dx;

			if(p>= 0)
			{
				x+= ax;
				p= p- 2* dy;
			}

		}
*/
	}
	line->dots_number= (uint32_t)(count- 1);
  OLED_close();
	OLED_setDots(line->dots_set,(uint32_t)(count- 1));
  OLED_open();
}

void OLED_rmLine(line_st *line)
{
  OLED_close();
	OLED_rmDots(line->dots_set,line->dots_number);
  OLED_open();
}

void OLED_circleSetDots(circle_st *circle)
{
  uint8_t mx,my,dx,dy,i;
  
  mx= circle->md_dot[0];
  my= circle->md_dot[1];

  OLED_close();

  for(i= 0;i< circle->dots_number;i++)
  {
    dx= circle->dots_set[i* 2+ 0];
    dy= circle->dots_set[i* 2+ 1];
    OLED_setDot(mx+ dx,my+ dy);
    OLED_setDot(mx+ dy,my+ dx);
    OLED_setDot(mx+ dx,my- dy);
    OLED_setDot(mx+ dy,my- dx);
    OLED_setDot(mx- dx,my- dy);
    OLED_setDot(mx- dy,my- dx);
    OLED_setDot(mx- dx,my+ dy);
    OLED_setDot(mx- dy,my+ dx);
  }

  OLED_open();
}

void OLED_rmCircle(circle_st *circle)
{
  uint8_t mx,my,dx,dy,i;
  
  mx= circle->md_dot[0];
  my= circle->md_dot[1];

  OLED_close();

  for(i= 0;i< circle->dots_number;i++)
  {
    dx= circle->dots_set[i* 2+ 0];
    dy= circle->dots_set[i* 2+ 1];
    OLED_rmDot(mx+ dx,my+ dy);
    OLED_rmDot(mx+ dy,my+ dx);
    OLED_rmDot(mx+ dx,my- dy);
    OLED_rmDot(mx+ dy,my- dx);
    OLED_rmDot(mx- dx,my- dy);
    OLED_rmDot(mx- dy,my- dx);
    OLED_rmDot(mx- dx,my+ dy);
    OLED_rmDot(mx- dy,my+ dx);
  }

  OLED_open();
}

void OLED_setCircle(circle_st *circle)
{
  int x,y,d,count;
  x= 0;
  y= circle->r;
  d= 1- circle->r;
  for(count= 0;x<= y;count++)
  {
    circle->dots_set[count* 2+ 0]=x;
    circle->dots_set[count* 2+ 1]=y;
    
    if(d< 0)
      d+= 2* x+ 3;
    else
    {
      d+= 2* (x-y)+ 5;
      y-= 1;
    }

    x+= 1;
  }
  circle->dots_number= count;

  OLED_circleSetDots(circle);
}

void OLED_ellipseSetDots(ellipse_st *ellipse)
{
  uint8_t mx,my,dx,dy,i;
  
  mx= ellipse->md_dot[0];
  my= ellipse->md_dot[1];

  OLED_close();

  for(i= 0;i< ellipse->dots_number;i++)
  {
    dx= ellipse->dots_set[i* 2+ 0];
    dy= ellipse->dots_set[i* 2+ 1];
    OLED_setDot(mx+ dx,my+ dy);
    OLED_setDot(mx+ dx,my- dy);
    OLED_setDot(mx- dx,my- dy);
    OLED_setDot(mx- dx,my+ dy);
  }

  OLED_open();

}

void OLED_rmEllipse(ellipse_st *ellipse)
{
  uint8_t mx,my,dx,dy,i;
  
  mx= ellipse->md_dot[0];
  my= ellipse->md_dot[1];

  OLED_close();

  for(i= 0;i< ellipse->dots_number;i++)
  {
    dx= ellipse->dots_set[i* 2+ 0];
    dy= ellipse->dots_set[i* 2+ 1];
    OLED_rmDot(mx+ dx,my+ dy);
    OLED_rmDot(mx+ dx,my- dy);
    OLED_rmDot(mx- dx,my- dy);
    OLED_rmDot(mx- dx,my+ dy);
  }

  OLED_open();

}

void OLED_setEllipse(ellipse_st *ellipse)
{
	int x,y,a,b,count;
	float d1,d2;
	x= 0;
	y= ellipse->b;
	a= ellipse->a;
	b= ellipse->b;

	d1= (float)(b* b+ a* a* (-b+ 0.25f));

	ellipse->dots_set[0]= x;
	ellipse->dots_set[1]= y;

	for(count= 1;(float)(b* b* (x+ 1.0f))< (float)(a* a* (y- 0.5f));count++)
	{
		if(d1<= 0.0f)
		{
			d1+= (float)(b* b* (2* x+ 3));
			x+= 1;
		}
		else
		{
			d1+= (float)(b* b* (2* x+ 3)+ a* a* (-2* y+ 2));
			x+= 1;
			y-= 1;
		}

		ellipse->dots_set[count* 2+ 0]= x;
		ellipse->dots_set[count* 2+ 1]= y;
	}
	d2= (float)(b* b* (x+ 0.5f)* (x+ 0.5f)+ a* a* (y- 1.0f)* (y- 1.0f)- a* a* b* b);
	for(;y> 0;count++)
	{
		if(d2<= 0.0f)
		{
			d2+= (float)(b* b* (2* x+ 2)+ a* a* (-2* y+ 3));
			x+= 1;
			y-= 1;
		}
		else
		{
			d2+= (float)(a* a* (-2* y+ 3));
			y-= 1;
		}

		ellipse->dots_set[count* 2+ 0]= x;
		ellipse->dots_set[count* 2+ 1]= y;
	}

	ellipse->dots_number= count;
	OLED_ellipseSetDots(ellipse);
}

