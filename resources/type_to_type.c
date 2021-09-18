#include "../push_swap.h"

int	ctoi(int c, int i)
{
	return (i * 10 + c);
}

int itoc(int i)
{
    return (i % 10);
}

int *gap_for_mas(t_gap *gap)
{
	int *mas;
	int min;
    int len;
    int i;

    len = gap_len(gap);
	mas = (int *)malloc(sizeof(int) * len + 1);
    mas[len] = -1;
	min = gap->number;
	while (gap->front)
	{
        gap = gap->front;
		if (min > gap->number)
			min = gap->number;
	}
    while (len > 0)
    {
        mas[len - 1] = gap->number - min;
        len--;
        gap = gap->back;
    }
	return (mas);
}
