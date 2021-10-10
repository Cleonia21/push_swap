/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:42 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:54:43 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	while (n-- > 0)
	{
		if (*m1 - *m2 != 0)
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	return (0);
}
