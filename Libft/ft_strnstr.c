/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:52:36 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 16:35:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 && !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n--)
	{
		i = 0;
		while (*(s2 + i) && *(s1 + i) == *(s2 + i) && i <= n)
		{
			if (!*(s2 + i + 1))
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}

/*int main()
{
    char s1[] = "What the fuck is going on";
    char s2[] = "fack";
    char *p;

    p = strnstr(s1, s2, 2);
    if (p == NULL)
        printf("could not be found\n");
    else
        printf("Here: %s\n", p);
    p = ft_strnstr(s1, s2, 2);
    if (p == NULL)
        printf("could not be found\n");
    else
        printf("Here: %s\n", p);
}*/
