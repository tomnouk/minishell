/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:12:42 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/26 10:12:43 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t			i;
	unsigned char	new_line;

	i = 0;
	new_line = '\n';
	while (s[i])
	{
		write (fd, (unsigned char *)&s[i], 1);
		i++;
	}
	write (fd, &new_line, 1);
}
/*
int	main()
{
	char	*s;
	s = "AcAV&()9&";
	ft_putendl_fd(s, 1);
}*/
