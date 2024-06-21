/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:05:37 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 18:04:56 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void memory_allocator(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return ;
}

int ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int ft_ismeta(int c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

// void	free_env(t_list *env_list)
// {
// 	t_list	*tmp;

// 	while (env_list)
// 	{
// 		tmp = env_list;
// 		env_list = env_list->next;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// }
