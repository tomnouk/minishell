/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:05:37 by aeid              #+#    #+#             */
/*   Updated: 2024/06/11 19:03:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void memory_allocator(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return ;
}

int ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int ft_ismeta(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '$')
		return (1);
	return (0);
}
