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

void	ft_cd(t_list *tokens, t_list *mini_env)
{
	char	*old_pwd;
	char	cwd[1024];
	char	*path;
	char	*new_pwd;

	if (!tokens || !tokens->next)
	{
		path = search_env(mini_env, "HOME");
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
	set_env("OLDPWD", old_pwd, mini_env);
	set_env("PWD", new_pwd, mini_env);
}

/*
void	ft_cd(t_list *tokens, t_list *env)
{
	char	*old_pwd;
	char	cwd[1024];
	char	*path;
	char	*new_pwd;
	t_list *current;
	t_tkn_data *data;

	current = tokens->next;
	data = NULL;
	if (current && current->next)
	{
		write(STDERR_FILENO, "minishell: cd: too many arguments\n", 35);
		return ;
	}
	else if (!tokens || !current)
	{
		path = search_env(env, "HOME");
		if (!path)
		{
			write(STDERR_FILENO, "minishell: cd: HOME not set\n", 29);
			return ;
		}
	}
	else
	{
		data = (t_tkn_data *)current->content;
		path = data->token;
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
}*/