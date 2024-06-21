/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:21 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 17:22:37 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum s_types
{
	SPECIAL_SQUOTE, //in parsing check for escape chars. [0]
	SPECIAL_DQUOTE, //in parsing check for escape chars   [1]
	META_DOL, // check for $ | > < >> <<					[2]	
	META_PIPE,		// |									[3]
	META_REDIR_IN, // <										[4]
	META_REDIR_OUT, // >									[5]
	META_APPEND, // >>										[6]
	META_HEREDOC, // <<										[7]
	WORD,												// [8]
	WORD_WITH_DQUOTE_INSIDE, //check for $ 					[9]
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