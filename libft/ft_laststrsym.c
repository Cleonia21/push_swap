/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_laststrsym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:37 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:02:24 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns a pointer to the last character in the string */
char	*ft_laststrsym(char *str)
{
	while (*str != '\0' && *str != '\n')
		str++;
	return (--str);
}
