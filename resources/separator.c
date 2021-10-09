#include "../push_swap.h"

static void	commands(char *com, char belong, int fd)
{
	ft_putstr_fd(com, fd);
	if (belong == 'a')
		ft_putstr_fd("a-", fd);
	if (belong == 'b')
		ft_putstr_fd("b-", fd);
}

static t_separator *new_sepr()
{
	t_separator	*sepr;

	sepr = (t_separator *)malloc(sizeof(t_separator));
	if (sepr == NULL)
		return (NULL);
	sepr->gap1 = NULL;
	sepr->gap2 = NULL;
	sepr->gap3 = NULL;
	return (sepr);
}

static	void	*free_separator(t_separator *sepr, t_block *block)
{
	if (sepr)
	{
		if (sepr->gap1)
			ft_free_ollgap(sepr->gap1);
		if (sepr->gap2)
			ft_free_ollgap(sepr->gap2);
		if (sepr->gap3)
			ft_free_ollgap(sepr->gap3);
		free (sepr);
	}
	if (block)
		ft_free_block(block);
	return (NULL);
}

static	t_separator	*block_sepr_a(t_block *from, t_separator *sepr, int fd)
{
	t_block	*buf_block;

	buf_block = from;
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
		{
			if (gap_put_before(&(sepr->gap1), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("p", belconv(from->belong), fd);
		}
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
		{
			if (gap_put_after(&(sepr->gap2), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("r", from->belong, fd);
		}
		else
		{
			if (gap_put_after(&(sepr->gap3), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("p", belconv(from->belong), fd);
			commands("r", belconv(from->belong), fd);
		}
		from->gap = from->gap->front;
	}
	ft_free_block(buf_block);
	return (sepr);
}

static	t_separator	*block_sepr_b(t_block *from, t_separator *sepr, int fd)
{
	t_block	*buf_block;

	buf_block = from;
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
		{
			if (gap_put_before(&(sepr->gap1), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("p", belconv(from->belong), fd);
		}
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
		{
			if (gap_put_after(&(sepr->gap2), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("p", belconv(from->belong), fd);
			commands("r", belconv(from->belong), fd);
		}
		else
		{
			if (gap_put_after(&(sepr->gap3), gap_new(from->gap->number)) == -1)
				return (free_separator(sepr, from));
			commands("r", from->belong, fd);
		}
		from->gap = from->gap->front;
	}
	ft_free_block(buf_block);
	return (sepr);
}
