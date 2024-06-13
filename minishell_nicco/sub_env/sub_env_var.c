/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t lenght_env_var(char *s)
{
    size_t i;

    i = 0;
    while (ft_isenvvar(s[i]) == 1)
    {
        i++;
    }
    return(i);
}

void sub_env_var(char **s, t_env_var *env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != NULL)
    {
        j = 0;
        while (s[i][j] != '\0')
        {
            if (s[i][j] == 39)
            {
                while (s[i][j] != 39)
                {
                    j++;
                }
            }
            else
            {
                if (s[i][j] == '$')
                {
                    lenght_env_var(s[i])
                }
            }
            j++;
        }
        i++;
    }
}

/*
int main()
{
    char *s = "cio  aa<<aaa\"ciao  <<<<    bb\"aaaq><<   \"come stai\"<";
    //char *s = "cio   aa<<aaa";
    char **words = split(s);
    int i = 0;
    while (words[i] != NULL)
    {
        printf("%s\n", words[i]);
        i++;
    }
    clean_all(words);
    return(0);
}*/