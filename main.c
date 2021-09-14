#include "push_swap.h"

int up_commands(int len_a, int len_b)
{
	int fd;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	while (len_a > 0 && len_b > 0)
	{
		commands(fd, REV_ROTATE + 1, '0');
		len_a--;
		len_b--;
	}
	while (len_a > 0)
	{
		commands(fd, ROTATE, 'a');
		len_a--;
	}
	while (len_b > 0)
	{
		commands(fd, ROTATE, 'b');
		len_b--;
	}
	return (0);
}

int blocks_up(t_lists *lists)
{
	int len_a;
	int len_b;
	t_block *block_a;
	t_block *block_b;
	t_block *buf;

	block_a = block_cut_last(lists->block_a);
	block_b = block_cut_last(lists->block_b);
	if (up_commands(gap_len(block_a), gap_len(block_b)) == -1)
		return (-1);
	if (block_put_before(&(lists->block_a), block_a) == -1)
		return (-1);
	if (block_put_before(&(lists->block_b), block_b) == -1)
		return (-1);
	return (0);
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

int sorter(t_lists *lists)
{
	int last_elem;//0: не отсортировано. 1: отсортированно. -1: сортировка не удалась
	t_block **focus;
	t_block **un_focus;

	focus = &(lists->block_a);
	un_focus = &(lists->block_b);
	while (*focus || *un_focus)
	{
		if ((*focus)->param->elem_num <= 5)
		{
			last_elem = (*focus)->param->first + (*focus)->param->elem_num;
			block_print(*focus, "---------dell-------");
			*focus = block_del(*focus);
			if (*un_focus)
			{
				if (last_elem != (*un_focus)->param->first)
					blocks_up(lists);
			}
			else
			{
				if (*focus)
				{
					if (last_elem != (*focus)->param->first)
						blocks_up(lists);
				}
			}
		}
		else
			block_trim(focus, un_focus);
		appoint_focus(focus, un_focus);
		// mark = is_lists_sorted(lists);
	}
	return (0);
}

int main()
{
	t_gap *gap;
	t_lists lists;
	int fd;

	fd = open("commands.inf", O_TRUNC);
	if (fd == -1)
		return (-1);
	close (fd);
	gap = rnd_mas_to_gap();
	lists.block_a = block_new(gap, 'a');
	//block_print(lists.block_a);
	// block_trim(&(lists.block_a), &(lists.block_b));
	// blocks_print(lists.block_a);
	// blocks_print(lists.block_b);
	// blocks_up(&lists);
	// blocks_print(lists.block_a);
	// blocks_print(lists.block_b);
	sorter(&lists);
	block_print(lists.block_a, "after oll");
	block_print(lists.block_b, NULL);
	return (0);
}