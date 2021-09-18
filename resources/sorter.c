#include "../push_swap.h"

/* this function moves the last blocks or block to the beginning. */
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

t_block *block_get_last(t_block *block)
{
	if (block == NULL)
		return (NULL);
	while (block->front)
		block = block->front;
	return (block);
}


void chek_for_up(t_block **focus, t_block **un_focus, int last_num)
{
	t_block *last_f;
	t_block *last_u;
	int last_num_f;
	int last_num_u;

	last_f = block_get_last(*focus);
	last_u = block_get_last(*un_focus);
	last_num_f = -1;
	last_num_u = -1;
	if (*focus)
	{
		if (last_f == *focus && (*focus)->belong == 'b')
			last_f = NULL;
	}
	if (*un_focus)
	{
		if (last_u == *un_focus && (*un_focus)->belong == 'b')
			last_u = NULL;
	}
	if (last_f)
		last_num_f = last_f->param->first + last_f->param->elem_num;
	if (last_u)
		last_num_u = last_u->param->first + last_u->param->elem_num;
	if (last_num_f == last_num)
	{
		if (last_num_u == last_num - last_f->param->elem_num)
			blocks_up(focus, un_focus);
		else
			blocks_up(focus, NULL);
	}
	if (last_num_u == last_num)
	{
		if (last_num_f == last_num - last_u->param->elem_num)
			blocks_up(focus, un_focus);
		else
			blocks_up(un_focus, NULL);
	}
}

static void appoint_focus(t_block **focus, t_block **un_focus, int last)
{
	t_block *buf;

	chek_for_up(focus, un_focus, last);
	if (*focus == NULL)
		*focus = *un_focus;
	else if (*focus && *un_focus)
	{
		buf = *focus;
		*focus = *un_focus;
		*un_focus = buf;
	}
}

void sorter(t_lists *lists)
{
	int last;
	t_block *focus;
	t_block *un_focus;

	trim_into_three(&(lists->block_a), &(lists->block_b));
	focus = (lists->block_b);
	un_focus = (lists->block_a);
	last = (focus)->param->first;
	while (focus || un_focus)
	{
		if ((focus)->param->elem_num <= 6)
		{
			last = (focus)->param->first;
			block_sort(lists);
			focus = (lists->block_b);
			un_focus = (lists->block_a);
		}
		else
			trim_into_three(&focus, &un_focus);
		if (focus || un_focus)
			appoint_focus(&focus, &un_focus, last);
	}
}
