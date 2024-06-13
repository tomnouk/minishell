/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    assign_type(char *s, t_word *new, t_word *prev)
{
    /*if (ft_strcmp(s, "echo") == 0 || ft_strcmp(s, "cd") == 0 || ft_strcmp(s, "pwd") == 0 || ft_strcmp(s, "export") == 0 || //
    ft_strcmp(s, "unset") == 0 || ft_strcmp(s, "env") == 0 || ft_strcmp(s, "exit") == 0)
        new->type = "command";*/
    if (ft_strcmp(s, ">") == 0 || ft_strcmp(s, ">>") == 0 || ft_strcmp(s, "<") == 0 || ft_strcmp(s, "<<") == 0)
        new->type = "operator";
    else if (prev != NULL && (ft_strcmp(prev->type, "operator") == 0))
    {
        new->type = "file";
    }
    else
    {
        new->type = "argument";
    }
    return;
}

void    assign_value(char *s, t_word *new)
{
    new->value = ft_strdup(s);
    return;
}

t_word  *create_node(char *s, t_word *prev)
{
    t_word *new;

    new = (t_word *)malloc(sizeof(t_word));
    if (new == NULL)
        return(NULL);
    assign_type(s, new, prev);
    assign_value(s, new);
    new->next = NULL;
    return(new);
}

t_word  *create_node_first(char *s)
{
    t_word *new;

    new = (t_word *)malloc(sizeof(t_word));
    if (new == NULL)
        return(NULL);
    if (ft_strcmp(s, "echo") == 0 || ft_strcmp(s, "cd") == 0 || ft_strcmp(s, "pwd") == 0 || ft_strcmp(s, "export") == 0 || //
    ft_strcmp(s, "unset") == 0 || ft_strcmp(s, "env") == 0 || ft_strcmp(s, "exit") == 0)
        new->type = "command";
    else
        new->type = "error";
    assign_value(s, new);
    new->next = NULL;
    return(new);
}

t_word  *create_list(char **s, t_word **word_list)
{
    int i;
    t_word *temp;
    t_word *new;
    t_word *prev;

    i = 0;
    prev = NULL;
    *word_list = create_node_first(s[i]);
    if (*word_list == NULL)
    {
        clean_list(word_list);
        return(NULL);
    }
    i++;
    temp = *word_list;
    while (s[i] != NULL)
    {

        prev = temp;
        new = create_node(s[i], prev);
        if (new == NULL)
        {
            clean_list(word_list);
            return(NULL);
        }
        temp->next = new;
        temp = new;
        i++;
    }
    clean_string(s);
    return(*word_list);
}