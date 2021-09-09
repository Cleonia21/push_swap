#include "../push_swap.h"

static void	make_block_param(t_gap *gap, t_param *param)
{
	param->elem_num = 1;
	param->first = gap->number;
	param->max = gap->number;
	param->min = gap->number;

	while (gap->front)
	{
		gap = gap->front;
		param->elem_num++;
		if (gap->number < param->first)
			param->first = gap->number;
	}
	param->min = param->first + (param->elem_num / 4) * 2;
	param->max = param->first + (param->elem_num / 4) * 3;
}

t_block	*block_new(t_gap *gap)
{
	t_block *empty;

	empty = (t_block *)malloc(sizeof(t_block));
	empty->gap = gap;
	empty->front = NULL;
	if (gap)
		make_block_param(gap, empty->param);
	return (empty);
}
