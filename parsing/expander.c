/* ************************************************************************** */
/*				                                                              */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:20 by aeid              #+#    #+#             */
/*   Updated: 2024/08/05 11:34:48 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_handle_status(t_tkn_data *current)
{
	char	*status;

	status = ft_itoa(g_exit_status);
	free(current->token);
	current->token = status;
	current->type = WORD;
}

static void	type_checker(t_types *cur_type, t_types *prev_type, t_data *data,
		t_tkn_data *current)
{
	if (*cur_type == META_DOL && *prev_type != META_HEREDOC)
		meta_dol_expander_manager(current->variable_len, &current->token, data,
			*prev_type);
	else if (*cur_type == SPECIAL_DQUOTE || *cur_type == WORD_DOL
		|| *cur_type == WORD_WITH_DQUOTE_INSIDE)
	{
		dquote_expander(data->mini_env, current->variable_len, &current->token,
			data);
		if (*prev_type != META_HEREDOC)
			current->type = WORD;
	}
	else if (*cur_type == META_STATUS)
		ft_handle_status(current);
	else if ((*cur_type == SPECIAL_SQUOTE
			|| *cur_type == WORD_WITH_SQUOTE_INSIDE)
		&& *prev_type != META_HEREDOC)
		current->type = WORD;
}

void	expander(t_list *tokens, t_data *data)
{
	t_list		*current;
	t_tkn_data	*tmp;
	t_list		*prev;
	t_tkn_data	*prev_tmp;

	current = tokens;
	prev = current;
	prev_tmp = NULL;
	tmp = NULL;
	while (current)
	{
		tmp = (t_tkn_data *)current->content;
		prev_tmp = (t_tkn_data *)prev->content;
		type_checker(&tmp->type, &prev_tmp->type, data, tmp);
		prev = current;
		current = current->next;
	}
}
