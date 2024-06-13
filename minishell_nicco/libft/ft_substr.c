/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:44:46 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/21 13:44:55 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	memo(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (start > ft_strlen(s) || s[0] == '\0')
	{
		i = 0;
		return (i);
	}
	else
	{
		while (s[i + start] != '\0' && i < len)
		{
			i++;
		}
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	m;
	size_t	j;
	char	*dest;

	m = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	m = memo (s, start, len);
	dest = malloc((m + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (m == 0)
	{
		dest[0] = '\0';
		return (dest);
	}
	while (j < m && s[start + j] != '\0')
	{
		dest[j] = ((char *)s)[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int	main()
{
	const char *par = "0123456789";
	unsigned int x = 9;
	size_t	a = 10;

	printf (" %s ", ft_substr(par, x, a));
	return (0);
}*/
