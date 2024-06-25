/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:58:38 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/25 12:46:07 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void	set_env(char *name, char *value, char **env)
{
	int		i;
	char	*new_entry;
	size_t	new_entry_len;

	new_entry_len = ft_strlen(name) + ft_strlen(value) + 2; // for '=' and null terminator
	new_entry = malloc(new_entry_len);
	if (new_entry == NULL)
	{
		perror("malloc");
		return;
	}
	strcpy(new_entry, name);
	new_entry[ft_strlen(name)] = '=';
	strcpy(new_entry + ft_strlen(name) + 1, value);
	for (i = 0; env[i]; i++)
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0 && env[i][ft_strlen(name)] == '=')
		{
			free(env[i]);
			env[i] = new_entry;
			return;
		}
	}
	env[i] = new_entry;
	env[i + 1] = NULL;
}

char *get_env_value(char *key)
{
	t_list *current;
		
	current = g_data.mini_env;
	while (current)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(key) + 1))
		{
			return (ft_strdup(current->value));
		}
		current = current->next;
	}
	return (NULL);
}

