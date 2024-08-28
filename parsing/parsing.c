/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:57:47 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 01:08:42 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_get_process_num(t_list *tokens)
{
	t_list		*current;
	t_tkn_data	*tokendata;
	int			process_num;

	process_num = 0;
	current = tokens;
	while (current != NULL)
	{
		tokendata = (t_tkn_data *)current->content;
		if (tokendata->type == META_PIPE)
			process_num++;
		current = current->next;
	}
	return (process_num + 1);
}

static bool	head_checker(t_list *tokens)
{
	t_list		*current;
	t_tkn_data	*string;

	current = tokens;
	string = (t_tkn_data *)current->content;
	if (is_redirection(string, 0))
		return (true);
	return (false);
}

static void	check_here_doc(t_data *data)
{
	t_list		*current;
	t_tkn_data	*tokendata;

	current = data->tokens;
	while (current != NULL)
	{
		tokendata = (t_tkn_data *)current->content;
		if (tokendata->type == META_HEREDOC)
			data->here_doc++;
		current = current->next;
	}
}

void	ft_parsing(t_data *data)
{
	char	**path;

	if (data->exit_code == -1)
		return ;
	path = get_cmd_path(data->mini_env, data);
	data->list_size = ft_lstsize(data->tokens);
	expander(data->tokens, data);
	ft_parser(data->tokens, data);
	if (data->exit_code == -1)
		return ;
	if (head_checker(data->tokens))
		ft_organizer1(&data->tokens);
	ft_organizer(data->tokens);
	define_commands(data->tokens, path);
	data->process_num = ft_get_process_num(data->tokens);
	memory_allocator((void **)&data->pipe_fd, sizeof(int) * (data->process_num
			- 1) * 2, data);
	memory_allocator((void **)&data->pids, sizeof(pid_t) * data->process_num,
		data);
	memory_allocator((void **)&data->wait_for, sizeof(bool) * data->process_num,
		data);
	define_builtins(data->tokens);
	check_here_doc(data);
	if (path)
		free_mtx(path);
}
