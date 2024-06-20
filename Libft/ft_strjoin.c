/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:06 by aeid              #+#    #+#             */
/*   Updated: 2023/11/13 14:44:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//
//#include <string.h>//

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	l;
	size_t	m;
	char	*p;
	char	*str_ptr;

	l = 0;
	m = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	str_ptr = p;
	while (s1[m] != '\0')
	{
		p[m] = s1[m];
		m++;
	}
	while (s2[l] != '\0')
	{
		p[m + l] = s2[l];
		l++;
	}
	p[m + l] = '\0';
	return (str_ptr);
}

/*int main()
{
    char s1[] = "Fucking";
    char s2[] = " shit";
    char *p;

    p = ft_strjoin(s1, s2);
    if (p == NULL)
    {
        printf("NULL");
        free(p);
    }
    else
        printf("%s\n", p);
}*/
