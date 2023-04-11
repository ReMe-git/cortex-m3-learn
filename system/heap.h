#ifndef _HEAP_H
#define _HEAP_H

void HEAP_init(void);
void *HEAP_malloc(uint32_t size);
void HEAP_free(void *pointer);
#endif
