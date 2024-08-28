/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_tkn_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:57:53 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 23:55:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_assign_word_token(int *q_flag, t_tkn_data **token, char **string,
		t_types type)
{
	(*token)->type = type;
	(*token)->variable_len = 0;
	(*token)->cmd_exec_path = NULL;
	*q_flag = 0;
	*string = NULL;
}

int	dollar_counter_lexer(char *args, int current)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < current)
	{
		if (args[i] == '$' && ft_isquote(args[i + 1]))
			count++;
		i++;
	}
	return (count);
}

void	copy_assign(char *string, t_data *data, t_tkn_data *token, t_list *node)
{
	token->token = string;
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

void	ft_copier(int *i, int c, char *string, t_data *data)
{
	(data->start)++;
	data->quote_flag--;
	while (data->args[data->start + *i] != c && data->args[data->start
			+ *i] != '\0')
	{
		string[*i] = data->args[data->start + *i];
		(*i)++;
	}
	(data->start)++;
	data->quote_flag--;
}

void	ft_copier_dol(int *i, int c, char *string, t_data **data)
{
	((*data)->start)++;
	((*data)->quote_flag)--;
	while ((*data)->args[(*data)->start + *i] == c
		&& (*data)->args[(*data)->start + *i] != '\0')
	{
		((*data)->start)++;
		((*data)->quote_flag)--;
	}
	while ((*data)->args[(*data)->start + *i] != c
		&& (*data)->args[(*data)->start + *i] != '\0')
	{
		string[*i] = (*data)->args[(*data)->start + *i];
		(*i)++;
	}
	((*data)->start)++;
	((*data)->quote_flag)--;
}
