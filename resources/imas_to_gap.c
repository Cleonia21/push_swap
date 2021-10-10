/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imas_to_gap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:33 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:31:42 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static	int	chek_to_repeat(int *mas, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (mas[i] == mas[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_gap	*imas_to_gap(int *mas, int argc)
{
	t_gap	*gap;
	int		*sort_mas;
	int		i;
	int		tmp;

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
		if ((tmp == -1) || (gap_put_after(&gap, gap_new(tmp)) == -1))
		{
			ft_free_ollgap(&gap);
			return (ft_free_imas(sort_mas));
		}
		i++;
	}
	ft_free_imas(sort_mas);
	return (gap);
}
