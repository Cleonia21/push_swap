#include "../push_swap.h"

t_gap *gap_get_last(t_gap *gap)
{
    while (gap->front)
        gap = gap->front;
    return (gap);
}

t_gap *gap_get_first(t_gap *gap)
{
    while (gap->back)
        gap = gap->back;
    return (gap);
}
