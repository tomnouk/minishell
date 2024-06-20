/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:03:51 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/11 15:03:53 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int main() {
    char source[5];
    char destination[20];
    char source_1[5];
    char destination_1[20];

    // Copy the data from source to destination
    ft_memmove(destination, source, 20);
    printf("f_Copied string: %s\n", destination);
    
    memmove(destination_1, source_1, 20);
	printf("  Copied string: %s\n", destination);
	
    return 0;
}*/
