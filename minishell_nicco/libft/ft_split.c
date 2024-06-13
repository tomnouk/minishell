/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:17:35 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/22 18:17:39 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	q;

	i = 0;
	j = 0;
	q = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == (char)c && s[i] != '\0')
		{
			i++;
		}
		while (s[i] != (char)c && s[i] != '\0')
		{
			j = 1;
			i++;
		}
		if (j == 1)
			q++;
	}
	return (q);
}

static char	*point_word(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	q;

	i = 0;
	j = 0;
	q = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == (char)c && s[i] != '\0')
		{
			i++;
		}
		if (n - 1 == q)
			return ((char *)&s[i]);
		while (s[i] != (char)c && s[i] != '\0')
		{
			j = 1;
			i++;
		}
		if (j == 1)
			q++;
	}
	return ((char *)&s[i]);
}

static size_t	long_word(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	q;
	size_t	z;

	i = 0;
	q = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == (char)c && s[i] != '\0')
			i++;
		z = 0;
		while (s[i] != (char)c && s[i] != '\0')
		{
			j = 1;
			i++;
			z++;
		}
		if (j == 1)
			q++;
		if (n == q)
			return (z);
	}
	return (z);
}

static char	**free_mem(char	**dest, size_t	j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	z;
	char	*start;
	char	**dest;

	j = 0;
	dest = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (j < count_word(s, c))
	{
		dest[j] = (char *)malloc((long_word(s, c, j + 1) + 1) * sizeof(char));
		if (dest[j] == NULL)
			return (free_mem(dest, j));
		z = 0;
		while (z++ < (long_word(s, c, j + 1)))
		{
			start = point_word(s, c, j + 1);
			dest[j][z - 1] = start[z - 1];
		}
		dest[j][z - 1] = '\0';
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
/*
int	main()
{
	char const *par = " ciao alla ciccia bu bua vv";
	char c = ' ';
	char **result = ft_split(par, c);
	size_t  i = 0;
    
    printf ("num parole: %zu\n", count_word(par, c));
	printf ("punt par: %s\n", point_word(par, c, 4));
	printf ("lungh par: %zu\n", long_word(par, c, 3));
	printf ("\n");
	printf ("\n");
	while (i < count_word(par, c))
	{
	    printf ("%s", result[i]);
	    printf ("\n%zu\n", i);
	    i++;
	}
	return (0);
}*/
