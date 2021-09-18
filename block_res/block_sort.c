#include "../push_swap.h"

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

void sort_two_a(t_gap *gap, int fd)
{
    if (gap->number > gap->front->number)
        commands(fd, '0', 1, SA);
}

void sort_two_b(t_gap *gap, int fd)
{
    if (gap->number > gap->front->number)
        commands(fd, '0', 1, SB);
    commands(fd, '0', 2, PA, PA);
}

void sort_three_a(t_gap *gap, int fd)
{
    int min;

    min = gap_min_num(gap);
	if (gap->number - min == 0)
	{
        gap = gap->front;
		if (gap->number - min == 2)
            commands(fd, 'a', 3, R, S, RR);
	}
    else if (gap->number - min == 1)
    {
        gap = gap->front;
        if (gap->number - min == 0)
            commands(fd, 'a', 1, S);
        else
            commands(fd, 'a', 4, R, S, RR, S);
    }
    else//2
    {
        gap = gap->front;
        if (gap->number == 0)
            commands(fd, 'a', 4, S, R, S, RR);
        else//1
            commands(fd, 'a', 6, R, P, RR, S, P, S);
    }
}

void sort_three_b(t_gap *gap, int fd)
{
    int min;

    min = gap_min_num(gap);
	if (gap->number - min == 0)
	{
        gap = gap->front;
		if (gap->number - min == 1)
			commands(fd, '0', 6, PA, SB, PA, SB, PA, SB);
        else
            commands(fd, '0', 5, SB, PA, SB, PA, PA);
	}
    else if (gap->number - min == 1)
    {
        gap = gap->front;
        if (gap->number - min == 0)
            commands(fd, '0', 5, PA, SB, PA, SB, PA);
        else
            commands(fd, '0', 4, SB, PA, PA, PA);
    }
    else//2
    {
        gap = gap->front;
        if (gap->number == 0)
            commands(fd, '0', 4, PA, SB, PA, PA);
        else//1
            commands(fd, '0', 6, PA, PA, PA);
    }
}

void sort_gap(t_gap *gap, int fd, char belong)
{
    int gaplen;

    gaplen = gap_len(gap);
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

void sort_big_block(t_block *block, int fd)
{
    t_gap *first;
    t_gap *second;
    int middle;
    char belong;

    first = NULL;
    second = NULL;
    middle = block->param->elem_num / 2 + block->param->first;
    belong = block->belong;
    while (block)
    {
        commands(fd, belong, 1, P);
        if (block->gap->number <= middle)
            gap_put_before(&first, gap_new(block->gap->number));
        else
        {
            gap_put_after(second, gap_new(block->gap->number));
            commands(fd, belconv(belong), 1, R);
        }
        block = block->front;
    }
    sort_gap(first, fd, belconv(belong));
    if (belong == 'a')
        up_commands(0, gap_len(second));
    else if (belong == 'b')
        up_commands(gap_len(second), 0);
    sort_gap(second, fd, belconv(belong));
}

int block_sort(t_lists *lists)
{
	int fd;
    char mark;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
    if (lists->block_a == NULL)
        mark = 'b';
    else if (lists->block_b == NULL)
        mark = 'a';
    else if (lists->block_a->param->first < lists->block_b->param->first)
        mark = 'a';
    else
        mark = 'b';
    if (mark == 'a')
    {
        if (lists->block_a->param->elem_num > 3)
            sort_big_block(lists->block_a, fd);
        if (lists->block_a->param->elem_num == 3)
            sort_three_a(lists->block_a->gap, fd);
        if (lists->block_a->param->elem_num == 2)
            sort_two_a(lists->block_a->gap, fd);
        block_print(lists->block_a, "------sort------");
        lists->block_a = block_del(lists->block_a);
    }
    if (mark == 'b')
    {
        if (lists->block_b->param->elem_num > 3)
            sort_big_block(lists->block_b, fd);
        if (lists->block_b->param->elem_num == 3)
            sort_three_b(lists->block_b->gap, fd);
        if (lists->block_b->param->elem_num == 2)
            sort_two_b(lists->block_b->gap, fd);
        block_print(lists->block_b, "------sort------");
        lists->block_b = block_del(lists->block_b);
    }
    close (fd);
    return (0);
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