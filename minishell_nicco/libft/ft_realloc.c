/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:33 by nspinell          #+#    #+#             */
/*   Updated: 2023/12/19 14:15:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *src, size_t old, size_t len)
{
    void *new;
    
    if (len == 0 && src != NULL)
    {
        free(src);
        return NULL;
    }
    else if (src == NULL && len > 0)
    {
        new = malloc(len);
        return new;
    }
    else if (src == NULL && len == 0)
    {
        return NULL;
    }
    new = malloc(len);
    if (new == NULL)
        return(NULL);
    else
    {
        if (len > old)
            ft_memcpy(new, src, old);
        else
            ft_memcpy(new, src, len);
        free(src);
    }
    return new;
}
