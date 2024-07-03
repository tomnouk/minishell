/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:54:48 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/07 11:54:49 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_unsigned(unsigned int nr)
{
	int	i;

	i = 0;
	if (nr == 0)
		return (1);
	while (nr)
	{
		nr = nr / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int nr)
{
	int				result;
	unsigned int	number;

	result = len_unsigned(nr);
	number = nr;
	if (nr > 9)
		ft_unsigned(nr / 10);
	number = number % 10 + '0';
	write(1, &number, 1);
	return (result);
}
