/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:35:22 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/27 14:48:09 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_exit_list_size(t_list *current, int *again)
{
	int		list_size;
	t_list	*temp;

	list_size = 0;
	temp = current;
	while (temp && till(((t_tkn_data *)(temp->content))->type))
	{
		if (((t_tkn_data *)(temp->content))->token)
			list_size++;
		temp = temp->next;
	}
	if (list_size > 1)
	{
		if (*again == 0)
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_exit_status = 1;
			(*again)++;
		}
	}
	return (list_size);
}

void	free_exit(t_data *data)
{
	free_all_exit(data);
	free_env_list(&data->mini_env);
	data->buffer_heredoc = get_next_line(-1);
	close(data->tmp_fd);
	close(data->tmp_fd2);
	exit(g_exit_status);
}

t_list	*control_first_arg(t_list *args, int *begin, t_data *data)
{
	t_list	*current;

	current = args;
	while (current && !(((t_tkn_data *)(current->content))->token))
		current = current->next;
	if (!current || !till(((t_tkn_data *)(current->content))->type))
	{
		ft_putstr_fd("exit\n", 1);
		g_exit_status = 0;
		free_exit(data);
	}
	else
		check_arg(((t_tkn_data *)(current->content))->token,
			begin, data);
	return (current);
}

void	ft_exit(t_list *args, t_data *data)
{
	long long int	exit_;
	int				begin;
	int				printed;

	printed = 0;
	exit_ = 0;
	args = control_first_arg(args->next, &begin, data);
	if (count_exit_list_size(args, &printed) == 1)
	{
		check_arg(((t_tkn_data *)(args->content))->token, &begin, data);
		exit_ = ft_atoll(((t_tkn_data *)(args->content))->token, begin, data);
	}
	else if (count_exit_list_size(args, &printed) == 0)
	{
		g_exit_status = 0;
		free_exit(data);
	}
	else
		return ;
	g_exit_status = exit_ % 256;
	ft_putstr_fd("exit\n", 1);
	free_exit(data);
}
