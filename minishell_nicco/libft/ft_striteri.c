/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:34:08 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/28 15:34:11 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}

int	main(void)
{
	char	s[] = "aaabbb";
	ft_striteri(s,f);
	printf("%s", s);
	return (0);
}*/
