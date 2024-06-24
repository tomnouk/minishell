/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:04 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 22:38:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
//# include "../Printft/ft_printf.h"
# include <readline/readline.h>
# include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	t_list *mini_env;
	t_list *tokens;
	int list_size;
	int current;
	int start;
	char *args; //needs to be freed, result of readline//
} t_data;

# include "lexer.h"
# include "builtins.h"
# include "expander.h"
//# include "parsing.h"

#endif