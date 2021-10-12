/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:12:26 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 14:50:55 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_gap(t_gap *gap, int fd, char belong, int gaplen)
{
	int	retval;

	retval = 0;
	gap = simplification_gap(gap);
	if (gaplen > 5)
		retval = sort_big_block(gap, fd, belong);
	else if (gaplen == 5 && belong == 'a')
		retval = sort_fifth_a(gap, fd);
	else if (gaplen == 5 && belong == 'b')
		retval = sort_fifth_b(gap, fd);
	else if (gaplen == 4 && belong == 'a')
		retval = sort_four_a(gap, fd);
	else if (gaplen == 4 && belong == 'b')
		retval = sort_four_b(gap, fd);
	else if (gaplen == 3 && belong == 'a')
		retval = sort_three_a(gap, fd);
	else if (gaplen == 3 && belong == 'b')
		retval = sort_three_b(gap, fd);
	else if (gaplen == 2 && belong == 'a')
		retval = sort_two_a(gap, fd);
	else if (gaplen == 2 && belong == 'b')
		retval = sort_two_b(gap, fd);
	ft_free_ollgap(&gap);
	return (retval);
}
