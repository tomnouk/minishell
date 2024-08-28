/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:25:53 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 00:53:53 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_data	initialize_data(void)
{
	t_data	data;

	data.mini_env = NULL;
	data.tokens = NULL;
	data.buffer_heredoc = NULL;
	data.list_size = 0;
	data.exp_var = 0;
	data.here_doc = 0;
	data.process_num = 0;
	data.current = 0;
	data.start = 0;
	data.quote_flag = 0;
	data.args_p = NULL;
	data.pipe_fd = NULL;
	data.pids = NULL;
	data.wait_for = NULL;
	data.exit_code = 0;
	data.pwd = NULL;
	data.old_pwd = NULL;
	data.args = NULL;
	data.env = NULL;
	data.tmp_fd = dup(0);
	data.tmp_fd2 = dup(1);
	return (data);
}

int	check_if_empty(char *args)
{
	size_t	i;

	i = 0;
	if (!args || !args[0])
		return (0);
	while (!ft_isprint(args[i]) && args[i] != '\0')
		i++;
	if (args[i] == '\0')
		return (0);
	return (1);
}

void	prompt_loop(t_data *data)
{
	while (1)
	{
		(*data).args = readline("minishell $ ");
		if ((*data).args == NULL)
			ft_sig_term(data);
		if (!check_if_empty((*data).args))
		{
			free((*data).args);
			(*data).args = NULL;
		}
		else
			break ;
	}
}

static void	reset_data_flags(t_data *data)
{
	data->process_num = 0;
	data->here_doc = 0;
	data->quote_flag = 0;
	data->exp_var = 0;
	data->start = 0;
	data->list_size = 0;
	data->args_p = NULL;
	data->pipe_fd = NULL;
	data->pids = NULL;
	data->wait_for = NULL;
}

void	reinitialize_data(t_data *data)
{
	data->exit_code = 0;
	data->old_pwd = NULL;
	data->current = 0;
	if (data->process_num > 1)
	{
		close(data->tmp_fd);
		close(data->tmp_fd2);
		data->tmp_fd = dup(0);
		data->tmp_fd2 = dup(1);
	}
	else
	{
		dup2(data->tmp_fd, 0);
		dup2(data->tmp_fd2, 1);
	}
	reset_data_flags(data);
	data->buffer_heredoc = NULL;
	data->tokens = NULL;
	data->args = NULL;
	data->env = NULL;
	data->pwd = NULL;
}
