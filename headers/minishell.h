/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:04 by aeid              #+#    #+#             */
/*   Updated: 2024/06/25 12:47:36 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
//# include "../Printft/ft_printf.h"
# include <readline/readline.h>
# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>

typedef struct s_data
{
	t_list	*mini_env;
	t_list	*tokens;
	int		list_size;
	int		current;
	int		start;
	char	*args; //need free
	char	**env;
} t_data;

extern t_data	g_data;

# include "lexer.h"
# include "builtins.h"
# include "expander.h"
//# include "parsing.h"


#endif