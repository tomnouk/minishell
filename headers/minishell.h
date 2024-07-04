/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:04 by aeid              #+#    #+#             */
/*   Updated: 2024/07/04 14:40:42 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include "../Libft/libft.h"
# include "../Printft/ft_printf.h"
# include <readline/readline.h>
#include <readline/history.h>
# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <termios.h>
//#include <linux/limits.h>


typedef struct	s_data
{
	t_list	*mini_env;
	t_list	*tokens;
	int		list_size;
	int		current;
	int		start;
	int		exit_code;
	char	*args; //needs to be freed, result of readline//
	char	**env;
}	t_data;

extern t_data	g_data;
extern int		g_exit_code;

void	printTokens(t_list *tokens);
void	ft_signals(void);

# include "lexer.h"
# include "builtins.h"
# include "parsing.h"

#endif