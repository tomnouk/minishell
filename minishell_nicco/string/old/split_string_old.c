/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *grate(const char *s, int *i)
{
    char *word;
    int j;

    j = *i;
    if (s[j + 1] !='\0' && s[j + 1] == 62)
    {
        j++;
    }
    j++;
    word = (char *)malloc((j - *i + 1) * sizeof(char));
    if (word == NULL)
        return(NULL);
    copy_string(word, s + *i, j - *i);
    *i = j;
    return(word);
}

char *less(const char *s, int *i)
{
    char *word;
    int j;

    j = *i;
    if (s[j + 1] !='\0' && s[j + 1] == 60)
    {
        j++;
    }
    j++;
    word = (char *)malloc((j - *i + 1) * sizeof(char));
    if (word == NULL)
        return(NULL);
    copy_string(word, s + *i, j - *i);
    *i = j;
    return(word);
}

char *single_quote(const char *s, int *i)
{
    char *word;
    int j;
    
    j = *i + 1;
    while (s[j] != 39)
    {
        j++;
    }
    word = (char *)malloc((j - *i + 1) * sizeof(char));
    if (word == NULL)
        return(NULL);
    copy_string(word, s + *i + 1, j - *i - 1);
    *i = j + 1;
    return(word);
}

char *double_quote(const char *s, int *i, t_env_var *env)
{
    char *word;
    int j;
    int q;
    int t;
    int z;
    
    j = *i + 1;
    z = j;
    q = count_env_var(s, j, env);
    //printf("q = %d\n", q);
    //fflush(stdout);
    while (s[z] != 34)
    {
        if (s[z] == 36)
        {
            z++;
            while (ft_isalnum(s[z]) == 1)
                z++;
        }
        else
        {
            z++;
            j++;
        }
    }
    //printf("j = %d\n", j);
    //fflush(stdout);
    word = (char *)malloc((j - (*i + 1) + 1 + q) * sizeof(char));
    //printf("i = %d\n", *i);
    //fflush(stdout);
    t = (j - (*i + 1) + 1 + q);
    //printf("t = %d\n", t);
    //fflush(stdout);
    if (word == NULL)
        return(NULL);
    //printf("tot %d\n", j - *i - 1 + q);
    //fflush(stdout);
    //printf("string = %s\n", (s + *i + 1));
    //fflush(stdout);
    copy_string_var(word, s + *i + 1, j - *i - 1 + q, env);
    *i = z + 1;
    //printf("d = %d\n", *i);
    //fflush(stdout);
    return(word);
}

char *space(const char *s, int *i)
{
    char *word;
    int j;
    int k;
    
    k = 0;
    j = *i;
    while (s[j] != 32 && s[j] != 60 && s[j] != 62 && s[j] != '\0')
    {
        if (s[j] == 34)
        {
            j++;
            while (s[j] != 34)
            {
                j++;
            }
            k = k + 2;
        }
        if (s[j] == 39)
        {
            j++;
            while (s[j] != 39)
            {
                j++;
            }
            k = k + 2;
        }
        j++;
    }
    word = (char *)malloc((j - *i + 1 - k) * sizeof(char));
    if (word == NULL)
        return(NULL);
    copy_string_mod(word, s + *i, j - *i);
    *i = j;
    return(word);
}

char **split_string(const char *s, t_env_var *env)
{
    char **words = malloc((ft_strlen(s) + 1) * sizeof(char *));

    int i = 0;
    size_t j = 0;

    while (s[i] != '\0')
    {
        while (s[i] == ' ' && s[i] != '\0')
        {
            i++;
        }
        if (s[i] == 34)
        {
            words[j] = double_quote(s, &i, env);
            if (words[j] == NULL)
                return(free_string(words, j));
            j++;
        }
        else if (s[i] == 39)
        {
            words[j] = single_quote(s, &i);
            if (words[j] == NULL)
                return(free_string(words, j));
            j++;
        }
        else if (s[i] == 60)
        {
            words[j] = less(s, &i);
            if (words[j] == NULL)
                return(free_string(words, j));
            j++;
        }
        else if (s[i] == 62)
        {
            words[j] = grate(s, &i);
            if (words[j] == NULL)
                return(free_string(words, j));
            j++;
        }
        else if (s[i] != '\0')
        {
            words[j] = space(s, &i);
            if (words[j] == NULL)
                return(free_string(words, j));
            j++;
        }
    }
    words[j] = NULL;
    while (j < ft_strlen(s) + 1)
    {
        words[j] = NULL;
        j++;
    }
    return(words);
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