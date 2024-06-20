/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:51:16 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/18 15:51:19 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	negativo;

	result = 0;
	i = 0;
	negativo = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		i++;
		negativo = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * negativo);
}
/*
int main() {
    const char *str = "   -2147483650noaa3";

    printf("   %d\n", atoi(str));
    printf("ft_%d\n", ft_atoi(str));
    return (0);
}*/
