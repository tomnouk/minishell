/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:14:05 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:57:42 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	val;

	str = (unsigned char *)s;
	val = (unsigned char)n;
	i = 0;
	while (i < val)
	{
		str[i] = '\0';
		i++;
	}
}

/*int main ()
{
    char s[6] = "Hello";
    //bzero(s, 2);//
    ft_bzero(s, 2);
    for (int i = 0; i < 6; i++)
        printf("%c", s[i]);
    printf("\n");
}*/