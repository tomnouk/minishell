/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:59:11 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/26 09:59:13 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s[i])
	{
		write(fd, (unsigned char *)&s[i], 1);
		i++;
	}
}
/*
int	main()
{
	char	*s;
	s = "AcAV&()9&";
	ft_putstr_fd(s, 1);
}*/
