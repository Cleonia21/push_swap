#include "libft.h"

int ft_isstrnum(char *str)
{
	if (str == NULL)
		return (-1);
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
