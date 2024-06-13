/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:27:58 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:28:01 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *str, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	while (dst[i] != '\0')
		i++;
	while (str[z] != '\0')
		z++;
	if (size <= i)
	{
		return (z + size);
	}
	while (j + i < size - 1 && str[j] != '\0')
	{
		dst[j + i] = str[j];
		j++;
	}
	dst[j + i] = '\0';
	return (z + i);
}
/*
int main()
{
    const char *par = "lorem ipsum dolor sit amet";
    char d[] = "rrrrrrrrrrrrrr";
    size_t c = 15;
    
    ft_strlcat(d, par, c);
    printf(" %zu ", ft_strlcat(d, par, c));
    printf(" %s ", d);

    return 0;
}*/
