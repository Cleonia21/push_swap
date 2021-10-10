/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:18 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:19 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	*s2;

	s1 = (char *)s;
	s2 = NULL;
	if (c == 0)
		return (s1 + ft_strlen(s1));
	while (*s1)
	{
		s1 = ft_memchr(s1, c, ft_strlen(s1) + 1);
		if (s1 == NULL)
			return (s2);
		s2 = (char *)s1;
		s1++;
	}
	return (s2);
}
