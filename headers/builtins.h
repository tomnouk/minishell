/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:27:02 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/03 12:14:01 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void    print_env(t_data data);
//char	*get_env_value(char *key);
void    solo_export(t_data data);
t_list  *get_env(t_data data, char **env);
void	set_env(char *name, char *path, t_list *mini_env);
char 	*search_env(t_list *mini_env, char *variable);
char 	*find_path(char *curr_content, char *variable);
void	ft_cd(t_list *tokens, t_list *mini_env);
void    check_left_side_export(char *str, int *left_side_type);
void    ft_export(t_data data, t_list *cur_token); //I will analize the next token and if OK put it in

#endif
