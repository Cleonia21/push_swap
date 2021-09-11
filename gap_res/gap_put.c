#include "../push_swap.h"

int	gap_put_after(t_gap *elem, t_gap *after)
{
	if (after == NULL)
		return (-1);
	while (elem->front != NULL)
		elem = elem->front;
	if (elem->number == -1)
		elem->number = after->number;
	else
	{
		after->front = elem->front;
		after->back = elem;
		elem->front = after;
	}
	return (0);
}

int gap_put_before(t_gap **elem, t_gap *before)
{
	if (before == NULL)
		return (-1);
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
