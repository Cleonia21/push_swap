#include "../push_swap.h"

void	lsort_three(t_gap *gap, int fd)
{
	if (gap->number == 0)
	{
		if (gap->front->number == 2)
			ft_putstr_fd("sa-ra-", fd);
	}
	else if (gap->number == 1)
	{
		if (gap->front->number == 0)
			ft_putstr_fd("sa-", fd);
		else if (gap->front->number == 2)
			ft_putstr_fd("rra-", fd);
	}
	else if (gap->number == 2)
	{
		if (gap->front->number == 0)
			ft_putstr_fd("ra-", fd);
		else if (gap->front->number == 1)
			ft_putstr_fd("sa-rra-", fd);
	}
}
