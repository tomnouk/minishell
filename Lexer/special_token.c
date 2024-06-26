/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:30 by aeid              #+#    #+#             */
/*   Updated: 2024/06/26 23:25:37 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static char *special_token_handler(t_data *data, t_tkn_data *token)
{
	if (data->args[data->start] == '\'')
		while (data->args[data->current] && data->args[data->current] != '\'')
			(data->current)++;
	else
		while (data->args[data->current] && data->args[data->current] != '\"')
		{
			if (data->args[data->current] == '$')
				get_variable_len(data, data->current, &token->variable_len);
			(data->current)++;
		}
	(data->current)++;
	return (ft_substr(data->args, data->start + 1, data->current - data->start - 2));
}

void ft_special_token(t_data *data, t_types type)
{
	t_list *node;
	t_tkn_data *token;
	char *tmp;

	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	token->type = type;
	token->variable_len = 0;
	while (ft_isprint(data->args[data->current]) && data->args[data->current])
	{
		if (ft_isquote(data->args[data->start]))
		{
			//data->start = data->current;
			(data->current)++;
			tmp = special_token_handler(data, token);	
		}
		else
		{
			while (ft_isprint(data->args[data->current]) && !ft_isquote(data->args[data->current]))
			{
				if (data->args[data->current] == '$')
					get_variable_len(data, data->current, &token->variable_len);
				(data->current)++;
			}
			tmp = ft_substr(data->args, data->start, data->current - data->start);
		}
		token->token = ft_strjoin(token->token, tmp);
		free(tmp);
		data->start = data->current;
	}
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}
