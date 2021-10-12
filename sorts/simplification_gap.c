/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification_gap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:39 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 13:15:02 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_gap	*simplification_gap(t_gap *gap)
{
	t_gap	*buf;
	int		min_num;

	min_num = gap_min_num(gap);
	buf = gap;
	while (buf)
	{
		buf->number -= min_num;
		buf = buf->front;
	}
	return (gap);
}
