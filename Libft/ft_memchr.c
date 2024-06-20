/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:12:46 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/17 14:12:48 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*r;

	r = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (r[i] == (unsigned char)c)
			return (&r[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	unsigned char *result = (memchr("A3\042567", '2', 5));
	printf("   %c\n", *result);
	unsigned char *ft_result = (ft_memchr("A3\042567", '2', 5));
	printf("ft_%c\n", *ft_result);
	return(0);
}*/
