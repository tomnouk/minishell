/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:12:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 14:12:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	c;
	int	r;

	i = 0;
	c = 0;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			c = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (c == 1)
		r = -r;
	return (r);
}
/*
int	main()
{
	char *s = "    +1234pppppp";
	char *s2 = "    -++-+3a";
	printf(" %d ", ft_atoi(s));
	return(0);
}*/
