/* ************************************************************************** */
/*						                                                      */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:27:02 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/27 17:58:13 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void			print_env(t_data data);
void			solo_export(t_data data);
t_list			*get_env(t_data data, char **env);
void			set_env(char *name, char *path, t_list *mini_env, t_data *data);
char			*search_env(t_list *mini_env, char *variable, t_data *data);
char			*find_path(char *curr_content, char *variable);
void			check_left_side_export(char *str, int *left_side_type);
t_list			*ft_export(t_data data, t_list *cur_token);
size_t			biggest_strlen(char *str1, char *str2);
size_t			most_right_eq(char *str1, char *str2);

//export UTILS
void			add_toenv_skip_plus(t_data data, char *str);
char			*strjoin_free(char *s1, char *s2, int frees);
size_t			idx_of_eq_or_plus(char *str_plus, char *str_eq);

//FREE and GARBAGE
void			free_mtx(char **path);
void			free_null(void *ptr);

//exit utils
void			exit_numeric_argument_required(char *token);
long long int	ft_atoll(char *str, int i, t_data *data);
void			check_arg(char *str, int *begin, t_data *data);
int				ft_iswhite(char c);

void			execute_command(t_list *tokens, t_data *data);
void			ft_unset(t_data data, t_list *cur_token);
void			error_export_unset(char flag, char *str);

void			ft_echo(t_list *cur_token);
void			skip_null_tokens(t_list **cur_token);
void			check_nl(bool nl);
bool			till(int type);
char			*get_next_token_path(t_list *tokens, t_list **temp, bool *flag);
#endif
