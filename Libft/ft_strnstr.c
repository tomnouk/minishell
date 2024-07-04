/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:47:26 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/04 10:55:02 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include <bsd/bsd.h>
#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	little_i;
	size_t	inizio;

	big_i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[big_i] && big_i + ft_strlen(little) <= len)
	{
		inizio = big_i;
		little_i = 0;
		while (big[inizio] == little[little_i])
		{
			inizio++;
			little_i++;
			if (!little[little_i])
				return ((char *)&big[big_i]);
		}
		big_i++;
	}
	return (NULL);
}
/*
int main()
{
	char b[30] = "loripsem ipsum dolor sit amet";
	char l[10] = "ipsum";
	size_t	len;
	
	char *result;
	len = 15;
	result = strnstr(b, l, len);
	printf("   %s\n", result);
	
//	const char *ft_b = "12345678";
//	const char *ft_l = "123";
	char *ft_result;
	ft_result = ft_strnstr(b, l, len);
	printf("ft %s\n", ft_result);
	return(0);
}*/
