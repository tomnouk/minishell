/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:44:39 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 18:13:57 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*application;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		application = f(lst->content);
		new_node = ft_lstnew(application);
		if (!new_node)
		{
			del(application);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		else
		{
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
	}
	return (new_list);
}
