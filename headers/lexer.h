/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:21 by aeid              #+#    #+#             */
/*   Updated: 2024/06/20 16:55:04 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum s_types
{
	SPECIAL_SQUOTE, //in parsing check for escape chars
	SPECIAL_DQUOTE, //in parsing check for escape chars
	META_DOL, // check for $ | > < >> <<
	META_PIPE,
	META_REDIR_IN, // <
	META_REDIR_OUT, // >
	META_APPEND, // >>
	META_HEREDOC, // <<
	WORD,
	WORD_WITH_SQUOTE_INSIDE, //dont check for $
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
void dollar_meta(t_data *data, t_list *node, t_tkn_data *token);
void pipe_meta(t_data *data, t_list *node, t_tkn_data *token);
void redirect_meta(t_data *data, t_list *node, t_tkn_data *token);

#endif