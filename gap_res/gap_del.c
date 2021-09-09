#include "../push_swap.h"

void gap_del(t_gap *gap)
{
	if (gap)
	{
		if (gap->back)
			gap->back->front = gap->front;
		if (gap->front)
			gap->front->back = gap->back;
		free(gap);
	}
}
