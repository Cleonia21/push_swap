/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ollgap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:48:59 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:49:00 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_free_ollgap(t_gap **gap)
{
	t_gap	*buf;

	if (*gap)
	{
		while ((*gap)->front != NULL)
		{
			buf = (*gap)->front;
			free (*gap);
			(*gap) = buf;
		}
		free (*gap);
	}
	*gap = NULL;
	return (NULL);
}
