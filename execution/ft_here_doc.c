/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:39:17 by aeid              #+#    #+#             */
/*   Updated: 2024/08/10 22:29:35 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	cleanup_heredoc(int tp_fd, int *fd, t_data *data, int *redi_num)
{
	int	p_errno;

	dup2(tp_fd, 0);
	close(*fd);
	p_errno = 0;
	if (data->buffer_heredoc)
		free(data->buffer_heredoc);
	get_next_line(-1);
	if ((*redi_num) - 1 == 0)
	{
		*fd = open(".heredoc", O_RDONLY);
		if (*fd == -1)
		{
			p_errno = errno;
			unlink(".heredoc");
			ft_dup2_error_manager(*fd, p_errno);
		}
		dup2(*fd, 0);
		close(*fd);
	}
	(*redi_num)--;
	unlink(".heredoc");
	close(tp_fd);
}

static bool	handle_exit_status(t_data *data, t_list *env, int tp_fd, int fd)
{
	if (g_exit_status == 130)
	{
		unlink(".heredoc");
		close(tp_fd);
		close(fd);
		free(data->buffer_heredoc);
		data->buffer_heredoc = get_next_line(-1);
		if (data->process_num > 1)
		{
			free_all(data);
			free_env_list(&env);
			exit(g_exit_status);
		}
		return (true);
	}
	return (false);
}

static bool	process_heredoc_line(t_tkn_data *tokendata, t_data *data, int fd,
		t_list *env)
{
	size_t	size_buff;
	size_t	size_token;

	size_token = ft_strlen(tokendata->token);
	size_buff = ft_strlen(data->buffer_heredoc) - 1;
	if (!data->buffer_heredoc)
	{
		write(2, WR, sizeof(WR) - 1);
		return (true);
	}
	if (size_buff > size_token)
	{
		if (ft_strncmp(tokendata->token, data->buffer_heredoc, size_buff) == 0)
			return (true);
	}
	else
	{
		if (ft_strncmp(tokendata->token, data->buffer_heredoc, size_token) == 0)
			return (true);
	}
	if (check_type(tokendata, 1))
		write(fd, data->buffer_heredoc, ft_strlen(data->buffer_heredoc));
	else
		check_expansion(data->buffer_heredoc, fd, env, data);
	return (false);
}

void	ft_heredoc(t_list *file, t_list *env, t_data *data, int *redi_num)
{
	t_tkn_data	*tokendata;
	int			fd;
	int			tp_fd;

	tp_fd = dup(0);
	tokendata = (t_tkn_data *)file->content;
	fd = open(".heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	signal(SIGINT, ft_heredoc_handler);
	signal(SIGQUIT, slash);
	g_exit_status = 0;
	while (1)
	{
		dup2(data->tmp_fd, 0);
		write(0, "> ", 2);
		data->buffer_heredoc = get_next_line(0);
		if (handle_exit_status(data, env, tp_fd, fd))
			return ;
		if (process_heredoc_line(tokendata, data, fd, env))
			break ;
		free(data->buffer_heredoc);
	}
	cleanup_heredoc(tp_fd, &fd, data, redi_num);
}
