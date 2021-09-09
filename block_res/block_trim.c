#include "../push_swap.h"

t_separator	*block_separation(t_block *from)
{
	t_separator	*sepr;
	int min;
	int max;
	int num;

	min = from->param->min;
	max = from->param->max;
	sepr = (t_separator *)malloc(sizeof(t_separator));
	if (sepr == NULL)
		return (-1);
	if (new_sepr_and_inf(sepr, inf, from) == -1)
		return (NULL);
	while (from->gap)
	{
		num = from->gap->number;
		if (num <= inf->min2)
			gap_put_before(sepr->gap1, gap_new(num));
		if (num > inf->min2 && num < inf->max2)
			gap_put_after(sepr->gap2, gap_new(num));
		if (num >= inf->max2)
			gap_put_after(sepr->gap3, gap_new(num));
		from->gap = from->gap->front;
	}
	return (sepr);
}

int function(char *str, t_lists *lists)
{
	t_separator *sepr;

	sepr = block_separation(lists->block_a);
	lists->block_a = block_del(lists->block_a);
	block_put_before(lists->block_b, block_new(sepr->gap1));
	block_put_after(lists->block_a, block_new(sepr->gap2));
	block_put_after(lists->block_b, block_new(sepr->gap3));
}