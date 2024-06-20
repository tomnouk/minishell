/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:45:48 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 14:46:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	value;

	i = 0;
	b = (unsigned char *)str;
	value = (unsigned char)c;
	while (i < n)
	{
		b[i] = value;
		i++;
	}
	return (str);
}

/*int main()
{
    char str[7];
    ft_memset(str, 'a', 5);
    //memset(str, 'A', 5);//
    
    for (int i = 0; i < 5; i++)
        printf("%c", str[i]);
    printf("\n");
}*/
