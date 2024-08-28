/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:16:59 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/08/10 14:32:22 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	sigint_exec(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 130;
	}
}

void	ft_heredoc_handler(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	ft_sign_back_slash(int sig)
{
	(void)sig;
	g_exit_status = 131;
}

void	ft_sig_term(t_data *data)
{
	close(data->tmp_fd2);
	close(data->tmp_fd);
	data->buffer_heredoc = get_next_line(-1);
	write(STDOUT_FILENO, "exit\n", 5);
	free_all_exit(data);
	free_env_list(&data->mini_env);
	exit(0);
}
