// #include "../push_swap.h"

// /*int *gap_in_str(t_gap *gap)
// {
// 	int first;
// 	char *str;
// 	int i;
// 	int elem_num;
// 	t_gap *buf_gap;

// 	buf_gap = gap;
// 	elem_num = 0;
// 	first = buf_gap->number;
// 	while (buf_gap)
// 	{
// 		elem_num++;
// 		if (first > buf_gap->number)
// 			first = buf_gap->number;
// 		buf_gap = buf_gap->front;
// 	}
// 	str = (char *)malloc(sizeof(char) * elem_num + 1);
// 	str[elem_num] = '\0';
// 	buf_gap = gap;
// 	while (i < elem_num)
// 	{
// 		str = buf_gap->number - first + '0';
// 		i++;
// 		buf_gap = buf_gap->front;
// 	}
// 	return (str);
// }*/

// int *gap_conv(t_gap *gap, int len)
// {
// 	int *mas;
// 	int min;

// 	mas = (int *)malloc(sizeof(int) * len);
// 	min = gap->number;
// 	while (gap)
// 	{
// 		if (min < gap->number)
// 			min = gap->number;
// 		gap = gap->front;
// 	}
// 	return (mas);
// }

// static int sort_three_a(t_gap *gap, char belong, int fd)
// {
// 	int com;
// 	int *mas;

// 	com = 0;
// 	mas = gap_conv(gap, 3);
// 	if (mas[0] == 1)
// 	{
// 		if (mas[1] == 2)
// 			return (0);
// 		write();
// 	}
// }

// void block_sort(t_lists *lists)
// {
// 	int fd;

// 	fd = open("commands.inf", O_WRONLY | O_APPEND);
// 	if (fd == -1)
// 		return (NULL);
	
// }