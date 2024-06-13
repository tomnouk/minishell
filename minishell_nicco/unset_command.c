/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_env_rem(t_env_var **env, char *s1)
{
  t_env_var *temp;
  t_env_var *prev;

  temp = *env;
  prev = NULL;
  while (temp != NULL)
	{
		if (ft_strcmp(temp->name, s1) == 0)
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

void  unset_command(t_word *word_list, t_env_var **env)
{
  t_word  *temp;

  temp = word_list;
  if (temp->next != NULL)
    temp = temp->next;
  ft_env_rem(env, temp->value);
  return;
}
