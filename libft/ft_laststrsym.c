#include "libft.h"

/* returns a pointer to the last character in the string */
char	*ft_laststrsym(char *str)
{
	while (*str != '\0' && *str != '\n')
		str++;
	return (--str);
}