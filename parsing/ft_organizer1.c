/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organizer1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:52:40 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 20:52:45 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_set_null(t_list **tmp, t_list **redir_tmp)
{
	*tmp = NULL;
	*redir_tmp = NULL;
}

static bool	update_current_and_prev(t_list **current, t_list **prev,
		t_tkn_data **token_data)
{
	*current = (*current)->next;
	*prev = *current;
	*current = (*current)->next;
	if (!*current)
		return (true);
	*token_data = (t_tkn_data *)(*current)->content;
	return (false);
}

static bool	ft_get_the_head(t_list **head, t_list **tokens, t_list **prev)
{
	t_list		*current;
	t_tkn_data	*token_data;

	current = *tokens;
	token_data = (t_tkn_data *)current->content;
	while (current)
	{
		token_data = (t_tkn_data *)current->content;
		while (token_data->type != META_PIPE)
		{
			token_data = (t_tkn_data *)current->content;
			while (is_redirection(token_data, 0))
				if (update_current_and_prev(&current, prev, &token_data))
					return (true);
			if (token_data->type != META_PIPE)
				*head = current;
			if (token_data->type != META_PIPE)
				return (false);
		}
		return (true);
	}
	return (true);
}

void	ft_organizer1(t_list **tokens)
{
	t_list	*prev;
	t_list	*head;

	ft_set_null(&prev, &head);
	if (ft_get_the_head(&head, tokens, &prev))
		return ;
	if (head)
	{
		prev->next = head->next;
		head->next = *tokens;
		*tokens = head;
	}
}
