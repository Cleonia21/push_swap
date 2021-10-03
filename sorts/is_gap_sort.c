#include "../push_swap.h"

int		is_gap_sort(t_gap *gap, char belong)
{
	int buf;

	if (gap == NULL)
		ft_error(ARG_NULL, "is_it_sort");
	buf = gap->number;
	while (gap && belong == 'a')
	{
		if (gap->front == NULL)
			return (1);
		gap = gap->front;
		if (gap->number != buf + 1)
			return (-1);
		buf = gap->number;
	}
	while (gap && belong == 'b')
	{
		if (gap->front == NULL)
			return (1);
		gap = gap->front;
		if (gap->number != buf - 1)
			return (-1);
		buf = gap->number;
	}
	return (-1);
}
