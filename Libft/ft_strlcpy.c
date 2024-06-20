/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:31 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:43:33 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (len == 0)
		return (i);
	while ((j < (len - 1)) && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

/*int main ()
{
    char src[] = "Hello";
    char dest[50];

    strlcpy(dest, src, 0);
    printf("%s\n", dest);

    ft_strlcpy(dest, src, 0);
    printf("%s\n", dest);
}*/
