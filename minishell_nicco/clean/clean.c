/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void clean_string(char **s)
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

void  clean_list(t_word **word_list)
{
	t_word *temp;

	while (*word_list != NULL)
	{
		temp = (*word_list);
    (*word_list) = (*word_list)->next;
    free(temp->value);
    free(temp);
	}
	return ;
}