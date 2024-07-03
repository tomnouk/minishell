/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:20:10 by aeid              #+#    #+#             */
/*   Updated: 2024/07/03 20:28:52 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"




void ft_parser(t_data *data, t_list *tokens)
{
	t_list *current;
	t_tkn_data *string;

	current = tokens;
	string = NULL;
	while (current)
	{
		string = (t_tkn_data *)current->content;
		
		current = current->next;
	}
}
