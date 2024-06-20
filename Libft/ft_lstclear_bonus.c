/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:49:22 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 20:49:24 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
void	del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
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

int main()
{
	char *cntnt = ft_strdup("XXXX");

	t_list *prova = ft_lstnew(cntnt);
	if (!prova)
	{
		free(cntnt);
		return (1);	
	}
	printf("content before del: %s\n", (char *)prova->content);
	ft_lstclear(&prova, del);
	if (prova)
		printf("content not del: %s\n", (char *)prova->content);
	else
		printf("Content deleted\n");
}*/
