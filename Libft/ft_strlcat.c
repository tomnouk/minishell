/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:21 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 18:20:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res_d;
	unsigned int	res_s;

	i = ft_strlen(dest);
	res_d = ft_strlen(dest);
	res_s = ft_strlen(src);
	j = 0;
	if (size <= 0)
		return (res_s + size);
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < res_d)
		return (res_s + size);
	else
		return (res_d + res_s);
}

/*int main ()
{
    char src[] = "World";
    char dest[20] = "Hello";

    strlcat(dest, src, 20);
    printf("%s\n", dest);
    ft_strlcat(dest, src, 20);
    printf("%s\n", dest);
    return (0);
}*/
