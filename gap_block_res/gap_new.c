/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:03 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:51:19 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_gap	*gap_new(int number)
{
	t_gap	*buf;

	buf = (t_gap *)malloc(sizeof(t_gap));
	if (buf == NULL)
		return (NULL);
	buf->number = number;
	buf->back = NULL;
	buf->front = NULL;
	return (buf);
}
