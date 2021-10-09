/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_into_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:49 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/09 17:24:05 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	trim_into_three(t_lists *lists)
{
	int fd;
	int b_first;
	char belong;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	b_first = -1;
	if (lists->block_b)
		b_first = lists->block_b->param->first;
	if (lists->block_a->param->first > b_first)
		belong = 'a';
	else if (lists->block_a->param->first < b_first)
		belong = 'b';
	if (separator(lists, belong, fd) == -1)
		return (-1);
	close (fd);
	return (0);
}