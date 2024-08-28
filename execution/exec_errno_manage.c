/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_errno_manage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:03:03 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 19:39:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	open_files_errors_manager(int fd, char *file_name, int errnum)
{
	if (fd < 0)
	{
		if (errnum == ENOENT)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(file_name, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		else if (errnum == EACCES)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(file_name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
		}
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(file_name, 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
		}
		g_exit_status = 1;
	}
}

void	ft_dup2_error_manager(int fd, int errnum)
{
	if (fd < 0)
	{
		if (errnum == EBADF)
			ft_putstr_fd("minishell: Bad file descriptor\n", 2);
		else if (errnum == EINTR)
			ft_putstr_fd("minishell: Interrupted system call\n", 2);
		else if (errnum == EINVAL)
			ft_putstr_fd("minishell: Invalid argument\n", 2);
		else if (errnum == EMFILE)
			ft_putstr_fd("minishell: Too many open files\n", 2);
		else if (errnum == ENFILE)
			ft_putstr_fd("minishell: File table overflow\n", 2);
		else if (errnum == ENOMEM)
			ft_putstr_fd("minishell: Out of memory\n", 2);
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
		}
		close(fd);
		g_exit_status = 1;
	}
}
