#include "../push_swap.h"

void	*ft_free_block(t_block **block)
{
	if (*block)
	{
		if ((*block)->gap)
			ft_free_ollgap(&((*block)->gap));
		if ((*block)->param)
			free ((*block)->param);
		free (*block);
	}
	*block = NULL;
	return (NULL);
}