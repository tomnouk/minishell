/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:20 by aeid              #+#    #+#             */
/*   Updated: 2024/07/04 01:05:10 by aeid             ###   ########.fr       */
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
	int start;
	char *variable;
	char *var_expand;
	char *new;

	i = 0;
	start = 0;
	variable = NULL;
	var_expand = NULL;
	new = NULL;
	if ((*tkn_str)[i + 1] == '\0' || (*tkn_str)[i + 1] == ' ' || variable_len == 0)
			return ;
	while ((*tkn_str)[i] != '\0')
	{
		if ((*tkn_str)[i] == '$' && (*tkn_str)[i + 1] != '\0' && (*tkn_str)[i + 1] != ' ')
		{
			i++;
			while (ft_isprint((*tkn_str)[i]) && (*tkn_str)[i] != '\0' && !ft_ismeta((*tkn_str)[i]) && variable_len > 0 && (*tkn_str)[i] != '$')
			{
				i++;
				variable_len--;
			}
			memory_allocator((void **)&variable, i - start);
			ft_strlcpy(variable, &(*tkn_str)[start + 1], i - start);
			var_expand = search_env(mini_env, variable);
			if (var_expand)
				new = ft_strjoin(new, var_expand);
			else if ((*tkn_str)[i] != '\0')
				new = ft_strjoin(new,"");
			free(variable);
			if (var_expand)
				free(var_expand);
		}
		else if ((*tkn_str)[i] == '$')
		{
			new = ft_strjoin(new, "$");
			i++;
		}
		else
		{
			while ((*tkn_str)[i] != '\0' && !ft_ismeta((*tkn_str)[i]) && (*tkn_str)[i] != '$')	
				i++;
			new = ft_strjoin(new, ft_substr(*tkn_str, start, i - start));
		}
		start = i;
	}
	free(*tkn_str);
	*tkn_str = new;
}

void expander(t_list *mini_env, t_list *tokens)
{
	t_list *current;
	t_tkn_data *tmp;
	t_list *prev;
	t_tkn_data *prev_tmp;

	current = tokens;
	prev = current;
	prev_tmp = NULL;
	while (current)
	{
		tmp = (t_tkn_data *)current->content;
		prev_tmp = (t_tkn_data *)prev->content;
		if (tmp->type == META_DOL && prev && prev_tmp->type != META_HEREDOC)
			meta_dol_expander(mini_env, tmp->variable_len, &tmp->token);
		else if (tmp->type == SPECIAL_DQUOTE || tmp->type == WORD_DOL || tmp->type == WORD_WITH_DQUOTE_INSIDE)
		{
			dquote_expander(mini_env, tmp->variable_len, &tmp->token);
			tmp->type = WORD;
		}
		else if (tmp->type == SPECIAL_SQUOTE)
			tmp->type = WORD;
		prev = current;
		current = current->next;
	}
}
