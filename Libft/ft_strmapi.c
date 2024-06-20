/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:51:57 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 15:16:46 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//
//#include <string.h>//

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
char	f(unsigned int i, char s)
{
    if (s >= 'a' && s <= 'z')
        return (s - 32);
    else
        return (s + 32);
}

int	main(void)
{
    char str[] = "HellOWorlD";
    char *p = ft_strmapi (str, f);
    printf("%s\n", p);
    return (0);
}*/
