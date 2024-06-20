/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:54:25 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:54:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	value;

	value = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == value)
			return ((char *)&str[i]);
		else
			i--;
	}
	return (NULL);
}

/*int main()
{
    char s[] = "fu,cking, hell";
    //char *p = strrchr(s, ',');//
    char *p = ft_strrchr(s, '\0');
    if (p == NULL)
        printf("This is NULL idiot\n");
    else
        printf("%s\n", p);
}*/
