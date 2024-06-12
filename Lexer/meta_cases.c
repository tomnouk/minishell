/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:57 by aeid              #+#    #+#             */
/*   Updated: 2024/06/12 21:15:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void dollar_meta(t_data *data, t_list *node, t_tkn_data *token)
{
	(data->current)++;
	if (ft_isalpha(data->args[data->current]))
			while ((ft_isalpha(data->args[data->current]) || data->args[data->current] == '_'))
				(data->current)++;
	else
	{
		if (data->args[data->current] == '?')
			(data->current)++;
		else if (ft_isquote(data->args[data->current]))
			data->start = data->current - 1;
	}
	token->token = ft_substrr(data->args, data->start, data->current - data->start);
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
	(data->current)++;
	if (data->args[data->current] == '\n')
		(data->current)++;
}
