/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:26:04 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 16:26:05 by rpaic            ###   ########.fr       */
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
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list *root = ft_lstnew("root content");
	printf("root content  : %s\n", (char *)root->content);
	t_list *toadd;

	toadd = ft_lstnew("new root content");
	printf("to add content: %s\n", (char *)toadd->content);
	ft_lstadd_front(&root, toadd);
	printf("AFTER CHANGE\n");
	printf("root content: %s\n", (char *)root->content);
	printf("next content: %s\n", (char *)root->next->content);
	
}*/
