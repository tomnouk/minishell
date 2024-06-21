/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:20 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 23:16:30 by aeid             ###   ########.fr       */
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
