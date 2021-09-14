#include "../push_swap.h"

t_block *block_cut_last(t_block *block)
{
    t_block *buf;
    t_block *last;

    if (!block)
        return (NULL);
    buf = block;
    last = last_block(block);
    if (buf == last)
        return (last);
    while (buf->front != last)
        buf = buf->front;
    buf->front = NULL;
    return (last);
}