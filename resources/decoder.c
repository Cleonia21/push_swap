/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:36:00 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:41:41 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	ft_print(char *str)
{
	int	mark;

	mark = 0;
	while (*str != '\0')
	{
		if (*str != '-' || *(str + 1) != '-')
		{
			if (mark == 0 && *str == '-')
				str++;
			if (*str == '-')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(*str, 1);
			mark++;
		}
		str++;
	}
}

int	decoder(void)
{
	char	*str;
	char	*buf_str;
	int		fd;

	fd = open("commands.inf", O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_next_line(fd, &str) == -1)
		return (-1);
	if (str == NULL)
		return (-1);
	buf_str = str;
	simplificator(str);
	ft_print(str);
	free(buf_str);
	return (1);
}
