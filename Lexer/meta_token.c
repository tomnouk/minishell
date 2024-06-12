/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:15:14 by aeid              #+#    #+#             */
/*   Updated: 2024/06/11 19:03:25 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static void dollar_token_handler(t_data *data, int *current)
{
	*current++;
	if (ft_isprint(data->args[*current]))
		while (data->args[*current] && ft_isprint(data->args[*current]) && !ft_isquote(data->args[*current]))
			(*current)++;
	
}

void ft_meta_token(t_data *data, t_types type)
{
	t_list *node;
	char *string;
	t_tkn_data *token;

	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	if (data->args[*current] == '$')
	{
		dollar_token_handler(data, current);
	}
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
