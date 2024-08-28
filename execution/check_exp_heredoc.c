/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exp_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:40:30 by aeid              #+#    #+#             */
/*   Updated: 2024/08/09 17:59:34 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	assigning_variables(int *i, char **var_env, t_list **tmp,
		t_list *env)
{
	*i = -1;
	*var_env = NULL;
	*tmp = env;
}

static int	get_var_len(char *buffer)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (buffer[i] && buffer[i] != '$')
	{
		if (buffer[i] == '\n')
			return (counter);
		i++;
		counter++;
	}
	return (counter);
}

static int	handle_non_expansion(char *buffer, int i, int fd)
{
	if (!buffer || buffer[i] == '\0' || buffer[i] == '\n')
	{
		write(fd, "\n", 1);
		return (1);
	}
	else if (buffer[i] != '$')
		write(fd, &buffer[i], 1);
	return (0);
}

static void	handle_no_var_found(int *i, char *buffer, int fd)
{
	*i = get_var_len(buffer);
	write(fd, " ", 1);
}

void	check_expansion(char *buffer, int fd, t_list *env, t_data *data)
{
	int		i;
	char	*var_env;
	char	*expand_value;
	t_list	*tmp;

	assigning_variables(&i, &var_env, &tmp, env);
	expand_value = NULL;
	while (buffer[++i])
	{
		if (buffer[i] == '$')
		{
			var_env = find_env_var(buffer, i, env);
			if (var_env)
			{
				expand_value = search_env(env, var_env, data);
				i += ft_strlen(var_env);
				write_and_free(fd, expand_value, var_env);
			}
			else
				handle_no_var_found(&i, buffer, fd);
		}
		else if (handle_non_expansion(buffer, i, fd))
			return ;
	}
}
