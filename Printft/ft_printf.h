/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:31:03 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/24 20:31:05 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr_base(char format, long long i, int choose_base);
int	ft_putadress(void *ptr);
int	ft_unsigned(unsigned int nr);
int	ft_unbr_base(char format, unsigned long long i, unsigned int choose_base);

#endif
