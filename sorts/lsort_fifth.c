#include "../push_swap.h"

static	int	free_fifth(t_gap *two, t_gap *three)
{
	if (two)
		ft_free_ollgap(&two);
	if (three)
		ft_free_ollgap(&three);
	return (-1);
}

int	lsort_fifth(t_gap *gap, int fd)
{
	t_gap *gap_three;
	t_gap *gap_two;

	gap_three = NULL;
	gap_two = NULL;
	while (gap)
	{
		if (gap->number > 1)
		{
			if (gap_put_after(&gap_three, gap_new(gap->number)) == -1)
				return (free_fifth(gap_two, gap_three));
			ft_putstr_fd("ra-", fd);
		}
		else
		{
			if (gap_put_before(&gap_two, gap_new(gap->number)) == -1)
				return (free_fifth(gap_two, gap_three));
			ft_putstr_fd("pb-", fd);
		}
		gap = gap->front;
	}
	simplification_gap(gap_three);
	lsort_three(gap_three, fd);
	if (gap_two->number == 0)
		ft_putstr_fd("sb-", fd);
	ft_putstr_fd("pa-pa-", fd);
	free_fifth(gap_two, gap_three);
	return (0);
}