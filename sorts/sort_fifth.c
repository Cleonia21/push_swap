/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fifth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:32 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 13:20:47 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_fifth_b(t_gap *gap, int fd)
{
	t_gap	*a_gap;
	t_gap	*under_gap;
	int		retval;

	retval = 0;
	a_gap = NULL;
	under_gap = NULL;
	while (gap)
	{
		if (gap->number >= 2)
		{
			ft_putstr_fd("pa-", fd);
			retval += gap_put_before(&a_gap, gap_new(gap->number));
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ft_putstr_fd("pa-ra-", fd);
			retval += gap_put_after(&under_gap, gap_new(gap->number));
		}
		gap = gap->front;
	}
	retval += sort_gap(a_gap, fd, 'a', gap_len(a_gap));
	ft_putstr_fd("rra-rra-", fd);
	retval += sort_gap(under_gap, fd, 'a', gap_len(under_gap));
	return (retval);
}

static	int	b_under_sorts(t_gap *b_gap, t_gap *under_gap, int fd)
{
	int	retval;

	retval = 0;
	retval += sort_gap(b_gap, fd, 'b', gap_len(b_gap));
	ft_putstr_fd("rra-rra-", fd);
	retval += sort_gap(under_gap, fd, 'a', gap_len(under_gap));
	return (retval);
}

int	sort_fifth_a(t_gap *gap, int fd)
{
	t_gap	*b_gap;
	t_gap	*under_gap;
	int		retval;

	retval = 0;
	b_gap = NULL;
	under_gap = NULL;
	while (gap->front != NULL)
	{
		if (gap->number == 4)
			gap_swap(gap, fd);
		else if (gap->number == 3 || gap->number == 2)
		{
			ft_putstr_fd("pb-", fd);
			retval += gap_put_before(&b_gap, gap_new(gap->number));
			gap = gap->front;
		}
		else if (gap->number == 1 || gap->number == 0)
		{
			ft_putstr_fd("ra-", fd);
			retval += gap_put_after(&under_gap, gap_new(gap->number));
			gap = gap->front;
		}
	}
	return (retval + b_under_sorts(b_gap, under_gap, fd));
}
