/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:56 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = (unsigned char *)s;
	while (i < n)
	{
		if (r[i] == (unsigned char)c)
		{
			return (&r[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char d[] = "ABCD";
	size_t x = 3;
	int j = 'C';

	printf("\n%s", (char *)ft_memchr(d,j,x));
	return(0);
}*/
