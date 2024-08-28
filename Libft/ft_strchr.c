/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:18:01 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/01 19:55:03 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
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
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s && s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *s = "teste";
	size_t	i;

	i = 0;	
	
	while (i <= ft_strlen(s))
	{
		printf("s[%zu]: %p\n", i, &s[i]);
		i++;
	}
	printf("ft %p\n", ft_strchr(s, 1024));
	printf("   %p\n", strchr(s, 1024));
}*/
