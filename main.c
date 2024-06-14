/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:16:30 by aeid              #+#    #+#             */
/*   Updated: 2024/06/14 18:55:40 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/minishell.h"

//int main (int argc, char **argv, char **env)
static void printTokens(t_list *tokens) {
    t_list *current = tokens;
    while (current != NULL) 
	{
        t_tkn_data *tokenData = (t_tkn_data *)current->content;
        printf("%s\n", tokenData->token);
        current = current->next;
    }
}

int main ()
{
	t_data data;

	data.args = readline("Enter a string: ");
	data.env = NULL;
	data.tokens = NULL;
	printf("You entered: %s\n", data.args);
	ft_tokenizing(&data);
	//ft_parsing(&data);
	printTokens(data.tokens);
}
