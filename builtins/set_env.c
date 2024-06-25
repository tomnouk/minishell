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

# include "../headers/minishell.h"

//"OLDPWD", old_pwd, env

void	set_env(char *name, char *path, t_list *mini_env)
{
	char	*new_entry;
	size_t	new_entry_len;
	t_list *current;

	current = mini_env;
	new_entry = NULL;
	new_entry_len = ft_strlen(name) + ft_strlen(path) + 2; // for '=' and null terminator
	while (current)
	{
		if (find_path((char *)current->content, name))
		{
			memory_allocator((void **)&new_entry, new_entry_len);
			ft_strlcat(new_entry, name, new_entry_len);
			ft_strlcat(new_entry, "=", new_entry_len);
			ft_strlcat(new_entry, path, new_entry_len);
			//printf("new_entry: %s\n", new_entry);
			//printf("current->content: %s\n", (char *)current->content);
			current->content = new_entry;
			return;
		}
		current = current->next;
	}
}

/*
void	set_env(char *name, char *value, char *env)
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
}*/

