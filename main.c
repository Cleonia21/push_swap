#include "push_swap.h"

int is_argv_num(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

char	*make_pattern()
{
	char *pattern;

	pattern = (char *)malloc(sizeof(char) * 10);
	if (pattern == NULL)
		ft_error(MEMORY_ALLOC, "make_pattern");
	pattern[0] = '2';
	pattern[1] = '1';
	pattern[2] = '4';
	pattern[3] = '7';
	pattern[4] = '4';
	pattern[5] = '8';
	pattern[6] = '3';
	pattern[7] = '6';
	pattern[8] = '4';
	pattern[9] = '\0';
	return (pattern);
}
//[−2 147 483 648, +2 147 483 647]
int	is_argv_int(char *str)
{
	char *pattern;
	int sign;

	pattern = make_pattern();
	sign = 1;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) < 10)
		return (1);
	while (*pattern != '\0')
	{
		if (*pattern < *str)
			return (0);
		if (*pattern > *str)
			return (1);
		pattern++;
		str++;
	}
	if (sign == 1 && *str > '7')
		return (0);
	if (sign == -1 && *str > '8')
		return (0);
	return (1);
}

int	*sort_imas(int *mas, int len)
{
	int *sort_mas;
	int i;
	int j;
	int tmp;

	i = 0;
	sort_mas = (int *)malloc(sizeof(int) * len);
	sort_mas = (int *)ft_memcpy(sort_mas, mas, len * sizeof(int));
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (sort_mas[j] > sort_mas[j + 1])
			{
				tmp = sort_mas[j];
				sort_mas[j] = sort_mas[j + 1];
				sort_mas[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sort_mas);
}

int search_numindex(int *mas, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (mas[i] == num)
			return (i);
		i++;
	}
	ft_error(OTHER, "search_numindex... num not find");
	return (-1);
}

void	chek_to_repeat(int *mas, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (mas[i] == mas[i + 1])
			ft_error(OTHER, "argv duplicate numbers");
		i++;
	}
}

t_gap	*mas_to_gap(int *mas, int argc)
{
	t_gap *gap;
	int	*sort_mas;
	int i;
	int tmp;

	gap = NULL;
	i = 0;
	sort_mas = sort_imas(mas, argc);
	chek_to_repeat(sort_mas, argc);
	while (i < argc)
	{
		tmp = search_numindex(sort_mas, argc, mas[i]);
		gap_put_after(&gap, gap_new(tmp));
		i++;
	}
	return (gap);
}

t_gap *argv_mas_to_gap(int argc, char **argv)
{
	int *mas;
	int i;

	i = 0;
	if (argc < 2)
		ft_error(ARGV, "argv_mas_to_gap");
	else if (argc == 2)
	{
		argc = ft_symbol_num(argv[1], ' ') + 1;
		argv = ft_split(argv[1], ' ');
	}
	else
	{
		argc--;
		argv++;
	}
	mas = (int *)malloc(sizeof(int) * argc);
	if (mas == NULL)
		ft_error(MEMORY_ALLOC, "argv_mas... bad malloc");
	while (i < argc)
	{
		if (argv[i] == NULL)
			ft_error(ARGV, "argv_mas... maybe a problem with spaces");
		if (is_argv_num(argv[i]) == 0)
			ft_error(ARGV, "argv_mas... maybe in argv not a number");
		if (is_argv_int(argv[i]) == 0)
			ft_error(ARGV, "argv_mas... maybe number type not int");
		mas[i] = ft_atoi(argv[i]);
		i++;
	}
	return (mas_to_gap(mas, argc));
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
	sorter(&lists);
	decoder();
	exit(0);
}