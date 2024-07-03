/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:32:32 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/24 20:32:33 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_unsigned_n(unsigned long long nr, int base)
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

int	ft_unbr_base(char format, unsigned long long i, unsigned int choose_base)
{
	long long	number;
	char		*base;
	int			len_nr;

	len_nr = ft_len_unsigned_n(i, choose_base);
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (i >= choose_base)
		ft_unbr_base (format, i / choose_base, choose_base);
	number = i % choose_base;
	ft_putchar(base[number]);
	return (len_nr);
}
