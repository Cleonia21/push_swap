/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:27 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 20:26:31 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	get_belong(t_lists *lists)
{
	char	belong;

	if (lists->block_a == NULL)
		belong = 'b';
	else if (lists->block_b == NULL)
		belong = 'a';
	else if (lists->block_a->param->first > lists->block_b->param->first)
		belong = 'a';
	else
		belong = 'b';
	if (lists->block_a->param->first == -1 && lists->block_b == NULL)
		return ('e');
	return (belong);
}

char	block_sort(t_lists *lists, int fd)
{
	char	belong;
	t_block	*buf_block;

	buf_block = NULL;
	belong = get_belong(lists);
	if (belong == 'a')
	{
		buf_block = lists->block_a;
		if (sort_gap(buf_block->gap, fd, belong, gap_len(buf_block->gap)) != 0)
			return ('o');
		buf_block->gap = NULL;
		lists->block_a = lists->block_a->front;
	}
	else if (belong == 'b')
	{
		buf_block = lists->block_b;
		if (sort_gap(buf_block->gap, fd, belong, gap_len(buf_block->gap)) != 0)
			return ('o');
		buf_block->gap = NULL;
		lists->block_b = lists->block_b->front;
	}
	ft_free_block(&buf_block);
	return (belong);
}
