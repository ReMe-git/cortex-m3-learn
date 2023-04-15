#include "core_m3.h"

#define HEAP_MAX_SIZE 10240
#define CHUNK_MIN_SIZE 8
#define CHUNK_MAX_NUM 510

typedef struct chunk_st{
	uint16_t size;
	uint16_t used;

} chunk_st;

typedef struct heap_st{
	uint16_t size;
	uint16_t chunk_number;
	chunk_st *chunks;

} heap_st;

heap_st *heap;

void HEAP_init(void)
{
  extern heap_st heap_base;
	heap= &heap_base;

	heap->size= 0;
	heap->chunk_number= 0;
	heap->chunks= (chunk_st *)(heap+ sizeof(heap_st));

}

void *HEAP_malloc(uint32_t size)
{
	int i;
	uint16_t reset;
	chunk_st *next;

	next= heap->chunks;

	for(i= 0;i< heap->chunk_number;i++)
	{
		reset= next->size- next->used;
	
		if(reset> 0)
		{
			if(next->used== 0&& reset>= size)
			{
				next->used= size;
				return (void *)((int)next+ sizeof(chunk_st));
			}
			else if(reset>= size+ sizeof(chunk_st))
			{
				heap->chunk_number+= 1;
				next->size= next->used;
				next= (chunk_st *)((int)next+ (next->size+ sizeof(chunk_st)));
				next->size= reset- sizeof(chunk_st);
				next->used= size;

				return (void *)((int)next+ sizeof(chunk_st));
			}

		}
		else
		{
			next= (chunk_st *)((int)next+ (next->size+ sizeof(chunk_st)));
		}

	}

	if(heap->size+ size+ sizeof(chunk_st)> HEAP_MAX_SIZE|| heap->chunk_number>= CHUNK_MAX_NUM)
	{
		return NULL;

	}
	else
	{
		heap->chunk_number+= 1;
		heap->size+= size+ sizeof(chunk_st);
		next->size= size;
		next->used= size;

		return (void *)((int)next+ sizeof(chunk_st));
	
	}

}

//堆栈式释放申请的内存可达到更好的回收效果
void HEAP_free(void *pointer)
{
	int i;
	chunk_st *target= (chunk_st *)((int)pointer- sizeof(chunk_st));
	chunk_st *next= heap->chunks;

	for(i= 1;i<= heap->chunk_number;i++)
	{
		if(next== target)
		{
			next->used= 0;

			next= (chunk_st *)((int)next+ (next->size+ sizeof(chunk_st)));
		
			for(;i< heap->chunk_number&& next->used== 0;i++)
			{
				target->size+= next->size+ sizeof(chunk_st);
				heap->chunk_number-= 1;
				next= (chunk_st *)((int)next+ (next->size+ sizeof(chunk_st)));

			}

			break;
		}
		else
		{
			next= (chunk_st *)((int)next+ (next->size+ sizeof(chunk_st)));	
		
		}
	
	}

}
