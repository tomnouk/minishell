/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tkn_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:51:20 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 00:14:52 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	handle_special_dquote(t_data *data, t_tkn_data *token, int *tmp,
		int prev)
{
	while (data->args[data->current] && data->args[data->current] != '\"')
	{
		if (data->args[data->current] == '$')
		{
			if (*tmp == 39 && prev != '\"')
				token->variable_len = token->variable_len;
			else
				get_variable_len(data, data->current, &token->variable_len);
		}
		*tmp = data->args[data->current];
		(data->current)++;
	}
}

char	*special_token_handler(t_data *data, t_tkn_data *token, int *quote_flag,
		int prev)
{
	int	tmp;

	tmp = 0;
	if (data->args[data->start] == '\'' && prev != '\"')
	{
		while (data->args[data->current] && data->args[data->current] != '\'')
			(data->current)++;
		if (data->args[data->current] == '\'')
			(*quote_flag)++;
	}
	else
	{
		handle_special_dquote(data, token, &tmp, prev);
		if (data->args[data->current] == '\"')
			(*quote_flag)++;
	}
	if (data->args[data->current])
		(data->current)++;
	return (ft_substr(data->args, data->start + 1, data->current - data->start
			- 2));
}
