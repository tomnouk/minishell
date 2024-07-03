/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:02:17 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/07 12:02:19 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	print_case(char format, va_list ap)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		result += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		result += ft_putadress(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		result += ft_putnbr_base(format, (long int)va_arg(ap, int), 10);
	else if (format == 'u')
		result += ft_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_putnbr_base(format, va_arg(ap, unsigned int), 16);
	else if (format == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			result += print_case(*(++format), ap);
		else
			result += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (result);
}
/*
int main()
{
	int d = 2;
	ft_printf("%da", d);
}

int	main()
{	

	printf("%p\t%p\t%p\t%p\n", LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX);
	ft_printf("%p\n", LONG_MIN);
	ft_printf("%p\n", LONG_MAX);
	ft_printf("%p\n", ULONG_MAX);
	ft_printf("%p\n", -ULONG_MAX);
}

	char c = '*';
	char	*str;
	
	str = "stringa";
	int d = -2147483648;
	unsigned int x = 4294967295;
	unsigned int X = 4294967295;
	unsigned int i = 0;

int res = printf      ("printf  %c, %d, %x, %X,
 i = %i, %%, %s, %p\n", c, d, x, X, i, str, &str);
int my_res = ft_printf("me  ->  %c, %d, %x, %X,
 i = %i, %%, %s, %p\n", c, d, x, X, i, str, &str);
	printf("%d\n", my_res);//, res);
}*/
