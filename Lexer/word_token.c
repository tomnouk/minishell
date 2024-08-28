/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:10:35 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 00:00:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	dquote_checker_handler(t_data **data, t_tkn_data **token,
		int *quote_flag)
{
	(*quote_flag)++;
	((*data)->current)++;
	while ((*data)->args[(*data)->current] != '\"'
		&& (*data)->args[(*data)->current] != '\0')
	{
		if ((*data)->args[(*data)->current] == '$')
			get_variable_len(*data, (*data)->current, &(*token)->variable_len);
		((*data)->current)++;
	}
	if ((*data)->args[(*data)->current] == '\"')
		(*quote_flag)++;
	if ((*data)->args[(*data)->current]
		&& ft_isprint((*data)->args[(*data)->current + 1])
		&& !ft_ismeta((*data)->args[(*data)->current + 1])
		&& (*data)->args[(*data)->current + 1] != '$')
	{
		((*data)->current)++;
		while (ft_isprint((*data)->args[(*data)->current])
			&& !ft_ismeta((*data)->args[(*data)->current])
			&& (*data)->args[(*data)->current] != '$'
			&& (*data)->args[(*data)->current] != '\0')
			((*data)->current)++;
		return (1);
	}
	return (0);
}

static int	squote_checker_handler(t_data **data, int *quote_flag)
{
	(*quote_flag)++;
	((*data)->current)++;
	while ((*data)->args[(*data)->current] != '\''
		&& (*data)->args[(*data)->current] != '\0')
		((*data)->current)++;
	if ((*data)->args[(*data)->current] == '\'')
		(*quote_flag)++;
	if (ft_isprint((*data)->args[(*data)->current + 1])
		&& !ft_ismeta((*data)->args[(*data)->current + 1])
		&& (*data)->args[(*data)->current + 1] != '$')
	{
		((*data)->current)++;
		while (ft_isprint((*data)->args[(*data)->current])
			&& !ft_ismeta((*data)->args[(*data)->current])
			&& (*data)->args[(*data)->current] != '$'
			&& (*data)->args[(*data)->current] != '\0')
			((*data)->current)++;
		return (1);
	}
	return (0);
}

static int	ft_checker(t_data *data, int *quote_flag, t_tkn_data *token)
{
	if (!ft_isprint(data->args[data->current]) && !(*quote_flag % 2))
		return (1);
	else if (ft_ismeta(data->args[data->current]) && !(*quote_flag % 2))
		return (1);
	else if (data->args[data->current] == '$')
	{
		token->type = WORD_DOL;
		get_variable_len(data, data->current, &token->variable_len);
	}
	else if (data->args[data->current] == '\"')
	{
		if (dquote_checker_handler(&data, &token, quote_flag))
			return (1);
	}
	else if (data->args[data->current] == '\'')
	{
		if (squote_checker_handler(&data, quote_flag))
			return (1);
	}
	return (0);
}

static int	qflag_word_token_handler(t_data **data, t_tkn_data **token,
		t_list **node, char **string)
{
	if ((*data)->quote_flag % 2 != 0)
	{
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		((*data)->current)--;
		(*data)->exit_code = -1;
		g_exit_status = -1;
		return (-1);
	}
	if (!((*data)->quote_flag % 2) && (*data)->quote_flag != 0)
		quote_removal_copy(*string, *data, *token, *node);
	else
	{
		*string = ft_substr((*data)->args, (*data)->start, (*data)->current
				- (*data)->start);
		copy_assign(*string, *data, *token, *node);
	}
	((*data)->current)--;
	return (0);
}

int	ft_word_token(t_data *data, t_types type)
{
	t_list		*node;
	char		*string;
	t_tkn_data	*token;
	int			quote_flag;

	memory_allocator((void **)&node, sizeof(t_list), data);
	memory_allocator((void **)&token, sizeof(t_tkn_data), data);
	ft_assign_word_token(&quote_flag, &token, &string, type);
	while (data->args[data->current])
	{
		if (ft_checker(data, &quote_flag, token))
			break ;
		if (data->args[data->current])
			(data->current)++;
	}
	data->quote_flag = quote_flag;
	if (qflag_word_token_handler(&data, &token, &node, &string) == -1)
		return (-1);
	return (g_exit_status);
}
