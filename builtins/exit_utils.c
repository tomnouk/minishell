/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:58:55 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/10 14:31:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_iswhite(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

void	numeric_arg_required(char *str, t_data *data)
{
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_exit_status = 255;
	free_all_exit(data);
	free_env_list(&data->mini_env);
	close(data->tmp_fd);
	close(data->tmp_fd2);
	data->buffer_heredoc = get_next_line(-1);
	exit(g_exit_status);
}

long long int	ft_atoll(char *str, int i, t_data *data)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	if (ft_strchr(str, '-'))
		sign = -1;
	while (ft_isdigit(str[i]))
	{
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
			numeric_arg_required(str, data);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	check_arg(char *str, int *begin, t_data *data)
{
	int	i;
	int	end;

	i = 0;
	while (ft_iswhite(str[i]))
		i++;
	if ((str[i] == '-' && ft_isdigit(str[i + 1])) || (str[i] == '+'
			&& ft_isdigit(str[i + 1])))
		i++;
	*begin = i;
	while (ft_isdigit(str[i]))
		i++;
	end = i;
	if (end - (*begin) > 19)
		numeric_arg_required(str, data);
	while (str[i])
	{
		if (!ft_iswhite(str[i]))
			numeric_arg_required(str, data);
		i++;
	}
}
