/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:15:14 by aeid              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/24 14:25:56 by anomourn         ###   ########.fr       */
=======
/*   Updated: 2024/06/24 20:17:22 by aeid             ###   ########.fr       */
>>>>>>> 249c45c6885c50737d50075fa90fcc6e5ce3bc92
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h" 

static void meta_token_handler(t_data *data, t_list *node, t_tkn_data *token)
{
	if (data->args[data->current] == '$')
		dollar_meta(data, node, token);
		
	else if (data->args[data->current] == '|')
		pipe_meta(data, node, token);
	else if (data->args[data->current] == '>' || data->args[data->current] == '<')
		redirect_meta(data, node, token);
}

void ft_meta_token(t_data *data, t_types type)
{
	t_list *node;
	t_tkn_data *token;

	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	token->type = type;
	token->variable_len = 0;
	meta_token_handler(data, node, token);
	//(data->current)--;
}

