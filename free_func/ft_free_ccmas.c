#include "../push_swap.h"

void	*ft_free_ccmas(char **mas)
{
	while (mas)
	{
		free (*mas);
		mas++;
	}
	return (NULL);
}