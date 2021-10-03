#include "../push_swap.h"

void	sort_two_a(t_gap *gap, int fd)
{
	int first;
	int second;

	first = -1;
	second = -1;
	if (gap)
		first = gap->number;
	if (gap && gap->front)
		second = gap->front->number;
	if (first != -1 && second != -1 && first > second)
		ft_putstr_fd("sa-", fd);
}

void	sort_two_b(t_gap *gap, int fd)
{
	int first;
	int second;

	first = -1;
	second = -1;
	if (gap)
	{
		first = gap->number;
		if (gap && gap->front)
		{
			second = gap->front->number;
			if (first < second)
				ft_putstr_fd("sb-pa-pa-", fd);
			else
				ft_putstr_fd("pa-pa-", fd);
		}
		else
			ft_putstr_fd("pa-", fd);
	}
}
