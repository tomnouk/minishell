SRCS = main.c\
	string/split_string.c string/split_string_2.c\
	list/create_list.c\
	clean/clean.c\
	analyze_command.c\
	echo_command.c cd_command.c pwd_command.c export_command.c unset_command.c env_command.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

all: $(NAME) libft/libft.a

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline -Llibft -lft

libft/libft.a:
	make -s -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)
	make -s -C libft clean

fclean: clean
	rm -f $(NAME)
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re
