/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:03:56 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 17:59:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*get_buff_var(char *buffer, int i)
{
	int	j;

	j = 0;
	if (buffer[i] == '$')
		i++;
	while (buffer[i + j] && buffer[i + j] != ' ' && buffer[i + j] != '\n'
		&& buffer[i + j] != '$')
		j++;
	return (ft_substr(buffer, i, j));
}

static char	*get_env_vars(char *env_line)
{
	int	i;

	i = -1;
	while (env_line[++i] != '=' && env_line[i])
		;
	if (!env_line[i] || !env_line)
		return (NULL);
	return (ft_substr(env_line, 0, i));
}

char	*find_env_var(char *buffer, int i, t_list *env)
{
	char	*var_env;
	t_list	*tmp;
	char	*var;

	tmp = env;
	var = get_buff_var(buffer, i);
	while (tmp)
	{
		var_env = get_env_vars((char *)tmp->content);
		if (ft_strncmp(var_env, var, ft_strlen(var)) == 0)
		{
			free(var);
			return (var_env);
		}
		free(var_env);
		var_env = NULL;
		tmp = tmp->next;
	}
	return (NULL);
}

void	slash(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", 2);
}

void	write_and_free(int fd, char *expand_value, char *var_env)
{
	write(fd, expand_value, ft_strlen(expand_value));
	free(var_env);
	free(expand_value);
}
