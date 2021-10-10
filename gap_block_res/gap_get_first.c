/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_get_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:58 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:52:58 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_gap	*gap_get_first(t_gap *gap)
{
	if (gap == NULL)
		return (NULL);
	while (gap->back != NULL)
		gap = gap->back;
	return (gap);
}
