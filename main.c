/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:21:23 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/12 17:21:12 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_free_lists(t_lists *lists)
{
	t_block	*block_buf;

	while (lists->block_a)
	{
		block_buf = lists->block_a->front;
		ft_free_block(&(lists->block_a));
		lists->block_a = block_buf;
	}
	while (lists->block_b)
	{
		block_buf = lists->block_b->front;
		ft_free_block(&(lists->block_b));
		lists->block_b = block_buf;
	}
	decoder();
}

static	void	clean_file(void)
{
	int	fd;

	fd = open("commands.inf", O_TRUNC);
	if (fd == -1)
		ft_error();
	close (fd);
}

static	void	chek_for_sorting_gap(t_gap *gap)
{
	if (is_gap_sort(gap, 'a') == 1)
	{
		ft_free_ollgap(&gap);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_lists	lists;
	t_gap	*gap;

	clean_file();
	gap = argv_to_gap(argc, argv);
	if (gap == NULL)
		ft_error();
	chek_for_sorting_gap(gap);
	lists.block_a = block_new(gap, 'a');
	if (lists.block_a == NULL)
	{
		ft_free_ollgap(&gap);
		ft_error();
	}
	if (block_put_after(&(lists.block_a), block_new(gap_new(-1), 'a')) == -1)
	{
		ft_free_block(&(lists.block_a));
		ft_error();
	}
	if (gap_len(gap) <= 5)
		little_sorts(gap);
	else if (sorter(&lists) == 'o')
		ft_error();
	ft_free_lists(&lists);
	exit(0);
}
