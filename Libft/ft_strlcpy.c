/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:50 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/04 10:54:41 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <bsd/string.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main() {
    char dst1[10] = "hello";
    printf("Before: %s\n", dst1);
    ft_strlcpy(dst1, "world", sizeof(dst1));
    printf("After: %s\n", dst1);
    
    char dst2[10] = "hello";
    printf("\nBefore: %s\n", dst2);
    ft_strlcpy(dst2, "worldworld", sizeof(dst2));
    printf("After: %s\n", dst2);
    
    char dst3[10] = "hello";
    printf("\nBefore: %s\n", dst3);
    ft_strlcpy(dst3, "world", 0);
    printf("After: %s\n", dst3);
    
    char dst4[10] = "hello";
    printf("\nBefore: %s\n", dst4);
    ft_strlcpy(dst4, "", sizeof(dst4));
    printf("After: %s\n", dst4);
    
    return 0;
}
*/
