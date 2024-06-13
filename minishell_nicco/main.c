/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:04:47 by nspinell          #+#    #+#             */
/*   Updated: 2024/05/11 19:40:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_word *word_list)
{
	t_word *temp;

	temp = word_list;
	while (temp != NULL)
	{
		printf("type: %s\n", temp->type);
		printf("value: %s\n", temp->value);
		temp = temp->next;
	}
	return;
}

int	main()
{
	char *input;
	char prompt[1024] = "";
	char cwd[1024] = "";
	char **s;
	t_env_var *env;
	t_word *word_list;

	env = NULL;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_strlcat(prompt, cwd, sizeof(cwd));
		ft_strlcat(prompt, "$ ", sizeof(cwd));
	}
	while (1)
	{
		input = readline(prompt);
		s = split_string(input);
		sub_env_var(s, &env);
		word_list = create_list(s, &word_list);
		print_list(word_list); //test
		analyze_command(word_list, prompt, &env);
		rl_on_new_line();
		add_history(input);
		free(input);
	}
	//rl_clear_history();
	return (0);
}
