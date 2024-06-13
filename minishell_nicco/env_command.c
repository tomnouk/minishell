/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void  env_command(t_env_var **env)
{
  ft_env_print(env);
  return;
}
