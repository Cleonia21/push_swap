#ifndef		PUSH_SWAP_H
#define		PUSH_SWAP_H

# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<time.h>
# include	<fcntl.h>
# include	"libft/libft.h"
# include	"get_next_line/get_next_line.h"

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
	SA = 10,
	SB = 11,
	SASB = 1,//ss
	PA = 20,
	PB = 21,
	PAPB = 2,//-
	RA = 30,
	RB = 31,
	RARB = 3,//rr
	RRA = 40,
	RRB = 41,
	RRARRB = 4//rrr
};

enum errors
{
	FILE_OPEN = -1,
	FILE_READ = -2,
	MEMORY_ALLOC = -3,
	ARG_NULL = -4,
	SWAP = -5,
	ARGV = -6,
	OTHER = -7
};

t_gap	*gap_new(int number);
int		gap_put_before(t_gap **elem, t_gap *before);
int		gap_put_after(t_gap **elem, t_gap *after);
void	gap_del(t_gap *gap);
t_gap	*gap_get_first(t_gap *gap);
t_gap	*gap_get_last(t_gap *gap);
void	gap_free_oll(t_gap *gap);
void	gap_print(t_gap *gap);
void	gap_print_num(t_gap *gap);
int 	gap_len_forblock(t_block *block);
int		gap_len(t_gap *gap);
int		*gap_for_mas(t_gap *gap);
int		gap_min_num(t_gap *gap);
void	gap_swap(t_gap *gap, int fd);

t_block	*block_new(t_gap *gap, char belong);
int		block_put_before(t_block **list, t_block *before);
int		block_put_after(t_block **elem, t_block *after);
int		block_swap(t_block *from, t_block *to);
t_block	*block_del(t_block *del);
void	block_print(t_block *block, char *str);
void	blocks_print(t_block *block, char *str);
t_block *block_cut_last(t_block *block);
char		block_sort(t_lists *lists);

void	sort_gap(t_gap *gap, int fd, char belong);
int		is_gap_sort(t_gap *gap, char belong);
void	sort_two_a(t_gap *gap, int fd);
void	sort_two_b(t_gap *gap, int fd);
void	sort_three_a(t_gap *gap, int fd);
void	sort_three_b(t_gap *gap, int fd);
void	sort_four_a(t_gap *gap, int fd);
void	sort_four_b(t_gap *gap, int fd);
void	sort_fifth_a(t_gap *gap, int fd);
void	sort_fifth_b(t_gap *gap, int fd);

t_gap	*rnd_mas_to_gap();
void	ft_print_mas(int *mas, int razm_mas);
int		trim_into_three(t_lists *lists);
void	commands(char *com, char belong, int fd);
char 	belconv(char c);
int		itoc(int i);
int		ctoi(int c, int i);
t_gap	*last_gap(t_gap *gap);
t_block *last_block(t_block *block);
void	up_commands(int len_a, int len_b);
void	ft_error(int key, char *str);
void	sorter(t_lists *lists);
t_gap *argv_mas_to_gap(int argc, char **argv);
void decoder();

#endif