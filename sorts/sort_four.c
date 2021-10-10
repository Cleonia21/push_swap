#include "../push_swap.h"

int sort_four_a(t_gap *gap, int fd)
{
	int ra;
	t_gap *buf;
	int retval;

	retval = 0;
	ra = 0;
	buf = NULL;
	while (is_gap_sort(gap, 'a') == -1)
	{
		if (gap->number == 3)
			gap_swap(gap, fd);
		else if (gap->number == 2)
		{
			gap = gap->front;
			ft_putstr_fd("ra-", fd);
			ra = 1;
		}
		else
		{
			ft_putstr_fd("pb-", fd);
			retval += gap_put_before(&buf, gap_new(gap->number));
			gap = gap->front;
		}
	}
	if (ra == 1)
		ft_putstr_fd("rra-", fd);
	retval += sort_gap(buf, fd, 'b');
	return (retval);
}

int sort_four_b(t_gap *gap, int fd)
{
	t_gap *buf;
	int min;
	int retval;

	retval = 0;
	buf = NULL;
	while (gap != NULL)
	{
		if (gap->number == 0)
			ft_putstr_fd("rb-", fd);
		else
		{
			ft_putstr_fd("pa-", fd);
			retval += gap_put_before(&buf, gap_new(gap->number));
		}
		gap = gap->front;
	}
	retval += sort_gap(buf, fd, 'a');
	ft_putstr_fd("rrb-pa-", fd);
	return (retval);
}
