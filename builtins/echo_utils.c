/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:09:50 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/27 16:07:56 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	skip_null_tokens(t_list **cur_token)
{
	*cur_token = (*cur_token)->next;
	while (*cur_token && !((t_tkn_data *)((*cur_token)->content))->token)
		*cur_token = (*cur_token)->next;
}

void	check_nl(bool nl)
{
	if (nl)
		write(STDOUT_FILENO, "\n", 1);
}

char	*get_next_token_path(t_list *tokens, t_list **temp, bool *flag)
{
	t_tkn_data	*token_data;
	char		*path;

	if (tokens->next)
	{
		*temp = tokens->next;
		token_data = (t_tkn_data *)(*temp)->content;
		*flag = false;
		path = token_data->token;
		return (path);
	}
	return (NULL);
}
