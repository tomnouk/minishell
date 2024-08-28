/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:20:10 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 22:46:06 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	check_initial_conditions(t_list *current, t_tkn_data *string)
{
	if (!current->next)
	{
		if (string->type == META_PIPE)
			ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
				2);
		else
			ft_ptsd("minishell: syntax error near unexpected token `newline'\n",
				2);
		return (-1);
	}
	return (0);
}

static int	check_next_token_conditions(t_tkn_data *string, t_tkn_data *next)
{
	if (string->type != META_PIPE && next->type == META_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (-1);
	}
	if (next->type == string->type)
	{
		if (string->type == META_PIPE)
			ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
				2);
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			write(2, next->token, ft_strlen(next->token));
			ft_putstr_fd("'\n", 2);
		}
		return (-1);
	}
	if (next->type == META_PIPE && string->type == META_HEREDOC)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (-1);
	}
	return (0);
}

static int	check_ambiguous_redirect(t_tkn_data *string, t_tkn_data *next,
		t_data *data)
{
	if (((is_redirection(string, 0))) && (next->type != WORD
			&& next->type != META_DOL && next->type != WORD_WITH_DQUOTE_INSIDE
			&& next->type != WORD_WITH_SQUOTE_INSIDE
			&& next->type != SPECIAL_DQUOTE && next->type != SPECIAL_SQUOTE))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
		write(2, "'", 1);
		write(2, next->token, ft_strlen(next->token));
		write(2, "'", 1);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	if ((string->type == META_REDIR_IN || string->type == META_REDIR_OUT
			|| string->type == META_APPEND) && (data->exp_var == 1))
	{
		ft_putstr_fd("minishell: ", 2);
		write(2, "'", 1);
		write(2, next->token, ft_strlen(next->token));
		write(2, "'", 1);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		return (-1);
	}
	return (0);
}

static int	ft_check_next_token(t_list *current, t_tkn_data *string,
		t_data *data)
{
	t_tkn_data	*next;

	next = NULL;
	if (is_redirection(string, 1))
	{
		if (check_initial_conditions(current, string) == -1)
			return (1);
		next = (t_tkn_data *)current->next->content;
		if (check_next_token_conditions(string, next) == -1)
			return (2);
		if (check_ambiguous_redirect(string, next, data) == -1)
			return (1);
	}
	return (0);
}

void	ft_parser(t_list *tokens, t_data *data)
{
	t_list		*current;
	t_tkn_data	*string;
	int			status;

	current = tokens;
	string = (t_tkn_data *)current->content;
	if (string->type == META_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		data->exit_code = -1;
		g_exit_status = 2;
		return ;
	}
	while (current)
	{
		string = (t_tkn_data *)current->content;
		status = ft_check_next_token(current, string, data);
		if (status != 0)
		{
			data->exit_code = -1;
			g_exit_status = status;
			return ;
		}
		current = current->next;
	}
}
