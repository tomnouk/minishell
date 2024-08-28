/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:58:33 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/09 15:29:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*get_env(t_data data, char **env)
{
	t_list	*env_list;
	int		i;

	data.mini_env = NULL;
	i = 0;
	if (!env)
		return (ft_printf("no env"), NULL);
	while (env[i])
	{
		env_list = ft_lstnew(ft_strdup(env[i]));
		if (!env_list)
			return (NULL);
		ft_lstadd_back(&data.mini_env, env_list);
		i++;
	}
	return (data.mini_env);
}

void	print_env(t_data data)
{
	t_list	*temp;

	temp = data.mini_env;
	while (temp)
	{
		if (ft_strchr((char *)temp->content, '='))
			ft_printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

void	solo_export(t_data data)
{
	t_list	*temp;
	char	*str;

	temp = data.mini_env;
	while (temp)
	{
		write(1, "declare -x ", 11);
		if (ft_strchr((char *)temp->content, '='))
		{
			str = (char *)temp->content;
			while (*(char *)str && *(char *)str != '=')
				write(1, (char *)str++, 1);
			write(1, (char *)str++, 1);
			write(1, "\"", 1);
			while (*(char *)str)
				write(1, (char *)str++, 1);
			write(1, "\"\n", 2);
		}
		else
			ft_printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	g_exit_status = 0;
}
