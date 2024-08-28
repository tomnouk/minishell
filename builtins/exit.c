/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:35:38 by anomourn          #+#    #+#             */
/*   Updated: 2024/08/09 19:41:21 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_list_size(t_list *current)
{
	int		list_size;
	t_list	*temp;

	list_size = 0;
	temp = current;
	while (temp != NULL)
	{
		list_size++;
		temp = temp->next;
	}
	return (list_size);
}

void	check_too_many_arguments(int list_size)
{
	if (list_size > 2)
	{
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		g_exit_status = 1;
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
}

void	check_numeric_argument(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(token, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		i++;
	}
}

void	ft_exit_handler(t_list *current)
{
	t_list		*next;
	t_tkn_data	*next_string;
	int			list_size;

	list_size = count_list_size(current);
	if (current->next != NULL)
	{
		next = current->next;
		next_string = (t_tkn_data *)next->content;
		check_numeric_argument(next_string->token);
		check_too_many_arguments(list_size);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	return ;
}

void	ft_exit(t_list *args)
{
	t_tkn_data	*arg_data;

	ft_exit_handler(args);
	if (args->next != NULL)
	{
		arg_data = (t_tkn_data *)args->next->content;
		g_exit_status = ft_atoi(arg_data->token) % 256;
	}
}
