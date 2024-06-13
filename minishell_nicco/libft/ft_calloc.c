/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:12 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/20 12:54:15 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	void	*dest;
	size_t	i;

	i = 0;
	dest = malloc (num * dim);
	if (dest == NULL)
		return (NULL);
	while (i < (num * dim))
	{
		((unsigned char *)dest)[i] = 0;
		i++;
	}
	return (dest);
}
/*
int main()
{
    size_t  x = 2;
    size_t  y = 3;
    
    //ft_calloc(x,y);
    printf(" %p ", ft_calloc(x,y));
    return 0;
}*/
