/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:27:06 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/02 10:27:08 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
/*
t_list *ft_lstnew(void *content)
{
	t_list	*new_list;
	
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;	
	return (new_list);
}

void	f(void *ptr)
{
	char *change = (char *)ptr;
	change[0] = 'X';
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
/*
int main()
{
	char *prima = malloc(2);
	if (!prima)
		return (1);
	strcpy(prima, "1");
	t_list *lprima = ft_lstnew(prima);
	if (!lprima)
	{
		free(prima);
		return (1);
	}
	char *seconda = malloc(2);
	strcpy(seconda, "2");
	t_list *lseconda = ft_lstnew(seconda);
	if (!lseconda)
	{
		free(seconda);
		return (1);
	}
	lprima->next = lseconda;
	ft_lstiter(lprima, f);
	free(prima);
	free(seconda);
	free(lprima);
	free(lseconda);
	
}*/
