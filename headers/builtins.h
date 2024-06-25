/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:27:02 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/25 15:47:53 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

t_list  *get_env(t_data data, char **env);
void    print_env(t_data data);
char	*get_env_value(char *key);
void	set_env(char *name, char *value, char **env);
void	ft_cd(t_list *tokens, char **env);
void    check_env_arg(char *str, int *left_side_type);
void    ft_export(t_data data, t_list *cur_token); //I will analize the next token and if OK put it in

#endif
