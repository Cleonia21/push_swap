#include "../push_swap.h"

static	int	free_fifth(t_gap *two, t_gap *three)
{
	if (two)
		ft_free_ollgap(&two);
	if (three)
		ft_free_ollgap(&three);
	return (-1);
}

static	void	two_putcom(int num, int fd)
{
	if (num == 0)
		ft_putstr_fd("sb-", fd);
	ft_putstr_fd("pa-pa-", fd);
}

int	lsort_fifth(t_gap *gap, int fd)
{
	t_gap *gap_three;
	t_gap *gap_two;
	int retval;

	retval = 0;
	gap_three = NULL;
	gap_two = NULL;
	while (gap)
	{
		if (gap->number > 1)
			retval += gap_put_after(&gap_three, gap_new(gap->number));
		else
			retval += gap_put_before(&gap_two, gap_new(gap->number));
		if (gap->number > 1)
			ft_putstr_fd("ra-", fd);
		else
			ft_putstr_fd("pb-", fd);
		gap = gap->front;
	}
	simplification_gap(gap_three);
	lsort_three(gap_three, fd);
	two_putcom(gap_two->number, fd);
	free_fifth(gap_two, gap_three);
	return (0);
}