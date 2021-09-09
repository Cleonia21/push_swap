#include "push_swap.h"
#include <fcntl.h>

int op_num = 0;

t_gap	*ft_(t_gap **stack, int *num)
{
	t_gap *to;

	while (*stack)
	{
		if ((*stack)->number == *num)
		{
			ft_push_back(&to, *num);
			*stack = ft_del_elem(*stack);
			num++;
		}
		else
			*stack = (*stack)->front;
		op_num++;
	}
	return (to);
}

void	ft_line_sort(t_gap *from, t_gap *to)
{
	int *num;

	*num = 0;
	while (*num < LIST_LEN - 1)
	{
		to = ft_(&from, num);
	}
	printf("\ni = %i\n", op_num);
	//ft_print_stack(-2, to);
}

int main()
{
	t_gap	*stack;
	t_gap *buf;
	int i;
	int fd;

	ft_mas_in_stack(&stack);
	//ft_print_stack(-2, stack);
	ft_line_sort(stack, buf);
	// int num = 0;
	// while (num < LIST_LEN)
	// {
	// 	i = 0;
	// 	buf = stack;
	// 	while (i < LIST_LEN)
	// 	{
	// 		if (buf->number == num)
	// 		{
	// 			printf("%i ", num);
	// 			num++;
	// 		}
	// 		buf = buf->next;
	// 		i++;
	// 	}
	// 	printf("\n");
	// }
	// printf("\n-> <-\n\n");
	// num = LIST_LEN - 1;
	// while (num > 0)
	// {
	// 	i = 0;
	// 	buf = stack;
	// 	while (i < LIST_LEN)
	// 	{
	// 		if (buf->number == num)
	// 		{
	// 			printf("%i ", num);
	// 			num--;
	// 		}
	// 		buf = buf->next;
	// 		i++;
	// 	}
	// 	printf("\n");
	// }
}