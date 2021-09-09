#include "../push_swap.h"

t_block *block_del(t_block *del)
{
    t_block *buf;

    if (del == NULL)
        return (NULL);
    buf = del->front;
    if (del->gap)
        gap_free_oll(del->gap);
    free (del);
    return (buf);
}