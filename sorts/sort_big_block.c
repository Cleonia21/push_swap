/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:59:02 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 20:14:56 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	create_first(t_gap **first, int number, char belong, int fd)
{
	int	retval;

	retval = gap_put_before(first, gap_new(number));
	if (belong == 'a')
		ft_putstr_fd("pb-", fd);
	if (belong == 'b')
		ft_putstr_fd("pa-", fd);
	return (retval);
}

static	int	create_second(t_gap **second, int number, char belong, int fd)
{
	int	retval;

	retval = gap_put_after(second, gap_new(number));
	if (belong == 'a')
		ft_putstr_fd("ra-", fd);
	if (belong == 'b')
		ft_putstr_fd("pa-ra-", fd);
	return (retval);
}

int	sort_big_block(t_gap *gap, int fd, char belong)
{
	t_gap	*first;
	t_gap	*second;
	int		retval;

	retval = 0;
	first = NULL;
	second = NULL;
	while (gap)
	{
		if (gap->number >= 4)
			retval += create_first(&first, gap->number, belong, fd);
		else
			retval += create_second(&second, gap->number, belong, fd);
		gap = gap->front;
	}
	retval += sort_gap(first, fd, belconv(belong), gap_len(first));
	up_commands(gap_len(second), 0);
	retval += sort_gap(second, fd, 'a', gap_len(second));
	return (retval);
}
