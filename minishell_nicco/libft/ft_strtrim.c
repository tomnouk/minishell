/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:35 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/22 15:11:39 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	begin(char const *s1, char const *set)
{
	size_t	i;
	size_t	z;
	size_t	n;
	size_t	q;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		z = 0;
		q = 0;
		while (z < ft_strlen(set))
		{
			if (s1[i] == set[z] && q == 0)
			{
				q = 1;
				n++;
			}
			z++;
		}
		if (q == 0)
			return (n);
		i++;
	}
	return (n);
}

static size_t	end(char const *s1, char const *set)
{
	size_t	i;
	size_t	z;
	size_t	n;
	size_t	q;

	i = (ft_strlen(s1) - 1);
	n = 0;
	while (s1[i] != '\0')
	{
		z = 0;
		q = 0;
		while (z < ft_strlen(set))
		{
			if (s1[i] == set[z] && q == 0)
			{
				q = 1;
				n++;
			}
			z++;
		}
		if (q == 0)
			return (n);
		i--;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	z;
	size_t	v;
	char	*dest;

	i = begin(s1, set);
	j = end(s1, set);
	z = ft_strlen(s1);
	if (i == z)
		j = 0;
	v = 0;
	dest = malloc((z - i - j + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (v < (z - i - j))
	{
		dest[v] = ((char *)s1)[v + i];
		v++;
	}
	dest[v] = '\0';
	return (dest);
}
/*
int	main()
{
	char const *par = "aaavvhhhhvaba";
	char const *par2 = "av";

	printf (" %s ", ft_strtrim(par, par2));
	return (0);
}*/
