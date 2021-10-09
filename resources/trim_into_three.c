/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_into_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@school.42>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:49 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/08 22:53:09 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		separator(t_lists *lists, int b_first, int fd)
{
	t_separator	*sepr;
	t_block		*buf_block;
	int			retval;

	sepr = new_sepr();
	retval = 0;
	if (sepr == NULL)
		return (-1);
	if (lists->block_a->param->first > b_first)
	{
		buf_block = lists->block_a->front;
		sepr = block_sepr_a(lists->block_a, sepr, fd);
		lists->block_a = buf_block;
		if (sepr == NULL)
			return (-1);
		retval += block_put_before(&(lists->block_b), block_new(sepr->gap1, 'b'));
		retval += block_put_after(&(lists->block_a), block_new(sepr->gap2, 'a'));
		retval += block_put_after(&(lists->block_b), block_new(sepr->gap3, 'b'));
	}
	else if (lists->block_a->param->first < b_first)
	{
		buf_block = lists->block_b->front;
		sepr = block_sepr_b(lists->block_b, sepr, fd);
			lists->block_b = buf_block;
		if (sepr == NULL)
			return (-1);
		retval += block_put_before(&(lists->block_a), block_new(sepr->gap1, 'a'));
		retval += block_put_after(&(lists->block_a), block_new(sepr->gap2, 'a'));
		retval += block_put_after(&(lists->block_b), block_new(sepr->gap3, 'b'));
	}
	if (retval != 0)
		return (-1);
	return (0);
}

int	trim_into_three(t_lists *lists)
{
	int fd;
	int b_first;

	fd = open("commands.inf", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	b_first = -1;
	if (lists->block_b)
		b_first = lists->block_b->param->first;
	if (separator(lists, b_first, fd) == -1)
		return (-1);
	close (fd);
	return (0);
}