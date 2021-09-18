#include "../push_swap.h"

int	gap_put_after(t_gap **elem, t_gap *after)
{
	t_gap *buf;

	buf = *elem;
	if (after == NULL)
		return (-1);
	if (*elem == NULL)
	{
		*elem = after;
		return (0);
	}
	while (buf->front != NULL)
		buf = buf->front;
	if (buf->number == -1)
		buf->number = after->number;
	else
	{
		after->front = NULL;
		after->back = buf;
		buf->front = after;
	}
	return (0);
}

int gap_put_before(t_gap **elem, t_gap *before)
{
	if (before == NULL)
		return (-1);
	if (*elem == NULL)
	{
		*elem = before;
		return (0);
	}
	if ((*elem)->number == -1)
		*elem = before;
	else
	{
		before->back = (*elem)->back;
		before->front = *elem;
		(*elem)->back = before;
		*elem = before;
	}
	return (0);
}
