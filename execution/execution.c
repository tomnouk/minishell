/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:27:04 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 16:08:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_assign_args(t_list **args, t_list *tokens)
{
	t_list		*current;
	t_tkn_data	*tokendata;
	int			i;

	i = 0;
	current = tokens;
	tokendata = NULL;
	if (current == NULL)
		return ;
	args[i] = tokens;
	while (current != NULL)
	{
		tokendata = (t_tkn_data *)current->content;
		while (tokendata->type != META_PIPE && current != NULL)
		{
			current = current->next;
			if (current != NULL)
				tokendata = (t_tkn_data *)current->content;
		}
		if (tokendata->type == META_PIPE)
		{
			args[++i] = current->next;
			current = current->next;
		}
	}
}

static void	execute_child_process(t_list *tokens, t_list *env, t_data *data)
{
	signal(SIGINT, sigint_exec);
	signal(SIGQUIT, SIG_DFL);
	data->process_num++;
	ft_execute_routine(tokens, env, data);
	free_all(data);
	free_env_list(&env);
	close(data->tmp_fd);
	close(data->tmp_fd2);
	data->buffer_heredoc = get_next_line(-1);
	exit(g_exit_status);
}

static void	execute_parent(pid_t pid)
{
	signal(SIGINT, sigint_exec);
	signal(SIGQUIT, ft_sign_back_slash);
	waitpid(pid, &g_exit_status, 0);
	if (WIFSIGNALED(g_exit_status) && WTERMSIG(g_exit_status) == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		g_exit_status = 131;
	}
	if (g_exit_status == SIGINT)
		g_exit_status = 130;
	else
		g_exit_status = g_exit_status / 256;
}

static void	execute_signle_command_line(t_list *tokens, t_list *env,
		t_data *data, t_types type)
{
	pid_t	pid;

	pid = 0;
	if (type == COMMAND)
	{
		pid = fork();
		if (pid == 0)
			execute_child_process(tokens, env, data);
		else
			execute_parent(pid);
	}
	else
		ft_execute_routine(tokens, env, data);
}

void	ft_execution(t_list *tokens, t_list *env, t_data *data)
{
	t_tkn_data	*tokendata;

	if (data->exit_code == -1)
		return ;
	tokendata = (t_tkn_data *)data->tokens->content;
	if (data->process_num < 1)
		return ;
	signal(SIGINT, sigint_exec);
	if (data->process_num > 1)
	{
		memory_allocator((void **)&(data)->args_p, sizeof(t_list *)
			* (data->process_num + 1), data);
		ft_assign_args(data->args_p, tokens);
		create_pipes_and_execution(env, data);
	}
	else
		execute_signle_command_line(tokens, env, data, tokendata->type);
}
