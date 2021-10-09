#include "../push_swap.h"

void *sort_big_block(t_gap *gap, int fd, char belong)
{
	t_gap *first;
	t_gap *second;
	int middle;

	first = NULL;
	second = NULL;
	middle = gap_min_num(gap) + 4;
	while (gap)
	{
		if (belong == 'a')
		{
			if (gap->number >= middle)
			{
				gap_put_before(&first, gap_new(gap->number));
				ft_putstr_fd("pb-", fd);
			}
			else
			{
				gap_put_after(&second, gap_new(gap->number));
				ft_putstr_fd("ra-", fd);
			}
		}
		if (belong == 'b')
		{
			if (gap->number >= middle)
			{
				gap_put_before(&first, gap_new(gap->number));
				ft_putstr_fd("pa-", fd);
			}
			else
			{
				gap_put_after(&second, gap_new(gap->number));
				ft_putstr_fd("pa-ra-", fd);
			}
		}
		gap = gap->front;
	}
	sort_gap(first, fd, belconv(belong));
	up_commands(gap_len(second), 0);
	sort_gap(second, fd, 'a');
}

void sort_gap(t_gap *gap, int fd, char belong)
{
	int gaplen;

	gaplen = gap_len(gap);
	gap = simplification_gap(gap);
	if (gaplen > 5)
		sort_big_block(gap, fd, belong);
	else if (gaplen == 5 && belong == 'a')
		sort_fifth_a(gap, fd);
	else if (gaplen == 5 && belong == 'b')
		sort_fifth_b(gap, fd);
	else if (gaplen == 4 && belong == 'a')
		sort_four_a(gap, fd);
	else if (gaplen == 4 && belong == 'b')
		sort_four_b(gap, fd);
	else if (gaplen == 3 && belong == 'a')
		sort_three_a(gap, fd);
	else if (gaplen == 3 && belong == 'b')
		sort_three_b(gap, fd);
	else if (gaplen == 2 && belong == 'a')
		sort_two_a(gap, fd);
	else if (gaplen == 2 && belong == 'b')
		sort_two_b(gap, fd);
	ft_free_ollgap(gap);
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
		ft_error(FILE_OPEN, "block_sort");
	belong = get_belong(lists);
	belong = chek_for_end(lists, belong);
	if (belong == 'a')
	{
		buf_block = lists->block_a->front;
		sort_gap(lists->block_a->gap, fd, belong);
		lists->block_a = buf_block;
	}
	if (belong == 'b')
	{
		buf_block = lists->block_b->front;
		sort_gap(lists->block_b->gap, fd, belong);
		lists->block_b = buf_block;
	}
	close (fd);
	return (belong);
}
