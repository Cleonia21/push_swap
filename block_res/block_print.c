#include "../push_swap.h"

void block_print(t_block *block, char *str)
{
    if (str)
        printf("%s\n\n", str);
    else
        printf("-----------///////////----------\n\n");
    if (block)
    {
        printf("adr =   %p\n\n", block);
        printf("belong:    %c\n", block->belong);
        printf("first:     %i\n", block->param->first);
        printf("elem_num:  %.0f\n", block->param->elem_num);
        printf("min/max    %.0f/%.0f\n\n", block->param->min, block->param->max);
        gap_print(block->gap);
        printf("front = %p\n", block->front);
    }
    printf("\n");
}

void blocks_print(t_block *block, char *str)
{
    while (block)
    {
        block_print(block, str);
        block = block->front;
    }
}