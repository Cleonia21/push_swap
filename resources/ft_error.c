#include "../push_swap.h"

void ft_error(int key, char *str)
{
    ft_putstr_fd("error ", 1);
    ft_putnbr_fd(key, 1);
    ft_putstr_fd("\nin ", 1);
    ft_putstr_fd(str, 1);
    exit(0);
}