/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_imas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:54:58 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:01:05 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	*ft_sort(int *sort_mas, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (sort_mas[j] > sort_mas[j + 1])
			{
				tmp = sort_mas[j];
				sort_mas[j] = sort_mas[j + 1];
				sort_mas[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sort_mas);
}

int	*ft_sort_imas(int *mas, int len)
{
	int	*sort_mas;

	if (mas == NULL)
		return (NULL);
	sort_mas = (int *)malloc(sizeof(int) * len);
	if (sort_mas == NULL)
		return (NULL);
	sort_mas = (int *)ft_memcpy(sort_mas, mas, len * sizeof(int));
	sort_mas = ft_sort(sort_mas, len);
	return (sort_mas);
}
