/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:45:30 by aeid              #+#    #+#             */
/*   Updated: 2023/11/11 15:04:51 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>//
//#include <string.h>//

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (src < dest)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
		{
			*(char *)dest++ = *(char *)src++;
		}
	}
	return (ptr);
}

/*int main () 
{
   char dest[] = "oldstring";
   const char src[]  = "newstrig";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   //memmove(dest, src, 9);//
   ft_memmove (dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}*/
