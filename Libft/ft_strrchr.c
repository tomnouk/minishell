/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:54:35 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/16 15:54:37 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	size_t	i;

	r = 0;
	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			r = (char *)&s[i];
		i++;
	}
	return (r);
}
/*
int main()
{
	printf("%s\n", ft_strrchr("abcddsbdf", 'd'));
	printf("%s\n", strrchr("abcddsbdf", 'd'));
}*/
