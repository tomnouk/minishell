/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:20:10 by aeid              #+#    #+#             */
/*   Updated: 2024/07/04 00:58:32 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_check_next_token(t_list *current, t_tkn_data *string)
{
	t_tkn_data	*next;

	next = NULL;
	if (string->type == META_PIPE || string->type == META_REDIR_IN
		|| string->type == META_REDIR_OUT || string->type == META_APPEND
		|| string->type == META_HEREDOC)
	{
		if (!current->next)
		{
			if (string->type == META_PIPE)
				ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
						2);
			else
				ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
						2);
			exit(2);
		}
		next = (t_tkn_data *)current->next->content;
		if (next->type == string->type)
		{
			if (string->type == META_PIPE)
				ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
						2);
			else
				ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
						2);
			exit(2);
		}
	}
}

static void	ft_organizer(t_list *tokens)
{
	t_list		*current;
	t_list		*tmp;
	t_list		*redir_tmp;
	t_tkn_data	*string;

	current = tokens;
	string = NULL;
	redir_tmp = NULL;
	tmp = NULL;
	while (current)
	{
		string = (t_tkn_data *)current->content;
		while (string->type != META_PIPE)
		{
			if (string->type == META_REDIR_IN || string->type == META_REDIR_OUT
				|| string->type == META_APPEND || string->type == META_HEREDOC)
				redir_tmp = current;
			else
				break ;
			current = current->next->next;
			if (!current)
				return ;
			string = (t_tkn_data *)current->content;
			if ((string->type == WORD || string->type == COMMAND) && current
				&& string->type != META_PIPE)
			{
				tmp->next = current;
				redir_tmp->next->next = current->next;
				current->next = redir_tmp;
				current = redir_tmp->next;
			}
			//printTokens(tokens);
		}
		tmp = current;
		current = current->next;
		//printTokens(tokens);
		//printf("\n");
	}
}

void	ft_parser(t_data *data, t_list *tokens)
{
	t_list		*current;
	t_tkn_data	*string;

	current = tokens;
	string = NULL;
	printf("here%d\n", data->list_size);
	while (current)
	{
		string = (t_tkn_data *)current->content;
		ft_check_next_token(current, string);
		current = current->next;
	}
	ft_organizer(tokens);
}
