#ifndef _OLED_H
#define _OLED_H

void OLED_init(void);
void OLED_clear(void);
void OLED_writeCmds(uint8_t *cmd,uint8_t len);
void OLED_setDots(uint8_t *dots,uint32_t num);
void OLED_setLine(uint8_t *dot1,uint8_t *dot2);
void OLED_setLine(uint8_t *dot1,uint8_t *dot2);
#endif
