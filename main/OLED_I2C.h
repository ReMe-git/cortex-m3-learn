#ifndef _OLED_H
#define _OLED_H

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

typedef struct change_st{
	float a;
	float b;
	float c;
	float d;
	float p;
	float q;
	float s;
	float l;
	float m;
} change_st;

void OLED_init(void);
void OLED_clear(void);
void OLED_writeCmds(uint8_t *cmd,uint8_t len);
void OLED_setDots(uint8_t *dots,uint32_t num);
void OLED_open(void);
void OLED_close(void);
void OLED_rmDots(uint8_t *dots,uint32_t num);
void OLED_setLine(line_st *line);
void OLED_freshLine(line_st *line);
void OLED_rmLine(line_st *line);
void OLED_setCircle(circle_st *circle);
void OLED_freshCircle(circle_st *circle);
void OLED_rmCircle(circle_st *circle);
void OLED_setEllipse(ellipse_st *ellipse);
void OLED_freshEllipse(ellipse_st *ellipse);
void OLED_rmEllipse(ellipse_st *ellipse);
void OLED_changeInit(change_st *change);
void OLED_changeMix(change_st *ch1,change_st *ch2);
void OLED_dotsChange(uint8_t *dots,uint32_t num,change_st *change);
#endif
