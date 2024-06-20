/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:12 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/13 20:07:14 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

/*int main()
{
	int	c = 84;
	printf("c upper %c diventa\n", c);
	printf("                  ft %c\n", ft_tolower(c));
	printf("                     %c\n",  tolower(c));
}*/
