/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:07 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/09 12:56:11 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || (ft_isdigit(c)))
		return (1);
	return (0);
}
/*int main(void)
{
	printf("a->%d\n", isalnum('a'));
	printf("A->%d\n", isalnum('3'));
	printf("8->%d\n", isalnum('.'));
	printf("B->%d\n", isalnum('B'));
	
	printf("f_a->%d\n", ft_isalnum('a'));
	printf("f_A->%d\n", ft_isalnum('3'));
	printf("f_8->%d\n", ft_isalnum('.'));
	printf("f_B->%d\n", ft_isalnum('B'));
}*/
