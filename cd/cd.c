/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:33:25 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/24 11:19:15 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"

void	update_env(const char *name, const char *value)
{
	char	*env_var;
	size_t	len;

	len = strlen(name) + strlen(value) + 2;
	env_var = (char *)malloc(len);
	if (!env_var)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	snprintf(env_var, len, "%s=%s", name, value);
	putenv(env_var);
}

void	cd(const char *path)
{
	char	*target_directory;
	char	cwd[1024];
	char	*oldpwd;
	char	*home;
	char	*pwd;

	oldpwd = getenv("OLDPWD");
	home = getenv("HOME");
	pwd = getenv("PWD");
	if (path == NULL || strcmp(path, "~") == 0)
	{
		if (home == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}
		target_directory = home;
	}
	else if (strcmp(path, "-") == 0)
	{
		if (oldpwd == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		target_directory = oldpwd;
	}
	else if (strcmp(path, "..") == 0)
	{
		char current_dir[1024];
		if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		{
			perror("cd: getcwd");
			return;
		}
		char parent_dir[1024];
		snprintf(parent_dir, sizeof(parent_dir), "%s/..", current_dir);
		struct stat st;
		if (stat(parent_dir, &st) == 0 && S_ISDIR(st.st_mode))
			target_directory = parent_dir;
		else
		{
			fprintf(stderr, "cd: %s: No such file or directory\n", parent_dir);
			return;
		}
	}
	else
		target_directory = (char *)path;
	if (chdir(target_directory) != 0)
	{
		fprintf(stderr, "cd: %s: %s\n", target_directory, strerror(errno));
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (pwd != NULL)
			update_env("OLDPWD", pwd);
		update_env("PWD", cwd);
	}
	else
		perror("cd: getcwd");
}


