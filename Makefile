NAME		= 	push_swap
SRC_DIR_LIB	= 	libft/
SRC_DIR_FRE	= 	free_func/
SRC_DIR_GB	=	gap_block_res/
SRC_DIR_GNL	=	get_next_line/
SRC_DIR_RES	=	resources/
SRC_DIR_SRT	=	sorts/
HEADER		= 	push_swap.h

SRC_MAIN	=	main.c\

SRC_LIB		=	ft_strlcat.c ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
				ft_putnbr_fd.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_strlcpy.c ft_memmove.c ft_laststrsym.c\
				ft_memcpy.c ft_memchr.c ft_memset.c ft_calloc.c ft_bzero.c ft_strnstr.c ft_strchr.c\
				ft_strdup.c ft_strncmp.c ft_memcmp.c ft_atoi.c ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
				ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_itoa.c ft_memccpy.c ft_symbol_num.c\
				ft_isstrnum.c ft_isstrint.c ft_sort_imas.c ft_print_imas.c\

SRC_FRE		= 	ft_error.c ft_free_block.c ft_free_ccmas.c ft_free_imas.c ft_free_ollgap.c\

SRC_GB		=	block_cut_last.c block_new.c block_put.c gap_del.c gap_get_first.c\
				gap_len.c gap_min_num.c gap_new.c gap_put.c gap_swap.c get_last.c\

SRC_GNL		=	get_next_line.c get_next_line_utils.c\

SRC_RES		=	argv_to_gap.c argv_to_imas.c belconv.c block_sepr_a.c block_sepr_b.c\
				chek_for_up.c decoder.c imas_to_gap.c separator.c simplificator.c\
				trim_into_three.c up_commands.c\

SRC_SRT		=	block_sort.c is_gap_sort.c little_sorts.c lsort_fifth.c lsort_four.c\
				lsort_three.c simplification_gap.c sort_big_block.c sort_fifth.c\
				sort_four.c sort_gap.c sort_three.c sort_two.c sorter.c\

SRCS_MAIN	=	$(SRC_MAIN)
SRCS_LIB	=	$(addprefix $(SRC_DIR_LIB), $(SRC_LIB))
SRCS_FRE	=	$(addprefix $(SRC_DIR_FRE), $(SRC_FRE))
SRCS_GB		=	$(addprefix $(SRC_DIR_GB), $(SRC_GB))
SRCS_GNL	=	$(addprefix $(SRC_DIR_GNL), $(SRC_GNL))
SRCS_RES	=	$(addprefix $(SRC_DIR_RES), $(SRC_RES))
SRCS_SRT	=	$(addprefix $(SRC_DIR_SRT), $(SRC_SRT))

OBJS_MAIN	=	$(SRCS_MAIN:.c=.o)
OBJS_LIB	=	$(SRCS_LIB:.c=.o)
OBJS_FRE	=	$(SRCS_FRE:.c=.o)
OBJS_GB		=	$(SRCS_GB:.c=.o)
OBJS_GNL	=	$(SRCS_GNL:.c=.o)
OBJS_RES	=	$(SRCS_RES:.c=.o)
OBJS_SRT	=	$(SRCS_SRT:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS_MAIN) $(OBJS_LIB) $(OBJS_FRE) $(OBJS_GB) $(OBJS_GNL) $(OBJS_RES) $(OBJS_SRT)
			@make -sC libft/ all
			$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS_FRE) $(OBJS_GB) $(OBJS_GNL) $(OBJS_RES) $(OBJS_SRT) $(OBJS_LIB) -o $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS_MAIN) $(OBJS_FRE) $(OBJS_GB) $(OBJS_GNL) $(OBJS_RES) $(OBJS_SRT)
			@make -sC libft/ clean

fclean:		clean
			$(RM) $(NAME)
			@make -sC libft/ fclean

re:			fclean all

.PHONY:		all clear fclean re