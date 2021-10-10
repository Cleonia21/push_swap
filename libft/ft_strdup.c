/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:03 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:04 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*new_str;

	len = ft_strlen((char *)str);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (*str)
		*new_str++ = *str++;
	*new_str = '\0';
	return (new_str - len);
}
