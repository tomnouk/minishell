/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:53:57 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 16:30:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//
//#include <stdlib.h>//
//s = (s + start);move the s pointer to the index to create substr from there//
//	p = str;assign str to p so we keep track of the begining of substr//
static size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static char	*newstring(size_t n)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start > str_len(s))
		len = 0;
	else if (len > (str_len(s) - start))
		len = str_len(s) - start;
	str = newstring(len);
	if (!str)
		return (NULL);
	s += start;
	p = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (p);
}

/*int	main(void)
{
	char	s[];
	char	*p;

	s[] = "hola";
	p = ft_substr(s, 4294967295, 0);
	if (p == NULL)
	{
		printf("it is NULL\n");
		free(p);
	}
	else
		printf("%s\n", p);
	return (0);
}*/
