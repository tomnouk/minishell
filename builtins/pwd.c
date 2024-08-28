/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:27:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/08/09 23:14:32 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/* Displays the current working directory */
int	ft_pwd(t_data *data)
{
	char	*str;

	str = malloc(sizeof(char) * PATH_MAX);
	if (str == NULL)
		return (1);
	if (getcwd(str, PATH_MAX) != NULL)
	{
		free(data->pwd);
		data->pwd = ft_strdup(str);
		printf("%s\n", data->pwd);
	}
	else
	{
		free(str);
		g_exit_status = 2;
		return (2);
	}
	free(str);
	g_exit_status = 0;
	return (0);
}
