#include "../push_swap.h"

t_gap	*simplification_gap(t_gap *gap)
{
	t_gap *buf;
	int min_num;

	min_num = gap_min_num(gap);
	buf = gap;
	while (buf)
	{
		buf->number -= min_num;
		buf = buf->front;
	}
	return (gap);
}
