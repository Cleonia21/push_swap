#include "../push_swap.h"

t_gap *gap_new(int number)
{
	t_gap *buf;

	buf = (t_gap *)malloc(sizeof(t_gap));
	if (buf == NULL)
		ft_error(MEMORY_ALLOC, "gap_new");
	buf->number = number;
	buf->back = NULL;
	buf->front = NULL;
	return (buf);
}
