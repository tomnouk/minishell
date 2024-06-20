/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:08:56 by aeid              #+#    #+#             */
/*   Updated: 2023/11/10 14:40:49 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//this is the function to call to delete the content//
/*void	delete (void *content)
{
	free(content);
}*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
