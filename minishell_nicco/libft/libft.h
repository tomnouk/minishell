/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:45:34 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 11:45:41 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H      //if not defined
# define LIBFT_H      //define

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, const char *str, size_t c);
size_t	ft_strlcat(char *dst, const char *str, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *b,	const char *l, size_t len);
int		ft_atoi(const char *str);
void	ft_bzero(void *dst, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dst, const void*src, size_t l);
void	*ft_memmove(void *dst, const void *src, size_t l);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t num, size_t dim);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void    *ft_realloc(void *src, size_t old, size_t len);
int     ft_isenvvar(int c);

#endif      //conclusione dell'if not defined
