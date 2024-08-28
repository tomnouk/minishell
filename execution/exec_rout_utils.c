/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rout_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:36:24 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 20:53:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	check_type(t_tkn_data *tokendata, int flag)
{
	if (flag == 0)
	{
		if (tokendata->type == WORD
			|| tokendata->type == WORD_WITH_DQUOTE_INSIDE
			|| tokendata->type == WORD_WITH_SQUOTE_INSIDE
			|| tokendata->type == WORD_DOL || tokendata->type == META_DOL)
			return (true);
	}
	else if (flag == 1)
	{
		if (tokendata->type == SPECIAL_DQUOTE
			|| tokendata->type == SPECIAL_SQUOTE
			|| tokendata->type == WORD_WITH_DQUOTE_INSIDE
			|| tokendata->type == WORD_WITH_SQUOTE_INSIDE)
			return (true);
	}
	return (false);
}

bool	is_redirection(t_tkn_data *tokendata, int flag)
{
	if (flag == 0)
	{
		if (tokendata->type == META_REDIR_IN
			|| tokendata->type == META_REDIR_OUT
			|| tokendata->type == META_APPEND
			|| tokendata->type == META_HEREDOC)
			return (true);
	}
	else if (flag == 1)
	{
		if (tokendata->type == META_PIPE || tokendata->type == META_REDIR_IN
			|| tokendata->type == META_REDIR_OUT
			|| tokendata->type == META_APPEND
			|| tokendata->type == META_HEREDOC)
			return (true);
	}
	return (false);
}

int	ft_get_number_of_redirections(t_list *tokens)
{
	t_list		*current;
	t_tkn_data	*tokendata;
	size_t		num_redirs;

	num_redirs = 0;
	current = tokens;
	tokendata = (t_tkn_data *)current->content;
	while (current != NULL && tokendata->type != META_PIPE)
	{
		if (is_redirection(tokendata, 0))
			num_redirs++;
		current = current->next;
		if (current != NULL)
			tokendata = (t_tkn_data *)current->content;
	}
	return (num_redirs);
}

int	ft_get_number_of_redir_in_or_out(t_list *tokens, t_types type1,
		t_types type2)
{
	t_list		*current;
	t_tkn_data	*tokendata;
	size_t		num_redirs;

	num_redirs = 0;
	current = tokens;
	tokendata = (t_tkn_data *)current->content;
	while (current != NULL && tokendata->type != META_PIPE)
	{
		if (tokendata->type == type1 || tokendata->type == type2)
			num_redirs++;
		current = current->next;
		if (current != NULL)
			tokendata = (t_tkn_data *)current->content;
	}
	return (num_redirs);
}
