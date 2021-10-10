/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbol_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:23 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:24 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_symbol_num(const char *str, char c)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		if (*str == c)
			num++;
		str++;
	}
	return (num);
}
