/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:44:57 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 15:07:06 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
	}
	return (0);
}

/*int main()
{
    char str1[] = "Hello";
    char str2[] = "Hell";
    int i;

    i = ft_memcmp(str1, str2, 6);
    if (i > 0)
        printf("str1 bigger\n");
    else if (i < 0)
        printf("str1 smaller\n");
    else
        printf("Equal\n");
    i = memcmp(str1, str2, 6);
    if (i > 0)
        printf("str1 bigger\n");
    else if (i < 0)
        printf("str1 smaller\n");
    else
        printf("Equal\n");
}*/
