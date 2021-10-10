/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:11 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:51:53 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_block	*last_block(t_block *block)
{
	if (block == NULL)
		return (NULL);
	while (block->front)
		block = block->front;
	return (block);
}

t_gap	*last_gap(t_gap *gap)
{
	if (gap == NULL)
		return (NULL);
	while (gap->front)
		gap = gap->front;
	return (gap);
}
