/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:50:27 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/03 03:28:41 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define	BUFF_SIZE	32

# define	PS(x)		ft_putstr(x)
# define	PSFD(x, y)	ft_putstr_fd(x, y)
# define	PE(x)		ft_putendl(x)
# define	PEFD(x, y)	ft_putendl_fd(x, y)
# define	PN(x)		ft_putnbr(x)
# define	PNFD(x, y)	ft_putnbr_fd(x, y)

int		get_next_line(int fd, char **line);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2, int value);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_count(const char *s, int c);
int		ft_isval(int nb);
char	*ft_split_whitespaces(const char *s);
char	*ft_strrev(char *s);
char	*ft_epur(char *s);
char	*ft_strtolower(char *s);
char	*ft_strtoupper(char *s);
char	**ft_doubleread(char *tab);
char	**ft_dobleendl(char **tab);
char	**ft_doubledup(char **tab);
char	**ft_doublepur(char **tab);
void	ft_doublestr(char **tab);
void	ft_putnbrl(int nb);
char	**ft_doublenew(int len);
size_t	ft_doublelen(char **tmp);

int		ft_dtoo(int nb);
void	ft_triplestr(char *a, char *b, char *c);
void	ft_triplendl(char *a, char *b, char *c);
char	*ft_takeout(char *tab, char c);
void	ft_triplendl_fd(int fd, char *a, char *b, char *c);
void	ft_triplestr_fd(int fd, char *a, char *b, char *c);
char	*ft_fullblanks(char *tab, size_t size);
char	*ft_strcut(char *tab, int start, int len);
char	**ft_sortit(char **tab);
char	**ft_sortrev(char **tab);
void	ft_doubledel(char **a, char **b);
void	ft_doublefree(char ***tab);
#endif
