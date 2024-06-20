/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:36:56 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/26 10:36:58 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	negative(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	size_n(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		str_size;
	int		i;
	long	nr;

	i = 0;
	nr = n;
	str_size = size_n(n) + negative(n);
	res = malloc(sizeof(char) * str_size + 1);
	if (!res)
		return (NULL);
	res[str_size] = '\0';
	str_size--;
	if (negative(n))
	{
		nr = -nr;
		res[i++] = '-';
	}
	while (i <= str_size)
	{
		res[str_size--] = nr % 10 + '0';
		nr = nr / 10;
	}
	return (res);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(-__INT_MAX__ - 1));
}*/
