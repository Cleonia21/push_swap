#include "../push_swap.h"

static  void	sepr_a_com(t_block *from, int fd)
{
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
			ft_putstr_fd("pb-", fd);
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
			ft_putstr_fd("ra-", fd);
		else
			ft_putstr_fd("pb-rb-", fd);
		from->gap = from->gap->front;
	}
}

t_separator	*block_sepr_a(t_block *from, t_separator *spr, int fd)
{
	int retval;
	t_gap *first_gap;

	retval = 0;
	first_gap = from->gap;
	sepr_a_com(from, fd);
	from->gap = first_gap;
	while (from->gap)
	{
		if (from->gap->number > from->param->max)
			retval += gap_put_before(&(spr->gap1), gap_new(from->gap->number));
		else if (from->gap->number > from->param->min &&
				from->gap->number <= from->param->max)
			retval += gap_put_after(&(spr->gap2), gap_new(from->gap->number));
		else
			retval += gap_put_after(&(spr->gap3), gap_new(from->gap->number));
		from->gap = from->gap->front;
	}
	from->gap = first_gap;
	if (retval != 0)
		return (NULL);
	return (spr);
}