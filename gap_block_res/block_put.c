/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:53 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:50:54 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	block_put_after(t_block **list, t_block *after)
{
	t_block	*buf;

	if (after == NULL || list == NULL)
		return (-1);
	if (*list == NULL)
		*list = after;
	else if (*list == after)
		return (0);
	else
	{
		buf = last_block(*list);
		buf->front = after;
	}
	return (0);
}

int	block_put_before(t_block **list, t_block *before)
{
	if (before == NULL)
		return (-1);
	if (*list == NULL)
		*list = before;
	else if (*list == before)
		return (0);
	else
	{
		before->front = *list;
		*list = before;
	}
	return (0);
}
