#include "../push_swap.h"

int up_commands(int len_a, int len_b)
{
	int fd;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	while (len_a > 0 && len_b > 0)
	{
		commands(fd, '0', 1, RRARRB);
		len_a--;
		len_b--;
	}
	while (len_a > 0)
	{
		commands(fd, '0', 1, RRA);
		len_a--;
	}
	while (len_b > 0)
	{
		commands(fd, '0', 1, RRB);
		len_b--;
	}
	return (0);
}
