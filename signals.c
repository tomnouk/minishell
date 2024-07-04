/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:16:59 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/07/04 14:41:29 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/minishell.h"

/**
	* Gets or sets the value of a static boolean variable by providing a set
	* flag and value to assign to the variable, primarily used to manage a
	* persistent boolean state across function calls
	*/
bool	get_hd_bool(bool set, bool value)
{
	static bool	hd_bool = false;

	if (set)
		hd_bool = value;
	return (hd_bool);
}

/** Signal handler for the SIGINT signal (ctrl+c) */
void	sigint_handler(int sig)
{
	(void)sig;
	g_exit_code = 130;
	if (get_hd_bool(false, true))
		return ;
	rl_on_new_line();
	rl_replace_line("", 0);
	write(STDOUT_FILENO, "\n", 1);
	rl_redisplay();
}

/** Signal handler for the SIGQUIT signal (ctrl+/) */
static void	sigquit_handler(int sig)
{
	struct termios	sa;

	(void)sig;
	tcgetattr(STDIN_FILENO, &sa);
	sa.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &sa);
}

/** Signal handler for the SIGINT signal inside a heredoc (ctrl+c) */
void	ft_heredoc_handler(int sig)
{
	(void)sig;
	printf("\n");
	g_exit_code = 130;
	exit(g_exit_code);
}

/** Uses signal function associate to handlers */
void	ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}