#include "../push_swap.h"

void	sort_fifth_b(t_gap *gap, int fd)
{
	t_gap *a_gap;
	t_gap *under_gap;

	a_gap = NULL;
	under_gap = NULL;
	while (gap)
	{
		if (gap->number >= 2)
		{
			ft_putstr_fd("pa-", fd);
			gap_put_before(&a_gap, gap_new(gap->number));
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ft_putstr_fd("pa-ra-", fd);
			gap_put_after(&under_gap, gap_new(gap->number));
		}
		gap = gap->front;
	}
	sort_gap(a_gap, fd, 'a');
	ft_putstr_fd("rra-rra-", fd);
	sort_two_a(under_gap, fd);
}

void	sort_fifth_a(t_gap *gap, int fd)
{
	t_gap *b_gap;
	t_gap *under_gap;

	b_gap = NULL;
	under_gap = NULL;
	while (is_gap_sort(gap, 'a') == -1)
	{
		if (gap->number == 4)
			gap_swap(gap, fd);
		else if (gap->number == 3 || gap->number == 2)
		{
			ft_putstr_fd("pb-", fd);
			gap_put_before(&b_gap, gap_new(gap->number));
			gap = gap->front;
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ft_putstr_fd("ra-", fd);
			gap_put_after(&under_gap, gap_new(gap->number));
			gap = gap->front;
		}
	}
	sort_two_b(b_gap, fd);
	ft_putstr_fd("rra-rra-", fd);
	sort_two_a(under_gap, fd);
}