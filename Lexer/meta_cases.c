/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:57 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 00:01:46 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	handle_dollar_meta(t_data **data, t_tkn_data **token)
{
	(*data)->current++;
	if (ft_isdigit((*data)->args[(*data)->current]))
		return (1);
	(*data)->current--;
	get_variable_len(*data, (*data)->current, &(*token)->variable_len);
	(*data)->current++;
	return (0);
}

static void	ft_quote_handler_meta(t_data **data, t_tkn_data **token)
{
	int	tmp;

	tmp = (*data)->args[(*data)->current];
	(*data)->current++;
	if ((*data)->args[(*data)->current] == '$')
	{
		if (tmp == 39)
			(*token)->variable_len = (*token)->variable_len;
		else
			get_variable_len(*data, (*data)->current, &(*token)->variable_len);
	}
	(*data)->start = (*data)->current;
	while ((*data)->args[(*data)->current]
		&& (*data)->args[(*data)->current] != tmp)
		(*data)->current++;
	if ((*token)->variable_len > 0)
		(*token)->type = META_DOL;
	else
		(*token)->type = WORD;
}

static char	*dollar_m(t_data *data, t_tkn_data *token)
{
	if (data->args[data->current] == '$')
	{
		if (handle_dollar_meta(&data, &token))
			return (NULL);
	}
	if (ft_isquote(data->args[data->current]))
		ft_quote_handler_meta(&data, &token);
	else if (ft_isalpha(data->args[data->current]))
	{
		while (ft_isprint(data->args[data->current]))
		{
			(data->current)++;
			if (ft_ismeta(data->args[data->current])
				|| ft_isquote(data->args[data->current]))
				break ;
		}
	}
	else if (ft_isdigit(data->args[data->current])
		|| data->args[data->current] == '?')
	{
		if (data->args[data->current] == '?')
			token->type = META_STATUS;
		(data->current)++;
	}
	return (ft_substr(data->args, data->start, data->current - data->start));
}

static void	ft_add_to_token(t_data **data, t_tkn_data **token)
{
	char	*tmp;

	tmp = dollar_m(*data, *token);
	(*token)->token = ft_join((*token)->token, tmp);
	free(tmp);
	(*data)->current++;
}

void	dollar_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	if (data->args[data->current] == '$')
	{
		if (handle_dollar_meta(&data, &token))
			return ;
	}
	if (ft_isquote(data->args[data->current]))
		ft_quote_handler_meta(&data, &token);
	else if (ft_isalpha(data->args[data->current]))
	{
		while (ft_isprint(data->args[data->current]))
		{
			(data->current)++;
			if (ft_ismeta(data->args[data->current])
				|| ft_isquote(data->args[data->current]))
				break ;
		}
	}
	else if (ft_isdigit(data->args[data->current])
		|| data->args[data->current] == '?')
		handle_meta_status(data, token);
	token->token = ft_substr(data->args, data->start, data->current
			- data->start);
	if (data->args[data->current] == '\"' || data->args[data->current] == '\'')
		ft_add_to_token(&data, &token);
	assign_nodes(node, token, data);
}
