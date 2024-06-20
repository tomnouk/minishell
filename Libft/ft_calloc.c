/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:16:38 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 15:26:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//
//#include <string.h>//
static void	b_zero(void *str, size_t n)
{
	while (n--)
		*(unsigned char *)str++ = 0;
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*s;

	if (n && size && n > (UINT_MAX / size))
		return (NULL);
	s = malloc(n * size);
	if (s == NULL)
		return (NULL);
	b_zero(s, n * size);
	return (s);
}

/*int main ()
{
    char s[] = "hello world";
    char *str;
    
    str = calloc(12, sizeof (char));
    strlcpy(str, s, 12);
    printf("%s\n", str);
    free(str);
    str = ft_calloc(12, sizeof (char));
    strlcpy(str, s, 12);
    printf("%s\n", str);
    free(str);
}*/
