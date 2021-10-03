#include "../push_swap.h"

void	gap_swap(t_gap *gap, int fd)
{
	int	buf;

	if (gap == NULL || gap->front == NULL)
		ft_error(SWAP, "sort_four_a");
	buf = gap->number;
	gap->number = gap->front->number;
	gap->front->number = buf;
	ft_putstr_fd("sa-", fd);
}
