/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:23 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 13:20:17 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_nums
{
	int				first;
	int				second;
	int				third;
}					t_nums;

t_nums	initial_nums(t_gap *gap)
{
	t_nums	nums;

	nums.first = gap->number;
	gap = gap->front;
	nums.second = gap->number;
	gap = gap->front;
	nums.third = gap->number;
	return (nums);
}

int	sort_three_a(t_gap *gap, int fd)
{
	t_nums	nums;

	nums = initial_nums(gap);
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

int	sort_three_b(t_gap *gap, int fd)
{
	t_nums	nums;

	nums = initial_nums(gap);
	if (nums.first == 2)
	{
		if (nums.second == 1)
			ft_putstr_fd("pa-pa-pa-", fd);
		else if (nums.second == 0)
			ft_putstr_fd("pa-pa-pa-sa-", fd);
	}
	else if (nums.first == 1)
	{
		if (nums.second == 2)
			ft_putstr_fd("sb-pa-pa-pa-", fd);
		else if (nums.second == 0)
			ft_putstr_fd("pa-ra-sb-pa-rra-pa-", fd);
	}
	else if (nums.first == 0)
	{
		if (nums.second == 2)
			ft_putstr_fd("sb-pa-sb-pa-pa-", fd);
		else if (nums.second == 1)
			ft_putstr_fd("pa-ra-pa-pa-sa-rra-", fd);
	}
	return (0);
}
