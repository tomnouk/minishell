/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:30:24 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 15:58:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	join_variable_expansion(char **new, char *var_expand,
		char **tkn_str, int i)
{
	if (var_expand)
		*new = ft_join(*new, var_expand);
	else if ((*tkn_str)[i] != '\0')
		*new = ft_join(*new, "");
}

static void	replace_token_string(char **tkn_str, char *new)
{
	free(*tkn_str);
	*tkn_str = new;
}

static void	free_variables_exp(char *variable, char *var_expand)
{
	free(variable);
	if (var_expand)
		free(var_expand);
}

static bool	is_variable_expansion(char **tkn_str, int i)
{
	return ((*tkn_str)[i] == '$' && (*tkn_str)[i + 1] != '\0' && (*tkn_str)[i
		+ 1] != ' ');
}

void	dquote_expander(t_list *env, int vlen, char **str, t_data *data)
{
	int		i;
	int		start;
	char	*new;
	char	*variable;
	char	*var_expand;

	initialize_dquote_expander(&i, &start, &new, &variable);
	if (vlen == 0 || (*str)[i + 1] == '\0' || (*str)[i + 1] == ' ')
		return ;
	while ((*str)[i] != '\0')
	{
		if (is_variable_expansion(str, i))
		{
			process_variable(str, &i, &vlen);
			memory_allocator((void **)&variable, i - start, data);
			ft_strlcpy(variable, &(*str)[start + 1], i - start);
			var_expand = search_env(env, variable, data);
			join_variable_expansion(&new, var_expand, str, i);
			free_variables_exp(variable, var_expand);
			start = i;
		}
		else
			process_remaining_characters(str, &i, &start, &new);
	}
	replace_token_string(str, new);
}

///////////////////////////////////////////////
// static void	expand_variable(t_list *mini_env, int *variable_len,
			//char **tkn_str,
// 		t_data *data, int *i, int *start, char **new)
// {
// 	char	*variable;
// 	char	*var_expand;

// 	variable = NULL;
// 	var_expand = NULL;
// 	(*i)++;
// 	while (ft_isprint((*tkn_str)[*i]) && (*tkn_str)[*i] != '\0'
// 		&& !ft_ismeta((*tkn_str)[*i]) && *variable_len > 0
// 		&& (*tkn_str)[*i] != '$')
// 	{
// 		(*i)++;
// 		(*variable_len)--;
// 	}
// 	memory_allocator((void **)&variable, *i - *start, data);
// 	ft_strlcpy(variable, &(*tkn_str)[*start + 1], *i - *start);
// 	var_expand = search_env(mini_env, variable, data);
// 	if (var_expand)
// 		*new = ft_join(*new, var_expand);
// 	else if ((*tkn_str)[*i] != '\0')
// 		*new = ft_join(*new, "");
// 	free(variable);
// 	if (var_expand)
// 		free(var_expand);
// }

// static void	append_non_dollar_characters(char **tkn_str, int *i, int *start,
// 		char **new)
// {
// 	char	*tmp;

// 	tmp = NULL;
// 	while ((*tkn_str)[*i] != '\0' && !ft_ismeta((*tkn_str)[*i])
// 		&& (*tkn_str)[*i] != '$')
// 		(*i)++;
// 	tmp = ft_substr(*tkn_str, *start, *i - *start);
// 	*new = ft_join(*new, tmp);
// 	free(tmp);
// }

// static void initialize_dquote_expander(int *i, int *start, char **new)
// {
//     *i = 0;
//     *start = 0;
//     *new = NULL;
// }

// void	dquote_expander(t_list *mini_env, int variable_len, char **tkn_str,
		//	t_data *data)
// {
// 	int		i;
// 	int		start;
// 	char	*new;

// 	initialize_dquote_expander(&i, &start, &new);
//     if (variable_len == 0 || (*tkn_str)[i + 1] == '\0' || (*tkn_str)[i
	//	+ 1] == ' ')
// 		return ;
// 	while ((*tkn_str)[i] != '\0')
// 	{
// 		if ((*tkn_str)[i] == '$' && (*tkn_str)[i + 1] != '\0' && (*tkn_str)[i
// 			+ 1] != ' ')
// 		{
// 			expand_variable(mini_env, &variable_len, tkn_str, data, &i, &start,
// 					&new);
// 		}
// 		else if ((*tkn_str)[i] == '$')
// 		{
// 			new = ft_join(new, "$");
// 			i++;
// 		}
// 		else
// 			append_non_dollar_characters(tkn_str, &i, &start, &new);
// 		start = i;
// 	}
// 	free(*tkn_str);
// 	*tkn_str = new;
// }