/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:21 by aeid              #+#    #+#             */
/*   Updated: 2024/06/12 18:06:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum s_types
{
	SPECIAL_S,
	SPECIAL_D,
	META,
	WORD,
	WORD_D,
} t_types;

typedef struct s_tkn_data
{
	char *token;
	t_types type;
} t_tkn_data;

void ft_tokenizing(t_data *data);
void memory_allocator(void **ptr, size_t size);
void ft_meta_token(t_data *data, t_types type);
int ft_isquote(int c);
int ft_ismeta(int c);
void ft_special_token(t_data *data, t_types type);
void ft_word_token(t_data *data, t_types type);

#endif