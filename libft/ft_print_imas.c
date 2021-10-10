/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_imas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:49 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:02:08 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_imas(int *mas, int razm_mas)
{
	int	i;

	i = 0;
	if (mas == NULL)
		return (-1);
	while (i < razm_mas)
	{
		ft_putnbr_fd(mas[i], 1);
		ft_putchar_fd('\0', 1);
		i++;
	}
	return (1);
}
