#include "../push_swap.h"

int gap_min_num(t_gap *gap)
{
    int min;

    if (gap == NULL)
        return (0);
    min = gap->number;
    while (gap->front)
    {
        gap = gap->front;
        if (gap->number < min)
            min = gap->number;
    }
    return (min);
}