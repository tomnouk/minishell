#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum s_types
{
	SPECIAL,
	META,
	WORD,
	
} t_types;

typedef struct s_tkn_data
{
	char *token;
	t_types type;
} t_tkn_data;

typedef struct s_data
{
	t_list *env;
	t_list *tokens;
	int list_size;
	char **envp;
	char *args; //needs to be freed, result of readline//
} t_data;

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
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

int	ft_isprint(int c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}

static size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static char	*newstring(size_t n)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == NULL)
		return (NULL);
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start > str_len(s))
		len = 0;
	else if (len > (str_len(s) - start))
		len = str_len(s) - start;
	str = newstring(len);
	if (!str)
		return (NULL);
	s += start;
	p = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (p);
}

void memory_allocator(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return ;
}

int ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int ft_ismeta(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '$')
		return (1);
	return (0);
}

//skip only if the quote is similar..if not it stays the same
static void quote_removal_copy(char *string, t_data *data, t_tkn_data *token, t_list *node,int start, int current, t_types type, int quote_flag)
{
	int len;
	int i;

	len = current - start - quote_flag;
	printf("len: %d\n", len);
	i = 0;
	memory_allocator((void **)&string, len + 1);
	while (i < len && quote_flag != 0)
	{
		if (data->args[start + i] == '\"')
		{
			start++;
			quote_flag--;
			while (data->args[start + i] != '\"' && data->args[start + i] != '\n' && data->args[start + i] != '\0')
			{
				string[i] = data->args[start + i];
				i++;
			}
		}
		else if (data->args[start + i] == '\'')
		{
			start++;
			quote_flag--;
			while (data->args[start + i] != '\'' && data->args[start + i] != '\n' && data->args[start + i] != '\0')
			{
				string[i] = data->args[start + i];
				i++;
			}
		}
		else
		{
			string[i] = data->args[start + i];
			i++;
		}
	}
	string[i] = '\0';
	token->token = string;
	token->type = type;
	node->content = token;
	node->next = NULL;
	ft_lstadd_back(&data->tokens, node);
}

//this is the length of the token string before expandint the variable
static int get_length(char *args, int start, int quote_flag, int current)
{
	while (start != current)
	{
		if (args[start] == '\"')
			quote_flag--;
		else
			start++;
	}
	while ((quote_flag + 1) != 0)
	{
		if (args[start] == '\"')
			quote_flag--;
		else
			start++;
	}
	while (ft_isprint(args[start]) && !ft_ismeta(args[start]) && !ft_isquote(args[start]))
		start++;
	return (start);
}
//get the variable name
static char *get_variable(t_data *data, int current)
{
	int len;

	current++;
	len = 0;
	if (data->args[current] >= '0' && data->args[current] <= '9')
		len++;
	else if (ft_isalpha(data->args[current]))
	{
		while (ft_isalpha(data->args[current]) || data->args[current] == '_')
		{
			len++;
			current++;
		}
	}
	else if (data->args[current] == '?')
		len++;
	else
	{
		printf("Error: Invalid variable name\n");
		return (NULL);
	}
	return(ft_substr(data->args, current, len));
}
// -1 for the $ sign
static char *variable_value(t_data *data, int current, int *length, char *variable_name)
{
	int i;
	int len;
	char *variable_value;

	i = -1;
	variable_name = get_variable(data, current);
	len = ft_strlen(variable_name);
	*length = *length - len - 1;
	while (data->envp[++i])
	{
		if (strncmp(data->envp[i], variable_name, len) == 0 && data->envp[i][len] == '=')
		{
			variable_value = ft_substr(data->envp[i], len + 1, ft_strlen(data->envp[i]) - len - 1);
			break;
		}
	}
	*length = *length + ft_strlen(variable_value);
	return (variable_value);
}

//len is the length of the token string before expandint the variable
static void copy_assign(char *string, t_data *data, t_tkn_data *token, t_list *node,int *start, int *current, t_types type, int quote_flag)
{
	int len;
	char *variable_name;
	int i;
	int j;

	i = 0;
	j = 0;
	if (quote_flag % 2 && data->args[*current] == '$')
	{
		len = get_length(data->args, *start, quote_flag, *current);
		variable_value(data, *current, &len, variable_name);
		memory_allocator((void **)&string, len + 1);
		while (len != 0)
		{
			if (data->args[*start] == '\"' || data->args[*start] == variable_name[i])
			{
				(*start)++;
				i++;
			}
			else
			{
				string[j] = data->args[*start];
				len--;
				(*start)++;
			}
		}
	}
	else if (quote_flag % 2)
	{
		printf("Error: Unmatched quote\n");
		return ;
	}
	else 
	{
		string = ft_substr(data->args, *start, *current - *start);
		token->token = string;
		token->type = type;
		node->content = token;
		node->next = NULL;
		ft_lstadd_back(&data->tokens, node);
	}
}

void ft_word_token(t_data *data, int *start, int *current, t_types type)
{
	t_list *node;
	char *string;
	t_tkn_data *token;
	int quote_flag;
	
	memory_allocator((void **)&node, sizeof(t_list));
	memory_allocator((void **)&token, sizeof(t_tkn_data));
	quote_flag = 0;
	while (data->args[*current] && data->args[*current] != '\n')
	{
		if (!ft_isprint(data->args[*current]) && !(quote_flag % 2))
			break;
		else if (ft_ismeta(data->args[*current]) && !(quote_flag % 2))
		{
			printf("i exited\n");
			break;
		}
		else if (data->args[*current] == '\"')
		{
			quote_flag++;
			(*current)++;
			while (data->args[*current] != '\"' && data->args[*current] != '$' && data->args[*current] != '\n')
				(*current)++;
			if (data->args[*current] == '\"')
				quote_flag++;
			if (data->args[*current] == '$')
				break;
		}
		else if (data->args[*current] == '\'')
		{
			quote_flag++;
			(*current)++;
			while (data->args[*current] != '\'' && data->args[*current] != '\n')
				(*current)++;
			if (data->args[*current] == '\'')
				quote_flag++;
		}
		(*current)++; 
	}
	if (!(quote_flag % 2))
		quote_removal_copy(string, data, token, node, *start, *current, type, quote_flag);
	else
		copy_assign(string, data, token, node, start, current, type, quote_flag);
	if (*current == '\n')
		(*current)++;
}

void skip_initial_spaces(char *args, int *start, int *current)
{
	while (!(ft_isprint(args[*current])) && args[*current] != '\0')
	{
		(*start)++;
		(*current)++;
	}
}

static int check_if_empty(char *args)
{
	int i;

	i = 0;
	while (!(ft_isprint(args[i])))
		i++;
	if (ft_strlen(args) == i)
		return (1);
	return (0);
}

static void define_type(char *args, int cur, t_types *type)
{
	if (ft_isquote(args[cur]))
		*type = SPECIAL;
	else if (ft_ismeta(args[cur]))
		*type = META;
	else
		*type = WORD;
}

void ft_tokenizing(t_data *data)
{
	int current;
	int start;
	t_types type;

	current = -1;
	start = 0;
	if (check_if_empty(data->args))
		return ;
	while (data->args[++current])
	{
		start = current;
		skip_initial_spaces(data->args, &start, &current);
		define_type(data->args, current, &type);
		if (type == WORD)
			ft_word_token(data, &start, &current, type);
	}
}

void printTokens(t_list *tokens) {
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

	data.envp = env;
	data.args = readline("Enter a string: ");
	data.env = NULL;
	data.tokens = NULL;
	printf("You entered: %s\n", data.args);
	ft_tokenizing(&data);
	printTokens(data.tokens);
}
