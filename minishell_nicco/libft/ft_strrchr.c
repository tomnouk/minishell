/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:40:00 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:40:04 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	j = i;
	while (j >= 0)
	{
		if (s[j] == (char)c)
		{
			return ((char *)&s[j]);
		}
		j--;
	}
	return (NULL);
}
//Cast eplicito era, const char *, dico di trattare come, char *
