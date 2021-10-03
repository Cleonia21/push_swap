#include "../push_swap.h"

int	block_put_after(t_block **list, t_block *after)
{
	t_block *buf;
	if (after == NULL)
		return (-1);
	if (*list == NULL)
		*list = after;
	else if (*list == after)
		return (0);
	else
	{
		buf = last_block(*list);
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
	else if (*list == before)
		return (0);
	else
	{
		before->front = *list;
		*list = before;
	}
	return (0);
}
