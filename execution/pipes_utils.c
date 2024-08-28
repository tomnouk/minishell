/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:06:11 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 01:00:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	create_pipes(t_data *data, int process_num)
{
	int	i;

	i = 0;
	while (i < process_num - 1)
	{
		if (pipe(data->pipe_fd + i * 2) == -1)
			return ;
		i++;
	}
}

void	close_pipes(int pipe_fd[], int process_num)
{
	int	i;

	i = -1;
	while (++i < 2 * (process_num - 1))
	{
		close(pipe_fd[i]);
	}
}

bool	ft_check_here_doc(t_list *list)
{
	t_list		*current;
	t_tkn_data	*tokendata;

	current = list;
	tokendata = (t_tkn_data *)current->content;
	while (current != NULL && tokendata->type != META_PIPE)
	{
		if (tokendata->type == META_HEREDOC)
			return (true);
		current = current->next;
		if (current != NULL)
			tokendata = (t_tkn_data *)current->content;
	}
	return (false);
}

void	assigning_pipes(t_data *data, int *i)
{
	*i = -1;
	while (++(*i) < data->process_num)
		data->wait_for[*i] = true;
	create_pipes(data, data->process_num);
	*i = -1;
}
