// #include "../push_swap.h"

// int		block_swap(t_block *from, t_block *to)
// {
// 	t_gap *buf;

// 	buf = from->gap;
// 	from->gap = buf->front;
// 	from->gap->back = NULL;
// 	gap_put_before(to->gap, buf);
// 	to->gap = buf;
// }