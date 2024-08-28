/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:36:03 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/05 19:51:44 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	create_new_env_var(t_data data, char *str, int type)
{
	t_list	*temp;
	t_list	*new_node;

	temp = data.mini_env;
	while (temp)
	{
		if (str)
		{
			if (!ft_strncmp(str, (char *)(temp->content), most_right_eq(str,
					(char *)(temp->content))))
			{
				if (type == 1)
				{
					free_null((temp->content));
					temp->content = ft_strdup(str);
					return ;
				}
				else if (type == 2)
					return ;
			}
			temp = temp->next;
		}
	}
	new_node = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(&data.mini_env, new_node);
}

static void	check_and_update_flag(char *l_eq, char *s, int *flag)
{
	if (ft_strchr(l_eq, '='))
	{
		l_eq[ft_strchr(l_eq, '=') - l_eq] = '\0';
	}
	if (!ft_strncmp(s, l_eq, biggest_strlen(s, l_eq)))
	{
		(*flag)++;
	}
}

static void	maybe_create_env_var(t_data data, char *s)
{
	t_list	*new_node;
	t_list	*temp_env;
	char	*l_eq;
	int		flag;

	flag = 0;
	temp_env = data.mini_env;
	while (temp_env)
	{
		l_eq = ft_strdup((char *)(temp_env->content));
		if (!temp_env->print && !ft_strncmp(s, l_eq, biggest_strlen(s, l_eq)))
			flag++;
		else
		{
			check_and_update_flag(l_eq, s, &flag);
		}
		free(l_eq);
		if (flag)
			return ;
		temp_env = temp_env->next;
	}
	new_node = ft_lstnew(ft_strdup(s));
	ft_lstadd_back(&data.mini_env, new_node);
}

static void	update_env_var(t_data data, char *str, char *eq, int type)
{
	t_list	*temp;
	size_t	compare_till;

	temp = data.mini_env;
	if (*(eq + 1) == '\0')
	{
		str[eq - str] = '\0';
		str[eq - str - 1] = '=';
		return (create_new_env_var(data, str, type));
	}
	while (temp)
	{
		compare_till = idx_of_eq_or_plus(str, (char *)(temp->content));
		if (!ft_strncmp(str, (char *)(temp->content), compare_till))
		{
			if (temp->print)
				temp->content = strjoin_free(temp->content, eq + 1, 1);
			else
				temp->content = strjoin_free(temp->content, eq, 1);
			temp->print = 1;
			return ;
		}
		temp = temp->next;
	}
	add_toenv_skip_plus(data, str);
}

t_list	*ft_export(t_data data, t_list *cur_token)
{
	char	*str;
	t_list	*curr;
	int		left_side_type;

	curr = cur_token->next;
	if (!curr || !till(((t_tkn_data *)(curr->content))->type))
		return (solo_export(data), curr);
	while (curr && till(((t_tkn_data *)(curr->content))->type))
	{
		str = ((t_tkn_data *)(curr->content))->token;
		left_side_type = -1;
		check_left_side_export(str, &left_side_type);
		if (left_side_type == -1)
			maybe_create_env_var(data, str);
		else if (left_side_type == 1)
			create_new_env_var(data, str, left_side_type);
		else if (left_side_type == 2)
			update_env_var(data, str, ft_strchr(str, '='), left_side_type);
		curr = curr->next;
	}
	return (curr);
	g_exit_status = 0;
}
