/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:43:39 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 17:43:42 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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
	printf("Size of Node %i\n", ft_lstsize(root));
	
	ft_lstadd_front(&root, toadd);
	
	printf("AFTER CHANGE\n");
	printf("Size of Node %i\n", ft_lstsize(root));
}*/
