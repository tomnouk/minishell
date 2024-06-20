/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:20:24 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 14:20:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <ctype.h>//

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int main()
{
    int num = 'a';
    //if (isdigit (num) == 1)//
        //printf("digit");//
    if (ft_isdigit (num) == 1)
        printf("digit");
    else
        printf("shit");
}*/
