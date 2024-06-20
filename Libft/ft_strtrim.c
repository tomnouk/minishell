/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:54:14 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 17:02:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//
//#include <string.h>//

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	a;
	size_t	z;
	char	*p;

	a = 0;
	z = ft_strlen(s1);
	while (s1[a] != '\0' && ft_strchr(set, s1[a]))
		a++;
	while (ft_strrchr(set, s1[z - 1]) && z > a)
		z--;
	p = (char *)malloc(sizeof(char) * (z - a + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, &s1[a], (z - a + 1));
	return (p);
}

/*int main()
{
    char s1[] = " shit shit Fucking shit shit";
    char s2[] = " shit";
    char *p;

    p = ft_strtrim(s1, s2);
    if (p == NULL)
    {
        printf("NULL");
        free(p);
    }
    else
        printf("%s\n", p);
}*/
