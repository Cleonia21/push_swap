// #include "../push_swap.h"

// t_separator *new_sepr()
// {
// 	t_separator	*sepr;

// 	sepr = (t_separator *)malloc(sizeof(t_separator));
// 	if (sepr == NULL)
// 		return (NULL);
// 	sepr->gap1 = gap_new(-1);
// 	sepr->gap2 = gap_new(-1);
// 	sepr->gap3 = gap_new(-1);
// 	if (sepr->gap1 == NULL || sepr->gap1 == NULL || sepr->gap1 == NULL)
// 		return (NULL);
// 	return (sepr);
// }

// t_separator	*block_separation(t_block *from)
// {//need buf to "from"
// 	t_separator	*sepr;
// 	int fd;
// 	int min;
// 	int max;
// 	int num;

// 	fd = open("commands.inf", O_WRONLY | O_APPEND);
// 	if (fd == -1)
// 		return (NULL);
// 	min = from->param->min;
// 	max = from->param->max;
// 	sepr = new_sepr();
// 	if (sepr == NULL)
// 		return (NULL);
// 	while (from->gap)
// 	{
// 		num = from->gap->number;
// 		if (num < min)
// 		{
// 			gap_put_before(&(sepr->gap1), gap_new(num));
// 			commands(fd, P, from->belong);
// 		}
// 		else if (num >= min && num < max)
// 		{
// 			gap_put_after(sepr->gap2, gap_new(num));
// 			commands(fd, R, from->belong);
// 		}
// 		else
// 		{
// 			gap_put_after(sepr->gap3, gap_new(num));
// 			commands(fd, P, from->belong);
// 			commands(fd, R, belconv(from->belong));
// 		}
// 		from->gap = from->gap->front;
// 	}
// 	return (sepr);
// }

// int trim_into_two(t_block **where, t_block **to)
// {
// 	t_separator *sepr;
// 	char belong;a

// 	belong = (*where)->belong;
// 	sepr = block_separation(*where);
// 	*where = block_del(*where);
// 	block_put_before(to, block_new(sepr->gap1, belconv(belong)));
// 	block_put_after(where, block_new(sepr->gap2, belong));
// 	block_put_after(to, block_new(sepr->gap3, belconv(belong)));
// 	return (0);
// }