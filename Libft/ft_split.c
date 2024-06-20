/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:47:52 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 23:15:42 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//

static size_t	wordcount(char const *str, char c)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != c)
		{
			wordcount++;
			while (*(str + i) && *(str + i) != c)
				i++;
		}
		else if (*(str + i) == c)
			i++;
	}
	return (wordcount);
}

static size_t	wordlength(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static void	freeupmem(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(*(str + i));
	}
	free(str);
}

static char	**split(char const *str, char c, char **s, size_t nowords)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nowords)
	{
		while (*(str + j) && *(str + j) == c)
			j++;
		*(s + i) = ft_substr(str, j, wordlength(&*(str + j), c));
		if (!*(s + i))
		{
			freeupmem(i, s);
			return (NULL);
		}
		while (*(str + j) && *(str + j) != c)
			j++;
		i++;
	}
	*(s + i) = NULL;
	return (s);
}

char	**ft_split(char const *str, char c)
{
	char	**p;
	size_t	i;

	if (!str)
		return (NULL);
	i = wordcount(str, c);
	p = (char **)malloc(sizeof(char *) * (i + 1));
	if (!p)
		return (NULL);
	p = split(str, c, p, i);
	return (p);
}
/*
int	main(void)
{
	const char	*str;
	char		delimiter;
	char		**words;
	int			i;

	str = ",,Hello,,World,How,Are,You,Shit,Fuck";
	delimiter = ',';
	words = ft_split(str, delimiter);
	if (words != NULL)
	{
		i = 0;
		while (words[i] != NULL)
		{
			printf("%s\n", words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	else
	{
		printf("Invalid input or allocation failed\n");
	}
	return (0);
}*/
