/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void  print_dir(char *output, t_word *temp, int operator)
{
  int fd;

  if (ft_strcmp(temp->type, "file") == 0)
  {
    if (operator == 1)
    {
      fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC, 0666);
      write(fd, output, strlen(output));
      close(fd);
    }
    else if (operator == 2)
    {
      fd = open(temp->value, O_WRONLY | O_CREAT | O_APPEND, 0666);
      write(fd, output, strlen(output));
      close(fd);
    }
  }
  return;
}

void  pwd_command(t_word *temp)
{
  char cwd[1024] = "";

  if (temp->next != NULL)
    temp = temp->next;
  ft_memset(cwd, '\0', sizeof(cwd));
  while (temp != NULL)
  {
    if (ft_strcmp(temp->type, "operator") == 0)
    {
      if (ft_strcmp(temp->value, ">") == 0)
      {
        if (temp->next == NULL)
        {
          perror("Errore in input");
          return;
        }
        temp = temp->next;
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
          print_dir(cwd, temp, 1);
          return;
        }
      }
      else if (ft_strcmp(temp->value, ">>") == 0)
      {
        if (temp->next == NULL)
        {
          perror("Errore in input");
          return;
        }
        temp = temp->next;
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
          print_dir(cwd, temp, 2);
          return;
        }
      }
    }
    temp = temp->next;
  }
  if (getcwd(cwd, sizeof(cwd)) != NULL)
    printf("%s\n",cwd);
  return;
}
