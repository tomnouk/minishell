/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/19 19:15:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *)dst;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main()

{
	char s[] = "aaaaaa";
	size_t x = 3;
	int j;

	ft_bzero(s, x);
	j=0;
	while (j < 6)
	{
		printf("\n%d", j);
		printf("%c", s[j]);
		j++;
	}
	return(0);
}*/
