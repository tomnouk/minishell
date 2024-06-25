/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:58:33 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/25 20:55:39 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list    *get_env(t_data data, char **env)
{
    t_list *env_list;
    int     i;
    
    data.mini_env = NULL;
    i = 0;
    if (!env)
        return (printf("no env"), NULL);
    while(env[i])
    {
        env_list = ft_lstnew((char *)env[i]);
        if (!env_list) //garbge_collector
            return (NULL);
        ft_lstadd_back(&data.mini_env, env_list);
        i++;
    }
    return (data.mini_env);
}

void    print_env(t_data data)
{
    t_list *temp;
    
    temp = data.mini_env;
    while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
