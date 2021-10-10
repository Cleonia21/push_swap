/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:05 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:06 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lenght;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	lenght = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new_str = (char *)malloc(lenght + 1);
	if (new_str == NULL)
		return (NULL);
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (new_str - lenght);
}
