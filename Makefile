# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/06/25 23:43:57 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
#PFLAGS = -L./Printft -lftprintf
LFLAGS = -L./Libft -lft
RM = rm -f
#PRINT_DIR = ./Printft
LIBFT_DIR = ./Libft

H_SRC = lexer.h minishell.h builtins.h expander.h parsing.h
H_DIR = headers/
H_PATH = $(addprefix $(H_DIR), $(H_SRC))

M_SRC = main.c
M_OBJ = $(M_SRC:.c=.o)

L_SRC = lexer.c word_token.c utils.c meta_token.c special_token.c \
		meta_cases.c define_builtins.c
L_DIR = Lexer/
L_PATH = $(addprefix $(L_DIR), $(L_SRC))
L_OBJ = $(L_PATH:.c=.o)

# P_SRC = parsing.c
# P_DIR = parsing/
# P_PATH = $(addprefix $(P_DIR), $(P_SRC))
# P_OBJ = $(P_PATH:.c=.o)

B_SRC = check_env_arg.c export.c get_env.c search_env.c cd.c set_env.c
B_DIR = builtins/
B_PATH = $(addprefix $(B_DIR), $(B_SRC))
B_OBJ = $(B_PATH:.c=.o)

E_SRC = expander.c
E_DIR = expander/
E_PATH = $(addprefix $(E_DIR), $(E_SRC))
E_OBJ = $(E_PATH:.c=.o)

%.o: %.c $(H_PATH) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(M_OBJ) $(L_OBJ) $(B_OBJ) $(E_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(L_OBJ) $(B_OBJ) $(E_OBJ) $(LFLAGS) -lreadline -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(M_OBJ) $(L_OBJ) $(B_OBJ) $(E_OBJ)
	

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	make clean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re