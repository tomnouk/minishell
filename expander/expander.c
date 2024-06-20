/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:20 by aeid              #+#    #+#             */
/*   Updated: 2024/06/20 22:31:19 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void expander(t_list *mini_env, t_list *tokens, char *tkn_str, t_types tkn_type)
{
	int i;

	i = 0;
	if (tkn_type == META_DOL || tkn_type == SPECIAL_DQUOTE || tkn_type == WORD_WITH_DQUOTE_INSIDE)
	{
		//try (ec$|ho) (ec" $ ho") (echo hello > $ file.txt)
		if (tkn_str[i + 1] == '\0' || tkn_str[i + 1] == ' ')
			return ;
		i++;
		while (tkn_str[i])
	}
	return ;
}
