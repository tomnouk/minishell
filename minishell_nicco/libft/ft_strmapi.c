/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:12:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/27 19:12:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = (char *)malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
char	f(unsigned int i, char c)
{
	c = c + i;
	return(c);
}

int	main()
{
	char c = 'a';
	unsigned int i = 2;
	char s[] = "aaabbb";
	char *result = ft_strmapi(s, f);

	printf(" %s ", result);
	return(0);
}*/
