/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:08:41 by aeid              #+#    #+#             */
/*   Updated: 2024/07/03 22:14:03 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

static char	*get_command(char **paths, char *cmd)
{
	char	*p;
	char	*command;

	while (*paths)
	{
		p = ft_strjoin(*paths, "/");
		command = ft_strjoin(p, cmd);
		free(p);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char **get_cmd_path(t_list *mini_env)
{
	char *path_str;
	
	path_str = search_env(mini_env, "PATH");
	return(ft_split(path_str, ':'));
}


void define_commands(t_list *tokens, char **path)
{
	t_list *current;
	t_tkn_data *string;
	
	current = tokens;
	string = NULL;
	while (current)
	{
		string = (t_tkn_data *)current->content;
		if (string->type == WORD)
			string->cmd_exec_path = get_command(path, string->token);
		if (string->cmd_exec_path == NULL)
			printf("Command not found\n");
		else
		{
			printf("Command path: %s\n", string->cmd_exec_path);
			string->type = COMMAND;
		}
		current = current->next;
	}
}

