/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <rpaic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:54:51 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/05 20:47:22 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	till(int type)
{
	if ((type == META_PIPE) || (type == META_REDIR_OUT))
		return (false);
	if ((type == META_HEREDOC) || (type == META_REDIR_IN))
		return (false);
	return (true);
}

static bool	is_white(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (true);
	return (false);
}

static int	write_no_white(char *str)
{
	char	*now;
	int		flag;
	int		res;

	flag = 0;
	res = 0;
	if (!str)
		return (0);
	now = str;
	while (*now && is_white(*now))
		now++;
	while (*now)
	{
		if (is_white(*now))
			flag = 1;
		if (ft_isprint(*now))
		{
			if (flag)
				res += write(STDOUT_FILENO, " ", 1);
			flag = 0;
			res += write(STDOUT_FILENO, now, 1);
		}
		now++;
	}
	return (res);
}

static t_list	*check_nl_flag(t_list *curr)
{
	char	*token_str;
	int		i;

	while (curr && till(((t_tkn_data *)(curr->content))->type))
	{
		token_str = ((t_tkn_data *)(curr->content))->token;
		i = 0;
		if (token_str)
		{
			if (token_str[i] == '-' && token_str[i + 1] == 'n')
			{
				while (token_str[++i])
					if (token_str[i] != 'n')
						return (curr);
				curr = curr->next;
			}
			else
				return (curr);
		}
		else
			curr = curr->next;
	}
	return (curr);
}

void	ft_echo(t_list *cur_token)
{
	bool	nl;
	t_list	*curr;
	t_list	*start;
	int		space;

	nl = false;
	skip_null_tokens(&cur_token);
	start = cur_token;
	curr = check_nl_flag(start);
	if (curr == start)
		nl = true;
	while (curr && till(((t_tkn_data *)(curr->content))->type))
	{
		if (((t_tkn_data *)(curr->content))->type == META_DOL)
			space = write_no_white(((t_tkn_data *)(curr->content))->token);
		else
			space = write(STDOUT_FILENO, ((t_tkn_data *)(curr->content))->token,
					ft_strlen(((t_tkn_data *)(curr->content))->token));
		skip_null_tokens(&curr);
		if (space && curr && ((t_tkn_data *)(curr->content))->token
			&& till(((t_tkn_data *)(curr->content))->type))
			write(STDOUT_FILENO, " ", 1);
	}
	check_nl(nl);
	g_exit_status = 0;
}
