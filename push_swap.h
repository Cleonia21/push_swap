#ifndef		PUSH_SWAP_H
#define		PUSH_SWAP_H

# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<time.h>
# include	<fcntl.h>
# include	"libft/libft.h"

#define LIST_LEN 100

typedef struct		s_gap
{
	struct s_gap	*front;
	struct s_gap	*back;
	int				number;
}					t_gap;

typedef struct		s_param
{
	int				first;
	double			elem_num;
	double			min;
	double			max;
}					t_param;

typedef struct		s_block
{
	char			belong;
	t_gap			*gap;
	t_param			*param;
	struct s_block	*front;
}					t_block;

typedef struct 		s_lists
{
	int				fd;
	t_block			*block_a;
	t_block			*block_b;
}					t_lists;

enum commands
{
	S = 1,//
	SA = 10,
	SB = 11,
	SASB = 2,
	P = 3,
	PA = 30,
	PB = 31,
	R = 4,
	RA = 40,
	RB = 41,
	RARB = 5,
	RR = 6,
	RRA = 60,
	RRB = 61,
	RRARRB = 62
};

enum errors
{
	FILE_OPEN = -1,
	FILE_READ = -2,
	MEMORY_ALLOC = -3
};

t_gap	*gap_new(int number);
int		gap_put_before(t_gap **elem, t_gap *before);
int		gap_put_after(t_gap *elem, t_gap *after);
void	gap_del(t_gap *gap);
t_gap	*gap_get_first(t_gap *gap);
t_gap	*gap_get_last(t_gap *gap);
void	gap_free_oll(t_gap *gap);
void	gap_print(t_gap *gap);
int 	gap_len_forblock(t_block *block);
int		gap_len(t_gap *gap);
int		*gap_for_mas(t_gap *gap);
int		gap_min_num(t_gap *gap);

t_block	*block_new(t_gap *gap, char belong);
int		block_put_before(t_block **list, t_block *before);
int		block_put_after(t_block **elem, t_block *after);
int		block_swap(t_block *from, t_block *to);
t_block	*block_del(t_block *del);
void	block_print(t_block *block, char *str);
void	blocks_print(t_block *block, char *str);
t_block *block_cut_last(t_block *block);
int		block_sort(t_lists *lists);

t_gap	*rnd_mas_to_gap();
void	ft_print_mas(int *mas, int razm_mas);
int		trim_into_three(t_block **where, t_block **to);
void    commands(int fd, char bel, int key_num, ...);
char 	belconv(char c);
int		itoc(int i);
int		ctoi(int c, int i);
t_gap	*last_gap(t_gap *gap);
t_block *last_block(t_block *block);
int		up_commands(int len_a, int len_b);
void	ft_error(int key, char *str);


#endif