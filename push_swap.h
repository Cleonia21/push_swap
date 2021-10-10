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

typedef struct		s_separator
{
	t_gap			*gap1;
	t_gap			*gap2;
	t_gap			*gap3;
}					t_separator;

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

t_gap	*simplification_gap(t_gap *gap);

int		little_sorts(t_gap *gap);
int		lsort_fifth(t_gap *gap, int fd);
void	lsort_four(t_gap *gap, int fd);
void	lsort_three(t_gap *gap, int fd);

char	block_sort(t_lists *lists, int fd);
int		sort_gap(t_gap *gap, int fd, char belong, int gaplen);
int		is_gap_sort(t_gap *gap, char belong);
int		sort_two_a(t_gap *gap, int fd);
int		sort_two_b(t_gap *gap, int fd);
int		sort_three_a(t_gap *gap, int fd);
int		sort_three_b(t_gap *gap, int fd);
int		sort_four_a(t_gap *gap, int fd);
int		sort_four_b(t_gap *gap, int fd);
int		sort_fifth_a(t_gap *gap, int fd);
int		sort_fifth_b(t_gap *gap, int fd);
int	sort_big_block(t_gap *gap, int fd, char belong);

void	*ft_free_ollgap(t_gap **gap);
void	*ft_free_imas(int *mas);
void	*ft_free_ccmas(char **mas);
void	*ft_free_block(t_block **block);
int		sorter(t_lists *lists);

int		separator(t_lists *lists, char belong, int fd);
t_separator	*block_sepr_a(t_block *from, t_separator *spr, int fd);
t_separator	*block_sepr_b(t_block *from, t_separator *spr, int fd);
void		*free_separator(t_separator *sepr, t_block *block);


/* finish */
t_gap	*argv_to_gap(int argc, char **argv);
int		*argv_to_imas(int argc, char **argv);
t_gap	*imas_to_gap(int *mas, int argc);
int		decoder();
void	simplificator(char *str);
int		trim_into_three(t_lists *lists, int fd);
void	up_commands(int len_a, int len_b);
void	ft_error();
char 	belconv(char c);
void	chek_for_up(t_lists *lists);

void	gap_del(t_gap *gap);
t_gap	*gap_get_first(t_gap *gap);
int 	gap_len_forblock(t_block *block);
int		gap_len(t_gap *gap);
int		gap_min_num(t_gap *gap);
t_gap	*gap_new(int number);
void	gap_print(t_gap *gap);
void	gap_print_num(t_gap *gap);
int		gap_put_before(t_gap **elem, t_gap *before);
int		gap_put_after(t_gap **elem, t_gap *after);
void	gap_swap(t_gap *gap, int fd);
t_gap	*last_gap(t_gap *gap);
t_block *last_block(t_block *block);
t_block *block_cut_last(t_block *block);
t_block	*block_del(t_block *del);
t_block	*block_new(t_gap *gap, char belong);
int		block_put_before(t_block **list, t_block *before);
int		block_put_after(t_block **elem, t_block *after);





#endif
