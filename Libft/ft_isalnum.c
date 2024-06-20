/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:17:54 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 14:18:00 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <ctype.h>//

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/*int main()
{
    int i = 'b';

    if (isalnum(i) == 1)
        printf("alpha numeric");
    //if (ft_isalnum(i) == 1)//
        //printf("alpha numeric");//
    else
        printf("shit");
}*/
