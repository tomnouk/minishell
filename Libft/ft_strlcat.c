/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:59:27 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/04 10:54:18 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
//#include <bsd/string.h>
#include <unistd.h>
#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	dst_i;
	size_t	i;

	len_d = ft_strlen(dst);
	dst_i = len_d;
	i = 0;
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	if (size > 0)
	{
		while (len_d < (size - 1) && src[i])
		{
			dst[len_d] = src[i];
			len_d++;
			i++;
		}
		dst[len_d] = '\0';
	}
	return (ft_strlen(src) + dst_i);
}
/*
int	main()
{
	char d[] = "123";
	char f_d[] = "123";
	size_t size = 0;
	
	//printf(" ->%zu, ", strlcat(d,"1234567", size));
	printf("%s\n", d);
	printf("f->%zu, ", ft_strlcat(f_d,"1234567", size));
	printf("%s\n", f_d);
	
	
}*/
