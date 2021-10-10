/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_gap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:17 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:28:13 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	t_gap	*converter(int argc, char **argv, int mark)
{
	t_gap	*gap;
	int		*imas;

	imas = argv_to_imas(argc, argv);
	if (imas == NULL && mark == 1)
		return (ft_free_ccmas(argv));
	else if (imas == NULL && mark == 0)
		return (NULL);
	gap = imas_to_gap(imas, argc);
	if (mark == 1)
		ft_free_ccmas(argv);
	ft_free_imas(imas);
	return (gap);
}

t_gap	*argv_to_gap(int argc, char **argv)
{
	t_gap	*gap;
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
	gap = converter(argc, argv, mark);
	return (gap);
}
