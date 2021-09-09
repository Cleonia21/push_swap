#ifndef		PUSH_SWAP_H
#define		PUSH_SWAP_H

# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<time.h>

#define LIST_LEN 10

typedef struct		s_gap
{
	struct s_gap	*front;
	struct s_gap	*back;
	int				number;
}					t_gap;

typedef struct		s_param
{
	int				first;
	int				elem_num;
	int				min;
	int				max;
}					t_param;

typedef struct		s_block
{
	t_gap			*gap;
	t_param			*param;
	struct s_block	*front;
}					t_block;

typedef struct 		s_lists
{
	t_block			*block_a;
	t_block			*block_b;
}					t_lists;

typedef struct		s_separator
{
	t_gap			*gap1;
	t_gap			*gap2;
	t_gap			*gap3;
}					t_separator;


t_gap	*gap_new(int number);
int		gap_put_before(t_gap *elem, t_gap *before);
int		gap_put_after(t_gap *elem, t_gap *after);
void	gap_del(t_gap *gap);
t_gap	*gap_get_first(t_gap *gap);
t_gap	*gap_get_last(t_gap *gap);
void	gap_free_oll(t_gap *gap);

t_block	*block_new(t_gap *gap);
int		block_put_before(t_block **list, t_block *before);
int		block_put_after(t_block *elem, t_block *after);
int		block_swap(t_block *from, t_block *to);
t_block	*block_del(t_block *del);


#endif