/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:15:14 by aeid              #+#    #+#             */
/*   Updated: 2024/06/13 16:43:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h" 

static void dollar_token_handler(t_data *data, t_list *node, t_tkn_data *token)
{
	if (data->args[data->current] == '$')
		dollar_meta(data, node, token);
	else if (data->args[data->current] == '|')
		pipe_meta(data, node, token);
	else if (data->args[data->current] == '>' || data->args[data->current] == '<')
		redirect_meta(data, node, token);
}

void ft_meta_token(t_data *data, t_types type)
{
	t_list *node;
	t_tkn_data *token;

	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	token->type = type;
	dollar_token_handler(data, node, token);
}

/*
	if (data->args[*current] == '|' || data->args[*current] == '>' || data->args[*current] == '<')
	{
		string = ft_substr(data->args, *current, 1);
		token->token = string;
		token->type = type;
		node->content = token;
		node->next = NULL;
		ft_lstadd_back(&data->tokens, node);
		(*current)++;
		*start = *current;
	}
	else if (data->args[*current] == '$')
	{
		(*current)++;
		while (data->args[*current] && data->args[*current] != ' ' && data->args[*current] != '\t' && data->args[*current] != '\n')
			(*current)++;
		string = ft_substr(data->args, *start, *current - *start);
		token->token = string;
		token->type = type;
		node->content = token;
		node->next = NULL;
		ft_lstadd_back(&data->tokens, node);
		*start = *current;
	}
}
*/
