/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:34 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:02:35 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrnum(char *str)
{
	if (str == NULL)
		return (-1);
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
