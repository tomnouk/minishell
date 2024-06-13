/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:49:50 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:49:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(size_t i, size_t len, const char *b, const char *l)
{
	size_t	j;

	j = i;
	while (b[j] == l[j - i] && b[j] != '\0' && l[j - i] != '\0' && j < len)
	{
		j++;
	}
	return (j);
}

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;

	i = 0;
	while (l[i] != '\0')
		i++;
	if (l[0] == '\0')
		return ((char *)&b[0]);
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		if (b[i] == l[0])
		{
			if (l[count(i, len, b, l) - i] == '\0')
				return ((char *)&b[i]);
		}
		i++;
	}
	return (NULL);
}
//Casting eplicito line 37 era, const char *, dico di trattare come, char *
/*
int main() {
    
    const char *s = "abcdef";
    const char *ss ="bc";
    size_t v= 0;
    printf("%s", ft_strnstr(s, ss, v));
    return 0;
}*/
/*OLD_VERSION
char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	while (l[i] != '\0')
		i++;
	if (l[0] == '\0')
		return ((char *)&b[0]);
	if (i > len && i != 0)
		return (NULL);
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			z = i;
			while (b[z] == l[j] && b[z] != '\0' && l[j] != '\0' && z < len)
			{
				z++;
				j++;
			}
			if (l[j] == '\0')
				return ((char *)&b[i]);
		}
		i++;
	}
	return (NULL);
}*/
