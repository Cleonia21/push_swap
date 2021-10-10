/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_min_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:01 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:52:27 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	gap_min_num(t_gap *gap)
{
	int	min;

	if (gap == NULL)
		return (0);
	min = gap->number;
	while (gap->front)
	{
		gap = gap->front;
		if (gap->number < min)
			min = gap->number;
	}
	return (min);
}
