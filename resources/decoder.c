/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@school.42>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:36:00 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/08 13:42:39 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	decoder()
{
	char	*str;
	int		fd;

	fd = open("commands.inf", O_RDONLY);
	if (fd == -1)
		ft_error(FILE_OPEN, "decoder");
	get_next_line(fd, &str);
	if (str == NULL)
		ft_error(MEMORY_ALLOC, "decoder");
	simplificator(str);
	fd = 0;
	while (*str != '\0')
	{
		if (*str != '-' || *(str + 1) != '-')
		{
			if (fd == 0 && *str == '-')
				str++;
			if (*str == '-')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(*str, 1);
			fd++;
		}
		str++;
	}
}
