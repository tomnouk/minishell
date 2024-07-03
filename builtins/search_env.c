/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:02:12 by aeid              #+#    #+#             */
/*   Updated: 2024/07/03 11:50:08 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this function will always return a pointer to the start after = sign

# include "../headers/minishell.h"

char *find_path(char *curr_content, char *variable)
{
	char *eq;
	char *path;
	size_t len;

	eq = NULL;
	path = NULL;
	len = 0;
	if (!ft_strncmp(variable, curr_content, ft_strlen(variable)))
	{
		eq = ft_strchr(curr_content, '=');
		path = curr_content;
		len = eq - path;
		if (len != ft_strlen(variable))
			return (NULL);
		return (ft_strchr(curr_content, '=') + 1);
	}
	return (NULL);
}

char *search_env(t_list *mini_env, char *variable)
{
	t_list *current;
	char *path;
	char *after_equal_sign;

	current = mini_env;
	path = NULL; //not mallcd
	after_equal_sign = NULL;
	while (current)
	{
		path = find_path((char *)current->content, variable);
		if (path)
		{
			memory_allocator((void **)&after_equal_sign, ft_strlen(path) + 1);
			ft_strlcpy(after_equal_sign, path, ft_strlen(path) + 1);
			return (after_equal_sign);
		}
		current = current->next;
	}
	return (NULL);
}
