/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:33:25 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/24 19:16:52 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void	ft_cd(t_list *tokens, char **env)
{
	char	*old_pwd;
	char	cwd[1024];
	char	*path;
	char	*new_pwd;

	if (!tokens || !tokens->next || !(path = (char *)tokens->next->content))
	{
		path = get_env_value("HOME");
		if (!path)
		{
			write(STDERR_FILENO, "minishell: cd: HOME not set\n", 29);
			return ;
		}
	}
	old_pwd = getcwd(cwd, sizeof(cwd));
	if (old_pwd == NULL)
	{
		perror("getcwd");
		return ;
	}
	if (chdir(path) != 0)
	{
		perror("cd");
		return ;
	}
	new_pwd = getcwd(cwd, sizeof(cwd));
	if (new_pwd == NULL)
	{
		perror("getcwd");
		return ;
	}
	set_env("OLDPWD", old_pwd, env);
	set_env("PWD", new_pwd, env);
}
 

