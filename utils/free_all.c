/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:15:35 by anomourn          #+#    #+#             */
/*   Updated: 2024/08/10 22:29:08 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_list(t_list *list)
{
	t_list		*tmp;
	t_tkn_data	*tkn_data;

	tmp = NULL;
	tkn_data = NULL;
	while (list)
	{
		tmp = list;
		tkn_data = (t_tkn_data *)tmp->content;
		list = list->next;
		if (tkn_data->token != NULL)
			free(tkn_data->token);
		if (tkn_data->cmd_exec_path)
			free(tkn_data->cmd_exec_path);
		free(tkn_data);
		free(tmp);
	}
}

void	free_env_list(t_list **env_list) // for get_env
{
	t_list	*tmp;
	t_list	*next;

	tmp = *env_list;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*env_list = NULL;
}

void	free_env(t_data *data)
{
	int	i;

	i = 0;
	if (data->env)
	{
		while (data->env[i] != NULL)
		{
			free(data->env[i]);
			i++;
		}
		free(data->env);
	}
}

void	free_all(t_data *data)
{
	if (data->tokens)
		free_list(data->tokens);
	if (data->pwd)
		free(data->pwd);
	if (data->args_p)
		free(data->args_p);
	free(data->pipe_fd);
	free(data->pids);
	free(data->wait_for);
	if (data->old_pwd)
		free(data->old_pwd);
	if (data->args)
		free(data->args);
	free_env(data);
	if (data->here_doc > 0 && g_exit_status == 130)
	{
		data->buffer_heredoc = get_next_line(-1);
		data->here_doc--;
	}
	if (data->process_num > 1)
	{
		close(data->tmp_fd);
		close(data->tmp_fd2);
	}
}

void	free_all_exit(t_data *data)
{
	if (data->tokens)
		free_list(data->tokens);
	if (data->pwd)
		free(data->pwd);
	if (data->args_p)
		free(data->args_p);
	if (data->old_pwd)
		free(data->old_pwd);
	if (data->args)
		free(data->args);
	free_env(data);
	if (data->here_doc > 0)
	{
		printf("here_doc: %d\n", data->here_doc);
		data->buffer_heredoc = get_next_line(-1);
		data->here_doc--;
	}
	if (data->process_num > 1)
	{
		close(data->tmp_fd);
		close(data->tmp_fd2);
	}
	free(data->pipe_fd);
	free(data->pids);
	free(data->wait_for);
}
