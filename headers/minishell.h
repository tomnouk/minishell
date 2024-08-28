/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:04 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 01:06:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "../Libft/libft.h"
# include "../Printft/ft_printf.h"
# include "builtins.h"
# include "execution.h"
# include "get_next_line.h"
# include "parsing.h"
# include "utils.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define PATH_MAX 4096

extern int	g_exit_status;

void		ft_exit(t_list *args, t_data *data);
void		free_exit(t_data *data);
void		printTokens(t_list *tokens);
void		ft_signals(void);
void		ft_sig_term(t_data *data);
int			ft_pwd(t_data *data);
int			ft_cd(t_list *tokens, t_data *data, t_list *mini_env);
void		ft_heredoc_handler(int sig);
void		free_env_list(t_list **env_list);
void		sigint_exec(int sig);
void		free_env_list(t_list **env_list);
void		ft_sign_back_slash(int sig);
void		sigint_handler(int sig);
char		*find_path(char *curr_content, char *variable);
void		create_pipes(t_data *data, int process_num);
void		close_pipes(int pipe_fd[], int process_num);
bool		ft_check_here_doc(t_list *list);
void		assigning_pipes(t_data *data, int *i);

#endif