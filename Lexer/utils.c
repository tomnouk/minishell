/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:05:37 by aeid              #+#    #+#             */
/*   Updated: 2024/06/22 23:42:46 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	memory_allocator(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return ;
}

int	ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	ft_ismeta(int c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

void	get_variable_len(t_data *data, int dol_position, int *variable_len)
{
	dol_position++;
	while (!ft_isquote(data->args[dol_position])
		&& !ft_ismeta(data->args[dol_position])
		&& (ft_isprint(data->args[dol_position]))
		&& (data->args[dol_position] != '\0')
		&& (data->args[dol_position] != '$'))
	{
		dol_position++;
		(*variable_len)++;
	}
}
