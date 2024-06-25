/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:27:02 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/24 20:10:17 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

t_list  *get_env(t_data data, char **env);
void    print_env(t_data data);

void    check_env_arg(char *str, int *left_side_type);
void    ft_export(t_data data, t_list *cur_token); //I will analize the next token and if OK put it in

#endif
