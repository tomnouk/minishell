/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:44:34 by rpaic             #+#    #+#             */
/*   Updated: 2024/06/21 19:55:27 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void    export(t_list *tokens)
{
    t_list *next_node;
    t_tkn_data *content_next_token;
    char    *string;

    next_node = tokens->next;
    content_next_token = (t_tkn_data *)next_node->content;
    string = content_next_token->token;
    //check string
    if(string[0] != '_' || !ft_isalpha(string[0]))
    {
        printf("minishell: export: `%s': not a valid identifier\n", string);
        return;
    }
    //check if string is in mini_env
    
    
    
    
}