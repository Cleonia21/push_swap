#include "../push_swap.h"

void sort_gap(t_gap *gap, int fd, char belong);

/*int *gap_in_str(t_gap *gap)
{
	int first;
	char *str;
	int i;
	int elem_num;
	t_gap *buf_gap;

	buf_gap = gap;
	elem_num = 0;
	first = buf_gap->number;
	while (buf_gap)
	{
		elem_num++;
		if (first > buf_gap->number)
			first = buf_gap->number;
		buf_gap = buf_gap->front;
	}
	str = (char *)malloc(sizeof(char) * elem_num + 1);
	str[elem_num] = '\0';
	buf_gap = gap;
	while (i < elem_num)
	{
		str = buf_gap->number - first + '0';
		i++;
		buf_gap = buf_gap->front;
	}
	return (str);
}



// int main()
// {
//     t_gap *gap;

//     gap = rnd_mas_to_gap();
//     while(gap->front)
//     {
//         gap->number += 10;
//         gap = gap->front;
//     }
//     gap->number += 10;
//     gap = gap_get_first(gap);
//     gap_print(gap);
//     int *mas = gap_conv(gap);
//     while (*mas != -1)
//     {
//         printf("%i\n", *mas);
//         mas++;
//     }
//     return (0);
// }*/

void sort_big_block(t_gap *gap, int fd, char belong)
{
	t_gap *first;
	t_gap *second;
	int middle;

	//fd = 1;//
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

t_gap *simplification_gap(t_gap *gap)
{
	t_gap *buf;
	int min_num;

	min_num = gap_min_num(gap);
	buf = gap;
	while (buf)
	{
		buf->number -= min_num;
		buf = buf->front;
	}
	return (gap);
}

void sort_gap(t_gap *gap, int fd, char belong)
{
	int gaplen;

	gaplen = gap_len(gap);
	gap = simplification_gap(gap);
	if (gaplen > 5)
		sort_big_block(gap, fd, belong);
	if (gaplen == 5)
	{
		if (belong == 'a')
			sort_fifth_a(gap, fd);
		if (belong == 'b')
			sort_fifth_b(gap, fd);
	}
	if (gaplen == 4)
	{
		if (belong == 'a')
			sort_four_a(gap, fd);
		if (belong == 'b')
			sort_four_b(gap, fd);
	}
	if (gaplen == 3)
	{
		if (belong == 'a')
			sort_three_a(gap, fd);
		if (belong == 'b')
			sort_three_b(gap, fd);
	}
	if (gaplen == 2)
	{
		if (belong == 'a')
			sort_two_a(gap, fd);
		if (belong == 'b')
			sort_two_b(gap, fd);
	}
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

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error(FILE_OPEN, "block_sort");
	//fd = 1;
	belong = get_belong(lists);
	belong = chek_for_end(lists, belong);
	if (belong == 'a')
	{
		// gap_print_num(lists->block_a->gap);//
		// ft_putchar_fd(belong, fd);
		// ft_putchar_fd('\n', fd);
		//block_print(lists->block_a, "------sort------");
		sort_gap(lists->block_a->gap, fd, belong);
		lists->block_a = block_del(lists->block_a);
	}
	if (belong == 'b')
	{
		// gap_print_num(lists->block_b->gap);//
		// ft_putchar_fd(belong, fd);
		// ft_putchar_fd('\n', fd);
		//block_print(lists->block_b, "------sort------");
		sort_gap(lists->block_b->gap, fd, belong);
		lists->block_b = block_del(lists->block_b);
	}
	//ft_putchar_fd('\n', fd);
	close (fd);
	return (belong);
}

/*
key com
10)  sa    swap the first 2 elements at the top of stack a
11)  sb    swap the first 2 elements at the top of stack b
2)  ss    sa & sb
  
30)  pa    from b to a
31)  pb    from a to b

40)  ra    first elem to end
41)  rb    first elem to end
5)  rr    ra & rb

60)  rra   end elem to first
61)  rrb   end elem to first
7)  rrr   rra & rrb
*/