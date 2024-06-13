/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:46:59 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/18 12:47:03 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0') && (s2[i] != '\0') && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*necessario cast a (unsigned char) per evitare 
che carattere speciale sia trattato come negativo*/
/*
int main() {
    
    const char *s = "1234";
    const char *ss ="1235";
    size_t v= 3;
    int d = ft_strncmp(s, ss, v);
    
    printf("%d", d);
    return 0;
}*/
