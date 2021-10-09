#include "../push_swap.h"

static void	make_block_param(t_gap *gap, t_param *param)
{
	param->elem_num = gap_len(gap);
	param->first = gap_min_num(gap);
	param->min = param->first + param->elem_num / 4;
	param->max = param->first + param->elem_num / 2;
}

t_block	*block_new(t_gap *gap, char belong)
{
	t_block *empty;

	if (gap == NULL)
		return (NULL);
	empty = (t_block *)malloc(sizeof(t_block));
	if (empty == NULL)
	{
		ft_free_ollgap(gap);
		return (NULL);
	}
	empty->param = (t_param *)malloc(sizeof(t_param));
	if (empty->param == NULL)
		return (ft_free_block(empty));
	empty->gap = gap;
	empty->front = NULL;
	empty->belong = belong;
	if (gap)
		make_block_param(gap, empty->param);
	return (empty);
}
