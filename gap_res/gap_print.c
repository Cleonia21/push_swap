#include "../push_swap.h"

void    gap_print(t_gap *gap)
{
	while(gap)
	{
		printf("%14p <- %p -> %14p {%i}\n", gap->back, gap, gap->front, gap->number);
		gap = gap->front;
	}
	printf("\n");
}

void	gap_print_num(t_gap *gap)
{
	while(gap)
	{
		ft_putnbr_fd(gap->number, 1);
		ft_putchar_fd(' ', 1);
		gap = gap->front;
	}
	ft_putchar_fd('\n', 1);
}
