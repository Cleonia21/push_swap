#include "../push_swap.h"

int	gap_put_after(t_gap *elem, t_gap *after)
{
	if (elem == NULL || after == NULL)
		return (-1);
	after->front = elem->front;
	after->back = elem;
	elem->front = after;
	return (0);
}

int gap_put_before(t_gap *elem, t_gap *before)
{
	if (elem == NULL || before == NULL)
		return (-1);
	if (elem->back)
		elem->back->front = before;
	before->back = elem->back;
	before->front = elem;
	elem->back = before;
	return (0);
}
