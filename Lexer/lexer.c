/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:39:40 by aeid              #+#    #+#             */
/*   Updated: 2024/06/12 18:57:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void skip_initial_spaces(char *args, t_data *data)
{
	while (!(ft_isprint(args[data->current])) && args[data->current] != '\0')
	{
		(data->start)++;
		(data->current)++;
	}
}

static int check_if_empty(char *args)
{
	size_t i;

	i = 0;
	while (!(ft_isprint(args[i])))
		i++;
	if (ft_strlen(args) == i)
		return (1);
	return (0);
}

static void define_type(char *args, int cur, t_types *type)
{
	if (args[cur] == '\'')
		*type = SPECIAL_SQUOTE;
	else if (args[cur] == '\"')
		*type = SPECIAL_DQUOTE;
	else if (ft_ismeta(args[cur]))
		*type = META;
	else
		*type = WORD;
}

void ft_tokenizing(t_data *data)
{
	t_types type;

	data->current = -1;
	data->start = 0;
	if (check_if_empty(data->args))
		return ;
	while (data->args[++data->current])
	{
		data->start = data->current;
		skip_initial_spaces(data->args, data);
		define_type(data->args, data->current, &type);
		if (type == SPECIAL_SQUOTE || type == SPECIAL_DQUOTE)
			ft_special_token(data, type);
		else if (type == META)
			ft_meta_token(data, type);
		else
			ft_word_token(data, type);
	}
}
