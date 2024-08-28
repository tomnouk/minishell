/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:03:51 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 23:47:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_redir_in(t_list *file, int *redi_num, t_data *data)
{
	t_tkn_data	*tokendata;
	int			fd;

	tokendata = (t_tkn_data *)file->content;
	fd = open(tokendata->token, O_RDONLY);
	if (fd == -1)
	{
		open_files_errors_manager(fd, tokendata->token, errno);
		data->exit_code = -1;
		return ;
	}
	if ((*redi_num) - 1 == 0)
	{
		dup2(fd, 0);
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
