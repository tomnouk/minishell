/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:44:40 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/09 12:44:42 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("a->%d\n", isdigit('a'));
	printf("A->%d\n", isdigit('3'));
	printf("8->%d\n", isdigit('.'));
	printf("B->%d\n", isdigit('B'));
	
	printf("f_a->%d\n", ft_isdigit('a'));
	printf("f_A->%d\n", ft_isdigit('3'));
	printf("f_8->%d\n", ft_isdigit('.'));
	printf("f_B->%d\n", ft_isdigit('B'));
	
	//printf("ù->%d\n", isalpha('ù'));
}*/
