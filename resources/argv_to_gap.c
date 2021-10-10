#include "../push_swap.h"

static	int	search_numindex(int *mas, int len, int num)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (mas[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

static int	chek_to_repeat(int *mas, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (mas[i] == mas[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static	t_gap	*imas_to_gap(int *mas, int argc)
{
	t_gap *gap;
	int	*sort_mas;
	int i;
	int tmp;

	gap = NULL;
	i = 0;
	sort_mas = ft_sort_imas(mas, argc);
	if (sort_mas == NULL)
		return (ft_free_imas(sort_mas));
	if (chek_to_repeat(sort_mas, argc) == 0)
		return (ft_free_imas(sort_mas));
	while (i < argc)
	{
		tmp = search_numindex(sort_mas, argc, mas[i]);
		if (tmp == -1)
		{
			ft_free_ollgap(&gap);
			return (ft_free_imas(sort_mas));
		}
		if (gap_put_after(&gap, gap_new(tmp)) == -1)
		{
			ft_free_ollgap(&gap);
			return (ft_free_imas(sort_mas));
		}
		i++;
	}
	ft_free_imas(sort_mas);
	return (gap);
}

static	int	*argv_to_imas(int argc, char **argv)
{
	int *mas;
	int i;

	i = 0;
	mas = (int *)malloc(sizeof(int) * argc);
	if (mas == NULL)
		return (NULL);
	while (i < argc)
	{
		if (argv[i] == NULL)
			return(ft_free_imas(mas));
		if (ft_isstrnum(argv[i]) == 0)
			return(ft_free_imas(mas));
		if (ft_isstrint(argv[i]) == 0)
			return(ft_free_imas(mas));
		mas[i] = ft_atoi(argv[i]);
		i++;
	}
	return (mas);
}

t_gap *argv_to_gap(int argc, char **argv)
{
	t_gap	*gap;
	int		*imas;
	int		mark;

	mark = 0;
	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		argc = ft_symbol_num(argv[1], ' ') + 1;
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (NULL);
		mark = 1;
	}
	else
	{
		argc--;
		argv++;
	}
	imas = argv_to_imas(argc, argv);
	if (imas == NULL && mark == 1)
		return (ft_free_ccmas(argv));
	else if (imas == NULL && mark == 0)
		return (NULL);
	gap = imas_to_gap(imas, argc);
	if (mark == 1)
		ft_free_ccmas(argv);
	ft_free_imas(imas);
	if (gap == NULL)
		return (NULL);
	return (gap);
}
