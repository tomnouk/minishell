/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:20:59 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 00:24:04 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//

static int	the_length(int i)
{
	int	len;

	len = 0;
	if (i <= 0)
		len++;
	while (i != 0)
	{
		i = (i / 10);
		len++;
	}
	return (len);
}

static long long	longnumbers(long long n)
{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

static char	*newstr(size_t n)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_itoa(int i)
{
	int				len;
	int				sign;
	unsigned int	nbr;
	char			*str;

	sign = 0;
	if (i < 0)
		sign = 1;
	len = the_length(i);
	str = newstr(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = longnumbers(i);
	while (len > 0)
	{
		str[len - 1] = '0' + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	if (sign)
		*(str) = '-';
	return (str);
}
/*
int	main(void)
{
    int i = 0;
    char *str;

    str = ft_itoa(i);
    printf("%s\n", str);
    return (0);
}*/
