/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void  export_env(t_word *temp, t_env_var **env)
{
  char **parts;

  parts = ft_split(temp->value, '=');
  //write(1,parts[0],ft_strlen(parts[0]));
  //write(1, parts[1], ft_strlen(parts[1]));
  ft_env_add(env, parts[0], parts[1]);
  return;
}

void  export_command(t_word *word_list, t_env_var **env)
{
  t_word  *temp;

  temp = word_list;
  if (temp->next != NULL)
    temp = temp->next;
  else
    ft_env_print_ex(env);
  while(temp != NULL)
  {
    if (ft_strchr(temp->value, '=') != NULL)
    {
      export_env(temp, env);
      return;
    }
    temp = temp->next;
  }
  return;
}
