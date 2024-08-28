/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:06:16 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 23:49:22 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_redir_append(t_list *file, int *redi_num, t_data *data)
{
	t_tkn_data	*tokendata;
	int			fd;

	tokendata = (t_tkn_data *)file->content;
	fd = open(tokendata->token, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		open_files_errors_manager(fd, tokendata->token, errno);
		data->exit_code = -1;
		return ;
	}
	if ((*redi_num) - 1 == 0)
	{
		dup2(fd, 1);
		if (fd == -1)
		{
			ft_dup2_error_manager(fd, errno);
			data->exit_code = -1;
			return ;
		}
	}
	(*redi_num)--;
	close(fd);
}
