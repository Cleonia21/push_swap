/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:55:41 by cleonia           #+#    #+#             */
/*   Updated: 2021/10/10 18:55:42 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include 	<ctype.h>
# include 	<unistd.h>
# include 	<stdlib.h>
# include 	<stdio.h>
# include   <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *mas, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_laststrsym(char *str);
char		*ft_itoa(int n);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_symbol_num(const char *str, char c);
int			ft_print_imas(int *mas, int razm_mas);
int			*ft_sort_imas(int *mas, int len);
int			ft_atoi(const char *str);
int			ft_isstrint(char *str);
int			ft_isstrnum(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif