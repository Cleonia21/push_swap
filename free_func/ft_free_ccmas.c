#include "../push_swap.h"

void	*ft_free_ccmas(char **mas)
{
	int i;

	i = 0;
	while (mas[i])
	{
		free (mas[i]);
		i++;
	}
	free(mas);
	return (NULL);
}