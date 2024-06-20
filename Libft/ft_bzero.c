/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:08:35 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/10 18:08:38 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main()
{
	char *s;
	
	s = "123456789";
	int i = 0;

	ft_bzero(s, 3);
	while (i < 3)
	{
		printf("s[%d] = %c\n", i, s[i]);
		i++;
	}
	return (0);
}*/
