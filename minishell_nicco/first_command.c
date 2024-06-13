/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clean_all(char **s)
{
  int i;

  i = 0;
  while (s[i] != NULL)
  {
    free(s[i]);
    i++;
  }
  free(s);
  return;
}

void ft_env_print(t_env_var **env)
{
  t_env_var *temp = *env;

  while (temp != NULL)
  {
    printf("%s=%s\n", temp->name, temp->value);
    temp = temp->next;
  }
  return;
}

void ft_env_print_ex(t_env_var **env)
{
  t_env_var *temp = *env;

  while (temp != NULL)
  {
    printf("declare -x ");
    printf("%s=\"%s\"\n", temp->name, temp->value);
    temp = temp->next;
  }
  return;
}

void ft_env_add(t_env_var **env, char *s1, char *s2)
{
  t_env_var *temp;
  t_env_var *new;

  temp = *env;
  new = (t_env_var *)malloc(sizeof(t_env_var));
  new->name = s1;
  new->value = s2;
  new->next = NULL;
  if (*env == NULL)
  {
    *env = new;
    return;
  }
  while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
  return;
}

void ft_env_rem(t_env_var **env, char *s1)
{
  t_env_var *temp;
  t_env_var *prev;

  temp = *env;
  prev = NULL;
  while (temp != NULL)
	{
		if (ft_strncmp(temp->name, s1, ft_strlen(s1)) == 0)
    {
      if (prev == NULL)
      {
        *env = temp->next;
        free(temp->name);
        free(temp->value);
        free(temp);
      }
      else
      {
      prev->next = temp->next;
      free(temp->name);
      free(temp->value);
      free(temp);
      }
      return;
	  }
    prev = temp;
    temp = temp->next;
	}
  return;
}

void first_command(char **s, char *prompt, t_env_var **env)
{
	char cwd[1024] = "";
  char **parts;

	if (ft_strncmp(s[0], "echo", 4) == 0)
  {
    if (ft_strncmp(s[1], "-n", 2) == 0)
      printf("%s", s[2]);
    else
      printf("%s\n", s[1]);
  }
  else if (ft_strncmp(s[0], "cd", 2) == 0) 
	{
    if (chdir(s[1]) == 0) 
		{
			ft_memset(cwd, '\0', sizeof(cwd));
			if (getcwd(cwd, sizeof(cwd)) != NULL) 
			{
        ft_memset(prompt, '\0', ft_strlen(prompt));
        ft_strlcat(prompt, cwd, sizeof(cwd));
        ft_strlcat(prompt, "$ ", sizeof(cwd));
      }
      rl_on_new_line();
      rl_replace_line(prompt, 1);
      //rl_redisplay();
    }
  }
  else if (ft_strncmp(s[0], "pwd", 3) == 0) 
  {
    ft_memset(cwd, '\0', sizeof(cwd));
    if (getcwd(cwd, sizeof(cwd)) != NULL) 
    {
      printf("%s\n",cwd);
    }
  }
  else if (ft_strncmp(s[0], "export", 6) == 0)
  {
    if (s[1] != NULL)
    {
      parts = ft_split(s[1], '=');
      ft_env_add(env, parts[0], parts[1]);
    }
    else
      ft_env_print_ex(env);
  }
  else if (ft_strncmp(s[0], "unset", 5) == 0)
  {
    if (s[1] != NULL)
    {
      ft_env_rem(env, s[1]);
    }
  }
  else if (ft_strncmp(s[0], "env", 3) == 0)
  {
    ft_env_print(env);
  }
  else if (ft_strncmp(s[0], "exit", 4) == 0)
  {
    clean_all(s);
    exit(-1);
  }
	else
	{
    clean_all(s);
    perror("Errore in input");
  }
  return;
}