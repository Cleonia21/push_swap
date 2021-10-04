#include "../push_swap.h"

static int get_com_key(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == 's' && *(str + 1) == 'a')
		return (SA);
	if (*str == 's' && *(str + 1) == 'b')
		return (SB);
	if (*str == 'p' && *(str + 1) == 'a')
		return (PA);
	if (*str == 'p' && *(str + 1) == 'b')
		return (PB);
	if (*str == 'r' && *(str + 1) == 'a')
		return (RA);
	if (*str == 'r' && *(str + 1) == 'b')
		return (RB);
	if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		return (RRA);
	if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		return (RRB);
	return (0);
}

static char *skip_command(char *str)
{
	while (*str != '-' && *str != '\0')
		str++;
	if (*str == '\0')
		return (str);
	str++;
	return (str);
}

static int get_next_com_key(char *str)
{
	str = skip_command(str);
	return (get_com_key(str));
}

static int compare_com(int a, int b)
{
	if (a + 1 == b || a - 1 == b)
		return (1);
	return (0);
}

char *paste_dash(char *str)
{
	while (*str != '-' && *str != '\0')
	{
		*str = '-';
		str++;
	}
	if (*str == '\0')
		return (str);
	return (++str);
}

char *paste_key(int key, char *str)
{
	if (key == SASB)
	{
		*str++ = 's';
		*str++ = 's';
	}
	else if (key == PAPB)
	{
		*str++ = '-';
		*str++ = '-';
	}
	else if (key == RARB)
	{
		*str++ = 'r';
		*str++ = 'r';
	}
	else if (key == RRARRB)
	{
		*str++ = 'r';
		*str++ = 'r';
		*str++ = 'r';
	}
	if (key < 10)
		return (paste_dash(++str));
	return (str);
}

static void simplificator(char *str)
{
	int com;
	int next_com;

	while (*str != '\0')
	{
		com = get_com_key(str);
		next_com = get_next_com_key(str);
		if (compare_com(com, next_com))
			str = paste_key(com / 10, str);
		else if (com == RA && next_com == RRA || com == RRA && next_com == RA
			|| com == RB && next_com == RRB || com == RRB && next_com == RB)
		{
			str = paste_dash(str);
			str = paste_dash(str);
		}
		else
			str = skip_command(str);
	}
	
}

void decoder()
{
	int fd;
	char *str;

	fd = open("commands.inf", O_RDONLY);
	if (fd == -1)
		ft_error(FILE_OPEN, "decoder");
	get_next_line(fd, &str);
	if (str == NULL)
		ft_error(MEMORY_ALLOC, "decoder");
	simplificator(str);
	while (*str != '\0')
	{
		if (*str == '-' && *(str + 1) == '-')
			str++;
		else
		{
			if (*str == '-')
				ft_putchar_fd('\n', 1);//
			else
				ft_putchar_fd(*str, 1);
			str++;
		}
	}
}
