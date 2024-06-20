/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:53:41 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/18 10:53:43 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*r1;
	unsigned char		*r2;

	i = 0;
	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	while (i < n && r1[i] == r2[i])
		i++;
	if (i == n || n == 0)
		return (0);
	return (r1[i] - r2[i]);
}
/*
int main()
{
	
	printf("ft %d\n", ft_memcmp("a2", "a2", 3));
	printf("   %d\n", memcmp("a2", "a2", 3));
}*/
