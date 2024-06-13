/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:44:46 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/21 15:44:55 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	z;
	char	*dest;

	z = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc((i + j + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (z < i)
	{
		dest[z] = ((char *)s1)[z];
		z++;
	}
	while (z < (i + j))
	{
		dest[z] = ((char *)s2)[z - i];
		z++;
	}
	dest[z] = '\0';
	return (dest);
}
/*
int	main()
{
	char const *par = "aaaa";
	char const *par2 = "bbb";

	printf (" %s ", ft_strjoin(par, par2));
	return (0);
}*/
