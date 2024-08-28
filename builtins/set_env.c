/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:58:38 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/25 22:46:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//QUESTO FILE SERVE?????

void	set_env(char *name, char *path, t_list *mini_env, t_data *data)
{
	char	*new_entry;
	size_t	new_entry_len;
	t_list	*current;

	current = mini_env;
	new_entry = NULL;
	new_entry_len = ft_strlen(name) + ft_strlen(path) + 2;
	while (current)
	{
		if (find_path((char *)current->content, name))
		{
			memory_allocator((void **)&new_entry, new_entry_len, data);
			new_entry = ft_join(name, "=");
			new_entry = ft_join(new_entry, "=");
			printf("new_entry: %s\n", new_entry);
			printf("current->content: %s\n", (char *)current->content);
			current->content = new_entry;
			return ;
		}
		current = current->next;
	}
}
