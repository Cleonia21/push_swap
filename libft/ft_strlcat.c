/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:09 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:10 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	while (len_dst + i < dstsize - 1 && *(src + i) != '\0' && dstsize > 0)
	{
		*(dst + len_dst + i) = *(src + i);
		i++;
	}
	*(dst + len_dst + i) = '\0';
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + len_src);
}
