/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:10:35 by aeid              #+#    #+#             */
/*   Updated: 2024/06/12 18:10:31 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static void copy_assign(char *string, t_data *data, t_tkn_data *token, t_list *node, int quote_flag)
{
	
	string = ft_substr(data->args, data->start, data->current - data->start);
	token->token = string;
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

static void  ft_copier()

static void quote_removal_copy(char *string, t_data *data, t_tkn_data *token, t_list *node, int quote_flag)
{
	int len;
	int i;

	len = data->current - data->start - quote_flag;
	i = 0;
	memory_allocator((void **)&string, len + 1);
	while (i < len && quote_flag != 0)
	{
		if (data->args[data->start + i] == '\"')
		{
			(data->start)++;
			quote_flag--;
			while (data->args[data->start + i] != '\"' && data->args[data->start + i] != '\n' && data->args[data->start + i] != '\0')
			{
				string[i] = data->args[data->start + i];
				i++;
			}
			token->type = WORD_D;
		}
		else if (data->args[data->start + i] == '\'')
		{
			(data->start)++;
			quote_flag--;
			while (data->args[data->start + i] != '\'' && data->args[data->start + i] != '\n' && data->args[data->start + i] != '\0')
			{
				string[i] = data->args[data->start + i];
				i++;
			}
		}
		else
		{
			string[i] = data->args[data->start + i];
			i++;
		}
	}
	string[i] = '\0';
	token->token = string;
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

void ft_word_token(t_data *data, t_types type)
{
	t_list *node;
	char *string;
	t_tkn_data *token;
	int quote_flag;
	
	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	quote_flag = 0;
	token->type = type;
	while (data->args[data->current] && data->args[data->current] != '\n')
	{
		if (!ft_isprint(data->args[data->current]) && !(quote_flag % 2))
			break;
		else if (ft_ismeta(data->args[data->current]) && !(quote_flag % 2))
			break;
		else if (data->args[data->current] == '\"')
		{
			quote_flag++;
			(data->current)++;
			while (data->args[data->current] != '\"' && data->args[data->current] != '\n')
				(data->current)++;
			if (data->args[data->current] == '\"')
				quote_flag++;
			
		}
		else if (data->args[data->current] == '\'')
		{
			quote_flag++;
			(data->current)++;
			while (data->args[data->current] != '\'' && data->args[data->current] != '\n')
				(data->current)++;
			if (data->args[data->current] == '\'')
				quote_flag++;
		}
		(data->current)++; 
	}
	if (!(quote_flag % 2))
		quote_removal_copy(string, data, token, node, quote_flag);
	else
		copy_assign(string, data, token, node, quote_flag);;
	if (data->current == '\n')
		(data->current)++;
}

