#include "../push_swap.h"

void	lsort_four(t_gap *gap, int fd)
{
	int sum_com;
	t_gap *buf_gap;

	sum_com = 0;
	buf_gap = gap;
	while (buf_gap->number != 3)
	{
		sum_com++;
		buf_gap = buf_gap->front;
	}
	if (sum_com == 0)
	{
		ft_putstr_fd("ra-", fd);
		buf_gap = gap;
		gap = gap->front;
		free(buf_gap);
	}
	else if (sum_com == 1)
	{
		ft_putstr_fd("sa-ra-", fd);
		gap_del(buf_gap);
	}
	else if (sum_com == 2)
	{
		ft_putstr_fd("rra-", fd);
		gap_put_before(&gap, buf_gap->front);
	}
	sort_gap(gap, fd, 'a');
}