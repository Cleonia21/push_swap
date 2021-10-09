/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@school.42>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:21:23 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/08 20:15:10 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	lists;
	t_gap	*gap;
	int		retval;
	int		fd;

	/* clean file */
	fd = open("commands.inf", O_TRUNC);
	if (fd == -1)
		ft_error(FILE_OPEN, "main");
	close (fd);
	/* checking the argument for conditions and writing to the gap */
    gap = argv_to_gap(argc, argv);
	if (gap == NULL)
		ft_error();
	lists.block_a = block_new(gap, 'a');
	if (lists.block_a == NULL)
		ft_error();
	/* insert a landmark on sorted lists */
	if (block_put_after(&(lists.block_a), block_new(gap_new(-1), 'a')) == -1)
		ft_error();
	/* write sorts command in file */
	if (gap_len(gap) <= 5)
		little_sorts(gap);
	else
		sorter(&lists);	
	/* simplification and console output */
	decoder();
	exit(0);
}