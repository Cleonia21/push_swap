/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_cut_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:49 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:53:26 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_block	*block_cut_last(t_block *block)
{
	t_block	*buf;
	t_block	*last;

	if (block == NULL)
		return (NULL);
	buf = block;
	last = last_block(block);
	if (buf == last)
		return (last);
	while (buf->front != last)
		buf = buf->front;
	buf->front = NULL;
	return (last);
}
