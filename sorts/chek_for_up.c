#include "../push_swap.h"

typedef struct s_min
{
	int	a_first;
	int b_first;
	int a_end;
	int	b_end;
}				t_min;

static void blocks_up(t_block **block_f, t_block **block_u)
{
	t_block *buf_f;
	t_block *buf_u;

	if (block_u == NULL || *block_u == NULL)
	{
		buf_f = block_cut_last(*block_f);
		buf_u = NULL;
	}
	else if (block_f == NULL || *block_f == NULL)
	{
		buf_f = NULL;
		buf_u = block_cut_last(*block_u);
	}
	else
	{
		buf_f = block_cut_last(*block_f);
		buf_u = block_cut_last(*block_u);
	}
	up_commands(gap_len_forblock(buf_f), gap_len_forblock(buf_u));
	if (buf_f)
		block_put_before(block_f, buf_f);
	if (buf_u)
		block_put_before(block_u, buf_u);
}

static  t_block *block_get_last(t_block *block)
{
	if (block == NULL)
		return (NULL);
	while (block->front)
		block = block->front;
	return (block);
}

static  t_min initial_min()
{
	t_min min;
	min.a_first = -1;
	min.a_end = -1;
	min.b_first = -1;
	min.b_end = -1;
	return (min);
}

void	chek_for_up(t_lists *lists)
{
	t_min min;

	min = initial_min();
	if (lists->block_a)
	{
		min.a_first = lists->block_a->param->first;
		min.a_end = block_get_last(lists->block_a)->param->first;
		if (min.a_end == min.a_first)
			min.a_end = -1;
	}
	if (lists->block_b)
	{
		min.b_first = lists->block_b->param->first;
		min.b_end = block_get_last(lists->block_b)->param->first;
		if (min.b_end == min.b_first)
			min.b_end = -1;
	}
	if (min.a_end > min.a_first && min.a_end > min.b_first
		&& min.b_end > min.a_first && min.b_end > min.b_first)
		blocks_up(&(lists->block_a), &(lists->block_b));
	else if (min.a_end > min.a_first && min.a_end > min.b_first)
		blocks_up(&(lists->block_a), NULL);
	else if (min.b_end > min.a_first && min.b_end > min.b_first)
		blocks_up(&(lists->block_b), NULL);
}
