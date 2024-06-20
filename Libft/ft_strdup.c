/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:42:23 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:42:26 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <stdlib.h>//
//#include <string.h>//

char	*ft_strdup(const char *str)
{
	char	*p;
	int		len;

	len = ft_strlen(str);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	else
		ft_strlcpy(p, str, (len + 1));
	return (p);
}

/*int main()
{
    char s[] = "Hello shit";
    char *p;

    p = strdup(s);
    printf("%s\n", p);
    p = ft_strdup(s);
    printf("%s\n", p);
}*/
