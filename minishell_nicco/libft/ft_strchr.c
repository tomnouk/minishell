/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:30 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:35:33 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
//Cast eplicito line 23,era const char *, dico di trattare come char *
//Cast su confronto tra s[i] e c
/*
int	main()
{
	char *s = "weuygfewuygf";
	printf(" %s ", ft_strchr(s, 'g'));
	return(0);
}*/
