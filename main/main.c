#include "main.h"

int main(void)
{
  HEAP_init();

  OLED_init();

  ellipse_st ellipse;
  change_st ch1,ch2;

  ellipse.md_dot[0]= 30;
  ellipse.md_dot[1]= 30;
  ellipse.a= 30;
  ellipse.b= 20;

  OLED_setEllipse(&ellipse);

  OLED_changeInit(&ch1);
  OLED_changeInit(&ch2);

  ch1.l= -(float)ellipse.md_dot[0];
  ch1.m= -(float)ellipse.md_dot[1];
  ch2.a= 0.7f;
  ch2.d= 0.7f;
  OLED_changeMix(&ch1,&ch2);

  OLED_changeInit(&ch2);
  ch2.a= 0.7f;
  ch2.d= 0.7f;
  ch2.b= -0.7f;
  ch2.c= 0.7f;
  OLED_changeMix(&ch1,&ch2);
  
  OLED_changeInit(&ch2);
  ch2.l= (float)ellipse.md_dot[0];
  ch2.m= (float)ellipse.md_dot[0];
  OLED_changeMix(&ch1,&ch2);

  OLED_dotsChange(ellipse.dots_set,ellipse.dots_number,&ch1);

  OLED_freshEllipse(&ellipse);

  while(1)
	{
  }

  return 0;
}
