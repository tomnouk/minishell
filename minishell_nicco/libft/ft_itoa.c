/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:58:10 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/27 14:58:14 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_int(int n)
{
	size_t	i;

	i = 1;
	while (n > 9)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static int	ft_power(int nb, int power)
{
	int	i;
	int	r;

	i = 1;
	r = nb;
	if (power == 0)
	{
		return (1);
	}
	else
	{
		while (i < power)
		{
			r = r * nb;
			i++;
		}
		return (r);
	}
}

static char	*int_min(int n)
{
	char	*dest;

	(void)n;
	dest = (char *)malloc((12) * (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	dest[0] = '-';
	dest[1] = '2';
	dest[2] = '1';
	dest[3] = '4';
	dest[4] = '7';
	dest[5] = '4';
	dest[6] = '8';
	dest[7] = '3';
	dest[8] = '6';
	dest[9] = '4';
	dest[10] = '8';
	dest[11] = '\0';
	return (dest);
}

static char	*dest_mem(int n, size_t j, size_t z, size_t i)
{
	char	*dest;

	dest = (char *)malloc((j + 1 + z) * (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	while (i < j + z)
	{
		if (z == 1)
			dest[0] = '-';
		dest[i + z] = (char)(n / (ft_power(10, j - i - 1)) + 48);
		n = (n % (ft_power(10, j - i - 1)));
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	z = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0)
	{
		n = -n;
		z = 1;
	}
	j = num_int(n);
	return (dest_mem(n, j, z, i));
}
/*
int	main(void)
{
	int	n;

	n = -44444;
	printf(" %zu\n ", num_int(n));
	printf(" %s ", ft_itoa(n));
	return (0);
}*/
