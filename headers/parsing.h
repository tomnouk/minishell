/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:53:21 by aeid              #+#    #+#             */
/*   Updated: 2024/07/02 23:06:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "../headers/minishell.h"

void ft_parsing(t_data *data, t_list *tokens);
void define_builtins(t_list *tokens);
void expander(t_list *mini_env, t_list *tokens);

#endif