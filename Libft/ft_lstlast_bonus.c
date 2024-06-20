/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:12:30 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 18:12:33 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	main()
{
	t_list *root = ft_lstnew("root content");
	t_list *toadd = ft_lstnew("new root content");
	
	ft_lstadd_front(&root, toadd);
	
	printf("AFTER CHANGE\n");
	t_list *ultima = ft_lstlast(root);
	printf("%s\n", (char *)ultima->content);
	printf("%s\n", (char *)ultima->next);
	
}*/
