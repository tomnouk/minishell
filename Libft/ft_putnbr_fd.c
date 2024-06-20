/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:17:36 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/26 10:17:38 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long			nr;
	unsigned char	c;

	if (fd < 0)
		return ;
	nr = n;
	if (nr < 0)
	{
		nr = -nr;
		write (fd, "-", 1);
	}
	if (nr > 9)
		ft_putnbr_fd (nr / 10, fd);
	c = nr % 10 + '0';
	write (fd, &c, 1);
}
/*
int	main()
{
	ft_putnbr_fd(-2147483649, 1);
}*/
