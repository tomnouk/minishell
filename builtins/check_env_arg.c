/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:05 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/24 20:23:52 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int    str_type(char *str)
{
    if (ft_isalpha(str[0]) == 0 && str[0] != '_')
         return (0);
    else if (ft_strchr(str, '+'))
    {
        if (*(ft_strchr(str, '+') + 1) == '=')
            return (2);
    }
    else if (ft_strchr(str, '='))
        return (1);
    return (-1);
}

static void    check_left_side(char *str, int *left_side_type)
{
    char *end;
    
    if (*left_side_type == 1)
        end = ft_strchr(str, '=');
    else if (*left_side_type == 2)
        end = ft_strchr(str, '+');
    else
        end = str + ft_strlen(str);
    while(str != end)
    {
        if ((ft_isalnum(*str) == 0) && *str != '_')
        {
            left_side_type = 0;
            return ;
        }
        str++;
    }
}

void    check_env_arg(char *str, int *left_side_type)
{
    *left_side_type = str_type(str);
    check_left_side(str, left_side_type);
}