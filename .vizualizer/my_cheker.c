// #include "../push_swap.h"

// static void push(t_gap **gap1, t_gap **gap2)
// {
// 	t_gap *buf;

// 	buf = *gap1;
// 	*gap1 = (*gap1)->front;
// 	gap_put_before(gap2, gap_new(buf->number));
// 	gap_del(buf);
// }

// static void	swap(t_gap *gap)
// {
// 	int	buf;

// 	if (gap != NULL || gap->front != NULL)
// 	{
// 		buf = gap->number;
// 		gap->number = gap->front->number;
// 		gap->front->number = buf;
// 	}
// }

// static void rotate(t_gap **gap)
// {
// 	t_gap *buf;
// 	t_gap *buf2;

// 	buf = gap_get_last(*gap);
// 	if (buf != NULL && buf != *gap)
// 	{
// 		if ((*gap)->front == buf)
// 			swap(*gap);
// 		else
// 		{
// 			buf2 = *gap;
// 			*gap = (*gap)->front;
// 			(*gap)->back = NULL;
// 			buf2->front = NULL;
// 			buf2->back = buf;
// 			buf->front = buf2;
// 		}
// 	}
// }

// static void revrotate(t_gap **gap)
// {
// 	t_gap *buf;
// 	t_gap *buf2;

// 	buf = gap_get_last(*gap);
// 	buf2 = buf->back;
// 	if (buf != NULL && buf != *gap)
// 	{
// 		if ((*gap)->front == buf)
// 			swap(*gap);
// 		else
// 		{
// 			(*gap)->back = buf;
// 			buf->back = NULL;
// 			buf->front = *gap;
// 			*gap = buf;
// 			buf2->front = NULL;
// 		}
// 	}
// }

// static void printer(t_gap *gap_a, t_gap *gap_b)
// {
// 	int len_a;
// 	int len_b;
// 	int tab;

// 	len_a = gap_len(gap_a);
// 	len_b = gap_len(gap_b);
// 	if (len_a > len_b)
// 	{
// 		tab = len_a - len_b;
// 		while (tab > 0)
// 		{
// 			printf("%i     \n", gap_a->number);
// 			gap_a = gap_a->front;
// 			tab--;
// 		}
// 		while (gap_a)
// 		{
// 			printf("%i    %i\n", gap_a->number, gap_b->number);
// 			gap_a = gap_a->front;
// 			gap_b = gap_b->front;
// 		}
// 	}
// 	else if (len_a <= len_b)
// 	{
// 		tab = len_b - len_a;
// 		while (tab > 0)
// 		{
// 			printf("     %i\n", gap_b->number);
// 			gap_b = gap_b->front;
// 			tab--;
// 		}
// 		while (gap_b)
// 		{
// 			printf("%i    %i\n", gap_a->number, gap_b->number);
// 			gap_a = gap_a->front;
// 			gap_b = gap_b->front;
// 		}
// 	}
// 	printf("_    _\na    b\n\n");
// }

// static void decoder(char *str, t_gap *gap_a, t_gap *gap_b)
// {
// 	int i;

// 	while (*str != '\0')
// 	{
// 		i = 0;
// 		getchar();
// 		while (*(str + i) != '-')
// 		{
// 			printf("%c", *(str + i));
// 			i++;
// 		}
// 		printf("\n");
// 		if (*str == 'p')
// 		{
// 			str++;
// 			if (*str == 'a')
// 				push(&gap_b, &gap_a);
// 			if (*str == 'b')
// 				push(&gap_a, &gap_b);
// 		}
// 		else if (*str == 's')
// 		{
// 			str++;
// 			if (*str == 'a')
// 				swap(gap_a);
// 			if (*str == 'b')
// 				swap(gap_b);
// 			if (*str == 's')
// 			{
// 				swap(gap_a);
// 				swap(gap_b);
// 			}
// 		}
// 		else if (*str == 'r' && *(str + 1) == 'r')
// 		{
// 			str = str + 2;
// 			if (*str == 'a')
// 				revrotate(&gap_a);
// 			if (*str == 'b')
// 				revrotate(&gap_b);
// 			if (*str == 'r')
// 			{
// 				revrotate(&gap_a);
// 				revrotate(&gap_b);
// 			}
// 		}
// 		else if (*str == 'r')
// 		{
// 			str++;
// 			if (*str == 'a')
// 				rotate(&gap_a);
// 			if (*str == 'b')
// 				rotate(&gap_b);
// 			if (*str == 'r')
// 			{
// 				rotate(&gap_a);
// 				rotate(&gap_b);
// 			}
// 		}
// 		str += 2;
// 		printer(gap_a, gap_b);
// 	}
// }

// int main(int argc, char **argv)
// {
// 	t_gap *gap_a;
// 	t_gap *gap_b;
// 	t_lists lists;
// 	char *str;
// 	int fd;

// 	gap_a = argv_mas_to_gap(argc, argv);
// 	gap_b = NULL;

// 	fd = open("commands.inf", O_RDONLY);
// 	if (fd == -1)
// 		ft_error(FILE_OPEN, "decoder");
// 	get_next_line(fd, &str);
// 	if (str == NULL)
// 		ft_error(MEMORY_ALLOC, "decoder");
// 	decoder(str, gap_a, gap_b);
// }