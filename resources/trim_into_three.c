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

t_separator	*block_separation(t_block *from, int fd)
{
	t_separator	*sepr;

	sepr = new_sepr();
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
		{
			gap_put_before(&(sepr->gap1), gap_new(from->gap->number));
			commands(fd, from->belong, 1, P);
		}
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
		{
			gap_put_after(&(sepr->gap2), gap_new(from->gap->number));
			commands(fd, from->belong, 1, R);
		}
		else
		{
			gap_put_after(&(sepr->gap3), gap_new(from->gap->number));
			commands(fd, from->belong, 1, P);
			commands(fd, belconv(from->belong), 1, R);
		}
		from->gap = from->gap->front;
	}
	return (sepr);
}


int trim_into_three(t_block **where, t_block **to)
{
	t_separator *sepr;
	char belong;
	int fd;

	belong = (*where)->belong;
	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error(FILE_OPEN, "block_separation");
	sepr = block_separation(*where, fd);
	close (fd);
	*where = block_del(*where);
	block_put_before(to, block_new(sepr->gap1, belconv(belong)));
	block_put_after(where, block_new(sepr->gap2, belong));
	block_put_after(to, block_new(sepr->gap3, belconv(belong)));
	return (0);
}