static void ft_exit_handler(t_list *current, int list_size)
{
	t_list *next;
	t_tkn_data *next_string;
	int i;

	next = current->next;
	next_string = (t_tkn_data *)next->content;
	i = -1;
	if (list_size > 2)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		exit(1);
	}
	else if (list_size == 2)
		while(next_string->token[++i])
		{
			if (!ft_isdigit(next_string->token[i]))
			{
				ft_putstr_fd("bash: exit: ", 2);
				ft_putstr_fd(next_string->token, 2);
				ft_putstr_fd(": numeric argument required\n", 2);
				exit(2);
			}
	}
	return;
}

static void ft_env_handler(int list_size)
{
	if (list_size > 1)
	{
		ft_putstr_fd("bash: env: too many arguments\n", 2);
		exit(1);
	}
}