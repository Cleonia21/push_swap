#include "libft.h"

int		ft_print_imas(int *mas, int razm_mas)
{
	int i;

	i = 0;
	if (mas == NULL)
		return (-1);
	while (i < razm_mas)
	{
		ft_putnbr_fd(mas[i], 1);
		ft_putchar_fd('\0', 1);
		i++;
	}
	return (1);
}
