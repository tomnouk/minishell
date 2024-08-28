/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_cases_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:35:53 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 23:50:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	redirect_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	if (data->args[data->current] == '>')
	{
		(data->current)++;
		if (data->args[data->current] == '>')
			(data->current)++;
	}
	else if (data->args[data->current] == '<')
	{
		(data->current)++;
		if (data->args[data->current] == '<')
			(data->current)++;
	}
	else
		(data->current)++;
	token->token = ft_substr(data->args, data->start, data->current
			- data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

void	pipe_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	(data->current)++;
	token->token = ft_substr(data->args, data->start, data->current
			- data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

void	handle_meta_status(t_data *data, t_tkn_data *token)
{
	if (data->args[data->current] == '?')
		token->type = META_STATUS;
	(data->current)++;
}
