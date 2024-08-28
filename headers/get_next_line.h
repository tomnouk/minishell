/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:14:12 by amireid           #+#    #+#             */
/*   Updated: 2024/07/11 23:09:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_left_string(int fd, char *fline);
char	*ft_get_line(char *str);
char	*ft_new_left_line(char *str);
char	*ft_strchar(char *str, int c);
char	*ft_join(char *s1, char *s2);
size_t	ft_strln(char *str);

#endif
