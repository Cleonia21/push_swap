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

t_separator	*block_separation(t_block *from)
{
	t_separator	*sepr;
	int fd;
	int min;
	int max;
	int num;

	min = from->param->min;
	max = from->param->max;
	sepr = new_sepr();
	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error(FILE_OPEN, "block_separation");
	while (from->gap)
	{
		num = from->gap->number;
		if (num < min)
		{
			gap_put_before(&(sepr->gap1), gap_new(num));
			commands(fd, from->belong, 1, P);
		}
		else if (num >= min && num < max)
		{
			gap_put_after(sepr->gap2, gap_new(num));
			commands(fd, from->belong, 1, R);
		}
		else
		{
			gap_put_after(sepr->gap3, gap_new(num));
			commands(fd, from->belong, 1, P);
			commands(fd, belconv(from->belong), 1, R);
		}
		from->gap = from->gap->front;
	}
	close (fd);
	return (sepr);
}


int trim_into_three(t_block **where, t_block **to)
{
	t_separator *sepr;
	char belong;

	belong = (*where)->belong;
	sepr = block_separation(*where);
	*where = block_del(*where);
	block_put_before(to, block_new(sepr->gap1, belconv(belong)));
	block_put_after(where, block_new(sepr->gap2, belong));
	block_put_after(to, block_new(sepr->gap3, belconv(belong)));
	return (0);
}