/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:57 by aeid              #+#    #+#             */
/*   Updated: 2024/07/03 22:30:20 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void redirect_meta(t_data *data, t_list *node, t_tkn_data *token)
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
	token->token = ft_substr(data->args, data->start, data->current - data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
	(data->current)--;
}

void pipe_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	(data->current)++;
	token->token = ft_substr(data->args, data->start, data->current - data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
	(data->current)--;
}

//$ sign can be followed by alpha and _
// number 0 to 9
// ? sign
// else take only $ sign
void dollar_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	int tmp;
	
	tmp = 0;
	get_variable_len(data, data->current, &token->variable_len);
	(data->current)++;
	if (ft_isquote(data->args[data->current]))
	{
		tmp = data->args[data->current];
		(data->current)++;
		data->start = data->current;
		while (data->args[data->current] != tmp)
			(data->current)++;
	}
	else if (ft_isalpha(data->args[data->current]))
		while ((ft_isalpha(data->args[data->current]) || data->args[data->current] == '_'))
			(data->current)++;
	else if (ft_isdigit(data->args[data->current]) || data->args[data->current] == '?')
		(data->current)++;
	token->token = ft_substr(data->args, data->start, data->current - data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}
