/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:12 by amireid           #+#    #+#             */
/*   Updated: 2024/08/10 16:14:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/minishell.h"

// #include <stdio.h>

char	*ft_left_string(int fd, char *fline)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchar(fline, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1 || g_exit_status == 130)
		{
			free(buff);
			fline = NULL;
			return (NULL);
		}
		buff[bytes_read] = '\0';
		fline = ft_join(fline, buff);
	}
	free(buff);
	return (fline);
}

static void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		*tmp;

	str = NULL;
	line = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || g_exit_status == 130)
		return (free_str(&str), NULL);
	tmp = ft_left_string(fd, str);
	if (!tmp)
		return (free_str(&str), NULL);
	str = tmp;
	line = ft_get_line(str);
	str = ft_new_left_line(str);
	if (ft_strlen(str) == 0)
		free_str(&str);
	return (line);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd1;
// 	char	*line;

// 	i = 1;
// 	fd1 = open("tests/file1.txt", O_RDONLY);
// 	while (i < 10)
// 	{
// 		line = get_next_line(fd1);
// 		printf("Line number %d: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }
