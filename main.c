/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:16:30 by aeid              #+#    #+#             */
/*   Updated: 2024/08/27 15:03:32 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

int		g_exit_status = 0;

void	ft_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data = initialize_data();
	data.mini_env = get_env(data, env);
	while (1)
	{
		ft_signals();
		prompt_loop(&data);
		ft_lexer(&data);
		ft_parsing(&data);
		ft_execution(data.tokens, data.mini_env, &data);
		rl_on_new_line();
		if (data.args)
			add_history(data.args);
		free_all(&data);
		reinitialize_data(&data);
	}
	close(data.tmp_fd2);
	close(data.tmp_fd);
	return (0);
}
