/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:06:57 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/05 11:43:07 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_how_many_strs(char *s1, char *s2, int frees)
{
	if (frees == 3)
	{
		free_null(s1);
		free_null(s2);
	}
	else if (frees == 2)
		free_null(s2);
	else if (frees == 1)
		free_null(s1);
}

// frees = 0 -> no free
// frees = 1 -> free s1
// frees = 2 -> free s2
// frees = 3 -> free s1 and s2
char	*strjoin_free(char *s1, char *s2, int frees)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free_how_many_strs(s1, s2, frees);
	return (str);
}
