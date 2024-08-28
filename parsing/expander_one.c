/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:24:58 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 22:23:03 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	dollar_counter_parsing(char *tkn_str)
{
	int	i;
	int	num_of_dollars;

	i = -1;
	num_of_dollars = 0;
	while (tkn_str[++i] != '\0')
	{
		if (tkn_str[i] == '$')
			num_of_dollars++;
	}
	return (num_of_dollars);
}

static void	get_var_len(char *str, int *variable_len)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '$')
		i++;
	(*variable_len) = i;
}

static char	*meta_dol_expander(t_list *mini_env, int variable_len,
		char *tkn_str, t_data *data)
{
	int		i;
	char	*variable;
	char	*after_expand;

	i = 0;
	variable = NULL;
	after_expand = NULL;
	memory_allocator((void **)&variable, variable_len + 1, data);
	while (i < variable_len)
	{
		variable[i] = tkn_str[i];
		i++;
	}
	variable[i] = '\0';
	after_expand = search_env(mini_env, variable, data);
	free(variable);
	if (after_expand)
		return (after_expand);
	data->exp_var = 1;
	return (NULL);
}

static char	*process_dollar_expansion(int variable_len, char **tkn_str,
		t_data *data, char *tmp)
{
	int		i;
	char	num_of_dollars;
	char	*string;

	i = 0;
	string = NULL;
	num_of_dollars = dollar_counter_parsing(*tkn_str);
	while (num_of_dollars > 0)
	{
		get_var_len(tmp + i + 1, &variable_len);
		free(*tkn_str);
		*tkn_str = meta_dol_expander(data->mini_env, variable_len, tmp + i + 1,
				data);
		num_of_dollars--;
		i += variable_len + 1;
		if (*tkn_str)
			string = ft_join(string, *tkn_str);
	}
	return (string);
}

void	meta_dol_expander_manager(int variable_len, char **tkn_str,
		t_data *data, t_types type)
{
	char	*string;
	char	*tmp;

	if (variable_len == 0 || (*tkn_str)[1] == '\0' || (*tkn_str)[1] == ' ')
		return ;
	tmp = ft_strdup(*tkn_str);
	string = process_dollar_expansion(variable_len, tkn_str, data, tmp);
	if (*tkn_str)
	{
		free(*tkn_str);
		*tkn_str = NULL;
	}
	if ((type == META_HEREDOC || type == META_REDIR_IN || type == META_REDIR_OUT
			|| type == META_APPEND) && data->exp_var)
	{
		*tkn_str = tmp;
		free(string);
	}
	else
	{
		*tkn_str = string;
		free(tmp);
	}
}
