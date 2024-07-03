/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:29:14 by rpaic             #+#    #+#             */
/*   Updated: 2024/07/03 20:39:22 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void    create_new_env_var(t_data data, char *str, char *eq)
{
    t_list  *temp;
    t_list  *new_node;
    
    temp = data.mini_env;
    while (temp)
    {
        if (!ft_strncmp(str, (char *)(temp->content), eq - str + 1))
        {
            free((temp->content));
            temp->content = str;
            return ;
        }
        temp = temp->next;
    }
    new_node = ft_lstnew(ft_strdup(str));
    // if (!new_node)               <-----
    //     garbage_collector(data);
    ft_lstadd_back(&data.mini_env, new_node);
}

static void maybe_create_env_var(t_data data, char *str)
{
    t_list  *new_node;
    
    if (!search_env(data.mini_env, str))
    {
        new_node = ft_lstnew(ft_strdup(str));
        // if (!new_node)
        //     garbage_collector(data);
        ft_lstadd_back(&data.mini_env, ft_lstnew(ft_strdup(str)));
    }
}

// static void update_env_var(t_data data, char *str, char *eq)
// {
//     t_list  *temp;
//     char    *new_token;
    
//     temp = g_data.mini_env;
//     if (*(eq + 1) == '\0')
//         return (maybe_create_env_var(data, str));
//     while (temp)
//     {
//         if (!ft_strncmp(str, (char *)(temp->content), eq - str + 1))
//         {
//             new_token = ft_strjoin((char *)(temp->content), eq + 1);
//             free(temp->content);
//             temp->content = new_token;
//             return ;
//         }
//         temp = temp->next;
//     }
// }
void    ft_export(t_data data, t_list *cur_token)
{
    char    *str;
    t_list  *actual_node;
    int     left_side_type;
    
    actual_node = cur_token->next;
    if (!actual_node || ((t_tkn_data *)(actual_node->content))->type != WORD)
        return (solo_export(data));   
    while (actual_node && ((t_tkn_data *)(actual_node->content))->type == WORD)
    {   
        str = ((t_tkn_data *)(actual_node->content))->token;
        left_side_type = -1;
        check_left_side_export(str, &left_side_type);
        if (left_side_type == -1)
            maybe_create_env_var(data, str);
        else if (left_side_type == 0)
            ft_printf("minishell: export: `%s': not a valid identifier\n", str); //EXIT STATUS
        else if (left_side_type == 1)
            create_new_env_var(data, str, ft_strchr(str, '='));
        // else if (left_side_type == 2)
        //     update_env_var(data, str, ft_strchr(str, '='));
        actual_node = actual_node->next;
    }
}
