/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:27:22 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 00:45:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
// # define MAX_PROCESS_NUM 100
# define WR "minishell: wrning: here-doc at line 5 delimited by end-o-file\n"

void	ft_execution(t_list *tokens, t_list *env, t_data *data);
void	ft_execute_routine(t_list *tokens, t_list *env, t_data *data);
void	open_files_errors_manager(int fd, char *file_name, int errnum);
void	ft_dup2_error_manager(int fd, int errnum);
void	ft_heredoc(t_list *file, t_list *env, t_data *data, int *redi_num);
void	ft_redir_in(t_list *file, int *redi_num, t_data *data);
void	ft_redir_append(t_list *file, int *redi_num, t_data *data);
void	ft_command_execution(t_list *tokens, t_list *env, t_list *current,
			t_data *data);
void	ft_redir_out(t_list *file, int *redi_num, t_data *data);
void	create_pipes_and_execution(t_list *env, t_data *data);
void	close_pipes(int pipe_fd[], int process_num);
int		ft_get_number_of_redir_in_or_out(t_list *tokens, t_types type1,
			t_types type2);
int		ft_get_number_of_redirections(t_list *tokens);
bool	is_redirection(t_tkn_data *tokendata, int flag);
bool	check_type(t_tkn_data *tokendata, int flag);
void	slash(int sig);
char	*find_env_var(char *buffer, int i, t_list *env);
void	check_expansion(char *buffer, int fd, t_list *env, t_data *data);
void	write_and_free(int fd, char *expand_value, char *var_env);
void	free_all_exit(t_data *data);

#endif