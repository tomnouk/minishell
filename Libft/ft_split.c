/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:42 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/20 18:42:44 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
*/
size_t	word_counter(char const *s, unsigned char c)
{
	size_t	wc;
	int		in_word;
	size_t	i;

	wc = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

size_t	free_matrix(char **matrix)
{
	free(matrix);
	return (1);
}

size_t	free_ptr_matrix(char **matrix, size_t idx)
{
	while (idx > 0)
		free(matrix[idx--]);
	free(matrix[idx]);
	free(matrix);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**matrix;
	size_t		inizio;
	size_t		i;
	size_t		idx;

	i = 0;
	matrix = malloc(sizeof(char *) * (word_counter(s, (unsigned char)c) + 1));
	if (!matrix && free_matrix(matrix))
		return (NULL);
	idx = 0;
	while (s[i] && idx < word_counter(s, (unsigned char)c))
	{
		while (s[i] == (unsigned char)c)
			i++;
		inizio = i;
		while (s[i] && s[i] != (unsigned char)c)
			i++;
		matrix[idx] = malloc(sizeof(char) * (i - inizio) + 1);
		if (!matrix[idx] && free_ptr_matrix(matrix, idx))
			return (NULL);
		ft_strlcpy(matrix[idx++], s + inizio, (i - inizio) + 1);
	}
	matrix[idx] = NULL;
	return (matrix);
}
/*
int	main()
{
	char	**matrix;
	char const	*s;
	char	c;
	
	s = "\t\t\t\t\t\t\t\t";
	c = '\t';
	printf("nr of words %zu,\n", word_counter(s, c));
	matrix = ft_split(s, c);
	
	for (size_t i = 0; i <= word_counter(s, c); i++)
		printf("-> %s\n", matrix[i]);
	free(matrix);
	//printf("* %lu\n", sizeof(char *));
}*/
