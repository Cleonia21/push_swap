/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:44 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:54:45 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*take;
	char	*give;

	if (dst == NULL && src == NULL)
		return (NULL);
	take = (char *)dst;
	give = (char *)src;
	while (n-- > 0)
		*take++ = *give++;
	return (dst);
}
