#include "libft.h"

int	*ft_sort_imas(int *mas, int len)
{
	int *sort_mas;
	int i;
	int j;
	int tmp;

	i = 0;
	if (mas == NULL)
		return (NULL);
	sort_mas = (int *)malloc(sizeof(int) * len);
	if (sort_mas == NULL)
		return (NULL);
	sort_mas = (int *)ft_memcpy(sort_mas, mas, len * sizeof(int));
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (sort_mas[j] > sort_mas[j + 1])
			{
				tmp = sort_mas[j];
				sort_mas[j] = sort_mas[j + 1];
				sort_mas[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sort_mas);
}
