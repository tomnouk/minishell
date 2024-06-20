/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:48:10 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/18 16:48:12 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "libft.h"
/*
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	ptr_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr_size = nmemb * size;
	ptr = malloc(ptr_size);
	if (!ptr)
		return (NULL);
	ft_memset (ptr, 0, ptr_size);
	return (ptr);
}
/*
int main()
{
	//char *p = calloc(92233721234, 9223372);
	//char *p = calloc(2,4);
	
	if (p == NULL)
	{
		printf("Troppo grande\n");
		return(0);
	}
	printf("X/n");
	
}*/
