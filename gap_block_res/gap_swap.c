/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:09 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:51:44 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	gap_swap(t_gap *gap, int fd)
{
	int	buf;

	if (gap == NULL || gap->front == NULL)
		ft_error(SWAP, "sort_four_a");
	buf = gap->number;
	gap->number = gap->front->number;
	gap->front->number = buf;
	ft_putstr_fd("sa-", fd);
}
