#include "push_swap.h"

void print_key(int key)
{
	if (key == SA)
		ft_putendl_fd("sa", 1);
	if (key == SB)
		ft_putendl_fd("sb", 1);
	if (key == SASB)
		ft_putendl_fd("ss", 1);
	if (key == PA)
		ft_putendl_fd("pa", 1);
	if (key == PB)
		ft_putendl_fd("pb", 1);
	if (key == RA)
		ft_putendl_fd("ra", 1);
	if (key == RB)
		ft_putendl_fd("rb", 1);
	if (key == RARB)
		ft_putendl_fd("rr", 1);
	if (key == RRA)
		ft_putendl_fd("rra", 1);
	if (key == RRB)
		ft_putendl_fd("rrb", 1);
	if (key == RRARRB)
		ft_putendl_fd("rrr", 1);
}

void decoder()
{
	int fd;
	int key;
	char *str;

	fd = open("commands.inf", O_RDONLY);
	if (fd == -1)
		ft_error(FILE_OPEN, "decoder");
	get_next_line(fd, &str);
	if (str == NULL)
		ft_error(MEMORY_ALLOC, "decoder");
	while (*str != '\0')
	{
		if (*str == '-')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
}

int ft_cnum(const char *str, char c)
{
	int num;

	num = 0;
	while (*str != '\0')
	{
		if (*str == c)
			num++;
		str++;
	}
	return (num);
}

t_gap *argv_mas_to_gap(int argc, char **argv)
{
	t_gap *gap;
	int i;

	i = 1;
	gap = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		i = 0;
		argc = ft_cnum(argv[1], ' ') + 1;
		argv = ft_split(argv[1], ' ');
	}
	while (i < argc)
	{
		gap_put_after(&gap, gap_new(ft_atoi(argv[i])));
		i++;
	}
	return (gap);
}

int main(int argc, char **argv)
{
	t_gap *gap;
	t_lists lists;
	int fd;
	int retval;

	fd = open("commands.inf", O_TRUNC);
	if (fd == -1)
		ft_error(FILE_OPEN, "main");
	close (fd);
    gap = argv_mas_to_gap(argc, argv);
	lists.block_a = block_new(gap, 'a');
	block_put_after(&(lists.block_a), block_new(gap_new(-1), 'a'));
	//blocks_print(lists.block_a, ";;;;;;;;;;;;;;");
	sorter(&lists);
	decoder();
	exit(0);
}