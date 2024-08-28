/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_tkn_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:55:28 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 23:50:56 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	dquote_removal_handler(char **string, t_data **data,
		t_tkn_data **token, int *i)
{
	ft_copier(i, '\"', *string, *data);
	(*token)->type = WORD_WITH_DQUOTE_INSIDE;
	if ((*token)->type != WORD_DOL)
		(*token)->type = WORD_WITH_DQUOTE_INSIDE;
}

static void	squote_removal_handler(char **string, t_data **data,
		t_tkn_data **token, int *i)
{
	ft_copier(i, '\'', *string, *data);
	(*token)->type = WORD_WITH_SQUOTE_INSIDE;
}

static void	else_handler(char **string, t_data **data, int *i)
{
	(*string)[*i] = (*data)->args[(*data)->start + *i];
	(*i)++;
}

static void	set_token_type_based_on_quote(t_data *data, t_tkn_data *token,
		int i)
{
	if (data->args[data->start + i] == '\"')
		token->type = WORD_WITH_DQUOTE_INSIDE;
	if (data->args[data->start + i] == '\'')
		token->type = WORD_WITH_SQUOTE_INSIDE;
}

void	quote_removal_copy(char *string, t_data *data, t_tkn_data *token,
		t_list *node)
{
	int	len;
	int	i;
	int	dol_count;

	dol_count = dollar_counter_lexer(data->args, data->current);
	len = data->current - data->start - data->quote_flag - dol_count;
	i = 0;
	memory_allocator((void **)&string, len + 1, data);
	while (i < (len + dol_count))
	{
		if (data->args[data->start + i] == '$'
			&& ft_isquote(data->args[data->start + i + 1]))
			ft_copier_dol(&i, data->args[data->start + i + 1], string, &data);
		else if (data->args[data->start + i] == '\"')
			dquote_removal_handler(&string, &data, &token, &i);
		else if (data->args[data->start + i] == '\'')
			squote_removal_handler(&string, &data, &token, &i);
		else
			else_handler(&string, &data, &i);
	}
	string[i] = '\0';
	set_token_type_based_on_quote(data, token, i);
	copy_assign(string, data, token, node);
}
