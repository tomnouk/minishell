/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:18:35 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/09 16:18:38 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (i < n)
	{
		((unsigned char *)s)[i] = uc;
		i++;
	}
	return (s);
}
/*
int main() 
{
    int myArray[5];
    int i = 0;

    ft_memset(myArray, 300, 3); 
    
    // Print the values in the array
    while (i < 3)
    {
        printf("myArray[%d] = %c\n", i, myArray[i]);
        i++;
    }
}        
   char myString[5];

    // Initialize the entire array to the value 42
    ft_memset(myString, 300, 3);
	//puts(myArray);
    // Print the values in the array
    for (int i = 0; i < 3; i++)
        printf("myString[%d] = %c\n", i, myString[i]);

    return 0;
}*/
