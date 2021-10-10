#include "../push_swap.h"

int	sort_fifth_b(t_gap *gap, int fd)
{
	t_gap *a_gap;
	t_gap *under_gap;
	int retval;

	retval = 0;
	a_gap = NULL;
	under_gap = NULL;
	while (gap)
	{
		if (gap->number >= 2)
		{
			ft_putstr_fd("pa-", fd);
			retval += gap_put_before(&a_gap, gap_new(gap->number));
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ft_putstr_fd("pa-ra-", fd);
			retval += gap_put_after(&under_gap, gap_new(gap->number));
		}
		gap = gap->front;
	}
	retval += sort_gap(a_gap, fd, 'a', gap_len(a_gap));
	ft_putstr_fd("rra-rra-", fd);
	retval += sort_gap(under_gap, fd, 'a', gap_len(under_gap));
	return (0);
}

int	sort_fifth_a(t_gap *gap, int fd)
{
	t_gap *b_gap;
	t_gap *under_gap;
	int ra;
	int retval;

	retval = 0;
	ra = 0;
	b_gap = NULL;
	under_gap = NULL;
	while (gap->front != NULL)
	{
		if (gap->number == 4)
			gap_swap(gap, fd);
		else if (gap->number == 3 || gap->number == 2)
		{
			ft_putstr_fd("pb-", fd);
			retval += gap_put_before(&b_gap, gap_new(gap->number));
			gap = gap->front;
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ra++;
			ft_putstr_fd("ra-", fd);
			retval += gap_put_after(&under_gap, gap_new(gap->number));
			gap = gap->front;
		}
	}
	retval += sort_gap(b_gap, fd, 'b', gap_len(b_gap));
	if (ra == 1)
		ft_putstr_fd("rra-", fd);
	if (ra == 2)
		ft_putstr_fd("rra-rra-", fd);
	retval += sort_gap(under_gap, fd, 'a', gap_len(under_gap));
	if (retval != 0)
		return (-1);
	return (0);
}