/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:16:30 by aeid              #+#    #+#             */
/*   Updated: 2024/06/20 19:42:06 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/minishell.h"

//int main (int argc, char **argv, char **env)
// static void printTokens(t_list *tokens) {
//     t_list *current = tokens;
//     while (current != NULL) 
// 	{
//         t_tkn_data *tokenData = (t_tkn_data *)current->content;
//         printf("%s\n", tokenData->token);
//         current = current->next;
//     }
// }
static void printTokens(t_list *tokens) {
    t_list *current = tokens;
    while (current != NULL) {
        t_tkn_data *tokenData = (t_tkn_data *)current->content;
        printf("%s\n", tokenData->token);
        current = current->next;
    }
}

int main (int argc, char **argv, char **env)
{
	t_data data;
	argc = 0;
	argv = 0;

	data.args = readline("Enter a string: ");
	data.mini_env = get_env(data, env);
	//print_env(data);
	data.tokens = NULL;
	printf("You entered: %s\n", data.args);
	ft_tokenizing(&data);
	//ft_parsing(&data);
	printTokens(data.tokens);
}
//https://www.gnu.org/software/bash/manual/bash.html#Shell-Operation