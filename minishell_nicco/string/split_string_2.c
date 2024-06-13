/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *copy_string_mod(char *dest, const char *src, size_t n)
{
    size_t j = 0;
    size_t z = 0;

    while (j < n && src[j] != '\0')
    {
        if (src[j] != 34)
        {
            dest[z] = src[j];
            z++;
        }
        j++;
    }
    dest[z] = '\0';
    return dest;
}

char *copy_string(char *dest, const char *src, size_t n)
{
    size_t j = 0;

    while (j < n && src[j] != '\0')
    {
        dest[j] = src[j];
        j++;
    }
    dest[j] = '\0';
    return dest;
}

void copy_env_var(const char *s, char *dest ,t_env_var *env, size_t *j)
{
    int i;
    char *c;
    size_t z;

    i = 0;
    while (ft_isalnum(s[i]) == 1)
        i++;
    c = (char *)malloc((i + 1) * sizeof(char));
    if (c == NULL)
        return;
    copy_string(c, s, i);
    while (env != NULL)
    {
        if (ft_strcmp(c, env->name) == 0)
        {
            z = 0;
            while (z < ft_strlen(env->value))
            {
                dest[*j] = env->value[z];
                z++;
                (*j)++;
            }
            free(c);
            return;
        }
        env = env->next;
    }
    free(c);
    return;
}

char *copy_string_var(char *dest, const char *src, size_t n, t_env_var *env)
{
    size_t j = 0;
    size_t z = 0;

    while (j < n && src[z] != '\0')
    {
        if (src[z] == 36)
        {
            z++;
            copy_env_var(src + z, dest, env, &j);
            while (ft_isalnum(src[z]) == 1 && src[z] != '\0')
                z++;
        }
        else
        {
            dest[j] = src[z];
            z++;
            j++;
        }
    }
    dest[j] = '\0';
    return (dest);
}

char	**free_string(char	**dest, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

int search_env_var(const char *s, t_env_var *env)
{
    int i;
    char *c;
    int z;

    i = 0;
    while (ft_isalnum(s[i]) == 1)
    {
        i++;
    }
    c = (char *)malloc((i + 1) * sizeof(char));
    if (c == NULL)
        return(0);
    copy_string(c, s, i);
    while (env != NULL)
    {
        if (ft_strcmp(c, env->name) == 0)
        {
            //z = ft_strlen(env->value) - ft_strlen(c) - 1; old
            z = ft_strlen(env->value);
            free(c);
            return(z);
        }
        env = env->next;
    }
    return(0);
}

int count_env_var(const char *s, int j, t_env_var *env)
{
    int i;
    int k;
    int z;

    i = j;
    k = 0;
    z = 0;
    while (s[i] != 34)
    {
        if (s[i] == 36)
        {
            i++;
            k = z;
            z = z + search_env_var(s + i, env);
            if (k == z)
                return(z);
            while (ft_isalnum(s[i]) == 1)
            {
                i++;
            }
        }
        i++;
    }
    return(z);
}