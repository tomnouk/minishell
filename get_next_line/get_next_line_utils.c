/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:34 by amireid           #+#    #+#             */
/*   Updated: 2024/08/10 16:12:25 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

size_t	ft_strln(char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	l;
	size_t	m;
	char	*p;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc((ft_strln(s1) + ft_strln(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	l = -1;
	m = 0;
	if (s1)
		while (s1[++l] != '\0')
			p[l] = s1[l];
	while (s2[m] != '\0')
		p[l++] = s2[m++];
	p[ft_strln(s1) + ft_strln(s2)] = '\0';
	if (s1)
		free(s1);
	return (p);
}

char	*ft_strchar(char *str, int c)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strln(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str[i] || !str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 2));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_new_left_line(char *str)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	p = (char *)malloc(sizeof(char) * (ft_strln(str) - i + 1));
	if (!p)
		return (NULL);
	i++;
	while (str[i])
		p[j++] = str[i++];
	p[j] = '\0';
	free(str);
	return (p);
}
