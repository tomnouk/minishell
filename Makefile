# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:36:53 by anomourn          #+#    #+#              #
#    Updated: 2024/08/09 22:44:34 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I./Libft -I./Printf -I./headers
PFLAGS = -L./Printft -lftprintf
LFLAGS = -L./Libft -lft
RM = rm -f
PRINT_DIR = ./Printft
LIBFT_DIR = ./Libft


#main
M_SRC = ./Lexer/lexer.c \
	./Lexer/meta_cases.c \
	./Lexer/meta_cases_two.c \
	./Lexer/meta_token.c \
	./Lexer/special_token.c \
	./Lexer/special_tkn_two.c \
	./Lexer/utils.c \
	./Lexer/word_token.c \
	./Lexer/word_tkn_one.c \
	./Lexer/word_tkn_utils.c \
	./builtins/cd.c \
	./builtins/check_env_arg.c \
	./builtins/echo.c \
	./builtins/echo_utils.c \
	./builtins/exit_utils.c \
	./builtins/exit_exit.c \
	./builtins/export.c \
	./builtins/export_utils.c \
	./builtins/garbage_collector.c \
	./builtins/get_env.c \
	./builtins/pwd.c \
	./builtins/search_env.c \
	./builtins/set_env.c \
	./builtins/unset.c \
	./execution/exec_errno_manage.c \
	./execution/execute_external.c \
	./execution/execution.c \
	./execution/execution_routine.c \
	./execution/ft_here_doc.c \
	./execution/check_exp_heredoc.c \
	./execution/here_doc_utils.c \
	./execution/ft_redir_append.c \
	./execution/ft_redir_in.c \
	./execution/ft_redir_out.c \
	./execution/pipes.c \
	./execution/pipes_utils.c \
	./execution/exec_rout_utils.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c \
	./main.c \
	./parsing/define_builtins.c \
	./parsing/expander.c \
	./parsing/expander_one.c \
	./parsing/expander_dquote.c \
	./parsing/shame_of_norm_exp_dquote.c \
	./parsing/shame_of_norm_parser.c \
	./parsing/get_command.c \
	./parsing/parser.c \
	./parsing/parsing.c \
	./parsing/ft_organizer.c \
	./parsing/ft_organizer1.c \
	./signals.c \
	./utils/strjoin_free.c \
	./utils/free_all.c \
	./utils/initialization.c



$(NAME): $(M_SRC)
	make -C $(LIBFT_DIR)
	make -C $(PRINT_DIR)
	$(CC) $(M_SRC) $(LFLAGS) $(PFLAGS) $(CFLAGS) -lreadline -o $(NAME)
	@echo "\e[0;35m ----> MINISHELL compliled with succes\e[0;m"

all: $(NAME)

clean:


fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(PRINT_DIR)/libftprintf.a
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINT_DIR)
	
re: fclean all

VALGRIND=@valgrind --suppressions=suppression.supp --leak-check=full --track-fds=yes --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
# FOR FD 		TRACKING: --track-fds=yes
# FOR CHILDREN	TRACKING: --trace-children=yes
valgrind: all
	clear
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re

.SILENT: