/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:55 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:50:58 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	gap_del(t_gap *gap)
{
	if (gap)
	{
		if (gap->back)
			gap->back->front = gap->front;
		if (gap->front)
			gap->front->back = gap->back;
		free(gap);
		gap = NULL;
	}
}
