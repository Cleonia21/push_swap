#include "../push_swap.h"

int	block_put_after(t_block **elem, t_block *after)
{
	t_block *buf;
	if (after == NULL)
		return (-1);
	if (*elem == NULL)
		*elem = after;
	else
	{
		buf = *elem;
		while (buf->front)
			buf = buf->front;
		buf->front = after;
	}
	return (0);
}

int	block_put_before(t_block **list, t_block *before)
{
	if (before == NULL)
		return (-1);
	if (*list == NULL)
		*list = before;
	else
	{
		before->front = *list;
		*list = before;
	}
	return (0);
}

// int main()
// {
// 	t_lists *list;

// 	list = (t_lists *)malloc(sizeof(t_lists));
// 	list->block_a = block_new(0, 0);
// 	list->block_a->gap = gap_new(0);
// 	gap_put_after(list->block_a->gap, gap_new(1));
// 	block_put_before(&(list->block_a), block_new(0, 1));
// 	return (0);
// }