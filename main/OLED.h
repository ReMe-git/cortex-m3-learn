#ifndef _OLED_H
#define _OLED_H

#define MAX_LINE_DOTS_NUMBER 128

typedef struct line_st{
	uint8_t bg_dot[2];
	uint8_t ed_dot[2];
	uint32_t dots_number;
  uint8_t dots_set[MAX_LINE_DOTS_NUMBER* 2];
} line_st;


void OLED_init(void);
void OLED_clear(void);
void OLED_writeCmds(uint8_t *cmd,uint8_t len);
void OLED_setDots(uint8_t *dots,uint32_t num);
void OLED_rmDots(uint8_t *dots,uint32_t num);
void OLED_setLine(line_st *line);
#endif
