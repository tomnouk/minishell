/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shame_of_norm_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:43:43 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 22:45:09 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_ptsd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s[i])
	{
		write(fd, (unsigned char *)&s[i], 1);
		i++;
	}
}
