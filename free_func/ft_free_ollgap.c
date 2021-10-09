#include "../push_swap.h"

void	ft_free_ollgap(t_gap *gap)
{
	t_gap	*buf;

	if (gap)
	{
		while (gap->front != NULL)
		{
			buf = gap->front;
			printf("free %p\n", gap);
			free (gap);
			gap = buf;
		}
		free (gap);
		printf("free %p\n", gap);
	}
	gap = NULL;
}
