/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:25:02 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 14:48:51 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	wait_for_processes(int *pipe_fd, t_data *data, bool *wait_for,
		pid_t *pids)
{
	int	i;

	i = -1;
	close_pipes(pipe_fd, data->process_num);
	while (++i < data->process_num)
	{
		if (wait_for[i])
		{
			signal(SIGINT, sigint_exec);
			signal(SIGQUIT, ft_sign_back_slash);
			waitpid(pids[i], &g_exit_status, 0);
			if ((i == data->process_num - 1) && WIFSIGNALED(g_exit_status)
				&& WTERMSIG(g_exit_status) == SIGQUIT)
			{
				write(1, "Quit (core dumped)\n", 19);
				g_exit_status = 131;
			}
			if (g_exit_status == SIGINT)
				g_exit_status = 130;
			else
				g_exit_status = g_exit_status / 256;
		}
	}
}

static void	assign_fds_pipes(int i, t_data *data)
{
	signal(SIGINT, sigint_exec);
	signal(SIGQUIT, SIG_DFL);
	if (i == 0)
	{
		close(data->pipe_fd[0]);
		dup2(data->pipe_fd[1], 1);
	}
	else if (i == data->process_num - 1)
	{
		close(data->pipe_fd[(i - 1) * 2 + 1]);
		dup2(data->pipe_fd[(i - 1) * 2], 0);
	}
	else
	{
		close(data->pipe_fd[(i - 1) * 2 + 1]);
		dup2(data->pipe_fd[(i - 1) * 2], 0);
		close(data->pipe_fd[i * 2]);
		dup2(data->pipe_fd[i * 2 + 1], 1);
	}
	close_pipes(data->pipe_fd, data->process_num);
}

static void	cleanup_and_exit(t_data *data, t_list **env, int g_exit_status)
{
	free_all(data);
	free_env_list(env);
	close(data->tmp_fd);
	close(data->tmp_fd2);
	exit(g_exit_status);
}

static void	handle_here_doc(int i, pid_t pid, int *g_exit_status,
		bool wait_for[])
{
	waitpid(pid, g_exit_status, 0);
	*g_exit_status = *g_exit_status / 256;
	wait_for[i] = false;
}

void	create_pipes_and_execution(t_list *env, t_data *data)
{
	int		i;
	pid_t	pid;

	pid = 0;
	assigning_pipes(data, &i);
	while (++i < data->process_num)
	{
		pid = fork();
		if (pid == 0)
		{
			assign_fds_pipes(i, data);
			ft_execute_routine(data->args_p[i], env, data);
			cleanup_and_exit(data, &env, g_exit_status);
		}
		data->pids[i] = pid;
		if (ft_check_here_doc(data->args_p[i]))
			handle_here_doc(i, pid, &g_exit_status, data->wait_for);
	}
	wait_for_processes(data->pipe_fd, data, data->wait_for, data->pids);
}
