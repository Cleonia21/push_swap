/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:07 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:51:41 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	gap_put_after(t_gap **elem, t_gap *after)
{
	t_gap	*buf;

	buf = *elem;
	if (after == NULL)
		return (-1);
	if (*elem == NULL)
	{
		*elem = after;
		return (0);
	}
	while (buf->front != NULL)
		buf = buf->front;
	after->front = NULL;
	after->back = buf;
	buf->front = after;
	return (0);
}

int	gap_put_before(t_gap **elem, t_gap *before)
{
	if (before == NULL)
		return (-1);
	if (*elem == NULL)
	{
		*elem = before;
		return (0);
	}
	before->back = (*elem)->back;
	before->front = *elem;
	(*elem)->back = before;
	*elem = before;
	return (0);
}
