/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:02:12 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 22:50:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static char *find_path(char *curr_content, char *variable)
{
	if (!ft_strncmp(variable, curr_content, ft_strlen(variable)))
		return (ft_strchr(curr_content, '=') + 1);
	return (NULL);
}

char *search_env(t_list *mini_env, char *variable)
{
	t_list *current;
	char *path;
	char *after_expand;

	current = mini_env;
	path = NULL;
	after_expand = NULL;
	while (current)
	{
		path = find_path((char *)current->content, variable);
		if (path)
		{
			memory_allocator((void **)&after_expand, ft_strlen(path) + 1);
			ft_strlcpy(after_expand, path, ft_strlen(path) + 1);
			return (after_expand);
		}
		current = current->next;
	}
	return (NULL);
}
