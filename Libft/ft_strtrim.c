/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:49:53 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/20 12:49:55 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	unsigned char	*d;
	const unsigned char	*s;
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
   	while (i < n) 
	{
        	d[i] = s[i];
        	i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len_s;
	
	len_s = ft_strlen(s);
	ptr = malloc((len_s + 1) * sizeof(char));
	if(!ptr)
		return (NULL);
	ft_memcpy(ptr, s, len_s);
	ptr[len_s] = '\0';
	return (ptr);	
}

char *ft_strchr(const char *s, int c)
{
	size_t	i;
	
	i = 0;
	
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if(s[i] == c)
			return((char *)&s[i]);
		i++;
	}
	return(NULL);
}
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*s_trim;
	size_t	i;
	size_t	s_trim_idx;	

	i = 0;
	if (!s1[i])
		return (ft_strdup(""));
	s1_len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[s1_len]))
	{
		if (s1_len == 0)
			return (ft_strdup(""));
		s1_len--;
	}
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	s_trim = malloc((s1_len - i + 2) * sizeof(char));
	if (!s_trim)
		return (NULL);
	s_trim_idx = -1;
	while (++s_trim_idx <= s1_len - i)
		s_trim[s_trim_idx] = s1[i + s_trim_idx];
	s_trim[s_trim_idx] = '\0';
	return (s_trim);
}
/*int main()
{
	char *r;
	r = ft_strtrim("1213", "1");
	printf("%s\n", r);
	free(r);
}*/
