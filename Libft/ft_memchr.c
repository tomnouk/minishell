/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:44:28 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 00:38:04 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)(unsigned char *)s - 1);
	}
	return (NULL);
}

/*int main()
{
    char s[] = "What the, fuck";
    char ch = 'z';
    char *p;

    //p = memchr(s, ch, 20);//
    p = ft_memchr(s, ch, 20);
    if (p == NULL)
        printf("Nothing idiot\n");
    else
        printf("%s\n", p);
}*/
