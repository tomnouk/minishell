#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include "../headers/minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static char *find_path(char *curr_content, char *variable)
{
	if (!ft_strncmp(variable, curr_content, ft_strlen(variable)))
	{
		char *eq = ft_strchr(curr_content, '=');
		char *path = curr_content;
		int len = eq - path;
		if (len != ft_strlen(variable))
			return (NULL);
		return (ft_strchr(curr_content, '=') + 1);
	}
	return (NULL);
}

void memory_allocator(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return ;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char *search_env(t_list *mini_env, char *variable)
{
	t_list *current;
	char *path;
	char *after_equal_sign;

	current = mini_env;
	path = NULL;
	after_equal_sign = NULL;
	while (current)
	{
		path = find_path((char *)current->content, variable);
		if (path)
		{
			memory_allocator((void **)&after_equal_sign, ft_strlen(path) + 1);
			ft_strlcpy(after_equal_sign, path, ft_strlen(path) + 1);
			return (after_equal_sign);
		}
		current = current->next;
	}
	return (NULL);
}

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

t_list    *get_env(t_data data, char **env)
{
    t_list *env_list;
    int     i;
    
    data.mini_env = NULL;
    i = 0;
    if (!env)
        return (printf("no env"), NULL);
    while(env[i])
    {
        env_list = ft_lstnew((char *)env[i]);
        if (!env_list) //garbge_collector
            return (NULL);
        ft_lstadd_back(&data.mini_env, env_list);
        i++;
    }
    return (data.mini_env);
}

void    print_env(t_data data)
{
    t_list *temp;
    
    temp = data.mini_env;
    while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

int main(int argc, char **argv, char **env)
{
	t_data data;
	data.mini_env = NULL;
	data.mini_env = get_env(data, env);
	char *str = search_env(data.mini_env, "PATH");
	printf("%s\n", str);
	char *str2 = search_env(data.mini_env, "PATH");
	printf("%s\n", str2);
}