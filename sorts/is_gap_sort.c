/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_gap_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:52 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 14:05:57 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_gap_sort(t_gap *gap, char belong)
{
	int	buf;

	if (gap == NULL)
		return (-1);
	buf = gap->number;
	while (gap && belong == 'a')
	{
		if (gap->front == NULL)
			return (1);
		gap = gap->front;
		if (gap->number != buf + 1)
			return (-1);
		buf = gap->number;
	}
	while (gap && belong == 'b')
	{
		if (gap->front == NULL)
			return (1);
		gap = gap->front;
		if (gap->number != buf - 1)
			return (-1);
		buf = gap->number;
	}
	return (-1);
}
