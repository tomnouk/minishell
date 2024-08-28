/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shame_of_norm_exp_dquote.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:03:38 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 15:34:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	handle_single_dollar(char **new, int *i)
{
	*new = ft_join(*new, "$");
	(*i)++;
}

static void	append_non_dollar_characters(char **tkn_str, int *i, int *start,
		char **new)
{
	char	*tmp;

	tmp = NULL;
	while ((*tkn_str)[*i] != '\0' && !ft_ismeta((*tkn_str)[*i])
		&& (*tkn_str)[*i] != '$')
		(*i)++;
	tmp = ft_substr(*tkn_str, *start, *i - *start);
	*new = ft_join(*new, tmp);
	free(tmp);
}

void	process_remaining_characters(char **tkn_str, int *i, int *start,
		char **new)
{
	if ((*tkn_str)[*i] == '$')
		handle_single_dollar(new, i);
	else
		append_non_dollar_characters(tkn_str, i, start, new);
	*start = *i;
}

void	initialize_dquote_expander(int *i, int *start, char **new,
		char **variable)
{
	*i = 0;
	*start = 0;
	*new = NULL;
	*variable = NULL;
}

void	process_variable(char **tkn_str, int *i, int *variable_len)
{
	(*i)++;
	while (ft_isprint((*tkn_str)[*i]) && (*tkn_str)[*i] != '\0'
		&& !ft_ismeta((*tkn_str)[*i]) && *variable_len > 0
		&& (*tkn_str)[*i] != '$' && (*tkn_str)[*i] != ':')
	{
		(*i)++;
		(*variable_len)--;
	}
}
