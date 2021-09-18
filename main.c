#include "push_swap.h"

int blocks_up(t_lists *lists)
{
	int len_a;
	int len_b;
	t_block *block_a;
	t_block *block_b;
	t_block *buf;

	block_a = block_cut_last(lists->block_a);
	block_b = block_cut_last(lists->block_b);
	if (up_commands(gap_len_forblock(block_a), gap_len_forblock(block_b)) == -1)
		return (-1);
	if (block_a)
	{
		if (block_put_before(&(lists->block_a), block_a) == -1)
			return (-1);
	}
	if (block_b)
	{
		if (block_put_before(&(lists->block_b), block_b) == -1)
			return (-1);
	}
	return (0);
}

int chek_for_up(t_lists *lists, int last_elem)
{
	if (lists->block_a && lists->block_b)
	{
		if (last_elem == lists->block_a->param->first ||
			last_elem == lists->block_b->param->first)
			return (0);
	}
	else if (lists->block_a)
	{
		if (last_elem == lists->block_a->param->first)
			return (0);
	}
	else if (lists->block_b)
		if (last_elem == lists->block_b->param->first)
			return (0);
	return (1);
}

void    appoint_focus(t_block **focus, t_block **un_focus)
{
	t_block *buf;

	if (*focus == NULL)
	{
		*focus = *un_focus;
		*un_focus = NULL;
	}
	else if (*un_focus == NULL)
		*un_focus = NULL;
	else
	{
		if ((*focus)->param->first > (*un_focus)->param->first)
		{
			buf = *focus;
			*focus = *un_focus;
			*un_focus = buf;
		}
	}
}

void sorter(t_lists *lists)//ринофлуимуцил
{
	int last_elem;
	t_block **focus;
	t_block **un_focus;

	focus = &(lists->block_a);
	un_focus = &(lists->block_b);
	while (*focus || *un_focus)
	{
		if ((*focus)->param->elem_num <= 6)
		{
			last_elem = (*focus)->param->first + (*focus)->param->elem_num;
			block_sort(lists);
			if (lists->block_a->front == NULL && lists->block_b == NULL)
				lists->block_a = NULL;
			else if (lists->block_a->param->first != LIST_LEN)
				block_put_before(&(lists->block_a), block_new(gap_new(LIST_LEN), 'a'));
			if (chek_for_up(lists, last_elem))
				blocks_up(lists);
		}
		else
			trim_into_three(focus, un_focus);
		appoint_focus(focus, un_focus);
	}
}

int main()
{
	t_gap *gap;
	t_lists lists;
	int fd;
	int retval;

	fd = open("commands.inf", O_TRUNC);
	if (fd == -1)
		ft_error(-1);
	close (fd);
	gap = rnd_mas_to_gap();
	lists.block_a = block_new(gap, 'a');
	if (lists.block_a == NULL)
		ft_error(1);
	sorter(&lists);
	exit(0);
}