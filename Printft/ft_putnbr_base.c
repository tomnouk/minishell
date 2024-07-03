/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:03:57 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/07 11:04:00 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_n(long nr, int base)
{
	int	len;

	len = 0;
	if (!nr)
		return (1);
	while (nr)
	{
		nr = nr / base;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(char format, long long i, int choose_base)
{
	long long	number;
	char		*base;
	int			len_nr;

	len_nr = ft_len_n(i, choose_base);
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (i < 0)
	{
		len_nr += write(1, "-", 1);
		i = -i;
	}
	if (i >= choose_base)
		ft_putnbr_base (format, i / choose_base, choose_base);
	number = i % choose_base;
	ft_putchar(base[number]);
	return (len_nr);
}
