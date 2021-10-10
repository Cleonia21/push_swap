#include "../push_swap.h"

int	sort_big_block(t_gap *gap, int fd, char belong)
{
	t_gap *first;
	t_gap *second;
	int retval;

	retval = 0;
	first = NULL;
	second = NULL;


	while (gap)
	{
		if (gap->number >= 4)
		{
			retval += gap_put_before(&first, gap_new(gap->number));
			if (belong == 'a')
				ft_putstr_fd("pb-", fd);
			if (belong == 'b')
				ft_putstr_fd("pa-", fd);
		}
		else
		{
			retval += gap_put_after(&second, gap_new(gap->number));
			if (belong == 'a')
				ft_putstr_fd("ra-", fd);
			if (belong == 'b')
				ft_putstr_fd("pa-ra-", fd);
		}
		gap = gap->front;
	}
	retval += sort_gap(first, fd, belconv(belong));
	up_commands(gap_len(second), 0);
	retval += sort_gap(second, fd, 'a');
	return (retval);
}

int sort_gap(t_gap *gap, int fd, char belong)
{
	int gaplen;
	int retval;

	retval = 0;
	gaplen = gap_len(gap);
	gap = simplification_gap(gap);
	if (gaplen > 5)
		retval = sort_big_block(gap, fd, belong);
	else if (gaplen == 5 && belong == 'a')
		retval = sort_fifth_a(gap, fd);
	else if (gaplen == 5 && belong == 'b')
		retval = sort_fifth_b(gap, fd);
	else if (gaplen == 4 && belong == 'a')
		retval = sort_four_a(gap, fd);
	else if (gaplen == 4 && belong == 'b')
		retval = sort_four_b(gap, fd);
	else if (gaplen == 3 && belong == 'a')
		retval = sort_three_a(gap, fd);
	else if (gaplen == 3 && belong == 'b')
		retval = sort_three_b(gap, fd);
	else if (gaplen == 2 && belong == 'a')
		retval = sort_two_a(gap, fd);
	else if (gaplen == 2 && belong == 'b')
		retval = sort_two_b(gap, fd);
	ft_free_ollgap(&gap);
	return (retval);
}

char get_belong(t_lists *lists)
{
	char belong;

	if (lists->block_a == NULL)
		belong = 'b';
	else if (lists->block_b == NULL)
		belong = 'a';
	else if (lists->block_a->param->first > lists->block_b->param->first)
		belong = 'a';
	else
		belong = 'b';
	return (belong);
}

static char chek_for_end(t_lists *lists, char belong)
{
	if (lists->block_a->param->first == -1 && lists->block_b == NULL)
		return ('e');
	return (belong);
}

char block_sort(t_lists *lists)
{
	int fd;
	char belong;
	t_block *buf_block;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error();
	belong = get_belong(lists);
	belong = chek_for_end(lists, belong);
	if (belong == 'a')
	{
		buf_block = lists->block_a;
		if (sort_gap(buf_block->gap, fd, belong) != 0)
			return ('o');
		buf_block->gap = NULL;
		lists->block_a = lists->block_a->front;
	}
	else if (belong == 'b')
	{
		buf_block = lists->block_b;
		if (sort_gap(buf_block->gap, fd, belong) != 0)
			return ('o');
		buf_block->gap = NULL;
		lists->block_b = lists->block_b->front;
	}
	ft_free_block(&buf_block);
	close (fd);
	return (belong);
}
