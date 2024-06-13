/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t l)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*s;

	i = 0;
	ptr = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < l)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main()
{
	char d[] = "abcdef";
	char s[] = "bbb";
	size_t x = 6;
	int j;
 
	ft_memcpy(d,s,x);
	j=0;
	while (j < 6)
	{
		printf("\n%d", j);
		printf("%c", d[j]);
		j++;
	}
	printf("\n%s", d);
	return(0);
}*/
