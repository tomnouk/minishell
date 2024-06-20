/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:41:44 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 18:41:46 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
/*
t_list *ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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

int	main ()
{
	t_list	*begin = NULL;
	t_list	*elem = ft_lstnew("lorem");
	t_list	*elem2 = ft_lstnew("ipsum");
	t_list	*elem3 = ft_lstnew("dolor");
	t_list	*elem4 = ft_lstnew("sit");
	
	ft_lstadd_back(&begin, elem);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	ft_lstadd_back(&begin, elem4);

	
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
	
	t_list *tail = ft_lstnew("Adesso sono diventata lultima");
	ft_lstadd_back(&root, tail);
	ultima = ft_lstlast(root);
	printf("ultima->content: %s\n", (char *)ultima->content);
	printf("ultima->next   : %s\n", (char *)ultima->next);	
}*/
