#include "../push_swap.h"

void	ft_free_ollgap(t_gap *gap)
{
	t_gap	*buf;

	if (gap)
	{
		while (gap->front != NULL)
		{
			buf = gap->front;
			free (gap);
			gap = buf;
		}
		free (gap);
	}
}
