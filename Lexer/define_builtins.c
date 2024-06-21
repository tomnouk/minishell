/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:44:06 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 16:51:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void define_builtins(char *tkn_str, t_types tkn_type)
{
	if (tkn_type == WORD || tkn_type == WORD_WITH_DQUOTE_INSIDE)
	{
		if (!ft_strncmp(tkn_str, "export", 7))
			tkn_type = WORD_EXPORT;
		else if (!ft_strncmp(tkn_str, "unset", 6))
			tkn_type = WORD_UNSET;
		else if (!ft_strncmp(tkn_str, "env", 4))
			tkn_type = WORD_ENV;
		else if (!ft_strncmp(tkn_str, "echo", 5))
			tkn_type = WORD_ECHO;
		else if (!ft_strncmp(tkn_str, "cd", 3))
			tkn_type = WORD_CD;
		else if (!ft_strncmp(tkn_str, "exit", 5))
			tkn_type = WORD_EXIT;
		else if (!ft_strncmp(tkn_str, "pwd", 4))
			tkn_type = WORD_PWD;
	}
	return ;
}