#include "../push_swap.h"

typedef struct		s_separator
{
	t_gap			*gap1;
	t_gap			*gap2;
	t_gap			*gap3;
}					t_separator;

static t_separator *new_sepr()
{
	t_separator	*sepr;

	sepr = (t_separator *)malloc(sizeof(t_separator));
	if (sepr == NULL)
		ft_error(MEMORY_ALLOC, "new_sepr");
	sepr->gap1 = gap_new(-1);
	sepr->gap2 = gap_new(-1);
	sepr->gap3 = gap_new(-1);
	return (sepr);
}

t_separator	*block_separation_a(t_block *from, int fd)
{
	t_separator	*sepr;

	sepr = new_sepr();
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
		{
			gap_put_before(&(sepr->gap1), gap_new(from->gap->number));
			commands("p", belconv(from->belong), fd);
		}
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
		{
			gap_put_after(&(sepr->gap2), gap_new(from->gap->number));
			commands("r", from->belong, fd);
		}
		else
		{
			gap_put_after(&(sepr->gap3), gap_new(from->gap->number));
			commands("p", belconv(from->belong), fd);
			commands("r", belconv(from->belong), fd);
		}
		from->gap = from->gap->front;
	}
	return (sepr);
}

t_separator	*block_separation_b(t_block *from, int fd)
{
	t_separator	*sepr;

	sepr = new_sepr();
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
		{
			gap_put_before(&(sepr->gap1), gap_new(from->gap->number));
			commands("p", belconv(from->belong), fd);
		}
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
		{
			gap_put_after(&(sepr->gap2), gap_new(from->gap->number));
			commands("p", belconv(from->belong), fd);
			commands("r", belconv(from->belong), fd);
		}
		else
		{
			gap_put_after(&(sepr->gap3), gap_new(from->gap->number));
			commands("r", from->belong, fd);
		}
		from->gap = from->gap->front;
	}
	return (sepr);
}


int trim_into_three(t_lists *lists)
{
	t_separator *sepr;
	int fd;
	int b_first;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error(FILE_OPEN, "block_separation");
	//fd = 1;//
	b_first = -1;
	if (lists->block_b)
		b_first = lists->block_b->param->first;
	if (lists->block_a->param->first > b_first)
	{
		// gap_print_num(lists->block_a->gap);
		// ft_putchar_fd('\n', 1);
		sepr = block_separation_a(lists->block_a, fd);
		lists->block_a = block_del(lists->block_a);
		block_put_before(&(lists->block_b), block_new(sepr->gap1, 'b'));
		block_put_after(&(lists->block_a), block_new(sepr->gap2, 'a'));
		block_put_after(&(lists->block_b), block_new(sepr->gap3, 'b'));
		//ft_putchar_fd('\n', 1);
	}
	else if (lists->block_a->param->first < b_first)
	{
		// gap_print_num(lists->block_b->gap);
		// ft_putchar_fd('\n', 1);
		sepr = block_separation_b(lists->block_b, fd);
		lists->block_b = block_del(lists->block_b);
		block_put_before(&(lists->block_a), block_new(sepr->gap1, 'a'));
		block_put_after(&(lists->block_a), block_new(sepr->gap2, 'a'));
		block_put_after(&(lists->block_b), block_new(sepr->gap3, 'b'));
		//ft_putchar_fd('\n', 1);
	}
	close (fd);
	return (0);
}