/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/06/25 15:51:15 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "./headers/minishell.h"

t_data g_data;

int g_status;

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
/*static void printTokens(t_list *tokens) {
    t_list *current = tokens;
    while (current != NULL) {
        t_tkn_data *tokenData = (t_tkn_data *)current->content;
        printf("%s\n", tokenData->token);
        current = current->next;
    }
}*/

const char* getTypeName(t_types type) {
    switch (type) {
        case SPECIAL_SQUOTE: return "SPECIAL_SQUOTE";
        case SPECIAL_DQUOTE: return "SPECIAL_DQUOTE";
        case META_DOL: return "META_DOL";
        case META_PIPE: return "META_PIPE";
        case META_REDIR_IN: return "META_REDIR_IN";
        case META_REDIR_OUT: return "META_REDIR_OUT";
        case META_APPEND: return "META_APPEND";
        case META_HEREDOC: return "META_HEREDOC";
		case WORD_EXPORT: return "WORD_EXPORT";
		case WORD_UNSET: return "WORD_UNSET";
		case WORD_ENV: return "WORD_ENV";
		case WORD_ECHO: return "WORD_ECHO";
		case WORD_CD: return "WORD_CD";
		case WORD_EXIT: return "WORD_EXIT";
		case WORD_PWD: return "WORD_PWD";
		case WORD_DOL: return "WORD_DOL";
        case WORD: return "WORD";
        case WORD_WITH_DQUOTE_INSIDE: return "WORD_WITH_DQUOTE_INSIDE";
        default: return "UNKNOWN_TYPE";
    }
}

void printTokens(t_list *tokens) {
    t_list *current = tokens;
    while (current != NULL) {
        t_tkn_data *tokenData = (t_tkn_data *)current->content;
        printf("%s - %s -- variable_len: %d\n", tokenData->token, getTypeName(tokenData->type), tokenData->variable_len);
        current = current->next;
    }
}

void    test_export(t_data data, t_list  *tokens)
{
    t_list *current = tokens;
    while (current != NULL) {
        t_tkn_data *tokenData = (t_tkn_data *)current->content;
        if (tokenData->type == WORD_EXPORT)
            ft_export(data, current);
        current = current->next;
    }
}

int main (int argc, char **argv, char **env)
{
	t_data data;
    int ac = argc;  // <----- AGGIUNTO PER EVITARE WARNING
    ac++;
    char **av = argv;
    av[0] = av[0];

	argc = 0;
	argv = 0;
	data.args = readline("Enter a string: ");
	data.mini_env = get_env(data, env);
	//print_env(data);
	data.tokens = NULL;
	printf("You entered: %s\n", data.args);
	ft_tokenizing(&data);
	//ft_parsing(&data);
	//printTokens(data.tokens);
    // test_export(data, data.tokens);
    // printf("After export:\n");
    // print_env(data);
	printTokens(data.tokens);
	/*if (data.tokens != NULL)
	{
		ft_parsing(&data);
	}*/

	free(data.args);
	return 0;
}
//https://www.gnu.org/software/bash/manual/bash.html#Shell-Operation

