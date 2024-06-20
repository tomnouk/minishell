/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:16:21 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 19:16:23 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
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

void	del(void *content)
{
	free(content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list *prova;
	prova = ft_lstnew("contenuto");	
	printf("content before del: %s", prova->content);
	ft_lstdelone(
}*/
