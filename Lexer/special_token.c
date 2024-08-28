/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:30 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 19:39:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_assigning(t_tkn_data **token, int *quote_flag, t_types type)
{
	(*token)->type = type;
	(*token)->token = NULL;
	(*token)->variable_len = 0;
	(*token)->cmd_exec_path = NULL;
	(*quote_flag) = 0;
}

static void	ft_quote_handler(t_data **data, t_tkn_data **token, int *quote_flag,
		char **tmp)
{
	int	prev;

	prev = 0;
	(*quote_flag)++;
	prev = (*data)->args[((*data)->current)];
	((*data)->current)++;
	(*tmp) = special_token_handler(*data, *token, quote_flag, prev);
}

static void	else_handler(t_data **data, t_tkn_data **token, char **tmp)
{
	while (ft_isprint((*data)->args[(*data)->current])
		&& !ft_isquote((*data)->args[(*data)->current]))
	{
		if ((*data)->args[(*data)->current] == '$')
			get_variable_len(*data, (*data)->current, &(*token)->variable_len);
		((*data)->current)++;
	}
	(*tmp) = ft_substr((*data)->args, (*data)->start, (*data)->current
			- (*data)->start);
}

static int	ft_unclosed_quote_error(int quote_flag, t_data **data)
{
	if (quote_flag % 2 != 0)
	{
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		(*data)->exit_code = -1;
		g_exit_status = 1;
		return (-1);
	}
	return (0);
}

int	ft_special_token(t_data *data, t_types type)
{
	t_list		*node;
	t_tkn_data	*token;
	char		*tmp;
	int			quote_flag;

	memory_allocator((void **)&node, sizeof(t_list), data);
	memory_allocator((void **)&token, sizeof(t_tkn_data), data);
	ft_assigning(&token, &quote_flag, type);
	while (data->args[data->current] && ft_isprint(data->args[data->current]))
	{
		if (ft_isquote(data->args[data->start]))
			ft_quote_handler(&data, &token, &quote_flag, &tmp);
		else
			else_handler(&data, &token, &tmp);
		token->token = ft_join(token->token, tmp);
		free(tmp);
		data->start = data->current;
	}
	assign_nodes(node, token, data);
	if (data->args[data->current] == '\0')
		data->current--;
	if (ft_unclosed_quote_error(quote_flag, &data) == -1)
		return (-1);
	return (g_exit_status);
}
