/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  cd_command(t_word *word_list, char *prompt)
{
  char cwd[1024] = "";
  t_word  *temp;

  temp = word_list->next;
  if (chdir(temp->value) == 0) 
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
  return;
}
