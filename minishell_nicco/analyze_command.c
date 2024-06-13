/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void analyze_command(t_word *word_list, char *prompt, t_env_var **env)
{
	if (ft_strcmp(word_list->value, "echo") == 0)
  {
    echo_command(word_list);
  }
  else if (ft_strcmp(word_list->value, "cd") == 0)
  {
    cd_command(word_list, prompt);
  }
  else if (ft_strcmp(word_list->value, "pwd") == 0)
  {
    pwd_command(word_list);
  }
  else if (ft_strcmp(word_list->value, "export") == 0)
  {
    export_command(word_list, env);
  }
  else if (ft_strcmp(word_list->value, "unset") == 0)
  {
    unset_command(word_list, env);
  }
  else if (ft_strcmp(word_list->value, "env") == 0)
  {
    env_command(env);
  }
  else if (ft_strcmp(word_list->value, "exit") == 0)
  {
    exit(0);
  }
	else
	{
    perror("Errore in input");
  }
  return;
}