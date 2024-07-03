/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:43:04 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/07 10:43:07 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(void *ptr)
{
	int				result;
	long long int	val_ptr;

	result = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	val_ptr = (long long int)ptr;
	result += write(1, "0x", 2);
	result += ft_unbr_base('x', val_ptr, 16);
	return (result);
}
/*
int main()
{
	char *c;
	
	c = "uno";
	printf("%p\n%p\n%p\n", &c, c, &c[0]);
	ft_putadress(&c);
	ft_putadress(c);
	ft_putadress(&c[0]);
}*/
