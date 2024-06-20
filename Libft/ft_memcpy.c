/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:54:14 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/11 10:54:16 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main() {
    char source[] = "";
    char destination[20];
    char source_1[] = "";
    char destination_1[20];

    // Copy the data from source to destination
    ft_memcpy(destination, source, 20);
    printf("f_Copied string: %s\n", destination);
    
    memcpy(destination_1, source_1, 20);
	printf("  Copied string: %s\n", destination);
	
    return 0;
}*/
