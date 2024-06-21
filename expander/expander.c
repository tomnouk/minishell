/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:20 by aeid              #+#    #+#             */
/*   Updated: 2024/06/22 01:02:38 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static void meta_dol_expander(t_list *mini_env, int variable_len, char **tkn_str)
{
	int i;
	char *variable;
	char *after_expand;

	i = 0;
	variable = NULL;
	after_expand = NULL;
	if ((*tkn_str)[i + 1] == '\0' || (*tkn_str)[i + 1] == ' ' || variable_len == 0)
			return ;
	memory_allocator((void **)&variable, variable_len - 1);
	while (i < variable_len)
	{
		variable[i] = (*tkn_str)[i + 1];
		i++;
	}
	variable[i] = '\0';
	after_expand = search_env(mini_env, variable);
	free(*tkn_str);
	free(variable);
	if (after_expand)
		*tkn_str = after_expand;
	else
		*tkn_str = NULL;
}

static void dquote_expander(t_list *mini_env, int variable_len, char **tkn_str)
{
	int i;
	int curr;
	char *variable;
	char *var_expand;
	char *tmp;
	char *new;
	char *new_tmp;
	
	i = 0;
	curr = 0;
	variable = NULL;
	tmp = NULL;
	var_expand = NULL;
	new = NULL;
	new_tmp = NULL;
	if ((*tkn_str)[i + 1] == '\0' || (*tkn_str)[i + 1] == ' ' || variable_len == 0)
			return ;
	while ((*tkn_str)[i] != '\0' && variable_len > 0)
	{
		if ((*tkn_str)[i] == '$')
		{
			memory_allocator((void **)&tmp, i - curr + 1);
			ft_strlcpy(tmp, *tkn_str, i - curr + 1);
			curr = i;
			while (ft_isprint((*tkn_str)[i]) && (*tkn_str)[i] != '\0' && !ft_ismeta((*tkn_str)[i]))
				i++;
			memory_allocator((void **)&variable, i - curr);
			ft_strlcpy(variable, &(*tkn_str)[curr + 1], i - curr);
			variable_len = variable_len - (i - curr - 1);
			var_expand = search_env(mini_env, variable);
			if (var_expand)
				new = ft_strjoin(tmp, var_expand);
			else
			{
				memory_allocator((void **)&new, ft_strlen(tmp) + 1);
				ft_strlcpy(new, tmp, ft_strlen(tmp) + 1);
			}
			free(tmp);
			free(variable);
			if (var_expand)
				free(var_expand);
			curr = i;
		}
		else
			i++;
	}
	free(*tkn_str);
	*tkn_str = new;
}


void expander(t_list *mini_env, int variable_len, char **tkn_str, t_types tkn_type)
{
	int i;

	i = 0;
	if (tkn_type == META_DOL)
		meta_dol_expander(mini_env, variable_len, tkn_str);
	else if (tkn_type == SPECIAL_DQUOTE)
		dquote_expander(mini_env, variable_len, tkn_str);
	/*else if (tkn_type = WORD_DOL || tkn_type == WORD_WITH_DQUOTE_INSIDE)
	{
		
	}*/
	return ;
}
