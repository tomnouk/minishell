/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:21 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/19 10:08:25 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	unsigned char	*d;
	const unsigned char	*s;
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
   	while (i < n) 
	{
        	d[i] = s[i];
        	i++;
	}
	return(dest);
}
*/
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s);
	ptr = malloc((len_s + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, len_s);
	ptr[len_s] = '\0';
	return (ptr);
}
/*
int main()
{
	const char *s = "";
	char	*ptr;
	
	ptr = ft_strdup(s);
	puts(ptr);
	free(ptr);
	return (0);
}*/
