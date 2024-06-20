/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:52:22 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:52:24 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (n > 0))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int main ()
{
    char s1[] = "Fuck";
    char s2[] = "Fuck";
    //int i = strncmp(s1, s2, 6);//
    int i = ft_strncmp(s1, s2, 2);
    if (i < 0)
        printf("s1 is lower\n");
    if (i > 0)
        printf("s1 is bigger\n");
    if (i == 0)
        printf("s1 and s2 are equal");
    return (0);
}*/
