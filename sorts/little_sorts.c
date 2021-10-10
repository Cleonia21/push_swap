#include "../push_swap.h"

static	void	lsort_two(t_gap *gap, int fd)
{
	if (gap->number > gap->front->number)
		ft_putstr_fd("sa-", fd);
}

int	little_sorts(t_gap *gap)
{
	int fd;
	int len;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	len = gap_len(gap);
	if (len == 2)
		lsort_two(gap, fd);
	else if (len == 3)
		lsort_three(gap, fd);
	else if (len == 4)
		lsort_four(gap, fd);
	else if (len == 5)
		lsort_fifth(gap, fd);
	close(fd);
	return (1);
}