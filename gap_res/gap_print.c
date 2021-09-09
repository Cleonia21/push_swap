#include "../push_swap.h"

void gap_print(t_gap *gap)
{
    while(gap)
    {
        printf("%p <- %p=%i -> %p\n", gap->back, gap, gap->number, gap->front);
        gap = gap->front;
    }
}
