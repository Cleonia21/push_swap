#include "../push_swap.h"

char *dictionary(char *str, char c)
{
    if (str == "123")
        return ("");
    if (str == "132")
        return (">")
    if (str == "213")
    if (str == "231")
    if (str == "312")
    if (str == "321")
}

int *gap_in_str(t_gap *gap)
{
    int first;
    char *str;
    int i;
    int elem_num;
    t_gap *buf_gap;

    buf_gap = gap;
    elem_num = 0;
    first = buf_gap->number;
    while (buf_gap)
    {
        elem_num++;
        if (first > buf_gap->number)
            first = buf_gap->number;
        buf_gap = buf_gap->front;
    }
    str = (char *)malloc(sizeof(char) * elem_num + 1);
    str[elem_num] = '\0';
    buf_gap = gap;
    while (i < elem_num)
    {
        str = buf_gap->number - first + '0';
        i++;
        buf_gap = buf_gap->front;
    }
    return (str);
}

static int sort_three(t_gap *gap)
{
    int *mas;


}

void block_sort(t_lists *lists)
{
    if (lists->block_a->param->first < lists->block_b->param->first)
    
}