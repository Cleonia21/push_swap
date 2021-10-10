/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:34 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:41:13 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	t_separator	*new_sepr(void)
{
	t_separator	*sepr;

	sepr = (t_separator *)malloc(sizeof(t_separator));
	if (sepr == NULL)
		return (NULL);
	sepr->gap1 = NULL;
	sepr->gap2 = NULL;
	sepr->gap3 = NULL;
	return (sepr);
}

t_separator	*ft_sepr(t_lists *lists, t_separator	*sepr, int fd, char belong)
{
	t_block		*buf_block;

	if (belong == 'a')
	{
		buf_block = lists->block_a;
		sepr = block_sepr_a(lists->block_a, sepr, fd);
		if (sepr == NULL)
			return (NULL);
		lists->block_a = lists->block_a->front;
	}
	if (belong == 'b')
	{
		buf_block = lists->block_b;
		sepr = block_sepr_b(lists->block_b, sepr, fd);
		if (sepr == NULL)
			return (NULL);
		lists->block_b = lists->block_b->front;
	}
	ft_free_block(&buf_block);
	return (sepr);
}

int	separator(t_lists *l, char belong, int fd)
{
	t_separator	*sepr;
	int			retval;

	sepr = new_sepr();
	retval = 0;
	if (sepr == NULL)
		return (-1);
	if (belong == 'a')
		sepr = ft_sepr(l, sepr, fd, belong);
	else if (belong == 'b')
		sepr = ft_sepr(l, sepr, fd, belong);
	if (sepr == NULL)
		return (-1);
	if (belong == 'a')
		retval += block_put_before(&(l->block_b), block_new(sepr->gap1, 'b'));
	else if (belong == 'b')
		retval += block_put_before(&(l->block_a), block_new(sepr->gap1, 'a'));
	retval += block_put_after(&(l->block_a), block_new(sepr->gap2, 'a'));
	retval += block_put_after(&(l->block_b), block_new(sepr->gap3, 'b'));
	free(sepr);
	if (retval != 0)
		return (-1);
	return (0);
}
