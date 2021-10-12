/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsort_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:44 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 15:14:48 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_nums
{
	int				first;
	int				second;
	int				third;
}					t_nums;

static	t_nums	initial_nums(t_gap *gap, int sum_com)
{
	t_nums	nums;

	if (sum_com == 2)
	{
		nums.second = gap->number;
		gap = gap->front;
		nums.third = gap->number;
		gap = gap->front->front;
		nums.first = gap->number;
	}
	else
	{
		if (sum_com == 0)
			gap = gap->front;
		nums.first = gap->number;
		gap = gap->front;
		if (sum_com == 1)
			gap = gap->front;
		nums.second = gap->number;
		gap = gap->front;
		nums.third = gap->number;
	}
	return (nums);
}

static	int	ft_sort_three(t_gap *gap, int fd, int sum_com)
{
	t_nums	nums;

	nums = initial_nums(gap, sum_com);
	if (nums.first == 0)
	{
		if (nums.second == 2)
			ft_putstr_fd("pb-sa-pa-", fd);
	}
	else if (nums.first == 1)
	{
		if (nums.second == 0)
			ft_putstr_fd("sa-", fd);
		else if (nums.second == 2)
			ft_putstr_fd("ra-sa-rra-sa-", fd);
	}
	else if (nums.first == 2)
	{
		if (nums.second == 0)
			ft_putstr_fd("ra-pb-rra-sa-pa-", fd);
		else if (nums.second == 1)
			ft_putstr_fd("ra-sa-pb-rra-sa-pa-", fd);
	}
	return (0);
}

void	lsort_four(t_gap *gap, int fd)
{
	int		sum_com;
	t_gap	*buf_gap;

	sum_com = 0;
	buf_gap = gap;
	while (buf_gap->number != 3)
	{
		sum_com++;
		buf_gap = buf_gap->front;
	}
	if (sum_com == 0)
		ft_putstr_fd("ra-", fd);
	else if (sum_com == 1)
		ft_putstr_fd("sa-ra-", fd);
	else if (sum_com == 2)
		ft_putstr_fd("rra-", fd);
	ft_sort_three(gap, fd, sum_com);
}
