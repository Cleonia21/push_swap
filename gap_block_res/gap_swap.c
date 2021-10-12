/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:50:09 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 15:12:32 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	gap_swap(t_gap *gap, int fd)
{
	int	buf;

	buf = gap->number;
	gap->number = gap->front->number;
	gap->front->number = buf;
	ft_putstr_fd("sa-", fd);
}
