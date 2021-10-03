#include "../push_swap.h"

void sort_four_a(t_gap *gap, int fd)
{
	int ra;
	t_gap *buf;

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
			gap_put_before(&buf, gap_new(gap->number));
			gap = gap->front;
		}
	}
	if (ra == 1)
		ft_putstr_fd("rra-", fd);
	sort_two_b(buf, fd);
}

void sort_four_b(t_gap *gap, int fd)
{
	t_gap *buf;
	int min;

	buf = NULL;
	while (gap != NULL)
	{
		if (gap->number == 0)
			ft_putstr_fd("rb-", fd);
		else
		{
			ft_putstr_fd("pa-", fd);
			gap_put_before(&buf, gap_new(gap->number));
		}
		gap = gap->front;
	}
	sort_gap(buf, fd, 'a');
	ft_putstr_fd("rrb-pa-", fd);
}
