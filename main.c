#include "push_swap.h"

int sorter(t_lists *lists)
{
    int mark;//0: не отсортировано. 1: отсортированно. -1: сортировка не удалась
    t_block *focus;
    t_block *un_focus;

    mark = 0;
    focus = lists->block_a;
    un_focus = lists->block_b;
    while (mark == 0)
    {
        if (focus->param->elem_num < 10)
        {
            block_sort(lists);
            block_up(lists);
        }
        else
            block_trim(focus, un_focus, );
        appoint_focus(focus, un_focus);
        mark = is_lists_sorted(lists);
    }
}

int main()
{
    t_gap *gap;
    t_lists lists;
    int fd;

    fd = open("commands.inf", O_RDONLY);
    gap = rnd_mas_to_gap();
    lists.block_a = block_new(gap);
    sorter(lists);
    return (0);
}