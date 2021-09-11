#include "../push_swap.h"

void block_print(t_block *block)
{
    printf("-----------///////////----------\n\n");
    printf("adr =   %p\n\n", block);
    printf("first:     %i\n", block->param->first);
    printf("elem_num:  %.0f\n", block->param->elem_num);
    printf("min/max    %.0f/%.0f\n\n", block->param->min, block->param->max);
    gap_print(block->gap);
    printf("front = %p\n", block->front);
    printf("\n");
}

void blocks_print(t_block *block)
{
    printf("-----------///////////----------\n\n");
    while (block)
    {
        printf("adr =   %p\n\n", block);
        printf("first:     %i\n", block->param->first);
        printf("elem_num:  %.0f\n", block->param->elem_num);
        printf("min/max    %.0f/%.0f\n\n", block->param->min, block->param->max);
        gap_print(block->gap);
        printf("front = %p\n", block->front);
        block = block->front;
    }
    printf("\n");
}