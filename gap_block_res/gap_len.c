/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:00 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:52:46 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	gap_len(t_gap *gap)
{
	int	len;

	len = 0;
	if (gap == NULL)
		return (0);
	while (gap)
	{
		len++;
		gap = gap->front;
	}
	return (len);
}

int	gap_len_forblock(t_block *block)
{
	t_gap	*gap;
	int		i;

	i = 0;
	if (block == NULL)
		return (0);
	if (block->gap == NULL)
		return (0);
	gap = block->gap;
	while (gap)
	{
		i++;
		gap = gap->front;
	}
	return (i);
}
