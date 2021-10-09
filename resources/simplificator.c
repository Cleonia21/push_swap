/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplificator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@school.42>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:36:04 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/05 16:36:05 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int get_com_key(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == 's' && *(str + 1) == 'a')
		return (SA);
	if (*str == 's' && *(str + 1) == 'b')
		return (SB);
	if (*str == 'p' && *(str + 1) == 'a')
		return (PA);
	if (*str == 'p' && *(str + 1) == 'b')
		return (PB);
	if (*str == 'r' && *(str + 1) == 'a')
		return (RA);
	if (*str == 'r' && *(str + 1) == 'b')
		return (RB);
	if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		return (RRA);
	if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		return (RRB);
	return (0);
}

static int get_next_com_key(char *str)
{
	while (*str != '-' && *str != '\0')
		str++;
	if (*str == '\0')
		return (0);
	str++;
	return (get_com_key(str));
}

char *paste_dash(char *str)
{
	while (*str != '-' && *str != '\0')
	{
		*str = '-';
		str++;
	}
	if (*str == '\0')
		return (str);
	return (++str);
}

char *paste_key(int key, char *str)
{
	if (key == SASB)
	{
		*str++ = 's';
		*str++ = 's';
	}
	else if (key == PAPB)
	{
		*str++ = '-';
		*str++ = '-';
	}
	else if (key == RARB)
	{
		*str++ = 'r';
		*str++ = 'r';
	}
	else if (key == RRARRB)
	{
		*str++ = 'r';
		*str++ = 'r';
		*str++ = 'r';
	}
	if (key < 10)
		return (paste_dash(++str));
	return (str);
}

void	simplificator(char *str)
{
	int com;
	int next_com;

	while (*str != '\0')
	{
		com = get_com_key(str);
		next_com = get_next_com_key(str);
		if (com + 1 == next_com || com - 1 == next_com)
			str = paste_key(com / 10, str);
		else if (com == RA && next_com == RRA || com == RRA && next_com == RA
			|| com == RB && next_com == RRB || com == RRB && next_com == RB)
			str = paste_dash(paste_dash(str));
		else
		{
			while (*str != '-' && *str != '\0')
				str++;
			if (*str != '\0')
				str++;
		}
	}
}
