#include "../push_swap.h"

void	gap_free_oll(t_gap *gap)
{
	t_gap	*buf;

	if (gap)
	{
		while (gap->front)
		{
			buf = gap->front;
			free (gap);
			gap = buf;
		}
		free (gap);
	}
}
