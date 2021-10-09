#include "../push_swap.h"

static	int	free_fifth(t_gap *two, t_gap *three, t_gap *buf)
{
	if (two)
		ft_free_ollgap(two);
	if (three)
		ft_free_ollgap(three);
	if (buf)
		ft_free_ollgap(buf);
	return (-1);
}

int	lsort_fifth(t_gap *gap, int fd)
{
	t_gap *gap_three;
	t_gap *gap_two;
	t_gap *buf_gap;

	buf_gap = gap;
	gap_three = NULL;
	gap_two = NULL;
	while (gap)
	{
		if (gap->number > 1)
		{
			if (gap_put_after(&gap_three, gap_new(gap->number)) == -1)
				return (free_fifth(gap_two, gap_three, buf_gap));
			ft_putstr_fd("ra-", fd);
		}
		else
		{
			if (gap_put_before(&gap_two, gap_new(gap->number)) == -1)
				return (free_fifth(gap_two, gap_three, buf_gap));
			ft_putstr_fd("pb-", fd);
		}
		gap = gap->front;
	}
	simplification_gap(gap_three);
	lsort_three(gap_three, fd);
	if (gap_two->number == 0)
		ft_putstr_fd("sb-", fd);
	ft_putstr_fd("pa-pa-", fd);
	free_fifth(gap_two, gap_three, buf_gap);
	return (0);
}