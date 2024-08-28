/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:54:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/08/09 23:55:42 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	meta_token_handler(t_data *data, t_list *node, t_tkn_data *token)
{
	if (data->args[data->current] == '$')
		dollar_meta(data, node, token);
	else if (data->args[data->current] == '|')
		pipe_meta(data, node, token);
	else if (data->args[data->current] == '>'
		|| data->args[data->current] == '<')
		redirect_meta(data, node, token);
}

void	ft_meta_token(t_data *data, t_types type)
{
	t_list		*node;
	t_tkn_data	*token;

	memory_allocator((void **)&node, sizeof(t_list), data);
	memory_allocator((void **)&token, sizeof(t_tkn_data), data);
	token->type = type;
	token->variable_len = 0;
	token->cmd_exec_path = NULL;
	meta_token_handler(data, node, token);
	(data->current)--;
}
