/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:30 by aeid              #+#    #+#             */
/*   Updated: 2024/06/14 00:46:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static void special_token_handler(t_data *data, t_list *node, t_tkn_data *token)
{
	(data->current)++;
	if (data->args[data->start] == '\'')
		while (data->args[data->current] && data->args[data->current] != '\'')
			(data->current)++;
	else
		while (data->args[data->current] && data->args[data->current] != '\"')
			(data->current)++;
	token->token = ft_substr(data->args, data->start + 1, data->current - data->start - 1);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

void ft_special_token(t_data *data, t_types type)
{
	t_list *node;
	t_tkn_data *token;

	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	token->type = type;
	special_token_handler(data, node, token);
	(data->current)++;
	if (data->args[data->current] == '\n')
		(data->current)++;
}
