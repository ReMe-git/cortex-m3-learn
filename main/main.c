#include "main.h"

int main(void)
{
  uint8_t dot1[2]= {0,0};
  uint8_t dot2[2]= {25,50};
  uint8_t dot3[2]= {0,0};
  uint8_t dot4[2]= {100,50};
  uint8_t dot5[2]= {0,0};
  uint8_t dot6[2]= {45,45};
	OLED_init();

  OLED_setLine(dot1,dot2);
  OLED_setLine(dot3,dot4);
  OLED_setLine(dot5,dot6);
  while(1)
	{

  }

  return 0;
}
