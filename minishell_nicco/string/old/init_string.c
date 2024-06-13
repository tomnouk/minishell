/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	count_word(char const *s)
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
		while (s[i] == 32 && s[i] != '\0')
		{
			i++;
		}
		if (s[i] == 34)
		{
			q++;
			i++;
			while (s[i] != 34 && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == 34)
        		i++;
		}
		else if (s[i] == 39)
		{
			q++;
			i++;
			while (s[i] != 39 && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == 39)
        		i++;
		}
		else if (s[i] == 60 || s[i] == 62)
		{
			q++;
			if (s[i] == 60 && s[i+1] == 60)
			    i++;
			else if (s[i] == 62 && s[i+1] == 62)
			    i++;
			i++;
		}
		else
		{
			while (s[i] != 32 && s[i] != '\0' && s[i] != 60 && s[i] != 62)
			{
				j = 1;
				i++;
			}
			if (j == 1)
				q++;
		}
	}
	return (q);
}


static char	*point_word(char const *s, size_t n)
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
		while (s[i] == 32 && s[i] != '\0')
		{
			i++;
		}
		if (n - 1 == q && s[i]!=34 && s[i]!=39)
			return ((char *)&s[i]);
		else if (n - 1 == q && (s[i]==34 || s[i]==39))
			return ((char *)&s[i+1]);
		if (s[i] == 34)
		{
			q++;
			i++;
			while (s[i] != 34 && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == 34)
        		i++;
		}
		else if (s[i] == 39)
		{
			q++;
			i++;
			while (s[i] != 39 && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == 39)
        		i++;
		}
		else if (s[i] == 60 || s[i] == 62)
		{
			q++;
			if (s[i] == 60 && s[i+1] == 60)
			    i++;
			else if (s[i] == 62 && s[i+1] == 62)
			    i++;
			i++;
		}
		else
		{
			while (s[i] != 32 && s[i] != '\0' && s[i] != 60 && s[i] != 62)
			{
				j = 1;
				i++;
			}
			if (j == 1)
				q++;
		}
	}
	return ((char *)&s[i]);
}

static size_t	long_word(char const *s, size_t n)
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
		while (s[i] == 32 && s[i] != '\0')
		{
			i++;
		}
		z = 0;
		if (s[i] == 34)
		{
			q++;
			i++;
			while (s[i] != 34 && s[i] != '\0')
			{
				i++;
				z++;
			}
			if (s[i] == 34)
        		i++;
		}
		else if (s[i] == 39)
		{
			q++;
			i++;
			while (s[i] != 39 && s[i] != '\0')
			{
				i++;
				z++;
			}
			if (s[i] == 39)
        		i++;
		}
		else if (s[i] == 60 || s[i] == 62)
		{
			q++;
			if (s[i] == 60 && s[i+1] == 60)
			    z++, i++;
			else if (s[i] == 62 && s[i+1] == 62)
			    z++, i++;
			z++;
			i++;
		}
		else
		{
			while (s[i] != 32 && s[i] != '\0' && s[i] != 60 && s[i] != 62)
			{
				j = 1;
				i++;
				z++;
			}
			if (j == 1)
				q++;
		}
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

char	**init_string(char const *s)
{
	size_t	j;
	size_t	z;
	char	*start;
	char	**dest;

	j = 0;
	dest = (char **)malloc((count_word(s) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (j < count_word(s))
	{
		dest[j] = (char *)malloc((long_word(s, j + 1) + 1) * sizeof(char));
		if (dest[j] == NULL)
			return (free_mem(dest, j));
		z = 0;
		while (z++ < (long_word(s, j + 1)))
		{
			start = point_word(s, j + 1);
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
	char const *par = " ciao dudu>>>>ciao";
	char **result = init_string(par);
	size_t  i = 0;
    
    printf ("num parole: %zu\n", count_word(par));
	while (i < count_word(par))
	{
	    printf ("%zu\n", i);
	    //printf ("punt par: %s\n", point_word(par, i+1));
	    //printf ("lungh par: %zu\n", long_word(par, i+1));
	    printf ("%s\n", result[i]);
	    i++;
	}
	
	return (0);
}*/