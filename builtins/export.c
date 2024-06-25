/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:29:14 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/25 14:24:22 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void    create_new_env_var(t_data data, char *str, char *eq)
{
    t_list  *temp;
    t_list  *new_node;
    
    temp = data.mini_env;
    if (!temp)
    {
        new_node = ft_lstnew(str);
        // if (!new_node)               <-----
        //     garbage_collector(data);
        ft_lstadd_back(&data.mini_env, new_node);
        return ;
    }
    //check if env var already exists
    while (temp)
    {
        if (!ft_strncmp(str, (char *)(temp->content), eq - str + 1))
        {
            free((char *)(temp->content));
            ((t_tkn_data *)(temp->content))->token = ft_strdup(str);
            return ;
        }
        temp = temp->next;
    }
    new_node = ft_lstnew(ft_strdup(str));
    // if (!new_node)               <-----
    //     garbage_collector(data);
    ft_lstadd_back(&data.mini_env, new_node);
}
void    ft_export(t_data data, t_list *cur_token)
{
    char    *str;
    t_list  *actual_node;
    int     left_side_type;
    
    actual_node = cur_token->next;
    while (actual_node && ((t_tkn_data *)(actual_node->content))->type == WORD)
    {   
        str = ((t_tkn_data *)(actual_node->content))->token;
        left_side_type = -1;
        check_env_arg(str, &left_side_type);
        if (left_side_type == 0)
            printf("minishell: export: `%s': not a valid identifier\n", str);
        else if (left_side_type == 1)
             create_new_env_var(data, str, ft_strchr(str, '='));
        // else if (left_side_type == 2)
        //     update_env_var(str, ft_strchr(str, '+'));
        actual_node = actual_node->next;
    }
    cur_token = actual_node;
}
