#include "../push_swap.h"

static void	make_block_param(t_gap *gap, t_param *param)
{
	param->elem_num = 1;
	param->first = gap->number;
	while (gap->front)
	{
		gap = gap->front;
		param->elem_num++;
		if (gap->number < param->first)
			param->first = gap->number;
	}
	param->min = param->first + param->elem_num / 2;
	param->max = param->first + param->elem_num / 4 * 3;
}

t_block	*block_new(t_gap *gap, char belong)
{
	t_block *empty;

	empty = (t_block *)malloc(sizeof(t_block));
	if (empty == NULL)
		ft_error(MEMORY_ALLOC, "block_new");
	empty->param = (t_param *)malloc(sizeof(t_param));
	if (empty->param == NULL)
		ft_error(MEMORY_ALLOC, "block_new");
	empty->gap = gap;
	empty->front = NULL;
	empty->belong = belong;
	if (gap)
		make_block_param(gap, empty->param);
	return (empty);
}
