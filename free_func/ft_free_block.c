/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:48:37 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:48:45 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_free_block(t_block **block)
{
	if (*block)
	{
		if ((*block)->gap)
			ft_free_ollgap(&((*block)->gap));
		if ((*block)->param)
			free ((*block)->param);
		free (*block);
	}
	*block = NULL;
	return (NULL);
}
