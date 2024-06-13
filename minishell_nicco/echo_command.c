/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin_mod(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	z;
	char	*dest;

	z = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc((i + j + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (z < i)
	{
		dest[z] = s1[z];
		z++;
	}
	while (z < (i + j))
	{
		dest[z] = s2[z - i];
		z++;
	}
	dest[z] = '\0';
  if (s1 != NULL)
    free(s1);
	return (dest);
}

static t_word  *search_file(t_word *word_list)
{
    t_word *temp;

    temp = word_list;
    while (temp != NULL && ft_strcmp(temp->type, "file") != 0)
    {
        temp = temp->next;
    }
    return(temp);
}

static void  print_output(char *output, int fd, int option)
{
  if (option == 0)
  {
    write(fd, output, strlen(output));
    write(fd, "\n", 1);
  }
  else
  {
    write(fd, output, strlen(output));
  }
  return;
}

static void  print_command(char *output, t_word *word_list, int option, int operator)
{
  t_word *temp;
  int fd;

  temp = word_list;
  if (operator == 1)
  {
    temp = search_file(word_list); //controllare
    fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    //if (fd == -1)
    print_output(output, fd, option);
    close(fd);
  }
  else if (operator == 2)
  {
    temp = search_file(word_list);
    fd = open(temp->value, O_WRONLY | O_CREAT | O_APPEND, 0666);
    //if (fd == -1)
    print_output(output, fd, option);
    close(fd);
  }
  else if (operator == 0)
  {
    fd = 1;
    print_output(output, fd, option);
  }
  return;
}

void  echo_command(t_word *word_list)
{
  t_word  *temp;
  char  *output;
  char  *old_output;
  int option;
  int operator;

  option = 0;
  operator = 0;
  output = ft_strdup("");
  temp = word_list->next;
  if (temp != NULL && ft_strcmp(temp->value, "-n") == 0)
  {
    option = 1;
    temp = temp->next;
  }
  while (temp != NULL)
  {
    if (ft_strcmp(temp->type, "operator") == 0)
    {
      if (ft_strcmp(temp->value, ">") == 0)
      {
        temp = temp->next;
        operator = 1;
      }
      else if (ft_strcmp(temp->value, ">>") == 0)
      {
        temp = temp->next;
        operator = 2;
      }
    }
    else if (ft_strcmp(temp->type, "argument") == 0)
    {
      old_output = output;
      if (ft_strcmp(output, "\0") != 0)
      {
        output = ft_strjoin_mod(old_output, " ");
        old_output = output;
      }
      output = ft_strjoin_mod(old_output, temp->value);
    }
    temp = temp->next;
  }
  print_command(output, word_list, option, operator);
  free(output);
  return;
}
