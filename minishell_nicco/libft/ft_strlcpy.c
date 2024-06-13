/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:24:30 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:24:34 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (size == 0)
		return (i);
	while (j < size - 1 && str[j] != '\0')
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}
/*
int	main()
{
	char dst[0] = "";
	char *sr = "aaa3a";
	char dest[]="   ";
	size_t x = 0;
	
	ft_strlcpy(dst, sr, x);
	printf(" %zu ", ft_strlcpy(dst, sr, x));
	return(0);
}*/
