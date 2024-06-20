/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:59:06 by rpaic             #+#    #+#             */
/*   Updated: 2023/11/01 15:59:09 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
/*
int main ()
{
	char	*contenuto;
	
	contenuto = "lista";
	//t_list	*ll = malloc(sizeof(t_list));
	t_list	*ll;
	ll = ft_lstnew(contenuto);
	printf("%s\n", (char *)ll->content);
	ll->content = "cambiata";
	printf("%s\n", (char *)ll->content);
	free(ll);
}*/
