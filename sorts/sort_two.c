/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:20 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 13:19:36 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_two_a(t_gap *gap, int fd)
{
	int	first;
	int	second;

	first = -1;
	second = -1;
	if (gap)
		first = gap->number;
	if (gap && gap->front)
		second = gap->front->number;
	if (first != -1 && second != -1 && first > second)
		ft_putstr_fd("sa-", fd);
	return (0);
}

int	sort_two_b(t_gap *gap, int fd)
{
	int	first;
	int	second;

	first = -1;
	second = -1;
	if (gap)
	{
		first = gap->number;
		if (gap && gap->front)
		{
			second = gap->front->number;
			if (first < second)
				ft_putstr_fd("sb-pa-pa-", fd);
			else
				ft_putstr_fd("pa-pa-", fd);
		}
		else
			ft_putstr_fd("pa-", fd);
	}
	return (0);
}
