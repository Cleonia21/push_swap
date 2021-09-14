#include "../push_swap.h"

// void ft_intset(int *mas, int num, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		mas[i] = num;
// 		i++;
// 	}
// }

/* int		*compres_com(int *mas)
{
	int *new_mas;
	int i;
	int j;

	i = 0;
	j = 0;
	new_mas = (int *)malloc(sizeof(int) * 101);
	if (new_mas == NULL)
		return (NULL);
	while (i < 101)
	{
		if (mas[i] + 1 == mas[i + 1] || mas[i] - 1 == mas[i + 1])
		{
			if (mas[i] / 10 != 3)
			{
				new_mas[j] = mas[i] / 10 + 1;
				i++;
			}
		}
		else
			new_mas[j] = mas[i];
		i++;
		j++;
	}
	return (new_mas);
} */

// int		putcom_infile(int *com)
// {
// 	int fd;
// 	int i;
	
// 	i = 0;
// 	fd = open("commands.inf", O_WRONLY | O_APPEND);
// 	if (fd == -1)
// 		return (-1);
// 	while (*com != -1 && *com != 0)
// 	{
// 		write(fd, &((char)*com), 1);
// 		com++;
// 	}
// }

void    commands(int fd, int key, char bel)
{
	if (key == PUSH)
		bel = belconv(bel);
	if (bel == 'a')
		key = key * 10;
	if (bel == 'b')
		key = key * 10 + 1;
	ft_putnbr_fd(key, fd);
	ft_putchar_fd('-', fd);
}

/*
key com
10)  sa    swap the first 2 elements at the top of stack a
11)  sb    swap the first 2 elements at the top of stack b
2)  ss    sa & sb
  
30)  pa    from b to a
31)  pb    from a to b

40)  ra    first elem to end
41)  rb    first elem to end
5)  rr    ra & rb

60)  rra   end elem to first
61)  rrb   end elem to first
7)  rrr   rra & rrb
*/