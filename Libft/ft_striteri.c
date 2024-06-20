/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:42:42 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:42:45 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
void	f(unsigned int i, char *str)
{
  
    if (*str == '1')
        *str = ' ';
}

int main ()
{
    char str[] = "Hello1World";
    ft_striteri(str, f);
    printf("%s\n", str);
    return (0);
}*/
