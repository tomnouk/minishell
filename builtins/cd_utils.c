/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:56:03 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/25 14:01:41 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*create_token(char *content)
{
	t_list *new_token = (t_list *)malloc(sizeof(t_list));
	if (!new_token)
		return NULL;
	new_token->content = strdup(content);
	new_token->next = NULL;
	return new_token;
}

void	free_tokens(t_list *tokens)
{
	t_list	*temp;
	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->content);
		free(temp);
	}
}

void	append_token(t_list **tokens, char *content)
{
	t_list	*new_token;
	
	new_token = create_token(content);
	if (!new_token)
		return;
	if (*tokens == NULL)
		*tokens = new_token;
	else
	{
		t_list *temp = *tokens;
		while (temp->next)
			temp = temp->next;
		temp->next = new_token;
	}
}

t_list	*parse_line(char *line)
{
	t_list	*tokens = NULL;
	char *token = strtok(line, " ");
	while (token)
	{
		append_token(&tokens, token);
		token = strtok(NULL, " ");
	}
	return tokens;
}

char	*read_line()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = getline(&line, &len, stdin); //sans utiliser getline
	if (nread == -1)
	{
		free(line);
		return NULL;
	}
	line[strcspn(line, "\n")] = '\0'; // supp le caract de new line
	return line;
}
