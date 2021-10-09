#include "../push_swap.h"

t_gap *gap_get_first(t_gap *gap)
{
    if (gap == NULL)
        return (NULL);
    while (gap->back != NULL)
        gap = gap->back;
    return (gap);
}