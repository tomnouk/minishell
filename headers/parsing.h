/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:53:21 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 22:45:26 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

void	ft_parsing(t_data *data);
void	define_builtins(t_list *tokens);
void	expander(t_list *tokens, t_data *data);
char	**get_cmd_path(t_list *mini_env, t_data *data);
void	define_commands(t_list *tokens, char **path);
void	ft_parser(t_list *tokens, t_data *data);
int		ft_get_process_num(t_list *tokens);
void	ft_organizer(t_list *tokens);
void	ft_organizer1(t_list **tokens);
void	meta_dol_expander_manager(int variable_len, char **tkn_str,
			t_data *data, t_types type);
void	dquote_expander(t_list *env, int vlen, char **str, t_data *data);
void	process_remaining_characters(char **tkn_str, int *i, int *start,
			char **new);
void	initialize_dquote_expander(int *i, int *start, char **new,
			char **variable);
void	process_variable(char **tkn_str, int *i, int *variable_len);
void	ft_ptsd(char *s, int fd);

#endif