/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:53:19 by anomourn          #+#    #+#             */
/*   Updated: 2024/08/09 19:39:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	skip_initial_spaces(char *args, t_data *data)
{
	while (!(ft_isprint(args[data->current])) && args[data->current] != '\0')
	{
		(data->start)++;
		(data->current)++;
	}
}

static void	define_type(char *args, int cur, t_types *type)
{
	if (args[cur] == '\'')
		*type = SPECIAL_SQUOTE;
	else if (args[cur] == '\"')
		*type = SPECIAL_DQUOTE;
	else if (args[cur] == '$')
		*type = META_DOL;
	else if (args[cur] == '|')
		*type = META_PIPE;
	else if (args[cur] == '>')
	{
		if (args[cur + 1] == '>')
			*type = META_APPEND;
		else
			*type = META_REDIR_OUT;
	}
	else if (args[cur] == '<')
	{
		if (args[cur + 1] == '<')
			*type = META_HEREDOC;
		else
			*type = META_REDIR_IN;
	}
	else
		*type = WORD;
}

void	ft_lexer(t_data *data)
{
	t_types	type;

	data->current = -1;
	data->start = 0;
	while (data->args[++data->current])
	{
		data->start = data->current;
		skip_initial_spaces(data->args, data);
		define_type(data->args, data->current, &type);
		if (data->args[data->current] == '\0')
			break ;
		if (type == SPECIAL_SQUOTE || type == SPECIAL_DQUOTE)
			g_exit_status = ft_special_token(data, type);
		else if (type == WORD)
			g_exit_status = ft_word_token(data, type);
		else
			ft_meta_token(data, type);
		if (data->exit_code != 0 || data->args[data->current] == '\0')
			break ;
	}
}
