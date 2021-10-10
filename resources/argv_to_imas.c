/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_imas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:20 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 19:27:38 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*argv_to_imas(int argc, char **argv)
{
	int	*mas;
	int	i;

	i = 0;
	mas = (int *)malloc(sizeof(int) * argc);
	if (mas == NULL)
		return (NULL);
	while (i < argc)
	{
		if (argv[i] == NULL)
			return (ft_free_imas(mas));
		if (ft_isstrnum(argv[i]) == 0)
			return (ft_free_imas(mas));
		if (ft_isstrint(argv[i]) == 0)
			return (ft_free_imas(mas));
		mas[i] = ft_atoi(argv[i]);
		i++;
	}
	return (mas);
}
