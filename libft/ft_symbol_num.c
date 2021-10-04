#include "libft.h"

int	ft_symbol_num(const char *str, char c)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		if (*str == c)
			num++;
		str++;
	}
	return (num);
}
