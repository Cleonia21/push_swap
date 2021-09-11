#include "../push_swap.h"

int *rnd_mas()
{
	int *mas;
	int i;
	int j1;
	int j2;
	int gap;

	i = 0;
	mas = (int *)malloc(sizeof(int) * LIST_LEN + 1);
	while (i < LIST_LEN)
	{
		mas[i] = i;
		i++;
	}
	mas[i] = -1;
	i = 0;
	srand(time(NULL));
	while (i < LIST_LEN * 10)
	{
	    j1 = rand() % LIST_LEN;
	    j2 = rand() % LIST_LEN;
	    gap = mas[j1];
	    mas[j1] = mas[j2];
	    mas[j2] = gap;
	    i++;
	}
	return (mas);
}

t_gap	*rnd_mas_to_gap()
{
	t_gap	*gap;
	t_gap	*buf;
	int		*mas;

	mas = rnd_mas();
	//ft_print_mas(mas, LIST_LEN);
	gap = gap_new(*mas);
	buf = gap;
	mas++;
	while (*mas != -1)
	{
		if (gap_put_after(buf, gap_new(*mas)) == -1)
			return (NULL);
		buf = buf->front;
		mas++;
	}
	return (gap);
}