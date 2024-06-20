/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:45:14 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 15:04:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	while (!dest && !src)
		return (dest);
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ptr);
}

/*int main()
{
    char src[] = "fuck";
    char dest[];
    strcpy(dest, "shit shit shit");
    printf("The string before: %s\n", dest);
    memcpy (dest, src, strlen(src) + 1);
    //ft_memcpy (dest, src, strlen(src) + 1);//
    printf("The string after: %s\n", dest);

    return (0);
}*/
