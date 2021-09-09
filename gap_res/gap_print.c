#include "../push_swap.h"

void gap_print(t_gap *gap)
{
    while(gap)
    {
        printf("%p <- %p=%i -> %p\n", gap->back, gap, gap->number, gap->front);
        gap = gap->front;
    }
}

// int main()
// {
//     t_gap *gap;

//     gap = gap_new(0);
//     gap_put_after(gap, gap_new(1));
//     gap_put_after(gap->front, gap_new(2));
//     gap_print(gap);
// }