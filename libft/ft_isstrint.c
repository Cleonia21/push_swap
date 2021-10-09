#include "libft.h"

static	char	*make_pattern()
{
	char *pattern;

	pattern = (char *)malloc(sizeof(char) * 10);
	if (pattern == NULL)
		return (NULL);
	pattern[0] = '2';
	pattern[1] = '1';
	pattern[2] = '4';
	pattern[3] = '7';
	pattern[4] = '4';
	pattern[5] = '8';
	pattern[6] = '3';
	pattern[7] = '6';
	pattern[8] = '4';
	pattern[9] = '\0';
	return (pattern);
}

int		compare(char *str, int sign)
{
	char	*pattern;

	pattern = make_pattern();
	if (pattern == NULL)
		return (0);
	while (*pattern != '\0')
	{
		if (*pattern < *str)
			return (0);
		if (*pattern > *str)
			return (1);
		pattern++;
		str++;
	}
	if (sign == 1 && *str > '7')
		return (0);
	if (sign == -1 && *str > '8')
		return (0);
	return (1);
}

/* [−2 147 483 648, +2 147 483 647] */
int		ft_isstrint(char *str)
{
	int		sign;
	int		retval;

	if (str == NULL)
		return (0);
	sign = 1;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '	')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) < 10)
		return (1);
	return (compare(str, sign));
}
