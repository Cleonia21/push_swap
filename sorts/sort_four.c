/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:28 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 15:15:00 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_four_a(t_gap *gap, int fd)
{
	t_gap	*buf;
	int		retval;

	retval = 0;
	buf = NULL;
	while (gap->front != NULL)
	{
		if (gap->number == 3)
			gap_swap(gap, fd);
		else if (gap->number == 2)
		{
			ft_putstr_fd("ra-", fd);
			retval++;
			gap = gap->front;
		}
		else
		{
			ft_putstr_fd("pb-", fd);
			retval += gap_put_before(&buf, gap_new(gap->number));
			gap = gap->front;
		}
	}
	if (retval == 1)
		ft_putstr_fd("rra-", fd);
	return (retval + sort_gap(buf, fd, 'b', gap_len(buf)) - 1);
}

int	sort_four_b(t_gap *gap, int fd)
{
	t_gap	*buf;
	int		retval;

	retval = 0;
	buf = NULL;
	while (gap != NULL)
	{
		if (gap->number == 0)
			ft_putstr_fd("rb-", fd);
		else
		{
			ft_putstr_fd("pa-", fd);
			retval += gap_put_before(&buf, gap_new(gap->number));
		}
		gap = gap->front;
	}
	retval += sort_gap(buf, fd, 'a', gap_len(buf));
	ft_putstr_fd("rrb-pa-", fd);
	return (retval);
}
