/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/19 16:15:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	*c;

	i = 0;
	if (n == 0)
		return (0);
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (i < n - 1 && b[i] == c[i])
	{
		i++;
	}
	return ((unsigned char)b[i] - (unsigned char)c[i]);
}
/*
int	main()
{
	char d[] = "ABCD";
	char s[] = "ABXX";
	size_t x = 3;

	printf("\n%d", ft_memcmp(d,s,x));
	return(0);
}*/
