/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:53 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/02 15:40:55 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void *duplicate_content(void *content)
{
    // Assuming content is a string for this example
    return (char *)content;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
void del(void *content)
{
    free(content);
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
void ft_lstadd_back(t_list **lst, t_list *new)
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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*new_content;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_element = ft_lstnew(new_content);
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			if (new_content)
				free(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
/*
int main(void)
{
    t_list *list = NULL;
    t_list *mapped = NULL;
    char *f_strdup = strdup("Node 1");
	t_list *lst1 = ft_lstnew(f_strdup);
    ft_lstadd_back(&list, lst1);
 

    mapped = ft_lstmap(list, duplicate_content, del);
    free(f_strdup);
    free(lst1);
    free(mapped);
}*/
