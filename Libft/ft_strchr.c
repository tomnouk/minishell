/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:41:53 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 16:41:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	value;

	value = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == value)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (value == '\0')
		return ((char *)(str + i));
	return (NULL);
}

/*int main()
{
    char str[] = "fucking hell, omg!";
    char ch = '\0';
    char *t;

    t = ft_strchr(str, ch);
    //t = strchr(str, ch);//
    if (t == NULL)
        printf("IT IS NULL");
    else
        printf("The string after %c is: %s\n", ch, t);
    return (0);
}*/
