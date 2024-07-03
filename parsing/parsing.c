/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:57:47 by aeid              #+#    #+#             */
/*   Updated: 2024/07/03 17:09:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"



void ft_parsing(t_data *data, t_list *tokens)
{
	char **path;
	
	path = get_cmd_path(data->mini_env);
	expander(data->mini_env, tokens);
	define_builtins(tokens);
	define_commands(tokens, path);
	//free the path** here
}
