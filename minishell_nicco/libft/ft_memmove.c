/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (d < s)
	{
		while (i < l)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
	{
		i = l - 1;
		while (i < l)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (d);
}
// (d < s) confronta le zone di memoria a cui puntano d e s, se prima o dopo
/*
int	main()
{
	char d[] = "ABCD";
	char v[] = "ABCD";
	size_t x = 4;
	int j;

    	ft_memmove(d+1,d,x);
    	memmove(v+1,v,x);
	j=0;
	while (j < 4)
	{
		printf("\n%d", j);
		printf("%c", d[j]);
		j++;
	}
	printf("\n%s", d);
	j=0;
	while (j < 4)
	{
		printf("\n%d", j);
		printf("%c", v[j]);
		j++;
	}
	printf("\n%s", v);
	return(0);
}*/
