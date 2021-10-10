/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_into_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:49 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 20:26:39 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	trim_into_three(t_lists *lists, int	fd)
{
	int		b_first;
	char	belong;

	b_first = -1;
	if (lists->block_b)
		b_first = lists->block_b->param->first;
	if (lists->block_a->param->first > b_first)
		belong = 'a';
	else if (lists->block_a->param->first < b_first)
		belong = 'b';
	if (separator(lists, belong, fd) == -1)
		return (-1);
	return (0);
}
