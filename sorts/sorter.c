#include "../push_swap.h"

static	char	chek_for_end(t_lists *lists, char belong)
{
	if (lists->block_a->param->first == -1 && lists->block_b == NULL
		&& lists->block_a->front == NULL)
		return ('e');
	return (belong);
}

int	sorter(t_lists *lists)
{
	char	end;
	int		fd;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return ('o');
	end = 'a';
	while (end != 'e' && end != 'o')
	{
		if ((lists->block_a && lists->block_a->param->elem_num <= 10
			&& lists->block_a->param->first != -1)
			|| (lists->block_b && lists->block_b->param->elem_num <= 10))
			end = block_sort(lists, fd);
		else
			if (trim_into_three(lists, fd) == -1)
				return (-1);
		end = chek_for_end(lists, end);
		if (end != 'e')
			chek_for_up(lists);
	}
	close(fd);
	return (end);
}
