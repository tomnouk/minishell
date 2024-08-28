/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:19 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/09 15:45:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	l;
	size_t	m;
	char	*p;

	l = 0;
	m = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[m] != '\0')
		{
			p[m] = s1[m];
			m++;
		}
	}
	while (s2[l] != '\0')
	{
		p[m + l] = s2[l];
		l++;
	}
	p[m + l] = '\0';
	return (p);
}
/*
int	main()
{
	puts(ft_strjoin("12345", "678"));
}*/
