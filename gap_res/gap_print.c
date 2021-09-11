#include "../push_swap.h"

void    gap_print(t_gap *gap)
{
    while(gap)
    {
        printf("%14p <- %p -> %14p {%i}\n", gap->back, gap, gap->front, gap->number);
        gap = gap->front;
    }
    printf("\n");
}
