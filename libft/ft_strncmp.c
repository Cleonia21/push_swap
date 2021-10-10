/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:15 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:16 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char *)s1) + 1;
	len2 = ft_strlen((char *)s2) + 1;
	if (len1 > len2)
		len1 = len2;
	if (len > len1)
		len = len1;
	return ((int)ft_memcmp((char *)s1, (char *)s2, len));
}
