/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:45:34 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 11:45:41 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct word
{
    char *type;
    char *value;
    struct word *next;
} t_word;

typedef struct env_var
{
    char *name;
    char *value;
    struct env_var *next;
} t_env_var;

char    **split_string(const char *s);
char    *copy_string_mod(char *dest, const char *src, size_t n);
char    *copy_string(char *dest, const char *src, size_t n);
void copy_env_var(const char *s, char *dest ,t_env_var *env, size_t *j);
char    *copy_string_var(char *dest, const char *src, size_t n, t_env_var *env);
char    **free_string(char	**dest, size_t j);
int search_env_var(const char *s, t_env_var *env);
int count_env_var(const char *s, int j, t_env_var *env);


void    first_command(char **s, char *prompt, t_env_var **env);

void    clean_string(char **s);
void    clean_list(t_word **word_list);

void    assign_type(char *s, t_word *new, t_word *prev);
void    assign_value(char *s, t_word *new);
t_word  *create_node(char *s, t_word *prev);
t_word  *create_list(char **s, t_word **word_list);

void    analyze_command(t_word *word_list, char *prompt, t_env_var **env);

void    echo_command(t_word *word_list);

void    cd_command(t_word *word_list, char *prompt);

void    pwd_command(t_word *word_list);

void    export_command(t_word *word_list, t_env_var **env);

void    unset_command(t_word *word_list, t_env_var **env);

void    env_command(t_env_var **env);

#endif
