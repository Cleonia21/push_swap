#include "../push_swap.h"

void up_commands(int len_a, int len_b)
{
	int fd;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error(FILE_OPEN, "up_commands");
	while (len_a > 0 && len_b > 0)
	{
		ft_putstr_fd("rrr-", fd);
		len_a--;
		len_b--;
	}
	while (len_a > 0)
	{
		ft_putstr_fd("rra-", fd);
		len_a--;
	}
	while (len_b > 0)
	{
		ft_putstr_fd("rrb-", fd);
		len_b--;
	}
	close(fd);
}
