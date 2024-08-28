/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:44:06 by aeid              #+#    #+#             */
/*   Updated: 2024/08/07 17:51:52 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	iteration_check(char *str, t_types *type)
{
	if (!ft_strncmp(str, "export", 7))
		*type = WORD_EXPORT;
	else if (!ft_strncmp(str, "unset", 6))
		*type = WORD_UNSET;
	else if (!ft_strncmp(str, "env", 4))
		*type = WORD_ENV;
	else if (!ft_strncmp(str, "echo", 5))
		*type = WORD_ECHO;
	else if ((!ft_strncmp(str, "cd", 3)))
		*type = WORD_CD;
	else if (!ft_strncmp(str, "exit", 5))
		*type = WORD_EXIT;
	else if ((!ft_strncmp(str, "pwd", 4)))
		*type = WORD_PWD;
	else if (!ft_strncmp(str, "/", 1) || !ft_strncmp(str, "./", 2))
		*type = COMMAND;
}

void	define_builtins(t_list *token)
{
	char		*tkn_str;
	t_list		*current;
	t_list		*prev;
	t_tkn_data	*prev_tmp;

	current = token;
	prev = current;
	prev_tmp = NULL;
	while (current != NULL)
	{
		prev_tmp = (t_tkn_data *)(prev->content);
		if (prev_tmp->type != META_HEREDOC)
		{
			tkn_str = ((t_tkn_data *)(current->content))->token;
			iteration_check(tkn_str, &((t_tkn_data *)(current->content))->type);
		}
		prev = current;
		current = current->next;
	}
}
